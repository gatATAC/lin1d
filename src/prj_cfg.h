#ifndef _PRJ_CFG_H
#define _PRJ_CFG_H


/////// Platform configuration /////////
#define CYCLE_TIME_IN_MICROS 4000L
#define CYCLE_SECURITY_TIME_MICROS 100L
#define CFG_MAX_TIMER 20000000L

//////// Peripherals ///////////

//// Status LED
#define CFG_LED_STATUS 13

//// End of career switches
#define CFG_ENDSWITCH_1_PIN 20
#define CFG_ENDSWITCH_2_PIN 21


//// Doubled input potentiometer slider
#define CFG_SLIDER_DTA_PIN 22 // Pin DIO 20
#define CFG_SLIDER_DTB_PIN 9 // Pin DIO 23

#define CFG_TM1638_DATA_PIN 8
#define CFG_TM1638_CLOCK_PIN 9
#define CFG_TM1638_STROBE_PIN 10
#define PORT_hmidata CFG_TM1638_DATA_PIN
#define PORT_hmistrobe CFG_TM1638_STROBE_PIN

//// DC MOTOR CONTROL
//#define CFG_USE_MOTORCTRL 1
#ifdef CFG_USE_MOTORCTRL

#define CFG_MOTORCTRL_DIR_QUIET 0
#define CFG_MOTORCTRL_DIR_FW 1
#define CFG_MOTORCTRL_DIR_BW 2

#define CFG_MOTORCTRL_IN3_PIN 19
#define CFG_MOTORCTRL_IN4_PIN 18
#define CFG_MOTORCTRL_PWM_PIN 17
//#define CFG_MOTORCTRL_DEBUGPWM_PIN 5

#define CFG_MOTORCTRL_WAIT_TIME_BEFORE 1000000L
#define CFG_MOTORCTRL_WAIT_TIME_AFTER 1000000L
#define CFG_MOTORCTRL_PWM_INCR_TIME 20000L
#define CFG_MOTORCTRL_PWM_DUTY_STOP 0
#define CFG_MOTORCTRL_PWM_DUTY_MIN 30
#define CFG_MOTORCTRL_PWM_DUTY_MAX 245
#define CFG_MOTORCTRL_PWM_DUTY_HALF 128
#define CFG_MOTORCTRL_PWM_DUTY_DELTA (-1)

// Specific Teensy configuration for motor control
#define CFG_MOTORCTRL_FREQUENCY 100

#endif

//// STEPPING MOTOR USING ACCELSTEPPER LIBRARY (NOT BLOCKING)
//#define CFG_USE_ACCELSTEPPER
#ifdef CFG_USE_ACCELSTEPPER
#define CFG_ACCELSTEPPER_IN1_PIN 16
#define CFG_ACCELSTEPPER_IN2_PIN 15
#define CFG_ACCELSTEPPER_IN3_PIN 19
#define CFG_ACCELSTEPPER_IN4_PIN 18
#define CFG_ACCELSTEPPER_STATUS_QUIET 0
#define CFG_ACCELSTEPPER_STATUS_MOVING 1
#define CFG_ACCELSTEPPER_POS 2000                     // 2000 para zapp (arbitrario)
#define CFG_ACCELSTEPPER_ACCEL 3000.0  // 1000 para zapp  // 2000 a 4000 para sanyo denki// 3000 para nanotec  // 5000 para minebea
#define CFG_ACCELSTEPPER_SPEED_SLIDERA_FACTOR (0.438)  // 0.3 para zapp  // 0.6 - 2 para Sanyo Denki La fuente a 5V 2.4A  // 2 para nanotec (grande) // 2 para minebea
#define CFG_ACCELSTEPPER_SPEED_SLIDERA_OFFSET (50.0)  // 550.0 para zapp // 860 para Sanyo Denki  // 400 para nanotec (grande) // 900 para minebea // 550.0 para zapp nema 17
#endif




#endif /* _PRJ_CFG_H */
