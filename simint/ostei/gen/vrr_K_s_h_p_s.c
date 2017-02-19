
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s h | p s )
//////////////////////////////////////////////
void VRR_K_s_h_p_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_K_h_s_p_s(
            PRIM_INT__s_h_p_s,
            PRIM_INT__s_h_s_s,
            PRIM_INT__s_g_s_s,
            Q_PA,
            aoq_PQ,
            one_over_2pq,
            num_n);
}


