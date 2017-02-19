
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// KET: | h p )
// Steps: 63
//////////////////////////////////////////////

void HRR_L_h_p(double * const restrict HRR_INT__X_X_h_p,
                    double const * const restrict HRR_INT__X_X_h_s,
                    double const * const restrict HRR_INT__X_X_i_s,
                    const double hCD[3], const int ncart_bra)
{
    int ibra;

                for(ibra = 0; ibra < ncart_bra; ++ibra)
                {
                    HRR_INT__X_X_h_p[ibra * 63 + 0] = HRR_INT__X_X_i_s[ibra * 28 + 0] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 0] );

                    HRR_INT__X_X_h_p[ibra * 63 + 1] = HRR_INT__X_X_i_s[ibra * 28 + 1] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 0] );

                    HRR_INT__X_X_h_p[ibra * 63 + 2] = HRR_INT__X_X_i_s[ibra * 28 + 2] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 0] );

                    HRR_INT__X_X_h_p[ibra * 63 + 3] = HRR_INT__X_X_i_s[ibra * 28 + 1] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 1] );

                    HRR_INT__X_X_h_p[ibra * 63 + 4] = HRR_INT__X_X_i_s[ibra * 28 + 3] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 1] );

                    HRR_INT__X_X_h_p[ibra * 63 + 5] = HRR_INT__X_X_i_s[ibra * 28 + 4] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 1] );

                    HRR_INT__X_X_h_p[ibra * 63 + 6] = HRR_INT__X_X_i_s[ibra * 28 + 2] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 2] );

                    HRR_INT__X_X_h_p[ibra * 63 + 7] = HRR_INT__X_X_i_s[ibra * 28 + 4] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 2] );

                    HRR_INT__X_X_h_p[ibra * 63 + 8] = HRR_INT__X_X_i_s[ibra * 28 + 5] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 2] );

                    HRR_INT__X_X_h_p[ibra * 63 + 9] = HRR_INT__X_X_i_s[ibra * 28 + 3] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 3] );

                    HRR_INT__X_X_h_p[ibra * 63 + 10] = HRR_INT__X_X_i_s[ibra * 28 + 6] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 3] );

                    HRR_INT__X_X_h_p[ibra * 63 + 11] = HRR_INT__X_X_i_s[ibra * 28 + 7] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 3] );

                    HRR_INT__X_X_h_p[ibra * 63 + 12] = HRR_INT__X_X_i_s[ibra * 28 + 4] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 4] );

                    HRR_INT__X_X_h_p[ibra * 63 + 13] = HRR_INT__X_X_i_s[ibra * 28 + 7] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 4] );

                    HRR_INT__X_X_h_p[ibra * 63 + 14] = HRR_INT__X_X_i_s[ibra * 28 + 8] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 4] );

                    HRR_INT__X_X_h_p[ibra * 63 + 15] = HRR_INT__X_X_i_s[ibra * 28 + 5] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 5] );

                    HRR_INT__X_X_h_p[ibra * 63 + 16] = HRR_INT__X_X_i_s[ibra * 28 + 8] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 5] );

                    HRR_INT__X_X_h_p[ibra * 63 + 17] = HRR_INT__X_X_i_s[ibra * 28 + 9] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 5] );

                    HRR_INT__X_X_h_p[ibra * 63 + 18] = HRR_INT__X_X_i_s[ibra * 28 + 6] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 6] );

                    HRR_INT__X_X_h_p[ibra * 63 + 19] = HRR_INT__X_X_i_s[ibra * 28 + 10] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 6] );

                    HRR_INT__X_X_h_p[ibra * 63 + 20] = HRR_INT__X_X_i_s[ibra * 28 + 11] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 6] );

                    HRR_INT__X_X_h_p[ibra * 63 + 21] = HRR_INT__X_X_i_s[ibra * 28 + 7] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 7] );

                    HRR_INT__X_X_h_p[ibra * 63 + 22] = HRR_INT__X_X_i_s[ibra * 28 + 11] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 7] );

                    HRR_INT__X_X_h_p[ibra * 63 + 23] = HRR_INT__X_X_i_s[ibra * 28 + 12] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 7] );

                    HRR_INT__X_X_h_p[ibra * 63 + 24] = HRR_INT__X_X_i_s[ibra * 28 + 8] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 8] );

                    HRR_INT__X_X_h_p[ibra * 63 + 25] = HRR_INT__X_X_i_s[ibra * 28 + 12] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 8] );

                    HRR_INT__X_X_h_p[ibra * 63 + 26] = HRR_INT__X_X_i_s[ibra * 28 + 13] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 8] );

                    HRR_INT__X_X_h_p[ibra * 63 + 27] = HRR_INT__X_X_i_s[ibra * 28 + 9] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 9] );

                    HRR_INT__X_X_h_p[ibra * 63 + 28] = HRR_INT__X_X_i_s[ibra * 28 + 13] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 9] );

                    HRR_INT__X_X_h_p[ibra * 63 + 29] = HRR_INT__X_X_i_s[ibra * 28 + 14] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 9] );

                    HRR_INT__X_X_h_p[ibra * 63 + 30] = HRR_INT__X_X_i_s[ibra * 28 + 10] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 10] );

                    HRR_INT__X_X_h_p[ibra * 63 + 31] = HRR_INT__X_X_i_s[ibra * 28 + 15] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 10] );

                    HRR_INT__X_X_h_p[ibra * 63 + 32] = HRR_INT__X_X_i_s[ibra * 28 + 16] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 10] );

                    HRR_INT__X_X_h_p[ibra * 63 + 33] = HRR_INT__X_X_i_s[ibra * 28 + 11] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 11] );

                    HRR_INT__X_X_h_p[ibra * 63 + 34] = HRR_INT__X_X_i_s[ibra * 28 + 16] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 11] );

                    HRR_INT__X_X_h_p[ibra * 63 + 35] = HRR_INT__X_X_i_s[ibra * 28 + 17] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 11] );

                    HRR_INT__X_X_h_p[ibra * 63 + 36] = HRR_INT__X_X_i_s[ibra * 28 + 12] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 12] );

                    HRR_INT__X_X_h_p[ibra * 63 + 37] = HRR_INT__X_X_i_s[ibra * 28 + 17] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 12] );

                    HRR_INT__X_X_h_p[ibra * 63 + 38] = HRR_INT__X_X_i_s[ibra * 28 + 18] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 12] );

                    HRR_INT__X_X_h_p[ibra * 63 + 39] = HRR_INT__X_X_i_s[ibra * 28 + 13] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 13] );

                    HRR_INT__X_X_h_p[ibra * 63 + 40] = HRR_INT__X_X_i_s[ibra * 28 + 18] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 13] );

                    HRR_INT__X_X_h_p[ibra * 63 + 41] = HRR_INT__X_X_i_s[ibra * 28 + 19] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 13] );

                    HRR_INT__X_X_h_p[ibra * 63 + 42] = HRR_INT__X_X_i_s[ibra * 28 + 14] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 14] );

                    HRR_INT__X_X_h_p[ibra * 63 + 43] = HRR_INT__X_X_i_s[ibra * 28 + 19] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 14] );

                    HRR_INT__X_X_h_p[ibra * 63 + 44] = HRR_INT__X_X_i_s[ibra * 28 + 20] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 14] );

                    HRR_INT__X_X_h_p[ibra * 63 + 45] = HRR_INT__X_X_i_s[ibra * 28 + 15] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 15] );

                    HRR_INT__X_X_h_p[ibra * 63 + 46] = HRR_INT__X_X_i_s[ibra * 28 + 21] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 15] );

                    HRR_INT__X_X_h_p[ibra * 63 + 47] = HRR_INT__X_X_i_s[ibra * 28 + 22] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 15] );

                    HRR_INT__X_X_h_p[ibra * 63 + 48] = HRR_INT__X_X_i_s[ibra * 28 + 16] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 16] );

                    HRR_INT__X_X_h_p[ibra * 63 + 49] = HRR_INT__X_X_i_s[ibra * 28 + 22] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 16] );

                    HRR_INT__X_X_h_p[ibra * 63 + 50] = HRR_INT__X_X_i_s[ibra * 28 + 23] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 16] );

                    HRR_INT__X_X_h_p[ibra * 63 + 51] = HRR_INT__X_X_i_s[ibra * 28 + 17] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 17] );

                    HRR_INT__X_X_h_p[ibra * 63 + 52] = HRR_INT__X_X_i_s[ibra * 28 + 23] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 17] );

                    HRR_INT__X_X_h_p[ibra * 63 + 53] = HRR_INT__X_X_i_s[ibra * 28 + 24] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 17] );

                    HRR_INT__X_X_h_p[ibra * 63 + 54] = HRR_INT__X_X_i_s[ibra * 28 + 18] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 18] );

                    HRR_INT__X_X_h_p[ibra * 63 + 55] = HRR_INT__X_X_i_s[ibra * 28 + 24] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 18] );

                    HRR_INT__X_X_h_p[ibra * 63 + 56] = HRR_INT__X_X_i_s[ibra * 28 + 25] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 18] );

                    HRR_INT__X_X_h_p[ibra * 63 + 57] = HRR_INT__X_X_i_s[ibra * 28 + 19] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 19] );

                    HRR_INT__X_X_h_p[ibra * 63 + 58] = HRR_INT__X_X_i_s[ibra * 28 + 25] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 19] );

                    HRR_INT__X_X_h_p[ibra * 63 + 59] = HRR_INT__X_X_i_s[ibra * 28 + 26] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 19] );

                    HRR_INT__X_X_h_p[ibra * 63 + 60] = HRR_INT__X_X_i_s[ibra * 28 + 20] + ( hCD[0] * HRR_INT__X_X_h_s[ibra * 21 + 20] );

                    HRR_INT__X_X_h_p[ibra * 63 + 61] = HRR_INT__X_X_i_s[ibra * 28 + 26] + ( hCD[1] * HRR_INT__X_X_h_s[ibra * 21 + 20] );

                    HRR_INT__X_X_h_p[ibra * 63 + 62] = HRR_INT__X_X_i_s[ibra * 28 + 27] + ( hCD[2] * HRR_INT__X_X_h_s[ibra * 21 + 20] );

                }

}


