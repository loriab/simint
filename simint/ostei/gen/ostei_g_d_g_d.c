#include "simint/boys/boys.h"
#include "simint/ostei/gen/ostei_generated.h"
#include "simint/vectorization/vectorization.h"
#include <math.h>
#include <string.h>


int ostei_g_d_g_d(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__g_d_g_d)
{

    SIMINT_ASSUME_ALIGN_DBL(work);
    SIMINT_ASSUME_ALIGN_DBL(INT__g_d_g_d);
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
    double * const INT__g_s_g_s = work + (SIMINT_NSHELL_SIMD * 0);
    double * const INT__g_s_h_s = work + (SIMINT_NSHELL_SIMD * 225);
    double * const INT__g_s_i_s = work + (SIMINT_NSHELL_SIMD * 540);
    double * const INT__h_s_g_s = work + (SIMINT_NSHELL_SIMD * 960);
    double * const INT__h_s_h_s = work + (SIMINT_NSHELL_SIMD * 1275);
    double * const INT__h_s_i_s = work + (SIMINT_NSHELL_SIMD * 1716);
    double * const INT__i_s_g_s = work + (SIMINT_NSHELL_SIMD * 2304);
    double * const INT__i_s_h_s = work + (SIMINT_NSHELL_SIMD * 2724);
    double * const INT__i_s_i_s = work + (SIMINT_NSHELL_SIMD * 3312);
    SIMINT_DBLTYPE * const primwork = (SIMINT_DBLTYPE *)(work + SIMINT_NSHELL_SIMD*4096);
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_s = primwork + 0;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_p_s = primwork + 13;
    SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_d_s = primwork + 31;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_s = primwork + 61;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_p_s = primwork + 97;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_d_s = primwork + 151;
    SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_f_s = primwork + 241;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_s = primwork + 361;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_p_s = primwork + 427;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_d_s = primwork + 535;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_f_s = primwork + 715;
    SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_g_s = primwork + 955;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_s = primwork + 1225;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_p_s = primwork + 1325;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s = primwork + 1505;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_f_s = primwork + 1805;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_g_s = primwork + 2205;
    SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_h_s = primwork + 2655;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_s = primwork + 3075;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_p_s = primwork + 3210;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_d_s = primwork + 3480;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_f_s = primwork + 3930;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_g_s = primwork + 4530;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_h_s = primwork + 5205;
    SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_i_s = primwork + 5835;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s = primwork + 6255;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_p_s = primwork + 6423;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_d_s = primwork + 6801;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_f_s = primwork + 7431;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_g_s = primwork + 8271;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_h_s = primwork + 9216;
    SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_i_s = primwork + 10098;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_s_s = primwork + 10686;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_p_s = primwork + 10882;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_d_s = primwork + 11386;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_f_s = primwork + 12226;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_g_s = primwork + 13346;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_h_s = primwork + 14606;
    SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_i_s = primwork + 15782;
    double * const hrrwork = (double *)(primwork + 16566);
    double * const HRR_INT__g_p_g_s = hrrwork + 0;
    double * const HRR_INT__g_p_h_s = hrrwork + 675;
    double * const HRR_INT__g_p_i_s = hrrwork + 1620;
    double * const HRR_INT__g_d_g_s = hrrwork + 2880;
    double * const HRR_INT__g_d_g_p = hrrwork + 4230;
    double * const HRR_INT__g_d_h_s = hrrwork + 8280;
    double * const HRR_INT__g_d_h_p = hrrwork + 10170;
    double * const HRR_INT__g_d_i_s = hrrwork + 15840;
    double * const HRR_INT__h_p_g_s = hrrwork + 18360;
    double * const HRR_INT__h_p_h_s = hrrwork + 19305;
    double * const HRR_INT__h_p_i_s = hrrwork + 20628;


    // Create constants
    const SIMINT_DBLTYPE const_1 = SIMINT_DBLSET1(1);
    const SIMINT_DBLTYPE const_2 = SIMINT_DBLSET1(2);
    const SIMINT_DBLTYPE const_3 = SIMINT_DBLSET1(3);
    const SIMINT_DBLTYPE const_4 = SIMINT_DBLSET1(4);
    const SIMINT_DBLTYPE const_5 = SIMINT_DBLSET1(5);
    const SIMINT_DBLTYPE const_6 = SIMINT_DBLSET1(6);
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
            memset(work, 0, SIMINT_NSHELL_SIMD * 4096 * sizeof(double));
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
                double * restrict PRIM_PTR_INT__g_s_g_s = INT__g_s_g_s + abcd * 225;
                double * restrict PRIM_PTR_INT__g_s_h_s = INT__g_s_h_s + abcd * 315;
                double * restrict PRIM_PTR_INT__g_s_i_s = INT__g_s_i_s + abcd * 420;
                double * restrict PRIM_PTR_INT__h_s_g_s = INT__h_s_g_s + abcd * 315;
                double * restrict PRIM_PTR_INT__h_s_h_s = INT__h_s_h_s + abcd * 441;
                double * restrict PRIM_PTR_INT__h_s_i_s = INT__h_s_i_s + abcd * 588;
                double * restrict PRIM_PTR_INT__i_s_g_s = INT__i_s_g_s + abcd * 420;
                double * restrict PRIM_PTR_INT__i_s_h_s = INT__i_s_h_s + abcd * 588;
                double * restrict PRIM_PTR_INT__i_s_i_s = INT__i_s_i_s + abcd * 784;



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
                            PRIM_PTR_INT__g_s_g_s += 225;
                            PRIM_PTR_INT__g_s_h_s += 315;
                            PRIM_PTR_INT__g_s_i_s += 420;
                            PRIM_PTR_INT__h_s_g_s += 315;
                            PRIM_PTR_INT__h_s_h_s += 441;
                            PRIM_PTR_INT__h_s_i_s += 588;
                            PRIM_PTR_INT__i_s_g_s += 420;
                            PRIM_PTR_INT__i_s_h_s += 588;
                            PRIM_PTR_INT__i_s_i_s += 784;
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
                            PRIM_PTR_INT__g_s_g_s += lastoffset*225;
                            PRIM_PTR_INT__g_s_h_s += lastoffset*315;
                            PRIM_PTR_INT__g_s_i_s += lastoffset*420;
                            PRIM_PTR_INT__h_s_g_s += lastoffset*315;
                            PRIM_PTR_INT__h_s_h_s += lastoffset*441;
                            PRIM_PTR_INT__h_s_i_s += lastoffset*588;
                            PRIM_PTR_INT__i_s_g_s += lastoffset*420;
                            PRIM_PTR_INT__i_s_h_s += lastoffset*588;
                            PRIM_PTR_INT__i_s_i_s += lastoffset*784;
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
                    // Maximum v value: 12
                    //////////////////////////////////////////////
                    // The parameter to the Fjt function
                    const SIMINT_DBLTYPE F_x = SIMINT_MUL(R2, alpha);


                    const SIMINT_DBLTYPE Q_prefac = mask_load(nlane, Q.prefac + j);


                    boys_F_split(PRIM_INT__s_s_s_s, F_x, 12);
                    SIMINT_DBLTYPE prefac = SIMINT_SQRT(one_over_PQalpha_sum);
                    prefac = SIMINT_MUL(SIMINT_MUL(P_prefac, Q_prefac), prefac);
                    for(n = 0; n <= 12; n++)
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
                    const SIMINT_DBLTYPE vrr_const_1_over_2pq = one_over_2pq;
                    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(const_2, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_3_over_2pq = SIMINT_MUL(const_3, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_4_over_2pq = SIMINT_MUL(const_4, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_5_over_2pq = SIMINT_MUL(const_5, one_over_2pq);
                    const SIMINT_DBLTYPE vrr_const_6_over_2pq = SIMINT_MUL(const_6, one_over_2pq);



                    // Forming PRIM_INT__p_s_s_s[12 * 3];
                    for(n = 0; n < 12; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__p_s_s_s[n * 3 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__p_s_s_s[n * 3 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_s_s[n * 3 + 0]);

                        PRIM_INT__p_s_s_s[n * 3 + 1] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__p_s_s_s[n * 3 + 1] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_s_s[n * 3 + 1]);

                        PRIM_INT__p_s_s_s[n * 3 + 2] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__p_s_s_s[n * 3 + 2] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_s_s[n * 3 + 2]);

                    }



                    // Forming PRIM_INT__d_s_s_s[11 * 6];
                    for(n = 0; n < 11; ++n)  // loop over orders of auxiliary function
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



                    // Forming PRIM_INT__f_s_s_s[10 * 10];
                    for(n = 0; n < 10; ++n)  // loop over orders of auxiliary function
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



                    // Forming PRIM_INT__g_s_s_s[9 * 15];
                    for(n = 0; n < 9; ++n)  // loop over orders of auxiliary function
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
                            6);



                    // Forming PRIM_INT__f_s_p_s[6 * 30];
                    for(n = 0; n < 6; ++n)  // loop over orders of auxiliary function
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
                            5);



                    // Forming PRIM_INT__d_s_p_s[6 * 18];
                    for(n = 0; n < 6; ++n)  // loop over orders of auxiliary function
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
                            5);


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
                            4);



                    // Forming PRIM_INT__p_s_p_s[6 * 9];
                    for(n = 0; n < 6; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__p_s_p_s[n * 9 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__p_s_s_s[n * 3 + 0]);
                        PRIM_INT__p_s_p_s[n * 9 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__p_s_p_s[n * 9 + 0]);
                        PRIM_INT__p_s_p_s[n * 9 + 0] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_p_s[n * 9 + 0]);

                        PRIM_INT__p_s_p_s[n * 9 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__p_s_s_s[n * 3 + 0]);
                        PRIM_INT__p_s_p_s[n * 9 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__p_s_p_s[n * 9 + 1]);

                        PRIM_INT__p_s_p_s[n * 9 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__p_s_s_s[n * 3 + 0]);
                        PRIM_INT__p_s_p_s[n * 9 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__p_s_p_s[n * 9 + 2]);

                        PRIM_INT__p_s_p_s[n * 9 + 3] = SIMINT_MUL(Q_PA[0], PRIM_INT__p_s_s_s[n * 3 + 1]);
                        PRIM_INT__p_s_p_s[n * 9 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__p_s_p_s[n * 9 + 3]);

                        PRIM_INT__p_s_p_s[n * 9 + 4] = SIMINT_MUL(Q_PA[1], PRIM_INT__p_s_s_s[n * 3 + 1]);
                        PRIM_INT__p_s_p_s[n * 9 + 4] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__p_s_p_s[n * 9 + 4]);
                        PRIM_INT__p_s_p_s[n * 9 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_p_s[n * 9 + 4]);

                        PRIM_INT__p_s_p_s[n * 9 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__p_s_s_s[n * 3 + 1]);
                        PRIM_INT__p_s_p_s[n * 9 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__p_s_p_s[n * 9 + 5]);

                        PRIM_INT__p_s_p_s[n * 9 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__p_s_s_s[n * 3 + 2]);
                        PRIM_INT__p_s_p_s[n * 9 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__p_s_p_s[n * 9 + 6]);

                        PRIM_INT__p_s_p_s[n * 9 + 7] = SIMINT_MUL(Q_PA[1], PRIM_INT__p_s_s_s[n * 3 + 2]);
                        PRIM_INT__p_s_p_s[n * 9 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__p_s_p_s[n * 9 + 7]);

                        PRIM_INT__p_s_p_s[n * 9 + 8] = SIMINT_MUL(Q_PA[2], PRIM_INT__p_s_s_s[n * 3 + 2]);
                        PRIM_INT__p_s_p_s[n * 9 + 8] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__p_s_p_s[n * 9 + 8]);
                        PRIM_INT__p_s_p_s[n * 9 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__p_s_p_s[n * 9 + 8]);

                    }



                    // Forming PRIM_INT__d_s_d_s[5 * 36];
                    for(n = 0; n < 5; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__d_s_d_s[n * 36 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_p_s[n * 18 + 0]);
                        PRIM_INT__d_s_d_s[n * 36 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_p_s[(n+1) * 18 + 0], PRIM_INT__d_s_d_s[n * 36 + 0]);
                        PRIM_INT__d_s_d_s[n * 36 + 0] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__d_s_s_s[n * 6 + 0]), PRIM_INT__d_s_d_s[n * 36 + 0]);
                        PRIM_INT__d_s_d_s[n * 36 + 0] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 0], PRIM_INT__d_s_d_s[n * 36 + 0]);

                        PRIM_INT__d_s_d_s[n * 36 + 3] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_p_s[n * 18 + 1]);
                        PRIM_INT__d_s_d_s[n * 36 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_p_s[(n+1) * 18 + 1], PRIM_INT__d_s_d_s[n * 36 + 3]);
                        PRIM_INT__d_s_d_s[n * 36 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__d_s_s_s[n * 6 + 0]), PRIM_INT__d_s_d_s[n * 36 + 3]);

                        PRIM_INT__d_s_d_s[n * 36 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_p_s[n * 18 + 2]);
                        PRIM_INT__d_s_d_s[n * 36 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_p_s[(n+1) * 18 + 2], PRIM_INT__d_s_d_s[n * 36 + 5]);
                        PRIM_INT__d_s_d_s[n * 36 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 0], PRIM_INT__d_s_s_s[n * 6 + 0]), PRIM_INT__d_s_d_s[n * 36 + 5]);

                        PRIM_INT__d_s_d_s[n * 36 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_p_s[n * 18 + 3]);
                        PRIM_INT__d_s_d_s[n * 36 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_p_s[(n+1) * 18 + 3], PRIM_INT__d_s_d_s[n * 36 + 6]);
                        PRIM_INT__d_s_d_s[n * 36 + 6] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 1], PRIM_INT__d_s_s_s[n * 6 + 1]), PRIM_INT__d_s_d_s[n * 36 + 6]);
                        PRIM_INT__d_s_d_s[n * 36 + 6] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 3], PRIM_INT__d_s_d_s[n * 36 + 6]);

                        PRIM_INT__d_s_d_s[n * 36 + 9] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_p_s[n * 18 + 4]);
                        PRIM_INT__d_s_d_s[n * 36 + 9] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_p_s[(n+1) * 18 + 4], PRIM_INT__d_s_d_s[n * 36 + 9]);
                        PRIM_INT__d_s_d_s[n * 36 + 9] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 1], PRIM_INT__d_s_s_s[n * 6 + 1]), PRIM_INT__d_s_d_s[n * 36 + 9]);
                        PRIM_INT__d_s_d_s[n * 36 + 9] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 1], PRIM_INT__d_s_d_s[n * 36 + 9]);

                        PRIM_INT__d_s_d_s[n * 36 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_p_s[n * 18 + 5]);
                        PRIM_INT__d_s_d_s[n * 36 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_p_s[(n+1) * 18 + 5], PRIM_INT__d_s_d_s[n * 36 + 11]);
                        PRIM_INT__d_s_d_s[n * 36 + 11] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 1], PRIM_INT__d_s_s_s[n * 6 + 1]), PRIM_INT__d_s_d_s[n * 36 + 11]);

                        PRIM_INT__d_s_d_s[n * 36 + 12] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_p_s[n * 18 + 6]);
                        PRIM_INT__d_s_d_s[n * 36 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_p_s[(n+1) * 18 + 6], PRIM_INT__d_s_d_s[n * 36 + 12]);
                        PRIM_INT__d_s_d_s[n * 36 + 12] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 2], PRIM_INT__d_s_s_s[n * 6 + 2]), PRIM_INT__d_s_d_s[n * 36 + 12]);
                        PRIM_INT__d_s_d_s[n * 36 + 12] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 6], PRIM_INT__d_s_d_s[n * 36 + 12]);

                        PRIM_INT__d_s_d_s[n * 36 + 15] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_p_s[n * 18 + 7]);
                        PRIM_INT__d_s_d_s[n * 36 + 15] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_p_s[(n+1) * 18 + 7], PRIM_INT__d_s_d_s[n * 36 + 15]);
                        PRIM_INT__d_s_d_s[n * 36 + 15] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 2], PRIM_INT__d_s_s_s[n * 6 + 2]), PRIM_INT__d_s_d_s[n * 36 + 15]);

                        PRIM_INT__d_s_d_s[n * 36 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_p_s[n * 18 + 8]);
                        PRIM_INT__d_s_d_s[n * 36 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_p_s[(n+1) * 18 + 8], PRIM_INT__d_s_d_s[n * 36 + 17]);
                        PRIM_INT__d_s_d_s[n * 36 + 17] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 2], PRIM_INT__d_s_s_s[n * 6 + 2]), PRIM_INT__d_s_d_s[n * 36 + 17]);
                        PRIM_INT__d_s_d_s[n * 36 + 17] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 2], PRIM_INT__d_s_d_s[n * 36 + 17]);

                        PRIM_INT__d_s_d_s[n * 36 + 18] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_p_s[n * 18 + 9]);
                        PRIM_INT__d_s_d_s[n * 36 + 18] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_p_s[(n+1) * 18 + 9], PRIM_INT__d_s_d_s[n * 36 + 18]);
                        PRIM_INT__d_s_d_s[n * 36 + 18] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__d_s_s_s[n * 6 + 3]), PRIM_INT__d_s_d_s[n * 36 + 18]);

                        PRIM_INT__d_s_d_s[n * 36 + 21] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_p_s[n * 18 + 10]);
                        PRIM_INT__d_s_d_s[n * 36 + 21] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_p_s[(n+1) * 18 + 10], PRIM_INT__d_s_d_s[n * 36 + 21]);
                        PRIM_INT__d_s_d_s[n * 36 + 21] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__d_s_s_s[n * 6 + 3]), PRIM_INT__d_s_d_s[n * 36 + 21]);
                        PRIM_INT__d_s_d_s[n * 36 + 21] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 4], PRIM_INT__d_s_d_s[n * 36 + 21]);

                        PRIM_INT__d_s_d_s[n * 36 + 23] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_p_s[n * 18 + 11]);
                        PRIM_INT__d_s_d_s[n * 36 + 23] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_p_s[(n+1) * 18 + 11], PRIM_INT__d_s_d_s[n * 36 + 23]);
                        PRIM_INT__d_s_d_s[n * 36 + 23] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 3], PRIM_INT__d_s_s_s[n * 6 + 3]), PRIM_INT__d_s_d_s[n * 36 + 23]);

                        PRIM_INT__d_s_d_s[n * 36 + 24] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_p_s[n * 18 + 12]);
                        PRIM_INT__d_s_d_s[n * 36 + 24] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_p_s[(n+1) * 18 + 12], PRIM_INT__d_s_d_s[n * 36 + 24]);
                        PRIM_INT__d_s_d_s[n * 36 + 24] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 4], PRIM_INT__d_s_s_s[n * 6 + 4]), PRIM_INT__d_s_d_s[n * 36 + 24]);

                        PRIM_INT__d_s_d_s[n * 36 + 27] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_p_s[n * 18 + 13]);
                        PRIM_INT__d_s_d_s[n * 36 + 27] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_p_s[(n+1) * 18 + 13], PRIM_INT__d_s_d_s[n * 36 + 27]);
                        PRIM_INT__d_s_d_s[n * 36 + 27] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 4], PRIM_INT__d_s_s_s[n * 6 + 4]), PRIM_INT__d_s_d_s[n * 36 + 27]);
                        PRIM_INT__d_s_d_s[n * 36 + 27] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 7], PRIM_INT__d_s_d_s[n * 36 + 27]);

                        PRIM_INT__d_s_d_s[n * 36 + 29] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_p_s[n * 18 + 14]);
                        PRIM_INT__d_s_d_s[n * 36 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_p_s[(n+1) * 18 + 14], PRIM_INT__d_s_d_s[n * 36 + 29]);
                        PRIM_INT__d_s_d_s[n * 36 + 29] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 4], PRIM_INT__d_s_s_s[n * 6 + 4]), PRIM_INT__d_s_d_s[n * 36 + 29]);
                        PRIM_INT__d_s_d_s[n * 36 + 29] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 5], PRIM_INT__d_s_d_s[n * 36 + 29]);

                        PRIM_INT__d_s_d_s[n * 36 + 30] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_p_s[n * 18 + 15]);
                        PRIM_INT__d_s_d_s[n * 36 + 30] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_p_s[(n+1) * 18 + 15], PRIM_INT__d_s_d_s[n * 36 + 30]);
                        PRIM_INT__d_s_d_s[n * 36 + 30] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__d_s_s_s[n * 6 + 5]), PRIM_INT__d_s_d_s[n * 36 + 30]);

                        PRIM_INT__d_s_d_s[n * 36 + 33] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_p_s[n * 18 + 16]);
                        PRIM_INT__d_s_d_s[n * 36 + 33] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_p_s[(n+1) * 18 + 16], PRIM_INT__d_s_d_s[n * 36 + 33]);
                        PRIM_INT__d_s_d_s[n * 36 + 33] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__d_s_s_s[n * 6 + 5]), PRIM_INT__d_s_d_s[n * 36 + 33]);

                        PRIM_INT__d_s_d_s[n * 36 + 35] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_p_s[n * 18 + 17]);
                        PRIM_INT__d_s_d_s[n * 36 + 35] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_p_s[(n+1) * 18 + 17], PRIM_INT__d_s_d_s[n * 36 + 35]);
                        PRIM_INT__d_s_d_s[n * 36 + 35] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_s_s[(n+1) * 6 + 5], PRIM_INT__d_s_s_s[n * 6 + 5]), PRIM_INT__d_s_d_s[n * 36 + 35]);
                        PRIM_INT__d_s_d_s[n * 36 + 35] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_p_s[(n+1) * 9 + 8], PRIM_INT__d_s_d_s[n * 36 + 35]);

                    }


                    VRR_K_f_s_f_s(
                            PRIM_INT__f_s_f_s,
                            PRIM_INT__f_s_d_s,
                            PRIM_INT__f_s_p_s,
                            PRIM_INT__d_s_d_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            4);


                    ostei_general_vrr_K(4, 0, 4, 0, 3,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__g_s_f_s, PRIM_INT__g_s_d_s, NULL, PRIM_INT__f_s_f_s, NULL, PRIM_INT__g_s_g_s);



                    // Forming PRIM_INT__s_s_p_s[6 * 3];
                    for(n = 0; n < 6; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_p_s[n * 3 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_p_s[n * 3 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_p_s[n * 3 + 0]);

                        PRIM_INT__s_s_p_s[n * 3 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_p_s[n * 3 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_p_s[n * 3 + 1]);

                        PRIM_INT__s_s_p_s[n * 3 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_s_s[n * 1 + 0]);
                        PRIM_INT__s_s_p_s[n * 3 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_p_s[n * 3 + 2]);

                    }



                    // Forming PRIM_INT__p_s_d_s[5 * 18];
                    for(n = 0; n < 5; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__p_s_d_s[n * 18 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__p_s_p_s[n * 9 + 0]);
                        PRIM_INT__p_s_d_s[n * 18 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__p_s_p_s[(n+1) * 9 + 0], PRIM_INT__p_s_d_s[n * 18 + 0]);
                        PRIM_INT__p_s_d_s[n * 18 + 0] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__p_s_s_s[n * 3 + 0]), PRIM_INT__p_s_d_s[n * 18 + 0]);
                        PRIM_INT__p_s_d_s[n * 18 + 0] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__p_s_d_s[n * 18 + 0]);

                        PRIM_INT__p_s_d_s[n * 18 + 3] = SIMINT_MUL(Q_PA[1], PRIM_INT__p_s_p_s[n * 9 + 1]);
                        PRIM_INT__p_s_d_s[n * 18 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__p_s_p_s[(n+1) * 9 + 1], PRIM_INT__p_s_d_s[n * 18 + 3]);
                        PRIM_INT__p_s_d_s[n * 18 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__p_s_s_s[n * 3 + 0]), PRIM_INT__p_s_d_s[n * 18 + 3]);

                        PRIM_INT__p_s_d_s[n * 18 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__p_s_p_s[n * 9 + 2]);
                        PRIM_INT__p_s_d_s[n * 18 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__p_s_p_s[(n+1) * 9 + 2], PRIM_INT__p_s_d_s[n * 18 + 5]);
                        PRIM_INT__p_s_d_s[n * 18 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_s_s[(n+1) * 3 + 0], PRIM_INT__p_s_s_s[n * 3 + 0]), PRIM_INT__p_s_d_s[n * 18 + 5]);

                        PRIM_INT__p_s_d_s[n * 18 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__p_s_p_s[n * 9 + 3]);
                        PRIM_INT__p_s_d_s[n * 18 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__p_s_p_s[(n+1) * 9 + 3], PRIM_INT__p_s_d_s[n * 18 + 6]);
                        PRIM_INT__p_s_d_s[n * 18 + 6] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__p_s_s_s[n * 3 + 1]), PRIM_INT__p_s_d_s[n * 18 + 6]);

                        PRIM_INT__p_s_d_s[n * 18 + 9] = SIMINT_MUL(Q_PA[1], PRIM_INT__p_s_p_s[n * 9 + 4]);
                        PRIM_INT__p_s_d_s[n * 18 + 9] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__p_s_p_s[(n+1) * 9 + 4], PRIM_INT__p_s_d_s[n * 18 + 9]);
                        PRIM_INT__p_s_d_s[n * 18 + 9] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__p_s_s_s[n * 3 + 1]), PRIM_INT__p_s_d_s[n * 18 + 9]);
                        PRIM_INT__p_s_d_s[n * 18 + 9] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__p_s_d_s[n * 18 + 9]);

                        PRIM_INT__p_s_d_s[n * 18 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__p_s_p_s[n * 9 + 5]);
                        PRIM_INT__p_s_d_s[n * 18 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__p_s_p_s[(n+1) * 9 + 5], PRIM_INT__p_s_d_s[n * 18 + 11]);
                        PRIM_INT__p_s_d_s[n * 18 + 11] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_s_s[(n+1) * 3 + 1], PRIM_INT__p_s_s_s[n * 3 + 1]), PRIM_INT__p_s_d_s[n * 18 + 11]);

                        PRIM_INT__p_s_d_s[n * 18 + 12] = SIMINT_MUL(Q_PA[0], PRIM_INT__p_s_p_s[n * 9 + 6]);
                        PRIM_INT__p_s_d_s[n * 18 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__p_s_p_s[(n+1) * 9 + 6], PRIM_INT__p_s_d_s[n * 18 + 12]);
                        PRIM_INT__p_s_d_s[n * 18 + 12] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__p_s_s_s[n * 3 + 2]), PRIM_INT__p_s_d_s[n * 18 + 12]);

                        PRIM_INT__p_s_d_s[n * 18 + 15] = SIMINT_MUL(Q_PA[1], PRIM_INT__p_s_p_s[n * 9 + 7]);
                        PRIM_INT__p_s_d_s[n * 18 + 15] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__p_s_p_s[(n+1) * 9 + 7], PRIM_INT__p_s_d_s[n * 18 + 15]);
                        PRIM_INT__p_s_d_s[n * 18 + 15] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__p_s_s_s[n * 3 + 2]), PRIM_INT__p_s_d_s[n * 18 + 15]);

                        PRIM_INT__p_s_d_s[n * 18 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__p_s_p_s[n * 9 + 8]);
                        PRIM_INT__p_s_d_s[n * 18 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__p_s_p_s[(n+1) * 9 + 8], PRIM_INT__p_s_d_s[n * 18 + 17]);
                        PRIM_INT__p_s_d_s[n * 18 + 17] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_s_s[(n+1) * 3 + 2], PRIM_INT__p_s_s_s[n * 3 + 2]), PRIM_INT__p_s_d_s[n * 18 + 17]);
                        PRIM_INT__p_s_d_s[n * 18 + 17] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__p_s_d_s[n * 18 + 17]);

                    }


                    VRR_K_d_s_f_s(
                            PRIM_INT__d_s_f_s,
                            PRIM_INT__d_s_d_s,
                            PRIM_INT__d_s_p_s,
                            PRIM_INT__p_s_d_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            4);


                    VRR_K_f_s_g_s(
                            PRIM_INT__f_s_g_s,
                            PRIM_INT__f_s_f_s,
                            PRIM_INT__f_s_d_s,
                            PRIM_INT__d_s_f_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            3);


                    ostei_general_vrr_K(4, 0, 5, 0, 2,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__g_s_g_s, PRIM_INT__g_s_f_s, NULL, PRIM_INT__f_s_g_s, NULL, PRIM_INT__g_s_h_s);


                    VRR_I_h_s_s_s(
                            PRIM_INT__h_s_s_s,
                            PRIM_INT__g_s_s_s,
                            PRIM_INT__f_s_s_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            8);


                    VRR_K_h_s_p_s(
                            PRIM_INT__h_s_p_s,
                            PRIM_INT__h_s_s_s,
                            PRIM_INT__g_s_s_s,
                            Q_PA,
                            aoq_PQ,
                            one_over_2pq,
                            6);


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
                            5);


                    ostei_general_vrr_K(5, 0, 3, 0, 4,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__h_s_d_s, PRIM_INT__h_s_p_s, NULL, PRIM_INT__g_s_d_s, NULL, PRIM_INT__h_s_f_s);


                    ostei_general_vrr_K(5, 0, 4, 0, 3,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__h_s_f_s, PRIM_INT__h_s_d_s, NULL, PRIM_INT__g_s_f_s, NULL, PRIM_INT__h_s_g_s);



                    // Forming PRIM_INT__s_s_d_s[5 * 6];
                    for(n = 0; n < 5; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_d_s[n * 6 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_p_s[n * 3 + 0]);
                        PRIM_INT__s_s_d_s[n * 6 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_p_s[(n+1) * 3 + 0], PRIM_INT__s_s_d_s[n * 6 + 0]);
                        PRIM_INT__s_s_d_s[n * 6 + 0] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_s_d_s[n * 6 + 0]);

                        PRIM_INT__s_s_d_s[n * 6 + 3] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_p_s[n * 3 + 1]);
                        PRIM_INT__s_s_d_s[n * 6 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_p_s[(n+1) * 3 + 1], PRIM_INT__s_s_d_s[n * 6 + 3]);
                        PRIM_INT__s_s_d_s[n * 6 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_s_d_s[n * 6 + 3]);

                        PRIM_INT__s_s_d_s[n * 6 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_p_s[n * 3 + 2]);
                        PRIM_INT__s_s_d_s[n * 6 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_p_s[(n+1) * 3 + 2], PRIM_INT__s_s_d_s[n * 6 + 5]);
                        PRIM_INT__s_s_d_s[n * 6 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_s_s[(n+1) * 1 + 0], PRIM_INT__s_s_s_s[n * 1 + 0]), PRIM_INT__s_s_d_s[n * 6 + 5]);

                    }



                    // Forming PRIM_INT__p_s_f_s[4 * 30];
                    for(n = 0; n < 4; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__p_s_f_s[n * 30 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__p_s_d_s[n * 18 + 0]);
                        PRIM_INT__p_s_f_s[n * 30 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__p_s_d_s[(n+1) * 18 + 0], PRIM_INT__p_s_f_s[n * 30 + 0]);
                        PRIM_INT__p_s_f_s[n * 30 + 0] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_p_s[(n+1) * 9 + 0], PRIM_INT__p_s_p_s[n * 9 + 0]), PRIM_INT__p_s_f_s[n * 30 + 0]);
                        PRIM_INT__p_s_f_s[n * 30 + 0] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__p_s_f_s[n * 30 + 0]);

                        PRIM_INT__p_s_f_s[n * 30 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__p_s_d_s[n * 18 + 0]);
                        PRIM_INT__p_s_f_s[n * 30 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__p_s_d_s[(n+1) * 18 + 0], PRIM_INT__p_s_f_s[n * 30 + 1]);

                        PRIM_INT__p_s_f_s[n * 30 + 6] = SIMINT_MUL(Q_PA[1], PRIM_INT__p_s_d_s[n * 18 + 3]);
                        PRIM_INT__p_s_f_s[n * 30 + 6] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__p_s_d_s[(n+1) * 18 + 3], PRIM_INT__p_s_f_s[n * 30 + 6]);
                        PRIM_INT__p_s_f_s[n * 30 + 6] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_p_s[(n+1) * 9 + 1], PRIM_INT__p_s_p_s[n * 9 + 1]), PRIM_INT__p_s_f_s[n * 30 + 6]);

                        PRIM_INT__p_s_f_s[n * 30 + 9] = SIMINT_MUL(Q_PA[2], PRIM_INT__p_s_d_s[n * 18 + 5]);
                        PRIM_INT__p_s_f_s[n * 30 + 9] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__p_s_d_s[(n+1) * 18 + 5], PRIM_INT__p_s_f_s[n * 30 + 9]);
                        PRIM_INT__p_s_f_s[n * 30 + 9] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_p_s[(n+1) * 9 + 2], PRIM_INT__p_s_p_s[n * 9 + 2]), PRIM_INT__p_s_f_s[n * 30 + 9]);

                        PRIM_INT__p_s_f_s[n * 30 + 10] = SIMINT_MUL(Q_PA[0], PRIM_INT__p_s_d_s[n * 18 + 6]);
                        PRIM_INT__p_s_f_s[n * 30 + 10] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__p_s_d_s[(n+1) * 18 + 6], PRIM_INT__p_s_f_s[n * 30 + 10]);
                        PRIM_INT__p_s_f_s[n * 30 + 10] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_p_s[(n+1) * 9 + 3], PRIM_INT__p_s_p_s[n * 9 + 3]), PRIM_INT__p_s_f_s[n * 30 + 10]);

                        PRIM_INT__p_s_f_s[n * 30 + 11] = SIMINT_MUL(Q_PA[1], PRIM_INT__p_s_d_s[n * 18 + 6]);
                        PRIM_INT__p_s_f_s[n * 30 + 11] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__p_s_d_s[(n+1) * 18 + 6], PRIM_INT__p_s_f_s[n * 30 + 11]);
                        PRIM_INT__p_s_f_s[n * 30 + 11] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 0], PRIM_INT__p_s_f_s[n * 30 + 11]);

                        PRIM_INT__p_s_f_s[n * 30 + 16] = SIMINT_MUL(Q_PA[1], PRIM_INT__p_s_d_s[n * 18 + 9]);
                        PRIM_INT__p_s_f_s[n * 30 + 16] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__p_s_d_s[(n+1) * 18 + 9], PRIM_INT__p_s_f_s[n * 30 + 16]);
                        PRIM_INT__p_s_f_s[n * 30 + 16] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_p_s[(n+1) * 9 + 4], PRIM_INT__p_s_p_s[n * 9 + 4]), PRIM_INT__p_s_f_s[n * 30 + 16]);
                        PRIM_INT__p_s_f_s[n * 30 + 16] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 3], PRIM_INT__p_s_f_s[n * 30 + 16]);

                        PRIM_INT__p_s_f_s[n * 30 + 19] = SIMINT_MUL(Q_PA[2], PRIM_INT__p_s_d_s[n * 18 + 11]);
                        PRIM_INT__p_s_f_s[n * 30 + 19] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__p_s_d_s[(n+1) * 18 + 11], PRIM_INT__p_s_f_s[n * 30 + 19]);
                        PRIM_INT__p_s_f_s[n * 30 + 19] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_p_s[(n+1) * 9 + 5], PRIM_INT__p_s_p_s[n * 9 + 5]), PRIM_INT__p_s_f_s[n * 30 + 19]);

                        PRIM_INT__p_s_f_s[n * 30 + 20] = SIMINT_MUL(Q_PA[0], PRIM_INT__p_s_d_s[n * 18 + 12]);
                        PRIM_INT__p_s_f_s[n * 30 + 20] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__p_s_d_s[(n+1) * 18 + 12], PRIM_INT__p_s_f_s[n * 30 + 20]);
                        PRIM_INT__p_s_f_s[n * 30 + 20] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_p_s[(n+1) * 9 + 6], PRIM_INT__p_s_p_s[n * 9 + 6]), PRIM_INT__p_s_f_s[n * 30 + 20]);

                        PRIM_INT__p_s_f_s[n * 30 + 21] = SIMINT_MUL(Q_PA[1], PRIM_INT__p_s_d_s[n * 18 + 12]);
                        PRIM_INT__p_s_f_s[n * 30 + 21] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__p_s_d_s[(n+1) * 18 + 12], PRIM_INT__p_s_f_s[n * 30 + 21]);

                        PRIM_INT__p_s_f_s[n * 30 + 26] = SIMINT_MUL(Q_PA[1], PRIM_INT__p_s_d_s[n * 18 + 15]);
                        PRIM_INT__p_s_f_s[n * 30 + 26] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__p_s_d_s[(n+1) * 18 + 15], PRIM_INT__p_s_f_s[n * 30 + 26]);
                        PRIM_INT__p_s_f_s[n * 30 + 26] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_p_s[(n+1) * 9 + 7], PRIM_INT__p_s_p_s[n * 9 + 7]), PRIM_INT__p_s_f_s[n * 30 + 26]);

                        PRIM_INT__p_s_f_s[n * 30 + 29] = SIMINT_MUL(Q_PA[2], PRIM_INT__p_s_d_s[n * 18 + 17]);
                        PRIM_INT__p_s_f_s[n * 30 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__p_s_d_s[(n+1) * 18 + 17], PRIM_INT__p_s_f_s[n * 30 + 29]);
                        PRIM_INT__p_s_f_s[n * 30 + 29] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__p_s_p_s[(n+1) * 9 + 8], PRIM_INT__p_s_p_s[n * 9 + 8]), PRIM_INT__p_s_f_s[n * 30 + 29]);
                        PRIM_INT__p_s_f_s[n * 30 + 29] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_d_s[(n+1) * 6 + 5], PRIM_INT__p_s_f_s[n * 30 + 29]);

                    }


                    VRR_K_d_s_g_s(
                            PRIM_INT__d_s_g_s,
                            PRIM_INT__d_s_f_s,
                            PRIM_INT__d_s_d_s,
                            PRIM_INT__p_s_f_s,
                            Q_PA,
                            a_over_q,
                            aoq_PQ,
                            one_over_2pq,
                            one_over_2q,
                            3);


                    ostei_general_vrr_K(3, 0, 5, 0, 2,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__f_s_g_s, PRIM_INT__f_s_f_s, NULL, PRIM_INT__d_s_g_s, NULL, PRIM_INT__f_s_h_s);


                    ostei_general_vrr_K(4, 0, 6, 0, 1,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__g_s_h_s, PRIM_INT__g_s_g_s, NULL, PRIM_INT__f_s_h_s, NULL, PRIM_INT__g_s_i_s);


                    ostei_general_vrr_K(5, 0, 5, 0, 2,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__h_s_g_s, PRIM_INT__h_s_f_s, NULL, PRIM_INT__g_s_g_s, NULL, PRIM_INT__h_s_h_s);


                    VRR_I_i_s_s_s(
                            PRIM_INT__i_s_s_s,
                            PRIM_INT__h_s_s_s,
                            PRIM_INT__g_s_s_s,
                            P_PA,
                            a_over_p,
                            aop_PQ,
                            one_over_2p,
                            7);


                    VRR_K_i_s_p_s(
                            PRIM_INT__i_s_p_s,
                            PRIM_INT__i_s_s_s,
                            PRIM_INT__h_s_s_s,
                            Q_PA,
                            aoq_PQ,
                            one_over_2pq,
                            6);


                    ostei_general_vrr_K(6, 0, 2, 0, 5,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__i_s_p_s, PRIM_INT__i_s_s_s, NULL, PRIM_INT__h_s_p_s, NULL, PRIM_INT__i_s_d_s);


                    ostei_general_vrr_K(6, 0, 3, 0, 4,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__i_s_d_s, PRIM_INT__i_s_p_s, NULL, PRIM_INT__h_s_d_s, NULL, PRIM_INT__i_s_f_s);


                    ostei_general_vrr_K(6, 0, 4, 0, 3,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__i_s_f_s, PRIM_INT__i_s_d_s, NULL, PRIM_INT__h_s_f_s, NULL, PRIM_INT__i_s_g_s);


                    ostei_general_vrr_K(5, 0, 6, 0, 1,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__h_s_h_s, PRIM_INT__h_s_g_s, NULL, PRIM_INT__g_s_h_s, NULL, PRIM_INT__h_s_i_s);


                    ostei_general_vrr_K(6, 0, 5, 0, 2,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__i_s_g_s, PRIM_INT__i_s_f_s, NULL, PRIM_INT__h_s_g_s, NULL, PRIM_INT__i_s_h_s);


                    ostei_general_vrr_K(6, 0, 6, 0, 1,
                            one_over_2q, a_over_q, one_over_2pq, aoq_PQ, Q_PA,
                            PRIM_INT__i_s_h_s, PRIM_INT__i_s_g_s, NULL, PRIM_INT__h_s_h_s, NULL, PRIM_INT__i_s_i_s);




                    ////////////////////////////////////
                    // Accumulate contracted integrals
                    ////////////////////////////////////
                    if(lastoffset == 0)
                    {
                        contract_all(225, PRIM_INT__g_s_g_s, PRIM_PTR_INT__g_s_g_s);
                        contract_all(315, PRIM_INT__g_s_h_s, PRIM_PTR_INT__g_s_h_s);
                        contract_all(420, PRIM_INT__g_s_i_s, PRIM_PTR_INT__g_s_i_s);
                        contract_all(315, PRIM_INT__h_s_g_s, PRIM_PTR_INT__h_s_g_s);
                        contract_all(441, PRIM_INT__h_s_h_s, PRIM_PTR_INT__h_s_h_s);
                        contract_all(588, PRIM_INT__h_s_i_s, PRIM_PTR_INT__h_s_i_s);
                        contract_all(420, PRIM_INT__i_s_g_s, PRIM_PTR_INT__i_s_g_s);
                        contract_all(588, PRIM_INT__i_s_h_s, PRIM_PTR_INT__i_s_h_s);
                        contract_all(784, PRIM_INT__i_s_i_s, PRIM_PTR_INT__i_s_i_s);
                    }
                    else
                    {
                        contract(225, shelloffsets, PRIM_INT__g_s_g_s, PRIM_PTR_INT__g_s_g_s);
                        contract(315, shelloffsets, PRIM_INT__g_s_h_s, PRIM_PTR_INT__g_s_h_s);
                        contract(420, shelloffsets, PRIM_INT__g_s_i_s, PRIM_PTR_INT__g_s_i_s);
                        contract(315, shelloffsets, PRIM_INT__h_s_g_s, PRIM_PTR_INT__h_s_g_s);
                        contract(441, shelloffsets, PRIM_INT__h_s_h_s, PRIM_PTR_INT__h_s_h_s);
                        contract(588, shelloffsets, PRIM_INT__h_s_i_s, PRIM_PTR_INT__h_s_i_s);
                        contract(420, shelloffsets, PRIM_INT__i_s_g_s, PRIM_PTR_INT__i_s_g_s);
                        contract(588, shelloffsets, PRIM_INT__i_s_h_s, PRIM_PTR_INT__i_s_h_s);
                        contract(784, shelloffsets, PRIM_INT__i_s_i_s, PRIM_PTR_INT__i_s_i_s);
                        PRIM_PTR_INT__g_s_g_s += lastoffset*225;
                        PRIM_PTR_INT__g_s_h_s += lastoffset*315;
                        PRIM_PTR_INT__g_s_i_s += lastoffset*420;
                        PRIM_PTR_INT__h_s_g_s += lastoffset*315;
                        PRIM_PTR_INT__h_s_h_s += lastoffset*441;
                        PRIM_PTR_INT__h_s_i_s += lastoffset*588;
                        PRIM_PTR_INT__i_s_g_s += lastoffset*420;
                        PRIM_PTR_INT__i_s_h_s += lastoffset*588;
                        PRIM_PTR_INT__i_s_i_s += lastoffset*784;
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
                double const * restrict HRR_INT__g_s_g_s = INT__g_s_g_s + abcd * 225;
                double const * restrict HRR_INT__g_s_h_s = INT__g_s_h_s + abcd * 315;
                double const * restrict HRR_INT__g_s_i_s = INT__g_s_i_s + abcd * 420;
                double const * restrict HRR_INT__h_s_g_s = INT__h_s_g_s + abcd * 315;
                double const * restrict HRR_INT__h_s_h_s = INT__h_s_h_s + abcd * 441;
                double const * restrict HRR_INT__h_s_i_s = INT__h_s_i_s + abcd * 588;
                double const * restrict HRR_INT__i_s_g_s = INT__i_s_g_s + abcd * 420;
                double const * restrict HRR_INT__i_s_h_s = INT__i_s_h_s + abcd * 588;
                double const * restrict HRR_INT__i_s_i_s = INT__i_s_i_s + abcd * 784;
                double * restrict HRR_INT__g_d_g_d = INT__g_d_g_d + real_abcd * 8100;

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

                // form INT__g_d_g_p
                HRR_L_g_p(
                    HRR_INT__g_d_g_p,
                    HRR_INT__g_d_g_s,
                    HRR_INT__g_d_h_s,
                    hCD, 90);

                // form INT__g_d_h_p
                HRR_L_h_p(
                    HRR_INT__g_d_h_p,
                    HRR_INT__g_d_h_s,
                    HRR_INT__g_d_i_s,
                    hCD, 90);

                // form INT__g_d_g_d
                HRR_L_g_d(
                    HRR_INT__g_d_g_d,
                    HRR_INT__g_d_g_p,
                    HRR_INT__g_d_h_p,
                    hCD, 90);


            }  // close HRR loop


        }   // close loop cdbatch

        istart = iend;
    }  // close loop over ab

    return P.nshell12_clip * Q.nshell12_clip;
}

int ostei_d_g_g_d(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__d_g_g_d)
{
    double P_AB[3*P.nshell12];
    struct simint_multi_shellpair P_tmp = P;
    P_tmp.PA_x = P.PB_x;  P_tmp.PA_y = P.PB_y;  P_tmp.PA_z = P.PB_z;
    P_tmp.PB_x = P.PA_x;  P_tmp.PB_y = P.PA_y;  P_tmp.PB_z = P.PA_z;
    P_tmp.AB_x = P_AB;
    P_tmp.AB_y = P_AB + P.nshell12;
    P_tmp.AB_z = P_AB + 2*P.nshell12;

    for(int i = 0; i < P.nshell12; i++)
    {
        P_tmp.AB_x[i] = -P.AB_x[i];
        P_tmp.AB_y[i] = -P.AB_y[i];
        P_tmp.AB_z[i] = -P.AB_z[i];
    }

    int ret = ostei_g_d_g_d(P_tmp, Q, screen_tol, work, INT__d_g_g_d);
    double buffer[8100] SIMINT_ALIGN_ARRAY_DBL;

    for(int q = 0; q < ret; q++)
    {
        int idx = 0;
        for(int a = 0; a < 6; ++a)
        for(int b = 0; b < 15; ++b)
        for(int c = 0; c < 15; ++c)
        for(int d = 0; d < 6; ++d)
            buffer[idx++] = INT__d_g_g_d[q*8100+b*540+a*90+c*6+d];

        memcpy(INT__d_g_g_d+q*8100, buffer, 8100*sizeof(double));
    }

    return ret;
}

int ostei_g_d_d_g(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__g_d_d_g)
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

    int ret = ostei_g_d_g_d(P, Q_tmp, screen_tol, work, INT__g_d_d_g);
    double buffer[8100] SIMINT_ALIGN_ARRAY_DBL;

    for(int q = 0; q < ret; q++)
    {
        int idx = 0;
        for(int a = 0; a < 15; ++a)
        for(int b = 0; b < 6; ++b)
        for(int c = 0; c < 6; ++c)
        for(int d = 0; d < 15; ++d)
            buffer[idx++] = INT__g_d_d_g[q*8100+a*540+b*90+d*6+c];

        memcpy(INT__g_d_d_g+q*8100, buffer, 8100*sizeof(double));
    }

    return ret;
}

int ostei_d_g_d_g(struct simint_multi_shellpair const P,
                  struct simint_multi_shellpair const Q,
                  double screen_tol,
                  double * const restrict work,
                  double * const restrict INT__d_g_d_g)
{
    double P_AB[3*P.nshell12];
    struct simint_multi_shellpair P_tmp = P;
    P_tmp.PA_x = P.PB_x;  P_tmp.PA_y = P.PB_y;  P_tmp.PA_z = P.PB_z;
    P_tmp.PB_x = P.PA_x;  P_tmp.PB_y = P.PA_y;  P_tmp.PB_z = P.PA_z;
    P_tmp.AB_x = P_AB;
    P_tmp.AB_y = P_AB + P.nshell12;
    P_tmp.AB_z = P_AB + 2*P.nshell12;

    for(int i = 0; i < P.nshell12; i++)
    {
        P_tmp.AB_x[i] = -P.AB_x[i];
        P_tmp.AB_y[i] = -P.AB_y[i];
        P_tmp.AB_z[i] = -P.AB_z[i];
    }

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

    int ret = ostei_g_d_g_d(P_tmp, Q_tmp, screen_tol, work, INT__d_g_d_g);
    double buffer[8100] SIMINT_ALIGN_ARRAY_DBL;

    for(int q = 0; q < ret; q++)
    {
        int idx = 0;
        for(int a = 0; a < 6; ++a)
        for(int b = 0; b < 15; ++b)
        for(int c = 0; c < 6; ++c)
        for(int d = 0; d < 15; ++d)
            buffer[idx++] = INT__d_g_d_g[q*8100+b*540+a*90+d*6+c];

        memcpy(INT__d_g_d_g+q*8100, buffer, 8100*sizeof(double));
    }

    return ret;
}

