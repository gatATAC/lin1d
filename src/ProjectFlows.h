#ifndef _PROJECT_FLOWS
#define _PROJECT_FLOWS

#include "ProjectTypes.h"
#include "ProjectFunctions.h"
#include "prj_cfg.h"

//// Doubled input potentiometer slider
#define CFG_SLIDER_DTA_PIN 22 // Pin DIO 20
#define CFG_SLIDER_DTB_PIN 9 // Pin DIO 23

#define CFG_FM1_ACT_DRIVER_STAB_TIME_IN_MS (2000)
#define CFG_FM1_ACT_DRIVER_STAB_TIME ((CFG_FM1_ACT_DRIVER_STAB_TIME_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_FM1_ACT_DRIVER_DISSIP_TIME_IN_MS (5000)
#define CFG_FM1_ACT_DRIVER_DISSIP_TIME  ((CFG_FM1_ACT_DRIVER_DISSIP_TIME_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))

#define CFG_FM1_UP_BUT_PRESS_TIMER_IN_MS 80
#define CFG_FM1_UP_BUT_PRESS_TIMER ((CFG_FM1_UP_BUT_PRESS_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_FM1_DWN_BUT_PRESS_TIMER_IN_MS 80
#define CFG_FM1_DWN_BUT_PRESS_TIMER ((CFG_FM1_DWN_BUT_PRESS_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_FM1_UP_BUT_UNPRESS_TIMER_IN_MS 80
#define CFG_FM1_UP_BUT_UNPRESS_TIMER ((CFG_FM1_UP_BUT_UNPRESS_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_FM1_DWN_BUT_UNPRESS_TIMER_IN_MS 80
#define CFG_FM1_DWN_BUT_UNPRESS_TIMER ((CFG_FM1_DWN_BUT_UNPRESS_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))

#define CFG_FM1_UP_SWITCH_DETECT_TIMER_IN_MS 30
#define CFG_FM1_UP_SWITCH_DETECT_TIMER ((CFG_FM1_UP_SWITCH_DETECT_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_FM1_DOWN_SWITCH_DETECT_TIMER_IN_MS 30
#define CFG_FM1_DOWN_SWITCH_DETECT_TIMER ((CFG_FM1_DOWN_SWITCH_DETECT_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_FM1_UP_SWITCH_UNDETECT_TIMER_IN_MS 30
#define CFG_FM1_UP_SWITCH_UNDETECT_TIMER ((CFG_FM1_UP_SWITCH_UNDETECT_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_FM1_DOWN_SWITCH_UNDETECT_TIMER_IN_MS 30
#define CFG_FM1_DOWN_SWITCH_UNDETECT_TIMER ((CFG_FM1_DOWN_SWITCH_UNDETECT_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))


#define CFG_POL_ACT_DRIVER_STAB_TIME_IN_MS (2000)
#define CFG_POL_ACT_DRIVER_STAB_TIME ((CFG_POL_ACT_DRIVER_STAB_TIME_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_POL_ACT_DRIVER_DISSIP_TIME_IN_MS (5000)
#define CFG_POL_ACT_DRIVER_DISSIP_TIME  ((CFG_POL_ACT_DRIVER_DISSIP_TIME_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))

#define CFG_POL_UP_BUT_PRESS_TIMER_IN_MS 80
#define CFG_POL_UP_BUT_PRESS_TIMER ((CFG_POL_UP_BUT_PRESS_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_POL_DWN_BUT_PRESS_TIMER_IN_MS 80
#define CFG_POL_DWN_BUT_PRESS_TIMER ((CFG_POL_DWN_BUT_PRESS_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_POL_UP_BUT_UNPRESS_TIMER_IN_MS 80
#define CFG_POL_UP_BUT_UNPRESS_TIMER ((CFG_POL_UP_BUT_UNPRESS_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_POL_DWN_BUT_UNPRESS_TIMER_IN_MS 80
#define CFG_POL_DWN_BUT_UNPRESS_TIMER ((CFG_POL_DWN_BUT_UNPRESS_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))

#define CFG_POL_UP_SWITCH_DETECT_TIMER_IN_MS 30
#define CFG_POL_UP_SWITCH_DETECT_TIMER ((CFG_POL_UP_SWITCH_DETECT_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_POL_DOWN_SWITCH_DETECT_TIMER_IN_MS 30
#define CFG_POL_DOWN_SWITCH_DETECT_TIMER ((CFG_POL_DOWN_SWITCH_DETECT_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_POL_UP_SWITCH_UNDETECT_TIMER_IN_MS 30
#define CFG_POL_UP_SWITCH_UNDETECT_TIMER ((CFG_POL_UP_SWITCH_UNDETECT_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))
#define CFG_POL_DOWN_SWITCH_UNDETECT_TIMER_IN_MS 30
#define CFG_POL_DOWN_SWITCH_UNDETECT_TIMER ((CFG_POL_DOWN_SWITCH_UNDETECT_TIMER_IN_MS*1000L)/(CYCLE_TIME_IN_MICROS))

#define PORT_FM1upReqDI 0
#define PORT_FM1downReqDI 1
#define PORT_FM1pwmActAction 17
#define PORT_FM1doDirFw 19
#define PORT_FM1doDirBw 18
#define PORT_FM1loadPosAcq 5
#define PORT_FM1loadPosAI 6
#define PORT_FM1loadPosUpSwchDI 20
#define PORT_FM1loadPosDownSwchDI 21
#define PORT_FM1driveCurrentAI 9
#define PORT_FM1hmidata 8
#define PORT_FM1hmiclock 9
#define PORT_FM1hmistrobe 10

#define PORT_POLupReqDI 0
#define PORT_POLdownReqDI 1
#define PORT_POLpwmActAction 17
#define PORT_POLdoDirFw 19
#define PORT_POLdoDirBw 18
#define PORT_POLloadPosAcq 5
#define PORT_POLloadPosAI 6
#define PORT_POLloadPosUpSwchDI 20
#define PORT_POLloadPosDownSwchDI 21
#define PORT_POLdriveCurrentAI 9
#define PORT_POLhmidata 8
#define PORT_POLhmiclock 9
#define PORT_POLhmistrobe 10

#define PORT_FM1stepCtrlA 0
#define PORT_FM1stepCtrlB 0
#define PORT_FM1stepA 0
#define PORT_FM1stepB 0

#define PORT_POLstepCtrlA 0
#define PORT_POLstepCtrlB 0
#define PORT_POLstepA 0
#define PORT_POLstepB 0


#define CFG_PWM_RESOLUTION 12

#define PORT_FM1pwmActAction_FREQ 100
#define PORT_POLpwmActAction_FREQ 100

/// Button masks
#define CFG_FM1_BUTACQ_HMI_UP_MASK (1 << 3)
#define CFG_FM1_BUTACQ_HMI_DOWN_MASK (1 << 0)
#define CFG_FM1_HMIBUT_SWITCH_UP_MASK (1 << 2)
#define CFG_FM1_HMIBUT_SWITCH_DOWN_MASK (1 << 1)

/// LED masks
#define CFG_FM1_HMILEDS_SWITCH_UP_MASK (1 << 2)
#define CFG_FM1_HMILEDS_SWITCH_DOWN_MASK (1 << 1)
#define CFG_FM1_HMILEDS_POSMODE_UP_MASK (1 << (3+8))
#define CFG_FM1_HMILEDS_POSMODE_DOWN_MASK (1 << (0+8))
#define CFG_FM1_HMILEDS_REQ_UP_MASK (1 << 3)
#define CFG_FM1_HMILEDS_REQ_DOWN_MASK (1 << 0)

#define CFG_POL_BUTACQ_HMI_UP_MASK (1 << 7)
#define CFG_POL_BUTACQ_HMI_DOWN_MASK (1 << 4)
#define CFG_POL_HMIBUT_SWITCH_UP_MASK (1 << 6)
#define CFG_POL_HMIBUT_SWITCH_DOWN_MASK (1 << 5)

/// LED masks
#define CFG_POL_HMILEDS_SWITCH_UP_MASK (1 << 6)
#define CFG_POL_HMILEDS_SWITCH_DOWN_MASK (1 << 5)
#define CFG_POL_HMILEDS_POSMODE_UP_MASK (1 << (7+8))
#define CFG_POL_HMILEDS_POSMODE_DOWN_MASK (1 << (4+8))
#define CFG_POL_HMILEDS_REQ_UP_MASK (1 << 7)
#define CFG_POL_HMILEDS_REQ_DOWN_MASK (1 << 4)

#define CFG_ACT_ACTION_STOP 0
#define CFG_ACT_ACTION_UP 1000
#define CFG_ACT_ACTION_DOWN -1000

#ifdef CFG_USE_MOTORCTRL

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

#ifdef CFG_USE_SERVO
#define CFG_FM1_SERVO_PIN SERVO_PIN_A
#define CFG_FM1_SERVO_POS_MIN 0
#define CFG_FM1_SERVO_POS_MAX 179

#define CFG_POL_SERVO_PIN SERVO_PIN_B
#define CFG_POL_SERVO_POS_MIN 0
#define CFG_POL_SERVO_POS_MAX 179
#endif

#endif













