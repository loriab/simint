
#include "simint/ostei/gen/ostei_generated.h"
//////////////////////////////////////////////
// VRR: ( s s | s h )
//////////////////////////////////////////////
void VRR_L_s_s_s_h(
            SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_h,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_g,
            const SIMINT_DBLTYPE * const restrict PRIM_INT__s_s_s_f,
            const SIMINT_DBLTYPE * Q_PB,
            const SIMINT_DBLTYPE a_over_q,
            const SIMINT_DBLTYPE * aoq_PQ,
            const SIMINT_DBLTYPE one_over_2q,
            const int num_n)
{
    // Routines are identical except for swapping of
    // PA with PB and QC with QD

    VRR_K_s_s_h_s(
            PRIM_INT__s_s_s_h,
            PRIM_INT__s_s_s_g,
            PRIM_INT__s_s_s_f,
            Q_PB,
            a_over_q,
            aoq_PQ,
            one_over_2q,
            num_n);
}


