
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( d s | s h )
//////////////////////////////////////////////
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
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_I_d_s_h_s(
            PRIM_INT__d_s_s_h,
            PRIM_INT__p_s_s_h,
            PRIM_INT__s_s_s_h,
            PRIM_INT__p_s_s_g,
            P_PA,
            a_over_p,
            aop_PQ,
            one_over_2p,
            one_over_2pq,
            num_n);
}


