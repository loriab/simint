
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s g | s p )
//////////////////////////////////////////////
void VRR_L_s_g_s_p(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_s,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_K_g_s_p_s(
            PRIM_INT__s_g_s_p,
            PRIM_INT__s_g_s_s,
            PRIM_INT__s_f_s_s,
            Q_PB,
            aoq_PQ,
            one_over_2pq,
            num_n);
}


