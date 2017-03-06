#ifndef _PROJECT_TYPES
#define _PROJECT_TYPES

#include <Arduino.h>

typedef uint8_t BOOL;
typedef uint8_t t_upreqacq;
typedef uint8_t t_downreqacq;
typedef uint8_t t_posmode;
typedef uint16_t t_pwm;
typedef t_pwm t_actaction;
typedef BOOL t_actenable;
typedef uint8_t t_actdirection;
typedef t_pwm t_pwm_duty;
typedef uint8_t t_rectifiedactdirection;
typedef uint8_t t_appliedactdirection;
typedef uint32_t t_timer;
typedef uint16_t t_drivecurrentacq;
typedef byte t_hmibuttons;
typedef word t_hmileds;
typedef unsigned long t_hmidigits;

#define TRUE (1==1)
#define FALSE (1==0)

#define CFG_ACT_DIRECTION_QUIET 0
#define CFG_ACT_DIRECTION_FW 1
#define CFG_ACT_DIRECTION_BW 2

#define CFG_ACT_DRIVER_STAB_TIME 40
#define CFG_ACT_DRIVER_DISSIP_TIME 100

#define CFG_UP_BUT_PRESS_TIMER 50
#define CFG_DWN_BUT_PRESS_TIMER 50
#define CFG_UP_BUT_UNPRESS_TIMER 50
#define CFG_DWN_BUT_UNPRESS_TIMER 50

#define CFG_BUTACQ_HMI_UP_MASK (1<<7)
#define CFG_BUTACQ_HMI_DOWN_MASK (1<<0)

#define CFG_UP_SWITCH_DETECT_TIMER 10
#define CFG_DOWN_SWITCH_DETECT_TIMER 10
#define CFG_UP_SWITCH_UNDETECT_TIMER 10
#define CFG_DOWN_SWITCH_UNDETECT_TIMER 10

#define CFG_ACT_ACTION_STOP 0
#define CFG_ACT_ACTION_UP 1
#define CFG_ACT_ACTION_DOWN 2

#define CFG_POS_MODE_STOP 0
#define CFG_POS_MODE_UP 1
#define CFG_POS_MODE_DOWN 2


#endif
