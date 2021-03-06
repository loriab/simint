
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s d | s f )
//////////////////////////////////////////////
void VRR_L_s_d_s_f(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_s_d,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_K_d_s_f_s(
            PRIM_INT__s_d_s_f,
            PRIM_INT__s_d_s_d,
            PRIM_INT__s_d_s_p,
            PRIM_INT__s_p_s_d,
            Q_PB,
            a_over_q,
            aoq_PQ,
            one_over_2pq,
            one_over_2q,
            num_n);
}


