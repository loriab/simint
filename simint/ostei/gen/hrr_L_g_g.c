
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// KET: | g g )
// Steps: 225
//////////////////////////////////////////////

void HRR_L_g_g(double * const restrict HRR_INT__X_X_g_g,
                    double const * const restrict HRR_INT__X_X_g_f,
                    double const * const restrict HRR_INT__X_X_h_f,
                    const double hCD[3], const int ncart_bra)
{
    int ibra;

                for(ibra = 0; ibra < ncart_bra; ++ibra)
                {
                    HRR_INT__X_X_g_g[ibra * 225 + 0] = HRR_INT__X_X_h_f[ibra * 210 + 0] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 0] );

                    HRR_INT__X_X_g_g[ibra * 225 + 1] = HRR_INT__X_X_h_f[ibra * 210 + 10] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 0] );

                    HRR_INT__X_X_g_g[ibra * 225 + 2] = HRR_INT__X_X_h_f[ibra * 210 + 20] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 0] );

                    HRR_INT__X_X_g_g[ibra * 225 + 3] = HRR_INT__X_X_h_f[ibra * 210 + 11] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 1] );

                    HRR_INT__X_X_g_g[ibra * 225 + 4] = HRR_INT__X_X_h_f[ibra * 210 + 21] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 1] );

                    HRR_INT__X_X_g_g[ibra * 225 + 5] = HRR_INT__X_X_h_f[ibra * 210 + 22] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 2] );

                    HRR_INT__X_X_g_g[ibra * 225 + 6] = HRR_INT__X_X_h_f[ibra * 210 + 6] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 6] );

                    HRR_INT__X_X_g_g[ibra * 225 + 7] = HRR_INT__X_X_h_f[ibra * 210 + 23] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 3] );

                    HRR_INT__X_X_g_g[ibra * 225 + 8] = HRR_INT__X_X_h_f[ibra * 210 + 15] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 5] );

                    HRR_INT__X_X_g_g[ibra * 225 + 9] = HRR_INT__X_X_h_f[ibra * 210 + 9] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 9] );

                    HRR_INT__X_X_g_g[ibra * 225 + 10] = HRR_INT__X_X_h_f[ibra * 210 + 16] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 6] );

                    HRR_INT__X_X_g_g[ibra * 225 + 11] = HRR_INT__X_X_h_f[ibra * 210 + 26] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 6] );

                    HRR_INT__X_X_g_g[ibra * 225 + 12] = HRR_INT__X_X_h_f[ibra * 210 + 27] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 7] );

                    HRR_INT__X_X_g_g[ibra * 225 + 13] = HRR_INT__X_X_h_f[ibra * 210 + 19] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 9] );

                    HRR_INT__X_X_g_g[ibra * 225 + 14] = HRR_INT__X_X_h_f[ibra * 210 + 29] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 9] );

                    HRR_INT__X_X_g_g[ibra * 225 + 15] = HRR_INT__X_X_h_f[ibra * 210 + 10] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 10] );

                    HRR_INT__X_X_g_g[ibra * 225 + 16] = HRR_INT__X_X_h_f[ibra * 210 + 30] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 10] );

                    HRR_INT__X_X_g_g[ibra * 225 + 17] = HRR_INT__X_X_h_f[ibra * 210 + 40] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 10] );

                    HRR_INT__X_X_g_g[ibra * 225 + 18] = HRR_INT__X_X_h_f[ibra * 210 + 31] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 11] );

                    HRR_INT__X_X_g_g[ibra * 225 + 19] = HRR_INT__X_X_h_f[ibra * 210 + 41] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 11] );

                    HRR_INT__X_X_g_g[ibra * 225 + 20] = HRR_INT__X_X_h_f[ibra * 210 + 42] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 12] );

                    HRR_INT__X_X_g_g[ibra * 225 + 21] = HRR_INT__X_X_h_f[ibra * 210 + 16] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 16] );

                    HRR_INT__X_X_g_g[ibra * 225 + 22] = HRR_INT__X_X_h_f[ibra * 210 + 43] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 13] );

                    HRR_INT__X_X_g_g[ibra * 225 + 23] = HRR_INT__X_X_h_f[ibra * 210 + 35] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 15] );

                    HRR_INT__X_X_g_g[ibra * 225 + 24] = HRR_INT__X_X_h_f[ibra * 210 + 19] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 19] );

                    HRR_INT__X_X_g_g[ibra * 225 + 25] = HRR_INT__X_X_h_f[ibra * 210 + 36] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 16] );

                    HRR_INT__X_X_g_g[ibra * 225 + 26] = HRR_INT__X_X_h_f[ibra * 210 + 46] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 16] );

                    HRR_INT__X_X_g_g[ibra * 225 + 27] = HRR_INT__X_X_h_f[ibra * 210 + 47] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 17] );

                    HRR_INT__X_X_g_g[ibra * 225 + 28] = HRR_INT__X_X_h_f[ibra * 210 + 39] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 19] );

                    HRR_INT__X_X_g_g[ibra * 225 + 29] = HRR_INT__X_X_h_f[ibra * 210 + 49] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 19] );

                    HRR_INT__X_X_g_g[ibra * 225 + 30] = HRR_INT__X_X_h_f[ibra * 210 + 20] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 20] );

                    HRR_INT__X_X_g_g[ibra * 225 + 31] = HRR_INT__X_X_h_f[ibra * 210 + 40] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 20] );

                    HRR_INT__X_X_g_g[ibra * 225 + 32] = HRR_INT__X_X_h_f[ibra * 210 + 50] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 20] );

                    HRR_INT__X_X_g_g[ibra * 225 + 33] = HRR_INT__X_X_h_f[ibra * 210 + 41] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 21] );

                    HRR_INT__X_X_g_g[ibra * 225 + 34] = HRR_INT__X_X_h_f[ibra * 210 + 51] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 21] );

                    HRR_INT__X_X_g_g[ibra * 225 + 35] = HRR_INT__X_X_h_f[ibra * 210 + 52] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 22] );

                    HRR_INT__X_X_g_g[ibra * 225 + 36] = HRR_INT__X_X_h_f[ibra * 210 + 26] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 26] );

                    HRR_INT__X_X_g_g[ibra * 225 + 37] = HRR_INT__X_X_h_f[ibra * 210 + 53] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 23] );

                    HRR_INT__X_X_g_g[ibra * 225 + 38] = HRR_INT__X_X_h_f[ibra * 210 + 45] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 25] );

                    HRR_INT__X_X_g_g[ibra * 225 + 39] = HRR_INT__X_X_h_f[ibra * 210 + 29] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 29] );

                    HRR_INT__X_X_g_g[ibra * 225 + 40] = HRR_INT__X_X_h_f[ibra * 210 + 46] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 26] );

                    HRR_INT__X_X_g_g[ibra * 225 + 41] = HRR_INT__X_X_h_f[ibra * 210 + 56] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 26] );

                    HRR_INT__X_X_g_g[ibra * 225 + 42] = HRR_INT__X_X_h_f[ibra * 210 + 57] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 27] );

                    HRR_INT__X_X_g_g[ibra * 225 + 43] = HRR_INT__X_X_h_f[ibra * 210 + 49] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 29] );

                    HRR_INT__X_X_g_g[ibra * 225 + 44] = HRR_INT__X_X_h_f[ibra * 210 + 59] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 29] );

                    HRR_INT__X_X_g_g[ibra * 225 + 45] = HRR_INT__X_X_h_f[ibra * 210 + 30] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 30] );

                    HRR_INT__X_X_g_g[ibra * 225 + 46] = HRR_INT__X_X_h_f[ibra * 210 + 60] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 30] );

                    HRR_INT__X_X_g_g[ibra * 225 + 47] = HRR_INT__X_X_h_f[ibra * 210 + 70] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 30] );

                    HRR_INT__X_X_g_g[ibra * 225 + 48] = HRR_INT__X_X_h_f[ibra * 210 + 61] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 31] );

                    HRR_INT__X_X_g_g[ibra * 225 + 49] = HRR_INT__X_X_h_f[ibra * 210 + 71] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 31] );

                    HRR_INT__X_X_g_g[ibra * 225 + 50] = HRR_INT__X_X_h_f[ibra * 210 + 72] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 32] );

                    HRR_INT__X_X_g_g[ibra * 225 + 51] = HRR_INT__X_X_h_f[ibra * 210 + 36] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 36] );

                    HRR_INT__X_X_g_g[ibra * 225 + 52] = HRR_INT__X_X_h_f[ibra * 210 + 73] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 33] );

                    HRR_INT__X_X_g_g[ibra * 225 + 53] = HRR_INT__X_X_h_f[ibra * 210 + 65] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 35] );

                    HRR_INT__X_X_g_g[ibra * 225 + 54] = HRR_INT__X_X_h_f[ibra * 210 + 39] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 39] );

                    HRR_INT__X_X_g_g[ibra * 225 + 55] = HRR_INT__X_X_h_f[ibra * 210 + 66] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 36] );

                    HRR_INT__X_X_g_g[ibra * 225 + 56] = HRR_INT__X_X_h_f[ibra * 210 + 76] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 36] );

                    HRR_INT__X_X_g_g[ibra * 225 + 57] = HRR_INT__X_X_h_f[ibra * 210 + 77] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 37] );

                    HRR_INT__X_X_g_g[ibra * 225 + 58] = HRR_INT__X_X_h_f[ibra * 210 + 69] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 39] );

                    HRR_INT__X_X_g_g[ibra * 225 + 59] = HRR_INT__X_X_h_f[ibra * 210 + 79] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 39] );

                    HRR_INT__X_X_g_g[ibra * 225 + 60] = HRR_INT__X_X_h_f[ibra * 210 + 40] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 40] );

                    HRR_INT__X_X_g_g[ibra * 225 + 61] = HRR_INT__X_X_h_f[ibra * 210 + 70] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 40] );

                    HRR_INT__X_X_g_g[ibra * 225 + 62] = HRR_INT__X_X_h_f[ibra * 210 + 80] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 40] );

                    HRR_INT__X_X_g_g[ibra * 225 + 63] = HRR_INT__X_X_h_f[ibra * 210 + 71] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 41] );

                    HRR_INT__X_X_g_g[ibra * 225 + 64] = HRR_INT__X_X_h_f[ibra * 210 + 81] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 41] );

                    HRR_INT__X_X_g_g[ibra * 225 + 65] = HRR_INT__X_X_h_f[ibra * 210 + 82] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 42] );

                    HRR_INT__X_X_g_g[ibra * 225 + 66] = HRR_INT__X_X_h_f[ibra * 210 + 46] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 46] );

                    HRR_INT__X_X_g_g[ibra * 225 + 67] = HRR_INT__X_X_h_f[ibra * 210 + 83] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 43] );

                    HRR_INT__X_X_g_g[ibra * 225 + 68] = HRR_INT__X_X_h_f[ibra * 210 + 75] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 45] );

                    HRR_INT__X_X_g_g[ibra * 225 + 69] = HRR_INT__X_X_h_f[ibra * 210 + 49] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 49] );

                    HRR_INT__X_X_g_g[ibra * 225 + 70] = HRR_INT__X_X_h_f[ibra * 210 + 76] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 46] );

                    HRR_INT__X_X_g_g[ibra * 225 + 71] = HRR_INT__X_X_h_f[ibra * 210 + 86] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 46] );

                    HRR_INT__X_X_g_g[ibra * 225 + 72] = HRR_INT__X_X_h_f[ibra * 210 + 87] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 47] );

                    HRR_INT__X_X_g_g[ibra * 225 + 73] = HRR_INT__X_X_h_f[ibra * 210 + 79] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 49] );

                    HRR_INT__X_X_g_g[ibra * 225 + 74] = HRR_INT__X_X_h_f[ibra * 210 + 89] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 49] );

                    HRR_INT__X_X_g_g[ibra * 225 + 75] = HRR_INT__X_X_h_f[ibra * 210 + 50] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 50] );

                    HRR_INT__X_X_g_g[ibra * 225 + 76] = HRR_INT__X_X_h_f[ibra * 210 + 80] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 50] );

                    HRR_INT__X_X_g_g[ibra * 225 + 77] = HRR_INT__X_X_h_f[ibra * 210 + 90] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 50] );

                    HRR_INT__X_X_g_g[ibra * 225 + 78] = HRR_INT__X_X_h_f[ibra * 210 + 81] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 51] );

                    HRR_INT__X_X_g_g[ibra * 225 + 79] = HRR_INT__X_X_h_f[ibra * 210 + 91] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 51] );

                    HRR_INT__X_X_g_g[ibra * 225 + 80] = HRR_INT__X_X_h_f[ibra * 210 + 92] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 52] );

                    HRR_INT__X_X_g_g[ibra * 225 + 81] = HRR_INT__X_X_h_f[ibra * 210 + 56] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 56] );

                    HRR_INT__X_X_g_g[ibra * 225 + 82] = HRR_INT__X_X_h_f[ibra * 210 + 93] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 53] );

                    HRR_INT__X_X_g_g[ibra * 225 + 83] = HRR_INT__X_X_h_f[ibra * 210 + 85] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 55] );

                    HRR_INT__X_X_g_g[ibra * 225 + 84] = HRR_INT__X_X_h_f[ibra * 210 + 59] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 59] );

                    HRR_INT__X_X_g_g[ibra * 225 + 85] = HRR_INT__X_X_h_f[ibra * 210 + 86] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 56] );

                    HRR_INT__X_X_g_g[ibra * 225 + 86] = HRR_INT__X_X_h_f[ibra * 210 + 96] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 56] );

                    HRR_INT__X_X_g_g[ibra * 225 + 87] = HRR_INT__X_X_h_f[ibra * 210 + 97] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 57] );

                    HRR_INT__X_X_g_g[ibra * 225 + 88] = HRR_INT__X_X_h_f[ibra * 210 + 89] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 59] );

                    HRR_INT__X_X_g_g[ibra * 225 + 89] = HRR_INT__X_X_h_f[ibra * 210 + 99] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 59] );

                    HRR_INT__X_X_g_g[ibra * 225 + 90] = HRR_INT__X_X_h_f[ibra * 210 + 60] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 60] );

                    HRR_INT__X_X_g_g[ibra * 225 + 91] = HRR_INT__X_X_h_f[ibra * 210 + 100] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 60] );

                    HRR_INT__X_X_g_g[ibra * 225 + 92] = HRR_INT__X_X_h_f[ibra * 210 + 110] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 60] );

                    HRR_INT__X_X_g_g[ibra * 225 + 93] = HRR_INT__X_X_h_f[ibra * 210 + 101] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 61] );

                    HRR_INT__X_X_g_g[ibra * 225 + 94] = HRR_INT__X_X_h_f[ibra * 210 + 111] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 61] );

                    HRR_INT__X_X_g_g[ibra * 225 + 95] = HRR_INT__X_X_h_f[ibra * 210 + 112] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 62] );

                    HRR_INT__X_X_g_g[ibra * 225 + 96] = HRR_INT__X_X_h_f[ibra * 210 + 66] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 66] );

                    HRR_INT__X_X_g_g[ibra * 225 + 97] = HRR_INT__X_X_h_f[ibra * 210 + 113] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 63] );

                    HRR_INT__X_X_g_g[ibra * 225 + 98] = HRR_INT__X_X_h_f[ibra * 210 + 105] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 65] );

                    HRR_INT__X_X_g_g[ibra * 225 + 99] = HRR_INT__X_X_h_f[ibra * 210 + 69] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 69] );

                    HRR_INT__X_X_g_g[ibra * 225 + 100] = HRR_INT__X_X_h_f[ibra * 210 + 106] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 66] );

                    HRR_INT__X_X_g_g[ibra * 225 + 101] = HRR_INT__X_X_h_f[ibra * 210 + 116] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 66] );

                    HRR_INT__X_X_g_g[ibra * 225 + 102] = HRR_INT__X_X_h_f[ibra * 210 + 117] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 67] );

                    HRR_INT__X_X_g_g[ibra * 225 + 103] = HRR_INT__X_X_h_f[ibra * 210 + 109] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 69] );

                    HRR_INT__X_X_g_g[ibra * 225 + 104] = HRR_INT__X_X_h_f[ibra * 210 + 119] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 69] );

                    HRR_INT__X_X_g_g[ibra * 225 + 105] = HRR_INT__X_X_h_f[ibra * 210 + 70] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 70] );

                    HRR_INT__X_X_g_g[ibra * 225 + 106] = HRR_INT__X_X_h_f[ibra * 210 + 110] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 70] );

                    HRR_INT__X_X_g_g[ibra * 225 + 107] = HRR_INT__X_X_h_f[ibra * 210 + 120] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 70] );

                    HRR_INT__X_X_g_g[ibra * 225 + 108] = HRR_INT__X_X_h_f[ibra * 210 + 111] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 71] );

                    HRR_INT__X_X_g_g[ibra * 225 + 109] = HRR_INT__X_X_h_f[ibra * 210 + 121] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 71] );

                    HRR_INT__X_X_g_g[ibra * 225 + 110] = HRR_INT__X_X_h_f[ibra * 210 + 122] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 72] );

                    HRR_INT__X_X_g_g[ibra * 225 + 111] = HRR_INT__X_X_h_f[ibra * 210 + 76] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 76] );

                    HRR_INT__X_X_g_g[ibra * 225 + 112] = HRR_INT__X_X_h_f[ibra * 210 + 123] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 73] );

                    HRR_INT__X_X_g_g[ibra * 225 + 113] = HRR_INT__X_X_h_f[ibra * 210 + 115] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 75] );

                    HRR_INT__X_X_g_g[ibra * 225 + 114] = HRR_INT__X_X_h_f[ibra * 210 + 79] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 79] );

                    HRR_INT__X_X_g_g[ibra * 225 + 115] = HRR_INT__X_X_h_f[ibra * 210 + 116] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 76] );

                    HRR_INT__X_X_g_g[ibra * 225 + 116] = HRR_INT__X_X_h_f[ibra * 210 + 126] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 76] );

                    HRR_INT__X_X_g_g[ibra * 225 + 117] = HRR_INT__X_X_h_f[ibra * 210 + 127] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 77] );

                    HRR_INT__X_X_g_g[ibra * 225 + 118] = HRR_INT__X_X_h_f[ibra * 210 + 119] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 79] );

                    HRR_INT__X_X_g_g[ibra * 225 + 119] = HRR_INT__X_X_h_f[ibra * 210 + 129] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 79] );

                    HRR_INT__X_X_g_g[ibra * 225 + 120] = HRR_INT__X_X_h_f[ibra * 210 + 80] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 80] );

                    HRR_INT__X_X_g_g[ibra * 225 + 121] = HRR_INT__X_X_h_f[ibra * 210 + 120] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 80] );

                    HRR_INT__X_X_g_g[ibra * 225 + 122] = HRR_INT__X_X_h_f[ibra * 210 + 130] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 80] );

                    HRR_INT__X_X_g_g[ibra * 225 + 123] = HRR_INT__X_X_h_f[ibra * 210 + 121] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 81] );

                    HRR_INT__X_X_g_g[ibra * 225 + 124] = HRR_INT__X_X_h_f[ibra * 210 + 131] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 81] );

                    HRR_INT__X_X_g_g[ibra * 225 + 125] = HRR_INT__X_X_h_f[ibra * 210 + 132] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 82] );

                    HRR_INT__X_X_g_g[ibra * 225 + 126] = HRR_INT__X_X_h_f[ibra * 210 + 86] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 86] );

                    HRR_INT__X_X_g_g[ibra * 225 + 127] = HRR_INT__X_X_h_f[ibra * 210 + 133] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 83] );

                    HRR_INT__X_X_g_g[ibra * 225 + 128] = HRR_INT__X_X_h_f[ibra * 210 + 125] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 85] );

                    HRR_INT__X_X_g_g[ibra * 225 + 129] = HRR_INT__X_X_h_f[ibra * 210 + 89] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 89] );

                    HRR_INT__X_X_g_g[ibra * 225 + 130] = HRR_INT__X_X_h_f[ibra * 210 + 126] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 86] );

                    HRR_INT__X_X_g_g[ibra * 225 + 131] = HRR_INT__X_X_h_f[ibra * 210 + 136] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 86] );

                    HRR_INT__X_X_g_g[ibra * 225 + 132] = HRR_INT__X_X_h_f[ibra * 210 + 137] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 87] );

                    HRR_INT__X_X_g_g[ibra * 225 + 133] = HRR_INT__X_X_h_f[ibra * 210 + 129] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 89] );

                    HRR_INT__X_X_g_g[ibra * 225 + 134] = HRR_INT__X_X_h_f[ibra * 210 + 139] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 89] );

                    HRR_INT__X_X_g_g[ibra * 225 + 135] = HRR_INT__X_X_h_f[ibra * 210 + 90] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 90] );

                    HRR_INT__X_X_g_g[ibra * 225 + 136] = HRR_INT__X_X_h_f[ibra * 210 + 130] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 90] );

                    HRR_INT__X_X_g_g[ibra * 225 + 137] = HRR_INT__X_X_h_f[ibra * 210 + 140] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 90] );

                    HRR_INT__X_X_g_g[ibra * 225 + 138] = HRR_INT__X_X_h_f[ibra * 210 + 131] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 91] );

                    HRR_INT__X_X_g_g[ibra * 225 + 139] = HRR_INT__X_X_h_f[ibra * 210 + 141] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 91] );

                    HRR_INT__X_X_g_g[ibra * 225 + 140] = HRR_INT__X_X_h_f[ibra * 210 + 142] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 92] );

                    HRR_INT__X_X_g_g[ibra * 225 + 141] = HRR_INT__X_X_h_f[ibra * 210 + 96] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 96] );

                    HRR_INT__X_X_g_g[ibra * 225 + 142] = HRR_INT__X_X_h_f[ibra * 210 + 143] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 93] );

                    HRR_INT__X_X_g_g[ibra * 225 + 143] = HRR_INT__X_X_h_f[ibra * 210 + 135] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 95] );

                    HRR_INT__X_X_g_g[ibra * 225 + 144] = HRR_INT__X_X_h_f[ibra * 210 + 99] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 99] );

                    HRR_INT__X_X_g_g[ibra * 225 + 145] = HRR_INT__X_X_h_f[ibra * 210 + 136] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 96] );

                    HRR_INT__X_X_g_g[ibra * 225 + 146] = HRR_INT__X_X_h_f[ibra * 210 + 146] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 96] );

                    HRR_INT__X_X_g_g[ibra * 225 + 147] = HRR_INT__X_X_h_f[ibra * 210 + 147] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 97] );

                    HRR_INT__X_X_g_g[ibra * 225 + 148] = HRR_INT__X_X_h_f[ibra * 210 + 139] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 99] );

                    HRR_INT__X_X_g_g[ibra * 225 + 149] = HRR_INT__X_X_h_f[ibra * 210 + 149] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 99] );

                    HRR_INT__X_X_g_g[ibra * 225 + 150] = HRR_INT__X_X_h_f[ibra * 210 + 100] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 100] );

                    HRR_INT__X_X_g_g[ibra * 225 + 151] = HRR_INT__X_X_h_f[ibra * 210 + 150] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 100] );

                    HRR_INT__X_X_g_g[ibra * 225 + 152] = HRR_INT__X_X_h_f[ibra * 210 + 160] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 100] );

                    HRR_INT__X_X_g_g[ibra * 225 + 153] = HRR_INT__X_X_h_f[ibra * 210 + 151] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 101] );

                    HRR_INT__X_X_g_g[ibra * 225 + 154] = HRR_INT__X_X_h_f[ibra * 210 + 161] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 101] );

                    HRR_INT__X_X_g_g[ibra * 225 + 155] = HRR_INT__X_X_h_f[ibra * 210 + 162] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 102] );

                    HRR_INT__X_X_g_g[ibra * 225 + 156] = HRR_INT__X_X_h_f[ibra * 210 + 106] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 106] );

                    HRR_INT__X_X_g_g[ibra * 225 + 157] = HRR_INT__X_X_h_f[ibra * 210 + 163] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 103] );

                    HRR_INT__X_X_g_g[ibra * 225 + 158] = HRR_INT__X_X_h_f[ibra * 210 + 155] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 105] );

                    HRR_INT__X_X_g_g[ibra * 225 + 159] = HRR_INT__X_X_h_f[ibra * 210 + 109] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 109] );

                    HRR_INT__X_X_g_g[ibra * 225 + 160] = HRR_INT__X_X_h_f[ibra * 210 + 156] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 106] );

                    HRR_INT__X_X_g_g[ibra * 225 + 161] = HRR_INT__X_X_h_f[ibra * 210 + 166] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 106] );

                    HRR_INT__X_X_g_g[ibra * 225 + 162] = HRR_INT__X_X_h_f[ibra * 210 + 167] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 107] );

                    HRR_INT__X_X_g_g[ibra * 225 + 163] = HRR_INT__X_X_h_f[ibra * 210 + 159] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 109] );

                    HRR_INT__X_X_g_g[ibra * 225 + 164] = HRR_INT__X_X_h_f[ibra * 210 + 169] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 109] );

                    HRR_INT__X_X_g_g[ibra * 225 + 165] = HRR_INT__X_X_h_f[ibra * 210 + 110] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 110] );

                    HRR_INT__X_X_g_g[ibra * 225 + 166] = HRR_INT__X_X_h_f[ibra * 210 + 160] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 110] );

                    HRR_INT__X_X_g_g[ibra * 225 + 167] = HRR_INT__X_X_h_f[ibra * 210 + 170] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 110] );

                    HRR_INT__X_X_g_g[ibra * 225 + 168] = HRR_INT__X_X_h_f[ibra * 210 + 161] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 111] );

                    HRR_INT__X_X_g_g[ibra * 225 + 169] = HRR_INT__X_X_h_f[ibra * 210 + 171] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 111] );

                    HRR_INT__X_X_g_g[ibra * 225 + 170] = HRR_INT__X_X_h_f[ibra * 210 + 172] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 112] );

                    HRR_INT__X_X_g_g[ibra * 225 + 171] = HRR_INT__X_X_h_f[ibra * 210 + 116] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 116] );

                    HRR_INT__X_X_g_g[ibra * 225 + 172] = HRR_INT__X_X_h_f[ibra * 210 + 173] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 113] );

                    HRR_INT__X_X_g_g[ibra * 225 + 173] = HRR_INT__X_X_h_f[ibra * 210 + 165] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 115] );

                    HRR_INT__X_X_g_g[ibra * 225 + 174] = HRR_INT__X_X_h_f[ibra * 210 + 119] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 119] );

                    HRR_INT__X_X_g_g[ibra * 225 + 175] = HRR_INT__X_X_h_f[ibra * 210 + 166] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 116] );

                    HRR_INT__X_X_g_g[ibra * 225 + 176] = HRR_INT__X_X_h_f[ibra * 210 + 176] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 116] );

                    HRR_INT__X_X_g_g[ibra * 225 + 177] = HRR_INT__X_X_h_f[ibra * 210 + 177] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 117] );

                    HRR_INT__X_X_g_g[ibra * 225 + 178] = HRR_INT__X_X_h_f[ibra * 210 + 169] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 119] );

                    HRR_INT__X_X_g_g[ibra * 225 + 179] = HRR_INT__X_X_h_f[ibra * 210 + 179] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 119] );

                    HRR_INT__X_X_g_g[ibra * 225 + 180] = HRR_INT__X_X_h_f[ibra * 210 + 120] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 120] );

                    HRR_INT__X_X_g_g[ibra * 225 + 181] = HRR_INT__X_X_h_f[ibra * 210 + 170] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 120] );

                    HRR_INT__X_X_g_g[ibra * 225 + 182] = HRR_INT__X_X_h_f[ibra * 210 + 180] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 120] );

                    HRR_INT__X_X_g_g[ibra * 225 + 183] = HRR_INT__X_X_h_f[ibra * 210 + 171] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 121] );

                    HRR_INT__X_X_g_g[ibra * 225 + 184] = HRR_INT__X_X_h_f[ibra * 210 + 181] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 121] );

                    HRR_INT__X_X_g_g[ibra * 225 + 185] = HRR_INT__X_X_h_f[ibra * 210 + 182] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 122] );

                    HRR_INT__X_X_g_g[ibra * 225 + 186] = HRR_INT__X_X_h_f[ibra * 210 + 126] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 126] );

                    HRR_INT__X_X_g_g[ibra * 225 + 187] = HRR_INT__X_X_h_f[ibra * 210 + 183] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 123] );

                    HRR_INT__X_X_g_g[ibra * 225 + 188] = HRR_INT__X_X_h_f[ibra * 210 + 175] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 125] );

                    HRR_INT__X_X_g_g[ibra * 225 + 189] = HRR_INT__X_X_h_f[ibra * 210 + 129] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 129] );

                    HRR_INT__X_X_g_g[ibra * 225 + 190] = HRR_INT__X_X_h_f[ibra * 210 + 176] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 126] );

                    HRR_INT__X_X_g_g[ibra * 225 + 191] = HRR_INT__X_X_h_f[ibra * 210 + 186] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 126] );

                    HRR_INT__X_X_g_g[ibra * 225 + 192] = HRR_INT__X_X_h_f[ibra * 210 + 187] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 127] );

                    HRR_INT__X_X_g_g[ibra * 225 + 193] = HRR_INT__X_X_h_f[ibra * 210 + 179] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 129] );

                    HRR_INT__X_X_g_g[ibra * 225 + 194] = HRR_INT__X_X_h_f[ibra * 210 + 189] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 129] );

                    HRR_INT__X_X_g_g[ibra * 225 + 195] = HRR_INT__X_X_h_f[ibra * 210 + 130] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 130] );

                    HRR_INT__X_X_g_g[ibra * 225 + 196] = HRR_INT__X_X_h_f[ibra * 210 + 180] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 130] );

                    HRR_INT__X_X_g_g[ibra * 225 + 197] = HRR_INT__X_X_h_f[ibra * 210 + 190] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 130] );

                    HRR_INT__X_X_g_g[ibra * 225 + 198] = HRR_INT__X_X_h_f[ibra * 210 + 181] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 131] );

                    HRR_INT__X_X_g_g[ibra * 225 + 199] = HRR_INT__X_X_h_f[ibra * 210 + 191] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 131] );

                    HRR_INT__X_X_g_g[ibra * 225 + 200] = HRR_INT__X_X_h_f[ibra * 210 + 192] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 132] );

                    HRR_INT__X_X_g_g[ibra * 225 + 201] = HRR_INT__X_X_h_f[ibra * 210 + 136] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 136] );

                    HRR_INT__X_X_g_g[ibra * 225 + 202] = HRR_INT__X_X_h_f[ibra * 210 + 193] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 133] );

                    HRR_INT__X_X_g_g[ibra * 225 + 203] = HRR_INT__X_X_h_f[ibra * 210 + 185] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 135] );

                    HRR_INT__X_X_g_g[ibra * 225 + 204] = HRR_INT__X_X_h_f[ibra * 210 + 139] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 139] );

                    HRR_INT__X_X_g_g[ibra * 225 + 205] = HRR_INT__X_X_h_f[ibra * 210 + 186] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 136] );

                    HRR_INT__X_X_g_g[ibra * 225 + 206] = HRR_INT__X_X_h_f[ibra * 210 + 196] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 136] );

                    HRR_INT__X_X_g_g[ibra * 225 + 207] = HRR_INT__X_X_h_f[ibra * 210 + 197] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 137] );

                    HRR_INT__X_X_g_g[ibra * 225 + 208] = HRR_INT__X_X_h_f[ibra * 210 + 189] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 139] );

                    HRR_INT__X_X_g_g[ibra * 225 + 209] = HRR_INT__X_X_h_f[ibra * 210 + 199] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 139] );

                    HRR_INT__X_X_g_g[ibra * 225 + 210] = HRR_INT__X_X_h_f[ibra * 210 + 140] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 140] );

                    HRR_INT__X_X_g_g[ibra * 225 + 211] = HRR_INT__X_X_h_f[ibra * 210 + 190] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 140] );

                    HRR_INT__X_X_g_g[ibra * 225 + 212] = HRR_INT__X_X_h_f[ibra * 210 + 200] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 140] );

                    HRR_INT__X_X_g_g[ibra * 225 + 213] = HRR_INT__X_X_h_f[ibra * 210 + 191] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 141] );

                    HRR_INT__X_X_g_g[ibra * 225 + 214] = HRR_INT__X_X_h_f[ibra * 210 + 201] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 141] );

                    HRR_INT__X_X_g_g[ibra * 225 + 215] = HRR_INT__X_X_h_f[ibra * 210 + 202] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 142] );

                    HRR_INT__X_X_g_g[ibra * 225 + 216] = HRR_INT__X_X_h_f[ibra * 210 + 146] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 146] );

                    HRR_INT__X_X_g_g[ibra * 225 + 217] = HRR_INT__X_X_h_f[ibra * 210 + 203] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 143] );

                    HRR_INT__X_X_g_g[ibra * 225 + 218] = HRR_INT__X_X_h_f[ibra * 210 + 195] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 145] );

                    HRR_INT__X_X_g_g[ibra * 225 + 219] = HRR_INT__X_X_h_f[ibra * 210 + 149] + ( hCD[0] * HRR_INT__X_X_g_f[ibra * 150 + 149] );

                    HRR_INT__X_X_g_g[ibra * 225 + 220] = HRR_INT__X_X_h_f[ibra * 210 + 196] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 146] );

                    HRR_INT__X_X_g_g[ibra * 225 + 221] = HRR_INT__X_X_h_f[ibra * 210 + 206] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 146] );

                    HRR_INT__X_X_g_g[ibra * 225 + 222] = HRR_INT__X_X_h_f[ibra * 210 + 207] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 147] );

                    HRR_INT__X_X_g_g[ibra * 225 + 223] = HRR_INT__X_X_h_f[ibra * 210 + 199] + ( hCD[1] * HRR_INT__X_X_g_f[ibra * 150 + 149] );

                    HRR_INT__X_X_g_g[ibra * 225 + 224] = HRR_INT__X_X_h_f[ibra * 210 + 209] + ( hCD[2] * HRR_INT__X_X_g_f[ibra * 150 + 149] );

                }

}


