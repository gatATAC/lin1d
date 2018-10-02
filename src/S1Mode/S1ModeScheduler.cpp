#include "S1ModePrj.h"
#include "../FM1DRE.h"

extern t_dreFM1 dreFM1;

void S1ModeSchedulerInit(void)
{
    dreFM1.s1_mode = S1_NORMAL_IDX;
    s1_d1d_block.input = dreFM1.s1_sense;
    S1Discretizer1DInit();
    s1_timefilter_block.input = s1_d1d_block.range_idx;
    S1TimeFilterInit();
    dreFM1.s1_mode = (t_enum_s1_mode) s1_timefilter_block.output;
}

void S1ModeScheduler(void)
{
        s1_d1d_block.input = dreFM1.s1_sense;
        S1Discretizer1D();
        s1_timefilter_block.input = s1_d1d_block.range_idx;
        S1TimeFilter();
        dreFM1.s1_mode = (t_enum_s1_mode) s1_timefilter_block.output;
}

