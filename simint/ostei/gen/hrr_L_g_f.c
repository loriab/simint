
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// KET: | g f )
// Steps: 150
//////////////////////////////////////////////

void HRR_L_g_f(double * const restrict HRR_INT__X_X_g_f,
                    double const * const restrict HRR_INT__X_X_g_d,
                    double const * const restrict HRR_INT__X_X_h_d,
                    const double hCD[3], const int ncart_bra)
{
    int ibra;

                for(ibra = 0; ibra < ncart_bra; ++ibra)
                {
                    HRR_INT__X_X_g_f[ibra * 150 + 0] = HRR_INT__X_X_h_d[ibra * 126 + 0] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 0] );

                    HRR_INT__X_X_g_f[ibra * 150 + 1] = HRR_INT__X_X_h_d[ibra * 126 + 6] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 0] );

                    HRR_INT__X_X_g_f[ibra * 150 + 2] = HRR_INT__X_X_h_d[ibra * 126 + 12] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 0] );

                    HRR_INT__X_X_g_f[ibra * 150 + 3] = HRR_INT__X_X_h_d[ibra * 126 + 3] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 3] );

                    HRR_INT__X_X_g_f[ibra * 150 + 4] = HRR_INT__X_X_h_d[ibra * 126 + 13] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 1] );

                    HRR_INT__X_X_g_f[ibra * 150 + 5] = HRR_INT__X_X_h_d[ibra * 126 + 5] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 5] );

                    HRR_INT__X_X_g_f[ibra * 150 + 6] = HRR_INT__X_X_h_d[ibra * 126 + 9] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 3] );

                    HRR_INT__X_X_g_f[ibra * 150 + 7] = HRR_INT__X_X_h_d[ibra * 126 + 15] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 3] );

                    HRR_INT__X_X_g_f[ibra * 150 + 8] = HRR_INT__X_X_h_d[ibra * 126 + 11] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 5] );

                    HRR_INT__X_X_g_f[ibra * 150 + 9] = HRR_INT__X_X_h_d[ibra * 126 + 17] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 5] );

                    HRR_INT__X_X_g_f[ibra * 150 + 10] = HRR_INT__X_X_h_d[ibra * 126 + 6] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 6] );

                    HRR_INT__X_X_g_f[ibra * 150 + 11] = HRR_INT__X_X_h_d[ibra * 126 + 18] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 6] );

                    HRR_INT__X_X_g_f[ibra * 150 + 12] = HRR_INT__X_X_h_d[ibra * 126 + 24] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 6] );

                    HRR_INT__X_X_g_f[ibra * 150 + 13] = HRR_INT__X_X_h_d[ibra * 126 + 9] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 9] );

                    HRR_INT__X_X_g_f[ibra * 150 + 14] = HRR_INT__X_X_h_d[ibra * 126 + 25] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 7] );

                    HRR_INT__X_X_g_f[ibra * 150 + 15] = HRR_INT__X_X_h_d[ibra * 126 + 11] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 11] );

                    HRR_INT__X_X_g_f[ibra * 150 + 16] = HRR_INT__X_X_h_d[ibra * 126 + 21] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 9] );

                    HRR_INT__X_X_g_f[ibra * 150 + 17] = HRR_INT__X_X_h_d[ibra * 126 + 27] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 9] );

                    HRR_INT__X_X_g_f[ibra * 150 + 18] = HRR_INT__X_X_h_d[ibra * 126 + 23] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 11] );

                    HRR_INT__X_X_g_f[ibra * 150 + 19] = HRR_INT__X_X_h_d[ibra * 126 + 29] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 11] );

                    HRR_INT__X_X_g_f[ibra * 150 + 20] = HRR_INT__X_X_h_d[ibra * 126 + 12] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 12] );

                    HRR_INT__X_X_g_f[ibra * 150 + 21] = HRR_INT__X_X_h_d[ibra * 126 + 24] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 12] );

                    HRR_INT__X_X_g_f[ibra * 150 + 22] = HRR_INT__X_X_h_d[ibra * 126 + 30] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 12] );

                    HRR_INT__X_X_g_f[ibra * 150 + 23] = HRR_INT__X_X_h_d[ibra * 126 + 15] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 15] );

                    HRR_INT__X_X_g_f[ibra * 150 + 24] = HRR_INT__X_X_h_d[ibra * 126 + 31] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 13] );

                    HRR_INT__X_X_g_f[ibra * 150 + 25] = HRR_INT__X_X_h_d[ibra * 126 + 17] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 17] );

                    HRR_INT__X_X_g_f[ibra * 150 + 26] = HRR_INT__X_X_h_d[ibra * 126 + 27] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 15] );

                    HRR_INT__X_X_g_f[ibra * 150 + 27] = HRR_INT__X_X_h_d[ibra * 126 + 33] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 15] );

                    HRR_INT__X_X_g_f[ibra * 150 + 28] = HRR_INT__X_X_h_d[ibra * 126 + 29] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 17] );

                    HRR_INT__X_X_g_f[ibra * 150 + 29] = HRR_INT__X_X_h_d[ibra * 126 + 35] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 17] );

                    HRR_INT__X_X_g_f[ibra * 150 + 30] = HRR_INT__X_X_h_d[ibra * 126 + 18] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 18] );

                    HRR_INT__X_X_g_f[ibra * 150 + 31] = HRR_INT__X_X_h_d[ibra * 126 + 36] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 18] );

                    HRR_INT__X_X_g_f[ibra * 150 + 32] = HRR_INT__X_X_h_d[ibra * 126 + 42] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 18] );

                    HRR_INT__X_X_g_f[ibra * 150 + 33] = HRR_INT__X_X_h_d[ibra * 126 + 21] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 21] );

                    HRR_INT__X_X_g_f[ibra * 150 + 34] = HRR_INT__X_X_h_d[ibra * 126 + 43] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 19] );

                    HRR_INT__X_X_g_f[ibra * 150 + 35] = HRR_INT__X_X_h_d[ibra * 126 + 23] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 23] );

                    HRR_INT__X_X_g_f[ibra * 150 + 36] = HRR_INT__X_X_h_d[ibra * 126 + 39] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 21] );

                    HRR_INT__X_X_g_f[ibra * 150 + 37] = HRR_INT__X_X_h_d[ibra * 126 + 45] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 21] );

                    HRR_INT__X_X_g_f[ibra * 150 + 38] = HRR_INT__X_X_h_d[ibra * 126 + 41] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 23] );

                    HRR_INT__X_X_g_f[ibra * 150 + 39] = HRR_INT__X_X_h_d[ibra * 126 + 47] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 23] );

                    HRR_INT__X_X_g_f[ibra * 150 + 40] = HRR_INT__X_X_h_d[ibra * 126 + 24] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 24] );

                    HRR_INT__X_X_g_f[ibra * 150 + 41] = HRR_INT__X_X_h_d[ibra * 126 + 42] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 24] );

                    HRR_INT__X_X_g_f[ibra * 150 + 42] = HRR_INT__X_X_h_d[ibra * 126 + 48] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 24] );

                    HRR_INT__X_X_g_f[ibra * 150 + 43] = HRR_INT__X_X_h_d[ibra * 126 + 27] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 27] );

                    HRR_INT__X_X_g_f[ibra * 150 + 44] = HRR_INT__X_X_h_d[ibra * 126 + 49] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 25] );

                    HRR_INT__X_X_g_f[ibra * 150 + 45] = HRR_INT__X_X_h_d[ibra * 126 + 29] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 29] );

                    HRR_INT__X_X_g_f[ibra * 150 + 46] = HRR_INT__X_X_h_d[ibra * 126 + 45] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 27] );

                    HRR_INT__X_X_g_f[ibra * 150 + 47] = HRR_INT__X_X_h_d[ibra * 126 + 51] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 27] );

                    HRR_INT__X_X_g_f[ibra * 150 + 48] = HRR_INT__X_X_h_d[ibra * 126 + 47] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 29] );

                    HRR_INT__X_X_g_f[ibra * 150 + 49] = HRR_INT__X_X_h_d[ibra * 126 + 53] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 29] );

                    HRR_INT__X_X_g_f[ibra * 150 + 50] = HRR_INT__X_X_h_d[ibra * 126 + 30] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 30] );

                    HRR_INT__X_X_g_f[ibra * 150 + 51] = HRR_INT__X_X_h_d[ibra * 126 + 48] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 30] );

                    HRR_INT__X_X_g_f[ibra * 150 + 52] = HRR_INT__X_X_h_d[ibra * 126 + 54] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 30] );

                    HRR_INT__X_X_g_f[ibra * 150 + 53] = HRR_INT__X_X_h_d[ibra * 126 + 33] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 33] );

                    HRR_INT__X_X_g_f[ibra * 150 + 54] = HRR_INT__X_X_h_d[ibra * 126 + 55] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 31] );

                    HRR_INT__X_X_g_f[ibra * 150 + 55] = HRR_INT__X_X_h_d[ibra * 126 + 35] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 35] );

                    HRR_INT__X_X_g_f[ibra * 150 + 56] = HRR_INT__X_X_h_d[ibra * 126 + 51] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 33] );

                    HRR_INT__X_X_g_f[ibra * 150 + 57] = HRR_INT__X_X_h_d[ibra * 126 + 57] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 33] );

                    HRR_INT__X_X_g_f[ibra * 150 + 58] = HRR_INT__X_X_h_d[ibra * 126 + 53] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 35] );

                    HRR_INT__X_X_g_f[ibra * 150 + 59] = HRR_INT__X_X_h_d[ibra * 126 + 59] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 35] );

                    HRR_INT__X_X_g_f[ibra * 150 + 60] = HRR_INT__X_X_h_d[ibra * 126 + 36] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 36] );

                    HRR_INT__X_X_g_f[ibra * 150 + 61] = HRR_INT__X_X_h_d[ibra * 126 + 60] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 36] );

                    HRR_INT__X_X_g_f[ibra * 150 + 62] = HRR_INT__X_X_h_d[ibra * 126 + 66] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 36] );

                    HRR_INT__X_X_g_f[ibra * 150 + 63] = HRR_INT__X_X_h_d[ibra * 126 + 39] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 39] );

                    HRR_INT__X_X_g_f[ibra * 150 + 64] = HRR_INT__X_X_h_d[ibra * 126 + 67] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 37] );

                    HRR_INT__X_X_g_f[ibra * 150 + 65] = HRR_INT__X_X_h_d[ibra * 126 + 41] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 41] );

                    HRR_INT__X_X_g_f[ibra * 150 + 66] = HRR_INT__X_X_h_d[ibra * 126 + 63] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 39] );

                    HRR_INT__X_X_g_f[ibra * 150 + 67] = HRR_INT__X_X_h_d[ibra * 126 + 69] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 39] );

                    HRR_INT__X_X_g_f[ibra * 150 + 68] = HRR_INT__X_X_h_d[ibra * 126 + 65] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 41] );

                    HRR_INT__X_X_g_f[ibra * 150 + 69] = HRR_INT__X_X_h_d[ibra * 126 + 71] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 41] );

                    HRR_INT__X_X_g_f[ibra * 150 + 70] = HRR_INT__X_X_h_d[ibra * 126 + 42] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 42] );

                    HRR_INT__X_X_g_f[ibra * 150 + 71] = HRR_INT__X_X_h_d[ibra * 126 + 66] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 42] );

                    HRR_INT__X_X_g_f[ibra * 150 + 72] = HRR_INT__X_X_h_d[ibra * 126 + 72] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 42] );

                    HRR_INT__X_X_g_f[ibra * 150 + 73] = HRR_INT__X_X_h_d[ibra * 126 + 45] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 45] );

                    HRR_INT__X_X_g_f[ibra * 150 + 74] = HRR_INT__X_X_h_d[ibra * 126 + 73] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 43] );

                    HRR_INT__X_X_g_f[ibra * 150 + 75] = HRR_INT__X_X_h_d[ibra * 126 + 47] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 47] );

                    HRR_INT__X_X_g_f[ibra * 150 + 76] = HRR_INT__X_X_h_d[ibra * 126 + 69] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 45] );

                    HRR_INT__X_X_g_f[ibra * 150 + 77] = HRR_INT__X_X_h_d[ibra * 126 + 75] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 45] );

                    HRR_INT__X_X_g_f[ibra * 150 + 78] = HRR_INT__X_X_h_d[ibra * 126 + 71] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 47] );

                    HRR_INT__X_X_g_f[ibra * 150 + 79] = HRR_INT__X_X_h_d[ibra * 126 + 77] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 47] );

                    HRR_INT__X_X_g_f[ibra * 150 + 80] = HRR_INT__X_X_h_d[ibra * 126 + 48] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 48] );

                    HRR_INT__X_X_g_f[ibra * 150 + 81] = HRR_INT__X_X_h_d[ibra * 126 + 72] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 48] );

                    HRR_INT__X_X_g_f[ibra * 150 + 82] = HRR_INT__X_X_h_d[ibra * 126 + 78] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 48] );

                    HRR_INT__X_X_g_f[ibra * 150 + 83] = HRR_INT__X_X_h_d[ibra * 126 + 51] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 51] );

                    HRR_INT__X_X_g_f[ibra * 150 + 84] = HRR_INT__X_X_h_d[ibra * 126 + 79] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 49] );

                    HRR_INT__X_X_g_f[ibra * 150 + 85] = HRR_INT__X_X_h_d[ibra * 126 + 53] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 53] );

                    HRR_INT__X_X_g_f[ibra * 150 + 86] = HRR_INT__X_X_h_d[ibra * 126 + 75] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 51] );

                    HRR_INT__X_X_g_f[ibra * 150 + 87] = HRR_INT__X_X_h_d[ibra * 126 + 81] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 51] );

                    HRR_INT__X_X_g_f[ibra * 150 + 88] = HRR_INT__X_X_h_d[ibra * 126 + 77] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 53] );

                    HRR_INT__X_X_g_f[ibra * 150 + 89] = HRR_INT__X_X_h_d[ibra * 126 + 83] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 53] );

                    HRR_INT__X_X_g_f[ibra * 150 + 90] = HRR_INT__X_X_h_d[ibra * 126 + 54] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 54] );

                    HRR_INT__X_X_g_f[ibra * 150 + 91] = HRR_INT__X_X_h_d[ibra * 126 + 78] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 54] );

                    HRR_INT__X_X_g_f[ibra * 150 + 92] = HRR_INT__X_X_h_d[ibra * 126 + 84] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 54] );

                    HRR_INT__X_X_g_f[ibra * 150 + 93] = HRR_INT__X_X_h_d[ibra * 126 + 57] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 57] );

                    HRR_INT__X_X_g_f[ibra * 150 + 94] = HRR_INT__X_X_h_d[ibra * 126 + 85] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 55] );

                    HRR_INT__X_X_g_f[ibra * 150 + 95] = HRR_INT__X_X_h_d[ibra * 126 + 59] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 59] );

                    HRR_INT__X_X_g_f[ibra * 150 + 96] = HRR_INT__X_X_h_d[ibra * 126 + 81] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 57] );

                    HRR_INT__X_X_g_f[ibra * 150 + 97] = HRR_INT__X_X_h_d[ibra * 126 + 87] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 57] );

                    HRR_INT__X_X_g_f[ibra * 150 + 98] = HRR_INT__X_X_h_d[ibra * 126 + 83] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 59] );

                    HRR_INT__X_X_g_f[ibra * 150 + 99] = HRR_INT__X_X_h_d[ibra * 126 + 89] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 59] );

                    HRR_INT__X_X_g_f[ibra * 150 + 100] = HRR_INT__X_X_h_d[ibra * 126 + 60] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 60] );

                    HRR_INT__X_X_g_f[ibra * 150 + 101] = HRR_INT__X_X_h_d[ibra * 126 + 90] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 60] );

                    HRR_INT__X_X_g_f[ibra * 150 + 102] = HRR_INT__X_X_h_d[ibra * 126 + 96] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 60] );

                    HRR_INT__X_X_g_f[ibra * 150 + 103] = HRR_INT__X_X_h_d[ibra * 126 + 63] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 63] );

                    HRR_INT__X_X_g_f[ibra * 150 + 104] = HRR_INT__X_X_h_d[ibra * 126 + 97] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 61] );

                    HRR_INT__X_X_g_f[ibra * 150 + 105] = HRR_INT__X_X_h_d[ibra * 126 + 65] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 65] );

                    HRR_INT__X_X_g_f[ibra * 150 + 106] = HRR_INT__X_X_h_d[ibra * 126 + 93] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 63] );

                    HRR_INT__X_X_g_f[ibra * 150 + 107] = HRR_INT__X_X_h_d[ibra * 126 + 99] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 63] );

                    HRR_INT__X_X_g_f[ibra * 150 + 108] = HRR_INT__X_X_h_d[ibra * 126 + 95] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 65] );

                    HRR_INT__X_X_g_f[ibra * 150 + 109] = HRR_INT__X_X_h_d[ibra * 126 + 101] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 65] );

                    HRR_INT__X_X_g_f[ibra * 150 + 110] = HRR_INT__X_X_h_d[ibra * 126 + 66] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 66] );

                    HRR_INT__X_X_g_f[ibra * 150 + 111] = HRR_INT__X_X_h_d[ibra * 126 + 96] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 66] );

                    HRR_INT__X_X_g_f[ibra * 150 + 112] = HRR_INT__X_X_h_d[ibra * 126 + 102] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 66] );

                    HRR_INT__X_X_g_f[ibra * 150 + 113] = HRR_INT__X_X_h_d[ibra * 126 + 69] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 69] );

                    HRR_INT__X_X_g_f[ibra * 150 + 114] = HRR_INT__X_X_h_d[ibra * 126 + 103] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 67] );

                    HRR_INT__X_X_g_f[ibra * 150 + 115] = HRR_INT__X_X_h_d[ibra * 126 + 71] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 71] );

                    HRR_INT__X_X_g_f[ibra * 150 + 116] = HRR_INT__X_X_h_d[ibra * 126 + 99] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 69] );

                    HRR_INT__X_X_g_f[ibra * 150 + 117] = HRR_INT__X_X_h_d[ibra * 126 + 105] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 69] );

                    HRR_INT__X_X_g_f[ibra * 150 + 118] = HRR_INT__X_X_h_d[ibra * 126 + 101] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 71] );

                    HRR_INT__X_X_g_f[ibra * 150 + 119] = HRR_INT__X_X_h_d[ibra * 126 + 107] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 71] );

                    HRR_INT__X_X_g_f[ibra * 150 + 120] = HRR_INT__X_X_h_d[ibra * 126 + 72] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 72] );

                    HRR_INT__X_X_g_f[ibra * 150 + 121] = HRR_INT__X_X_h_d[ibra * 126 + 102] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 72] );

                    HRR_INT__X_X_g_f[ibra * 150 + 122] = HRR_INT__X_X_h_d[ibra * 126 + 108] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 72] );

                    HRR_INT__X_X_g_f[ibra * 150 + 123] = HRR_INT__X_X_h_d[ibra * 126 + 75] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 75] );

                    HRR_INT__X_X_g_f[ibra * 150 + 124] = HRR_INT__X_X_h_d[ibra * 126 + 109] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 73] );

                    HRR_INT__X_X_g_f[ibra * 150 + 125] = HRR_INT__X_X_h_d[ibra * 126 + 77] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 77] );

                    HRR_INT__X_X_g_f[ibra * 150 + 126] = HRR_INT__X_X_h_d[ibra * 126 + 105] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 75] );

                    HRR_INT__X_X_g_f[ibra * 150 + 127] = HRR_INT__X_X_h_d[ibra * 126 + 111] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 75] );

                    HRR_INT__X_X_g_f[ibra * 150 + 128] = HRR_INT__X_X_h_d[ibra * 126 + 107] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 77] );

                    HRR_INT__X_X_g_f[ibra * 150 + 129] = HRR_INT__X_X_h_d[ibra * 126 + 113] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 77] );

                    HRR_INT__X_X_g_f[ibra * 150 + 130] = HRR_INT__X_X_h_d[ibra * 126 + 78] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 78] );

                    HRR_INT__X_X_g_f[ibra * 150 + 131] = HRR_INT__X_X_h_d[ibra * 126 + 108] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 78] );

                    HRR_INT__X_X_g_f[ibra * 150 + 132] = HRR_INT__X_X_h_d[ibra * 126 + 114] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 78] );

                    HRR_INT__X_X_g_f[ibra * 150 + 133] = HRR_INT__X_X_h_d[ibra * 126 + 81] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 81] );

                    HRR_INT__X_X_g_f[ibra * 150 + 134] = HRR_INT__X_X_h_d[ibra * 126 + 115] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 79] );

                    HRR_INT__X_X_g_f[ibra * 150 + 135] = HRR_INT__X_X_h_d[ibra * 126 + 83] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 83] );

                    HRR_INT__X_X_g_f[ibra * 150 + 136] = HRR_INT__X_X_h_d[ibra * 126 + 111] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 81] );

                    HRR_INT__X_X_g_f[ibra * 150 + 137] = HRR_INT__X_X_h_d[ibra * 126 + 117] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 81] );

                    HRR_INT__X_X_g_f[ibra * 150 + 138] = HRR_INT__X_X_h_d[ibra * 126 + 113] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 83] );

                    HRR_INT__X_X_g_f[ibra * 150 + 139] = HRR_INT__X_X_h_d[ibra * 126 + 119] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 83] );

                    HRR_INT__X_X_g_f[ibra * 150 + 140] = HRR_INT__X_X_h_d[ibra * 126 + 84] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 84] );

                    HRR_INT__X_X_g_f[ibra * 150 + 141] = HRR_INT__X_X_h_d[ibra * 126 + 114] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 84] );

                    HRR_INT__X_X_g_f[ibra * 150 + 142] = HRR_INT__X_X_h_d[ibra * 126 + 120] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 84] );

                    HRR_INT__X_X_g_f[ibra * 150 + 143] = HRR_INT__X_X_h_d[ibra * 126 + 87] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 87] );

                    HRR_INT__X_X_g_f[ibra * 150 + 144] = HRR_INT__X_X_h_d[ibra * 126 + 121] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 85] );

                    HRR_INT__X_X_g_f[ibra * 150 + 145] = HRR_INT__X_X_h_d[ibra * 126 + 89] + ( hCD[0] * HRR_INT__X_X_g_d[ibra * 90 + 89] );

                    HRR_INT__X_X_g_f[ibra * 150 + 146] = HRR_INT__X_X_h_d[ibra * 126 + 117] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 87] );

                    HRR_INT__X_X_g_f[ibra * 150 + 147] = HRR_INT__X_X_h_d[ibra * 126 + 123] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 87] );

                    HRR_INT__X_X_g_f[ibra * 150 + 148] = HRR_INT__X_X_h_d[ibra * 126 + 119] + ( hCD[1] * HRR_INT__X_X_g_d[ibra * 90 + 89] );

                    HRR_INT__X_X_g_f[ibra * 150 + 149] = HRR_INT__X_X_h_d[ibra * 126 + 125] + ( hCD[2] * HRR_INT__X_X_g_d[ibra * 90 + 89] );

                }

}


