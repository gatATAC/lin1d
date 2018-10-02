#include "BATModePrj.h"

t_timefilter_block bat_timefilter_block;

static void CreateBATTimefilterContext(void)
{
    bat_timefilter_block.stability_time = T_BAT_RANGE_STABILITY_TIME;
    tf_block = &bat_timefilter_block;
}

static void SaveBATTimefilterContext(void)
{
    tf_block->current_state = GetCurrentTimeFilterState();
}

static void RestoreBATTimefilterContext(void)
{
    tf_block = &bat_timefilter_block;
    SetCurrentTimeFilterState(tf_block->current_state);
}

void BATTimeFilter_init(void)
{
    CreateBATTimefilterContext();
    TimeFilter_init();
    SaveBATTimefilterContext();
}

void BATTimeFilter(void)
{
        RestoreBATTimefilterContext();
        TimeFilter();
        SaveBATTimefilterContext();
}

