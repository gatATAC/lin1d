#include "S1ModePrj.h"

t_timefilter_block s1_timefilter_block;

static void CreateS1TimefilterContext(void)
{
    s1_timefilter_block.stability_time = T_S1_RANGE_STABILITY_TIME;
    tf_block = &s1_timefilter_block;
}

static void SaveS1TimefilterContext(void)
{
    tf_block->current_state = GetCurrentTimeFilterState();
}

static void RestoreS1TimefilterContext(void)
{
    tf_block = &s1_timefilter_block;
    SetCurrentTimeFilterState(tf_block->current_state);
}

void S1TimeFilterInit(void)
{
    CreateS1TimefilterContext();
    TimeFilterInit();
    SaveS1TimefilterContext();
}

void S1TimeFilter(void)
{
        RestoreS1TimefilterContext();
        TimeFilter();
        SaveS1TimefilterContext();
}

