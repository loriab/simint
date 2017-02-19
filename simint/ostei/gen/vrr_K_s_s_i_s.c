
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s s | i s )
//////////////////////////////////////////////
void VRR_K_s_s_i_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_i_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n)
{
    int n = 0;
    const SIMINT_DBLTYPE vrr_const_1_over_2q = SIMINT_MUL(SIMINT_DBLSET1(1), one_over_2q);
    const SIMINT_DBLTYPE vrr_const_2_over_2q = SIMINT_MUL(SIMINT_DBLSET1(2), one_over_2q);
    const SIMINT_DBLTYPE vrr_const_5_over_2q = SIMINT_MUL(SIMINT_DBLSET1(5), one_over_2q);

                    // Forming PRIM_INT__s_s_i_s[num_n * 28];
                    for(n = 0; n < num_n; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_i_s[n * 28 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_h_s[n * 21 + 0]);
                        PRIM_INT__s_s_i_s[n * 28 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_h_s[(n+1) * 21 + 0], PRIM_INT__s_s_i_s[n * 28 + 0]);
                        PRIM_INT__s_s_i_s[n * 28 + 0] = SIMINT_FMADD( vrr_const_5_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 0], PRIM_INT__s_s_g_s[n * 15 + 0]), PRIM_INT__s_s_i_s[n * 28 + 0]);

                        PRIM_INT__s_s_i_s[n * 28 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_h_s[n * 21 + 0]);
                        PRIM_INT__s_s_i_s[n * 28 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_h_s[(n+1) * 21 + 0], PRIM_INT__s_s_i_s[n * 28 + 1]);

                        PRIM_INT__s_s_i_s[n * 28 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_h_s[n * 21 + 0]);
                        PRIM_INT__s_s_i_s[n * 28 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_h_s[(n+1) * 21 + 0], PRIM_INT__s_s_i_s[n * 28 + 2]);

                        PRIM_INT__s_s_i_s[n * 28 + 3] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_h_s[n * 21 + 1]);
                        PRIM_INT__s_s_i_s[n * 28 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_h_s[(n+1) * 21 + 1], PRIM_INT__s_s_i_s[n * 28 + 3]);
                        PRIM_INT__s_s_i_s[n * 28 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 0], PRIM_INT__s_s_g_s[n * 15 + 0]), PRIM_INT__s_s_i_s[n * 28 + 3]);

                        PRIM_INT__s_s_i_s[n * 28 + 4] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_h_s[n * 21 + 1]);
                        PRIM_INT__s_s_i_s[n * 28 + 4] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_h_s[(n+1) * 21 + 1], PRIM_INT__s_s_i_s[n * 28 + 4]);

                        PRIM_INT__s_s_i_s[n * 28 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_h_s[n * 21 + 2]);
                        PRIM_INT__s_s_i_s[n * 28 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_h_s[(n+1) * 21 + 2], PRIM_INT__s_s_i_s[n * 28 + 5]);
                        PRIM_INT__s_s_i_s[n * 28 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 0], PRIM_INT__s_s_g_s[n * 15 + 0]), PRIM_INT__s_s_i_s[n * 28 + 5]);

                        PRIM_INT__s_s_i_s[n * 28 + 6] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_h_s[n * 21 + 3]);
                        PRIM_INT__s_s_i_s[n * 28 + 6] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_h_s[(n+1) * 21 + 3], PRIM_INT__s_s_i_s[n * 28 + 6]);
                        PRIM_INT__s_s_i_s[n * 28 + 6] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 1], PRIM_INT__s_s_g_s[n * 15 + 1]), PRIM_INT__s_s_i_s[n * 28 + 6]);

                        PRIM_INT__s_s_i_s[n * 28 + 7] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_h_s[n * 21 + 3]);
                        PRIM_INT__s_s_i_s[n * 28 + 7] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_h_s[(n+1) * 21 + 3], PRIM_INT__s_s_i_s[n * 28 + 7]);

                        PRIM_INT__s_s_i_s[n * 28 + 8] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_h_s[n * 21 + 5]);
                        PRIM_INT__s_s_i_s[n * 28 + 8] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_h_s[(n+1) * 21 + 5], PRIM_INT__s_s_i_s[n * 28 + 8]);

                        PRIM_INT__s_s_i_s[n * 28 + 9] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_h_s[n * 21 + 5]);
                        PRIM_INT__s_s_i_s[n * 28 + 9] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_h_s[(n+1) * 21 + 5], PRIM_INT__s_s_i_s[n * 28 + 9]);
                        PRIM_INT__s_s_i_s[n * 28 + 9] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 2], PRIM_INT__s_s_g_s[n * 15 + 2]), PRIM_INT__s_s_i_s[n * 28 + 9]);

                        PRIM_INT__s_s_i_s[n * 28 + 10] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_h_s[n * 21 + 10]);
                        PRIM_INT__s_s_i_s[n * 28 + 10] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_h_s[(n+1) * 21 + 10], PRIM_INT__s_s_i_s[n * 28 + 10]);
                        PRIM_INT__s_s_i_s[n * 28 + 10] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 10], PRIM_INT__s_s_g_s[n * 15 + 10]), PRIM_INT__s_s_i_s[n * 28 + 10]);

                        PRIM_INT__s_s_i_s[n * 28 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_h_s[n * 21 + 6]);
                        PRIM_INT__s_s_i_s[n * 28 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_h_s[(n+1) * 21 + 6], PRIM_INT__s_s_i_s[n * 28 + 11]);

                        PRIM_INT__s_s_i_s[n * 28 + 12] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_h_s[n * 21 + 7]);
                        PRIM_INT__s_s_i_s[n * 28 + 12] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_h_s[(n+1) * 21 + 7], PRIM_INT__s_s_i_s[n * 28 + 12]);
                        PRIM_INT__s_s_i_s[n * 28 + 12] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 3], PRIM_INT__s_s_g_s[n * 15 + 3]), PRIM_INT__s_s_i_s[n * 28 + 12]);

                        PRIM_INT__s_s_i_s[n * 28 + 13] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_h_s[n * 21 + 9]);
                        PRIM_INT__s_s_i_s[n * 28 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_h_s[(n+1) * 21 + 9], PRIM_INT__s_s_i_s[n * 28 + 13]);

                        PRIM_INT__s_s_i_s[n * 28 + 14] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_h_s[n * 21 + 14]);
                        PRIM_INT__s_s_i_s[n * 28 + 14] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_h_s[(n+1) * 21 + 14], PRIM_INT__s_s_i_s[n * 28 + 14]);
                        PRIM_INT__s_s_i_s[n * 28 + 14] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 14], PRIM_INT__s_s_g_s[n * 15 + 14]), PRIM_INT__s_s_i_s[n * 28 + 14]);

                        PRIM_INT__s_s_i_s[n * 28 + 15] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_h_s[n * 21 + 15]);
                        PRIM_INT__s_s_i_s[n * 28 + 15] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_h_s[(n+1) * 21 + 15], PRIM_INT__s_s_i_s[n * 28 + 15]);

                        PRIM_INT__s_s_i_s[n * 28 + 16] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_h_s[n * 21 + 10]);
                        PRIM_INT__s_s_i_s[n * 28 + 16] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_h_s[(n+1) * 21 + 10], PRIM_INT__s_s_i_s[n * 28 + 16]);

                        PRIM_INT__s_s_i_s[n * 28 + 17] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_h_s[n * 21 + 17]);
                        PRIM_INT__s_s_i_s[n * 28 + 17] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_h_s[(n+1) * 21 + 17], PRIM_INT__s_s_i_s[n * 28 + 17]);

                        PRIM_INT__s_s_i_s[n * 28 + 18] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_h_s[n * 21 + 18]);
                        PRIM_INT__s_s_i_s[n * 28 + 18] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_h_s[(n+1) * 21 + 18], PRIM_INT__s_s_i_s[n * 28 + 18]);

                        PRIM_INT__s_s_i_s[n * 28 + 19] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_h_s[n * 21 + 14]);
                        PRIM_INT__s_s_i_s[n * 28 + 19] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_h_s[(n+1) * 21 + 14], PRIM_INT__s_s_i_s[n * 28 + 19]);

                        PRIM_INT__s_s_i_s[n * 28 + 20] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_h_s[n * 21 + 20]);
                        PRIM_INT__s_s_i_s[n * 28 + 20] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_h_s[(n+1) * 21 + 20], PRIM_INT__s_s_i_s[n * 28 + 20]);

                        PRIM_INT__s_s_i_s[n * 28 + 21] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_h_s[n * 21 + 15]);
                        PRIM_INT__s_s_i_s[n * 28 + 21] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_h_s[(n+1) * 21 + 15], PRIM_INT__s_s_i_s[n * 28 + 21]);
                        PRIM_INT__s_s_i_s[n * 28 + 21] = SIMINT_FMADD( vrr_const_5_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 10], PRIM_INT__s_s_g_s[n * 15 + 10]), PRIM_INT__s_s_i_s[n * 28 + 21]);

                        PRIM_INT__s_s_i_s[n * 28 + 22] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_h_s[n * 21 + 15]);
                        PRIM_INT__s_s_i_s[n * 28 + 22] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_h_s[(n+1) * 21 + 15], PRIM_INT__s_s_i_s[n * 28 + 22]);

                        PRIM_INT__s_s_i_s[n * 28 + 23] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_h_s[n * 21 + 16]);
                        PRIM_INT__s_s_i_s[n * 28 + 23] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_h_s[(n+1) * 21 + 16], PRIM_INT__s_s_i_s[n * 28 + 23]);
                        PRIM_INT__s_s_i_s[n * 28 + 23] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 10], PRIM_INT__s_s_g_s[n * 15 + 10]), PRIM_INT__s_s_i_s[n * 28 + 23]);

                        PRIM_INT__s_s_i_s[n * 28 + 24] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_h_s[n * 21 + 17]);
                        PRIM_INT__s_s_i_s[n * 28 + 24] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_h_s[(n+1) * 21 + 17], PRIM_INT__s_s_i_s[n * 28 + 24]);
                        PRIM_INT__s_s_i_s[n * 28 + 24] = SIMINT_FMADD( vrr_const_2_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 11], PRIM_INT__s_s_g_s[n * 15 + 11]), PRIM_INT__s_s_i_s[n * 28 + 24]);

                        PRIM_INT__s_s_i_s[n * 28 + 25] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_h_s[n * 21 + 19]);
                        PRIM_INT__s_s_i_s[n * 28 + 25] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_h_s[(n+1) * 21 + 19], PRIM_INT__s_s_i_s[n * 28 + 25]);
                        PRIM_INT__s_s_i_s[n * 28 + 25] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 14], PRIM_INT__s_s_g_s[n * 15 + 14]), PRIM_INT__s_s_i_s[n * 28 + 25]);

                        PRIM_INT__s_s_i_s[n * 28 + 26] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_h_s[n * 21 + 20]);
                        PRIM_INT__s_s_i_s[n * 28 + 26] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_h_s[(n+1) * 21 + 20], PRIM_INT__s_s_i_s[n * 28 + 26]);

                        PRIM_INT__s_s_i_s[n * 28 + 27] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_h_s[n * 21 + 20]);
                        PRIM_INT__s_s_i_s[n * 28 + 27] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_h_s[(n+1) * 21 + 20], PRIM_INT__s_s_i_s[n * 28 + 27]);
                        PRIM_INT__s_s_i_s[n * 28 + 27] = SIMINT_FMADD( vrr_const_5_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_g_s[(n+1) * 15 + 14], PRIM_INT__s_s_g_s[n * 15 + 14]), PRIM_INT__s_s_i_s[n * 28 + 27]);

                    }

}


