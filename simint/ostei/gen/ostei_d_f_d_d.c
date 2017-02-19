#include "simint/boys/boys.h"
#include "simint/ostei/gen/ostei_generated.h"
#include "simint/vectorization/vectorization.h"
#include <math.h>
#include <string.h>


int ostei_d_f_d_d(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__d_f_d_d)
{

    SIMINT_ASSUME_ALIGN_DBL(work);
    SIMINT_ASSUME_ALIGN_DBL(INT__d_f_d_d);
    int ab, cd, abcd;
    int istart, jstart;
    int iprimcd, nprim_icd, icd;
    const int check_screen = (screen_tol > 0.0);
    int i, j;
    int n;
    int not_screened;
    int real_abcd;
    int iket;
    int ibra;

    // partition workspace
    double * const INT__s_f_d_s = work + (SIMINT_NSHELL_SIMD * 0);
    double * const INT__s_f_f_s = work + (SIMINT_NSHELL_SIMD * 60);
    double * const INT__s_f_g_s = work + (SIMINT_NSHELL_SIMD * 160);
    double * const INT__s_g_d_s = work + (SIMINT_NSHELL_SIMD * 310);
    double * const INT__s_g_f_s = work + (SIMINT_NSHELL_SIMD * 400);
    double * const INT__s_g_g_s = work + (SIMINT_NSHELL_SIMD * 550);
    double * const INT__s_h_d_s = work + (SIMINT_NSHELL_SIMD * 775);
    double * const INT__s_h_f_s = work + (SIMINT_NSHELL_SIMD * 901);
    double * const INT__s_h_g_s = work + (SIMINT_NSHELL_SIMD * 1111);
    SIMINT_DBLTYPE * const primwork = (SIMINT_DBLTYPE *)(work + SIMINT_NSHELL_SIMD*1426);
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_s = primwork + 0;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_p_s = primwork + 10;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_s = primwork + 22;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_p_s = primwork + 49;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_d_s = primwork + 85;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_s = primwork + 139;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_p_s = primwork + 187;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_d_s = primwork + 259;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_f_s = primwork + 367;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_s = primwork + 487;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_p_s = primwork + 557;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_d_s = primwork + 677;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_f_s = primwork + 857;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_g_s = primwork + 1057;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s = primwork + 1207;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_p_s = primwork + 1297;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_d_s = primwork + 1477;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_f_s = primwork + 1747;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_g_s = primwork + 2047;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_s = primwork + 2272;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_p_s = primwork + 2377;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_d_s = primwork + 2629;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_f_s = primwork + 3007;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_g_s = primwork + 3427;
    double * const hrrwork = (double *)(primwork + 3742);
    double * const HRR_INT__p_f_d_s = hrrwork + 0;
    double * const HRR_INT__p_f_f_s = hrrwork + 180;
    double * const HRR_INT__p_f_g_s = hrrwork + 480;
    double * const HRR_INT__p_g_d_s = hrrwork + 930;
    double * const HRR_INT__p_g_f_s = hrrwork + 1200;
    double * const HRR_INT__p_g_g_s = hrrwork + 1650;
    double * const HRR_INT__d_f_d_s = hrrwork + 2325;
    double * const HRR_INT__d_f_d_p = hrrwork + 2685;
    double * const HRR_INT__d_f_f_s = hrrwork + 3765;
    double * const HRR_INT__d_f_f_p = hrrwork + 4365;
    double * const HRR_INT__d_f_g_s = hrrwork + 6165;


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
            memset(work, 0, SIMINT_NSHELL_SIMD * 1426 * sizeof(double));
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
                double * restrict PRIM_PTR_INT__s_f_d_s = INT__s_f_d_s + abcd * 60;
                double * restrict PRIM_PTR_INT__s_f_f_s = INT__s_f_f_s + abcd * 100;
                double * restrict PRIM_PTR_INT__s_f_g_s = INT__s_f_g_s + abcd * 150;
                double * restrict PRIM_PTR_INT__s_g_d_s = INT__s_g_d_s + abcd * 90;
                double * restrict PRIM_PTR_INT__s_g_f_s = INT__s_g_f_s + abcd * 150;
                double * restrict PRIM_PTR_INT__s_g_g_s = INT__s_g_g_s + abcd * 225;
                double * restrict PRIM_PTR_INT__s_h_d_s = INT__s_h_d_s + abcd * 126;
                double * restrict PRIM_PTR_INT__s_h_f_s = INT__s_h_f_s + abcd * 210;
                double * restrict PRIM_PTR_INT__s_h_g_s = INT__s_h_g_s + abcd * 315;



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
                            PRIM_PTR_INT__s_f_d_s += 60;
                            PRIM_PTR_INT__s_f_f_s += 100;
                            PRIM_PTR_INT__s_f_g_s += 150;
                            PRIM_PTR_INT__s_g_d_s += 90;
                            PRIM_PTR_INT__s_g_f_s += 150;
                            PRIM_PTR_INT__s_g_g_s += 225;
                            PRIM_PTR_INT__s_h_d_s += 126;
                            PRIM_PTR_INT__s_h_f_s += 210;
                            PRIM_PTR_INT__s_h_g_s += 315;
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
                            PRIM_PTR_INT__s_f_d_s += lastoffset*60;
                            PRIM_PTR_INT__s_f_f_s += lastoffset*100;
                            PRIM_PTR_INT__s_f_g_s += lastoffset*150;
                            PRIM_PTR_INT__s_g_d_s += lastoffset*90;
                            PRIM_PTR_INT__s_g_f_s += lastoffset*150;
                            PRIM_PTR_INT__s_g_g_s += lastoffset*225;
                            PRIM_PTR_INT__s_h_d_s += lastoffset*126;
                            PRIM_PTR_INT__s_h_f_s += lastoffset*210;
                            PRIM_PTR_INT__s_h_g_s += lastoffset*315;
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
                    // Maximum v value: 9
                    //////////////////////////////////////////////
                    // The parameter to the Fjt function
                    const SIMINT_DBLTYPE F_x = SIMINT_MUL(R2, alpha);


                    const SIMINT_DBLTYPE Q_prefac = mask_load(nlane, Q.prefac + j);


                    boys_F_split(PRIM_INT__s_s_s_s, F_x, 9);
                    SIMINT_DBLTYPE prefac = SIMINT_SQRT(one_over_PQalpha_sum);
                    prefac = SIMINT_MUL(SIMINT_MUL(P_prefac, Q_prefac), prefac);
                    for(n = 0; n <= 9; n++)
                        PRIM_INT__s_s_s_s[n] = SIMINT_MUL(PRIM_INT__s_s_s_s[n], prefac);

                    //////////////////////////////////////////////
                    // Primitive integrals: Vertical recurrance
                    //////////////////////////////////////////////

                    const SIMINT_DBLTYPE vrr_const_1_over_2p = one_over_2p;
                    const SIMINT_DBLTYPE vrr_const_2_over_2p = SIMINT_MUL(const_2, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_3_over_2p = SIMINT_MUL(const_3, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_4_over_2p = SIMINT_MUL(const_4, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_1_over_2q = one_over_2q;
                    const SIMINT_DBLTYPE vrr_const_2_over_2q = SIMINT_MUL(const_2, one_over_2q);
                    const SIMINT_DBLTYPE vrr_const_3_over_2q = SIMINT_MUL(const_3, one_over_2q);
                    const SIMINT_DBLTYPE vrr_const_1_over_2pq = one_over_2pq;
                    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(const_2, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_3_over_2pq = SIMINT_MUL(const_3, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_4_over_2pq = SIMINT_MUL(const_4, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_5_over_2pq = SIMINT_MUL(const_5, one_over_2pq);



                    // Forming PRIM_INT__s_p_s_s[9 * 3];
                    for(n = 0; n < 9; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_p_s_s[n * 3 + 0] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_p_s_s[n * 3 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_s_s[n * 3 + 0]);

                        PRIM_INT__s_p_s_s[n * 3 + 1] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_p_s_s[n * 3 + 1] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_s_s[n * 3 + 1]);

                        PRIM_INT__s_p_s_s[n * 3 + 2] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_p_s_s[n * 3 + 2] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_s_s[n * 3 + 2]);

                    }



                    // Forming PRIM_INT__s_d_s_s[8 * 6];
                    for(n = 0; n < 8; ++n)  // loop over orders of auxiliary function
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



                    // Forming PRIM_INT__s_f_s_s[7 * 10];
                    for(n = 0; n < 7; ++n)  // loop over orders of auxiliary function
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



                    // Forming PRIM_INT__s_f_p_s[4 * 30];
                    for(n = 0; n < 4; ++n)  // loop over orders of auxiliary function
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



                    // Forming PRIM_INT__s_d_p_s[4 * 18];
                    for(n = 0; n < 4; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_d_p_s[n * 18 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_d_s_s[n * 6 + 0]);
                        PRIM_INT__s_d_p_s[n * 18 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_p_s[n * 18 + 0]);
                        PRIM_INT__s_d_p_s[n * 18 + 0] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_d_p_s[n * 18 + 0]);

                        PRIM_INT__s_d_p_s[n * 18 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_s_s[n * 6 + 0]);
                        PRIM_INT__s_d_p_s[n * 18 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_p_s[n * 18 + 1]);

                        PRIM_INT__s_d_p_s[n * 18 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_d_s_s[n * 6 + 0]);
                        PRIM_INT__s_d_p_s[n * 18 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_p_s[n * 18 + 2]);

                        PRIM_INT__s_d_p_s[n * 18 + 3] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_d_s_s[n * 6 + 1]);
                        PRIM_INT__s_d_p_s[n * 18 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_d_p_s[n * 18 + 3]);
                        PRIM_INT__s_d_p_s[n * 18 + 3] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_d_p_s[n * 18 + 3]);

                        PRIM_INT__s_d_p_s[n * 18 + 4] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_s_s[n * 6 + 1]);
                        PRIM_INT__s_d_p_s[n * 18 + 4] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_d_p_s[n * 18 + 4]);
                        PRIM_INT__s_d_p_s[n * 18 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_d_p_s[n * 18 + 4]);

                        PRIM_INT__s_d_p_s[n * 18 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_d_s_s[n * 6 + 1]);
                        PRIM_INT__s_d_p_s[n * 18 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_d_p_s[n * 18 + 5]);

                        PRIM_INT__s_d_p_s[n * 18 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_d_s_s[n * 6 + 2]);
                        PRIM_INT__s_d_p_s[n * 18 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_d_p_s[n * 18 + 6]);
                        PRIM_INT__s_d_p_s[n * 18 + 6] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_d_p_s[n * 18 + 6]);

                        PRIM_INT__s_d_p_s[n * 18 + 7] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_s_s[n * 6 + 2]);
                        PRIM_INT__s_d_p_s[n * 18 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_d_p_s[n * 18 + 7]);

                        PRIM_INT__s_d_p_s[n * 18 + 8] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_d_s_s[n * 6 + 2]);
                        PRIM_INT__s_d_p_s[n * 18 + 8] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_d_p_s[n * 18 + 8]);
                        PRIM_INT__s_d_p_s[n * 18 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_d_p_s[n * 18 + 8]);

                        PRIM_INT__s_d_p_s[n * 18 + 9] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_d_s_s[n * 6 + 3]);
                        PRIM_INT__s_d_p_s[n * 18 + 9] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_p_s[n * 18 + 9]);

                        PRIM_INT__s_d_p_s[n * 18 + 10] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_s_s[n * 6 + 3]);
                        PRIM_INT__s_d_p_s[n * 18 + 10] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_p_s[n * 18 + 10]);
                        PRIM_INT__s_d_p_s[n * 18 + 10] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_d_p_s[n * 18 + 10]);

                        PRIM_INT__s_d_p_s[n * 18 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_d_s_s[n * 6 + 3]);
                        PRIM_INT__s_d_p_s[n * 18 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_p_s[n * 18 + 11]);

                        PRIM_INT__s_d_p_s[n * 18 + 12] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_d_s_s[n * 6 + 4]);
                        PRIM_INT__s_d_p_s[n * 18 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_d_p_s[n * 18 + 12]);

                        PRIM_INT__s_d_p_s[n * 18 + 13] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_s_s[n * 6 + 4]);
                        PRIM_INT__s_d_p_s[n * 18 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_d_p_s[n * 18 + 13]);
                        PRIM_INT__s_d_p_s[n * 18 + 13] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_d_p_s[n * 18 + 13]);

                        PRIM_INT__s_d_p_s[n * 18 + 14] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_d_s_s[n * 6 + 4]);
                        PRIM_INT__s_d_p_s[n * 18 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_d_p_s[n * 18 + 14]);
                        PRIM_INT__s_d_p_s[n * 18 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_d_p_s[n * 18 + 14]);

                        PRIM_INT__s_d_p_s[n * 18 + 15] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_d_s_s[n * 6 + 5]);
                        PRIM_INT__s_d_p_s[n * 18 + 15] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_p_s[n * 18 + 15]);

                        PRIM_INT__s_d_p_s[n * 18 + 16] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_s_s[n * 6 + 5]);
                        PRIM_INT__s_d_p_s[n * 18 + 16] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_p_s[n * 18 + 16]);

                        PRIM_INT__s_d_p_s[n * 18 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_d_s_s[n * 6 + 5]);
                        PRIM_INT__s_d_p_s[n * 18 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_p_s[n * 18 + 17]);
                        PRIM_INT__s_d_p_s[n * 18 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_d_p_s[n * 18 + 17]);

                    }


                    VRR_K_s_f_d_s(
                            PRIM_INT__s_f_d_s,
                            PRIM_INT__s_f_p_s,
                            PRIM_INT__s_f_s_s,
                            PRIM_INT__s_d_p_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            3);



                    // Forming PRIM_INT__s_p_p_s[4 * 9];
                    for(n = 0; n < 4; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_p_p_s[n * 9 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_p_s_s[n * 3 + 0]);
                        PRIM_INT__s_p_p_s[n * 9 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_p_s[n * 9 + 0]);
                        PRIM_INT__s_p_p_s[n * 9 + 0] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_p_s[n * 9 + 0]);

                        PRIM_INT__s_p_p_s[n * 9 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_p_s_s[n * 3 + 0]);
                        PRIM_INT__s_p_p_s[n * 9 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_p_s[n * 9 + 1]);

                        PRIM_INT__s_p_p_s[n * 9 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_p_s_s[n * 3 + 0]);
                        PRIM_INT__s_p_p_s[n * 9 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_p_s[n * 9 + 2]);

                        PRIM_INT__s_p_p_s[n * 9 + 3] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_p_s_s[n * 3 + 1]);
                        PRIM_INT__s_p_p_s[n * 9 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_p_s[n * 9 + 3]);

                        PRIM_INT__s_p_p_s[n * 9 + 4] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_p_s_s[n * 3 + 1]);
                        PRIM_INT__s_p_p_s[n * 9 + 4] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_p_s[n * 9 + 4]);
                        PRIM_INT__s_p_p_s[n * 9 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_p_s[n * 9 + 4]);

                        PRIM_INT__s_p_p_s[n * 9 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_p_s_s[n * 3 + 1]);
                        PRIM_INT__s_p_p_s[n * 9 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_p_s[n * 9 + 5]);

                        PRIM_INT__s_p_p_s[n * 9 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_p_s_s[n * 3 + 2]);
                        PRIM_INT__s_p_p_s[n * 9 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_p_s[n * 9 + 6]);

                        PRIM_INT__s_p_p_s[n * 9 + 7] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_p_s_s[n * 3 + 2]);
                        PRIM_INT__s_p_p_s[n * 9 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_p_s[n * 9 + 7]);

                        PRIM_INT__s_p_p_s[n * 9 + 8] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_p_s_s[n * 3 + 2]);
                        PRIM_INT__s_p_p_s[n * 9 + 8] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_p_s[n * 9 + 8]);
                        PRIM_INT__s_p_p_s[n * 9 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_p_s[n * 9 + 8]);

                    }



                    // Forming PRIM_INT__s_d_d_s[3 * 36];
                    for(n = 0; n < 3; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_d_d_s[n * 36 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_d_p_s[n * 18 + 0]);
                        PRIM_INT__s_d_d_s[n * 36 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_p_s[(n+1) * 18 + 0], PRIM_INT__s_d_d_s[n * 36 + 0]);
                        PRIM_INT__s_d_d_s[n * 36 + 0] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_s_s[n * 6 + 0]), PRIM_INT__s_d_d_s[n * 36 + 0]);
                        PRIM_INT__s_d_d_s[n * 36 + 0] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_p_s[(n+1) * 9 + 0], PRIM_INT__s_d_d_s[n * 36 + 0]);

                        PRIM_INT__s_d_d_s[n * 36 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_p_s[n * 18 + 0]);
                        PRIM_INT__s_d_d_s[n * 36 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_p_s[(n+1) * 18 + 0], PRIM_INT__s_d_d_s[n * 36 + 1]);

                        PRIM_INT__s_d_d_s[n * 36 + 3] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_p_s[n * 18 + 1]);
                        PRIM_INT__s_d_d_s[n * 36 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_p_s[(n+1) * 18 + 1], PRIM_INT__s_d_d_s[n * 36 + 3]);
                        PRIM_INT__s_d_d_s[n * 36 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_s_s[n * 6 + 0]), PRIM_INT__s_d_d_s[n * 36 + 3]);

                        PRIM_INT__s_d_d_s[n * 36 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_d_p_s[n * 18 + 2]);
                        PRIM_INT__s_d_d_s[n * 36 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_p_s[(n+1) * 18 + 2], PRIM_INT__s_d_d_s[n * 36 + 5]);
                        PRIM_INT__s_d_d_s[n * 36 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_s_s[n * 6 + 0]), PRIM_INT__s_d_d_s[n * 36 + 5]);

                        PRIM_INT__s_d_d_s[n * 36 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_d_p_s[n * 18 + 3]);
                        PRIM_INT__s_d_d_s[n * 36 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_p_s[(n+1) * 18 + 3], PRIM_INT__s_d_d_s[n * 36 + 6]);
                        PRIM_INT__s_d_d_s[n * 36 + 6] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_d_s_s[n * 6 + 1]), PRIM_INT__s_d_d_s[n * 36 + 6]);
                        PRIM_INT__s_d_d_s[n * 36 + 6] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_p_s[(n+1) * 9 + 3], PRIM_INT__s_d_d_s[n * 36 + 6]);

                        PRIM_INT__s_d_d_s[n * 36 + 7] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_p_s[n * 18 + 3]);
                        PRIM_INT__s_d_d_s[n * 36 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_p_s[(n+1) * 18 + 3], PRIM_INT__s_d_d_s[n * 36 + 7]);
                        PRIM_INT__s_d_d_s[n * 36 + 7] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_p_s[(n+1) * 9 + 0], PRIM_INT__s_d_d_s[n * 36 + 7]);

                        PRIM_INT__s_d_d_s[n * 36 + 9] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_p_s[n * 18 + 4]);
                        PRIM_INT__s_d_d_s[n * 36 + 9] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_p_s[(n+1) * 18 + 4], PRIM_INT__s_d_d_s[n * 36 + 9]);
                        PRIM_INT__s_d_d_s[n * 36 + 9] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_d_s_s[n * 6 + 1]), PRIM_INT__s_d_d_s[n * 36 + 9]);
                        PRIM_INT__s_d_d_s[n * 36 + 9] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_p_s[(n+1) * 9 + 1], PRIM_INT__s_d_d_s[n * 36 + 9]);

                        PRIM_INT__s_d_d_s[n * 36 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_d_p_s[n * 18 + 5]);
                        PRIM_INT__s_d_d_s[n * 36 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_p_s[(n+1) * 18 + 5], PRIM_INT__s_d_d_s[n * 36 + 11]);
                        PRIM_INT__s_d_d_s[n * 36 + 11] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_d_s_s[n * 6 + 1]), PRIM_INT__s_d_d_s[n * 36 + 11]);

                        PRIM_INT__s_d_d_s[n * 36 + 12] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_d_p_s[n * 18 + 6]);
                        PRIM_INT__s_d_d_s[n * 36 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_p_s[(n+1) * 18 + 6], PRIM_INT__s_d_d_s[n * 36 + 12]);
                        PRIM_INT__s_d_d_s[n * 36 + 12] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_d_s_s[n * 6 + 2]), PRIM_INT__s_d_d_s[n * 36 + 12]);
                        PRIM_INT__s_d_d_s[n * 36 + 12] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_p_s[(n+1) * 9 + 6], PRIM_INT__s_d_d_s[n * 36 + 12]);

                        PRIM_INT__s_d_d_s[n * 36 + 13] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_p_s[n * 18 + 6]);
                        PRIM_INT__s_d_d_s[n * 36 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_p_s[(n+1) * 18 + 6], PRIM_INT__s_d_d_s[n * 36 + 13]);

                        PRIM_INT__s_d_d_s[n * 36 + 15] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_p_s[n * 18 + 7]);
                        PRIM_INT__s_d_d_s[n * 36 + 15] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_p_s[(n+1) * 18 + 7], PRIM_INT__s_d_d_s[n * 36 + 15]);
                        PRIM_INT__s_d_d_s[n * 36 + 15] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_d_s_s[n * 6 + 2]), PRIM_INT__s_d_d_s[n * 36 + 15]);

                        PRIM_INT__s_d_d_s[n * 36 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_d_p_s[n * 18 + 8]);
                        PRIM_INT__s_d_d_s[n * 36 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_p_s[(n+1) * 18 + 8], PRIM_INT__s_d_d_s[n * 36 + 17]);
                        PRIM_INT__s_d_d_s[n * 36 + 17] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_d_s_s[n * 6 + 2]), PRIM_INT__s_d_d_s[n * 36 + 17]);
                        PRIM_INT__s_d_d_s[n * 36 + 17] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_p_s[(n+1) * 9 + 2], PRIM_INT__s_d_d_s[n * 36 + 17]);

                        PRIM_INT__s_d_d_s[n * 36 + 18] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_d_p_s[n * 18 + 9]);
                        PRIM_INT__s_d_d_s[n * 36 + 18] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_p_s[(n+1) * 18 + 9], PRIM_INT__s_d_d_s[n * 36 + 18]);
                        PRIM_INT__s_d_d_s[n * 36 + 18] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_s_s[n * 6 + 3]), PRIM_INT__s_d_d_s[n * 36 + 18]);

                        PRIM_INT__s_d_d_s[n * 36 + 19] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_p_s[n * 18 + 9]);
                        PRIM_INT__s_d_d_s[n * 36 + 19] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_p_s[(n+1) * 18 + 9], PRIM_INT__s_d_d_s[n * 36 + 19]);
                        PRIM_INT__s_d_d_s[n * 36 + 19] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_p_s[(n+1) * 9 + 3], PRIM_INT__s_d_d_s[n * 36 + 19]);

                        PRIM_INT__s_d_d_s[n * 36 + 21] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_p_s[n * 18 + 10]);
                        PRIM_INT__s_d_d_s[n * 36 + 21] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_p_s[(n+1) * 18 + 10], PRIM_INT__s_d_d_s[n * 36 + 21]);
                        PRIM_INT__s_d_d_s[n * 36 + 21] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_s_s[n * 6 + 3]), PRIM_INT__s_d_d_s[n * 36 + 21]);
                        PRIM_INT__s_d_d_s[n * 36 + 21] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_p_s[(n+1) * 9 + 4], PRIM_INT__s_d_d_s[n * 36 + 21]);

                        PRIM_INT__s_d_d_s[n * 36 + 23] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_d_p_s[n * 18 + 11]);
                        PRIM_INT__s_d_d_s[n * 36 + 23] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_p_s[(n+1) * 18 + 11], PRIM_INT__s_d_d_s[n * 36 + 23]);
                        PRIM_INT__s_d_d_s[n * 36 + 23] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_s_s[n * 6 + 3]), PRIM_INT__s_d_d_s[n * 36 + 23]);

                        PRIM_INT__s_d_d_s[n * 36 + 24] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_d_p_s[n * 18 + 12]);
                        PRIM_INT__s_d_d_s[n * 36 + 24] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_p_s[(n+1) * 18 + 12], PRIM_INT__s_d_d_s[n * 36 + 24]);
                        PRIM_INT__s_d_d_s[n * 36 + 24] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_d_s_s[n * 6 + 4]), PRIM_INT__s_d_d_s[n * 36 + 24]);

                        PRIM_INT__s_d_d_s[n * 36 + 25] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_p_s[n * 18 + 12]);
                        PRIM_INT__s_d_d_s[n * 36 + 25] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_p_s[(n+1) * 18 + 12], PRIM_INT__s_d_d_s[n * 36 + 25]);
                        PRIM_INT__s_d_d_s[n * 36 + 25] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_p_s[(n+1) * 9 + 6], PRIM_INT__s_d_d_s[n * 36 + 25]);

                        PRIM_INT__s_d_d_s[n * 36 + 27] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_p_s[n * 18 + 13]);
                        PRIM_INT__s_d_d_s[n * 36 + 27] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_p_s[(n+1) * 18 + 13], PRIM_INT__s_d_d_s[n * 36 + 27]);
                        PRIM_INT__s_d_d_s[n * 36 + 27] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_d_s_s[n * 6 + 4]), PRIM_INT__s_d_d_s[n * 36 + 27]);
                        PRIM_INT__s_d_d_s[n * 36 + 27] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_p_s[(n+1) * 9 + 7], PRIM_INT__s_d_d_s[n * 36 + 27]);

                        PRIM_INT__s_d_d_s[n * 36 + 29] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_d_p_s[n * 18 + 14]);
                        PRIM_INT__s_d_d_s[n * 36 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_p_s[(n+1) * 18 + 14], PRIM_INT__s_d_d_s[n * 36 + 29]);
                        PRIM_INT__s_d_d_s[n * 36 + 29] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_d_s_s[n * 6 + 4]), PRIM_INT__s_d_d_s[n * 36 + 29]);
                        PRIM_INT__s_d_d_s[n * 36 + 29] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_p_s[(n+1) * 9 + 5], PRIM_INT__s_d_d_s[n * 36 + 29]);

                        PRIM_INT__s_d_d_s[n * 36 + 30] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_d_p_s[n * 18 + 15]);
                        PRIM_INT__s_d_d_s[n * 36 + 30] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_p_s[(n+1) * 18 + 15], PRIM_INT__s_d_d_s[n * 36 + 30]);
                        PRIM_INT__s_d_d_s[n * 36 + 30] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_s_s[n * 6 + 5]), PRIM_INT__s_d_d_s[n * 36 + 30]);

                        PRIM_INT__s_d_d_s[n * 36 + 31] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_p_s[n * 18 + 15]);
                        PRIM_INT__s_d_d_s[n * 36 + 31] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_p_s[(n+1) * 18 + 15], PRIM_INT__s_d_d_s[n * 36 + 31]);

                        PRIM_INT__s_d_d_s[n * 36 + 33] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_d_p_s[n * 18 + 16]);
                        PRIM_INT__s_d_d_s[n * 36 + 33] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_p_s[(n+1) * 18 + 16], PRIM_INT__s_d_d_s[n * 36 + 33]);
                        PRIM_INT__s_d_d_s[n * 36 + 33] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_s_s[n * 6 + 5]), PRIM_INT__s_d_d_s[n * 36 + 33]);

                        PRIM_INT__s_d_d_s[n * 36 + 35] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_d_p_s[n * 18 + 17]);
                        PRIM_INT__s_d_d_s[n * 36 + 35] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_p_s[(n+1) * 18 + 17], PRIM_INT__s_d_d_s[n * 36 + 35]);
                        PRIM_INT__s_d_d_s[n * 36 + 35] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_s_s[n * 6 + 5]), PRIM_INT__s_d_d_s[n * 36 + 35]);
                        PRIM_INT__s_d_d_s[n * 36 + 35] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_p_s[(n+1) * 9 + 8], PRIM_INT__s_d_d_s[n * 36 + 35]);

                    }


                    VRR_K_s_f_f_s(
                            PRIM_INT__s_f_f_s,
                            PRIM_INT__s_f_d_s,
                            PRIM_INT__s_f_p_s,
                            PRIM_INT__s_d_d_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            2);



                    // Forming PRIM_INT__s_g_s_s[6 * 15];
                    for(n = 0; n < 6; ++n)  // loop over orders of auxiliary function
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
                            4);


                    VRR_K_s_g_d_s(
                            PRIM_INT__s_g_d_s,
                            PRIM_INT__s_g_p_s,
                            PRIM_INT__s_g_s_s,
                            PRIM_INT__s_f_p_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            3);



                    // Forming PRIM_INT__s_s_p_s[4 * 3];
                    for(n = 0; n < 4; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_p_s[n * 3 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_p_s[n * 3 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_p_s[n * 3 + 0]);

                        PRIM_INT__s_s_p_s[n * 3 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_p_s[n * 3 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_p_s[n * 3 + 1]);

                        PRIM_INT__s_s_p_s[n * 3 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_p_s[n * 3 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_p_s[n * 3 + 2]);

                    }



                    // Forming PRIM_INT__s_p_d_s[3 * 18];
                    for(n = 0; n < 3; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_p_d_s[n * 18 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_p_p_s[n * 9 + 0]);
                        PRIM_INT__s_p_d_s[n * 18 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_p_s[(n+1) * 9 + 0], PRIM_INT__s_p_d_s[n * 18 + 0]);
                        PRIM_INT__s_p_d_s[n * 18 + 0] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_s_s[n * 3 + 0]), PRIM_INT__s_p_d_s[n * 18 + 0]);
                        PRIM_INT__s_p_d_s[n * 18 + 0] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__s_p_d_s[n * 18 + 0]);

                        PRIM_INT__s_p_d_s[n * 18 + 3] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_p_p_s[n * 9 + 1]);
                        PRIM_INT__s_p_d_s[n * 18 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_p_s[(n+1) * 9 + 1], PRIM_INT__s_p_d_s[n * 18 + 3]);
                        PRIM_INT__s_p_d_s[n * 18 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_s_s[n * 3 + 0]), PRIM_INT__s_p_d_s[n * 18 + 3]);

                        PRIM_INT__s_p_d_s[n * 18 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_p_p_s[n * 9 + 2]);
                        PRIM_INT__s_p_d_s[n * 18 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_p_s[(n+1) * 9 + 2], PRIM_INT__s_p_d_s[n * 18 + 5]);
                        PRIM_INT__s_p_d_s[n * 18 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_s_s[n * 3 + 0]), PRIM_INT__s_p_d_s[n * 18 + 5]);

                        PRIM_INT__s_p_d_s[n * 18 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_p_p_s[n * 9 + 3]);
                        PRIM_INT__s_p_d_s[n * 18 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_p_s[(n+1) * 9 + 3], PRIM_INT__s_p_d_s[n * 18 + 6]);
                        PRIM_INT__s_p_d_s[n * 18 + 6] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_s_s[n * 3 + 1]), PRIM_INT__s_p_d_s[n * 18 + 6]);

                        PRIM_INT__s_p_d_s[n * 18 + 9] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_p_p_s[n * 9 + 4]);
                        PRIM_INT__s_p_d_s[n * 18 + 9] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_p_s[(n+1) * 9 + 4], PRIM_INT__s_p_d_s[n * 18 + 9]);
                        PRIM_INT__s_p_d_s[n * 18 + 9] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_s_s[n * 3 + 1]), PRIM_INT__s_p_d_s[n * 18 + 9]);
                        PRIM_INT__s_p_d_s[n * 18 + 9] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__s_p_d_s[n * 18 + 9]);

                        PRIM_INT__s_p_d_s[n * 18 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_p_p_s[n * 9 + 5]);
                        PRIM_INT__s_p_d_s[n * 18 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_p_s[(n+1) * 9 + 5], PRIM_INT__s_p_d_s[n * 18 + 11]);
                        PRIM_INT__s_p_d_s[n * 18 + 11] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_s_s[n * 3 + 1]), PRIM_INT__s_p_d_s[n * 18 + 11]);

                        PRIM_INT__s_p_d_s[n * 18 + 12] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_p_p_s[n * 9 + 6]);
                        PRIM_INT__s_p_d_s[n * 18 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_p_s[(n+1) * 9 + 6], PRIM_INT__s_p_d_s[n * 18 + 12]);
                        PRIM_INT__s_p_d_s[n * 18 + 12] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_s_s[n * 3 + 2]), PRIM_INT__s_p_d_s[n * 18 + 12]);

                        PRIM_INT__s_p_d_s[n * 18 + 15] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_p_p_s[n * 9 + 7]);
                        PRIM_INT__s_p_d_s[n * 18 + 15] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_p_s[(n+1) * 9 + 7], PRIM_INT__s_p_d_s[n * 18 + 15]);
                        PRIM_INT__s_p_d_s[n * 18 + 15] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_s_s[n * 3 + 2]), PRIM_INT__s_p_d_s[n * 18 + 15]);

                        PRIM_INT__s_p_d_s[n * 18 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_p_p_s[n * 9 + 8]);
                        PRIM_INT__s_p_d_s[n * 18 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_p_s[(n+1) * 9 + 8], PRIM_INT__s_p_d_s[n * 18 + 17]);
                        PRIM_INT__s_p_d_s[n * 18 + 17] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_s_s[n * 3 + 2]), PRIM_INT__s_p_d_s[n * 18 + 17]);
                        PRIM_INT__s_p_d_s[n * 18 + 17] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__s_p_d_s[n * 18 + 17]);

                    }


                    VRR_K_s_d_f_s(
                            PRIM_INT__s_d_f_s,
                            PRIM_INT__s_d_d_s,
                            PRIM_INT__s_d_p_s,
                            PRIM_INT__s_p_d_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            2);


                    VRR_K_s_f_g_s(
                            PRIM_INT__s_f_g_s,
                            PRIM_INT__s_f_f_s,
                            PRIM_INT__s_f_d_s,
                            PRIM_INT__s_d_f_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            1);


                    VRR_K_s_g_f_s(
                            PRIM_INT__s_g_f_s,
                            PRIM_INT__s_g_d_s,
                            PRIM_INT__s_g_p_s,
                            PRIM_INT__s_f_d_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            2);


                    VRR_J_s_h_s_s(
                            PRIM_INT__s_h_s_s,
                            PRIM_INT__s_g_s_s,
                            PRIM_INT__s_f_s_s,
                            P_PB,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            5);


                    VRR_K_s_h_p_s(
                            PRIM_INT__s_h_p_s,
                            PRIM_INT__s_h_s_s,
                            PRIM_INT__s_g_s_s,
                            Q_PA,
                            aoq_PQ,
                            one_over_2pq,
                            4);


                    VRR_K_s_h_d_s(
                            PRIM_INT__s_h_d_s,
                            PRIM_INT__s_h_p_s,
                            PRIM_INT__s_h_s_s,
                            PRIM_INT__s_g_p_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            3);


                    ostei_general_vrr_K(0, 4, 4, 0, 1,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__s_g_f_s, PRIM_INT__s_g_d_s, NULL, NULL, PRIM_INT__s_f_f_s, PRIM_INT__s_g_g_s);


                    ostei_general_vrr_K(0, 5, 3, 0, 2,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__s_h_d_s, PRIM_INT__s_h_p_s, NULL, NULL, PRIM_INT__s_g_d_s, PRIM_INT__s_h_f_s);


                    ostei_general_vrr_K(0, 5, 4, 0, 1,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__s_h_f_s, PRIM_INT__s_h_d_s, NULL, NULL, PRIM_INT__s_g_f_s, PRIM_INT__s_h_g_s);




                    ////////////////////////////////////
                    // Accumulate contracted integrals
                    ////////////////////////////////////
                    if(lastoffset == 0)
                    {
                        contract_all(60, PRIM_INT__s_f_d_s, PRIM_PTR_INT__s_f_d_s);
                        contract_all(100, PRIM_INT__s_f_f_s, PRIM_PTR_INT__s_f_f_s);
                        contract_all(150, PRIM_INT__s_f_g_s, PRIM_PTR_INT__s_f_g_s);
                        contract_all(90, PRIM_INT__s_g_d_s, PRIM_PTR_INT__s_g_d_s);
                        contract_all(150, PRIM_INT__s_g_f_s, PRIM_PTR_INT__s_g_f_s);
                        contract_all(225, PRIM_INT__s_g_g_s, PRIM_PTR_INT__s_g_g_s);
                        contract_all(126, PRIM_INT__s_h_d_s, PRIM_PTR_INT__s_h_d_s);
                        contract_all(210, PRIM_INT__s_h_f_s, PRIM_PTR_INT__s_h_f_s);
                        contract_all(315, PRIM_INT__s_h_g_s, PRIM_PTR_INT__s_h_g_s);
                    }
                    else
                    {
                        contract(60, shelloffsets, PRIM_INT__s_f_d_s, PRIM_PTR_INT__s_f_d_s);
                        contract(100, shelloffsets, PRIM_INT__s_f_f_s, PRIM_PTR_INT__s_f_f_s);
                        contract(150, shelloffsets, PRIM_INT__s_f_g_s, PRIM_PTR_INT__s_f_g_s);
                        contract(90, shelloffsets, PRIM_INT__s_g_d_s, PRIM_PTR_INT__s_g_d_s);
                        contract(150, shelloffsets, PRIM_INT__s_g_f_s, PRIM_PTR_INT__s_g_f_s);
                        contract(225, shelloffsets, PRIM_INT__s_g_g_s, PRIM_PTR_INT__s_g_g_s);
                        contract(126, shelloffsets, PRIM_INT__s_h_d_s, PRIM_PTR_INT__s_h_d_s);
                        contract(210, shelloffsets, PRIM_INT__s_h_f_s, PRIM_PTR_INT__s_h_f_s);
                        contract(315, shelloffsets, PRIM_INT__s_h_g_s, PRIM_PTR_INT__s_h_g_s);
                        PRIM_PTR_INT__s_f_d_s += lastoffset*60;
                        PRIM_PTR_INT__s_f_f_s += lastoffset*100;
                        PRIM_PTR_INT__s_f_g_s += lastoffset*150;
                        PRIM_PTR_INT__s_g_d_s += lastoffset*90;
                        PRIM_PTR_INT__s_g_f_s += lastoffset*150;
                        PRIM_PTR_INT__s_g_g_s += lastoffset*225;
                        PRIM_PTR_INT__s_h_d_s += lastoffset*126;
                        PRIM_PTR_INT__s_h_f_s += lastoffset*210;
                        PRIM_PTR_INT__s_h_g_s += lastoffset*315;
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
                const double hCD[3] = { Q.AB_x[cd+abcd], Q.AB_y[cd+abcd], Q.AB_z[cd+abcd] };

                // set up HRR pointers
                double const * restrict HRR_INT__s_f_d_s = INT__s_f_d_s + abcd * 60;
                double const * restrict HRR_INT__s_f_f_s = INT__s_f_f_s + abcd * 100;
                double const * restrict HRR_INT__s_f_g_s = INT__s_f_g_s + abcd * 150;
                double const * restrict HRR_INT__s_g_d_s = INT__s_g_d_s + abcd * 90;
                double const * restrict HRR_INT__s_g_f_s = INT__s_g_f_s + abcd * 150;
                double const * restrict HRR_INT__s_g_g_s = INT__s_g_g_s + abcd * 225;
                double const * restrict HRR_INT__s_h_d_s = INT__s_h_d_s + abcd * 126;
                double const * restrict HRR_INT__s_h_f_s = INT__s_h_f_s + abcd * 210;
                double const * restrict HRR_INT__s_h_g_s = INT__s_h_g_s + abcd * 315;
                double * restrict HRR_INT__d_f_d_d = INT__d_f_d_d + real_abcd * 2160;

                // form INT__p_f_d_s
                for(iket = 0; iket < 6; ++iket)
                {
                    HRR_INT__p_f_d_s[0 * 6 + iket] = HRR_INT__s_g_d_s[0 * 6 + iket] - ( hAB[0] * HRR_INT__s_f_d_s[0 * 6 + iket] );

                    HRR_INT__p_f_d_s[1 * 6 + iket] = HRR_INT__s_g_d_s[1 * 6 + iket] - ( hAB[0] * HRR_INT__s_f_d_s[1 * 6 + iket] );

                    HRR_INT__p_f_d_s[2 * 6 + iket] = HRR_INT__s_g_d_s[2 * 6 + iket] - ( hAB[0] * HRR_INT__s_f_d_s[2 * 6 + iket] );

                    HRR_INT__p_f_d_s[3 * 6 + iket] = HRR_INT__s_g_d_s[3 * 6 + iket] - ( hAB[0] * HRR_INT__s_f_d_s[3 * 6 + iket] );

                    HRR_INT__p_f_d_s[4 * 6 + iket] = HRR_INT__s_g_d_s[4 * 6 + iket] - ( hAB[0] * HRR_INT__s_f_d_s[4 * 6 + iket] );

                    HRR_INT__p_f_d_s[5 * 6 + iket] = HRR_INT__s_g_d_s[5 * 6 + iket] - ( hAB[0] * HRR_INT__s_f_d_s[5 * 6 + iket] );

                    HRR_INT__p_f_d_s[6 * 6 + iket] = HRR_INT__s_g_d_s[6 * 6 + iket] - ( hAB[0] * HRR_INT__s_f_d_s[6 * 6 + iket] );

                    HRR_INT__p_f_d_s[7 * 6 + iket] = HRR_INT__s_g_d_s[7 * 6 + iket] - ( hAB[0] * HRR_INT__s_f_d_s[7 * 6 + iket] );

                    HRR_INT__p_f_d_s[8 * 6 + iket] = HRR_INT__s_g_d_s[8 * 6 + iket] - ( hAB[0] * HRR_INT__s_f_d_s[8 * 6 + iket] );

                    HRR_INT__p_f_d_s[9 * 6 + iket] = HRR_INT__s_g_d_s[9 * 6 + iket] - ( hAB[0] * HRR_INT__s_f_d_s[9 * 6 + iket] );

                    HRR_INT__p_f_d_s[10 * 6 + iket] = HRR_INT__s_g_d_s[1 * 6 + iket] - ( hAB[1] * HRR_INT__s_f_d_s[0 * 6 + iket] );

                    HRR_INT__p_f_d_s[11 * 6 + iket] = HRR_INT__s_g_d_s[3 * 6 + iket] - ( hAB[1] * HRR_INT__s_f_d_s[1 * 6 + iket] );

                    HRR_INT__p_f_d_s[12 * 6 + iket] = HRR_INT__s_g_d_s[4 * 6 + iket] - ( hAB[1] * HRR_INT__s_f_d_s[2 * 6 + iket] );

                    HRR_INT__p_f_d_s[13 * 6 + iket] = HRR_INT__s_g_d_s[6 * 6 + iket] - ( hAB[1] * HRR_INT__s_f_d_s[3 * 6 + iket] );

                    HRR_INT__p_f_d_s[14 * 6 + iket] = HRR_INT__s_g_d_s[7 * 6 + iket] - ( hAB[1] * HRR_INT__s_f_d_s[4 * 6 + iket] );

                    HRR_INT__p_f_d_s[15 * 6 + iket] = HRR_INT__s_g_d_s[8 * 6 + iket] - ( hAB[1] * HRR_INT__s_f_d_s[5 * 6 + iket] );

                    HRR_INT__p_f_d_s[16 * 6 + iket] = HRR_INT__s_g_d_s[10 * 6 + iket] - ( hAB[1] * HRR_INT__s_f_d_s[6 * 6 + iket] );

                    HRR_INT__p_f_d_s[17 * 6 + iket] = HRR_INT__s_g_d_s[11 * 6 + iket] - ( hAB[1] * HRR_INT__s_f_d_s[7 * 6 + iket] );

                    HRR_INT__p_f_d_s[18 * 6 + iket] = HRR_INT__s_g_d_s[12 * 6 + iket] - ( hAB[1] * HRR_INT__s_f_d_s[8 * 6 + iket] );

                    HRR_INT__p_f_d_s[19 * 6 + iket] = HRR_INT__s_g_d_s[13 * 6 + iket] - ( hAB[1] * HRR_INT__s_f_d_s[9 * 6 + iket] );

                    HRR_INT__p_f_d_s[20 * 6 + iket] = HRR_INT__s_g_d_s[2 * 6 + iket] - ( hAB[2] * HRR_INT__s_f_d_s[0 * 6 + iket] );

                    HRR_INT__p_f_d_s[21 * 6 + iket] = HRR_INT__s_g_d_s[4 * 6 + iket] - ( hAB[2] * HRR_INT__s_f_d_s[1 * 6 + iket] );

                    HRR_INT__p_f_d_s[22 * 6 + iket] = HRR_INT__s_g_d_s[5 * 6 + iket] - ( hAB[2] * HRR_INT__s_f_d_s[2 * 6 + iket] );

                    HRR_INT__p_f_d_s[23 * 6 + iket] = HRR_INT__s_g_d_s[7 * 6 + iket] - ( hAB[2] * HRR_INT__s_f_d_s[3 * 6 + iket] );

                    HRR_INT__p_f_d_s[24 * 6 + iket] = HRR_INT__s_g_d_s[8 * 6 + iket] - ( hAB[2] * HRR_INT__s_f_d_s[4 * 6 + iket] );

                    HRR_INT__p_f_d_s[25 * 6 + iket] = HRR_INT__s_g_d_s[9 * 6 + iket] - ( hAB[2] * HRR_INT__s_f_d_s[5 * 6 + iket] );

                    HRR_INT__p_f_d_s[26 * 6 + iket] = HRR_INT__s_g_d_s[11 * 6 + iket] - ( hAB[2] * HRR_INT__s_f_d_s[6 * 6 + iket] );

                    HRR_INT__p_f_d_s[27 * 6 + iket] = HRR_INT__s_g_d_s[12 * 6 + iket] - ( hAB[2] * HRR_INT__s_f_d_s[7 * 6 + iket] );

                    HRR_INT__p_f_d_s[28 * 6 + iket] = HRR_INT__s_g_d_s[13 * 6 + iket] - ( hAB[2] * HRR_INT__s_f_d_s[8 * 6 + iket] );

                    HRR_INT__p_f_d_s[29 * 6 + iket] = HRR_INT__s_g_d_s[14 * 6 + iket] - ( hAB[2] * HRR_INT__s_f_d_s[9 * 6 + iket] );

                }


                // form INT__p_f_f_s
                for(iket = 0; iket < 10; ++iket)
                {
                    HRR_INT__p_f_f_s[0 * 10 + iket] = HRR_INT__s_g_f_s[0 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_f_s[0 * 10 + iket] );

                    HRR_INT__p_f_f_s[1 * 10 + iket] = HRR_INT__s_g_f_s[1 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_f_s[1 * 10 + iket] );

                    HRR_INT__p_f_f_s[2 * 10 + iket] = HRR_INT__s_g_f_s[2 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_f_s[2 * 10 + iket] );

                    HRR_INT__p_f_f_s[3 * 10 + iket] = HRR_INT__s_g_f_s[3 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_f_s[3 * 10 + iket] );

                    HRR_INT__p_f_f_s[4 * 10 + iket] = HRR_INT__s_g_f_s[4 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_f_s[4 * 10 + iket] );

                    HRR_INT__p_f_f_s[5 * 10 + iket] = HRR_INT__s_g_f_s[5 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_f_s[5 * 10 + iket] );

                    HRR_INT__p_f_f_s[6 * 10 + iket] = HRR_INT__s_g_f_s[6 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_f_s[6 * 10 + iket] );

                    HRR_INT__p_f_f_s[7 * 10 + iket] = HRR_INT__s_g_f_s[7 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_f_s[7 * 10 + iket] );

                    HRR_INT__p_f_f_s[8 * 10 + iket] = HRR_INT__s_g_f_s[8 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_f_s[8 * 10 + iket] );

                    HRR_INT__p_f_f_s[9 * 10 + iket] = HRR_INT__s_g_f_s[9 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_f_s[9 * 10 + iket] );

                    HRR_INT__p_f_f_s[10 * 10 + iket] = HRR_INT__s_g_f_s[1 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_f_s[0 * 10 + iket] );

                    HRR_INT__p_f_f_s[11 * 10 + iket] = HRR_INT__s_g_f_s[3 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_f_s[1 * 10 + iket] );

                    HRR_INT__p_f_f_s[12 * 10 + iket] = HRR_INT__s_g_f_s[4 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_f_s[2 * 10 + iket] );

                    HRR_INT__p_f_f_s[13 * 10 + iket] = HRR_INT__s_g_f_s[6 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_f_s[3 * 10 + iket] );

                    HRR_INT__p_f_f_s[14 * 10 + iket] = HRR_INT__s_g_f_s[7 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_f_s[4 * 10 + iket] );

                    HRR_INT__p_f_f_s[15 * 10 + iket] = HRR_INT__s_g_f_s[8 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_f_s[5 * 10 + iket] );

                    HRR_INT__p_f_f_s[16 * 10 + iket] = HRR_INT__s_g_f_s[10 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_f_s[6 * 10 + iket] );

                    HRR_INT__p_f_f_s[17 * 10 + iket] = HRR_INT__s_g_f_s[11 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_f_s[7 * 10 + iket] );

                    HRR_INT__p_f_f_s[18 * 10 + iket] = HRR_INT__s_g_f_s[12 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_f_s[8 * 10 + iket] );

                    HRR_INT__p_f_f_s[19 * 10 + iket] = HRR_INT__s_g_f_s[13 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_f_s[9 * 10 + iket] );

                    HRR_INT__p_f_f_s[20 * 10 + iket] = HRR_INT__s_g_f_s[2 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_f_s[0 * 10 + iket] );

                    HRR_INT__p_f_f_s[21 * 10 + iket] = HRR_INT__s_g_f_s[4 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_f_s[1 * 10 + iket] );

                    HRR_INT__p_f_f_s[22 * 10 + iket] = HRR_INT__s_g_f_s[5 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_f_s[2 * 10 + iket] );

                    HRR_INT__p_f_f_s[23 * 10 + iket] = HRR_INT__s_g_f_s[7 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_f_s[3 * 10 + iket] );

                    HRR_INT__p_f_f_s[24 * 10 + iket] = HRR_INT__s_g_f_s[8 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_f_s[4 * 10 + iket] );

                    HRR_INT__p_f_f_s[25 * 10 + iket] = HRR_INT__s_g_f_s[9 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_f_s[5 * 10 + iket] );

                    HRR_INT__p_f_f_s[26 * 10 + iket] = HRR_INT__s_g_f_s[11 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_f_s[6 * 10 + iket] );

                    HRR_INT__p_f_f_s[27 * 10 + iket] = HRR_INT__s_g_f_s[12 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_f_s[7 * 10 + iket] );

                    HRR_INT__p_f_f_s[28 * 10 + iket] = HRR_INT__s_g_f_s[13 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_f_s[8 * 10 + iket] );

                    HRR_INT__p_f_f_s[29 * 10 + iket] = HRR_INT__s_g_f_s[14 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_f_s[9 * 10 + iket] );

                }


                // form INT__p_f_g_s
                for(iket = 0; iket < 15; ++iket)
                {
                    HRR_INT__p_f_g_s[0 * 15 + iket] = HRR_INT__s_g_g_s[0 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_g_s[0 * 15 + iket] );

                    HRR_INT__p_f_g_s[1 * 15 + iket] = HRR_INT__s_g_g_s[1 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_g_s[1 * 15 + iket] );

                    HRR_INT__p_f_g_s[2 * 15 + iket] = HRR_INT__s_g_g_s[2 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_g_s[2 * 15 + iket] );

                    HRR_INT__p_f_g_s[3 * 15 + iket] = HRR_INT__s_g_g_s[3 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_g_s[3 * 15 + iket] );

                    HRR_INT__p_f_g_s[4 * 15 + iket] = HRR_INT__s_g_g_s[4 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_g_s[4 * 15 + iket] );

                    HRR_INT__p_f_g_s[5 * 15 + iket] = HRR_INT__s_g_g_s[5 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_g_s[5 * 15 + iket] );

                    HRR_INT__p_f_g_s[6 * 15 + iket] = HRR_INT__s_g_g_s[6 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_g_s[6 * 15 + iket] );

                    HRR_INT__p_f_g_s[7 * 15 + iket] = HRR_INT__s_g_g_s[7 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_g_s[7 * 15 + iket] );

                    HRR_INT__p_f_g_s[8 * 15 + iket] = HRR_INT__s_g_g_s[8 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_g_s[8 * 15 + iket] );

                    HRR_INT__p_f_g_s[9 * 15 + iket] = HRR_INT__s_g_g_s[9 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_g_s[9 * 15 + iket] );

                    HRR_INT__p_f_g_s[10 * 15 + iket] = HRR_INT__s_g_g_s[1 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_g_s[0 * 15 + iket] );

                    HRR_INT__p_f_g_s[11 * 15 + iket] = HRR_INT__s_g_g_s[3 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_g_s[1 * 15 + iket] );

                    HRR_INT__p_f_g_s[12 * 15 + iket] = HRR_INT__s_g_g_s[4 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_g_s[2 * 15 + iket] );

                    HRR_INT__p_f_g_s[13 * 15 + iket] = HRR_INT__s_g_g_s[6 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_g_s[3 * 15 + iket] );

                    HRR_INT__p_f_g_s[14 * 15 + iket] = HRR_INT__s_g_g_s[7 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_g_s[4 * 15 + iket] );

                    HRR_INT__p_f_g_s[15 * 15 + iket] = HRR_INT__s_g_g_s[8 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_g_s[5 * 15 + iket] );

                    HRR_INT__p_f_g_s[16 * 15 + iket] = HRR_INT__s_g_g_s[10 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_g_s[6 * 15 + iket] );

                    HRR_INT__p_f_g_s[17 * 15 + iket] = HRR_INT__s_g_g_s[11 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_g_s[7 * 15 + iket] );

                    HRR_INT__p_f_g_s[18 * 15 + iket] = HRR_INT__s_g_g_s[12 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_g_s[8 * 15 + iket] );

                    HRR_INT__p_f_g_s[19 * 15 + iket] = HRR_INT__s_g_g_s[13 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_g_s[9 * 15 + iket] );

                    HRR_INT__p_f_g_s[20 * 15 + iket] = HRR_INT__s_g_g_s[2 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_g_s[0 * 15 + iket] );

                    HRR_INT__p_f_g_s[21 * 15 + iket] = HRR_INT__s_g_g_s[4 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_g_s[1 * 15 + iket] );

                    HRR_INT__p_f_g_s[22 * 15 + iket] = HRR_INT__s_g_g_s[5 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_g_s[2 * 15 + iket] );

                    HRR_INT__p_f_g_s[23 * 15 + iket] = HRR_INT__s_g_g_s[7 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_g_s[3 * 15 + iket] );

                    HRR_INT__p_f_g_s[24 * 15 + iket] = HRR_INT__s_g_g_s[8 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_g_s[4 * 15 + iket] );

                    HRR_INT__p_f_g_s[25 * 15 + iket] = HRR_INT__s_g_g_s[9 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_g_s[5 * 15 + iket] );

                    HRR_INT__p_f_g_s[26 * 15 + iket] = HRR_INT__s_g_g_s[11 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_g_s[6 * 15 + iket] );

                    HRR_INT__p_f_g_s[27 * 15 + iket] = HRR_INT__s_g_g_s[12 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_g_s[7 * 15 + iket] );

                    HRR_INT__p_f_g_s[28 * 15 + iket] = HRR_INT__s_g_g_s[13 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_g_s[8 * 15 + iket] );

                    HRR_INT__p_f_g_s[29 * 15 + iket] = HRR_INT__s_g_g_s[14 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_g_s[9 * 15 + iket] );

                }


                // form INT__p_g_d_s
                HRR_I_p_g(
                    HRR_INT__p_g_d_s,
                    HRR_INT__s_g_d_s,
                    HRR_INT__s_h_d_s,
                    hAB, 6);

                // form INT__p_g_f_s
                HRR_I_p_g(
                    HRR_INT__p_g_f_s,
                    HRR_INT__s_g_f_s,
                    HRR_INT__s_h_f_s,
                    hAB, 10);

                // form INT__p_g_g_s
                HRR_I_p_g(
                    HRR_INT__p_g_g_s,
                    HRR_INT__s_g_g_s,
                    HRR_INT__s_h_g_s,
                    hAB, 15);

                // form INT__d_f_d_s
                HRR_I_d_f(
                    HRR_INT__d_f_d_s,
                    HRR_INT__p_f_d_s,
                    HRR_INT__p_g_d_s,
                    hAB, 6);

                // form INT__d_f_f_s
                HRR_I_d_f(
                    HRR_INT__d_f_f_s,
                    HRR_INT__p_f_f_s,
                    HRR_INT__p_g_f_s,
                    hAB, 10);

                // form INT__d_f_g_s
                HRR_I_d_f(
                    HRR_INT__d_f_g_s,
                    HRR_INT__p_f_g_s,
                    HRR_INT__p_g_g_s,
                    hAB, 15);

                // form INT__d_f_d_p
                for(ibra = 0; ibra < 60; ++ibra)
                {
                    HRR_INT__d_f_d_p[ibra * 18 + 0] = HRR_INT__d_f_f_s[ibra * 10 + 0] + ( hCD[0] * HRR_INT__d_f_d_s[ibra * 6 + 0] );

                    HRR_INT__d_f_d_p[ibra * 18 + 1] = HRR_INT__d_f_f_s[ibra * 10 + 1] + ( hCD[1] * HRR_INT__d_f_d_s[ibra * 6 + 0] );

                    HRR_INT__d_f_d_p[ibra * 18 + 2] = HRR_INT__d_f_f_s[ibra * 10 + 2] + ( hCD[2] * HRR_INT__d_f_d_s[ibra * 6 + 0] );

                    HRR_INT__d_f_d_p[ibra * 18 + 3] = HRR_INT__d_f_f_s[ibra * 10 + 1] + ( hCD[0] * HRR_INT__d_f_d_s[ibra * 6 + 1] );

                    HRR_INT__d_f_d_p[ibra * 18 + 4] = HRR_INT__d_f_f_s[ibra * 10 + 3] + ( hCD[1] * HRR_INT__d_f_d_s[ibra * 6 + 1] );

                    HRR_INT__d_f_d_p[ibra * 18 + 5] = HRR_INT__d_f_f_s[ibra * 10 + 4] + ( hCD[2] * HRR_INT__d_f_d_s[ibra * 6 + 1] );

                    HRR_INT__d_f_d_p[ibra * 18 + 6] = HRR_INT__d_f_f_s[ibra * 10 + 2] + ( hCD[0] * HRR_INT__d_f_d_s[ibra * 6 + 2] );

                    HRR_INT__d_f_d_p[ibra * 18 + 7] = HRR_INT__d_f_f_s[ibra * 10 + 4] + ( hCD[1] * HRR_INT__d_f_d_s[ibra * 6 + 2] );

                    HRR_INT__d_f_d_p[ibra * 18 + 8] = HRR_INT__d_f_f_s[ibra * 10 + 5] + ( hCD[2] * HRR_INT__d_f_d_s[ibra * 6 + 2] );

                    HRR_INT__d_f_d_p[ibra * 18 + 9] = HRR_INT__d_f_f_s[ibra * 10 + 3] + ( hCD[0] * HRR_INT__d_f_d_s[ibra * 6 + 3] );

                    HRR_INT__d_f_d_p[ibra * 18 + 10] = HRR_INT__d_f_f_s[ibra * 10 + 6] + ( hCD[1] * HRR_INT__d_f_d_s[ibra * 6 + 3] );

                    HRR_INT__d_f_d_p[ibra * 18 + 11] = HRR_INT__d_f_f_s[ibra * 10 + 7] + ( hCD[2] * HRR_INT__d_f_d_s[ibra * 6 + 3] );

                    HRR_INT__d_f_d_p[ibra * 18 + 12] = HRR_INT__d_f_f_s[ibra * 10 + 4] + ( hCD[0] * HRR_INT__d_f_d_s[ibra * 6 + 4] );

                    HRR_INT__d_f_d_p[ibra * 18 + 13] = HRR_INT__d_f_f_s[ibra * 10 + 7] + ( hCD[1] * HRR_INT__d_f_d_s[ibra * 6 + 4] );

                    HRR_INT__d_f_d_p[ibra * 18 + 14] = HRR_INT__d_f_f_s[ibra * 10 + 8] + ( hCD[2] * HRR_INT__d_f_d_s[ibra * 6 + 4] );

                    HRR_INT__d_f_d_p[ibra * 18 + 15] = HRR_INT__d_f_f_s[ibra * 10 + 5] + ( hCD[0] * HRR_INT__d_f_d_s[ibra * 6 + 5] );

                    HRR_INT__d_f_d_p[ibra * 18 + 16] = HRR_INT__d_f_f_s[ibra * 10 + 8] + ( hCD[1] * HRR_INT__d_f_d_s[ibra * 6 + 5] );

                    HRR_INT__d_f_d_p[ibra * 18 + 17] = HRR_INT__d_f_f_s[ibra * 10 + 9] + ( hCD[2] * HRR_INT__d_f_d_s[ibra * 6 + 5] );

                }

                // form INT__d_f_f_p
                for(ibra = 0; ibra < 60; ++ibra)
                {
                    HRR_INT__d_f_f_p[ibra * 30 + 0] = HRR_INT__d_f_g_s[ibra * 15 + 0] + ( hCD[0] * HRR_INT__d_f_f_s[ibra * 10 + 0] );

                    HRR_INT__d_f_f_p[ibra * 30 + 3] = HRR_INT__d_f_g_s[ibra * 15 + 1] + ( hCD[0] * HRR_INT__d_f_f_s[ibra * 10 + 1] );

                    HRR_INT__d_f_f_p[ibra * 30 + 4] = HRR_INT__d_f_g_s[ibra * 15 + 3] + ( hCD[1] * HRR_INT__d_f_f_s[ibra * 10 + 1] );

                    HRR_INT__d_f_f_p[ibra * 30 + 6] = HRR_INT__d_f_g_s[ibra * 15 + 2] + ( hCD[0] * HRR_INT__d_f_f_s[ibra * 10 + 2] );

                    HRR_INT__d_f_f_p[ibra * 30 + 7] = HRR_INT__d_f_g_s[ibra * 15 + 4] + ( hCD[1] * HRR_INT__d_f_f_s[ibra * 10 + 2] );

                    HRR_INT__d_f_f_p[ibra * 30 + 8] = HRR_INT__d_f_g_s[ibra * 15 + 5] + ( hCD[2] * HRR_INT__d_f_f_s[ibra * 10 + 2] );

                    HRR_INT__d_f_f_p[ibra * 30 + 9] = HRR_INT__d_f_g_s[ibra * 15 + 3] + ( hCD[0] * HRR_INT__d_f_f_s[ibra * 10 + 3] );

                    HRR_INT__d_f_f_p[ibra * 30 + 10] = HRR_INT__d_f_g_s[ibra * 15 + 6] + ( hCD[1] * HRR_INT__d_f_f_s[ibra * 10 + 3] );

                    HRR_INT__d_f_f_p[ibra * 30 + 12] = HRR_INT__d_f_g_s[ibra * 15 + 4] + ( hCD[0] * HRR_INT__d_f_f_s[ibra * 10 + 4] );

                    HRR_INT__d_f_f_p[ibra * 30 + 13] = HRR_INT__d_f_g_s[ibra * 15 + 7] + ( hCD[1] * HRR_INT__d_f_f_s[ibra * 10 + 4] );

                    HRR_INT__d_f_f_p[ibra * 30 + 14] = HRR_INT__d_f_g_s[ibra * 15 + 8] + ( hCD[2] * HRR_INT__d_f_f_s[ibra * 10 + 4] );

                    HRR_INT__d_f_f_p[ibra * 30 + 15] = HRR_INT__d_f_g_s[ibra * 15 + 5] + ( hCD[0] * HRR_INT__d_f_f_s[ibra * 10 + 5] );

                    HRR_INT__d_f_f_p[ibra * 30 + 16] = HRR_INT__d_f_g_s[ibra * 15 + 8] + ( hCD[1] * HRR_INT__d_f_f_s[ibra * 10 + 5] );

                    HRR_INT__d_f_f_p[ibra * 30 + 17] = HRR_INT__d_f_g_s[ibra * 15 + 9] + ( hCD[2] * HRR_INT__d_f_f_s[ibra * 10 + 5] );

                    HRR_INT__d_f_f_p[ibra * 30 + 18] = HRR_INT__d_f_g_s[ibra * 15 + 6] + ( hCD[0] * HRR_INT__d_f_f_s[ibra * 10 + 6] );

                    HRR_INT__d_f_f_p[ibra * 30 + 19] = HRR_INT__d_f_g_s[ibra * 15 + 10] + ( hCD[1] * HRR_INT__d_f_f_s[ibra * 10 + 6] );

                    HRR_INT__d_f_f_p[ibra * 30 + 21] = HRR_INT__d_f_g_s[ibra * 15 + 7] + ( hCD[0] * HRR_INT__d_f_f_s[ibra * 10 + 7] );

                    HRR_INT__d_f_f_p[ibra * 30 + 22] = HRR_INT__d_f_g_s[ibra * 15 + 11] + ( hCD[1] * HRR_INT__d_f_f_s[ibra * 10 + 7] );

                    HRR_INT__d_f_f_p[ibra * 30 + 23] = HRR_INT__d_f_g_s[ibra * 15 + 12] + ( hCD[2] * HRR_INT__d_f_f_s[ibra * 10 + 7] );

                    HRR_INT__d_f_f_p[ibra * 30 + 24] = HRR_INT__d_f_g_s[ibra * 15 + 8] + ( hCD[0] * HRR_INT__d_f_f_s[ibra * 10 + 8] );

                    HRR_INT__d_f_f_p[ibra * 30 + 25] = HRR_INT__d_f_g_s[ibra * 15 + 12] + ( hCD[1] * HRR_INT__d_f_f_s[ibra * 10 + 8] );

                    HRR_INT__d_f_f_p[ibra * 30 + 26] = HRR_INT__d_f_g_s[ibra * 15 + 13] + ( hCD[2] * HRR_INT__d_f_f_s[ibra * 10 + 8] );

                    HRR_INT__d_f_f_p[ibra * 30 + 27] = HRR_INT__d_f_g_s[ibra * 15 + 9] + ( hCD[0] * HRR_INT__d_f_f_s[ibra * 10 + 9] );

                    HRR_INT__d_f_f_p[ibra * 30 + 28] = HRR_INT__d_f_g_s[ibra * 15 + 13] + ( hCD[1] * HRR_INT__d_f_f_s[ibra * 10 + 9] );

                    HRR_INT__d_f_f_p[ibra * 30 + 29] = HRR_INT__d_f_g_s[ibra * 15 + 14] + ( hCD[2] * HRR_INT__d_f_f_s[ibra * 10 + 9] );

                }

                // form INT__d_f_d_d
                for(ibra = 0; ibra < 60; ++ibra)
                {
                    HRR_INT__d_f_d_d[ibra * 36 + 0] = HRR_INT__d_f_f_p[ibra * 30 + 0] + ( hCD[0] * HRR_INT__d_f_d_p[ibra * 18 + 0] );

                    HRR_INT__d_f_d_d[ibra * 36 + 1] = HRR_INT__d_f_f_p[ibra * 30 + 3] + ( hCD[1] * HRR_INT__d_f_d_p[ibra * 18 + 0] );

                    HRR_INT__d_f_d_d[ibra * 36 + 2] = HRR_INT__d_f_f_p[ibra * 30 + 6] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 0] );

                    HRR_INT__d_f_d_d[ibra * 36 + 3] = HRR_INT__d_f_f_p[ibra * 30 + 4] + ( hCD[1] * HRR_INT__d_f_d_p[ibra * 18 + 1] );

                    HRR_INT__d_f_d_d[ibra * 36 + 4] = HRR_INT__d_f_f_p[ibra * 30 + 7] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 1] );

                    HRR_INT__d_f_d_d[ibra * 36 + 5] = HRR_INT__d_f_f_p[ibra * 30 + 8] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 2] );

                    HRR_INT__d_f_d_d[ibra * 36 + 6] = HRR_INT__d_f_f_p[ibra * 30 + 3] + ( hCD[0] * HRR_INT__d_f_d_p[ibra * 18 + 3] );

                    HRR_INT__d_f_d_d[ibra * 36 + 7] = HRR_INT__d_f_f_p[ibra * 30 + 9] + ( hCD[1] * HRR_INT__d_f_d_p[ibra * 18 + 3] );

                    HRR_INT__d_f_d_d[ibra * 36 + 8] = HRR_INT__d_f_f_p[ibra * 30 + 12] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 3] );

                    HRR_INT__d_f_d_d[ibra * 36 + 9] = HRR_INT__d_f_f_p[ibra * 30 + 10] + ( hCD[1] * HRR_INT__d_f_d_p[ibra * 18 + 4] );

                    HRR_INT__d_f_d_d[ibra * 36 + 10] = HRR_INT__d_f_f_p[ibra * 30 + 13] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 4] );

                    HRR_INT__d_f_d_d[ibra * 36 + 11] = HRR_INT__d_f_f_p[ibra * 30 + 14] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 5] );

                    HRR_INT__d_f_d_d[ibra * 36 + 12] = HRR_INT__d_f_f_p[ibra * 30 + 6] + ( hCD[0] * HRR_INT__d_f_d_p[ibra * 18 + 6] );

                    HRR_INT__d_f_d_d[ibra * 36 + 13] = HRR_INT__d_f_f_p[ibra * 30 + 12] + ( hCD[1] * HRR_INT__d_f_d_p[ibra * 18 + 6] );

                    HRR_INT__d_f_d_d[ibra * 36 + 14] = HRR_INT__d_f_f_p[ibra * 30 + 15] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 6] );

                    HRR_INT__d_f_d_d[ibra * 36 + 15] = HRR_INT__d_f_f_p[ibra * 30 + 13] + ( hCD[1] * HRR_INT__d_f_d_p[ibra * 18 + 7] );

                    HRR_INT__d_f_d_d[ibra * 36 + 16] = HRR_INT__d_f_f_p[ibra * 30 + 16] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 7] );

                    HRR_INT__d_f_d_d[ibra * 36 + 17] = HRR_INT__d_f_f_p[ibra * 30 + 17] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 8] );

                    HRR_INT__d_f_d_d[ibra * 36 + 18] = HRR_INT__d_f_f_p[ibra * 30 + 9] + ( hCD[0] * HRR_INT__d_f_d_p[ibra * 18 + 9] );

                    HRR_INT__d_f_d_d[ibra * 36 + 19] = HRR_INT__d_f_f_p[ibra * 30 + 18] + ( hCD[1] * HRR_INT__d_f_d_p[ibra * 18 + 9] );

                    HRR_INT__d_f_d_d[ibra * 36 + 20] = HRR_INT__d_f_f_p[ibra * 30 + 21] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 9] );

                    HRR_INT__d_f_d_d[ibra * 36 + 21] = HRR_INT__d_f_f_p[ibra * 30 + 19] + ( hCD[1] * HRR_INT__d_f_d_p[ibra * 18 + 10] );

                    HRR_INT__d_f_d_d[ibra * 36 + 22] = HRR_INT__d_f_f_p[ibra * 30 + 22] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 10] );

                    HRR_INT__d_f_d_d[ibra * 36 + 23] = HRR_INT__d_f_f_p[ibra * 30 + 23] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 11] );

                    HRR_INT__d_f_d_d[ibra * 36 + 24] = HRR_INT__d_f_f_p[ibra * 30 + 12] + ( hCD[0] * HRR_INT__d_f_d_p[ibra * 18 + 12] );

                    HRR_INT__d_f_d_d[ibra * 36 + 25] = HRR_INT__d_f_f_p[ibra * 30 + 21] + ( hCD[1] * HRR_INT__d_f_d_p[ibra * 18 + 12] );

                    HRR_INT__d_f_d_d[ibra * 36 + 26] = HRR_INT__d_f_f_p[ibra * 30 + 24] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 12] );

                    HRR_INT__d_f_d_d[ibra * 36 + 27] = HRR_INT__d_f_f_p[ibra * 30 + 22] + ( hCD[1] * HRR_INT__d_f_d_p[ibra * 18 + 13] );

                    HRR_INT__d_f_d_d[ibra * 36 + 28] = HRR_INT__d_f_f_p[ibra * 30 + 25] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 13] );

                    HRR_INT__d_f_d_d[ibra * 36 + 29] = HRR_INT__d_f_f_p[ibra * 30 + 26] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 14] );

                    HRR_INT__d_f_d_d[ibra * 36 + 30] = HRR_INT__d_f_f_p[ibra * 30 + 15] + ( hCD[0] * HRR_INT__d_f_d_p[ibra * 18 + 15] );

                    HRR_INT__d_f_d_d[ibra * 36 + 31] = HRR_INT__d_f_f_p[ibra * 30 + 24] + ( hCD[1] * HRR_INT__d_f_d_p[ibra * 18 + 15] );

                    HRR_INT__d_f_d_d[ibra * 36 + 32] = HRR_INT__d_f_f_p[ibra * 30 + 27] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 15] );

                    HRR_INT__d_f_d_d[ibra * 36 + 33] = HRR_INT__d_f_f_p[ibra * 30 + 25] + ( hCD[1] * HRR_INT__d_f_d_p[ibra * 18 + 16] );

                    HRR_INT__d_f_d_d[ibra * 36 + 34] = HRR_INT__d_f_f_p[ibra * 30 + 28] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 16] );

                    HRR_INT__d_f_d_d[ibra * 36 + 35] = HRR_INT__d_f_f_p[ibra * 30 + 29] + ( hCD[2] * HRR_INT__d_f_d_p[ibra * 18 + 17] );

                }


            }  // close HRR loop


        }   // close loop cdbatch

        istart = iend;
    }  // close loop over ab

    return P.nshell12_clip * Q.nshell12_clip;
}
