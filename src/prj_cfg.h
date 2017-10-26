#ifndef _PRJ_CFG_H
#define _PRJ_CFG_H

#include "ProjectVariants.h"

/////// Platform configuration /////////
#define CYCLE_TIME_IN_MICROS 4000L
#define CYCLE_SECURITY_TIME_MICROS 100L
#define CFG_MAX_TIMER 20000000L

//////// Peripherals ///////////

//// Status LED
#define CFG_LED_STATUS 13

//#define CFG_SWITCHES_EMULATED_BY_HMI

#endif /* _PRJ_CFG_H */
