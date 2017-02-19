
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s s | h s )
//////////////////////////////////////////////
void VRR_K_s_s_h_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_f_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n)
{
    int n = 0;
    const SIMINT_DBLTYPE vrr_const_1_over_2q = SIMINT_MUL(SIMINT_DBLSET1(1), one_over_2q);
    const SIMINT_DBLTYPE vrr_const_4_over_2q = SIMINT_MUL(SIMINT_DBLSET1(4), one_over_2q);

                    // Forming PRIM_INT__s_s_h_s[num_n * 21];
                    for(n = 0; n < num_n; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__s_s_h_s[n * 21 + 0] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_g_s[n * 15 + 0]);
                        PRIM_INT__s_s_h_s[n * 21 + 0] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 0], PRIM_INT__s_s_h_s[n * 21 + 0]);
                        PRIM_INT__s_s_h_s[n * 21 + 0] = SIMINT_FMADD( vrr_const_4_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_f_s[(n+1) * 10 + 0], PRIM_INT__s_s_f_s[n * 10 + 0]), PRIM_INT__s_s_h_s[n * 21 + 0]);

                        PRIM_INT__s_s_h_s[n * 21 + 1] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_g_s[n * 15 + 0]);
                        PRIM_INT__s_s_h_s[n * 21 + 1] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 0], PRIM_INT__s_s_h_s[n * 21 + 1]);

                        PRIM_INT__s_s_h_s[n * 21 + 2] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_g_s[n * 15 + 0]);
                        PRIM_INT__s_s_h_s[n * 21 + 2] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 0], PRIM_INT__s_s_h_s[n * 21 + 2]);

                        PRIM_INT__s_s_h_s[n * 21 + 3] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_g_s[n * 15 + 1]);
                        PRIM_INT__s_s_h_s[n * 21 + 3] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 1], PRIM_INT__s_s_h_s[n * 21 + 3]);
                        PRIM_INT__s_s_h_s[n * 21 + 3] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_f_s[(n+1) * 10 + 0], PRIM_INT__s_s_f_s[n * 10 + 0]), PRIM_INT__s_s_h_s[n * 21 + 3]);

                        PRIM_INT__s_s_h_s[n * 21 + 4] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_g_s[n * 15 + 1]);
                        PRIM_INT__s_s_h_s[n * 21 + 4] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 1], PRIM_INT__s_s_h_s[n * 21 + 4]);

                        PRIM_INT__s_s_h_s[n * 21 + 5] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_g_s[n * 15 + 2]);
                        PRIM_INT__s_s_h_s[n * 21 + 5] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 2], PRIM_INT__s_s_h_s[n * 21 + 5]);
                        PRIM_INT__s_s_h_s[n * 21 + 5] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_f_s[(n+1) * 10 + 0], PRIM_INT__s_s_f_s[n * 10 + 0]), PRIM_INT__s_s_h_s[n * 21 + 5]);

                        PRIM_INT__s_s_h_s[n * 21 + 6] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_g_s[n * 15 + 6]);
                        PRIM_INT__s_s_h_s[n * 21 + 6] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 6], PRIM_INT__s_s_h_s[n * 21 + 6]);
                        PRIM_INT__s_s_h_s[n * 21 + 6] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_f_s[(n+1) * 10 + 6], PRIM_INT__s_s_f_s[n * 10 + 6]), PRIM_INT__s_s_h_s[n * 21 + 6]);

                        PRIM_INT__s_s_h_s[n * 21 + 7] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_g_s[n * 15 + 3]);
                        PRIM_INT__s_s_h_s[n * 21 + 7] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 3], PRIM_INT__s_s_h_s[n * 21 + 7]);

                        PRIM_INT__s_s_h_s[n * 21 + 8] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_g_s[n * 15 + 5]);
                        PRIM_INT__s_s_h_s[n * 21 + 8] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 5], PRIM_INT__s_s_h_s[n * 21 + 8]);

                        PRIM_INT__s_s_h_s[n * 21 + 9] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_g_s[n * 15 + 9]);
                        PRIM_INT__s_s_h_s[n * 21 + 9] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 9], PRIM_INT__s_s_h_s[n * 21 + 9]);
                        PRIM_INT__s_s_h_s[n * 21 + 9] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_f_s[(n+1) * 10 + 9], PRIM_INT__s_s_f_s[n * 10 + 9]), PRIM_INT__s_s_h_s[n * 21 + 9]);

                        PRIM_INT__s_s_h_s[n * 21 + 10] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_g_s[n * 15 + 10]);
                        PRIM_INT__s_s_h_s[n * 21 + 10] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 10], PRIM_INT__s_s_h_s[n * 21 + 10]);

                        PRIM_INT__s_s_h_s[n * 21 + 11] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_g_s[n * 15 + 6]);
                        PRIM_INT__s_s_h_s[n * 21 + 11] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 6], PRIM_INT__s_s_h_s[n * 21 + 11]);

                        PRIM_INT__s_s_h_s[n * 21 + 12] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_g_s[n * 15 + 12]);
                        PRIM_INT__s_s_h_s[n * 21 + 12] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 12], PRIM_INT__s_s_h_s[n * 21 + 12]);

                        PRIM_INT__s_s_h_s[n * 21 + 13] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_g_s[n * 15 + 9]);
                        PRIM_INT__s_s_h_s[n * 21 + 13] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 9], PRIM_INT__s_s_h_s[n * 21 + 13]);

                        PRIM_INT__s_s_h_s[n * 21 + 14] = SIMINT_MUL(Q_PA[0], PRIM_INT__s_s_g_s[n * 15 + 14]);
                        PRIM_INT__s_s_h_s[n * 21 + 14] = SIMINT_FMADD( aoq_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 14], PRIM_INT__s_s_h_s[n * 21 + 14]);

                        PRIM_INT__s_s_h_s[n * 21 + 15] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_g_s[n * 15 + 10]);
                        PRIM_INT__s_s_h_s[n * 21 + 15] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 10], PRIM_INT__s_s_h_s[n * 21 + 15]);
                        PRIM_INT__s_s_h_s[n * 21 + 15] = SIMINT_FMADD( vrr_const_4_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_f_s[(n+1) * 10 + 6], PRIM_INT__s_s_f_s[n * 10 + 6]), PRIM_INT__s_s_h_s[n * 21 + 15]);

                        PRIM_INT__s_s_h_s[n * 21 + 16] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_g_s[n * 15 + 10]);
                        PRIM_INT__s_s_h_s[n * 21 + 16] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 10], PRIM_INT__s_s_h_s[n * 21 + 16]);

                        PRIM_INT__s_s_h_s[n * 21 + 17] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_g_s[n * 15 + 11]);
                        PRIM_INT__s_s_h_s[n * 21 + 17] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 11], PRIM_INT__s_s_h_s[n * 21 + 17]);
                        PRIM_INT__s_s_h_s[n * 21 + 17] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_f_s[(n+1) * 10 + 6], PRIM_INT__s_s_f_s[n * 10 + 6]), PRIM_INT__s_s_h_s[n * 21 + 17]);

                        PRIM_INT__s_s_h_s[n * 21 + 18] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_g_s[n * 15 + 13]);
                        PRIM_INT__s_s_h_s[n * 21 + 18] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 13], PRIM_INT__s_s_h_s[n * 21 + 18]);
                        PRIM_INT__s_s_h_s[n * 21 + 18] = SIMINT_FMADD( vrr_const_1_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_f_s[(n+1) * 10 + 9], PRIM_INT__s_s_f_s[n * 10 + 9]), PRIM_INT__s_s_h_s[n * 21 + 18]);

                        PRIM_INT__s_s_h_s[n * 21 + 19] = SIMINT_MUL(Q_PA[1], PRIM_INT__s_s_g_s[n * 15 + 14]);
                        PRIM_INT__s_s_h_s[n * 21 + 19] = SIMINT_FMADD( aoq_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 14], PRIM_INT__s_s_h_s[n * 21 + 19]);

                        PRIM_INT__s_s_h_s[n * 21 + 20] = SIMINT_MUL(Q_PA[2], PRIM_INT__s_s_g_s[n * 15 + 14]);
                        PRIM_INT__s_s_h_s[n * 21 + 20] = SIMINT_FMADD( aoq_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 14], PRIM_INT__s_s_h_s[n * 21 + 20]);
                        PRIM_INT__s_s_h_s[n * 21 + 20] = SIMINT_FMADD( vrr_const_4_over_2q, SIMINT_FMADD(a_over_q, PRIM_INT__s_s_f_s[(n+1) * 10 + 9], PRIM_INT__s_s_f_s[n * 10 + 9]), PRIM_INT__s_s_h_s[n * 21 + 20]);

                    }

}


