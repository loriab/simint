
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s f | s g )
//////////////////////////////////////////////
void VRR_L_s_f_s_g(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_f,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_f_s_d,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_d_s_f,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2pq,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_K_f_s_g_s(
            PRIM_INT__s_f_s_g,
            PRIM_INT__s_f_s_f,
            PRIM_INT__s_f_s_d,
            PRIM_INT__s_d_s_f,
            Q_PB,
            a_over_q,
            aoq_PQ,
            one_over_2pq,
            one_over_2q,
            num_n);
}


