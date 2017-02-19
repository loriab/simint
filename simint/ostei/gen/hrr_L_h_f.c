
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// KET: | h f )
// Steps: 210
//////////////////////////////////////////////

void HRR_L_h_f(double * const restrict HRR_INT__X_X_h_f,
                    double const * const restrict HRR_INT__X_X_h_d,
                    double const * const restrict HRR_INT__X_X_i_d,
                    const double hCD[3], const int ncart_bra)
{
    int ibra;

                for(ibra = 0; ibra < ncart_bra; ++ibra)
                {
                    HRR_INT__X_X_h_f[ibra * 210 + 0] = HRR_INT__X_X_i_d[ibra * 168 + 0] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 0] );

                    HRR_INT__X_X_h_f[ibra * 210 + 1] = HRR_INT__X_X_i_d[ibra * 168 + 6] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 0] );

                    HRR_INT__X_X_h_f[ibra * 210 + 2] = HRR_INT__X_X_i_d[ibra * 168 + 12] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 0] );

                    HRR_INT__X_X_h_f[ibra * 210 + 3] = HRR_INT__X_X_i_d[ibra * 168 + 3] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 3] );

                    HRR_INT__X_X_h_f[ibra * 210 + 4] = HRR_INT__X_X_i_d[ibra * 168 + 13] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 1] );

                    HRR_INT__X_X_h_f[ibra * 210 + 5] = HRR_INT__X_X_i_d[ibra * 168 + 5] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 5] );

                    HRR_INT__X_X_h_f[ibra * 210 + 6] = HRR_INT__X_X_i_d[ibra * 168 + 9] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 3] );

                    HRR_INT__X_X_h_f[ibra * 210 + 7] = HRR_INT__X_X_i_d[ibra * 168 + 15] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 3] );

                    HRR_INT__X_X_h_f[ibra * 210 + 8] = HRR_INT__X_X_i_d[ibra * 168 + 11] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 5] );

                    HRR_INT__X_X_h_f[ibra * 210 + 9] = HRR_INT__X_X_i_d[ibra * 168 + 17] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 5] );

                    HRR_INT__X_X_h_f[ibra * 210 + 10] = HRR_INT__X_X_i_d[ibra * 168 + 6] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 6] );

                    HRR_INT__X_X_h_f[ibra * 210 + 11] = HRR_INT__X_X_i_d[ibra * 168 + 18] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 6] );

                    HRR_INT__X_X_h_f[ibra * 210 + 12] = HRR_INT__X_X_i_d[ibra * 168 + 24] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 6] );

                    HRR_INT__X_X_h_f[ibra * 210 + 13] = HRR_INT__X_X_i_d[ibra * 168 + 9] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 9] );

                    HRR_INT__X_X_h_f[ibra * 210 + 14] = HRR_INT__X_X_i_d[ibra * 168 + 25] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 7] );

                    HRR_INT__X_X_h_f[ibra * 210 + 15] = HRR_INT__X_X_i_d[ibra * 168 + 11] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 11] );

                    HRR_INT__X_X_h_f[ibra * 210 + 16] = HRR_INT__X_X_i_d[ibra * 168 + 21] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 9] );

                    HRR_INT__X_X_h_f[ibra * 210 + 17] = HRR_INT__X_X_i_d[ibra * 168 + 27] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 9] );

                    HRR_INT__X_X_h_f[ibra * 210 + 18] = HRR_INT__X_X_i_d[ibra * 168 + 23] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 11] );

                    HRR_INT__X_X_h_f[ibra * 210 + 19] = HRR_INT__X_X_i_d[ibra * 168 + 29] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 11] );

                    HRR_INT__X_X_h_f[ibra * 210 + 20] = HRR_INT__X_X_i_d[ibra * 168 + 12] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 12] );

                    HRR_INT__X_X_h_f[ibra * 210 + 21] = HRR_INT__X_X_i_d[ibra * 168 + 24] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 12] );

                    HRR_INT__X_X_h_f[ibra * 210 + 22] = HRR_INT__X_X_i_d[ibra * 168 + 30] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 12] );

                    HRR_INT__X_X_h_f[ibra * 210 + 23] = HRR_INT__X_X_i_d[ibra * 168 + 15] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 15] );

                    HRR_INT__X_X_h_f[ibra * 210 + 24] = HRR_INT__X_X_i_d[ibra * 168 + 31] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 13] );

                    HRR_INT__X_X_h_f[ibra * 210 + 25] = HRR_INT__X_X_i_d[ibra * 168 + 17] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 17] );

                    HRR_INT__X_X_h_f[ibra * 210 + 26] = HRR_INT__X_X_i_d[ibra * 168 + 27] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 15] );

                    HRR_INT__X_X_h_f[ibra * 210 + 27] = HRR_INT__X_X_i_d[ibra * 168 + 33] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 15] );

                    HRR_INT__X_X_h_f[ibra * 210 + 28] = HRR_INT__X_X_i_d[ibra * 168 + 29] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 17] );

                    HRR_INT__X_X_h_f[ibra * 210 + 29] = HRR_INT__X_X_i_d[ibra * 168 + 35] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 17] );

                    HRR_INT__X_X_h_f[ibra * 210 + 30] = HRR_INT__X_X_i_d[ibra * 168 + 18] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 18] );

                    HRR_INT__X_X_h_f[ibra * 210 + 31] = HRR_INT__X_X_i_d[ibra * 168 + 36] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 18] );

                    HRR_INT__X_X_h_f[ibra * 210 + 32] = HRR_INT__X_X_i_d[ibra * 168 + 42] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 18] );

                    HRR_INT__X_X_h_f[ibra * 210 + 33] = HRR_INT__X_X_i_d[ibra * 168 + 21] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 21] );

                    HRR_INT__X_X_h_f[ibra * 210 + 34] = HRR_INT__X_X_i_d[ibra * 168 + 43] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 19] );

                    HRR_INT__X_X_h_f[ibra * 210 + 35] = HRR_INT__X_X_i_d[ibra * 168 + 23] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 23] );

                    HRR_INT__X_X_h_f[ibra * 210 + 36] = HRR_INT__X_X_i_d[ibra * 168 + 39] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 21] );

                    HRR_INT__X_X_h_f[ibra * 210 + 37] = HRR_INT__X_X_i_d[ibra * 168 + 45] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 21] );

                    HRR_INT__X_X_h_f[ibra * 210 + 38] = HRR_INT__X_X_i_d[ibra * 168 + 41] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 23] );

                    HRR_INT__X_X_h_f[ibra * 210 + 39] = HRR_INT__X_X_i_d[ibra * 168 + 47] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 23] );

                    HRR_INT__X_X_h_f[ibra * 210 + 40] = HRR_INT__X_X_i_d[ibra * 168 + 24] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 24] );

                    HRR_INT__X_X_h_f[ibra * 210 + 41] = HRR_INT__X_X_i_d[ibra * 168 + 42] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 24] );

                    HRR_INT__X_X_h_f[ibra * 210 + 42] = HRR_INT__X_X_i_d[ibra * 168 + 48] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 24] );

                    HRR_INT__X_X_h_f[ibra * 210 + 43] = HRR_INT__X_X_i_d[ibra * 168 + 27] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 27] );

                    HRR_INT__X_X_h_f[ibra * 210 + 44] = HRR_INT__X_X_i_d[ibra * 168 + 49] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 25] );

                    HRR_INT__X_X_h_f[ibra * 210 + 45] = HRR_INT__X_X_i_d[ibra * 168 + 29] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 29] );

                    HRR_INT__X_X_h_f[ibra * 210 + 46] = HRR_INT__X_X_i_d[ibra * 168 + 45] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 27] );

                    HRR_INT__X_X_h_f[ibra * 210 + 47] = HRR_INT__X_X_i_d[ibra * 168 + 51] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 27] );

                    HRR_INT__X_X_h_f[ibra * 210 + 48] = HRR_INT__X_X_i_d[ibra * 168 + 47] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 29] );

                    HRR_INT__X_X_h_f[ibra * 210 + 49] = HRR_INT__X_X_i_d[ibra * 168 + 53] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 29] );

                    HRR_INT__X_X_h_f[ibra * 210 + 50] = HRR_INT__X_X_i_d[ibra * 168 + 30] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 30] );

                    HRR_INT__X_X_h_f[ibra * 210 + 51] = HRR_INT__X_X_i_d[ibra * 168 + 48] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 30] );

                    HRR_INT__X_X_h_f[ibra * 210 + 52] = HRR_INT__X_X_i_d[ibra * 168 + 54] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 30] );

                    HRR_INT__X_X_h_f[ibra * 210 + 53] = HRR_INT__X_X_i_d[ibra * 168 + 33] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 33] );

                    HRR_INT__X_X_h_f[ibra * 210 + 54] = HRR_INT__X_X_i_d[ibra * 168 + 55] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 31] );

                    HRR_INT__X_X_h_f[ibra * 210 + 55] = HRR_INT__X_X_i_d[ibra * 168 + 35] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 35] );

                    HRR_INT__X_X_h_f[ibra * 210 + 56] = HRR_INT__X_X_i_d[ibra * 168 + 51] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 33] );

                    HRR_INT__X_X_h_f[ibra * 210 + 57] = HRR_INT__X_X_i_d[ibra * 168 + 57] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 33] );

                    HRR_INT__X_X_h_f[ibra * 210 + 58] = HRR_INT__X_X_i_d[ibra * 168 + 53] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 35] );

                    HRR_INT__X_X_h_f[ibra * 210 + 59] = HRR_INT__X_X_i_d[ibra * 168 + 59] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 35] );

                    HRR_INT__X_X_h_f[ibra * 210 + 60] = HRR_INT__X_X_i_d[ibra * 168 + 36] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 36] );

                    HRR_INT__X_X_h_f[ibra * 210 + 61] = HRR_INT__X_X_i_d[ibra * 168 + 60] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 36] );

                    HRR_INT__X_X_h_f[ibra * 210 + 62] = HRR_INT__X_X_i_d[ibra * 168 + 66] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 36] );

                    HRR_INT__X_X_h_f[ibra * 210 + 63] = HRR_INT__X_X_i_d[ibra * 168 + 39] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 39] );

                    HRR_INT__X_X_h_f[ibra * 210 + 64] = HRR_INT__X_X_i_d[ibra * 168 + 67] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 37] );

                    HRR_INT__X_X_h_f[ibra * 210 + 65] = HRR_INT__X_X_i_d[ibra * 168 + 41] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 41] );

                    HRR_INT__X_X_h_f[ibra * 210 + 66] = HRR_INT__X_X_i_d[ibra * 168 + 63] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 39] );

                    HRR_INT__X_X_h_f[ibra * 210 + 67] = HRR_INT__X_X_i_d[ibra * 168 + 69] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 39] );

                    HRR_INT__X_X_h_f[ibra * 210 + 68] = HRR_INT__X_X_i_d[ibra * 168 + 65] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 41] );

                    HRR_INT__X_X_h_f[ibra * 210 + 69] = HRR_INT__X_X_i_d[ibra * 168 + 71] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 41] );

                    HRR_INT__X_X_h_f[ibra * 210 + 70] = HRR_INT__X_X_i_d[ibra * 168 + 42] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 42] );

                    HRR_INT__X_X_h_f[ibra * 210 + 71] = HRR_INT__X_X_i_d[ibra * 168 + 66] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 42] );

                    HRR_INT__X_X_h_f[ibra * 210 + 72] = HRR_INT__X_X_i_d[ibra * 168 + 72] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 42] );

                    HRR_INT__X_X_h_f[ibra * 210 + 73] = HRR_INT__X_X_i_d[ibra * 168 + 45] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 45] );

                    HRR_INT__X_X_h_f[ibra * 210 + 74] = HRR_INT__X_X_i_d[ibra * 168 + 73] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 43] );

                    HRR_INT__X_X_h_f[ibra * 210 + 75] = HRR_INT__X_X_i_d[ibra * 168 + 47] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 47] );

                    HRR_INT__X_X_h_f[ibra * 210 + 76] = HRR_INT__X_X_i_d[ibra * 168 + 69] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 45] );

                    HRR_INT__X_X_h_f[ibra * 210 + 77] = HRR_INT__X_X_i_d[ibra * 168 + 75] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 45] );

                    HRR_INT__X_X_h_f[ibra * 210 + 78] = HRR_INT__X_X_i_d[ibra * 168 + 71] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 47] );

                    HRR_INT__X_X_h_f[ibra * 210 + 79] = HRR_INT__X_X_i_d[ibra * 168 + 77] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 47] );

                    HRR_INT__X_X_h_f[ibra * 210 + 80] = HRR_INT__X_X_i_d[ibra * 168 + 48] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 48] );

                    HRR_INT__X_X_h_f[ibra * 210 + 81] = HRR_INT__X_X_i_d[ibra * 168 + 72] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 48] );

                    HRR_INT__X_X_h_f[ibra * 210 + 82] = HRR_INT__X_X_i_d[ibra * 168 + 78] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 48] );

                    HRR_INT__X_X_h_f[ibra * 210 + 83] = HRR_INT__X_X_i_d[ibra * 168 + 51] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 51] );

                    HRR_INT__X_X_h_f[ibra * 210 + 84] = HRR_INT__X_X_i_d[ibra * 168 + 79] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 49] );

                    HRR_INT__X_X_h_f[ibra * 210 + 85] = HRR_INT__X_X_i_d[ibra * 168 + 53] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 53] );

                    HRR_INT__X_X_h_f[ibra * 210 + 86] = HRR_INT__X_X_i_d[ibra * 168 + 75] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 51] );

                    HRR_INT__X_X_h_f[ibra * 210 + 87] = HRR_INT__X_X_i_d[ibra * 168 + 81] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 51] );

                    HRR_INT__X_X_h_f[ibra * 210 + 88] = HRR_INT__X_X_i_d[ibra * 168 + 77] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 53] );

                    HRR_INT__X_X_h_f[ibra * 210 + 89] = HRR_INT__X_X_i_d[ibra * 168 + 83] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 53] );

                    HRR_INT__X_X_h_f[ibra * 210 + 90] = HRR_INT__X_X_i_d[ibra * 168 + 54] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 54] );

                    HRR_INT__X_X_h_f[ibra * 210 + 91] = HRR_INT__X_X_i_d[ibra * 168 + 78] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 54] );

                    HRR_INT__X_X_h_f[ibra * 210 + 92] = HRR_INT__X_X_i_d[ibra * 168 + 84] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 54] );

                    HRR_INT__X_X_h_f[ibra * 210 + 93] = HRR_INT__X_X_i_d[ibra * 168 + 57] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 57] );

                    HRR_INT__X_X_h_f[ibra * 210 + 94] = HRR_INT__X_X_i_d[ibra * 168 + 85] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 55] );

                    HRR_INT__X_X_h_f[ibra * 210 + 95] = HRR_INT__X_X_i_d[ibra * 168 + 59] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 59] );

                    HRR_INT__X_X_h_f[ibra * 210 + 96] = HRR_INT__X_X_i_d[ibra * 168 + 81] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 57] );

                    HRR_INT__X_X_h_f[ibra * 210 + 97] = HRR_INT__X_X_i_d[ibra * 168 + 87] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 57] );

                    HRR_INT__X_X_h_f[ibra * 210 + 98] = HRR_INT__X_X_i_d[ibra * 168 + 83] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 59] );

                    HRR_INT__X_X_h_f[ibra * 210 + 99] = HRR_INT__X_X_i_d[ibra * 168 + 89] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 59] );

                    HRR_INT__X_X_h_f[ibra * 210 + 100] = HRR_INT__X_X_i_d[ibra * 168 + 60] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 60] );

                    HRR_INT__X_X_h_f[ibra * 210 + 101] = HRR_INT__X_X_i_d[ibra * 168 + 90] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 60] );

                    HRR_INT__X_X_h_f[ibra * 210 + 102] = HRR_INT__X_X_i_d[ibra * 168 + 96] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 60] );

                    HRR_INT__X_X_h_f[ibra * 210 + 103] = HRR_INT__X_X_i_d[ibra * 168 + 63] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 63] );

                    HRR_INT__X_X_h_f[ibra * 210 + 104] = HRR_INT__X_X_i_d[ibra * 168 + 97] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 61] );

                    HRR_INT__X_X_h_f[ibra * 210 + 105] = HRR_INT__X_X_i_d[ibra * 168 + 65] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 65] );

                    HRR_INT__X_X_h_f[ibra * 210 + 106] = HRR_INT__X_X_i_d[ibra * 168 + 93] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 63] );

                    HRR_INT__X_X_h_f[ibra * 210 + 107] = HRR_INT__X_X_i_d[ibra * 168 + 99] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 63] );

                    HRR_INT__X_X_h_f[ibra * 210 + 108] = HRR_INT__X_X_i_d[ibra * 168 + 95] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 65] );

                    HRR_INT__X_X_h_f[ibra * 210 + 109] = HRR_INT__X_X_i_d[ibra * 168 + 101] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 65] );

                    HRR_INT__X_X_h_f[ibra * 210 + 110] = HRR_INT__X_X_i_d[ibra * 168 + 66] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 66] );

                    HRR_INT__X_X_h_f[ibra * 210 + 111] = HRR_INT__X_X_i_d[ibra * 168 + 96] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 66] );

                    HRR_INT__X_X_h_f[ibra * 210 + 112] = HRR_INT__X_X_i_d[ibra * 168 + 102] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 66] );

                    HRR_INT__X_X_h_f[ibra * 210 + 113] = HRR_INT__X_X_i_d[ibra * 168 + 69] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 69] );

                    HRR_INT__X_X_h_f[ibra * 210 + 114] = HRR_INT__X_X_i_d[ibra * 168 + 103] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 67] );

                    HRR_INT__X_X_h_f[ibra * 210 + 115] = HRR_INT__X_X_i_d[ibra * 168 + 71] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 71] );

                    HRR_INT__X_X_h_f[ibra * 210 + 116] = HRR_INT__X_X_i_d[ibra * 168 + 99] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 69] );

                    HRR_INT__X_X_h_f[ibra * 210 + 117] = HRR_INT__X_X_i_d[ibra * 168 + 105] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 69] );

                    HRR_INT__X_X_h_f[ibra * 210 + 118] = HRR_INT__X_X_i_d[ibra * 168 + 101] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 71] );

                    HRR_INT__X_X_h_f[ibra * 210 + 119] = HRR_INT__X_X_i_d[ibra * 168 + 107] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 71] );

                    HRR_INT__X_X_h_f[ibra * 210 + 120] = HRR_INT__X_X_i_d[ibra * 168 + 72] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 72] );

                    HRR_INT__X_X_h_f[ibra * 210 + 121] = HRR_INT__X_X_i_d[ibra * 168 + 102] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 72] );

                    HRR_INT__X_X_h_f[ibra * 210 + 122] = HRR_INT__X_X_i_d[ibra * 168 + 108] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 72] );

                    HRR_INT__X_X_h_f[ibra * 210 + 123] = HRR_INT__X_X_i_d[ibra * 168 + 75] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 75] );

                    HRR_INT__X_X_h_f[ibra * 210 + 124] = HRR_INT__X_X_i_d[ibra * 168 + 109] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 73] );

                    HRR_INT__X_X_h_f[ibra * 210 + 125] = HRR_INT__X_X_i_d[ibra * 168 + 77] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 77] );

                    HRR_INT__X_X_h_f[ibra * 210 + 126] = HRR_INT__X_X_i_d[ibra * 168 + 105] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 75] );

                    HRR_INT__X_X_h_f[ibra * 210 + 127] = HRR_INT__X_X_i_d[ibra * 168 + 111] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 75] );

                    HRR_INT__X_X_h_f[ibra * 210 + 128] = HRR_INT__X_X_i_d[ibra * 168 + 107] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 77] );

                    HRR_INT__X_X_h_f[ibra * 210 + 129] = HRR_INT__X_X_i_d[ibra * 168 + 113] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 77] );

                    HRR_INT__X_X_h_f[ibra * 210 + 130] = HRR_INT__X_X_i_d[ibra * 168 + 78] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 78] );

                    HRR_INT__X_X_h_f[ibra * 210 + 131] = HRR_INT__X_X_i_d[ibra * 168 + 108] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 78] );

                    HRR_INT__X_X_h_f[ibra * 210 + 132] = HRR_INT__X_X_i_d[ibra * 168 + 114] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 78] );

                    HRR_INT__X_X_h_f[ibra * 210 + 133] = HRR_INT__X_X_i_d[ibra * 168 + 81] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 81] );

                    HRR_INT__X_X_h_f[ibra * 210 + 134] = HRR_INT__X_X_i_d[ibra * 168 + 115] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 79] );

                    HRR_INT__X_X_h_f[ibra * 210 + 135] = HRR_INT__X_X_i_d[ibra * 168 + 83] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 83] );

                    HRR_INT__X_X_h_f[ibra * 210 + 136] = HRR_INT__X_X_i_d[ibra * 168 + 111] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 81] );

                    HRR_INT__X_X_h_f[ibra * 210 + 137] = HRR_INT__X_X_i_d[ibra * 168 + 117] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 81] );

                    HRR_INT__X_X_h_f[ibra * 210 + 138] = HRR_INT__X_X_i_d[ibra * 168 + 113] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 83] );

                    HRR_INT__X_X_h_f[ibra * 210 + 139] = HRR_INT__X_X_i_d[ibra * 168 + 119] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 83] );

                    HRR_INT__X_X_h_f[ibra * 210 + 140] = HRR_INT__X_X_i_d[ibra * 168 + 84] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 84] );

                    HRR_INT__X_X_h_f[ibra * 210 + 141] = HRR_INT__X_X_i_d[ibra * 168 + 114] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 84] );

                    HRR_INT__X_X_h_f[ibra * 210 + 142] = HRR_INT__X_X_i_d[ibra * 168 + 120] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 84] );

                    HRR_INT__X_X_h_f[ibra * 210 + 143] = HRR_INT__X_X_i_d[ibra * 168 + 87] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 87] );

                    HRR_INT__X_X_h_f[ibra * 210 + 144] = HRR_INT__X_X_i_d[ibra * 168 + 121] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 85] );

                    HRR_INT__X_X_h_f[ibra * 210 + 145] = HRR_INT__X_X_i_d[ibra * 168 + 89] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 89] );

                    HRR_INT__X_X_h_f[ibra * 210 + 146] = HRR_INT__X_X_i_d[ibra * 168 + 117] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 87] );

                    HRR_INT__X_X_h_f[ibra * 210 + 147] = HRR_INT__X_X_i_d[ibra * 168 + 123] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 87] );

                    HRR_INT__X_X_h_f[ibra * 210 + 148] = HRR_INT__X_X_i_d[ibra * 168 + 119] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 89] );

                    HRR_INT__X_X_h_f[ibra * 210 + 149] = HRR_INT__X_X_i_d[ibra * 168 + 125] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 89] );

                    HRR_INT__X_X_h_f[ibra * 210 + 150] = HRR_INT__X_X_i_d[ibra * 168 + 90] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 90] );

                    HRR_INT__X_X_h_f[ibra * 210 + 151] = HRR_INT__X_X_i_d[ibra * 168 + 126] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 90] );

                    HRR_INT__X_X_h_f[ibra * 210 + 152] = HRR_INT__X_X_i_d[ibra * 168 + 132] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 90] );

                    HRR_INT__X_X_h_f[ibra * 210 + 153] = HRR_INT__X_X_i_d[ibra * 168 + 93] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 93] );

                    HRR_INT__X_X_h_f[ibra * 210 + 154] = HRR_INT__X_X_i_d[ibra * 168 + 133] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 91] );

                    HRR_INT__X_X_h_f[ibra * 210 + 155] = HRR_INT__X_X_i_d[ibra * 168 + 95] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 95] );

                    HRR_INT__X_X_h_f[ibra * 210 + 156] = HRR_INT__X_X_i_d[ibra * 168 + 129] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 93] );

                    HRR_INT__X_X_h_f[ibra * 210 + 157] = HRR_INT__X_X_i_d[ibra * 168 + 135] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 93] );

                    HRR_INT__X_X_h_f[ibra * 210 + 158] = HRR_INT__X_X_i_d[ibra * 168 + 131] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 95] );

                    HRR_INT__X_X_h_f[ibra * 210 + 159] = HRR_INT__X_X_i_d[ibra * 168 + 137] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 95] );

                    HRR_INT__X_X_h_f[ibra * 210 + 160] = HRR_INT__X_X_i_d[ibra * 168 + 96] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 96] );

                    HRR_INT__X_X_h_f[ibra * 210 + 161] = HRR_INT__X_X_i_d[ibra * 168 + 132] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 96] );

                    HRR_INT__X_X_h_f[ibra * 210 + 162] = HRR_INT__X_X_i_d[ibra * 168 + 138] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 96] );

                    HRR_INT__X_X_h_f[ibra * 210 + 163] = HRR_INT__X_X_i_d[ibra * 168 + 99] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 99] );

                    HRR_INT__X_X_h_f[ibra * 210 + 164] = HRR_INT__X_X_i_d[ibra * 168 + 139] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 97] );

                    HRR_INT__X_X_h_f[ibra * 210 + 165] = HRR_INT__X_X_i_d[ibra * 168 + 101] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 101] );

                    HRR_INT__X_X_h_f[ibra * 210 + 166] = HRR_INT__X_X_i_d[ibra * 168 + 135] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 99] );

                    HRR_INT__X_X_h_f[ibra * 210 + 167] = HRR_INT__X_X_i_d[ibra * 168 + 141] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 99] );

                    HRR_INT__X_X_h_f[ibra * 210 + 168] = HRR_INT__X_X_i_d[ibra * 168 + 137] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 101] );

                    HRR_INT__X_X_h_f[ibra * 210 + 169] = HRR_INT__X_X_i_d[ibra * 168 + 143] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 101] );

                    HRR_INT__X_X_h_f[ibra * 210 + 170] = HRR_INT__X_X_i_d[ibra * 168 + 102] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 102] );

                    HRR_INT__X_X_h_f[ibra * 210 + 171] = HRR_INT__X_X_i_d[ibra * 168 + 138] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 102] );

                    HRR_INT__X_X_h_f[ibra * 210 + 172] = HRR_INT__X_X_i_d[ibra * 168 + 144] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 102] );

                    HRR_INT__X_X_h_f[ibra * 210 + 173] = HRR_INT__X_X_i_d[ibra * 168 + 105] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 105] );

                    HRR_INT__X_X_h_f[ibra * 210 + 174] = HRR_INT__X_X_i_d[ibra * 168 + 145] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 103] );

                    HRR_INT__X_X_h_f[ibra * 210 + 175] = HRR_INT__X_X_i_d[ibra * 168 + 107] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 107] );

                    HRR_INT__X_X_h_f[ibra * 210 + 176] = HRR_INT__X_X_i_d[ibra * 168 + 141] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 105] );

                    HRR_INT__X_X_h_f[ibra * 210 + 177] = HRR_INT__X_X_i_d[ibra * 168 + 147] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 105] );

                    HRR_INT__X_X_h_f[ibra * 210 + 178] = HRR_INT__X_X_i_d[ibra * 168 + 143] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 107] );

                    HRR_INT__X_X_h_f[ibra * 210 + 179] = HRR_INT__X_X_i_d[ibra * 168 + 149] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 107] );

                    HRR_INT__X_X_h_f[ibra * 210 + 180] = HRR_INT__X_X_i_d[ibra * 168 + 108] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 108] );

                    HRR_INT__X_X_h_f[ibra * 210 + 181] = HRR_INT__X_X_i_d[ibra * 168 + 144] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 108] );

                    HRR_INT__X_X_h_f[ibra * 210 + 182] = HRR_INT__X_X_i_d[ibra * 168 + 150] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 108] );

                    HRR_INT__X_X_h_f[ibra * 210 + 183] = HRR_INT__X_X_i_d[ibra * 168 + 111] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 111] );

                    HRR_INT__X_X_h_f[ibra * 210 + 184] = HRR_INT__X_X_i_d[ibra * 168 + 151] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 109] );

                    HRR_INT__X_X_h_f[ibra * 210 + 185] = HRR_INT__X_X_i_d[ibra * 168 + 113] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 113] );

                    HRR_INT__X_X_h_f[ibra * 210 + 186] = HRR_INT__X_X_i_d[ibra * 168 + 147] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 111] );

                    HRR_INT__X_X_h_f[ibra * 210 + 187] = HRR_INT__X_X_i_d[ibra * 168 + 153] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 111] );

                    HRR_INT__X_X_h_f[ibra * 210 + 188] = HRR_INT__X_X_i_d[ibra * 168 + 149] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 113] );

                    HRR_INT__X_X_h_f[ibra * 210 + 189] = HRR_INT__X_X_i_d[ibra * 168 + 155] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 113] );

                    HRR_INT__X_X_h_f[ibra * 210 + 190] = HRR_INT__X_X_i_d[ibra * 168 + 114] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 114] );

                    HRR_INT__X_X_h_f[ibra * 210 + 191] = HRR_INT__X_X_i_d[ibra * 168 + 150] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 114] );

                    HRR_INT__X_X_h_f[ibra * 210 + 192] = HRR_INT__X_X_i_d[ibra * 168 + 156] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 114] );

                    HRR_INT__X_X_h_f[ibra * 210 + 193] = HRR_INT__X_X_i_d[ibra * 168 + 117] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 117] );

                    HRR_INT__X_X_h_f[ibra * 210 + 194] = HRR_INT__X_X_i_d[ibra * 168 + 157] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 115] );

                    HRR_INT__X_X_h_f[ibra * 210 + 195] = HRR_INT__X_X_i_d[ibra * 168 + 119] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 119] );

                    HRR_INT__X_X_h_f[ibra * 210 + 196] = HRR_INT__X_X_i_d[ibra * 168 + 153] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 117] );

                    HRR_INT__X_X_h_f[ibra * 210 + 197] = HRR_INT__X_X_i_d[ibra * 168 + 159] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 117] );

                    HRR_INT__X_X_h_f[ibra * 210 + 198] = HRR_INT__X_X_i_d[ibra * 168 + 155] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 119] );

                    HRR_INT__X_X_h_f[ibra * 210 + 199] = HRR_INT__X_X_i_d[ibra * 168 + 161] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 119] );

                    HRR_INT__X_X_h_f[ibra * 210 + 200] = HRR_INT__X_X_i_d[ibra * 168 + 120] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 120] );

                    HRR_INT__X_X_h_f[ibra * 210 + 201] = HRR_INT__X_X_i_d[ibra * 168 + 156] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 120] );

                    HRR_INT__X_X_h_f[ibra * 210 + 202] = HRR_INT__X_X_i_d[ibra * 168 + 162] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 120] );

                    HRR_INT__X_X_h_f[ibra * 210 + 203] = HRR_INT__X_X_i_d[ibra * 168 + 123] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 123] );

                    HRR_INT__X_X_h_f[ibra * 210 + 204] = HRR_INT__X_X_i_d[ibra * 168 + 163] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 121] );

                    HRR_INT__X_X_h_f[ibra * 210 + 205] = HRR_INT__X_X_i_d[ibra * 168 + 125] + ( hCD[0] * HRR_INT__X_X_h_d[ibra * 126 + 125] );

                    HRR_INT__X_X_h_f[ibra * 210 + 206] = HRR_INT__X_X_i_d[ibra * 168 + 159] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 123] );

                    HRR_INT__X_X_h_f[ibra * 210 + 207] = HRR_INT__X_X_i_d[ibra * 168 + 165] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 123] );

                    HRR_INT__X_X_h_f[ibra * 210 + 208] = HRR_INT__X_X_i_d[ibra * 168 + 161] + ( hCD[1] * HRR_INT__X_X_h_d[ibra * 126 + 125] );

                    HRR_INT__X_X_h_f[ibra * 210 + 209] = HRR_INT__X_X_i_d[ibra * 168 + 167] + ( hCD[2] * HRR_INT__X_X_h_d[ibra * 126 + 125] );

                }

}


