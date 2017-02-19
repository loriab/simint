#include "simint/boys/boys.h"
#include "simint/ostei/gen/ostei_generated.h"
#include "simint/vectorization/vectorization.h"
#include <math.h>
#include <string.h>


int ostei_s_p_p_f(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__s_p_p_f)
{

    SIMINT_ASSUME_ALIGN_DBL(work);
    SIMINT_ASSUME_ALIGN_DBL(INT__s_p_p_f);
    int ab, cd, abcd;
    int istart, jstart;
    int iprimcd, nprim_icd, icd;
    const int check_screen = (screen_tol > 0.0);
    int i, j;
    int n;
    int not_screened;
    int real_abcd;
    int ibra;

    // partition workspace
    double * const INT__s_p_s_f = work + (SIMINT_NSHELL_SIMD * 0);
    double * const INT__s_p_s_g = work + (SIMINT_NSHELL_SIMD * 30);
    SIMINT_DBLTYPE * const primwork = (SIMINT_DBLTYPE *)(work + SIMINT_NSHELL_SIMD*75);
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_s = primwork + 0;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_p = primwork + 6;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_d = primwork + 21;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_f = primwork + 45;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_g = primwork + 75;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_f = primwork + 105;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_g = primwork + 135;
    double * const hrrwork = (double *)(primwork + 180);


    // Create constants
    const SIMINT_DBLTYPE const_1 = SIMINT_DBLSET1(1);
    const SIMINT_DBLTYPE const_2 = SIMINT_DBLSET1(2);
    const SIMINT_DBLTYPE const_3 = SIMINT_DBLSET1(3);
    const SIMINT_DBLTYPE const_4 = SIMINT_DBLSET1(4);
    const SIMINT_DBLTYPE one_half = SIMINT_DBLSET1(0.5);


    ////////////////////////////////////////
    // Loop over shells and primitives
    ////////////////////////////////////////

    real_abcd = 0;
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

            // Clear the beginning of the workspace (where we are accumulating integrals)
            memset(work, 0, SIMINT_NSHELL_SIMD * 75 * sizeof(double));
            abcd = 0;


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
                double * restrict PRIM_PTR_INT__s_p_s_f = INT__s_p_s_f + abcd * 30;
                double * restrict PRIM_PTR_INT__s_p_s_g = INT__s_p_s_g + abcd * 45;



                // Load these one per loop over i
                const SIMINT_DBLTYPE P_alpha = SIMINT_DBLSET1(P.alpha[i]);
                const SIMINT_DBLTYPE P_prefac = SIMINT_DBLSET1(P.prefac[i]);
                const SIMINT_DBLTYPE Pxyz[3] = { SIMINT_DBLSET1(P.x[i]), SIMINT_DBLSET1(P.y[i]), SIMINT_DBLSET1(P.z[i]) };

                const SIMINT_DBLTYPE P_PB[3] = { SIMINT_DBLSET1(P.PB_x[i]), SIMINT_DBLSET1(P.PB_y[i]), SIMINT_DBLSET1(P.PB_z[i]) };

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
                            PRIM_PTR_INT__s_p_s_f += 30;
                            PRIM_PTR_INT__s_p_s_g += 45;
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
                            PRIM_PTR_INT__s_p_s_f += lastoffset*30;
                            PRIM_PTR_INT__s_p_s_g += lastoffset*45;
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
                    // Maximum v value: 5
                    //////////////////////////////////////////////
                    // The parameter to the Fjt function
                    const SIMINT_DBLTYPE F_x = SIMINT_MUL(R2, alpha);


                    const SIMINT_DBLTYPE Q_prefac = mask_load(nlane, Q.prefac + j);


                    boys_F_split(PRIM_INT__s_s_s_s, F_x, 5);
                    SIMINT_DBLTYPE prefac = SIMINT_SQRT(one_over_PQalpha_sum);
                    prefac = SIMINT_MUL(SIMINT_MUL(P_prefac, Q_prefac), prefac);
                    for(n = 0; n <= 5; n++)
                        PRIM_INT__s_s_s_s[n] = SIMINT_MUL(PRIM_INT__s_s_s_s[n], prefac);

                    //////////////////////////////////////////////
                    // Primitive integrals: Vertical recurrance
                    //////////////////////////////////////////////

                    const SIMINT_DBLTYPE vrr_const_1_over_2q = one_over_2q;
                    const SIMINT_DBLTYPE vrr_const_2_over_2q = SIMINT_MUL(const_2, one_over_2q);
                    const SIMINT_DBLTYPE vrr_const_3_over_2q = SIMINT_MUL(const_3, one_over_2q);
                    const SIMINT_DBLTYPE vrr_const_1_over_2pq = one_over_2pq;
                    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(const_2, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_3_over_2pq = SIMINT_MUL(const_3, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_4_over_2pq = SIMINT_MUL(const_4, one_over_2pq);



                    // Forming PRIM_INT__s_s_s_p[5 * 3];
                    for(n = 0; n < 5; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_s_p[n * 3 + 0] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_s_p[n * 3 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_p[n * 3 + 0]);

                        PRIM_INT__s_s_s_p[n * 3 + 1] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_s_p[n * 3 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_p[n * 3 + 1]);

                        PRIM_INT__s_s_s_p[n * 3 + 2] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_s_p[n * 3 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_p[n * 3 + 2]);

                    }



                    // Forming PRIM_INT__s_s_s_d[4 * 6];
                    for(n = 0; n < 4; ++n)  // loop over orders of auxiliary function
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



                    // Forming PRIM_INT__s_s_s_f[3 * 10];
                    for(n = 0; n < 3; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_s_f[n * 10 + 0] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_s_s_d[n * 6 + 0]);
                        PRIM_INT__s_s_s_f[n * 10 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__s_s_s_f[n * 10 + 0]);
                        PRIM_INT__s_s_s_f[n * 10 + 0] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_p[(n+1) * 3 + 0], PRIM_INT__s_s_s_p[n * 3 + 0]), PRIM_INT__s_s_s_f[n * 10 + 0]);

                        PRIM_INT__s_s_s_f[n * 10 + 1] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_d[n * 6 + 0]);
                        PRIM_INT__s_s_s_f[n * 10 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__s_s_s_f[n * 10 + 1]);

                        PRIM_INT__s_s_s_f[n * 10 + 2] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_d[n * 6 + 0]);
                        PRIM_INT__s_s_s_f[n * 10 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__s_s_s_f[n * 10 + 2]);

                        PRIM_INT__s_s_s_f[n * 10 + 3] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_s_s_d[n * 6 + 3]);
                        PRIM_INT__s_s_s_f[n * 10 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__s_s_s_f[n * 10 + 3]);

                        PRIM_INT__s_s_s_f[n * 10 + 4] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_d[n * 6 + 1]);
                        PRIM_INT__s_s_s_f[n * 10 + 4] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_d[(n+1) * 6 + 1], PRIM_INT__s_s_s_f[n * 10 + 4]);

                        PRIM_INT__s_s_s_f[n * 10 + 5] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_s_s_d[n * 6 + 5]);
                        PRIM_INT__s_s_s_f[n * 10 + 5] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_d[(n+1) * 6 + 5], PRIM_INT__s_s_s_f[n * 10 + 5]);

                        PRIM_INT__s_s_s_f[n * 10 + 6] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_d[n * 6 + 3]);
                        PRIM_INT__s_s_s_f[n * 10 + 6] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__s_s_s_f[n * 10 + 6]);
                        PRIM_INT__s_s_s_f[n * 10 + 6] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_p[(n+1) * 3 + 1], PRIM_INT__s_s_s_p[n * 3 + 1]), PRIM_INT__s_s_s_f[n * 10 + 6]);

                        PRIM_INT__s_s_s_f[n * 10 + 7] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_d[n * 6 + 3]);
                        PRIM_INT__s_s_s_f[n * 10 + 7] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__s_s_s_f[n * 10 + 7]);

                        PRIM_INT__s_s_s_f[n * 10 + 8] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_d[n * 6 + 5]);
                        PRIM_INT__s_s_s_f[n * 10 + 8] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_d[(n+1) * 6 + 5], PRIM_INT__s_s_s_f[n * 10 + 8]);

                        PRIM_INT__s_s_s_f[n * 10 + 9] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_d[n * 6 + 5]);
                        PRIM_INT__s_s_s_f[n * 10 + 9] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_d[(n+1) * 6 + 5], PRIM_INT__s_s_s_f[n * 10 + 9]);
                        PRIM_INT__s_s_s_f[n * 10 + 9] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_p[(n+1) * 3 + 2], PRIM_INT__s_s_s_p[n * 3 + 2]), PRIM_INT__s_s_s_f[n * 10 + 9]);

                    }



                    // Forming PRIM_INT__s_p_s_f[1 * 30];
                    for(n = 0; n < 1; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_p_s_f[n * 30 + 0] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_f[n * 10 + 0]);
                        PRIM_INT__s_p_s_f[n * 30 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 0], PRIM_INT__s_p_s_f[n * 30 + 0]);
                        PRIM_INT__s_p_s_f[n * 30 + 0] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__s_p_s_f[n * 30 + 0]);

                        PRIM_INT__s_p_s_f[n * 30 + 1] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_f[n * 10 + 1]);
                        PRIM_INT__s_p_s_f[n * 30 + 1] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 1], PRIM_INT__s_p_s_f[n * 30 + 1]);
                        PRIM_INT__s_p_s_f[n * 30 + 1] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 1], PRIM_INT__s_p_s_f[n * 30 + 1]);

                        PRIM_INT__s_p_s_f[n * 30 + 2] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_f[n * 10 + 2]);
                        PRIM_INT__s_p_s_f[n * 30 + 2] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 2], PRIM_INT__s_p_s_f[n * 30 + 2]);
                        PRIM_INT__s_p_s_f[n * 30 + 2] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 2], PRIM_INT__s_p_s_f[n * 30 + 2]);

                        PRIM_INT__s_p_s_f[n * 30 + 3] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_f[n * 10 + 3]);
                        PRIM_INT__s_p_s_f[n * 30 + 3] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 3], PRIM_INT__s_p_s_f[n * 30 + 3]);
                        PRIM_INT__s_p_s_f[n * 30 + 3] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__s_p_s_f[n * 30 + 3]);

                        PRIM_INT__s_p_s_f[n * 30 + 4] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_f[n * 10 + 4]);
                        PRIM_INT__s_p_s_f[n * 30 + 4] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 4], PRIM_INT__s_p_s_f[n * 30 + 4]);
                        PRIM_INT__s_p_s_f[n * 30 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 4], PRIM_INT__s_p_s_f[n * 30 + 4]);

                        PRIM_INT__s_p_s_f[n * 30 + 5] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_f[n * 10 + 5]);
                        PRIM_INT__s_p_s_f[n * 30 + 5] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 5], PRIM_INT__s_p_s_f[n * 30 + 5]);
                        PRIM_INT__s_p_s_f[n * 30 + 5] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 5], PRIM_INT__s_p_s_f[n * 30 + 5]);

                        PRIM_INT__s_p_s_f[n * 30 + 6] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_f[n * 10 + 6]);
                        PRIM_INT__s_p_s_f[n * 30 + 6] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 6], PRIM_INT__s_p_s_f[n * 30 + 6]);

                        PRIM_INT__s_p_s_f[n * 30 + 7] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_f[n * 10 + 7]);
                        PRIM_INT__s_p_s_f[n * 30 + 7] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 7], PRIM_INT__s_p_s_f[n * 30 + 7]);

                        PRIM_INT__s_p_s_f[n * 30 + 8] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_f[n * 10 + 8]);
                        PRIM_INT__s_p_s_f[n * 30 + 8] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 8], PRIM_INT__s_p_s_f[n * 30 + 8]);

                        PRIM_INT__s_p_s_f[n * 30 + 9] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_f[n * 10 + 9]);
                        PRIM_INT__s_p_s_f[n * 30 + 9] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 9], PRIM_INT__s_p_s_f[n * 30 + 9]);

                        PRIM_INT__s_p_s_f[n * 30 + 10] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_f[n * 10 + 0]);
                        PRIM_INT__s_p_s_f[n * 30 + 10] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 0], PRIM_INT__s_p_s_f[n * 30 + 10]);

                        PRIM_INT__s_p_s_f[n * 30 + 11] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_f[n * 10 + 1]);
                        PRIM_INT__s_p_s_f[n * 30 + 11] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 1], PRIM_INT__s_p_s_f[n * 30 + 11]);
                        PRIM_INT__s_p_s_f[n * 30 + 11] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__s_p_s_f[n * 30 + 11]);

                        PRIM_INT__s_p_s_f[n * 30 + 12] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_f[n * 10 + 2]);
                        PRIM_INT__s_p_s_f[n * 30 + 12] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 2], PRIM_INT__s_p_s_f[n * 30 + 12]);

                        PRIM_INT__s_p_s_f[n * 30 + 13] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_f[n * 10 + 3]);
                        PRIM_INT__s_p_s_f[n * 30 + 13] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 3], PRIM_INT__s_p_s_f[n * 30 + 13]);
                        PRIM_INT__s_p_s_f[n * 30 + 13] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 1], PRIM_INT__s_p_s_f[n * 30 + 13]);

                        PRIM_INT__s_p_s_f[n * 30 + 14] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_f[n * 10 + 4]);
                        PRIM_INT__s_p_s_f[n * 30 + 14] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 4], PRIM_INT__s_p_s_f[n * 30 + 14]);
                        PRIM_INT__s_p_s_f[n * 30 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 2], PRIM_INT__s_p_s_f[n * 30 + 14]);

                        PRIM_INT__s_p_s_f[n * 30 + 15] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_f[n * 10 + 5]);
                        PRIM_INT__s_p_s_f[n * 30 + 15] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 5], PRIM_INT__s_p_s_f[n * 30 + 15]);

                        PRIM_INT__s_p_s_f[n * 30 + 16] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_f[n * 10 + 6]);
                        PRIM_INT__s_p_s_f[n * 30 + 16] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 6], PRIM_INT__s_p_s_f[n * 30 + 16]);
                        PRIM_INT__s_p_s_f[n * 30 + 16] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__s_p_s_f[n * 30 + 16]);

                        PRIM_INT__s_p_s_f[n * 30 + 17] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_f[n * 10 + 7]);
                        PRIM_INT__s_p_s_f[n * 30 + 17] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 7], PRIM_INT__s_p_s_f[n * 30 + 17]);
                        PRIM_INT__s_p_s_f[n * 30 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 4], PRIM_INT__s_p_s_f[n * 30 + 17]);

                        PRIM_INT__s_p_s_f[n * 30 + 18] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_f[n * 10 + 8]);
                        PRIM_INT__s_p_s_f[n * 30 + 18] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 8], PRIM_INT__s_p_s_f[n * 30 + 18]);
                        PRIM_INT__s_p_s_f[n * 30 + 18] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 5], PRIM_INT__s_p_s_f[n * 30 + 18]);

                        PRIM_INT__s_p_s_f[n * 30 + 19] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_f[n * 10 + 9]);
                        PRIM_INT__s_p_s_f[n * 30 + 19] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 9], PRIM_INT__s_p_s_f[n * 30 + 19]);

                        PRIM_INT__s_p_s_f[n * 30 + 20] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_f[n * 10 + 0]);
                        PRIM_INT__s_p_s_f[n * 30 + 20] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 0], PRIM_INT__s_p_s_f[n * 30 + 20]);

                        PRIM_INT__s_p_s_f[n * 30 + 21] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_f[n * 10 + 1]);
                        PRIM_INT__s_p_s_f[n * 30 + 21] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 1], PRIM_INT__s_p_s_f[n * 30 + 21]);

                        PRIM_INT__s_p_s_f[n * 30 + 22] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_f[n * 10 + 2]);
                        PRIM_INT__s_p_s_f[n * 30 + 22] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 2], PRIM_INT__s_p_s_f[n * 30 + 22]);
                        PRIM_INT__s_p_s_f[n * 30 + 22] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__s_p_s_f[n * 30 + 22]);

                        PRIM_INT__s_p_s_f[n * 30 + 23] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_f[n * 10 + 3]);
                        PRIM_INT__s_p_s_f[n * 30 + 23] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 3], PRIM_INT__s_p_s_f[n * 30 + 23]);

                        PRIM_INT__s_p_s_f[n * 30 + 24] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_f[n * 10 + 4]);
                        PRIM_INT__s_p_s_f[n * 30 + 24] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 4], PRIM_INT__s_p_s_f[n * 30 + 24]);
                        PRIM_INT__s_p_s_f[n * 30 + 24] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 1], PRIM_INT__s_p_s_f[n * 30 + 24]);

                        PRIM_INT__s_p_s_f[n * 30 + 25] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_f[n * 10 + 5]);
                        PRIM_INT__s_p_s_f[n * 30 + 25] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 5], PRIM_INT__s_p_s_f[n * 30 + 25]);
                        PRIM_INT__s_p_s_f[n * 30 + 25] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 2], PRIM_INT__s_p_s_f[n * 30 + 25]);

                        PRIM_INT__s_p_s_f[n * 30 + 26] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_f[n * 10 + 6]);
                        PRIM_INT__s_p_s_f[n * 30 + 26] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 6], PRIM_INT__s_p_s_f[n * 30 + 26]);

                        PRIM_INT__s_p_s_f[n * 30 + 27] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_f[n * 10 + 7]);
                        PRIM_INT__s_p_s_f[n * 30 + 27] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 7], PRIM_INT__s_p_s_f[n * 30 + 27]);
                        PRIM_INT__s_p_s_f[n * 30 + 27] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__s_p_s_f[n * 30 + 27]);

                        PRIM_INT__s_p_s_f[n * 30 + 28] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_f[n * 10 + 8]);
                        PRIM_INT__s_p_s_f[n * 30 + 28] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 8], PRIM_INT__s_p_s_f[n * 30 + 28]);
                        PRIM_INT__s_p_s_f[n * 30 + 28] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 4], PRIM_INT__s_p_s_f[n * 30 + 28]);

                        PRIM_INT__s_p_s_f[n * 30 + 29] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_f[n * 10 + 9]);
                        PRIM_INT__s_p_s_f[n * 30 + 29] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 9], PRIM_INT__s_p_s_f[n * 30 + 29]);
                        PRIM_INT__s_p_s_f[n * 30 + 29] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 5], PRIM_INT__s_p_s_f[n * 30 + 29]);

                    }



                    // Forming PRIM_INT__s_s_s_g[2 * 15];
                    for(n = 0; n < 2; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_s_g[n * 15 + 0] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_s_s_f[n * 10 + 0]);
                        PRIM_INT__s_s_s_g[n * 15 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 0], PRIM_INT__s_s_s_g[n * 15 + 0]);
                        PRIM_INT__s_s_s_g[n * 15 + 0] = SIMINT_FMADD( vrr_const_3_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__s_s_s_d[n * 6 + 0]), PRIM_INT__s_s_s_g[n * 15 + 0]);

                        PRIM_INT__s_s_s_g[n * 15 + 1] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_f[n * 10 + 0]);
                        PRIM_INT__s_s_s_g[n * 15 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 0], PRIM_INT__s_s_s_g[n * 15 + 1]);

                        PRIM_INT__s_s_s_g[n * 15 + 2] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_f[n * 10 + 0]);
                        PRIM_INT__s_s_s_g[n * 15 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 0], PRIM_INT__s_s_s_g[n * 15 + 2]);

                        PRIM_INT__s_s_s_g[n * 15 + 3] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_f[n * 10 + 1]);
                        PRIM_INT__s_s_s_g[n * 15 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 1], PRIM_INT__s_s_s_g[n * 15 + 3]);
                        PRIM_INT__s_s_s_g[n * 15 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__s_s_s_d[n * 6 + 0]), PRIM_INT__s_s_s_g[n * 15 + 3]);

                        PRIM_INT__s_s_s_g[n * 15 + 4] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_f[n * 10 + 1]);
                        PRIM_INT__s_s_s_g[n * 15 + 4] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 1], PRIM_INT__s_s_s_g[n * 15 + 4]);

                        PRIM_INT__s_s_s_g[n * 15 + 5] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_f[n * 10 + 2]);
                        PRIM_INT__s_s_s_g[n * 15 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 2], PRIM_INT__s_s_s_g[n * 15 + 5]);
                        PRIM_INT__s_s_s_g[n * 15 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__s_s_s_d[n * 6 + 0]), PRIM_INT__s_s_s_g[n * 15 + 5]);

                        PRIM_INT__s_s_s_g[n * 15 + 6] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_s_s_f[n * 10 + 6]);
                        PRIM_INT__s_s_s_g[n * 15 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 6], PRIM_INT__s_s_s_g[n * 15 + 6]);

                        PRIM_INT__s_s_s_g[n * 15 + 7] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_f[n * 10 + 3]);
                        PRIM_INT__s_s_s_g[n * 15 + 7] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 3], PRIM_INT__s_s_s_g[n * 15 + 7]);

                        PRIM_INT__s_s_s_g[n * 15 + 8] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_f[n * 10 + 5]);
                        PRIM_INT__s_s_s_g[n * 15 + 8] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 5], PRIM_INT__s_s_s_g[n * 15 + 8]);

                        PRIM_INT__s_s_s_g[n * 15 + 9] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_s_s_f[n * 10 + 9]);
                        PRIM_INT__s_s_s_g[n * 15 + 9] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_f[(n+1) * 10 + 9], PRIM_INT__s_s_s_g[n * 15 + 9]);

                        PRIM_INT__s_s_s_g[n * 15 + 10] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_f[n * 10 + 6]);
                        PRIM_INT__s_s_s_g[n * 15 + 10] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 6], PRIM_INT__s_s_s_g[n * 15 + 10]);
                        PRIM_INT__s_s_s_g[n * 15 + 10] = SIMINT_FMADD( vrr_const_3_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__s_s_s_d[n * 6 + 3]), PRIM_INT__s_s_s_g[n * 15 + 10]);

                        PRIM_INT__s_s_s_g[n * 15 + 11] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_f[n * 10 + 6]);
                        PRIM_INT__s_s_s_g[n * 15 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 6], PRIM_INT__s_s_s_g[n * 15 + 11]);

                        PRIM_INT__s_s_s_g[n * 15 + 12] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_f[n * 10 + 7]);
                        PRIM_INT__s_s_s_g[n * 15 + 12] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 7], PRIM_INT__s_s_s_g[n * 15 + 12]);
                        PRIM_INT__s_s_s_g[n * 15 + 12] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__s_s_s_d[n * 6 + 3]), PRIM_INT__s_s_s_g[n * 15 + 12]);

                        PRIM_INT__s_s_s_g[n * 15 + 13] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_f[n * 10 + 9]);
                        PRIM_INT__s_s_s_g[n * 15 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_f[(n+1) * 10 + 9], PRIM_INT__s_s_s_g[n * 15 + 13]);

                        PRIM_INT__s_s_s_g[n * 15 + 14] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_f[n * 10 + 9]);
                        PRIM_INT__s_s_s_g[n * 15 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_f[(n+1) * 10 + 9], PRIM_INT__s_s_s_g[n * 15 + 14]);
                        PRIM_INT__s_s_s_g[n * 15 + 14] = SIMINT_FMADD( vrr_const_3_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_d[(n+1) * 6 + 5], PRIM_INT__s_s_s_d[n * 6 + 5]), PRIM_INT__s_s_s_g[n * 15 + 14]);

                    }


                    VRR_J_s_p_s_g(
                            PRIM_INT__s_p_s_g,
                            PRIM_INT__s_s_s_g,
                            PRIM_INT__s_s_s_f,
                            P_PB,
                            aop_PQ,
                            one_over_2pq,
                            1);




                    ////////////////////////////////////
                    // Accumulate contracted integrals
                    ////////////////////////////////////
                    if(lastoffset == 0)
                    {
                        contract_all(30, PRIM_INT__s_p_s_f, PRIM_PTR_INT__s_p_s_f);
                        contract_all(45, PRIM_INT__s_p_s_g, PRIM_PTR_INT__s_p_s_g);
                    }
                    else
                    {
                        contract(30, shelloffsets, PRIM_INT__s_p_s_f, PRIM_PTR_INT__s_p_s_f);
                        contract(45, shelloffsets, PRIM_INT__s_p_s_g, PRIM_PTR_INT__s_p_s_g);
                        PRIM_PTR_INT__s_p_s_f += lastoffset*30;
                        PRIM_PTR_INT__s_p_s_g += lastoffset*45;
                    }

                }  // close loop over j
            }  // close loop over i
            
            //Advance to the next batch
            jstart = SIMINT_SIMD_ROUND(jend);
            
            //////////////////////////////////////////////
            // Contracted integrals: Horizontal recurrance
            //////////////////////////////////////////////




            for(abcd = 0; abcd < nshellbatch; ++abcd, ++real_abcd)
            {
                const double hCD[3] = { Q.AB_x[cd+abcd], Q.AB_y[cd+abcd], Q.AB_z[cd+abcd] };

                // set up HRR pointers
                double const * restrict HRR_INT__s_p_s_f = INT__s_p_s_f + abcd * 30;
                double const * restrict HRR_INT__s_p_s_g = INT__s_p_s_g + abcd * 45;
                double * restrict HRR_INT__s_p_p_f = INT__s_p_p_f + real_abcd * 90;

                // form INT__s_p_p_f
                for(ibra = 0; ibra < 3; ++ibra)
                {
                    HRR_INT__s_p_p_f[ibra * 30 + 0] = HRR_INT__s_p_s_g[ibra * 15 + 0] - ( hCD[0] * HRR_INT__s_p_s_f[ibra * 10 + 0] );

                    HRR_INT__s_p_p_f[ibra * 30 + 1] = HRR_INT__s_p_s_g[ibra * 15 + 1] - ( hCD[0] * HRR_INT__s_p_s_f[ibra * 10 + 1] );

                    HRR_INT__s_p_p_f[ibra * 30 + 2] = HRR_INT__s_p_s_g[ibra * 15 + 2] - ( hCD[0] * HRR_INT__s_p_s_f[ibra * 10 + 2] );

                    HRR_INT__s_p_p_f[ibra * 30 + 3] = HRR_INT__s_p_s_g[ibra * 15 + 3] - ( hCD[0] * HRR_INT__s_p_s_f[ibra * 10 + 3] );

                    HRR_INT__s_p_p_f[ibra * 30 + 4] = HRR_INT__s_p_s_g[ibra * 15 + 4] - ( hCD[0] * HRR_INT__s_p_s_f[ibra * 10 + 4] );

                    HRR_INT__s_p_p_f[ibra * 30 + 5] = HRR_INT__s_p_s_g[ibra * 15 + 5] - ( hCD[0] * HRR_INT__s_p_s_f[ibra * 10 + 5] );

                    HRR_INT__s_p_p_f[ibra * 30 + 6] = HRR_INT__s_p_s_g[ibra * 15 + 6] - ( hCD[0] * HRR_INT__s_p_s_f[ibra * 10 + 6] );

                    HRR_INT__s_p_p_f[ibra * 30 + 7] = HRR_INT__s_p_s_g[ibra * 15 + 7] - ( hCD[0] * HRR_INT__s_p_s_f[ibra * 10 + 7] );

                    HRR_INT__s_p_p_f[ibra * 30 + 8] = HRR_INT__s_p_s_g[ibra * 15 + 8] - ( hCD[0] * HRR_INT__s_p_s_f[ibra * 10 + 8] );

                    HRR_INT__s_p_p_f[ibra * 30 + 9] = HRR_INT__s_p_s_g[ibra * 15 + 9] - ( hCD[0] * HRR_INT__s_p_s_f[ibra * 10 + 9] );

                    HRR_INT__s_p_p_f[ibra * 30 + 10] = HRR_INT__s_p_s_g[ibra * 15 + 1] - ( hCD[1] * HRR_INT__s_p_s_f[ibra * 10 + 0] );

                    HRR_INT__s_p_p_f[ibra * 30 + 11] = HRR_INT__s_p_s_g[ibra * 15 + 3] - ( hCD[1] * HRR_INT__s_p_s_f[ibra * 10 + 1] );

                    HRR_INT__s_p_p_f[ibra * 30 + 12] = HRR_INT__s_p_s_g[ibra * 15 + 4] - ( hCD[1] * HRR_INT__s_p_s_f[ibra * 10 + 2] );

                    HRR_INT__s_p_p_f[ibra * 30 + 13] = HRR_INT__s_p_s_g[ibra * 15 + 6] - ( hCD[1] * HRR_INT__s_p_s_f[ibra * 10 + 3] );

                    HRR_INT__s_p_p_f[ibra * 30 + 14] = HRR_INT__s_p_s_g[ibra * 15 + 7] - ( hCD[1] * HRR_INT__s_p_s_f[ibra * 10 + 4] );

                    HRR_INT__s_p_p_f[ibra * 30 + 15] = HRR_INT__s_p_s_g[ibra * 15 + 8] - ( hCD[1] * HRR_INT__s_p_s_f[ibra * 10 + 5] );

                    HRR_INT__s_p_p_f[ibra * 30 + 16] = HRR_INT__s_p_s_g[ibra * 15 + 10] - ( hCD[1] * HRR_INT__s_p_s_f[ibra * 10 + 6] );

                    HRR_INT__s_p_p_f[ibra * 30 + 17] = HRR_INT__s_p_s_g[ibra * 15 + 11] - ( hCD[1] * HRR_INT__s_p_s_f[ibra * 10 + 7] );

                    HRR_INT__s_p_p_f[ibra * 30 + 18] = HRR_INT__s_p_s_g[ibra * 15 + 12] - ( hCD[1] * HRR_INT__s_p_s_f[ibra * 10 + 8] );

                    HRR_INT__s_p_p_f[ibra * 30 + 19] = HRR_INT__s_p_s_g[ibra * 15 + 13] - ( hCD[1] * HRR_INT__s_p_s_f[ibra * 10 + 9] );

                    HRR_INT__s_p_p_f[ibra * 30 + 20] = HRR_INT__s_p_s_g[ibra * 15 + 2] - ( hCD[2] * HRR_INT__s_p_s_f[ibra * 10 + 0] );

                    HRR_INT__s_p_p_f[ibra * 30 + 21] = HRR_INT__s_p_s_g[ibra * 15 + 4] - ( hCD[2] * HRR_INT__s_p_s_f[ibra * 10 + 1] );

                    HRR_INT__s_p_p_f[ibra * 30 + 22] = HRR_INT__s_p_s_g[ibra * 15 + 5] - ( hCD[2] * HRR_INT__s_p_s_f[ibra * 10 + 2] );

                    HRR_INT__s_p_p_f[ibra * 30 + 23] = HRR_INT__s_p_s_g[ibra * 15 + 7] - ( hCD[2] * HRR_INT__s_p_s_f[ibra * 10 + 3] );

                    HRR_INT__s_p_p_f[ibra * 30 + 24] = HRR_INT__s_p_s_g[ibra * 15 + 8] - ( hCD[2] * HRR_INT__s_p_s_f[ibra * 10 + 4] );

                    HRR_INT__s_p_p_f[ibra * 30 + 25] = HRR_INT__s_p_s_g[ibra * 15 + 9] - ( hCD[2] * HRR_INT__s_p_s_f[ibra * 10 + 5] );

                    HRR_INT__s_p_p_f[ibra * 30 + 26] = HRR_INT__s_p_s_g[ibra * 15 + 11] - ( hCD[2] * HRR_INT__s_p_s_f[ibra * 10 + 6] );

                    HRR_INT__s_p_p_f[ibra * 30 + 27] = HRR_INT__s_p_s_g[ibra * 15 + 12] - ( hCD[2] * HRR_INT__s_p_s_f[ibra * 10 + 7] );

                    HRR_INT__s_p_p_f[ibra * 30 + 28] = HRR_INT__s_p_s_g[ibra * 15 + 13] - ( hCD[2] * HRR_INT__s_p_s_f[ibra * 10 + 8] );

                    HRR_INT__s_p_p_f[ibra * 30 + 29] = HRR_INT__s_p_s_g[ibra * 15 + 14] - ( hCD[2] * HRR_INT__s_p_s_f[ibra * 10 + 9] );

                }


            }  // close HRR loop


        }   // close loop cdbatch

        istart = iend;
    }  // close loop over ab

    return P.nshell12_clip * Q.nshell12_clip;
}

