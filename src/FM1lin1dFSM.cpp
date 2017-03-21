/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "FM1lin1dFSM.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

#include "FM1DRE.h"

extern t_dreFM1 dreFM1;

#define upReqAcq (dreFM1.upReqAcq)
#define downReqAcq (dreFM1.downReqAcq)
#define upReqDI (dreFM1.upReqDI)
#define downReqDI (dreFM1.downReqDI)
#define posMode (dreFM1.posMode)
#define actAction (dreFM1.actAction)
#define pwmActAction (dreFM1.pwmActAction)
#define doDirFw (dreFM1.doDirFw)
#define doDirBw (dreFM1.doDirBw)
#define actEnable (dreFM1.actEnable)
#define actDirection (dreFM1.actDirection)
#define appliedActAction (dreFM1.appliedActAction)
#define loadPosAcq (dreFM1.loadPosAcq)
#define appliedActDirection (dreFM1.appliedActDirection)
#define actDrvTimer (dreFM1.actDrvTimer)
#define loadPosAI (dreFM1.loadPosAI)
#define upButTimer (dreFM1.upButTimer)
#define downButTimer (dreFM1.downButTimer)
#define loadPosUpSwchDI (dreFM1.loadPosUpSwchDI)
#define loadPosDownSwchDI (dreFM1.loadPosDownSwchDI)
#define posAchieved (dreFM1.posAchieved)
#define ctrlError (dreFM1.ctrlError)
#define driveCurrentAI (dreFM1.driveCurrentAI)
#define driveCurrentAcq (dreFM1.driveCurrentAcq)
#define currentError (dreFM1.currentError)
#define brokenChainError (dreFM1.brokenChainError)
#define stuckActError (dreFM1.stuckActError)
#define loadPosUpSwchAcq (dreFM1.loadPosUpSwchAcq)
#define loadPosDownSwchAcq (dreFM1.loadPosDownSwchAcq)
#define upSwitchTimer (dreFM1.upSwitchTimer)
#define downSwitchTimer (dreFM1.downSwitchTimer)
#define hmibuttons (dreFM1.hmibuttons)
#define hmileds (dreFM1.hmileds)
#define hmidigits (dreFM1.hmidigits)
#define rectifiedActAction (dreFM1.rectifiedActAction)

/* ['FM1downSwitchAcq' begin (DON'T REMOVE THIS LINE!)] */
void FM1downSwitchAcq() {
    /* set initial state */
    static STATE_T state = ID_FM1DOWNSWITCHACQ_INIT;

    switch (state) {
            /* State ID: ID_FM1DOWNSWITCHACQ_INIT */
        case ID_FM1DOWNSWITCHACQ_INIT:
        {
            /* Transition ID: ID_FM1DOWNSWITCHACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetDownSwitchTimer' begin] */
            downSwitchTimer = 0L;
            /* ['<global>::resetDownSwitchTimer' end] */
            /* ['<global>::clearDownSwitch' begin] */
            loadPosDownSwchAcq = FALSE;
            /* ['<global>::clearDownSwitch' end] */
            state = ID_FM1DOWNSWITCHACQ_NOTDETECTED;
            break;
        }
            /* State ID: ID_FM1DOWNSWITCHACQ_NOTDETECTED */
        case ID_FM1DOWNSWITCHACQ_NOTDETECTED:
        {
            if ((loadPosDownSwchDI == TRUE) && (downSwitchTimer > CFG_FM1_DOWN_SWITCH_DETECT_TIMER)) {
                /* Transition ID: ID_FM1DOWNSWITCHACQ_DETECT */
                /* Actions: */
                /* ['<global>::resetDownSwitchTimer' begin] */
                downSwitchTimer = 0L;
                /* ['<global>::resetDownSwitchTimer' end] */
                /* ['<global>::setDownSwitch' begin] */
                loadPosDownSwchAcq = TRUE;
                /* ['<global>::setDownSwitch' end] */
                state = ID_FM1DOWNSWITCHACQ_DETECTED;
            } else if ((loadPosDownSwchDI == TRUE)) {
                /* Transition ID: ID_FM1DOWNSWITCHACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementDownSwitchTimer' begin] */
                downSwitchTimer++;
                /* ['<global>::incrementDownSwitchTimer' end] */
            } else if ((loadPosDownSwchDI == FALSE)) {
                /* Transition ID: ID_FM1DOWNSWITCHACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetDownSwitchTimer' begin] */
                downSwitchTimer = 0L;
                /* ['<global>::resetDownSwitchTimer' end] */
            }
            break;
        }
            /* State ID: ID_FM1DOWNSWITCHACQ_DETECTED */
        case ID_FM1DOWNSWITCHACQ_DETECTED:
        {
            if ((loadPosDownSwchDI == FALSE) && (downSwitchTimer > CFG_FM1_DOWN_SWITCH_DETECT_TIMER)) {
                /* Transition ID: ID_FM1DOWNSWITCHACQ_UNDETECT */
                /* Actions: */
                /* ['<global>::resetDownSwitchTimer' begin] */
                downSwitchTimer = 0L;
                /* ['<global>::resetDownSwitchTimer' end] */
                /* ['<global>::clearDownSwitch' begin] */
                loadPosDownSwchAcq = FALSE;
                /* ['<global>::clearDownSwitch' end] */
                state = ID_FM1DOWNSWITCHACQ_NOTDETECTED;
            } else if ((loadPosDownSwchDI == FALSE)) {
                /* Transition ID: ID_FM1DOWNSWITCHACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementDownSwitchTimer' begin] */
                downSwitchTimer++;
                /* ['<global>::incrementDownSwitchTimer' end] */
            } else if ((loadPosDownSwchDI == TRUE)) {
                /* Transition ID: ID_FM1DOWNSWITCHACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetDownSwitchTimer' begin] */
                downSwitchTimer = 0L;
                /* ['<global>::resetDownSwitchTimer' end] */
            }
            break;
        }
    }
}
/* ['FM1downSwitchAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1upSwitchAcq' begin (DON'T REMOVE THIS LINE!)] */
void FM1upSwitchAcq() {
    /* set initial state */
    static STATE_T state = ID_FM1UPSWITCHACQ_INIT;

    switch (state) {
            /* State ID: ID_FM1UPSWITCHACQ_INIT */
        case ID_FM1UPSWITCHACQ_INIT:
        {
            /* Transition ID: ID_FM1UPSWITCHACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetUpSwitchTimer' begin] */
            upSwitchTimer = 0L;
            /* ['<global>::resetUpSwitchTimer' end] */
            /* ['<global>::clearUpSwitch' begin] */
            loadPosUpSwchAcq = FALSE;
            /* ['<global>::clearUpSwitch' end] */
            state = ID_FM1UPSWITCHACQ_NOTDETECTED;
            break;
        }
            /* State ID: ID_FM1UPSWITCHACQ_NOTDETECTED */
        case ID_FM1UPSWITCHACQ_NOTDETECTED:
        {
            if ((loadPosUpSwchDI == TRUE) && (upSwitchTimer > CFG_FM1_UP_SWITCH_DETECT_TIMER)) {
                /* Transition ID: ID_FM1UPSWITCHACQ_DETECT */
                /* Actions: */
                /* ['<global>::resetUpSwitchTimer' begin] */
                upSwitchTimer = 0L;
                /* ['<global>::resetUpSwitchTimer' end] */
                /* ['<global>::setUpSwitch' begin] */
                loadPosUpSwchAcq = TRUE;
                /* ['<global>::setUpSwitch' end] */
                state = ID_FM1UPSWITCHACQ_DETECTED;
            } else if ((loadPosUpSwchDI == TRUE)) {
                /* Transition ID: ID_FM1UPSWITCHACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpSwitchTimer' begin] */
                upSwitchTimer++;
                /* ['<global>::incrementUpSwitchTimer' end] */
            } else if ((loadPosUpSwchDI == FALSE)) {
                /* Transition ID: ID_FM1UPSWITCHACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpSwitchTimer' begin] */
                upSwitchTimer = 0L;
                /* ['<global>::resetUpSwitchTimer' end] */
            }
            break;
        }
            /* State ID: ID_FM1UPSWITCHACQ_DETECTED */
        case ID_FM1UPSWITCHACQ_DETECTED:
        {
            if ((loadPosUpSwchDI == FALSE) && (upSwitchTimer > CFG_FM1_UP_SWITCH_DETECT_TIMER)) {
                /* Transition ID: ID_FM1UPSWITCHACQ_UNDETECT */
                /* Actions: */
                /* ['<global>::resetUpSwitchTimer' begin] */
                upSwitchTimer = 0L;
                /* ['<global>::resetUpSwitchTimer' end] */
                /* ['<global>::clearUpSwitch' begin] */
                loadPosUpSwchAcq = FALSE;
                /* ['<global>::clearUpSwitch' end] */
                state = ID_FM1UPSWITCHACQ_NOTDETECTED;
            } else if ((loadPosUpSwchDI == FALSE)) {
                /* Transition ID: ID_FM1UPSWITCHACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpSwitchTimer' begin] */
                upSwitchTimer++;
                /* ['<global>::incrementUpSwitchTimer' end] */
            } else if ((loadPosUpSwchDI == TRUE)) {
                /* Transition ID: ID_FM1UPSWITCHACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpSwitchTimer' begin] */
                upSwitchTimer = 0L;
                /* ['<global>::resetUpSwitchTimer' end] */
            }
            break;
        }
    }
}
/* ['FM1upSwitchAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1ActRectifier' begin (DON'T REMOVE THIS LINE!)] */
void FM1ActRectifier() {
    /* set initial state */
    static STATE_T state = ID_FM1ACTRECTIFIER_INIT;

    switch (state) {
            /* State ID: ID_FM1ACTRECTIFIER_INIT */
        case ID_FM1ACTRECTIFIER_INIT:
        {
            /* Transition ID: ID_FM1ACTRECTIFIER_FROMINITTOQUIET */
            /* Actions: */
            /* ['<global>::setActuationQuiet' begin] */
            rectifiedActAction = (t_pwm) 0;
            actDirection = CFG_ACT_DIRECTION_QUIET;
            /* ['<global>::setActuationQuiet' end] */
            /* ['<global>::execActDriving' begin] */
            FM1ActDriving();
            /* ['<global>::execActDriving' end] */
            state = ID_FM1ACTRECTIFIER_QUIET;
            break;
        }
            /* State ID: ID_FM1ACTRECTIFIER_QUIET */
        case ID_FM1ACTRECTIFIER_QUIET:
        {
            if (actAction < 0) {
                /* Transition ID: ID_FM1ACTRECTIFIER_FROMQUIETTOBW */
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
                FM1ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_FM1ACTRECTIFIER_BW;
            } else if (actAction > 0) {
                /* Transition ID: ID_FM1ACTRECTIFIER_FROMQUIETTOFW */
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
                FM1ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_FM1ACTRECTIFIER_FW;
            }
            break;
        }
            /* State ID: ID_FM1ACTRECTIFIER_BW */
        case ID_FM1ACTRECTIFIER_BW:
        {
            if (actAction == 0) {
                /* Transition ID: ID_FM1ACTRECTIFIER_FROMBWTOQUIET */
                /* Actions: */
                /* ['<global>::setActuationQuiet' begin] */
                rectifiedActAction = (t_pwm) 0;
                actDirection = CFG_ACT_DIRECTION_QUIET;
                /* ['<global>::setActuationQuiet' end] */
                /* ['<global>::execActDriving' begin] */
                FM1ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_FM1ACTRECTIFIER_QUIET;
            } else if (actAction > 0) {
                /* Transition ID: ID_FM1ACTRECTIFIER_FROMBWTOFW */
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
                FM1ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_FM1ACTRECTIFIER_FW;
            } else if (actAction < 0) {
                /* Transition ID: ID_FM1ACTRECTIFIER_BWLOOP */
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
                FM1ActDriving();
                /* ['<global>::execActDriving' end] */
            }
            break;
        }
            /* State ID: ID_FM1ACTRECTIFIER_FW */
        case ID_FM1ACTRECTIFIER_FW:
        {
            if (actAction == 0) {
                /* Transition ID: ID_FM1ACTRECTIFIER_FROMFWTOQUIET */
                /* Actions: */
                /* ['<global>::setActuationQuiet' begin] */
                rectifiedActAction = (t_pwm) 0;
                actDirection = CFG_ACT_DIRECTION_QUIET;
                /* ['<global>::setActuationQuiet' end] */
                /* ['<global>::execActDriving' begin] */
                FM1ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_FM1ACTRECTIFIER_QUIET;
            } else if (actAction < 0) {
                /* Transition ID: ID_FM1ACTRECTIFIER_FROMFWTOBW */
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
                FM1ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_FM1ACTRECTIFIER_BW;
            } else if (actAction > 0) {
                /* Transition ID: ID_FM1ACTRECTIFIER_FWLOOP */
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
                FM1ActDriving();
                /* ['<global>::execActDriving' end] */
            }
            break;
        }
    }
}
/* ['FM1ActRectifier' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1ActDriving' begin (DON'T REMOVE THIS LINE!)] */
void FM1ActDriving() {
    /* set initial state */
    static STATE_T state = ID_FM1ACTDRIVING_INIT;

    switch (state) {
            /* State ID: ID_FM1ACTDRIVING_INIT */
        case ID_FM1ACTDRIVING_INIT:
        {
            /* Transition ID: ID_FM1ACTDRIVING_TODISSIPATE */
            /* Actions: */
            /* ['<global>::stopActuation' begin] */
            appliedActAction = 0;
            /* ['<global>::stopActuation' end] */
            /* ['<global>::applyDirection' begin] */
            appliedActDirection = actDirection;
            /* ['<global>::applyDirection' end] */
            /* ['<global>::resetActDriverTimer' begin] */
            actDrvTimer = 0L;
            /* ['<global>::resetActDriverTimer' end] */
            state = ID_FM1ACTDRIVING_DISSIPATE;
            break;
        }
            /* State ID: ID_FM1ACTDRIVING_DISSIPATE */
        case ID_FM1ACTDRIVING_DISSIPATE:
        {
            if (actDrvTimer >= CFG_FM1_ACT_DRIVER_DISSIP_TIME) {
                /* Transition ID: ID_FM1ACTDRIVING_ENDDISSIPATE */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                appliedActAction = 0;
                /* ['<global>::stopActuation' end] */
                /* ['<global>::applyDirection' begin] */
                appliedActDirection = actDirection;
                /* ['<global>::applyDirection' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer = 0L;
                /* ['<global>::resetActDriverTimer' end] */
                state = ID_FM1ACTDRIVING_STABILIZE;
            } else {
                /* Transition ID: ID_FM1ACTDRIVING_DISSIPATELOOP */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                appliedActAction = 0;
                /* ['<global>::stopActuation' end] */
                /* ['<global>::incrementActDriverDissipTimer' begin] */
                if (actDrvTimer < CFG_FM1_ACT_DRIVER_DISSIP_TIME) {
                    actDrvTimer++;
                }
                /* ['<global>::incrementActDriverDissipTimer' end] */
            }
            break;
        }
            /* State ID: ID_FM1ACTDRIVING_STABILIZE */
        case ID_FM1ACTDRIVING_STABILIZE:
        {
            if (appliedActDirection != actDirection) {
                /* Transition ID: ID_FM1ACTDRIVING_DIRCHANGEDURINGSTAB */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                appliedActAction = 0;
                /* ['<global>::stopActuation' end] */
                /* ['<global>::applyDirection' begin] */
                appliedActDirection = actDirection;
                /* ['<global>::applyDirection' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer = 0L;
                /* ['<global>::resetActDriverTimer' end] */
            } else if ((actDirection != CFG_ACT_DIRECTION_QUIET) && (actDrvTimer >= CFG_FM1_ACT_DRIVER_STAB_TIME)) {
                /* Transition ID: ID_FM1ACTDRIVING_FROMSTABTOWORK */
                /* Actions: */
                /* ['<global>::applyActuation' begin] */
                appliedActAction = rectifiedActAction;
                /* ['<global>::applyActuation' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer = 0L;
                /* ['<global>::resetActDriverTimer' end] */
                state = ID_FM1ACTDRIVING_WORK;
            } else if (actDirection != CFG_ACT_DIRECTION_QUIET
                    ) {
                /* Transition ID: ID_FM1ACTDRIVING_STABLOOP */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                appliedActAction = 0;
                /* ['<global>::stopActuation' end] */
                /* ['<global>::incrementActDriverStabTimer' begin] */
                if (actDrvTimer < CFG_FM1_ACT_DRIVER_STAB_TIME) {
                    actDrvTimer++;
                }
                /* ['<global>::incrementActDriverStabTimer' end] */
            }
            break;
        }
            /* State ID: ID_FM1ACTDRIVING_WORK */
        case ID_FM1ACTDRIVING_WORK:
        {
            if (appliedActDirection != actDirection) {
                /* Transition ID: ID_FM1ACTDRIVING_TODISSIPATE */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                appliedActAction = 0;
                /* ['<global>::stopActuation' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer = 0L;
                /* ['<global>::resetActDriverTimer' end] */
                state = ID_FM1ACTDRIVING_DISSIPATE;
            }
            break;
        }
    }
}
/* ['FM1ActDriving' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1ActEnabler' begin (DON'T REMOVE THIS LINE!)] */
void FM1ActEnabler() {
    /* set initial state */
    static STATE_T state = ID_FM1ACTENABLER_INIT;

    switch (state) {
            /* State ID: ID_FM1ACTENABLER_INIT */
        case ID_FM1ACTENABLER_INIT:
        {
            /* Transition ID: ID_FM1ACTENABLER_FROMINITTODISABLE */
            /* Actions: */
            /* ['<global>::setActuationQuiet' begin] */
            rectifiedActAction = (t_pwm) 0;
            actDirection = CFG_ACT_DIRECTION_QUIET;
            /* ['<global>::setActuationQuiet' end] */
            /* ['<global>::execActDriving' begin] */
            FM1ActDriving();
            /* ['<global>::execActDriving' end] */
            state = ID_FM1ACTENABLER_DISABLED;
            break;
        }
            /* State ID: ID_FM1ACTENABLER_DISABLED */
        case ID_FM1ACTENABLER_DISABLED:
        {
            if (actEnable == TRUE) {
                /* Transition ID: ID_FM1ACTENABLER_TOENABLE */
                /* Actions: */
                /* ['<global>::execActRectifier' begin] */
                FM1ActRectifier();
                /* ['<global>::execActRectifier' end] */
                state = ID_FM1ACTENABLER_ENABLED;
            }
            break;
        }
            /* State ID: ID_FM1ACTENABLER_ENABLED */
        case ID_FM1ACTENABLER_ENABLED:
        {
            if (actEnable == FALSE) {
                /* Transition ID: ID_FM1ACTENABLER_TODISABLE */
                /* Actions: */
                /* ['<global>::setActuationQuiet' begin] */
                rectifiedActAction = (t_pwm) 0;
                actDirection = CFG_ACT_DIRECTION_QUIET;
                /* ['<global>::setActuationQuiet' end] */
                /* ['<global>::execActDriving' begin] */
                FM1ActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_FM1ACTENABLER_DISABLED;
            } else {
                /* Transition ID: ID_FM1ACTENABLER_LOOP */
                /* Actions: */
                /* ['<global>::execActRectifier' begin] */
                FM1ActRectifier();
                /* ['<global>::execActRectifier' end] */
            }
            break;
        }
    }
}
/* ['FM1ActEnabler' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1PosControl' begin (DON'T REMOVE THIS LINE!)] */
void FM1PosControl() {
    /* set initial state */
    static STATE_T state = ID_FM1POSCONTROL_INIT;

    switch (state) {
            /* State ID: ID_FM1POSCONTROL_INIT */
        case ID_FM1POSCONTROL_INIT:
        {
            /* Transition ID: ID_FM1POSCONTROL_INITIAL */
            /* Actions: */
            /* ['<global>::stopAction' begin] */
            actAction = CFG_ACT_ACTION_STOP;
            /* ['<global>::stopAction' end] */
            /* ['<global>::cleanError' begin] */
            ctrlError = FALSE;
            /* ['<global>::cleanError' end] */
            state = ID_FM1POSCONTROL_STOP;
            break;
        }
            /* State ID: ID_FM1POSCONTROL_STOP */
        case ID_FM1POSCONTROL_STOP:
        {
            if ((posMode == CFG_POS_MODE_UP) && (loadPosUpSwchAcq == FALSE) && (ctrlError == FALSE)) {
                /* Transition ID: ID_FM1POSCONTROL_TOUP */
                /* Actions: */
                /* ['<global>::upAction' begin] */
                actAction = CFG_ACT_ACTION_UP;
                posAchieved = FALSE;
                /* ['<global>::upAction' end] */
                state = ID_FM1POSCONTROL_GOINGUP;
            } else if (((loadPosDownSwchAcq == FALSE) && (posMode == CFG_POS_MODE_DOWN)) && (ctrlError == FALSE)) {
                /* Transition ID: ID_FM1POSCONTROL_TODOWN */
                /* Actions: */
                /* ['<global>::downAction' begin] */
                actAction = CFG_ACT_ACTION_DOWN;
                posAchieved = FALSE;
                /* ['<global>::downAction' end] */
                state = ID_FM1POSCONTROL_GOINGDOWN;
            }
            break;
        }
            /* State ID: ID_FM1POSCONTROL_GOINGUP */
        case ID_FM1POSCONTROL_GOINGUP:
        {
            if ((currentError == TRUE) || (brokenChainError == TRUE) || (stuckActError == TRUE)) {
                /* Transition ID: ID_FM1POSCONTROL_ERROR */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                /* ['<global>::setError' begin] */
                ctrlError = TRUE;
                /* ['<global>::setError' end] */
                state = ID_FM1POSCONTROL_STOP;
            } else if (posMode != CFG_POS_MODE_UP) {
                /* Transition ID: ID_FM1POSCONTROL_CANCEL */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                state = ID_FM1POSCONTROL_STOP;
            } else if (loadPosUpSwchAcq == TRUE) {
                /* Transition ID: ID_FM1POSCONTROL_FINISHED */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                /* ['<global>::notifyAchieved' begin] */
                posAchieved = TRUE;
                /* ['<global>::notifyAchieved' end] */
                state = ID_FM1POSCONTROL_STOP;
            }
            break;
        }
            /* State ID: ID_FM1POSCONTROL_GOINGDOWN */
        case ID_FM1POSCONTROL_GOINGDOWN:
        {
            if ((currentError == TRUE) || (brokenChainError == TRUE) || (stuckActError == TRUE)) {
                /* Transition ID: ID_FM1POSCONTROL_ERROR */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                /* ['<global>::setError' begin] */
                ctrlError = TRUE;
                /* ['<global>::setError' end] */
                state = ID_FM1POSCONTROL_STOP;
            } else if (posMode != CFG_POS_MODE_DOWN) {
                /* Transition ID: ID_FM1POSCONTROL_CANCEL */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                state = ID_FM1POSCONTROL_STOP;
            } else if (loadPosDownSwchAcq == TRUE) {
                /* Transition ID: ID_FM1POSCONTROL_FINISHED */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                /* ['<global>::notifyAchieved' begin] */
                posAchieved = TRUE;
                /* ['<global>::notifyAchieved' end] */
                state = ID_FM1POSCONTROL_STOP;
            }
            break;
        }
    }
}
/* ['FM1PosControl' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1ModeSelector' begin (DON'T REMOVE THIS LINE!)] */
void FM1ModeSelector() {
    /* set initial state */
    static STATE_T state = ID_FM1MODESELECTOR_INIT;

    switch (state) {
            /* State ID: ID_FM1MODESELECTOR_INIT */
        case ID_FM1MODESELECTOR_INIT:
        {
            /* Transition ID: ID_FM1MODESELECTOR_INITIAL */
            /* Actions: */
            /* ['<global>::setStopMode' begin] */
            posMode = CFG_POS_MODE_STOP;
            /* ['<global>::setStopMode' end] */
            state = ID_FM1MODESELECTOR_STOP;
            break;
        }
            /* State ID: ID_FM1MODESELECTOR_STOP */
        case ID_FM1MODESELECTOR_STOP:
        {
            if (upReqAcq == TRUE && downReqAcq == FALSE) {
                /* Transition ID: ID_FM1MODESELECTOR_TOUP */
                /* Actions: */
                /* ['<global>::setUpMode' begin] */
                posMode = CFG_POS_MODE_UP;
                /* ['<global>::setUpMode' end] */
                state = ID_FM1MODESELECTOR_UP;
            } else if (downReqAcq == TRUE) {
                /* Transition ID: ID_FM1MODESELECTOR_TODOWN */
                /* Actions: */
                /* ['<global>::setDownMode' begin] */
                posMode = CFG_POS_MODE_DOWN;
                /* ['<global>::setDownMode' end] */
                state = ID_FM1MODESELECTOR_DOWN;
            }
            break;
        }
            /* State ID: ID_FM1MODESELECTOR_UP */
        case ID_FM1MODESELECTOR_UP:
        {
            if ((downReqAcq == TRUE) || (ctrlError == TRUE) || (posAchieved == TRUE)) {
                /* Transition ID: ID_FM1MODESELECTOR_OPTIMIZED_TRANSITION_1 */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_FM1MODESELECTOR_STOPWAIT;
            }
            break;
        }
            /* State ID: ID_FM1MODESELECTOR_STOPWAIT */
        case ID_FM1MODESELECTOR_STOPWAIT:
        {
            if ((downReqAcq == FALSE && upReqAcq == FALSE)) {
                /* Transition ID: ID_FM1MODESELECTOR_RELEASE */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_FM1MODESELECTOR_STOP;
            }
            break;
        }
            /* State ID: ID_FM1MODESELECTOR_DOWN */
        case ID_FM1MODESELECTOR_DOWN:
        {
            if ((upReqAcq == TRUE && downReqAcq == FALSE) || (ctrlError == TRUE) || (posAchieved == TRUE)) {
                /* Transition ID: ID_FM1MODESELECTOR_OPTIMIZED_TRANSITION_1 */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_FM1MODESELECTOR_STOPWAIT;
            }
            break;
        }
    }
}
/* ['FM1ModeSelector' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1UpButAcq' begin (DON'T REMOVE THIS LINE!)] */
void FM1UpButAcq() {
    /* set initial state */
    static STATE_T state = ID_FM1UPBUTACQ_INIT;

    switch (state) {
            /* State ID: ID_FM1UPBUTACQ_INIT */
        case ID_FM1UPBUTACQ_INIT:
        {
            /* Transition ID: ID_FM1UPBUTACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetUpButTimer' begin] */
            upButTimer = 0L;
            /* ['<global>::resetUpButTimer' end] */
            /* ['<global>::clearUpButton' begin] */
            upReqAcq = FALSE;
            /* ['<global>::clearUpButton' end] */
            state = ID_FM1UPBUTACQ_NOTPRESSED;
            break;
        }
            /* State ID: ID_FM1UPBUTACQ_NOTPRESSED */
        case ID_FM1UPBUTACQ_NOTPRESSED:
        {
            if (((upReqDI == TRUE) || (hmibuttons & CFG_FM1_BUTACQ_HMI_UP_MASK)) && (upButTimer > CFG_FM1_UP_BUT_PRESS_TIMER)) {
                /* Transition ID: ID_FM1UPBUTACQ_PRESS */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
                /* ['<global>::setUpButton' begin] */
                upReqAcq = TRUE;
                /* ['<global>::setUpButton' end] */
                state = ID_FM1UPBUTACQ_PRESSED;
            } else if (((upReqDI == TRUE) || (hmibuttons & CFG_FM1_BUTACQ_HMI_UP_MASK))) {
                /* Transition ID: ID_FM1UPBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpButTimer' begin] */
                upButTimer++;
                /* ['<global>::incrementUpButTimer' end] */
            } else if (((upReqDI == FALSE) && !(hmibuttons & CFG_FM1_BUTACQ_HMI_UP_MASK))) {
                /* Transition ID: ID_FM1UPBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
            }
            break;
        }
            /* State ID: ID_FM1UPBUTACQ_PRESSED */
        case ID_FM1UPBUTACQ_PRESSED:
        {
            if (((upReqDI == FALSE) && !(hmibuttons & CFG_FM1_BUTACQ_HMI_UP_MASK)) && (upButTimer > CFG_FM1_UP_BUT_UNPRESS_TIMER)
                    ) {
                /* Transition ID: ID_FM1UPBUTACQ_UNPRESS */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
                /* ['<global>::clearUpButton' begin] */
                upReqAcq = FALSE;
                /* ['<global>::clearUpButton' end] */
                state = ID_FM1UPBUTACQ_NOTPRESSED;
            } else if (((upReqDI == FALSE) && !(hmibuttons & CFG_FM1_BUTACQ_HMI_UP_MASK))) {
                /* Transition ID: ID_FM1UPBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpButTimer' begin] */
                upButTimer++;
                /* ['<global>::incrementUpButTimer' end] */
            } else if (((upReqDI == TRUE) || (hmibuttons & CFG_FM1_BUTACQ_HMI_UP_MASK))) {
                /* Transition ID: ID_FM1UPBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
            }
            break;
        }
    }
}
/* ['FM1UpButAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1DownButAcq' begin (DON'T REMOVE THIS LINE!)] */
void FM1DownButAcq() {
    /* set initial state */
    static STATE_T state = ID_FM1DOWNBUTACQ_INIT;

    switch (state) {
            /* State ID: ID_FM1DOWNBUTACQ_INIT */
        case ID_FM1DOWNBUTACQ_INIT:
        {
            /* Transition ID: ID_FM1DOWNBUTACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetDownButTimer' begin] */
            downButTimer = 0L;
            /* ['<global>::resetDownButTimer' end] */
            /* ['<global>::clearDownButton' begin] */
            downReqAcq = FALSE;
            /* ['<global>::clearDownButton' end] */
            state = ID_FM1DOWNBUTACQ_NOTPRESSED;
            break;
        }
            /* State ID: ID_FM1DOWNBUTACQ_NOTPRESSED */
        case ID_FM1DOWNBUTACQ_NOTPRESSED:
        {
            if (((downReqDI == TRUE) || (hmibuttons & CFG_FM1_BUTACQ_HMI_DOWN_MASK)) && (downButTimer > CFG_FM1_DWN_BUT_PRESS_TIMER)) {
                /* Transition ID: ID_FM1DOWNBUTACQ_PRESS */
                /* Actions: */
                /* ['<global>::resetDownButTimer' begin] */
                downButTimer = 0L;
                /* ['<global>::resetDownButTimer' end] */
                /* ['<global>::setDownButton' begin] */
                downReqAcq = TRUE;
                /* ['<global>::setDownButton' end] */
                state = ID_FM1DOWNBUTACQ_PRESSED;
            } else if (((downReqDI == TRUE) || (hmibuttons & CFG_FM1_BUTACQ_HMI_DOWN_MASK))) {
                /* Transition ID: ID_FM1DOWNBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementDownButTimer' begin] */
                downButTimer++;
                /* ['<global>::incrementDownButTimer' end] */
            } else if (((downReqDI == FALSE) && !(hmibuttons & CFG_FM1_BUTACQ_HMI_DOWN_MASK)) && (downButTimer > CFG_FM1_DWN_BUT_UNPRESS_TIMER)) {
                /* Transition ID: ID_FM1DOWNBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetDownButTimer' begin] */
                downButTimer = 0L;
                /* ['<global>::resetDownButTimer' end] */
            }
            break;
        }
            /* State ID: ID_FM1DOWNBUTACQ_PRESSED */
        case ID_FM1DOWNBUTACQ_PRESSED:
        {
            if (((downReqDI == FALSE) && !(hmibuttons & CFG_FM1_BUTACQ_HMI_DOWN_MASK)) && (downButTimer > CFG_FM1_DWN_BUT_UNPRESS_TIMER)) {
                /* Transition ID: ID_FM1DOWNBUTACQ_UNPRESS */
                /* Actions: */
                /* ['<global>::resetDownButTimer' begin] */
                downButTimer = 0L;
                /* ['<global>::resetDownButTimer' end] */
                /* ['<global>::clearDownButton' begin] */
                downReqAcq = FALSE;
                /* ['<global>::clearDownButton' end] */
                state = ID_FM1DOWNBUTACQ_NOTPRESSED;
            } else if (((downReqDI == FALSE) && !(hmibuttons & CFG_FM1_BUTACQ_HMI_DOWN_MASK))) {
                /* Transition ID: ID_FM1DOWNBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementDownButTimer' begin] */
                downButTimer++;
                /* ['<global>::incrementDownButTimer' end] */
            } else if (((downReqDI == TRUE) || (hmibuttons & CFG_FM1_BUTACQ_HMI_DOWN_MASK))) {
                /* Transition ID: ID_FM1DOWNBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetDownButTimer' begin] */
                downButTimer = 0L;
                /* ['<global>::resetDownButTimer' end] */
            }
            break;
        }
    }
}
/* ['FM1DownButAcq' end (DON'T REMOVE THIS LINE!)] */
