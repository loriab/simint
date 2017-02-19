
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( p s | s g )
//////////////////////////////////////////////
void VRR_I_p_s_s_g(
            SIMINT_DBLTYPE * const restrict PRIM_INT__p_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_f,
            const SIMINT_DBLTYPE * P_PA,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_I_p_s_g_s(
            PRIM_INT__p_s_s_g,
            PRIM_INT__s_s_s_g,
            PRIM_INT__s_s_s_f,
            P_PA,
            aop_PQ,
            one_over_2pq,
            num_n);
}


