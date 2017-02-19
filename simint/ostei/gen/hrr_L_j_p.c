
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// KET: | k p )
// Steps: 108
//////////////////////////////////////////////

void HRR_L_k_p(double * const restrict HRR_INT__X_X_k_p,
                    double const * const restrict HRR_INT__X_X_k_s,
                    double const * const restrict HRR_INT__X_X_l_s,
                    const double hCD[3], const int ncart_bra)
{
    int ibra;

                for(ibra = 0; ibra < ncart_bra; ++ibra)
                {
                    HRR_INT__X_X_k_p[ibra * 108 + 0] = HRR_INT__X_X_l_s[ibra * 45 + 0] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 0] );

                    HRR_INT__X_X_k_p[ibra * 108 + 1] = HRR_INT__X_X_l_s[ibra * 45 + 1] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 0] );

                    HRR_INT__X_X_k_p[ibra * 108 + 2] = HRR_INT__X_X_l_s[ibra * 45 + 2] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 0] );

                    HRR_INT__X_X_k_p[ibra * 108 + 3] = HRR_INT__X_X_l_s[ibra * 45 + 1] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 1] );

                    HRR_INT__X_X_k_p[ibra * 108 + 4] = HRR_INT__X_X_l_s[ibra * 45 + 3] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 1] );

                    HRR_INT__X_X_k_p[ibra * 108 + 5] = HRR_INT__X_X_l_s[ibra * 45 + 4] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 1] );

                    HRR_INT__X_X_k_p[ibra * 108 + 6] = HRR_INT__X_X_l_s[ibra * 45 + 2] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 2] );

                    HRR_INT__X_X_k_p[ibra * 108 + 7] = HRR_INT__X_X_l_s[ibra * 45 + 4] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 2] );

                    HRR_INT__X_X_k_p[ibra * 108 + 8] = HRR_INT__X_X_l_s[ibra * 45 + 5] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 2] );

                    HRR_INT__X_X_k_p[ibra * 108 + 9] = HRR_INT__X_X_l_s[ibra * 45 + 3] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 3] );

                    HRR_INT__X_X_k_p[ibra * 108 + 10] = HRR_INT__X_X_l_s[ibra * 45 + 6] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 3] );

                    HRR_INT__X_X_k_p[ibra * 108 + 11] = HRR_INT__X_X_l_s[ibra * 45 + 7] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 3] );

                    HRR_INT__X_X_k_p[ibra * 108 + 12] = HRR_INT__X_X_l_s[ibra * 45 + 4] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 4] );

                    HRR_INT__X_X_k_p[ibra * 108 + 13] = HRR_INT__X_X_l_s[ibra * 45 + 7] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 4] );

                    HRR_INT__X_X_k_p[ibra * 108 + 14] = HRR_INT__X_X_l_s[ibra * 45 + 8] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 4] );

                    HRR_INT__X_X_k_p[ibra * 108 + 15] = HRR_INT__X_X_l_s[ibra * 45 + 5] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 5] );

                    HRR_INT__X_X_k_p[ibra * 108 + 16] = HRR_INT__X_X_l_s[ibra * 45 + 8] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 5] );

                    HRR_INT__X_X_k_p[ibra * 108 + 17] = HRR_INT__X_X_l_s[ibra * 45 + 9] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 5] );

                    HRR_INT__X_X_k_p[ibra * 108 + 18] = HRR_INT__X_X_l_s[ibra * 45 + 6] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 6] );

                    HRR_INT__X_X_k_p[ibra * 108 + 19] = HRR_INT__X_X_l_s[ibra * 45 + 10] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 6] );

                    HRR_INT__X_X_k_p[ibra * 108 + 20] = HRR_INT__X_X_l_s[ibra * 45 + 11] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 6] );

                    HRR_INT__X_X_k_p[ibra * 108 + 21] = HRR_INT__X_X_l_s[ibra * 45 + 7] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 7] );

                    HRR_INT__X_X_k_p[ibra * 108 + 22] = HRR_INT__X_X_l_s[ibra * 45 + 11] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 7] );

                    HRR_INT__X_X_k_p[ibra * 108 + 23] = HRR_INT__X_X_l_s[ibra * 45 + 12] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 7] );

                    HRR_INT__X_X_k_p[ibra * 108 + 24] = HRR_INT__X_X_l_s[ibra * 45 + 8] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 8] );

                    HRR_INT__X_X_k_p[ibra * 108 + 25] = HRR_INT__X_X_l_s[ibra * 45 + 12] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 8] );

                    HRR_INT__X_X_k_p[ibra * 108 + 26] = HRR_INT__X_X_l_s[ibra * 45 + 13] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 8] );

                    HRR_INT__X_X_k_p[ibra * 108 + 27] = HRR_INT__X_X_l_s[ibra * 45 + 9] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 9] );

                    HRR_INT__X_X_k_p[ibra * 108 + 28] = HRR_INT__X_X_l_s[ibra * 45 + 13] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 9] );

                    HRR_INT__X_X_k_p[ibra * 108 + 29] = HRR_INT__X_X_l_s[ibra * 45 + 14] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 9] );

                    HRR_INT__X_X_k_p[ibra * 108 + 30] = HRR_INT__X_X_l_s[ibra * 45 + 10] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 10] );

                    HRR_INT__X_X_k_p[ibra * 108 + 31] = HRR_INT__X_X_l_s[ibra * 45 + 15] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 10] );

                    HRR_INT__X_X_k_p[ibra * 108 + 32] = HRR_INT__X_X_l_s[ibra * 45 + 16] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 10] );

                    HRR_INT__X_X_k_p[ibra * 108 + 33] = HRR_INT__X_X_l_s[ibra * 45 + 11] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 11] );

                    HRR_INT__X_X_k_p[ibra * 108 + 34] = HRR_INT__X_X_l_s[ibra * 45 + 16] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 11] );

                    HRR_INT__X_X_k_p[ibra * 108 + 35] = HRR_INT__X_X_l_s[ibra * 45 + 17] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 11] );

                    HRR_INT__X_X_k_p[ibra * 108 + 36] = HRR_INT__X_X_l_s[ibra * 45 + 12] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 12] );

                    HRR_INT__X_X_k_p[ibra * 108 + 37] = HRR_INT__X_X_l_s[ibra * 45 + 17] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 12] );

                    HRR_INT__X_X_k_p[ibra * 108 + 38] = HRR_INT__X_X_l_s[ibra * 45 + 18] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 12] );

                    HRR_INT__X_X_k_p[ibra * 108 + 39] = HRR_INT__X_X_l_s[ibra * 45 + 13] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 13] );

                    HRR_INT__X_X_k_p[ibra * 108 + 40] = HRR_INT__X_X_l_s[ibra * 45 + 18] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 13] );

                    HRR_INT__X_X_k_p[ibra * 108 + 41] = HRR_INT__X_X_l_s[ibra * 45 + 19] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 13] );

                    HRR_INT__X_X_k_p[ibra * 108 + 42] = HRR_INT__X_X_l_s[ibra * 45 + 14] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 14] );

                    HRR_INT__X_X_k_p[ibra * 108 + 43] = HRR_INT__X_X_l_s[ibra * 45 + 19] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 14] );

                    HRR_INT__X_X_k_p[ibra * 108 + 44] = HRR_INT__X_X_l_s[ibra * 45 + 20] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 14] );

                    HRR_INT__X_X_k_p[ibra * 108 + 45] = HRR_INT__X_X_l_s[ibra * 45 + 15] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 15] );

                    HRR_INT__X_X_k_p[ibra * 108 + 46] = HRR_INT__X_X_l_s[ibra * 45 + 21] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 15] );

                    HRR_INT__X_X_k_p[ibra * 108 + 47] = HRR_INT__X_X_l_s[ibra * 45 + 22] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 15] );

                    HRR_INT__X_X_k_p[ibra * 108 + 48] = HRR_INT__X_X_l_s[ibra * 45 + 16] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 16] );

                    HRR_INT__X_X_k_p[ibra * 108 + 49] = HRR_INT__X_X_l_s[ibra * 45 + 22] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 16] );

                    HRR_INT__X_X_k_p[ibra * 108 + 50] = HRR_INT__X_X_l_s[ibra * 45 + 23] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 16] );

                    HRR_INT__X_X_k_p[ibra * 108 + 51] = HRR_INT__X_X_l_s[ibra * 45 + 17] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 17] );

                    HRR_INT__X_X_k_p[ibra * 108 + 52] = HRR_INT__X_X_l_s[ibra * 45 + 23] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 17] );

                    HRR_INT__X_X_k_p[ibra * 108 + 53] = HRR_INT__X_X_l_s[ibra * 45 + 24] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 17] );

                    HRR_INT__X_X_k_p[ibra * 108 + 54] = HRR_INT__X_X_l_s[ibra * 45 + 18] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 18] );

                    HRR_INT__X_X_k_p[ibra * 108 + 55] = HRR_INT__X_X_l_s[ibra * 45 + 24] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 18] );

                    HRR_INT__X_X_k_p[ibra * 108 + 56] = HRR_INT__X_X_l_s[ibra * 45 + 25] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 18] );

                    HRR_INT__X_X_k_p[ibra * 108 + 57] = HRR_INT__X_X_l_s[ibra * 45 + 19] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 19] );

                    HRR_INT__X_X_k_p[ibra * 108 + 58] = HRR_INT__X_X_l_s[ibra * 45 + 25] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 19] );

                    HRR_INT__X_X_k_p[ibra * 108 + 59] = HRR_INT__X_X_l_s[ibra * 45 + 26] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 19] );

                    HRR_INT__X_X_k_p[ibra * 108 + 60] = HRR_INT__X_X_l_s[ibra * 45 + 20] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 20] );

                    HRR_INT__X_X_k_p[ibra * 108 + 61] = HRR_INT__X_X_l_s[ibra * 45 + 26] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 20] );

                    HRR_INT__X_X_k_p[ibra * 108 + 62] = HRR_INT__X_X_l_s[ibra * 45 + 27] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 20] );

                    HRR_INT__X_X_k_p[ibra * 108 + 63] = HRR_INT__X_X_l_s[ibra * 45 + 21] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 21] );

                    HRR_INT__X_X_k_p[ibra * 108 + 64] = HRR_INT__X_X_l_s[ibra * 45 + 28] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 21] );

                    HRR_INT__X_X_k_p[ibra * 108 + 65] = HRR_INT__X_X_l_s[ibra * 45 + 29] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 21] );

                    HRR_INT__X_X_k_p[ibra * 108 + 66] = HRR_INT__X_X_l_s[ibra * 45 + 22] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 22] );

                    HRR_INT__X_X_k_p[ibra * 108 + 67] = HRR_INT__X_X_l_s[ibra * 45 + 29] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 22] );

                    HRR_INT__X_X_k_p[ibra * 108 + 68] = HRR_INT__X_X_l_s[ibra * 45 + 30] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 22] );

                    HRR_INT__X_X_k_p[ibra * 108 + 69] = HRR_INT__X_X_l_s[ibra * 45 + 23] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 23] );

                    HRR_INT__X_X_k_p[ibra * 108 + 70] = HRR_INT__X_X_l_s[ibra * 45 + 30] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 23] );

                    HRR_INT__X_X_k_p[ibra * 108 + 71] = HRR_INT__X_X_l_s[ibra * 45 + 31] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 23] );

                    HRR_INT__X_X_k_p[ibra * 108 + 72] = HRR_INT__X_X_l_s[ibra * 45 + 24] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 24] );

                    HRR_INT__X_X_k_p[ibra * 108 + 73] = HRR_INT__X_X_l_s[ibra * 45 + 31] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 24] );

                    HRR_INT__X_X_k_p[ibra * 108 + 74] = HRR_INT__X_X_l_s[ibra * 45 + 32] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 24] );

                    HRR_INT__X_X_k_p[ibra * 108 + 75] = HRR_INT__X_X_l_s[ibra * 45 + 25] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 25] );

                    HRR_INT__X_X_k_p[ibra * 108 + 76] = HRR_INT__X_X_l_s[ibra * 45 + 32] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 25] );

                    HRR_INT__X_X_k_p[ibra * 108 + 77] = HRR_INT__X_X_l_s[ibra * 45 + 33] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 25] );

                    HRR_INT__X_X_k_p[ibra * 108 + 78] = HRR_INT__X_X_l_s[ibra * 45 + 26] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 26] );

                    HRR_INT__X_X_k_p[ibra * 108 + 79] = HRR_INT__X_X_l_s[ibra * 45 + 33] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 26] );

                    HRR_INT__X_X_k_p[ibra * 108 + 80] = HRR_INT__X_X_l_s[ibra * 45 + 34] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 26] );

                    HRR_INT__X_X_k_p[ibra * 108 + 81] = HRR_INT__X_X_l_s[ibra * 45 + 27] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 27] );

                    HRR_INT__X_X_k_p[ibra * 108 + 82] = HRR_INT__X_X_l_s[ibra * 45 + 34] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 27] );

                    HRR_INT__X_X_k_p[ibra * 108 + 83] = HRR_INT__X_X_l_s[ibra * 45 + 35] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 27] );

                    HRR_INT__X_X_k_p[ibra * 108 + 84] = HRR_INT__X_X_l_s[ibra * 45 + 28] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 28] );

                    HRR_INT__X_X_k_p[ibra * 108 + 85] = HRR_INT__X_X_l_s[ibra * 45 + 36] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 28] );

                    HRR_INT__X_X_k_p[ibra * 108 + 86] = HRR_INT__X_X_l_s[ibra * 45 + 37] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 28] );

                    HRR_INT__X_X_k_p[ibra * 108 + 87] = HRR_INT__X_X_l_s[ibra * 45 + 29] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 29] );

                    HRR_INT__X_X_k_p[ibra * 108 + 88] = HRR_INT__X_X_l_s[ibra * 45 + 37] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 29] );

                    HRR_INT__X_X_k_p[ibra * 108 + 89] = HRR_INT__X_X_l_s[ibra * 45 + 38] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 29] );

                    HRR_INT__X_X_k_p[ibra * 108 + 90] = HRR_INT__X_X_l_s[ibra * 45 + 30] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 30] );

                    HRR_INT__X_X_k_p[ibra * 108 + 91] = HRR_INT__X_X_l_s[ibra * 45 + 38] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 30] );

                    HRR_INT__X_X_k_p[ibra * 108 + 92] = HRR_INT__X_X_l_s[ibra * 45 + 39] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 30] );

                    HRR_INT__X_X_k_p[ibra * 108 + 93] = HRR_INT__X_X_l_s[ibra * 45 + 31] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 31] );

                    HRR_INT__X_X_k_p[ibra * 108 + 94] = HRR_INT__X_X_l_s[ibra * 45 + 39] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 31] );

                    HRR_INT__X_X_k_p[ibra * 108 + 95] = HRR_INT__X_X_l_s[ibra * 45 + 40] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 31] );

                    HRR_INT__X_X_k_p[ibra * 108 + 96] = HRR_INT__X_X_l_s[ibra * 45 + 32] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 32] );

                    HRR_INT__X_X_k_p[ibra * 108 + 97] = HRR_INT__X_X_l_s[ibra * 45 + 40] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 32] );

                    HRR_INT__X_X_k_p[ibra * 108 + 98] = HRR_INT__X_X_l_s[ibra * 45 + 41] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 32] );

                    HRR_INT__X_X_k_p[ibra * 108 + 99] = HRR_INT__X_X_l_s[ibra * 45 + 33] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 33] );

                    HRR_INT__X_X_k_p[ibra * 108 + 100] = HRR_INT__X_X_l_s[ibra * 45 + 41] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 33] );

                    HRR_INT__X_X_k_p[ibra * 108 + 101] = HRR_INT__X_X_l_s[ibra * 45 + 42] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 33] );

                    HRR_INT__X_X_k_p[ibra * 108 + 102] = HRR_INT__X_X_l_s[ibra * 45 + 34] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 34] );

                    HRR_INT__X_X_k_p[ibra * 108 + 103] = HRR_INT__X_X_l_s[ibra * 45 + 42] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 34] );

                    HRR_INT__X_X_k_p[ibra * 108 + 104] = HRR_INT__X_X_l_s[ibra * 45 + 43] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 34] );

                    HRR_INT__X_X_k_p[ibra * 108 + 105] = HRR_INT__X_X_l_s[ibra * 45 + 35] + ( hCD[0] * HRR_INT__X_X_k_s[ibra * 36 + 35] );

                    HRR_INT__X_X_k_p[ibra * 108 + 106] = HRR_INT__X_X_l_s[ibra * 45 + 43] + ( hCD[1] * HRR_INT__X_X_k_s[ibra * 36 + 35] );

                    HRR_INT__X_X_k_p[ibra * 108 + 107] = HRR_INT__X_X_l_s[ibra * 45 + 44] + ( hCD[2] * HRR_INT__X_X_k_s[ibra * 36 + 35] );

                }

}


