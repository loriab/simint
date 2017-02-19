
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( h s | p s )
//////////////////////////////////////////////
void VRR_K_h_s_p_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n)
{
    int n = 0;
    const SIMINT_DBLTYPE vrr_const_1_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(1), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(2), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_3_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(3), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_4_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(4), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_5_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(5), one_over_2pq);

                    // Forming PRIM_INT__h_s_p_s[num_n * 63];
                    for(n = 0; n < num_n; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__h_s_p_s[n * 63 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 0]);
                        PRIM_INT__h_s_p_s[n * 63 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 0], PRIM_INT__h_s_p_s[n * 63 + 0]);
                        PRIM_INT__h_s_p_s[n * 63 + 0] = SIMINT_FMADD( vrr_const_5_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 0], PRIM_INT__h_s_p_s[n * 63 + 0]);

                        PRIM_INT__h_s_p_s[n * 63 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 0]);
                        PRIM_INT__h_s_p_s[n * 63 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 0], PRIM_INT__h_s_p_s[n * 63 + 1]);

                        PRIM_INT__h_s_p_s[n * 63 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 0]);
                        PRIM_INT__h_s_p_s[n * 63 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 0], PRIM_INT__h_s_p_s[n * 63 + 2]);

                        PRIM_INT__h_s_p_s[n * 63 + 3] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 1]);
                        PRIM_INT__h_s_p_s[n * 63 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 1], PRIM_INT__h_s_p_s[n * 63 + 3]);
                        PRIM_INT__h_s_p_s[n * 63 + 3] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 1], PRIM_INT__h_s_p_s[n * 63 + 3]);

                        PRIM_INT__h_s_p_s[n * 63 + 4] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 1]);
                        PRIM_INT__h_s_p_s[n * 63 + 4] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 1], PRIM_INT__h_s_p_s[n * 63 + 4]);
                        PRIM_INT__h_s_p_s[n * 63 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 0], PRIM_INT__h_s_p_s[n * 63 + 4]);

                        PRIM_INT__h_s_p_s[n * 63 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 1]);
                        PRIM_INT__h_s_p_s[n * 63 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 1], PRIM_INT__h_s_p_s[n * 63 + 5]);

                        PRIM_INT__h_s_p_s[n * 63 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 2]);
                        PRIM_INT__h_s_p_s[n * 63 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 2], PRIM_INT__h_s_p_s[n * 63 + 6]);
                        PRIM_INT__h_s_p_s[n * 63 + 6] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 2], PRIM_INT__h_s_p_s[n * 63 + 6]);

                        PRIM_INT__h_s_p_s[n * 63 + 7] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 2]);
                        PRIM_INT__h_s_p_s[n * 63 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 2], PRIM_INT__h_s_p_s[n * 63 + 7]);

                        PRIM_INT__h_s_p_s[n * 63 + 8] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 2]);
                        PRIM_INT__h_s_p_s[n * 63 + 8] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 2], PRIM_INT__h_s_p_s[n * 63 + 8]);
                        PRIM_INT__h_s_p_s[n * 63 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 0], PRIM_INT__h_s_p_s[n * 63 + 8]);

                        PRIM_INT__h_s_p_s[n * 63 + 9] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 3]);
                        PRIM_INT__h_s_p_s[n * 63 + 9] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 3], PRIM_INT__h_s_p_s[n * 63 + 9]);
                        PRIM_INT__h_s_p_s[n * 63 + 9] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 3], PRIM_INT__h_s_p_s[n * 63 + 9]);

                        PRIM_INT__h_s_p_s[n * 63 + 10] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 3]);
                        PRIM_INT__h_s_p_s[n * 63 + 10] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 3], PRIM_INT__h_s_p_s[n * 63 + 10]);
                        PRIM_INT__h_s_p_s[n * 63 + 10] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 1], PRIM_INT__h_s_p_s[n * 63 + 10]);

                        PRIM_INT__h_s_p_s[n * 63 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 3]);
                        PRIM_INT__h_s_p_s[n * 63 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 3], PRIM_INT__h_s_p_s[n * 63 + 11]);

                        PRIM_INT__h_s_p_s[n * 63 + 12] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 4]);
                        PRIM_INT__h_s_p_s[n * 63 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 4], PRIM_INT__h_s_p_s[n * 63 + 12]);
                        PRIM_INT__h_s_p_s[n * 63 + 12] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 4], PRIM_INT__h_s_p_s[n * 63 + 12]);

                        PRIM_INT__h_s_p_s[n * 63 + 13] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 4]);
                        PRIM_INT__h_s_p_s[n * 63 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 4], PRIM_INT__h_s_p_s[n * 63 + 13]);
                        PRIM_INT__h_s_p_s[n * 63 + 13] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 2], PRIM_INT__h_s_p_s[n * 63 + 13]);

                        PRIM_INT__h_s_p_s[n * 63 + 14] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 4]);
                        PRIM_INT__h_s_p_s[n * 63 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 4], PRIM_INT__h_s_p_s[n * 63 + 14]);
                        PRIM_INT__h_s_p_s[n * 63 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 1], PRIM_INT__h_s_p_s[n * 63 + 14]);

                        PRIM_INT__h_s_p_s[n * 63 + 15] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 5]);
                        PRIM_INT__h_s_p_s[n * 63 + 15] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 5], PRIM_INT__h_s_p_s[n * 63 + 15]);
                        PRIM_INT__h_s_p_s[n * 63 + 15] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 5], PRIM_INT__h_s_p_s[n * 63 + 15]);

                        PRIM_INT__h_s_p_s[n * 63 + 16] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 5]);
                        PRIM_INT__h_s_p_s[n * 63 + 16] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 5], PRIM_INT__h_s_p_s[n * 63 + 16]);

                        PRIM_INT__h_s_p_s[n * 63 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 5]);
                        PRIM_INT__h_s_p_s[n * 63 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 5], PRIM_INT__h_s_p_s[n * 63 + 17]);
                        PRIM_INT__h_s_p_s[n * 63 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 2], PRIM_INT__h_s_p_s[n * 63 + 17]);

                        PRIM_INT__h_s_p_s[n * 63 + 18] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 6]);
                        PRIM_INT__h_s_p_s[n * 63 + 18] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 6], PRIM_INT__h_s_p_s[n * 63 + 18]);
                        PRIM_INT__h_s_p_s[n * 63 + 18] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 6], PRIM_INT__h_s_p_s[n * 63 + 18]);

                        PRIM_INT__h_s_p_s[n * 63 + 19] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 6]);
                        PRIM_INT__h_s_p_s[n * 63 + 19] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 6], PRIM_INT__h_s_p_s[n * 63 + 19]);
                        PRIM_INT__h_s_p_s[n * 63 + 19] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 3], PRIM_INT__h_s_p_s[n * 63 + 19]);

                        PRIM_INT__h_s_p_s[n * 63 + 20] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 6]);
                        PRIM_INT__h_s_p_s[n * 63 + 20] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 6], PRIM_INT__h_s_p_s[n * 63 + 20]);

                        PRIM_INT__h_s_p_s[n * 63 + 21] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 7]);
                        PRIM_INT__h_s_p_s[n * 63 + 21] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 7], PRIM_INT__h_s_p_s[n * 63 + 21]);
                        PRIM_INT__h_s_p_s[n * 63 + 21] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 7], PRIM_INT__h_s_p_s[n * 63 + 21]);

                        PRIM_INT__h_s_p_s[n * 63 + 22] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 7]);
                        PRIM_INT__h_s_p_s[n * 63 + 22] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 7], PRIM_INT__h_s_p_s[n * 63 + 22]);
                        PRIM_INT__h_s_p_s[n * 63 + 22] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 4], PRIM_INT__h_s_p_s[n * 63 + 22]);

                        PRIM_INT__h_s_p_s[n * 63 + 23] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 7]);
                        PRIM_INT__h_s_p_s[n * 63 + 23] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 7], PRIM_INT__h_s_p_s[n * 63 + 23]);
                        PRIM_INT__h_s_p_s[n * 63 + 23] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 3], PRIM_INT__h_s_p_s[n * 63 + 23]);

                        PRIM_INT__h_s_p_s[n * 63 + 24] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 8]);
                        PRIM_INT__h_s_p_s[n * 63 + 24] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 8], PRIM_INT__h_s_p_s[n * 63 + 24]);
                        PRIM_INT__h_s_p_s[n * 63 + 24] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 8], PRIM_INT__h_s_p_s[n * 63 + 24]);

                        PRIM_INT__h_s_p_s[n * 63 + 25] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 8]);
                        PRIM_INT__h_s_p_s[n * 63 + 25] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 8], PRIM_INT__h_s_p_s[n * 63 + 25]);
                        PRIM_INT__h_s_p_s[n * 63 + 25] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 5], PRIM_INT__h_s_p_s[n * 63 + 25]);

                        PRIM_INT__h_s_p_s[n * 63 + 26] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 8]);
                        PRIM_INT__h_s_p_s[n * 63 + 26] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 8], PRIM_INT__h_s_p_s[n * 63 + 26]);
                        PRIM_INT__h_s_p_s[n * 63 + 26] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 4], PRIM_INT__h_s_p_s[n * 63 + 26]);

                        PRIM_INT__h_s_p_s[n * 63 + 27] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 9]);
                        PRIM_INT__h_s_p_s[n * 63 + 27] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 9], PRIM_INT__h_s_p_s[n * 63 + 27]);
                        PRIM_INT__h_s_p_s[n * 63 + 27] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 9], PRIM_INT__h_s_p_s[n * 63 + 27]);

                        PRIM_INT__h_s_p_s[n * 63 + 28] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 9]);
                        PRIM_INT__h_s_p_s[n * 63 + 28] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 9], PRIM_INT__h_s_p_s[n * 63 + 28]);

                        PRIM_INT__h_s_p_s[n * 63 + 29] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 9]);
                        PRIM_INT__h_s_p_s[n * 63 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 9], PRIM_INT__h_s_p_s[n * 63 + 29]);
                        PRIM_INT__h_s_p_s[n * 63 + 29] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 5], PRIM_INT__h_s_p_s[n * 63 + 29]);

                        PRIM_INT__h_s_p_s[n * 63 + 30] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 10]);
                        PRIM_INT__h_s_p_s[n * 63 + 30] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 10], PRIM_INT__h_s_p_s[n * 63 + 30]);
                        PRIM_INT__h_s_p_s[n * 63 + 30] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 10], PRIM_INT__h_s_p_s[n * 63 + 30]);

                        PRIM_INT__h_s_p_s[n * 63 + 31] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 10]);
                        PRIM_INT__h_s_p_s[n * 63 + 31] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 10], PRIM_INT__h_s_p_s[n * 63 + 31]);
                        PRIM_INT__h_s_p_s[n * 63 + 31] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 6], PRIM_INT__h_s_p_s[n * 63 + 31]);

                        PRIM_INT__h_s_p_s[n * 63 + 32] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 10]);
                        PRIM_INT__h_s_p_s[n * 63 + 32] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 10], PRIM_INT__h_s_p_s[n * 63 + 32]);

                        PRIM_INT__h_s_p_s[n * 63 + 33] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 11]);
                        PRIM_INT__h_s_p_s[n * 63 + 33] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 11], PRIM_INT__h_s_p_s[n * 63 + 33]);
                        PRIM_INT__h_s_p_s[n * 63 + 33] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 11], PRIM_INT__h_s_p_s[n * 63 + 33]);

                        PRIM_INT__h_s_p_s[n * 63 + 34] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 11]);
                        PRIM_INT__h_s_p_s[n * 63 + 34] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 11], PRIM_INT__h_s_p_s[n * 63 + 34]);
                        PRIM_INT__h_s_p_s[n * 63 + 34] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 7], PRIM_INT__h_s_p_s[n * 63 + 34]);

                        PRIM_INT__h_s_p_s[n * 63 + 35] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 11]);
                        PRIM_INT__h_s_p_s[n * 63 + 35] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 11], PRIM_INT__h_s_p_s[n * 63 + 35]);
                        PRIM_INT__h_s_p_s[n * 63 + 35] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 6], PRIM_INT__h_s_p_s[n * 63 + 35]);

                        PRIM_INT__h_s_p_s[n * 63 + 36] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 12]);
                        PRIM_INT__h_s_p_s[n * 63 + 36] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 12], PRIM_INT__h_s_p_s[n * 63 + 36]);
                        PRIM_INT__h_s_p_s[n * 63 + 36] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 12], PRIM_INT__h_s_p_s[n * 63 + 36]);

                        PRIM_INT__h_s_p_s[n * 63 + 37] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 12]);
                        PRIM_INT__h_s_p_s[n * 63 + 37] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 12], PRIM_INT__h_s_p_s[n * 63 + 37]);
                        PRIM_INT__h_s_p_s[n * 63 + 37] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 8], PRIM_INT__h_s_p_s[n * 63 + 37]);

                        PRIM_INT__h_s_p_s[n * 63 + 38] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 12]);
                        PRIM_INT__h_s_p_s[n * 63 + 38] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 12], PRIM_INT__h_s_p_s[n * 63 + 38]);
                        PRIM_INT__h_s_p_s[n * 63 + 38] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 7], PRIM_INT__h_s_p_s[n * 63 + 38]);

                        PRIM_INT__h_s_p_s[n * 63 + 39] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 13]);
                        PRIM_INT__h_s_p_s[n * 63 + 39] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 13], PRIM_INT__h_s_p_s[n * 63 + 39]);
                        PRIM_INT__h_s_p_s[n * 63 + 39] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 13], PRIM_INT__h_s_p_s[n * 63 + 39]);

                        PRIM_INT__h_s_p_s[n * 63 + 40] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 13]);
                        PRIM_INT__h_s_p_s[n * 63 + 40] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 13], PRIM_INT__h_s_p_s[n * 63 + 40]);
                        PRIM_INT__h_s_p_s[n * 63 + 40] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 9], PRIM_INT__h_s_p_s[n * 63 + 40]);

                        PRIM_INT__h_s_p_s[n * 63 + 41] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 13]);
                        PRIM_INT__h_s_p_s[n * 63 + 41] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 13], PRIM_INT__h_s_p_s[n * 63 + 41]);
                        PRIM_INT__h_s_p_s[n * 63 + 41] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 8], PRIM_INT__h_s_p_s[n * 63 + 41]);

                        PRIM_INT__h_s_p_s[n * 63 + 42] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 14]);
                        PRIM_INT__h_s_p_s[n * 63 + 42] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 14], PRIM_INT__h_s_p_s[n * 63 + 42]);
                        PRIM_INT__h_s_p_s[n * 63 + 42] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 14], PRIM_INT__h_s_p_s[n * 63 + 42]);

                        PRIM_INT__h_s_p_s[n * 63 + 43] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 14]);
                        PRIM_INT__h_s_p_s[n * 63 + 43] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 14], PRIM_INT__h_s_p_s[n * 63 + 43]);

                        PRIM_INT__h_s_p_s[n * 63 + 44] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 14]);
                        PRIM_INT__h_s_p_s[n * 63 + 44] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 14], PRIM_INT__h_s_p_s[n * 63 + 44]);
                        PRIM_INT__h_s_p_s[n * 63 + 44] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 9], PRIM_INT__h_s_p_s[n * 63 + 44]);

                        PRIM_INT__h_s_p_s[n * 63 + 45] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 15]);
                        PRIM_INT__h_s_p_s[n * 63 + 45] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 15], PRIM_INT__h_s_p_s[n * 63 + 45]);

                        PRIM_INT__h_s_p_s[n * 63 + 46] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 15]);
                        PRIM_INT__h_s_p_s[n * 63 + 46] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 15], PRIM_INT__h_s_p_s[n * 63 + 46]);
                        PRIM_INT__h_s_p_s[n * 63 + 46] = SIMINT_FMADD( vrr_const_5_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 10], PRIM_INT__h_s_p_s[n * 63 + 46]);

                        PRIM_INT__h_s_p_s[n * 63 + 47] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 15]);
                        PRIM_INT__h_s_p_s[n * 63 + 47] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 15], PRIM_INT__h_s_p_s[n * 63 + 47]);

                        PRIM_INT__h_s_p_s[n * 63 + 48] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 16]);
                        PRIM_INT__h_s_p_s[n * 63 + 48] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 16], PRIM_INT__h_s_p_s[n * 63 + 48]);

                        PRIM_INT__h_s_p_s[n * 63 + 49] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 16]);
                        PRIM_INT__h_s_p_s[n * 63 + 49] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 16], PRIM_INT__h_s_p_s[n * 63 + 49]);
                        PRIM_INT__h_s_p_s[n * 63 + 49] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 11], PRIM_INT__h_s_p_s[n * 63 + 49]);

                        PRIM_INT__h_s_p_s[n * 63 + 50] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 16]);
                        PRIM_INT__h_s_p_s[n * 63 + 50] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 16], PRIM_INT__h_s_p_s[n * 63 + 50]);
                        PRIM_INT__h_s_p_s[n * 63 + 50] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 10], PRIM_INT__h_s_p_s[n * 63 + 50]);

                        PRIM_INT__h_s_p_s[n * 63 + 51] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 17]);
                        PRIM_INT__h_s_p_s[n * 63 + 51] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 17], PRIM_INT__h_s_p_s[n * 63 + 51]);

                        PRIM_INT__h_s_p_s[n * 63 + 52] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 17]);
                        PRIM_INT__h_s_p_s[n * 63 + 52] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 17], PRIM_INT__h_s_p_s[n * 63 + 52]);
                        PRIM_INT__h_s_p_s[n * 63 + 52] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 12], PRIM_INT__h_s_p_s[n * 63 + 52]);

                        PRIM_INT__h_s_p_s[n * 63 + 53] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 17]);
                        PRIM_INT__h_s_p_s[n * 63 + 53] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 17], PRIM_INT__h_s_p_s[n * 63 + 53]);
                        PRIM_INT__h_s_p_s[n * 63 + 53] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 11], PRIM_INT__h_s_p_s[n * 63 + 53]);

                        PRIM_INT__h_s_p_s[n * 63 + 54] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 18]);
                        PRIM_INT__h_s_p_s[n * 63 + 54] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 18], PRIM_INT__h_s_p_s[n * 63 + 54]);

                        PRIM_INT__h_s_p_s[n * 63 + 55] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 18]);
                        PRIM_INT__h_s_p_s[n * 63 + 55] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 18], PRIM_INT__h_s_p_s[n * 63 + 55]);
                        PRIM_INT__h_s_p_s[n * 63 + 55] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 13], PRIM_INT__h_s_p_s[n * 63 + 55]);

                        PRIM_INT__h_s_p_s[n * 63 + 56] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 18]);
                        PRIM_INT__h_s_p_s[n * 63 + 56] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 18], PRIM_INT__h_s_p_s[n * 63 + 56]);
                        PRIM_INT__h_s_p_s[n * 63 + 56] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 12], PRIM_INT__h_s_p_s[n * 63 + 56]);

                        PRIM_INT__h_s_p_s[n * 63 + 57] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 19]);
                        PRIM_INT__h_s_p_s[n * 63 + 57] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 19], PRIM_INT__h_s_p_s[n * 63 + 57]);

                        PRIM_INT__h_s_p_s[n * 63 + 58] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 19]);
                        PRIM_INT__h_s_p_s[n * 63 + 58] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 19], PRIM_INT__h_s_p_s[n * 63 + 58]);
                        PRIM_INT__h_s_p_s[n * 63 + 58] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 14], PRIM_INT__h_s_p_s[n * 63 + 58]);

                        PRIM_INT__h_s_p_s[n * 63 + 59] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 19]);
                        PRIM_INT__h_s_p_s[n * 63 + 59] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 19], PRIM_INT__h_s_p_s[n * 63 + 59]);
                        PRIM_INT__h_s_p_s[n * 63 + 59] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 13], PRIM_INT__h_s_p_s[n * 63 + 59]);

                        PRIM_INT__h_s_p_s[n * 63 + 60] = SIMINT_MUL(Q_PA[0], PRIM_INT__h_s_s_s[n * 21 + 20]);
                        PRIM_INT__h_s_p_s[n * 63 + 60] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__h_s_s_s[(n+1) * 21 + 20], PRIM_INT__h_s_p_s[n * 63 + 60]);

                        PRIM_INT__h_s_p_s[n * 63 + 61] = SIMINT_MUL(Q_PA[1], PRIM_INT__h_s_s_s[n * 21 + 20]);
                        PRIM_INT__h_s_p_s[n * 63 + 61] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__h_s_s_s[(n+1) * 21 + 20], PRIM_INT__h_s_p_s[n * 63 + 61]);

                        PRIM_INT__h_s_p_s[n * 63 + 62] = SIMINT_MUL(Q_PA[2], PRIM_INT__h_s_s_s[n * 21 + 20]);
                        PRIM_INT__h_s_p_s[n * 63 + 62] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__h_s_s_s[(n+1) * 21 + 20], PRIM_INT__h_s_p_s[n * 63 + 62]);
                        PRIM_INT__h_s_p_s[n * 63 + 62] = SIMINT_FMADD( vrr_const_5_over_2pq, PRIM_INT__g_s_s_s[(n+1) * 15 + 14], PRIM_INT__h_s_p_s[n * 63 + 62]);

                    }

}


