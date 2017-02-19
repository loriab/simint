
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( i s | p s )
//////////////////////////////////////////////
void VRR_K_i_s_p_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s,
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
    const SIMINT_DBLTYPE vrr_const_6_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(6), one_over_2pq);

                    // Forming PRIM_INT__i_s_p_s[num_n * 84];
                    for(n = 0; n < num_n; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__i_s_p_s[n * 84 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 0]);
                        PRIM_INT__i_s_p_s[n * 84 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 0], PRIM_INT__i_s_p_s[n * 84 + 0]);
                        PRIM_INT__i_s_p_s[n * 84 + 0] = SIMINT_FMADD( vrr_const_6_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 0], PRIM_INT__i_s_p_s[n * 84 + 0]);

                        PRIM_INT__i_s_p_s[n * 84 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 0]);
                        PRIM_INT__i_s_p_s[n * 84 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 0], PRIM_INT__i_s_p_s[n * 84 + 1]);

                        PRIM_INT__i_s_p_s[n * 84 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 0]);
                        PRIM_INT__i_s_p_s[n * 84 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 0], PRIM_INT__i_s_p_s[n * 84 + 2]);

                        PRIM_INT__i_s_p_s[n * 84 + 3] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 1]);
                        PRIM_INT__i_s_p_s[n * 84 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 1], PRIM_INT__i_s_p_s[n * 84 + 3]);
                        PRIM_INT__i_s_p_s[n * 84 + 3] = SIMINT_FMADD( vrr_const_5_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 1], PRIM_INT__i_s_p_s[n * 84 + 3]);

                        PRIM_INT__i_s_p_s[n * 84 + 4] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 1]);
                        PRIM_INT__i_s_p_s[n * 84 + 4] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 1], PRIM_INT__i_s_p_s[n * 84 + 4]);
                        PRIM_INT__i_s_p_s[n * 84 + 4] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 0], PRIM_INT__i_s_p_s[n * 84 + 4]);

                        PRIM_INT__i_s_p_s[n * 84 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 1]);
                        PRIM_INT__i_s_p_s[n * 84 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 1], PRIM_INT__i_s_p_s[n * 84 + 5]);

                        PRIM_INT__i_s_p_s[n * 84 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 2]);
                        PRIM_INT__i_s_p_s[n * 84 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 2], PRIM_INT__i_s_p_s[n * 84 + 6]);
                        PRIM_INT__i_s_p_s[n * 84 + 6] = SIMINT_FMADD( vrr_const_5_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 2], PRIM_INT__i_s_p_s[n * 84 + 6]);

                        PRIM_INT__i_s_p_s[n * 84 + 7] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 2]);
                        PRIM_INT__i_s_p_s[n * 84 + 7] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 2], PRIM_INT__i_s_p_s[n * 84 + 7]);

                        PRIM_INT__i_s_p_s[n * 84 + 8] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 2]);
                        PRIM_INT__i_s_p_s[n * 84 + 8] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 2], PRIM_INT__i_s_p_s[n * 84 + 8]);
                        PRIM_INT__i_s_p_s[n * 84 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 0], PRIM_INT__i_s_p_s[n * 84 + 8]);

                        PRIM_INT__i_s_p_s[n * 84 + 9] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 3]);
                        PRIM_INT__i_s_p_s[n * 84 + 9] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 3], PRIM_INT__i_s_p_s[n * 84 + 9]);
                        PRIM_INT__i_s_p_s[n * 84 + 9] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 3], PRIM_INT__i_s_p_s[n * 84 + 9]);

                        PRIM_INT__i_s_p_s[n * 84 + 10] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 3]);
                        PRIM_INT__i_s_p_s[n * 84 + 10] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 3], PRIM_INT__i_s_p_s[n * 84 + 10]);
                        PRIM_INT__i_s_p_s[n * 84 + 10] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 1], PRIM_INT__i_s_p_s[n * 84 + 10]);

                        PRIM_INT__i_s_p_s[n * 84 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 3]);
                        PRIM_INT__i_s_p_s[n * 84 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 3], PRIM_INT__i_s_p_s[n * 84 + 11]);

                        PRIM_INT__i_s_p_s[n * 84 + 12] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 4]);
                        PRIM_INT__i_s_p_s[n * 84 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 4], PRIM_INT__i_s_p_s[n * 84 + 12]);
                        PRIM_INT__i_s_p_s[n * 84 + 12] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 4], PRIM_INT__i_s_p_s[n * 84 + 12]);

                        PRIM_INT__i_s_p_s[n * 84 + 13] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 4]);
                        PRIM_INT__i_s_p_s[n * 84 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 4], PRIM_INT__i_s_p_s[n * 84 + 13]);
                        PRIM_INT__i_s_p_s[n * 84 + 13] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 2], PRIM_INT__i_s_p_s[n * 84 + 13]);

                        PRIM_INT__i_s_p_s[n * 84 + 14] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 4]);
                        PRIM_INT__i_s_p_s[n * 84 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 4], PRIM_INT__i_s_p_s[n * 84 + 14]);
                        PRIM_INT__i_s_p_s[n * 84 + 14] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 1], PRIM_INT__i_s_p_s[n * 84 + 14]);

                        PRIM_INT__i_s_p_s[n * 84 + 15] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 5]);
                        PRIM_INT__i_s_p_s[n * 84 + 15] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 5], PRIM_INT__i_s_p_s[n * 84 + 15]);
                        PRIM_INT__i_s_p_s[n * 84 + 15] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 5], PRIM_INT__i_s_p_s[n * 84 + 15]);

                        PRIM_INT__i_s_p_s[n * 84 + 16] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 5]);
                        PRIM_INT__i_s_p_s[n * 84 + 16] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 5], PRIM_INT__i_s_p_s[n * 84 + 16]);

                        PRIM_INT__i_s_p_s[n * 84 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 5]);
                        PRIM_INT__i_s_p_s[n * 84 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 5], PRIM_INT__i_s_p_s[n * 84 + 17]);
                        PRIM_INT__i_s_p_s[n * 84 + 17] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 2], PRIM_INT__i_s_p_s[n * 84 + 17]);

                        PRIM_INT__i_s_p_s[n * 84 + 18] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 6]);
                        PRIM_INT__i_s_p_s[n * 84 + 18] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 6], PRIM_INT__i_s_p_s[n * 84 + 18]);
                        PRIM_INT__i_s_p_s[n * 84 + 18] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 6], PRIM_INT__i_s_p_s[n * 84 + 18]);

                        PRIM_INT__i_s_p_s[n * 84 + 19] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 6]);
                        PRIM_INT__i_s_p_s[n * 84 + 19] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 6], PRIM_INT__i_s_p_s[n * 84 + 19]);
                        PRIM_INT__i_s_p_s[n * 84 + 19] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 3], PRIM_INT__i_s_p_s[n * 84 + 19]);

                        PRIM_INT__i_s_p_s[n * 84 + 20] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 6]);
                        PRIM_INT__i_s_p_s[n * 84 + 20] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 6], PRIM_INT__i_s_p_s[n * 84 + 20]);

                        PRIM_INT__i_s_p_s[n * 84 + 21] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 7]);
                        PRIM_INT__i_s_p_s[n * 84 + 21] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 7], PRIM_INT__i_s_p_s[n * 84 + 21]);
                        PRIM_INT__i_s_p_s[n * 84 + 21] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 7], PRIM_INT__i_s_p_s[n * 84 + 21]);

                        PRIM_INT__i_s_p_s[n * 84 + 22] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 7]);
                        PRIM_INT__i_s_p_s[n * 84 + 22] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 7], PRIM_INT__i_s_p_s[n * 84 + 22]);
                        PRIM_INT__i_s_p_s[n * 84 + 22] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 4], PRIM_INT__i_s_p_s[n * 84 + 22]);

                        PRIM_INT__i_s_p_s[n * 84 + 23] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 7]);
                        PRIM_INT__i_s_p_s[n * 84 + 23] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 7], PRIM_INT__i_s_p_s[n * 84 + 23]);
                        PRIM_INT__i_s_p_s[n * 84 + 23] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 3], PRIM_INT__i_s_p_s[n * 84 + 23]);

                        PRIM_INT__i_s_p_s[n * 84 + 24] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 8]);
                        PRIM_INT__i_s_p_s[n * 84 + 24] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 8], PRIM_INT__i_s_p_s[n * 84 + 24]);
                        PRIM_INT__i_s_p_s[n * 84 + 24] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 8], PRIM_INT__i_s_p_s[n * 84 + 24]);

                        PRIM_INT__i_s_p_s[n * 84 + 25] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 8]);
                        PRIM_INT__i_s_p_s[n * 84 + 25] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 8], PRIM_INT__i_s_p_s[n * 84 + 25]);
                        PRIM_INT__i_s_p_s[n * 84 + 25] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 5], PRIM_INT__i_s_p_s[n * 84 + 25]);

                        PRIM_INT__i_s_p_s[n * 84 + 26] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 8]);
                        PRIM_INT__i_s_p_s[n * 84 + 26] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 8], PRIM_INT__i_s_p_s[n * 84 + 26]);
                        PRIM_INT__i_s_p_s[n * 84 + 26] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 4], PRIM_INT__i_s_p_s[n * 84 + 26]);

                        PRIM_INT__i_s_p_s[n * 84 + 27] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 9]);
                        PRIM_INT__i_s_p_s[n * 84 + 27] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 9], PRIM_INT__i_s_p_s[n * 84 + 27]);
                        PRIM_INT__i_s_p_s[n * 84 + 27] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 9], PRIM_INT__i_s_p_s[n * 84 + 27]);

                        PRIM_INT__i_s_p_s[n * 84 + 28] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 9]);
                        PRIM_INT__i_s_p_s[n * 84 + 28] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 9], PRIM_INT__i_s_p_s[n * 84 + 28]);

                        PRIM_INT__i_s_p_s[n * 84 + 29] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 9]);
                        PRIM_INT__i_s_p_s[n * 84 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 9], PRIM_INT__i_s_p_s[n * 84 + 29]);
                        PRIM_INT__i_s_p_s[n * 84 + 29] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 5], PRIM_INT__i_s_p_s[n * 84 + 29]);

                        PRIM_INT__i_s_p_s[n * 84 + 30] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 10]);
                        PRIM_INT__i_s_p_s[n * 84 + 30] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 10], PRIM_INT__i_s_p_s[n * 84 + 30]);
                        PRIM_INT__i_s_p_s[n * 84 + 30] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 10], PRIM_INT__i_s_p_s[n * 84 + 30]);

                        PRIM_INT__i_s_p_s[n * 84 + 31] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 10]);
                        PRIM_INT__i_s_p_s[n * 84 + 31] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 10], PRIM_INT__i_s_p_s[n * 84 + 31]);
                        PRIM_INT__i_s_p_s[n * 84 + 31] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 6], PRIM_INT__i_s_p_s[n * 84 + 31]);

                        PRIM_INT__i_s_p_s[n * 84 + 32] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 10]);
                        PRIM_INT__i_s_p_s[n * 84 + 32] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 10], PRIM_INT__i_s_p_s[n * 84 + 32]);

                        PRIM_INT__i_s_p_s[n * 84 + 33] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 11]);
                        PRIM_INT__i_s_p_s[n * 84 + 33] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 11], PRIM_INT__i_s_p_s[n * 84 + 33]);
                        PRIM_INT__i_s_p_s[n * 84 + 33] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 11], PRIM_INT__i_s_p_s[n * 84 + 33]);

                        PRIM_INT__i_s_p_s[n * 84 + 34] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 11]);
                        PRIM_INT__i_s_p_s[n * 84 + 34] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 11], PRIM_INT__i_s_p_s[n * 84 + 34]);
                        PRIM_INT__i_s_p_s[n * 84 + 34] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 7], PRIM_INT__i_s_p_s[n * 84 + 34]);

                        PRIM_INT__i_s_p_s[n * 84 + 35] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 11]);
                        PRIM_INT__i_s_p_s[n * 84 + 35] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 11], PRIM_INT__i_s_p_s[n * 84 + 35]);
                        PRIM_INT__i_s_p_s[n * 84 + 35] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 6], PRIM_INT__i_s_p_s[n * 84 + 35]);

                        PRIM_INT__i_s_p_s[n * 84 + 36] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 12]);
                        PRIM_INT__i_s_p_s[n * 84 + 36] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 12], PRIM_INT__i_s_p_s[n * 84 + 36]);
                        PRIM_INT__i_s_p_s[n * 84 + 36] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 12], PRIM_INT__i_s_p_s[n * 84 + 36]);

                        PRIM_INT__i_s_p_s[n * 84 + 37] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 12]);
                        PRIM_INT__i_s_p_s[n * 84 + 37] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 12], PRIM_INT__i_s_p_s[n * 84 + 37]);
                        PRIM_INT__i_s_p_s[n * 84 + 37] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 8], PRIM_INT__i_s_p_s[n * 84 + 37]);

                        PRIM_INT__i_s_p_s[n * 84 + 38] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 12]);
                        PRIM_INT__i_s_p_s[n * 84 + 38] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 12], PRIM_INT__i_s_p_s[n * 84 + 38]);
                        PRIM_INT__i_s_p_s[n * 84 + 38] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 7], PRIM_INT__i_s_p_s[n * 84 + 38]);

                        PRIM_INT__i_s_p_s[n * 84 + 39] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 13]);
                        PRIM_INT__i_s_p_s[n * 84 + 39] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 13], PRIM_INT__i_s_p_s[n * 84 + 39]);
                        PRIM_INT__i_s_p_s[n * 84 + 39] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 13], PRIM_INT__i_s_p_s[n * 84 + 39]);

                        PRIM_INT__i_s_p_s[n * 84 + 40] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 13]);
                        PRIM_INT__i_s_p_s[n * 84 + 40] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 13], PRIM_INT__i_s_p_s[n * 84 + 40]);
                        PRIM_INT__i_s_p_s[n * 84 + 40] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 9], PRIM_INT__i_s_p_s[n * 84 + 40]);

                        PRIM_INT__i_s_p_s[n * 84 + 41] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 13]);
                        PRIM_INT__i_s_p_s[n * 84 + 41] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 13], PRIM_INT__i_s_p_s[n * 84 + 41]);
                        PRIM_INT__i_s_p_s[n * 84 + 41] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 8], PRIM_INT__i_s_p_s[n * 84 + 41]);

                        PRIM_INT__i_s_p_s[n * 84 + 42] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 14]);
                        PRIM_INT__i_s_p_s[n * 84 + 42] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 14], PRIM_INT__i_s_p_s[n * 84 + 42]);
                        PRIM_INT__i_s_p_s[n * 84 + 42] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 14], PRIM_INT__i_s_p_s[n * 84 + 42]);

                        PRIM_INT__i_s_p_s[n * 84 + 43] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 14]);
                        PRIM_INT__i_s_p_s[n * 84 + 43] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 14], PRIM_INT__i_s_p_s[n * 84 + 43]);

                        PRIM_INT__i_s_p_s[n * 84 + 44] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 14]);
                        PRIM_INT__i_s_p_s[n * 84 + 44] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 14], PRIM_INT__i_s_p_s[n * 84 + 44]);
                        PRIM_INT__i_s_p_s[n * 84 + 44] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 9], PRIM_INT__i_s_p_s[n * 84 + 44]);

                        PRIM_INT__i_s_p_s[n * 84 + 45] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 15]);
                        PRIM_INT__i_s_p_s[n * 84 + 45] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 15], PRIM_INT__i_s_p_s[n * 84 + 45]);
                        PRIM_INT__i_s_p_s[n * 84 + 45] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 15], PRIM_INT__i_s_p_s[n * 84 + 45]);

                        PRIM_INT__i_s_p_s[n * 84 + 46] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 15]);
                        PRIM_INT__i_s_p_s[n * 84 + 46] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 15], PRIM_INT__i_s_p_s[n * 84 + 46]);
                        PRIM_INT__i_s_p_s[n * 84 + 46] = SIMINT_FMADD( vrr_const_5_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 10], PRIM_INT__i_s_p_s[n * 84 + 46]);

                        PRIM_INT__i_s_p_s[n * 84 + 47] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 15]);
                        PRIM_INT__i_s_p_s[n * 84 + 47] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 15], PRIM_INT__i_s_p_s[n * 84 + 47]);

                        PRIM_INT__i_s_p_s[n * 84 + 48] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 16]);
                        PRIM_INT__i_s_p_s[n * 84 + 48] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 16], PRIM_INT__i_s_p_s[n * 84 + 48]);
                        PRIM_INT__i_s_p_s[n * 84 + 48] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 16], PRIM_INT__i_s_p_s[n * 84 + 48]);

                        PRIM_INT__i_s_p_s[n * 84 + 49] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 16]);
                        PRIM_INT__i_s_p_s[n * 84 + 49] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 16], PRIM_INT__i_s_p_s[n * 84 + 49]);
                        PRIM_INT__i_s_p_s[n * 84 + 49] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 11], PRIM_INT__i_s_p_s[n * 84 + 49]);

                        PRIM_INT__i_s_p_s[n * 84 + 50] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 16]);
                        PRIM_INT__i_s_p_s[n * 84 + 50] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 16], PRIM_INT__i_s_p_s[n * 84 + 50]);
                        PRIM_INT__i_s_p_s[n * 84 + 50] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 10], PRIM_INT__i_s_p_s[n * 84 + 50]);

                        PRIM_INT__i_s_p_s[n * 84 + 51] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 17]);
                        PRIM_INT__i_s_p_s[n * 84 + 51] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 17], PRIM_INT__i_s_p_s[n * 84 + 51]);
                        PRIM_INT__i_s_p_s[n * 84 + 51] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 17], PRIM_INT__i_s_p_s[n * 84 + 51]);

                        PRIM_INT__i_s_p_s[n * 84 + 52] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 17]);
                        PRIM_INT__i_s_p_s[n * 84 + 52] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 17], PRIM_INT__i_s_p_s[n * 84 + 52]);
                        PRIM_INT__i_s_p_s[n * 84 + 52] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 12], PRIM_INT__i_s_p_s[n * 84 + 52]);

                        PRIM_INT__i_s_p_s[n * 84 + 53] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 17]);
                        PRIM_INT__i_s_p_s[n * 84 + 53] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 17], PRIM_INT__i_s_p_s[n * 84 + 53]);
                        PRIM_INT__i_s_p_s[n * 84 + 53] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 11], PRIM_INT__i_s_p_s[n * 84 + 53]);

                        PRIM_INT__i_s_p_s[n * 84 + 54] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 18]);
                        PRIM_INT__i_s_p_s[n * 84 + 54] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 18], PRIM_INT__i_s_p_s[n * 84 + 54]);
                        PRIM_INT__i_s_p_s[n * 84 + 54] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 18], PRIM_INT__i_s_p_s[n * 84 + 54]);

                        PRIM_INT__i_s_p_s[n * 84 + 55] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 18]);
                        PRIM_INT__i_s_p_s[n * 84 + 55] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 18], PRIM_INT__i_s_p_s[n * 84 + 55]);
                        PRIM_INT__i_s_p_s[n * 84 + 55] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 13], PRIM_INT__i_s_p_s[n * 84 + 55]);

                        PRIM_INT__i_s_p_s[n * 84 + 56] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 18]);
                        PRIM_INT__i_s_p_s[n * 84 + 56] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 18], PRIM_INT__i_s_p_s[n * 84 + 56]);
                        PRIM_INT__i_s_p_s[n * 84 + 56] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 12], PRIM_INT__i_s_p_s[n * 84 + 56]);

                        PRIM_INT__i_s_p_s[n * 84 + 57] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 19]);
                        PRIM_INT__i_s_p_s[n * 84 + 57] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 19], PRIM_INT__i_s_p_s[n * 84 + 57]);
                        PRIM_INT__i_s_p_s[n * 84 + 57] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 19], PRIM_INT__i_s_p_s[n * 84 + 57]);

                        PRIM_INT__i_s_p_s[n * 84 + 58] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 19]);
                        PRIM_INT__i_s_p_s[n * 84 + 58] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 19], PRIM_INT__i_s_p_s[n * 84 + 58]);
                        PRIM_INT__i_s_p_s[n * 84 + 58] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 14], PRIM_INT__i_s_p_s[n * 84 + 58]);

                        PRIM_INT__i_s_p_s[n * 84 + 59] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 19]);
                        PRIM_INT__i_s_p_s[n * 84 + 59] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 19], PRIM_INT__i_s_p_s[n * 84 + 59]);
                        PRIM_INT__i_s_p_s[n * 84 + 59] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 13], PRIM_INT__i_s_p_s[n * 84 + 59]);

                        PRIM_INT__i_s_p_s[n * 84 + 60] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 20]);
                        PRIM_INT__i_s_p_s[n * 84 + 60] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 20], PRIM_INT__i_s_p_s[n * 84 + 60]);
                        PRIM_INT__i_s_p_s[n * 84 + 60] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 20], PRIM_INT__i_s_p_s[n * 84 + 60]);

                        PRIM_INT__i_s_p_s[n * 84 + 61] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 20]);
                        PRIM_INT__i_s_p_s[n * 84 + 61] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 20], PRIM_INT__i_s_p_s[n * 84 + 61]);

                        PRIM_INT__i_s_p_s[n * 84 + 62] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 20]);
                        PRIM_INT__i_s_p_s[n * 84 + 62] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 20], PRIM_INT__i_s_p_s[n * 84 + 62]);
                        PRIM_INT__i_s_p_s[n * 84 + 62] = SIMINT_FMADD( vrr_const_5_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 14], PRIM_INT__i_s_p_s[n * 84 + 62]);

                        PRIM_INT__i_s_p_s[n * 84 + 63] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 21]);
                        PRIM_INT__i_s_p_s[n * 84 + 63] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 21], PRIM_INT__i_s_p_s[n * 84 + 63]);

                        PRIM_INT__i_s_p_s[n * 84 + 64] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 21]);
                        PRIM_INT__i_s_p_s[n * 84 + 64] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 21], PRIM_INT__i_s_p_s[n * 84 + 64]);
                        PRIM_INT__i_s_p_s[n * 84 + 64] = SIMINT_FMADD( vrr_const_6_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 15], PRIM_INT__i_s_p_s[n * 84 + 64]);

                        PRIM_INT__i_s_p_s[n * 84 + 65] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 21]);
                        PRIM_INT__i_s_p_s[n * 84 + 65] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 21], PRIM_INT__i_s_p_s[n * 84 + 65]);

                        PRIM_INT__i_s_p_s[n * 84 + 66] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 22]);
                        PRIM_INT__i_s_p_s[n * 84 + 66] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 22], PRIM_INT__i_s_p_s[n * 84 + 66]);

                        PRIM_INT__i_s_p_s[n * 84 + 67] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 22]);
                        PRIM_INT__i_s_p_s[n * 84 + 67] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 22], PRIM_INT__i_s_p_s[n * 84 + 67]);
                        PRIM_INT__i_s_p_s[n * 84 + 67] = SIMINT_FMADD( vrr_const_5_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 16], PRIM_INT__i_s_p_s[n * 84 + 67]);

                        PRIM_INT__i_s_p_s[n * 84 + 68] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 22]);
                        PRIM_INT__i_s_p_s[n * 84 + 68] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 22], PRIM_INT__i_s_p_s[n * 84 + 68]);
                        PRIM_INT__i_s_p_s[n * 84 + 68] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 15], PRIM_INT__i_s_p_s[n * 84 + 68]);

                        PRIM_INT__i_s_p_s[n * 84 + 69] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 23]);
                        PRIM_INT__i_s_p_s[n * 84 + 69] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 23], PRIM_INT__i_s_p_s[n * 84 + 69]);

                        PRIM_INT__i_s_p_s[n * 84 + 70] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 23]);
                        PRIM_INT__i_s_p_s[n * 84 + 70] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 23], PRIM_INT__i_s_p_s[n * 84 + 70]);
                        PRIM_INT__i_s_p_s[n * 84 + 70] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 17], PRIM_INT__i_s_p_s[n * 84 + 70]);

                        PRIM_INT__i_s_p_s[n * 84 + 71] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 23]);
                        PRIM_INT__i_s_p_s[n * 84 + 71] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 23], PRIM_INT__i_s_p_s[n * 84 + 71]);
                        PRIM_INT__i_s_p_s[n * 84 + 71] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 16], PRIM_INT__i_s_p_s[n * 84 + 71]);

                        PRIM_INT__i_s_p_s[n * 84 + 72] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 24]);
                        PRIM_INT__i_s_p_s[n * 84 + 72] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 24], PRIM_INT__i_s_p_s[n * 84 + 72]);

                        PRIM_INT__i_s_p_s[n * 84 + 73] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 24]);
                        PRIM_INT__i_s_p_s[n * 84 + 73] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 24], PRIM_INT__i_s_p_s[n * 84 + 73]);
                        PRIM_INT__i_s_p_s[n * 84 + 73] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 18], PRIM_INT__i_s_p_s[n * 84 + 73]);

                        PRIM_INT__i_s_p_s[n * 84 + 74] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 24]);
                        PRIM_INT__i_s_p_s[n * 84 + 74] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 24], PRIM_INT__i_s_p_s[n * 84 + 74]);
                        PRIM_INT__i_s_p_s[n * 84 + 74] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 17], PRIM_INT__i_s_p_s[n * 84 + 74]);

                        PRIM_INT__i_s_p_s[n * 84 + 75] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 25]);
                        PRIM_INT__i_s_p_s[n * 84 + 75] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 25], PRIM_INT__i_s_p_s[n * 84 + 75]);

                        PRIM_INT__i_s_p_s[n * 84 + 76] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 25]);
                        PRIM_INT__i_s_p_s[n * 84 + 76] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 25], PRIM_INT__i_s_p_s[n * 84 + 76]);
                        PRIM_INT__i_s_p_s[n * 84 + 76] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 19], PRIM_INT__i_s_p_s[n * 84 + 76]);

                        PRIM_INT__i_s_p_s[n * 84 + 77] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 25]);
                        PRIM_INT__i_s_p_s[n * 84 + 77] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 25], PRIM_INT__i_s_p_s[n * 84 + 77]);
                        PRIM_INT__i_s_p_s[n * 84 + 77] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 18], PRIM_INT__i_s_p_s[n * 84 + 77]);

                        PRIM_INT__i_s_p_s[n * 84 + 78] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 26]);
                        PRIM_INT__i_s_p_s[n * 84 + 78] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 26], PRIM_INT__i_s_p_s[n * 84 + 78]);

                        PRIM_INT__i_s_p_s[n * 84 + 79] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 26]);
                        PRIM_INT__i_s_p_s[n * 84 + 79] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 26], PRIM_INT__i_s_p_s[n * 84 + 79]);
                        PRIM_INT__i_s_p_s[n * 84 + 79] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 20], PRIM_INT__i_s_p_s[n * 84 + 79]);

                        PRIM_INT__i_s_p_s[n * 84 + 80] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 26]);
                        PRIM_INT__i_s_p_s[n * 84 + 80] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 26], PRIM_INT__i_s_p_s[n * 84 + 80]);
                        PRIM_INT__i_s_p_s[n * 84 + 80] = SIMINT_FMADD( vrr_const_5_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 19], PRIM_INT__i_s_p_s[n * 84 + 80]);

                        PRIM_INT__i_s_p_s[n * 84 + 81] = SIMINT_MUL(Q_PA[0], PRIM_INT__i_s_s_s[n * 28 + 27]);
                        PRIM_INT__i_s_p_s[n * 84 + 81] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__i_s_s_s[(n+1) * 28 + 27], PRIM_INT__i_s_p_s[n * 84 + 81]);

                        PRIM_INT__i_s_p_s[n * 84 + 82] = SIMINT_MUL(Q_PA[1], PRIM_INT__i_s_s_s[n * 28 + 27]);
                        PRIM_INT__i_s_p_s[n * 84 + 82] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__i_s_s_s[(n+1) * 28 + 27], PRIM_INT__i_s_p_s[n * 84 + 82]);

                        PRIM_INT__i_s_p_s[n * 84 + 83] = SIMINT_MUL(Q_PA[2], PRIM_INT__i_s_s_s[n * 28 + 27]);
                        PRIM_INT__i_s_p_s[n * 84 + 83] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__i_s_s_s[(n+1) * 28 + 27], PRIM_INT__i_s_p_s[n * 84 + 83]);
                        PRIM_INT__i_s_p_s[n * 84 + 83] = SIMINT_FMADD( vrr_const_6_over_2pq, PRIM_INT__h_s_s_s[(n+1) * 21 + 20], PRIM_INT__i_s_p_s[n * 84 + 83]);

                    }

}


