
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( g s | d s )
//////////////////////////////////////////////
void VRR_K_g_s_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_p_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n)
{
    int n = 0;
    const SIMINT_DBLTYPE vrr_const_1_over_2q = SIMINT_MUL(SIMINT_DBLSET1(1), one_over_2q);
    const SIMINT_DBLTYPE vrr_const_1_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(1), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(2), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_3_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(3), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_4_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(4), one_over_2pq);

                    // Forming PRIM_INT__g_s_d_s[num_n * 90];
                    for(n = 0; n < num_n; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__g_s_d_s[n * 90 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 0]);
                        PRIM_INT__g_s_d_s[n * 90 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 0], PRIM_INT__g_s_d_s[n * 90 + 0]);
                        PRIM_INT__g_s_d_s[n * 90 + 0] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 0], PRIM_INT__g_s_s_s[n * 15 + 0]), PRIM_INT__g_s_d_s[n * 90 + 0]);
                        PRIM_INT__g_s_d_s[n * 90 + 0] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 0], PRIM_INT__g_s_d_s[n * 90 + 0]);

                        PRIM_INT__g_s_d_s[n * 90 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 0]);
                        PRIM_INT__g_s_d_s[n * 90 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 0], PRIM_INT__g_s_d_s[n * 90 + 1]);

                        PRIM_INT__g_s_d_s[n * 90 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 0]);
                        PRIM_INT__g_s_d_s[n * 90 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 0], PRIM_INT__g_s_d_s[n * 90 + 2]);

                        PRIM_INT__g_s_d_s[n * 90 + 3] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 1]);
                        PRIM_INT__g_s_d_s[n * 90 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 1], PRIM_INT__g_s_d_s[n * 90 + 3]);
                        PRIM_INT__g_s_d_s[n * 90 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 0], PRIM_INT__g_s_s_s[n * 15 + 0]), PRIM_INT__g_s_d_s[n * 90 + 3]);

                        PRIM_INT__g_s_d_s[n * 90 + 4] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 1]);
                        PRIM_INT__g_s_d_s[n * 90 + 4] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 1], PRIM_INT__g_s_d_s[n * 90 + 4]);

                        PRIM_INT__g_s_d_s[n * 90 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 2]);
                        PRIM_INT__g_s_d_s[n * 90 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 2], PRIM_INT__g_s_d_s[n * 90 + 5]);
                        PRIM_INT__g_s_d_s[n * 90 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 0], PRIM_INT__g_s_s_s[n * 15 + 0]), PRIM_INT__g_s_d_s[n * 90 + 5]);

                        PRIM_INT__g_s_d_s[n * 90 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 3]);
                        PRIM_INT__g_s_d_s[n * 90 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 3], PRIM_INT__g_s_d_s[n * 90 + 6]);
                        PRIM_INT__g_s_d_s[n * 90 + 6] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 1], PRIM_INT__g_s_s_s[n * 15 + 1]), PRIM_INT__g_s_d_s[n * 90 + 6]);
                        PRIM_INT__g_s_d_s[n * 90 + 6] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 3], PRIM_INT__g_s_d_s[n * 90 + 6]);

                        PRIM_INT__g_s_d_s[n * 90 + 7] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 3]);
                        PRIM_INT__g_s_d_s[n * 90 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 3], PRIM_INT__g_s_d_s[n * 90 + 7]);
                        PRIM_INT__g_s_d_s[n * 90 + 7] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 0], PRIM_INT__g_s_d_s[n * 90 + 7]);

                        PRIM_INT__g_s_d_s[n * 90 + 8] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 3]);
                        PRIM_INT__g_s_d_s[n * 90 + 8] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 3], PRIM_INT__g_s_d_s[n * 90 + 8]);

                        PRIM_INT__g_s_d_s[n * 90 + 9] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 4]);
                        PRIM_INT__g_s_d_s[n * 90 + 9] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 4], PRIM_INT__g_s_d_s[n * 90 + 9]);
                        PRIM_INT__g_s_d_s[n * 90 + 9] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 1], PRIM_INT__g_s_s_s[n * 15 + 1]), PRIM_INT__g_s_d_s[n * 90 + 9]);
                        PRIM_INT__g_s_d_s[n * 90 + 9] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 1], PRIM_INT__g_s_d_s[n * 90 + 9]);

                        PRIM_INT__g_s_d_s[n * 90 + 10] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 4]);
                        PRIM_INT__g_s_d_s[n * 90 + 10] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 4], PRIM_INT__g_s_d_s[n * 90 + 10]);

                        PRIM_INT__g_s_d_s[n * 90 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 5]);
                        PRIM_INT__g_s_d_s[n * 90 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 5], PRIM_INT__g_s_d_s[n * 90 + 11]);
                        PRIM_INT__g_s_d_s[n * 90 + 11] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 1], PRIM_INT__g_s_s_s[n * 15 + 1]), PRIM_INT__g_s_d_s[n * 90 + 11]);

                        PRIM_INT__g_s_d_s[n * 90 + 12] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 6]);
                        PRIM_INT__g_s_d_s[n * 90 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 6], PRIM_INT__g_s_d_s[n * 90 + 12]);
                        PRIM_INT__g_s_d_s[n * 90 + 12] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 2], PRIM_INT__g_s_s_s[n * 15 + 2]), PRIM_INT__g_s_d_s[n * 90 + 12]);
                        PRIM_INT__g_s_d_s[n * 90 + 12] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 6], PRIM_INT__g_s_d_s[n * 90 + 12]);

                        PRIM_INT__g_s_d_s[n * 90 + 13] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 6]);
                        PRIM_INT__g_s_d_s[n * 90 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 6], PRIM_INT__g_s_d_s[n * 90 + 13]);

                        PRIM_INT__g_s_d_s[n * 90 + 14] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 6]);
                        PRIM_INT__g_s_d_s[n * 90 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 6], PRIM_INT__g_s_d_s[n * 90 + 14]);
                        PRIM_INT__g_s_d_s[n * 90 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 0], PRIM_INT__g_s_d_s[n * 90 + 14]);

                        PRIM_INT__g_s_d_s[n * 90 + 15] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 7]);
                        PRIM_INT__g_s_d_s[n * 90 + 15] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 7], PRIM_INT__g_s_d_s[n * 90 + 15]);
                        PRIM_INT__g_s_d_s[n * 90 + 15] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 2], PRIM_INT__g_s_s_s[n * 15 + 2]), PRIM_INT__g_s_d_s[n * 90 + 15]);

                        PRIM_INT__g_s_d_s[n * 90 + 16] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 7]);
                        PRIM_INT__g_s_d_s[n * 90 + 16] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 7], PRIM_INT__g_s_d_s[n * 90 + 16]);
                        PRIM_INT__g_s_d_s[n * 90 + 16] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 1], PRIM_INT__g_s_d_s[n * 90 + 16]);

                        PRIM_INT__g_s_d_s[n * 90 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 8]);
                        PRIM_INT__g_s_d_s[n * 90 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 8], PRIM_INT__g_s_d_s[n * 90 + 17]);
                        PRIM_INT__g_s_d_s[n * 90 + 17] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 2], PRIM_INT__g_s_s_s[n * 15 + 2]), PRIM_INT__g_s_d_s[n * 90 + 17]);
                        PRIM_INT__g_s_d_s[n * 90 + 17] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 2], PRIM_INT__g_s_d_s[n * 90 + 17]);

                        PRIM_INT__g_s_d_s[n * 90 + 18] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 9]);
                        PRIM_INT__g_s_d_s[n * 90 + 18] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 9], PRIM_INT__g_s_d_s[n * 90 + 18]);
                        PRIM_INT__g_s_d_s[n * 90 + 18] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 3], PRIM_INT__g_s_s_s[n * 15 + 3]), PRIM_INT__g_s_d_s[n * 90 + 18]);
                        PRIM_INT__g_s_d_s[n * 90 + 18] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 9], PRIM_INT__g_s_d_s[n * 90 + 18]);

                        PRIM_INT__g_s_d_s[n * 90 + 19] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 9]);
                        PRIM_INT__g_s_d_s[n * 90 + 19] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 9], PRIM_INT__g_s_d_s[n * 90 + 19]);
                        PRIM_INT__g_s_d_s[n * 90 + 19] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 3], PRIM_INT__g_s_d_s[n * 90 + 19]);

                        PRIM_INT__g_s_d_s[n * 90 + 20] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 9]);
                        PRIM_INT__g_s_d_s[n * 90 + 20] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 9], PRIM_INT__g_s_d_s[n * 90 + 20]);

                        PRIM_INT__g_s_d_s[n * 90 + 21] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 10]);
                        PRIM_INT__g_s_d_s[n * 90 + 21] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 10], PRIM_INT__g_s_d_s[n * 90 + 21]);
                        PRIM_INT__g_s_d_s[n * 90 + 21] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 3], PRIM_INT__g_s_s_s[n * 15 + 3]), PRIM_INT__g_s_d_s[n * 90 + 21]);
                        PRIM_INT__g_s_d_s[n * 90 + 21] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 4], PRIM_INT__g_s_d_s[n * 90 + 21]);

                        PRIM_INT__g_s_d_s[n * 90 + 22] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 10]);
                        PRIM_INT__g_s_d_s[n * 90 + 22] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 10], PRIM_INT__g_s_d_s[n * 90 + 22]);

                        PRIM_INT__g_s_d_s[n * 90 + 23] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 11]);
                        PRIM_INT__g_s_d_s[n * 90 + 23] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 11], PRIM_INT__g_s_d_s[n * 90 + 23]);
                        PRIM_INT__g_s_d_s[n * 90 + 23] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 3], PRIM_INT__g_s_s_s[n * 15 + 3]), PRIM_INT__g_s_d_s[n * 90 + 23]);

                        PRIM_INT__g_s_d_s[n * 90 + 24] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 12]);
                        PRIM_INT__g_s_d_s[n * 90 + 24] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 12], PRIM_INT__g_s_d_s[n * 90 + 24]);
                        PRIM_INT__g_s_d_s[n * 90 + 24] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 4], PRIM_INT__g_s_s_s[n * 15 + 4]), PRIM_INT__g_s_d_s[n * 90 + 24]);
                        PRIM_INT__g_s_d_s[n * 90 + 24] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 12], PRIM_INT__g_s_d_s[n * 90 + 24]);

                        PRIM_INT__g_s_d_s[n * 90 + 25] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 12]);
                        PRIM_INT__g_s_d_s[n * 90 + 25] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 12], PRIM_INT__g_s_d_s[n * 90 + 25]);
                        PRIM_INT__g_s_d_s[n * 90 + 25] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 6], PRIM_INT__g_s_d_s[n * 90 + 25]);

                        PRIM_INT__g_s_d_s[n * 90 + 26] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 12]);
                        PRIM_INT__g_s_d_s[n * 90 + 26] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 12], PRIM_INT__g_s_d_s[n * 90 + 26]);
                        PRIM_INT__g_s_d_s[n * 90 + 26] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 3], PRIM_INT__g_s_d_s[n * 90 + 26]);

                        PRIM_INT__g_s_d_s[n * 90 + 27] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 13]);
                        PRIM_INT__g_s_d_s[n * 90 + 27] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 13], PRIM_INT__g_s_d_s[n * 90 + 27]);
                        PRIM_INT__g_s_d_s[n * 90 + 27] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 4], PRIM_INT__g_s_s_s[n * 15 + 4]), PRIM_INT__g_s_d_s[n * 90 + 27]);
                        PRIM_INT__g_s_d_s[n * 90 + 27] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 7], PRIM_INT__g_s_d_s[n * 90 + 27]);

                        PRIM_INT__g_s_d_s[n * 90 + 28] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 13]);
                        PRIM_INT__g_s_d_s[n * 90 + 28] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 13], PRIM_INT__g_s_d_s[n * 90 + 28]);
                        PRIM_INT__g_s_d_s[n * 90 + 28] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 4], PRIM_INT__g_s_d_s[n * 90 + 28]);

                        PRIM_INT__g_s_d_s[n * 90 + 29] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 14]);
                        PRIM_INT__g_s_d_s[n * 90 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 14], PRIM_INT__g_s_d_s[n * 90 + 29]);
                        PRIM_INT__g_s_d_s[n * 90 + 29] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 4], PRIM_INT__g_s_s_s[n * 15 + 4]), PRIM_INT__g_s_d_s[n * 90 + 29]);
                        PRIM_INT__g_s_d_s[n * 90 + 29] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 5], PRIM_INT__g_s_d_s[n * 90 + 29]);

                        PRIM_INT__g_s_d_s[n * 90 + 30] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 15]);
                        PRIM_INT__g_s_d_s[n * 90 + 30] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 15], PRIM_INT__g_s_d_s[n * 90 + 30]);
                        PRIM_INT__g_s_d_s[n * 90 + 30] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 5], PRIM_INT__g_s_s_s[n * 15 + 5]), PRIM_INT__g_s_d_s[n * 90 + 30]);
                        PRIM_INT__g_s_d_s[n * 90 + 30] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 15], PRIM_INT__g_s_d_s[n * 90 + 30]);

                        PRIM_INT__g_s_d_s[n * 90 + 31] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 15]);
                        PRIM_INT__g_s_d_s[n * 90 + 31] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 15], PRIM_INT__g_s_d_s[n * 90 + 31]);

                        PRIM_INT__g_s_d_s[n * 90 + 32] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 15]);
                        PRIM_INT__g_s_d_s[n * 90 + 32] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 15], PRIM_INT__g_s_d_s[n * 90 + 32]);
                        PRIM_INT__g_s_d_s[n * 90 + 32] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 6], PRIM_INT__g_s_d_s[n * 90 + 32]);

                        PRIM_INT__g_s_d_s[n * 90 + 33] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 16]);
                        PRIM_INT__g_s_d_s[n * 90 + 33] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 16], PRIM_INT__g_s_d_s[n * 90 + 33]);
                        PRIM_INT__g_s_d_s[n * 90 + 33] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 5], PRIM_INT__g_s_s_s[n * 15 + 5]), PRIM_INT__g_s_d_s[n * 90 + 33]);

                        PRIM_INT__g_s_d_s[n * 90 + 34] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 16]);
                        PRIM_INT__g_s_d_s[n * 90 + 34] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 16], PRIM_INT__g_s_d_s[n * 90 + 34]);
                        PRIM_INT__g_s_d_s[n * 90 + 34] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 7], PRIM_INT__g_s_d_s[n * 90 + 34]);

                        PRIM_INT__g_s_d_s[n * 90 + 35] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 17]);
                        PRIM_INT__g_s_d_s[n * 90 + 35] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 17], PRIM_INT__g_s_d_s[n * 90 + 35]);
                        PRIM_INT__g_s_d_s[n * 90 + 35] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 5], PRIM_INT__g_s_s_s[n * 15 + 5]), PRIM_INT__g_s_d_s[n * 90 + 35]);
                        PRIM_INT__g_s_d_s[n * 90 + 35] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 8], PRIM_INT__g_s_d_s[n * 90 + 35]);

                        PRIM_INT__g_s_d_s[n * 90 + 36] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 18]);
                        PRIM_INT__g_s_d_s[n * 90 + 36] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 18], PRIM_INT__g_s_d_s[n * 90 + 36]);
                        PRIM_INT__g_s_d_s[n * 90 + 36] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 6], PRIM_INT__g_s_s_s[n * 15 + 6]), PRIM_INT__g_s_d_s[n * 90 + 36]);
                        PRIM_INT__g_s_d_s[n * 90 + 36] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 18], PRIM_INT__g_s_d_s[n * 90 + 36]);

                        PRIM_INT__g_s_d_s[n * 90 + 37] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 18]);
                        PRIM_INT__g_s_d_s[n * 90 + 37] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 18], PRIM_INT__g_s_d_s[n * 90 + 37]);
                        PRIM_INT__g_s_d_s[n * 90 + 37] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 9], PRIM_INT__g_s_d_s[n * 90 + 37]);

                        PRIM_INT__g_s_d_s[n * 90 + 38] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 18]);
                        PRIM_INT__g_s_d_s[n * 90 + 38] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 18], PRIM_INT__g_s_d_s[n * 90 + 38]);

                        PRIM_INT__g_s_d_s[n * 90 + 39] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 19]);
                        PRIM_INT__g_s_d_s[n * 90 + 39] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 19], PRIM_INT__g_s_d_s[n * 90 + 39]);
                        PRIM_INT__g_s_d_s[n * 90 + 39] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 6], PRIM_INT__g_s_s_s[n * 15 + 6]), PRIM_INT__g_s_d_s[n * 90 + 39]);
                        PRIM_INT__g_s_d_s[n * 90 + 39] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 10], PRIM_INT__g_s_d_s[n * 90 + 39]);

                        PRIM_INT__g_s_d_s[n * 90 + 40] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 19]);
                        PRIM_INT__g_s_d_s[n * 90 + 40] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 19], PRIM_INT__g_s_d_s[n * 90 + 40]);

                        PRIM_INT__g_s_d_s[n * 90 + 41] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 20]);
                        PRIM_INT__g_s_d_s[n * 90 + 41] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 20], PRIM_INT__g_s_d_s[n * 90 + 41]);
                        PRIM_INT__g_s_d_s[n * 90 + 41] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 6], PRIM_INT__g_s_s_s[n * 15 + 6]), PRIM_INT__g_s_d_s[n * 90 + 41]);

                        PRIM_INT__g_s_d_s[n * 90 + 42] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 21]);
                        PRIM_INT__g_s_d_s[n * 90 + 42] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 21], PRIM_INT__g_s_d_s[n * 90 + 42]);
                        PRIM_INT__g_s_d_s[n * 90 + 42] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 7], PRIM_INT__g_s_s_s[n * 15 + 7]), PRIM_INT__g_s_d_s[n * 90 + 42]);
                        PRIM_INT__g_s_d_s[n * 90 + 42] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 21], PRIM_INT__g_s_d_s[n * 90 + 42]);

                        PRIM_INT__g_s_d_s[n * 90 + 43] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 21]);
                        PRIM_INT__g_s_d_s[n * 90 + 43] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 21], PRIM_INT__g_s_d_s[n * 90 + 43]);
                        PRIM_INT__g_s_d_s[n * 90 + 43] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 12], PRIM_INT__g_s_d_s[n * 90 + 43]);

                        PRIM_INT__g_s_d_s[n * 90 + 44] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 21]);
                        PRIM_INT__g_s_d_s[n * 90 + 44] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 21], PRIM_INT__g_s_d_s[n * 90 + 44]);
                        PRIM_INT__g_s_d_s[n * 90 + 44] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 9], PRIM_INT__g_s_d_s[n * 90 + 44]);

                        PRIM_INT__g_s_d_s[n * 90 + 45] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 22]);
                        PRIM_INT__g_s_d_s[n * 90 + 45] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 22], PRIM_INT__g_s_d_s[n * 90 + 45]);
                        PRIM_INT__g_s_d_s[n * 90 + 45] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 7], PRIM_INT__g_s_s_s[n * 15 + 7]), PRIM_INT__g_s_d_s[n * 90 + 45]);
                        PRIM_INT__g_s_d_s[n * 90 + 45] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 13], PRIM_INT__g_s_d_s[n * 90 + 45]);

                        PRIM_INT__g_s_d_s[n * 90 + 46] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 22]);
                        PRIM_INT__g_s_d_s[n * 90 + 46] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 22], PRIM_INT__g_s_d_s[n * 90 + 46]);
                        PRIM_INT__g_s_d_s[n * 90 + 46] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 10], PRIM_INT__g_s_d_s[n * 90 + 46]);

                        PRIM_INT__g_s_d_s[n * 90 + 47] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 23]);
                        PRIM_INT__g_s_d_s[n * 90 + 47] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 23], PRIM_INT__g_s_d_s[n * 90 + 47]);
                        PRIM_INT__g_s_d_s[n * 90 + 47] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 7], PRIM_INT__g_s_s_s[n * 15 + 7]), PRIM_INT__g_s_d_s[n * 90 + 47]);
                        PRIM_INT__g_s_d_s[n * 90 + 47] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 11], PRIM_INT__g_s_d_s[n * 90 + 47]);

                        PRIM_INT__g_s_d_s[n * 90 + 48] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 24]);
                        PRIM_INT__g_s_d_s[n * 90 + 48] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 24], PRIM_INT__g_s_d_s[n * 90 + 48]);
                        PRIM_INT__g_s_d_s[n * 90 + 48] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 8], PRIM_INT__g_s_s_s[n * 15 + 8]), PRIM_INT__g_s_d_s[n * 90 + 48]);
                        PRIM_INT__g_s_d_s[n * 90 + 48] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 24], PRIM_INT__g_s_d_s[n * 90 + 48]);

                        PRIM_INT__g_s_d_s[n * 90 + 49] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 24]);
                        PRIM_INT__g_s_d_s[n * 90 + 49] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 24], PRIM_INT__g_s_d_s[n * 90 + 49]);
                        PRIM_INT__g_s_d_s[n * 90 + 49] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 15], PRIM_INT__g_s_d_s[n * 90 + 49]);

                        PRIM_INT__g_s_d_s[n * 90 + 50] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 24]);
                        PRIM_INT__g_s_d_s[n * 90 + 50] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 24], PRIM_INT__g_s_d_s[n * 90 + 50]);
                        PRIM_INT__g_s_d_s[n * 90 + 50] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 12], PRIM_INT__g_s_d_s[n * 90 + 50]);

                        PRIM_INT__g_s_d_s[n * 90 + 51] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 25]);
                        PRIM_INT__g_s_d_s[n * 90 + 51] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 25], PRIM_INT__g_s_d_s[n * 90 + 51]);
                        PRIM_INT__g_s_d_s[n * 90 + 51] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 8], PRIM_INT__g_s_s_s[n * 15 + 8]), PRIM_INT__g_s_d_s[n * 90 + 51]);
                        PRIM_INT__g_s_d_s[n * 90 + 51] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 16], PRIM_INT__g_s_d_s[n * 90 + 51]);

                        PRIM_INT__g_s_d_s[n * 90 + 52] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 25]);
                        PRIM_INT__g_s_d_s[n * 90 + 52] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 25], PRIM_INT__g_s_d_s[n * 90 + 52]);
                        PRIM_INT__g_s_d_s[n * 90 + 52] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 13], PRIM_INT__g_s_d_s[n * 90 + 52]);

                        PRIM_INT__g_s_d_s[n * 90 + 53] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 26]);
                        PRIM_INT__g_s_d_s[n * 90 + 53] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 26], PRIM_INT__g_s_d_s[n * 90 + 53]);
                        PRIM_INT__g_s_d_s[n * 90 + 53] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 8], PRIM_INT__g_s_s_s[n * 15 + 8]), PRIM_INT__g_s_d_s[n * 90 + 53]);
                        PRIM_INT__g_s_d_s[n * 90 + 53] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 14], PRIM_INT__g_s_d_s[n * 90 + 53]);

                        PRIM_INT__g_s_d_s[n * 90 + 54] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 27]);
                        PRIM_INT__g_s_d_s[n * 90 + 54] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 27], PRIM_INT__g_s_d_s[n * 90 + 54]);
                        PRIM_INT__g_s_d_s[n * 90 + 54] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 9], PRIM_INT__g_s_s_s[n * 15 + 9]), PRIM_INT__g_s_d_s[n * 90 + 54]);
                        PRIM_INT__g_s_d_s[n * 90 + 54] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 27], PRIM_INT__g_s_d_s[n * 90 + 54]);

                        PRIM_INT__g_s_d_s[n * 90 + 55] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 27]);
                        PRIM_INT__g_s_d_s[n * 90 + 55] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 27], PRIM_INT__g_s_d_s[n * 90 + 55]);

                        PRIM_INT__g_s_d_s[n * 90 + 56] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 27]);
                        PRIM_INT__g_s_d_s[n * 90 + 56] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 27], PRIM_INT__g_s_d_s[n * 90 + 56]);
                        PRIM_INT__g_s_d_s[n * 90 + 56] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 15], PRIM_INT__g_s_d_s[n * 90 + 56]);

                        PRIM_INT__g_s_d_s[n * 90 + 57] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 28]);
                        PRIM_INT__g_s_d_s[n * 90 + 57] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 28], PRIM_INT__g_s_d_s[n * 90 + 57]);
                        PRIM_INT__g_s_d_s[n * 90 + 57] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 9], PRIM_INT__g_s_s_s[n * 15 + 9]), PRIM_INT__g_s_d_s[n * 90 + 57]);

                        PRIM_INT__g_s_d_s[n * 90 + 58] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 28]);
                        PRIM_INT__g_s_d_s[n * 90 + 58] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 28], PRIM_INT__g_s_d_s[n * 90 + 58]);
                        PRIM_INT__g_s_d_s[n * 90 + 58] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 16], PRIM_INT__g_s_d_s[n * 90 + 58]);

                        PRIM_INT__g_s_d_s[n * 90 + 59] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 29]);
                        PRIM_INT__g_s_d_s[n * 90 + 59] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 29], PRIM_INT__g_s_d_s[n * 90 + 59]);
                        PRIM_INT__g_s_d_s[n * 90 + 59] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 9], PRIM_INT__g_s_s_s[n * 15 + 9]), PRIM_INT__g_s_d_s[n * 90 + 59]);
                        PRIM_INT__g_s_d_s[n * 90 + 59] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 17], PRIM_INT__g_s_d_s[n * 90 + 59]);

                        PRIM_INT__g_s_d_s[n * 90 + 60] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 30]);
                        PRIM_INT__g_s_d_s[n * 90 + 60] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 30], PRIM_INT__g_s_d_s[n * 90 + 60]);
                        PRIM_INT__g_s_d_s[n * 90 + 60] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 10], PRIM_INT__g_s_s_s[n * 15 + 10]), PRIM_INT__g_s_d_s[n * 90 + 60]);

                        PRIM_INT__g_s_d_s[n * 90 + 61] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 30]);
                        PRIM_INT__g_s_d_s[n * 90 + 61] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 30], PRIM_INT__g_s_d_s[n * 90 + 61]);
                        PRIM_INT__g_s_d_s[n * 90 + 61] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 18], PRIM_INT__g_s_d_s[n * 90 + 61]);

                        PRIM_INT__g_s_d_s[n * 90 + 62] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 30]);
                        PRIM_INT__g_s_d_s[n * 90 + 62] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 30], PRIM_INT__g_s_d_s[n * 90 + 62]);

                        PRIM_INT__g_s_d_s[n * 90 + 63] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 31]);
                        PRIM_INT__g_s_d_s[n * 90 + 63] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 31], PRIM_INT__g_s_d_s[n * 90 + 63]);
                        PRIM_INT__g_s_d_s[n * 90 + 63] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 10], PRIM_INT__g_s_s_s[n * 15 + 10]), PRIM_INT__g_s_d_s[n * 90 + 63]);
                        PRIM_INT__g_s_d_s[n * 90 + 63] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 19], PRIM_INT__g_s_d_s[n * 90 + 63]);

                        PRIM_INT__g_s_d_s[n * 90 + 64] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 31]);
                        PRIM_INT__g_s_d_s[n * 90 + 64] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 31], PRIM_INT__g_s_d_s[n * 90 + 64]);

                        PRIM_INT__g_s_d_s[n * 90 + 65] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 32]);
                        PRIM_INT__g_s_d_s[n * 90 + 65] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 32], PRIM_INT__g_s_d_s[n * 90 + 65]);
                        PRIM_INT__g_s_d_s[n * 90 + 65] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 10], PRIM_INT__g_s_s_s[n * 15 + 10]), PRIM_INT__g_s_d_s[n * 90 + 65]);

                        PRIM_INT__g_s_d_s[n * 90 + 66] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 33]);
                        PRIM_INT__g_s_d_s[n * 90 + 66] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 33], PRIM_INT__g_s_d_s[n * 90 + 66]);
                        PRIM_INT__g_s_d_s[n * 90 + 66] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 11], PRIM_INT__g_s_s_s[n * 15 + 11]), PRIM_INT__g_s_d_s[n * 90 + 66]);

                        PRIM_INT__g_s_d_s[n * 90 + 67] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 33]);
                        PRIM_INT__g_s_d_s[n * 90 + 67] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 33], PRIM_INT__g_s_d_s[n * 90 + 67]);
                        PRIM_INT__g_s_d_s[n * 90 + 67] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 21], PRIM_INT__g_s_d_s[n * 90 + 67]);

                        PRIM_INT__g_s_d_s[n * 90 + 68] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 33]);
                        PRIM_INT__g_s_d_s[n * 90 + 68] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 33], PRIM_INT__g_s_d_s[n * 90 + 68]);
                        PRIM_INT__g_s_d_s[n * 90 + 68] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 18], PRIM_INT__g_s_d_s[n * 90 + 68]);

                        PRIM_INT__g_s_d_s[n * 90 + 69] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 34]);
                        PRIM_INT__g_s_d_s[n * 90 + 69] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 34], PRIM_INT__g_s_d_s[n * 90 + 69]);
                        PRIM_INT__g_s_d_s[n * 90 + 69] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 11], PRIM_INT__g_s_s_s[n * 15 + 11]), PRIM_INT__g_s_d_s[n * 90 + 69]);
                        PRIM_INT__g_s_d_s[n * 90 + 69] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 22], PRIM_INT__g_s_d_s[n * 90 + 69]);

                        PRIM_INT__g_s_d_s[n * 90 + 70] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 34]);
                        PRIM_INT__g_s_d_s[n * 90 + 70] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 34], PRIM_INT__g_s_d_s[n * 90 + 70]);
                        PRIM_INT__g_s_d_s[n * 90 + 70] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 19], PRIM_INT__g_s_d_s[n * 90 + 70]);

                        PRIM_INT__g_s_d_s[n * 90 + 71] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 35]);
                        PRIM_INT__g_s_d_s[n * 90 + 71] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 35], PRIM_INT__g_s_d_s[n * 90 + 71]);
                        PRIM_INT__g_s_d_s[n * 90 + 71] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 11], PRIM_INT__g_s_s_s[n * 15 + 11]), PRIM_INT__g_s_d_s[n * 90 + 71]);
                        PRIM_INT__g_s_d_s[n * 90 + 71] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 20], PRIM_INT__g_s_d_s[n * 90 + 71]);

                        PRIM_INT__g_s_d_s[n * 90 + 72] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 36]);
                        PRIM_INT__g_s_d_s[n * 90 + 72] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 36], PRIM_INT__g_s_d_s[n * 90 + 72]);
                        PRIM_INT__g_s_d_s[n * 90 + 72] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 12], PRIM_INT__g_s_s_s[n * 15 + 12]), PRIM_INT__g_s_d_s[n * 90 + 72]);

                        PRIM_INT__g_s_d_s[n * 90 + 73] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 36]);
                        PRIM_INT__g_s_d_s[n * 90 + 73] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 36], PRIM_INT__g_s_d_s[n * 90 + 73]);
                        PRIM_INT__g_s_d_s[n * 90 + 73] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 24], PRIM_INT__g_s_d_s[n * 90 + 73]);

                        PRIM_INT__g_s_d_s[n * 90 + 74] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 36]);
                        PRIM_INT__g_s_d_s[n * 90 + 74] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 36], PRIM_INT__g_s_d_s[n * 90 + 74]);
                        PRIM_INT__g_s_d_s[n * 90 + 74] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 21], PRIM_INT__g_s_d_s[n * 90 + 74]);

                        PRIM_INT__g_s_d_s[n * 90 + 75] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 37]);
                        PRIM_INT__g_s_d_s[n * 90 + 75] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 37], PRIM_INT__g_s_d_s[n * 90 + 75]);
                        PRIM_INT__g_s_d_s[n * 90 + 75] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 12], PRIM_INT__g_s_s_s[n * 15 + 12]), PRIM_INT__g_s_d_s[n * 90 + 75]);
                        PRIM_INT__g_s_d_s[n * 90 + 75] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 25], PRIM_INT__g_s_d_s[n * 90 + 75]);

                        PRIM_INT__g_s_d_s[n * 90 + 76] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 37]);
                        PRIM_INT__g_s_d_s[n * 90 + 76] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 37], PRIM_INT__g_s_d_s[n * 90 + 76]);
                        PRIM_INT__g_s_d_s[n * 90 + 76] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 22], PRIM_INT__g_s_d_s[n * 90 + 76]);

                        PRIM_INT__g_s_d_s[n * 90 + 77] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 38]);
                        PRIM_INT__g_s_d_s[n * 90 + 77] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 38], PRIM_INT__g_s_d_s[n * 90 + 77]);
                        PRIM_INT__g_s_d_s[n * 90 + 77] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 12], PRIM_INT__g_s_s_s[n * 15 + 12]), PRIM_INT__g_s_d_s[n * 90 + 77]);
                        PRIM_INT__g_s_d_s[n * 90 + 77] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 23], PRIM_INT__g_s_d_s[n * 90 + 77]);

                        PRIM_INT__g_s_d_s[n * 90 + 78] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 39]);
                        PRIM_INT__g_s_d_s[n * 90 + 78] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 39], PRIM_INT__g_s_d_s[n * 90 + 78]);
                        PRIM_INT__g_s_d_s[n * 90 + 78] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 13], PRIM_INT__g_s_s_s[n * 15 + 13]), PRIM_INT__g_s_d_s[n * 90 + 78]);

                        PRIM_INT__g_s_d_s[n * 90 + 79] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 39]);
                        PRIM_INT__g_s_d_s[n * 90 + 79] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 39], PRIM_INT__g_s_d_s[n * 90 + 79]);
                        PRIM_INT__g_s_d_s[n * 90 + 79] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 27], PRIM_INT__g_s_d_s[n * 90 + 79]);

                        PRIM_INT__g_s_d_s[n * 90 + 80] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 39]);
                        PRIM_INT__g_s_d_s[n * 90 + 80] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 39], PRIM_INT__g_s_d_s[n * 90 + 80]);
                        PRIM_INT__g_s_d_s[n * 90 + 80] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 24], PRIM_INT__g_s_d_s[n * 90 + 80]);

                        PRIM_INT__g_s_d_s[n * 90 + 81] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 40]);
                        PRIM_INT__g_s_d_s[n * 90 + 81] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 40], PRIM_INT__g_s_d_s[n * 90 + 81]);
                        PRIM_INT__g_s_d_s[n * 90 + 81] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 13], PRIM_INT__g_s_s_s[n * 15 + 13]), PRIM_INT__g_s_d_s[n * 90 + 81]);
                        PRIM_INT__g_s_d_s[n * 90 + 81] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 28], PRIM_INT__g_s_d_s[n * 90 + 81]);

                        PRIM_INT__g_s_d_s[n * 90 + 82] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 40]);
                        PRIM_INT__g_s_d_s[n * 90 + 82] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 40], PRIM_INT__g_s_d_s[n * 90 + 82]);
                        PRIM_INT__g_s_d_s[n * 90 + 82] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 25], PRIM_INT__g_s_d_s[n * 90 + 82]);

                        PRIM_INT__g_s_d_s[n * 90 + 83] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 41]);
                        PRIM_INT__g_s_d_s[n * 90 + 83] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 41], PRIM_INT__g_s_d_s[n * 90 + 83]);
                        PRIM_INT__g_s_d_s[n * 90 + 83] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 13], PRIM_INT__g_s_s_s[n * 15 + 13]), PRIM_INT__g_s_d_s[n * 90 + 83]);
                        PRIM_INT__g_s_d_s[n * 90 + 83] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 26], PRIM_INT__g_s_d_s[n * 90 + 83]);

                        PRIM_INT__g_s_d_s[n * 90 + 84] = SIMINT_MUL(Q_PA[0], PRIM_INT__g_s_p_s[n * 45 + 42]);
                        PRIM_INT__g_s_d_s[n * 90 + 84] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__g_s_p_s[(n+1) * 45 + 42], PRIM_INT__g_s_d_s[n * 90 + 84]);
                        PRIM_INT__g_s_d_s[n * 90 + 84] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 14], PRIM_INT__g_s_s_s[n * 15 + 14]), PRIM_INT__g_s_d_s[n * 90 + 84]);

                        PRIM_INT__g_s_d_s[n * 90 + 85] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 42]);
                        PRIM_INT__g_s_d_s[n * 90 + 85] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 42], PRIM_INT__g_s_d_s[n * 90 + 85]);

                        PRIM_INT__g_s_d_s[n * 90 + 86] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 42]);
                        PRIM_INT__g_s_d_s[n * 90 + 86] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 42], PRIM_INT__g_s_d_s[n * 90 + 86]);
                        PRIM_INT__g_s_d_s[n * 90 + 86] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 27], PRIM_INT__g_s_d_s[n * 90 + 86]);

                        PRIM_INT__g_s_d_s[n * 90 + 87] = SIMINT_MUL(Q_PA[1], PRIM_INT__g_s_p_s[n * 45 + 43]);
                        PRIM_INT__g_s_d_s[n * 90 + 87] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__g_s_p_s[(n+1) * 45 + 43], PRIM_INT__g_s_d_s[n * 90 + 87]);
                        PRIM_INT__g_s_d_s[n * 90 + 87] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 14], PRIM_INT__g_s_s_s[n * 15 + 14]), PRIM_INT__g_s_d_s[n * 90 + 87]);

                        PRIM_INT__g_s_d_s[n * 90 + 88] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 43]);
                        PRIM_INT__g_s_d_s[n * 90 + 88] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 43], PRIM_INT__g_s_d_s[n * 90 + 88]);
                        PRIM_INT__g_s_d_s[n * 90 + 88] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 28], PRIM_INT__g_s_d_s[n * 90 + 88]);

                        PRIM_INT__g_s_d_s[n * 90 + 89] = SIMINT_MUL(Q_PA[2], PRIM_INT__g_s_p_s[n * 45 + 44]);
                        PRIM_INT__g_s_d_s[n * 90 + 89] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__g_s_p_s[(n+1) * 45 + 44], PRIM_INT__g_s_d_s[n * 90 + 89]);
                        PRIM_INT__g_s_d_s[n * 90 + 89] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__g_s_s_s[(n+1) * 15 + 14], PRIM_INT__g_s_s_s[n * 15 + 14]), PRIM_INT__g_s_d_s[n * 90 + 89]);
                        PRIM_INT__g_s_d_s[n * 90 + 89] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__f_s_p_s[(n+1) * 30 + 29], PRIM_INT__g_s_d_s[n * 90 + 89]);

                    }

}


