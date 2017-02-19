
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( h s | d s )
//////////////////////////////////////////////
void VRR_I_h_s_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_p_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n)
{
    int n = 0;
    const SIMINT_DBLTYPE vrr_const_1_over_2p = SIMINT_MUL(SIMINT_DBLSET1(1), one_over_2p);
    const SIMINT_DBLTYPE vrr_const_4_over_2p = SIMINT_MUL(SIMINT_DBLSET1(4), one_over_2p);
    const SIMINT_DBLTYPE vrr_const_1_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(1), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(2), one_over_2pq);

                    // Forming PRIM_INT__h_s_d_s[num_n * 126];
                    for(n = 0; n < num_n; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__h_s_d_s[n * 126 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 0]);
                        PRIM_INT__h_s_d_s[n * 126 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 0], PRIM_INT__h_s_d_s[n * 126 + 0]);
                        PRIM_INT__h_s_d_s[n * 126 + 0] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 0], PRIM_INT__f_s_d_s[n * 60 + 0]), PRIM_INT__h_s_d_s[n * 126 + 0]);
                        PRIM_INT__h_s_d_s[n * 126 + 0] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 0], PRIM_INT__h_s_d_s[n * 126 + 0]);

                        PRIM_INT__h_s_d_s[n * 126 + 1] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 1]);
                        PRIM_INT__h_s_d_s[n * 126 + 1] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 1], PRIM_INT__h_s_d_s[n * 126 + 1]);
                        PRIM_INT__h_s_d_s[n * 126 + 1] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 1], PRIM_INT__f_s_d_s[n * 60 + 1]), PRIM_INT__h_s_d_s[n * 126 + 1]);
                        PRIM_INT__h_s_d_s[n * 126 + 1] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 1], PRIM_INT__h_s_d_s[n * 126 + 1]);

                        PRIM_INT__h_s_d_s[n * 126 + 2] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 2]);
                        PRIM_INT__h_s_d_s[n * 126 + 2] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 2], PRIM_INT__h_s_d_s[n * 126 + 2]);
                        PRIM_INT__h_s_d_s[n * 126 + 2] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 2], PRIM_INT__f_s_d_s[n * 60 + 2]), PRIM_INT__h_s_d_s[n * 126 + 2]);
                        PRIM_INT__h_s_d_s[n * 126 + 2] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 2], PRIM_INT__h_s_d_s[n * 126 + 2]);

                        PRIM_INT__h_s_d_s[n * 126 + 3] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 3]);
                        PRIM_INT__h_s_d_s[n * 126 + 3] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 3], PRIM_INT__h_s_d_s[n * 126 + 3]);
                        PRIM_INT__h_s_d_s[n * 126 + 3] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 3], PRIM_INT__f_s_d_s[n * 60 + 3]), PRIM_INT__h_s_d_s[n * 126 + 3]);

                        PRIM_INT__h_s_d_s[n * 126 + 4] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 4]);
                        PRIM_INT__h_s_d_s[n * 126 + 4] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 4], PRIM_INT__h_s_d_s[n * 126 + 4]);
                        PRIM_INT__h_s_d_s[n * 126 + 4] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 4], PRIM_INT__f_s_d_s[n * 60 + 4]), PRIM_INT__h_s_d_s[n * 126 + 4]);

                        PRIM_INT__h_s_d_s[n * 126 + 5] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 5]);
                        PRIM_INT__h_s_d_s[n * 126 + 5] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 5], PRIM_INT__h_s_d_s[n * 126 + 5]);
                        PRIM_INT__h_s_d_s[n * 126 + 5] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 5], PRIM_INT__f_s_d_s[n * 60 + 5]), PRIM_INT__h_s_d_s[n * 126 + 5]);

                        PRIM_INT__h_s_d_s[n * 126 + 6] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 0]);
                        PRIM_INT__h_s_d_s[n * 126 + 6] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 0], PRIM_INT__h_s_d_s[n * 126 + 6]);

                        PRIM_INT__h_s_d_s[n * 126 + 7] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 1]);
                        PRIM_INT__h_s_d_s[n * 126 + 7] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 1], PRIM_INT__h_s_d_s[n * 126 + 7]);
                        PRIM_INT__h_s_d_s[n * 126 + 7] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 0], PRIM_INT__h_s_d_s[n * 126 + 7]);

                        PRIM_INT__h_s_d_s[n * 126 + 8] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 2]);
                        PRIM_INT__h_s_d_s[n * 126 + 8] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 2], PRIM_INT__h_s_d_s[n * 126 + 8]);

                        PRIM_INT__h_s_d_s[n * 126 + 9] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 3]);
                        PRIM_INT__h_s_d_s[n * 126 + 9] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 3], PRIM_INT__h_s_d_s[n * 126 + 9]);
                        PRIM_INT__h_s_d_s[n * 126 + 9] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 1], PRIM_INT__h_s_d_s[n * 126 + 9]);

                        PRIM_INT__h_s_d_s[n * 126 + 10] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 4]);
                        PRIM_INT__h_s_d_s[n * 126 + 10] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 4], PRIM_INT__h_s_d_s[n * 126 + 10]);
                        PRIM_INT__h_s_d_s[n * 126 + 10] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 2], PRIM_INT__h_s_d_s[n * 126 + 10]);

                        PRIM_INT__h_s_d_s[n * 126 + 11] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 5]);
                        PRIM_INT__h_s_d_s[n * 126 + 11] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 5], PRIM_INT__h_s_d_s[n * 126 + 11]);

                        PRIM_INT__h_s_d_s[n * 126 + 12] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 0]);
                        PRIM_INT__h_s_d_s[n * 126 + 12] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 0], PRIM_INT__h_s_d_s[n * 126 + 12]);

                        PRIM_INT__h_s_d_s[n * 126 + 13] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 1]);
                        PRIM_INT__h_s_d_s[n * 126 + 13] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 1], PRIM_INT__h_s_d_s[n * 126 + 13]);

                        PRIM_INT__h_s_d_s[n * 126 + 14] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 2]);
                        PRIM_INT__h_s_d_s[n * 126 + 14] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 2], PRIM_INT__h_s_d_s[n * 126 + 14]);
                        PRIM_INT__h_s_d_s[n * 126 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 0], PRIM_INT__h_s_d_s[n * 126 + 14]);

                        PRIM_INT__h_s_d_s[n * 126 + 15] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 3]);
                        PRIM_INT__h_s_d_s[n * 126 + 15] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 3], PRIM_INT__h_s_d_s[n * 126 + 15]);

                        PRIM_INT__h_s_d_s[n * 126 + 16] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 4]);
                        PRIM_INT__h_s_d_s[n * 126 + 16] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 4], PRIM_INT__h_s_d_s[n * 126 + 16]);
                        PRIM_INT__h_s_d_s[n * 126 + 16] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 1], PRIM_INT__h_s_d_s[n * 126 + 16]);

                        PRIM_INT__h_s_d_s[n * 126 + 17] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 5]);
                        PRIM_INT__h_s_d_s[n * 126 + 17] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 5], PRIM_INT__h_s_d_s[n * 126 + 17]);
                        PRIM_INT__h_s_d_s[n * 126 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 2], PRIM_INT__h_s_d_s[n * 126 + 17]);

                        PRIM_INT__h_s_d_s[n * 126 + 18] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 6]);
                        PRIM_INT__h_s_d_s[n * 126 + 18] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 6], PRIM_INT__h_s_d_s[n * 126 + 18]);
                        PRIM_INT__h_s_d_s[n * 126 + 18] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 0], PRIM_INT__f_s_d_s[n * 60 + 0]), PRIM_INT__h_s_d_s[n * 126 + 18]);

                        PRIM_INT__h_s_d_s[n * 126 + 19] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 7]);
                        PRIM_INT__h_s_d_s[n * 126 + 19] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 7], PRIM_INT__h_s_d_s[n * 126 + 19]);
                        PRIM_INT__h_s_d_s[n * 126 + 19] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 1], PRIM_INT__f_s_d_s[n * 60 + 1]), PRIM_INT__h_s_d_s[n * 126 + 19]);
                        PRIM_INT__h_s_d_s[n * 126 + 19] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 3], PRIM_INT__h_s_d_s[n * 126 + 19]);

                        PRIM_INT__h_s_d_s[n * 126 + 20] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 8]);
                        PRIM_INT__h_s_d_s[n * 126 + 20] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 8], PRIM_INT__h_s_d_s[n * 126 + 20]);
                        PRIM_INT__h_s_d_s[n * 126 + 20] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 2], PRIM_INT__f_s_d_s[n * 60 + 2]), PRIM_INT__h_s_d_s[n * 126 + 20]);

                        PRIM_INT__h_s_d_s[n * 126 + 21] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 9]);
                        PRIM_INT__h_s_d_s[n * 126 + 21] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 9], PRIM_INT__h_s_d_s[n * 126 + 21]);
                        PRIM_INT__h_s_d_s[n * 126 + 21] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 3], PRIM_INT__f_s_d_s[n * 60 + 3]), PRIM_INT__h_s_d_s[n * 126 + 21]);
                        PRIM_INT__h_s_d_s[n * 126 + 21] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 4], PRIM_INT__h_s_d_s[n * 126 + 21]);

                        PRIM_INT__h_s_d_s[n * 126 + 22] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 10]);
                        PRIM_INT__h_s_d_s[n * 126 + 22] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 10], PRIM_INT__h_s_d_s[n * 126 + 22]);
                        PRIM_INT__h_s_d_s[n * 126 + 22] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 4], PRIM_INT__f_s_d_s[n * 60 + 4]), PRIM_INT__h_s_d_s[n * 126 + 22]);
                        PRIM_INT__h_s_d_s[n * 126 + 22] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 5], PRIM_INT__h_s_d_s[n * 126 + 22]);

                        PRIM_INT__h_s_d_s[n * 126 + 23] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 11]);
                        PRIM_INT__h_s_d_s[n * 126 + 23] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 11], PRIM_INT__h_s_d_s[n * 126 + 23]);
                        PRIM_INT__h_s_d_s[n * 126 + 23] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 5], PRIM_INT__f_s_d_s[n * 60 + 5]), PRIM_INT__h_s_d_s[n * 126 + 23]);

                        PRIM_INT__h_s_d_s[n * 126 + 24] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 6]);
                        PRIM_INT__h_s_d_s[n * 126 + 24] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 6], PRIM_INT__h_s_d_s[n * 126 + 24]);

                        PRIM_INT__h_s_d_s[n * 126 + 25] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 7]);
                        PRIM_INT__h_s_d_s[n * 126 + 25] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 7], PRIM_INT__h_s_d_s[n * 126 + 25]);

                        PRIM_INT__h_s_d_s[n * 126 + 26] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 8]);
                        PRIM_INT__h_s_d_s[n * 126 + 26] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 8], PRIM_INT__h_s_d_s[n * 126 + 26]);
                        PRIM_INT__h_s_d_s[n * 126 + 26] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 3], PRIM_INT__h_s_d_s[n * 126 + 26]);

                        PRIM_INT__h_s_d_s[n * 126 + 27] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 9]);
                        PRIM_INT__h_s_d_s[n * 126 + 27] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 9], PRIM_INT__h_s_d_s[n * 126 + 27]);

                        PRIM_INT__h_s_d_s[n * 126 + 28] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 10]);
                        PRIM_INT__h_s_d_s[n * 126 + 28] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 10], PRIM_INT__h_s_d_s[n * 126 + 28]);
                        PRIM_INT__h_s_d_s[n * 126 + 28] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 4], PRIM_INT__h_s_d_s[n * 126 + 28]);

                        PRIM_INT__h_s_d_s[n * 126 + 29] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 11]);
                        PRIM_INT__h_s_d_s[n * 126 + 29] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 11], PRIM_INT__h_s_d_s[n * 126 + 29]);
                        PRIM_INT__h_s_d_s[n * 126 + 29] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 5], PRIM_INT__h_s_d_s[n * 126 + 29]);

                        PRIM_INT__h_s_d_s[n * 126 + 30] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 12]);
                        PRIM_INT__h_s_d_s[n * 126 + 30] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 12], PRIM_INT__h_s_d_s[n * 126 + 30]);
                        PRIM_INT__h_s_d_s[n * 126 + 30] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 0], PRIM_INT__f_s_d_s[n * 60 + 0]), PRIM_INT__h_s_d_s[n * 126 + 30]);

                        PRIM_INT__h_s_d_s[n * 126 + 31] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 13]);
                        PRIM_INT__h_s_d_s[n * 126 + 31] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 13], PRIM_INT__h_s_d_s[n * 126 + 31]);
                        PRIM_INT__h_s_d_s[n * 126 + 31] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 1], PRIM_INT__f_s_d_s[n * 60 + 1]), PRIM_INT__h_s_d_s[n * 126 + 31]);

                        PRIM_INT__h_s_d_s[n * 126 + 32] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 14]);
                        PRIM_INT__h_s_d_s[n * 126 + 32] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 14], PRIM_INT__h_s_d_s[n * 126 + 32]);
                        PRIM_INT__h_s_d_s[n * 126 + 32] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 2], PRIM_INT__f_s_d_s[n * 60 + 2]), PRIM_INT__h_s_d_s[n * 126 + 32]);
                        PRIM_INT__h_s_d_s[n * 126 + 32] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 6], PRIM_INT__h_s_d_s[n * 126 + 32]);

                        PRIM_INT__h_s_d_s[n * 126 + 33] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 15]);
                        PRIM_INT__h_s_d_s[n * 126 + 33] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 15], PRIM_INT__h_s_d_s[n * 126 + 33]);
                        PRIM_INT__h_s_d_s[n * 126 + 33] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 3], PRIM_INT__f_s_d_s[n * 60 + 3]), PRIM_INT__h_s_d_s[n * 126 + 33]);

                        PRIM_INT__h_s_d_s[n * 126 + 34] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 16]);
                        PRIM_INT__h_s_d_s[n * 126 + 34] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 16], PRIM_INT__h_s_d_s[n * 126 + 34]);
                        PRIM_INT__h_s_d_s[n * 126 + 34] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 4], PRIM_INT__f_s_d_s[n * 60 + 4]), PRIM_INT__h_s_d_s[n * 126 + 34]);
                        PRIM_INT__h_s_d_s[n * 126 + 34] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 7], PRIM_INT__h_s_d_s[n * 126 + 34]);

                        PRIM_INT__h_s_d_s[n * 126 + 35] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 17]);
                        PRIM_INT__h_s_d_s[n * 126 + 35] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 17], PRIM_INT__h_s_d_s[n * 126 + 35]);
                        PRIM_INT__h_s_d_s[n * 126 + 35] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 5], PRIM_INT__f_s_d_s[n * 60 + 5]), PRIM_INT__h_s_d_s[n * 126 + 35]);
                        PRIM_INT__h_s_d_s[n * 126 + 35] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 8], PRIM_INT__h_s_d_s[n * 126 + 35]);

                        PRIM_INT__h_s_d_s[n * 126 + 36] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 36]);
                        PRIM_INT__h_s_d_s[n * 126 + 36] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 36], PRIM_INT__h_s_d_s[n * 126 + 36]);
                        PRIM_INT__h_s_d_s[n * 126 + 36] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 36], PRIM_INT__f_s_d_s[n * 60 + 36]), PRIM_INT__h_s_d_s[n * 126 + 36]);
                        PRIM_INT__h_s_d_s[n * 126 + 36] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 18], PRIM_INT__h_s_d_s[n * 126 + 36]);

                        PRIM_INT__h_s_d_s[n * 126 + 37] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 37]);
                        PRIM_INT__h_s_d_s[n * 126 + 37] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 37], PRIM_INT__h_s_d_s[n * 126 + 37]);
                        PRIM_INT__h_s_d_s[n * 126 + 37] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 37], PRIM_INT__f_s_d_s[n * 60 + 37]), PRIM_INT__h_s_d_s[n * 126 + 37]);
                        PRIM_INT__h_s_d_s[n * 126 + 37] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 19], PRIM_INT__h_s_d_s[n * 126 + 37]);

                        PRIM_INT__h_s_d_s[n * 126 + 38] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 38]);
                        PRIM_INT__h_s_d_s[n * 126 + 38] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 38], PRIM_INT__h_s_d_s[n * 126 + 38]);
                        PRIM_INT__h_s_d_s[n * 126 + 38] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 38], PRIM_INT__f_s_d_s[n * 60 + 38]), PRIM_INT__h_s_d_s[n * 126 + 38]);
                        PRIM_INT__h_s_d_s[n * 126 + 38] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 20], PRIM_INT__h_s_d_s[n * 126 + 38]);

                        PRIM_INT__h_s_d_s[n * 126 + 39] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 39]);
                        PRIM_INT__h_s_d_s[n * 126 + 39] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 39], PRIM_INT__h_s_d_s[n * 126 + 39]);
                        PRIM_INT__h_s_d_s[n * 126 + 39] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 39], PRIM_INT__f_s_d_s[n * 60 + 39]), PRIM_INT__h_s_d_s[n * 126 + 39]);

                        PRIM_INT__h_s_d_s[n * 126 + 40] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 40]);
                        PRIM_INT__h_s_d_s[n * 126 + 40] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 40], PRIM_INT__h_s_d_s[n * 126 + 40]);
                        PRIM_INT__h_s_d_s[n * 126 + 40] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 40], PRIM_INT__f_s_d_s[n * 60 + 40]), PRIM_INT__h_s_d_s[n * 126 + 40]);

                        PRIM_INT__h_s_d_s[n * 126 + 41] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 41]);
                        PRIM_INT__h_s_d_s[n * 126 + 41] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 41], PRIM_INT__h_s_d_s[n * 126 + 41]);
                        PRIM_INT__h_s_d_s[n * 126 + 41] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 41], PRIM_INT__f_s_d_s[n * 60 + 41]), PRIM_INT__h_s_d_s[n * 126 + 41]);

                        PRIM_INT__h_s_d_s[n * 126 + 42] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 18]);
                        PRIM_INT__h_s_d_s[n * 126 + 42] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 18], PRIM_INT__h_s_d_s[n * 126 + 42]);

                        PRIM_INT__h_s_d_s[n * 126 + 43] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 19]);
                        PRIM_INT__h_s_d_s[n * 126 + 43] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 19], PRIM_INT__h_s_d_s[n * 126 + 43]);

                        PRIM_INT__h_s_d_s[n * 126 + 44] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 20]);
                        PRIM_INT__h_s_d_s[n * 126 + 44] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 20], PRIM_INT__h_s_d_s[n * 126 + 44]);
                        PRIM_INT__h_s_d_s[n * 126 + 44] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 9], PRIM_INT__h_s_d_s[n * 126 + 44]);

                        PRIM_INT__h_s_d_s[n * 126 + 45] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 21]);
                        PRIM_INT__h_s_d_s[n * 126 + 45] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 21], PRIM_INT__h_s_d_s[n * 126 + 45]);

                        PRIM_INT__h_s_d_s[n * 126 + 46] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 22]);
                        PRIM_INT__h_s_d_s[n * 126 + 46] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 22], PRIM_INT__h_s_d_s[n * 126 + 46]);
                        PRIM_INT__h_s_d_s[n * 126 + 46] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 10], PRIM_INT__h_s_d_s[n * 126 + 46]);

                        PRIM_INT__h_s_d_s[n * 126 + 47] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 23]);
                        PRIM_INT__h_s_d_s[n * 126 + 47] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 23], PRIM_INT__h_s_d_s[n * 126 + 47]);
                        PRIM_INT__h_s_d_s[n * 126 + 47] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 11], PRIM_INT__h_s_d_s[n * 126 + 47]);

                        PRIM_INT__h_s_d_s[n * 126 + 48] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 30]);
                        PRIM_INT__h_s_d_s[n * 126 + 48] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 30], PRIM_INT__h_s_d_s[n * 126 + 48]);

                        PRIM_INT__h_s_d_s[n * 126 + 49] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 31]);
                        PRIM_INT__h_s_d_s[n * 126 + 49] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 31], PRIM_INT__h_s_d_s[n * 126 + 49]);
                        PRIM_INT__h_s_d_s[n * 126 + 49] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 15], PRIM_INT__h_s_d_s[n * 126 + 49]);

                        PRIM_INT__h_s_d_s[n * 126 + 50] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 32]);
                        PRIM_INT__h_s_d_s[n * 126 + 50] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 32], PRIM_INT__h_s_d_s[n * 126 + 50]);

                        PRIM_INT__h_s_d_s[n * 126 + 51] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 33]);
                        PRIM_INT__h_s_d_s[n * 126 + 51] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 33], PRIM_INT__h_s_d_s[n * 126 + 51]);
                        PRIM_INT__h_s_d_s[n * 126 + 51] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 16], PRIM_INT__h_s_d_s[n * 126 + 51]);

                        PRIM_INT__h_s_d_s[n * 126 + 52] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 34]);
                        PRIM_INT__h_s_d_s[n * 126 + 52] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 34], PRIM_INT__h_s_d_s[n * 126 + 52]);
                        PRIM_INT__h_s_d_s[n * 126 + 52] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 17], PRIM_INT__h_s_d_s[n * 126 + 52]);

                        PRIM_INT__h_s_d_s[n * 126 + 53] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 35]);
                        PRIM_INT__h_s_d_s[n * 126 + 53] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 35], PRIM_INT__h_s_d_s[n * 126 + 53]);

                        PRIM_INT__h_s_d_s[n * 126 + 54] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 54]);
                        PRIM_INT__h_s_d_s[n * 126 + 54] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 54], PRIM_INT__h_s_d_s[n * 126 + 54]);
                        PRIM_INT__h_s_d_s[n * 126 + 54] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 54], PRIM_INT__f_s_d_s[n * 60 + 54]), PRIM_INT__h_s_d_s[n * 126 + 54]);
                        PRIM_INT__h_s_d_s[n * 126 + 54] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 27], PRIM_INT__h_s_d_s[n * 126 + 54]);

                        PRIM_INT__h_s_d_s[n * 126 + 55] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 55]);
                        PRIM_INT__h_s_d_s[n * 126 + 55] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 55], PRIM_INT__h_s_d_s[n * 126 + 55]);
                        PRIM_INT__h_s_d_s[n * 126 + 55] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 55], PRIM_INT__f_s_d_s[n * 60 + 55]), PRIM_INT__h_s_d_s[n * 126 + 55]);
                        PRIM_INT__h_s_d_s[n * 126 + 55] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 28], PRIM_INT__h_s_d_s[n * 126 + 55]);

                        PRIM_INT__h_s_d_s[n * 126 + 56] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 56]);
                        PRIM_INT__h_s_d_s[n * 126 + 56] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 56], PRIM_INT__h_s_d_s[n * 126 + 56]);
                        PRIM_INT__h_s_d_s[n * 126 + 56] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 56], PRIM_INT__f_s_d_s[n * 60 + 56]), PRIM_INT__h_s_d_s[n * 126 + 56]);
                        PRIM_INT__h_s_d_s[n * 126 + 56] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 29], PRIM_INT__h_s_d_s[n * 126 + 56]);

                        PRIM_INT__h_s_d_s[n * 126 + 57] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 57]);
                        PRIM_INT__h_s_d_s[n * 126 + 57] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 57], PRIM_INT__h_s_d_s[n * 126 + 57]);
                        PRIM_INT__h_s_d_s[n * 126 + 57] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 57], PRIM_INT__f_s_d_s[n * 60 + 57]), PRIM_INT__h_s_d_s[n * 126 + 57]);

                        PRIM_INT__h_s_d_s[n * 126 + 58] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 58]);
                        PRIM_INT__h_s_d_s[n * 126 + 58] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 58], PRIM_INT__h_s_d_s[n * 126 + 58]);
                        PRIM_INT__h_s_d_s[n * 126 + 58] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 58], PRIM_INT__f_s_d_s[n * 60 + 58]), PRIM_INT__h_s_d_s[n * 126 + 58]);

                        PRIM_INT__h_s_d_s[n * 126 + 59] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 59]);
                        PRIM_INT__h_s_d_s[n * 126 + 59] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 59], PRIM_INT__h_s_d_s[n * 126 + 59]);
                        PRIM_INT__h_s_d_s[n * 126 + 59] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 59], PRIM_INT__f_s_d_s[n * 60 + 59]), PRIM_INT__h_s_d_s[n * 126 + 59]);

                        PRIM_INT__h_s_d_s[n * 126 + 60] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 60]);
                        PRIM_INT__h_s_d_s[n * 126 + 60] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 60], PRIM_INT__h_s_d_s[n * 126 + 60]);
                        PRIM_INT__h_s_d_s[n * 126 + 60] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 30], PRIM_INT__h_s_d_s[n * 126 + 60]);

                        PRIM_INT__h_s_d_s[n * 126 + 61] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 61]);
                        PRIM_INT__h_s_d_s[n * 126 + 61] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 61], PRIM_INT__h_s_d_s[n * 126 + 61]);
                        PRIM_INT__h_s_d_s[n * 126 + 61] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 31], PRIM_INT__h_s_d_s[n * 126 + 61]);

                        PRIM_INT__h_s_d_s[n * 126 + 62] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 62]);
                        PRIM_INT__h_s_d_s[n * 126 + 62] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 62], PRIM_INT__h_s_d_s[n * 126 + 62]);
                        PRIM_INT__h_s_d_s[n * 126 + 62] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 32], PRIM_INT__h_s_d_s[n * 126 + 62]);

                        PRIM_INT__h_s_d_s[n * 126 + 63] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 63]);
                        PRIM_INT__h_s_d_s[n * 126 + 63] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 63], PRIM_INT__h_s_d_s[n * 126 + 63]);

                        PRIM_INT__h_s_d_s[n * 126 + 64] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 64]);
                        PRIM_INT__h_s_d_s[n * 126 + 64] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 64], PRIM_INT__h_s_d_s[n * 126 + 64]);

                        PRIM_INT__h_s_d_s[n * 126 + 65] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 65]);
                        PRIM_INT__h_s_d_s[n * 126 + 65] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 65], PRIM_INT__h_s_d_s[n * 126 + 65]);

                        PRIM_INT__h_s_d_s[n * 126 + 66] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 36]);
                        PRIM_INT__h_s_d_s[n * 126 + 66] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 36], PRIM_INT__h_s_d_s[n * 126 + 66]);

                        PRIM_INT__h_s_d_s[n * 126 + 67] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 37]);
                        PRIM_INT__h_s_d_s[n * 126 + 67] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 37], PRIM_INT__h_s_d_s[n * 126 + 67]);

                        PRIM_INT__h_s_d_s[n * 126 + 68] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 38]);
                        PRIM_INT__h_s_d_s[n * 126 + 68] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 38], PRIM_INT__h_s_d_s[n * 126 + 68]);
                        PRIM_INT__h_s_d_s[n * 126 + 68] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 18], PRIM_INT__h_s_d_s[n * 126 + 68]);

                        PRIM_INT__h_s_d_s[n * 126 + 69] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 39]);
                        PRIM_INT__h_s_d_s[n * 126 + 69] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 39], PRIM_INT__h_s_d_s[n * 126 + 69]);

                        PRIM_INT__h_s_d_s[n * 126 + 70] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 40]);
                        PRIM_INT__h_s_d_s[n * 126 + 70] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 40], PRIM_INT__h_s_d_s[n * 126 + 70]);
                        PRIM_INT__h_s_d_s[n * 126 + 70] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 19], PRIM_INT__h_s_d_s[n * 126 + 70]);

                        PRIM_INT__h_s_d_s[n * 126 + 71] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 41]);
                        PRIM_INT__h_s_d_s[n * 126 + 71] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 41], PRIM_INT__h_s_d_s[n * 126 + 71]);
                        PRIM_INT__h_s_d_s[n * 126 + 71] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 20], PRIM_INT__h_s_d_s[n * 126 + 71]);

                        PRIM_INT__h_s_d_s[n * 126 + 72] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 72]);
                        PRIM_INT__h_s_d_s[n * 126 + 72] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 72], PRIM_INT__h_s_d_s[n * 126 + 72]);
                        PRIM_INT__h_s_d_s[n * 126 + 72] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 36], PRIM_INT__h_s_d_s[n * 126 + 72]);

                        PRIM_INT__h_s_d_s[n * 126 + 73] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 73]);
                        PRIM_INT__h_s_d_s[n * 126 + 73] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 73], PRIM_INT__h_s_d_s[n * 126 + 73]);
                        PRIM_INT__h_s_d_s[n * 126 + 73] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 37], PRIM_INT__h_s_d_s[n * 126 + 73]);

                        PRIM_INT__h_s_d_s[n * 126 + 74] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 74]);
                        PRIM_INT__h_s_d_s[n * 126 + 74] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 74], PRIM_INT__h_s_d_s[n * 126 + 74]);
                        PRIM_INT__h_s_d_s[n * 126 + 74] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 38], PRIM_INT__h_s_d_s[n * 126 + 74]);

                        PRIM_INT__h_s_d_s[n * 126 + 75] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 75]);
                        PRIM_INT__h_s_d_s[n * 126 + 75] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 75], PRIM_INT__h_s_d_s[n * 126 + 75]);

                        PRIM_INT__h_s_d_s[n * 126 + 76] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 76]);
                        PRIM_INT__h_s_d_s[n * 126 + 76] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 76], PRIM_INT__h_s_d_s[n * 126 + 76]);

                        PRIM_INT__h_s_d_s[n * 126 + 77] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 77]);
                        PRIM_INT__h_s_d_s[n * 126 + 77] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 77], PRIM_INT__h_s_d_s[n * 126 + 77]);

                        PRIM_INT__h_s_d_s[n * 126 + 78] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 54]);
                        PRIM_INT__h_s_d_s[n * 126 + 78] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 54], PRIM_INT__h_s_d_s[n * 126 + 78]);

                        PRIM_INT__h_s_d_s[n * 126 + 79] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 55]);
                        PRIM_INT__h_s_d_s[n * 126 + 79] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 55], PRIM_INT__h_s_d_s[n * 126 + 79]);
                        PRIM_INT__h_s_d_s[n * 126 + 79] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 27], PRIM_INT__h_s_d_s[n * 126 + 79]);

                        PRIM_INT__h_s_d_s[n * 126 + 80] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 56]);
                        PRIM_INT__h_s_d_s[n * 126 + 80] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 56], PRIM_INT__h_s_d_s[n * 126 + 80]);

                        PRIM_INT__h_s_d_s[n * 126 + 81] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 57]);
                        PRIM_INT__h_s_d_s[n * 126 + 81] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 57], PRIM_INT__h_s_d_s[n * 126 + 81]);
                        PRIM_INT__h_s_d_s[n * 126 + 81] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 28], PRIM_INT__h_s_d_s[n * 126 + 81]);

                        PRIM_INT__h_s_d_s[n * 126 + 82] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 58]);
                        PRIM_INT__h_s_d_s[n * 126 + 82] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 58], PRIM_INT__h_s_d_s[n * 126 + 82]);
                        PRIM_INT__h_s_d_s[n * 126 + 82] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 29], PRIM_INT__h_s_d_s[n * 126 + 82]);

                        PRIM_INT__h_s_d_s[n * 126 + 83] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 59]);
                        PRIM_INT__h_s_d_s[n * 126 + 83] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 59], PRIM_INT__h_s_d_s[n * 126 + 83]);

                        PRIM_INT__h_s_d_s[n * 126 + 84] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 84]);
                        PRIM_INT__h_s_d_s[n * 126 + 84] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 84], PRIM_INT__h_s_d_s[n * 126 + 84]);
                        PRIM_INT__h_s_d_s[n * 126 + 84] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 42], PRIM_INT__h_s_d_s[n * 126 + 84]);

                        PRIM_INT__h_s_d_s[n * 126 + 85] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 85]);
                        PRIM_INT__h_s_d_s[n * 126 + 85] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 85], PRIM_INT__h_s_d_s[n * 126 + 85]);
                        PRIM_INT__h_s_d_s[n * 126 + 85] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 43], PRIM_INT__h_s_d_s[n * 126 + 85]);

                        PRIM_INT__h_s_d_s[n * 126 + 86] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 86]);
                        PRIM_INT__h_s_d_s[n * 126 + 86] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 86], PRIM_INT__h_s_d_s[n * 126 + 86]);
                        PRIM_INT__h_s_d_s[n * 126 + 86] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 44], PRIM_INT__h_s_d_s[n * 126 + 86]);

                        PRIM_INT__h_s_d_s[n * 126 + 87] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 87]);
                        PRIM_INT__h_s_d_s[n * 126 + 87] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 87], PRIM_INT__h_s_d_s[n * 126 + 87]);

                        PRIM_INT__h_s_d_s[n * 126 + 88] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 88]);
                        PRIM_INT__h_s_d_s[n * 126 + 88] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 88], PRIM_INT__h_s_d_s[n * 126 + 88]);

                        PRIM_INT__h_s_d_s[n * 126 + 89] = SIMINT_MUL(P_PA[0], PRIM_INT__g_s_d_s[n * 90 + 89]);
                        PRIM_INT__h_s_d_s[n * 126 + 89] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__g_s_d_s[(n+1) * 90 + 89], PRIM_INT__h_s_d_s[n * 126 + 89]);

                        PRIM_INT__h_s_d_s[n * 126 + 90] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 60]);
                        PRIM_INT__h_s_d_s[n * 126 + 90] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 60], PRIM_INT__h_s_d_s[n * 126 + 90]);
                        PRIM_INT__h_s_d_s[n * 126 + 90] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 36], PRIM_INT__f_s_d_s[n * 60 + 36]), PRIM_INT__h_s_d_s[n * 126 + 90]);

                        PRIM_INT__h_s_d_s[n * 126 + 91] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 61]);
                        PRIM_INT__h_s_d_s[n * 126 + 91] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 61], PRIM_INT__h_s_d_s[n * 126 + 91]);
                        PRIM_INT__h_s_d_s[n * 126 + 91] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 37], PRIM_INT__f_s_d_s[n * 60 + 37]), PRIM_INT__h_s_d_s[n * 126 + 91]);
                        PRIM_INT__h_s_d_s[n * 126 + 91] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 30], PRIM_INT__h_s_d_s[n * 126 + 91]);

                        PRIM_INT__h_s_d_s[n * 126 + 92] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 62]);
                        PRIM_INT__h_s_d_s[n * 126 + 92] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 62], PRIM_INT__h_s_d_s[n * 126 + 92]);
                        PRIM_INT__h_s_d_s[n * 126 + 92] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 38], PRIM_INT__f_s_d_s[n * 60 + 38]), PRIM_INT__h_s_d_s[n * 126 + 92]);

                        PRIM_INT__h_s_d_s[n * 126 + 93] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 63]);
                        PRIM_INT__h_s_d_s[n * 126 + 93] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 63], PRIM_INT__h_s_d_s[n * 126 + 93]);
                        PRIM_INT__h_s_d_s[n * 126 + 93] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 39], PRIM_INT__f_s_d_s[n * 60 + 39]), PRIM_INT__h_s_d_s[n * 126 + 93]);
                        PRIM_INT__h_s_d_s[n * 126 + 93] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 31], PRIM_INT__h_s_d_s[n * 126 + 93]);

                        PRIM_INT__h_s_d_s[n * 126 + 94] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 64]);
                        PRIM_INT__h_s_d_s[n * 126 + 94] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 64], PRIM_INT__h_s_d_s[n * 126 + 94]);
                        PRIM_INT__h_s_d_s[n * 126 + 94] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 40], PRIM_INT__f_s_d_s[n * 60 + 40]), PRIM_INT__h_s_d_s[n * 126 + 94]);
                        PRIM_INT__h_s_d_s[n * 126 + 94] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 32], PRIM_INT__h_s_d_s[n * 126 + 94]);

                        PRIM_INT__h_s_d_s[n * 126 + 95] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 65]);
                        PRIM_INT__h_s_d_s[n * 126 + 95] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 65], PRIM_INT__h_s_d_s[n * 126 + 95]);
                        PRIM_INT__h_s_d_s[n * 126 + 95] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 41], PRIM_INT__f_s_d_s[n * 60 + 41]), PRIM_INT__h_s_d_s[n * 126 + 95]);

                        PRIM_INT__h_s_d_s[n * 126 + 96] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 60]);
                        PRIM_INT__h_s_d_s[n * 126 + 96] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 60], PRIM_INT__h_s_d_s[n * 126 + 96]);

                        PRIM_INT__h_s_d_s[n * 126 + 97] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 61]);
                        PRIM_INT__h_s_d_s[n * 126 + 97] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 61], PRIM_INT__h_s_d_s[n * 126 + 97]);

                        PRIM_INT__h_s_d_s[n * 126 + 98] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 62]);
                        PRIM_INT__h_s_d_s[n * 126 + 98] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 62], PRIM_INT__h_s_d_s[n * 126 + 98]);
                        PRIM_INT__h_s_d_s[n * 126 + 98] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 30], PRIM_INT__h_s_d_s[n * 126 + 98]);

                        PRIM_INT__h_s_d_s[n * 126 + 99] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 63]);
                        PRIM_INT__h_s_d_s[n * 126 + 99] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 63], PRIM_INT__h_s_d_s[n * 126 + 99]);

                        PRIM_INT__h_s_d_s[n * 126 + 100] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 64]);
                        PRIM_INT__h_s_d_s[n * 126 + 100] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 64], PRIM_INT__h_s_d_s[n * 126 + 100]);
                        PRIM_INT__h_s_d_s[n * 126 + 100] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 31], PRIM_INT__h_s_d_s[n * 126 + 100]);

                        PRIM_INT__h_s_d_s[n * 126 + 101] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 65]);
                        PRIM_INT__h_s_d_s[n * 126 + 101] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 65], PRIM_INT__h_s_d_s[n * 126 + 101]);
                        PRIM_INT__h_s_d_s[n * 126 + 101] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 32], PRIM_INT__h_s_d_s[n * 126 + 101]);

                        PRIM_INT__h_s_d_s[n * 126 + 102] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 66]);
                        PRIM_INT__h_s_d_s[n * 126 + 102] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 66], PRIM_INT__h_s_d_s[n * 126 + 102]);
                        PRIM_INT__h_s_d_s[n * 126 + 102] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 36], PRIM_INT__f_s_d_s[n * 60 + 36]), PRIM_INT__h_s_d_s[n * 126 + 102]);

                        PRIM_INT__h_s_d_s[n * 126 + 103] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 67]);
                        PRIM_INT__h_s_d_s[n * 126 + 103] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 67], PRIM_INT__h_s_d_s[n * 126 + 103]);
                        PRIM_INT__h_s_d_s[n * 126 + 103] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 37], PRIM_INT__f_s_d_s[n * 60 + 37]), PRIM_INT__h_s_d_s[n * 126 + 103]);

                        PRIM_INT__h_s_d_s[n * 126 + 104] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 68]);
                        PRIM_INT__h_s_d_s[n * 126 + 104] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 68], PRIM_INT__h_s_d_s[n * 126 + 104]);
                        PRIM_INT__h_s_d_s[n * 126 + 104] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 38], PRIM_INT__f_s_d_s[n * 60 + 38]), PRIM_INT__h_s_d_s[n * 126 + 104]);
                        PRIM_INT__h_s_d_s[n * 126 + 104] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 33], PRIM_INT__h_s_d_s[n * 126 + 104]);

                        PRIM_INT__h_s_d_s[n * 126 + 105] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 69]);
                        PRIM_INT__h_s_d_s[n * 126 + 105] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 69], PRIM_INT__h_s_d_s[n * 126 + 105]);
                        PRIM_INT__h_s_d_s[n * 126 + 105] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 39], PRIM_INT__f_s_d_s[n * 60 + 39]), PRIM_INT__h_s_d_s[n * 126 + 105]);

                        PRIM_INT__h_s_d_s[n * 126 + 106] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 70]);
                        PRIM_INT__h_s_d_s[n * 126 + 106] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 70], PRIM_INT__h_s_d_s[n * 126 + 106]);
                        PRIM_INT__h_s_d_s[n * 126 + 106] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 40], PRIM_INT__f_s_d_s[n * 60 + 40]), PRIM_INT__h_s_d_s[n * 126 + 106]);
                        PRIM_INT__h_s_d_s[n * 126 + 106] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 34], PRIM_INT__h_s_d_s[n * 126 + 106]);

                        PRIM_INT__h_s_d_s[n * 126 + 107] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 71]);
                        PRIM_INT__h_s_d_s[n * 126 + 107] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 71], PRIM_INT__h_s_d_s[n * 126 + 107]);
                        PRIM_INT__h_s_d_s[n * 126 + 107] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 41], PRIM_INT__f_s_d_s[n * 60 + 41]), PRIM_INT__h_s_d_s[n * 126 + 107]);
                        PRIM_INT__h_s_d_s[n * 126 + 107] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 35], PRIM_INT__h_s_d_s[n * 126 + 107]);

                        PRIM_INT__h_s_d_s[n * 126 + 108] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 78]);
                        PRIM_INT__h_s_d_s[n * 126 + 108] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 78], PRIM_INT__h_s_d_s[n * 126 + 108]);
                        PRIM_INT__h_s_d_s[n * 126 + 108] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 54], PRIM_INT__f_s_d_s[n * 60 + 54]), PRIM_INT__h_s_d_s[n * 126 + 108]);

                        PRIM_INT__h_s_d_s[n * 126 + 109] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 79]);
                        PRIM_INT__h_s_d_s[n * 126 + 109] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 79], PRIM_INT__h_s_d_s[n * 126 + 109]);
                        PRIM_INT__h_s_d_s[n * 126 + 109] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 55], PRIM_INT__f_s_d_s[n * 60 + 55]), PRIM_INT__h_s_d_s[n * 126 + 109]);
                        PRIM_INT__h_s_d_s[n * 126 + 109] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 39], PRIM_INT__h_s_d_s[n * 126 + 109]);

                        PRIM_INT__h_s_d_s[n * 126 + 110] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 80]);
                        PRIM_INT__h_s_d_s[n * 126 + 110] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 80], PRIM_INT__h_s_d_s[n * 126 + 110]);
                        PRIM_INT__h_s_d_s[n * 126 + 110] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 56], PRIM_INT__f_s_d_s[n * 60 + 56]), PRIM_INT__h_s_d_s[n * 126 + 110]);

                        PRIM_INT__h_s_d_s[n * 126 + 111] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 81]);
                        PRIM_INT__h_s_d_s[n * 126 + 111] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 81], PRIM_INT__h_s_d_s[n * 126 + 111]);
                        PRIM_INT__h_s_d_s[n * 126 + 111] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 57], PRIM_INT__f_s_d_s[n * 60 + 57]), PRIM_INT__h_s_d_s[n * 126 + 111]);
                        PRIM_INT__h_s_d_s[n * 126 + 111] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 40], PRIM_INT__h_s_d_s[n * 126 + 111]);

                        PRIM_INT__h_s_d_s[n * 126 + 112] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 82]);
                        PRIM_INT__h_s_d_s[n * 126 + 112] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 82], PRIM_INT__h_s_d_s[n * 126 + 112]);
                        PRIM_INT__h_s_d_s[n * 126 + 112] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 58], PRIM_INT__f_s_d_s[n * 60 + 58]), PRIM_INT__h_s_d_s[n * 126 + 112]);
                        PRIM_INT__h_s_d_s[n * 126 + 112] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 41], PRIM_INT__h_s_d_s[n * 126 + 112]);

                        PRIM_INT__h_s_d_s[n * 126 + 113] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 83]);
                        PRIM_INT__h_s_d_s[n * 126 + 113] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 83], PRIM_INT__h_s_d_s[n * 126 + 113]);
                        PRIM_INT__h_s_d_s[n * 126 + 113] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 59], PRIM_INT__f_s_d_s[n * 60 + 59]), PRIM_INT__h_s_d_s[n * 126 + 113]);

                        PRIM_INT__h_s_d_s[n * 126 + 114] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 84]);
                        PRIM_INT__h_s_d_s[n * 126 + 114] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 84], PRIM_INT__h_s_d_s[n * 126 + 114]);

                        PRIM_INT__h_s_d_s[n * 126 + 115] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 85]);
                        PRIM_INT__h_s_d_s[n * 126 + 115] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 85], PRIM_INT__h_s_d_s[n * 126 + 115]);
                        PRIM_INT__h_s_d_s[n * 126 + 115] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 42], PRIM_INT__h_s_d_s[n * 126 + 115]);

                        PRIM_INT__h_s_d_s[n * 126 + 116] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 86]);
                        PRIM_INT__h_s_d_s[n * 126 + 116] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 86], PRIM_INT__h_s_d_s[n * 126 + 116]);

                        PRIM_INT__h_s_d_s[n * 126 + 117] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 87]);
                        PRIM_INT__h_s_d_s[n * 126 + 117] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 87], PRIM_INT__h_s_d_s[n * 126 + 117]);
                        PRIM_INT__h_s_d_s[n * 126 + 117] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 43], PRIM_INT__h_s_d_s[n * 126 + 117]);

                        PRIM_INT__h_s_d_s[n * 126 + 118] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 88]);
                        PRIM_INT__h_s_d_s[n * 126 + 118] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 88], PRIM_INT__h_s_d_s[n * 126 + 118]);
                        PRIM_INT__h_s_d_s[n * 126 + 118] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 44], PRIM_INT__h_s_d_s[n * 126 + 118]);

                        PRIM_INT__h_s_d_s[n * 126 + 119] = SIMINT_MUL(P_PA[1], PRIM_INT__g_s_d_s[n * 90 + 89]);
                        PRIM_INT__h_s_d_s[n * 126 + 119] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__g_s_d_s[(n+1) * 90 + 89], PRIM_INT__h_s_d_s[n * 126 + 119]);

                        PRIM_INT__h_s_d_s[n * 126 + 120] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 84]);
                        PRIM_INT__h_s_d_s[n * 126 + 120] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 84], PRIM_INT__h_s_d_s[n * 126 + 120]);
                        PRIM_INT__h_s_d_s[n * 126 + 120] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 54], PRIM_INT__f_s_d_s[n * 60 + 54]), PRIM_INT__h_s_d_s[n * 126 + 120]);

                        PRIM_INT__h_s_d_s[n * 126 + 121] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 85]);
                        PRIM_INT__h_s_d_s[n * 126 + 121] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 85], PRIM_INT__h_s_d_s[n * 126 + 121]);
                        PRIM_INT__h_s_d_s[n * 126 + 121] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 55], PRIM_INT__f_s_d_s[n * 60 + 55]), PRIM_INT__h_s_d_s[n * 126 + 121]);

                        PRIM_INT__h_s_d_s[n * 126 + 122] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 86]);
                        PRIM_INT__h_s_d_s[n * 126 + 122] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 86], PRIM_INT__h_s_d_s[n * 126 + 122]);
                        PRIM_INT__h_s_d_s[n * 126 + 122] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 56], PRIM_INT__f_s_d_s[n * 60 + 56]), PRIM_INT__h_s_d_s[n * 126 + 122]);
                        PRIM_INT__h_s_d_s[n * 126 + 122] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 42], PRIM_INT__h_s_d_s[n * 126 + 122]);

                        PRIM_INT__h_s_d_s[n * 126 + 123] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 87]);
                        PRIM_INT__h_s_d_s[n * 126 + 123] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 87], PRIM_INT__h_s_d_s[n * 126 + 123]);
                        PRIM_INT__h_s_d_s[n * 126 + 123] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 57], PRIM_INT__f_s_d_s[n * 60 + 57]), PRIM_INT__h_s_d_s[n * 126 + 123]);

                        PRIM_INT__h_s_d_s[n * 126 + 124] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 88]);
                        PRIM_INT__h_s_d_s[n * 126 + 124] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 88], PRIM_INT__h_s_d_s[n * 126 + 124]);
                        PRIM_INT__h_s_d_s[n * 126 + 124] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 58], PRIM_INT__f_s_d_s[n * 60 + 58]), PRIM_INT__h_s_d_s[n * 126 + 124]);
                        PRIM_INT__h_s_d_s[n * 126 + 124] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 43], PRIM_INT__h_s_d_s[n * 126 + 124]);

                        PRIM_INT__h_s_d_s[n * 126 + 125] = SIMINT_MUL(P_PA[2], PRIM_INT__g_s_d_s[n * 90 + 89]);
                        PRIM_INT__h_s_d_s[n * 126 + 125] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__g_s_d_s[(n+1) * 90 + 89], PRIM_INT__h_s_d_s[n * 126 + 125]);
                        PRIM_INT__h_s_d_s[n * 126 + 125] = SIMINT_FMADD( vrr_const_4_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__f_s_d_s[(n+1) * 60 + 59], PRIM_INT__f_s_d_s[n * 60 + 59]), PRIM_INT__h_s_d_s[n * 126 + 125]);
                        PRIM_INT__h_s_d_s[n * 126 + 125] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_p_s[(n+1) * 45 + 44], PRIM_INT__h_s_d_s[n * 126 + 125]);

                    }

}


