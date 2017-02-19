#include "simint/boys/boys.h"
#include "simint/ostei/gen/ostei_generated.h"
#include "simint/vectorization/vectorization.h"
#include <math.h>
#include <string.h>


int ostei_d_f_p_s(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__d_f_p_s)
{

    SIMINT_ASSUME_ALIGN_DBL(work);
    SIMINT_ASSUME_ALIGN_DBL(INT__d_f_p_s);
    int ab, cd, abcd;
    int istart, jstart;
    int iprimcd, nprim_icd, icd;
    const int check_screen = (screen_tol > 0.0);
    int i, j;
    int n;
    int not_screened;
    int real_abcd;
    int iket;

    // partition workspace
    double * const INT__s_f_p_s = work + (SIMINT_NSHELL_SIMD * 0);
    double * const INT__s_g_p_s = work + (SIMINT_NSHELL_SIMD * 30);
    double * const INT__s_h_p_s = work + (SIMINT_NSHELL_SIMD * 75);
    SIMINT_DBLTYPE * const primwork = (SIMINT_DBLTYPE *)(work + SIMINT_NSHELL_SIMD*138);
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_s = primwork + 0;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_s = primwork + 7;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_s = primwork + 25;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_s = primwork + 55;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_p_s = primwork + 95;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s = primwork + 125;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_p_s = primwork + 170;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_s = primwork + 215;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_p_s = primwork + 257;
    double * const hrrwork = (double *)(primwork + 320);
    double * const HRR_INT__p_f_p_s = hrrwork + 0;
    double * const HRR_INT__p_g_p_s = hrrwork + 90;


    // Create constants
    const SIMINT_DBLTYPE const_1 = SIMINT_DBLSET1(1);
    const SIMINT_DBLTYPE const_2 = SIMINT_DBLSET1(2);
    const SIMINT_DBLTYPE const_3 = SIMINT_DBLSET1(3);
    const SIMINT_DBLTYPE const_4 = SIMINT_DBLSET1(4);
    const SIMINT_DBLTYPE const_5 = SIMINT_DBLSET1(5);
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
            memset(work, 0, SIMINT_NSHELL_SIMD * 138 * sizeof(double));
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
                double * restrict PRIM_PTR_INT__s_f_p_s = INT__s_f_p_s + abcd * 30;
                double * restrict PRIM_PTR_INT__s_g_p_s = INT__s_g_p_s + abcd * 45;
                double * restrict PRIM_PTR_INT__s_h_p_s = INT__s_h_p_s + abcd * 63;



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
                            PRIM_PTR_INT__s_f_p_s += 30;
                            PRIM_PTR_INT__s_g_p_s += 45;
                            PRIM_PTR_INT__s_h_p_s += 63;
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
                            PRIM_PTR_INT__s_f_p_s += lastoffset*30;
                            PRIM_PTR_INT__s_g_p_s += lastoffset*45;
                            PRIM_PTR_INT__s_h_p_s += lastoffset*63;
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
                    const SIMINT_DBLTYPE Q_PA[3] = { SIMINT_DBLLOAD(Q.PA_x, j), SIMINT_DBLLOAD(Q.PA_y, j), SIMINT_DBLLOAD(Q.PA_z, j) };

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
                    // Maximum v value: 6
                    //////////////////////////////////////////////
                    // The parameter to the Fjt function
                    const SIMINT_DBLTYPE F_x = SIMINT_MUL(R2, alpha);


                    const SIMINT_DBLTYPE Q_prefac = mask_load(nlane, Q.prefac + j);


                    boys_F_split(PRIM_INT__s_s_s_s, F_x, 6);
                    SIMINT_DBLTYPE prefac = SIMINT_SQRT(one_over_PQalpha_sum);
                    prefac = SIMINT_MUL(SIMINT_MUL(P_prefac, Q_prefac), prefac);
                    for(n = 0; n <= 6; n++)
                        PRIM_INT__s_s_s_s[n] = SIMINT_MUL(PRIM_INT__s_s_s_s[n], prefac);

                    //////////////////////////////////////////////
                    // Primitive integrals: Vertical recurrance
                    //////////////////////////////////////////////

                    const SIMINT_DBLTYPE vrr_const_1_over_2p = one_over_2p;
                    const SIMINT_DBLTYPE vrr_const_2_over_2p = SIMINT_MUL(const_2, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_3_over_2p = SIMINT_MUL(const_3, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_4_over_2p = SIMINT_MUL(const_4, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_1_over_2pq = one_over_2pq;
                    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(const_2, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_3_over_2pq = SIMINT_MUL(const_3, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_4_over_2pq = SIMINT_MUL(const_4, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_5_over_2pq = SIMINT_MUL(const_5, one_over_2pq);



                    // Forming PRIM_INT__s_p_s_s[6 * 3];
                    for(n = 0; n < 6; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_p_s_s[n * 3 + 0] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_p_s_s[n * 3 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_s_s[n * 3 + 0]);

                        PRIM_INT__s_p_s_s[n * 3 + 1] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_p_s_s[n * 3 + 1] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_s_s[n * 3 + 1]);

                        PRIM_INT__s_p_s_s[n * 3 + 2] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_p_s_s[n * 3 + 2] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_s_s[n * 3 + 2]);

                    }



                    // Forming PRIM_INT__s_d_s_s[5 * 6];
                    for(n = 0; n < 5; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_d_s_s[n * 6 + 0] = SIMINT_MUL(P_PB[0], PRIM_INT__s_p_s_s[n * 3 + 0]);
                        PRIM_INT__s_d_s_s[n * 6 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_d_s_s[n * 6 + 0]);
                        PRIM_INT__s_d_s_s[n * 6 + 0] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_d_s_s[n * 6 + 0]);

                        PRIM_INT__s_d_s_s[n * 6 + 1] = SIMINT_MUL(P_PB[1], PRIM_INT__s_p_s_s[n * 3 + 0]);
                        PRIM_INT__s_d_s_s[n * 6 + 1] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_d_s_s[n * 6 + 1]);

                        PRIM_INT__s_d_s_s[n * 6 + 2] = SIMINT_MUL(P_PB[2], PRIM_INT__s_p_s_s[n * 3 + 0]);
                        PRIM_INT__s_d_s_s[n * 6 + 2] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_d_s_s[n * 6 + 2]);

                        PRIM_INT__s_d_s_s[n * 6 + 3] = SIMINT_MUL(P_PB[1], PRIM_INT__s_p_s_s[n * 3 + 1]);
                        PRIM_INT__s_d_s_s[n * 6 + 3] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_d_s_s[n * 6 + 3]);
                        PRIM_INT__s_d_s_s[n * 6 + 3] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_d_s_s[n * 6 + 3]);

                        PRIM_INT__s_d_s_s[n * 6 + 4] = SIMINT_MUL(P_PB[2], PRIM_INT__s_p_s_s[n * 3 + 1]);
                        PRIM_INT__s_d_s_s[n * 6 + 4] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_d_s_s[n * 6 + 4]);

                        PRIM_INT__s_d_s_s[n * 6 + 5] = SIMINT_MUL(P_PB[2], PRIM_INT__s_p_s_s[n * 3 + 2]);
                        PRIM_INT__s_d_s_s[n * 6 + 5] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_d_s_s[n * 6 + 5]);
                        PRIM_INT__s_d_s_s[n * 6 + 5] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_d_s_s[n * 6 + 5]);

                    }



                    // Forming PRIM_INT__s_f_s_s[4 * 10];
                    for(n = 0; n < 4; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_f_s_s[n * 10 + 0] = SIMINT_MUL(P_PB[0], PRIM_INT__s_d_s_s[n * 6 + 0]);
                        PRIM_INT__s_f_s_s[n * 10 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_f_s_s[n * 10 + 0]);
                        PRIM_INT__s_f_s_s[n * 10 + 0] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_s_s[n * 3 + 0]), PRIM_INT__s_f_s_s[n * 10 + 0]);

                        PRIM_INT__s_f_s_s[n * 10 + 1] = SIMINT_MUL(P_PB[1], PRIM_INT__s_d_s_s[n * 6 + 0]);
                        PRIM_INT__s_f_s_s[n * 10 + 1] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_f_s_s[n * 10 + 1]);

                        PRIM_INT__s_f_s_s[n * 10 + 2] = SIMINT_MUL(P_PB[2], PRIM_INT__s_d_s_s[n * 6 + 0]);
                        PRIM_INT__s_f_s_s[n * 10 + 2] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_f_s_s[n * 10 + 2]);

                        PRIM_INT__s_f_s_s[n * 10 + 3] = SIMINT_MUL(P_PB[0], PRIM_INT__s_d_s_s[n * 6 + 3]);
                        PRIM_INT__s_f_s_s[n * 10 + 3] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_f_s_s[n * 10 + 3]);

                        PRIM_INT__s_f_s_s[n * 10 + 4] = SIMINT_MUL(P_PB[2], PRIM_INT__s_d_s_s[n * 6 + 1]);
                        PRIM_INT__s_f_s_s[n * 10 + 4] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_f_s_s[n * 10 + 4]);

                        PRIM_INT__s_f_s_s[n * 10 + 5] = SIMINT_MUL(P_PB[0], PRIM_INT__s_d_s_s[n * 6 + 5]);
                        PRIM_INT__s_f_s_s[n * 10 + 5] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_f_s_s[n * 10 + 5]);

                        PRIM_INT__s_f_s_s[n * 10 + 6] = SIMINT_MUL(P_PB[1], PRIM_INT__s_d_s_s[n * 6 + 3]);
                        PRIM_INT__s_f_s_s[n * 10 + 6] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_f_s_s[n * 10 + 6]);
                        PRIM_INT__s_f_s_s[n * 10 + 6] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_s_s[n * 3 + 1]), PRIM_INT__s_f_s_s[n * 10 + 6]);

                        PRIM_INT__s_f_s_s[n * 10 + 7] = SIMINT_MUL(P_PB[2], PRIM_INT__s_d_s_s[n * 6 + 3]);
                        PRIM_INT__s_f_s_s[n * 10 + 7] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_f_s_s[n * 10 + 7]);

                        PRIM_INT__s_f_s_s[n * 10 + 8] = SIMINT_MUL(P_PB[1], PRIM_INT__s_d_s_s[n * 6 + 5]);
                        PRIM_INT__s_f_s_s[n * 10 + 8] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_f_s_s[n * 10 + 8]);

                        PRIM_INT__s_f_s_s[n * 10 + 9] = SIMINT_MUL(P_PB[2], PRIM_INT__s_d_s_s[n * 6 + 5]);
                        PRIM_INT__s_f_s_s[n * 10 + 9] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_f_s_s[n * 10 + 9]);
                        PRIM_INT__s_f_s_s[n * 10 + 9] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_s_s[n * 3 + 2]), PRIM_INT__s_f_s_s[n * 10 + 9]);

                    }



                    // Forming PRIM_INT__s_f_p_s[1 * 30];
                    for(n = 0; n < 1; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_f_p_s[n * 30 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_f_s_s[n * 10 + 0]);
                        PRIM_INT__s_f_p_s[n * 30 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 0], PRIM_INT__s_f_p_s[n * 30 + 0]);
                        PRIM_INT__s_f_p_s[n * 30 + 0] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_f_p_s[n * 30 + 0]);

                        PRIM_INT__s_f_p_s[n * 30 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_f_s_s[n * 10 + 0]);
                        PRIM_INT__s_f_p_s[n * 30 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 0], PRIM_INT__s_f_p_s[n * 30 + 1]);

                        PRIM_INT__s_f_p_s[n * 30 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_f_s_s[n * 10 + 0]);
                        PRIM_INT__s_f_p_s[n * 30 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 0], PRIM_INT__s_f_p_s[n * 30 + 2]);

                        PRIM_INT__s_f_p_s[n * 30 + 3] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_f_s_s[n * 10 + 1]);
                        PRIM_INT__s_f_p_s[n * 30 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 1], PRIM_INT__s_f_p_s[n * 30 + 3]);
                        PRIM_INT__s_f_p_s[n * 30 + 3] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_f_p_s[n * 30 + 3]);

                        PRIM_INT__s_f_p_s[n * 30 + 4] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_f_s_s[n * 10 + 1]);
                        PRIM_INT__s_f_p_s[n * 30 + 4] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 1], PRIM_INT__s_f_p_s[n * 30 + 4]);
                        PRIM_INT__s_f_p_s[n * 30 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_f_p_s[n * 30 + 4]);

                        PRIM_INT__s_f_p_s[n * 30 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_f_s_s[n * 10 + 1]);
                        PRIM_INT__s_f_p_s[n * 30 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 1], PRIM_INT__s_f_p_s[n * 30 + 5]);

                        PRIM_INT__s_f_p_s[n * 30 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_f_s_s[n * 10 + 2]);
                        PRIM_INT__s_f_p_s[n * 30 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 2], PRIM_INT__s_f_p_s[n * 30 + 6]);
                        PRIM_INT__s_f_p_s[n * 30 + 6] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_f_p_s[n * 30 + 6]);

                        PRIM_INT__s_f_p_s[n * 30 + 7] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_f_s_s[n * 10 + 2]);
                        PRIM_INT__s_f_p_s[n * 30 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 2], PRIM_INT__s_f_p_s[n * 30 + 7]);

                        PRIM_INT__s_f_p_s[n * 30 + 8] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_f_s_s[n * 10 + 2]);
                        PRIM_INT__s_f_p_s[n * 30 + 8] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 2], PRIM_INT__s_f_p_s[n * 30 + 8]);
                        PRIM_INT__s_f_p_s[n * 30 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_f_p_s[n * 30 + 8]);

                        PRIM_INT__s_f_p_s[n * 30 + 9] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_f_s_s[n * 10 + 3]);
                        PRIM_INT__s_f_p_s[n * 30 + 9] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 3], PRIM_INT__s_f_p_s[n * 30 + 9]);
                        PRIM_INT__s_f_p_s[n * 30 + 9] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_f_p_s[n * 30 + 9]);

                        PRIM_INT__s_f_p_s[n * 30 + 10] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_f_s_s[n * 10 + 3]);
                        PRIM_INT__s_f_p_s[n * 30 + 10] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 3], PRIM_INT__s_f_p_s[n * 30 + 10]);
                        PRIM_INT__s_f_p_s[n * 30 + 10] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_f_p_s[n * 30 + 10]);

                        PRIM_INT__s_f_p_s[n * 30 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_f_s_s[n * 10 + 3]);
                        PRIM_INT__s_f_p_s[n * 30 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 3], PRIM_INT__s_f_p_s[n * 30 + 11]);

                        PRIM_INT__s_f_p_s[n * 30 + 12] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_f_s_s[n * 10 + 4]);
                        PRIM_INT__s_f_p_s[n * 30 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 4], PRIM_INT__s_f_p_s[n * 30 + 12]);
                        PRIM_INT__s_f_p_s[n * 30 + 12] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_f_p_s[n * 30 + 12]);

                        PRIM_INT__s_f_p_s[n * 30 + 13] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_f_s_s[n * 10 + 4]);
                        PRIM_INT__s_f_p_s[n * 30 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 4], PRIM_INT__s_f_p_s[n * 30 + 13]);
                        PRIM_INT__s_f_p_s[n * 30 + 13] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_f_p_s[n * 30 + 13]);

                        PRIM_INT__s_f_p_s[n * 30 + 14] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_f_s_s[n * 10 + 4]);
                        PRIM_INT__s_f_p_s[n * 30 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 4], PRIM_INT__s_f_p_s[n * 30 + 14]);
                        PRIM_INT__s_f_p_s[n * 30 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_f_p_s[n * 30 + 14]);

                        PRIM_INT__s_f_p_s[n * 30 + 15] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_f_s_s[n * 10 + 5]);
                        PRIM_INT__s_f_p_s[n * 30 + 15] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 5], PRIM_INT__s_f_p_s[n * 30 + 15]);
                        PRIM_INT__s_f_p_s[n * 30 + 15] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_f_p_s[n * 30 + 15]);

                        PRIM_INT__s_f_p_s[n * 30 + 16] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_f_s_s[n * 10 + 5]);
                        PRIM_INT__s_f_p_s[n * 30 + 16] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 5], PRIM_INT__s_f_p_s[n * 30 + 16]);

                        PRIM_INT__s_f_p_s[n * 30 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_f_s_s[n * 10 + 5]);
                        PRIM_INT__s_f_p_s[n * 30 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 5], PRIM_INT__s_f_p_s[n * 30 + 17]);
                        PRIM_INT__s_f_p_s[n * 30 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_f_p_s[n * 30 + 17]);

                        PRIM_INT__s_f_p_s[n * 30 + 18] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_f_s_s[n * 10 + 6]);
                        PRIM_INT__s_f_p_s[n * 30 + 18] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 6], PRIM_INT__s_f_p_s[n * 30 + 18]);

                        PRIM_INT__s_f_p_s[n * 30 + 19] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_f_s_s[n * 10 + 6]);
                        PRIM_INT__s_f_p_s[n * 30 + 19] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 6], PRIM_INT__s_f_p_s[n * 30 + 19]);
                        PRIM_INT__s_f_p_s[n * 30 + 19] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_f_p_s[n * 30 + 19]);

                        PRIM_INT__s_f_p_s[n * 30 + 20] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_f_s_s[n * 10 + 6]);
                        PRIM_INT__s_f_p_s[n * 30 + 20] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 6], PRIM_INT__s_f_p_s[n * 30 + 20]);

                        PRIM_INT__s_f_p_s[n * 30 + 21] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_f_s_s[n * 10 + 7]);
                        PRIM_INT__s_f_p_s[n * 30 + 21] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 7], PRIM_INT__s_f_p_s[n * 30 + 21]);

                        PRIM_INT__s_f_p_s[n * 30 + 22] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_f_s_s[n * 10 + 7]);
                        PRIM_INT__s_f_p_s[n * 30 + 22] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 7], PRIM_INT__s_f_p_s[n * 30 + 22]);
                        PRIM_INT__s_f_p_s[n * 30 + 22] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_f_p_s[n * 30 + 22]);

                        PRIM_INT__s_f_p_s[n * 30 + 23] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_f_s_s[n * 10 + 7]);
                        PRIM_INT__s_f_p_s[n * 30 + 23] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 7], PRIM_INT__s_f_p_s[n * 30 + 23]);
                        PRIM_INT__s_f_p_s[n * 30 + 23] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_f_p_s[n * 30 + 23]);

                        PRIM_INT__s_f_p_s[n * 30 + 24] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_f_s_s[n * 10 + 8]);
                        PRIM_INT__s_f_p_s[n * 30 + 24] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 8], PRIM_INT__s_f_p_s[n * 30 + 24]);

                        PRIM_INT__s_f_p_s[n * 30 + 25] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_f_s_s[n * 10 + 8]);
                        PRIM_INT__s_f_p_s[n * 30 + 25] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 8], PRIM_INT__s_f_p_s[n * 30 + 25]);
                        PRIM_INT__s_f_p_s[n * 30 + 25] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_f_p_s[n * 30 + 25]);

                        PRIM_INT__s_f_p_s[n * 30 + 26] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_f_s_s[n * 10 + 8]);
                        PRIM_INT__s_f_p_s[n * 30 + 26] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 8], PRIM_INT__s_f_p_s[n * 30 + 26]);
                        PRIM_INT__s_f_p_s[n * 30 + 26] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_f_p_s[n * 30 + 26]);

                        PRIM_INT__s_f_p_s[n * 30 + 27] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_f_s_s[n * 10 + 9]);
                        PRIM_INT__s_f_p_s[n * 30 + 27] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 9], PRIM_INT__s_f_p_s[n * 30 + 27]);

                        PRIM_INT__s_f_p_s[n * 30 + 28] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_f_s_s[n * 10 + 9]);
                        PRIM_INT__s_f_p_s[n * 30 + 28] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 9], PRIM_INT__s_f_p_s[n * 30 + 28]);

                        PRIM_INT__s_f_p_s[n * 30 + 29] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_f_s_s[n * 10 + 9]);
                        PRIM_INT__s_f_p_s[n * 30 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 9], PRIM_INT__s_f_p_s[n * 30 + 29]);
                        PRIM_INT__s_f_p_s[n * 30 + 29] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_f_p_s[n * 30 + 29]);

                    }



                    // Forming PRIM_INT__s_g_s_s[3 * 15];
                    for(n = 0; n < 3; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_g_s_s[n * 15 + 0] = SIMINT_MUL(P_PB[0], PRIM_INT__s_f_s_s[n * 10 + 0]);
                        PRIM_INT__s_g_s_s[n * 15 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 0], PRIM_INT__s_g_s_s[n * 15 + 0]);
                        PRIM_INT__s_g_s_s[n * 15 + 0] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_s_s[n * 6 + 0]), PRIM_INT__s_g_s_s[n * 15 + 0]);

                        PRIM_INT__s_g_s_s[n * 15 + 1] = SIMINT_MUL(P_PB[1], PRIM_INT__s_f_s_s[n * 10 + 0]);
                        PRIM_INT__s_g_s_s[n * 15 + 1] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 0], PRIM_INT__s_g_s_s[n * 15 + 1]);

                        PRIM_INT__s_g_s_s[n * 15 + 2] = SIMINT_MUL(P_PB[2], PRIM_INT__s_f_s_s[n * 10 + 0]);
                        PRIM_INT__s_g_s_s[n * 15 + 2] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 0], PRIM_INT__s_g_s_s[n * 15 + 2]);

                        PRIM_INT__s_g_s_s[n * 15 + 3] = SIMINT_MUL(P_PB[1], PRIM_INT__s_f_s_s[n * 10 + 1]);
                        PRIM_INT__s_g_s_s[n * 15 + 3] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 1], PRIM_INT__s_g_s_s[n * 15 + 3]);
                        PRIM_INT__s_g_s_s[n * 15 + 3] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_s_s[n * 6 + 0]), PRIM_INT__s_g_s_s[n * 15 + 3]);

                        PRIM_INT__s_g_s_s[n * 15 + 4] = SIMINT_MUL(P_PB[2], PRIM_INT__s_f_s_s[n * 10 + 1]);
                        PRIM_INT__s_g_s_s[n * 15 + 4] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 1], PRIM_INT__s_g_s_s[n * 15 + 4]);

                        PRIM_INT__s_g_s_s[n * 15 + 5] = SIMINT_MUL(P_PB[2], PRIM_INT__s_f_s_s[n * 10 + 2]);
                        PRIM_INT__s_g_s_s[n * 15 + 5] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 2], PRIM_INT__s_g_s_s[n * 15 + 5]);
                        PRIM_INT__s_g_s_s[n * 15 + 5] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_s_s[n * 6 + 0]), PRIM_INT__s_g_s_s[n * 15 + 5]);

                        PRIM_INT__s_g_s_s[n * 15 + 6] = SIMINT_MUL(P_PB[0], PRIM_INT__s_f_s_s[n * 10 + 6]);
                        PRIM_INT__s_g_s_s[n * 15 + 6] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 6], PRIM_INT__s_g_s_s[n * 15 + 6]);

                        PRIM_INT__s_g_s_s[n * 15 + 7] = SIMINT_MUL(P_PB[2], PRIM_INT__s_f_s_s[n * 10 + 3]);
                        PRIM_INT__s_g_s_s[n * 15 + 7] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 3], PRIM_INT__s_g_s_s[n * 15 + 7]);

                        PRIM_INT__s_g_s_s[n * 15 + 8] = SIMINT_MUL(P_PB[1], PRIM_INT__s_f_s_s[n * 10 + 5]);
                        PRIM_INT__s_g_s_s[n * 15 + 8] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 5], PRIM_INT__s_g_s_s[n * 15 + 8]);

                        PRIM_INT__s_g_s_s[n * 15 + 9] = SIMINT_MUL(P_PB[0], PRIM_INT__s_f_s_s[n * 10 + 9]);
                        PRIM_INT__s_g_s_s[n * 15 + 9] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 9], PRIM_INT__s_g_s_s[n * 15 + 9]);

                        PRIM_INT__s_g_s_s[n * 15 + 10] = SIMINT_MUL(P_PB[1], PRIM_INT__s_f_s_s[n * 10 + 6]);
                        PRIM_INT__s_g_s_s[n * 15 + 10] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 6], PRIM_INT__s_g_s_s[n * 15 + 10]);
                        PRIM_INT__s_g_s_s[n * 15 + 10] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_s_s[n * 6 + 3]), PRIM_INT__s_g_s_s[n * 15 + 10]);

                        PRIM_INT__s_g_s_s[n * 15 + 11] = SIMINT_MUL(P_PB[2], PRIM_INT__s_f_s_s[n * 10 + 6]);
                        PRIM_INT__s_g_s_s[n * 15 + 11] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 6], PRIM_INT__s_g_s_s[n * 15 + 11]);

                        PRIM_INT__s_g_s_s[n * 15 + 12] = SIMINT_MUL(P_PB[2], PRIM_INT__s_f_s_s[n * 10 + 7]);
                        PRIM_INT__s_g_s_s[n * 15 + 12] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 7], PRIM_INT__s_g_s_s[n * 15 + 12]);
                        PRIM_INT__s_g_s_s[n * 15 + 12] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_s_s[n * 6 + 3]), PRIM_INT__s_g_s_s[n * 15 + 12]);

                        PRIM_INT__s_g_s_s[n * 15 + 13] = SIMINT_MUL(P_PB[1], PRIM_INT__s_f_s_s[n * 10 + 9]);
                        PRIM_INT__s_g_s_s[n * 15 + 13] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 9], PRIM_INT__s_g_s_s[n * 15 + 13]);

                        PRIM_INT__s_g_s_s[n * 15 + 14] = SIMINT_MUL(P_PB[2], PRIM_INT__s_f_s_s[n * 10 + 9]);
                        PRIM_INT__s_g_s_s[n * 15 + 14] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 9], PRIM_INT__s_g_s_s[n * 15 + 14]);
                        PRIM_INT__s_g_s_s[n * 15 + 14] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_s_s[n * 6 + 5]), PRIM_INT__s_g_s_s[n * 15 + 14]);

                    }


                    VRR_K_s_g_p_s(
                            PRIM_INT__s_g_p_s,
                            PRIM_INT__s_g_s_s,
                            PRIM_INT__s_f_s_s,
                            Q_PA,
                            aoq_PQ,
                            one_over_2pq,
                            1);


                    VRR_J_s_h_s_s(
                            PRIM_INT__s_h_s_s,
                            PRIM_INT__s_g_s_s,
                            PRIM_INT__s_f_s_s,
                            P_PB,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            2);


                    VRR_K_s_h_p_s(
                            PRIM_INT__s_h_p_s,
                            PRIM_INT__s_h_s_s,
                            PRIM_INT__s_g_s_s,
                            Q_PA,
                            aoq_PQ,
                            one_over_2pq,
                            1);




                    ////////////////////////////////////
                    // Accumulate contracted integrals
                    ////////////////////////////////////
                    if(lastoffset == 0)
                    {
                        contract_all(30, PRIM_INT__s_f_p_s, PRIM_PTR_INT__s_f_p_s);
                        contract_all(45, PRIM_INT__s_g_p_s, PRIM_PTR_INT__s_g_p_s);
                        contract_all(63, PRIM_INT__s_h_p_s, PRIM_PTR_INT__s_h_p_s);
                    }
                    else
                    {
                        contract(30, shelloffsets, PRIM_INT__s_f_p_s, PRIM_PTR_INT__s_f_p_s);
                        contract(45, shelloffsets, PRIM_INT__s_g_p_s, PRIM_PTR_INT__s_g_p_s);
                        contract(63, shelloffsets, PRIM_INT__s_h_p_s, PRIM_PTR_INT__s_h_p_s);
                        PRIM_PTR_INT__s_f_p_s += lastoffset*30;
                        PRIM_PTR_INT__s_g_p_s += lastoffset*45;
                        PRIM_PTR_INT__s_h_p_s += lastoffset*63;
                    }

                }  // close loop over j
            }  // close loop over i
            
            //Advance to the next batch
            jstart = SIMINT_SIMD_ROUND(jend);
            
            //////////////////////////////////////////////
            // Contracted integrals: Horizontal recurrance
            //////////////////////////////////////////////


            const double hAB[3] = { P.AB_x[ab], P.AB_y[ab], P.AB_z[ab] };


            for(abcd = 0; abcd < nshellbatch; ++abcd, ++real_abcd)
            {

                // set up HRR pointers
                double const * restrict HRR_INT__s_f_p_s = INT__s_f_p_s + abcd * 30;
                double const * restrict HRR_INT__s_g_p_s = INT__s_g_p_s + abcd * 45;
                double const * restrict HRR_INT__s_h_p_s = INT__s_h_p_s + abcd * 63;
                double * restrict HRR_INT__d_f_p_s = INT__d_f_p_s + real_abcd * 180;

                // form INT__p_f_p_s
                for(iket = 0; iket < 3; ++iket)
                {
                    HRR_INT__p_f_p_s[0 * 3 + iket] = HRR_INT__s_g_p_s[0 * 3 + iket] - ( hAB[0] * HRR_INT__s_f_p_s[0 * 3 + iket] );

                    HRR_INT__p_f_p_s[1 * 3 + iket] = HRR_INT__s_g_p_s[1 * 3 + iket] - ( hAB[0] * HRR_INT__s_f_p_s[1 * 3 + iket] );

                    HRR_INT__p_f_p_s[2 * 3 + iket] = HRR_INT__s_g_p_s[2 * 3 + iket] - ( hAB[0] * HRR_INT__s_f_p_s[2 * 3 + iket] );

                    HRR_INT__p_f_p_s[3 * 3 + iket] = HRR_INT__s_g_p_s[3 * 3 + iket] - ( hAB[0] * HRR_INT__s_f_p_s[3 * 3 + iket] );

                    HRR_INT__p_f_p_s[4 * 3 + iket] = HRR_INT__s_g_p_s[4 * 3 + iket] - ( hAB[0] * HRR_INT__s_f_p_s[4 * 3 + iket] );

                    HRR_INT__p_f_p_s[5 * 3 + iket] = HRR_INT__s_g_p_s[5 * 3 + iket] - ( hAB[0] * HRR_INT__s_f_p_s[5 * 3 + iket] );

                    HRR_INT__p_f_p_s[6 * 3 + iket] = HRR_INT__s_g_p_s[6 * 3 + iket] - ( hAB[0] * HRR_INT__s_f_p_s[6 * 3 + iket] );

                    HRR_INT__p_f_p_s[7 * 3 + iket] = HRR_INT__s_g_p_s[7 * 3 + iket] - ( hAB[0] * HRR_INT__s_f_p_s[7 * 3 + iket] );

                    HRR_INT__p_f_p_s[8 * 3 + iket] = HRR_INT__s_g_p_s[8 * 3 + iket] - ( hAB[0] * HRR_INT__s_f_p_s[8 * 3 + iket] );

                    HRR_INT__p_f_p_s[9 * 3 + iket] = HRR_INT__s_g_p_s[9 * 3 + iket] - ( hAB[0] * HRR_INT__s_f_p_s[9 * 3 + iket] );

                    HRR_INT__p_f_p_s[10 * 3 + iket] = HRR_INT__s_g_p_s[1 * 3 + iket] - ( hAB[1] * HRR_INT__s_f_p_s[0 * 3 + iket] );

                    HRR_INT__p_f_p_s[11 * 3 + iket] = HRR_INT__s_g_p_s[3 * 3 + iket] - ( hAB[1] * HRR_INT__s_f_p_s[1 * 3 + iket] );

                    HRR_INT__p_f_p_s[12 * 3 + iket] = HRR_INT__s_g_p_s[4 * 3 + iket] - ( hAB[1] * HRR_INT__s_f_p_s[2 * 3 + iket] );

                    HRR_INT__p_f_p_s[13 * 3 + iket] = HRR_INT__s_g_p_s[6 * 3 + iket] - ( hAB[1] * HRR_INT__s_f_p_s[3 * 3 + iket] );

                    HRR_INT__p_f_p_s[14 * 3 + iket] = HRR_INT__s_g_p_s[7 * 3 + iket] - ( hAB[1] * HRR_INT__s_f_p_s[4 * 3 + iket] );

                    HRR_INT__p_f_p_s[15 * 3 + iket] = HRR_INT__s_g_p_s[8 * 3 + iket] - ( hAB[1] * HRR_INT__s_f_p_s[5 * 3 + iket] );

                    HRR_INT__p_f_p_s[16 * 3 + iket] = HRR_INT__s_g_p_s[10 * 3 + iket] - ( hAB[1] * HRR_INT__s_f_p_s[6 * 3 + iket] );

                    HRR_INT__p_f_p_s[17 * 3 + iket] = HRR_INT__s_g_p_s[11 * 3 + iket] - ( hAB[1] * HRR_INT__s_f_p_s[7 * 3 + iket] );

                    HRR_INT__p_f_p_s[18 * 3 + iket] = HRR_INT__s_g_p_s[12 * 3 + iket] - ( hAB[1] * HRR_INT__s_f_p_s[8 * 3 + iket] );

                    HRR_INT__p_f_p_s[19 * 3 + iket] = HRR_INT__s_g_p_s[13 * 3 + iket] - ( hAB[1] * HRR_INT__s_f_p_s[9 * 3 + iket] );

                    HRR_INT__p_f_p_s[20 * 3 + iket] = HRR_INT__s_g_p_s[2 * 3 + iket] - ( hAB[2] * HRR_INT__s_f_p_s[0 * 3 + iket] );

                    HRR_INT__p_f_p_s[21 * 3 + iket] = HRR_INT__s_g_p_s[4 * 3 + iket] - ( hAB[2] * HRR_INT__s_f_p_s[1 * 3 + iket] );

                    HRR_INT__p_f_p_s[22 * 3 + iket] = HRR_INT__s_g_p_s[5 * 3 + iket] - ( hAB[2] * HRR_INT__s_f_p_s[2 * 3 + iket] );

                    HRR_INT__p_f_p_s[23 * 3 + iket] = HRR_INT__s_g_p_s[7 * 3 + iket] - ( hAB[2] * HRR_INT__s_f_p_s[3 * 3 + iket] );

                    HRR_INT__p_f_p_s[24 * 3 + iket] = HRR_INT__s_g_p_s[8 * 3 + iket] - ( hAB[2] * HRR_INT__s_f_p_s[4 * 3 + iket] );

                    HRR_INT__p_f_p_s[25 * 3 + iket] = HRR_INT__s_g_p_s[9 * 3 + iket] - ( hAB[2] * HRR_INT__s_f_p_s[5 * 3 + iket] );

                    HRR_INT__p_f_p_s[26 * 3 + iket] = HRR_INT__s_g_p_s[11 * 3 + iket] - ( hAB[2] * HRR_INT__s_f_p_s[6 * 3 + iket] );

                    HRR_INT__p_f_p_s[27 * 3 + iket] = HRR_INT__s_g_p_s[12 * 3 + iket] - ( hAB[2] * HRR_INT__s_f_p_s[7 * 3 + iket] );

                    HRR_INT__p_f_p_s[28 * 3 + iket] = HRR_INT__s_g_p_s[13 * 3 + iket] - ( hAB[2] * HRR_INT__s_f_p_s[8 * 3 + iket] );

                    HRR_INT__p_f_p_s[29 * 3 + iket] = HRR_INT__s_g_p_s[14 * 3 + iket] - ( hAB[2] * HRR_INT__s_f_p_s[9 * 3 + iket] );

                }


                // form INT__p_g_p_s
                HRR_I_p_g(
                    HRR_INT__p_g_p_s,
                    HRR_INT__s_g_p_s,
                    HRR_INT__s_h_p_s,
                    hAB, 3);

                // form INT__d_f_p_s
                HRR_I_d_f(
                    HRR_INT__d_f_p_s,
                    HRR_INT__p_f_p_s,
                    HRR_INT__p_g_p_s,
                    hAB, 3);


            }  // close HRR loop


        }   // close loop cdbatch

        istart = iend;
    }  // close loop over ab

    return P.nshell12_clip * Q.nshell12_clip;
}

