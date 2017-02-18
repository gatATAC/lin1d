/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "lin1dFSM.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

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
            rectifiedActAction=(t_pwm)0;
            actDirection=CFG_ACT_DIRECTION_QUIET;
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
                if (actAction>=0){
                  rectifiedActAction=(t_pwm)actAction;
                } else {
                  rectifiedActAction=(t_pwm)(-actAction);
                }
                /* ['<global>::setActuationModule' end] */
                /* ['<global>::setActuationBw' begin] */
                actDirection=CFG_ACT_DIRECTION_BW;
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
                if (actAction>=0){
                  rectifiedActAction=(t_pwm)actAction;
                } else {
                  rectifiedActAction=(t_pwm)(-actAction);
                }
                /* ['<global>::setActuationModule' end] */
                /* ['<global>::setActuationFw' begin] */
                actDirection=CFG_ACT_DIRECTION_FW;
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
                if (actAction>=0){
                  rectifiedActAction=(t_pwm)actAction;
                } else {
                  rectifiedActAction=(t_pwm)(-actAction);
                }
                /* ['<global>::setActuationModule' end] */
                /* ['<global>::setActuationBw' begin] */
                actDirection=CFG_ACT_DIRECTION_BW;
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
                if (actAction>=0){
                  rectifiedActAction=(t_pwm)actAction;
                } else {
                  rectifiedActAction=(t_pwm)(-actAction);
                }
                /* ['<global>::setActuationModule' end] */
                /* ['<global>::setActuationFw' begin] */
                actDirection=CFG_ACT_DIRECTION_FW;
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
                rectifiedActAction=(t_pwm)0;
                actDirection=CFG_ACT_DIRECTION_QUIET;
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
                if (actAction>=0){
                  rectifiedActAction=(t_pwm)actAction;
                } else {
                  rectifiedActAction=(t_pwm)(-actAction);
                }
                /* ['<global>::setActuationModule' end] */
                /* ['<global>::setActuationFw' begin] */
                actDirection=CFG_ACT_DIRECTION_FW;
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
                rectifiedActAction=(t_pwm)0;
                actDirection=CFG_ACT_DIRECTION_QUIET;
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
            synthesize_pwmActAction((t_pwm)0);
            /* ['<global>::stopActuation' end] */
            /* ['<global>::applyDirection' begin] */
            appliedActDirection=actDirection;
            /* ['<global>::applyDirection' end] */
            /* ['<global>::resetActDriverTimer' begin] */
            actDrvTimer=0L;
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
                actDrvTimer=0L;
                /* ['<global>::resetActDriverTimer' end] */
                state = ID_ACTDRIVING_WORK;
            }
            else if( appliedActDirection!=actDirection )
            {
                /* Transition ID: ID_ACTDRIVING_DIRCHANGEDURINGSTAB */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                synthesize_pwmActAction((t_pwm)0);
                /* ['<global>::stopActuation' end] */
                /* ['<global>::applyDirection' begin] */
                appliedActDirection=actDirection;
                /* ['<global>::applyDirection' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer=0L;
                /* ['<global>::resetActDriverTimer' end] */
            }
            else
            {
                /* Transition ID: ID_ACTDRIVING_STABLOOP */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                synthesize_pwmActAction((t_pwm)0);
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
                synthesize_pwmActAction((t_pwm)0);
                /* ['<global>::stopActuation' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer=0L;
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
                synthesize_pwmActAction((t_pwm)0);
                /* ['<global>::stopActuation' end] */
                /* ['<global>::applyDirection' begin] */
                appliedActDirection=actDirection;
                /* ['<global>::applyDirection' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer=0L;
                /* ['<global>::resetActDriverTimer' end] */
                state = ID_ACTDRIVING_STABILIZE;
            }
            else
            {
                /* Transition ID: ID_ACTDRIVING_DISSIPATELOOP */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                synthesize_pwmActAction((t_pwm)0);
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
            rectifiedActAction=(t_pwm)0;
            actDirection=CFG_ACT_DIRECTION_QUIET;
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
                rectifiedActAction=(t_pwm)0;
                actDirection=CFG_ACT_DIRECTION_QUIET;
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
            upButTimer=0L;
            /* ['<global>::resetUpButTimer' end] */
            /* ['<global>::clearUpButton' begin] */
            upReqAcq=FALSE;
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
                upButTimer=0L;
                /* ['<global>::resetUpButTimer' end] */
                /* ['<global>::setUpButton' begin] */
                upReqAcq=TRUE;
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
                upButTimer=0L;
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
                upButTimer=0L;
                /* ['<global>::resetUpButTimer' end] */
                /* ['<global>::clearUpButton' begin] */
                upReqAcq=FALSE;
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
                upButTimer=0L;
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
            downButTimer=0L;
            /* ['<global>::resetDownButTimer' end] */
            /* ['<global>::setDownButton' begin] */
            downReqAcq=TRUE;
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
                downButTimer=0L;
                /* ['<global>::resetDownButTimer' end] */
                /* ['<global>::setDownButton' begin] */
                downReqAcq=TRUE;
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
                downButTimer=0L;
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
                downButTimer=0L;
                /* ['<global>::resetDownButTimer' end] */
                /* ['<global>::clearDownButton' begin] */
                downReqAcq=FALSE;
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
                downButTimer=0L;
                /* ['<global>::resetDownButTimer' end] */
            }
            break;
        }
    }
}
/* ['DownButAcq' end (DON'T REMOVE THIS LINE!)] */
