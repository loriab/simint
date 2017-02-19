
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( g s | f s )
//////////////////////////////////////////////
void VRR_I_g_s_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n)
{
    int n = 0;
    const SIMINT_DBLTYPE vrr_const_1_over_2p = SIMINT_MUL(SIMINT_DBLSET1(1), one_over_2p);
    const SIMINT_DBLTYPE vrr_const_3_over_2p = SIMINT_MUL(SIMINT_DBLSET1(3), one_over_2p);
    const SIMINT_DBLTYPE vrr_const_1_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(1), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(2), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_3_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(3), one_over_2pq);

                    // Forming PRIM_INT__g_s_f_s[num_n * 150];
                    for(n = 0; n < num_n; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__g_s_f_s[n * 150 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 0]);
                        PRIM_INT__g_s_f_s[n * 150 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 0], PRIM_INT__g_s_f_s[n * 150 + 0]);
                        PRIM_INT__g_s_f_s[n * 150 + 0] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 0], PRIM_INT__d_s_f_s[n * 60 + 0]), PRIM_INT__g_s_f_s[n * 150 + 0]);
                        PRIM_INT__g_s_f_s[n * 150 + 0] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 0], PRIM_INT__g_s_f_s[n * 150 + 0]);

                        PRIM_INT__g_s_f_s[n * 150 + 1] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 1]);
                        PRIM_INT__g_s_f_s[n * 150 + 1] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 1], PRIM_INT__g_s_f_s[n * 150 + 1]);
                        PRIM_INT__g_s_f_s[n * 150 + 1] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 1], PRIM_INT__d_s_f_s[n * 60 + 1]), PRIM_INT__g_s_f_s[n * 150 + 1]);
                        PRIM_INT__g_s_f_s[n * 150 + 1] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 1], PRIM_INT__g_s_f_s[n * 150 + 1]);

                        PRIM_INT__g_s_f_s[n * 150 + 2] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 2]);
                        PRIM_INT__g_s_f_s[n * 150 + 2] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 2], PRIM_INT__g_s_f_s[n * 150 + 2]);
                        PRIM_INT__g_s_f_s[n * 150 + 2] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 2], PRIM_INT__d_s_f_s[n * 60 + 2]), PRIM_INT__g_s_f_s[n * 150 + 2]);
                        PRIM_INT__g_s_f_s[n * 150 + 2] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 2], PRIM_INT__g_s_f_s[n * 150 + 2]);

                        PRIM_INT__g_s_f_s[n * 150 + 3] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 3]);
                        PRIM_INT__g_s_f_s[n * 150 + 3] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 3], PRIM_INT__g_s_f_s[n * 150 + 3]);
                        PRIM_INT__g_s_f_s[n * 150 + 3] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 3], PRIM_INT__d_s_f_s[n * 60 + 3]), PRIM_INT__g_s_f_s[n * 150 + 3]);
                        PRIM_INT__g_s_f_s[n * 150 + 3] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 3], PRIM_INT__g_s_f_s[n * 150 + 3]);

                        PRIM_INT__g_s_f_s[n * 150 + 4] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 4]);
                        PRIM_INT__g_s_f_s[n * 150 + 4] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 4], PRIM_INT__g_s_f_s[n * 150 + 4]);
                        PRIM_INT__g_s_f_s[n * 150 + 4] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 4], PRIM_INT__d_s_f_s[n * 60 + 4]), PRIM_INT__g_s_f_s[n * 150 + 4]);
                        PRIM_INT__g_s_f_s[n * 150 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 4], PRIM_INT__g_s_f_s[n * 150 + 4]);

                        PRIM_INT__g_s_f_s[n * 150 + 5] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 5]);
                        PRIM_INT__g_s_f_s[n * 150 + 5] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 5], PRIM_INT__g_s_f_s[n * 150 + 5]);
                        PRIM_INT__g_s_f_s[n * 150 + 5] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 5], PRIM_INT__d_s_f_s[n * 60 + 5]), PRIM_INT__g_s_f_s[n * 150 + 5]);
                        PRIM_INT__g_s_f_s[n * 150 + 5] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 5], PRIM_INT__g_s_f_s[n * 150 + 5]);

                        PRIM_INT__g_s_f_s[n * 150 + 6] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 6]);
                        PRIM_INT__g_s_f_s[n * 150 + 6] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 6], PRIM_INT__g_s_f_s[n * 150 + 6]);
                        PRIM_INT__g_s_f_s[n * 150 + 6] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 6], PRIM_INT__d_s_f_s[n * 60 + 6]), PRIM_INT__g_s_f_s[n * 150 + 6]);

                        PRIM_INT__g_s_f_s[n * 150 + 7] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 7]);
                        PRIM_INT__g_s_f_s[n * 150 + 7] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 7], PRIM_INT__g_s_f_s[n * 150 + 7]);
                        PRIM_INT__g_s_f_s[n * 150 + 7] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 7], PRIM_INT__d_s_f_s[n * 60 + 7]), PRIM_INT__g_s_f_s[n * 150 + 7]);

                        PRIM_INT__g_s_f_s[n * 150 + 8] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 8]);
                        PRIM_INT__g_s_f_s[n * 150 + 8] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 8], PRIM_INT__g_s_f_s[n * 150 + 8]);
                        PRIM_INT__g_s_f_s[n * 150 + 8] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 8], PRIM_INT__d_s_f_s[n * 60 + 8]), PRIM_INT__g_s_f_s[n * 150 + 8]);

                        PRIM_INT__g_s_f_s[n * 150 + 9] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 9]);
                        PRIM_INT__g_s_f_s[n * 150 + 9] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 9], PRIM_INT__g_s_f_s[n * 150 + 9]);
                        PRIM_INT__g_s_f_s[n * 150 + 9] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 9], PRIM_INT__d_s_f_s[n * 60 + 9]), PRIM_INT__g_s_f_s[n * 150 + 9]);

                        PRIM_INT__g_s_f_s[n * 150 + 10] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 0]);
                        PRIM_INT__g_s_f_s[n * 150 + 10] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 0], PRIM_INT__g_s_f_s[n * 150 + 10]);

                        PRIM_INT__g_s_f_s[n * 150 + 11] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 1]);
                        PRIM_INT__g_s_f_s[n * 150 + 11] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 1], PRIM_INT__g_s_f_s[n * 150 + 11]);
                        PRIM_INT__g_s_f_s[n * 150 + 11] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 0], PRIM_INT__g_s_f_s[n * 150 + 11]);

                        PRIM_INT__g_s_f_s[n * 150 + 12] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 2]);
                        PRIM_INT__g_s_f_s[n * 150 + 12] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 2], PRIM_INT__g_s_f_s[n * 150 + 12]);

                        PRIM_INT__g_s_f_s[n * 150 + 13] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 3]);
                        PRIM_INT__g_s_f_s[n * 150 + 13] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 3], PRIM_INT__g_s_f_s[n * 150 + 13]);
                        PRIM_INT__g_s_f_s[n * 150 + 13] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 1], PRIM_INT__g_s_f_s[n * 150 + 13]);

                        PRIM_INT__g_s_f_s[n * 150 + 14] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 4]);
                        PRIM_INT__g_s_f_s[n * 150 + 14] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 4], PRIM_INT__g_s_f_s[n * 150 + 14]);
                        PRIM_INT__g_s_f_s[n * 150 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 2], PRIM_INT__g_s_f_s[n * 150 + 14]);

                        PRIM_INT__g_s_f_s[n * 150 + 15] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 5]);
                        PRIM_INT__g_s_f_s[n * 150 + 15] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 5], PRIM_INT__g_s_f_s[n * 150 + 15]);

                        PRIM_INT__g_s_f_s[n * 150 + 16] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 6]);
                        PRIM_INT__g_s_f_s[n * 150 + 16] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 6], PRIM_INT__g_s_f_s[n * 150 + 16]);
                        PRIM_INT__g_s_f_s[n * 150 + 16] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 3], PRIM_INT__g_s_f_s[n * 150 + 16]);

                        PRIM_INT__g_s_f_s[n * 150 + 17] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 7]);
                        PRIM_INT__g_s_f_s[n * 150 + 17] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 7], PRIM_INT__g_s_f_s[n * 150 + 17]);
                        PRIM_INT__g_s_f_s[n * 150 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 4], PRIM_INT__g_s_f_s[n * 150 + 17]);

                        PRIM_INT__g_s_f_s[n * 150 + 18] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 8]);
                        PRIM_INT__g_s_f_s[n * 150 + 18] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 8], PRIM_INT__g_s_f_s[n * 150 + 18]);
                        PRIM_INT__g_s_f_s[n * 150 + 18] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 5], PRIM_INT__g_s_f_s[n * 150 + 18]);

                        PRIM_INT__g_s_f_s[n * 150 + 19] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 9]);
                        PRIM_INT__g_s_f_s[n * 150 + 19] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 9], PRIM_INT__g_s_f_s[n * 150 + 19]);

                        PRIM_INT__g_s_f_s[n * 150 + 20] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 0]);
                        PRIM_INT__g_s_f_s[n * 150 + 20] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 0], PRIM_INT__g_s_f_s[n * 150 + 20]);

                        PRIM_INT__g_s_f_s[n * 150 + 21] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 1]);
                        PRIM_INT__g_s_f_s[n * 150 + 21] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 1], PRIM_INT__g_s_f_s[n * 150 + 21]);

                        PRIM_INT__g_s_f_s[n * 150 + 22] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 2]);
                        PRIM_INT__g_s_f_s[n * 150 + 22] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 2], PRIM_INT__g_s_f_s[n * 150 + 22]);
                        PRIM_INT__g_s_f_s[n * 150 + 22] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 0], PRIM_INT__g_s_f_s[n * 150 + 22]);

                        PRIM_INT__g_s_f_s[n * 150 + 23] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 3]);
                        PRIM_INT__g_s_f_s[n * 150 + 23] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 3], PRIM_INT__g_s_f_s[n * 150 + 23]);

                        PRIM_INT__g_s_f_s[n * 150 + 24] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 4]);
                        PRIM_INT__g_s_f_s[n * 150 + 24] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 4], PRIM_INT__g_s_f_s[n * 150 + 24]);
                        PRIM_INT__g_s_f_s[n * 150 + 24] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 1], PRIM_INT__g_s_f_s[n * 150 + 24]);

                        PRIM_INT__g_s_f_s[n * 150 + 25] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 5]);
                        PRIM_INT__g_s_f_s[n * 150 + 25] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 5], PRIM_INT__g_s_f_s[n * 150 + 25]);
                        PRIM_INT__g_s_f_s[n * 150 + 25] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 2], PRIM_INT__g_s_f_s[n * 150 + 25]);

                        PRIM_INT__g_s_f_s[n * 150 + 26] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 6]);
                        PRIM_INT__g_s_f_s[n * 150 + 26] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 6], PRIM_INT__g_s_f_s[n * 150 + 26]);

                        PRIM_INT__g_s_f_s[n * 150 + 27] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 7]);
                        PRIM_INT__g_s_f_s[n * 150 + 27] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 7], PRIM_INT__g_s_f_s[n * 150 + 27]);
                        PRIM_INT__g_s_f_s[n * 150 + 27] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 3], PRIM_INT__g_s_f_s[n * 150 + 27]);

                        PRIM_INT__g_s_f_s[n * 150 + 28] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 8]);
                        PRIM_INT__g_s_f_s[n * 150 + 28] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 8], PRIM_INT__g_s_f_s[n * 150 + 28]);
                        PRIM_INT__g_s_f_s[n * 150 + 28] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 4], PRIM_INT__g_s_f_s[n * 150 + 28]);

                        PRIM_INT__g_s_f_s[n * 150 + 29] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 9]);
                        PRIM_INT__g_s_f_s[n * 150 + 29] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 9], PRIM_INT__g_s_f_s[n * 150 + 29]);
                        PRIM_INT__g_s_f_s[n * 150 + 29] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 5], PRIM_INT__g_s_f_s[n * 150 + 29]);

                        PRIM_INT__g_s_f_s[n * 150 + 30] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 10]);
                        PRIM_INT__g_s_f_s[n * 150 + 30] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 10], PRIM_INT__g_s_f_s[n * 150 + 30]);
                        PRIM_INT__g_s_f_s[n * 150 + 30] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 0], PRIM_INT__d_s_f_s[n * 60 + 0]), PRIM_INT__g_s_f_s[n * 150 + 30]);

                        PRIM_INT__g_s_f_s[n * 150 + 31] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 11]);
                        PRIM_INT__g_s_f_s[n * 150 + 31] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 11], PRIM_INT__g_s_f_s[n * 150 + 31]);
                        PRIM_INT__g_s_f_s[n * 150 + 31] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 1], PRIM_INT__d_s_f_s[n * 60 + 1]), PRIM_INT__g_s_f_s[n * 150 + 31]);
                        PRIM_INT__g_s_f_s[n * 150 + 31] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 6], PRIM_INT__g_s_f_s[n * 150 + 31]);

                        PRIM_INT__g_s_f_s[n * 150 + 32] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 12]);
                        PRIM_INT__g_s_f_s[n * 150 + 32] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 12], PRIM_INT__g_s_f_s[n * 150 + 32]);
                        PRIM_INT__g_s_f_s[n * 150 + 32] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 2], PRIM_INT__d_s_f_s[n * 60 + 2]), PRIM_INT__g_s_f_s[n * 150 + 32]);

                        PRIM_INT__g_s_f_s[n * 150 + 33] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 13]);
                        PRIM_INT__g_s_f_s[n * 150 + 33] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 13], PRIM_INT__g_s_f_s[n * 150 + 33]);
                        PRIM_INT__g_s_f_s[n * 150 + 33] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 3], PRIM_INT__d_s_f_s[n * 60 + 3]), PRIM_INT__g_s_f_s[n * 150 + 33]);
                        PRIM_INT__g_s_f_s[n * 150 + 33] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 7], PRIM_INT__g_s_f_s[n * 150 + 33]);

                        PRIM_INT__g_s_f_s[n * 150 + 34] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 14]);
                        PRIM_INT__g_s_f_s[n * 150 + 34] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 14], PRIM_INT__g_s_f_s[n * 150 + 34]);
                        PRIM_INT__g_s_f_s[n * 150 + 34] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 4], PRIM_INT__d_s_f_s[n * 60 + 4]), PRIM_INT__g_s_f_s[n * 150 + 34]);
                        PRIM_INT__g_s_f_s[n * 150 + 34] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 8], PRIM_INT__g_s_f_s[n * 150 + 34]);

                        PRIM_INT__g_s_f_s[n * 150 + 35] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 15]);
                        PRIM_INT__g_s_f_s[n * 150 + 35] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 15], PRIM_INT__g_s_f_s[n * 150 + 35]);
                        PRIM_INT__g_s_f_s[n * 150 + 35] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 5], PRIM_INT__d_s_f_s[n * 60 + 5]), PRIM_INT__g_s_f_s[n * 150 + 35]);

                        PRIM_INT__g_s_f_s[n * 150 + 36] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 16]);
                        PRIM_INT__g_s_f_s[n * 150 + 36] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 16], PRIM_INT__g_s_f_s[n * 150 + 36]);
                        PRIM_INT__g_s_f_s[n * 150 + 36] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 6], PRIM_INT__d_s_f_s[n * 60 + 6]), PRIM_INT__g_s_f_s[n * 150 + 36]);
                        PRIM_INT__g_s_f_s[n * 150 + 36] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 9], PRIM_INT__g_s_f_s[n * 150 + 36]);

                        PRIM_INT__g_s_f_s[n * 150 + 37] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 17]);
                        PRIM_INT__g_s_f_s[n * 150 + 37] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 17], PRIM_INT__g_s_f_s[n * 150 + 37]);
                        PRIM_INT__g_s_f_s[n * 150 + 37] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 7], PRIM_INT__d_s_f_s[n * 60 + 7]), PRIM_INT__g_s_f_s[n * 150 + 37]);
                        PRIM_INT__g_s_f_s[n * 150 + 37] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 10], PRIM_INT__g_s_f_s[n * 150 + 37]);

                        PRIM_INT__g_s_f_s[n * 150 + 38] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 18]);
                        PRIM_INT__g_s_f_s[n * 150 + 38] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 18], PRIM_INT__g_s_f_s[n * 150 + 38]);
                        PRIM_INT__g_s_f_s[n * 150 + 38] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 8], PRIM_INT__d_s_f_s[n * 60 + 8]), PRIM_INT__g_s_f_s[n * 150 + 38]);
                        PRIM_INT__g_s_f_s[n * 150 + 38] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 11], PRIM_INT__g_s_f_s[n * 150 + 38]);

                        PRIM_INT__g_s_f_s[n * 150 + 39] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 19]);
                        PRIM_INT__g_s_f_s[n * 150 + 39] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 19], PRIM_INT__g_s_f_s[n * 150 + 39]);
                        PRIM_INT__g_s_f_s[n * 150 + 39] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 9], PRIM_INT__d_s_f_s[n * 60 + 9]), PRIM_INT__g_s_f_s[n * 150 + 39]);

                        PRIM_INT__g_s_f_s[n * 150 + 40] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 10]);
                        PRIM_INT__g_s_f_s[n * 150 + 40] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 10], PRIM_INT__g_s_f_s[n * 150 + 40]);

                        PRIM_INT__g_s_f_s[n * 150 + 41] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 11]);
                        PRIM_INT__g_s_f_s[n * 150 + 41] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 11], PRIM_INT__g_s_f_s[n * 150 + 41]);

                        PRIM_INT__g_s_f_s[n * 150 + 42] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 12]);
                        PRIM_INT__g_s_f_s[n * 150 + 42] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 12], PRIM_INT__g_s_f_s[n * 150 + 42]);
                        PRIM_INT__g_s_f_s[n * 150 + 42] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 6], PRIM_INT__g_s_f_s[n * 150 + 42]);

                        PRIM_INT__g_s_f_s[n * 150 + 43] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 13]);
                        PRIM_INT__g_s_f_s[n * 150 + 43] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 13], PRIM_INT__g_s_f_s[n * 150 + 43]);

                        PRIM_INT__g_s_f_s[n * 150 + 44] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 14]);
                        PRIM_INT__g_s_f_s[n * 150 + 44] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 14], PRIM_INT__g_s_f_s[n * 150 + 44]);
                        PRIM_INT__g_s_f_s[n * 150 + 44] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 7], PRIM_INT__g_s_f_s[n * 150 + 44]);

                        PRIM_INT__g_s_f_s[n * 150 + 45] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 15]);
                        PRIM_INT__g_s_f_s[n * 150 + 45] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 15], PRIM_INT__g_s_f_s[n * 150 + 45]);
                        PRIM_INT__g_s_f_s[n * 150 + 45] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 8], PRIM_INT__g_s_f_s[n * 150 + 45]);

                        PRIM_INT__g_s_f_s[n * 150 + 46] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 16]);
                        PRIM_INT__g_s_f_s[n * 150 + 46] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 16], PRIM_INT__g_s_f_s[n * 150 + 46]);

                        PRIM_INT__g_s_f_s[n * 150 + 47] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 17]);
                        PRIM_INT__g_s_f_s[n * 150 + 47] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 17], PRIM_INT__g_s_f_s[n * 150 + 47]);
                        PRIM_INT__g_s_f_s[n * 150 + 47] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 9], PRIM_INT__g_s_f_s[n * 150 + 47]);

                        PRIM_INT__g_s_f_s[n * 150 + 48] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 18]);
                        PRIM_INT__g_s_f_s[n * 150 + 48] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 18], PRIM_INT__g_s_f_s[n * 150 + 48]);
                        PRIM_INT__g_s_f_s[n * 150 + 48] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 10], PRIM_INT__g_s_f_s[n * 150 + 48]);

                        PRIM_INT__g_s_f_s[n * 150 + 49] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 19]);
                        PRIM_INT__g_s_f_s[n * 150 + 49] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 19], PRIM_INT__g_s_f_s[n * 150 + 49]);
                        PRIM_INT__g_s_f_s[n * 150 + 49] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 11], PRIM_INT__g_s_f_s[n * 150 + 49]);

                        PRIM_INT__g_s_f_s[n * 150 + 50] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 20]);
                        PRIM_INT__g_s_f_s[n * 150 + 50] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 20], PRIM_INT__g_s_f_s[n * 150 + 50]);
                        PRIM_INT__g_s_f_s[n * 150 + 50] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 0], PRIM_INT__d_s_f_s[n * 60 + 0]), PRIM_INT__g_s_f_s[n * 150 + 50]);

                        PRIM_INT__g_s_f_s[n * 150 + 51] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 21]);
                        PRIM_INT__g_s_f_s[n * 150 + 51] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 21], PRIM_INT__g_s_f_s[n * 150 + 51]);
                        PRIM_INT__g_s_f_s[n * 150 + 51] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 1], PRIM_INT__d_s_f_s[n * 60 + 1]), PRIM_INT__g_s_f_s[n * 150 + 51]);

                        PRIM_INT__g_s_f_s[n * 150 + 52] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 22]);
                        PRIM_INT__g_s_f_s[n * 150 + 52] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 22], PRIM_INT__g_s_f_s[n * 150 + 52]);
                        PRIM_INT__g_s_f_s[n * 150 + 52] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 2], PRIM_INT__d_s_f_s[n * 60 + 2]), PRIM_INT__g_s_f_s[n * 150 + 52]);
                        PRIM_INT__g_s_f_s[n * 150 + 52] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 12], PRIM_INT__g_s_f_s[n * 150 + 52]);

                        PRIM_INT__g_s_f_s[n * 150 + 53] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 23]);
                        PRIM_INT__g_s_f_s[n * 150 + 53] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 23], PRIM_INT__g_s_f_s[n * 150 + 53]);
                        PRIM_INT__g_s_f_s[n * 150 + 53] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 3], PRIM_INT__d_s_f_s[n * 60 + 3]), PRIM_INT__g_s_f_s[n * 150 + 53]);

                        PRIM_INT__g_s_f_s[n * 150 + 54] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 24]);
                        PRIM_INT__g_s_f_s[n * 150 + 54] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 24], PRIM_INT__g_s_f_s[n * 150 + 54]);
                        PRIM_INT__g_s_f_s[n * 150 + 54] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 4], PRIM_INT__d_s_f_s[n * 60 + 4]), PRIM_INT__g_s_f_s[n * 150 + 54]);
                        PRIM_INT__g_s_f_s[n * 150 + 54] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 13], PRIM_INT__g_s_f_s[n * 150 + 54]);

                        PRIM_INT__g_s_f_s[n * 150 + 55] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 25]);
                        PRIM_INT__g_s_f_s[n * 150 + 55] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 25], PRIM_INT__g_s_f_s[n * 150 + 55]);
                        PRIM_INT__g_s_f_s[n * 150 + 55] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 5], PRIM_INT__d_s_f_s[n * 60 + 5]), PRIM_INT__g_s_f_s[n * 150 + 55]);
                        PRIM_INT__g_s_f_s[n * 150 + 55] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 14], PRIM_INT__g_s_f_s[n * 150 + 55]);

                        PRIM_INT__g_s_f_s[n * 150 + 56] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 26]);
                        PRIM_INT__g_s_f_s[n * 150 + 56] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 26], PRIM_INT__g_s_f_s[n * 150 + 56]);
                        PRIM_INT__g_s_f_s[n * 150 + 56] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 6], PRIM_INT__d_s_f_s[n * 60 + 6]), PRIM_INT__g_s_f_s[n * 150 + 56]);

                        PRIM_INT__g_s_f_s[n * 150 + 57] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 27]);
                        PRIM_INT__g_s_f_s[n * 150 + 57] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 27], PRIM_INT__g_s_f_s[n * 150 + 57]);
                        PRIM_INT__g_s_f_s[n * 150 + 57] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 7], PRIM_INT__d_s_f_s[n * 60 + 7]), PRIM_INT__g_s_f_s[n * 150 + 57]);
                        PRIM_INT__g_s_f_s[n * 150 + 57] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 15], PRIM_INT__g_s_f_s[n * 150 + 57]);

                        PRIM_INT__g_s_f_s[n * 150 + 58] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 28]);
                        PRIM_INT__g_s_f_s[n * 150 + 58] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 28], PRIM_INT__g_s_f_s[n * 150 + 58]);
                        PRIM_INT__g_s_f_s[n * 150 + 58] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 8], PRIM_INT__d_s_f_s[n * 60 + 8]), PRIM_INT__g_s_f_s[n * 150 + 58]);
                        PRIM_INT__g_s_f_s[n * 150 + 58] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 16], PRIM_INT__g_s_f_s[n * 150 + 58]);

                        PRIM_INT__g_s_f_s[n * 150 + 59] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 29]);
                        PRIM_INT__g_s_f_s[n * 150 + 59] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 29], PRIM_INT__g_s_f_s[n * 150 + 59]);
                        PRIM_INT__g_s_f_s[n * 150 + 59] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 9], PRIM_INT__d_s_f_s[n * 60 + 9]), PRIM_INT__g_s_f_s[n * 150 + 59]);
                        PRIM_INT__g_s_f_s[n * 150 + 59] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 17], PRIM_INT__g_s_f_s[n * 150 + 59]);

                        PRIM_INT__g_s_f_s[n * 150 + 60] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 60]);
                        PRIM_INT__g_s_f_s[n * 150 + 60] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 60], PRIM_INT__g_s_f_s[n * 150 + 60]);
                        PRIM_INT__g_s_f_s[n * 150 + 60] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 36], PRIM_INT__g_s_f_s[n * 150 + 60]);

                        PRIM_INT__g_s_f_s[n * 150 + 61] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 61]);
                        PRIM_INT__g_s_f_s[n * 150 + 61] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 61], PRIM_INT__g_s_f_s[n * 150 + 61]);
                        PRIM_INT__g_s_f_s[n * 150 + 61] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 37], PRIM_INT__g_s_f_s[n * 150 + 61]);

                        PRIM_INT__g_s_f_s[n * 150 + 62] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 62]);
                        PRIM_INT__g_s_f_s[n * 150 + 62] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 62], PRIM_INT__g_s_f_s[n * 150 + 62]);
                        PRIM_INT__g_s_f_s[n * 150 + 62] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 38], PRIM_INT__g_s_f_s[n * 150 + 62]);

                        PRIM_INT__g_s_f_s[n * 150 + 63] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 63]);
                        PRIM_INT__g_s_f_s[n * 150 + 63] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 63], PRIM_INT__g_s_f_s[n * 150 + 63]);
                        PRIM_INT__g_s_f_s[n * 150 + 63] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 39], PRIM_INT__g_s_f_s[n * 150 + 63]);

                        PRIM_INT__g_s_f_s[n * 150 + 64] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 64]);
                        PRIM_INT__g_s_f_s[n * 150 + 64] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 64], PRIM_INT__g_s_f_s[n * 150 + 64]);
                        PRIM_INT__g_s_f_s[n * 150 + 64] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 40], PRIM_INT__g_s_f_s[n * 150 + 64]);

                        PRIM_INT__g_s_f_s[n * 150 + 65] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 65]);
                        PRIM_INT__g_s_f_s[n * 150 + 65] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 65], PRIM_INT__g_s_f_s[n * 150 + 65]);
                        PRIM_INT__g_s_f_s[n * 150 + 65] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 41], PRIM_INT__g_s_f_s[n * 150 + 65]);

                        PRIM_INT__g_s_f_s[n * 150 + 66] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 66]);
                        PRIM_INT__g_s_f_s[n * 150 + 66] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 66], PRIM_INT__g_s_f_s[n * 150 + 66]);

                        PRIM_INT__g_s_f_s[n * 150 + 67] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 67]);
                        PRIM_INT__g_s_f_s[n * 150 + 67] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 67], PRIM_INT__g_s_f_s[n * 150 + 67]);

                        PRIM_INT__g_s_f_s[n * 150 + 68] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 68]);
                        PRIM_INT__g_s_f_s[n * 150 + 68] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 68], PRIM_INT__g_s_f_s[n * 150 + 68]);

                        PRIM_INT__g_s_f_s[n * 150 + 69] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 69]);
                        PRIM_INT__g_s_f_s[n * 150 + 69] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 69], PRIM_INT__g_s_f_s[n * 150 + 69]);

                        PRIM_INT__g_s_f_s[n * 150 + 70] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 30]);
                        PRIM_INT__g_s_f_s[n * 150 + 70] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 30], PRIM_INT__g_s_f_s[n * 150 + 70]);

                        PRIM_INT__g_s_f_s[n * 150 + 71] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 31]);
                        PRIM_INT__g_s_f_s[n * 150 + 71] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 31], PRIM_INT__g_s_f_s[n * 150 + 71]);

                        PRIM_INT__g_s_f_s[n * 150 + 72] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 32]);
                        PRIM_INT__g_s_f_s[n * 150 + 72] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 32], PRIM_INT__g_s_f_s[n * 150 + 72]);
                        PRIM_INT__g_s_f_s[n * 150 + 72] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 18], PRIM_INT__g_s_f_s[n * 150 + 72]);

                        PRIM_INT__g_s_f_s[n * 150 + 73] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 33]);
                        PRIM_INT__g_s_f_s[n * 150 + 73] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 33], PRIM_INT__g_s_f_s[n * 150 + 73]);

                        PRIM_INT__g_s_f_s[n * 150 + 74] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 34]);
                        PRIM_INT__g_s_f_s[n * 150 + 74] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 34], PRIM_INT__g_s_f_s[n * 150 + 74]);
                        PRIM_INT__g_s_f_s[n * 150 + 74] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 19], PRIM_INT__g_s_f_s[n * 150 + 74]);

                        PRIM_INT__g_s_f_s[n * 150 + 75] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 35]);
                        PRIM_INT__g_s_f_s[n * 150 + 75] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 35], PRIM_INT__g_s_f_s[n * 150 + 75]);
                        PRIM_INT__g_s_f_s[n * 150 + 75] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 20], PRIM_INT__g_s_f_s[n * 150 + 75]);

                        PRIM_INT__g_s_f_s[n * 150 + 76] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 36]);
                        PRIM_INT__g_s_f_s[n * 150 + 76] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 36], PRIM_INT__g_s_f_s[n * 150 + 76]);

                        PRIM_INT__g_s_f_s[n * 150 + 77] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 37]);
                        PRIM_INT__g_s_f_s[n * 150 + 77] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 37], PRIM_INT__g_s_f_s[n * 150 + 77]);
                        PRIM_INT__g_s_f_s[n * 150 + 77] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 21], PRIM_INT__g_s_f_s[n * 150 + 77]);

                        PRIM_INT__g_s_f_s[n * 150 + 78] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 38]);
                        PRIM_INT__g_s_f_s[n * 150 + 78] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 38], PRIM_INT__g_s_f_s[n * 150 + 78]);
                        PRIM_INT__g_s_f_s[n * 150 + 78] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 22], PRIM_INT__g_s_f_s[n * 150 + 78]);

                        PRIM_INT__g_s_f_s[n * 150 + 79] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 39]);
                        PRIM_INT__g_s_f_s[n * 150 + 79] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 39], PRIM_INT__g_s_f_s[n * 150 + 79]);
                        PRIM_INT__g_s_f_s[n * 150 + 79] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 23], PRIM_INT__g_s_f_s[n * 150 + 79]);

                        PRIM_INT__g_s_f_s[n * 150 + 80] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 50]);
                        PRIM_INT__g_s_f_s[n * 150 + 80] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 50], PRIM_INT__g_s_f_s[n * 150 + 80]);

                        PRIM_INT__g_s_f_s[n * 150 + 81] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 51]);
                        PRIM_INT__g_s_f_s[n * 150 + 81] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 51], PRIM_INT__g_s_f_s[n * 150 + 81]);
                        PRIM_INT__g_s_f_s[n * 150 + 81] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 30], PRIM_INT__g_s_f_s[n * 150 + 81]);

                        PRIM_INT__g_s_f_s[n * 150 + 82] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 52]);
                        PRIM_INT__g_s_f_s[n * 150 + 82] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 52], PRIM_INT__g_s_f_s[n * 150 + 82]);

                        PRIM_INT__g_s_f_s[n * 150 + 83] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 53]);
                        PRIM_INT__g_s_f_s[n * 150 + 83] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 53], PRIM_INT__g_s_f_s[n * 150 + 83]);
                        PRIM_INT__g_s_f_s[n * 150 + 83] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 31], PRIM_INT__g_s_f_s[n * 150 + 83]);

                        PRIM_INT__g_s_f_s[n * 150 + 84] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 54]);
                        PRIM_INT__g_s_f_s[n * 150 + 84] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 54], PRIM_INT__g_s_f_s[n * 150 + 84]);
                        PRIM_INT__g_s_f_s[n * 150 + 84] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 32], PRIM_INT__g_s_f_s[n * 150 + 84]);

                        PRIM_INT__g_s_f_s[n * 150 + 85] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 55]);
                        PRIM_INT__g_s_f_s[n * 150 + 85] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 55], PRIM_INT__g_s_f_s[n * 150 + 85]);

                        PRIM_INT__g_s_f_s[n * 150 + 86] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 56]);
                        PRIM_INT__g_s_f_s[n * 150 + 86] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 56], PRIM_INT__g_s_f_s[n * 150 + 86]);
                        PRIM_INT__g_s_f_s[n * 150 + 86] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 33], PRIM_INT__g_s_f_s[n * 150 + 86]);

                        PRIM_INT__g_s_f_s[n * 150 + 87] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 57]);
                        PRIM_INT__g_s_f_s[n * 150 + 87] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 57], PRIM_INT__g_s_f_s[n * 150 + 87]);
                        PRIM_INT__g_s_f_s[n * 150 + 87] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 34], PRIM_INT__g_s_f_s[n * 150 + 87]);

                        PRIM_INT__g_s_f_s[n * 150 + 88] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 58]);
                        PRIM_INT__g_s_f_s[n * 150 + 88] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 58], PRIM_INT__g_s_f_s[n * 150 + 88]);
                        PRIM_INT__g_s_f_s[n * 150 + 88] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 35], PRIM_INT__g_s_f_s[n * 150 + 88]);

                        PRIM_INT__g_s_f_s[n * 150 + 89] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 59]);
                        PRIM_INT__g_s_f_s[n * 150 + 89] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 59], PRIM_INT__g_s_f_s[n * 150 + 89]);

                        PRIM_INT__g_s_f_s[n * 150 + 90] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 90]);
                        PRIM_INT__g_s_f_s[n * 150 + 90] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 90], PRIM_INT__g_s_f_s[n * 150 + 90]);
                        PRIM_INT__g_s_f_s[n * 150 + 90] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 54], PRIM_INT__g_s_f_s[n * 150 + 90]);

                        PRIM_INT__g_s_f_s[n * 150 + 91] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 91]);
                        PRIM_INT__g_s_f_s[n * 150 + 91] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 91], PRIM_INT__g_s_f_s[n * 150 + 91]);
                        PRIM_INT__g_s_f_s[n * 150 + 91] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 55], PRIM_INT__g_s_f_s[n * 150 + 91]);

                        PRIM_INT__g_s_f_s[n * 150 + 92] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 92]);
                        PRIM_INT__g_s_f_s[n * 150 + 92] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 92], PRIM_INT__g_s_f_s[n * 150 + 92]);
                        PRIM_INT__g_s_f_s[n * 150 + 92] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 56], PRIM_INT__g_s_f_s[n * 150 + 92]);

                        PRIM_INT__g_s_f_s[n * 150 + 93] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 93]);
                        PRIM_INT__g_s_f_s[n * 150 + 93] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 93], PRIM_INT__g_s_f_s[n * 150 + 93]);
                        PRIM_INT__g_s_f_s[n * 150 + 93] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 57], PRIM_INT__g_s_f_s[n * 150 + 93]);

                        PRIM_INT__g_s_f_s[n * 150 + 94] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 94]);
                        PRIM_INT__g_s_f_s[n * 150 + 94] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 94], PRIM_INT__g_s_f_s[n * 150 + 94]);
                        PRIM_INT__g_s_f_s[n * 150 + 94] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 58], PRIM_INT__g_s_f_s[n * 150 + 94]);

                        PRIM_INT__g_s_f_s[n * 150 + 95] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 95]);
                        PRIM_INT__g_s_f_s[n * 150 + 95] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 95], PRIM_INT__g_s_f_s[n * 150 + 95]);
                        PRIM_INT__g_s_f_s[n * 150 + 95] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 59], PRIM_INT__g_s_f_s[n * 150 + 95]);

                        PRIM_INT__g_s_f_s[n * 150 + 96] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 96]);
                        PRIM_INT__g_s_f_s[n * 150 + 96] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 96], PRIM_INT__g_s_f_s[n * 150 + 96]);

                        PRIM_INT__g_s_f_s[n * 150 + 97] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 97]);
                        PRIM_INT__g_s_f_s[n * 150 + 97] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 97], PRIM_INT__g_s_f_s[n * 150 + 97]);

                        PRIM_INT__g_s_f_s[n * 150 + 98] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 98]);
                        PRIM_INT__g_s_f_s[n * 150 + 98] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 98], PRIM_INT__g_s_f_s[n * 150 + 98]);

                        PRIM_INT__g_s_f_s[n * 150 + 99] = SIMINT_MUL(P_PA[0], PRIM_INT__f_s_f_s[n * 100 + 99]);
                        PRIM_INT__g_s_f_s[n * 150 + 99] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__f_s_f_s[(n+1) * 100 + 99], PRIM_INT__g_s_f_s[n * 150 + 99]);

                        PRIM_INT__g_s_f_s[n * 150 + 100] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 60]);
                        PRIM_INT__g_s_f_s[n * 150 + 100] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 60], PRIM_INT__g_s_f_s[n * 150 + 100]);
                        PRIM_INT__g_s_f_s[n * 150 + 100] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 30], PRIM_INT__d_s_f_s[n * 60 + 30]), PRIM_INT__g_s_f_s[n * 150 + 100]);

                        PRIM_INT__g_s_f_s[n * 150 + 101] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 61]);
                        PRIM_INT__g_s_f_s[n * 150 + 101] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 61], PRIM_INT__g_s_f_s[n * 150 + 101]);
                        PRIM_INT__g_s_f_s[n * 150 + 101] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 31], PRIM_INT__d_s_f_s[n * 60 + 31]), PRIM_INT__g_s_f_s[n * 150 + 101]);
                        PRIM_INT__g_s_f_s[n * 150 + 101] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 36], PRIM_INT__g_s_f_s[n * 150 + 101]);

                        PRIM_INT__g_s_f_s[n * 150 + 102] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 62]);
                        PRIM_INT__g_s_f_s[n * 150 + 102] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 62], PRIM_INT__g_s_f_s[n * 150 + 102]);
                        PRIM_INT__g_s_f_s[n * 150 + 102] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 32], PRIM_INT__d_s_f_s[n * 60 + 32]), PRIM_INT__g_s_f_s[n * 150 + 102]);

                        PRIM_INT__g_s_f_s[n * 150 + 103] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 63]);
                        PRIM_INT__g_s_f_s[n * 150 + 103] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 63], PRIM_INT__g_s_f_s[n * 150 + 103]);
                        PRIM_INT__g_s_f_s[n * 150 + 103] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 33], PRIM_INT__d_s_f_s[n * 60 + 33]), PRIM_INT__g_s_f_s[n * 150 + 103]);
                        PRIM_INT__g_s_f_s[n * 150 + 103] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 37], PRIM_INT__g_s_f_s[n * 150 + 103]);

                        PRIM_INT__g_s_f_s[n * 150 + 104] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 64]);
                        PRIM_INT__g_s_f_s[n * 150 + 104] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 64], PRIM_INT__g_s_f_s[n * 150 + 104]);
                        PRIM_INT__g_s_f_s[n * 150 + 104] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 34], PRIM_INT__d_s_f_s[n * 60 + 34]), PRIM_INT__g_s_f_s[n * 150 + 104]);
                        PRIM_INT__g_s_f_s[n * 150 + 104] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 38], PRIM_INT__g_s_f_s[n * 150 + 104]);

                        PRIM_INT__g_s_f_s[n * 150 + 105] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 65]);
                        PRIM_INT__g_s_f_s[n * 150 + 105] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 65], PRIM_INT__g_s_f_s[n * 150 + 105]);
                        PRIM_INT__g_s_f_s[n * 150 + 105] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 35], PRIM_INT__d_s_f_s[n * 60 + 35]), PRIM_INT__g_s_f_s[n * 150 + 105]);

                        PRIM_INT__g_s_f_s[n * 150 + 106] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 66]);
                        PRIM_INT__g_s_f_s[n * 150 + 106] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 66], PRIM_INT__g_s_f_s[n * 150 + 106]);
                        PRIM_INT__g_s_f_s[n * 150 + 106] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 36], PRIM_INT__d_s_f_s[n * 60 + 36]), PRIM_INT__g_s_f_s[n * 150 + 106]);
                        PRIM_INT__g_s_f_s[n * 150 + 106] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 39], PRIM_INT__g_s_f_s[n * 150 + 106]);

                        PRIM_INT__g_s_f_s[n * 150 + 107] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 67]);
                        PRIM_INT__g_s_f_s[n * 150 + 107] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 67], PRIM_INT__g_s_f_s[n * 150 + 107]);
                        PRIM_INT__g_s_f_s[n * 150 + 107] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 37], PRIM_INT__d_s_f_s[n * 60 + 37]), PRIM_INT__g_s_f_s[n * 150 + 107]);
                        PRIM_INT__g_s_f_s[n * 150 + 107] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 40], PRIM_INT__g_s_f_s[n * 150 + 107]);

                        PRIM_INT__g_s_f_s[n * 150 + 108] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 68]);
                        PRIM_INT__g_s_f_s[n * 150 + 108] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 68], PRIM_INT__g_s_f_s[n * 150 + 108]);
                        PRIM_INT__g_s_f_s[n * 150 + 108] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 38], PRIM_INT__d_s_f_s[n * 60 + 38]), PRIM_INT__g_s_f_s[n * 150 + 108]);
                        PRIM_INT__g_s_f_s[n * 150 + 108] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 41], PRIM_INT__g_s_f_s[n * 150 + 108]);

                        PRIM_INT__g_s_f_s[n * 150 + 109] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 69]);
                        PRIM_INT__g_s_f_s[n * 150 + 109] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 69], PRIM_INT__g_s_f_s[n * 150 + 109]);
                        PRIM_INT__g_s_f_s[n * 150 + 109] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 39], PRIM_INT__d_s_f_s[n * 60 + 39]), PRIM_INT__g_s_f_s[n * 150 + 109]);

                        PRIM_INT__g_s_f_s[n * 150 + 110] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 60]);
                        PRIM_INT__g_s_f_s[n * 150 + 110] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 60], PRIM_INT__g_s_f_s[n * 150 + 110]);

                        PRIM_INT__g_s_f_s[n * 150 + 111] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 61]);
                        PRIM_INT__g_s_f_s[n * 150 + 111] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 61], PRIM_INT__g_s_f_s[n * 150 + 111]);

                        PRIM_INT__g_s_f_s[n * 150 + 112] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 62]);
                        PRIM_INT__g_s_f_s[n * 150 + 112] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 62], PRIM_INT__g_s_f_s[n * 150 + 112]);
                        PRIM_INT__g_s_f_s[n * 150 + 112] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 36], PRIM_INT__g_s_f_s[n * 150 + 112]);

                        PRIM_INT__g_s_f_s[n * 150 + 113] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 63]);
                        PRIM_INT__g_s_f_s[n * 150 + 113] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 63], PRIM_INT__g_s_f_s[n * 150 + 113]);

                        PRIM_INT__g_s_f_s[n * 150 + 114] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 64]);
                        PRIM_INT__g_s_f_s[n * 150 + 114] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 64], PRIM_INT__g_s_f_s[n * 150 + 114]);
                        PRIM_INT__g_s_f_s[n * 150 + 114] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 37], PRIM_INT__g_s_f_s[n * 150 + 114]);

                        PRIM_INT__g_s_f_s[n * 150 + 115] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 65]);
                        PRIM_INT__g_s_f_s[n * 150 + 115] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 65], PRIM_INT__g_s_f_s[n * 150 + 115]);
                        PRIM_INT__g_s_f_s[n * 150 + 115] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 38], PRIM_INT__g_s_f_s[n * 150 + 115]);

                        PRIM_INT__g_s_f_s[n * 150 + 116] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 66]);
                        PRIM_INT__g_s_f_s[n * 150 + 116] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 66], PRIM_INT__g_s_f_s[n * 150 + 116]);

                        PRIM_INT__g_s_f_s[n * 150 + 117] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 67]);
                        PRIM_INT__g_s_f_s[n * 150 + 117] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 67], PRIM_INT__g_s_f_s[n * 150 + 117]);
                        PRIM_INT__g_s_f_s[n * 150 + 117] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 39], PRIM_INT__g_s_f_s[n * 150 + 117]);

                        PRIM_INT__g_s_f_s[n * 150 + 118] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 68]);
                        PRIM_INT__g_s_f_s[n * 150 + 118] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 68], PRIM_INT__g_s_f_s[n * 150 + 118]);
                        PRIM_INT__g_s_f_s[n * 150 + 118] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 40], PRIM_INT__g_s_f_s[n * 150 + 118]);

                        PRIM_INT__g_s_f_s[n * 150 + 119] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 69]);
                        PRIM_INT__g_s_f_s[n * 150 + 119] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 69], PRIM_INT__g_s_f_s[n * 150 + 119]);
                        PRIM_INT__g_s_f_s[n * 150 + 119] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 41], PRIM_INT__g_s_f_s[n * 150 + 119]);

                        PRIM_INT__g_s_f_s[n * 150 + 120] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 70]);
                        PRIM_INT__g_s_f_s[n * 150 + 120] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 70], PRIM_INT__g_s_f_s[n * 150 + 120]);
                        PRIM_INT__g_s_f_s[n * 150 + 120] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 30], PRIM_INT__d_s_f_s[n * 60 + 30]), PRIM_INT__g_s_f_s[n * 150 + 120]);

                        PRIM_INT__g_s_f_s[n * 150 + 121] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 71]);
                        PRIM_INT__g_s_f_s[n * 150 + 121] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 71], PRIM_INT__g_s_f_s[n * 150 + 121]);
                        PRIM_INT__g_s_f_s[n * 150 + 121] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 31], PRIM_INT__d_s_f_s[n * 60 + 31]), PRIM_INT__g_s_f_s[n * 150 + 121]);

                        PRIM_INT__g_s_f_s[n * 150 + 122] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 72]);
                        PRIM_INT__g_s_f_s[n * 150 + 122] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 72], PRIM_INT__g_s_f_s[n * 150 + 122]);
                        PRIM_INT__g_s_f_s[n * 150 + 122] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 32], PRIM_INT__d_s_f_s[n * 60 + 32]), PRIM_INT__g_s_f_s[n * 150 + 122]);
                        PRIM_INT__g_s_f_s[n * 150 + 122] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 42], PRIM_INT__g_s_f_s[n * 150 + 122]);

                        PRIM_INT__g_s_f_s[n * 150 + 123] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 73]);
                        PRIM_INT__g_s_f_s[n * 150 + 123] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 73], PRIM_INT__g_s_f_s[n * 150 + 123]);
                        PRIM_INT__g_s_f_s[n * 150 + 123] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 33], PRIM_INT__d_s_f_s[n * 60 + 33]), PRIM_INT__g_s_f_s[n * 150 + 123]);

                        PRIM_INT__g_s_f_s[n * 150 + 124] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 74]);
                        PRIM_INT__g_s_f_s[n * 150 + 124] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 74], PRIM_INT__g_s_f_s[n * 150 + 124]);
                        PRIM_INT__g_s_f_s[n * 150 + 124] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 34], PRIM_INT__d_s_f_s[n * 60 + 34]), PRIM_INT__g_s_f_s[n * 150 + 124]);
                        PRIM_INT__g_s_f_s[n * 150 + 124] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 43], PRIM_INT__g_s_f_s[n * 150 + 124]);

                        PRIM_INT__g_s_f_s[n * 150 + 125] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 75]);
                        PRIM_INT__g_s_f_s[n * 150 + 125] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 75], PRIM_INT__g_s_f_s[n * 150 + 125]);
                        PRIM_INT__g_s_f_s[n * 150 + 125] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 35], PRIM_INT__d_s_f_s[n * 60 + 35]), PRIM_INT__g_s_f_s[n * 150 + 125]);
                        PRIM_INT__g_s_f_s[n * 150 + 125] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 44], PRIM_INT__g_s_f_s[n * 150 + 125]);

                        PRIM_INT__g_s_f_s[n * 150 + 126] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 76]);
                        PRIM_INT__g_s_f_s[n * 150 + 126] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 76], PRIM_INT__g_s_f_s[n * 150 + 126]);
                        PRIM_INT__g_s_f_s[n * 150 + 126] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 36], PRIM_INT__d_s_f_s[n * 60 + 36]), PRIM_INT__g_s_f_s[n * 150 + 126]);

                        PRIM_INT__g_s_f_s[n * 150 + 127] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 77]);
                        PRIM_INT__g_s_f_s[n * 150 + 127] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 77], PRIM_INT__g_s_f_s[n * 150 + 127]);
                        PRIM_INT__g_s_f_s[n * 150 + 127] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 37], PRIM_INT__d_s_f_s[n * 60 + 37]), PRIM_INT__g_s_f_s[n * 150 + 127]);
                        PRIM_INT__g_s_f_s[n * 150 + 127] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 45], PRIM_INT__g_s_f_s[n * 150 + 127]);

                        PRIM_INT__g_s_f_s[n * 150 + 128] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 78]);
                        PRIM_INT__g_s_f_s[n * 150 + 128] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 78], PRIM_INT__g_s_f_s[n * 150 + 128]);
                        PRIM_INT__g_s_f_s[n * 150 + 128] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 38], PRIM_INT__d_s_f_s[n * 60 + 38]), PRIM_INT__g_s_f_s[n * 150 + 128]);
                        PRIM_INT__g_s_f_s[n * 150 + 128] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 46], PRIM_INT__g_s_f_s[n * 150 + 128]);

                        PRIM_INT__g_s_f_s[n * 150 + 129] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 79]);
                        PRIM_INT__g_s_f_s[n * 150 + 129] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 79], PRIM_INT__g_s_f_s[n * 150 + 129]);
                        PRIM_INT__g_s_f_s[n * 150 + 129] = SIMINT_FMADD( vrr_const_1_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 39], PRIM_INT__d_s_f_s[n * 60 + 39]), PRIM_INT__g_s_f_s[n * 150 + 129]);
                        PRIM_INT__g_s_f_s[n * 150 + 129] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 47], PRIM_INT__g_s_f_s[n * 150 + 129]);

                        PRIM_INT__g_s_f_s[n * 150 + 130] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 90]);
                        PRIM_INT__g_s_f_s[n * 150 + 130] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 90], PRIM_INT__g_s_f_s[n * 150 + 130]);

                        PRIM_INT__g_s_f_s[n * 150 + 131] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 91]);
                        PRIM_INT__g_s_f_s[n * 150 + 131] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 91], PRIM_INT__g_s_f_s[n * 150 + 131]);
                        PRIM_INT__g_s_f_s[n * 150 + 131] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 54], PRIM_INT__g_s_f_s[n * 150 + 131]);

                        PRIM_INT__g_s_f_s[n * 150 + 132] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 92]);
                        PRIM_INT__g_s_f_s[n * 150 + 132] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 92], PRIM_INT__g_s_f_s[n * 150 + 132]);

                        PRIM_INT__g_s_f_s[n * 150 + 133] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 93]);
                        PRIM_INT__g_s_f_s[n * 150 + 133] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 93], PRIM_INT__g_s_f_s[n * 150 + 133]);
                        PRIM_INT__g_s_f_s[n * 150 + 133] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 55], PRIM_INT__g_s_f_s[n * 150 + 133]);

                        PRIM_INT__g_s_f_s[n * 150 + 134] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 94]);
                        PRIM_INT__g_s_f_s[n * 150 + 134] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 94], PRIM_INT__g_s_f_s[n * 150 + 134]);
                        PRIM_INT__g_s_f_s[n * 150 + 134] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 56], PRIM_INT__g_s_f_s[n * 150 + 134]);

                        PRIM_INT__g_s_f_s[n * 150 + 135] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 95]);
                        PRIM_INT__g_s_f_s[n * 150 + 135] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 95], PRIM_INT__g_s_f_s[n * 150 + 135]);

                        PRIM_INT__g_s_f_s[n * 150 + 136] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 96]);
                        PRIM_INT__g_s_f_s[n * 150 + 136] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 96], PRIM_INT__g_s_f_s[n * 150 + 136]);
                        PRIM_INT__g_s_f_s[n * 150 + 136] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 57], PRIM_INT__g_s_f_s[n * 150 + 136]);

                        PRIM_INT__g_s_f_s[n * 150 + 137] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 97]);
                        PRIM_INT__g_s_f_s[n * 150 + 137] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 97], PRIM_INT__g_s_f_s[n * 150 + 137]);
                        PRIM_INT__g_s_f_s[n * 150 + 137] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 58], PRIM_INT__g_s_f_s[n * 150 + 137]);

                        PRIM_INT__g_s_f_s[n * 150 + 138] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 98]);
                        PRIM_INT__g_s_f_s[n * 150 + 138] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 98], PRIM_INT__g_s_f_s[n * 150 + 138]);
                        PRIM_INT__g_s_f_s[n * 150 + 138] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 59], PRIM_INT__g_s_f_s[n * 150 + 138]);

                        PRIM_INT__g_s_f_s[n * 150 + 139] = SIMINT_MUL(P_PA[1], PRIM_INT__f_s_f_s[n * 100 + 99]);
                        PRIM_INT__g_s_f_s[n * 150 + 139] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__f_s_f_s[(n+1) * 100 + 99], PRIM_INT__g_s_f_s[n * 150 + 139]);

                        PRIM_INT__g_s_f_s[n * 150 + 140] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 90]);
                        PRIM_INT__g_s_f_s[n * 150 + 140] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 90], PRIM_INT__g_s_f_s[n * 150 + 140]);
                        PRIM_INT__g_s_f_s[n * 150 + 140] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 50], PRIM_INT__d_s_f_s[n * 60 + 50]), PRIM_INT__g_s_f_s[n * 150 + 140]);

                        PRIM_INT__g_s_f_s[n * 150 + 141] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 91]);
                        PRIM_INT__g_s_f_s[n * 150 + 141] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 91], PRIM_INT__g_s_f_s[n * 150 + 141]);
                        PRIM_INT__g_s_f_s[n * 150 + 141] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 51], PRIM_INT__d_s_f_s[n * 60 + 51]), PRIM_INT__g_s_f_s[n * 150 + 141]);

                        PRIM_INT__g_s_f_s[n * 150 + 142] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 92]);
                        PRIM_INT__g_s_f_s[n * 150 + 142] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 92], PRIM_INT__g_s_f_s[n * 150 + 142]);
                        PRIM_INT__g_s_f_s[n * 150 + 142] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 52], PRIM_INT__d_s_f_s[n * 60 + 52]), PRIM_INT__g_s_f_s[n * 150 + 142]);
                        PRIM_INT__g_s_f_s[n * 150 + 142] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 54], PRIM_INT__g_s_f_s[n * 150 + 142]);

                        PRIM_INT__g_s_f_s[n * 150 + 143] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 93]);
                        PRIM_INT__g_s_f_s[n * 150 + 143] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 93], PRIM_INT__g_s_f_s[n * 150 + 143]);
                        PRIM_INT__g_s_f_s[n * 150 + 143] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 53], PRIM_INT__d_s_f_s[n * 60 + 53]), PRIM_INT__g_s_f_s[n * 150 + 143]);

                        PRIM_INT__g_s_f_s[n * 150 + 144] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 94]);
                        PRIM_INT__g_s_f_s[n * 150 + 144] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 94], PRIM_INT__g_s_f_s[n * 150 + 144]);
                        PRIM_INT__g_s_f_s[n * 150 + 144] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 54], PRIM_INT__d_s_f_s[n * 60 + 54]), PRIM_INT__g_s_f_s[n * 150 + 144]);
                        PRIM_INT__g_s_f_s[n * 150 + 144] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 55], PRIM_INT__g_s_f_s[n * 150 + 144]);

                        PRIM_INT__g_s_f_s[n * 150 + 145] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 95]);
                        PRIM_INT__g_s_f_s[n * 150 + 145] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 95], PRIM_INT__g_s_f_s[n * 150 + 145]);
                        PRIM_INT__g_s_f_s[n * 150 + 145] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 55], PRIM_INT__d_s_f_s[n * 60 + 55]), PRIM_INT__g_s_f_s[n * 150 + 145]);
                        PRIM_INT__g_s_f_s[n * 150 + 145] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 56], PRIM_INT__g_s_f_s[n * 150 + 145]);

                        PRIM_INT__g_s_f_s[n * 150 + 146] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 96]);
                        PRIM_INT__g_s_f_s[n * 150 + 146] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 96], PRIM_INT__g_s_f_s[n * 150 + 146]);
                        PRIM_INT__g_s_f_s[n * 150 + 146] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 56], PRIM_INT__d_s_f_s[n * 60 + 56]), PRIM_INT__g_s_f_s[n * 150 + 146]);

                        PRIM_INT__g_s_f_s[n * 150 + 147] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 97]);
                        PRIM_INT__g_s_f_s[n * 150 + 147] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 97], PRIM_INT__g_s_f_s[n * 150 + 147]);
                        PRIM_INT__g_s_f_s[n * 150 + 147] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 57], PRIM_INT__d_s_f_s[n * 60 + 57]), PRIM_INT__g_s_f_s[n * 150 + 147]);
                        PRIM_INT__g_s_f_s[n * 150 + 147] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 57], PRIM_INT__g_s_f_s[n * 150 + 147]);

                        PRIM_INT__g_s_f_s[n * 150 + 148] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 98]);
                        PRIM_INT__g_s_f_s[n * 150 + 148] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 98], PRIM_INT__g_s_f_s[n * 150 + 148]);
                        PRIM_INT__g_s_f_s[n * 150 + 148] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 58], PRIM_INT__d_s_f_s[n * 60 + 58]), PRIM_INT__g_s_f_s[n * 150 + 148]);
                        PRIM_INT__g_s_f_s[n * 150 + 148] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 58], PRIM_INT__g_s_f_s[n * 150 + 148]);

                        PRIM_INT__g_s_f_s[n * 150 + 149] = SIMINT_MUL(P_PA[2], PRIM_INT__f_s_f_s[n * 100 + 99]);
                        PRIM_INT__g_s_f_s[n * 150 + 149] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__f_s_f_s[(n+1) * 100 + 99], PRIM_INT__g_s_f_s[n * 150 + 149]);
                        PRIM_INT__g_s_f_s[n * 150 + 149] = SIMINT_FMADD( vrr_const_3_over_2p, SIMINT_FMADD(a_over_p, PRIM_INT__d_s_f_s[(n+1) * 60 + 59], PRIM_INT__d_s_f_s[n * 60 + 59]), PRIM_INT__g_s_f_s[n * 150 + 149]);
                        PRIM_INT__g_s_f_s[n * 150 + 149] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_d_s[(n+1) * 60 + 59], PRIM_INT__g_s_f_s[n * 150 + 149]);

                    }

}


