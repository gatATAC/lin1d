/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "lin1dFSM.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

#include "DRE.h"

extern t_dre dre;

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
#define loadPosAcq (dre.loadPosAcq)
#define appliedActDirection (dre.appliedActDirection)
#define actDrvTimer (dre.actDrvTimer)
#define loadPosAI (dre.loadPosAI)
#define upButTimer (dre.upButTimer)
#define downButTimer (dre.downButTimer)
#define loadPosUpSwchDI (dre.loadPosUpSwchDI)
#define loadPosDownSwchDI (dre.loadPosDownSwchDI)
#define posAchieved (dre.posAchieved)
#define ctrlError (dre.ctrlError)
#define driveCurrentAI (dre.driveCurrentAI)
#define driveCurrentAcq (dre.driveCurrentAcq)
#define currentError (dre.currentError)
#define brokenChainError (dre.brokenChainError)
#define stuckActError (dre.stuckActError)
#define loadPosUpSwchAcq (dre.loadPosUpSwchAcq)
#define loadPosDownSwchAcq (dre.loadPosDownSwchAcq)
#define upSwitchTimer (dre.upSwitchTimer)
#define downSwitchTimer (dre.downSwitchTimer)

/* ['ActRectifier' begin (DON'T REMOVE THIS LINE!)] */
void ActRectifier(  )
{
    /* set initial state */
    static STATE_T state = ID_ACTRECTIFIER_INIT;

    switch( state )
    {
        /* State ID: ID_ACTRECTIFIER_INIT */
        case ID_ACTRECTIFIER_INIT:
        {
            /* Transition ID: ID_ACTRECTIFIER_FROMINITTOQUIET */
            /* Actions: */
            /* ['<global>::setActuationQuiet' begin] */
            rectifiedActAction = (t_pwm) 0;
            actDirection = CFG_ACT_DIRECTION_QUIET;
            /* ['<global>::setActuationQuiet' end] */
            /* ['<global>::execActDriving' begin] */
            ActDriving();
            /* ['<global>::execActDriving' end] */
            state = ID_ACTRECTIFIER_QUIET;
            break;
        }
        /* State ID: ID_ACTRECTIFIER_QUIET */
        case ID_ACTRECTIFIER_QUIET:
        {
            if( actAction<0 )
            {
                /* Transition ID: ID_ACTRECTIFIER_FROMQUIETTOBW */
                /* Actions: */
                /* ['<global>::setActuationModule' begin] */
                if (actAction >= 0) {
                    rectifiedActAction = (t_pwm) actAction;
                } else {
                    rectifiedActAction = (t_pwm) (-actAction);
                }
                /* ['<global>::setActuationModule' end] */
                /* ['<global>::setActuationBw' begin] */
                actDirection = CFG_ACT_DIRECTION_BW;
                /* ['<global>::setActuationBw' end] */
                /* ['<global>::execActDriving' begin] */
                ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_ACTRECTIFIER_BW;
            }
            else if( actAction>0 )
            {
                /* Transition ID: ID_ACTRECTIFIER_FROMQUIETTOFW */
                /* Actions: */
                /* ['<global>::setActuationModule' begin] */
                if (actAction >= 0) {
                    rectifiedActAction = (t_pwm) actAction;
                } else {
                    rectifiedActAction = (t_pwm) (-actAction);
                }
                /* ['<global>::setActuationModule' end] */
                /* ['<global>::setActuationFw' begin] */
                actDirection = CFG_ACT_DIRECTION_FW;
                /* ['<global>::setActuationFw' end] */
                /* ['<global>::execActDriving' begin] */
                ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_ACTRECTIFIER_FW;
            }
            break;
        }
        /* State ID: ID_ACTRECTIFIER_BW */
        case ID_ACTRECTIFIER_BW:
        {
            if( actAction<0 )
            {
                /* Transition ID: ID_ACTRECTIFIER_BWLOOP */
                /* Actions: */
                /* ['<global>::setActuationModule' begin] */
                if (actAction >= 0) {
                    rectifiedActAction = (t_pwm) actAction;
                } else {
                    rectifiedActAction = (t_pwm) (-actAction);
                }
                /* ['<global>::setActuationModule' end] */
                /* ['<global>::setActuationBw' begin] */
                actDirection = CFG_ACT_DIRECTION_BW;
                /* ['<global>::setActuationBw' end] */
                /* ['<global>::execActDriving' begin] */
                ActDriving();
                /* ['<global>::execActDriving' end] */
            }
            else if( actAction>0 )
            {
                /* Transition ID: ID_ACTRECTIFIER_FROMBWTOFW */
                /* Actions: */
                /* ['<global>::setActuationModule' begin] */
                if (actAction >= 0) {
                    rectifiedActAction = (t_pwm) actAction;
                } else {
                    rectifiedActAction = (t_pwm) (-actAction);
                }
                /* ['<global>::setActuationModule' end] */
                /* ['<global>::setActuationFw' begin] */
                actDirection = CFG_ACT_DIRECTION_FW;
                /* ['<global>::setActuationFw' end] */
                /* ['<global>::execActDriving' begin] */
                ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_ACTRECTIFIER_FW;
            }
            else if( actAction==0 )
            {
                /* Transition ID: ID_ACTRECTIFIER_FROMBWTOQUIET */
                /* Actions: */
                /* ['<global>::setActuationQuiet' begin] */
                rectifiedActAction = (t_pwm) 0;
                actDirection = CFG_ACT_DIRECTION_QUIET;
                /* ['<global>::setActuationQuiet' end] */
                /* ['<global>::execActDriving' begin] */
                ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_ACTRECTIFIER_QUIET;
            }
            break;
        }
        /* State ID: ID_ACTRECTIFIER_FW */
        case ID_ACTRECTIFIER_FW:
        {
            if( actAction>0 )
            {
                /* Transition ID: ID_ACTRECTIFIER_FWLOOP */
                /* Actions: */
                /* ['<global>::setActuationModule' begin] */
                if (actAction >= 0) {
                    rectifiedActAction = (t_pwm) actAction;
                } else {
                    rectifiedActAction = (t_pwm) (-actAction);
                }
                /* ['<global>::setActuationModule' end] */
                /* ['<global>::setActuationFw' begin] */
                actDirection = CFG_ACT_DIRECTION_FW;
                /* ['<global>::setActuationFw' end] */
                /* ['<global>::execActDriving' begin] */
                ActDriving();
                /* ['<global>::execActDriving' end] */
            }
            else if( actAction==0 )
            {
                /* Transition ID: ID_ACTRECTIFIER_FROMFWTOQUIET */
                /* Actions: */
                /* ['<global>::setActuationQuiet' begin] */
                rectifiedActAction = (t_pwm) 0;
                actDirection = CFG_ACT_DIRECTION_QUIET;
                /* ['<global>::setActuationQuiet' end] */
                /* ['<global>::execActDriving' begin] */
                ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_ACTRECTIFIER_QUIET;
            }
            break;
        }
    }
}
/* ['ActRectifier' end (DON'T REMOVE THIS LINE!)] */

/* ['ActDriving' begin (DON'T REMOVE THIS LINE!)] */
void ActDriving(  )
{
    /* set initial state */
    static STATE_T state = ID_ACTDRIVING_INIT;

    switch( state )
    {
        /* State ID: ID_ACTDRIVING_INIT */
        case ID_ACTDRIVING_INIT:
        {
            /* Transition ID: ID_ACTDRIVING_TOSTAB */
            /* Actions: */
            /* ['<global>::stopActuation' begin] */
            synthesize_pwmActAction((t_pwm) 0);
            /* ['<global>::stopActuation' end] */
            /* ['<global>::applyDirection' begin] */
            appliedActDirection = actDirection;
            /* ['<global>::applyDirection' end] */
            /* ['<global>::resetActDriverTimer' begin] */
            actDrvTimer = 0L;
            /* ['<global>::resetActDriverTimer' end] */
            state = ID_ACTDRIVING_STABILIZE;
            break;
        }
        /* State ID: ID_ACTDRIVING_STABILIZE */
        case ID_ACTDRIVING_STABILIZE:
        {
            if( (actDirection!=CFG_ACT_DIRECTION_QUIET) && (actDrvTimer>=CFG_ACT_DRIVER_STAB_TIME) )
            {
                /* Transition ID: ID_ACTDRIVING_FROMSTABTOWORK */
                /* Actions: */
                /* ['<global>::applyActuation' begin] */
                synthesize_pwmActAction(rectifiedActAction);
                /* ['<global>::applyActuation' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer = 0L;
                /* ['<global>::resetActDriverTimer' end] */
                state = ID_ACTDRIVING_WORK;
            }
            else if( appliedActDirection!=actDirection )
            {
                /* Transition ID: ID_ACTDRIVING_DIRCHANGEDURINGSTAB */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                synthesize_pwmActAction((t_pwm) 0);
                /* ['<global>::stopActuation' end] */
                /* ['<global>::applyDirection' begin] */
                appliedActDirection = actDirection;
                /* ['<global>::applyDirection' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer = 0L;
                /* ['<global>::resetActDriverTimer' end] */
            }
            else
            {
                /* Transition ID: ID_ACTDRIVING_STABLOOP */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                synthesize_pwmActAction((t_pwm) 0);
                /* ['<global>::stopActuation' end] */
                /* ['<global>::incrementActDriverTimer' begin] */
                actDrvTimer++;
                /* ['<global>::incrementActDriverTimer' end] */
            }
            break;
        }
        /* State ID: ID_ACTDRIVING_WORK */
        case ID_ACTDRIVING_WORK:
        {
            if( appliedActDirection!=actDirection )
            {
                /* Transition ID: ID_ACTDRIVING_TODISSIPATE */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                synthesize_pwmActAction((t_pwm) 0);
                /* ['<global>::stopActuation' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer = 0L;
                /* ['<global>::resetActDriverTimer' end] */
                state = ID_ACTDRIVING_DISSIPATE;
            }
            break;
        }
        /* State ID: ID_ACTDRIVING_DISSIPATE */
        case ID_ACTDRIVING_DISSIPATE:
        {
            if( actDrvTimer>=CFG_ACT_DRIVER_DISSIP_TIME )
            {
                /* Transition ID: ID_ACTDRIVING_ENDDISSIPATE */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                synthesize_pwmActAction((t_pwm) 0);
                /* ['<global>::stopActuation' end] */
                /* ['<global>::applyDirection' begin] */
                appliedActDirection = actDirection;
                /* ['<global>::applyDirection' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer = 0L;
                /* ['<global>::resetActDriverTimer' end] */
                state = ID_ACTDRIVING_STABILIZE;
            }
            else
            {
                /* Transition ID: ID_ACTDRIVING_DISSIPATELOOP */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                synthesize_pwmActAction((t_pwm) 0);
                /* ['<global>::stopActuation' end] */
                /* ['<global>::incrementActDriverTimer' begin] */
                actDrvTimer++;
                /* ['<global>::incrementActDriverTimer' end] */
            }
            break;
        }
    }
}
/* ['ActDriving' end (DON'T REMOVE THIS LINE!)] */

/* ['ActEnabler' begin (DON'T REMOVE THIS LINE!)] */
void ActEnabler(  )
{
    /* set initial state */
    static STATE_T state = ID_ACTENABLER_INIT;

    switch( state )
    {
        /* State ID: ID_ACTENABLER_INIT */
        case ID_ACTENABLER_INIT:
        {
            /* Transition ID: ID_ACTENABLER_FROMINITTODISABLE */
            /* Actions: */
            /* ['<global>::setActuationQuiet' begin] */
            rectifiedActAction = (t_pwm) 0;
            actDirection = CFG_ACT_DIRECTION_QUIET;
            /* ['<global>::setActuationQuiet' end] */
            /* ['<global>::execActDriving' begin] */
            ActDriving();
            /* ['<global>::execActDriving' end] */
            state = ID_ACTENABLER_DISABLED;
            break;
        }
        /* State ID: ID_ACTENABLER_DISABLED */
        case ID_ACTENABLER_DISABLED:
        {
            if( actEnable==TRUE )
            {
                /* Transition ID: ID_ACTENABLER_TOENABLE */
                /* Actions: */
                /* ['<global>::execActRectifier' begin] */
                ActRectifier();
                /* ['<global>::execActRectifier' end] */
                state = ID_ACTENABLER_ENABLED;
            }
            break;
        }
        /* State ID: ID_ACTENABLER_ENABLED */
        case ID_ACTENABLER_ENABLED:
        {
            if( actEnable==FALSE )
            {
                /* Transition ID: ID_ACTENABLER_TODISABLE */
                /* Actions: */
                /* ['<global>::setActuationQuiet' begin] */
                rectifiedActAction = (t_pwm) 0;
                actDirection = CFG_ACT_DIRECTION_QUIET;
                /* ['<global>::setActuationQuiet' end] */
                /* ['<global>::execActDriving' begin] */
                ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_ACTENABLER_DISABLED;
            }
            else
            {
                /* Transition ID: ID_ACTENABLER_LOOP */
                /* Actions: */
                /* ['<global>::execActRectifier' begin] */
                ActRectifier();
                /* ['<global>::execActRectifier' end] */
            }
            break;
        }
    }
}
/* ['ActEnabler' end (DON'T REMOVE THIS LINE!)] */

/* ['UpButAcq' begin (DON'T REMOVE THIS LINE!)] */
void UpButAcq(  )
{
    /* set initial state */
    static STATE_T state = ID_UPBUTACQ_INIT;

    switch( state )
    {
        /* State ID: ID_UPBUTACQ_INIT */
        case ID_UPBUTACQ_INIT:
        {
            /* Transition ID: ID_UPBUTACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetUpButTimer' begin] */
            upButTimer = 0L;
            /* ['<global>::resetUpButTimer' end] */
            /* ['<global>::clearUpButton' begin] */
            upReqAcq = FALSE;
            /* ['<global>::clearUpButton' end] */
            state = ID_UPBUTACQ_NOTPRESSED;
            break;
        }
        /* State ID: ID_UPBUTACQ_NOTPRESSED */
        case ID_UPBUTACQ_NOTPRESSED:
        {
            if( (upReqDI==TRUE) && (upButTimer > CFG_UP_BUT_PRESS_TIMER) )
            {
                /* Transition ID: ID_UPBUTACQ_PRESS */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
                /* ['<global>::setUpButton' begin] */
                upReqAcq = TRUE;
                /* ['<global>::setUpButton' end] */
                state = ID_UPBUTACQ_PRESSED;
            }
            else if( (upReqDI==TRUE) )
            {
                /* Transition ID: ID_UPBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpButTimer' begin] */
                upButTimer++;
                /* ['<global>::incrementUpButTimer' end] */
            }
            else if( (upReqDI==FALSE) )
            {
                /* Transition ID: ID_UPBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
            }
            break;
        }
        /* State ID: ID_UPBUTACQ_PRESSED */
        case ID_UPBUTACQ_PRESSED:
        {
            if( (upReqDI==FALSE)  && (upButTimer > CFG_UP_BUT_UNPRESS_TIMER) )
            {
                /* Transition ID: ID_UPBUTACQ_UNPRESS */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
                /* ['<global>::clearUpButton' begin] */
                upReqAcq = FALSE;
                /* ['<global>::clearUpButton' end] */
                state = ID_UPBUTACQ_NOTPRESSED;
            }
            else if( (upReqDI==FALSE) )
            {
                /* Transition ID: ID_UPBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpButTimer' begin] */
                upButTimer++;
                /* ['<global>::incrementUpButTimer' end] */
            }
            else if( (upReqDI==TRUE) )
            {
                /* Transition ID: ID_UPBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
            }
            break;
        }
    }
}
/* ['UpButAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['DownButAcq' begin (DON'T REMOVE THIS LINE!)] */
void DownButAcq(  )
{
    /* set initial state */
    static STATE_T state = ID_DOWNBUTACQ_INIT;

    switch( state )
    {
        /* State ID: ID_DOWNBUTACQ_INIT */
        case ID_DOWNBUTACQ_INIT:
        {
            /* Transition ID: ID_DOWNBUTACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetDownButTimer' begin] */
            downButTimer = 0L;
            /* ['<global>::resetDownButTimer' end] */
            /* ['<global>::setDownButton' begin] */
            downReqAcq = TRUE;
            /* ['<global>::setDownButton' end] */
            state = ID_DOWNBUTACQ_NOTPRESSED;
            break;
        }
        /* State ID: ID_DOWNBUTACQ_NOTPRESSED */
        case ID_DOWNBUTACQ_NOTPRESSED:
        {
            if( (downReqDI==TRUE) && (downButTimer > CFG_DWN_BUT_PRESS_TIMER) )
            {
                /* Transition ID: ID_DOWNBUTACQ_PRESS */
                /* Actions: */
                /* ['<global>::resetDownButTimer' begin] */
                downButTimer = 0L;
                /* ['<global>::resetDownButTimer' end] */
                /* ['<global>::setDownButton' begin] */
                downReqAcq = TRUE;
                /* ['<global>::setDownButton' end] */
                state = ID_DOWNBUTACQ_PRESSED;
            }
            else if( (downReqDI==TRUE) )
            {
                /* Transition ID: ID_DOWNBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementDownButTimer' begin] */
                downButTimer++;
                /* ['<global>::incrementDownButTimer' end] */
            }
            else if( (downReqDI==FALSE) && (downButTimer > CFG_DWN_BUT_UNPRESS_TIMER) )
            {
                /* Transition ID: ID_DOWNBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetDownButTimer' begin] */
                downButTimer = 0L;
                /* ['<global>::resetDownButTimer' end] */
            }
            break;
        }
        /* State ID: ID_DOWNBUTACQ_PRESSED */
        case ID_DOWNBUTACQ_PRESSED:
        {
            if( (downReqDI==FALSE) && (downButTimer > CFG_DWN_BUT_UNPRESS_TIMER) )
            {
                /* Transition ID: ID_DOWNBUTACQ_UNPRESS */
                /* Actions: */
                /* ['<global>::resetDownButTimer' begin] */
                downButTimer = 0L;
                /* ['<global>::resetDownButTimer' end] */
                /* ['<global>::clearDownButton' begin] */
                downReqAcq = FALSE;
                /* ['<global>::clearDownButton' end] */
                state = ID_DOWNBUTACQ_NOTPRESSED;
            }
            else if( (upReqDI==TRUE) )
            {
                /* Transition ID: ID_DOWNBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementDownButTimer' begin] */
                downButTimer++;
                /* ['<global>::incrementDownButTimer' end] */
            }
            else if( (downReqDI==TRUE) )
            {
                /* Transition ID: ID_DOWNBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetDownButTimer' begin] */
                downButTimer = 0L;
                /* ['<global>::resetDownButTimer' end] */
            }
            break;
        }
    }
}
/* ['DownButAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['PosControl' begin (DON'T REMOVE THIS LINE!)] */
void PosControl(  )
{
    /* set initial state */
    static STATE_T state = ID_POSCONTROL_INIT;

    switch( state )
    {
        /* State ID: ID_POSCONTROL_INIT */
        case ID_POSCONTROL_INIT:
        {
            /* Transition ID: ID_POSCONTROL_INITIAL */
            /* Actions: */
            /* ['<global>::stopAction' begin] */
            actAction = CFG_ACT_ACTION_STOP;
            /* ['<global>::stopAction' end] */
            /* ['<global>::cleanError' begin] */
            ctrlError = FALSE;
            /* ['<global>::cleanError' end] */
            state = ID_POSCONTROL_STOP;
            break;
        }
        /* State ID: ID_POSCONTROL_STOP */
        case ID_POSCONTROL_STOP:
        {
            if( (posMode=CFG_POS_MODE_UP) && (loadPosUpSwchAcq==FALSE) && (ctrlError==FALSE) )
            {
                /* Transition ID: ID_POSCONTROL_TOUP */
                /* Actions: */
                /* ['<global>::upAction' begin] */
                actAction = CFG_ACT_ACTION_UP;
                posAchieved = FALSE;
                /* ['<global>::upAction' end] */
                state = ID_POSCONTROL_GOINGUP;
            }
            else if( ((loadPosDownSwchAcq==FALSE) && (posMode==CFG_POS_MODE_DOWN)) && (ctrlError==FALSE) )
            {
                /* Transition ID: ID_POSCONTROL_TODOWN */
                /* Actions: */
                /* ['<global>::downAction' begin] */
                actAction = CFG_ACT_ACTION_DOWN;
                posAchieved = FALSE;
                /* ['<global>::downAction' end] */
                state = ID_POSCONTROL_GOINGDOWN;
            }
            break;
        }
        /* State ID: ID_POSCONTROL_GOINGUP */
        case ID_POSCONTROL_GOINGUP:
        {
            if( loadPosUpSwchAcq==TRUE )
            {
                /* Transition ID: ID_POSCONTROL_FINISHED */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                /* ['<global>::notifyAchieved' begin] */
                posAchieved = TRUE;
                /* ['<global>::notifyAchieved' end] */
                state = ID_POSCONTROL_STOP;
            }
            else if( posMode!=CFG_POS_MODE_UP )
            {
                /* Transition ID: ID_POSCONTROL_CANCEL */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                state = ID_POSCONTROL_STOP;
            }
            else if( (currentError==TRUE) || (brokenChainError==TRUE) || (stuckActError==TRUE) )
            {
                /* Transition ID: ID_POSCONTROL_ERROR */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                /* ['<global>::setError' begin] */
                ctrlError = TRUE;
                /* ['<global>::setError' end] */
                state = ID_POSCONTROL_STOP;
            }
            break;
        }
        /* State ID: ID_POSCONTROL_GOINGDOWN */
        case ID_POSCONTROL_GOINGDOWN:
        {
            if( loadPosDownSwchAcq==TRUE )
            {
                /* Transition ID: ID_POSCONTROL_FINISHED */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                /* ['<global>::notifyAchieved' begin] */
                posAchieved = TRUE;
                /* ['<global>::notifyAchieved' end] */
                state = ID_POSCONTROL_STOP;
            }
            else if( posMode!=CFG_POS_MODE_DOWN )
            {
                /* Transition ID: ID_POSCONTROL_CANCEL */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                state = ID_POSCONTROL_STOP;
            }
            else if( (currentError==TRUE) || (brokenChainError==TRUE) || (stuckActError==TRUE) )
            {
                /* Transition ID: ID_POSCONTROL_ERROR */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                /* ['<global>::setError' begin] */
                ctrlError = TRUE;
                /* ['<global>::setError' end] */
                state = ID_POSCONTROL_STOP;
            }
            break;
        }
    }
}
/* ['PosControl' end (DON'T REMOVE THIS LINE!)] */

/* ['ModeSelector' begin (DON'T REMOVE THIS LINE!)] */
void ModeSelector(  )
{
    /* set initial state */
    static STATE_T state = ID_MODESELECTOR_INIT;

    switch( state )
    {
        /* State ID: ID_MODESELECTOR_INIT */
        case ID_MODESELECTOR_INIT:
        {
            /* Transition ID: ID_MODESELECTOR_INITIAL */
            /* Actions: */
            /* ['<global>::setStopMode' begin] */
            posMode = CFG_POS_MODE_STOP;
            /* ['<global>::setStopMode' end] */
            state = ID_MODESELECTOR_STOP;
            break;
        }
        /* State ID: ID_MODESELECTOR_STOP */
        case ID_MODESELECTOR_STOP:
        {
            if( upReqAcq==TRUE && downReqAcq==FALSE )
            {
                /* Transition ID: ID_MODESELECTOR_TOUP */
                /* Actions: */
                /* ['<global>::setUpMode' begin] */
                posMode = CFG_POS_MODE_UP;
                /* ['<global>::setUpMode' end] */
                state = ID_MODESELECTOR_UP;
            }
            else if( downReqAcq==TRUE )
            {
                /* Transition ID: ID_MODESELECTOR_TODOWN */
                /* Actions: */
                /* ['<global>::setDownMode' begin] */
                posMode = CFG_POS_MODE_DOWN;
                /* ['<global>::setDownMode' end] */
                state = ID_MODESELECTOR_DOWN;
            }
            break;
        }
        /* State ID: ID_MODESELECTOR_UP */
        case ID_MODESELECTOR_UP:
        {
            if( ( downReqAcq==TRUE ) || ( posAchieved==TRUE ) || ( ctrlError==TRUE ) )
            {
                /* Transition ID: ID_MODESELECTOR_OPTIMIZED_TRANSITION_1 */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_MODESELECTOR_STOPWAIT;
            }
            break;
        }
        /* State ID: ID_MODESELECTOR_STOPWAIT */
        case ID_MODESELECTOR_STOPWAIT:
        {
            if( (downReqAcq==FALSE && upReqAcq==FALSE) )
            {
                /* Transition ID: ID_MODESELECTOR_RELEASE */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_MODESELECTOR_STOP;
            }
            break;
        }
        /* State ID: ID_MODESELECTOR_DOWN */
        case ID_MODESELECTOR_DOWN:
        {
            if( ( upReqAcq==TRUE && downReqAcq==FALSE ) || ( posAchieved==TRUE ) || ( ctrlError==TRUE ) )
            {
                /* Transition ID: ID_MODESELECTOR_OPTIMIZED_TRANSITION_1 */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_MODESELECTOR_STOPWAIT;
            }
            break;
        }
    }
}
/* ['ModeSelector' end (DON'T REMOVE THIS LINE!)] */

/* ['downSwitchAcq' begin (DON'T REMOVE THIS LINE!)] */
void downSwitchAcq(  )
{
    /* set initial state */
    static STATE_T state = ID_DOWNSWITCHACQ_INIT;

    switch( state )
    {
        /* State ID: ID_DOWNSWITCHACQ_INIT */
        case ID_DOWNSWITCHACQ_INIT:
        {
            /* Transition ID: ID_DOWNSWITCHACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetDownSwitchTimer' begin] */
            downSwitchTimer=0L;
            /* ['<global>::resetDownSwitchTimer' end] */
            /* ['<global>::clearDownSwitch' begin] */
            loadPosDownSwchAcq = FALSE;
            /* ['<global>::clearDownSwitch' end] */
            state = ID_DOWNSWITCHACQ_NOTDETECTED;
            break;
        }
        /* State ID: ID_DOWNSWITCHACQ_NOTDETECTED */
        case ID_DOWNSWITCHACQ_NOTDETECTED:
        {
            if( (loadPosDownSwchDI==TRUE) && (downSwitchTimer > CFG_DOWN_SWITCH_DETECT_TIMER) )
            {
                /* Transition ID: ID_DOWNSWITCHACQ_DETECT */
                /* Actions: */
                /* ['<global>::resetDownSwitchTimer' begin] */
                downSwitchTimer=0L;
                /* ['<global>::resetDownSwitchTimer' end] */
                /* ['<global>::setDownSwitch' begin] */
                loadPosDownSwchAcq = TRUE;
                /* ['<global>::setDownSwitch' end] */
                state = ID_DOWNSWITCHACQ_DETECTED;
            }
            else if( (loadPosDownSwchDI ==TRUE) )
            {
                /* Transition ID: ID_DOWNSWITCHACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementDownSwitchTimer' begin] */
                downSwitchTimer++;
                /* ['<global>::incrementDownSwitchTimer' end] */
            }
            else if( (loadPosDownSwchDI == FALSE) )
            {
                /* Transition ID: ID_DOWNSWITCHACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetDownSwitchTimer' begin] */
                downSwitchTimer=0L;
                /* ['<global>::resetDownSwitchTimer' end] */
            }
            break;
        }
        /* State ID: ID_DOWNSWITCHACQ_DETECTED */
        case ID_DOWNSWITCHACQ_DETECTED:
        {
            if( (loadPosDownSwchDI == FALSE) )
            {
                /* Transition ID: ID_DOWNSWITCHACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementDownSwitchTimer' begin] */
                downSwitchTimer++;
                /* ['<global>::incrementDownSwitchTimer' end] */
            }
            else if( (loadPosDownSwchDI ==TRUE) )
            {
                /* Transition ID: ID_DOWNSWITCHACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetDownSwitchTimer' begin] */
                downSwitchTimer=0L;
                /* ['<global>::resetDownSwitchTimer' end] */
            }
            else if( (loadPosDownSwchDI ==FALSE) && (downSwitchTimer > CFG_DOWN_SWITCH_DETECT_TIMER) )
            {
                /* Transition ID: ID_DOWNSWITCHACQ_UNDETECT */
                /* Actions: */
                /* ['<global>::resetDownSwitchTimer' begin] */
                downSwitchTimer=0L;
                /* ['<global>::resetDownSwitchTimer' end] */
                /* ['<global>::clearDownSwitch' begin] */
                loadPosDownSwchAcq = FALSE;
                /* ['<global>::clearDownSwitch' end] */
                state = ID_DOWNSWITCHACQ_NOTDETECTED;
            }
            break;
        }
    }
}
/* ['downSwitchAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['upSwitchAcq' begin (DON'T REMOVE THIS LINE!)] */
void upSwitchAcq(  )
{
    /* set initial state */
    static STATE_T state = ID_UPSWITCHACQ_INIT;

    switch( state )
    {
        /* State ID: ID_UPSWITCHACQ_INIT */
        case ID_UPSWITCHACQ_INIT:
        {
            /* Transition ID: ID_UPSWITCHACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetUpSwitchTimer' begin] */
            upSwitchTimer=0L;
            /* ['<global>::resetUpSwitchTimer' end] */
            /* ['<global>::clearUpSwitch' begin] */
            loadPosUpSwchAcq = FALSE;
            /* ['<global>::clearUpSwitch' end] */
            state = ID_UPSWITCHACQ_NOTDETECTED;
            break;
        }
        /* State ID: ID_UPSWITCHACQ_NOTDETECTED */
        case ID_UPSWITCHACQ_NOTDETECTED:
        {
            if( (loadPosUpSwchDI==TRUE) && (upSwitchTimer > CFG_UP_SWITCH_DETECT_TIMER) )
            {
                /* Transition ID: ID_UPSWITCHACQ_DETECT */
                /* Actions: */
                /* ['<global>::resetUpSwitchTimer' begin] */
                upSwitchTimer=0L;
                /* ['<global>::resetUpSwitchTimer' end] */
                /* ['<global>::setUpSwitch' begin] */
                loadPosUpSwchAcq = TRUE;
                /* ['<global>::setUpSwitch' end] */
                state = ID_UPSWITCHACQ_DETECTED;
            }
            else if( (loadPosUpSwchDI ==TRUE) )
            {
                /* Transition ID: ID_UPSWITCHACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpSwitchTimer' begin] */
                upSwitchTimer++;
                /* ['<global>::incrementUpSwitchTimer' end] */
            }
            else if( (loadPosUpSwchDI == FALSE) )
            {
                /* Transition ID: ID_UPSWITCHACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpSwitchTimer' begin] */
                upSwitchTimer=0L;
                /* ['<global>::resetUpSwitchTimer' end] */
            }
            break;
        }
        /* State ID: ID_UPSWITCHACQ_DETECTED */
        case ID_UPSWITCHACQ_DETECTED:
        {
            if( (loadPosUpSwchDI ==FALSE) && (upSwitchTimer > CFG_UP_SWITCH_DETECT_TIMER) )
            {
                /* Transition ID: ID_UPSWITCHACQ_UNDETECT */
                /* Actions: */
                /* ['<global>::resetUpSwitchTimer' begin] */
                upSwitchTimer=0L;
                /* ['<global>::resetUpSwitchTimer' end] */
                /* ['<global>::clearUpSwitch' begin] */
                loadPosUpSwchAcq = FALSE;
                /* ['<global>::clearUpSwitch' end] */
                state = ID_UPSWITCHACQ_NOTDETECTED;
            }
            else if( (loadPosUpSwchDI == FALSE) )
            {
                /* Transition ID: ID_UPSWITCHACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpSwitchTimer' begin] */
                upSwitchTimer++;
                /* ['<global>::incrementUpSwitchTimer' end] */
            }
            else if( (loadPosUpSwchDI ==TRUE) )
            {
                /* Transition ID: ID_UPSWITCHACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpSwitchTimer' begin] */
                upSwitchTimer=0L;
                /* ['<global>::resetUpSwitchTimer' end] */
            }
            break;
        }
    }
}
/* ['upSwitchAcq' end (DON'T REMOVE THIS LINE!)] */
