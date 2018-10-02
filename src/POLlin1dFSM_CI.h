/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include <stdio.h>
#include <stdlib.h>
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

#ifdef CODEDESIGNER_VARS
/* ['Common declarations for 'Code items generator'' begin (DON'T REMOVE THIS LINE!)] */
/* Generic code items' declarations */
extern t_upreqacq upReqAcq;
extern t_downreqacq downReqAcq;
extern bool upReqDI;
extern bool downReqDI;
extern t_posmode posMode;
extern t_actaction actAction;
extern t_pwm pwmActAction;
extern bool doDirFw;
extern bool doDirBw;
extern t_actenable actEnable;
extern t_actdirection actDirection;
extern t_pwm_duty appliedActAction;
extern UI_10 loadPosAcq;
extern t_appliedactdirection appliedActDirection;
extern t_timer actDrvTimer;
extern UI_10 loadPosAI;
extern t_timer upButTimer;
extern t_timer downButTimer;
extern bool loadPosUpSwchDI;
extern bool loadPosDownSwchDI;
extern bool posAchieved;
extern bool ctrlError;
extern UI_10 driveCurrentAI;
extern t_drivecurrentacq driveCurrentAcq;
extern bool currentError;
extern bool brokenChainError;
extern bool stuckActError;
extern bool loadPosUpSwchAcq;
extern bool loadPosDownSwchAcq;
extern t_timer upSwitchTimer;
extern t_timer downSwitchTimer;
extern t_hmibuttons hmibuttons;
extern t_hmileds hmileds;
extern t_hmidigits hmidigits;
extern t_pwm_duty rectifiedActAction;
extern t_forcedpos forcedPos;
extern bool stepCtrlA;
extern bool stepCtrlB;
extern bool stepB;
extern t_pwmservoanglefdback pwmServoAngleFdback;
extern t_pwmservoenable pwmServoEnable;
extern t_pwmservosetpoint pwmServoSetPoint;
extern bool pwmServoActive;
extern bool pwmServoPwm;
/* ['Common declarations for 'Code items generator'' end (DON'T REMOVE THIS LINE!)] */
#endif /* CODEDESIGNER_VARS */

/* ['Common declarations for 'Hierarchical State Chart generator'' begin (DON'T REMOVE THIS LINE!)] */
/* State ID data type */
typedef unsigned long STATE_T;

/* Declaration of code items used in state charts */
/* ['Common declarations for 'Hierarchical State Chart generator'' end (DON'T REMOVE THIS LINE!)] */
