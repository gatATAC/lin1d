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
            break;
        }
        /* State ID: ID_ACTRECTIFIER_FW */
        case ID_ACTRECTIFIER_FW:
        {
            if( actAction==0 )
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
            else if( actAction>0 )
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
