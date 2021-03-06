
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s d | f s )
//////////////////////////////////////////////
void VRR_K_s_d_f_s(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_f_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_d_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_p_s,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_p_d_s,
            const SIMINT_DBLTYPE * Q_PA,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_K_d_s_f_s(
            PRIM_INT__s_d_f_s,
            PRIM_INT__s_d_d_s,
            PRIM_INT__s_d_p_s,
            PRIM_INT__s_p_d_s,
            Q_PA,
            a_over_q,
            aoq_PQ,
            one_over_2pq,
            one_over_2q,
            num_n);
}


