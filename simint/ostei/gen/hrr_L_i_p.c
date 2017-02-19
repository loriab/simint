
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// KET: | i p )
// Steps: 84
//////////////////////////////////////////////

void HRR_L_i_p(double * const restrict HRR_INT__X_X_i_p,
                    double const * const restrict HRR_INT__X_X_i_s,
                    double const * const restrict HRR_INT__X_X_k_s,
                    const double hCD[3], const int ncart_bra)
{
    int ibra;

                for(ibra = 0; ibra < ncart_bra; ++ibra)
                {
                    HRR_INT__X_X_i_p[ibra * 84 + 0] = HRR_INT__X_X_k_s[ibra * 36 + 0] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 0] );

                    HRR_INT__X_X_i_p[ibra * 84 + 1] = HRR_INT__X_X_k_s[ibra * 36 + 1] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 0] );

                    HRR_INT__X_X_i_p[ibra * 84 + 2] = HRR_INT__X_X_k_s[ibra * 36 + 2] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 0] );

                    HRR_INT__X_X_i_p[ibra * 84 + 3] = HRR_INT__X_X_k_s[ibra * 36 + 1] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 1] );

                    HRR_INT__X_X_i_p[ibra * 84 + 4] = HRR_INT__X_X_k_s[ibra * 36 + 3] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 1] );

                    HRR_INT__X_X_i_p[ibra * 84 + 5] = HRR_INT__X_X_k_s[ibra * 36 + 4] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 1] );

                    HRR_INT__X_X_i_p[ibra * 84 + 6] = HRR_INT__X_X_k_s[ibra * 36 + 2] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 2] );

                    HRR_INT__X_X_i_p[ibra * 84 + 7] = HRR_INT__X_X_k_s[ibra * 36 + 4] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 2] );

                    HRR_INT__X_X_i_p[ibra * 84 + 8] = HRR_INT__X_X_k_s[ibra * 36 + 5] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 2] );

                    HRR_INT__X_X_i_p[ibra * 84 + 9] = HRR_INT__X_X_k_s[ibra * 36 + 3] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 3] );

                    HRR_INT__X_X_i_p[ibra * 84 + 10] = HRR_INT__X_X_k_s[ibra * 36 + 6] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 3] );

                    HRR_INT__X_X_i_p[ibra * 84 + 11] = HRR_INT__X_X_k_s[ibra * 36 + 7] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 3] );

                    HRR_INT__X_X_i_p[ibra * 84 + 12] = HRR_INT__X_X_k_s[ibra * 36 + 4] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 4] );

                    HRR_INT__X_X_i_p[ibra * 84 + 13] = HRR_INT__X_X_k_s[ibra * 36 + 7] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 4] );

                    HRR_INT__X_X_i_p[ibra * 84 + 14] = HRR_INT__X_X_k_s[ibra * 36 + 8] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 4] );

                    HRR_INT__X_X_i_p[ibra * 84 + 15] = HRR_INT__X_X_k_s[ibra * 36 + 5] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 5] );

                    HRR_INT__X_X_i_p[ibra * 84 + 16] = HRR_INT__X_X_k_s[ibra * 36 + 8] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 5] );

                    HRR_INT__X_X_i_p[ibra * 84 + 17] = HRR_INT__X_X_k_s[ibra * 36 + 9] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 5] );

                    HRR_INT__X_X_i_p[ibra * 84 + 18] = HRR_INT__X_X_k_s[ibra * 36 + 6] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 6] );

                    HRR_INT__X_X_i_p[ibra * 84 + 19] = HRR_INT__X_X_k_s[ibra * 36 + 10] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 6] );

                    HRR_INT__X_X_i_p[ibra * 84 + 20] = HRR_INT__X_X_k_s[ibra * 36 + 11] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 6] );

                    HRR_INT__X_X_i_p[ibra * 84 + 21] = HRR_INT__X_X_k_s[ibra * 36 + 7] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 7] );

                    HRR_INT__X_X_i_p[ibra * 84 + 22] = HRR_INT__X_X_k_s[ibra * 36 + 11] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 7] );

                    HRR_INT__X_X_i_p[ibra * 84 + 23] = HRR_INT__X_X_k_s[ibra * 36 + 12] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 7] );

                    HRR_INT__X_X_i_p[ibra * 84 + 24] = HRR_INT__X_X_k_s[ibra * 36 + 8] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 8] );

                    HRR_INT__X_X_i_p[ibra * 84 + 25] = HRR_INT__X_X_k_s[ibra * 36 + 12] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 8] );

                    HRR_INT__X_X_i_p[ibra * 84 + 26] = HRR_INT__X_X_k_s[ibra * 36 + 13] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 8] );

                    HRR_INT__X_X_i_p[ibra * 84 + 27] = HRR_INT__X_X_k_s[ibra * 36 + 9] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 9] );

                    HRR_INT__X_X_i_p[ibra * 84 + 28] = HRR_INT__X_X_k_s[ibra * 36 + 13] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 9] );

                    HRR_INT__X_X_i_p[ibra * 84 + 29] = HRR_INT__X_X_k_s[ibra * 36 + 14] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 9] );

                    HRR_INT__X_X_i_p[ibra * 84 + 30] = HRR_INT__X_X_k_s[ibra * 36 + 10] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 10] );

                    HRR_INT__X_X_i_p[ibra * 84 + 31] = HRR_INT__X_X_k_s[ibra * 36 + 15] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 10] );

                    HRR_INT__X_X_i_p[ibra * 84 + 32] = HRR_INT__X_X_k_s[ibra * 36 + 16] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 10] );

                    HRR_INT__X_X_i_p[ibra * 84 + 33] = HRR_INT__X_X_k_s[ibra * 36 + 11] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 11] );

                    HRR_INT__X_X_i_p[ibra * 84 + 34] = HRR_INT__X_X_k_s[ibra * 36 + 16] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 11] );

                    HRR_INT__X_X_i_p[ibra * 84 + 35] = HRR_INT__X_X_k_s[ibra * 36 + 17] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 11] );

                    HRR_INT__X_X_i_p[ibra * 84 + 36] = HRR_INT__X_X_k_s[ibra * 36 + 12] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 12] );

                    HRR_INT__X_X_i_p[ibra * 84 + 37] = HRR_INT__X_X_k_s[ibra * 36 + 17] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 12] );

                    HRR_INT__X_X_i_p[ibra * 84 + 38] = HRR_INT__X_X_k_s[ibra * 36 + 18] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 12] );

                    HRR_INT__X_X_i_p[ibra * 84 + 39] = HRR_INT__X_X_k_s[ibra * 36 + 13] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 13] );

                    HRR_INT__X_X_i_p[ibra * 84 + 40] = HRR_INT__X_X_k_s[ibra * 36 + 18] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 13] );

                    HRR_INT__X_X_i_p[ibra * 84 + 41] = HRR_INT__X_X_k_s[ibra * 36 + 19] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 13] );

                    HRR_INT__X_X_i_p[ibra * 84 + 42] = HRR_INT__X_X_k_s[ibra * 36 + 14] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 14] );

                    HRR_INT__X_X_i_p[ibra * 84 + 43] = HRR_INT__X_X_k_s[ibra * 36 + 19] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 14] );

                    HRR_INT__X_X_i_p[ibra * 84 + 44] = HRR_INT__X_X_k_s[ibra * 36 + 20] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 14] );

                    HRR_INT__X_X_i_p[ibra * 84 + 45] = HRR_INT__X_X_k_s[ibra * 36 + 15] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 15] );

                    HRR_INT__X_X_i_p[ibra * 84 + 46] = HRR_INT__X_X_k_s[ibra * 36 + 21] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 15] );

                    HRR_INT__X_X_i_p[ibra * 84 + 47] = HRR_INT__X_X_k_s[ibra * 36 + 22] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 15] );

                    HRR_INT__X_X_i_p[ibra * 84 + 48] = HRR_INT__X_X_k_s[ibra * 36 + 16] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 16] );

                    HRR_INT__X_X_i_p[ibra * 84 + 49] = HRR_INT__X_X_k_s[ibra * 36 + 22] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 16] );

                    HRR_INT__X_X_i_p[ibra * 84 + 50] = HRR_INT__X_X_k_s[ibra * 36 + 23] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 16] );

                    HRR_INT__X_X_i_p[ibra * 84 + 51] = HRR_INT__X_X_k_s[ibra * 36 + 17] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 17] );

                    HRR_INT__X_X_i_p[ibra * 84 + 52] = HRR_INT__X_X_k_s[ibra * 36 + 23] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 17] );

                    HRR_INT__X_X_i_p[ibra * 84 + 53] = HRR_INT__X_X_k_s[ibra * 36 + 24] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 17] );

                    HRR_INT__X_X_i_p[ibra * 84 + 54] = HRR_INT__X_X_k_s[ibra * 36 + 18] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 18] );

                    HRR_INT__X_X_i_p[ibra * 84 + 55] = HRR_INT__X_X_k_s[ibra * 36 + 24] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 18] );

                    HRR_INT__X_X_i_p[ibra * 84 + 56] = HRR_INT__X_X_k_s[ibra * 36 + 25] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 18] );

                    HRR_INT__X_X_i_p[ibra * 84 + 57] = HRR_INT__X_X_k_s[ibra * 36 + 19] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 19] );

                    HRR_INT__X_X_i_p[ibra * 84 + 58] = HRR_INT__X_X_k_s[ibra * 36 + 25] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 19] );

                    HRR_INT__X_X_i_p[ibra * 84 + 59] = HRR_INT__X_X_k_s[ibra * 36 + 26] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 19] );

                    HRR_INT__X_X_i_p[ibra * 84 + 60] = HRR_INT__X_X_k_s[ibra * 36 + 20] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 20] );

                    HRR_INT__X_X_i_p[ibra * 84 + 61] = HRR_INT__X_X_k_s[ibra * 36 + 26] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 20] );

                    HRR_INT__X_X_i_p[ibra * 84 + 62] = HRR_INT__X_X_k_s[ibra * 36 + 27] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 20] );

                    HRR_INT__X_X_i_p[ibra * 84 + 63] = HRR_INT__X_X_k_s[ibra * 36 + 21] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 21] );

                    HRR_INT__X_X_i_p[ibra * 84 + 64] = HRR_INT__X_X_k_s[ibra * 36 + 28] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 21] );

                    HRR_INT__X_X_i_p[ibra * 84 + 65] = HRR_INT__X_X_k_s[ibra * 36 + 29] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 21] );

                    HRR_INT__X_X_i_p[ibra * 84 + 66] = HRR_INT__X_X_k_s[ibra * 36 + 22] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 22] );

                    HRR_INT__X_X_i_p[ibra * 84 + 67] = HRR_INT__X_X_k_s[ibra * 36 + 29] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 22] );

                    HRR_INT__X_X_i_p[ibra * 84 + 68] = HRR_INT__X_X_k_s[ibra * 36 + 30] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 22] );

                    HRR_INT__X_X_i_p[ibra * 84 + 69] = HRR_INT__X_X_k_s[ibra * 36 + 23] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 23] );

                    HRR_INT__X_X_i_p[ibra * 84 + 70] = HRR_INT__X_X_k_s[ibra * 36 + 30] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 23] );

                    HRR_INT__X_X_i_p[ibra * 84 + 71] = HRR_INT__X_X_k_s[ibra * 36 + 31] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 23] );

                    HRR_INT__X_X_i_p[ibra * 84 + 72] = HRR_INT__X_X_k_s[ibra * 36 + 24] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 24] );

                    HRR_INT__X_X_i_p[ibra * 84 + 73] = HRR_INT__X_X_k_s[ibra * 36 + 31] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 24] );

                    HRR_INT__X_X_i_p[ibra * 84 + 74] = HRR_INT__X_X_k_s[ibra * 36 + 32] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 24] );

                    HRR_INT__X_X_i_p[ibra * 84 + 75] = HRR_INT__X_X_k_s[ibra * 36 + 25] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 25] );

                    HRR_INT__X_X_i_p[ibra * 84 + 76] = HRR_INT__X_X_k_s[ibra * 36 + 32] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 25] );

                    HRR_INT__X_X_i_p[ibra * 84 + 77] = HRR_INT__X_X_k_s[ibra * 36 + 33] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 25] );

                    HRR_INT__X_X_i_p[ibra * 84 + 78] = HRR_INT__X_X_k_s[ibra * 36 + 26] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 26] );

                    HRR_INT__X_X_i_p[ibra * 84 + 79] = HRR_INT__X_X_k_s[ibra * 36 + 33] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 26] );

                    HRR_INT__X_X_i_p[ibra * 84 + 80] = HRR_INT__X_X_k_s[ibra * 36 + 34] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 26] );

                    HRR_INT__X_X_i_p[ibra * 84 + 81] = HRR_INT__X_X_k_s[ibra * 36 + 27] + ( hCD[0] * HRR_INT__X_X_i_s[ibra * 28 + 27] );

                    HRR_INT__X_X_i_p[ibra * 84 + 82] = HRR_INT__X_X_k_s[ibra * 36 + 34] + ( hCD[1] * HRR_INT__X_X_i_s[ibra * 28 + 27] );

                    HRR_INT__X_X_i_p[ibra * 84 + 83] = HRR_INT__X_X_k_s[ibra * 36 + 35] + ( hCD[2] * HRR_INT__X_X_i_s[ibra * 28 + 27] );

                }

}


