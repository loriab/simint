#include "simint/boys/boys.h"
#include "simint/ostei/gen/ostei_generated.h"
#include "simint/vectorization/vectorization.h"
#include <math.h>
#include <string.h>


int ostei_p_s_s_d(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__p_s_s_d)
{

    SIMINT_ASSUME_ALIGN_DBL(work);
    SIMINT_ASSUME_ALIGN_DBL(INT__p_s_s_d);
    memset(INT__p_s_s_d, 0, P.nshell12_clip * Q.nshell12_clip * 18 * sizeof(double));

    int ab, cd, abcd;
    int istart, jstart;
    int iprimcd, nprim_icd, icd;
    const int check_screen = (screen_tol > 0.0);
    int i, j;
    int n;
    int not_screened;

    // partition workspace
    SIMINT_DBLTYPE * const primwork = (SIMINT_DBLTYPE *)(work + SIMINT_NSHELL_SIMD*0);
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_s = primwork + 0;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_p = primwork + 4;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_d = primwork + 13;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_d = primwork + 25;
    double * const hrrwork = (double *)(primwork + 43);


    // Create constants
    const SIMINT_DBLTYPE const_1 = SIMINT_DBLSET1(1);
    const SIMINT_DBLTYPE const_2 = SIMINT_DBLSET1(2);
    const SIMINT_DBLTYPE one_half = SIMINT_DBLSET1(0.5);


    ////////////////////////////////////////
    // Loop over shells and primitives
    ////////////////////////////////////////

    abcd = 0;
    istart = 0;
    for(ab = 0; ab < P.nshell12_clip; ++ab)
    {
        const int iend = istart + P.nprim12[ab];

        cd = 0;
        jstart = 0;

        for(cd = 0; cd < Q.nshell12_clip; cd += SIMINT_NSHELL_SIMD)
        {
            const int nshellbatch = ((cd + SIMINT_NSHELL_SIMD) > Q.nshell12_clip) ? Q.nshell12_clip - cd : SIMINT_NSHELL_SIMD;
            int jend = jstart;
            for(i = 0; i < nshellbatch; i++)
                jend += Q.nprim12[cd+i];


            for(i = istart; i < iend; ++i)
            {
                SIMINT_DBLTYPE bra_screen_max;  // only used if check_screen

                if(check_screen)
                {
                    // Skip this whole thing if always insignificant
                    if((P.screen[i] * Q.screen_max) < screen_tol)
                        continue;
                    bra_screen_max = SIMINT_DBLSET1(P.screen[i]);
                }

                icd = 0;
                iprimcd = 0;
                nprim_icd = Q.nprim12[cd];
                double * restrict PRIM_PTR_INT__p_s_s_d = INT__p_s_s_d + abcd * 18;



                // Load these one per loop over i
                const SIMINT_DBLTYPE P_alpha = SIMINT_DBLSET1(P.alpha[i]);
                const SIMINT_DBLTYPE P_prefac = SIMINT_DBLSET1(P.prefac[i]);
                const SIMINT_DBLTYPE Pxyz[3] = { SIMINT_DBLSET1(P.x[i]), SIMINT_DBLSET1(P.y[i]), SIMINT_DBLSET1(P.z[i]) };

                const SIMINT_DBLTYPE P_PA[3] = { SIMINT_DBLSET1(P.PA_x[i]), SIMINT_DBLSET1(P.PA_y[i]), SIMINT_DBLSET1(P.PA_z[i]) };

                for(j = jstart; j < jend; j += SIMINT_SIMD_LEN)
                {
                    // calculate the shell offsets
                    // these are the offset from the shell pointed to by cd
                    // for each element
                    int shelloffsets[SIMINT_SIMD_LEN] = {0};
                    int lastoffset = 0;
                    const int nlane = ( ((j + SIMINT_SIMD_LEN) < jend) ? SIMINT_SIMD_LEN : (jend - j));

                    if((iprimcd + SIMINT_SIMD_LEN) >= nprim_icd)
                    {
                        // Handle if the first element of the vector is a new shell
                        if(iprimcd >= nprim_icd && ((icd+1) < nshellbatch))
                        {
                            nprim_icd += Q.nprim12[cd + (++icd)];
                            PRIM_PTR_INT__p_s_s_d += 18;
                        }
                        iprimcd++;
                        for(n = 1; n < SIMINT_SIMD_LEN; ++n)
                        {
                            if(iprimcd >= nprim_icd && ((icd+1) < nshellbatch))
                            {
                                shelloffsets[n] = shelloffsets[n-1] + 1;
                                lastoffset++;
                                nprim_icd += Q.nprim12[cd + (++icd)];
                            }
                            else
                                shelloffsets[n] = shelloffsets[n-1];
                            iprimcd++;
                        }
                    }
                    else
                        iprimcd += SIMINT_SIMD_LEN;

                    // Do we have to compute this vector (or has it been screened out)?
                    // (not_screened != 0 means we have to do this vector)
                    if(check_screen)
                    {
                        const double vmax = vector_max(SIMINT_MUL(bra_screen_max, SIMINT_DBLLOAD(Q.screen, j)));
                        if(vmax < screen_tol)
                        {
                            PRIM_PTR_INT__p_s_s_d += lastoffset*18;
                            continue;
                        }
                    }

                    const SIMINT_DBLTYPE Q_alpha = SIMINT_DBLLOAD(Q.alpha, j);
                    const SIMINT_DBLTYPE PQalpha_mul = SIMINT_MUL(P_alpha, Q_alpha);
                    const SIMINT_DBLTYPE PQalpha_sum = SIMINT_ADD(P_alpha, Q_alpha);
                    const SIMINT_DBLTYPE one_over_PQalpha_sum = SIMINT_DIV(const_1, PQalpha_sum);


                    /* construct R2 = (Px - Qx)**2 + (Py - Qy)**2 + (Pz -Qz)**2 */
                    SIMINT_DBLTYPE PQ[3];
                    PQ[0] = SIMINT_SUB(Pxyz[0], SIMINT_DBLLOAD(Q.x, j));
                    PQ[1] = SIMINT_SUB(Pxyz[1], SIMINT_DBLLOAD(Q.y, j));
                    PQ[2] = SIMINT_SUB(Pxyz[2], SIMINT_DBLLOAD(Q.z, j));
                    SIMINT_DBLTYPE R2 = SIMINT_MUL(PQ[0], PQ[0]);
                    R2 = SIMINT_FMADD(PQ[1], PQ[1], R2);
                    R2 = SIMINT_FMADD(PQ[2], PQ[2], R2);

                    const SIMINT_DBLTYPE alpha = SIMINT_MUL(PQalpha_mul, one_over_PQalpha_sum); // alpha from MEST
                    const SIMINT_DBLTYPE one_over_p = SIMINT_DIV(const_1, P_alpha);
                    const SIMINT_DBLTYPE one_over_q = SIMINT_DIV(const_1, Q_alpha);
                    const SIMINT_DBLTYPE one_over_2p = SIMINT_MUL(one_half, one_over_p);
                    const SIMINT_DBLTYPE one_over_2q = SIMINT_MUL(one_half, one_over_q);
                    const SIMINT_DBLTYPE one_over_2pq = SIMINT_MUL(one_half, one_over_PQalpha_sum);
                    const SIMINT_DBLTYPE Q_PB[3] = { SIMINT_DBLLOAD(Q.PB_x, j), SIMINT_DBLLOAD(Q.PB_y, j), SIMINT_DBLLOAD(Q.PB_z, j) };

                    // NOTE: Minus sign!
                    const SIMINT_DBLTYPE a_over_p = SIMINT_MUL(SIMINT_NEG(alpha), one_over_p);
                    SIMINT_DBLTYPE aop_PQ[3];
                    aop_PQ[0] = SIMINT_MUL(a_over_p, PQ[0]);
                    aop_PQ[1] = SIMINT_MUL(a_over_p, PQ[1]);
                    aop_PQ[2] = SIMINT_MUL(a_over_p, PQ[2]);

                    SIMINT_DBLTYPE a_over_q = SIMINT_MUL(alpha, one_over_q);
                    SIMINT_DBLTYPE aoq_PQ[3];
                    aoq_PQ[0] = SIMINT_MUL(a_over_q, PQ[0]);
                    aoq_PQ[1] = SIMINT_MUL(a_over_q, PQ[1]);
                    aoq_PQ[2] = SIMINT_MUL(a_over_q, PQ[2]);
                    // Put a minus sign here so we don't have to in RR routines
                    a_over_q = SIMINT_NEG(a_over_q);


                    //////////////////////////////////////////////
                    // Fjt function section
                    // Maximum v value: 3
                    //////////////////////////////////////////////
                    // The parameter to the Fjt function
                    const SIMINT_DBLTYPE F_x = SIMINT_MUL(R2, alpha);


                    const SIMINT_DBLTYPE Q_prefac = mask_load(nlane, Q.prefac + j);


                    boys_F_split(PRIM_INT__s_s_s_s, F_x, 3);
                    SIMINT_DBLTYPE prefac = SIMINT_SQRT(one_over_PQalpha_sum);
                    prefac = SIMINT_MUL(SIMINT_MUL(P_prefac, Q_prefac), prefac);
                    for(n = 0; n <= 3; n++)
                        PRIM_INT__s_s_s_s[n] = SIMINT_MUL(PRIM_INT__s_s_s_s[n], prefac);

                    //////////////////////////////////////////////
                    // Primitive integrals: Vertical recurrance
                    //////////////////////////////////////////////

                    const SIMINT_DBLTYPE vrr_const_1_over_2q = one_over_2q;
                    const SIMINT_DBLTYPE vrr_const_1_over_2pq = one_over_2pq;
                    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(const_2, one_over_2pq);



                    // Forming PRIM_INT__s_s_s_p[3 * 3];
                    for(n = 0; n < 3; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_s_p[n * 3 + 0] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_s_p[n * 3 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_p[n * 3 + 0]);

                        PRIM_INT__s_s_s_p[n * 3 + 1] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_s_p[n * 3 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_p[n * 3 + 1]);

                        PRIM_INT__s_s_s_p[n * 3 + 2] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_s_p[n * 3 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_p[n * 3 + 2]);

                    }



                    // Forming PRIM_INT__s_s_s_d[2 * 6];
                    for(n = 0; n < 2; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_s_d[n * 6 + 0] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_s_s_p[n * 3 + 0]);
                        PRIM_INT__s_s_s_d[n * 6 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_p[(n+1) * 3 + 0], PRIM_INT__s_s_s_d[n * 6 + 0]);
                        PRIM_INT__s_s_s_d[n * 6 + 0] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_s_s_d[n * 6 + 0]);

                        PRIM_INT__s_s_s_d[n * 6 + 1] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_p[n * 3 + 0]);
                        PRIM_INT__s_s_s_d[n * 6 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_p[(n+1) * 3 + 0], PRIM_INT__s_s_s_d[n * 6 + 1]);

                        PRIM_INT__s_s_s_d[n * 6 + 2] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_p[n * 3 + 0]);
                        PRIM_INT__s_s_s_d[n * 6 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_p[(n+1) * 3 + 0], PRIM_INT__s_s_s_d[n * 6 + 2]);

                        PRIM_INT__s_s_s_d[n * 6 + 3] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_p[n * 3 + 1]);
                        PRIM_INT__s_s_s_d[n * 6 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_p[(n+1) * 3 + 1], PRIM_INT__s_s_s_d[n * 6 + 3]);
                        PRIM_INT__s_s_s_d[n * 6 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_s_s_d[n * 6 + 3]);

                        PRIM_INT__s_s_s_d[n * 6 + 4] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_p[n * 3 + 1]);
                        PRIM_INT__s_s_s_d[n * 6 + 4] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_p[(n+1) * 3 + 1], PRIM_INT__s_s_s_d[n * 6 + 4]);

                        PRIM_INT__s_s_s_d[n * 6 + 5] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_p[n * 3 + 2]);
                        PRIM_INT__s_s_s_d[n * 6 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_p[(n+1) * 3 + 2], PRIM_INT__s_s_s_d[n * 6 + 5]);
                        PRIM_INT__s_s_s_d[n * 6 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_s_s_d[n * 6 + 5]);

                    }



                    // Forming PRIM_INT__p_s_s_d[1 * 18];
                    for(n = 0; n < 1; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__p_s_s_d[n * 18 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_s_d[n * 6 + 0]);
                        PRIM_INT__p_s_s_d[n * 18 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__p_s_s_d[n * 18 + 0]);
                        PRIM_INT__p_s_s_d[n * 18 + 0] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_s_p[(n+1) * 3 + 0], PRIM_INT__p_s_s_d[n * 18 + 0]);

                        PRIM_INT__p_s_s_d[n * 18 + 1] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_s_d[n * 6 + 1]);
                        PRIM_INT__p_s_s_d[n * 18 + 1] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_d[(n+1) * 6 + 1], PRIM_INT__p_s_s_d[n * 18 + 1]);
                        PRIM_INT__p_s_s_d[n * 18 + 1] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_p[(n+1) * 3 + 1], PRIM_INT__p_s_s_d[n * 18 + 1]);

                        PRIM_INT__p_s_s_d[n * 18 + 2] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_s_d[n * 6 + 2]);
                        PRIM_INT__p_s_s_d[n * 18 + 2] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_d[(n+1) * 6 + 2], PRIM_INT__p_s_s_d[n * 18 + 2]);
                        PRIM_INT__p_s_s_d[n * 18 + 2] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_p[(n+1) * 3 + 2], PRIM_INT__p_s_s_d[n * 18 + 2]);

                        PRIM_INT__p_s_s_d[n * 18 + 3] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_s_d[n * 6 + 3]);
                        PRIM_INT__p_s_s_d[n * 18 + 3] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__p_s_s_d[n * 18 + 3]);

                        PRIM_INT__p_s_s_d[n * 18 + 4] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_s_d[n * 6 + 4]);
                        PRIM_INT__p_s_s_d[n * 18 + 4] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_d[(n+1) * 6 + 4], PRIM_INT__p_s_s_d[n * 18 + 4]);

                        PRIM_INT__p_s_s_d[n * 18 + 5] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_s_d[n * 6 + 5]);
                        PRIM_INT__p_s_s_d[n * 18 + 5] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_d[(n+1) * 6 + 5], PRIM_INT__p_s_s_d[n * 18 + 5]);

                        PRIM_INT__p_s_s_d[n * 18 + 6] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_s_d[n * 6 + 0]);
                        PRIM_INT__p_s_s_d[n * 18 + 6] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__p_s_s_d[n * 18 + 6]);

                        PRIM_INT__p_s_s_d[n * 18 + 7] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_s_d[n * 6 + 1]);
                        PRIM_INT__p_s_s_d[n * 18 + 7] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_d[(n+1) * 6 + 1], PRIM_INT__p_s_s_d[n * 18 + 7]);
                        PRIM_INT__p_s_s_d[n * 18 + 7] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_p[(n+1) * 3 + 0], PRIM_INT__p_s_s_d[n * 18 + 7]);

                        PRIM_INT__p_s_s_d[n * 18 + 8] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_s_d[n * 6 + 2]);
                        PRIM_INT__p_s_s_d[n * 18 + 8] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_d[(n+1) * 6 + 2], PRIM_INT__p_s_s_d[n * 18 + 8]);

                        PRIM_INT__p_s_s_d[n * 18 + 9] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_s_d[n * 6 + 3]);
                        PRIM_INT__p_s_s_d[n * 18 + 9] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__p_s_s_d[n * 18 + 9]);
                        PRIM_INT__p_s_s_d[n * 18 + 9] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_s_p[(n+1) * 3 + 1], PRIM_INT__p_s_s_d[n * 18 + 9]);

                        PRIM_INT__p_s_s_d[n * 18 + 10] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_s_d[n * 6 + 4]);
                        PRIM_INT__p_s_s_d[n * 18 + 10] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_d[(n+1) * 6 + 4], PRIM_INT__p_s_s_d[n * 18 + 10]);
                        PRIM_INT__p_s_s_d[n * 18 + 10] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_p[(n+1) * 3 + 2], PRIM_INT__p_s_s_d[n * 18 + 10]);

                        PRIM_INT__p_s_s_d[n * 18 + 11] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_s_d[n * 6 + 5]);
                        PRIM_INT__p_s_s_d[n * 18 + 11] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_d[(n+1) * 6 + 5], PRIM_INT__p_s_s_d[n * 18 + 11]);

                        PRIM_INT__p_s_s_d[n * 18 + 12] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_s_d[n * 6 + 0]);
                        PRIM_INT__p_s_s_d[n * 18 + 12] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__p_s_s_d[n * 18 + 12]);

                        PRIM_INT__p_s_s_d[n * 18 + 13] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_s_d[n * 6 + 1]);
                        PRIM_INT__p_s_s_d[n * 18 + 13] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_d[(n+1) * 6 + 1], PRIM_INT__p_s_s_d[n * 18 + 13]);

                        PRIM_INT__p_s_s_d[n * 18 + 14] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_s_d[n * 6 + 2]);
                        PRIM_INT__p_s_s_d[n * 18 + 14] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_d[(n+1) * 6 + 2], PRIM_INT__p_s_s_d[n * 18 + 14]);
                        PRIM_INT__p_s_s_d[n * 18 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_p[(n+1) * 3 + 0], PRIM_INT__p_s_s_d[n * 18 + 14]);

                        PRIM_INT__p_s_s_d[n * 18 + 15] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_s_d[n * 6 + 3]);
                        PRIM_INT__p_s_s_d[n * 18 + 15] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__p_s_s_d[n * 18 + 15]);

                        PRIM_INT__p_s_s_d[n * 18 + 16] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_s_d[n * 6 + 4]);
                        PRIM_INT__p_s_s_d[n * 18 + 16] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_d[(n+1) * 6 + 4], PRIM_INT__p_s_s_d[n * 18 + 16]);
                        PRIM_INT__p_s_s_d[n * 18 + 16] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_p[(n+1) * 3 + 1], PRIM_INT__p_s_s_d[n * 18 + 16]);

                        PRIM_INT__p_s_s_d[n * 18 + 17] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_s_d[n * 6 + 5]);
                        PRIM_INT__p_s_s_d[n * 18 + 17] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_d[(n+1) * 6 + 5], PRIM_INT__p_s_s_d[n * 18 + 17]);
                        PRIM_INT__p_s_s_d[n * 18 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_s_p[(n+1) * 3 + 2], PRIM_INT__p_s_s_d[n * 18 + 17]);

                    }




                    ////////////////////////////////////
                    // Accumulate contracted integrals
                    ////////////////////////////////////
                    if(lastoffset == 0)
                    {
                        contract_all(18, PRIM_INT__p_s_s_d, PRIM_PTR_INT__p_s_s_d);
                    }
                    else
                    {
                        contract(18, shelloffsets, PRIM_INT__p_s_s_d, PRIM_PTR_INT__p_s_s_d);
                        PRIM_PTR_INT__p_s_s_d += lastoffset*18;
                    }

                }  // close loop over j
            }  // close loop over i
            
            //Advance to the next batch
            jstart = SIMINT_SIMD_ROUND(jend);
            abcd += nshellbatch;
            
        }   // close loop cdbatch

        istart = iend;
    }  // close loop over ab

    return P.nshell12_clip * Q.nshell12_clip;
}

