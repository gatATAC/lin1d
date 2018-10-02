#include "CommonLibrary.h"

void Discretizer1DUpRange_init(void) {

}

void Discretizer1DUpRange(void) {
    uint8_t idx;
    BOOL found = FALSE;
    for (idx = 1; (found == FALSE) && (idx < (d1d_block->num_ranges)); idx++) {
        if (d1d_block->input < d1d_block->range_values_up[idx]) {
            found = TRUE;
            d1d_block->range_up_idx = idx - 1;
        }
    }
    /* PLEASE NOTE THAT SUCCESS MUST BE GUARANTEED BY DESIGN!!! */ 
    if (found != TRUE) {
        d1d_block->range_up_idx = (d1d_block->num_ranges) - 1;
    }

}


