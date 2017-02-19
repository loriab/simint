
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// KET: | f f )
// Steps: 100
//////////////////////////////////////////////

void HRR_L_f_f(double * const restrict HRR_INT__X_X_f_f,
                    double const * const restrict HRR_INT__X_X_f_d,
                    double const * const restrict HRR_INT__X_X_g_d,
                    const double hCD[3], const int ncart_bra)
{
    int ibra;

                for(ibra = 0; ibra < ncart_bra; ++ibra)
                {
                    HRR_INT__X_X_f_f[ibra * 100 + 0] = HRR_INT__X_X_g_d[ibra * 90 + 0] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 0] );

                    HRR_INT__X_X_f_f[ibra * 100 + 1] = HRR_INT__X_X_g_d[ibra * 90 + 6] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 0] );

                    HRR_INT__X_X_f_f[ibra * 100 + 2] = HRR_INT__X_X_g_d[ibra * 90 + 12] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 0] );

                    HRR_INT__X_X_f_f[ibra * 100 + 3] = HRR_INT__X_X_g_d[ibra * 90 + 3] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 3] );

                    HRR_INT__X_X_f_f[ibra * 100 + 4] = HRR_INT__X_X_g_d[ibra * 90 + 13] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 1] );

                    HRR_INT__X_X_f_f[ibra * 100 + 5] = HRR_INT__X_X_g_d[ibra * 90 + 5] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 5] );

                    HRR_INT__X_X_f_f[ibra * 100 + 6] = HRR_INT__X_X_g_d[ibra * 90 + 9] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 3] );

                    HRR_INT__X_X_f_f[ibra * 100 + 7] = HRR_INT__X_X_g_d[ibra * 90 + 15] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 3] );

                    HRR_INT__X_X_f_f[ibra * 100 + 8] = HRR_INT__X_X_g_d[ibra * 90 + 11] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 5] );

                    HRR_INT__X_X_f_f[ibra * 100 + 9] = HRR_INT__X_X_g_d[ibra * 90 + 17] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 5] );

                    HRR_INT__X_X_f_f[ibra * 100 + 10] = HRR_INT__X_X_g_d[ibra * 90 + 6] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 6] );

                    HRR_INT__X_X_f_f[ibra * 100 + 11] = HRR_INT__X_X_g_d[ibra * 90 + 18] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 6] );

                    HRR_INT__X_X_f_f[ibra * 100 + 12] = HRR_INT__X_X_g_d[ibra * 90 + 24] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 6] );

                    HRR_INT__X_X_f_f[ibra * 100 + 13] = HRR_INT__X_X_g_d[ibra * 90 + 9] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 9] );

                    HRR_INT__X_X_f_f[ibra * 100 + 14] = HRR_INT__X_X_g_d[ibra * 90 + 25] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 7] );

                    HRR_INT__X_X_f_f[ibra * 100 + 15] = HRR_INT__X_X_g_d[ibra * 90 + 11] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 11] );

                    HRR_INT__X_X_f_f[ibra * 100 + 16] = HRR_INT__X_X_g_d[ibra * 90 + 21] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 9] );

                    HRR_INT__X_X_f_f[ibra * 100 + 17] = HRR_INT__X_X_g_d[ibra * 90 + 27] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 9] );

                    HRR_INT__X_X_f_f[ibra * 100 + 18] = HRR_INT__X_X_g_d[ibra * 90 + 23] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 11] );

                    HRR_INT__X_X_f_f[ibra * 100 + 19] = HRR_INT__X_X_g_d[ibra * 90 + 29] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 11] );

                    HRR_INT__X_X_f_f[ibra * 100 + 20] = HRR_INT__X_X_g_d[ibra * 90 + 12] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 12] );

                    HRR_INT__X_X_f_f[ibra * 100 + 21] = HRR_INT__X_X_g_d[ibra * 90 + 24] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 12] );

                    HRR_INT__X_X_f_f[ibra * 100 + 22] = HRR_INT__X_X_g_d[ibra * 90 + 30] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 12] );

                    HRR_INT__X_X_f_f[ibra * 100 + 23] = HRR_INT__X_X_g_d[ibra * 90 + 15] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 15] );

                    HRR_INT__X_X_f_f[ibra * 100 + 24] = HRR_INT__X_X_g_d[ibra * 90 + 31] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 13] );

                    HRR_INT__X_X_f_f[ibra * 100 + 25] = HRR_INT__X_X_g_d[ibra * 90 + 17] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 17] );

                    HRR_INT__X_X_f_f[ibra * 100 + 26] = HRR_INT__X_X_g_d[ibra * 90 + 27] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 15] );

                    HRR_INT__X_X_f_f[ibra * 100 + 27] = HRR_INT__X_X_g_d[ibra * 90 + 33] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 15] );

                    HRR_INT__X_X_f_f[ibra * 100 + 28] = HRR_INT__X_X_g_d[ibra * 90 + 29] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 17] );

                    HRR_INT__X_X_f_f[ibra * 100 + 29] = HRR_INT__X_X_g_d[ibra * 90 + 35] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 17] );

                    HRR_INT__X_X_f_f[ibra * 100 + 30] = HRR_INT__X_X_g_d[ibra * 90 + 18] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 18] );

                    HRR_INT__X_X_f_f[ibra * 100 + 31] = HRR_INT__X_X_g_d[ibra * 90 + 36] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 18] );

                    HRR_INT__X_X_f_f[ibra * 100 + 32] = HRR_INT__X_X_g_d[ibra * 90 + 42] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 18] );

                    HRR_INT__X_X_f_f[ibra * 100 + 33] = HRR_INT__X_X_g_d[ibra * 90 + 21] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 21] );

                    HRR_INT__X_X_f_f[ibra * 100 + 34] = HRR_INT__X_X_g_d[ibra * 90 + 43] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 19] );

                    HRR_INT__X_X_f_f[ibra * 100 + 35] = HRR_INT__X_X_g_d[ibra * 90 + 23] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 23] );

                    HRR_INT__X_X_f_f[ibra * 100 + 36] = HRR_INT__X_X_g_d[ibra * 90 + 39] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 21] );

                    HRR_INT__X_X_f_f[ibra * 100 + 37] = HRR_INT__X_X_g_d[ibra * 90 + 45] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 21] );

                    HRR_INT__X_X_f_f[ibra * 100 + 38] = HRR_INT__X_X_g_d[ibra * 90 + 41] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 23] );

                    HRR_INT__X_X_f_f[ibra * 100 + 39] = HRR_INT__X_X_g_d[ibra * 90 + 47] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 23] );

                    HRR_INT__X_X_f_f[ibra * 100 + 40] = HRR_INT__X_X_g_d[ibra * 90 + 24] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 24] );

                    HRR_INT__X_X_f_f[ibra * 100 + 41] = HRR_INT__X_X_g_d[ibra * 90 + 42] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 24] );

                    HRR_INT__X_X_f_f[ibra * 100 + 42] = HRR_INT__X_X_g_d[ibra * 90 + 48] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 24] );

                    HRR_INT__X_X_f_f[ibra * 100 + 43] = HRR_INT__X_X_g_d[ibra * 90 + 27] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 27] );

                    HRR_INT__X_X_f_f[ibra * 100 + 44] = HRR_INT__X_X_g_d[ibra * 90 + 49] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 25] );

                    HRR_INT__X_X_f_f[ibra * 100 + 45] = HRR_INT__X_X_g_d[ibra * 90 + 29] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 29] );

                    HRR_INT__X_X_f_f[ibra * 100 + 46] = HRR_INT__X_X_g_d[ibra * 90 + 45] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 27] );

                    HRR_INT__X_X_f_f[ibra * 100 + 47] = HRR_INT__X_X_g_d[ibra * 90 + 51] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 27] );

                    HRR_INT__X_X_f_f[ibra * 100 + 48] = HRR_INT__X_X_g_d[ibra * 90 + 47] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 29] );

                    HRR_INT__X_X_f_f[ibra * 100 + 49] = HRR_INT__X_X_g_d[ibra * 90 + 53] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 29] );

                    HRR_INT__X_X_f_f[ibra * 100 + 50] = HRR_INT__X_X_g_d[ibra * 90 + 30] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 30] );

                    HRR_INT__X_X_f_f[ibra * 100 + 51] = HRR_INT__X_X_g_d[ibra * 90 + 48] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 30] );

                    HRR_INT__X_X_f_f[ibra * 100 + 52] = HRR_INT__X_X_g_d[ibra * 90 + 54] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 30] );

                    HRR_INT__X_X_f_f[ibra * 100 + 53] = HRR_INT__X_X_g_d[ibra * 90 + 33] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 33] );

                    HRR_INT__X_X_f_f[ibra * 100 + 54] = HRR_INT__X_X_g_d[ibra * 90 + 55] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 31] );

                    HRR_INT__X_X_f_f[ibra * 100 + 55] = HRR_INT__X_X_g_d[ibra * 90 + 35] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 35] );

                    HRR_INT__X_X_f_f[ibra * 100 + 56] = HRR_INT__X_X_g_d[ibra * 90 + 51] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 33] );

                    HRR_INT__X_X_f_f[ibra * 100 + 57] = HRR_INT__X_X_g_d[ibra * 90 + 57] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 33] );

                    HRR_INT__X_X_f_f[ibra * 100 + 58] = HRR_INT__X_X_g_d[ibra * 90 + 53] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 35] );

                    HRR_INT__X_X_f_f[ibra * 100 + 59] = HRR_INT__X_X_g_d[ibra * 90 + 59] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 35] );

                    HRR_INT__X_X_f_f[ibra * 100 + 60] = HRR_INT__X_X_g_d[ibra * 90 + 36] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 36] );

                    HRR_INT__X_X_f_f[ibra * 100 + 61] = HRR_INT__X_X_g_d[ibra * 90 + 60] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 36] );

                    HRR_INT__X_X_f_f[ibra * 100 + 62] = HRR_INT__X_X_g_d[ibra * 90 + 66] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 36] );

                    HRR_INT__X_X_f_f[ibra * 100 + 63] = HRR_INT__X_X_g_d[ibra * 90 + 39] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 39] );

                    HRR_INT__X_X_f_f[ibra * 100 + 64] = HRR_INT__X_X_g_d[ibra * 90 + 67] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 37] );

                    HRR_INT__X_X_f_f[ibra * 100 + 65] = HRR_INT__X_X_g_d[ibra * 90 + 41] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 41] );

                    HRR_INT__X_X_f_f[ibra * 100 + 66] = HRR_INT__X_X_g_d[ibra * 90 + 63] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 39] );

                    HRR_INT__X_X_f_f[ibra * 100 + 67] = HRR_INT__X_X_g_d[ibra * 90 + 69] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 39] );

                    HRR_INT__X_X_f_f[ibra * 100 + 68] = HRR_INT__X_X_g_d[ibra * 90 + 65] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 41] );

                    HRR_INT__X_X_f_f[ibra * 100 + 69] = HRR_INT__X_X_g_d[ibra * 90 + 71] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 41] );

                    HRR_INT__X_X_f_f[ibra * 100 + 70] = HRR_INT__X_X_g_d[ibra * 90 + 42] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 42] );

                    HRR_INT__X_X_f_f[ibra * 100 + 71] = HRR_INT__X_X_g_d[ibra * 90 + 66] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 42] );

                    HRR_INT__X_X_f_f[ibra * 100 + 72] = HRR_INT__X_X_g_d[ibra * 90 + 72] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 42] );

                    HRR_INT__X_X_f_f[ibra * 100 + 73] = HRR_INT__X_X_g_d[ibra * 90 + 45] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 45] );

                    HRR_INT__X_X_f_f[ibra * 100 + 74] = HRR_INT__X_X_g_d[ibra * 90 + 73] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 43] );

                    HRR_INT__X_X_f_f[ibra * 100 + 75] = HRR_INT__X_X_g_d[ibra * 90 + 47] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 47] );

                    HRR_INT__X_X_f_f[ibra * 100 + 76] = HRR_INT__X_X_g_d[ibra * 90 + 69] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 45] );

                    HRR_INT__X_X_f_f[ibra * 100 + 77] = HRR_INT__X_X_g_d[ibra * 90 + 75] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 45] );

                    HRR_INT__X_X_f_f[ibra * 100 + 78] = HRR_INT__X_X_g_d[ibra * 90 + 71] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 47] );

                    HRR_INT__X_X_f_f[ibra * 100 + 79] = HRR_INT__X_X_g_d[ibra * 90 + 77] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 47] );

                    HRR_INT__X_X_f_f[ibra * 100 + 80] = HRR_INT__X_X_g_d[ibra * 90 + 48] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 48] );

                    HRR_INT__X_X_f_f[ibra * 100 + 81] = HRR_INT__X_X_g_d[ibra * 90 + 72] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 48] );

                    HRR_INT__X_X_f_f[ibra * 100 + 82] = HRR_INT__X_X_g_d[ibra * 90 + 78] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 48] );

                    HRR_INT__X_X_f_f[ibra * 100 + 83] = HRR_INT__X_X_g_d[ibra * 90 + 51] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 51] );

                    HRR_INT__X_X_f_f[ibra * 100 + 84] = HRR_INT__X_X_g_d[ibra * 90 + 79] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 49] );

                    HRR_INT__X_X_f_f[ibra * 100 + 85] = HRR_INT__X_X_g_d[ibra * 90 + 53] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 53] );

                    HRR_INT__X_X_f_f[ibra * 100 + 86] = HRR_INT__X_X_g_d[ibra * 90 + 75] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 51] );

                    HRR_INT__X_X_f_f[ibra * 100 + 87] = HRR_INT__X_X_g_d[ibra * 90 + 81] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 51] );

                    HRR_INT__X_X_f_f[ibra * 100 + 88] = HRR_INT__X_X_g_d[ibra * 90 + 77] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 53] );

                    HRR_INT__X_X_f_f[ibra * 100 + 89] = HRR_INT__X_X_g_d[ibra * 90 + 83] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 53] );

                    HRR_INT__X_X_f_f[ibra * 100 + 90] = HRR_INT__X_X_g_d[ibra * 90 + 54] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 54] );

                    HRR_INT__X_X_f_f[ibra * 100 + 91] = HRR_INT__X_X_g_d[ibra * 90 + 78] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 54] );

                    HRR_INT__X_X_f_f[ibra * 100 + 92] = HRR_INT__X_X_g_d[ibra * 90 + 84] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 54] );

                    HRR_INT__X_X_f_f[ibra * 100 + 93] = HRR_INT__X_X_g_d[ibra * 90 + 57] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 57] );

                    HRR_INT__X_X_f_f[ibra * 100 + 94] = HRR_INT__X_X_g_d[ibra * 90 + 85] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 55] );

                    HRR_INT__X_X_f_f[ibra * 100 + 95] = HRR_INT__X_X_g_d[ibra * 90 + 59] + ( hCD[0] * HRR_INT__X_X_f_d[ibra * 60 + 59] );

                    HRR_INT__X_X_f_f[ibra * 100 + 96] = HRR_INT__X_X_g_d[ibra * 90 + 81] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 57] );

                    HRR_INT__X_X_f_f[ibra * 100 + 97] = HRR_INT__X_X_g_d[ibra * 90 + 87] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 57] );

                    HRR_INT__X_X_f_f[ibra * 100 + 98] = HRR_INT__X_X_g_d[ibra * 90 + 83] + ( hCD[1] * HRR_INT__X_X_f_d[ibra * 60 + 59] );

                    HRR_INT__X_X_f_f[ibra * 100 + 99] = HRR_INT__X_X_g_d[ibra * 90 + 89] + ( hCD[2] * HRR_INT__X_X_f_d[ibra * 60 + 59] );

                }

}


