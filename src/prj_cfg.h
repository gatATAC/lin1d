#ifndef _PRJ_CFG_H
#define _PRJ_CFG_H


/////// Platform configuration /////////
#define CYCLE_TIME_IN_MICROS 4000L
#define CYCLE_SECURITY_TIME_MICROS 100L
#define CFG_MAX_TIMER 20000000L

//////// Peripherals ///////////

//// Status LED
#define CFG_LED_STATUS 13

//// DC MOTOR CONTROL
//#define CFG_USE_MOTORCTRL 1

//// STEPPING MOTOR USING ACCELSTEPPER LIBRARY (NOT BLOCKING)
//#define CFG_USE_ACCELSTEPPER

/////// Diagnostics ////////////
#define _DIAG_ACTIVE 1

#endif /* _PRJ_CFG_H */






