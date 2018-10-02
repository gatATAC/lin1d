/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "FM1lin1dFSM_CI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

#ifdef CODEDESIGNER_VARS
/* ['Common definitions for 'Code items generator'' begin (DON'T REMOVE THIS LINE!)] */
/* Generic code items' definitions */
t_upreqacq upReqAcq;
t_downreqacq downReqAcq;
bool upReqDI;
bool downReqDI;
t_posmode posMode;
t_actaction actAction;
t_pwm pwmActAction;
bool doDirFw;
bool doDirBw;
t_actenable actEnable;
t_actdirection actDirection;
t_pwm_duty appliedActAction;
UI_10 loadPosAcq;
t_appliedactdirection appliedActDirection;
t_timer actDrvTimer;
UI_10 loadPosAI;
t_timer upButTimer;
t_timer downButTimer;
bool loadPosUpSwchDI;
bool loadPosDownSwchDI;
bool posAchieved;
bool ctrlError;
UI_10 driveCurrentAI;
t_drivecurrentacq driveCurrentAcq;
bool currentError;
bool brokenChainError;
bool stuckActError;
bool loadPosUpSwchAcq;
bool loadPosDownSwchAcq;
t_timer upSwitchTimer;
t_timer downSwitchTimer;
t_hmibuttons hmibuttons;
t_hmileds hmileds;
t_hmidigits hmidigits;
t_pwm_duty rectifiedActAction;
t_forcedpos forcedPos;
bool stepCtrlA;
bool stepCtrlB;
bool stepB;
t_pwmservoanglefdback pwmServoAngleFdback;
t_pwmservoenable pwmServoEnable;
t_pwmservosetpoint pwmServoSetPoint;
bool pwmServoActive;
bool pwmServoPwm;
/* ['Common definitions for 'Code items generator'' end (DON'T REMOVE THIS LINE!)] */
#endif /* CODEDESIGNER_VARS */

/* ['Common definitions for 'Hierarchical State Chart generator'' begin (DON'T REMOVE THIS LINE!)] */
/* Code items' definitions */
/* ['Common definitions for 'Hierarchical State Chart generator'' end (DON'T REMOVE THIS LINE!)] */
