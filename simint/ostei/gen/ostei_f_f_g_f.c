#include "simint/boys/boys.h"
#include "simint/ostei/gen/ostei_generated.h"
#include "simint/vectorization/vectorization.h"
#include <math.h>
#include <string.h>


int ostei_f_f_g_f(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__f_f_g_f)
{

    SIMINT_ASSUME_ALIGN_DBL(work);
    SIMINT_ASSUME_ALIGN_DBL(INT__f_f_g_f);
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
    double * const INT__f_s_g_s = work + (SIMINT_NSHELL_SIMD * 0);
    double * const INT__f_s_h_s = work + (SIMINT_NSHELL_SIMD * 150);
    double * const INT__f_s_i_s = work + (SIMINT_NSHELL_SIMD * 360);
    double * const INT__f_s_k_s = work + (SIMINT_NSHELL_SIMD * 640);
    double * const INT__g_s_g_s = work + (SIMINT_NSHELL_SIMD * 1000);
    double * const INT__g_s_h_s = work + (SIMINT_NSHELL_SIMD * 1225);
    double * const INT__g_s_i_s = work + (SIMINT_NSHELL_SIMD * 1540);
    double * const INT__g_s_k_s = work + (SIMINT_NSHELL_SIMD * 1960);
    double * const INT__h_s_g_s = work + (SIMINT_NSHELL_SIMD * 2500);
    double * const INT__h_s_h_s = work + (SIMINT_NSHELL_SIMD * 2815);
    double * const INT__h_s_i_s = work + (SIMINT_NSHELL_SIMD * 3256);
    double * const INT__h_s_k_s = work + (SIMINT_NSHELL_SIMD * 3844);
    double * const INT__i_s_g_s = work + (SIMINT_NSHELL_SIMD * 4600);
    double * const INT__i_s_h_s = work + (SIMINT_NSHELL_SIMD * 5020);
    double * const INT__i_s_i_s = work + (SIMINT_NSHELL_SIMD * 5608);
    double * const INT__i_s_k_s = work + (SIMINT_NSHELL_SIMD * 6392);
    SIMINT_DBLTYPE * const primwork = (SIMINT_DBLTYPE *)(work + SIMINT_NSHELL_SIMD*7400);
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_s = primwork + 0;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_p_s = primwork + 14;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_d_s = primwork + 53;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_f_s = primwork + 125;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s = primwork + 235;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s = primwork + 385;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_i_s = primwork + 574;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_k_s = primwork + 798;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_s = primwork + 1050;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_p_s = primwork + 1068;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_d_s = primwork + 1122;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_f_s = primwork + 1230;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_g_s = primwork + 1410;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_h_s = primwork + 1680;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_i_s = primwork + 2058;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_k_s = primwork + 2562;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_s = primwork + 3210;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_p_s = primwork + 3240;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_d_s = primwork + 3330;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_f_s = primwork + 3510;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_g_s = primwork + 3810;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_h_s = primwork + 4260;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_i_s = primwork + 4890;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_k_s = primwork + 5730;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_p_s = primwork + 6810;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s = primwork + 6930;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_f_s = primwork + 7170;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_g_s = primwork + 7570;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_h_s = primwork + 8170;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_i_s = primwork + 9010;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_k_s = primwork + 10130;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_d_s = primwork + 11570;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_f_s = primwork + 11840;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_g_s = primwork + 12290;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_h_s = primwork + 12965;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_i_s = primwork + 13910;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_k_s = primwork + 15170;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_f_s = primwork + 16790;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_g_s = primwork + 17210;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_h_s = primwork + 17840;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_i_s = primwork + 18722;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_k_s = primwork + 19898;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_g_s = primwork + 21410;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_h_s = primwork + 21830;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_i_s = primwork + 22418;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_k_s = primwork + 23202;
    double * const hrrwork = (double *)(primwork + 24210);
    double * const HRR_INT__f_p_g_s = hrrwork + 0;
    double * const HRR_INT__f_p_h_s = hrrwork + 450;
    double * const HRR_INT__f_p_i_s = hrrwork + 1080;
    double * const HRR_INT__f_p_k_s = hrrwork + 1920;
    double * const HRR_INT__f_d_g_s = hrrwork + 3000;
    double * const HRR_INT__f_d_h_s = hrrwork + 3900;
    double * const HRR_INT__f_d_i_s = hrrwork + 5160;
    double * const HRR_INT__f_d_k_s = hrrwork + 6840;
    double * const HRR_INT__f_f_g_s = hrrwork + 9000;
    double * const HRR_INT__f_f_g_p = hrrwork + 10500;
    double * const HRR_INT__f_f_g_d = hrrwork + 15000;
    double * const HRR_INT__f_f_h_s = hrrwork + 24000;
    double * const HRR_INT__f_f_h_p = hrrwork + 26100;
    double * const HRR_INT__f_f_h_d = hrrwork + 32400;
    double * const HRR_INT__f_f_i_s = hrrwork + 45000;
    double * const HRR_INT__f_f_i_p = hrrwork + 47800;
    double * const HRR_INT__f_f_k_s = hrrwork + 56200;
    double * const HRR_INT__g_p_g_s = hrrwork + 59800;
    double * const HRR_INT__g_p_h_s = hrrwork + 60475;
    double * const HRR_INT__g_p_i_s = hrrwork + 61420;
    double * const HRR_INT__g_p_k_s = hrrwork + 62680;
    double * const HRR_INT__g_d_g_s = hrrwork + 64300;
    double * const HRR_INT__g_d_h_s = hrrwork + 65650;
    double * const HRR_INT__g_d_i_s = hrrwork + 67540;
    double * const HRR_INT__g_d_k_s = hrrwork + 70060;
    double * const HRR_INT__h_p_g_s = hrrwork + 73300;
    double * const HRR_INT__h_p_h_s = hrrwork + 74245;
    double * const HRR_INT__h_p_i_s = hrrwork + 75568;
    double * const HRR_INT__h_p_k_s = hrrwork + 77332;


    // Create constants
    const SIMINT_DBLTYPE const_1 = SIMINT_DBLSET1(1);
    const SIMINT_DBLTYPE const_2 = SIMINT_DBLSET1(2);
    const SIMINT_DBLTYPE const_3 = SIMINT_DBLSET1(3);
    const SIMINT_DBLTYPE const_4 = SIMINT_DBLSET1(4);
    const SIMINT_DBLTYPE const_5 = SIMINT_DBLSET1(5);
    const SIMINT_DBLTYPE const_6 = SIMINT_DBLSET1(6);
    const SIMINT_DBLTYPE const_7 = SIMINT_DBLSET1(7);
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
            memset(work, 0, SIMINT_NSHELL_SIMD * 7400 * sizeof(double));
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
                double * restrict PRIM_PTR_INT__f_s_g_s = INT__f_s_g_s + abcd * 150;
                double * restrict PRIM_PTR_INT__f_s_h_s = INT__f_s_h_s + abcd * 210;
                double * restrict PRIM_PTR_INT__f_s_i_s = INT__f_s_i_s + abcd * 280;
                double * restrict PRIM_PTR_INT__f_s_k_s = INT__f_s_k_s + abcd * 360;
                double * restrict PRIM_PTR_INT__g_s_g_s = INT__g_s_g_s + abcd * 225;
                double * restrict PRIM_PTR_INT__g_s_h_s = INT__g_s_h_s + abcd * 315;
                double * restrict PRIM_PTR_INT__g_s_i_s = INT__g_s_i_s + abcd * 420;
                double * restrict PRIM_PTR_INT__g_s_k_s = INT__g_s_k_s + abcd * 540;
                double * restrict PRIM_PTR_INT__h_s_g_s = INT__h_s_g_s + abcd * 315;
                double * restrict PRIM_PTR_INT__h_s_h_s = INT__h_s_h_s + abcd * 441;
                double * restrict PRIM_PTR_INT__h_s_i_s = INT__h_s_i_s + abcd * 588;
                double * restrict PRIM_PTR_INT__h_s_k_s = INT__h_s_k_s + abcd * 756;
                double * restrict PRIM_PTR_INT__i_s_g_s = INT__i_s_g_s + abcd * 420;
                double * restrict PRIM_PTR_INT__i_s_h_s = INT__i_s_h_s + abcd * 588;
                double * restrict PRIM_PTR_INT__i_s_i_s = INT__i_s_i_s + abcd * 784;
                double * restrict PRIM_PTR_INT__i_s_k_s = INT__i_s_k_s + abcd * 1008;



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
                            PRIM_PTR_INT__f_s_g_s += 150;
                            PRIM_PTR_INT__f_s_h_s += 210;
                            PRIM_PTR_INT__f_s_i_s += 280;
                            PRIM_PTR_INT__f_s_k_s += 360;
                            PRIM_PTR_INT__g_s_g_s += 225;
                            PRIM_PTR_INT__g_s_h_s += 315;
                            PRIM_PTR_INT__g_s_i_s += 420;
                            PRIM_PTR_INT__g_s_k_s += 540;
                            PRIM_PTR_INT__h_s_g_s += 315;
                            PRIM_PTR_INT__h_s_h_s += 441;
                            PRIM_PTR_INT__h_s_i_s += 588;
                            PRIM_PTR_INT__h_s_k_s += 756;
                            PRIM_PTR_INT__i_s_g_s += 420;
                            PRIM_PTR_INT__i_s_h_s += 588;
                            PRIM_PTR_INT__i_s_i_s += 784;
                            PRIM_PTR_INT__i_s_k_s += 1008;
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
                            PRIM_PTR_INT__f_s_g_s += lastoffset*150;
                            PRIM_PTR_INT__f_s_h_s += lastoffset*210;
                            PRIM_PTR_INT__f_s_i_s += lastoffset*280;
                            PRIM_PTR_INT__f_s_k_s += lastoffset*360;
                            PRIM_PTR_INT__g_s_g_s += lastoffset*225;
                            PRIM_PTR_INT__g_s_h_s += lastoffset*315;
                            PRIM_PTR_INT__g_s_i_s += lastoffset*420;
                            PRIM_PTR_INT__g_s_k_s += lastoffset*540;
                            PRIM_PTR_INT__h_s_g_s += lastoffset*315;
                            PRIM_PTR_INT__h_s_h_s += lastoffset*441;
                            PRIM_PTR_INT__h_s_i_s += lastoffset*588;
                            PRIM_PTR_INT__h_s_k_s += lastoffset*756;
                            PRIM_PTR_INT__i_s_g_s += lastoffset*420;
                            PRIM_PTR_INT__i_s_h_s += lastoffset*588;
                            PRIM_PTR_INT__i_s_i_s += lastoffset*784;
                            PRIM_PTR_INT__i_s_k_s += lastoffset*1008;
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
                    // Maximum v value: 13
                    //////////////////////////////////////////////
                    // The parameter to the Fjt function
                    const SIMINT_DBLTYPE F_x = SIMINT_MUL(R2, alpha);


                    const SIMINT_DBLTYPE Q_prefac = mask_load(nlane, Q.prefac + j);


                    boys_F_split(PRIM_INT__s_s_s_s, F_x, 13);
                    SIMINT_DBLTYPE prefac = SIMINT_SQRT(one_over_PQalpha_sum);
                    prefac = SIMINT_MUL(SIMINT_MUL(P_prefac, Q_prefac), prefac);
                    for(n = 0; n <= 13; n++)
                        PRIM_INT__s_s_s_s[n] = SIMINT_MUL(PRIM_INT__s_s_s_s[n], prefac);

                    //////////////////////////////////////////////
                    // Primitive integrals: Vertical recurrance
                    //////////////////////////////////////////////

                    const SIMINT_DBLTYPE vrr_const_1_over_2p = one_over_2p;
                    const SIMINT_DBLTYPE vrr_const_2_over_2p = SIMINT_MUL(const_2, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_3_over_2p = SIMINT_MUL(const_3, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_4_over_2p = SIMINT_MUL(const_4, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_5_over_2p = SIMINT_MUL(const_5, one_over_2p);
                    const SIMINT_DBLTYPE vrr_const_1_over_2q = one_over_2q;
                    const SIMINT_DBLTYPE vrr_const_2_over_2q = SIMINT_MUL(const_2, one_over_2q);
                    const SIMINT_DBLTYPE vrr_const_3_over_2q = SIMINT_MUL(const_3, one_over_2q);
                    const SIMINT_DBLTYPE vrr_const_4_over_2q = SIMINT_MUL(const_4, one_over_2q);
                    const SIMINT_DBLTYPE vrr_const_5_over_2q = SIMINT_MUL(const_5, one_over_2q);
                    const SIMINT_DBLTYPE vrr_const_6_over_2q = SIMINT_MUL(const_6, one_over_2q);
                    const SIMINT_DBLTYPE vrr_const_1_over_2pq = one_over_2pq;
                    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(const_2, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_3_over_2pq = SIMINT_MUL(const_3, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_4_over_2pq = SIMINT_MUL(const_4, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_5_over_2pq = SIMINT_MUL(const_5, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_6_over_2pq = SIMINT_MUL(const_6, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_7_over_2pq = SIMINT_MUL(const_7, one_over_2pq);



                    // Forming PRIM_INT__s_s_p_s[13 * 3];
                    for(n = 0; n < 13; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_p_s[n * 3 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_p_s[n * 3 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_p_s[n * 3 + 0]);

                        PRIM_INT__s_s_p_s[n * 3 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_p_s[n * 3 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_p_s[n * 3 + 1]);

                        PRIM_INT__s_s_p_s[n * 3 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_p_s[n * 3 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_p_s[n * 3 + 2]);

                    }



                    // Forming PRIM_INT__s_s_d_s[12 * 6];
                    for(n = 0; n < 12; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_d_s[n * 6 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_p_s[n * 3 + 0]);
                        PRIM_INT__s_s_d_s[n * 6 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__s_s_d_s[n * 6 + 0]);
                        PRIM_INT__s_s_d_s[n * 6 + 0] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_s_d_s[n * 6 + 0]);

                        PRIM_INT__s_s_d_s[n * 6 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_p_s[n * 3 + 0]);
                        PRIM_INT__s_s_d_s[n * 6 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__s_s_d_s[n * 6 + 1]);

                        PRIM_INT__s_s_d_s[n * 6 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_p_s[n * 3 + 0]);
                        PRIM_INT__s_s_d_s[n * 6 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__s_s_d_s[n * 6 + 2]);

                        PRIM_INT__s_s_d_s[n * 6 + 3] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_p_s[n * 3 + 1]);
                        PRIM_INT__s_s_d_s[n * 6 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__s_s_d_s[n * 6 + 3]);
                        PRIM_INT__s_s_d_s[n * 6 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_s_d_s[n * 6 + 3]);

                        PRIM_INT__s_s_d_s[n * 6 + 4] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_p_s[n * 3 + 1]);
                        PRIM_INT__s_s_d_s[n * 6 + 4] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__s_s_d_s[n * 6 + 4]);

                        PRIM_INT__s_s_d_s[n * 6 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_p_s[n * 3 + 2]);
                        PRIM_INT__s_s_d_s[n * 6 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__s_s_d_s[n * 6 + 5]);
                        PRIM_INT__s_s_d_s[n * 6 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_s_d_s[n * 6 + 5]);

                    }



                    // Forming PRIM_INT__s_s_f_s[11 * 10];
                    for(n = 0; n < 11; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_f_s[n * 10 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_d_s[n * 6 + 0]);
                        PRIM_INT__s_s_f_s[n * 10 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__s_s_f_s[n * 10 + 0]);
                        PRIM_INT__s_s_f_s[n * 10 + 0] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__s_s_p_s[n * 3 + 0]), PRIM_INT__s_s_f_s[n * 10 + 0]);

                        PRIM_INT__s_s_f_s[n * 10 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_d_s[n * 6 + 0]);
                        PRIM_INT__s_s_f_s[n * 10 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__s_s_f_s[n * 10 + 1]);

                        PRIM_INT__s_s_f_s[n * 10 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_d_s[n * 6 + 0]);
                        PRIM_INT__s_s_f_s[n * 10 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__s_s_f_s[n * 10 + 2]);

                        PRIM_INT__s_s_f_s[n * 10 + 3] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_d_s[n * 6 + 3]);
                        PRIM_INT__s_s_f_s[n * 10 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__s_s_f_s[n * 10 + 3]);

                        PRIM_INT__s_s_f_s[n * 10 + 4] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_d_s[n * 6 + 1]);
                        PRIM_INT__s_s_f_s[n * 10 + 4] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_d_s[(n+1) * 6 + 1], PRIM_INT__s_s_f_s[n * 10 + 4]);

                        PRIM_INT__s_s_f_s[n * 10 + 5] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_d_s[n * 6 + 5]);
                        PRIM_INT__s_s_f_s[n * 10 + 5] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__s_s_f_s[n * 10 + 5]);

                        PRIM_INT__s_s_f_s[n * 10 + 6] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_d_s[n * 6 + 3]);
                        PRIM_INT__s_s_f_s[n * 10 + 6] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__s_s_f_s[n * 10 + 6]);
                        PRIM_INT__s_s_f_s[n * 10 + 6] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__s_s_p_s[n * 3 + 1]), PRIM_INT__s_s_f_s[n * 10 + 6]);

                        PRIM_INT__s_s_f_s[n * 10 + 7] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_d_s[n * 6 + 3]);
                        PRIM_INT__s_s_f_s[n * 10 + 7] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__s_s_f_s[n * 10 + 7]);

                        PRIM_INT__s_s_f_s[n * 10 + 8] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_d_s[n * 6 + 5]);
                        PRIM_INT__s_s_f_s[n * 10 + 8] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__s_s_f_s[n * 10 + 8]);

                        PRIM_INT__s_s_f_s[n * 10 + 9] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_d_s[n * 6 + 5]);
                        PRIM_INT__s_s_f_s[n * 10 + 9] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__s_s_f_s[n * 10 + 9]);
                        PRIM_INT__s_s_f_s[n * 10 + 9] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__s_s_p_s[n * 3 + 2]), PRIM_INT__s_s_f_s[n * 10 + 9]);

                    }



                    // Forming PRIM_INT__s_s_g_s[10 * 15];
                    for(n = 0; n < 10; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_g_s[n * 15 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_f_s[n * 10 + 0]);
                        PRIM_INT__s_s_g_s[n * 15 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 0], PRIM_INT__s_s_g_s[n * 15 + 0]);
                        PRIM_INT__s_s_g_s[n * 15 + 0] = SIMINT_FMADD( vrr_const_3_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__s_s_d_s[n * 6 + 0]), PRIM_INT__s_s_g_s[n * 15 + 0]);

                        PRIM_INT__s_s_g_s[n * 15 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_f_s[n * 10 + 0]);
                        PRIM_INT__s_s_g_s[n * 15 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 0], PRIM_INT__s_s_g_s[n * 15 + 1]);

                        PRIM_INT__s_s_g_s[n * 15 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_f_s[n * 10 + 0]);
                        PRIM_INT__s_s_g_s[n * 15 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 0], PRIM_INT__s_s_g_s[n * 15 + 2]);

                        PRIM_INT__s_s_g_s[n * 15 + 3] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_f_s[n * 10 + 1]);
                        PRIM_INT__s_s_g_s[n * 15 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 1], PRIM_INT__s_s_g_s[n * 15 + 3]);
                        PRIM_INT__s_s_g_s[n * 15 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__s_s_d_s[n * 6 + 0]), PRIM_INT__s_s_g_s[n * 15 + 3]);

                        PRIM_INT__s_s_g_s[n * 15 + 4] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_f_s[n * 10 + 1]);
                        PRIM_INT__s_s_g_s[n * 15 + 4] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 1], PRIM_INT__s_s_g_s[n * 15 + 4]);

                        PRIM_INT__s_s_g_s[n * 15 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_f_s[n * 10 + 2]);
                        PRIM_INT__s_s_g_s[n * 15 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 2], PRIM_INT__s_s_g_s[n * 15 + 5]);
                        PRIM_INT__s_s_g_s[n * 15 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__s_s_d_s[n * 6 + 0]), PRIM_INT__s_s_g_s[n * 15 + 5]);

                        PRIM_INT__s_s_g_s[n * 15 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_f_s[n * 10 + 6]);
                        PRIM_INT__s_s_g_s[n * 15 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 6], PRIM_INT__s_s_g_s[n * 15 + 6]);

                        PRIM_INT__s_s_g_s[n * 15 + 7] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_f_s[n * 10 + 3]);
                        PRIM_INT__s_s_g_s[n * 15 + 7] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 3], PRIM_INT__s_s_g_s[n * 15 + 7]);

                        PRIM_INT__s_s_g_s[n * 15 + 8] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_f_s[n * 10 + 5]);
                        PRIM_INT__s_s_g_s[n * 15 + 8] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 5], PRIM_INT__s_s_g_s[n * 15 + 8]);

                        PRIM_INT__s_s_g_s[n * 15 + 9] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_f_s[n * 10 + 9]);
                        PRIM_INT__s_s_g_s[n * 15 + 9] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 9], PRIM_INT__s_s_g_s[n * 15 + 9]);

                        PRIM_INT__s_s_g_s[n * 15 + 10] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_f_s[n * 10 + 6]);
                        PRIM_INT__s_s_g_s[n * 15 + 10] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 6], PRIM_INT__s_s_g_s[n * 15 + 10]);
                        PRIM_INT__s_s_g_s[n * 15 + 10] = SIMINT_FMADD( vrr_const_3_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__s_s_d_s[n * 6 + 3]), PRIM_INT__s_s_g_s[n * 15 + 10]);

                        PRIM_INT__s_s_g_s[n * 15 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_f_s[n * 10 + 6]);
                        PRIM_INT__s_s_g_s[n * 15 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 6], PRIM_INT__s_s_g_s[n * 15 + 11]);

                        PRIM_INT__s_s_g_s[n * 15 + 12] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_f_s[n * 10 + 7]);
                        PRIM_INT__s_s_g_s[n * 15 + 12] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 7], PRIM_INT__s_s_g_s[n * 15 + 12]);
                        PRIM_INT__s_s_g_s[n * 15 + 12] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__s_s_d_s[n * 6 + 3]), PRIM_INT__s_s_g_s[n * 15 + 12]);

                        PRIM_INT__s_s_g_s[n * 15 + 13] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_f_s[n * 10 + 9]);
                        PRIM_INT__s_s_g_s[n * 15 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 9], PRIM_INT__s_s_g_s[n * 15 + 13]);

                        PRIM_INT__s_s_g_s[n * 15 + 14] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_f_s[n * 10 + 9]);
                        PRIM_INT__s_s_g_s[n * 15 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 9], PRIM_INT__s_s_g_s[n * 15 + 14]);
                        PRIM_INT__s_s_g_s[n * 15 + 14] = SIMINT_FMADD( vrr_const_3_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__s_s_d_s[n * 6 + 5]), PRIM_INT__s_s_g_s[n * 15 + 14]);

                    }


                    VRR_I_p_s_g_s(
                            PRIM_INT__p_s_g_s,
                            PRIM_INT__s_s_g_s,
                            PRIM_INT__s_s_f_s,
                            P_PA,
                            aop_PQ,
                            one_over_2pq,
                            6);



                    // Forming PRIM_INT__p_s_f_s[6 * 30];
                    for(n = 0; n < 6; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__p_s_f_s[n * 30 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_f_s[n * 10 + 0]);
                        PRIM_INT__p_s_f_s[n * 30 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 0], PRIM_INT__p_s_f_s[n * 30 + 0]);
                        PRIM_INT__p_s_f_s[n * 30 + 0] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__p_s_f_s[n * 30 + 0]);

                        PRIM_INT__p_s_f_s[n * 30 + 1] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_f_s[n * 10 + 1]);
                        PRIM_INT__p_s_f_s[n * 30 + 1] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 1], PRIM_INT__p_s_f_s[n * 30 + 1]);
                        PRIM_INT__p_s_f_s[n * 30 + 1] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 1], PRIM_INT__p_s_f_s[n * 30 + 1]);

                        PRIM_INT__p_s_f_s[n * 30 + 2] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_f_s[n * 10 + 2]);
                        PRIM_INT__p_s_f_s[n * 30 + 2] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 2], PRIM_INT__p_s_f_s[n * 30 + 2]);
                        PRIM_INT__p_s_f_s[n * 30 + 2] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 2], PRIM_INT__p_s_f_s[n * 30 + 2]);

                        PRIM_INT__p_s_f_s[n * 30 + 3] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_f_s[n * 10 + 3]);
                        PRIM_INT__p_s_f_s[n * 30 + 3] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 3], PRIM_INT__p_s_f_s[n * 30 + 3]);
                        PRIM_INT__p_s_f_s[n * 30 + 3] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__p_s_f_s[n * 30 + 3]);

                        PRIM_INT__p_s_f_s[n * 30 + 4] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_f_s[n * 10 + 4]);
                        PRIM_INT__p_s_f_s[n * 30 + 4] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 4], PRIM_INT__p_s_f_s[n * 30 + 4]);
                        PRIM_INT__p_s_f_s[n * 30 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 4], PRIM_INT__p_s_f_s[n * 30 + 4]);

                        PRIM_INT__p_s_f_s[n * 30 + 5] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_f_s[n * 10 + 5]);
                        PRIM_INT__p_s_f_s[n * 30 + 5] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 5], PRIM_INT__p_s_f_s[n * 30 + 5]);
                        PRIM_INT__p_s_f_s[n * 30 + 5] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__p_s_f_s[n * 30 + 5]);

                        PRIM_INT__p_s_f_s[n * 30 + 6] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_f_s[n * 10 + 6]);
                        PRIM_INT__p_s_f_s[n * 30 + 6] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 6], PRIM_INT__p_s_f_s[n * 30 + 6]);

                        PRIM_INT__p_s_f_s[n * 30 + 7] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_f_s[n * 10 + 7]);
                        PRIM_INT__p_s_f_s[n * 30 + 7] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 7], PRIM_INT__p_s_f_s[n * 30 + 7]);

                        PRIM_INT__p_s_f_s[n * 30 + 8] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_f_s[n * 10 + 8]);
                        PRIM_INT__p_s_f_s[n * 30 + 8] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 8], PRIM_INT__p_s_f_s[n * 30 + 8]);

                        PRIM_INT__p_s_f_s[n * 30 + 9] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_f_s[n * 10 + 9]);
                        PRIM_INT__p_s_f_s[n * 30 + 9] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_f_s[(n+1) * 10 + 9], PRIM_INT__p_s_f_s[n * 30 + 9]);

                        PRIM_INT__p_s_f_s[n * 30 + 10] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_f_s[n * 10 + 0]);
                        PRIM_INT__p_s_f_s[n * 30 + 10] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 0], PRIM_INT__p_s_f_s[n * 30 + 10]);

                        PRIM_INT__p_s_f_s[n * 30 + 11] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_f_s[n * 10 + 1]);
                        PRIM_INT__p_s_f_s[n * 30 + 11] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 1], PRIM_INT__p_s_f_s[n * 30 + 11]);
                        PRIM_INT__p_s_f_s[n * 30 + 11] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__p_s_f_s[n * 30 + 11]);

                        PRIM_INT__p_s_f_s[n * 30 + 12] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_f_s[n * 10 + 2]);
                        PRIM_INT__p_s_f_s[n * 30 + 12] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 2], PRIM_INT__p_s_f_s[n * 30 + 12]);

                        PRIM_INT__p_s_f_s[n * 30 + 13] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_f_s[n * 10 + 3]);
                        PRIM_INT__p_s_f_s[n * 30 + 13] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 3], PRIM_INT__p_s_f_s[n * 30 + 13]);
                        PRIM_INT__p_s_f_s[n * 30 + 13] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 1], PRIM_INT__p_s_f_s[n * 30 + 13]);

                        PRIM_INT__p_s_f_s[n * 30 + 14] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_f_s[n * 10 + 4]);
                        PRIM_INT__p_s_f_s[n * 30 + 14] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 4], PRIM_INT__p_s_f_s[n * 30 + 14]);
                        PRIM_INT__p_s_f_s[n * 30 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 2], PRIM_INT__p_s_f_s[n * 30 + 14]);

                        PRIM_INT__p_s_f_s[n * 30 + 15] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_f_s[n * 10 + 5]);
                        PRIM_INT__p_s_f_s[n * 30 + 15] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 5], PRIM_INT__p_s_f_s[n * 30 + 15]);

                        PRIM_INT__p_s_f_s[n * 30 + 16] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_f_s[n * 10 + 6]);
                        PRIM_INT__p_s_f_s[n * 30 + 16] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 6], PRIM_INT__p_s_f_s[n * 30 + 16]);
                        PRIM_INT__p_s_f_s[n * 30 + 16] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__p_s_f_s[n * 30 + 16]);

                        PRIM_INT__p_s_f_s[n * 30 + 17] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_f_s[n * 10 + 7]);
                        PRIM_INT__p_s_f_s[n * 30 + 17] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 7], PRIM_INT__p_s_f_s[n * 30 + 17]);
                        PRIM_INT__p_s_f_s[n * 30 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 4], PRIM_INT__p_s_f_s[n * 30 + 17]);

                        PRIM_INT__p_s_f_s[n * 30 + 18] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_f_s[n * 10 + 8]);
                        PRIM_INT__p_s_f_s[n * 30 + 18] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 8], PRIM_INT__p_s_f_s[n * 30 + 18]);
                        PRIM_INT__p_s_f_s[n * 30 + 18] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__p_s_f_s[n * 30 + 18]);

                        PRIM_INT__p_s_f_s[n * 30 + 19] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_f_s[n * 10 + 9]);
                        PRIM_INT__p_s_f_s[n * 30 + 19] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_f_s[(n+1) * 10 + 9], PRIM_INT__p_s_f_s[n * 30 + 19]);

                        PRIM_INT__p_s_f_s[n * 30 + 20] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_f_s[n * 10 + 0]);
                        PRIM_INT__p_s_f_s[n * 30 + 20] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 0], PRIM_INT__p_s_f_s[n * 30 + 20]);

                        PRIM_INT__p_s_f_s[n * 30 + 21] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_f_s[n * 10 + 1]);
                        PRIM_INT__p_s_f_s[n * 30 + 21] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 1], PRIM_INT__p_s_f_s[n * 30 + 21]);

                        PRIM_INT__p_s_f_s[n * 30 + 22] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_f_s[n * 10 + 2]);
                        PRIM_INT__p_s_f_s[n * 30 + 22] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 2], PRIM_INT__p_s_f_s[n * 30 + 22]);
                        PRIM_INT__p_s_f_s[n * 30 + 22] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__p_s_f_s[n * 30 + 22]);

                        PRIM_INT__p_s_f_s[n * 30 + 23] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_f_s[n * 10 + 3]);
                        PRIM_INT__p_s_f_s[n * 30 + 23] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 3], PRIM_INT__p_s_f_s[n * 30 + 23]);

                        PRIM_INT__p_s_f_s[n * 30 + 24] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_f_s[n * 10 + 4]);
                        PRIM_INT__p_s_f_s[n * 30 + 24] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 4], PRIM_INT__p_s_f_s[n * 30 + 24]);
                        PRIM_INT__p_s_f_s[n * 30 + 24] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 1], PRIM_INT__p_s_f_s[n * 30 + 24]);

                        PRIM_INT__p_s_f_s[n * 30 + 25] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_f_s[n * 10 + 5]);
                        PRIM_INT__p_s_f_s[n * 30 + 25] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 5], PRIM_INT__p_s_f_s[n * 30 + 25]);
                        PRIM_INT__p_s_f_s[n * 30 + 25] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 2], PRIM_INT__p_s_f_s[n * 30 + 25]);

                        PRIM_INT__p_s_f_s[n * 30 + 26] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_f_s[n * 10 + 6]);
                        PRIM_INT__p_s_f_s[n * 30 + 26] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 6], PRIM_INT__p_s_f_s[n * 30 + 26]);

                        PRIM_INT__p_s_f_s[n * 30 + 27] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_f_s[n * 10 + 7]);
                        PRIM_INT__p_s_f_s[n * 30 + 27] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 7], PRIM_INT__p_s_f_s[n * 30 + 27]);
                        PRIM_INT__p_s_f_s[n * 30 + 27] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__p_s_f_s[n * 30 + 27]);

                        PRIM_INT__p_s_f_s[n * 30 + 28] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_f_s[n * 10 + 8]);
                        PRIM_INT__p_s_f_s[n * 30 + 28] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 8], PRIM_INT__p_s_f_s[n * 30 + 28]);
                        PRIM_INT__p_s_f_s[n * 30 + 28] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 4], PRIM_INT__p_s_f_s[n * 30 + 28]);

                        PRIM_INT__p_s_f_s[n * 30 + 29] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_f_s[n * 10 + 9]);
                        PRIM_INT__p_s_f_s[n * 30 + 29] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_f_s[(n+1) * 10 + 9], PRIM_INT__p_s_f_s[n * 30 + 29]);
                        PRIM_INT__p_s_f_s[n * 30 + 29] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__p_s_f_s[n * 30 + 29]);

                    }


                    VRR_I_d_s_g_s(
                            PRIM_INT__d_s_g_s,
                            PRIM_INT__p_s_g_s,
                            PRIM_INT__s_s_g_s,
                            PRIM_INT__p_s_f_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            one_over_2pq,
                            5);



                    // Forming PRIM_INT__p_s_d_s[6 * 18];
                    for(n = 0; n < 6; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__p_s_d_s[n * 18 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_d_s[n * 6 + 0]);
                        PRIM_INT__p_s_d_s[n * 18 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__p_s_d_s[n * 18 + 0]);
                        PRIM_INT__p_s_d_s[n * 18 + 0] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__p_s_d_s[n * 18 + 0]);

                        PRIM_INT__p_s_d_s[n * 18 + 1] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_d_s[n * 6 + 1]);
                        PRIM_INT__p_s_d_s[n * 18 + 1] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_d_s[(n+1) * 6 + 1], PRIM_INT__p_s_d_s[n * 18 + 1]);
                        PRIM_INT__p_s_d_s[n * 18 + 1] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__p_s_d_s[n * 18 + 1]);

                        PRIM_INT__p_s_d_s[n * 18 + 2] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_d_s[n * 6 + 2]);
                        PRIM_INT__p_s_d_s[n * 18 + 2] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_d_s[(n+1) * 6 + 2], PRIM_INT__p_s_d_s[n * 18 + 2]);
                        PRIM_INT__p_s_d_s[n * 18 + 2] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__p_s_d_s[n * 18 + 2]);

                        PRIM_INT__p_s_d_s[n * 18 + 3] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_d_s[n * 6 + 3]);
                        PRIM_INT__p_s_d_s[n * 18 + 3] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__p_s_d_s[n * 18 + 3]);

                        PRIM_INT__p_s_d_s[n * 18 + 4] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_d_s[n * 6 + 4]);
                        PRIM_INT__p_s_d_s[n * 18 + 4] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_d_s[(n+1) * 6 + 4], PRIM_INT__p_s_d_s[n * 18 + 4]);

                        PRIM_INT__p_s_d_s[n * 18 + 5] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_d_s[n * 6 + 5]);
                        PRIM_INT__p_s_d_s[n * 18 + 5] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__p_s_d_s[n * 18 + 5]);

                        PRIM_INT__p_s_d_s[n * 18 + 6] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_d_s[n * 6 + 0]);
                        PRIM_INT__p_s_d_s[n * 18 + 6] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__p_s_d_s[n * 18 + 6]);

                        PRIM_INT__p_s_d_s[n * 18 + 7] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_d_s[n * 6 + 1]);
                        PRIM_INT__p_s_d_s[n * 18 + 7] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_d_s[(n+1) * 6 + 1], PRIM_INT__p_s_d_s[n * 18 + 7]);
                        PRIM_INT__p_s_d_s[n * 18 + 7] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__p_s_d_s[n * 18 + 7]);

                        PRIM_INT__p_s_d_s[n * 18 + 8] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_d_s[n * 6 + 2]);
                        PRIM_INT__p_s_d_s[n * 18 + 8] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_d_s[(n+1) * 6 + 2], PRIM_INT__p_s_d_s[n * 18 + 8]);

                        PRIM_INT__p_s_d_s[n * 18 + 9] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_d_s[n * 6 + 3]);
                        PRIM_INT__p_s_d_s[n * 18 + 9] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__p_s_d_s[n * 18 + 9]);
                        PRIM_INT__p_s_d_s[n * 18 + 9] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__p_s_d_s[n * 18 + 9]);

                        PRIM_INT__p_s_d_s[n * 18 + 10] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_d_s[n * 6 + 4]);
                        PRIM_INT__p_s_d_s[n * 18 + 10] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_d_s[(n+1) * 6 + 4], PRIM_INT__p_s_d_s[n * 18 + 10]);
                        PRIM_INT__p_s_d_s[n * 18 + 10] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__p_s_d_s[n * 18 + 10]);

                        PRIM_INT__p_s_d_s[n * 18 + 11] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_d_s[n * 6 + 5]);
                        PRIM_INT__p_s_d_s[n * 18 + 11] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__p_s_d_s[n * 18 + 11]);

                        PRIM_INT__p_s_d_s[n * 18 + 12] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_d_s[n * 6 + 0]);
                        PRIM_INT__p_s_d_s[n * 18 + 12] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__p_s_d_s[n * 18 + 12]);

                        PRIM_INT__p_s_d_s[n * 18 + 13] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_d_s[n * 6 + 1]);
                        PRIM_INT__p_s_d_s[n * 18 + 13] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_d_s[(n+1) * 6 + 1], PRIM_INT__p_s_d_s[n * 18 + 13]);

                        PRIM_INT__p_s_d_s[n * 18 + 14] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_d_s[n * 6 + 2]);
                        PRIM_INT__p_s_d_s[n * 18 + 14] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_d_s[(n+1) * 6 + 2], PRIM_INT__p_s_d_s[n * 18 + 14]);
                        PRIM_INT__p_s_d_s[n * 18 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__p_s_d_s[n * 18 + 14]);

                        PRIM_INT__p_s_d_s[n * 18 + 15] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_d_s[n * 6 + 3]);
                        PRIM_INT__p_s_d_s[n * 18 + 15] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__p_s_d_s[n * 18 + 15]);

                        PRIM_INT__p_s_d_s[n * 18 + 16] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_d_s[n * 6 + 4]);
                        PRIM_INT__p_s_d_s[n * 18 + 16] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_d_s[(n+1) * 6 + 4], PRIM_INT__p_s_d_s[n * 18 + 16]);
                        PRIM_INT__p_s_d_s[n * 18 + 16] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__p_s_d_s[n * 18 + 16]);

                        PRIM_INT__p_s_d_s[n * 18 + 17] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_d_s[n * 6 + 5]);
                        PRIM_INT__p_s_d_s[n * 18 + 17] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__p_s_d_s[n * 18 + 17]);
                        PRIM_INT__p_s_d_s[n * 18 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__p_s_d_s[n * 18 + 17]);

                    }


                    VRR_I_d_s_f_s(
                            PRIM_INT__d_s_f_s,
                            PRIM_INT__p_s_f_s,
                            PRIM_INT__s_s_f_s,
                            PRIM_INT__p_s_d_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            one_over_2pq,
                            5);


                    VRR_I_f_s_g_s(
                            PRIM_INT__f_s_g_s,
                            PRIM_INT__d_s_g_s,
                            PRIM_INT__p_s_g_s,
                            PRIM_INT__d_s_f_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            one_over_2pq,
                            4);


                    VRR_K_s_s_h_s(
                            PRIM_INT__s_s_h_s,
                            PRIM_INT__s_s_g_s,
                            PRIM_INT__s_s_f_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2q,
                            9);


                    VRR_I_p_s_h_s(
                            PRIM_INT__p_s_h_s,
                            PRIM_INT__s_s_h_s,
                            PRIM_INT__s_s_g_s,
                            P_PA,
                            aop_PQ,
                            one_over_2pq,
                            6);


                    VRR_I_d_s_h_s(
                            PRIM_INT__d_s_h_s,
                            PRIM_INT__p_s_h_s,
                            PRIM_INT__s_s_h_s,
                            PRIM_INT__p_s_g_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            one_over_2pq,
                            5);


                    ostei_general_vrr_I(3, 0, 5, 0, 4,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__d_s_h_s, PRIM_INT__p_s_h_s, NULL, PRIM_INT__d_s_g_s, NULL, PRIM_INT__f_s_h_s);



                    // Forming PRIM_INT__p_s_p_s[6 * 9];
                    for(n = 0; n < 6; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__p_s_p_s[n * 9 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_p_s[n * 3 + 0]);
                        PRIM_INT__p_s_p_s[n * 9 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__p_s_p_s[n * 9 + 0]);
                        PRIM_INT__p_s_p_s[n * 9 + 0] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_p_s[n * 9 + 0]);

                        PRIM_INT__p_s_p_s[n * 9 + 1] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_p_s[n * 3 + 1]);
                        PRIM_INT__p_s_p_s[n * 9 + 1] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__p_s_p_s[n * 9 + 1]);

                        PRIM_INT__p_s_p_s[n * 9 + 2] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_p_s[n * 3 + 2]);
                        PRIM_INT__p_s_p_s[n * 9 + 2] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__p_s_p_s[n * 9 + 2]);

                        PRIM_INT__p_s_p_s[n * 9 + 3] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_p_s[n * 3 + 0]);
                        PRIM_INT__p_s_p_s[n * 9 + 3] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__p_s_p_s[n * 9 + 3]);

                        PRIM_INT__p_s_p_s[n * 9 + 4] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_p_s[n * 3 + 1]);
                        PRIM_INT__p_s_p_s[n * 9 + 4] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__p_s_p_s[n * 9 + 4]);
                        PRIM_INT__p_s_p_s[n * 9 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_p_s[n * 9 + 4]);

                        PRIM_INT__p_s_p_s[n * 9 + 5] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_p_s[n * 3 + 2]);
                        PRIM_INT__p_s_p_s[n * 9 + 5] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__p_s_p_s[n * 9 + 5]);

                        PRIM_INT__p_s_p_s[n * 9 + 6] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_p_s[n * 3 + 0]);
                        PRIM_INT__p_s_p_s[n * 9 + 6] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__p_s_p_s[n * 9 + 6]);

                        PRIM_INT__p_s_p_s[n * 9 + 7] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_p_s[n * 3 + 1]);
                        PRIM_INT__p_s_p_s[n * 9 + 7] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__p_s_p_s[n * 9 + 7]);

                        PRIM_INT__p_s_p_s[n * 9 + 8] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_p_s[n * 3 + 2]);
                        PRIM_INT__p_s_p_s[n * 9 + 8] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__p_s_p_s[n * 9 + 8]);
                        PRIM_INT__p_s_p_s[n * 9 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_p_s[n * 9 + 8]);

                    }



                    // Forming PRIM_INT__d_s_d_s[5 * 36];
                    for(n = 0; n < 5; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__d_s_d_s[n * 36 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__p_s_d_s[n * 18 + 0]);
                        PRIM_INT__d_s_d_s[n * 36 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__p_s_d_s[(n+1) * 18 + 0], PRIM_INT__d_s_d_s[n * 36 + 0]);
                        PRIM_INT__d_s_d_s[n * 36 + 0] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__s_s_d_s[n * 6 + 0]), PRIM_INT__d_s_d_s[n * 36 + 0]);
                        PRIM_INT__d_s_d_s[n * 36 + 0] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 0], PRIM_INT__d_s_d_s[n * 36 + 0]);

                        PRIM_INT__d_s_d_s[n * 36 + 1] = SIMINT_MUL(P_PA[0], PRIM_INT__p_s_d_s[n * 18 + 1]);
                        PRIM_INT__d_s_d_s[n * 36 + 1] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__p_s_d_s[(n+1) * 18 + 1], PRIM_INT__d_s_d_s[n * 36 + 1]);
                        PRIM_INT__d_s_d_s[n * 36 + 1] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 1], PRIM_INT__s_s_d_s[n * 6 + 1]), PRIM_INT__d_s_d_s[n * 36 + 1]);
                        PRIM_INT__d_s_d_s[n * 36 + 1] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 1], PRIM_INT__d_s_d_s[n * 36 + 1]);

                        PRIM_INT__d_s_d_s[n * 36 + 2] = SIMINT_MUL(P_PA[0], PRIM_INT__p_s_d_s[n * 18 + 2]);
                        PRIM_INT__d_s_d_s[n * 36 + 2] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__p_s_d_s[(n+1) * 18 + 2], PRIM_INT__d_s_d_s[n * 36 + 2]);
                        PRIM_INT__d_s_d_s[n * 36 + 2] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 2], PRIM_INT__s_s_d_s[n * 6 + 2]), PRIM_INT__d_s_d_s[n * 36 + 2]);
                        PRIM_INT__d_s_d_s[n * 36 + 2] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 2], PRIM_INT__d_s_d_s[n * 36 + 2]);

                        PRIM_INT__d_s_d_s[n * 36 + 3] = SIMINT_MUL(P_PA[0], PRIM_INT__p_s_d_s[n * 18 + 3]);
                        PRIM_INT__d_s_d_s[n * 36 + 3] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__p_s_d_s[(n+1) * 18 + 3], PRIM_INT__d_s_d_s[n * 36 + 3]);
                        PRIM_INT__d_s_d_s[n * 36 + 3] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__s_s_d_s[n * 6 + 3]), PRIM_INT__d_s_d_s[n * 36 + 3]);

                        PRIM_INT__d_s_d_s[n * 36 + 4] = SIMINT_MUL(P_PA[0], PRIM_INT__p_s_d_s[n * 18 + 4]);
                        PRIM_INT__d_s_d_s[n * 36 + 4] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__p_s_d_s[(n+1) * 18 + 4], PRIM_INT__d_s_d_s[n * 36 + 4]);
                        PRIM_INT__d_s_d_s[n * 36 + 4] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 4], PRIM_INT__s_s_d_s[n * 6 + 4]), PRIM_INT__d_s_d_s[n * 36 + 4]);

                        PRIM_INT__d_s_d_s[n * 36 + 5] = SIMINT_MUL(P_PA[0], PRIM_INT__p_s_d_s[n * 18 + 5]);
                        PRIM_INT__d_s_d_s[n * 36 + 5] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__p_s_d_s[(n+1) * 18 + 5], PRIM_INT__d_s_d_s[n * 36 + 5]);
                        PRIM_INT__d_s_d_s[n * 36 + 5] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__s_s_d_s[n * 6 + 5]), PRIM_INT__d_s_d_s[n * 36 + 5]);

                        PRIM_INT__d_s_d_s[n * 36 + 18] = SIMINT_MUL(P_PA[1], PRIM_INT__p_s_d_s[n * 18 + 6]);
                        PRIM_INT__d_s_d_s[n * 36 + 18] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__p_s_d_s[(n+1) * 18 + 6], PRIM_INT__d_s_d_s[n * 36 + 18]);
                        PRIM_INT__d_s_d_s[n * 36 + 18] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__s_s_d_s[n * 6 + 0]), PRIM_INT__d_s_d_s[n * 36 + 18]);

                        PRIM_INT__d_s_d_s[n * 36 + 19] = SIMINT_MUL(P_PA[1], PRIM_INT__p_s_d_s[n * 18 + 7]);
                        PRIM_INT__d_s_d_s[n * 36 + 19] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__p_s_d_s[(n+1) * 18 + 7], PRIM_INT__d_s_d_s[n * 36 + 19]);
                        PRIM_INT__d_s_d_s[n * 36 + 19] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 1], PRIM_INT__s_s_d_s[n * 6 + 1]), PRIM_INT__d_s_d_s[n * 36 + 19]);
                        PRIM_INT__d_s_d_s[n * 36 + 19] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 3], PRIM_INT__d_s_d_s[n * 36 + 19]);

                        PRIM_INT__d_s_d_s[n * 36 + 20] = SIMINT_MUL(P_PA[1], PRIM_INT__p_s_d_s[n * 18 + 8]);
                        PRIM_INT__d_s_d_s[n * 36 + 20] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__p_s_d_s[(n+1) * 18 + 8], PRIM_INT__d_s_d_s[n * 36 + 20]);
                        PRIM_INT__d_s_d_s[n * 36 + 20] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 2], PRIM_INT__s_s_d_s[n * 6 + 2]), PRIM_INT__d_s_d_s[n * 36 + 20]);

                        PRIM_INT__d_s_d_s[n * 36 + 21] = SIMINT_MUL(P_PA[1], PRIM_INT__p_s_d_s[n * 18 + 9]);
                        PRIM_INT__d_s_d_s[n * 36 + 21] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__p_s_d_s[(n+1) * 18 + 9], PRIM_INT__d_s_d_s[n * 36 + 21]);
                        PRIM_INT__d_s_d_s[n * 36 + 21] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__s_s_d_s[n * 6 + 3]), PRIM_INT__d_s_d_s[n * 36 + 21]);
                        PRIM_INT__d_s_d_s[n * 36 + 21] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 4], PRIM_INT__d_s_d_s[n * 36 + 21]);

                        PRIM_INT__d_s_d_s[n * 36 + 22] = SIMINT_MUL(P_PA[1], PRIM_INT__p_s_d_s[n * 18 + 10]);
                        PRIM_INT__d_s_d_s[n * 36 + 22] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__p_s_d_s[(n+1) * 18 + 10], PRIM_INT__d_s_d_s[n * 36 + 22]);
                        PRIM_INT__d_s_d_s[n * 36 + 22] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 4], PRIM_INT__s_s_d_s[n * 6 + 4]), PRIM_INT__d_s_d_s[n * 36 + 22]);
                        PRIM_INT__d_s_d_s[n * 36 + 22] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 5], PRIM_INT__d_s_d_s[n * 36 + 22]);

                        PRIM_INT__d_s_d_s[n * 36 + 23] = SIMINT_MUL(P_PA[1], PRIM_INT__p_s_d_s[n * 18 + 11]);
                        PRIM_INT__d_s_d_s[n * 36 + 23] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__p_s_d_s[(n+1) * 18 + 11], PRIM_INT__d_s_d_s[n * 36 + 23]);
                        PRIM_INT__d_s_d_s[n * 36 + 23] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__s_s_d_s[n * 6 + 5]), PRIM_INT__d_s_d_s[n * 36 + 23]);

                        PRIM_INT__d_s_d_s[n * 36 + 30] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_d_s[n * 18 + 12]);
                        PRIM_INT__d_s_d_s[n * 36 + 30] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_d_s[(n+1) * 18 + 12], PRIM_INT__d_s_d_s[n * 36 + 30]);
                        PRIM_INT__d_s_d_s[n * 36 + 30] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__s_s_d_s[n * 6 + 0]), PRIM_INT__d_s_d_s[n * 36 + 30]);

                        PRIM_INT__d_s_d_s[n * 36 + 31] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_d_s[n * 18 + 13]);
                        PRIM_INT__d_s_d_s[n * 36 + 31] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_d_s[(n+1) * 18 + 13], PRIM_INT__d_s_d_s[n * 36 + 31]);
                        PRIM_INT__d_s_d_s[n * 36 + 31] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 1], PRIM_INT__s_s_d_s[n * 6 + 1]), PRIM_INT__d_s_d_s[n * 36 + 31]);

                        PRIM_INT__d_s_d_s[n * 36 + 32] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_d_s[n * 18 + 14]);
                        PRIM_INT__d_s_d_s[n * 36 + 32] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_d_s[(n+1) * 18 + 14], PRIM_INT__d_s_d_s[n * 36 + 32]);
                        PRIM_INT__d_s_d_s[n * 36 + 32] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 2], PRIM_INT__s_s_d_s[n * 6 + 2]), PRIM_INT__d_s_d_s[n * 36 + 32]);
                        PRIM_INT__d_s_d_s[n * 36 + 32] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 6], PRIM_INT__d_s_d_s[n * 36 + 32]);

                        PRIM_INT__d_s_d_s[n * 36 + 33] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_d_s[n * 18 + 15]);
                        PRIM_INT__d_s_d_s[n * 36 + 33] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_d_s[(n+1) * 18 + 15], PRIM_INT__d_s_d_s[n * 36 + 33]);
                        PRIM_INT__d_s_d_s[n * 36 + 33] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__s_s_d_s[n * 6 + 3]), PRIM_INT__d_s_d_s[n * 36 + 33]);

                        PRIM_INT__d_s_d_s[n * 36 + 34] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_d_s[n * 18 + 16]);
                        PRIM_INT__d_s_d_s[n * 36 + 34] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_d_s[(n+1) * 18 + 16], PRIM_INT__d_s_d_s[n * 36 + 34]);
                        PRIM_INT__d_s_d_s[n * 36 + 34] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 4], PRIM_INT__s_s_d_s[n * 6 + 4]), PRIM_INT__d_s_d_s[n * 36 + 34]);
                        PRIM_INT__d_s_d_s[n * 36 + 34] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 7], PRIM_INT__d_s_d_s[n * 36 + 34]);

                        PRIM_INT__d_s_d_s[n * 36 + 35] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_d_s[n * 18 + 17]);
                        PRIM_INT__d_s_d_s[n * 36 + 35] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_d_s[(n+1) * 18 + 17], PRIM_INT__d_s_d_s[n * 36 + 35]);
                        PRIM_INT__d_s_d_s[n * 36 + 35] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__s_s_d_s[n * 6 + 5]), PRIM_INT__d_s_d_s[n * 36 + 35]);
                        PRIM_INT__d_s_d_s[n * 36 + 35] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 8], PRIM_INT__d_s_d_s[n * 36 + 35]);

                    }


                    VRR_I_f_s_f_s(
                            PRIM_INT__f_s_f_s,
                            PRIM_INT__d_s_f_s,
                            PRIM_INT__p_s_f_s,
                            PRIM_INT__d_s_d_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            one_over_2pq,
                            4);


                    ostei_general_vrr_I(4, 0, 4, 0, 3,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__f_s_g_s, PRIM_INT__d_s_g_s, NULL, PRIM_INT__f_s_f_s, NULL, PRIM_INT__g_s_g_s);


                    VRR_K_s_s_i_s(
                            PRIM_INT__s_s_i_s,
                            PRIM_INT__s_s_h_s,
                            PRIM_INT__s_s_g_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2q,
                            8);


                    VRR_I_p_s_i_s(
                            PRIM_INT__p_s_i_s,
                            PRIM_INT__s_s_i_s,
                            PRIM_INT__s_s_h_s,
                            P_PA,
                            aop_PQ,
                            one_over_2pq,
                            6);


                    ostei_general_vrr_I(2, 0, 6, 0, 5,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__p_s_i_s, PRIM_INT__s_s_i_s, NULL, PRIM_INT__p_s_h_s, NULL, PRIM_INT__d_s_i_s);


                    ostei_general_vrr_I(3, 0, 6, 0, 4,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__d_s_i_s, PRIM_INT__p_s_i_s, NULL, PRIM_INT__d_s_h_s, NULL, PRIM_INT__f_s_i_s);


                    ostei_general_vrr_I(4, 0, 5, 0, 3,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__f_s_h_s, PRIM_INT__d_s_h_s, NULL, PRIM_INT__f_s_g_s, NULL, PRIM_INT__g_s_h_s);



                    // Forming PRIM_INT__p_s_s_s[6 * 3];
                    for(n = 0; n < 6; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__p_s_s_s[n * 3 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__p_s_s_s[n * 3 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_s_s[n * 3 + 0]);

                        PRIM_INT__p_s_s_s[n * 3 + 1] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__p_s_s_s[n * 3 + 1] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_s_s[n * 3 + 1]);

                        PRIM_INT__p_s_s_s[n * 3 + 2] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__p_s_s_s[n * 3 + 2] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_s_s[n * 3 + 2]);

                    }



                    // Forming PRIM_INT__d_s_p_s[5 * 18];
                    for(n = 0; n < 5; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__d_s_p_s[n * 18 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__p_s_p_s[n * 9 + 0]);
                        PRIM_INT__d_s_p_s[n * 18 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__p_s_p_s[(n+1) * 9 + 0], PRIM_INT__d_s_p_s[n * 18 + 0]);
                        PRIM_INT__d_s_p_s[n * 18 + 0] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__s_s_p_s[n * 3 + 0]), PRIM_INT__d_s_p_s[n * 18 + 0]);
                        PRIM_INT__d_s_p_s[n * 18 + 0] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__d_s_p_s[n * 18 + 0]);

                        PRIM_INT__d_s_p_s[n * 18 + 1] = SIMINT_MUL(P_PA[0], PRIM_INT__p_s_p_s[n * 9 + 1]);
                        PRIM_INT__d_s_p_s[n * 18 + 1] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__p_s_p_s[(n+1) * 9 + 1], PRIM_INT__d_s_p_s[n * 18 + 1]);
                        PRIM_INT__d_s_p_s[n * 18 + 1] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__s_s_p_s[n * 3 + 1]), PRIM_INT__d_s_p_s[n * 18 + 1]);

                        PRIM_INT__d_s_p_s[n * 18 + 2] = SIMINT_MUL(P_PA[0], PRIM_INT__p_s_p_s[n * 9 + 2]);
                        PRIM_INT__d_s_p_s[n * 18 + 2] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__p_s_p_s[(n+1) * 9 + 2], PRIM_INT__d_s_p_s[n * 18 + 2]);
                        PRIM_INT__d_s_p_s[n * 18 + 2] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__s_s_p_s[n * 3 + 2]), PRIM_INT__d_s_p_s[n * 18 + 2]);

                        PRIM_INT__d_s_p_s[n * 18 + 9] = SIMINT_MUL(P_PA[1], PRIM_INT__p_s_p_s[n * 9 + 3]);
                        PRIM_INT__d_s_p_s[n * 18 + 9] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__p_s_p_s[(n+1) * 9 + 3], PRIM_INT__d_s_p_s[n * 18 + 9]);
                        PRIM_INT__d_s_p_s[n * 18 + 9] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__s_s_p_s[n * 3 + 0]), PRIM_INT__d_s_p_s[n * 18 + 9]);

                        PRIM_INT__d_s_p_s[n * 18 + 10] = SIMINT_MUL(P_PA[1], PRIM_INT__p_s_p_s[n * 9 + 4]);
                        PRIM_INT__d_s_p_s[n * 18 + 10] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__p_s_p_s[(n+1) * 9 + 4], PRIM_INT__d_s_p_s[n * 18 + 10]);
                        PRIM_INT__d_s_p_s[n * 18 + 10] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__s_s_p_s[n * 3 + 1]), PRIM_INT__d_s_p_s[n * 18 + 10]);
                        PRIM_INT__d_s_p_s[n * 18 + 10] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__d_s_p_s[n * 18 + 10]);

                        PRIM_INT__d_s_p_s[n * 18 + 11] = SIMINT_MUL(P_PA[1], PRIM_INT__p_s_p_s[n * 9 + 5]);
                        PRIM_INT__d_s_p_s[n * 18 + 11] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__p_s_p_s[(n+1) * 9 + 5], PRIM_INT__d_s_p_s[n * 18 + 11]);
                        PRIM_INT__d_s_p_s[n * 18 + 11] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__s_s_p_s[n * 3 + 2]), PRIM_INT__d_s_p_s[n * 18 + 11]);

                        PRIM_INT__d_s_p_s[n * 18 + 15] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_p_s[n * 9 + 6]);
                        PRIM_INT__d_s_p_s[n * 18 + 15] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_p_s[(n+1) * 9 + 6], PRIM_INT__d_s_p_s[n * 18 + 15]);
                        PRIM_INT__d_s_p_s[n * 18 + 15] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__s_s_p_s[n * 3 + 0]), PRIM_INT__d_s_p_s[n * 18 + 15]);

                        PRIM_INT__d_s_p_s[n * 18 + 16] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_p_s[n * 9 + 7]);
                        PRIM_INT__d_s_p_s[n * 18 + 16] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_p_s[(n+1) * 9 + 7], PRIM_INT__d_s_p_s[n * 18 + 16]);
                        PRIM_INT__d_s_p_s[n * 18 + 16] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__s_s_p_s[n * 3 + 1]), PRIM_INT__d_s_p_s[n * 18 + 16]);

                        PRIM_INT__d_s_p_s[n * 18 + 17] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_p_s[n * 9 + 8]);
                        PRIM_INT__d_s_p_s[n * 18 + 17] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_p_s[(n+1) * 9 + 8], PRIM_INT__d_s_p_s[n * 18 + 17]);
                        PRIM_INT__d_s_p_s[n * 18 + 17] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__s_s_p_s[n * 3 + 2]), PRIM_INT__d_s_p_s[n * 18 + 17]);
                        PRIM_INT__d_s_p_s[n * 18 + 17] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__d_s_p_s[n * 18 + 17]);

                    }


                    VRR_I_f_s_d_s(
                            PRIM_INT__f_s_d_s,
                            PRIM_INT__d_s_d_s,
                            PRIM_INT__p_s_d_s,
                            PRIM_INT__d_s_p_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            one_over_2pq,
                            4);


                    VRR_I_g_s_f_s(
                            PRIM_INT__g_s_f_s,
                            PRIM_INT__f_s_f_s,
                            PRIM_INT__d_s_f_s,
                            PRIM_INT__f_s_d_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            one_over_2pq,
                            3);


                    ostei_general_vrr_I(5, 0, 4, 0, 2,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__g_s_g_s, PRIM_INT__f_s_g_s, NULL, PRIM_INT__g_s_f_s, NULL, PRIM_INT__h_s_g_s);


                    VRR_K_s_s_k_s(
                            PRIM_INT__s_s_k_s,
                            PRIM_INT__s_s_i_s,
                            PRIM_INT__s_s_h_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2q,
                            7);


                    ostei_general_vrr_I(1, 0, 7, 0, 6,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__s_s_k_s, NULL, NULL, PRIM_INT__s_s_i_s, NULL, PRIM_INT__p_s_k_s);


                    ostei_general_vrr_I(2, 0, 7, 0, 5,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__p_s_k_s, PRIM_INT__s_s_k_s, NULL, PRIM_INT__p_s_i_s, NULL, PRIM_INT__d_s_k_s);


                    ostei_general_vrr_I(3, 0, 7, 0, 4,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__d_s_k_s, PRIM_INT__p_s_k_s, NULL, PRIM_INT__d_s_i_s, NULL, PRIM_INT__f_s_k_s);


                    ostei_general_vrr_I(4, 0, 6, 0, 3,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__f_s_i_s, PRIM_INT__d_s_i_s, NULL, PRIM_INT__f_s_h_s, NULL, PRIM_INT__g_s_i_s);


                    ostei_general_vrr_I(5, 0, 5, 0, 2,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__g_s_h_s, PRIM_INT__f_s_h_s, NULL, PRIM_INT__g_s_g_s, NULL, PRIM_INT__h_s_h_s);



                    // Forming PRIM_INT__d_s_s_s[5 * 6];
                    for(n = 0; n < 5; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__d_s_s_s[n * 6 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__p_s_s_s[n * 3 + 0]);
                        PRIM_INT__d_s_s_s[n * 6 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__d_s_s_s[n * 6 + 0]);
                        PRIM_INT__d_s_s_s[n * 6 + 0] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__d_s_s_s[n * 6 + 0]);

                        PRIM_INT__d_s_s_s[n * 6 + 3] = SIMINT_MUL(P_PA[1], PRIM_INT__p_s_s_s[n * 3 + 1]);
                        PRIM_INT__d_s_s_s[n * 6 + 3] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__d_s_s_s[n * 6 + 3]);
                        PRIM_INT__d_s_s_s[n * 6 + 3] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__d_s_s_s[n * 6 + 3]);

                        PRIM_INT__d_s_s_s[n * 6 + 5] = SIMINT_MUL(P_PA[2], PRIM_INT__p_s_s_s[n * 3 + 2]);
                        PRIM_INT__d_s_s_s[n * 6 + 5] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__d_s_s_s[n * 6 + 5]);
                        PRIM_INT__d_s_s_s[n * 6 + 5] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__d_s_s_s[n * 6 + 5]);

                    }



                    // Forming PRIM_INT__f_s_p_s[4 * 30];
                    for(n = 0; n < 4; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__f_s_p_s[n * 30 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__d_s_p_s[n * 18 + 0]);
                        PRIM_INT__f_s_p_s[n * 30 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__d_s_p_s[(n+1) * 18 + 0], PRIM_INT__f_s_p_s[n * 30 + 0]);
                        PRIM_INT__f_s_p_s[n * 30 + 0] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__p_s_p_s[(n+1) * 9 + 0], PRIM_INT__p_s_p_s[n * 9 + 0]), PRIM_INT__f_s_p_s[n * 30 + 0]);
                        PRIM_INT__f_s_p_s[n * 30 + 0] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__f_s_p_s[n * 30 + 0]);

                        PRIM_INT__f_s_p_s[n * 30 + 1] = SIMINT_MUL(P_PA[0], PRIM_INT__d_s_p_s[n * 18 + 1]);
                        PRIM_INT__f_s_p_s[n * 30 + 1] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__d_s_p_s[(n+1) * 18 + 1], PRIM_INT__f_s_p_s[n * 30 + 1]);
                        PRIM_INT__f_s_p_s[n * 30 + 1] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__p_s_p_s[(n+1) * 9 + 1], PRIM_INT__p_s_p_s[n * 9 + 1]), PRIM_INT__f_s_p_s[n * 30 + 1]);

                        PRIM_INT__f_s_p_s[n * 30 + 2] = SIMINT_MUL(P_PA[0], PRIM_INT__d_s_p_s[n * 18 + 2]);
                        PRIM_INT__f_s_p_s[n * 30 + 2] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__d_s_p_s[(n+1) * 18 + 2], PRIM_INT__f_s_p_s[n * 30 + 2]);
                        PRIM_INT__f_s_p_s[n * 30 + 2] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__p_s_p_s[(n+1) * 9 + 2], PRIM_INT__p_s_p_s[n * 9 + 2]), PRIM_INT__f_s_p_s[n * 30 + 2]);

                        PRIM_INT__f_s_p_s[n * 30 + 3] = SIMINT_MUL(P_PA[1], PRIM_INT__d_s_p_s[n * 18 + 0]);
                        PRIM_INT__f_s_p_s[n * 30 + 3] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__d_s_p_s[(n+1) * 18 + 0], PRIM_INT__f_s_p_s[n * 30 + 3]);

                        PRIM_INT__f_s_p_s[n * 30 + 4] = SIMINT_MUL(P_PA[1], PRIM_INT__d_s_p_s[n * 18 + 1]);
                        PRIM_INT__f_s_p_s[n * 30 + 4] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__d_s_p_s[(n+1) * 18 + 1], PRIM_INT__f_s_p_s[n * 30 + 4]);
                        PRIM_INT__f_s_p_s[n * 30 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__f_s_p_s[n * 30 + 4]);

                        PRIM_INT__f_s_p_s[n * 30 + 5] = SIMINT_MUL(P_PA[1], PRIM_INT__d_s_p_s[n * 18 + 2]);
                        PRIM_INT__f_s_p_s[n * 30 + 5] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__d_s_p_s[(n+1) * 18 + 2], PRIM_INT__f_s_p_s[n * 30 + 5]);

                        PRIM_INT__f_s_p_s[n * 30 + 18] = SIMINT_MUL(P_PA[1], PRIM_INT__d_s_p_s[n * 18 + 9]);
                        PRIM_INT__f_s_p_s[n * 30 + 18] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__d_s_p_s[(n+1) * 18 + 9], PRIM_INT__f_s_p_s[n * 30 + 18]);
                        PRIM_INT__f_s_p_s[n * 30 + 18] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__p_s_p_s[(n+1) * 9 + 3], PRIM_INT__p_s_p_s[n * 9 + 3]), PRIM_INT__f_s_p_s[n * 30 + 18]);

                        PRIM_INT__f_s_p_s[n * 30 + 19] = SIMINT_MUL(P_PA[1], PRIM_INT__d_s_p_s[n * 18 + 10]);
                        PRIM_INT__f_s_p_s[n * 30 + 19] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__d_s_p_s[(n+1) * 18 + 10], PRIM_INT__f_s_p_s[n * 30 + 19]);
                        PRIM_INT__f_s_p_s[n * 30 + 19] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__p_s_p_s[(n+1) * 9 + 4], PRIM_INT__p_s_p_s[n * 9 + 4]), PRIM_INT__f_s_p_s[n * 30 + 19]);
                        PRIM_INT__f_s_p_s[n * 30 + 19] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__f_s_p_s[n * 30 + 19]);

                        PRIM_INT__f_s_p_s[n * 30 + 20] = SIMINT_MUL(P_PA[1], PRIM_INT__d_s_p_s[n * 18 + 11]);
                        PRIM_INT__f_s_p_s[n * 30 + 20] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__d_s_p_s[(n+1) * 18 + 11], PRIM_INT__f_s_p_s[n * 30 + 20]);
                        PRIM_INT__f_s_p_s[n * 30 + 20] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__p_s_p_s[(n+1) * 9 + 5], PRIM_INT__p_s_p_s[n * 9 + 5]), PRIM_INT__f_s_p_s[n * 30 + 20]);

                        PRIM_INT__f_s_p_s[n * 30 + 27] = SIMINT_MUL(P_PA[2], PRIM_INT__d_s_p_s[n * 18 + 15]);
                        PRIM_INT__f_s_p_s[n * 30 + 27] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__d_s_p_s[(n+1) * 18 + 15], PRIM_INT__f_s_p_s[n * 30 + 27]);
                        PRIM_INT__f_s_p_s[n * 30 + 27] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__p_s_p_s[(n+1) * 9 + 6], PRIM_INT__p_s_p_s[n * 9 + 6]), PRIM_INT__f_s_p_s[n * 30 + 27]);

                        PRIM_INT__f_s_p_s[n * 30 + 28] = SIMINT_MUL(P_PA[2], PRIM_INT__d_s_p_s[n * 18 + 16]);
                        PRIM_INT__f_s_p_s[n * 30 + 28] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__d_s_p_s[(n+1) * 18 + 16], PRIM_INT__f_s_p_s[n * 30 + 28]);
                        PRIM_INT__f_s_p_s[n * 30 + 28] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__p_s_p_s[(n+1) * 9 + 7], PRIM_INT__p_s_p_s[n * 9 + 7]), PRIM_INT__f_s_p_s[n * 30 + 28]);

                        PRIM_INT__f_s_p_s[n * 30 + 29] = SIMINT_MUL(P_PA[2], PRIM_INT__d_s_p_s[n * 18 + 17]);
                        PRIM_INT__f_s_p_s[n * 30 + 29] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__d_s_p_s[(n+1) * 18 + 17], PRIM_INT__f_s_p_s[n * 30 + 29]);
                        PRIM_INT__f_s_p_s[n * 30 + 29] = SIMINT_FMADD( vrr_const_2_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__p_s_p_s[(n+1) * 9 + 8], PRIM_INT__p_s_p_s[n * 9 + 8]), PRIM_INT__f_s_p_s[n * 30 + 29]);
                        PRIM_INT__f_s_p_s[n * 30 + 29] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__f_s_p_s[n * 30 + 29]);

                    }


                    VRR_I_g_s_d_s(
                            PRIM_INT__g_s_d_s,
                            PRIM_INT__f_s_d_s,
                            PRIM_INT__d_s_d_s,
                            PRIM_INT__f_s_p_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            one_over_2pq,
                            3);


                    ostei_general_vrr_I(5, 0, 3, 0, 2,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__g_s_f_s, PRIM_INT__f_s_f_s, NULL, PRIM_INT__g_s_d_s, NULL, PRIM_INT__h_s_f_s);


                    ostei_general_vrr_I(6, 0, 4, 0, 1,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__h_s_g_s, PRIM_INT__g_s_g_s, NULL, PRIM_INT__h_s_f_s, NULL, PRIM_INT__i_s_g_s);


                    ostei_general_vrr_I(4, 0, 7, 0, 3,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__f_s_k_s, PRIM_INT__d_s_k_s, NULL, PRIM_INT__f_s_i_s, NULL, PRIM_INT__g_s_k_s);


                    ostei_general_vrr_I(5, 0, 6, 0, 2,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__g_s_i_s, PRIM_INT__f_s_i_s, NULL, PRIM_INT__g_s_h_s, NULL, PRIM_INT__h_s_i_s);


                    ostei_general_vrr_I(6, 0, 5, 0, 1,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__h_s_h_s, PRIM_INT__g_s_h_s, NULL, PRIM_INT__h_s_g_s, NULL, PRIM_INT__i_s_h_s);


                    ostei_general_vrr_I(5, 0, 7, 0, 2,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__g_s_k_s, PRIM_INT__f_s_k_s, NULL, PRIM_INT__g_s_i_s, NULL, PRIM_INT__h_s_k_s);


                    ostei_general_vrr_I(6, 0, 6, 0, 1,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__h_s_i_s, PRIM_INT__g_s_i_s, NULL, PRIM_INT__h_s_h_s, NULL, PRIM_INT__i_s_i_s);


                    ostei_general_vrr_I(6, 0, 7, 0, 1,
                            one_over_2p, a_over_p, one_over_2pq, aop_PQ, P_PA,
                            PRIM_INT__h_s_k_s, PRIM_INT__g_s_k_s, NULL, PRIM_INT__h_s_i_s, NULL, PRIM_INT__i_s_k_s);




                    ////////////////////////////////////
                    // Accumulate contracted integrals
                    ////////////////////////////////////
                    if(lastoffset == 0)
                    {
                        contract_all(150, PRIM_INT__f_s_g_s, PRIM_PTR_INT__f_s_g_s);
                        contract_all(210, PRIM_INT__f_s_h_s, PRIM_PTR_INT__f_s_h_s);
                        contract_all(280, PRIM_INT__f_s_i_s, PRIM_PTR_INT__f_s_i_s);
                        contract_all(360, PRIM_INT__f_s_k_s, PRIM_PTR_INT__f_s_k_s);
                        contract_all(225, PRIM_INT__g_s_g_s, PRIM_PTR_INT__g_s_g_s);
                        contract_all(315, PRIM_INT__g_s_h_s, PRIM_PTR_INT__g_s_h_s);
                        contract_all(420, PRIM_INT__g_s_i_s, PRIM_PTR_INT__g_s_i_s);
                        contract_all(540, PRIM_INT__g_s_k_s, PRIM_PTR_INT__g_s_k_s);
                        contract_all(315, PRIM_INT__h_s_g_s, PRIM_PTR_INT__h_s_g_s);
                        contract_all(441, PRIM_INT__h_s_h_s, PRIM_PTR_INT__h_s_h_s);
                        contract_all(588, PRIM_INT__h_s_i_s, PRIM_PTR_INT__h_s_i_s);
                        contract_all(756, PRIM_INT__h_s_k_s, PRIM_PTR_INT__h_s_k_s);
                        contract_all(420, PRIM_INT__i_s_g_s, PRIM_PTR_INT__i_s_g_s);
                        contract_all(588, PRIM_INT__i_s_h_s, PRIM_PTR_INT__i_s_h_s);
                        contract_all(784, PRIM_INT__i_s_i_s, PRIM_PTR_INT__i_s_i_s);
                        contract_all(1008, PRIM_INT__i_s_k_s, PRIM_PTR_INT__i_s_k_s);
                    }
                    else
                    {
                        contract(150, shelloffsets, PRIM_INT__f_s_g_s, PRIM_PTR_INT__f_s_g_s);
                        contract(210, shelloffsets, PRIM_INT__f_s_h_s, PRIM_PTR_INT__f_s_h_s);
                        contract(280, shelloffsets, PRIM_INT__f_s_i_s, PRIM_PTR_INT__f_s_i_s);
                        contract(360, shelloffsets, PRIM_INT__f_s_k_s, PRIM_PTR_INT__f_s_k_s);
                        contract(225, shelloffsets, PRIM_INT__g_s_g_s, PRIM_PTR_INT__g_s_g_s);
                        contract(315, shelloffsets, PRIM_INT__g_s_h_s, PRIM_PTR_INT__g_s_h_s);
                        contract(420, shelloffsets, PRIM_INT__g_s_i_s, PRIM_PTR_INT__g_s_i_s);
                        contract(540, shelloffsets, PRIM_INT__g_s_k_s, PRIM_PTR_INT__g_s_k_s);
                        contract(315, shelloffsets, PRIM_INT__h_s_g_s, PRIM_PTR_INT__h_s_g_s);
                        contract(441, shelloffsets, PRIM_INT__h_s_h_s, PRIM_PTR_INT__h_s_h_s);
                        contract(588, shelloffsets, PRIM_INT__h_s_i_s, PRIM_PTR_INT__h_s_i_s);
                        contract(756, shelloffsets, PRIM_INT__h_s_k_s, PRIM_PTR_INT__h_s_k_s);
                        contract(420, shelloffsets, PRIM_INT__i_s_g_s, PRIM_PTR_INT__i_s_g_s);
                        contract(588, shelloffsets, PRIM_INT__i_s_h_s, PRIM_PTR_INT__i_s_h_s);
                        contract(784, shelloffsets, PRIM_INT__i_s_i_s, PRIM_PTR_INT__i_s_i_s);
                        contract(1008, shelloffsets, PRIM_INT__i_s_k_s, PRIM_PTR_INT__i_s_k_s);
                        PRIM_PTR_INT__f_s_g_s += lastoffset*150;
                        PRIM_PTR_INT__f_s_h_s += lastoffset*210;
                        PRIM_PTR_INT__f_s_i_s += lastoffset*280;
                        PRIM_PTR_INT__f_s_k_s += lastoffset*360;
                        PRIM_PTR_INT__g_s_g_s += lastoffset*225;
                        PRIM_PTR_INT__g_s_h_s += lastoffset*315;
                        PRIM_PTR_INT__g_s_i_s += lastoffset*420;
                        PRIM_PTR_INT__g_s_k_s += lastoffset*540;
                        PRIM_PTR_INT__h_s_g_s += lastoffset*315;
                        PRIM_PTR_INT__h_s_h_s += lastoffset*441;
                        PRIM_PTR_INT__h_s_i_s += lastoffset*588;
                        PRIM_PTR_INT__h_s_k_s += lastoffset*756;
                        PRIM_PTR_INT__i_s_g_s += lastoffset*420;
                        PRIM_PTR_INT__i_s_h_s += lastoffset*588;
                        PRIM_PTR_INT__i_s_i_s += lastoffset*784;
                        PRIM_PTR_INT__i_s_k_s += lastoffset*1008;
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
                double const * restrict HRR_INT__f_s_g_s = INT__f_s_g_s + abcd * 150;
                double const * restrict HRR_INT__f_s_h_s = INT__f_s_h_s + abcd * 210;
                double const * restrict HRR_INT__f_s_i_s = INT__f_s_i_s + abcd * 280;
                double const * restrict HRR_INT__f_s_k_s = INT__f_s_k_s + abcd * 360;
                double const * restrict HRR_INT__g_s_g_s = INT__g_s_g_s + abcd * 225;
                double const * restrict HRR_INT__g_s_h_s = INT__g_s_h_s + abcd * 315;
                double const * restrict HRR_INT__g_s_i_s = INT__g_s_i_s + abcd * 420;
                double const * restrict HRR_INT__g_s_k_s = INT__g_s_k_s + abcd * 540;
                double const * restrict HRR_INT__h_s_g_s = INT__h_s_g_s + abcd * 315;
                double const * restrict HRR_INT__h_s_h_s = INT__h_s_h_s + abcd * 441;
                double const * restrict HRR_INT__h_s_i_s = INT__h_s_i_s + abcd * 588;
                double const * restrict HRR_INT__h_s_k_s = INT__h_s_k_s + abcd * 756;
                double const * restrict HRR_INT__i_s_g_s = INT__i_s_g_s + abcd * 420;
                double const * restrict HRR_INT__i_s_h_s = INT__i_s_h_s + abcd * 588;
                double const * restrict HRR_INT__i_s_i_s = INT__i_s_i_s + abcd * 784;
                double const * restrict HRR_INT__i_s_k_s = INT__i_s_k_s + abcd * 1008;
                double * restrict HRR_INT__f_f_g_f = INT__f_f_g_f + real_abcd * 15000;

                // form INT__f_p_g_s
                for(iket = 0; iket < 15; ++iket)
                {
                    HRR_INT__f_p_g_s[0 * 15 + iket] = HRR_INT__g_s_g_s[0 * 15 + iket] + ( hAB[0] * HRR_INT__f_s_g_s[0 * 15 + iket] );

                    HRR_INT__f_p_g_s[1 * 15 + iket] = HRR_INT__g_s_g_s[1 * 15 + iket] + ( hAB[1] * HRR_INT__f_s_g_s[0 * 15 + iket] );

                    HRR_INT__f_p_g_s[2 * 15 + iket] = HRR_INT__g_s_g_s[2 * 15 + iket] + ( hAB[2] * HRR_INT__f_s_g_s[0 * 15 + iket] );

                    HRR_INT__f_p_g_s[3 * 15 + iket] = HRR_INT__g_s_g_s[1 * 15 + iket] + ( hAB[0] * HRR_INT__f_s_g_s[1 * 15 + iket] );

                    HRR_INT__f_p_g_s[4 * 15 + iket] = HRR_INT__g_s_g_s[3 * 15 + iket] + ( hAB[1] * HRR_INT__f_s_g_s[1 * 15 + iket] );

                    HRR_INT__f_p_g_s[5 * 15 + iket] = HRR_INT__g_s_g_s[4 * 15 + iket] + ( hAB[2] * HRR_INT__f_s_g_s[1 * 15 + iket] );

                    HRR_INT__f_p_g_s[6 * 15 + iket] = HRR_INT__g_s_g_s[2 * 15 + iket] + ( hAB[0] * HRR_INT__f_s_g_s[2 * 15 + iket] );

                    HRR_INT__f_p_g_s[7 * 15 + iket] = HRR_INT__g_s_g_s[4 * 15 + iket] + ( hAB[1] * HRR_INT__f_s_g_s[2 * 15 + iket] );

                    HRR_INT__f_p_g_s[8 * 15 + iket] = HRR_INT__g_s_g_s[5 * 15 + iket] + ( hAB[2] * HRR_INT__f_s_g_s[2 * 15 + iket] );

                    HRR_INT__f_p_g_s[9 * 15 + iket] = HRR_INT__g_s_g_s[3 * 15 + iket] + ( hAB[0] * HRR_INT__f_s_g_s[3 * 15 + iket] );

                    HRR_INT__f_p_g_s[10 * 15 + iket] = HRR_INT__g_s_g_s[6 * 15 + iket] + ( hAB[1] * HRR_INT__f_s_g_s[3 * 15 + iket] );

                    HRR_INT__f_p_g_s[11 * 15 + iket] = HRR_INT__g_s_g_s[7 * 15 + iket] + ( hAB[2] * HRR_INT__f_s_g_s[3 * 15 + iket] );

                    HRR_INT__f_p_g_s[12 * 15 + iket] = HRR_INT__g_s_g_s[4 * 15 + iket] + ( hAB[0] * HRR_INT__f_s_g_s[4 * 15 + iket] );

                    HRR_INT__f_p_g_s[13 * 15 + iket] = HRR_INT__g_s_g_s[7 * 15 + iket] + ( hAB[1] * HRR_INT__f_s_g_s[4 * 15 + iket] );

                    HRR_INT__f_p_g_s[14 * 15 + iket] = HRR_INT__g_s_g_s[8 * 15 + iket] + ( hAB[2] * HRR_INT__f_s_g_s[4 * 15 + iket] );

                    HRR_INT__f_p_g_s[15 * 15 + iket] = HRR_INT__g_s_g_s[5 * 15 + iket] + ( hAB[0] * HRR_INT__f_s_g_s[5 * 15 + iket] );

                    HRR_INT__f_p_g_s[16 * 15 + iket] = HRR_INT__g_s_g_s[8 * 15 + iket] + ( hAB[1] * HRR_INT__f_s_g_s[5 * 15 + iket] );

                    HRR_INT__f_p_g_s[17 * 15 + iket] = HRR_INT__g_s_g_s[9 * 15 + iket] + ( hAB[2] * HRR_INT__f_s_g_s[5 * 15 + iket] );

                    HRR_INT__f_p_g_s[18 * 15 + iket] = HRR_INT__g_s_g_s[6 * 15 + iket] + ( hAB[0] * HRR_INT__f_s_g_s[6 * 15 + iket] );

                    HRR_INT__f_p_g_s[19 * 15 + iket] = HRR_INT__g_s_g_s[10 * 15 + iket] + ( hAB[1] * HRR_INT__f_s_g_s[6 * 15 + iket] );

                    HRR_INT__f_p_g_s[20 * 15 + iket] = HRR_INT__g_s_g_s[11 * 15 + iket] + ( hAB[2] * HRR_INT__f_s_g_s[6 * 15 + iket] );

                    HRR_INT__f_p_g_s[21 * 15 + iket] = HRR_INT__g_s_g_s[7 * 15 + iket] + ( hAB[0] * HRR_INT__f_s_g_s[7 * 15 + iket] );

                    HRR_INT__f_p_g_s[22 * 15 + iket] = HRR_INT__g_s_g_s[11 * 15 + iket] + ( hAB[1] * HRR_INT__f_s_g_s[7 * 15 + iket] );

                    HRR_INT__f_p_g_s[23 * 15 + iket] = HRR_INT__g_s_g_s[12 * 15 + iket] + ( hAB[2] * HRR_INT__f_s_g_s[7 * 15 + iket] );

                    HRR_INT__f_p_g_s[24 * 15 + iket] = HRR_INT__g_s_g_s[8 * 15 + iket] + ( hAB[0] * HRR_INT__f_s_g_s[8 * 15 + iket] );

                    HRR_INT__f_p_g_s[25 * 15 + iket] = HRR_INT__g_s_g_s[12 * 15 + iket] + ( hAB[1] * HRR_INT__f_s_g_s[8 * 15 + iket] );

                    HRR_INT__f_p_g_s[26 * 15 + iket] = HRR_INT__g_s_g_s[13 * 15 + iket] + ( hAB[2] * HRR_INT__f_s_g_s[8 * 15 + iket] );

                    HRR_INT__f_p_g_s[27 * 15 + iket] = HRR_INT__g_s_g_s[9 * 15 + iket] + ( hAB[0] * HRR_INT__f_s_g_s[9 * 15 + iket] );

                    HRR_INT__f_p_g_s[28 * 15 + iket] = HRR_INT__g_s_g_s[13 * 15 + iket] + ( hAB[1] * HRR_INT__f_s_g_s[9 * 15 + iket] );

                    HRR_INT__f_p_g_s[29 * 15 + iket] = HRR_INT__g_s_g_s[14 * 15 + iket] + ( hAB[2] * HRR_INT__f_s_g_s[9 * 15 + iket] );

                }


                // form INT__f_p_h_s
                for(iket = 0; iket < 21; ++iket)
                {
                    HRR_INT__f_p_h_s[0 * 21 + iket] = HRR_INT__g_s_h_s[0 * 21 + iket] + ( hAB[0] * HRR_INT__f_s_h_s[0 * 21 + iket] );

                    HRR_INT__f_p_h_s[1 * 21 + iket] = HRR_INT__g_s_h_s[1 * 21 + iket] + ( hAB[1] * HRR_INT__f_s_h_s[0 * 21 + iket] );

                    HRR_INT__f_p_h_s[2 * 21 + iket] = HRR_INT__g_s_h_s[2 * 21 + iket] + ( hAB[2] * HRR_INT__f_s_h_s[0 * 21 + iket] );

                    HRR_INT__f_p_h_s[3 * 21 + iket] = HRR_INT__g_s_h_s[1 * 21 + iket] + ( hAB[0] * HRR_INT__f_s_h_s[1 * 21 + iket] );

                    HRR_INT__f_p_h_s[4 * 21 + iket] = HRR_INT__g_s_h_s[3 * 21 + iket] + ( hAB[1] * HRR_INT__f_s_h_s[1 * 21 + iket] );

                    HRR_INT__f_p_h_s[5 * 21 + iket] = HRR_INT__g_s_h_s[4 * 21 + iket] + ( hAB[2] * HRR_INT__f_s_h_s[1 * 21 + iket] );

                    HRR_INT__f_p_h_s[6 * 21 + iket] = HRR_INT__g_s_h_s[2 * 21 + iket] + ( hAB[0] * HRR_INT__f_s_h_s[2 * 21 + iket] );

                    HRR_INT__f_p_h_s[7 * 21 + iket] = HRR_INT__g_s_h_s[4 * 21 + iket] + ( hAB[1] * HRR_INT__f_s_h_s[2 * 21 + iket] );

                    HRR_INT__f_p_h_s[8 * 21 + iket] = HRR_INT__g_s_h_s[5 * 21 + iket] + ( hAB[2] * HRR_INT__f_s_h_s[2 * 21 + iket] );

                    HRR_INT__f_p_h_s[9 * 21 + iket] = HRR_INT__g_s_h_s[3 * 21 + iket] + ( hAB[0] * HRR_INT__f_s_h_s[3 * 21 + iket] );

                    HRR_INT__f_p_h_s[10 * 21 + iket] = HRR_INT__g_s_h_s[6 * 21 + iket] + ( hAB[1] * HRR_INT__f_s_h_s[3 * 21 + iket] );

                    HRR_INT__f_p_h_s[11 * 21 + iket] = HRR_INT__g_s_h_s[7 * 21 + iket] + ( hAB[2] * HRR_INT__f_s_h_s[3 * 21 + iket] );

                    HRR_INT__f_p_h_s[12 * 21 + iket] = HRR_INT__g_s_h_s[4 * 21 + iket] + ( hAB[0] * HRR_INT__f_s_h_s[4 * 21 + iket] );

                    HRR_INT__f_p_h_s[13 * 21 + iket] = HRR_INT__g_s_h_s[7 * 21 + iket] + ( hAB[1] * HRR_INT__f_s_h_s[4 * 21 + iket] );

                    HRR_INT__f_p_h_s[14 * 21 + iket] = HRR_INT__g_s_h_s[8 * 21 + iket] + ( hAB[2] * HRR_INT__f_s_h_s[4 * 21 + iket] );

                    HRR_INT__f_p_h_s[15 * 21 + iket] = HRR_INT__g_s_h_s[5 * 21 + iket] + ( hAB[0] * HRR_INT__f_s_h_s[5 * 21 + iket] );

                    HRR_INT__f_p_h_s[16 * 21 + iket] = HRR_INT__g_s_h_s[8 * 21 + iket] + ( hAB[1] * HRR_INT__f_s_h_s[5 * 21 + iket] );

                    HRR_INT__f_p_h_s[17 * 21 + iket] = HRR_INT__g_s_h_s[9 * 21 + iket] + ( hAB[2] * HRR_INT__f_s_h_s[5 * 21 + iket] );

                    HRR_INT__f_p_h_s[18 * 21 + iket] = HRR_INT__g_s_h_s[6 * 21 + iket] + ( hAB[0] * HRR_INT__f_s_h_s[6 * 21 + iket] );

                    HRR_INT__f_p_h_s[19 * 21 + iket] = HRR_INT__g_s_h_s[10 * 21 + iket] + ( hAB[1] * HRR_INT__f_s_h_s[6 * 21 + iket] );

                    HRR_INT__f_p_h_s[20 * 21 + iket] = HRR_INT__g_s_h_s[11 * 21 + iket] + ( hAB[2] * HRR_INT__f_s_h_s[6 * 21 + iket] );

                    HRR_INT__f_p_h_s[21 * 21 + iket] = HRR_INT__g_s_h_s[7 * 21 + iket] + ( hAB[0] * HRR_INT__f_s_h_s[7 * 21 + iket] );

                    HRR_INT__f_p_h_s[22 * 21 + iket] = HRR_INT__g_s_h_s[11 * 21 + iket] + ( hAB[1] * HRR_INT__f_s_h_s[7 * 21 + iket] );

                    HRR_INT__f_p_h_s[23 * 21 + iket] = HRR_INT__g_s_h_s[12 * 21 + iket] + ( hAB[2] * HRR_INT__f_s_h_s[7 * 21 + iket] );

                    HRR_INT__f_p_h_s[24 * 21 + iket] = HRR_INT__g_s_h_s[8 * 21 + iket] + ( hAB[0] * HRR_INT__f_s_h_s[8 * 21 + iket] );

                    HRR_INT__f_p_h_s[25 * 21 + iket] = HRR_INT__g_s_h_s[12 * 21 + iket] + ( hAB[1] * HRR_INT__f_s_h_s[8 * 21 + iket] );

                    HRR_INT__f_p_h_s[26 * 21 + iket] = HRR_INT__g_s_h_s[13 * 21 + iket] + ( hAB[2] * HRR_INT__f_s_h_s[8 * 21 + iket] );

                    HRR_INT__f_p_h_s[27 * 21 + iket] = HRR_INT__g_s_h_s[9 * 21 + iket] + ( hAB[0] * HRR_INT__f_s_h_s[9 * 21 + iket] );

                    HRR_INT__f_p_h_s[28 * 21 + iket] = HRR_INT__g_s_h_s[13 * 21 + iket] + ( hAB[1] * HRR_INT__f_s_h_s[9 * 21 + iket] );

                    HRR_INT__f_p_h_s[29 * 21 + iket] = HRR_INT__g_s_h_s[14 * 21 + iket] + ( hAB[2] * HRR_INT__f_s_h_s[9 * 21 + iket] );

                }


                // form INT__f_p_i_s
                for(iket = 0; iket < 28; ++iket)
                {
                    HRR_INT__f_p_i_s[0 * 28 + iket] = HRR_INT__g_s_i_s[0 * 28 + iket] + ( hAB[0] * HRR_INT__f_s_i_s[0 * 28 + iket] );

                    HRR_INT__f_p_i_s[1 * 28 + iket] = HRR_INT__g_s_i_s[1 * 28 + iket] + ( hAB[1] * HRR_INT__f_s_i_s[0 * 28 + iket] );

                    HRR_INT__f_p_i_s[2 * 28 + iket] = HRR_INT__g_s_i_s[2 * 28 + iket] + ( hAB[2] * HRR_INT__f_s_i_s[0 * 28 + iket] );

                    HRR_INT__f_p_i_s[3 * 28 + iket] = HRR_INT__g_s_i_s[1 * 28 + iket] + ( hAB[0] * HRR_INT__f_s_i_s[1 * 28 + iket] );

                    HRR_INT__f_p_i_s[4 * 28 + iket] = HRR_INT__g_s_i_s[3 * 28 + iket] + ( hAB[1] * HRR_INT__f_s_i_s[1 * 28 + iket] );

                    HRR_INT__f_p_i_s[5 * 28 + iket] = HRR_INT__g_s_i_s[4 * 28 + iket] + ( hAB[2] * HRR_INT__f_s_i_s[1 * 28 + iket] );

                    HRR_INT__f_p_i_s[6 * 28 + iket] = HRR_INT__g_s_i_s[2 * 28 + iket] + ( hAB[0] * HRR_INT__f_s_i_s[2 * 28 + iket] );

                    HRR_INT__f_p_i_s[7 * 28 + iket] = HRR_INT__g_s_i_s[4 * 28 + iket] + ( hAB[1] * HRR_INT__f_s_i_s[2 * 28 + iket] );

                    HRR_INT__f_p_i_s[8 * 28 + iket] = HRR_INT__g_s_i_s[5 * 28 + iket] + ( hAB[2] * HRR_INT__f_s_i_s[2 * 28 + iket] );

                    HRR_INT__f_p_i_s[9 * 28 + iket] = HRR_INT__g_s_i_s[3 * 28 + iket] + ( hAB[0] * HRR_INT__f_s_i_s[3 * 28 + iket] );

                    HRR_INT__f_p_i_s[10 * 28 + iket] = HRR_INT__g_s_i_s[6 * 28 + iket] + ( hAB[1] * HRR_INT__f_s_i_s[3 * 28 + iket] );

                    HRR_INT__f_p_i_s[11 * 28 + iket] = HRR_INT__g_s_i_s[7 * 28 + iket] + ( hAB[2] * HRR_INT__f_s_i_s[3 * 28 + iket] );

                    HRR_INT__f_p_i_s[12 * 28 + iket] = HRR_INT__g_s_i_s[4 * 28 + iket] + ( hAB[0] * HRR_INT__f_s_i_s[4 * 28 + iket] );

                    HRR_INT__f_p_i_s[13 * 28 + iket] = HRR_INT__g_s_i_s[7 * 28 + iket] + ( hAB[1] * HRR_INT__f_s_i_s[4 * 28 + iket] );

                    HRR_INT__f_p_i_s[14 * 28 + iket] = HRR_INT__g_s_i_s[8 * 28 + iket] + ( hAB[2] * HRR_INT__f_s_i_s[4 * 28 + iket] );

                    HRR_INT__f_p_i_s[15 * 28 + iket] = HRR_INT__g_s_i_s[5 * 28 + iket] + ( hAB[0] * HRR_INT__f_s_i_s[5 * 28 + iket] );

                    HRR_INT__f_p_i_s[16 * 28 + iket] = HRR_INT__g_s_i_s[8 * 28 + iket] + ( hAB[1] * HRR_INT__f_s_i_s[5 * 28 + iket] );

                    HRR_INT__f_p_i_s[17 * 28 + iket] = HRR_INT__g_s_i_s[9 * 28 + iket] + ( hAB[2] * HRR_INT__f_s_i_s[5 * 28 + iket] );

                    HRR_INT__f_p_i_s[18 * 28 + iket] = HRR_INT__g_s_i_s[6 * 28 + iket] + ( hAB[0] * HRR_INT__f_s_i_s[6 * 28 + iket] );

                    HRR_INT__f_p_i_s[19 * 28 + iket] = HRR_INT__g_s_i_s[10 * 28 + iket] + ( hAB[1] * HRR_INT__f_s_i_s[6 * 28 + iket] );

                    HRR_INT__f_p_i_s[20 * 28 + iket] = HRR_INT__g_s_i_s[11 * 28 + iket] + ( hAB[2] * HRR_INT__f_s_i_s[6 * 28 + iket] );

                    HRR_INT__f_p_i_s[21 * 28 + iket] = HRR_INT__g_s_i_s[7 * 28 + iket] + ( hAB[0] * HRR_INT__f_s_i_s[7 * 28 + iket] );

                    HRR_INT__f_p_i_s[22 * 28 + iket] = HRR_INT__g_s_i_s[11 * 28 + iket] + ( hAB[1] * HRR_INT__f_s_i_s[7 * 28 + iket] );

                    HRR_INT__f_p_i_s[23 * 28 + iket] = HRR_INT__g_s_i_s[12 * 28 + iket] + ( hAB[2] * HRR_INT__f_s_i_s[7 * 28 + iket] );

                    HRR_INT__f_p_i_s[24 * 28 + iket] = HRR_INT__g_s_i_s[8 * 28 + iket] + ( hAB[0] * HRR_INT__f_s_i_s[8 * 28 + iket] );

                    HRR_INT__f_p_i_s[25 * 28 + iket] = HRR_INT__g_s_i_s[12 * 28 + iket] + ( hAB[1] * HRR_INT__f_s_i_s[8 * 28 + iket] );

                    HRR_INT__f_p_i_s[26 * 28 + iket] = HRR_INT__g_s_i_s[13 * 28 + iket] + ( hAB[2] * HRR_INT__f_s_i_s[8 * 28 + iket] );

                    HRR_INT__f_p_i_s[27 * 28 + iket] = HRR_INT__g_s_i_s[9 * 28 + iket] + ( hAB[0] * HRR_INT__f_s_i_s[9 * 28 + iket] );

                    HRR_INT__f_p_i_s[28 * 28 + iket] = HRR_INT__g_s_i_s[13 * 28 + iket] + ( hAB[1] * HRR_INT__f_s_i_s[9 * 28 + iket] );

                    HRR_INT__f_p_i_s[29 * 28 + iket] = HRR_INT__g_s_i_s[14 * 28 + iket] + ( hAB[2] * HRR_INT__f_s_i_s[9 * 28 + iket] );

                }


                // form INT__f_p_k_s
                for(iket = 0; iket < 36; ++iket)
                {
                    HRR_INT__f_p_k_s[0 * 36 + iket] = HRR_INT__g_s_k_s[0 * 36 + iket] + ( hAB[0] * HRR_INT__f_s_k_s[0 * 36 + iket] );

                    HRR_INT__f_p_k_s[1 * 36 + iket] = HRR_INT__g_s_k_s[1 * 36 + iket] + ( hAB[1] * HRR_INT__f_s_k_s[0 * 36 + iket] );

                    HRR_INT__f_p_k_s[2 * 36 + iket] = HRR_INT__g_s_k_s[2 * 36 + iket] + ( hAB[2] * HRR_INT__f_s_k_s[0 * 36 + iket] );

                    HRR_INT__f_p_k_s[3 * 36 + iket] = HRR_INT__g_s_k_s[1 * 36 + iket] + ( hAB[0] * HRR_INT__f_s_k_s[1 * 36 + iket] );

                    HRR_INT__f_p_k_s[4 * 36 + iket] = HRR_INT__g_s_k_s[3 * 36 + iket] + ( hAB[1] * HRR_INT__f_s_k_s[1 * 36 + iket] );

                    HRR_INT__f_p_k_s[5 * 36 + iket] = HRR_INT__g_s_k_s[4 * 36 + iket] + ( hAB[2] * HRR_INT__f_s_k_s[1 * 36 + iket] );

                    HRR_INT__f_p_k_s[6 * 36 + iket] = HRR_INT__g_s_k_s[2 * 36 + iket] + ( hAB[0] * HRR_INT__f_s_k_s[2 * 36 + iket] );

                    HRR_INT__f_p_k_s[7 * 36 + iket] = HRR_INT__g_s_k_s[4 * 36 + iket] + ( hAB[1] * HRR_INT__f_s_k_s[2 * 36 + iket] );

                    HRR_INT__f_p_k_s[8 * 36 + iket] = HRR_INT__g_s_k_s[5 * 36 + iket] + ( hAB[2] * HRR_INT__f_s_k_s[2 * 36 + iket] );

                    HRR_INT__f_p_k_s[9 * 36 + iket] = HRR_INT__g_s_k_s[3 * 36 + iket] + ( hAB[0] * HRR_INT__f_s_k_s[3 * 36 + iket] );

                    HRR_INT__f_p_k_s[10 * 36 + iket] = HRR_INT__g_s_k_s[6 * 36 + iket] + ( hAB[1] * HRR_INT__f_s_k_s[3 * 36 + iket] );

                    HRR_INT__f_p_k_s[11 * 36 + iket] = HRR_INT__g_s_k_s[7 * 36 + iket] + ( hAB[2] * HRR_INT__f_s_k_s[3 * 36 + iket] );

                    HRR_INT__f_p_k_s[12 * 36 + iket] = HRR_INT__g_s_k_s[4 * 36 + iket] + ( hAB[0] * HRR_INT__f_s_k_s[4 * 36 + iket] );

                    HRR_INT__f_p_k_s[13 * 36 + iket] = HRR_INT__g_s_k_s[7 * 36 + iket] + ( hAB[1] * HRR_INT__f_s_k_s[4 * 36 + iket] );

                    HRR_INT__f_p_k_s[14 * 36 + iket] = HRR_INT__g_s_k_s[8 * 36 + iket] + ( hAB[2] * HRR_INT__f_s_k_s[4 * 36 + iket] );

                    HRR_INT__f_p_k_s[15 * 36 + iket] = HRR_INT__g_s_k_s[5 * 36 + iket] + ( hAB[0] * HRR_INT__f_s_k_s[5 * 36 + iket] );

                    HRR_INT__f_p_k_s[16 * 36 + iket] = HRR_INT__g_s_k_s[8 * 36 + iket] + ( hAB[1] * HRR_INT__f_s_k_s[5 * 36 + iket] );

                    HRR_INT__f_p_k_s[17 * 36 + iket] = HRR_INT__g_s_k_s[9 * 36 + iket] + ( hAB[2] * HRR_INT__f_s_k_s[5 * 36 + iket] );

                    HRR_INT__f_p_k_s[18 * 36 + iket] = HRR_INT__g_s_k_s[6 * 36 + iket] + ( hAB[0] * HRR_INT__f_s_k_s[6 * 36 + iket] );

                    HRR_INT__f_p_k_s[19 * 36 + iket] = HRR_INT__g_s_k_s[10 * 36 + iket] + ( hAB[1] * HRR_INT__f_s_k_s[6 * 36 + iket] );

                    HRR_INT__f_p_k_s[20 * 36 + iket] = HRR_INT__g_s_k_s[11 * 36 + iket] + ( hAB[2] * HRR_INT__f_s_k_s[6 * 36 + iket] );

                    HRR_INT__f_p_k_s[21 * 36 + iket] = HRR_INT__g_s_k_s[7 * 36 + iket] + ( hAB[0] * HRR_INT__f_s_k_s[7 * 36 + iket] );

                    HRR_INT__f_p_k_s[22 * 36 + iket] = HRR_INT__g_s_k_s[11 * 36 + iket] + ( hAB[1] * HRR_INT__f_s_k_s[7 * 36 + iket] );

                    HRR_INT__f_p_k_s[23 * 36 + iket] = HRR_INT__g_s_k_s[12 * 36 + iket] + ( hAB[2] * HRR_INT__f_s_k_s[7 * 36 + iket] );

                    HRR_INT__f_p_k_s[24 * 36 + iket] = HRR_INT__g_s_k_s[8 * 36 + iket] + ( hAB[0] * HRR_INT__f_s_k_s[8 * 36 + iket] );

                    HRR_INT__f_p_k_s[25 * 36 + iket] = HRR_INT__g_s_k_s[12 * 36 + iket] + ( hAB[1] * HRR_INT__f_s_k_s[8 * 36 + iket] );

                    HRR_INT__f_p_k_s[26 * 36 + iket] = HRR_INT__g_s_k_s[13 * 36 + iket] + ( hAB[2] * HRR_INT__f_s_k_s[8 * 36 + iket] );

                    HRR_INT__f_p_k_s[27 * 36 + iket] = HRR_INT__g_s_k_s[9 * 36 + iket] + ( hAB[0] * HRR_INT__f_s_k_s[9 * 36 + iket] );

                    HRR_INT__f_p_k_s[28 * 36 + iket] = HRR_INT__g_s_k_s[13 * 36 + iket] + ( hAB[1] * HRR_INT__f_s_k_s[9 * 36 + iket] );

                    HRR_INT__f_p_k_s[29 * 36 + iket] = HRR_INT__g_s_k_s[14 * 36 + iket] + ( hAB[2] * HRR_INT__f_s_k_s[9 * 36 + iket] );

                }


                // form INT__g_p_g_s
                HRR_J_g_p(
                    HRR_INT__g_p_g_s,
                    HRR_INT__g_s_g_s,
                    HRR_INT__h_s_g_s,
                    hAB, 15);

                // form INT__g_p_h_s
                HRR_J_g_p(
                    HRR_INT__g_p_h_s,
                    HRR_INT__g_s_h_s,
                    HRR_INT__h_s_h_s,
                    hAB, 21);

                // form INT__g_p_i_s
                HRR_J_g_p(
                    HRR_INT__g_p_i_s,
                    HRR_INT__g_s_i_s,
                    HRR_INT__h_s_i_s,
                    hAB, 28);

                // form INT__g_p_k_s
                HRR_J_g_p(
                    HRR_INT__g_p_k_s,
                    HRR_INT__g_s_k_s,
                    HRR_INT__h_s_k_s,
                    hAB, 36);

                // form INT__h_p_g_s
                HRR_J_h_p(
                    HRR_INT__h_p_g_s,
                    HRR_INT__h_s_g_s,
                    HRR_INT__i_s_g_s,
                    hAB, 15);

                // form INT__h_p_h_s
                HRR_J_h_p(
                    HRR_INT__h_p_h_s,
                    HRR_INT__h_s_h_s,
                    HRR_INT__i_s_h_s,
                    hAB, 21);

                // form INT__h_p_i_s
                HRR_J_h_p(
                    HRR_INT__h_p_i_s,
                    HRR_INT__h_s_i_s,
                    HRR_INT__i_s_i_s,
                    hAB, 28);

                // form INT__h_p_k_s
                HRR_J_h_p(
                    HRR_INT__h_p_k_s,
                    HRR_INT__h_s_k_s,
                    HRR_INT__i_s_k_s,
                    hAB, 36);

                // form INT__f_d_g_s
                HRR_J_f_d(
                    HRR_INT__f_d_g_s,
                    HRR_INT__f_p_g_s,
                    HRR_INT__g_p_g_s,
                    hAB, 15);

                // form INT__f_d_h_s
                HRR_J_f_d(
                    HRR_INT__f_d_h_s,
                    HRR_INT__f_p_h_s,
                    HRR_INT__g_p_h_s,
                    hAB, 21);

                // form INT__f_d_i_s
                HRR_J_f_d(
                    HRR_INT__f_d_i_s,
                    HRR_INT__f_p_i_s,
                    HRR_INT__g_p_i_s,
                    hAB, 28);

                // form INT__f_d_k_s
                HRR_J_f_d(
                    HRR_INT__f_d_k_s,
                    HRR_INT__f_p_k_s,
                    HRR_INT__g_p_k_s,
                    hAB, 36);

                // form INT__g_d_g_s
                HRR_J_g_d(
                    HRR_INT__g_d_g_s,
                    HRR_INT__g_p_g_s,
                    HRR_INT__h_p_g_s,
                    hAB, 15);

                // form INT__g_d_h_s
                HRR_J_g_d(
                    HRR_INT__g_d_h_s,
                    HRR_INT__g_p_h_s,
                    HRR_INT__h_p_h_s,
                    hAB, 21);

                // form INT__g_d_i_s
                HRR_J_g_d(
                    HRR_INT__g_d_i_s,
                    HRR_INT__g_p_i_s,
                    HRR_INT__h_p_i_s,
                    hAB, 28);

                // form INT__g_d_k_s
                HRR_J_g_d(
                    HRR_INT__g_d_k_s,
                    HRR_INT__g_p_k_s,
                    HRR_INT__h_p_k_s,
                    hAB, 36);

                // form INT__f_f_g_s
                HRR_J_f_f(
                    HRR_INT__f_f_g_s,
                    HRR_INT__f_d_g_s,
                    HRR_INT__g_d_g_s,
                    hAB, 15);

                // form INT__f_f_h_s
                HRR_J_f_f(
                    HRR_INT__f_f_h_s,
                    HRR_INT__f_d_h_s,
                    HRR_INT__g_d_h_s,
                    hAB, 21);

                // form INT__f_f_i_s
                HRR_J_f_f(
                    HRR_INT__f_f_i_s,
                    HRR_INT__f_d_i_s,
                    HRR_INT__g_d_i_s,
                    hAB, 28);

                // form INT__f_f_k_s
                HRR_J_f_f(
                    HRR_INT__f_f_k_s,
                    HRR_INT__f_d_k_s,
                    HRR_INT__g_d_k_s,
                    hAB, 36);

                // form INT__f_f_g_p
                HRR_L_g_p(
                    HRR_INT__f_f_g_p,
                    HRR_INT__f_f_g_s,
                    HRR_INT__f_f_h_s,
                    hCD, 100);

                // form INT__f_f_h_p
                HRR_L_h_p(
                    HRR_INT__f_f_h_p,
                    HRR_INT__f_f_h_s,
                    HRR_INT__f_f_i_s,
                    hCD, 100);

                // form INT__f_f_i_p
                HRR_L_i_p(
                    HRR_INT__f_f_i_p,
                    HRR_INT__f_f_i_s,
                    HRR_INT__f_f_k_s,
                    hCD, 100);

                // form INT__f_f_g_d
                HRR_L_g_d(
                    HRR_INT__f_f_g_d,
                    HRR_INT__f_f_g_p,
                    HRR_INT__f_f_h_p,
                    hCD, 100);

                // form INT__f_f_h_d
                HRR_L_h_d(
                    HRR_INT__f_f_h_d,
                    HRR_INT__f_f_h_p,
                    HRR_INT__f_f_i_p,
                    hCD, 100);

                // form INT__f_f_g_f
                HRR_L_g_f(
                    HRR_INT__f_f_g_f,
                    HRR_INT__f_f_g_d,
                    HRR_INT__f_f_h_d,
                    hCD, 100);


            }  // close HRR loop


        }   // close loop cdbatch

        istart = iend;
    }  // close loop over ab

    return P.nshell12_clip * Q.nshell12_clip;
}

int ostei_f_f_f_g(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__f_f_f_g)
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

    int ret = ostei_f_f_g_f(P, Q_tmp, screen_tol, work, INT__f_f_f_g);
    double buffer[15000] SIMINT_ALIGN_ARRAY_DBL;

    for(int q = 0; q < ret; q++)
    {
        int idx = 0;
        for(int a = 0; a < 10; ++a)
        for(int b = 0; b < 10; ++b)
        for(int c = 0; c < 10; ++c)
        for(int d = 0; d < 15; ++d)
            buffer[idx++] = INT__f_f_f_g[q*15000+a*1500+b*150+d*10+c];

        memcpy(INT__f_f_f_g+q*15000, buffer, 15000*sizeof(double));
    }

    return ret;
}

