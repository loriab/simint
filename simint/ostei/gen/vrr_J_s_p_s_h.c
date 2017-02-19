
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s p | s h )
//////////////////////////////////////////////
void VRR_J_s_p_s_h(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_g,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_I_p_s_h_s(
            PRIM_INT__s_p_s_h,
            PRIM_INT__s_s_s_h,
            PRIM_INT__s_s_s_g,
            P_PB,
            aop_PQ,
            one_over_2pq,
            num_n);
}


