
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( d s | f s )
//////////////////////////////////////////////
void VRR_K_d_s_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_d_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n)
{
    int n = 0;
    const SIMINT_DBLTYPE vrr_const_2_over_2q = SIMINT_MUL(SIMINT_DBLSET1(2), one_over_2q);
    const SIMINT_DBLTYPE vrr_const_1_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(1), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(2), one_over_2pq);

                    // Forming PRIM_INT__d_s_f_s[num_n * 60];
                    for(n = 0; n < num_n; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__d_s_f_s[n * 60 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 0]);
                        PRIM_INT__d_s_f_s[n * 60 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 0], PRIM_INT__d_s_f_s[n * 60 + 0]);
                        PRIM_INT__d_s_f_s[n * 60 + 0] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 0], PRIM_INT__d_s_p_s[n * 18 + 0]), PRIM_INT__d_s_f_s[n * 60 + 0]);
                        PRIM_INT__d_s_f_s[n * 60 + 0] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 0], PRIM_INT__d_s_f_s[n * 60 + 0]);

                        PRIM_INT__d_s_f_s[n * 60 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 0]);
                        PRIM_INT__d_s_f_s[n * 60 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 0], PRIM_INT__d_s_f_s[n * 60 + 1]);

                        PRIM_INT__d_s_f_s[n * 60 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 0]);
                        PRIM_INT__d_s_f_s[n * 60 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 0], PRIM_INT__d_s_f_s[n * 60 + 2]);

                        PRIM_INT__d_s_f_s[n * 60 + 3] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 3]);
                        PRIM_INT__d_s_f_s[n * 60 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 3], PRIM_INT__d_s_f_s[n * 60 + 3]);
                        PRIM_INT__d_s_f_s[n * 60 + 3] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 3], PRIM_INT__d_s_f_s[n * 60 + 3]);

                        PRIM_INT__d_s_f_s[n * 60 + 4] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 1]);
                        PRIM_INT__d_s_f_s[n * 60 + 4] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 1], PRIM_INT__d_s_f_s[n * 60 + 4]);

                        PRIM_INT__d_s_f_s[n * 60 + 5] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 5]);
                        PRIM_INT__d_s_f_s[n * 60 + 5] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 5], PRIM_INT__d_s_f_s[n * 60 + 5]);
                        PRIM_INT__d_s_f_s[n * 60 + 5] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 5], PRIM_INT__d_s_f_s[n * 60 + 5]);

                        PRIM_INT__d_s_f_s[n * 60 + 6] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 3]);
                        PRIM_INT__d_s_f_s[n * 60 + 6] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 3], PRIM_INT__d_s_f_s[n * 60 + 6]);
                        PRIM_INT__d_s_f_s[n * 60 + 6] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 1], PRIM_INT__d_s_p_s[n * 18 + 1]), PRIM_INT__d_s_f_s[n * 60 + 6]);

                        PRIM_INT__d_s_f_s[n * 60 + 7] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 3]);
                        PRIM_INT__d_s_f_s[n * 60 + 7] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 3], PRIM_INT__d_s_f_s[n * 60 + 7]);

                        PRIM_INT__d_s_f_s[n * 60 + 8] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 5]);
                        PRIM_INT__d_s_f_s[n * 60 + 8] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 5], PRIM_INT__d_s_f_s[n * 60 + 8]);

                        PRIM_INT__d_s_f_s[n * 60 + 9] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 5]);
                        PRIM_INT__d_s_f_s[n * 60 + 9] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 5], PRIM_INT__d_s_f_s[n * 60 + 9]);
                        PRIM_INT__d_s_f_s[n * 60 + 9] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 2], PRIM_INT__d_s_p_s[n * 18 + 2]), PRIM_INT__d_s_f_s[n * 60 + 9]);

                        PRIM_INT__d_s_f_s[n * 60 + 10] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 6]);
                        PRIM_INT__d_s_f_s[n * 60 + 10] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 6], PRIM_INT__d_s_f_s[n * 60 + 10]);
                        PRIM_INT__d_s_f_s[n * 60 + 10] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 3], PRIM_INT__d_s_p_s[n * 18 + 3]), PRIM_INT__d_s_f_s[n * 60 + 10]);
                        PRIM_INT__d_s_f_s[n * 60 + 10] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 6], PRIM_INT__d_s_f_s[n * 60 + 10]);

                        PRIM_INT__d_s_f_s[n * 60 + 11] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 6]);
                        PRIM_INT__d_s_f_s[n * 60 + 11] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 6], PRIM_INT__d_s_f_s[n * 60 + 11]);
                        PRIM_INT__d_s_f_s[n * 60 + 11] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 0], PRIM_INT__d_s_f_s[n * 60 + 11]);

                        PRIM_INT__d_s_f_s[n * 60 + 12] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 6]);
                        PRIM_INT__d_s_f_s[n * 60 + 12] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 6], PRIM_INT__d_s_f_s[n * 60 + 12]);

                        PRIM_INT__d_s_f_s[n * 60 + 13] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 9]);
                        PRIM_INT__d_s_f_s[n * 60 + 13] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 9], PRIM_INT__d_s_f_s[n * 60 + 13]);
                        PRIM_INT__d_s_f_s[n * 60 + 13] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 9], PRIM_INT__d_s_f_s[n * 60 + 13]);

                        PRIM_INT__d_s_f_s[n * 60 + 14] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 7]);
                        PRIM_INT__d_s_f_s[n * 60 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 7], PRIM_INT__d_s_f_s[n * 60 + 14]);

                        PRIM_INT__d_s_f_s[n * 60 + 15] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 11]);
                        PRIM_INT__d_s_f_s[n * 60 + 15] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 11], PRIM_INT__d_s_f_s[n * 60 + 15]);
                        PRIM_INT__d_s_f_s[n * 60 + 15] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 11], PRIM_INT__d_s_f_s[n * 60 + 15]);

                        PRIM_INT__d_s_f_s[n * 60 + 16] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 9]);
                        PRIM_INT__d_s_f_s[n * 60 + 16] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 9], PRIM_INT__d_s_f_s[n * 60 + 16]);
                        PRIM_INT__d_s_f_s[n * 60 + 16] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 4], PRIM_INT__d_s_p_s[n * 18 + 4]), PRIM_INT__d_s_f_s[n * 60 + 16]);
                        PRIM_INT__d_s_f_s[n * 60 + 16] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 3], PRIM_INT__d_s_f_s[n * 60 + 16]);

                        PRIM_INT__d_s_f_s[n * 60 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 9]);
                        PRIM_INT__d_s_f_s[n * 60 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 9], PRIM_INT__d_s_f_s[n * 60 + 17]);

                        PRIM_INT__d_s_f_s[n * 60 + 18] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 11]);
                        PRIM_INT__d_s_f_s[n * 60 + 18] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 11], PRIM_INT__d_s_f_s[n * 60 + 18]);
                        PRIM_INT__d_s_f_s[n * 60 + 18] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 5], PRIM_INT__d_s_f_s[n * 60 + 18]);

                        PRIM_INT__d_s_f_s[n * 60 + 19] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 11]);
                        PRIM_INT__d_s_f_s[n * 60 + 19] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 11], PRIM_INT__d_s_f_s[n * 60 + 19]);
                        PRIM_INT__d_s_f_s[n * 60 + 19] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 5], PRIM_INT__d_s_p_s[n * 18 + 5]), PRIM_INT__d_s_f_s[n * 60 + 19]);

                        PRIM_INT__d_s_f_s[n * 60 + 20] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 12]);
                        PRIM_INT__d_s_f_s[n * 60 + 20] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 12], PRIM_INT__d_s_f_s[n * 60 + 20]);
                        PRIM_INT__d_s_f_s[n * 60 + 20] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 6], PRIM_INT__d_s_p_s[n * 18 + 6]), PRIM_INT__d_s_f_s[n * 60 + 20]);
                        PRIM_INT__d_s_f_s[n * 60 + 20] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 12], PRIM_INT__d_s_f_s[n * 60 + 20]);

                        PRIM_INT__d_s_f_s[n * 60 + 21] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 12]);
                        PRIM_INT__d_s_f_s[n * 60 + 21] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 12], PRIM_INT__d_s_f_s[n * 60 + 21]);

                        PRIM_INT__d_s_f_s[n * 60 + 22] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 12]);
                        PRIM_INT__d_s_f_s[n * 60 + 22] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 12], PRIM_INT__d_s_f_s[n * 60 + 22]);
                        PRIM_INT__d_s_f_s[n * 60 + 22] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 0], PRIM_INT__d_s_f_s[n * 60 + 22]);

                        PRIM_INT__d_s_f_s[n * 60 + 23] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 15]);
                        PRIM_INT__d_s_f_s[n * 60 + 23] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 15], PRIM_INT__d_s_f_s[n * 60 + 23]);
                        PRIM_INT__d_s_f_s[n * 60 + 23] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 15], PRIM_INT__d_s_f_s[n * 60 + 23]);

                        PRIM_INT__d_s_f_s[n * 60 + 24] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 13]);
                        PRIM_INT__d_s_f_s[n * 60 + 24] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 13], PRIM_INT__d_s_f_s[n * 60 + 24]);
                        PRIM_INT__d_s_f_s[n * 60 + 24] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 1], PRIM_INT__d_s_f_s[n * 60 + 24]);

                        PRIM_INT__d_s_f_s[n * 60 + 25] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 17]);
                        PRIM_INT__d_s_f_s[n * 60 + 25] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 17], PRIM_INT__d_s_f_s[n * 60 + 25]);
                        PRIM_INT__d_s_f_s[n * 60 + 25] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 17], PRIM_INT__d_s_f_s[n * 60 + 25]);

                        PRIM_INT__d_s_f_s[n * 60 + 26] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 15]);
                        PRIM_INT__d_s_f_s[n * 60 + 26] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 15], PRIM_INT__d_s_f_s[n * 60 + 26]);
                        PRIM_INT__d_s_f_s[n * 60 + 26] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 7], PRIM_INT__d_s_p_s[n * 18 + 7]), PRIM_INT__d_s_f_s[n * 60 + 26]);

                        PRIM_INT__d_s_f_s[n * 60 + 27] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 15]);
                        PRIM_INT__d_s_f_s[n * 60 + 27] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 15], PRIM_INT__d_s_f_s[n * 60 + 27]);
                        PRIM_INT__d_s_f_s[n * 60 + 27] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 3], PRIM_INT__d_s_f_s[n * 60 + 27]);

                        PRIM_INT__d_s_f_s[n * 60 + 28] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 17]);
                        PRIM_INT__d_s_f_s[n * 60 + 28] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 17], PRIM_INT__d_s_f_s[n * 60 + 28]);

                        PRIM_INT__d_s_f_s[n * 60 + 29] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 17]);
                        PRIM_INT__d_s_f_s[n * 60 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 17], PRIM_INT__d_s_f_s[n * 60 + 29]);
                        PRIM_INT__d_s_f_s[n * 60 + 29] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 8], PRIM_INT__d_s_p_s[n * 18 + 8]), PRIM_INT__d_s_f_s[n * 60 + 29]);
                        PRIM_INT__d_s_f_s[n * 60 + 29] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 5], PRIM_INT__d_s_f_s[n * 60 + 29]);

                        PRIM_INT__d_s_f_s[n * 60 + 30] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 18]);
                        PRIM_INT__d_s_f_s[n * 60 + 30] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 18], PRIM_INT__d_s_f_s[n * 60 + 30]);
                        PRIM_INT__d_s_f_s[n * 60 + 30] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 9], PRIM_INT__d_s_p_s[n * 18 + 9]), PRIM_INT__d_s_f_s[n * 60 + 30]);

                        PRIM_INT__d_s_f_s[n * 60 + 31] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 18]);
                        PRIM_INT__d_s_f_s[n * 60 + 31] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 18], PRIM_INT__d_s_f_s[n * 60 + 31]);
                        PRIM_INT__d_s_f_s[n * 60 + 31] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 6], PRIM_INT__d_s_f_s[n * 60 + 31]);

                        PRIM_INT__d_s_f_s[n * 60 + 32] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 18]);
                        PRIM_INT__d_s_f_s[n * 60 + 32] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 18], PRIM_INT__d_s_f_s[n * 60 + 32]);

                        PRIM_INT__d_s_f_s[n * 60 + 33] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 21]);
                        PRIM_INT__d_s_f_s[n * 60 + 33] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 21], PRIM_INT__d_s_f_s[n * 60 + 33]);

                        PRIM_INT__d_s_f_s[n * 60 + 34] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 19]);
                        PRIM_INT__d_s_f_s[n * 60 + 34] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 19], PRIM_INT__d_s_f_s[n * 60 + 34]);

                        PRIM_INT__d_s_f_s[n * 60 + 35] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 23]);
                        PRIM_INT__d_s_f_s[n * 60 + 35] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 23], PRIM_INT__d_s_f_s[n * 60 + 35]);

                        PRIM_INT__d_s_f_s[n * 60 + 36] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 21]);
                        PRIM_INT__d_s_f_s[n * 60 + 36] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 21], PRIM_INT__d_s_f_s[n * 60 + 36]);
                        PRIM_INT__d_s_f_s[n * 60 + 36] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 10], PRIM_INT__d_s_p_s[n * 18 + 10]), PRIM_INT__d_s_f_s[n * 60 + 36]);
                        PRIM_INT__d_s_f_s[n * 60 + 36] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 9], PRIM_INT__d_s_f_s[n * 60 + 36]);

                        PRIM_INT__d_s_f_s[n * 60 + 37] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 21]);
                        PRIM_INT__d_s_f_s[n * 60 + 37] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 21], PRIM_INT__d_s_f_s[n * 60 + 37]);

                        PRIM_INT__d_s_f_s[n * 60 + 38] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 23]);
                        PRIM_INT__d_s_f_s[n * 60 + 38] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 23], PRIM_INT__d_s_f_s[n * 60 + 38]);
                        PRIM_INT__d_s_f_s[n * 60 + 38] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 11], PRIM_INT__d_s_f_s[n * 60 + 38]);

                        PRIM_INT__d_s_f_s[n * 60 + 39] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 23]);
                        PRIM_INT__d_s_f_s[n * 60 + 39] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 23], PRIM_INT__d_s_f_s[n * 60 + 39]);
                        PRIM_INT__d_s_f_s[n * 60 + 39] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 11], PRIM_INT__d_s_p_s[n * 18 + 11]), PRIM_INT__d_s_f_s[n * 60 + 39]);

                        PRIM_INT__d_s_f_s[n * 60 + 40] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 24]);
                        PRIM_INT__d_s_f_s[n * 60 + 40] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 24], PRIM_INT__d_s_f_s[n * 60 + 40]);
                        PRIM_INT__d_s_f_s[n * 60 + 40] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 12], PRIM_INT__d_s_p_s[n * 18 + 12]), PRIM_INT__d_s_f_s[n * 60 + 40]);

                        PRIM_INT__d_s_f_s[n * 60 + 41] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 24]);
                        PRIM_INT__d_s_f_s[n * 60 + 41] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 24], PRIM_INT__d_s_f_s[n * 60 + 41]);
                        PRIM_INT__d_s_f_s[n * 60 + 41] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 12], PRIM_INT__d_s_f_s[n * 60 + 41]);

                        PRIM_INT__d_s_f_s[n * 60 + 42] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 24]);
                        PRIM_INT__d_s_f_s[n * 60 + 42] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 24], PRIM_INT__d_s_f_s[n * 60 + 42]);
                        PRIM_INT__d_s_f_s[n * 60 + 42] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 6], PRIM_INT__d_s_f_s[n * 60 + 42]);

                        PRIM_INT__d_s_f_s[n * 60 + 43] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 27]);
                        PRIM_INT__d_s_f_s[n * 60 + 43] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 27], PRIM_INT__d_s_f_s[n * 60 + 43]);

                        PRIM_INT__d_s_f_s[n * 60 + 44] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 25]);
                        PRIM_INT__d_s_f_s[n * 60 + 44] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 25], PRIM_INT__d_s_f_s[n * 60 + 44]);
                        PRIM_INT__d_s_f_s[n * 60 + 44] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 7], PRIM_INT__d_s_f_s[n * 60 + 44]);

                        PRIM_INT__d_s_f_s[n * 60 + 45] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 29]);
                        PRIM_INT__d_s_f_s[n * 60 + 45] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 29], PRIM_INT__d_s_f_s[n * 60 + 45]);

                        PRIM_INT__d_s_f_s[n * 60 + 46] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 27]);
                        PRIM_INT__d_s_f_s[n * 60 + 46] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 27], PRIM_INT__d_s_f_s[n * 60 + 46]);
                        PRIM_INT__d_s_f_s[n * 60 + 46] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 13], PRIM_INT__d_s_p_s[n * 18 + 13]), PRIM_INT__d_s_f_s[n * 60 + 46]);
                        PRIM_INT__d_s_f_s[n * 60 + 46] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 15], PRIM_INT__d_s_f_s[n * 60 + 46]);

                        PRIM_INT__d_s_f_s[n * 60 + 47] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 27]);
                        PRIM_INT__d_s_f_s[n * 60 + 47] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 27], PRIM_INT__d_s_f_s[n * 60 + 47]);
                        PRIM_INT__d_s_f_s[n * 60 + 47] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 9], PRIM_INT__d_s_f_s[n * 60 + 47]);

                        PRIM_INT__d_s_f_s[n * 60 + 48] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 29]);
                        PRIM_INT__d_s_f_s[n * 60 + 48] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 29], PRIM_INT__d_s_f_s[n * 60 + 48]);
                        PRIM_INT__d_s_f_s[n * 60 + 48] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 17], PRIM_INT__d_s_f_s[n * 60 + 48]);

                        PRIM_INT__d_s_f_s[n * 60 + 49] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 29]);
                        PRIM_INT__d_s_f_s[n * 60 + 49] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 29], PRIM_INT__d_s_f_s[n * 60 + 49]);
                        PRIM_INT__d_s_f_s[n * 60 + 49] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 14], PRIM_INT__d_s_p_s[n * 18 + 14]), PRIM_INT__d_s_f_s[n * 60 + 49]);
                        PRIM_INT__d_s_f_s[n * 60 + 49] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 11], PRIM_INT__d_s_f_s[n * 60 + 49]);

                        PRIM_INT__d_s_f_s[n * 60 + 50] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 30]);
                        PRIM_INT__d_s_f_s[n * 60 + 50] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 30], PRIM_INT__d_s_f_s[n * 60 + 50]);
                        PRIM_INT__d_s_f_s[n * 60 + 50] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 15], PRIM_INT__d_s_p_s[n * 18 + 15]), PRIM_INT__d_s_f_s[n * 60 + 50]);

                        PRIM_INT__d_s_f_s[n * 60 + 51] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 30]);
                        PRIM_INT__d_s_f_s[n * 60 + 51] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 30], PRIM_INT__d_s_f_s[n * 60 + 51]);

                        PRIM_INT__d_s_f_s[n * 60 + 52] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 30]);
                        PRIM_INT__d_s_f_s[n * 60 + 52] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 30], PRIM_INT__d_s_f_s[n * 60 + 52]);
                        PRIM_INT__d_s_f_s[n * 60 + 52] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 12], PRIM_INT__d_s_f_s[n * 60 + 52]);

                        PRIM_INT__d_s_f_s[n * 60 + 53] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 33]);
                        PRIM_INT__d_s_f_s[n * 60 + 53] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 33], PRIM_INT__d_s_f_s[n * 60 + 53]);

                        PRIM_INT__d_s_f_s[n * 60 + 54] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 31]);
                        PRIM_INT__d_s_f_s[n * 60 + 54] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 31], PRIM_INT__d_s_f_s[n * 60 + 54]);
                        PRIM_INT__d_s_f_s[n * 60 + 54] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 13], PRIM_INT__d_s_f_s[n * 60 + 54]);

                        PRIM_INT__d_s_f_s[n * 60 + 55] = SIMINT_MUL(Q_PA[0], PRIM_INT__d_s_d_s[n * 36 + 35]);
                        PRIM_INT__d_s_f_s[n * 60 + 55] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__d_s_d_s[(n+1) * 36 + 35], PRIM_INT__d_s_f_s[n * 60 + 55]);

                        PRIM_INT__d_s_f_s[n * 60 + 56] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 33]);
                        PRIM_INT__d_s_f_s[n * 60 + 56] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 33], PRIM_INT__d_s_f_s[n * 60 + 56]);
                        PRIM_INT__d_s_f_s[n * 60 + 56] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 16], PRIM_INT__d_s_p_s[n * 18 + 16]), PRIM_INT__d_s_f_s[n * 60 + 56]);

                        PRIM_INT__d_s_f_s[n * 60 + 57] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 33]);
                        PRIM_INT__d_s_f_s[n * 60 + 57] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 33], PRIM_INT__d_s_f_s[n * 60 + 57]);
                        PRIM_INT__d_s_f_s[n * 60 + 57] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 15], PRIM_INT__d_s_f_s[n * 60 + 57]);

                        PRIM_INT__d_s_f_s[n * 60 + 58] = SIMINT_MUL(Q_PA[1], PRIM_INT__d_s_d_s[n * 36 + 35]);
                        PRIM_INT__d_s_f_s[n * 60 + 58] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__d_s_d_s[(n+1) * 36 + 35], PRIM_INT__d_s_f_s[n * 60 + 58]);

                        PRIM_INT__d_s_f_s[n * 60 + 59] = SIMINT_MUL(Q_PA[2], PRIM_INT__d_s_d_s[n * 36 + 35]);
                        PRIM_INT__d_s_f_s[n * 60 + 59] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__d_s_d_s[(n+1) * 36 + 35], PRIM_INT__d_s_f_s[n * 60 + 59]);
                        PRIM_INT__d_s_f_s[n * 60 + 59] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__d_s_p_s[(n+1) * 18 + 17], PRIM_INT__d_s_p_s[n * 18 + 17]), PRIM_INT__d_s_f_s[n * 60 + 59]);
                        PRIM_INT__d_s_f_s[n * 60 + 59] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__p_s_d_s[(n+1) * 18 + 17], PRIM_INT__d_s_f_s[n * 60 + 59]);

                    }

}


