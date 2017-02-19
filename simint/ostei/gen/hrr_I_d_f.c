
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// BRA: ( d f |
// Steps: 60
//////////////////////////////////////////////

void HRR_I_d_f(double * const restrict HRR_INT__d_f_X_X,
                    double const * const restrict HRR_INT__p_f_X_X,
                    double const * const restrict HRR_INT__p_g_X_X,
                    const double hAB[3], const int ncart_ket)
{
    int iket;

                for(iket = 0; iket < ncart_ket; ++iket)
                {
                    HRR_INT__d_f_X_X[0 * ncart_ket + iket] = HRR_INT__p_g_X_X[0 * ncart_ket + iket] - ( hAB[0] * HRR_INT__p_f_X_X[0 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[1 * ncart_ket + iket] = HRR_INT__p_g_X_X[1 * ncart_ket + iket] - ( hAB[0] * HRR_INT__p_f_X_X[1 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[2 * ncart_ket + iket] = HRR_INT__p_g_X_X[2 * ncart_ket + iket] - ( hAB[0] * HRR_INT__p_f_X_X[2 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[3 * ncart_ket + iket] = HRR_INT__p_g_X_X[3 * ncart_ket + iket] - ( hAB[0] * HRR_INT__p_f_X_X[3 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[4 * ncart_ket + iket] = HRR_INT__p_g_X_X[4 * ncart_ket + iket] - ( hAB[0] * HRR_INT__p_f_X_X[4 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[5 * ncart_ket + iket] = HRR_INT__p_g_X_X[5 * ncart_ket + iket] - ( hAB[0] * HRR_INT__p_f_X_X[5 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[6 * ncart_ket + iket] = HRR_INT__p_g_X_X[6 * ncart_ket + iket] - ( hAB[0] * HRR_INT__p_f_X_X[6 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[7 * ncart_ket + iket] = HRR_INT__p_g_X_X[7 * ncart_ket + iket] - ( hAB[0] * HRR_INT__p_f_X_X[7 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[8 * ncart_ket + iket] = HRR_INT__p_g_X_X[8 * ncart_ket + iket] - ( hAB[0] * HRR_INT__p_f_X_X[8 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[9 * ncart_ket + iket] = HRR_INT__p_g_X_X[9 * ncart_ket + iket] - ( hAB[0] * HRR_INT__p_f_X_X[9 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[10 * ncart_ket + iket] = HRR_INT__p_g_X_X[1 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[0 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[11 * ncart_ket + iket] = HRR_INT__p_g_X_X[3 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[1 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[12 * ncart_ket + iket] = HRR_INT__p_g_X_X[4 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[2 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[13 * ncart_ket + iket] = HRR_INT__p_g_X_X[6 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[3 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[14 * ncart_ket + iket] = HRR_INT__p_g_X_X[7 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[4 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[15 * ncart_ket + iket] = HRR_INT__p_g_X_X[8 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[5 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[16 * ncart_ket + iket] = HRR_INT__p_g_X_X[10 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[6 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[17 * ncart_ket + iket] = HRR_INT__p_g_X_X[11 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[7 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[18 * ncart_ket + iket] = HRR_INT__p_g_X_X[12 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[8 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[19 * ncart_ket + iket] = HRR_INT__p_g_X_X[13 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[9 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[20 * ncart_ket + iket] = HRR_INT__p_g_X_X[2 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[0 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[21 * ncart_ket + iket] = HRR_INT__p_g_X_X[4 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[1 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[22 * ncart_ket + iket] = HRR_INT__p_g_X_X[5 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[2 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[23 * ncart_ket + iket] = HRR_INT__p_g_X_X[7 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[3 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[24 * ncart_ket + iket] = HRR_INT__p_g_X_X[8 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[4 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[25 * ncart_ket + iket] = HRR_INT__p_g_X_X[9 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[5 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[26 * ncart_ket + iket] = HRR_INT__p_g_X_X[11 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[6 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[27 * ncart_ket + iket] = HRR_INT__p_g_X_X[12 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[7 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[28 * ncart_ket + iket] = HRR_INT__p_g_X_X[13 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[8 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[29 * ncart_ket + iket] = HRR_INT__p_g_X_X[14 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[9 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[30 * ncart_ket + iket] = HRR_INT__p_g_X_X[16 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[10 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[31 * ncart_ket + iket] = HRR_INT__p_g_X_X[18 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[11 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[32 * ncart_ket + iket] = HRR_INT__p_g_X_X[19 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[12 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[33 * ncart_ket + iket] = HRR_INT__p_g_X_X[21 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[13 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[34 * ncart_ket + iket] = HRR_INT__p_g_X_X[22 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[14 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[35 * ncart_ket + iket] = HRR_INT__p_g_X_X[23 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[15 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[36 * ncart_ket + iket] = HRR_INT__p_g_X_X[25 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[16 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[37 * ncart_ket + iket] = HRR_INT__p_g_X_X[26 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[17 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[38 * ncart_ket + iket] = HRR_INT__p_g_X_X[27 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[18 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[39 * ncart_ket + iket] = HRR_INT__p_g_X_X[28 * ncart_ket + iket] - ( hAB[1] * HRR_INT__p_f_X_X[19 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[40 * ncart_ket + iket] = HRR_INT__p_g_X_X[17 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[10 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[41 * ncart_ket + iket] = HRR_INT__p_g_X_X[19 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[11 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[42 * ncart_ket + iket] = HRR_INT__p_g_X_X[20 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[12 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[43 * ncart_ket + iket] = HRR_INT__p_g_X_X[22 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[13 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[44 * ncart_ket + iket] = HRR_INT__p_g_X_X[23 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[14 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[45 * ncart_ket + iket] = HRR_INT__p_g_X_X[24 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[15 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[46 * ncart_ket + iket] = HRR_INT__p_g_X_X[26 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[16 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[47 * ncart_ket + iket] = HRR_INT__p_g_X_X[27 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[17 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[48 * ncart_ket + iket] = HRR_INT__p_g_X_X[28 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[18 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[49 * ncart_ket + iket] = HRR_INT__p_g_X_X[29 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[19 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[50 * ncart_ket + iket] = HRR_INT__p_g_X_X[32 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[20 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[51 * ncart_ket + iket] = HRR_INT__p_g_X_X[34 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[21 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[52 * ncart_ket + iket] = HRR_INT__p_g_X_X[35 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[22 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[53 * ncart_ket + iket] = HRR_INT__p_g_X_X[37 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[23 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[54 * ncart_ket + iket] = HRR_INT__p_g_X_X[38 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[24 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[55 * ncart_ket + iket] = HRR_INT__p_g_X_X[39 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[25 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[56 * ncart_ket + iket] = HRR_INT__p_g_X_X[41 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[26 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[57 * ncart_ket + iket] = HRR_INT__p_g_X_X[42 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[27 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[58 * ncart_ket + iket] = HRR_INT__p_g_X_X[43 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[28 * ncart_ket + iket] );

                    HRR_INT__d_f_X_X[59 * ncart_ket + iket] = HRR_INT__p_g_X_X[44 * ncart_ket + iket] - ( hAB[2] * HRR_INT__p_f_X_X[29 * ncart_ket + iket] );

                }


}


