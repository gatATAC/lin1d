#include "BATModePrj.h"
#include "../FM1DRE.h"

extern t_dreFM1 dreFM1;

void BATModeSchedulerInit(void)
{
    dreFM1.bat_mode = BAT_NORMAL_IDX;
    bat_d1d_block.input = dreFM1.bat_sense;
    BATDiscretizer1DInit();
    bat_timefilter_block.input = bat_d1d_block.range_idx;
    BATTimeFilterInit();
    dreFM1.bat_mode = (t_enum_bat_mode) bat_timefilter_block.output;
}

void BATModeScheduler(void)
{
        bat_d1d_block.input = dreFM1.bat_sense;
        BATDiscretizer1D();
        bat_timefilter_block.input = bat_d1d_block.range_idx;
        BATTimeFilter();
        dreFM1.bat_mode = (t_enum_bat_mode) bat_timefilter_block.output;
}

