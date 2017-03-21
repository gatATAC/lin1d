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
// #define CFG_FM1_USE_ACCELSTEPPER
#define CFG_POL_USE_ACCELSTEPPER

#define CFG_FM1_USE_SERVO
#define CFG_POL_USE_SERVO

//#define CFG_FM1_USE_SLIDER
#define CFG_POL_USE_SLIDER

/////// Diagnostics ////////////
#define _DIAG_ACTIVE 1

#define CTE_DEBUG_STEP_SPEED
#ifdef CTE_DEBUG_STEP_SPEED
#define CFG_DEBUG_STEP_SPEED_FACTOR (0.9)
#define CFG_DEBUG_STEP_SPEED_OFFSET (100.0)

#endif

//#define CFG_POL_USE_SLIDER

#endif /* _PRJ_CFG_H */

















