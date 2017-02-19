
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( f s | f s )
//////////////////////////////////////////////
void VRR_K_f_s_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_d_s,
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
    const SIMINT_DBLTYPE vrr_const_3_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(3), one_over_2pq);

                    // Forming PRIM_INT__f_s_f_s[num_n * 100];
                    for(n = 0; n < num_n; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__f_s_f_s[n * 100 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 0]);
                        PRIM_INT__f_s_f_s[n * 100 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 0], PRIM_INT__f_s_f_s[n * 100 + 0]);
                        PRIM_INT__f_s_f_s[n * 100 + 0] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 0], PRIM_INT__f_s_p_s[n * 30 + 0]), PRIM_INT__f_s_f_s[n * 100 + 0]);
                        PRIM_INT__f_s_f_s[n * 100 + 0] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 0], PRIM_INT__f_s_f_s[n * 100 + 0]);

                        PRIM_INT__f_s_f_s[n * 100 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 0]);
                        PRIM_INT__f_s_f_s[n * 100 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 0], PRIM_INT__f_s_f_s[n * 100 + 1]);

                        PRIM_INT__f_s_f_s[n * 100 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 0]);
                        PRIM_INT__f_s_f_s[n * 100 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 0], PRIM_INT__f_s_f_s[n * 100 + 2]);

                        PRIM_INT__f_s_f_s[n * 100 + 3] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 3]);
                        PRIM_INT__f_s_f_s[n * 100 + 3] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 3], PRIM_INT__f_s_f_s[n * 100 + 3]);
                        PRIM_INT__f_s_f_s[n * 100 + 3] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 3], PRIM_INT__f_s_f_s[n * 100 + 3]);

                        PRIM_INT__f_s_f_s[n * 100 + 4] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 1]);
                        PRIM_INT__f_s_f_s[n * 100 + 4] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 1], PRIM_INT__f_s_f_s[n * 100 + 4]);

                        PRIM_INT__f_s_f_s[n * 100 + 5] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 5]);
                        PRIM_INT__f_s_f_s[n * 100 + 5] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 5], PRIM_INT__f_s_f_s[n * 100 + 5]);
                        PRIM_INT__f_s_f_s[n * 100 + 5] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 5], PRIM_INT__f_s_f_s[n * 100 + 5]);

                        PRIM_INT__f_s_f_s[n * 100 + 6] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 3]);
                        PRIM_INT__f_s_f_s[n * 100 + 6] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 3], PRIM_INT__f_s_f_s[n * 100 + 6]);
                        PRIM_INT__f_s_f_s[n * 100 + 6] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 1], PRIM_INT__f_s_p_s[n * 30 + 1]), PRIM_INT__f_s_f_s[n * 100 + 6]);

                        PRIM_INT__f_s_f_s[n * 100 + 7] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 3]);
                        PRIM_INT__f_s_f_s[n * 100 + 7] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 3], PRIM_INT__f_s_f_s[n * 100 + 7]);

                        PRIM_INT__f_s_f_s[n * 100 + 8] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 5]);
                        PRIM_INT__f_s_f_s[n * 100 + 8] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 5], PRIM_INT__f_s_f_s[n * 100 + 8]);

                        PRIM_INT__f_s_f_s[n * 100 + 9] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 5]);
                        PRIM_INT__f_s_f_s[n * 100 + 9] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 5], PRIM_INT__f_s_f_s[n * 100 + 9]);
                        PRIM_INT__f_s_f_s[n * 100 + 9] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 2], PRIM_INT__f_s_p_s[n * 30 + 2]), PRIM_INT__f_s_f_s[n * 100 + 9]);

                        PRIM_INT__f_s_f_s[n * 100 + 10] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 6]);
                        PRIM_INT__f_s_f_s[n * 100 + 10] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 6], PRIM_INT__f_s_f_s[n * 100 + 10]);
                        PRIM_INT__f_s_f_s[n * 100 + 10] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 3], PRIM_INT__f_s_p_s[n * 30 + 3]), PRIM_INT__f_s_f_s[n * 100 + 10]);
                        PRIM_INT__f_s_f_s[n * 100 + 10] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 6], PRIM_INT__f_s_f_s[n * 100 + 10]);

                        PRIM_INT__f_s_f_s[n * 100 + 11] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 6]);
                        PRIM_INT__f_s_f_s[n * 100 + 11] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 6], PRIM_INT__f_s_f_s[n * 100 + 11]);
                        PRIM_INT__f_s_f_s[n * 100 + 11] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 0], PRIM_INT__f_s_f_s[n * 100 + 11]);

                        PRIM_INT__f_s_f_s[n * 100 + 12] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 6]);
                        PRIM_INT__f_s_f_s[n * 100 + 12] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 6], PRIM_INT__f_s_f_s[n * 100 + 12]);

                        PRIM_INT__f_s_f_s[n * 100 + 13] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 9]);
                        PRIM_INT__f_s_f_s[n * 100 + 13] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 9], PRIM_INT__f_s_f_s[n * 100 + 13]);
                        PRIM_INT__f_s_f_s[n * 100 + 13] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 9], PRIM_INT__f_s_f_s[n * 100 + 13]);

                        PRIM_INT__f_s_f_s[n * 100 + 14] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 7]);
                        PRIM_INT__f_s_f_s[n * 100 + 14] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 7], PRIM_INT__f_s_f_s[n * 100 + 14]);

                        PRIM_INT__f_s_f_s[n * 100 + 15] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 11]);
                        PRIM_INT__f_s_f_s[n * 100 + 15] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 11], PRIM_INT__f_s_f_s[n * 100 + 15]);
                        PRIM_INT__f_s_f_s[n * 100 + 15] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 11], PRIM_INT__f_s_f_s[n * 100 + 15]);

                        PRIM_INT__f_s_f_s[n * 100 + 16] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 9]);
                        PRIM_INT__f_s_f_s[n * 100 + 16] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 9], PRIM_INT__f_s_f_s[n * 100 + 16]);
                        PRIM_INT__f_s_f_s[n * 100 + 16] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 4], PRIM_INT__f_s_p_s[n * 30 + 4]), PRIM_INT__f_s_f_s[n * 100 + 16]);
                        PRIM_INT__f_s_f_s[n * 100 + 16] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 3], PRIM_INT__f_s_f_s[n * 100 + 16]);

                        PRIM_INT__f_s_f_s[n * 100 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 9]);
                        PRIM_INT__f_s_f_s[n * 100 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 9], PRIM_INT__f_s_f_s[n * 100 + 17]);

                        PRIM_INT__f_s_f_s[n * 100 + 18] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 11]);
                        PRIM_INT__f_s_f_s[n * 100 + 18] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 11], PRIM_INT__f_s_f_s[n * 100 + 18]);
                        PRIM_INT__f_s_f_s[n * 100 + 18] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 5], PRIM_INT__f_s_f_s[n * 100 + 18]);

                        PRIM_INT__f_s_f_s[n * 100 + 19] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 11]);
                        PRIM_INT__f_s_f_s[n * 100 + 19] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 11], PRIM_INT__f_s_f_s[n * 100 + 19]);
                        PRIM_INT__f_s_f_s[n * 100 + 19] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 5], PRIM_INT__f_s_p_s[n * 30 + 5]), PRIM_INT__f_s_f_s[n * 100 + 19]);

                        PRIM_INT__f_s_f_s[n * 100 + 20] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 12]);
                        PRIM_INT__f_s_f_s[n * 100 + 20] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 12], PRIM_INT__f_s_f_s[n * 100 + 20]);
                        PRIM_INT__f_s_f_s[n * 100 + 20] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 6], PRIM_INT__f_s_p_s[n * 30 + 6]), PRIM_INT__f_s_f_s[n * 100 + 20]);
                        PRIM_INT__f_s_f_s[n * 100 + 20] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 12], PRIM_INT__f_s_f_s[n * 100 + 20]);

                        PRIM_INT__f_s_f_s[n * 100 + 21] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 12]);
                        PRIM_INT__f_s_f_s[n * 100 + 21] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 12], PRIM_INT__f_s_f_s[n * 100 + 21]);

                        PRIM_INT__f_s_f_s[n * 100 + 22] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 12]);
                        PRIM_INT__f_s_f_s[n * 100 + 22] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 12], PRIM_INT__f_s_f_s[n * 100 + 22]);
                        PRIM_INT__f_s_f_s[n * 100 + 22] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 0], PRIM_INT__f_s_f_s[n * 100 + 22]);

                        PRIM_INT__f_s_f_s[n * 100 + 23] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 15]);
                        PRIM_INT__f_s_f_s[n * 100 + 23] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 15], PRIM_INT__f_s_f_s[n * 100 + 23]);
                        PRIM_INT__f_s_f_s[n * 100 + 23] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 15], PRIM_INT__f_s_f_s[n * 100 + 23]);

                        PRIM_INT__f_s_f_s[n * 100 + 24] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 13]);
                        PRIM_INT__f_s_f_s[n * 100 + 24] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 13], PRIM_INT__f_s_f_s[n * 100 + 24]);
                        PRIM_INT__f_s_f_s[n * 100 + 24] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 1], PRIM_INT__f_s_f_s[n * 100 + 24]);

                        PRIM_INT__f_s_f_s[n * 100 + 25] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 17]);
                        PRIM_INT__f_s_f_s[n * 100 + 25] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 17], PRIM_INT__f_s_f_s[n * 100 + 25]);
                        PRIM_INT__f_s_f_s[n * 100 + 25] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 17], PRIM_INT__f_s_f_s[n * 100 + 25]);

                        PRIM_INT__f_s_f_s[n * 100 + 26] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 15]);
                        PRIM_INT__f_s_f_s[n * 100 + 26] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 15], PRIM_INT__f_s_f_s[n * 100 + 26]);
                        PRIM_INT__f_s_f_s[n * 100 + 26] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 7], PRIM_INT__f_s_p_s[n * 30 + 7]), PRIM_INT__f_s_f_s[n * 100 + 26]);

                        PRIM_INT__f_s_f_s[n * 100 + 27] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 15]);
                        PRIM_INT__f_s_f_s[n * 100 + 27] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 15], PRIM_INT__f_s_f_s[n * 100 + 27]);
                        PRIM_INT__f_s_f_s[n * 100 + 27] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 3], PRIM_INT__f_s_f_s[n * 100 + 27]);

                        PRIM_INT__f_s_f_s[n * 100 + 28] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 17]);
                        PRIM_INT__f_s_f_s[n * 100 + 28] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 17], PRIM_INT__f_s_f_s[n * 100 + 28]);

                        PRIM_INT__f_s_f_s[n * 100 + 29] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 17]);
                        PRIM_INT__f_s_f_s[n * 100 + 29] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 17], PRIM_INT__f_s_f_s[n * 100 + 29]);
                        PRIM_INT__f_s_f_s[n * 100 + 29] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 8], PRIM_INT__f_s_p_s[n * 30 + 8]), PRIM_INT__f_s_f_s[n * 100 + 29]);
                        PRIM_INT__f_s_f_s[n * 100 + 29] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 5], PRIM_INT__f_s_f_s[n * 100 + 29]);

                        PRIM_INT__f_s_f_s[n * 100 + 30] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 18]);
                        PRIM_INT__f_s_f_s[n * 100 + 30] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 18], PRIM_INT__f_s_f_s[n * 100 + 30]);
                        PRIM_INT__f_s_f_s[n * 100 + 30] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 9], PRIM_INT__f_s_p_s[n * 30 + 9]), PRIM_INT__f_s_f_s[n * 100 + 30]);
                        PRIM_INT__f_s_f_s[n * 100 + 30] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 18], PRIM_INT__f_s_f_s[n * 100 + 30]);

                        PRIM_INT__f_s_f_s[n * 100 + 31] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 18]);
                        PRIM_INT__f_s_f_s[n * 100 + 31] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 18], PRIM_INT__f_s_f_s[n * 100 + 31]);
                        PRIM_INT__f_s_f_s[n * 100 + 31] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 6], PRIM_INT__f_s_f_s[n * 100 + 31]);

                        PRIM_INT__f_s_f_s[n * 100 + 32] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 18]);
                        PRIM_INT__f_s_f_s[n * 100 + 32] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 18], PRIM_INT__f_s_f_s[n * 100 + 32]);

                        PRIM_INT__f_s_f_s[n * 100 + 33] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 21]);
                        PRIM_INT__f_s_f_s[n * 100 + 33] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 21], PRIM_INT__f_s_f_s[n * 100 + 33]);
                        PRIM_INT__f_s_f_s[n * 100 + 33] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 21], PRIM_INT__f_s_f_s[n * 100 + 33]);

                        PRIM_INT__f_s_f_s[n * 100 + 34] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 19]);
                        PRIM_INT__f_s_f_s[n * 100 + 34] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 19], PRIM_INT__f_s_f_s[n * 100 + 34]);

                        PRIM_INT__f_s_f_s[n * 100 + 35] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 23]);
                        PRIM_INT__f_s_f_s[n * 100 + 35] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 23], PRIM_INT__f_s_f_s[n * 100 + 35]);
                        PRIM_INT__f_s_f_s[n * 100 + 35] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 23], PRIM_INT__f_s_f_s[n * 100 + 35]);

                        PRIM_INT__f_s_f_s[n * 100 + 36] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 21]);
                        PRIM_INT__f_s_f_s[n * 100 + 36] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 21], PRIM_INT__f_s_f_s[n * 100 + 36]);
                        PRIM_INT__f_s_f_s[n * 100 + 36] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 10], PRIM_INT__f_s_p_s[n * 30 + 10]), PRIM_INT__f_s_f_s[n * 100 + 36]);
                        PRIM_INT__f_s_f_s[n * 100 + 36] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 9], PRIM_INT__f_s_f_s[n * 100 + 36]);

                        PRIM_INT__f_s_f_s[n * 100 + 37] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 21]);
                        PRIM_INT__f_s_f_s[n * 100 + 37] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 21], PRIM_INT__f_s_f_s[n * 100 + 37]);

                        PRIM_INT__f_s_f_s[n * 100 + 38] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 23]);
                        PRIM_INT__f_s_f_s[n * 100 + 38] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 23], PRIM_INT__f_s_f_s[n * 100 + 38]);
                        PRIM_INT__f_s_f_s[n * 100 + 38] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 11], PRIM_INT__f_s_f_s[n * 100 + 38]);

                        PRIM_INT__f_s_f_s[n * 100 + 39] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 23]);
                        PRIM_INT__f_s_f_s[n * 100 + 39] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 23], PRIM_INT__f_s_f_s[n * 100 + 39]);
                        PRIM_INT__f_s_f_s[n * 100 + 39] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 11], PRIM_INT__f_s_p_s[n * 30 + 11]), PRIM_INT__f_s_f_s[n * 100 + 39]);

                        PRIM_INT__f_s_f_s[n * 100 + 40] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 24]);
                        PRIM_INT__f_s_f_s[n * 100 + 40] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 24], PRIM_INT__f_s_f_s[n * 100 + 40]);
                        PRIM_INT__f_s_f_s[n * 100 + 40] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 12], PRIM_INT__f_s_p_s[n * 30 + 12]), PRIM_INT__f_s_f_s[n * 100 + 40]);
                        PRIM_INT__f_s_f_s[n * 100 + 40] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 24], PRIM_INT__f_s_f_s[n * 100 + 40]);

                        PRIM_INT__f_s_f_s[n * 100 + 41] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 24]);
                        PRIM_INT__f_s_f_s[n * 100 + 41] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 24], PRIM_INT__f_s_f_s[n * 100 + 41]);
                        PRIM_INT__f_s_f_s[n * 100 + 41] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 12], PRIM_INT__f_s_f_s[n * 100 + 41]);

                        PRIM_INT__f_s_f_s[n * 100 + 42] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 24]);
                        PRIM_INT__f_s_f_s[n * 100 + 42] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 24], PRIM_INT__f_s_f_s[n * 100 + 42]);
                        PRIM_INT__f_s_f_s[n * 100 + 42] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 6], PRIM_INT__f_s_f_s[n * 100 + 42]);

                        PRIM_INT__f_s_f_s[n * 100 + 43] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 27]);
                        PRIM_INT__f_s_f_s[n * 100 + 43] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 27], PRIM_INT__f_s_f_s[n * 100 + 43]);
                        PRIM_INT__f_s_f_s[n * 100 + 43] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 27], PRIM_INT__f_s_f_s[n * 100 + 43]);

                        PRIM_INT__f_s_f_s[n * 100 + 44] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 25]);
                        PRIM_INT__f_s_f_s[n * 100 + 44] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 25], PRIM_INT__f_s_f_s[n * 100 + 44]);
                        PRIM_INT__f_s_f_s[n * 100 + 44] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 7], PRIM_INT__f_s_f_s[n * 100 + 44]);

                        PRIM_INT__f_s_f_s[n * 100 + 45] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 29]);
                        PRIM_INT__f_s_f_s[n * 100 + 45] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 29], PRIM_INT__f_s_f_s[n * 100 + 45]);
                        PRIM_INT__f_s_f_s[n * 100 + 45] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 29], PRIM_INT__f_s_f_s[n * 100 + 45]);

                        PRIM_INT__f_s_f_s[n * 100 + 46] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 27]);
                        PRIM_INT__f_s_f_s[n * 100 + 46] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 27], PRIM_INT__f_s_f_s[n * 100 + 46]);
                        PRIM_INT__f_s_f_s[n * 100 + 46] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 13], PRIM_INT__f_s_p_s[n * 30 + 13]), PRIM_INT__f_s_f_s[n * 100 + 46]);
                        PRIM_INT__f_s_f_s[n * 100 + 46] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 15], PRIM_INT__f_s_f_s[n * 100 + 46]);

                        PRIM_INT__f_s_f_s[n * 100 + 47] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 27]);
                        PRIM_INT__f_s_f_s[n * 100 + 47] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 27], PRIM_INT__f_s_f_s[n * 100 + 47]);
                        PRIM_INT__f_s_f_s[n * 100 + 47] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 9], PRIM_INT__f_s_f_s[n * 100 + 47]);

                        PRIM_INT__f_s_f_s[n * 100 + 48] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 29]);
                        PRIM_INT__f_s_f_s[n * 100 + 48] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 29], PRIM_INT__f_s_f_s[n * 100 + 48]);
                        PRIM_INT__f_s_f_s[n * 100 + 48] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 17], PRIM_INT__f_s_f_s[n * 100 + 48]);

                        PRIM_INT__f_s_f_s[n * 100 + 49] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 29]);
                        PRIM_INT__f_s_f_s[n * 100 + 49] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 29], PRIM_INT__f_s_f_s[n * 100 + 49]);
                        PRIM_INT__f_s_f_s[n * 100 + 49] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 14], PRIM_INT__f_s_p_s[n * 30 + 14]), PRIM_INT__f_s_f_s[n * 100 + 49]);
                        PRIM_INT__f_s_f_s[n * 100 + 49] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 11], PRIM_INT__f_s_f_s[n * 100 + 49]);

                        PRIM_INT__f_s_f_s[n * 100 + 50] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 30]);
                        PRIM_INT__f_s_f_s[n * 100 + 50] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 30], PRIM_INT__f_s_f_s[n * 100 + 50]);
                        PRIM_INT__f_s_f_s[n * 100 + 50] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 15], PRIM_INT__f_s_p_s[n * 30 + 15]), PRIM_INT__f_s_f_s[n * 100 + 50]);
                        PRIM_INT__f_s_f_s[n * 100 + 50] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 30], PRIM_INT__f_s_f_s[n * 100 + 50]);

                        PRIM_INT__f_s_f_s[n * 100 + 51] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 30]);
                        PRIM_INT__f_s_f_s[n * 100 + 51] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 30], PRIM_INT__f_s_f_s[n * 100 + 51]);

                        PRIM_INT__f_s_f_s[n * 100 + 52] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 30]);
                        PRIM_INT__f_s_f_s[n * 100 + 52] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 30], PRIM_INT__f_s_f_s[n * 100 + 52]);
                        PRIM_INT__f_s_f_s[n * 100 + 52] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 12], PRIM_INT__f_s_f_s[n * 100 + 52]);

                        PRIM_INT__f_s_f_s[n * 100 + 53] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 33]);
                        PRIM_INT__f_s_f_s[n * 100 + 53] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 33], PRIM_INT__f_s_f_s[n * 100 + 53]);
                        PRIM_INT__f_s_f_s[n * 100 + 53] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 33], PRIM_INT__f_s_f_s[n * 100 + 53]);

                        PRIM_INT__f_s_f_s[n * 100 + 54] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 31]);
                        PRIM_INT__f_s_f_s[n * 100 + 54] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 31], PRIM_INT__f_s_f_s[n * 100 + 54]);
                        PRIM_INT__f_s_f_s[n * 100 + 54] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 13], PRIM_INT__f_s_f_s[n * 100 + 54]);

                        PRIM_INT__f_s_f_s[n * 100 + 55] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 35]);
                        PRIM_INT__f_s_f_s[n * 100 + 55] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 35], PRIM_INT__f_s_f_s[n * 100 + 55]);
                        PRIM_INT__f_s_f_s[n * 100 + 55] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 35], PRIM_INT__f_s_f_s[n * 100 + 55]);

                        PRIM_INT__f_s_f_s[n * 100 + 56] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 33]);
                        PRIM_INT__f_s_f_s[n * 100 + 56] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 33], PRIM_INT__f_s_f_s[n * 100 + 56]);
                        PRIM_INT__f_s_f_s[n * 100 + 56] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 16], PRIM_INT__f_s_p_s[n * 30 + 16]), PRIM_INT__f_s_f_s[n * 100 + 56]);

                        PRIM_INT__f_s_f_s[n * 100 + 57] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 33]);
                        PRIM_INT__f_s_f_s[n * 100 + 57] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 33], PRIM_INT__f_s_f_s[n * 100 + 57]);
                        PRIM_INT__f_s_f_s[n * 100 + 57] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 15], PRIM_INT__f_s_f_s[n * 100 + 57]);

                        PRIM_INT__f_s_f_s[n * 100 + 58] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 35]);
                        PRIM_INT__f_s_f_s[n * 100 + 58] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 35], PRIM_INT__f_s_f_s[n * 100 + 58]);

                        PRIM_INT__f_s_f_s[n * 100 + 59] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 35]);
                        PRIM_INT__f_s_f_s[n * 100 + 59] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 35], PRIM_INT__f_s_f_s[n * 100 + 59]);
                        PRIM_INT__f_s_f_s[n * 100 + 59] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 17], PRIM_INT__f_s_p_s[n * 30 + 17]), PRIM_INT__f_s_f_s[n * 100 + 59]);
                        PRIM_INT__f_s_f_s[n * 100 + 59] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 17], PRIM_INT__f_s_f_s[n * 100 + 59]);

                        PRIM_INT__f_s_f_s[n * 100 + 60] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 36]);
                        PRIM_INT__f_s_f_s[n * 100 + 60] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 36], PRIM_INT__f_s_f_s[n * 100 + 60]);
                        PRIM_INT__f_s_f_s[n * 100 + 60] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 18], PRIM_INT__f_s_p_s[n * 30 + 18]), PRIM_INT__f_s_f_s[n * 100 + 60]);

                        PRIM_INT__f_s_f_s[n * 100 + 61] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 36]);
                        PRIM_INT__f_s_f_s[n * 100 + 61] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 36], PRIM_INT__f_s_f_s[n * 100 + 61]);
                        PRIM_INT__f_s_f_s[n * 100 + 61] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 18], PRIM_INT__f_s_f_s[n * 100 + 61]);

                        PRIM_INT__f_s_f_s[n * 100 + 62] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 36]);
                        PRIM_INT__f_s_f_s[n * 100 + 62] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 36], PRIM_INT__f_s_f_s[n * 100 + 62]);

                        PRIM_INT__f_s_f_s[n * 100 + 63] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 39]);
                        PRIM_INT__f_s_f_s[n * 100 + 63] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 39], PRIM_INT__f_s_f_s[n * 100 + 63]);

                        PRIM_INT__f_s_f_s[n * 100 + 64] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 37]);
                        PRIM_INT__f_s_f_s[n * 100 + 64] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 37], PRIM_INT__f_s_f_s[n * 100 + 64]);

                        PRIM_INT__f_s_f_s[n * 100 + 65] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 41]);
                        PRIM_INT__f_s_f_s[n * 100 + 65] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 41], PRIM_INT__f_s_f_s[n * 100 + 65]);

                        PRIM_INT__f_s_f_s[n * 100 + 66] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 39]);
                        PRIM_INT__f_s_f_s[n * 100 + 66] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 39], PRIM_INT__f_s_f_s[n * 100 + 66]);
                        PRIM_INT__f_s_f_s[n * 100 + 66] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 19], PRIM_INT__f_s_p_s[n * 30 + 19]), PRIM_INT__f_s_f_s[n * 100 + 66]);
                        PRIM_INT__f_s_f_s[n * 100 + 66] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 21], PRIM_INT__f_s_f_s[n * 100 + 66]);

                        PRIM_INT__f_s_f_s[n * 100 + 67] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 39]);
                        PRIM_INT__f_s_f_s[n * 100 + 67] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 39], PRIM_INT__f_s_f_s[n * 100 + 67]);

                        PRIM_INT__f_s_f_s[n * 100 + 68] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 41]);
                        PRIM_INT__f_s_f_s[n * 100 + 68] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 41], PRIM_INT__f_s_f_s[n * 100 + 68]);
                        PRIM_INT__f_s_f_s[n * 100 + 68] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 23], PRIM_INT__f_s_f_s[n * 100 + 68]);

                        PRIM_INT__f_s_f_s[n * 100 + 69] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 41]);
                        PRIM_INT__f_s_f_s[n * 100 + 69] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 41], PRIM_INT__f_s_f_s[n * 100 + 69]);
                        PRIM_INT__f_s_f_s[n * 100 + 69] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 20], PRIM_INT__f_s_p_s[n * 30 + 20]), PRIM_INT__f_s_f_s[n * 100 + 69]);

                        PRIM_INT__f_s_f_s[n * 100 + 70] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 42]);
                        PRIM_INT__f_s_f_s[n * 100 + 70] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 42], PRIM_INT__f_s_f_s[n * 100 + 70]);
                        PRIM_INT__f_s_f_s[n * 100 + 70] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 21], PRIM_INT__f_s_p_s[n * 30 + 21]), PRIM_INT__f_s_f_s[n * 100 + 70]);

                        PRIM_INT__f_s_f_s[n * 100 + 71] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 42]);
                        PRIM_INT__f_s_f_s[n * 100 + 71] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 42], PRIM_INT__f_s_f_s[n * 100 + 71]);
                        PRIM_INT__f_s_f_s[n * 100 + 71] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 24], PRIM_INT__f_s_f_s[n * 100 + 71]);

                        PRIM_INT__f_s_f_s[n * 100 + 72] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 42]);
                        PRIM_INT__f_s_f_s[n * 100 + 72] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 42], PRIM_INT__f_s_f_s[n * 100 + 72]);
                        PRIM_INT__f_s_f_s[n * 100 + 72] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 18], PRIM_INT__f_s_f_s[n * 100 + 72]);

                        PRIM_INT__f_s_f_s[n * 100 + 73] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 45]);
                        PRIM_INT__f_s_f_s[n * 100 + 73] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 45], PRIM_INT__f_s_f_s[n * 100 + 73]);

                        PRIM_INT__f_s_f_s[n * 100 + 74] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 43]);
                        PRIM_INT__f_s_f_s[n * 100 + 74] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 43], PRIM_INT__f_s_f_s[n * 100 + 74]);
                        PRIM_INT__f_s_f_s[n * 100 + 74] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 19], PRIM_INT__f_s_f_s[n * 100 + 74]);

                        PRIM_INT__f_s_f_s[n * 100 + 75] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 47]);
                        PRIM_INT__f_s_f_s[n * 100 + 75] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 47], PRIM_INT__f_s_f_s[n * 100 + 75]);

                        PRIM_INT__f_s_f_s[n * 100 + 76] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 45]);
                        PRIM_INT__f_s_f_s[n * 100 + 76] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 45], PRIM_INT__f_s_f_s[n * 100 + 76]);
                        PRIM_INT__f_s_f_s[n * 100 + 76] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 22], PRIM_INT__f_s_p_s[n * 30 + 22]), PRIM_INT__f_s_f_s[n * 100 + 76]);
                        PRIM_INT__f_s_f_s[n * 100 + 76] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 27], PRIM_INT__f_s_f_s[n * 100 + 76]);

                        PRIM_INT__f_s_f_s[n * 100 + 77] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 45]);
                        PRIM_INT__f_s_f_s[n * 100 + 77] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 45], PRIM_INT__f_s_f_s[n * 100 + 77]);
                        PRIM_INT__f_s_f_s[n * 100 + 77] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 21], PRIM_INT__f_s_f_s[n * 100 + 77]);

                        PRIM_INT__f_s_f_s[n * 100 + 78] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 47]);
                        PRIM_INT__f_s_f_s[n * 100 + 78] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 47], PRIM_INT__f_s_f_s[n * 100 + 78]);
                        PRIM_INT__f_s_f_s[n * 100 + 78] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 29], PRIM_INT__f_s_f_s[n * 100 + 78]);

                        PRIM_INT__f_s_f_s[n * 100 + 79] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 47]);
                        PRIM_INT__f_s_f_s[n * 100 + 79] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 47], PRIM_INT__f_s_f_s[n * 100 + 79]);
                        PRIM_INT__f_s_f_s[n * 100 + 79] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 23], PRIM_INT__f_s_p_s[n * 30 + 23]), PRIM_INT__f_s_f_s[n * 100 + 79]);
                        PRIM_INT__f_s_f_s[n * 100 + 79] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 23], PRIM_INT__f_s_f_s[n * 100 + 79]);

                        PRIM_INT__f_s_f_s[n * 100 + 80] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 48]);
                        PRIM_INT__f_s_f_s[n * 100 + 80] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 48], PRIM_INT__f_s_f_s[n * 100 + 80]);
                        PRIM_INT__f_s_f_s[n * 100 + 80] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 24], PRIM_INT__f_s_p_s[n * 30 + 24]), PRIM_INT__f_s_f_s[n * 100 + 80]);

                        PRIM_INT__f_s_f_s[n * 100 + 81] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 48]);
                        PRIM_INT__f_s_f_s[n * 100 + 81] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 48], PRIM_INT__f_s_f_s[n * 100 + 81]);
                        PRIM_INT__f_s_f_s[n * 100 + 81] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 30], PRIM_INT__f_s_f_s[n * 100 + 81]);

                        PRIM_INT__f_s_f_s[n * 100 + 82] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 48]);
                        PRIM_INT__f_s_f_s[n * 100 + 82] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 48], PRIM_INT__f_s_f_s[n * 100 + 82]);
                        PRIM_INT__f_s_f_s[n * 100 + 82] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 24], PRIM_INT__f_s_f_s[n * 100 + 82]);

                        PRIM_INT__f_s_f_s[n * 100 + 83] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 51]);
                        PRIM_INT__f_s_f_s[n * 100 + 83] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 51], PRIM_INT__f_s_f_s[n * 100 + 83]);

                        PRIM_INT__f_s_f_s[n * 100 + 84] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 49]);
                        PRIM_INT__f_s_f_s[n * 100 + 84] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 49], PRIM_INT__f_s_f_s[n * 100 + 84]);
                        PRIM_INT__f_s_f_s[n * 100 + 84] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 25], PRIM_INT__f_s_f_s[n * 100 + 84]);

                        PRIM_INT__f_s_f_s[n * 100 + 85] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 53]);
                        PRIM_INT__f_s_f_s[n * 100 + 85] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 53], PRIM_INT__f_s_f_s[n * 100 + 85]);

                        PRIM_INT__f_s_f_s[n * 100 + 86] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 51]);
                        PRIM_INT__f_s_f_s[n * 100 + 86] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 51], PRIM_INT__f_s_f_s[n * 100 + 86]);
                        PRIM_INT__f_s_f_s[n * 100 + 86] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 25], PRIM_INT__f_s_p_s[n * 30 + 25]), PRIM_INT__f_s_f_s[n * 100 + 86]);
                        PRIM_INT__f_s_f_s[n * 100 + 86] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 33], PRIM_INT__f_s_f_s[n * 100 + 86]);

                        PRIM_INT__f_s_f_s[n * 100 + 87] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 51]);
                        PRIM_INT__f_s_f_s[n * 100 + 87] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 51], PRIM_INT__f_s_f_s[n * 100 + 87]);
                        PRIM_INT__f_s_f_s[n * 100 + 87] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 27], PRIM_INT__f_s_f_s[n * 100 + 87]);

                        PRIM_INT__f_s_f_s[n * 100 + 88] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 53]);
                        PRIM_INT__f_s_f_s[n * 100 + 88] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 53], PRIM_INT__f_s_f_s[n * 100 + 88]);
                        PRIM_INT__f_s_f_s[n * 100 + 88] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 35], PRIM_INT__f_s_f_s[n * 100 + 88]);

                        PRIM_INT__f_s_f_s[n * 100 + 89] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 53]);
                        PRIM_INT__f_s_f_s[n * 100 + 89] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 53], PRIM_INT__f_s_f_s[n * 100 + 89]);
                        PRIM_INT__f_s_f_s[n * 100 + 89] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 26], PRIM_INT__f_s_p_s[n * 30 + 26]), PRIM_INT__f_s_f_s[n * 100 + 89]);
                        PRIM_INT__f_s_f_s[n * 100 + 89] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 29], PRIM_INT__f_s_f_s[n * 100 + 89]);

                        PRIM_INT__f_s_f_s[n * 100 + 90] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 54]);
                        PRIM_INT__f_s_f_s[n * 100 + 90] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 54], PRIM_INT__f_s_f_s[n * 100 + 90]);
                        PRIM_INT__f_s_f_s[n * 100 + 90] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 27], PRIM_INT__f_s_p_s[n * 30 + 27]), PRIM_INT__f_s_f_s[n * 100 + 90]);

                        PRIM_INT__f_s_f_s[n * 100 + 91] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 54]);
                        PRIM_INT__f_s_f_s[n * 100 + 91] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 54], PRIM_INT__f_s_f_s[n * 100 + 91]);

                        PRIM_INT__f_s_f_s[n * 100 + 92] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 54]);
                        PRIM_INT__f_s_f_s[n * 100 + 92] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 54], PRIM_INT__f_s_f_s[n * 100 + 92]);
                        PRIM_INT__f_s_f_s[n * 100 + 92] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 30], PRIM_INT__f_s_f_s[n * 100 + 92]);

                        PRIM_INT__f_s_f_s[n * 100 + 93] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 57]);
                        PRIM_INT__f_s_f_s[n * 100 + 93] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 57], PRIM_INT__f_s_f_s[n * 100 + 93]);

                        PRIM_INT__f_s_f_s[n * 100 + 94] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 55]);
                        PRIM_INT__f_s_f_s[n * 100 + 94] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 55], PRIM_INT__f_s_f_s[n * 100 + 94]);
                        PRIM_INT__f_s_f_s[n * 100 + 94] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 31], PRIM_INT__f_s_f_s[n * 100 + 94]);

                        PRIM_INT__f_s_f_s[n * 100 + 95] = SIMINT_MUL(Q_PA[0], PRIM_INT__f_s_d_s[n * 60 + 59]);
                        PRIM_INT__f_s_f_s[n * 100 + 95] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__f_s_d_s[(n+1) * 60 + 59], PRIM_INT__f_s_f_s[n * 100 + 95]);

                        PRIM_INT__f_s_f_s[n * 100 + 96] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 57]);
                        PRIM_INT__f_s_f_s[n * 100 + 96] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 57], PRIM_INT__f_s_f_s[n * 100 + 96]);
                        PRIM_INT__f_s_f_s[n * 100 + 96] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 28], PRIM_INT__f_s_p_s[n * 30 + 28]), PRIM_INT__f_s_f_s[n * 100 + 96]);

                        PRIM_INT__f_s_f_s[n * 100 + 97] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 57]);
                        PRIM_INT__f_s_f_s[n * 100 + 97] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 57], PRIM_INT__f_s_f_s[n * 100 + 97]);
                        PRIM_INT__f_s_f_s[n * 100 + 97] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 33], PRIM_INT__f_s_f_s[n * 100 + 97]);

                        PRIM_INT__f_s_f_s[n * 100 + 98] = SIMINT_MUL(Q_PA[1], PRIM_INT__f_s_d_s[n * 60 + 59]);
                        PRIM_INT__f_s_f_s[n * 100 + 98] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__f_s_d_s[(n+1) * 60 + 59], PRIM_INT__f_s_f_s[n * 100 + 98]);

                        PRIM_INT__f_s_f_s[n * 100 + 99] = SIMINT_MUL(Q_PA[2], PRIM_INT__f_s_d_s[n * 60 + 59]);
                        PRIM_INT__f_s_f_s[n * 100 + 99] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__f_s_d_s[(n+1) * 60 + 59], PRIM_INT__f_s_f_s[n * 100 + 99]);
                        PRIM_INT__f_s_f_s[n * 100 + 99] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__f_s_p_s[(n+1) * 30 + 29], PRIM_INT__f_s_p_s[n * 30 + 29]), PRIM_INT__f_s_f_s[n * 100 + 99]);
                        PRIM_INT__f_s_f_s[n * 100 + 99] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__d_s_d_s[(n+1) * 36 + 35], PRIM_INT__f_s_f_s[n * 100 + 99]);

                    }

}


