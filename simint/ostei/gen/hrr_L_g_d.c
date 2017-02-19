
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// KET: | g d )
// Steps: 90
//////////////////////////////////////////////

void HRR_L_g_d(double * const restrict HRR_INT__X_X_g_d,
                    double const * const restrict HRR_INT__X_X_g_p,
                    double const * const restrict HRR_INT__X_X_h_p,
                    const double hCD[3], const int ncart_bra)
{
    int ibra;

                for(ibra = 0; ibra < ncart_bra; ++ibra)
                {
                    HRR_INT__X_X_g_d[ibra * 90 + 0] = HRR_INT__X_X_h_p[ibra * 63 + 0] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 0] );

                    HRR_INT__X_X_g_d[ibra * 90 + 1] = HRR_INT__X_X_h_p[ibra * 63 + 3] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 0] );

                    HRR_INT__X_X_g_d[ibra * 90 + 2] = HRR_INT__X_X_h_p[ibra * 63 + 6] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 0] );

                    HRR_INT__X_X_g_d[ibra * 90 + 3] = HRR_INT__X_X_h_p[ibra * 63 + 4] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 1] );

                    HRR_INT__X_X_g_d[ibra * 90 + 4] = HRR_INT__X_X_h_p[ibra * 63 + 7] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 1] );

                    HRR_INT__X_X_g_d[ibra * 90 + 5] = HRR_INT__X_X_h_p[ibra * 63 + 8] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 2] );

                    HRR_INT__X_X_g_d[ibra * 90 + 6] = HRR_INT__X_X_h_p[ibra * 63 + 3] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 3] );

                    HRR_INT__X_X_g_d[ibra * 90 + 7] = HRR_INT__X_X_h_p[ibra * 63 + 9] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 3] );

                    HRR_INT__X_X_g_d[ibra * 90 + 8] = HRR_INT__X_X_h_p[ibra * 63 + 12] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 3] );

                    HRR_INT__X_X_g_d[ibra * 90 + 9] = HRR_INT__X_X_h_p[ibra * 63 + 10] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 4] );

                    HRR_INT__X_X_g_d[ibra * 90 + 10] = HRR_INT__X_X_h_p[ibra * 63 + 13] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 4] );

                    HRR_INT__X_X_g_d[ibra * 90 + 11] = HRR_INT__X_X_h_p[ibra * 63 + 14] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 5] );

                    HRR_INT__X_X_g_d[ibra * 90 + 12] = HRR_INT__X_X_h_p[ibra * 63 + 6] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 6] );

                    HRR_INT__X_X_g_d[ibra * 90 + 13] = HRR_INT__X_X_h_p[ibra * 63 + 12] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 6] );

                    HRR_INT__X_X_g_d[ibra * 90 + 14] = HRR_INT__X_X_h_p[ibra * 63 + 15] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 6] );

                    HRR_INT__X_X_g_d[ibra * 90 + 15] = HRR_INT__X_X_h_p[ibra * 63 + 13] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 7] );

                    HRR_INT__X_X_g_d[ibra * 90 + 16] = HRR_INT__X_X_h_p[ibra * 63 + 16] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 7] );

                    HRR_INT__X_X_g_d[ibra * 90 + 17] = HRR_INT__X_X_h_p[ibra * 63 + 17] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 8] );

                    HRR_INT__X_X_g_d[ibra * 90 + 18] = HRR_INT__X_X_h_p[ibra * 63 + 9] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 9] );

                    HRR_INT__X_X_g_d[ibra * 90 + 19] = HRR_INT__X_X_h_p[ibra * 63 + 18] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 9] );

                    HRR_INT__X_X_g_d[ibra * 90 + 20] = HRR_INT__X_X_h_p[ibra * 63 + 21] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 9] );

                    HRR_INT__X_X_g_d[ibra * 90 + 21] = HRR_INT__X_X_h_p[ibra * 63 + 19] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 10] );

                    HRR_INT__X_X_g_d[ibra * 90 + 22] = HRR_INT__X_X_h_p[ibra * 63 + 22] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 10] );

                    HRR_INT__X_X_g_d[ibra * 90 + 23] = HRR_INT__X_X_h_p[ibra * 63 + 23] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 11] );

                    HRR_INT__X_X_g_d[ibra * 90 + 24] = HRR_INT__X_X_h_p[ibra * 63 + 12] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 12] );

                    HRR_INT__X_X_g_d[ibra * 90 + 25] = HRR_INT__X_X_h_p[ibra * 63 + 21] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 12] );

                    HRR_INT__X_X_g_d[ibra * 90 + 26] = HRR_INT__X_X_h_p[ibra * 63 + 24] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 12] );

                    HRR_INT__X_X_g_d[ibra * 90 + 27] = HRR_INT__X_X_h_p[ibra * 63 + 22] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 13] );

                    HRR_INT__X_X_g_d[ibra * 90 + 28] = HRR_INT__X_X_h_p[ibra * 63 + 25] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 13] );

                    HRR_INT__X_X_g_d[ibra * 90 + 29] = HRR_INT__X_X_h_p[ibra * 63 + 26] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 14] );

                    HRR_INT__X_X_g_d[ibra * 90 + 30] = HRR_INT__X_X_h_p[ibra * 63 + 15] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 15] );

                    HRR_INT__X_X_g_d[ibra * 90 + 31] = HRR_INT__X_X_h_p[ibra * 63 + 24] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 15] );

                    HRR_INT__X_X_g_d[ibra * 90 + 32] = HRR_INT__X_X_h_p[ibra * 63 + 27] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 15] );

                    HRR_INT__X_X_g_d[ibra * 90 + 33] = HRR_INT__X_X_h_p[ibra * 63 + 25] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 16] );

                    HRR_INT__X_X_g_d[ibra * 90 + 34] = HRR_INT__X_X_h_p[ibra * 63 + 28] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 16] );

                    HRR_INT__X_X_g_d[ibra * 90 + 35] = HRR_INT__X_X_h_p[ibra * 63 + 29] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 17] );

                    HRR_INT__X_X_g_d[ibra * 90 + 36] = HRR_INT__X_X_h_p[ibra * 63 + 18] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 18] );

                    HRR_INT__X_X_g_d[ibra * 90 + 37] = HRR_INT__X_X_h_p[ibra * 63 + 30] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 18] );

                    HRR_INT__X_X_g_d[ibra * 90 + 38] = HRR_INT__X_X_h_p[ibra * 63 + 33] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 18] );

                    HRR_INT__X_X_g_d[ibra * 90 + 39] = HRR_INT__X_X_h_p[ibra * 63 + 31] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 19] );

                    HRR_INT__X_X_g_d[ibra * 90 + 40] = HRR_INT__X_X_h_p[ibra * 63 + 34] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 19] );

                    HRR_INT__X_X_g_d[ibra * 90 + 41] = HRR_INT__X_X_h_p[ibra * 63 + 35] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 20] );

                    HRR_INT__X_X_g_d[ibra * 90 + 42] = HRR_INT__X_X_h_p[ibra * 63 + 21] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 21] );

                    HRR_INT__X_X_g_d[ibra * 90 + 43] = HRR_INT__X_X_h_p[ibra * 63 + 33] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 21] );

                    HRR_INT__X_X_g_d[ibra * 90 + 44] = HRR_INT__X_X_h_p[ibra * 63 + 36] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 21] );

                    HRR_INT__X_X_g_d[ibra * 90 + 45] = HRR_INT__X_X_h_p[ibra * 63 + 34] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 22] );

                    HRR_INT__X_X_g_d[ibra * 90 + 46] = HRR_INT__X_X_h_p[ibra * 63 + 37] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 22] );

                    HRR_INT__X_X_g_d[ibra * 90 + 47] = HRR_INT__X_X_h_p[ibra * 63 + 38] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 23] );

                    HRR_INT__X_X_g_d[ibra * 90 + 48] = HRR_INT__X_X_h_p[ibra * 63 + 24] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 24] );

                    HRR_INT__X_X_g_d[ibra * 90 + 49] = HRR_INT__X_X_h_p[ibra * 63 + 36] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 24] );

                    HRR_INT__X_X_g_d[ibra * 90 + 50] = HRR_INT__X_X_h_p[ibra * 63 + 39] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 24] );

                    HRR_INT__X_X_g_d[ibra * 90 + 51] = HRR_INT__X_X_h_p[ibra * 63 + 37] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 25] );

                    HRR_INT__X_X_g_d[ibra * 90 + 52] = HRR_INT__X_X_h_p[ibra * 63 + 40] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 25] );

                    HRR_INT__X_X_g_d[ibra * 90 + 53] = HRR_INT__X_X_h_p[ibra * 63 + 41] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 26] );

                    HRR_INT__X_X_g_d[ibra * 90 + 54] = HRR_INT__X_X_h_p[ibra * 63 + 27] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 27] );

                    HRR_INT__X_X_g_d[ibra * 90 + 55] = HRR_INT__X_X_h_p[ibra * 63 + 39] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 27] );

                    HRR_INT__X_X_g_d[ibra * 90 + 56] = HRR_INT__X_X_h_p[ibra * 63 + 42] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 27] );

                    HRR_INT__X_X_g_d[ibra * 90 + 57] = HRR_INT__X_X_h_p[ibra * 63 + 40] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 28] );

                    HRR_INT__X_X_g_d[ibra * 90 + 58] = HRR_INT__X_X_h_p[ibra * 63 + 43] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 28] );

                    HRR_INT__X_X_g_d[ibra * 90 + 59] = HRR_INT__X_X_h_p[ibra * 63 + 44] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 29] );

                    HRR_INT__X_X_g_d[ibra * 90 + 60] = HRR_INT__X_X_h_p[ibra * 63 + 30] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 30] );

                    HRR_INT__X_X_g_d[ibra * 90 + 61] = HRR_INT__X_X_h_p[ibra * 63 + 45] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 30] );

                    HRR_INT__X_X_g_d[ibra * 90 + 62] = HRR_INT__X_X_h_p[ibra * 63 + 48] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 30] );

                    HRR_INT__X_X_g_d[ibra * 90 + 63] = HRR_INT__X_X_h_p[ibra * 63 + 46] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 31] );

                    HRR_INT__X_X_g_d[ibra * 90 + 64] = HRR_INT__X_X_h_p[ibra * 63 + 49] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 31] );

                    HRR_INT__X_X_g_d[ibra * 90 + 65] = HRR_INT__X_X_h_p[ibra * 63 + 50] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 32] );

                    HRR_INT__X_X_g_d[ibra * 90 + 66] = HRR_INT__X_X_h_p[ibra * 63 + 33] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 33] );

                    HRR_INT__X_X_g_d[ibra * 90 + 67] = HRR_INT__X_X_h_p[ibra * 63 + 48] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 33] );

                    HRR_INT__X_X_g_d[ibra * 90 + 68] = HRR_INT__X_X_h_p[ibra * 63 + 51] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 33] );

                    HRR_INT__X_X_g_d[ibra * 90 + 69] = HRR_INT__X_X_h_p[ibra * 63 + 49] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 34] );

                    HRR_INT__X_X_g_d[ibra * 90 + 70] = HRR_INT__X_X_h_p[ibra * 63 + 52] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 34] );

                    HRR_INT__X_X_g_d[ibra * 90 + 71] = HRR_INT__X_X_h_p[ibra * 63 + 53] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 35] );

                    HRR_INT__X_X_g_d[ibra * 90 + 72] = HRR_INT__X_X_h_p[ibra * 63 + 36] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 36] );

                    HRR_INT__X_X_g_d[ibra * 90 + 73] = HRR_INT__X_X_h_p[ibra * 63 + 51] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 36] );

                    HRR_INT__X_X_g_d[ibra * 90 + 74] = HRR_INT__X_X_h_p[ibra * 63 + 54] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 36] );

                    HRR_INT__X_X_g_d[ibra * 90 + 75] = HRR_INT__X_X_h_p[ibra * 63 + 52] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 37] );

                    HRR_INT__X_X_g_d[ibra * 90 + 76] = HRR_INT__X_X_h_p[ibra * 63 + 55] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 37] );

                    HRR_INT__X_X_g_d[ibra * 90 + 77] = HRR_INT__X_X_h_p[ibra * 63 + 56] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 38] );

                    HRR_INT__X_X_g_d[ibra * 90 + 78] = HRR_INT__X_X_h_p[ibra * 63 + 39] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 39] );

                    HRR_INT__X_X_g_d[ibra * 90 + 79] = HRR_INT__X_X_h_p[ibra * 63 + 54] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 39] );

                    HRR_INT__X_X_g_d[ibra * 90 + 80] = HRR_INT__X_X_h_p[ibra * 63 + 57] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 39] );

                    HRR_INT__X_X_g_d[ibra * 90 + 81] = HRR_INT__X_X_h_p[ibra * 63 + 55] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 40] );

                    HRR_INT__X_X_g_d[ibra * 90 + 82] = HRR_INT__X_X_h_p[ibra * 63 + 58] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 40] );

                    HRR_INT__X_X_g_d[ibra * 90 + 83] = HRR_INT__X_X_h_p[ibra * 63 + 59] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 41] );

                    HRR_INT__X_X_g_d[ibra * 90 + 84] = HRR_INT__X_X_h_p[ibra * 63 + 42] + ( hCD[0] * HRR_INT__X_X_g_p[ibra * 45 + 42] );

                    HRR_INT__X_X_g_d[ibra * 90 + 85] = HRR_INT__X_X_h_p[ibra * 63 + 57] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 42] );

                    HRR_INT__X_X_g_d[ibra * 90 + 86] = HRR_INT__X_X_h_p[ibra * 63 + 60] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 42] );

                    HRR_INT__X_X_g_d[ibra * 90 + 87] = HRR_INT__X_X_h_p[ibra * 63 + 58] + ( hCD[1] * HRR_INT__X_X_g_p[ibra * 45 + 43] );

                    HRR_INT__X_X_g_d[ibra * 90 + 88] = HRR_INT__X_X_h_p[ibra * 63 + 61] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 43] );

                    HRR_INT__X_X_g_d[ibra * 90 + 89] = HRR_INT__X_X_h_p[ibra * 63 + 62] + ( hCD[2] * HRR_INT__X_X_g_p[ibra * 45 + 44] );

                }

}


