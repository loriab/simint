
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// BRA: ( p g |
// Steps: 45
//////////////////////////////////////////////

void HRR_I_p_g(double * const restrict HRR_INT__p_g_X_X,
                    double const * const restrict HRR_INT__s_g_X_X,
                    double const * const restrict HRR_INT__s_h_X_X,
                    const double hAB[3], const int ncart_ket)
{
    int iket;

                for(iket = 0; iket < ncart_ket; ++iket)
                {
                    HRR_INT__p_g_X_X[0 * ncart_ket + iket] = HRR_INT__s_h_X_X[0 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[0 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[1 * ncart_ket + iket] = HRR_INT__s_h_X_X[1 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[1 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[2 * ncart_ket + iket] = HRR_INT__s_h_X_X[2 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[2 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[3 * ncart_ket + iket] = HRR_INT__s_h_X_X[3 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[3 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[4 * ncart_ket + iket] = HRR_INT__s_h_X_X[4 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[4 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[5 * ncart_ket + iket] = HRR_INT__s_h_X_X[5 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[5 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[6 * ncart_ket + iket] = HRR_INT__s_h_X_X[6 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[6 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[7 * ncart_ket + iket] = HRR_INT__s_h_X_X[7 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[7 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[8 * ncart_ket + iket] = HRR_INT__s_h_X_X[8 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[8 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[9 * ncart_ket + iket] = HRR_INT__s_h_X_X[9 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[9 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[10 * ncart_ket + iket] = HRR_INT__s_h_X_X[10 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[10 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[11 * ncart_ket + iket] = HRR_INT__s_h_X_X[11 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[11 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[12 * ncart_ket + iket] = HRR_INT__s_h_X_X[12 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[12 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[13 * ncart_ket + iket] = HRR_INT__s_h_X_X[13 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[13 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[14 * ncart_ket + iket] = HRR_INT__s_h_X_X[14 * ncart_ket + iket] - ( hAB[0] * HRR_INT__s_g_X_X[14 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[15 * ncart_ket + iket] = HRR_INT__s_h_X_X[1 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[0 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[16 * ncart_ket + iket] = HRR_INT__s_h_X_X[3 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[1 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[17 * ncart_ket + iket] = HRR_INT__s_h_X_X[4 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[2 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[18 * ncart_ket + iket] = HRR_INT__s_h_X_X[6 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[3 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[19 * ncart_ket + iket] = HRR_INT__s_h_X_X[7 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[4 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[20 * ncart_ket + iket] = HRR_INT__s_h_X_X[8 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[5 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[21 * ncart_ket + iket] = HRR_INT__s_h_X_X[10 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[6 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[22 * ncart_ket + iket] = HRR_INT__s_h_X_X[11 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[7 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[23 * ncart_ket + iket] = HRR_INT__s_h_X_X[12 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[8 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[24 * ncart_ket + iket] = HRR_INT__s_h_X_X[13 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[9 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[25 * ncart_ket + iket] = HRR_INT__s_h_X_X[15 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[10 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[26 * ncart_ket + iket] = HRR_INT__s_h_X_X[16 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[11 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[27 * ncart_ket + iket] = HRR_INT__s_h_X_X[17 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[12 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[28 * ncart_ket + iket] = HRR_INT__s_h_X_X[18 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[13 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[29 * ncart_ket + iket] = HRR_INT__s_h_X_X[19 * ncart_ket + iket] - ( hAB[1] * HRR_INT__s_g_X_X[14 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[30 * ncart_ket + iket] = HRR_INT__s_h_X_X[2 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[0 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[31 * ncart_ket + iket] = HRR_INT__s_h_X_X[4 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[1 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[32 * ncart_ket + iket] = HRR_INT__s_h_X_X[5 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[2 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[33 * ncart_ket + iket] = HRR_INT__s_h_X_X[7 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[3 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[34 * ncart_ket + iket] = HRR_INT__s_h_X_X[8 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[4 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[35 * ncart_ket + iket] = HRR_INT__s_h_X_X[9 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[5 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[36 * ncart_ket + iket] = HRR_INT__s_h_X_X[11 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[6 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[37 * ncart_ket + iket] = HRR_INT__s_h_X_X[12 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[7 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[38 * ncart_ket + iket] = HRR_INT__s_h_X_X[13 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[8 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[39 * ncart_ket + iket] = HRR_INT__s_h_X_X[14 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[9 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[40 * ncart_ket + iket] = HRR_INT__s_h_X_X[16 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[10 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[41 * ncart_ket + iket] = HRR_INT__s_h_X_X[17 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[11 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[42 * ncart_ket + iket] = HRR_INT__s_h_X_X[18 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[12 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[43 * ncart_ket + iket] = HRR_INT__s_h_X_X[19 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[13 * ncart_ket + iket] );

                    HRR_INT__p_g_X_X[44 * ncart_ket + iket] = HRR_INT__s_h_X_X[20 * ncart_ket + iket] - ( hAB[2] * HRR_INT__s_g_X_X[14 * ncart_ket + iket] );

                }


}


