
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( p s | g s )
//////////////////////////////////////////////
void VRR_I_p_s_g_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_f_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n)
{
    int n = 0;
    const SIMINT_DBLTYPE vrr_const_1_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(1), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_2_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(2), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_3_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(3), one_over_2pq);
    const SIMINT_DBLTYPE vrr_const_4_over_2pq = SIMINT_MUL(SIMINT_DBLSET1(4), one_over_2pq);

                    // Forming PRIM_INT__p_s_g_s[num_n * 45];
                    for(n = 0; n < num_n; ++n)  // loop over orders of auxiliary function
                    {

                        PRIM_INT__p_s_g_s[n * 45 + 0] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 0]);
                        PRIM_INT__p_s_g_s[n * 45 + 0] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 0], PRIM_INT__p_s_g_s[n * 45 + 0]);
                        PRIM_INT__p_s_g_s[n * 45 + 0] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 0], PRIM_INT__p_s_g_s[n * 45 + 0]);

                        PRIM_INT__p_s_g_s[n * 45 + 1] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 1]);
                        PRIM_INT__p_s_g_s[n * 45 + 1] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 1], PRIM_INT__p_s_g_s[n * 45 + 1]);
                        PRIM_INT__p_s_g_s[n * 45 + 1] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 1], PRIM_INT__p_s_g_s[n * 45 + 1]);

                        PRIM_INT__p_s_g_s[n * 45 + 2] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 2]);
                        PRIM_INT__p_s_g_s[n * 45 + 2] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 2], PRIM_INT__p_s_g_s[n * 45 + 2]);
                        PRIM_INT__p_s_g_s[n * 45 + 2] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 2], PRIM_INT__p_s_g_s[n * 45 + 2]);

                        PRIM_INT__p_s_g_s[n * 45 + 3] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 3]);
                        PRIM_INT__p_s_g_s[n * 45 + 3] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 3], PRIM_INT__p_s_g_s[n * 45 + 3]);
                        PRIM_INT__p_s_g_s[n * 45 + 3] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 3], PRIM_INT__p_s_g_s[n * 45 + 3]);

                        PRIM_INT__p_s_g_s[n * 45 + 4] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 4]);
                        PRIM_INT__p_s_g_s[n * 45 + 4] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 4], PRIM_INT__p_s_g_s[n * 45 + 4]);
                        PRIM_INT__p_s_g_s[n * 45 + 4] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 4], PRIM_INT__p_s_g_s[n * 45 + 4]);

                        PRIM_INT__p_s_g_s[n * 45 + 5] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 5]);
                        PRIM_INT__p_s_g_s[n * 45 + 5] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 5], PRIM_INT__p_s_g_s[n * 45 + 5]);
                        PRIM_INT__p_s_g_s[n * 45 + 5] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 5], PRIM_INT__p_s_g_s[n * 45 + 5]);

                        PRIM_INT__p_s_g_s[n * 45 + 6] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 6]);
                        PRIM_INT__p_s_g_s[n * 45 + 6] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 6], PRIM_INT__p_s_g_s[n * 45 + 6]);
                        PRIM_INT__p_s_g_s[n * 45 + 6] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 6], PRIM_INT__p_s_g_s[n * 45 + 6]);

                        PRIM_INT__p_s_g_s[n * 45 + 7] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 7]);
                        PRIM_INT__p_s_g_s[n * 45 + 7] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 7], PRIM_INT__p_s_g_s[n * 45 + 7]);
                        PRIM_INT__p_s_g_s[n * 45 + 7] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 7], PRIM_INT__p_s_g_s[n * 45 + 7]);

                        PRIM_INT__p_s_g_s[n * 45 + 8] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 8]);
                        PRIM_INT__p_s_g_s[n * 45 + 8] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 8], PRIM_INT__p_s_g_s[n * 45 + 8]);
                        PRIM_INT__p_s_g_s[n * 45 + 8] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 8], PRIM_INT__p_s_g_s[n * 45 + 8]);

                        PRIM_INT__p_s_g_s[n * 45 + 9] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 9]);
                        PRIM_INT__p_s_g_s[n * 45 + 9] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 9], PRIM_INT__p_s_g_s[n * 45 + 9]);
                        PRIM_INT__p_s_g_s[n * 45 + 9] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 9], PRIM_INT__p_s_g_s[n * 45 + 9]);

                        PRIM_INT__p_s_g_s[n * 45 + 10] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 10]);
                        PRIM_INT__p_s_g_s[n * 45 + 10] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 10], PRIM_INT__p_s_g_s[n * 45 + 10]);

                        PRIM_INT__p_s_g_s[n * 45 + 11] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 11]);
                        PRIM_INT__p_s_g_s[n * 45 + 11] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 11], PRIM_INT__p_s_g_s[n * 45 + 11]);

                        PRIM_INT__p_s_g_s[n * 45 + 12] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 12]);
                        PRIM_INT__p_s_g_s[n * 45 + 12] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 12], PRIM_INT__p_s_g_s[n * 45 + 12]);

                        PRIM_INT__p_s_g_s[n * 45 + 13] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 13]);
                        PRIM_INT__p_s_g_s[n * 45 + 13] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 13], PRIM_INT__p_s_g_s[n * 45 + 13]);

                        PRIM_INT__p_s_g_s[n * 45 + 14] = SIMINT_MUL(P_PA[0], PRIM_INT__s_s_g_s[n * 15 + 14]);
                        PRIM_INT__p_s_g_s[n * 45 + 14] = SIMINT_FMADD( aop_PQ[0], PRIM_INT__s_s_g_s[(n+1) * 15 + 14], PRIM_INT__p_s_g_s[n * 45 + 14]);

                        PRIM_INT__p_s_g_s[n * 45 + 15] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 0]);
                        PRIM_INT__p_s_g_s[n * 45 + 15] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 0], PRIM_INT__p_s_g_s[n * 45 + 15]);

                        PRIM_INT__p_s_g_s[n * 45 + 16] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 1]);
                        PRIM_INT__p_s_g_s[n * 45 + 16] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 1], PRIM_INT__p_s_g_s[n * 45 + 16]);
                        PRIM_INT__p_s_g_s[n * 45 + 16] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 0], PRIM_INT__p_s_g_s[n * 45 + 16]);

                        PRIM_INT__p_s_g_s[n * 45 + 17] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 2]);
                        PRIM_INT__p_s_g_s[n * 45 + 17] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 2], PRIM_INT__p_s_g_s[n * 45 + 17]);

                        PRIM_INT__p_s_g_s[n * 45 + 18] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 3]);
                        PRIM_INT__p_s_g_s[n * 45 + 18] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 3], PRIM_INT__p_s_g_s[n * 45 + 18]);
                        PRIM_INT__p_s_g_s[n * 45 + 18] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 1], PRIM_INT__p_s_g_s[n * 45 + 18]);

                        PRIM_INT__p_s_g_s[n * 45 + 19] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 4]);
                        PRIM_INT__p_s_g_s[n * 45 + 19] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 4], PRIM_INT__p_s_g_s[n * 45 + 19]);
                        PRIM_INT__p_s_g_s[n * 45 + 19] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 2], PRIM_INT__p_s_g_s[n * 45 + 19]);

                        PRIM_INT__p_s_g_s[n * 45 + 20] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 5]);
                        PRIM_INT__p_s_g_s[n * 45 + 20] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 5], PRIM_INT__p_s_g_s[n * 45 + 20]);

                        PRIM_INT__p_s_g_s[n * 45 + 21] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 6]);
                        PRIM_INT__p_s_g_s[n * 45 + 21] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 6], PRIM_INT__p_s_g_s[n * 45 + 21]);
                        PRIM_INT__p_s_g_s[n * 45 + 21] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 3], PRIM_INT__p_s_g_s[n * 45 + 21]);

                        PRIM_INT__p_s_g_s[n * 45 + 22] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 7]);
                        PRIM_INT__p_s_g_s[n * 45 + 22] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 7], PRIM_INT__p_s_g_s[n * 45 + 22]);
                        PRIM_INT__p_s_g_s[n * 45 + 22] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 4], PRIM_INT__p_s_g_s[n * 45 + 22]);

                        PRIM_INT__p_s_g_s[n * 45 + 23] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 8]);
                        PRIM_INT__p_s_g_s[n * 45 + 23] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 8], PRIM_INT__p_s_g_s[n * 45 + 23]);
                        PRIM_INT__p_s_g_s[n * 45 + 23] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 5], PRIM_INT__p_s_g_s[n * 45 + 23]);

                        PRIM_INT__p_s_g_s[n * 45 + 24] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 9]);
                        PRIM_INT__p_s_g_s[n * 45 + 24] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 9], PRIM_INT__p_s_g_s[n * 45 + 24]);

                        PRIM_INT__p_s_g_s[n * 45 + 25] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 10]);
                        PRIM_INT__p_s_g_s[n * 45 + 25] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 10], PRIM_INT__p_s_g_s[n * 45 + 25]);
                        PRIM_INT__p_s_g_s[n * 45 + 25] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 6], PRIM_INT__p_s_g_s[n * 45 + 25]);

                        PRIM_INT__p_s_g_s[n * 45 + 26] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 11]);
                        PRIM_INT__p_s_g_s[n * 45 + 26] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 11], PRIM_INT__p_s_g_s[n * 45 + 26]);
                        PRIM_INT__p_s_g_s[n * 45 + 26] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 7], PRIM_INT__p_s_g_s[n * 45 + 26]);

                        PRIM_INT__p_s_g_s[n * 45 + 27] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 12]);
                        PRIM_INT__p_s_g_s[n * 45 + 27] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 12], PRIM_INT__p_s_g_s[n * 45 + 27]);
                        PRIM_INT__p_s_g_s[n * 45 + 27] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 8], PRIM_INT__p_s_g_s[n * 45 + 27]);

                        PRIM_INT__p_s_g_s[n * 45 + 28] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 13]);
                        PRIM_INT__p_s_g_s[n * 45 + 28] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 13], PRIM_INT__p_s_g_s[n * 45 + 28]);
                        PRIM_INT__p_s_g_s[n * 45 + 28] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 9], PRIM_INT__p_s_g_s[n * 45 + 28]);

                        PRIM_INT__p_s_g_s[n * 45 + 29] = SIMINT_MUL(P_PA[1], PRIM_INT__s_s_g_s[n * 15 + 14]);
                        PRIM_INT__p_s_g_s[n * 45 + 29] = SIMINT_FMADD( aop_PQ[1], PRIM_INT__s_s_g_s[(n+1) * 15 + 14], PRIM_INT__p_s_g_s[n * 45 + 29]);

                        PRIM_INT__p_s_g_s[n * 45 + 30] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 0]);
                        PRIM_INT__p_s_g_s[n * 45 + 30] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 0], PRIM_INT__p_s_g_s[n * 45 + 30]);

                        PRIM_INT__p_s_g_s[n * 45 + 31] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 1]);
                        PRIM_INT__p_s_g_s[n * 45 + 31] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 1], PRIM_INT__p_s_g_s[n * 45 + 31]);

                        PRIM_INT__p_s_g_s[n * 45 + 32] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 2]);
                        PRIM_INT__p_s_g_s[n * 45 + 32] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 2], PRIM_INT__p_s_g_s[n * 45 + 32]);
                        PRIM_INT__p_s_g_s[n * 45 + 32] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 0], PRIM_INT__p_s_g_s[n * 45 + 32]);

                        PRIM_INT__p_s_g_s[n * 45 + 33] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 3]);
                        PRIM_INT__p_s_g_s[n * 45 + 33] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 3], PRIM_INT__p_s_g_s[n * 45 + 33]);

                        PRIM_INT__p_s_g_s[n * 45 + 34] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 4]);
                        PRIM_INT__p_s_g_s[n * 45 + 34] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 4], PRIM_INT__p_s_g_s[n * 45 + 34]);
                        PRIM_INT__p_s_g_s[n * 45 + 34] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 1], PRIM_INT__p_s_g_s[n * 45 + 34]);

                        PRIM_INT__p_s_g_s[n * 45 + 35] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 5]);
                        PRIM_INT__p_s_g_s[n * 45 + 35] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 5], PRIM_INT__p_s_g_s[n * 45 + 35]);
                        PRIM_INT__p_s_g_s[n * 45 + 35] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 2], PRIM_INT__p_s_g_s[n * 45 + 35]);

                        PRIM_INT__p_s_g_s[n * 45 + 36] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 6]);
                        PRIM_INT__p_s_g_s[n * 45 + 36] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 6], PRIM_INT__p_s_g_s[n * 45 + 36]);

                        PRIM_INT__p_s_g_s[n * 45 + 37] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 7]);
                        PRIM_INT__p_s_g_s[n * 45 + 37] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 7], PRIM_INT__p_s_g_s[n * 45 + 37]);
                        PRIM_INT__p_s_g_s[n * 45 + 37] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 3], PRIM_INT__p_s_g_s[n * 45 + 37]);

                        PRIM_INT__p_s_g_s[n * 45 + 38] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 8]);
                        PRIM_INT__p_s_g_s[n * 45 + 38] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 8], PRIM_INT__p_s_g_s[n * 45 + 38]);
                        PRIM_INT__p_s_g_s[n * 45 + 38] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 4], PRIM_INT__p_s_g_s[n * 45 + 38]);

                        PRIM_INT__p_s_g_s[n * 45 + 39] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 9]);
                        PRIM_INT__p_s_g_s[n * 45 + 39] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 9], PRIM_INT__p_s_g_s[n * 45 + 39]);
                        PRIM_INT__p_s_g_s[n * 45 + 39] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 5], PRIM_INT__p_s_g_s[n * 45 + 39]);

                        PRIM_INT__p_s_g_s[n * 45 + 40] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 10]);
                        PRIM_INT__p_s_g_s[n * 45 + 40] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 10], PRIM_INT__p_s_g_s[n * 45 + 40]);

                        PRIM_INT__p_s_g_s[n * 45 + 41] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 11]);
                        PRIM_INT__p_s_g_s[n * 45 + 41] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 11], PRIM_INT__p_s_g_s[n * 45 + 41]);
                        PRIM_INT__p_s_g_s[n * 45 + 41] = SIMINT_FMADD( vrr_const_1_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 6], PRIM_INT__p_s_g_s[n * 45 + 41]);

                        PRIM_INT__p_s_g_s[n * 45 + 42] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 12]);
                        PRIM_INT__p_s_g_s[n * 45 + 42] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 12], PRIM_INT__p_s_g_s[n * 45 + 42]);
                        PRIM_INT__p_s_g_s[n * 45 + 42] = SIMINT_FMADD( vrr_const_2_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 7], PRIM_INT__p_s_g_s[n * 45 + 42]);

                        PRIM_INT__p_s_g_s[n * 45 + 43] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 13]);
                        PRIM_INT__p_s_g_s[n * 45 + 43] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 13], PRIM_INT__p_s_g_s[n * 45 + 43]);
                        PRIM_INT__p_s_g_s[n * 45 + 43] = SIMINT_FMADD( vrr_const_3_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 8], PRIM_INT__p_s_g_s[n * 45 + 43]);

                        PRIM_INT__p_s_g_s[n * 45 + 44] = SIMINT_MUL(P_PA[2], PRIM_INT__s_s_g_s[n * 15 + 14]);
                        PRIM_INT__p_s_g_s[n * 45 + 44] = SIMINT_FMADD( aop_PQ[2], PRIM_INT__s_s_g_s[(n+1) * 15 + 14], PRIM_INT__p_s_g_s[n * 45 + 44]);
                        PRIM_INT__p_s_g_s[n * 45 + 44] = SIMINT_FMADD( vrr_const_4_over_2pq, PRIM_INT__s_s_f_s[(n+1) * 10 + 9], PRIM_INT__p_s_g_s[n * 45 + 44]);

                    }

}


