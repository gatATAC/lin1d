/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include <stdio.h>
#include <stdlib.h>
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

#include "ProjectTypes.h"
#include "DRE.h"

#define upReqAcq (dre.upReqAcq)
#define downReqAcq (dre.downReqAcq)
#define upReqDI (dre.upReqDI)
#define downReqDI (dre.downReqDI)
#define posMode (dre.posMode)

#define actAction (dre.actAction)
#define pwmActAction (dre.pwmActAction)
#define doDirFw (dre.doDirFw)
#define doDirBw (dre.doDirBw)
#define actEnable (dre.actEnable)
#define actDirection (dre.actDirection)
#define rectifiedActAction (dre.rectifiedActAction)
#define rectifiedActDirection (dre.rectifiedActDirection)
#define appliedActDirection (dre.appliedActDirection)
#define actDrvTimer (dre.actDrvTimer)
#define loadPosAI (dre.loadPosAI)
#define upButTimer (dre.upButTimer)
#define downButTimer (dre.downButTimer)

#ifdef CODEDESIGNER_VARS

/* ['Common declarations for 'Code items generator'' begin (DON'T REMOVE THIS LINE!)] */
/* Generic code items' declarations */
extern t_upreqacq upReqAcq;
extern t_downreqacq downReqAcq;
extern BOOL upReqDI;
extern BOOL downReqDI;
extern t_posmode posMode;
extern t_actaction actAction;
extern t_pwm pwmActAction;
extern BOOL doDirFw;
extern BOOL doDirBw;
extern t_actenable actEnable;
extern t_actdirection actDirection;
extern t_pwm_duty rectifiedActAction;
extern t_rectifiedactdirection rectifiedActDirection;
extern UI_10 loadPosAcq;
extern t_appliedactdirection appliedActDirection;
extern t_timer actDrvTimer;
extern UI_10 loadPosAI;
extern t_timer upButTimer;
extern t_timer downButTimer;
/* ['Common declarations for 'Code items generator'' end (DON'T REMOVE THIS LINE!)] */

#endif // CODEDESIGNER_VARS

/* ['Common declarations for 'Hierarchical State Chart generator'' begin (DON'T REMOVE THIS LINE!)] */
/* State ID data type */
typedef unsigned long STATE_T;

/* Declaration of code items used in state charts */
/* ['Common declarations for 'Hierarchical State Chart generator'' end (DON'T REMOVE THIS LINE!)] */
