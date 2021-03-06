#include "simint/boys/boys.h"
#include "simint/ostei/gen/ostei_generated.h"
#include "simint/vectorization/vectorization.h"
#include <math.h>
#include <string.h>


int ostei_d_f_d_f(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__d_f_d_f)
{

    SIMINT_ASSUME_ALIGN_DBL(work);
    SIMINT_ASSUME_ALIGN_DBL(INT__d_f_d_f);
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
    double * const INT__s_f_s_f = work + (SIMINT_NSHELL_SIMD * 0);
    double * const INT__s_f_s_g = work + (SIMINT_NSHELL_SIMD * 100);
    double * const INT__s_f_s_h = work + (SIMINT_NSHELL_SIMD * 250);
    double * const INT__s_g_s_f = work + (SIMINT_NSHELL_SIMD * 460);
    double * const INT__s_g_s_g = work + (SIMINT_NSHELL_SIMD * 610);
    double * const INT__s_g_s_h = work + (SIMINT_NSHELL_SIMD * 835);
    double * const INT__s_h_s_f = work + (SIMINT_NSHELL_SIMD * 1150);
    double * const INT__s_h_s_g = work + (SIMINT_NSHELL_SIMD * 1360);
    double * const INT__s_h_s_h = work + (SIMINT_NSHELL_SIMD * 1675);
    SIMINT_DBLTYPE * const primwork = (SIMINT_DBLTYPE *)(work + SIMINT_NSHELL_SIMD*2116);
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_s = primwork + 0;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_p = primwork + 11;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_d = primwork + 26;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_s = primwork + 50;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_p = primwork + 80;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_d = primwork + 125;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_f = primwork + 197;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_s = primwork + 287;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_p = primwork + 341;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_d = primwork + 431;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_f = primwork + 575;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_g = primwork + 755;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_s = primwork + 935;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_p = primwork + 1015;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_d = primwork + 1165;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_f = primwork + 1405;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_g = primwork + 1705;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_h = primwork + 2005;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s = primwork + 2215;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_p = primwork + 2320;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_d = primwork + 2545;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_f = primwork + 2905;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_g = primwork + 3355;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_h = primwork + 3805;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_s = primwork + 4120;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_p = primwork + 4246;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_d = primwork + 4561;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_f = primwork + 5065;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_g = primwork + 5695;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_h = primwork + 6325;
    double * const hrrwork = (double *)(primwork + 6766);
    double * const HRR_INT__p_f_s_f = hrrwork + 0;
    double * const HRR_INT__p_f_s_g = hrrwork + 300;
    double * const HRR_INT__p_f_s_h = hrrwork + 750;
    double * const HRR_INT__p_g_s_f = hrrwork + 1380;
    double * const HRR_INT__p_g_s_g = hrrwork + 1830;
    double * const HRR_INT__p_g_s_h = hrrwork + 2505;
    double * const HRR_INT__d_f_s_f = hrrwork + 3450;
    double * const HRR_INT__d_f_s_g = hrrwork + 4050;
    double * const HRR_INT__d_f_s_h = hrrwork + 4950;
    double * const HRR_INT__d_f_p_f = hrrwork + 6210;
    double * const HRR_INT__d_f_p_g = hrrwork + 8010;


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
            memset(work, 0, SIMINT_NSHELL_SIMD * 2116 * sizeof(double));
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
                double * restrict PRIM_PTR_INT__s_f_s_f = INT__s_f_s_f + abcd * 100;
                double * restrict PRIM_PTR_INT__s_f_s_g = INT__s_f_s_g + abcd * 150;
                double * restrict PRIM_PTR_INT__s_f_s_h = INT__s_f_s_h + abcd * 210;
                double * restrict PRIM_PTR_INT__s_g_s_f = INT__s_g_s_f + abcd * 150;
                double * restrict PRIM_PTR_INT__s_g_s_g = INT__s_g_s_g + abcd * 225;
                double * restrict PRIM_PTR_INT__s_g_s_h = INT__s_g_s_h + abcd * 315;
                double * restrict PRIM_PTR_INT__s_h_s_f = INT__s_h_s_f + abcd * 210;
                double * restrict PRIM_PTR_INT__s_h_s_g = INT__s_h_s_g + abcd * 315;
                double * restrict PRIM_PTR_INT__s_h_s_h = INT__s_h_s_h + abcd * 441;



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
                            PRIM_PTR_INT__s_f_s_f += 100;
                            PRIM_PTR_INT__s_f_s_g += 150;
                            PRIM_PTR_INT__s_f_s_h += 210;
                            PRIM_PTR_INT__s_g_s_f += 150;
                            PRIM_PTR_INT__s_g_s_g += 225;
                            PRIM_PTR_INT__s_g_s_h += 315;
                            PRIM_PTR_INT__s_h_s_f += 210;
                            PRIM_PTR_INT__s_h_s_g += 315;
                            PRIM_PTR_INT__s_h_s_h += 441;
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
                            PRIM_PTR_INT__s_f_s_f += lastoffset*100;
                            PRIM_PTR_INT__s_f_s_g += lastoffset*150;
                            PRIM_PTR_INT__s_f_s_h += lastoffset*210;
                            PRIM_PTR_INT__s_g_s_f += lastoffset*150;
                            PRIM_PTR_INT__s_g_s_g += lastoffset*225;
                            PRIM_PTR_INT__s_g_s_h += lastoffset*315;
                            PRIM_PTR_INT__s_h_s_f += lastoffset*210;
                            PRIM_PTR_INT__s_h_s_g += lastoffset*315;
                            PRIM_PTR_INT__s_h_s_h += lastoffset*441;
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
                    // Maximum v value: 10
                    //////////////////////////////////////////////
                    // The parameter to the Fjt function
                    const SIMINT_DBLTYPE F_x = SIMINT_MUL(R2, alpha);


                    const SIMINT_DBLTYPE Q_prefac = mask_load(nlane, Q.prefac + j);


                    boys_F_split(PRIM_INT__s_s_s_s, F_x, 10);
                    SIMINT_DBLTYPE prefac = SIMINT_SQRT(one_over_PQalpha_sum);
                    prefac = SIMINT_MUL(SIMINT_MUL(P_prefac, Q_prefac), prefac);
                    for(n = 0; n <= 10; n++)
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
                    const SIMINT_DBLTYPE vrr_const_4_over_2q = SIMINT_MUL(const_4, one_over_2q);
                    const SIMINT_DBLTYPE vrr_const_1_over_2pq = one_over_2pq;
                    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(const_2, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_3_over_2pq = SIMINT_MUL(const_3, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_4_over_2pq = SIMINT_MUL(const_4, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_5_over_2pq = SIMINT_MUL(const_5, one_over_2pq);



                    // Forming PRIM_INT__s_p_s_s[10 * 3];
                    for(n = 0; n < 10; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_p_s_s[n * 3 + 0] = SIMINT_MUL(P_PB[0], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_p_s_s[n * 3 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_s_s[n * 3 + 0]);

                        PRIM_INT__s_p_s_s[n * 3 + 1] = SIMINT_MUL(P_PB[1], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_p_s_s[n * 3 + 1] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_s_s[n * 3 + 1]);

                        PRIM_INT__s_p_s_s[n * 3 + 2] = SIMINT_MUL(P_PB[2], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_p_s_s[n * 3 + 2] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_s_s[n * 3 + 2]);

                    }



                    // Forming PRIM_INT__s_d_s_s[9 * 6];
                    for(n = 0; n < 9; ++n)  // loop over orders of auxiliary function
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



                    // Forming PRIM_INT__s_f_s_s[8 * 10];
                    for(n = 0; n < 8; ++n)  // loop over orders of auxiliary function
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



                    // Forming PRIM_INT__s_f_s_p[5 * 30];
                    for(n = 0; n < 5; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_f_s_p[n * 30 + 0] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_f_s_s[n * 10 + 0]);
                        PRIM_INT__s_f_s_p[n * 30 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 0], PRIM_INT__s_f_s_p[n * 30 + 0]);
                        PRIM_INT__s_f_s_p[n * 30 + 0] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_f_s_p[n * 30 + 0]);

                        PRIM_INT__s_f_s_p[n * 30 + 1] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_f_s_s[n * 10 + 0]);
                        PRIM_INT__s_f_s_p[n * 30 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 0], PRIM_INT__s_f_s_p[n * 30 + 1]);

                        PRIM_INT__s_f_s_p[n * 30 + 2] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_f_s_s[n * 10 + 0]);
                        PRIM_INT__s_f_s_p[n * 30 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 0], PRIM_INT__s_f_s_p[n * 30 + 2]);

                        PRIM_INT__s_f_s_p[n * 30 + 3] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_f_s_s[n * 10 + 1]);
                        PRIM_INT__s_f_s_p[n * 30 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 1], PRIM_INT__s_f_s_p[n * 30 + 3]);
                        PRIM_INT__s_f_s_p[n * 30 + 3] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_f_s_p[n * 30 + 3]);

                        PRIM_INT__s_f_s_p[n * 30 + 4] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_f_s_s[n * 10 + 1]);
                        PRIM_INT__s_f_s_p[n * 30 + 4] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 1], PRIM_INT__s_f_s_p[n * 30 + 4]);
                        PRIM_INT__s_f_s_p[n * 30 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_f_s_p[n * 30 + 4]);

                        PRIM_INT__s_f_s_p[n * 30 + 5] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_f_s_s[n * 10 + 1]);
                        PRIM_INT__s_f_s_p[n * 30 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 1], PRIM_INT__s_f_s_p[n * 30 + 5]);

                        PRIM_INT__s_f_s_p[n * 30 + 6] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_f_s_s[n * 10 + 2]);
                        PRIM_INT__s_f_s_p[n * 30 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 2], PRIM_INT__s_f_s_p[n * 30 + 6]);
                        PRIM_INT__s_f_s_p[n * 30 + 6] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_f_s_p[n * 30 + 6]);

                        PRIM_INT__s_f_s_p[n * 30 + 7] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_f_s_s[n * 10 + 2]);
                        PRIM_INT__s_f_s_p[n * 30 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 2], PRIM_INT__s_f_s_p[n * 30 + 7]);

                        PRIM_INT__s_f_s_p[n * 30 + 8] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_f_s_s[n * 10 + 2]);
                        PRIM_INT__s_f_s_p[n * 30 + 8] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 2], PRIM_INT__s_f_s_p[n * 30 + 8]);
                        PRIM_INT__s_f_s_p[n * 30 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_f_s_p[n * 30 + 8]);

                        PRIM_INT__s_f_s_p[n * 30 + 9] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_f_s_s[n * 10 + 3]);
                        PRIM_INT__s_f_s_p[n * 30 + 9] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 3], PRIM_INT__s_f_s_p[n * 30 + 9]);
                        PRIM_INT__s_f_s_p[n * 30 + 9] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_f_s_p[n * 30 + 9]);

                        PRIM_INT__s_f_s_p[n * 30 + 10] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_f_s_s[n * 10 + 3]);
                        PRIM_INT__s_f_s_p[n * 30 + 10] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 3], PRIM_INT__s_f_s_p[n * 30 + 10]);
                        PRIM_INT__s_f_s_p[n * 30 + 10] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_f_s_p[n * 30 + 10]);

                        PRIM_INT__s_f_s_p[n * 30 + 11] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_f_s_s[n * 10 + 3]);
                        PRIM_INT__s_f_s_p[n * 30 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 3], PRIM_INT__s_f_s_p[n * 30 + 11]);

                        PRIM_INT__s_f_s_p[n * 30 + 12] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_f_s_s[n * 10 + 4]);
                        PRIM_INT__s_f_s_p[n * 30 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 4], PRIM_INT__s_f_s_p[n * 30 + 12]);
                        PRIM_INT__s_f_s_p[n * 30 + 12] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_f_s_p[n * 30 + 12]);

                        PRIM_INT__s_f_s_p[n * 30 + 13] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_f_s_s[n * 10 + 4]);
                        PRIM_INT__s_f_s_p[n * 30 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 4], PRIM_INT__s_f_s_p[n * 30 + 13]);
                        PRIM_INT__s_f_s_p[n * 30 + 13] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_f_s_p[n * 30 + 13]);

                        PRIM_INT__s_f_s_p[n * 30 + 14] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_f_s_s[n * 10 + 4]);
                        PRIM_INT__s_f_s_p[n * 30 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 4], PRIM_INT__s_f_s_p[n * 30 + 14]);
                        PRIM_INT__s_f_s_p[n * 30 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_f_s_p[n * 30 + 14]);

                        PRIM_INT__s_f_s_p[n * 30 + 15] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_f_s_s[n * 10 + 5]);
                        PRIM_INT__s_f_s_p[n * 30 + 15] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 5], PRIM_INT__s_f_s_p[n * 30 + 15]);
                        PRIM_INT__s_f_s_p[n * 30 + 15] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_f_s_p[n * 30 + 15]);

                        PRIM_INT__s_f_s_p[n * 30 + 16] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_f_s_s[n * 10 + 5]);
                        PRIM_INT__s_f_s_p[n * 30 + 16] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 5], PRIM_INT__s_f_s_p[n * 30 + 16]);

                        PRIM_INT__s_f_s_p[n * 30 + 17] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_f_s_s[n * 10 + 5]);
                        PRIM_INT__s_f_s_p[n * 30 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 5], PRIM_INT__s_f_s_p[n * 30 + 17]);
                        PRIM_INT__s_f_s_p[n * 30 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_f_s_p[n * 30 + 17]);

                        PRIM_INT__s_f_s_p[n * 30 + 18] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_f_s_s[n * 10 + 6]);
                        PRIM_INT__s_f_s_p[n * 30 + 18] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 6], PRIM_INT__s_f_s_p[n * 30 + 18]);

                        PRIM_INT__s_f_s_p[n * 30 + 19] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_f_s_s[n * 10 + 6]);
                        PRIM_INT__s_f_s_p[n * 30 + 19] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 6], PRIM_INT__s_f_s_p[n * 30 + 19]);
                        PRIM_INT__s_f_s_p[n * 30 + 19] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_f_s_p[n * 30 + 19]);

                        PRIM_INT__s_f_s_p[n * 30 + 20] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_f_s_s[n * 10 + 6]);
                        PRIM_INT__s_f_s_p[n * 30 + 20] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 6], PRIM_INT__s_f_s_p[n * 30 + 20]);

                        PRIM_INT__s_f_s_p[n * 30 + 21] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_f_s_s[n * 10 + 7]);
                        PRIM_INT__s_f_s_p[n * 30 + 21] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 7], PRIM_INT__s_f_s_p[n * 30 + 21]);

                        PRIM_INT__s_f_s_p[n * 30 + 22] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_f_s_s[n * 10 + 7]);
                        PRIM_INT__s_f_s_p[n * 30 + 22] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 7], PRIM_INT__s_f_s_p[n * 30 + 22]);
                        PRIM_INT__s_f_s_p[n * 30 + 22] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_f_s_p[n * 30 + 22]);

                        PRIM_INT__s_f_s_p[n * 30 + 23] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_f_s_s[n * 10 + 7]);
                        PRIM_INT__s_f_s_p[n * 30 + 23] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 7], PRIM_INT__s_f_s_p[n * 30 + 23]);
                        PRIM_INT__s_f_s_p[n * 30 + 23] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_f_s_p[n * 30 + 23]);

                        PRIM_INT__s_f_s_p[n * 30 + 24] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_f_s_s[n * 10 + 8]);
                        PRIM_INT__s_f_s_p[n * 30 + 24] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 8], PRIM_INT__s_f_s_p[n * 30 + 24]);

                        PRIM_INT__s_f_s_p[n * 30 + 25] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_f_s_s[n * 10 + 8]);
                        PRIM_INT__s_f_s_p[n * 30 + 25] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 8], PRIM_INT__s_f_s_p[n * 30 + 25]);
                        PRIM_INT__s_f_s_p[n * 30 + 25] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_f_s_p[n * 30 + 25]);

                        PRIM_INT__s_f_s_p[n * 30 + 26] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_f_s_s[n * 10 + 8]);
                        PRIM_INT__s_f_s_p[n * 30 + 26] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 8], PRIM_INT__s_f_s_p[n * 30 + 26]);
                        PRIM_INT__s_f_s_p[n * 30 + 26] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_f_s_p[n * 30 + 26]);

                        PRIM_INT__s_f_s_p[n * 30 + 27] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_f_s_s[n * 10 + 9]);
                        PRIM_INT__s_f_s_p[n * 30 + 27] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_f_s_s[(n+1) * 10 + 9], PRIM_INT__s_f_s_p[n * 30 + 27]);

                        PRIM_INT__s_f_s_p[n * 30 + 28] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_f_s_s[n * 10 + 9]);
                        PRIM_INT__s_f_s_p[n * 30 + 28] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_f_s_s[(n+1) * 10 + 9], PRIM_INT__s_f_s_p[n * 30 + 28]);

                        PRIM_INT__s_f_s_p[n * 30 + 29] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_f_s_s[n * 10 + 9]);
                        PRIM_INT__s_f_s_p[n * 30 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_f_s_s[(n+1) * 10 + 9], PRIM_INT__s_f_s_p[n * 30 + 29]);
                        PRIM_INT__s_f_s_p[n * 30 + 29] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_f_s_p[n * 30 + 29]);

                    }



                    // Forming PRIM_INT__s_d_s_p[5 * 18];
                    for(n = 0; n < 5; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_d_s_p[n * 18 + 0] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_d_s_s[n * 6 + 0]);
                        PRIM_INT__s_d_s_p[n * 18 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_s_p[n * 18 + 0]);
                        PRIM_INT__s_d_s_p[n * 18 + 0] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_d_s_p[n * 18 + 0]);

                        PRIM_INT__s_d_s_p[n * 18 + 1] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_s[n * 6 + 0]);
                        PRIM_INT__s_d_s_p[n * 18 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_s_p[n * 18 + 1]);

                        PRIM_INT__s_d_s_p[n * 18 + 2] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_d_s_s[n * 6 + 0]);
                        PRIM_INT__s_d_s_p[n * 18 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_s_p[n * 18 + 2]);

                        PRIM_INT__s_d_s_p[n * 18 + 3] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_d_s_s[n * 6 + 1]);
                        PRIM_INT__s_d_s_p[n * 18 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_d_s_p[n * 18 + 3]);
                        PRIM_INT__s_d_s_p[n * 18 + 3] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_d_s_p[n * 18 + 3]);

                        PRIM_INT__s_d_s_p[n * 18 + 4] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_s[n * 6 + 1]);
                        PRIM_INT__s_d_s_p[n * 18 + 4] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_d_s_p[n * 18 + 4]);
                        PRIM_INT__s_d_s_p[n * 18 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_d_s_p[n * 18 + 4]);

                        PRIM_INT__s_d_s_p[n * 18 + 5] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_d_s_s[n * 6 + 1]);
                        PRIM_INT__s_d_s_p[n * 18 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_d_s_p[n * 18 + 5]);

                        PRIM_INT__s_d_s_p[n * 18 + 6] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_d_s_s[n * 6 + 2]);
                        PRIM_INT__s_d_s_p[n * 18 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_d_s_p[n * 18 + 6]);
                        PRIM_INT__s_d_s_p[n * 18 + 6] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_d_s_p[n * 18 + 6]);

                        PRIM_INT__s_d_s_p[n * 18 + 7] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_s[n * 6 + 2]);
                        PRIM_INT__s_d_s_p[n * 18 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_d_s_p[n * 18 + 7]);

                        PRIM_INT__s_d_s_p[n * 18 + 8] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_d_s_s[n * 6 + 2]);
                        PRIM_INT__s_d_s_p[n * 18 + 8] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_d_s_p[n * 18 + 8]);
                        PRIM_INT__s_d_s_p[n * 18 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_d_s_p[n * 18 + 8]);

                        PRIM_INT__s_d_s_p[n * 18 + 9] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_d_s_s[n * 6 + 3]);
                        PRIM_INT__s_d_s_p[n * 18 + 9] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_s_p[n * 18 + 9]);

                        PRIM_INT__s_d_s_p[n * 18 + 10] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_s[n * 6 + 3]);
                        PRIM_INT__s_d_s_p[n * 18 + 10] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_s_p[n * 18 + 10]);
                        PRIM_INT__s_d_s_p[n * 18 + 10] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_d_s_p[n * 18 + 10]);

                        PRIM_INT__s_d_s_p[n * 18 + 11] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_d_s_s[n * 6 + 3]);
                        PRIM_INT__s_d_s_p[n * 18 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_s_p[n * 18 + 11]);

                        PRIM_INT__s_d_s_p[n * 18 + 12] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_d_s_s[n * 6 + 4]);
                        PRIM_INT__s_d_s_p[n * 18 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_d_s_p[n * 18 + 12]);

                        PRIM_INT__s_d_s_p[n * 18 + 13] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_s[n * 6 + 4]);
                        PRIM_INT__s_d_s_p[n * 18 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_d_s_p[n * 18 + 13]);
                        PRIM_INT__s_d_s_p[n * 18 + 13] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_d_s_p[n * 18 + 13]);

                        PRIM_INT__s_d_s_p[n * 18 + 14] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_d_s_s[n * 6 + 4]);
                        PRIM_INT__s_d_s_p[n * 18 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_d_s_p[n * 18 + 14]);
                        PRIM_INT__s_d_s_p[n * 18 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_d_s_p[n * 18 + 14]);

                        PRIM_INT__s_d_s_p[n * 18 + 15] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_d_s_s[n * 6 + 5]);
                        PRIM_INT__s_d_s_p[n * 18 + 15] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_s_p[n * 18 + 15]);

                        PRIM_INT__s_d_s_p[n * 18 + 16] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_s[n * 6 + 5]);
                        PRIM_INT__s_d_s_p[n * 18 + 16] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_s_p[n * 18 + 16]);

                        PRIM_INT__s_d_s_p[n * 18 + 17] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_d_s_s[n * 6 + 5]);
                        PRIM_INT__s_d_s_p[n * 18 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_s_p[n * 18 + 17]);
                        PRIM_INT__s_d_s_p[n * 18 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_d_s_p[n * 18 + 17]);

                    }


                    VRR_L_s_f_s_d(
                            PRIM_INT__s_f_s_d,
                            PRIM_INT__s_f_s_p,
                            PRIM_INT__s_f_s_s,
                            PRIM_INT__s_d_s_p,
                            Q_PB,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            4);



                    // Forming PRIM_INT__s_p_s_p[5 * 9];
                    for(n = 0; n < 5; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_p_s_p[n * 9 + 0] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_p_s_s[n * 3 + 0]);
                        PRIM_INT__s_p_s_p[n * 9 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_s_p[n * 9 + 0]);
                        PRIM_INT__s_p_s_p[n * 9 + 0] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_s_p[n * 9 + 0]);

                        PRIM_INT__s_p_s_p[n * 9 + 1] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_p_s_s[n * 3 + 0]);
                        PRIM_INT__s_p_s_p[n * 9 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_s_p[n * 9 + 1]);

                        PRIM_INT__s_p_s_p[n * 9 + 2] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_s[n * 3 + 0]);
                        PRIM_INT__s_p_s_p[n * 9 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_s_p[n * 9 + 2]);

                        PRIM_INT__s_p_s_p[n * 9 + 3] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_p_s_s[n * 3 + 1]);
                        PRIM_INT__s_p_s_p[n * 9 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_s_p[n * 9 + 3]);

                        PRIM_INT__s_p_s_p[n * 9 + 4] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_p_s_s[n * 3 + 1]);
                        PRIM_INT__s_p_s_p[n * 9 + 4] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_s_p[n * 9 + 4]);
                        PRIM_INT__s_p_s_p[n * 9 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_s_p[n * 9 + 4]);

                        PRIM_INT__s_p_s_p[n * 9 + 5] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_s[n * 3 + 1]);
                        PRIM_INT__s_p_s_p[n * 9 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_s_p[n * 9 + 5]);

                        PRIM_INT__s_p_s_p[n * 9 + 6] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_p_s_s[n * 3 + 2]);
                        PRIM_INT__s_p_s_p[n * 9 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_s_p[n * 9 + 6]);

                        PRIM_INT__s_p_s_p[n * 9 + 7] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_p_s_s[n * 3 + 2]);
                        PRIM_INT__s_p_s_p[n * 9 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_s_p[n * 9 + 7]);

                        PRIM_INT__s_p_s_p[n * 9 + 8] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_s[n * 3 + 2]);
                        PRIM_INT__s_p_s_p[n * 9 + 8] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_s_p[n * 9 + 8]);
                        PRIM_INT__s_p_s_p[n * 9 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_p_s_p[n * 9 + 8]);

                    }



                    // Forming PRIM_INT__s_d_s_d[4 * 36];
                    for(n = 0; n < 4; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_d_s_d[n * 36 + 0] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_d_s_p[n * 18 + 0]);
                        PRIM_INT__s_d_s_d[n * 36 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_p[(n+1) * 18 + 0], PRIM_INT__s_d_s_d[n * 36 + 0]);
                        PRIM_INT__s_d_s_d[n * 36 + 0] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_s_s[n * 6 + 0]), PRIM_INT__s_d_s_d[n * 36 + 0]);
                        PRIM_INT__s_d_s_d[n * 36 + 0] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_s_p[(n+1) * 9 + 0], PRIM_INT__s_d_s_d[n * 36 + 0]);

                        PRIM_INT__s_d_s_d[n * 36 + 1] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_p[n * 18 + 0]);
                        PRIM_INT__s_d_s_d[n * 36 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_p[(n+1) * 18 + 0], PRIM_INT__s_d_s_d[n * 36 + 1]);

                        PRIM_INT__s_d_s_d[n * 36 + 3] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_p[n * 18 + 1]);
                        PRIM_INT__s_d_s_d[n * 36 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_p[(n+1) * 18 + 1], PRIM_INT__s_d_s_d[n * 36 + 3]);
                        PRIM_INT__s_d_s_d[n * 36 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_s_s[n * 6 + 0]), PRIM_INT__s_d_s_d[n * 36 + 3]);

                        PRIM_INT__s_d_s_d[n * 36 + 5] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_d_s_p[n * 18 + 2]);
                        PRIM_INT__s_d_s_d[n * 36 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_p[(n+1) * 18 + 2], PRIM_INT__s_d_s_d[n * 36 + 5]);
                        PRIM_INT__s_d_s_d[n * 36 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 0], PRIM_INT__s_d_s_s[n * 6 + 0]), PRIM_INT__s_d_s_d[n * 36 + 5]);

                        PRIM_INT__s_d_s_d[n * 36 + 6] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_d_s_p[n * 18 + 3]);
                        PRIM_INT__s_d_s_d[n * 36 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_p[(n+1) * 18 + 3], PRIM_INT__s_d_s_d[n * 36 + 6]);
                        PRIM_INT__s_d_s_d[n * 36 + 6] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_d_s_s[n * 6 + 1]), PRIM_INT__s_d_s_d[n * 36 + 6]);
                        PRIM_INT__s_d_s_d[n * 36 + 6] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_p[(n+1) * 9 + 3], PRIM_INT__s_d_s_d[n * 36 + 6]);

                        PRIM_INT__s_d_s_d[n * 36 + 7] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_p[n * 18 + 3]);
                        PRIM_INT__s_d_s_d[n * 36 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_p[(n+1) * 18 + 3], PRIM_INT__s_d_s_d[n * 36 + 7]);
                        PRIM_INT__s_d_s_d[n * 36 + 7] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_p[(n+1) * 9 + 0], PRIM_INT__s_d_s_d[n * 36 + 7]);

                        PRIM_INT__s_d_s_d[n * 36 + 9] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_p[n * 18 + 4]);
                        PRIM_INT__s_d_s_d[n * 36 + 9] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_p[(n+1) * 18 + 4], PRIM_INT__s_d_s_d[n * 36 + 9]);
                        PRIM_INT__s_d_s_d[n * 36 + 9] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_d_s_s[n * 6 + 1]), PRIM_INT__s_d_s_d[n * 36 + 9]);
                        PRIM_INT__s_d_s_d[n * 36 + 9] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_p[(n+1) * 9 + 1], PRIM_INT__s_d_s_d[n * 36 + 9]);

                        PRIM_INT__s_d_s_d[n * 36 + 11] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_d_s_p[n * 18 + 5]);
                        PRIM_INT__s_d_s_d[n * 36 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_p[(n+1) * 18 + 5], PRIM_INT__s_d_s_d[n * 36 + 11]);
                        PRIM_INT__s_d_s_d[n * 36 + 11] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 1], PRIM_INT__s_d_s_s[n * 6 + 1]), PRIM_INT__s_d_s_d[n * 36 + 11]);

                        PRIM_INT__s_d_s_d[n * 36 + 12] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_d_s_p[n * 18 + 6]);
                        PRIM_INT__s_d_s_d[n * 36 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_p[(n+1) * 18 + 6], PRIM_INT__s_d_s_d[n * 36 + 12]);
                        PRIM_INT__s_d_s_d[n * 36 + 12] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_d_s_s[n * 6 + 2]), PRIM_INT__s_d_s_d[n * 36 + 12]);
                        PRIM_INT__s_d_s_d[n * 36 + 12] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_p[(n+1) * 9 + 6], PRIM_INT__s_d_s_d[n * 36 + 12]);

                        PRIM_INT__s_d_s_d[n * 36 + 13] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_p[n * 18 + 6]);
                        PRIM_INT__s_d_s_d[n * 36 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_p[(n+1) * 18 + 6], PRIM_INT__s_d_s_d[n * 36 + 13]);

                        PRIM_INT__s_d_s_d[n * 36 + 15] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_p[n * 18 + 7]);
                        PRIM_INT__s_d_s_d[n * 36 + 15] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_p[(n+1) * 18 + 7], PRIM_INT__s_d_s_d[n * 36 + 15]);
                        PRIM_INT__s_d_s_d[n * 36 + 15] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_d_s_s[n * 6 + 2]), PRIM_INT__s_d_s_d[n * 36 + 15]);

                        PRIM_INT__s_d_s_d[n * 36 + 17] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_d_s_p[n * 18 + 8]);
                        PRIM_INT__s_d_s_d[n * 36 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_p[(n+1) * 18 + 8], PRIM_INT__s_d_s_d[n * 36 + 17]);
                        PRIM_INT__s_d_s_d[n * 36 + 17] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 2], PRIM_INT__s_d_s_s[n * 6 + 2]), PRIM_INT__s_d_s_d[n * 36 + 17]);
                        PRIM_INT__s_d_s_d[n * 36 + 17] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_p[(n+1) * 9 + 2], PRIM_INT__s_d_s_d[n * 36 + 17]);

                        PRIM_INT__s_d_s_d[n * 36 + 18] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_d_s_p[n * 18 + 9]);
                        PRIM_INT__s_d_s_d[n * 36 + 18] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_p[(n+1) * 18 + 9], PRIM_INT__s_d_s_d[n * 36 + 18]);
                        PRIM_INT__s_d_s_d[n * 36 + 18] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_s_s[n * 6 + 3]), PRIM_INT__s_d_s_d[n * 36 + 18]);

                        PRIM_INT__s_d_s_d[n * 36 + 19] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_p[n * 18 + 9]);
                        PRIM_INT__s_d_s_d[n * 36 + 19] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_p[(n+1) * 18 + 9], PRIM_INT__s_d_s_d[n * 36 + 19]);
                        PRIM_INT__s_d_s_d[n * 36 + 19] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_s_p[(n+1) * 9 + 3], PRIM_INT__s_d_s_d[n * 36 + 19]);

                        PRIM_INT__s_d_s_d[n * 36 + 21] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_p[n * 18 + 10]);
                        PRIM_INT__s_d_s_d[n * 36 + 21] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_p[(n+1) * 18 + 10], PRIM_INT__s_d_s_d[n * 36 + 21]);
                        PRIM_INT__s_d_s_d[n * 36 + 21] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_s_s[n * 6 + 3]), PRIM_INT__s_d_s_d[n * 36 + 21]);
                        PRIM_INT__s_d_s_d[n * 36 + 21] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_s_p[(n+1) * 9 + 4], PRIM_INT__s_d_s_d[n * 36 + 21]);

                        PRIM_INT__s_d_s_d[n * 36 + 23] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_d_s_p[n * 18 + 11]);
                        PRIM_INT__s_d_s_d[n * 36 + 23] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_p[(n+1) * 18 + 11], PRIM_INT__s_d_s_d[n * 36 + 23]);
                        PRIM_INT__s_d_s_d[n * 36 + 23] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 3], PRIM_INT__s_d_s_s[n * 6 + 3]), PRIM_INT__s_d_s_d[n * 36 + 23]);

                        PRIM_INT__s_d_s_d[n * 36 + 24] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_d_s_p[n * 18 + 12]);
                        PRIM_INT__s_d_s_d[n * 36 + 24] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_p[(n+1) * 18 + 12], PRIM_INT__s_d_s_d[n * 36 + 24]);
                        PRIM_INT__s_d_s_d[n * 36 + 24] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_d_s_s[n * 6 + 4]), PRIM_INT__s_d_s_d[n * 36 + 24]);

                        PRIM_INT__s_d_s_d[n * 36 + 25] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_p[n * 18 + 12]);
                        PRIM_INT__s_d_s_d[n * 36 + 25] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_p[(n+1) * 18 + 12], PRIM_INT__s_d_s_d[n * 36 + 25]);
                        PRIM_INT__s_d_s_d[n * 36 + 25] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_p[(n+1) * 9 + 6], PRIM_INT__s_d_s_d[n * 36 + 25]);

                        PRIM_INT__s_d_s_d[n * 36 + 27] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_p[n * 18 + 13]);
                        PRIM_INT__s_d_s_d[n * 36 + 27] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_p[(n+1) * 18 + 13], PRIM_INT__s_d_s_d[n * 36 + 27]);
                        PRIM_INT__s_d_s_d[n * 36 + 27] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_d_s_s[n * 6 + 4]), PRIM_INT__s_d_s_d[n * 36 + 27]);
                        PRIM_INT__s_d_s_d[n * 36 + 27] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_p[(n+1) * 9 + 7], PRIM_INT__s_d_s_d[n * 36 + 27]);

                        PRIM_INT__s_d_s_d[n * 36 + 29] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_d_s_p[n * 18 + 14]);
                        PRIM_INT__s_d_s_d[n * 36 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_p[(n+1) * 18 + 14], PRIM_INT__s_d_s_d[n * 36 + 29]);
                        PRIM_INT__s_d_s_d[n * 36 + 29] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 4], PRIM_INT__s_d_s_s[n * 6 + 4]), PRIM_INT__s_d_s_d[n * 36 + 29]);
                        PRIM_INT__s_d_s_d[n * 36 + 29] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_p_s_p[(n+1) * 9 + 5], PRIM_INT__s_d_s_d[n * 36 + 29]);

                        PRIM_INT__s_d_s_d[n * 36 + 30] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_d_s_p[n * 18 + 15]);
                        PRIM_INT__s_d_s_d[n * 36 + 30] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_d_s_p[(n+1) * 18 + 15], PRIM_INT__s_d_s_d[n * 36 + 30]);
                        PRIM_INT__s_d_s_d[n * 36 + 30] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_s_s[n * 6 + 5]), PRIM_INT__s_d_s_d[n * 36 + 30]);

                        PRIM_INT__s_d_s_d[n * 36 + 31] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_p[n * 18 + 15]);
                        PRIM_INT__s_d_s_d[n * 36 + 31] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_p[(n+1) * 18 + 15], PRIM_INT__s_d_s_d[n * 36 + 31]);

                        PRIM_INT__s_d_s_d[n * 36 + 33] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_d_s_p[n * 18 + 16]);
                        PRIM_INT__s_d_s_d[n * 36 + 33] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_d_s_p[(n+1) * 18 + 16], PRIM_INT__s_d_s_d[n * 36 + 33]);
                        PRIM_INT__s_d_s_d[n * 36 + 33] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_s_s[n * 6 + 5]), PRIM_INT__s_d_s_d[n * 36 + 33]);

                        PRIM_INT__s_d_s_d[n * 36 + 35] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_d_s_p[n * 18 + 17]);
                        PRIM_INT__s_d_s_d[n * 36 + 35] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_d_s_p[(n+1) * 18 + 17], PRIM_INT__s_d_s_d[n * 36 + 35]);
                        PRIM_INT__s_d_s_d[n * 36 + 35] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_d_s_s[(n+1) * 6 + 5], PRIM_INT__s_d_s_s[n * 6 + 5]), PRIM_INT__s_d_s_d[n * 36 + 35]);
                        PRIM_INT__s_d_s_d[n * 36 + 35] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_p_s_p[(n+1) * 9 + 8], PRIM_INT__s_d_s_d[n * 36 + 35]);

                    }


                    VRR_L_s_f_s_f(
                            PRIM_INT__s_f_s_f,
                            PRIM_INT__s_f_s_d,
                            PRIM_INT__s_f_s_p,
                            PRIM_INT__s_d_s_d,
                            Q_PB,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            3);



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



                    // Forming PRIM_INT__s_p_s_d[4 * 18];
                    for(n = 0; n < 4; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_p_s_d[n * 18 + 0] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_p_s_p[n * 9 + 0]);
                        PRIM_INT__s_p_s_d[n * 18 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_s_p[(n+1) * 9 + 0], PRIM_INT__s_p_s_d[n * 18 + 0]);
                        PRIM_INT__s_p_s_d[n * 18 + 0] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_s_s[n * 3 + 0]), PRIM_INT__s_p_s_d[n * 18 + 0]);
                        PRIM_INT__s_p_s_d[n * 18 + 0] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_p[(n+1) * 3 + 0], PRIM_INT__s_p_s_d[n * 18 + 0]);

                        PRIM_INT__s_p_s_d[n * 18 + 3] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_p_s_p[n * 9 + 1]);
                        PRIM_INT__s_p_s_d[n * 18 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_p[(n+1) * 9 + 1], PRIM_INT__s_p_s_d[n * 18 + 3]);
                        PRIM_INT__s_p_s_d[n * 18 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_s_s[n * 3 + 0]), PRIM_INT__s_p_s_d[n * 18 + 3]);

                        PRIM_INT__s_p_s_d[n * 18 + 5] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_p[n * 9 + 2]);
                        PRIM_INT__s_p_s_d[n * 18 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_p[(n+1) * 9 + 2], PRIM_INT__s_p_s_d[n * 18 + 5]);
                        PRIM_INT__s_p_s_d[n * 18 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 0], PRIM_INT__s_p_s_s[n * 3 + 0]), PRIM_INT__s_p_s_d[n * 18 + 5]);

                        PRIM_INT__s_p_s_d[n * 18 + 6] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_p_s_p[n * 9 + 3]);
                        PRIM_INT__s_p_s_d[n * 18 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_s_p[(n+1) * 9 + 3], PRIM_INT__s_p_s_d[n * 18 + 6]);
                        PRIM_INT__s_p_s_d[n * 18 + 6] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_s_s[n * 3 + 1]), PRIM_INT__s_p_s_d[n * 18 + 6]);

                        PRIM_INT__s_p_s_d[n * 18 + 9] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_p_s_p[n * 9 + 4]);
                        PRIM_INT__s_p_s_d[n * 18 + 9] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_p[(n+1) * 9 + 4], PRIM_INT__s_p_s_d[n * 18 + 9]);
                        PRIM_INT__s_p_s_d[n * 18 + 9] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_s_s[n * 3 + 1]), PRIM_INT__s_p_s_d[n * 18 + 9]);
                        PRIM_INT__s_p_s_d[n * 18 + 9] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_p[(n+1) * 3 + 1], PRIM_INT__s_p_s_d[n * 18 + 9]);

                        PRIM_INT__s_p_s_d[n * 18 + 11] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_p[n * 9 + 5]);
                        PRIM_INT__s_p_s_d[n * 18 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_p[(n+1) * 9 + 5], PRIM_INT__s_p_s_d[n * 18 + 11]);
                        PRIM_INT__s_p_s_d[n * 18 + 11] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 1], PRIM_INT__s_p_s_s[n * 3 + 1]), PRIM_INT__s_p_s_d[n * 18 + 11]);

                        PRIM_INT__s_p_s_d[n * 18 + 12] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_p_s_p[n * 9 + 6]);
                        PRIM_INT__s_p_s_d[n * 18 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_s_p[(n+1) * 9 + 6], PRIM_INT__s_p_s_d[n * 18 + 12]);
                        PRIM_INT__s_p_s_d[n * 18 + 12] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_s_s[n * 3 + 2]), PRIM_INT__s_p_s_d[n * 18 + 12]);

                        PRIM_INT__s_p_s_d[n * 18 + 15] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_p_s_p[n * 9 + 7]);
                        PRIM_INT__s_p_s_d[n * 18 + 15] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_p[(n+1) * 9 + 7], PRIM_INT__s_p_s_d[n * 18 + 15]);
                        PRIM_INT__s_p_s_d[n * 18 + 15] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_s_s[n * 3 + 2]), PRIM_INT__s_p_s_d[n * 18 + 15]);

                        PRIM_INT__s_p_s_d[n * 18 + 17] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_p[n * 9 + 8]);
                        PRIM_INT__s_p_s_d[n * 18 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_p[(n+1) * 9 + 8], PRIM_INT__s_p_s_d[n * 18 + 17]);
                        PRIM_INT__s_p_s_d[n * 18 + 17] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_s[(n+1) * 3 + 2], PRIM_INT__s_p_s_s[n * 3 + 2]), PRIM_INT__s_p_s_d[n * 18 + 17]);
                        PRIM_INT__s_p_s_d[n * 18 + 17] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_p[(n+1) * 3 + 2], PRIM_INT__s_p_s_d[n * 18 + 17]);

                    }


                    VRR_L_s_d_s_f(
                            PRIM_INT__s_d_s_f,
                            PRIM_INT__s_d_s_d,
                            PRIM_INT__s_d_s_p,
                            PRIM_INT__s_p_s_d,
                            Q_PB,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            3);


                    VRR_L_s_f_s_g(
                            PRIM_INT__s_f_s_g,
                            PRIM_INT__s_f_s_f,
                            PRIM_INT__s_f_s_d,
                            PRIM_INT__s_d_s_f,
                            Q_PB,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            2);



                    // Forming PRIM_INT__s_g_s_s[7 * 15];
                    for(n = 0; n < 7; ++n)  // loop over orders of auxiliary function
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


                    VRR_L_s_g_s_p(
                            PRIM_INT__s_g_s_p,
                            PRIM_INT__s_g_s_s,
                            PRIM_INT__s_f_s_s,
                            Q_PB,
                            aoq_PQ,
                            one_over_2pq,
                            5);


                    VRR_L_s_g_s_d(
                            PRIM_INT__s_g_s_d,
                            PRIM_INT__s_g_s_p,
                            PRIM_INT__s_g_s_s,
                            PRIM_INT__s_f_s_p,
                            Q_PB,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            4);


                    VRR_L_s_g_s_f(
                            PRIM_INT__s_g_s_f,
                            PRIM_INT__s_g_s_d,
                            PRIM_INT__s_g_s_p,
                            PRIM_INT__s_f_s_d,
                            Q_PB,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            3);



                    // Forming PRIM_INT__s_s_s_d[4 * 6];
                    for(n = 0; n < 4; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_s_d[n * 6 + 0] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_s_s_p[n * 3 + 0]);
                        PRIM_INT__s_s_s_d[n * 6 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_p[(n+1) * 3 + 0], PRIM_INT__s_s_s_d[n * 6 + 0]);
                        PRIM_INT__s_s_s_d[n * 6 + 0] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_s_s_d[n * 6 + 0]);

                        PRIM_INT__s_s_s_d[n * 6 + 3] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_s_s_p[n * 3 + 1]);
                        PRIM_INT__s_s_s_d[n * 6 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_p[(n+1) * 3 + 1], PRIM_INT__s_s_s_d[n * 6 + 3]);
                        PRIM_INT__s_s_s_d[n * 6 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_s_s_d[n * 6 + 3]);

                        PRIM_INT__s_s_s_d[n * 6 + 5] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_s_s_p[n * 3 + 2]);
                        PRIM_INT__s_s_s_d[n * 6 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_p[(n+1) * 3 + 2], PRIM_INT__s_s_s_d[n * 6 + 5]);
                        PRIM_INT__s_s_s_d[n * 6 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_s_s_d[n * 6 + 5]);

                    }



                    // Forming PRIM_INT__s_p_s_f[3 * 30];
                    for(n = 0; n < 3; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_p_s_f[n * 30 + 0] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_p_s_d[n * 18 + 0]);
                        PRIM_INT__s_p_s_f[n * 30 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_s_d[(n+1) * 18 + 0], PRIM_INT__s_p_s_f[n * 30 + 0]);
                        PRIM_INT__s_p_s_f[n * 30 + 0] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_p[(n+1) * 9 + 0], PRIM_INT__s_p_s_p[n * 9 + 0]), PRIM_INT__s_p_s_f[n * 30 + 0]);
                        PRIM_INT__s_p_s_f[n * 30 + 0] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__s_p_s_f[n * 30 + 0]);

                        PRIM_INT__s_p_s_f[n * 30 + 1] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_p_s_d[n * 18 + 0]);
                        PRIM_INT__s_p_s_f[n * 30 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_d[(n+1) * 18 + 0], PRIM_INT__s_p_s_f[n * 30 + 1]);

                        PRIM_INT__s_p_s_f[n * 30 + 2] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_d[n * 18 + 0]);
                        PRIM_INT__s_p_s_f[n * 30 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_d[(n+1) * 18 + 0], PRIM_INT__s_p_s_f[n * 30 + 2]);

                        PRIM_INT__s_p_s_f[n * 30 + 6] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_p_s_d[n * 18 + 3]);
                        PRIM_INT__s_p_s_f[n * 30 + 6] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_d[(n+1) * 18 + 3], PRIM_INT__s_p_s_f[n * 30 + 6]);
                        PRIM_INT__s_p_s_f[n * 30 + 6] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_p[(n+1) * 9 + 1], PRIM_INT__s_p_s_p[n * 9 + 1]), PRIM_INT__s_p_s_f[n * 30 + 6]);

                        PRIM_INT__s_p_s_f[n * 30 + 7] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_d[n * 18 + 3]);
                        PRIM_INT__s_p_s_f[n * 30 + 7] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_d[(n+1) * 18 + 3], PRIM_INT__s_p_s_f[n * 30 + 7]);

                        PRIM_INT__s_p_s_f[n * 30 + 9] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_d[n * 18 + 5]);
                        PRIM_INT__s_p_s_f[n * 30 + 9] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_d[(n+1) * 18 + 5], PRIM_INT__s_p_s_f[n * 30 + 9]);
                        PRIM_INT__s_p_s_f[n * 30 + 9] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_p[(n+1) * 9 + 2], PRIM_INT__s_p_s_p[n * 9 + 2]), PRIM_INT__s_p_s_f[n * 30 + 9]);

                        PRIM_INT__s_p_s_f[n * 30 + 10] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_p_s_d[n * 18 + 6]);
                        PRIM_INT__s_p_s_f[n * 30 + 10] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_s_d[(n+1) * 18 + 6], PRIM_INT__s_p_s_f[n * 30 + 10]);
                        PRIM_INT__s_p_s_f[n * 30 + 10] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_p[(n+1) * 9 + 3], PRIM_INT__s_p_s_p[n * 9 + 3]), PRIM_INT__s_p_s_f[n * 30 + 10]);

                        PRIM_INT__s_p_s_f[n * 30 + 11] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_p_s_d[n * 18 + 6]);
                        PRIM_INT__s_p_s_f[n * 30 + 11] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_d[(n+1) * 18 + 6], PRIM_INT__s_p_s_f[n * 30 + 11]);
                        PRIM_INT__s_p_s_f[n * 30 + 11] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__s_p_s_f[n * 30 + 11]);

                        PRIM_INT__s_p_s_f[n * 30 + 12] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_d[n * 18 + 6]);
                        PRIM_INT__s_p_s_f[n * 30 + 12] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_d[(n+1) * 18 + 6], PRIM_INT__s_p_s_f[n * 30 + 12]);

                        PRIM_INT__s_p_s_f[n * 30 + 16] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_p_s_d[n * 18 + 9]);
                        PRIM_INT__s_p_s_f[n * 30 + 16] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_d[(n+1) * 18 + 9], PRIM_INT__s_p_s_f[n * 30 + 16]);
                        PRIM_INT__s_p_s_f[n * 30 + 16] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_p[(n+1) * 9 + 4], PRIM_INT__s_p_s_p[n * 9 + 4]), PRIM_INT__s_p_s_f[n * 30 + 16]);
                        PRIM_INT__s_p_s_f[n * 30 + 16] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__s_p_s_f[n * 30 + 16]);

                        PRIM_INT__s_p_s_f[n * 30 + 17] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_d[n * 18 + 9]);
                        PRIM_INT__s_p_s_f[n * 30 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_d[(n+1) * 18 + 9], PRIM_INT__s_p_s_f[n * 30 + 17]);

                        PRIM_INT__s_p_s_f[n * 30 + 19] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_d[n * 18 + 11]);
                        PRIM_INT__s_p_s_f[n * 30 + 19] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_d[(n+1) * 18 + 11], PRIM_INT__s_p_s_f[n * 30 + 19]);
                        PRIM_INT__s_p_s_f[n * 30 + 19] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_p[(n+1) * 9 + 5], PRIM_INT__s_p_s_p[n * 9 + 5]), PRIM_INT__s_p_s_f[n * 30 + 19]);

                        PRIM_INT__s_p_s_f[n * 30 + 20] = SIMINT_MUL(Q_PB[0], PRIM_INT__s_p_s_d[n * 18 + 12]);
                        PRIM_INT__s_p_s_f[n * 30 + 20] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_p_s_d[(n+1) * 18 + 12], PRIM_INT__s_p_s_f[n * 30 + 20]);
                        PRIM_INT__s_p_s_f[n * 30 + 20] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_p[(n+1) * 9 + 6], PRIM_INT__s_p_s_p[n * 9 + 6]), PRIM_INT__s_p_s_f[n * 30 + 20]);

                        PRIM_INT__s_p_s_f[n * 30 + 21] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_p_s_d[n * 18 + 12]);
                        PRIM_INT__s_p_s_f[n * 30 + 21] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_d[(n+1) * 18 + 12], PRIM_INT__s_p_s_f[n * 30 + 21]);

                        PRIM_INT__s_p_s_f[n * 30 + 22] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_d[n * 18 + 12]);
                        PRIM_INT__s_p_s_f[n * 30 + 22] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_d[(n+1) * 18 + 12], PRIM_INT__s_p_s_f[n * 30 + 22]);
                        PRIM_INT__s_p_s_f[n * 30 + 22] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 0], PRIM_INT__s_p_s_f[n * 30 + 22]);

                        PRIM_INT__s_p_s_f[n * 30 + 26] = SIMINT_MUL(Q_PB[1], PRIM_INT__s_p_s_d[n * 18 + 15]);
                        PRIM_INT__s_p_s_f[n * 30 + 26] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_p_s_d[(n+1) * 18 + 15], PRIM_INT__s_p_s_f[n * 30 + 26]);
                        PRIM_INT__s_p_s_f[n * 30 + 26] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_p[(n+1) * 9 + 7], PRIM_INT__s_p_s_p[n * 9 + 7]), PRIM_INT__s_p_s_f[n * 30 + 26]);

                        PRIM_INT__s_p_s_f[n * 30 + 27] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_d[n * 18 + 15]);
                        PRIM_INT__s_p_s_f[n * 30 + 27] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_d[(n+1) * 18 + 15], PRIM_INT__s_p_s_f[n * 30 + 27]);
                        PRIM_INT__s_p_s_f[n * 30 + 27] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 3], PRIM_INT__s_p_s_f[n * 30 + 27]);

                        PRIM_INT__s_p_s_f[n * 30 + 29] = SIMINT_MUL(Q_PB[2], PRIM_INT__s_p_s_d[n * 18 + 17]);
                        PRIM_INT__s_p_s_f[n * 30 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_p_s_d[(n+1) * 18 + 17], PRIM_INT__s_p_s_f[n * 30 + 29]);
                        PRIM_INT__s_p_s_f[n * 30 + 29] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_p_s_p[(n+1) * 9 + 8], PRIM_INT__s_p_s_p[n * 9 + 8]), PRIM_INT__s_p_s_f[n * 30 + 29]);
                        PRIM_INT__s_p_s_f[n * 30 + 29] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_d[(n+1) * 6 + 5], PRIM_INT__s_p_s_f[n * 30 + 29]);

                    }


                    VRR_L_s_d_s_g(
                            PRIM_INT__s_d_s_g,
                            PRIM_INT__s_d_s_f,
                            PRIM_INT__s_d_s_d,
                            PRIM_INT__s_p_s_f,
                            Q_PB,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            2);


                    ostei_general_vrr_L(0, 3, 0, 5, 1,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PB,
                            PRIM_INT__s_f_s_g, NULL, PRIM_INT__s_f_s_f, NULL, PRIM_INT__s_d_s_g, PRIM_INT__s_f_s_h);


                    ostei_general_vrr_L(0, 4, 0, 4, 2,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PB,
                            PRIM_INT__s_g_s_f, NULL, PRIM_INT__s_g_s_d, NULL, PRIM_INT__s_f_s_f, PRIM_INT__s_g_s_g);


                    VRR_J_s_h_s_s(
                            PRIM_INT__s_h_s_s,
                            PRIM_INT__s_g_s_s,
                            PRIM_INT__s_f_s_s,
                            P_PB,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            6);


                    VRR_L_s_h_s_p(
                            PRIM_INT__s_h_s_p,
                            PRIM_INT__s_h_s_s,
                            PRIM_INT__s_g_s_s,
                            Q_PB,
                            aoq_PQ,
                            one_over_2pq,
                            5);


                    VRR_L_s_h_s_d(
                            PRIM_INT__s_h_s_d,
                            PRIM_INT__s_h_s_p,
                            PRIM_INT__s_h_s_s,
                            PRIM_INT__s_g_s_p,
                            Q_PB,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            4);


                    ostei_general_vrr_L(0, 5, 0, 3, 3,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PB,
                            PRIM_INT__s_h_s_d, NULL, PRIM_INT__s_h_s_p, NULL, PRIM_INT__s_g_s_d, PRIM_INT__s_h_s_f);


                    ostei_general_vrr_L(0, 4, 0, 5, 1,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PB,
                            PRIM_INT__s_g_s_g, NULL, PRIM_INT__s_g_s_f, NULL, PRIM_INT__s_f_s_g, PRIM_INT__s_g_s_h);


                    ostei_general_vrr_L(0, 5, 0, 4, 2,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PB,
                            PRIM_INT__s_h_s_f, NULL, PRIM_INT__s_h_s_d, NULL, PRIM_INT__s_g_s_f, PRIM_INT__s_h_s_g);


                    ostei_general_vrr_L(0, 5, 0, 5, 1,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PB,
                            PRIM_INT__s_h_s_g, NULL, PRIM_INT__s_h_s_f, NULL, PRIM_INT__s_g_s_g, PRIM_INT__s_h_s_h);




                    ////////////////////////////////////
                    // Accumulate contracted integrals
                    ////////////////////////////////////
                    if(lastoffset == 0)
                    {
                        contract_all(100, PRIM_INT__s_f_s_f, PRIM_PTR_INT__s_f_s_f);
                        contract_all(150, PRIM_INT__s_f_s_g, PRIM_PTR_INT__s_f_s_g);
                        contract_all(210, PRIM_INT__s_f_s_h, PRIM_PTR_INT__s_f_s_h);
                        contract_all(150, PRIM_INT__s_g_s_f, PRIM_PTR_INT__s_g_s_f);
                        contract_all(225, PRIM_INT__s_g_s_g, PRIM_PTR_INT__s_g_s_g);
                        contract_all(315, PRIM_INT__s_g_s_h, PRIM_PTR_INT__s_g_s_h);
                        contract_all(210, PRIM_INT__s_h_s_f, PRIM_PTR_INT__s_h_s_f);
                        contract_all(315, PRIM_INT__s_h_s_g, PRIM_PTR_INT__s_h_s_g);
                        contract_all(441, PRIM_INT__s_h_s_h, PRIM_PTR_INT__s_h_s_h);
                    }
                    else
                    {
                        contract(100, shelloffsets, PRIM_INT__s_f_s_f, PRIM_PTR_INT__s_f_s_f);
                        contract(150, shelloffsets, PRIM_INT__s_f_s_g, PRIM_PTR_INT__s_f_s_g);
                        contract(210, shelloffsets, PRIM_INT__s_f_s_h, PRIM_PTR_INT__s_f_s_h);
                        contract(150, shelloffsets, PRIM_INT__s_g_s_f, PRIM_PTR_INT__s_g_s_f);
                        contract(225, shelloffsets, PRIM_INT__s_g_s_g, PRIM_PTR_INT__s_g_s_g);
                        contract(315, shelloffsets, PRIM_INT__s_g_s_h, PRIM_PTR_INT__s_g_s_h);
                        contract(210, shelloffsets, PRIM_INT__s_h_s_f, PRIM_PTR_INT__s_h_s_f);
                        contract(315, shelloffsets, PRIM_INT__s_h_s_g, PRIM_PTR_INT__s_h_s_g);
                        contract(441, shelloffsets, PRIM_INT__s_h_s_h, PRIM_PTR_INT__s_h_s_h);
                        PRIM_PTR_INT__s_f_s_f += lastoffset*100;
                        PRIM_PTR_INT__s_f_s_g += lastoffset*150;
                        PRIM_PTR_INT__s_f_s_h += lastoffset*210;
                        PRIM_PTR_INT__s_g_s_f += lastoffset*150;
                        PRIM_PTR_INT__s_g_s_g += lastoffset*225;
                        PRIM_PTR_INT__s_g_s_h += lastoffset*315;
                        PRIM_PTR_INT__s_h_s_f += lastoffset*210;
                        PRIM_PTR_INT__s_h_s_g += lastoffset*315;
                        PRIM_PTR_INT__s_h_s_h += lastoffset*441;
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
                double const * restrict HRR_INT__s_f_s_f = INT__s_f_s_f + abcd * 100;
                double const * restrict HRR_INT__s_f_s_g = INT__s_f_s_g + abcd * 150;
                double const * restrict HRR_INT__s_f_s_h = INT__s_f_s_h + abcd * 210;
                double const * restrict HRR_INT__s_g_s_f = INT__s_g_s_f + abcd * 150;
                double const * restrict HRR_INT__s_g_s_g = INT__s_g_s_g + abcd * 225;
                double const * restrict HRR_INT__s_g_s_h = INT__s_g_s_h + abcd * 315;
                double const * restrict HRR_INT__s_h_s_f = INT__s_h_s_f + abcd * 210;
                double const * restrict HRR_INT__s_h_s_g = INT__s_h_s_g + abcd * 315;
                double const * restrict HRR_INT__s_h_s_h = INT__s_h_s_h + abcd * 441;
                double * restrict HRR_INT__d_f_d_f = INT__d_f_d_f + real_abcd * 3600;

                // form INT__p_f_s_f
                for(iket = 0; iket < 10; ++iket)
                {
                    HRR_INT__p_f_s_f[0 * 10 + iket] = HRR_INT__s_g_s_f[0 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_s_f[0 * 10 + iket] );

                    HRR_INT__p_f_s_f[1 * 10 + iket] = HRR_INT__s_g_s_f[1 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_s_f[1 * 10 + iket] );

                    HRR_INT__p_f_s_f[2 * 10 + iket] = HRR_INT__s_g_s_f[2 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_s_f[2 * 10 + iket] );

                    HRR_INT__p_f_s_f[3 * 10 + iket] = HRR_INT__s_g_s_f[3 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_s_f[3 * 10 + iket] );

                    HRR_INT__p_f_s_f[4 * 10 + iket] = HRR_INT__s_g_s_f[4 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_s_f[4 * 10 + iket] );

                    HRR_INT__p_f_s_f[5 * 10 + iket] = HRR_INT__s_g_s_f[5 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_s_f[5 * 10 + iket] );

                    HRR_INT__p_f_s_f[6 * 10 + iket] = HRR_INT__s_g_s_f[6 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_s_f[6 * 10 + iket] );

                    HRR_INT__p_f_s_f[7 * 10 + iket] = HRR_INT__s_g_s_f[7 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_s_f[7 * 10 + iket] );

                    HRR_INT__p_f_s_f[8 * 10 + iket] = HRR_INT__s_g_s_f[8 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_s_f[8 * 10 + iket] );

                    HRR_INT__p_f_s_f[9 * 10 + iket] = HRR_INT__s_g_s_f[9 * 10 + iket] - ( hAB[0] * HRR_INT__s_f_s_f[9 * 10 + iket] );

                    HRR_INT__p_f_s_f[10 * 10 + iket] = HRR_INT__s_g_s_f[1 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_s_f[0 * 10 + iket] );

                    HRR_INT__p_f_s_f[11 * 10 + iket] = HRR_INT__s_g_s_f[3 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_s_f[1 * 10 + iket] );

                    HRR_INT__p_f_s_f[12 * 10 + iket] = HRR_INT__s_g_s_f[4 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_s_f[2 * 10 + iket] );

                    HRR_INT__p_f_s_f[13 * 10 + iket] = HRR_INT__s_g_s_f[6 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_s_f[3 * 10 + iket] );

                    HRR_INT__p_f_s_f[14 * 10 + iket] = HRR_INT__s_g_s_f[7 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_s_f[4 * 10 + iket] );

                    HRR_INT__p_f_s_f[15 * 10 + iket] = HRR_INT__s_g_s_f[8 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_s_f[5 * 10 + iket] );

                    HRR_INT__p_f_s_f[16 * 10 + iket] = HRR_INT__s_g_s_f[10 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_s_f[6 * 10 + iket] );

                    HRR_INT__p_f_s_f[17 * 10 + iket] = HRR_INT__s_g_s_f[11 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_s_f[7 * 10 + iket] );

                    HRR_INT__p_f_s_f[18 * 10 + iket] = HRR_INT__s_g_s_f[12 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_s_f[8 * 10 + iket] );

                    HRR_INT__p_f_s_f[19 * 10 + iket] = HRR_INT__s_g_s_f[13 * 10 + iket] - ( hAB[1] * HRR_INT__s_f_s_f[9 * 10 + iket] );

                    HRR_INT__p_f_s_f[20 * 10 + iket] = HRR_INT__s_g_s_f[2 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_s_f[0 * 10 + iket] );

                    HRR_INT__p_f_s_f[21 * 10 + iket] = HRR_INT__s_g_s_f[4 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_s_f[1 * 10 + iket] );

                    HRR_INT__p_f_s_f[22 * 10 + iket] = HRR_INT__s_g_s_f[5 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_s_f[2 * 10 + iket] );

                    HRR_INT__p_f_s_f[23 * 10 + iket] = HRR_INT__s_g_s_f[7 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_s_f[3 * 10 + iket] );

                    HRR_INT__p_f_s_f[24 * 10 + iket] = HRR_INT__s_g_s_f[8 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_s_f[4 * 10 + iket] );

                    HRR_INT__p_f_s_f[25 * 10 + iket] = HRR_INT__s_g_s_f[9 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_s_f[5 * 10 + iket] );

                    HRR_INT__p_f_s_f[26 * 10 + iket] = HRR_INT__s_g_s_f[11 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_s_f[6 * 10 + iket] );

                    HRR_INT__p_f_s_f[27 * 10 + iket] = HRR_INT__s_g_s_f[12 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_s_f[7 * 10 + iket] );

                    HRR_INT__p_f_s_f[28 * 10 + iket] = HRR_INT__s_g_s_f[13 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_s_f[8 * 10 + iket] );

                    HRR_INT__p_f_s_f[29 * 10 + iket] = HRR_INT__s_g_s_f[14 * 10 + iket] - ( hAB[2] * HRR_INT__s_f_s_f[9 * 10 + iket] );

                }


                // form INT__p_f_s_g
                for(iket = 0; iket < 15; ++iket)
                {
                    HRR_INT__p_f_s_g[0 * 15 + iket] = HRR_INT__s_g_s_g[0 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_s_g[0 * 15 + iket] );

                    HRR_INT__p_f_s_g[1 * 15 + iket] = HRR_INT__s_g_s_g[1 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_s_g[1 * 15 + iket] );

                    HRR_INT__p_f_s_g[2 * 15 + iket] = HRR_INT__s_g_s_g[2 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_s_g[2 * 15 + iket] );

                    HRR_INT__p_f_s_g[3 * 15 + iket] = HRR_INT__s_g_s_g[3 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_s_g[3 * 15 + iket] );

                    HRR_INT__p_f_s_g[4 * 15 + iket] = HRR_INT__s_g_s_g[4 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_s_g[4 * 15 + iket] );

                    HRR_INT__p_f_s_g[5 * 15 + iket] = HRR_INT__s_g_s_g[5 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_s_g[5 * 15 + iket] );

                    HRR_INT__p_f_s_g[6 * 15 + iket] = HRR_INT__s_g_s_g[6 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_s_g[6 * 15 + iket] );

                    HRR_INT__p_f_s_g[7 * 15 + iket] = HRR_INT__s_g_s_g[7 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_s_g[7 * 15 + iket] );

                    HRR_INT__p_f_s_g[8 * 15 + iket] = HRR_INT__s_g_s_g[8 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_s_g[8 * 15 + iket] );

                    HRR_INT__p_f_s_g[9 * 15 + iket] = HRR_INT__s_g_s_g[9 * 15 + iket] - ( hAB[0] * HRR_INT__s_f_s_g[9 * 15 + iket] );

                    HRR_INT__p_f_s_g[10 * 15 + iket] = HRR_INT__s_g_s_g[1 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_s_g[0 * 15 + iket] );

                    HRR_INT__p_f_s_g[11 * 15 + iket] = HRR_INT__s_g_s_g[3 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_s_g[1 * 15 + iket] );

                    HRR_INT__p_f_s_g[12 * 15 + iket] = HRR_INT__s_g_s_g[4 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_s_g[2 * 15 + iket] );

                    HRR_INT__p_f_s_g[13 * 15 + iket] = HRR_INT__s_g_s_g[6 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_s_g[3 * 15 + iket] );

                    HRR_INT__p_f_s_g[14 * 15 + iket] = HRR_INT__s_g_s_g[7 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_s_g[4 * 15 + iket] );

                    HRR_INT__p_f_s_g[15 * 15 + iket] = HRR_INT__s_g_s_g[8 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_s_g[5 * 15 + iket] );

                    HRR_INT__p_f_s_g[16 * 15 + iket] = HRR_INT__s_g_s_g[10 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_s_g[6 * 15 + iket] );

                    HRR_INT__p_f_s_g[17 * 15 + iket] = HRR_INT__s_g_s_g[11 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_s_g[7 * 15 + iket] );

                    HRR_INT__p_f_s_g[18 * 15 + iket] = HRR_INT__s_g_s_g[12 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_s_g[8 * 15 + iket] );

                    HRR_INT__p_f_s_g[19 * 15 + iket] = HRR_INT__s_g_s_g[13 * 15 + iket] - ( hAB[1] * HRR_INT__s_f_s_g[9 * 15 + iket] );

                    HRR_INT__p_f_s_g[20 * 15 + iket] = HRR_INT__s_g_s_g[2 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_s_g[0 * 15 + iket] );

                    HRR_INT__p_f_s_g[21 * 15 + iket] = HRR_INT__s_g_s_g[4 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_s_g[1 * 15 + iket] );

                    HRR_INT__p_f_s_g[22 * 15 + iket] = HRR_INT__s_g_s_g[5 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_s_g[2 * 15 + iket] );

                    HRR_INT__p_f_s_g[23 * 15 + iket] = HRR_INT__s_g_s_g[7 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_s_g[3 * 15 + iket] );

                    HRR_INT__p_f_s_g[24 * 15 + iket] = HRR_INT__s_g_s_g[8 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_s_g[4 * 15 + iket] );

                    HRR_INT__p_f_s_g[25 * 15 + iket] = HRR_INT__s_g_s_g[9 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_s_g[5 * 15 + iket] );

                    HRR_INT__p_f_s_g[26 * 15 + iket] = HRR_INT__s_g_s_g[11 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_s_g[6 * 15 + iket] );

                    HRR_INT__p_f_s_g[27 * 15 + iket] = HRR_INT__s_g_s_g[12 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_s_g[7 * 15 + iket] );

                    HRR_INT__p_f_s_g[28 * 15 + iket] = HRR_INT__s_g_s_g[13 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_s_g[8 * 15 + iket] );

                    HRR_INT__p_f_s_g[29 * 15 + iket] = HRR_INT__s_g_s_g[14 * 15 + iket] - ( hAB[2] * HRR_INT__s_f_s_g[9 * 15 + iket] );

                }


                // form INT__p_f_s_h
                for(iket = 0; iket < 21; ++iket)
                {
                    HRR_INT__p_f_s_h[0 * 21 + iket] = HRR_INT__s_g_s_h[0 * 21 + iket] - ( hAB[0] * HRR_INT__s_f_s_h[0 * 21 + iket] );

                    HRR_INT__p_f_s_h[1 * 21 + iket] = HRR_INT__s_g_s_h[1 * 21 + iket] - ( hAB[0] * HRR_INT__s_f_s_h[1 * 21 + iket] );

                    HRR_INT__p_f_s_h[2 * 21 + iket] = HRR_INT__s_g_s_h[2 * 21 + iket] - ( hAB[0] * HRR_INT__s_f_s_h[2 * 21 + iket] );

                    HRR_INT__p_f_s_h[3 * 21 + iket] = HRR_INT__s_g_s_h[3 * 21 + iket] - ( hAB[0] * HRR_INT__s_f_s_h[3 * 21 + iket] );

                    HRR_INT__p_f_s_h[4 * 21 + iket] = HRR_INT__s_g_s_h[4 * 21 + iket] - ( hAB[0] * HRR_INT__s_f_s_h[4 * 21 + iket] );

                    HRR_INT__p_f_s_h[5 * 21 + iket] = HRR_INT__s_g_s_h[5 * 21 + iket] - ( hAB[0] * HRR_INT__s_f_s_h[5 * 21 + iket] );

                    HRR_INT__p_f_s_h[6 * 21 + iket] = HRR_INT__s_g_s_h[6 * 21 + iket] - ( hAB[0] * HRR_INT__s_f_s_h[6 * 21 + iket] );

                    HRR_INT__p_f_s_h[7 * 21 + iket] = HRR_INT__s_g_s_h[7 * 21 + iket] - ( hAB[0] * HRR_INT__s_f_s_h[7 * 21 + iket] );

                    HRR_INT__p_f_s_h[8 * 21 + iket] = HRR_INT__s_g_s_h[8 * 21 + iket] - ( hAB[0] * HRR_INT__s_f_s_h[8 * 21 + iket] );

                    HRR_INT__p_f_s_h[9 * 21 + iket] = HRR_INT__s_g_s_h[9 * 21 + iket] - ( hAB[0] * HRR_INT__s_f_s_h[9 * 21 + iket] );

                    HRR_INT__p_f_s_h[10 * 21 + iket] = HRR_INT__s_g_s_h[1 * 21 + iket] - ( hAB[1] * HRR_INT__s_f_s_h[0 * 21 + iket] );

                    HRR_INT__p_f_s_h[11 * 21 + iket] = HRR_INT__s_g_s_h[3 * 21 + iket] - ( hAB[1] * HRR_INT__s_f_s_h[1 * 21 + iket] );

                    HRR_INT__p_f_s_h[12 * 21 + iket] = HRR_INT__s_g_s_h[4 * 21 + iket] - ( hAB[1] * HRR_INT__s_f_s_h[2 * 21 + iket] );

                    HRR_INT__p_f_s_h[13 * 21 + iket] = HRR_INT__s_g_s_h[6 * 21 + iket] - ( hAB[1] * HRR_INT__s_f_s_h[3 * 21 + iket] );

                    HRR_INT__p_f_s_h[14 * 21 + iket] = HRR_INT__s_g_s_h[7 * 21 + iket] - ( hAB[1] * HRR_INT__s_f_s_h[4 * 21 + iket] );

                    HRR_INT__p_f_s_h[15 * 21 + iket] = HRR_INT__s_g_s_h[8 * 21 + iket] - ( hAB[1] * HRR_INT__s_f_s_h[5 * 21 + iket] );

                    HRR_INT__p_f_s_h[16 * 21 + iket] = HRR_INT__s_g_s_h[10 * 21 + iket] - ( hAB[1] * HRR_INT__s_f_s_h[6 * 21 + iket] );

                    HRR_INT__p_f_s_h[17 * 21 + iket] = HRR_INT__s_g_s_h[11 * 21 + iket] - ( hAB[1] * HRR_INT__s_f_s_h[7 * 21 + iket] );

                    HRR_INT__p_f_s_h[18 * 21 + iket] = HRR_INT__s_g_s_h[12 * 21 + iket] - ( hAB[1] * HRR_INT__s_f_s_h[8 * 21 + iket] );

                    HRR_INT__p_f_s_h[19 * 21 + iket] = HRR_INT__s_g_s_h[13 * 21 + iket] - ( hAB[1] * HRR_INT__s_f_s_h[9 * 21 + iket] );

                    HRR_INT__p_f_s_h[20 * 21 + iket] = HRR_INT__s_g_s_h[2 * 21 + iket] - ( hAB[2] * HRR_INT__s_f_s_h[0 * 21 + iket] );

                    HRR_INT__p_f_s_h[21 * 21 + iket] = HRR_INT__s_g_s_h[4 * 21 + iket] - ( hAB[2] * HRR_INT__s_f_s_h[1 * 21 + iket] );

                    HRR_INT__p_f_s_h[22 * 21 + iket] = HRR_INT__s_g_s_h[5 * 21 + iket] - ( hAB[2] * HRR_INT__s_f_s_h[2 * 21 + iket] );

                    HRR_INT__p_f_s_h[23 * 21 + iket] = HRR_INT__s_g_s_h[7 * 21 + iket] - ( hAB[2] * HRR_INT__s_f_s_h[3 * 21 + iket] );

                    HRR_INT__p_f_s_h[24 * 21 + iket] = HRR_INT__s_g_s_h[8 * 21 + iket] - ( hAB[2] * HRR_INT__s_f_s_h[4 * 21 + iket] );

                    HRR_INT__p_f_s_h[25 * 21 + iket] = HRR_INT__s_g_s_h[9 * 21 + iket] - ( hAB[2] * HRR_INT__s_f_s_h[5 * 21 + iket] );

                    HRR_INT__p_f_s_h[26 * 21 + iket] = HRR_INT__s_g_s_h[11 * 21 + iket] - ( hAB[2] * HRR_INT__s_f_s_h[6 * 21 + iket] );

                    HRR_INT__p_f_s_h[27 * 21 + iket] = HRR_INT__s_g_s_h[12 * 21 + iket] - ( hAB[2] * HRR_INT__s_f_s_h[7 * 21 + iket] );

                    HRR_INT__p_f_s_h[28 * 21 + iket] = HRR_INT__s_g_s_h[13 * 21 + iket] - ( hAB[2] * HRR_INT__s_f_s_h[8 * 21 + iket] );

                    HRR_INT__p_f_s_h[29 * 21 + iket] = HRR_INT__s_g_s_h[14 * 21 + iket] - ( hAB[2] * HRR_INT__s_f_s_h[9 * 21 + iket] );

                }


                // form INT__p_g_s_f
                HRR_I_p_g(
                    HRR_INT__p_g_s_f,
                    HRR_INT__s_g_s_f,
                    HRR_INT__s_h_s_f,
                    hAB, 10);

                // form INT__p_g_s_g
                HRR_I_p_g(
                    HRR_INT__p_g_s_g,
                    HRR_INT__s_g_s_g,
                    HRR_INT__s_h_s_g,
                    hAB, 15);

                // form INT__p_g_s_h
                HRR_I_p_g(
                    HRR_INT__p_g_s_h,
                    HRR_INT__s_g_s_h,
                    HRR_INT__s_h_s_h,
                    hAB, 21);

                // form INT__d_f_s_f
                HRR_I_d_f(
                    HRR_INT__d_f_s_f,
                    HRR_INT__p_f_s_f,
                    HRR_INT__p_g_s_f,
                    hAB, 10);

                // form INT__d_f_s_g
                HRR_I_d_f(
                    HRR_INT__d_f_s_g,
                    HRR_INT__p_f_s_g,
                    HRR_INT__p_g_s_g,
                    hAB, 15);

                // form INT__d_f_s_h
                HRR_I_d_f(
                    HRR_INT__d_f_s_h,
                    HRR_INT__p_f_s_h,
                    HRR_INT__p_g_s_h,
                    hAB, 21);

                // form INT__d_f_p_f
                for(ibra = 0; ibra < 60; ++ibra)
                {
                    HRR_INT__d_f_p_f[ibra * 30 + 0] = HRR_INT__d_f_s_g[ibra * 15 + 0] - ( hCD[0] * HRR_INT__d_f_s_f[ibra * 10 + 0] );

                    HRR_INT__d_f_p_f[ibra * 30 + 1] = HRR_INT__d_f_s_g[ibra * 15 + 1] - ( hCD[0] * HRR_INT__d_f_s_f[ibra * 10 + 1] );

                    HRR_INT__d_f_p_f[ibra * 30 + 2] = HRR_INT__d_f_s_g[ibra * 15 + 2] - ( hCD[0] * HRR_INT__d_f_s_f[ibra * 10 + 2] );

                    HRR_INT__d_f_p_f[ibra * 30 + 3] = HRR_INT__d_f_s_g[ibra * 15 + 3] - ( hCD[0] * HRR_INT__d_f_s_f[ibra * 10 + 3] );

                    HRR_INT__d_f_p_f[ibra * 30 + 4] = HRR_INT__d_f_s_g[ibra * 15 + 4] - ( hCD[0] * HRR_INT__d_f_s_f[ibra * 10 + 4] );

                    HRR_INT__d_f_p_f[ibra * 30 + 5] = HRR_INT__d_f_s_g[ibra * 15 + 5] - ( hCD[0] * HRR_INT__d_f_s_f[ibra * 10 + 5] );

                    HRR_INT__d_f_p_f[ibra * 30 + 6] = HRR_INT__d_f_s_g[ibra * 15 + 6] - ( hCD[0] * HRR_INT__d_f_s_f[ibra * 10 + 6] );

                    HRR_INT__d_f_p_f[ibra * 30 + 7] = HRR_INT__d_f_s_g[ibra * 15 + 7] - ( hCD[0] * HRR_INT__d_f_s_f[ibra * 10 + 7] );

                    HRR_INT__d_f_p_f[ibra * 30 + 8] = HRR_INT__d_f_s_g[ibra * 15 + 8] - ( hCD[0] * HRR_INT__d_f_s_f[ibra * 10 + 8] );

                    HRR_INT__d_f_p_f[ibra * 30 + 9] = HRR_INT__d_f_s_g[ibra * 15 + 9] - ( hCD[0] * HRR_INT__d_f_s_f[ibra * 10 + 9] );

                    HRR_INT__d_f_p_f[ibra * 30 + 10] = HRR_INT__d_f_s_g[ibra * 15 + 1] - ( hCD[1] * HRR_INT__d_f_s_f[ibra * 10 + 0] );

                    HRR_INT__d_f_p_f[ibra * 30 + 11] = HRR_INT__d_f_s_g[ibra * 15 + 3] - ( hCD[1] * HRR_INT__d_f_s_f[ibra * 10 + 1] );

                    HRR_INT__d_f_p_f[ibra * 30 + 12] = HRR_INT__d_f_s_g[ibra * 15 + 4] - ( hCD[1] * HRR_INT__d_f_s_f[ibra * 10 + 2] );

                    HRR_INT__d_f_p_f[ibra * 30 + 13] = HRR_INT__d_f_s_g[ibra * 15 + 6] - ( hCD[1] * HRR_INT__d_f_s_f[ibra * 10 + 3] );

                    HRR_INT__d_f_p_f[ibra * 30 + 14] = HRR_INT__d_f_s_g[ibra * 15 + 7] - ( hCD[1] * HRR_INT__d_f_s_f[ibra * 10 + 4] );

                    HRR_INT__d_f_p_f[ibra * 30 + 15] = HRR_INT__d_f_s_g[ibra * 15 + 8] - ( hCD[1] * HRR_INT__d_f_s_f[ibra * 10 + 5] );

                    HRR_INT__d_f_p_f[ibra * 30 + 16] = HRR_INT__d_f_s_g[ibra * 15 + 10] - ( hCD[1] * HRR_INT__d_f_s_f[ibra * 10 + 6] );

                    HRR_INT__d_f_p_f[ibra * 30 + 17] = HRR_INT__d_f_s_g[ibra * 15 + 11] - ( hCD[1] * HRR_INT__d_f_s_f[ibra * 10 + 7] );

                    HRR_INT__d_f_p_f[ibra * 30 + 18] = HRR_INT__d_f_s_g[ibra * 15 + 12] - ( hCD[1] * HRR_INT__d_f_s_f[ibra * 10 + 8] );

                    HRR_INT__d_f_p_f[ibra * 30 + 19] = HRR_INT__d_f_s_g[ibra * 15 + 13] - ( hCD[1] * HRR_INT__d_f_s_f[ibra * 10 + 9] );

                    HRR_INT__d_f_p_f[ibra * 30 + 20] = HRR_INT__d_f_s_g[ibra * 15 + 2] - ( hCD[2] * HRR_INT__d_f_s_f[ibra * 10 + 0] );

                    HRR_INT__d_f_p_f[ibra * 30 + 21] = HRR_INT__d_f_s_g[ibra * 15 + 4] - ( hCD[2] * HRR_INT__d_f_s_f[ibra * 10 + 1] );

                    HRR_INT__d_f_p_f[ibra * 30 + 22] = HRR_INT__d_f_s_g[ibra * 15 + 5] - ( hCD[2] * HRR_INT__d_f_s_f[ibra * 10 + 2] );

                    HRR_INT__d_f_p_f[ibra * 30 + 23] = HRR_INT__d_f_s_g[ibra * 15 + 7] - ( hCD[2] * HRR_INT__d_f_s_f[ibra * 10 + 3] );

                    HRR_INT__d_f_p_f[ibra * 30 + 24] = HRR_INT__d_f_s_g[ibra * 15 + 8] - ( hCD[2] * HRR_INT__d_f_s_f[ibra * 10 + 4] );

                    HRR_INT__d_f_p_f[ibra * 30 + 25] = HRR_INT__d_f_s_g[ibra * 15 + 9] - ( hCD[2] * HRR_INT__d_f_s_f[ibra * 10 + 5] );

                    HRR_INT__d_f_p_f[ibra * 30 + 26] = HRR_INT__d_f_s_g[ibra * 15 + 11] - ( hCD[2] * HRR_INT__d_f_s_f[ibra * 10 + 6] );

                    HRR_INT__d_f_p_f[ibra * 30 + 27] = HRR_INT__d_f_s_g[ibra * 15 + 12] - ( hCD[2] * HRR_INT__d_f_s_f[ibra * 10 + 7] );

                    HRR_INT__d_f_p_f[ibra * 30 + 28] = HRR_INT__d_f_s_g[ibra * 15 + 13] - ( hCD[2] * HRR_INT__d_f_s_f[ibra * 10 + 8] );

                    HRR_INT__d_f_p_f[ibra * 30 + 29] = HRR_INT__d_f_s_g[ibra * 15 + 14] - ( hCD[2] * HRR_INT__d_f_s_f[ibra * 10 + 9] );

                }

                // form INT__d_f_p_g
                HRR_K_p_g(
                    HRR_INT__d_f_p_g,
                    HRR_INT__d_f_s_g,
                    HRR_INT__d_f_s_h,
                    hCD, 60);

                // form INT__d_f_d_f
                HRR_K_d_f(
                    HRR_INT__d_f_d_f,
                    HRR_INT__d_f_p_f,
                    HRR_INT__d_f_p_g,
                    hCD, 60);


            }  // close HRR loop


        }   // close loop cdbatch

        istart = iend;
    }  // close loop over ab

    return P.nshell12_clip * Q.nshell12_clip;
}

