/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "lin1dFSM_CI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

#ifdef CODEDESIGNER_VARS
/* ['Common definitions for 'Code items generator'' begin (DON'T REMOVE THIS LINE!)] */
/* Generic code items' definitions */
t_upreqacq upReqAcq;
t_downreqacq downReqAcq;
BOOL upReqDI;
BOOL downReqDI;
t_posmode posMode;
t_actaction actAction;
t_pwm pwmActAction;
BOOL doDirFw;
BOOL doDirBw;
t_actenable actEnable;
t_actdirection actDirection;
t_pwm_duty rectifiedActAction;
t_rectifiedactdirection rectifiedActDirection;
UI_10 loadPosAcq;
t_appliedactdirection appliedActDirection;
t_timer actDrvTimer;
UI_10 loadPosAI;
t_timer upButTimer;
t_timer downButTimer;
BOOL loadPosUpSwchDI;
BOOL loadPosDownSwchDI;
BOOL posAchieved;
BOOL ctrlError;
UI_10 driveCurrentAI;
t_drivecurrentacq driveCurrentAcq;
BOOL currentError;
BOOL brokenChainError;
BOOL stuckActError;
BOOL loadPosUpSwchAcq;
BOOL loadPosDownSwchAcq;
t_timer upSwitchTimer;
t_timer downSwitchTimer;
/* ['Common definitions for 'Code items generator'' end (DON'T REMOVE THIS LINE!)] */
#endif // CODEDESIGNER_VARS
/* ['Common definitions for 'Hierarchical State Chart generator'' begin (DON'T REMOVE THIS LINE!)] */
/* Code items' definitions */
/* ['Common definitions for 'Hierarchical State Chart generator'' end (DON'T REMOVE THIS LINE!)] */
