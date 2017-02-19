
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// KET: | f d )
// Steps: 60
//////////////////////////////////////////////

void HRR_L_f_d(double * const restrict HRR_INT__X_X_f_d,
                    double const * const restrict HRR_INT__X_X_f_p,
                    double const * const restrict HRR_INT__X_X_g_p,
                    const double hCD[3], const int ncart_bra)
{
    int ibra;

                for(ibra = 0; ibra < ncart_bra; ++ibra)
                {
                    HRR_INT__X_X_f_d[ibra * 60 + 0] = HRR_INT__X_X_g_p[ibra * 45 + 0] + ( hCD[0] * HRR_INT__X_X_f_p[ibra * 30 + 0] );

                    HRR_INT__X_X_f_d[ibra * 60 + 1] = HRR_INT__X_X_g_p[ibra * 45 + 3] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 0] );

                    HRR_INT__X_X_f_d[ibra * 60 + 2] = HRR_INT__X_X_g_p[ibra * 45 + 6] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 0] );

                    HRR_INT__X_X_f_d[ibra * 60 + 3] = HRR_INT__X_X_g_p[ibra * 45 + 4] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 1] );

                    HRR_INT__X_X_f_d[ibra * 60 + 4] = HRR_INT__X_X_g_p[ibra * 45 + 7] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 1] );

                    HRR_INT__X_X_f_d[ibra * 60 + 5] = HRR_INT__X_X_g_p[ibra * 45 + 8] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 2] );

                    HRR_INT__X_X_f_d[ibra * 60 + 6] = HRR_INT__X_X_g_p[ibra * 45 + 3] + ( hCD[0] * HRR_INT__X_X_f_p[ibra * 30 + 3] );

                    HRR_INT__X_X_f_d[ibra * 60 + 7] = HRR_INT__X_X_g_p[ibra * 45 + 9] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 3] );

                    HRR_INT__X_X_f_d[ibra * 60 + 8] = HRR_INT__X_X_g_p[ibra * 45 + 12] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 3] );

                    HRR_INT__X_X_f_d[ibra * 60 + 9] = HRR_INT__X_X_g_p[ibra * 45 + 10] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 4] );

                    HRR_INT__X_X_f_d[ibra * 60 + 10] = HRR_INT__X_X_g_p[ibra * 45 + 13] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 4] );

                    HRR_INT__X_X_f_d[ibra * 60 + 11] = HRR_INT__X_X_g_p[ibra * 45 + 14] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 5] );

                    HRR_INT__X_X_f_d[ibra * 60 + 12] = HRR_INT__X_X_g_p[ibra * 45 + 6] + ( hCD[0] * HRR_INT__X_X_f_p[ibra * 30 + 6] );

                    HRR_INT__X_X_f_d[ibra * 60 + 13] = HRR_INT__X_X_g_p[ibra * 45 + 12] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 6] );

                    HRR_INT__X_X_f_d[ibra * 60 + 14] = HRR_INT__X_X_g_p[ibra * 45 + 15] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 6] );

                    HRR_INT__X_X_f_d[ibra * 60 + 15] = HRR_INT__X_X_g_p[ibra * 45 + 13] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 7] );

                    HRR_INT__X_X_f_d[ibra * 60 + 16] = HRR_INT__X_X_g_p[ibra * 45 + 16] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 7] );

                    HRR_INT__X_X_f_d[ibra * 60 + 17] = HRR_INT__X_X_g_p[ibra * 45 + 17] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 8] );

                    HRR_INT__X_X_f_d[ibra * 60 + 18] = HRR_INT__X_X_g_p[ibra * 45 + 9] + ( hCD[0] * HRR_INT__X_X_f_p[ibra * 30 + 9] );

                    HRR_INT__X_X_f_d[ibra * 60 + 19] = HRR_INT__X_X_g_p[ibra * 45 + 18] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 9] );

                    HRR_INT__X_X_f_d[ibra * 60 + 20] = HRR_INT__X_X_g_p[ibra * 45 + 21] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 9] );

                    HRR_INT__X_X_f_d[ibra * 60 + 21] = HRR_INT__X_X_g_p[ibra * 45 + 19] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 10] );

                    HRR_INT__X_X_f_d[ibra * 60 + 22] = HRR_INT__X_X_g_p[ibra * 45 + 22] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 10] );

                    HRR_INT__X_X_f_d[ibra * 60 + 23] = HRR_INT__X_X_g_p[ibra * 45 + 23] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 11] );

                    HRR_INT__X_X_f_d[ibra * 60 + 24] = HRR_INT__X_X_g_p[ibra * 45 + 12] + ( hCD[0] * HRR_INT__X_X_f_p[ibra * 30 + 12] );

                    HRR_INT__X_X_f_d[ibra * 60 + 25] = HRR_INT__X_X_g_p[ibra * 45 + 21] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 12] );

                    HRR_INT__X_X_f_d[ibra * 60 + 26] = HRR_INT__X_X_g_p[ibra * 45 + 24] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 12] );

                    HRR_INT__X_X_f_d[ibra * 60 + 27] = HRR_INT__X_X_g_p[ibra * 45 + 22] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 13] );

                    HRR_INT__X_X_f_d[ibra * 60 + 28] = HRR_INT__X_X_g_p[ibra * 45 + 25] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 13] );

                    HRR_INT__X_X_f_d[ibra * 60 + 29] = HRR_INT__X_X_g_p[ibra * 45 + 26] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 14] );

                    HRR_INT__X_X_f_d[ibra * 60 + 30] = HRR_INT__X_X_g_p[ibra * 45 + 15] + ( hCD[0] * HRR_INT__X_X_f_p[ibra * 30 + 15] );

                    HRR_INT__X_X_f_d[ibra * 60 + 31] = HRR_INT__X_X_g_p[ibra * 45 + 24] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 15] );

                    HRR_INT__X_X_f_d[ibra * 60 + 32] = HRR_INT__X_X_g_p[ibra * 45 + 27] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 15] );

                    HRR_INT__X_X_f_d[ibra * 60 + 33] = HRR_INT__X_X_g_p[ibra * 45 + 25] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 16] );

                    HRR_INT__X_X_f_d[ibra * 60 + 34] = HRR_INT__X_X_g_p[ibra * 45 + 28] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 16] );

                    HRR_INT__X_X_f_d[ibra * 60 + 35] = HRR_INT__X_X_g_p[ibra * 45 + 29] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 17] );

                    HRR_INT__X_X_f_d[ibra * 60 + 36] = HRR_INT__X_X_g_p[ibra * 45 + 18] + ( hCD[0] * HRR_INT__X_X_f_p[ibra * 30 + 18] );

                    HRR_INT__X_X_f_d[ibra * 60 + 37] = HRR_INT__X_X_g_p[ibra * 45 + 30] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 18] );

                    HRR_INT__X_X_f_d[ibra * 60 + 38] = HRR_INT__X_X_g_p[ibra * 45 + 33] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 18] );

                    HRR_INT__X_X_f_d[ibra * 60 + 39] = HRR_INT__X_X_g_p[ibra * 45 + 31] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 19] );

                    HRR_INT__X_X_f_d[ibra * 60 + 40] = HRR_INT__X_X_g_p[ibra * 45 + 34] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 19] );

                    HRR_INT__X_X_f_d[ibra * 60 + 41] = HRR_INT__X_X_g_p[ibra * 45 + 35] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 20] );

                    HRR_INT__X_X_f_d[ibra * 60 + 42] = HRR_INT__X_X_g_p[ibra * 45 + 21] + ( hCD[0] * HRR_INT__X_X_f_p[ibra * 30 + 21] );

                    HRR_INT__X_X_f_d[ibra * 60 + 43] = HRR_INT__X_X_g_p[ibra * 45 + 33] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 21] );

                    HRR_INT__X_X_f_d[ibra * 60 + 44] = HRR_INT__X_X_g_p[ibra * 45 + 36] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 21] );

                    HRR_INT__X_X_f_d[ibra * 60 + 45] = HRR_INT__X_X_g_p[ibra * 45 + 34] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 22] );

                    HRR_INT__X_X_f_d[ibra * 60 + 46] = HRR_INT__X_X_g_p[ibra * 45 + 37] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 22] );

                    HRR_INT__X_X_f_d[ibra * 60 + 47] = HRR_INT__X_X_g_p[ibra * 45 + 38] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 23] );

                    HRR_INT__X_X_f_d[ibra * 60 + 48] = HRR_INT__X_X_g_p[ibra * 45 + 24] + ( hCD[0] * HRR_INT__X_X_f_p[ibra * 30 + 24] );

                    HRR_INT__X_X_f_d[ibra * 60 + 49] = HRR_INT__X_X_g_p[ibra * 45 + 36] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 24] );

                    HRR_INT__X_X_f_d[ibra * 60 + 50] = HRR_INT__X_X_g_p[ibra * 45 + 39] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 24] );

                    HRR_INT__X_X_f_d[ibra * 60 + 51] = HRR_INT__X_X_g_p[ibra * 45 + 37] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 25] );

                    HRR_INT__X_X_f_d[ibra * 60 + 52] = HRR_INT__X_X_g_p[ibra * 45 + 40] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 25] );

                    HRR_INT__X_X_f_d[ibra * 60 + 53] = HRR_INT__X_X_g_p[ibra * 45 + 41] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 26] );

                    HRR_INT__X_X_f_d[ibra * 60 + 54] = HRR_INT__X_X_g_p[ibra * 45 + 27] + ( hCD[0] * HRR_INT__X_X_f_p[ibra * 30 + 27] );

                    HRR_INT__X_X_f_d[ibra * 60 + 55] = HRR_INT__X_X_g_p[ibra * 45 + 39] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 27] );

                    HRR_INT__X_X_f_d[ibra * 60 + 56] = HRR_INT__X_X_g_p[ibra * 45 + 42] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 27] );

                    HRR_INT__X_X_f_d[ibra * 60 + 57] = HRR_INT__X_X_g_p[ibra * 45 + 40] + ( hCD[1] * HRR_INT__X_X_f_p[ibra * 30 + 28] );

                    HRR_INT__X_X_f_d[ibra * 60 + 58] = HRR_INT__X_X_g_p[ibra * 45 + 43] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 28] );

                    HRR_INT__X_X_f_d[ibra * 60 + 59] = HRR_INT__X_X_g_p[ibra * 45 + 44] + ( hCD[2] * HRR_INT__X_X_f_p[ibra * 30 + 29] );

                }

}


