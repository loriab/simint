
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s f | s g )
//////////////////////////////////////////////
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
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_I_f_s_g_s(
            PRIM_INT__s_f_s_g,
            PRIM_INT__s_d_s_g,
            PRIM_INT__s_p_s_g,
            PRIM_INT__s_d_s_f,
            P_PB,
            a_over_p,
            aop_PQ,
            one_over_2p,
            one_over_2pq,
            num_n);
}


