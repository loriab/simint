#pragma once

#ifdef __cplusplus
extern "C" {
#endif


#include "simint/vectorization/vectorization.h"

void VRR_J_s_f_g_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_f_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_J_s_f_s_g(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_f,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_L_f_s_s_g(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_f,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_K_g_s_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_p_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_J_s_p_s_h(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_g,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_L_s_d_s_g(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_f,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_J_s_h_s_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const int num_n);

void VRR_L_s_d_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_d,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_L_h_s_s_p(
            SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_s,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_J_s_g_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_d,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_f_s_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_d_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_J_s_d_g_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_f_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_s_f_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_d_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_K_d_s_g_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_f_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_I_d_s_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_d_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_J_s_d_s_h(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_g,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_I_p_s_s_h(
            SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_g,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_L_f_s_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_d,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_K_s_g_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_p_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_L_d_s_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_d,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_L_s_h_s_p(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_p_s_g_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_f_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_L_s_f_s_g(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_f,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_I_h_s_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_p_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_s_g_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_d_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_L_g_s_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_d,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_I_p_s_g_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_f_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_I_d_s_g_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_f_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_I_d_s_h_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_g_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_L_s_g_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_d,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_L_s_g_s_p(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_s,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_J_s_p_h_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_L_s_g_s_d(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_p,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_I_g_s_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_I_f_s_g_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_f_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_s_h_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_p_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_L_s_s_s_h(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_f,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_J_s_p_i_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_i_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_i_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_J_s_f_s_d(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_p,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_L_f_s_s_d(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_p,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_I_g_s_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_p_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_J_s_f_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_d,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_I_f_s_s_d(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_p,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_J_s_g_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_d_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_s_s_i_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_i_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_I_g_s_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_d,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_L_s_f_s_d(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_p,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_K_s_s_k_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_k_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_i_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_J_s_f_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_d_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_I_i_s_s_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const int num_n);

void VRR_I_p_s_s_g(
            SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_f,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_I_f_s_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_d_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_I_p_s_i_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_i_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_i_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_J_s_g_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_p_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_h_s_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_p_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_I_h_s_s_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const int num_n);

void VRR_K_s_d_g_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_f_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_K_p_s_h_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_I_g_s_p_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_s_s_h_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_f_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_K_s_f_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_p_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_K_s_d_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_d_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_J_s_d_s_g(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_f,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_f_s_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_p_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_I_d_s_s_g(
            SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_f,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_d_s_h_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_g_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_K_s_f_g_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_f_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_I_f_s_s_g(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_f,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_J_s_p_g_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_f_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_I_f_s_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_d,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_f_s_g_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_g_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_f_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_L_i_s_s_p(
            SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_L_s_f_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_d,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_L_h_s_s_d(
            SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_p,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_K_g_s_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_K_s_h_p_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_J_s_p_s_g(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_f,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_J_s_d_h_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_g_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_L_g_s_s_d(
            SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_p,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_J_s_d_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_d,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_L_d_s_s_g(
            SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_f,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_K_s_g_p_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_L_g_s_s_p(
            SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_s,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_g_s_p_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_s_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_i_s_p_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_I_d_s_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_d,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_L_s_h_s_d(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_p,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_I_p_s_h_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_g_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_I_k_s_s_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__k_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__i_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const int num_n);

void VRR_J_s_d_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_d_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_J_s_f_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_p_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_I_d_s_s_h(
            SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_g,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_h_s_p_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__h_s_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__g_s_s_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);

void VRR_K_d_s_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_d_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n);

void VRR_I_f_s_d_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__f_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__d_s_p_s,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n);


#ifdef __cplusplus
}
#endif

