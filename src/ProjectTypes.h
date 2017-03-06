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

#define CFG_ACT_ACTION_STOP 0
#define CFG_ACT_ACTION_UP 1
#define CFG_ACT_ACTION_DOWN 2

#define CFG_POS_MODE_STOP 0
#define CFG_POS_MODE_UP 1
#define CFG_POS_MODE_DOWN 2

#ifdef CFG_USE_MOTORCTRL

#define CFG_MOTORCTRL_DIR_QUIET 0
#define CFG_MOTORCTRL_DIR_FW 1
#define CFG_MOTORCTRL_DIR_BW 2

#endif

#endif


