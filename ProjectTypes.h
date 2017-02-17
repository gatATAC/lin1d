#ifndef _PROJECT_TYPES
#define _PROJECT_TYPES

#ifdef DUMMY_COMPILATION
#include "DummyTypes.h"
#endif

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

#define CFG_ACT_DIRECTION_QUIET 0
#define CFG_ACT_DIRECTION_FW 1
#define CFG_ACT_DIRECTION_BW 2

#define CFG_ACT_DRIVER_STAB_TIME 40
#define CFG_ACT_DRIVER_DISSIP_TIME 100

#endif
