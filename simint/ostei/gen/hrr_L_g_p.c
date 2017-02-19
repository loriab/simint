
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// KET: | g p )
// Steps: 45
//////////////////////////////////////////////

void HRR_L_g_p(double * const restrict HRR_INT__X_X_g_p,
                    double const * const restrict HRR_INT__X_X_g_s,
                    double const * const restrict HRR_INT__X_X_h_s,
                    const double hCD[3], const int ncart_bra)
{
    int ibra;

                for(ibra = 0; ibra < ncart_bra; ++ibra)
                {
                    HRR_INT__X_X_g_p[ibra * 45 + 0] = HRR_INT__X_X_h_s[ibra * 21 + 0] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 0] );

                    HRR_INT__X_X_g_p[ibra * 45 + 1] = HRR_INT__X_X_h_s[ibra * 21 + 1] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 0] );

                    HRR_INT__X_X_g_p[ibra * 45 + 2] = HRR_INT__X_X_h_s[ibra * 21 + 2] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 0] );

                    HRR_INT__X_X_g_p[ibra * 45 + 3] = HRR_INT__X_X_h_s[ibra * 21 + 1] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 1] );

                    HRR_INT__X_X_g_p[ibra * 45 + 4] = HRR_INT__X_X_h_s[ibra * 21 + 3] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 1] );

                    HRR_INT__X_X_g_p[ibra * 45 + 5] = HRR_INT__X_X_h_s[ibra * 21 + 4] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 1] );

                    HRR_INT__X_X_g_p[ibra * 45 + 6] = HRR_INT__X_X_h_s[ibra * 21 + 2] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 2] );

                    HRR_INT__X_X_g_p[ibra * 45 + 7] = HRR_INT__X_X_h_s[ibra * 21 + 4] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 2] );

                    HRR_INT__X_X_g_p[ibra * 45 + 8] = HRR_INT__X_X_h_s[ibra * 21 + 5] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 2] );

                    HRR_INT__X_X_g_p[ibra * 45 + 9] = HRR_INT__X_X_h_s[ibra * 21 + 3] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 3] );

                    HRR_INT__X_X_g_p[ibra * 45 + 10] = HRR_INT__X_X_h_s[ibra * 21 + 6] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 3] );

                    HRR_INT__X_X_g_p[ibra * 45 + 11] = HRR_INT__X_X_h_s[ibra * 21 + 7] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 3] );

                    HRR_INT__X_X_g_p[ibra * 45 + 12] = HRR_INT__X_X_h_s[ibra * 21 + 4] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 4] );

                    HRR_INT__X_X_g_p[ibra * 45 + 13] = HRR_INT__X_X_h_s[ibra * 21 + 7] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 4] );

                    HRR_INT__X_X_g_p[ibra * 45 + 14] = HRR_INT__X_X_h_s[ibra * 21 + 8] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 4] );

                    HRR_INT__X_X_g_p[ibra * 45 + 15] = HRR_INT__X_X_h_s[ibra * 21 + 5] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 5] );

                    HRR_INT__X_X_g_p[ibra * 45 + 16] = HRR_INT__X_X_h_s[ibra * 21 + 8] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 5] );

                    HRR_INT__X_X_g_p[ibra * 45 + 17] = HRR_INT__X_X_h_s[ibra * 21 + 9] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 5] );

                    HRR_INT__X_X_g_p[ibra * 45 + 18] = HRR_INT__X_X_h_s[ibra * 21 + 6] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 6] );

                    HRR_INT__X_X_g_p[ibra * 45 + 19] = HRR_INT__X_X_h_s[ibra * 21 + 10] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 6] );

                    HRR_INT__X_X_g_p[ibra * 45 + 20] = HRR_INT__X_X_h_s[ibra * 21 + 11] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 6] );

                    HRR_INT__X_X_g_p[ibra * 45 + 21] = HRR_INT__X_X_h_s[ibra * 21 + 7] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 7] );

                    HRR_INT__X_X_g_p[ibra * 45 + 22] = HRR_INT__X_X_h_s[ibra * 21 + 11] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 7] );

                    HRR_INT__X_X_g_p[ibra * 45 + 23] = HRR_INT__X_X_h_s[ibra * 21 + 12] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 7] );

                    HRR_INT__X_X_g_p[ibra * 45 + 24] = HRR_INT__X_X_h_s[ibra * 21 + 8] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 8] );

                    HRR_INT__X_X_g_p[ibra * 45 + 25] = HRR_INT__X_X_h_s[ibra * 21 + 12] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 8] );

                    HRR_INT__X_X_g_p[ibra * 45 + 26] = HRR_INT__X_X_h_s[ibra * 21 + 13] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 8] );

                    HRR_INT__X_X_g_p[ibra * 45 + 27] = HRR_INT__X_X_h_s[ibra * 21 + 9] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 9] );

                    HRR_INT__X_X_g_p[ibra * 45 + 28] = HRR_INT__X_X_h_s[ibra * 21 + 13] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 9] );

                    HRR_INT__X_X_g_p[ibra * 45 + 29] = HRR_INT__X_X_h_s[ibra * 21 + 14] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 9] );

                    HRR_INT__X_X_g_p[ibra * 45 + 30] = HRR_INT__X_X_h_s[ibra * 21 + 10] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 10] );

                    HRR_INT__X_X_g_p[ibra * 45 + 31] = HRR_INT__X_X_h_s[ibra * 21 + 15] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 10] );

                    HRR_INT__X_X_g_p[ibra * 45 + 32] = HRR_INT__X_X_h_s[ibra * 21 + 16] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 10] );

                    HRR_INT__X_X_g_p[ibra * 45 + 33] = HRR_INT__X_X_h_s[ibra * 21 + 11] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 11] );

                    HRR_INT__X_X_g_p[ibra * 45 + 34] = HRR_INT__X_X_h_s[ibra * 21 + 16] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 11] );

                    HRR_INT__X_X_g_p[ibra * 45 + 35] = HRR_INT__X_X_h_s[ibra * 21 + 17] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 11] );

                    HRR_INT__X_X_g_p[ibra * 45 + 36] = HRR_INT__X_X_h_s[ibra * 21 + 12] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 12] );

                    HRR_INT__X_X_g_p[ibra * 45 + 37] = HRR_INT__X_X_h_s[ibra * 21 + 17] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 12] );

                    HRR_INT__X_X_g_p[ibra * 45 + 38] = HRR_INT__X_X_h_s[ibra * 21 + 18] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 12] );

                    HRR_INT__X_X_g_p[ibra * 45 + 39] = HRR_INT__X_X_h_s[ibra * 21 + 13] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 13] );

                    HRR_INT__X_X_g_p[ibra * 45 + 40] = HRR_INT__X_X_h_s[ibra * 21 + 18] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 13] );

                    HRR_INT__X_X_g_p[ibra * 45 + 41] = HRR_INT__X_X_h_s[ibra * 21 + 19] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 13] );

                    HRR_INT__X_X_g_p[ibra * 45 + 42] = HRR_INT__X_X_h_s[ibra * 21 + 14] + ( hCD[0] * HRR_INT__X_X_g_s[ibra * 15 + 14] );

                    HRR_INT__X_X_g_p[ibra * 45 + 43] = HRR_INT__X_X_h_s[ibra * 21 + 19] + ( hCD[1] * HRR_INT__X_X_g_s[ibra * 15 + 14] );

                    HRR_INT__X_X_g_p[ibra * 45 + 44] = HRR_INT__X_X_h_s[ibra * 21 + 20] + ( hCD[2] * HRR_INT__X_X_g_s[ibra * 15 + 14] );

                }

}


