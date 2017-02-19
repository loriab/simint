
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s f | s d )
//////////////////////////////////////////////
void VRR_L_s_f_s_d(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_p,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_p,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_K_f_s_d_s(
            PRIM_INT__s_f_s_d,
            PRIM_INT__s_f_s_p,
            PRIM_INT__s_f_s_s,
            PRIM_INT__s_d_s_p,
            Q_PB,
            a_over_q,
            aoq_PQ,
            one_over_2pq,
            one_over_2q,
            num_n);
}

