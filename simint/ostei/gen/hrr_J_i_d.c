
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// BRA: ( i d |
// Steps: 168
//////////////////////////////////////////////

void HRR_J_i_d(double * const restrict HRR_INT__i_d_X_X,
                    double const * const restrict HRR_INT__i_p_X_X,
                    double const * const restrict HRR_INT__k_p_X_X,
                    const double hAB[3], const int ncart_ket)
{
    int iket;

                for(iket = 0; iket < ncart_ket; ++iket)
                {
                    HRR_INT__i_d_X_X[0 * ncart_ket + iket] = HRR_INT__k_p_X_X[0 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[0 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[1 * ncart_ket + iket] = HRR_INT__k_p_X_X[3 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[0 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[2 * ncart_ket + iket] = HRR_INT__k_p_X_X[6 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[0 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[3 * ncart_ket + iket] = HRR_INT__k_p_X_X[4 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[1 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[4 * ncart_ket + iket] = HRR_INT__k_p_X_X[7 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[1 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[5 * ncart_ket + iket] = HRR_INT__k_p_X_X[8 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[2 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[6 * ncart_ket + iket] = HRR_INT__k_p_X_X[3 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[3 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[7 * ncart_ket + iket] = HRR_INT__k_p_X_X[9 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[3 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[8 * ncart_ket + iket] = HRR_INT__k_p_X_X[12 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[3 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[9 * ncart_ket + iket] = HRR_INT__k_p_X_X[10 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[4 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[10 * ncart_ket + iket] = HRR_INT__k_p_X_X[13 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[4 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[11 * ncart_ket + iket] = HRR_INT__k_p_X_X[14 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[5 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[12 * ncart_ket + iket] = HRR_INT__k_p_X_X[6 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[6 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[13 * ncart_ket + iket] = HRR_INT__k_p_X_X[12 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[6 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[14 * ncart_ket + iket] = HRR_INT__k_p_X_X[15 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[6 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[15 * ncart_ket + iket] = HRR_INT__k_p_X_X[13 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[7 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[16 * ncart_ket + iket] = HRR_INT__k_p_X_X[16 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[7 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[17 * ncart_ket + iket] = HRR_INT__k_p_X_X[17 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[8 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[18 * ncart_ket + iket] = HRR_INT__k_p_X_X[9 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[9 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[19 * ncart_ket + iket] = HRR_INT__k_p_X_X[18 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[9 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[20 * ncart_ket + iket] = HRR_INT__k_p_X_X[21 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[9 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[21 * ncart_ket + iket] = HRR_INT__k_p_X_X[19 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[10 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[22 * ncart_ket + iket] = HRR_INT__k_p_X_X[22 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[10 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[23 * ncart_ket + iket] = HRR_INT__k_p_X_X[23 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[11 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[24 * ncart_ket + iket] = HRR_INT__k_p_X_X[12 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[12 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[25 * ncart_ket + iket] = HRR_INT__k_p_X_X[21 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[12 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[26 * ncart_ket + iket] = HRR_INT__k_p_X_X[24 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[12 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[27 * ncart_ket + iket] = HRR_INT__k_p_X_X[22 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[13 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[28 * ncart_ket + iket] = HRR_INT__k_p_X_X[25 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[13 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[29 * ncart_ket + iket] = HRR_INT__k_p_X_X[26 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[14 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[30 * ncart_ket + iket] = HRR_INT__k_p_X_X[15 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[15 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[31 * ncart_ket + iket] = HRR_INT__k_p_X_X[24 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[15 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[32 * ncart_ket + iket] = HRR_INT__k_p_X_X[27 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[15 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[33 * ncart_ket + iket] = HRR_INT__k_p_X_X[25 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[16 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[34 * ncart_ket + iket] = HRR_INT__k_p_X_X[28 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[16 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[35 * ncart_ket + iket] = HRR_INT__k_p_X_X[29 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[17 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[36 * ncart_ket + iket] = HRR_INT__k_p_X_X[18 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[18 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[37 * ncart_ket + iket] = HRR_INT__k_p_X_X[30 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[18 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[38 * ncart_ket + iket] = HRR_INT__k_p_X_X[33 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[18 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[39 * ncart_ket + iket] = HRR_INT__k_p_X_X[31 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[19 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[40 * ncart_ket + iket] = HRR_INT__k_p_X_X[34 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[19 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[41 * ncart_ket + iket] = HRR_INT__k_p_X_X[35 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[20 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[42 * ncart_ket + iket] = HRR_INT__k_p_X_X[21 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[21 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[43 * ncart_ket + iket] = HRR_INT__k_p_X_X[33 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[21 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[44 * ncart_ket + iket] = HRR_INT__k_p_X_X[36 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[21 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[45 * ncart_ket + iket] = HRR_INT__k_p_X_X[34 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[22 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[46 * ncart_ket + iket] = HRR_INT__k_p_X_X[37 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[22 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[47 * ncart_ket + iket] = HRR_INT__k_p_X_X[38 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[23 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[48 * ncart_ket + iket] = HRR_INT__k_p_X_X[24 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[24 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[49 * ncart_ket + iket] = HRR_INT__k_p_X_X[36 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[24 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[50 * ncart_ket + iket] = HRR_INT__k_p_X_X[39 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[24 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[51 * ncart_ket + iket] = HRR_INT__k_p_X_X[37 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[25 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[52 * ncart_ket + iket] = HRR_INT__k_p_X_X[40 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[25 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[53 * ncart_ket + iket] = HRR_INT__k_p_X_X[41 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[26 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[54 * ncart_ket + iket] = HRR_INT__k_p_X_X[27 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[27 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[55 * ncart_ket + iket] = HRR_INT__k_p_X_X[39 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[27 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[56 * ncart_ket + iket] = HRR_INT__k_p_X_X[42 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[27 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[57 * ncart_ket + iket] = HRR_INT__k_p_X_X[40 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[28 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[58 * ncart_ket + iket] = HRR_INT__k_p_X_X[43 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[28 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[59 * ncart_ket + iket] = HRR_INT__k_p_X_X[44 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[29 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[60 * ncart_ket + iket] = HRR_INT__k_p_X_X[30 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[30 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[61 * ncart_ket + iket] = HRR_INT__k_p_X_X[45 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[30 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[62 * ncart_ket + iket] = HRR_INT__k_p_X_X[48 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[30 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[63 * ncart_ket + iket] = HRR_INT__k_p_X_X[46 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[31 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[64 * ncart_ket + iket] = HRR_INT__k_p_X_X[49 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[31 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[65 * ncart_ket + iket] = HRR_INT__k_p_X_X[50 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[32 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[66 * ncart_ket + iket] = HRR_INT__k_p_X_X[33 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[33 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[67 * ncart_ket + iket] = HRR_INT__k_p_X_X[48 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[33 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[68 * ncart_ket + iket] = HRR_INT__k_p_X_X[51 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[33 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[69 * ncart_ket + iket] = HRR_INT__k_p_X_X[49 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[34 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[70 * ncart_ket + iket] = HRR_INT__k_p_X_X[52 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[34 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[71 * ncart_ket + iket] = HRR_INT__k_p_X_X[53 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[35 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[72 * ncart_ket + iket] = HRR_INT__k_p_X_X[36 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[36 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[73 * ncart_ket + iket] = HRR_INT__k_p_X_X[51 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[36 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[74 * ncart_ket + iket] = HRR_INT__k_p_X_X[54 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[36 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[75 * ncart_ket + iket] = HRR_INT__k_p_X_X[52 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[37 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[76 * ncart_ket + iket] = HRR_INT__k_p_X_X[55 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[37 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[77 * ncart_ket + iket] = HRR_INT__k_p_X_X[56 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[38 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[78 * ncart_ket + iket] = HRR_INT__k_p_X_X[39 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[39 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[79 * ncart_ket + iket] = HRR_INT__k_p_X_X[54 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[39 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[80 * ncart_ket + iket] = HRR_INT__k_p_X_X[57 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[39 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[81 * ncart_ket + iket] = HRR_INT__k_p_X_X[55 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[40 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[82 * ncart_ket + iket] = HRR_INT__k_p_X_X[58 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[40 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[83 * ncart_ket + iket] = HRR_INT__k_p_X_X[59 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[41 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[84 * ncart_ket + iket] = HRR_INT__k_p_X_X[42 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[42 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[85 * ncart_ket + iket] = HRR_INT__k_p_X_X[57 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[42 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[86 * ncart_ket + iket] = HRR_INT__k_p_X_X[60 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[42 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[87 * ncart_ket + iket] = HRR_INT__k_p_X_X[58 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[43 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[88 * ncart_ket + iket] = HRR_INT__k_p_X_X[61 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[43 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[89 * ncart_ket + iket] = HRR_INT__k_p_X_X[62 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[44 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[90 * ncart_ket + iket] = HRR_INT__k_p_X_X[45 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[45 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[91 * ncart_ket + iket] = HRR_INT__k_p_X_X[63 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[45 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[92 * ncart_ket + iket] = HRR_INT__k_p_X_X[66 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[45 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[93 * ncart_ket + iket] = HRR_INT__k_p_X_X[64 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[46 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[94 * ncart_ket + iket] = HRR_INT__k_p_X_X[67 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[46 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[95 * ncart_ket + iket] = HRR_INT__k_p_X_X[68 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[47 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[96 * ncart_ket + iket] = HRR_INT__k_p_X_X[48 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[48 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[97 * ncart_ket + iket] = HRR_INT__k_p_X_X[66 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[48 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[98 * ncart_ket + iket] = HRR_INT__k_p_X_X[69 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[48 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[99 * ncart_ket + iket] = HRR_INT__k_p_X_X[67 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[49 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[100 * ncart_ket + iket] = HRR_INT__k_p_X_X[70 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[49 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[101 * ncart_ket + iket] = HRR_INT__k_p_X_X[71 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[50 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[102 * ncart_ket + iket] = HRR_INT__k_p_X_X[51 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[51 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[103 * ncart_ket + iket] = HRR_INT__k_p_X_X[69 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[51 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[104 * ncart_ket + iket] = HRR_INT__k_p_X_X[72 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[51 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[105 * ncart_ket + iket] = HRR_INT__k_p_X_X[70 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[52 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[106 * ncart_ket + iket] = HRR_INT__k_p_X_X[73 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[52 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[107 * ncart_ket + iket] = HRR_INT__k_p_X_X[74 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[53 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[108 * ncart_ket + iket] = HRR_INT__k_p_X_X[54 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[54 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[109 * ncart_ket + iket] = HRR_INT__k_p_X_X[72 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[54 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[110 * ncart_ket + iket] = HRR_INT__k_p_X_X[75 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[54 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[111 * ncart_ket + iket] = HRR_INT__k_p_X_X[73 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[55 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[112 * ncart_ket + iket] = HRR_INT__k_p_X_X[76 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[55 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[113 * ncart_ket + iket] = HRR_INT__k_p_X_X[77 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[56 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[114 * ncart_ket + iket] = HRR_INT__k_p_X_X[57 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[57 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[115 * ncart_ket + iket] = HRR_INT__k_p_X_X[75 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[57 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[116 * ncart_ket + iket] = HRR_INT__k_p_X_X[78 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[57 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[117 * ncart_ket + iket] = HRR_INT__k_p_X_X[76 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[58 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[118 * ncart_ket + iket] = HRR_INT__k_p_X_X[79 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[58 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[119 * ncart_ket + iket] = HRR_INT__k_p_X_X[80 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[59 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[120 * ncart_ket + iket] = HRR_INT__k_p_X_X[60 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[60 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[121 * ncart_ket + iket] = HRR_INT__k_p_X_X[78 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[60 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[122 * ncart_ket + iket] = HRR_INT__k_p_X_X[81 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[60 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[123 * ncart_ket + iket] = HRR_INT__k_p_X_X[79 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[61 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[124 * ncart_ket + iket] = HRR_INT__k_p_X_X[82 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[61 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[125 * ncart_ket + iket] = HRR_INT__k_p_X_X[83 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[62 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[126 * ncart_ket + iket] = HRR_INT__k_p_X_X[63 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[63 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[127 * ncart_ket + iket] = HRR_INT__k_p_X_X[84 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[63 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[128 * ncart_ket + iket] = HRR_INT__k_p_X_X[87 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[63 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[129 * ncart_ket + iket] = HRR_INT__k_p_X_X[85 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[64 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[130 * ncart_ket + iket] = HRR_INT__k_p_X_X[88 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[64 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[131 * ncart_ket + iket] = HRR_INT__k_p_X_X[89 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[65 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[132 * ncart_ket + iket] = HRR_INT__k_p_X_X[66 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[66 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[133 * ncart_ket + iket] = HRR_INT__k_p_X_X[87 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[66 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[134 * ncart_ket + iket] = HRR_INT__k_p_X_X[90 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[66 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[135 * ncart_ket + iket] = HRR_INT__k_p_X_X[88 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[67 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[136 * ncart_ket + iket] = HRR_INT__k_p_X_X[91 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[67 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[137 * ncart_ket + iket] = HRR_INT__k_p_X_X[92 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[68 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[138 * ncart_ket + iket] = HRR_INT__k_p_X_X[69 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[69 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[139 * ncart_ket + iket] = HRR_INT__k_p_X_X[90 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[69 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[140 * ncart_ket + iket] = HRR_INT__k_p_X_X[93 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[69 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[141 * ncart_ket + iket] = HRR_INT__k_p_X_X[91 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[70 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[142 * ncart_ket + iket] = HRR_INT__k_p_X_X[94 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[70 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[143 * ncart_ket + iket] = HRR_INT__k_p_X_X[95 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[71 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[144 * ncart_ket + iket] = HRR_INT__k_p_X_X[72 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[72 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[145 * ncart_ket + iket] = HRR_INT__k_p_X_X[93 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[72 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[146 * ncart_ket + iket] = HRR_INT__k_p_X_X[96 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[72 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[147 * ncart_ket + iket] = HRR_INT__k_p_X_X[94 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[73 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[148 * ncart_ket + iket] = HRR_INT__k_p_X_X[97 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[73 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[149 * ncart_ket + iket] = HRR_INT__k_p_X_X[98 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[74 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[150 * ncart_ket + iket] = HRR_INT__k_p_X_X[75 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[75 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[151 * ncart_ket + iket] = HRR_INT__k_p_X_X[96 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[75 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[152 * ncart_ket + iket] = HRR_INT__k_p_X_X[99 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[75 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[153 * ncart_ket + iket] = HRR_INT__k_p_X_X[97 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[76 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[154 * ncart_ket + iket] = HRR_INT__k_p_X_X[100 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[76 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[155 * ncart_ket + iket] = HRR_INT__k_p_X_X[101 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[77 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[156 * ncart_ket + iket] = HRR_INT__k_p_X_X[78 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[78 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[157 * ncart_ket + iket] = HRR_INT__k_p_X_X[99 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[78 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[158 * ncart_ket + iket] = HRR_INT__k_p_X_X[102 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[78 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[159 * ncart_ket + iket] = HRR_INT__k_p_X_X[100 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[79 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[160 * ncart_ket + iket] = HRR_INT__k_p_X_X[103 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[79 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[161 * ncart_ket + iket] = HRR_INT__k_p_X_X[104 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[80 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[162 * ncart_ket + iket] = HRR_INT__k_p_X_X[81 * ncart_ket + iket] + ( hAB[0] * HRR_INT__i_p_X_X[81 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[163 * ncart_ket + iket] = HRR_INT__k_p_X_X[102 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[81 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[164 * ncart_ket + iket] = HRR_INT__k_p_X_X[105 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[81 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[165 * ncart_ket + iket] = HRR_INT__k_p_X_X[103 * ncart_ket + iket] + ( hAB[1] * HRR_INT__i_p_X_X[82 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[166 * ncart_ket + iket] = HRR_INT__k_p_X_X[106 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[82 * ncart_ket + iket] );

                    HRR_INT__i_d_X_X[167 * ncart_ket + iket] = HRR_INT__k_p_X_X[107 * ncart_ket + iket] + ( hAB[2] * HRR_INT__i_p_X_X[83 * ncart_ket + iket] );

                }


}


