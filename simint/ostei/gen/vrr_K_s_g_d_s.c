
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s g | d s )
//////////////////////////////////////////////
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
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_K_g_s_d_s(
            PRIM_INT__s_g_d_s,
            PRIM_INT__s_g_p_s,
            PRIM_INT__s_g_s_s,
            PRIM_INT__s_f_p_s,
            Q_PA,
            a_over_q,
            aoq_PQ,
            one_over_2pq,
            one_over_2q,
            num_n);
}


