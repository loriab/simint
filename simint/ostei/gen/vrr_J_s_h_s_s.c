
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s h | s s )
//////////////////////////////////////////////
void VRR_J_s_h_s_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_h_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_g_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_s,
            const SIMINT_DBLTYPE * P_PB,
            const SIMINT_DBLTYPE a_over_p,
            const SIMINT_DBLTYPE * aop_PQ,
            const SIMINT_DBLTYPE one_over_2p,
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_I_h_s_s_s(
            PRIM_INT__s_h_s_s,
            PRIM_INT__s_g_s_s,
            PRIM_INT__s_f_s_s,
            P_PB,
            a_over_p,
            aop_PQ,
            one_over_2p,
            num_n);
}


