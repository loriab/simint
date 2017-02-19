#pragma once

#ifdef __cplusplus
extern "C" {
#endif


#include "simint/vectorization/vectorization.h"

void HRR_J_h_d(double * const restrict HRR_INT__h_d_X_X,
                    double const * const restrict HRR_INT__h_p_X_X,
                    double const * const restrict HRR_INT__i_p_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_J_h_f(double * const restrict HRR_INT__h_f_X_X,
                    double const * const restrict HRR_INT__h_d_X_X,
                    double const * const restrict HRR_INT__i_d_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_L_h_f(double * const restrict HRR_INT__X_X_h_f,
                    double const * const restrict HRR_INT__X_X_h_d,
                    double const * const restrict HRR_INT__X_X_i_d,
                    const double hCD[3], const int ncart_bra);

void HRR_J_k_p(double * const restrict HRR_INT__k_p_X_X,
                    double const * const restrict HRR_INT__k_s_X_X,
                    double const * const restrict HRR_INT__l_s_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_L_g_p(double * const restrict HRR_INT__X_X_g_p,
                    double const * const restrict HRR_INT__X_X_g_s,
                    double const * const restrict HRR_INT__X_X_h_s,
                    const double hCD[3], const int ncart_bra);

void HRR_L_f_f(double * const restrict HRR_INT__X_X_f_f,
                    double const * const restrict HRR_INT__X_X_f_d,
                    double const * const restrict HRR_INT__X_X_g_d,
                    const double hCD[3], const int ncart_bra);

void HRR_L_g_f(double * const restrict HRR_INT__X_X_g_f,
                    double const * const restrict HRR_INT__X_X_g_d,
                    double const * const restrict HRR_INT__X_X_h_d,
                    const double hCD[3], const int ncart_bra);

void HRR_J_f_f(double * const restrict HRR_INT__f_f_X_X,
                    double const * const restrict HRR_INT__f_d_X_X,
                    double const * const restrict HRR_INT__g_d_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_J_i_p(double * const restrict HRR_INT__i_p_X_X,
                    double const * const restrict HRR_INT__i_s_X_X,
                    double const * const restrict HRR_INT__k_s_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_L_f_d(double * const restrict HRR_INT__X_X_f_d,
                    double const * const restrict HRR_INT__X_X_f_p,
                    double const * const restrict HRR_INT__X_X_g_p,
                    const double hCD[3], const int ncart_bra);

void HRR_J_f_d(double * const restrict HRR_INT__f_d_X_X,
                    double const * const restrict HRR_INT__f_p_X_X,
                    double const * const restrict HRR_INT__g_p_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_J_i_d(double * const restrict HRR_INT__i_d_X_X,
                    double const * const restrict HRR_INT__i_p_X_X,
                    double const * const restrict HRR_INT__k_p_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_L_g_d(double * const restrict HRR_INT__X_X_g_d,
                    double const * const restrict HRR_INT__X_X_g_p,
                    double const * const restrict HRR_INT__X_X_h_p,
                    const double hCD[3], const int ncart_bra);

void HRR_K_p_g(double * const restrict HRR_INT__X_X_p_g,
                    double const * const restrict HRR_INT__X_X_s_g,
                    double const * const restrict HRR_INT__X_X_s_h,
                    const double hCD[3], const int ncart_bra);

void HRR_I_p_g(double * const restrict HRR_INT__p_g_X_X,
                    double const * const restrict HRR_INT__s_g_X_X,
                    double const * const restrict HRR_INT__s_h_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_L_g_g(double * const restrict HRR_INT__X_X_g_g,
                    double const * const restrict HRR_INT__X_X_g_f,
                    double const * const restrict HRR_INT__X_X_h_f,
                    const double hCD[3], const int ncart_bra);

void HRR_I_d_f(double * const restrict HRR_INT__d_f_X_X,
                    double const * const restrict HRR_INT__p_f_X_X,
                    double const * const restrict HRR_INT__p_g_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_J_g_g(double * const restrict HRR_INT__g_g_X_X,
                    double const * const restrict HRR_INT__g_f_X_X,
                    double const * const restrict HRR_INT__h_f_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_L_k_p(double * const restrict HRR_INT__X_X_k_p,
                    double const * const restrict HRR_INT__X_X_k_s,
                    double const * const restrict HRR_INT__X_X_l_s,
                    const double hCD[3], const int ncart_bra);

void HRR_J_g_p(double * const restrict HRR_INT__g_p_X_X,
                    double const * const restrict HRR_INT__g_s_X_X,
                    double const * const restrict HRR_INT__h_s_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_J_g_f(double * const restrict HRR_INT__g_f_X_X,
                    double const * const restrict HRR_INT__g_d_X_X,
                    double const * const restrict HRR_INT__h_d_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_K_d_f(double * const restrict HRR_INT__X_X_d_f,
                    double const * const restrict HRR_INT__X_X_p_f,
                    double const * const restrict HRR_INT__X_X_p_g,
                    const double hCD[3], const int ncart_bra);

void HRR_L_i_p(double * const restrict HRR_INT__X_X_i_p,
                    double const * const restrict HRR_INT__X_X_i_s,
                    double const * const restrict HRR_INT__X_X_k_s,
                    const double hCD[3], const int ncart_bra);

void HRR_J_h_p(double * const restrict HRR_INT__h_p_X_X,
                    double const * const restrict HRR_INT__h_s_X_X,
                    double const * const restrict HRR_INT__i_s_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_L_h_p(double * const restrict HRR_INT__X_X_h_p,
                    double const * const restrict HRR_INT__X_X_h_s,
                    double const * const restrict HRR_INT__X_X_i_s,
                    const double hCD[3], const int ncart_bra);

void HRR_L_i_d(double * const restrict HRR_INT__X_X_i_d,
                    double const * const restrict HRR_INT__X_X_i_p,
                    double const * const restrict HRR_INT__X_X_k_p,
                    const double hCD[3], const int ncart_bra);

void HRR_J_g_d(double * const restrict HRR_INT__g_d_X_X,
                    double const * const restrict HRR_INT__g_p_X_X,
                    double const * const restrict HRR_INT__h_p_X_X,
                    const double hAB[3], const int ncart_ket);

void HRR_L_h_d(double * const restrict HRR_INT__X_X_h_d,
                    double const * const restrict HRR_INT__X_X_h_p,
                    double const * const restrict HRR_INT__X_X_i_p,
                    const double hCD[3], const int ncart_bra);


#ifdef __cplusplus
}
#endif

