
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s p | i s )
//////////////////////////////////////////////
void VRR_J_s_p_i_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_i_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_i_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_h_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_I_p_s_i_s(
            PRIM_INT__s_p_i_s,
            PRIM_INT__s_s_i_s,
            PRIM_INT__s_s_h_s,
            P_PB,
            aop_PQ,
            one_over_2pq,
            num_n);
}


