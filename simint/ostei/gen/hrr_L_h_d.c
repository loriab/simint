
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// KET: | h d )
// Steps: 126
//////////////////////////////////////////////

void HRR_L_h_d(double * const restrict HRR_INT__X_X_h_d,
                    double const * const restrict HRR_INT__X_X_h_p,
                    double const * const restrict HRR_INT__X_X_i_p,
                    const double hCD[3], const int ncart_bra)
{
    int ibra;

                for(ibra = 0; ibra < ncart_bra; ++ibra)
                {
                    HRR_INT__X_X_h_d[ibra * 126 + 0] = HRR_INT__X_X_i_p[ibra * 84 + 0] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 0] );

                    HRR_INT__X_X_h_d[ibra * 126 + 1] = HRR_INT__X_X_i_p[ibra * 84 + 3] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 0] );

                    HRR_INT__X_X_h_d[ibra * 126 + 2] = HRR_INT__X_X_i_p[ibra * 84 + 6] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 0] );

                    HRR_INT__X_X_h_d[ibra * 126 + 3] = HRR_INT__X_X_i_p[ibra * 84 + 4] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 1] );

                    HRR_INT__X_X_h_d[ibra * 126 + 4] = HRR_INT__X_X_i_p[ibra * 84 + 7] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 1] );

                    HRR_INT__X_X_h_d[ibra * 126 + 5] = HRR_INT__X_X_i_p[ibra * 84 + 8] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 2] );

                    HRR_INT__X_X_h_d[ibra * 126 + 6] = HRR_INT__X_X_i_p[ibra * 84 + 3] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 3] );

                    HRR_INT__X_X_h_d[ibra * 126 + 7] = HRR_INT__X_X_i_p[ibra * 84 + 9] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 3] );

                    HRR_INT__X_X_h_d[ibra * 126 + 8] = HRR_INT__X_X_i_p[ibra * 84 + 12] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 3] );

                    HRR_INT__X_X_h_d[ibra * 126 + 9] = HRR_INT__X_X_i_p[ibra * 84 + 10] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 4] );

                    HRR_INT__X_X_h_d[ibra * 126 + 10] = HRR_INT__X_X_i_p[ibra * 84 + 13] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 4] );

                    HRR_INT__X_X_h_d[ibra * 126 + 11] = HRR_INT__X_X_i_p[ibra * 84 + 14] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 5] );

                    HRR_INT__X_X_h_d[ibra * 126 + 12] = HRR_INT__X_X_i_p[ibra * 84 + 6] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 6] );

                    HRR_INT__X_X_h_d[ibra * 126 + 13] = HRR_INT__X_X_i_p[ibra * 84 + 12] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 6] );

                    HRR_INT__X_X_h_d[ibra * 126 + 14] = HRR_INT__X_X_i_p[ibra * 84 + 15] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 6] );

                    HRR_INT__X_X_h_d[ibra * 126 + 15] = HRR_INT__X_X_i_p[ibra * 84 + 13] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 7] );

                    HRR_INT__X_X_h_d[ibra * 126 + 16] = HRR_INT__X_X_i_p[ibra * 84 + 16] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 7] );

                    HRR_INT__X_X_h_d[ibra * 126 + 17] = HRR_INT__X_X_i_p[ibra * 84 + 17] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 8] );

                    HRR_INT__X_X_h_d[ibra * 126 + 18] = HRR_INT__X_X_i_p[ibra * 84 + 9] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 9] );

                    HRR_INT__X_X_h_d[ibra * 126 + 19] = HRR_INT__X_X_i_p[ibra * 84 + 18] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 9] );

                    HRR_INT__X_X_h_d[ibra * 126 + 20] = HRR_INT__X_X_i_p[ibra * 84 + 21] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 9] );

                    HRR_INT__X_X_h_d[ibra * 126 + 21] = HRR_INT__X_X_i_p[ibra * 84 + 19] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 10] );

                    HRR_INT__X_X_h_d[ibra * 126 + 22] = HRR_INT__X_X_i_p[ibra * 84 + 22] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 10] );

                    HRR_INT__X_X_h_d[ibra * 126 + 23] = HRR_INT__X_X_i_p[ibra * 84 + 23] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 11] );

                    HRR_INT__X_X_h_d[ibra * 126 + 24] = HRR_INT__X_X_i_p[ibra * 84 + 12] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 12] );

                    HRR_INT__X_X_h_d[ibra * 126 + 25] = HRR_INT__X_X_i_p[ibra * 84 + 21] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 12] );

                    HRR_INT__X_X_h_d[ibra * 126 + 26] = HRR_INT__X_X_i_p[ibra * 84 + 24] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 12] );

                    HRR_INT__X_X_h_d[ibra * 126 + 27] = HRR_INT__X_X_i_p[ibra * 84 + 22] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 13] );

                    HRR_INT__X_X_h_d[ibra * 126 + 28] = HRR_INT__X_X_i_p[ibra * 84 + 25] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 13] );

                    HRR_INT__X_X_h_d[ibra * 126 + 29] = HRR_INT__X_X_i_p[ibra * 84 + 26] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 14] );

                    HRR_INT__X_X_h_d[ibra * 126 + 30] = HRR_INT__X_X_i_p[ibra * 84 + 15] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 15] );

                    HRR_INT__X_X_h_d[ibra * 126 + 31] = HRR_INT__X_X_i_p[ibra * 84 + 24] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 15] );

                    HRR_INT__X_X_h_d[ibra * 126 + 32] = HRR_INT__X_X_i_p[ibra * 84 + 27] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 15] );

                    HRR_INT__X_X_h_d[ibra * 126 + 33] = HRR_INT__X_X_i_p[ibra * 84 + 25] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 16] );

                    HRR_INT__X_X_h_d[ibra * 126 + 34] = HRR_INT__X_X_i_p[ibra * 84 + 28] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 16] );

                    HRR_INT__X_X_h_d[ibra * 126 + 35] = HRR_INT__X_X_i_p[ibra * 84 + 29] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 17] );

                    HRR_INT__X_X_h_d[ibra * 126 + 36] = HRR_INT__X_X_i_p[ibra * 84 + 18] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 18] );

                    HRR_INT__X_X_h_d[ibra * 126 + 37] = HRR_INT__X_X_i_p[ibra * 84 + 30] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 18] );

                    HRR_INT__X_X_h_d[ibra * 126 + 38] = HRR_INT__X_X_i_p[ibra * 84 + 33] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 18] );

                    HRR_INT__X_X_h_d[ibra * 126 + 39] = HRR_INT__X_X_i_p[ibra * 84 + 31] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 19] );

                    HRR_INT__X_X_h_d[ibra * 126 + 40] = HRR_INT__X_X_i_p[ibra * 84 + 34] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 19] );

                    HRR_INT__X_X_h_d[ibra * 126 + 41] = HRR_INT__X_X_i_p[ibra * 84 + 35] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 20] );

                    HRR_INT__X_X_h_d[ibra * 126 + 42] = HRR_INT__X_X_i_p[ibra * 84 + 21] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 21] );

                    HRR_INT__X_X_h_d[ibra * 126 + 43] = HRR_INT__X_X_i_p[ibra * 84 + 33] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 21] );

                    HRR_INT__X_X_h_d[ibra * 126 + 44] = HRR_INT__X_X_i_p[ibra * 84 + 36] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 21] );

                    HRR_INT__X_X_h_d[ibra * 126 + 45] = HRR_INT__X_X_i_p[ibra * 84 + 34] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 22] );

                    HRR_INT__X_X_h_d[ibra * 126 + 46] = HRR_INT__X_X_i_p[ibra * 84 + 37] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 22] );

                    HRR_INT__X_X_h_d[ibra * 126 + 47] = HRR_INT__X_X_i_p[ibra * 84 + 38] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 23] );

                    HRR_INT__X_X_h_d[ibra * 126 + 48] = HRR_INT__X_X_i_p[ibra * 84 + 24] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 24] );

                    HRR_INT__X_X_h_d[ibra * 126 + 49] = HRR_INT__X_X_i_p[ibra * 84 + 36] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 24] );

                    HRR_INT__X_X_h_d[ibra * 126 + 50] = HRR_INT__X_X_i_p[ibra * 84 + 39] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 24] );

                    HRR_INT__X_X_h_d[ibra * 126 + 51] = HRR_INT__X_X_i_p[ibra * 84 + 37] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 25] );

                    HRR_INT__X_X_h_d[ibra * 126 + 52] = HRR_INT__X_X_i_p[ibra * 84 + 40] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 25] );

                    HRR_INT__X_X_h_d[ibra * 126 + 53] = HRR_INT__X_X_i_p[ibra * 84 + 41] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 26] );

                    HRR_INT__X_X_h_d[ibra * 126 + 54] = HRR_INT__X_X_i_p[ibra * 84 + 27] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 27] );

                    HRR_INT__X_X_h_d[ibra * 126 + 55] = HRR_INT__X_X_i_p[ibra * 84 + 39] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 27] );

                    HRR_INT__X_X_h_d[ibra * 126 + 56] = HRR_INT__X_X_i_p[ibra * 84 + 42] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 27] );

                    HRR_INT__X_X_h_d[ibra * 126 + 57] = HRR_INT__X_X_i_p[ibra * 84 + 40] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 28] );

                    HRR_INT__X_X_h_d[ibra * 126 + 58] = HRR_INT__X_X_i_p[ibra * 84 + 43] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 28] );

                    HRR_INT__X_X_h_d[ibra * 126 + 59] = HRR_INT__X_X_i_p[ibra * 84 + 44] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 29] );

                    HRR_INT__X_X_h_d[ibra * 126 + 60] = HRR_INT__X_X_i_p[ibra * 84 + 30] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 30] );

                    HRR_INT__X_X_h_d[ibra * 126 + 61] = HRR_INT__X_X_i_p[ibra * 84 + 45] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 30] );

                    HRR_INT__X_X_h_d[ibra * 126 + 62] = HRR_INT__X_X_i_p[ibra * 84 + 48] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 30] );

                    HRR_INT__X_X_h_d[ibra * 126 + 63] = HRR_INT__X_X_i_p[ibra * 84 + 46] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 31] );

                    HRR_INT__X_X_h_d[ibra * 126 + 64] = HRR_INT__X_X_i_p[ibra * 84 + 49] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 31] );

                    HRR_INT__X_X_h_d[ibra * 126 + 65] = HRR_INT__X_X_i_p[ibra * 84 + 50] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 32] );

                    HRR_INT__X_X_h_d[ibra * 126 + 66] = HRR_INT__X_X_i_p[ibra * 84 + 33] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 33] );

                    HRR_INT__X_X_h_d[ibra * 126 + 67] = HRR_INT__X_X_i_p[ibra * 84 + 48] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 33] );

                    HRR_INT__X_X_h_d[ibra * 126 + 68] = HRR_INT__X_X_i_p[ibra * 84 + 51] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 33] );

                    HRR_INT__X_X_h_d[ibra * 126 + 69] = HRR_INT__X_X_i_p[ibra * 84 + 49] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 34] );

                    HRR_INT__X_X_h_d[ibra * 126 + 70] = HRR_INT__X_X_i_p[ibra * 84 + 52] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 34] );

                    HRR_INT__X_X_h_d[ibra * 126 + 71] = HRR_INT__X_X_i_p[ibra * 84 + 53] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 35] );

                    HRR_INT__X_X_h_d[ibra * 126 + 72] = HRR_INT__X_X_i_p[ibra * 84 + 36] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 36] );

                    HRR_INT__X_X_h_d[ibra * 126 + 73] = HRR_INT__X_X_i_p[ibra * 84 + 51] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 36] );

                    HRR_INT__X_X_h_d[ibra * 126 + 74] = HRR_INT__X_X_i_p[ibra * 84 + 54] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 36] );

                    HRR_INT__X_X_h_d[ibra * 126 + 75] = HRR_INT__X_X_i_p[ibra * 84 + 52] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 37] );

                    HRR_INT__X_X_h_d[ibra * 126 + 76] = HRR_INT__X_X_i_p[ibra * 84 + 55] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 37] );

                    HRR_INT__X_X_h_d[ibra * 126 + 77] = HRR_INT__X_X_i_p[ibra * 84 + 56] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 38] );

                    HRR_INT__X_X_h_d[ibra * 126 + 78] = HRR_INT__X_X_i_p[ibra * 84 + 39] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 39] );

                    HRR_INT__X_X_h_d[ibra * 126 + 79] = HRR_INT__X_X_i_p[ibra * 84 + 54] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 39] );

                    HRR_INT__X_X_h_d[ibra * 126 + 80] = HRR_INT__X_X_i_p[ibra * 84 + 57] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 39] );

                    HRR_INT__X_X_h_d[ibra * 126 + 81] = HRR_INT__X_X_i_p[ibra * 84 + 55] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 40] );

                    HRR_INT__X_X_h_d[ibra * 126 + 82] = HRR_INT__X_X_i_p[ibra * 84 + 58] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 40] );

                    HRR_INT__X_X_h_d[ibra * 126 + 83] = HRR_INT__X_X_i_p[ibra * 84 + 59] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 41] );

                    HRR_INT__X_X_h_d[ibra * 126 + 84] = HRR_INT__X_X_i_p[ibra * 84 + 42] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 42] );

                    HRR_INT__X_X_h_d[ibra * 126 + 85] = HRR_INT__X_X_i_p[ibra * 84 + 57] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 42] );

                    HRR_INT__X_X_h_d[ibra * 126 + 86] = HRR_INT__X_X_i_p[ibra * 84 + 60] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 42] );

                    HRR_INT__X_X_h_d[ibra * 126 + 87] = HRR_INT__X_X_i_p[ibra * 84 + 58] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 43] );

                    HRR_INT__X_X_h_d[ibra * 126 + 88] = HRR_INT__X_X_i_p[ibra * 84 + 61] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 43] );

                    HRR_INT__X_X_h_d[ibra * 126 + 89] = HRR_INT__X_X_i_p[ibra * 84 + 62] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 44] );

                    HRR_INT__X_X_h_d[ibra * 126 + 90] = HRR_INT__X_X_i_p[ibra * 84 + 45] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 45] );

                    HRR_INT__X_X_h_d[ibra * 126 + 91] = HRR_INT__X_X_i_p[ibra * 84 + 63] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 45] );

                    HRR_INT__X_X_h_d[ibra * 126 + 92] = HRR_INT__X_X_i_p[ibra * 84 + 66] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 45] );

                    HRR_INT__X_X_h_d[ibra * 126 + 93] = HRR_INT__X_X_i_p[ibra * 84 + 64] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 46] );

                    HRR_INT__X_X_h_d[ibra * 126 + 94] = HRR_INT__X_X_i_p[ibra * 84 + 67] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 46] );

                    HRR_INT__X_X_h_d[ibra * 126 + 95] = HRR_INT__X_X_i_p[ibra * 84 + 68] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 47] );

                    HRR_INT__X_X_h_d[ibra * 126 + 96] = HRR_INT__X_X_i_p[ibra * 84 + 48] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 48] );

                    HRR_INT__X_X_h_d[ibra * 126 + 97] = HRR_INT__X_X_i_p[ibra * 84 + 66] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 48] );

                    HRR_INT__X_X_h_d[ibra * 126 + 98] = HRR_INT__X_X_i_p[ibra * 84 + 69] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 48] );

                    HRR_INT__X_X_h_d[ibra * 126 + 99] = HRR_INT__X_X_i_p[ibra * 84 + 67] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 49] );

                    HRR_INT__X_X_h_d[ibra * 126 + 100] = HRR_INT__X_X_i_p[ibra * 84 + 70] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 49] );

                    HRR_INT__X_X_h_d[ibra * 126 + 101] = HRR_INT__X_X_i_p[ibra * 84 + 71] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 50] );

                    HRR_INT__X_X_h_d[ibra * 126 + 102] = HRR_INT__X_X_i_p[ibra * 84 + 51] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 51] );

                    HRR_INT__X_X_h_d[ibra * 126 + 103] = HRR_INT__X_X_i_p[ibra * 84 + 69] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 51] );

                    HRR_INT__X_X_h_d[ibra * 126 + 104] = HRR_INT__X_X_i_p[ibra * 84 + 72] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 51] );

                    HRR_INT__X_X_h_d[ibra * 126 + 105] = HRR_INT__X_X_i_p[ibra * 84 + 70] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 52] );

                    HRR_INT__X_X_h_d[ibra * 126 + 106] = HRR_INT__X_X_i_p[ibra * 84 + 73] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 52] );

                    HRR_INT__X_X_h_d[ibra * 126 + 107] = HRR_INT__X_X_i_p[ibra * 84 + 74] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 53] );

                    HRR_INT__X_X_h_d[ibra * 126 + 108] = HRR_INT__X_X_i_p[ibra * 84 + 54] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 54] );

                    HRR_INT__X_X_h_d[ibra * 126 + 109] = HRR_INT__X_X_i_p[ibra * 84 + 72] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 54] );

                    HRR_INT__X_X_h_d[ibra * 126 + 110] = HRR_INT__X_X_i_p[ibra * 84 + 75] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 54] );

                    HRR_INT__X_X_h_d[ibra * 126 + 111] = HRR_INT__X_X_i_p[ibra * 84 + 73] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 55] );

                    HRR_INT__X_X_h_d[ibra * 126 + 112] = HRR_INT__X_X_i_p[ibra * 84 + 76] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 55] );

                    HRR_INT__X_X_h_d[ibra * 126 + 113] = HRR_INT__X_X_i_p[ibra * 84 + 77] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 56] );

                    HRR_INT__X_X_h_d[ibra * 126 + 114] = HRR_INT__X_X_i_p[ibra * 84 + 57] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 57] );

                    HRR_INT__X_X_h_d[ibra * 126 + 115] = HRR_INT__X_X_i_p[ibra * 84 + 75] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 57] );

                    HRR_INT__X_X_h_d[ibra * 126 + 116] = HRR_INT__X_X_i_p[ibra * 84 + 78] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 57] );

                    HRR_INT__X_X_h_d[ibra * 126 + 117] = HRR_INT__X_X_i_p[ibra * 84 + 76] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 58] );

                    HRR_INT__X_X_h_d[ibra * 126 + 118] = HRR_INT__X_X_i_p[ibra * 84 + 79] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 58] );

                    HRR_INT__X_X_h_d[ibra * 126 + 119] = HRR_INT__X_X_i_p[ibra * 84 + 80] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 59] );

                    HRR_INT__X_X_h_d[ibra * 126 + 120] = HRR_INT__X_X_i_p[ibra * 84 + 60] + ( hCD[0] * HRR_INT__X_X_h_p[ibra * 63 + 60] );

                    HRR_INT__X_X_h_d[ibra * 126 + 121] = HRR_INT__X_X_i_p[ibra * 84 + 78] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 60] );

                    HRR_INT__X_X_h_d[ibra * 126 + 122] = HRR_INT__X_X_i_p[ibra * 84 + 81] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 60] );

                    HRR_INT__X_X_h_d[ibra * 126 + 123] = HRR_INT__X_X_i_p[ibra * 84 + 79] + ( hCD[1] * HRR_INT__X_X_h_p[ibra * 63 + 61] );

                    HRR_INT__X_X_h_d[ibra * 126 + 124] = HRR_INT__X_X_i_p[ibra * 84 + 82] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 61] );

                    HRR_INT__X_X_h_d[ibra * 126 + 125] = HRR_INT__X_X_i_p[ibra * 84 + 83] + ( hCD[2] * HRR_INT__X_X_h_p[ibra * 63 + 62] );

                }

}


