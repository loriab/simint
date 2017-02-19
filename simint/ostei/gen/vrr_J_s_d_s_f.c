
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s d | s f )
//////////////////////////////////////////////
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
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_I_d_s_f_s(
            PRIM_INT__s_d_s_f,
            PRIM_INT__s_p_s_f,
            PRIM_INT__s_s_s_f,
            PRIM_INT__s_p_s_d,
            P_PB,
            a_over_p,
            aop_PQ,
            one_over_2p,
            one_over_2pq,
            num_n);
}


