#include "simint/boys/boys.h"
#include "simint/ostei/gen/ostei_generated.h"
#include "simint/vectorization/vectorization.h"
#include <math.h>
#include <string.h>


int ostei_g_g_d_p(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__g_g_d_p)
{

    SIMINT_ASSUME_ALIGN_DBL(work);
    SIMINT_ASSUME_ALIGN_DBL(INT__g_g_d_p);
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
    double * const INT__g_s_d_s = work + (SIMINT_NSHELL_SIMD * 0);
    double * const INT__g_s_f_s = work + (SIMINT_NSHELL_SIMD * 90);
    double * const INT__h_s_d_s = work + (SIMINT_NSHELL_SIMD * 240);
    double * const INT__h_s_f_s = work + (SIMINT_NSHELL_SIMD * 366);
    double * const INT__i_s_d_s = work + (SIMINT_NSHELL_SIMD * 576);
    double * const INT__i_s_f_s = work + (SIMINT_NSHELL_SIMD * 744);
    double * const INT__k_s_d_s = work + (SIMINT_NSHELL_SIMD * 1024);
    double * const INT__k_s_f_s = work + (SIMINT_NSHELL_SIMD * 1240);
    double * const INT__l_s_d_s = work + (SIMINT_NSHELL_SIMD * 1600);
    double * const INT__l_s_f_s = work + (SIMINT_NSHELL_SIMD * 1870);
    SIMINT_DBLTYPE * const primwork = (SIMINT_DBLTYPE *)(work + SIMINT_NSHELL_SIMD*2320);
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_s = primwork + 0;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_s = primwork + 12;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_s = primwork + 45;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_p_s = primwork + 105;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_s = primwork + 159;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_p_s = primwork + 249;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s = primwork + 339;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_s = primwork + 459;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_p_s = primwork + 579;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_d_s = primwork + 714;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_f_s = primwork + 894;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s = primwork + 1044;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_p_s = primwork + 1191;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_d_s = primwork + 1380;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_f_s = primwork + 1632;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_s_s = primwork + 1842;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_p_s = primwork + 2010;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_d_s = primwork + 2262;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_f_s = primwork + 2598;
    SIMINT_DBLTYPE * const restrict PRIM_INT__k_s_s_s = primwork + 2878;
    SIMINT_DBLTYPE * const restrict PRIM_INT__k_s_p_s = primwork + 3058;
    SIMINT_DBLTYPE * const restrict PRIM_INT__k_s_d_s = primwork + 3382;
    SIMINT_DBLTYPE * const restrict PRIM_INT__k_s_f_s = primwork + 3814;
    SIMINT_DBLTYPE * const restrict PRIM_INT__l_s_s_s = primwork + 4174;
    SIMINT_DBLTYPE * const restrict PRIM_INT__l_s_p_s = primwork + 4354;
    SIMINT_DBLTYPE * const restrict PRIM_INT__l_s_d_s = primwork + 4759;
    SIMINT_DBLTYPE * const restrict PRIM_INT__l_s_f_s = primwork + 5299;
    double * const hrrwork = (double *)(primwork + 5749);
    double * const HRR_INT__g_p_d_s = hrrwork + 0;
    double * const HRR_INT__g_p_f_s = hrrwork + 270;
    double * const HRR_INT__g_d_d_s = hrrwork + 720;
    double * const HRR_INT__g_d_f_s = hrrwork + 1260;
    double * const HRR_INT__g_f_d_s = hrrwork + 2160;
    double * const HRR_INT__g_f_f_s = hrrwork + 3060;
    double * const HRR_INT__g_g_d_s = hrrwork + 4560;
    double * const HRR_INT__g_g_f_s = hrrwork + 5910;
    double * const HRR_INT__h_p_d_s = hrrwork + 8160;
    double * const HRR_INT__h_p_f_s = hrrwork + 8538;
    double * const HRR_INT__h_d_d_s = hrrwork + 9168;
    double * const HRR_INT__h_d_f_s = hrrwork + 9924;
    double * const HRR_INT__h_f_d_s = hrrwork + 11184;
    double * const HRR_INT__h_f_f_s = hrrwork + 12444;
    double * const HRR_INT__i_p_d_s = hrrwork + 14544;
    double * const HRR_INT__i_p_f_s = hrrwork + 15048;
    double * const HRR_INT__i_d_d_s = hrrwork + 15888;
    double * const HRR_INT__i_d_f_s = hrrwork + 16896;
    double * const HRR_INT__k_p_d_s = hrrwork + 18576;
    double * const HRR_INT__k_p_f_s = hrrwork + 19224;


    // Create constants
    const SIMINT_DBLTYPE const_1 = SIMINT_DBLSET1(1);
    const SIMINT_DBLTYPE const_2 = SIMINT_DBLSET1(2);
    const SIMINT_DBLTYPE const_3 = SIMINT_DBLSET1(3);
    const SIMINT_DBLTYPE const_4 = SIMINT_DBLSET1(4);
    const SIMINT_DBLTYPE const_5 = SIMINT_DBLSET1(5);
    const SIMINT_DBLTYPE const_6 = SIMINT_DBLSET1(6);
    const SIMINT_DBLTYPE const_7 = SIMINT_DBLSET1(7);
    const SIMINT_DBLTYPE const_8 = SIMINT_DBLSET1(8);
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
            memset(work, 0, SIMINT_NSHELL_SIMD * 2320 * sizeof(double));
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
                double * restrict PRIM_PTR_INT__g_s_d_s = INT__g_s_d_s + abcd * 90;
                double * restrict PRIM_PTR_INT__g_s_f_s = INT__g_s_f_s + abcd * 150;
                double * restrict PRIM_PTR_INT__h_s_d_s = INT__h_s_d_s + abcd * 126;
                double * restrict PRIM_PTR_INT__h_s_f_s = INT__h_s_f_s + abcd * 210;
                double * restrict PRIM_PTR_INT__i_s_d_s = INT__i_s_d_s + abcd * 168;
                double * restrict PRIM_PTR_INT__i_s_f_s = INT__i_s_f_s + abcd * 280;
                double * restrict PRIM_PTR_INT__k_s_d_s = INT__k_s_d_s + abcd * 216;
                double * restrict PRIM_PTR_INT__k_s_f_s = INT__k_s_f_s + abcd * 360;
                double * restrict PRIM_PTR_INT__l_s_d_s = INT__l_s_d_s + abcd * 270;
                double * restrict PRIM_PTR_INT__l_s_f_s = INT__l_s_f_s + abcd * 450;



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
                            PRIM_PTR_INT__g_s_d_s += 90;
                            PRIM_PTR_INT__g_s_f_s += 150;
                            PRIM_PTR_INT__h_s_d_s += 126;
                            PRIM_PTR_INT__h_s_f_s += 210;
                            PRIM_PTR_INT__i_s_d_s += 168;
                            PRIM_PTR_INT__i_s_f_s += 280;
                            PRIM_PTR_INT__k_s_d_s += 216;
                            PRIM_PTR_INT__k_s_f_s += 360;
                            PRIM_PTR_INT__l_s_d_s += 270;
                            PRIM_PTR_INT__l_s_f_s += 450;
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
                            PRIM_PTR_INT__g_s_d_s += lastoffset*90;
                            PRIM_PTR_INT__g_s_f_s += lastoffset*150;
                            PRIM_PTR_INT__h_s_d_s += lastoffset*126;
                            PRIM_PTR_INT__h_s_f_s += lastoffset*210;
                            PRIM_PTR_INT__i_s_d_s += lastoffset*168;
                            PRIM_PTR_INT__i_s_f_s += lastoffset*280;
                            PRIM_PTR_INT__k_s_d_s += lastoffset*216;
                            PRIM_PTR_INT__k_s_f_s += lastoffset*360;
                            PRIM_PTR_INT__l_s_d_s += lastoffset*270;
                            PRIM_PTR_INT__l_s_f_s += lastoffset*450;
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
                    // Maximum v value: 11
                    //////////////////////////////////////////////
                    // The parameter to the Fjt function
                    const SIMINT_DBLTYPE F_x = SIMINT_MUL(R2, alpha);


                    const SIMINT_DBLTYPE Q_prefac = mask_load(nlane, Q.prefac + j);


                    boys_F_split(PRIM_INT__s_s_s_s, F_x, 11);
                    SIMINT_DBLTYPE prefac = SIMINT_SQRT(one_over_PQalpha_sum);
                    prefac = SIMINT_MUL(SIMINT_MUL(P_prefac, Q_prefac), prefac);
                    for(n = 0; n <= 11; n++)
                        PRIM_INT__s_s_s_s[n] = SIMINT_MUL(PRIM_INT__s_s_s_s[n], prefac);

                    //////////////////////////////////////////////
                    // Primitive integrals: Vertical recurrance
                    //////////////////////////////////////////////

                    const SIMINT_DBLTYPE vrr_const_1_over_2p = one_over_2p;
                    const SIMINT_DBLTYPE vrr_const_2_over_2p = SIMINT_MUL(const_2, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_3_over_2p = SIMINT_MUL(const_3, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_4_over_2p = SIMINT_MUL(const_4, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_5_over_2p = SIMINT_MUL(const_5, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_6_over_2p = SIMINT_MUL(const_6, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_7_over_2p = SIMINT_MUL(const_7, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_1_over_2q = one_over_2q;
                    const SIMINT_DBLTYPE vrr_const_2_over_2q = SIMINT_MUL(const_2, one_over_2q);
                    const SIMINT_DBLTYPE vrr_const_1_over_2pq = one_over_2pq;
                    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(const_2, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_3_over_2pq = SIMINT_MUL(const_3, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_4_over_2pq = SIMINT_MUL(const_4, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_5_over_2pq = SIMINT_MUL(const_5, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_6_over_2pq = SIMINT_MUL(const_6, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_7_over_2pq = SIMINT_MUL(const_7, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_8_over_2pq = SIMINT_MUL(const_8, one_over_2pq);



                    // Forming PRIM_INT__p_s_s_s[11 * 3];
                    for(n = 0; n < 11; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__p_s_s_s[n * 3 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__p_s_s_s[n * 3 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_s_s[n * 3 + 0]);

                        PRIM_INT__p_s_s_s[n * 3 + 1] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__p_s_s_s[n * 3 + 1] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_s_s[n * 3 + 1]);

                        PRIM_INT__p_s_s_s[n * 3 + 2] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__p_s_s_s[n * 3 + 2] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_s_s[n * 3 + 2]);

                    }



                    // Forming PRIM_INT__d_s_s_s[10 * 6];
                    for(n = 0; n < 10; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__d_s_s_s[n * 6 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__p_s_s_s[n * 3 + 0]);
                        PRIM_INT__d_s_s_s[n * 6 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__d_s_s_s[n * 6 + 0]);
                        PRIM_INT__d_s_s_s[n * 6 + 0] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__d_s_s_s[n * 6 + 0]);

                        PRIM_INT__d_s_s_s[n * 6 + 1] = SIMINT_MUL(P_PA[1], PRIM_INT__p_s_s_s[n * 3 + 0]);
                        PRIM_INT__d_s_s_s[n * 6 + 1] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__d_s_s_s[n * 6 + 1]);

                        PRIM_INT__d_s_s_s[n * 6 + 2] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_s_s[n * 3 + 0]);
                        PRIM_INT__d_s_s_s[n * 6 + 2] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__d_s_s_s[n * 6 + 2]);

                        PRIM_INT__d_s_s_s[n * 6 + 3] = SIMINT_MUL(P_PA[1], PRIM_INT__p_s_s_s[n * 3 + 1]);
                        PRIM_INT__d_s_s_s[n * 6 + 3] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__d_s_s_s[n * 6 + 3]);
                        PRIM_INT__d_s_s_s[n * 6 + 3] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__d_s_s_s[n * 6 + 3]);

                        PRIM_INT__d_s_s_s[n * 6 + 4] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_s_s[n * 3 + 1]);
                        PRIM_INT__d_s_s_s[n * 6 + 4] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__d_s_s_s[n * 6 + 4]);

                        PRIM_INT__d_s_s_s[n * 6 + 5] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_s_s[n * 3 + 2]);
                        PRIM_INT__d_s_s_s[n * 6 + 5] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__d_s_s_s[n * 6 + 5]);
                        PRIM_INT__d_s_s_s[n * 6 + 5] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__d_s_s_s[n * 6 + 5]);

                    }



                    // Forming PRIM_INT__f_s_s_s[9 * 10];
                    for(n = 0; n < 9; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__f_s_s_s[n * 10 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__d_s_s_s[n * 6 + 0]);
                        PRIM_INT__f_s_s_s[n * 10 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__f_s_s_s[n * 10 + 0]);
                        PRIM_INT__f_s_s_s[n * 10 + 0] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__p_s_s_s[n * 3 + 0]), PRIM_INT__f_s_s_s[n * 10 + 0]);

                        PRIM_INT__f_s_s_s[n * 10 + 1] = SIMINT_MUL(P_PA[1], PRIM_INT__d_s_s_s[n * 6 + 0]);
                        PRIM_INT__f_s_s_s[n * 10 + 1] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__f_s_s_s[n * 10 + 1]);

                        PRIM_INT__f_s_s_s[n * 10 + 2] = SIMINT_MUL(P_PA[2], PRIM_INT__d_s_s_s[n * 6 + 0]);
                        PRIM_INT__f_s_s_s[n * 10 + 2] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__f_s_s_s[n * 10 + 2]);

                        PRIM_INT__f_s_s_s[n * 10 + 3] = SIMINT_MUL(P_PA[0], PRIM_INT__d_s_s_s[n * 6 + 3]);
                        PRIM_INT__f_s_s_s[n * 10 + 3] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__f_s_s_s[n * 10 + 3]);

                        PRIM_INT__f_s_s_s[n * 10 + 4] = SIMINT_MUL(P_PA[2], PRIM_INT__d_s_s_s[n * 6 + 1]);
                        PRIM_INT__f_s_s_s[n * 10 + 4] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__d_s_s_s[(n+1) * 6 + 1], PRIM_INT__f_s_s_s[n * 10 + 4]);

                        PRIM_INT__f_s_s_s[n * 10 + 5] = SIMINT_MUL(P_PA[0], PRIM_INT__d_s_s_s[n * 6 + 5]);
                        PRIM_INT__f_s_s_s[n * 10 + 5] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__f_s_s_s[n * 10 + 5]);

                        PRIM_INT__f_s_s_s[n * 10 + 6] = SIMINT_MUL(P_PA[1], PRIM_INT__d_s_s_s[n * 6 + 3]);
                        PRIM_INT__f_s_s_s[n * 10 + 6] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__f_s_s_s[n * 10 + 6]);
                        PRIM_INT__f_s_s_s[n * 10 + 6] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__p_s_s_s[n * 3 + 1]), PRIM_INT__f_s_s_s[n * 10 + 6]);

                        PRIM_INT__f_s_s_s[n * 10 + 7] = SIMINT_MUL(P_PA[2], PRIM_INT__d_s_s_s[n * 6 + 3]);
                        PRIM_INT__f_s_s_s[n * 10 + 7] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__f_s_s_s[n * 10 + 7]);

                        PRIM_INT__f_s_s_s[n * 10 + 8] = SIMINT_MUL(P_PA[1], PRIM_INT__d_s_s_s[n * 6 + 5]);
                        PRIM_INT__f_s_s_s[n * 10 + 8] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__f_s_s_s[n * 10 + 8]);

                        PRIM_INT__f_s_s_s[n * 10 + 9] = SIMINT_MUL(P_PA[2], PRIM_INT__d_s_s_s[n * 6 + 5]);
                        PRIM_INT__f_s_s_s[n * 10 + 9] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__f_s_s_s[n * 10 + 9]);
                        PRIM_INT__f_s_s_s[n * 10 + 9] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__p_s_s_s[n * 3 + 2]), PRIM_INT__f_s_s_s[n * 10 + 9]);

                    }



                    // Forming PRIM_INT__g_s_s_s[8 * 15];
                    for(n = 0; n < 8; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__g_s_s_s[n * 15 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_s_s[n * 10 + 0]);
                        PRIM_INT__g_s_s_s[n * 15 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 0], PRIM_INT__g_s_s_s[n * 15 + 0]);
                        PRIM_INT__g_s_s_s[n * 15 + 0] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__d_s_s_s[n * 6 + 0]), PRIM_INT__g_s_s_s[n * 15 + 0]);

                        PRIM_INT__g_s_s_s[n * 15 + 1] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_s_s[n * 10 + 0]);
                        PRIM_INT__g_s_s_s[n * 15 + 1] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 0], PRIM_INT__g_s_s_s[n * 15 + 1]);

                        PRIM_INT__g_s_s_s[n * 15 + 2] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_s_s[n * 10 + 0]);
                        PRIM_INT__g_s_s_s[n * 15 + 2] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 0], PRIM_INT__g_s_s_s[n * 15 + 2]);

                        PRIM_INT__g_s_s_s[n * 15 + 3] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_s_s[n * 10 + 1]);
                        PRIM_INT__g_s_s_s[n * 15 + 3] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 1], PRIM_INT__g_s_s_s[n * 15 + 3]);
                        PRIM_INT__g_s_s_s[n * 15 + 3] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__d_s_s_s[n * 6 + 0]), PRIM_INT__g_s_s_s[n * 15 + 3]);

                        PRIM_INT__g_s_s_s[n * 15 + 4] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_s_s[n * 10 + 1]);
                        PRIM_INT__g_s_s_s[n * 15 + 4] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 1], PRIM_INT__g_s_s_s[n * 15 + 4]);

                        PRIM_INT__g_s_s_s[n * 15 + 5] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_s_s[n * 10 + 2]);
                        PRIM_INT__g_s_s_s[n * 15 + 5] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 2], PRIM_INT__g_s_s_s[n * 15 + 5]);
                        PRIM_INT__g_s_s_s[n * 15 + 5] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__d_s_s_s[n * 6 + 0]), PRIM_INT__g_s_s_s[n * 15 + 5]);

                        PRIM_INT__g_s_s_s[n * 15 + 6] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_s_s[n * 10 + 6]);
                        PRIM_INT__g_s_s_s[n * 15 + 6] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 6], PRIM_INT__g_s_s_s[n * 15 + 6]);

                        PRIM_INT__g_s_s_s[n * 15 + 7] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_s_s[n * 10 + 3]);
                        PRIM_INT__g_s_s_s[n * 15 + 7] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 3], PRIM_INT__g_s_s_s[n * 15 + 7]);

                        PRIM_INT__g_s_s_s[n * 15 + 8] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_s_s[n * 10 + 5]);
                        PRIM_INT__g_s_s_s[n * 15 + 8] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 5], PRIM_INT__g_s_s_s[n * 15 + 8]);

                        PRIM_INT__g_s_s_s[n * 15 + 9] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_s_s[n * 10 + 9]);
                        PRIM_INT__g_s_s_s[n * 15 + 9] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 9], PRIM_INT__g_s_s_s[n * 15 + 9]);

                        PRIM_INT__g_s_s_s[n * 15 + 10] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_s_s[n * 10 + 6]);
                        PRIM_INT__g_s_s_s[n * 15 + 10] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 6], PRIM_INT__g_s_s_s[n * 15 + 10]);
                        PRIM_INT__g_s_s_s[n * 15 + 10] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__d_s_s_s[n * 6 + 3]), PRIM_INT__g_s_s_s[n * 15 + 10]);

                        PRIM_INT__g_s_s_s[n * 15 + 11] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_s_s[n * 10 + 6]);
                        PRIM_INT__g_s_s_s[n * 15 + 11] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 6], PRIM_INT__g_s_s_s[n * 15 + 11]);

                        PRIM_INT__g_s_s_s[n * 15 + 12] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_s_s[n * 10 + 7]);
                        PRIM_INT__g_s_s_s[n * 15 + 12] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 7], PRIM_INT__g_s_s_s[n * 15 + 12]);
                        PRIM_INT__g_s_s_s[n * 15 + 12] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__d_s_s_s[n * 6 + 3]), PRIM_INT__g_s_s_s[n * 15 + 12]);

                        PRIM_INT__g_s_s_s[n * 15 + 13] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_s_s[n * 10 + 9]);
                        PRIM_INT__g_s_s_s[n * 15 + 13] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 9], PRIM_INT__g_s_s_s[n * 15 + 13]);

                        PRIM_INT__g_s_s_s[n * 15 + 14] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_s_s[n * 10 + 9]);
                        PRIM_INT__g_s_s_s[n * 15 + 14] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 9], PRIM_INT__g_s_s_s[n * 15 + 14]);
                        PRIM_INT__g_s_s_s[n * 15 + 14] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__d_s_s_s[n * 6 + 5]), PRIM_INT__g_s_s_s[n * 15 + 14]);

                    }


                    VRR_K_g_s_p_s(
                            PRIM_INT__g_s_p_s,
                            PRIM_INT__g_s_s_s,
                            PRIM_INT__f_s_s_s,
                            Q_PA,
                            aoq_PQ,
                            one_over_2pq,
                            3);



                    // Forming PRIM_INT__f_s_p_s[3 * 30];
                    for(n = 0; n < 3; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__f_s_p_s[n * 30 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_s_s[n * 10 + 0]);
                        PRIM_INT__f_s_p_s[n * 30 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 0], PRIM_INT__f_s_p_s[n * 30 + 0]);
                        PRIM_INT__f_s_p_s[n * 30 + 0] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__f_s_p_s[n * 30 + 0]);

                        PRIM_INT__f_s_p_s[n * 30 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_s_s[n * 10 + 0]);
                        PRIM_INT__f_s_p_s[n * 30 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 0], PRIM_INT__f_s_p_s[n * 30 + 1]);

                        PRIM_INT__f_s_p_s[n * 30 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_s_s[n * 10 + 0]);
                        PRIM_INT__f_s_p_s[n * 30 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 0], PRIM_INT__f_s_p_s[n * 30 + 2]);

                        PRIM_INT__f_s_p_s[n * 30 + 3] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_s_s[n * 10 + 1]);
                        PRIM_INT__f_s_p_s[n * 30 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 1], PRIM_INT__f_s_p_s[n * 30 + 3]);
                        PRIM_INT__f_s_p_s[n * 30 + 3] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 1], PRIM_INT__f_s_p_s[n * 30 + 3]);

                        PRIM_INT__f_s_p_s[n * 30 + 4] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_s_s[n * 10 + 1]);
                        PRIM_INT__f_s_p_s[n * 30 + 4] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 1], PRIM_INT__f_s_p_s[n * 30 + 4]);
                        PRIM_INT__f_s_p_s[n * 30 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__f_s_p_s[n * 30 + 4]);

                        PRIM_INT__f_s_p_s[n * 30 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_s_s[n * 10 + 1]);
                        PRIM_INT__f_s_p_s[n * 30 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 1], PRIM_INT__f_s_p_s[n * 30 + 5]);

                        PRIM_INT__f_s_p_s[n * 30 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_s_s[n * 10 + 2]);
                        PRIM_INT__f_s_p_s[n * 30 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 2], PRIM_INT__f_s_p_s[n * 30 + 6]);
                        PRIM_INT__f_s_p_s[n * 30 + 6] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 2], PRIM_INT__f_s_p_s[n * 30 + 6]);

                        PRIM_INT__f_s_p_s[n * 30 + 7] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_s_s[n * 10 + 2]);
                        PRIM_INT__f_s_p_s[n * 30 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 2], PRIM_INT__f_s_p_s[n * 30 + 7]);

                        PRIM_INT__f_s_p_s[n * 30 + 8] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_s_s[n * 10 + 2]);
                        PRIM_INT__f_s_p_s[n * 30 + 8] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 2], PRIM_INT__f_s_p_s[n * 30 + 8]);
                        PRIM_INT__f_s_p_s[n * 30 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__f_s_p_s[n * 30 + 8]);

                        PRIM_INT__f_s_p_s[n * 30 + 9] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_s_s[n * 10 + 3]);
                        PRIM_INT__f_s_p_s[n * 30 + 9] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 3], PRIM_INT__f_s_p_s[n * 30 + 9]);
                        PRIM_INT__f_s_p_s[n * 30 + 9] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__f_s_p_s[n * 30 + 9]);

                        PRIM_INT__f_s_p_s[n * 30 + 10] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_s_s[n * 10 + 3]);
                        PRIM_INT__f_s_p_s[n * 30 + 10] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 3], PRIM_INT__f_s_p_s[n * 30 + 10]);
                        PRIM_INT__f_s_p_s[n * 30 + 10] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 1], PRIM_INT__f_s_p_s[n * 30 + 10]);

                        PRIM_INT__f_s_p_s[n * 30 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_s_s[n * 10 + 3]);
                        PRIM_INT__f_s_p_s[n * 30 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 3], PRIM_INT__f_s_p_s[n * 30 + 11]);

                        PRIM_INT__f_s_p_s[n * 30 + 12] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_s_s[n * 10 + 4]);
                        PRIM_INT__f_s_p_s[n * 30 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 4], PRIM_INT__f_s_p_s[n * 30 + 12]);
                        PRIM_INT__f_s_p_s[n * 30 + 12] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 4], PRIM_INT__f_s_p_s[n * 30 + 12]);

                        PRIM_INT__f_s_p_s[n * 30 + 13] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_s_s[n * 10 + 4]);
                        PRIM_INT__f_s_p_s[n * 30 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 4], PRIM_INT__f_s_p_s[n * 30 + 13]);
                        PRIM_INT__f_s_p_s[n * 30 + 13] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 2], PRIM_INT__f_s_p_s[n * 30 + 13]);

                        PRIM_INT__f_s_p_s[n * 30 + 14] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_s_s[n * 10 + 4]);
                        PRIM_INT__f_s_p_s[n * 30 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 4], PRIM_INT__f_s_p_s[n * 30 + 14]);
                        PRIM_INT__f_s_p_s[n * 30 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 1], PRIM_INT__f_s_p_s[n * 30 + 14]);

                        PRIM_INT__f_s_p_s[n * 30 + 15] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_s_s[n * 10 + 5]);
                        PRIM_INT__f_s_p_s[n * 30 + 15] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 5], PRIM_INT__f_s_p_s[n * 30 + 15]);
                        PRIM_INT__f_s_p_s[n * 30 + 15] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__f_s_p_s[n * 30 + 15]);

                        PRIM_INT__f_s_p_s[n * 30 + 16] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_s_s[n * 10 + 5]);
                        PRIM_INT__f_s_p_s[n * 30 + 16] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 5], PRIM_INT__f_s_p_s[n * 30 + 16]);

                        PRIM_INT__f_s_p_s[n * 30 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_s_s[n * 10 + 5]);
                        PRIM_INT__f_s_p_s[n * 30 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 5], PRIM_INT__f_s_p_s[n * 30 + 17]);
                        PRIM_INT__f_s_p_s[n * 30 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 2], PRIM_INT__f_s_p_s[n * 30 + 17]);

                        PRIM_INT__f_s_p_s[n * 30 + 18] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_s_s[n * 10 + 6]);
                        PRIM_INT__f_s_p_s[n * 30 + 18] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 6], PRIM_INT__f_s_p_s[n * 30 + 18]);

                        PRIM_INT__f_s_p_s[n * 30 + 19] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_s_s[n * 10 + 6]);
                        PRIM_INT__f_s_p_s[n * 30 + 19] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 6], PRIM_INT__f_s_p_s[n * 30 + 19]);
                        PRIM_INT__f_s_p_s[n * 30 + 19] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__f_s_p_s[n * 30 + 19]);

                        PRIM_INT__f_s_p_s[n * 30 + 20] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_s_s[n * 10 + 6]);
                        PRIM_INT__f_s_p_s[n * 30 + 20] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 6], PRIM_INT__f_s_p_s[n * 30 + 20]);

                        PRIM_INT__f_s_p_s[n * 30 + 21] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_s_s[n * 10 + 7]);
                        PRIM_INT__f_s_p_s[n * 30 + 21] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 7], PRIM_INT__f_s_p_s[n * 30 + 21]);

                        PRIM_INT__f_s_p_s[n * 30 + 22] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_s_s[n * 10 + 7]);
                        PRIM_INT__f_s_p_s[n * 30 + 22] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 7], PRIM_INT__f_s_p_s[n * 30 + 22]);
                        PRIM_INT__f_s_p_s[n * 30 + 22] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 4], PRIM_INT__f_s_p_s[n * 30 + 22]);

                        PRIM_INT__f_s_p_s[n * 30 + 23] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_s_s[n * 10 + 7]);
                        PRIM_INT__f_s_p_s[n * 30 + 23] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 7], PRIM_INT__f_s_p_s[n * 30 + 23]);
                        PRIM_INT__f_s_p_s[n * 30 + 23] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__f_s_p_s[n * 30 + 23]);

                        PRIM_INT__f_s_p_s[n * 30 + 24] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_s_s[n * 10 + 8]);
                        PRIM_INT__f_s_p_s[n * 30 + 24] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 8], PRIM_INT__f_s_p_s[n * 30 + 24]);

                        PRIM_INT__f_s_p_s[n * 30 + 25] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_s_s[n * 10 + 8]);
                        PRIM_INT__f_s_p_s[n * 30 + 25] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 8], PRIM_INT__f_s_p_s[n * 30 + 25]);
                        PRIM_INT__f_s_p_s[n * 30 + 25] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__f_s_p_s[n * 30 + 25]);

                        PRIM_INT__f_s_p_s[n * 30 + 26] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_s_s[n * 10 + 8]);
                        PRIM_INT__f_s_p_s[n * 30 + 26] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 8], PRIM_INT__f_s_p_s[n * 30 + 26]);
                        PRIM_INT__f_s_p_s[n * 30 + 26] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 4], PRIM_INT__f_s_p_s[n * 30 + 26]);

                        PRIM_INT__f_s_p_s[n * 30 + 27] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_s_s[n * 10 + 9]);
                        PRIM_INT__f_s_p_s[n * 30 + 27] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_s_s[(n+1) * 10 + 9], PRIM_INT__f_s_p_s[n * 30 + 27]);

                        PRIM_INT__f_s_p_s[n * 30 + 28] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_s_s[n * 10 + 9]);
                        PRIM_INT__f_s_p_s[n * 30 + 28] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_s_s[(n+1) * 10 + 9], PRIM_INT__f_s_p_s[n * 30 + 28]);

                        PRIM_INT__f_s_p_s[n * 30 + 29] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_s_s[n * 10 + 9]);
                        PRIM_INT__f_s_p_s[n * 30 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_s_s[(n+1) * 10 + 9], PRIM_INT__f_s_p_s[n * 30 + 29]);
                        PRIM_INT__f_s_p_s[n * 30 + 29] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__f_s_p_s[n * 30 + 29]);

                    }


                    VRR_K_g_s_d_s(
                            PRIM_INT__g_s_d_s,
                            PRIM_INT__g_s_p_s,
                            PRIM_INT__g_s_s_s,
                            PRIM_INT__f_s_p_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            2);



                    // Forming PRIM_INT__d_s_p_s[3 * 18];
                    for(n = 0; n < 3; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__d_s_p_s[n * 18 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_s_s[n * 6 + 0]);
                        PRIM_INT__d_s_p_s[n * 18 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__d_s_p_s[n * 18 + 0]);
                        PRIM_INT__d_s_p_s[n * 18 + 0] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__d_s_p_s[n * 18 + 0]);

                        PRIM_INT__d_s_p_s[n * 18 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_s_s[n * 6 + 0]);
                        PRIM_INT__d_s_p_s[n * 18 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__d_s_p_s[n * 18 + 1]);

                        PRIM_INT__d_s_p_s[n * 18 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_s_s[n * 6 + 0]);
                        PRIM_INT__d_s_p_s[n * 18 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__d_s_p_s[n * 18 + 2]);

                        PRIM_INT__d_s_p_s[n * 18 + 3] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_s_s[n * 6 + 1]);
                        PRIM_INT__d_s_p_s[n * 18 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_s_s[(n+1) * 6 + 1], PRIM_INT__d_s_p_s[n * 18 + 3]);
                        PRIM_INT__d_s_p_s[n * 18 + 3] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__d_s_p_s[n * 18 + 3]);

                        PRIM_INT__d_s_p_s[n * 18 + 4] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_s_s[n * 6 + 1]);
                        PRIM_INT__d_s_p_s[n * 18 + 4] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_s_s[(n+1) * 6 + 1], PRIM_INT__d_s_p_s[n * 18 + 4]);
                        PRIM_INT__d_s_p_s[n * 18 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__d_s_p_s[n * 18 + 4]);

                        PRIM_INT__d_s_p_s[n * 18 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_s_s[n * 6 + 1]);
                        PRIM_INT__d_s_p_s[n * 18 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_s_s[(n+1) * 6 + 1], PRIM_INT__d_s_p_s[n * 18 + 5]);

                        PRIM_INT__d_s_p_s[n * 18 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_s_s[n * 6 + 2]);
                        PRIM_INT__d_s_p_s[n * 18 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_s_s[(n+1) * 6 + 2], PRIM_INT__d_s_p_s[n * 18 + 6]);
                        PRIM_INT__d_s_p_s[n * 18 + 6] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__d_s_p_s[n * 18 + 6]);

                        PRIM_INT__d_s_p_s[n * 18 + 7] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_s_s[n * 6 + 2]);
                        PRIM_INT__d_s_p_s[n * 18 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_s_s[(n+1) * 6 + 2], PRIM_INT__d_s_p_s[n * 18 + 7]);

                        PRIM_INT__d_s_p_s[n * 18 + 8] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_s_s[n * 6 + 2]);
                        PRIM_INT__d_s_p_s[n * 18 + 8] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_s_s[(n+1) * 6 + 2], PRIM_INT__d_s_p_s[n * 18 + 8]);
                        PRIM_INT__d_s_p_s[n * 18 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__d_s_p_s[n * 18 + 8]);

                        PRIM_INT__d_s_p_s[n * 18 + 9] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_s_s[n * 6 + 3]);
                        PRIM_INT__d_s_p_s[n * 18 + 9] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__d_s_p_s[n * 18 + 9]);

                        PRIM_INT__d_s_p_s[n * 18 + 10] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_s_s[n * 6 + 3]);
                        PRIM_INT__d_s_p_s[n * 18 + 10] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__d_s_p_s[n * 18 + 10]);
                        PRIM_INT__d_s_p_s[n * 18 + 10] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__d_s_p_s[n * 18 + 10]);

                        PRIM_INT__d_s_p_s[n * 18 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_s_s[n * 6 + 3]);
                        PRIM_INT__d_s_p_s[n * 18 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__d_s_p_s[n * 18 + 11]);

                        PRIM_INT__d_s_p_s[n * 18 + 12] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_s_s[n * 6 + 4]);
                        PRIM_INT__d_s_p_s[n * 18 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_s_s[(n+1) * 6 + 4], PRIM_INT__d_s_p_s[n * 18 + 12]);

                        PRIM_INT__d_s_p_s[n * 18 + 13] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_s_s[n * 6 + 4]);
                        PRIM_INT__d_s_p_s[n * 18 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_s_s[(n+1) * 6 + 4], PRIM_INT__d_s_p_s[n * 18 + 13]);
                        PRIM_INT__d_s_p_s[n * 18 + 13] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__d_s_p_s[n * 18 + 13]);

                        PRIM_INT__d_s_p_s[n * 18 + 14] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_s_s[n * 6 + 4]);
                        PRIM_INT__d_s_p_s[n * 18 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_s_s[(n+1) * 6 + 4], PRIM_INT__d_s_p_s[n * 18 + 14]);
                        PRIM_INT__d_s_p_s[n * 18 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__d_s_p_s[n * 18 + 14]);

                        PRIM_INT__d_s_p_s[n * 18 + 15] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_s_s[n * 6 + 5]);
                        PRIM_INT__d_s_p_s[n * 18 + 15] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__d_s_p_s[n * 18 + 15]);

                        PRIM_INT__d_s_p_s[n * 18 + 16] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_s_s[n * 6 + 5]);
                        PRIM_INT__d_s_p_s[n * 18 + 16] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__d_s_p_s[n * 18 + 16]);

                        PRIM_INT__d_s_p_s[n * 18 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_s_s[n * 6 + 5]);
                        PRIM_INT__d_s_p_s[n * 18 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__d_s_p_s[n * 18 + 17]);
                        PRIM_INT__d_s_p_s[n * 18 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__d_s_p_s[n * 18 + 17]);

                    }


                    VRR_K_f_s_d_s(
                            PRIM_INT__f_s_d_s,
                            PRIM_INT__f_s_p_s,
                            PRIM_INT__f_s_s_s,
                            PRIM_INT__d_s_p_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            2);


                    VRR_K_g_s_f_s(
                            PRIM_INT__g_s_f_s,
                            PRIM_INT__g_s_d_s,
                            PRIM_INT__g_s_p_s,
                            PRIM_INT__f_s_d_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            1);


                    VRR_I_h_s_s_s(
                            PRIM_INT__h_s_s_s,
                            PRIM_INT__g_s_s_s,
                            PRIM_INT__f_s_s_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            7);


                    VRR_K_h_s_p_s(
                            PRIM_INT__h_s_p_s,
                            PRIM_INT__h_s_s_s,
                            PRIM_INT__g_s_s_s,
                            Q_PA,
                            aoq_PQ,
                            one_over_2pq,
                            3);


                    VRR_K_h_s_d_s(
                            PRIM_INT__h_s_d_s,
                            PRIM_INT__h_s_p_s,
                            PRIM_INT__h_s_s_s,
                            PRIM_INT__g_s_p_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            2);


                    ostei_general_vrr_K(5, 0, 3, 0, 1,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__h_s_d_s, PRIM_INT__h_s_p_s, NULL, PRIM_INT__g_s_d_s, NULL, PRIM_INT__h_s_f_s);


                    VRR_I_i_s_s_s(
                            PRIM_INT__i_s_s_s,
                            PRIM_INT__h_s_s_s,
                            PRIM_INT__g_s_s_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            6);


                    VRR_K_i_s_p_s(
                            PRIM_INT__i_s_p_s,
                            PRIM_INT__i_s_s_s,
                            PRIM_INT__h_s_s_s,
                            Q_PA,
                            aoq_PQ,
                            one_over_2pq,
                            3);


                    ostei_general_vrr_K(6, 0, 2, 0, 2,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__i_s_p_s, PRIM_INT__i_s_s_s, NULL, PRIM_INT__h_s_p_s, NULL, PRIM_INT__i_s_d_s);


                    ostei_general_vrr_K(6, 0, 3, 0, 1,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__i_s_d_s, PRIM_INT__i_s_p_s, NULL, PRIM_INT__h_s_d_s, NULL, PRIM_INT__i_s_f_s);


                    VRR_I_k_s_s_s(
                            PRIM_INT__k_s_s_s,
                            PRIM_INT__i_s_s_s,
                            PRIM_INT__h_s_s_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            5);


                    ostei_general_vrr_K(7, 0, 1, 0, 3,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__k_s_s_s, NULL, NULL, PRIM_INT__i_s_s_s, NULL, PRIM_INT__k_s_p_s);


                    ostei_general_vrr_K(7, 0, 2, 0, 2,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__k_s_p_s, PRIM_INT__k_s_s_s, NULL, PRIM_INT__i_s_p_s, NULL, PRIM_INT__k_s_d_s);


                    ostei_general_vrr_K(7, 0, 3, 0, 1,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__k_s_d_s, PRIM_INT__k_s_p_s, NULL, PRIM_INT__i_s_d_s, NULL, PRIM_INT__k_s_f_s);


                    ostei_general_vrr1_I(8, 4,
                            one_over_2p, a_over_p, aop_PQ, P_PA,
                            PRIM_INT__k_s_s_s, PRIM_INT__i_s_s_s, PRIM_INT__l_s_s_s);


                    ostei_general_vrr_K(8, 0, 1, 0, 3,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__l_s_s_s, NULL, NULL, PRIM_INT__k_s_s_s, NULL, PRIM_INT__l_s_p_s);


                    ostei_general_vrr_K(8, 0, 2, 0, 2,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__l_s_p_s, PRIM_INT__l_s_s_s, NULL, PRIM_INT__k_s_p_s, NULL, PRIM_INT__l_s_d_s);


                    ostei_general_vrr_K(8, 0, 3, 0, 1,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__l_s_d_s, PRIM_INT__l_s_p_s, NULL, PRIM_INT__k_s_d_s, NULL, PRIM_INT__l_s_f_s);




                    ////////////////////////////////////
                    // Accumulate contracted integrals
                    ////////////////////////////////////
                    if(lastoffset == 0)
                    {
                        contract_all(90, PRIM_INT__g_s_d_s, PRIM_PTR_INT__g_s_d_s);
                        contract_all(150, PRIM_INT__g_s_f_s, PRIM_PTR_INT__g_s_f_s);
                        contract_all(126, PRIM_INT__h_s_d_s, PRIM_PTR_INT__h_s_d_s);
                        contract_all(210, PRIM_INT__h_s_f_s, PRIM_PTR_INT__h_s_f_s);
                        contract_all(168, PRIM_INT__i_s_d_s, PRIM_PTR_INT__i_s_d_s);
                        contract_all(280, PRIM_INT__i_s_f_s, PRIM_PTR_INT__i_s_f_s);
                        contract_all(216, PRIM_INT__k_s_d_s, PRIM_PTR_INT__k_s_d_s);
                        contract_all(360, PRIM_INT__k_s_f_s, PRIM_PTR_INT__k_s_f_s);
                        contract_all(270, PRIM_INT__l_s_d_s, PRIM_PTR_INT__l_s_d_s);
                        contract_all(450, PRIM_INT__l_s_f_s, PRIM_PTR_INT__l_s_f_s);
                    }
                    else
                    {
                        contract(90, shelloffsets, PRIM_INT__g_s_d_s, PRIM_PTR_INT__g_s_d_s);
                        contract(150, shelloffsets, PRIM_INT__g_s_f_s, PRIM_PTR_INT__g_s_f_s);
                        contract(126, shelloffsets, PRIM_INT__h_s_d_s, PRIM_PTR_INT__h_s_d_s);
                        contract(210, shelloffsets, PRIM_INT__h_s_f_s, PRIM_PTR_INT__h_s_f_s);
                        contract(168, shelloffsets, PRIM_INT__i_s_d_s, PRIM_PTR_INT__i_s_d_s);
                        contract(280, shelloffsets, PRIM_INT__i_s_f_s, PRIM_PTR_INT__i_s_f_s);
                        contract(216, shelloffsets, PRIM_INT__k_s_d_s, PRIM_PTR_INT__k_s_d_s);
                        contract(360, shelloffsets, PRIM_INT__k_s_f_s, PRIM_PTR_INT__k_s_f_s);
                        contract(270, shelloffsets, PRIM_INT__l_s_d_s, PRIM_PTR_INT__l_s_d_s);
                        contract(450, shelloffsets, PRIM_INT__l_s_f_s, PRIM_PTR_INT__l_s_f_s);
                        PRIM_PTR_INT__g_s_d_s += lastoffset*90;
                        PRIM_PTR_INT__g_s_f_s += lastoffset*150;
                        PRIM_PTR_INT__h_s_d_s += lastoffset*126;
                        PRIM_PTR_INT__h_s_f_s += lastoffset*210;
                        PRIM_PTR_INT__i_s_d_s += lastoffset*168;
                        PRIM_PTR_INT__i_s_f_s += lastoffset*280;
                        PRIM_PTR_INT__k_s_d_s += lastoffset*216;
                        PRIM_PTR_INT__k_s_f_s += lastoffset*360;
                        PRIM_PTR_INT__l_s_d_s += lastoffset*270;
                        PRIM_PTR_INT__l_s_f_s += lastoffset*450;
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
                double const * restrict HRR_INT__g_s_d_s = INT__g_s_d_s + abcd * 90;
                double const * restrict HRR_INT__g_s_f_s = INT__g_s_f_s + abcd * 150;
                double const * restrict HRR_INT__h_s_d_s = INT__h_s_d_s + abcd * 126;
                double const * restrict HRR_INT__h_s_f_s = INT__h_s_f_s + abcd * 210;
                double const * restrict HRR_INT__i_s_d_s = INT__i_s_d_s + abcd * 168;
                double const * restrict HRR_INT__i_s_f_s = INT__i_s_f_s + abcd * 280;
                double const * restrict HRR_INT__k_s_d_s = INT__k_s_d_s + abcd * 216;
                double const * restrict HRR_INT__k_s_f_s = INT__k_s_f_s + abcd * 360;
                double const * restrict HRR_INT__l_s_d_s = INT__l_s_d_s + abcd * 270;
                double const * restrict HRR_INT__l_s_f_s = INT__l_s_f_s + abcd * 450;
                double * restrict HRR_INT__g_g_d_p = INT__g_g_d_p + real_abcd * 4050;

                // form INT__g_p_d_s
                HRR_J_g_p(
                    HRR_INT__g_p_d_s,
                    HRR_INT__g_s_d_s,
                    HRR_INT__h_s_d_s,
                    hAB, 6);

                // form INT__g_p_f_s
                HRR_J_g_p(
                    HRR_INT__g_p_f_s,
                    HRR_INT__g_s_f_s,
                    HRR_INT__h_s_f_s,
                    hAB, 10);

                // form INT__h_p_d_s
                HRR_J_h_p(
                    HRR_INT__h_p_d_s,
                    HRR_INT__h_s_d_s,
                    HRR_INT__i_s_d_s,
                    hAB, 6);

                // form INT__h_p_f_s
                HRR_J_h_p(
                    HRR_INT__h_p_f_s,
                    HRR_INT__h_s_f_s,
                    HRR_INT__i_s_f_s,
                    hAB, 10);

                // form INT__i_p_d_s
                HRR_J_i_p(
                    HRR_INT__i_p_d_s,
                    HRR_INT__i_s_d_s,
                    HRR_INT__k_s_d_s,
                    hAB, 6);

                // form INT__i_p_f_s
                HRR_J_i_p(
                    HRR_INT__i_p_f_s,
                    HRR_INT__i_s_f_s,
                    HRR_INT__k_s_f_s,
                    hAB, 10);

                // form INT__k_p_d_s
                HRR_J_k_p(
                    HRR_INT__k_p_d_s,
                    HRR_INT__k_s_d_s,
                    HRR_INT__l_s_d_s,
                    hAB, 6);

                // form INT__k_p_f_s
                HRR_J_k_p(
                    HRR_INT__k_p_f_s,
                    HRR_INT__k_s_f_s,
                    HRR_INT__l_s_f_s,
                    hAB, 10);

                // form INT__g_d_d_s
                HRR_J_g_d(
                    HRR_INT__g_d_d_s,
                    HRR_INT__g_p_d_s,
                    HRR_INT__h_p_d_s,
                    hAB, 6);

                // form INT__g_d_f_s
                HRR_J_g_d(
                    HRR_INT__g_d_f_s,
                    HRR_INT__g_p_f_s,
                    HRR_INT__h_p_f_s,
                    hAB, 10);

                // form INT__h_d_d_s
                HRR_J_h_d(
                    HRR_INT__h_d_d_s,
                    HRR_INT__h_p_d_s,
                    HRR_INT__i_p_d_s,
                    hAB, 6);

                // form INT__h_d_f_s
                HRR_J_h_d(
                    HRR_INT__h_d_f_s,
                    HRR_INT__h_p_f_s,
                    HRR_INT__i_p_f_s,
                    hAB, 10);

                // form INT__i_d_d_s
                HRR_J_i_d(
                    HRR_INT__i_d_d_s,
                    HRR_INT__i_p_d_s,
                    HRR_INT__k_p_d_s,
                    hAB, 6);

                // form INT__i_d_f_s
                HRR_J_i_d(
                    HRR_INT__i_d_f_s,
                    HRR_INT__i_p_f_s,
                    HRR_INT__k_p_f_s,
                    hAB, 10);

                // form INT__g_f_d_s
                HRR_J_g_f(
                    HRR_INT__g_f_d_s,
                    HRR_INT__g_d_d_s,
                    HRR_INT__h_d_d_s,
                    hAB, 6);

                // form INT__g_f_f_s
                HRR_J_g_f(
                    HRR_INT__g_f_f_s,
                    HRR_INT__g_d_f_s,
                    HRR_INT__h_d_f_s,
                    hAB, 10);

                // form INT__h_f_d_s
                HRR_J_h_f(
                    HRR_INT__h_f_d_s,
                    HRR_INT__h_d_d_s,
                    HRR_INT__i_d_d_s,
                    hAB, 6);

                // form INT__h_f_f_s
                HRR_J_h_f(
                    HRR_INT__h_f_f_s,
                    HRR_INT__h_d_f_s,
                    HRR_INT__i_d_f_s,
                    hAB, 10);

                // form INT__g_g_d_s
                HRR_J_g_g(
                    HRR_INT__g_g_d_s,
                    HRR_INT__g_f_d_s,
                    HRR_INT__h_f_d_s,
                    hAB, 6);

                // form INT__g_g_f_s
                HRR_J_g_g(
                    HRR_INT__g_g_f_s,
                    HRR_INT__g_f_f_s,
                    HRR_INT__h_f_f_s,
                    hAB, 10);

                // form INT__g_g_d_p
                for(ibra = 0; ibra < 225; ++ibra)
                {
                    HRR_INT__g_g_d_p[ibra * 18 + 0] = HRR_INT__g_g_f_s[ibra * 10 + 0] + ( hCD[0] * HRR_INT__g_g_d_s[ibra * 6 + 0] );

                    HRR_INT__g_g_d_p[ibra * 18 + 1] = HRR_INT__g_g_f_s[ibra * 10 + 1] + ( hCD[1] * HRR_INT__g_g_d_s[ibra * 6 + 0] );

                    HRR_INT__g_g_d_p[ibra * 18 + 2] = HRR_INT__g_g_f_s[ibra * 10 + 2] + ( hCD[2] * HRR_INT__g_g_d_s[ibra * 6 + 0] );

                    HRR_INT__g_g_d_p[ibra * 18 + 3] = HRR_INT__g_g_f_s[ibra * 10 + 1] + ( hCD[0] * HRR_INT__g_g_d_s[ibra * 6 + 1] );

                    HRR_INT__g_g_d_p[ibra * 18 + 4] = HRR_INT__g_g_f_s[ibra * 10 + 3] + ( hCD[1] * HRR_INT__g_g_d_s[ibra * 6 + 1] );

                    HRR_INT__g_g_d_p[ibra * 18 + 5] = HRR_INT__g_g_f_s[ibra * 10 + 4] + ( hCD[2] * HRR_INT__g_g_d_s[ibra * 6 + 1] );

                    HRR_INT__g_g_d_p[ibra * 18 + 6] = HRR_INT__g_g_f_s[ibra * 10 + 2] + ( hCD[0] * HRR_INT__g_g_d_s[ibra * 6 + 2] );

                    HRR_INT__g_g_d_p[ibra * 18 + 7] = HRR_INT__g_g_f_s[ibra * 10 + 4] + ( hCD[1] * HRR_INT__g_g_d_s[ibra * 6 + 2] );

                    HRR_INT__g_g_d_p[ibra * 18 + 8] = HRR_INT__g_g_f_s[ibra * 10 + 5] + ( hCD[2] * HRR_INT__g_g_d_s[ibra * 6 + 2] );

                    HRR_INT__g_g_d_p[ibra * 18 + 9] = HRR_INT__g_g_f_s[ibra * 10 + 3] + ( hCD[0] * HRR_INT__g_g_d_s[ibra * 6 + 3] );

                    HRR_INT__g_g_d_p[ibra * 18 + 10] = HRR_INT__g_g_f_s[ibra * 10 + 6] + ( hCD[1] * HRR_INT__g_g_d_s[ibra * 6 + 3] );

                    HRR_INT__g_g_d_p[ibra * 18 + 11] = HRR_INT__g_g_f_s[ibra * 10 + 7] + ( hCD[2] * HRR_INT__g_g_d_s[ibra * 6 + 3] );

                    HRR_INT__g_g_d_p[ibra * 18 + 12] = HRR_INT__g_g_f_s[ibra * 10 + 4] + ( hCD[0] * HRR_INT__g_g_d_s[ibra * 6 + 4] );

                    HRR_INT__g_g_d_p[ibra * 18 + 13] = HRR_INT__g_g_f_s[ibra * 10 + 7] + ( hCD[1] * HRR_INT__g_g_d_s[ibra * 6 + 4] );

                    HRR_INT__g_g_d_p[ibra * 18 + 14] = HRR_INT__g_g_f_s[ibra * 10 + 8] + ( hCD[2] * HRR_INT__g_g_d_s[ibra * 6 + 4] );

                    HRR_INT__g_g_d_p[ibra * 18 + 15] = HRR_INT__g_g_f_s[ibra * 10 + 5] + ( hCD[0] * HRR_INT__g_g_d_s[ibra * 6 + 5] );

                    HRR_INT__g_g_d_p[ibra * 18 + 16] = HRR_INT__g_g_f_s[ibra * 10 + 8] + ( hCD[1] * HRR_INT__g_g_d_s[ibra * 6 + 5] );

                    HRR_INT__g_g_d_p[ibra * 18 + 17] = HRR_INT__g_g_f_s[ibra * 10 + 9] + ( hCD[2] * HRR_INT__g_g_d_s[ibra * 6 + 5] );

                }


            }  // close HRR loop


        }   // close loop cdbatch

        istart = iend;
    }  // close loop over ab

    return P.nshell12_clip * Q.nshell12_clip;
}

int ostei_g_g_p_d(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__g_g_p_d)
{
    double Q_AB[3*Q.nshell12];
    struct simint_multi_shellpair Q_tmp = Q;
    Q_tmp.PA_x = Q.PB_x;  Q_tmp.PA_y = Q.PB_y;  Q_tmp.PA_z = Q.PB_z;
    Q_tmp.PB_x = Q.PA_x;  Q_tmp.PB_y = Q.PA_y;  Q_tmp.PB_z = Q.PA_z;
    Q_tmp.AB_x = Q_AB;
    Q_tmp.AB_y = Q_AB + Q.nshell12;
    Q_tmp.AB_z = Q_AB + 2*Q.nshell12;

    for(int i = 0; i < Q.nshell12; i++)
    {
        Q_tmp.AB_x[i] = -Q.AB_x[i];
        Q_tmp.AB_y[i] = -Q.AB_y[i];
        Q_tmp.AB_z[i] = -Q.AB_z[i];
    }

    int ret = ostei_g_g_d_p(P, Q_tmp, screen_tol, work, INT__g_g_p_d);
    double buffer[4050] SIMINT_ALIGN_ARRAY_DBL;

    for(int q = 0; q < ret; q++)
    {
        int idx = 0;
        for(int a = 0; a < 15; ++a)
        for(int b = 0; b < 15; ++b)
        for(int c = 0; c < 3; ++c)
        for(int d = 0; d < 6; ++d)
            buffer[idx++] = INT__g_g_p_d[q*4050+a*270+b*18+d*3+c];

        memcpy(INT__g_g_p_d+q*4050, buffer, 4050*sizeof(double));
    }

    return ret;
}

