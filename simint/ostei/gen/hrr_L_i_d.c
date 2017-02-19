
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// KET: | i d )
// Steps: 168
//////////////////////////////////////////////

void HRR_L_i_d(double * const restrict HRR_INT__X_X_i_d,
                    double const * const restrict HRR_INT__X_X_i_p,
                    double const * const restrict HRR_INT__X_X_k_p,
                    const double hCD[3], const int ncart_bra)
{
    int ibra;

                for(ibra = 0; ibra < ncart_bra; ++ibra)
                {
                    HRR_INT__X_X_i_d[ibra * 168 + 0] = HRR_INT__X_X_k_p[ibra * 108 + 0] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 0] );

                    HRR_INT__X_X_i_d[ibra * 168 + 1] = HRR_INT__X_X_k_p[ibra * 108 + 3] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 0] );

                    HRR_INT__X_X_i_d[ibra * 168 + 2] = HRR_INT__X_X_k_p[ibra * 108 + 6] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 0] );

                    HRR_INT__X_X_i_d[ibra * 168 + 3] = HRR_INT__X_X_k_p[ibra * 108 + 4] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 1] );

                    HRR_INT__X_X_i_d[ibra * 168 + 4] = HRR_INT__X_X_k_p[ibra * 108 + 7] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 1] );

                    HRR_INT__X_X_i_d[ibra * 168 + 5] = HRR_INT__X_X_k_p[ibra * 108 + 8] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 2] );

                    HRR_INT__X_X_i_d[ibra * 168 + 6] = HRR_INT__X_X_k_p[ibra * 108 + 3] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 3] );

                    HRR_INT__X_X_i_d[ibra * 168 + 7] = HRR_INT__X_X_k_p[ibra * 108 + 9] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 3] );

                    HRR_INT__X_X_i_d[ibra * 168 + 8] = HRR_INT__X_X_k_p[ibra * 108 + 12] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 3] );

                    HRR_INT__X_X_i_d[ibra * 168 + 9] = HRR_INT__X_X_k_p[ibra * 108 + 10] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 4] );

                    HRR_INT__X_X_i_d[ibra * 168 + 10] = HRR_INT__X_X_k_p[ibra * 108 + 13] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 4] );

                    HRR_INT__X_X_i_d[ibra * 168 + 11] = HRR_INT__X_X_k_p[ibra * 108 + 14] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 5] );

                    HRR_INT__X_X_i_d[ibra * 168 + 12] = HRR_INT__X_X_k_p[ibra * 108 + 6] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 6] );

                    HRR_INT__X_X_i_d[ibra * 168 + 13] = HRR_INT__X_X_k_p[ibra * 108 + 12] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 6] );

                    HRR_INT__X_X_i_d[ibra * 168 + 14] = HRR_INT__X_X_k_p[ibra * 108 + 15] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 6] );

                    HRR_INT__X_X_i_d[ibra * 168 + 15] = HRR_INT__X_X_k_p[ibra * 108 + 13] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 7] );

                    HRR_INT__X_X_i_d[ibra * 168 + 16] = HRR_INT__X_X_k_p[ibra * 108 + 16] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 7] );

                    HRR_INT__X_X_i_d[ibra * 168 + 17] = HRR_INT__X_X_k_p[ibra * 108 + 17] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 8] );

                    HRR_INT__X_X_i_d[ibra * 168 + 18] = HRR_INT__X_X_k_p[ibra * 108 + 9] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 9] );

                    HRR_INT__X_X_i_d[ibra * 168 + 19] = HRR_INT__X_X_k_p[ibra * 108 + 18] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 9] );

                    HRR_INT__X_X_i_d[ibra * 168 + 20] = HRR_INT__X_X_k_p[ibra * 108 + 21] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 9] );

                    HRR_INT__X_X_i_d[ibra * 168 + 21] = HRR_INT__X_X_k_p[ibra * 108 + 19] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 10] );

                    HRR_INT__X_X_i_d[ibra * 168 + 22] = HRR_INT__X_X_k_p[ibra * 108 + 22] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 10] );

                    HRR_INT__X_X_i_d[ibra * 168 + 23] = HRR_INT__X_X_k_p[ibra * 108 + 23] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 11] );

                    HRR_INT__X_X_i_d[ibra * 168 + 24] = HRR_INT__X_X_k_p[ibra * 108 + 12] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 12] );

                    HRR_INT__X_X_i_d[ibra * 168 + 25] = HRR_INT__X_X_k_p[ibra * 108 + 21] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 12] );

                    HRR_INT__X_X_i_d[ibra * 168 + 26] = HRR_INT__X_X_k_p[ibra * 108 + 24] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 12] );

                    HRR_INT__X_X_i_d[ibra * 168 + 27] = HRR_INT__X_X_k_p[ibra * 108 + 22] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 13] );

                    HRR_INT__X_X_i_d[ibra * 168 + 28] = HRR_INT__X_X_k_p[ibra * 108 + 25] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 13] );

                    HRR_INT__X_X_i_d[ibra * 168 + 29] = HRR_INT__X_X_k_p[ibra * 108 + 26] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 14] );

                    HRR_INT__X_X_i_d[ibra * 168 + 30] = HRR_INT__X_X_k_p[ibra * 108 + 15] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 15] );

                    HRR_INT__X_X_i_d[ibra * 168 + 31] = HRR_INT__X_X_k_p[ibra * 108 + 24] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 15] );

                    HRR_INT__X_X_i_d[ibra * 168 + 32] = HRR_INT__X_X_k_p[ibra * 108 + 27] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 15] );

                    HRR_INT__X_X_i_d[ibra * 168 + 33] = HRR_INT__X_X_k_p[ibra * 108 + 25] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 16] );

                    HRR_INT__X_X_i_d[ibra * 168 + 34] = HRR_INT__X_X_k_p[ibra * 108 + 28] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 16] );

                    HRR_INT__X_X_i_d[ibra * 168 + 35] = HRR_INT__X_X_k_p[ibra * 108 + 29] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 17] );

                    HRR_INT__X_X_i_d[ibra * 168 + 36] = HRR_INT__X_X_k_p[ibra * 108 + 18] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 18] );

                    HRR_INT__X_X_i_d[ibra * 168 + 37] = HRR_INT__X_X_k_p[ibra * 108 + 30] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 18] );

                    HRR_INT__X_X_i_d[ibra * 168 + 38] = HRR_INT__X_X_k_p[ibra * 108 + 33] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 18] );

                    HRR_INT__X_X_i_d[ibra * 168 + 39] = HRR_INT__X_X_k_p[ibra * 108 + 31] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 19] );

                    HRR_INT__X_X_i_d[ibra * 168 + 40] = HRR_INT__X_X_k_p[ibra * 108 + 34] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 19] );

                    HRR_INT__X_X_i_d[ibra * 168 + 41] = HRR_INT__X_X_k_p[ibra * 108 + 35] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 20] );

                    HRR_INT__X_X_i_d[ibra * 168 + 42] = HRR_INT__X_X_k_p[ibra * 108 + 21] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 21] );

                    HRR_INT__X_X_i_d[ibra * 168 + 43] = HRR_INT__X_X_k_p[ibra * 108 + 33] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 21] );

                    HRR_INT__X_X_i_d[ibra * 168 + 44] = HRR_INT__X_X_k_p[ibra * 108 + 36] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 21] );

                    HRR_INT__X_X_i_d[ibra * 168 + 45] = HRR_INT__X_X_k_p[ibra * 108 + 34] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 22] );

                    HRR_INT__X_X_i_d[ibra * 168 + 46] = HRR_INT__X_X_k_p[ibra * 108 + 37] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 22] );

                    HRR_INT__X_X_i_d[ibra * 168 + 47] = HRR_INT__X_X_k_p[ibra * 108 + 38] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 23] );

                    HRR_INT__X_X_i_d[ibra * 168 + 48] = HRR_INT__X_X_k_p[ibra * 108 + 24] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 24] );

                    HRR_INT__X_X_i_d[ibra * 168 + 49] = HRR_INT__X_X_k_p[ibra * 108 + 36] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 24] );

                    HRR_INT__X_X_i_d[ibra * 168 + 50] = HRR_INT__X_X_k_p[ibra * 108 + 39] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 24] );

                    HRR_INT__X_X_i_d[ibra * 168 + 51] = HRR_INT__X_X_k_p[ibra * 108 + 37] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 25] );

                    HRR_INT__X_X_i_d[ibra * 168 + 52] = HRR_INT__X_X_k_p[ibra * 108 + 40] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 25] );

                    HRR_INT__X_X_i_d[ibra * 168 + 53] = HRR_INT__X_X_k_p[ibra * 108 + 41] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 26] );

                    HRR_INT__X_X_i_d[ibra * 168 + 54] = HRR_INT__X_X_k_p[ibra * 108 + 27] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 27] );

                    HRR_INT__X_X_i_d[ibra * 168 + 55] = HRR_INT__X_X_k_p[ibra * 108 + 39] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 27] );

                    HRR_INT__X_X_i_d[ibra * 168 + 56] = HRR_INT__X_X_k_p[ibra * 108 + 42] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 27] );

                    HRR_INT__X_X_i_d[ibra * 168 + 57] = HRR_INT__X_X_k_p[ibra * 108 + 40] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 28] );

                    HRR_INT__X_X_i_d[ibra * 168 + 58] = HRR_INT__X_X_k_p[ibra * 108 + 43] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 28] );

                    HRR_INT__X_X_i_d[ibra * 168 + 59] = HRR_INT__X_X_k_p[ibra * 108 + 44] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 29] );

                    HRR_INT__X_X_i_d[ibra * 168 + 60] = HRR_INT__X_X_k_p[ibra * 108 + 30] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 30] );

                    HRR_INT__X_X_i_d[ibra * 168 + 61] = HRR_INT__X_X_k_p[ibra * 108 + 45] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 30] );

                    HRR_INT__X_X_i_d[ibra * 168 + 62] = HRR_INT__X_X_k_p[ibra * 108 + 48] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 30] );

                    HRR_INT__X_X_i_d[ibra * 168 + 63] = HRR_INT__X_X_k_p[ibra * 108 + 46] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 31] );

                    HRR_INT__X_X_i_d[ibra * 168 + 64] = HRR_INT__X_X_k_p[ibra * 108 + 49] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 31] );

                    HRR_INT__X_X_i_d[ibra * 168 + 65] = HRR_INT__X_X_k_p[ibra * 108 + 50] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 32] );

                    HRR_INT__X_X_i_d[ibra * 168 + 66] = HRR_INT__X_X_k_p[ibra * 108 + 33] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 33] );

                    HRR_INT__X_X_i_d[ibra * 168 + 67] = HRR_INT__X_X_k_p[ibra * 108 + 48] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 33] );

                    HRR_INT__X_X_i_d[ibra * 168 + 68] = HRR_INT__X_X_k_p[ibra * 108 + 51] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 33] );

                    HRR_INT__X_X_i_d[ibra * 168 + 69] = HRR_INT__X_X_k_p[ibra * 108 + 49] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 34] );

                    HRR_INT__X_X_i_d[ibra * 168 + 70] = HRR_INT__X_X_k_p[ibra * 108 + 52] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 34] );

                    HRR_INT__X_X_i_d[ibra * 168 + 71] = HRR_INT__X_X_k_p[ibra * 108 + 53] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 35] );

                    HRR_INT__X_X_i_d[ibra * 168 + 72] = HRR_INT__X_X_k_p[ibra * 108 + 36] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 36] );

                    HRR_INT__X_X_i_d[ibra * 168 + 73] = HRR_INT__X_X_k_p[ibra * 108 + 51] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 36] );

                    HRR_INT__X_X_i_d[ibra * 168 + 74] = HRR_INT__X_X_k_p[ibra * 108 + 54] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 36] );

                    HRR_INT__X_X_i_d[ibra * 168 + 75] = HRR_INT__X_X_k_p[ibra * 108 + 52] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 37] );

                    HRR_INT__X_X_i_d[ibra * 168 + 76] = HRR_INT__X_X_k_p[ibra * 108 + 55] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 37] );

                    HRR_INT__X_X_i_d[ibra * 168 + 77] = HRR_INT__X_X_k_p[ibra * 108 + 56] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 38] );

                    HRR_INT__X_X_i_d[ibra * 168 + 78] = HRR_INT__X_X_k_p[ibra * 108 + 39] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 39] );

                    HRR_INT__X_X_i_d[ibra * 168 + 79] = HRR_INT__X_X_k_p[ibra * 108 + 54] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 39] );

                    HRR_INT__X_X_i_d[ibra * 168 + 80] = HRR_INT__X_X_k_p[ibra * 108 + 57] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 39] );

                    HRR_INT__X_X_i_d[ibra * 168 + 81] = HRR_INT__X_X_k_p[ibra * 108 + 55] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 40] );

                    HRR_INT__X_X_i_d[ibra * 168 + 82] = HRR_INT__X_X_k_p[ibra * 108 + 58] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 40] );

                    HRR_INT__X_X_i_d[ibra * 168 + 83] = HRR_INT__X_X_k_p[ibra * 108 + 59] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 41] );

                    HRR_INT__X_X_i_d[ibra * 168 + 84] = HRR_INT__X_X_k_p[ibra * 108 + 42] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 42] );

                    HRR_INT__X_X_i_d[ibra * 168 + 85] = HRR_INT__X_X_k_p[ibra * 108 + 57] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 42] );

                    HRR_INT__X_X_i_d[ibra * 168 + 86] = HRR_INT__X_X_k_p[ibra * 108 + 60] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 42] );

                    HRR_INT__X_X_i_d[ibra * 168 + 87] = HRR_INT__X_X_k_p[ibra * 108 + 58] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 43] );

                    HRR_INT__X_X_i_d[ibra * 168 + 88] = HRR_INT__X_X_k_p[ibra * 108 + 61] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 43] );

                    HRR_INT__X_X_i_d[ibra * 168 + 89] = HRR_INT__X_X_k_p[ibra * 108 + 62] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 44] );

                    HRR_INT__X_X_i_d[ibra * 168 + 90] = HRR_INT__X_X_k_p[ibra * 108 + 45] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 45] );

                    HRR_INT__X_X_i_d[ibra * 168 + 91] = HRR_INT__X_X_k_p[ibra * 108 + 63] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 45] );

                    HRR_INT__X_X_i_d[ibra * 168 + 92] = HRR_INT__X_X_k_p[ibra * 108 + 66] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 45] );

                    HRR_INT__X_X_i_d[ibra * 168 + 93] = HRR_INT__X_X_k_p[ibra * 108 + 64] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 46] );

                    HRR_INT__X_X_i_d[ibra * 168 + 94] = HRR_INT__X_X_k_p[ibra * 108 + 67] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 46] );

                    HRR_INT__X_X_i_d[ibra * 168 + 95] = HRR_INT__X_X_k_p[ibra * 108 + 68] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 47] );

                    HRR_INT__X_X_i_d[ibra * 168 + 96] = HRR_INT__X_X_k_p[ibra * 108 + 48] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 48] );

                    HRR_INT__X_X_i_d[ibra * 168 + 97] = HRR_INT__X_X_k_p[ibra * 108 + 66] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 48] );

                    HRR_INT__X_X_i_d[ibra * 168 + 98] = HRR_INT__X_X_k_p[ibra * 108 + 69] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 48] );

                    HRR_INT__X_X_i_d[ibra * 168 + 99] = HRR_INT__X_X_k_p[ibra * 108 + 67] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 49] );

                    HRR_INT__X_X_i_d[ibra * 168 + 100] = HRR_INT__X_X_k_p[ibra * 108 + 70] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 49] );

                    HRR_INT__X_X_i_d[ibra * 168 + 101] = HRR_INT__X_X_k_p[ibra * 108 + 71] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 50] );

                    HRR_INT__X_X_i_d[ibra * 168 + 102] = HRR_INT__X_X_k_p[ibra * 108 + 51] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 51] );

                    HRR_INT__X_X_i_d[ibra * 168 + 103] = HRR_INT__X_X_k_p[ibra * 108 + 69] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 51] );

                    HRR_INT__X_X_i_d[ibra * 168 + 104] = HRR_INT__X_X_k_p[ibra * 108 + 72] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 51] );

                    HRR_INT__X_X_i_d[ibra * 168 + 105] = HRR_INT__X_X_k_p[ibra * 108 + 70] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 52] );

                    HRR_INT__X_X_i_d[ibra * 168 + 106] = HRR_INT__X_X_k_p[ibra * 108 + 73] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 52] );

                    HRR_INT__X_X_i_d[ibra * 168 + 107] = HRR_INT__X_X_k_p[ibra * 108 + 74] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 53] );

                    HRR_INT__X_X_i_d[ibra * 168 + 108] = HRR_INT__X_X_k_p[ibra * 108 + 54] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 54] );

                    HRR_INT__X_X_i_d[ibra * 168 + 109] = HRR_INT__X_X_k_p[ibra * 108 + 72] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 54] );

                    HRR_INT__X_X_i_d[ibra * 168 + 110] = HRR_INT__X_X_k_p[ibra * 108 + 75] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 54] );

                    HRR_INT__X_X_i_d[ibra * 168 + 111] = HRR_INT__X_X_k_p[ibra * 108 + 73] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 55] );

                    HRR_INT__X_X_i_d[ibra * 168 + 112] = HRR_INT__X_X_k_p[ibra * 108 + 76] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 55] );

                    HRR_INT__X_X_i_d[ibra * 168 + 113] = HRR_INT__X_X_k_p[ibra * 108 + 77] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 56] );

                    HRR_INT__X_X_i_d[ibra * 168 + 114] = HRR_INT__X_X_k_p[ibra * 108 + 57] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 57] );

                    HRR_INT__X_X_i_d[ibra * 168 + 115] = HRR_INT__X_X_k_p[ibra * 108 + 75] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 57] );

                    HRR_INT__X_X_i_d[ibra * 168 + 116] = HRR_INT__X_X_k_p[ibra * 108 + 78] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 57] );

                    HRR_INT__X_X_i_d[ibra * 168 + 117] = HRR_INT__X_X_k_p[ibra * 108 + 76] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 58] );

                    HRR_INT__X_X_i_d[ibra * 168 + 118] = HRR_INT__X_X_k_p[ibra * 108 + 79] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 58] );

                    HRR_INT__X_X_i_d[ibra * 168 + 119] = HRR_INT__X_X_k_p[ibra * 108 + 80] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 59] );

                    HRR_INT__X_X_i_d[ibra * 168 + 120] = HRR_INT__X_X_k_p[ibra * 108 + 60] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 60] );

                    HRR_INT__X_X_i_d[ibra * 168 + 121] = HRR_INT__X_X_k_p[ibra * 108 + 78] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 60] );

                    HRR_INT__X_X_i_d[ibra * 168 + 122] = HRR_INT__X_X_k_p[ibra * 108 + 81] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 60] );

                    HRR_INT__X_X_i_d[ibra * 168 + 123] = HRR_INT__X_X_k_p[ibra * 108 + 79] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 61] );

                    HRR_INT__X_X_i_d[ibra * 168 + 124] = HRR_INT__X_X_k_p[ibra * 108 + 82] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 61] );

                    HRR_INT__X_X_i_d[ibra * 168 + 125] = HRR_INT__X_X_k_p[ibra * 108 + 83] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 62] );

                    HRR_INT__X_X_i_d[ibra * 168 + 126] = HRR_INT__X_X_k_p[ibra * 108 + 63] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 63] );

                    HRR_INT__X_X_i_d[ibra * 168 + 127] = HRR_INT__X_X_k_p[ibra * 108 + 84] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 63] );

                    HRR_INT__X_X_i_d[ibra * 168 + 128] = HRR_INT__X_X_k_p[ibra * 108 + 87] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 63] );

                    HRR_INT__X_X_i_d[ibra * 168 + 129] = HRR_INT__X_X_k_p[ibra * 108 + 85] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 64] );

                    HRR_INT__X_X_i_d[ibra * 168 + 130] = HRR_INT__X_X_k_p[ibra * 108 + 88] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 64] );

                    HRR_INT__X_X_i_d[ibra * 168 + 131] = HRR_INT__X_X_k_p[ibra * 108 + 89] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 65] );

                    HRR_INT__X_X_i_d[ibra * 168 + 132] = HRR_INT__X_X_k_p[ibra * 108 + 66] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 66] );

                    HRR_INT__X_X_i_d[ibra * 168 + 133] = HRR_INT__X_X_k_p[ibra * 108 + 87] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 66] );

                    HRR_INT__X_X_i_d[ibra * 168 + 134] = HRR_INT__X_X_k_p[ibra * 108 + 90] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 66] );

                    HRR_INT__X_X_i_d[ibra * 168 + 135] = HRR_INT__X_X_k_p[ibra * 108 + 88] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 67] );

                    HRR_INT__X_X_i_d[ibra * 168 + 136] = HRR_INT__X_X_k_p[ibra * 108 + 91] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 67] );

                    HRR_INT__X_X_i_d[ibra * 168 + 137] = HRR_INT__X_X_k_p[ibra * 108 + 92] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 68] );

                    HRR_INT__X_X_i_d[ibra * 168 + 138] = HRR_INT__X_X_k_p[ibra * 108 + 69] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 69] );

                    HRR_INT__X_X_i_d[ibra * 168 + 139] = HRR_INT__X_X_k_p[ibra * 108 + 90] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 69] );

                    HRR_INT__X_X_i_d[ibra * 168 + 140] = HRR_INT__X_X_k_p[ibra * 108 + 93] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 69] );

                    HRR_INT__X_X_i_d[ibra * 168 + 141] = HRR_INT__X_X_k_p[ibra * 108 + 91] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 70] );

                    HRR_INT__X_X_i_d[ibra * 168 + 142] = HRR_INT__X_X_k_p[ibra * 108 + 94] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 70] );

                    HRR_INT__X_X_i_d[ibra * 168 + 143] = HRR_INT__X_X_k_p[ibra * 108 + 95] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 71] );

                    HRR_INT__X_X_i_d[ibra * 168 + 144] = HRR_INT__X_X_k_p[ibra * 108 + 72] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 72] );

                    HRR_INT__X_X_i_d[ibra * 168 + 145] = HRR_INT__X_X_k_p[ibra * 108 + 93] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 72] );

                    HRR_INT__X_X_i_d[ibra * 168 + 146] = HRR_INT__X_X_k_p[ibra * 108 + 96] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 72] );

                    HRR_INT__X_X_i_d[ibra * 168 + 147] = HRR_INT__X_X_k_p[ibra * 108 + 94] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 73] );

                    HRR_INT__X_X_i_d[ibra * 168 + 148] = HRR_INT__X_X_k_p[ibra * 108 + 97] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 73] );

                    HRR_INT__X_X_i_d[ibra * 168 + 149] = HRR_INT__X_X_k_p[ibra * 108 + 98] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 74] );

                    HRR_INT__X_X_i_d[ibra * 168 + 150] = HRR_INT__X_X_k_p[ibra * 108 + 75] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 75] );

                    HRR_INT__X_X_i_d[ibra * 168 + 151] = HRR_INT__X_X_k_p[ibra * 108 + 96] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 75] );

                    HRR_INT__X_X_i_d[ibra * 168 + 152] = HRR_INT__X_X_k_p[ibra * 108 + 99] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 75] );

                    HRR_INT__X_X_i_d[ibra * 168 + 153] = HRR_INT__X_X_k_p[ibra * 108 + 97] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 76] );

                    HRR_INT__X_X_i_d[ibra * 168 + 154] = HRR_INT__X_X_k_p[ibra * 108 + 100] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 76] );

                    HRR_INT__X_X_i_d[ibra * 168 + 155] = HRR_INT__X_X_k_p[ibra * 108 + 101] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 77] );

                    HRR_INT__X_X_i_d[ibra * 168 + 156] = HRR_INT__X_X_k_p[ibra * 108 + 78] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 78] );

                    HRR_INT__X_X_i_d[ibra * 168 + 157] = HRR_INT__X_X_k_p[ibra * 108 + 99] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 78] );

                    HRR_INT__X_X_i_d[ibra * 168 + 158] = HRR_INT__X_X_k_p[ibra * 108 + 102] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 78] );

                    HRR_INT__X_X_i_d[ibra * 168 + 159] = HRR_INT__X_X_k_p[ibra * 108 + 100] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 79] );

                    HRR_INT__X_X_i_d[ibra * 168 + 160] = HRR_INT__X_X_k_p[ibra * 108 + 103] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 79] );

                    HRR_INT__X_X_i_d[ibra * 168 + 161] = HRR_INT__X_X_k_p[ibra * 108 + 104] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 80] );

                    HRR_INT__X_X_i_d[ibra * 168 + 162] = HRR_INT__X_X_k_p[ibra * 108 + 81] + ( hCD[0] * HRR_INT__X_X_i_p[ibra * 84 + 81] );

                    HRR_INT__X_X_i_d[ibra * 168 + 163] = HRR_INT__X_X_k_p[ibra * 108 + 102] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 81] );

                    HRR_INT__X_X_i_d[ibra * 168 + 164] = HRR_INT__X_X_k_p[ibra * 108 + 105] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 81] );

                    HRR_INT__X_X_i_d[ibra * 168 + 165] = HRR_INT__X_X_k_p[ibra * 108 + 103] + ( hCD[1] * HRR_INT__X_X_i_p[ibra * 84 + 82] );

                    HRR_INT__X_X_i_d[ibra * 168 + 166] = HRR_INT__X_X_k_p[ibra * 108 + 106] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 82] );

                    HRR_INT__X_X_i_d[ibra * 168 + 167] = HRR_INT__X_X_k_p[ibra * 108 + 107] + ( hCD[2] * HRR_INT__X_X_i_p[ibra * 84 + 83] );

                }

}


