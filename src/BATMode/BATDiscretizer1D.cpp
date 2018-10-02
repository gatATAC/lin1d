#include "BatModePrj.h"

t_d1d_block bat_d1d_block;

static void CreateBATD1dContext(void)
{
    bat_d1d_block.num_ranges = (uint8_t) (sizeof (bat_mode_values) / sizeof (uint16_t));
    bat_d1d_block.range_values_up = bat_mode_values;
    bat_d1d_block.range_values_down = bat_mode_hyst_values;
    d1d_block = &bat_d1d_block;
}

static void RestoreBATD1dContext(void)
{
    d1d_block = &bat_d1d_block;
}

static void SaveBATD1dContext(void)
{
}

void BATDiscretizer1D_init(void)
{
    CreateBATD1dContext();
    Discretizer1D_init();
    SaveBATD1dContext();    
}

void BATDiscretizer1D(void)
{
        RestoreBATD1dContext();
        Discretizer1D();
        SaveBATD1dContext();
}
