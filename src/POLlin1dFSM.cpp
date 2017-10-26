/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "POLlin1dFSM.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

#include "POLDRE.h"
#include "FM1DRE.h"       // Both subsystems (POL and FM1) share same hmi

extern t_drePOL drePOL;
extern t_dreFM1 dreFM1; // Both subsystems (POL and FM1) share same hmi

#define upReqAcq (drePOL.upReqAcq)
#define downReqAcq (drePOL.downReqAcq)
#define upReqDI (drePOL.upReqDI)
#define downReqDI (drePOL.downReqDI)
#define posMode (drePOL.posMode)
#define actAction (drePOL.actAction)
#define pwmActAction (drePOL.pwmActAction)
#define doDirFw (drePOL.doDirFw)
#define doDirBw (drePOL.doDirBw)
#define actEnable (drePOL.actEnable)
#define actDirection (drePOL.actDirection)
#define appliedActAction (drePOL.appliedActAction)
#define loadPosAcq (drePOL.loadPosAcq)
#define appliedActDirection (drePOL.appliedActDirection)
#define actDrvTimer (drePOL.actDrvTimer)
#define loadPosAI (drePOL.loadPosAI)
#define upButTimer (drePOL.upButTimer)
#define downButTimer (drePOL.downButTimer)
#define loadPosUpSwchDI (drePOL.loadPosUpSwchDI)
#define loadPosDownSwchDI (drePOL.loadPosDownSwchDI)
#define posAchieved (drePOL.posAchieved)
#define ctrlError (drePOL.ctrlError)
#define driveCurrentAI (drePOL.driveCurrentAI)
#define driveCurrentAcq (drePOL.driveCurrentAcq)
#define currentError (drePOL.currentError)
#define brokenChainError (drePOL.brokenChainError)
#define stuckActError (drePOL.stuckActError)
#define loadPosUpSwchAcq (drePOL.loadPosUpSwchAcq)
#define loadPosDownSwchAcq (drePOL.loadPosDownSwchAcq)
#define upSwitchTimer (drePOL.upSwitchTimer)
#define downSwitchTimer (drePOL.downSwitchTimer)
#define hmibuttons (dreFM1.hmibuttons)    // Both subsystems (POL and FM1) share same hmi
#define hmileds (dreFM1.hmileds)          // Both subsystems (POL and FM1) share same hmi
#define hmidigits (dreFM1.hmidigits)      // Both subsystems (POL and FM1) share same hmi
#define rectifiedActAction (drePOL.rectifiedActAction)

/* ['POLdownSwitchAcq' begin (DON'T REMOVE THIS LINE!)] */
void POLdownSwitchAcq() {
    /* set initial state */
    static STATE_T state = ID_POLDOWNSWITCHACQ_INIT;

    switch (state) {
            /* State ID: ID_POLDOWNSWITCHACQ_INIT */
        case ID_POLDOWNSWITCHACQ_INIT:
        {
            /* Transition ID: ID_POLDOWNSWITCHACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetDownSwitchTimer' begin] */
            downSwitchTimer = 0L;
            /* ['<global>::resetDownSwitchTimer' end] */
            /* ['<global>::clearDownSwitch' begin] */
            loadPosDownSwchAcq = FALSE;
            /* ['<global>::clearDownSwitch' end] */
            state = ID_POLDOWNSWITCHACQ_NOTDETECTED;
            break;
        }
            /* State ID: ID_POLDOWNSWITCHACQ_NOTDETECTED */
        case ID_POLDOWNSWITCHACQ_NOTDETECTED:
        {
            if ((loadPosDownSwchDI == TRUE) && (downSwitchTimer > CFG_POL_DOWN_SWITCH_DETECT_TIMER)) {
                /* Transition ID: ID_POLDOWNSWITCHACQ_DETECT */
                /* Actions: */
                /* ['<global>::resetDownSwitchTimer' begin] */
                downSwitchTimer = 0L;
                /* ['<global>::resetDownSwitchTimer' end] */
                /* ['<global>::setDownSwitch' begin] */
                loadPosDownSwchAcq = TRUE;
                /* ['<global>::setDownSwitch' end] */
                state = ID_POLDOWNSWITCHACQ_DETECTED;
            } else if ((loadPosDownSwchDI == TRUE)) {
                /* Transition ID: ID_POLDOWNSWITCHACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementDownSwitchTimer' begin] */
                downSwitchTimer++;
                /* ['<global>::incrementDownSwitchTimer' end] */
            } else if ((loadPosDownSwchDI == FALSE)) {
                /* Transition ID: ID_POLDOWNSWITCHACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetDownSwitchTimer' begin] */
                downSwitchTimer = 0L;
                /* ['<global>::resetDownSwitchTimer' end] */
            }
            break;
        }
            /* State ID: ID_POLDOWNSWITCHACQ_DETECTED */
        case ID_POLDOWNSWITCHACQ_DETECTED:
        {
            if ((loadPosDownSwchDI == FALSE) && (downSwitchTimer > CFG_POL_DOWN_SWITCH_DETECT_TIMER)) {
                /* Transition ID: ID_POLDOWNSWITCHACQ_UNDETECT */
                /* Actions: */
                /* ['<global>::resetDownSwitchTimer' begin] */
                downSwitchTimer = 0L;
                /* ['<global>::resetDownSwitchTimer' end] */
                /* ['<global>::clearDownSwitch' begin] */
                loadPosDownSwchAcq = FALSE;
                /* ['<global>::clearDownSwitch' end] */
                state = ID_POLDOWNSWITCHACQ_NOTDETECTED;
            } else if ((loadPosDownSwchDI == FALSE)) {
                /* Transition ID: ID_POLDOWNSWITCHACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementDownSwitchTimer' begin] */
                downSwitchTimer++;
                /* ['<global>::incrementDownSwitchTimer' end] */
            } else if ((loadPosDownSwchDI == TRUE)) {
                /* Transition ID: ID_POLDOWNSWITCHACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetDownSwitchTimer' begin] */
                downSwitchTimer = 0L;
                /* ['<global>::resetDownSwitchTimer' end] */
            }
            break;
        }
    }
}
/* ['POLdownSwitchAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['POLupSwitchAcq' begin (DON'T REMOVE THIS LINE!)] */
void POLupSwitchAcq() {
    /* set initial state */
    static STATE_T state = ID_POLUPSWITCHACQ_INIT;

    switch (state) {
            /* State ID: ID_POLUPSWITCHACQ_INIT */
        case ID_POLUPSWITCHACQ_INIT:
        {
            /* Transition ID: ID_POLUPSWITCHACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetUpSwitchTimer' begin] */
            upSwitchTimer = 0L;
            /* ['<global>::resetUpSwitchTimer' end] */
            /* ['<global>::clearUpSwitch' begin] */
            loadPosUpSwchAcq = FALSE;
            /* ['<global>::clearUpSwitch' end] */
            state = ID_POLUPSWITCHACQ_NOTDETECTED;
            break;
        }
            /* State ID: ID_POLUPSWITCHACQ_NOTDETECTED */
        case ID_POLUPSWITCHACQ_NOTDETECTED:
        {
            if ((loadPosUpSwchDI == TRUE) && (upSwitchTimer > CFG_POL_UP_SWITCH_DETECT_TIMER)) {
                /* Transition ID: ID_POLUPSWITCHACQ_DETECT */
                /* Actions: */
                /* ['<global>::resetUpSwitchTimer' begin] */
                upSwitchTimer = 0L;
                /* ['<global>::resetUpSwitchTimer' end] */
                /* ['<global>::setUpSwitch' begin] */
                loadPosUpSwchAcq = TRUE;
                /* ['<global>::setUpSwitch' end] */
                state = ID_POLUPSWITCHACQ_DETECTED;
            } else if ((loadPosUpSwchDI == TRUE)) {
                /* Transition ID: ID_POLUPSWITCHACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpSwitchTimer' begin] */
                upSwitchTimer++;
                /* ['<global>::incrementUpSwitchTimer' end] */
            } else if ((loadPosUpSwchDI == FALSE)) {
                /* Transition ID: ID_POLUPSWITCHACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpSwitchTimer' begin] */
                upSwitchTimer = 0L;
                /* ['<global>::resetUpSwitchTimer' end] */
            }
            break;
        }
            /* State ID: ID_POLUPSWITCHACQ_DETECTED */
        case ID_POLUPSWITCHACQ_DETECTED:
        {
            if ((loadPosUpSwchDI == FALSE) && (upSwitchTimer > CFG_POL_UP_SWITCH_DETECT_TIMER)) {
                /* Transition ID: ID_POLUPSWITCHACQ_UNDETECT */
                /* Actions: */
                /* ['<global>::resetUpSwitchTimer' begin] */
                upSwitchTimer = 0L;
                /* ['<global>::resetUpSwitchTimer' end] */
                /* ['<global>::clearUpSwitch' begin] */
                loadPosUpSwchAcq = FALSE;
                /* ['<global>::clearUpSwitch' end] */
                state = ID_POLUPSWITCHACQ_NOTDETECTED;
            } else if ((loadPosUpSwchDI == FALSE)) {
                /* Transition ID: ID_POLUPSWITCHACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpSwitchTimer' begin] */
                upSwitchTimer++;
                /* ['<global>::incrementUpSwitchTimer' end] */
            } else if ((loadPosUpSwchDI == TRUE)) {
                /* Transition ID: ID_POLUPSWITCHACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpSwitchTimer' begin] */
                upSwitchTimer = 0L;
                /* ['<global>::resetUpSwitchTimer' end] */
            }
            break;
        }
    }
}
/* ['POLupSwitchAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['POLActRectifier' begin (DON'T REMOVE THIS LINE!)] */
void POLActRectifier() {
    /* set initial state */
    static STATE_T state = ID_POLACTRECTIFIER_INIT;

    switch (state) {
            /* State ID: ID_POLACTRECTIFIER_INIT */
        case ID_POLACTRECTIFIER_INIT:
        {
            /* Transition ID: ID_POLACTRECTIFIER_FROMINITTOQUIET */
            /* Actions: */
            /* ['<global>::setActuationQuiet' begin] */
            rectifiedActAction = (t_pwm) 0;
            actDirection = CFG_ACT_DIRECTION_QUIET;
            /* ['<global>::setActuationQuiet' end] */
            /* ['<global>::execActDriving' begin] */
            POLActDriving();
            /* ['<global>::execActDriving' end] */
            state = ID_POLACTRECTIFIER_QUIET;
            break;
        }
            /* State ID: ID_POLACTRECTIFIER_QUIET */
        case ID_POLACTRECTIFIER_QUIET:
        {
            if (actAction < 0) {
                /* Transition ID: ID_POLACTRECTIFIER_FROMQUIETTOBW */
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
                POLActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_POLACTRECTIFIER_BW;
            } else if (actAction > 0) {
                /* Transition ID: ID_POLACTRECTIFIER_FROMQUIETTOFW */
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
                POLActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_POLACTRECTIFIER_FW;
            }
            break;
        }
            /* State ID: ID_POLACTRECTIFIER_BW */
        case ID_POLACTRECTIFIER_BW:
        {
            if (actAction == 0) {
                /* Transition ID: ID_POLACTRECTIFIER_FROMBWTOQUIET */
                /* Actions: */
                /* ['<global>::setActuationQuiet' begin] */
                rectifiedActAction = (t_pwm) 0;
                actDirection = CFG_ACT_DIRECTION_QUIET;
                /* ['<global>::setActuationQuiet' end] */
                /* ['<global>::execActDriving' begin] */
                POLActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_POLACTRECTIFIER_QUIET;
            } else if (actAction > 0) {
                /* Transition ID: ID_POLACTRECTIFIER_FROMBWTOFW */
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
                POLActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_POLACTRECTIFIER_FW;
            } else if (actAction < 0) {
                /* Transition ID: ID_POLACTRECTIFIER_BWLOOP */
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
                POLActDriving();
                /* ['<global>::execActDriving' end] */
            }
            break;
        }
            /* State ID: ID_POLACTRECTIFIER_FW */
        case ID_POLACTRECTIFIER_FW:
        {
            if (actAction == 0) {
                /* Transition ID: ID_POLACTRECTIFIER_FROMFWTOQUIET */
                /* Actions: */
                /* ['<global>::setActuationQuiet' begin] */
                rectifiedActAction = (t_pwm) 0;
                actDirection = CFG_ACT_DIRECTION_QUIET;
                /* ['<global>::setActuationQuiet' end] */
                /* ['<global>::execActDriving' begin] */
                POLActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_POLACTRECTIFIER_QUIET;
            } else if (actAction < 0) {
                /* Transition ID: ID_POLACTRECTIFIER_FROMFWTOBW */
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
                POLActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_POLACTRECTIFIER_BW;
            } else if (actAction > 0) {
                /* Transition ID: ID_POLACTRECTIFIER_FWLOOP */
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
                POLActDriving();
                /* ['<global>::execActDriving' end] */
            }
            break;
        }
    }
}
/* ['POLActRectifier' end (DON'T REMOVE THIS LINE!)] */

/* ['POLActDriving' begin (DON'T REMOVE THIS LINE!)] */
void POLActDriving() {
    /* set initial state */
    static STATE_T state = ID_POLACTDRIVING_INIT;

    switch (state) {
            /* State ID: ID_POLACTDRIVING_INIT */
        case ID_POLACTDRIVING_INIT:
        {
            /* Transition ID: ID_POLACTDRIVING_TODISSIPATE */
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
            state = ID_POLACTDRIVING_DISSIPATE;
            break;
        }
            /* State ID: ID_POLACTDRIVING_DISSIPATE */
        case ID_POLACTDRIVING_DISSIPATE:
        {
            if (actDrvTimer >= CFG_POL_ACT_DRIVER_DISSIP_TIME) {
                /* Transition ID: ID_POLACTDRIVING_ENDDISSIPATE */
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
                state = ID_POLACTDRIVING_STABILIZE;
            } else {
                /* Transition ID: ID_POLACTDRIVING_DISSIPATELOOP */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                appliedActAction = 0;
                /* ['<global>::stopActuation' end] */
                /* ['<global>::incrementActDriverDissipTimer' begin] */
                if (actDrvTimer < CFG_POL_ACT_DRIVER_DISSIP_TIME) {
                    actDrvTimer++;
                }
                /* ['<global>::incrementActDriverDissipTimer' end] */
            }
            break;
        }
            /* State ID: ID_POLACTDRIVING_STABILIZE */
        case ID_POLACTDRIVING_STABILIZE:
        {
            if (appliedActDirection != actDirection) {
                /* Transition ID: ID_POLACTDRIVING_DIRCHANGEDURINGSTAB */
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
            } else if ((actDirection != CFG_ACT_DIRECTION_QUIET) && (actDrvTimer >= CFG_POL_ACT_DRIVER_STAB_TIME)) {
                /* Transition ID: ID_POLACTDRIVING_FROMSTABTOWORK */
                /* Actions: */
                /* ['<global>::applyActuation' begin] */
                appliedActAction = rectifiedActAction;
                /* ['<global>::applyActuation' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer = 0L;
                /* ['<global>::resetActDriverTimer' end] */
                state = ID_POLACTDRIVING_WORK;
            } else if (actDirection != CFG_ACT_DIRECTION_QUIET
                    ) {
                /* Transition ID: ID_POLACTDRIVING_STABLOOP */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                appliedActAction = 0;
                /* ['<global>::stopActuation' end] */
                /* ['<global>::incrementActDriverStabTimer' begin] */
                if (actDrvTimer < CFG_POL_ACT_DRIVER_STAB_TIME) {
                    actDrvTimer++;
                }
                /* ['<global>::incrementActDriverStabTimer' end] */
            }
            break;
        }
            /* State ID: ID_POLACTDRIVING_WORK */
        case ID_POLACTDRIVING_WORK:
        {
            if (appliedActDirection != actDirection) {
                /* Transition ID: ID_POLACTDRIVING_TODISSIPATE */
                /* Actions: */
                /* ['<global>::stopActuation' begin] */
                appliedActAction = 0;
                /* ['<global>::stopActuation' end] */
                /* ['<global>::resetActDriverTimer' begin] */
                actDrvTimer = 0L;
                /* ['<global>::resetActDriverTimer' end] */
                state = ID_POLACTDRIVING_DISSIPATE;
            }
            break;
        }
    }
}
/* ['POLActDriving' end (DON'T REMOVE THIS LINE!)] */

/* ['POLActEnabler' begin (DON'T REMOVE THIS LINE!)] */
void POLActEnabler() {
    /* set initial state */
    static STATE_T state = ID_POLACTENABLER_INIT;

    switch (state) {
            /* State ID: ID_POLACTENABLER_INIT */
        case ID_POLACTENABLER_INIT:
        {
            /* Transition ID: ID_POLACTENABLER_FROMINITTODISABLE */
            /* Actions: */
            /* ['<global>::setActuationQuiet' begin] */
            rectifiedActAction = (t_pwm) 0;
            actDirection = CFG_ACT_DIRECTION_QUIET;
            /* ['<global>::setActuationQuiet' end] */
            /* ['<global>::execActDriving' begin] */
            POLActDriving();
            /* ['<global>::execActDriving' end] */
            state = ID_POLACTENABLER_DISABLED;
            break;
        }
            /* State ID: ID_POLACTENABLER_DISABLED */
        case ID_POLACTENABLER_DISABLED:
        {
            if (actEnable == TRUE) {
                /* Transition ID: ID_POLACTENABLER_TOENABLE */
                /* Actions: */
                /* ['<global>::execActRectifier' begin] */
                POLActRectifier();
                /* ['<global>::execActRectifier' end] */
                state = ID_POLACTENABLER_ENABLED;
            }
            break;
        }
            /* State ID: ID_POLACTENABLER_ENABLED */
        case ID_POLACTENABLER_ENABLED:
        {
            if (actEnable == FALSE) {
                /* Transition ID: ID_POLACTENABLER_TODISABLE */
                /* Actions: */
                /* ['<global>::setActuationQuiet' begin] */
                rectifiedActAction = (t_pwm) 0;
                actDirection = CFG_ACT_DIRECTION_QUIET;
                /* ['<global>::setActuationQuiet' end] */
                /* ['<global>::execActDriving' begin] */
                POLActDriving();
                /* ['<global>::execActDriving' end] */
                state = ID_POLACTENABLER_DISABLED;
            } else {
                /* Transition ID: ID_POLACTENABLER_LOOP */
                /* Actions: */
                /* ['<global>::execActRectifier' begin] */
                POLActRectifier();
                /* ['<global>::execActRectifier' end] */
            }
            break;
        }
    }
}
/* ['POLActEnabler' end (DON'T REMOVE THIS LINE!)] */

/* ['POLPosControl' begin (DON'T REMOVE THIS LINE!)] */
void POLPosControl() {
    /* set initial state */
    static STATE_T state = ID_POLPOSCONTROL_INIT;

    switch (state) {
            /* State ID: ID_POLPOSCONTROL_INIT */
        case ID_POLPOSCONTROL_INIT:
        {
            /* Transition ID: ID_POLPOSCONTROL_INITIAL */
            /* Actions: */
            /* ['<global>::stopAction' begin] */
            actAction = CFG_POL_ACT_ACTION_STOP;
            /* ['<global>::stopAction' end] */
            /* ['<global>::cleanError' begin] */
            ctrlError = FALSE;
            /* ['<global>::cleanError' end] */
            state = ID_POLPOSCONTROL_STOP;
            break;
        }
            /* State ID: ID_POLPOSCONTROL_STOP */
        case ID_POLPOSCONTROL_STOP:
        {
            if ((posMode == CFG_POS_MODE_UP) && (loadPosUpSwchAcq == FALSE) && (ctrlError == FALSE)) {
                /* Transition ID: ID_POLPOSCONTROL_TOUP */
                /* Actions: */
                /* ['<global>::upAction' begin] */
                actAction = CFG_POL_ACT_ACTION_UP;
                posAchieved = FALSE;
                /* ['<global>::upAction' end] */
                state = ID_POLPOSCONTROL_GOINGUP;
            } else if (((loadPosDownSwchAcq == FALSE) && (posMode == CFG_POS_MODE_DOWN)) && (ctrlError == FALSE)) {
                /* Transition ID: ID_POLPOSCONTROL_TODOWN */
                /* Actions: */
                /* ['<global>::downAction' begin] */
                actAction = CFG_POL_ACT_ACTION_DOWN;
                posAchieved = FALSE;
                /* ['<global>::downAction' end] */
                state = ID_POLPOSCONTROL_GOINGDOWN;
            }
            break;
        }
            /* State ID: ID_POLPOSCONTROL_GOINGUP */
        case ID_POLPOSCONTROL_GOINGUP:
        {
            if ((currentError == TRUE) || (brokenChainError == TRUE) || (stuckActError == TRUE)) {
                /* Transition ID: ID_POLPOSCONTROL_ERROR */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_POL_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                /* ['<global>::setError' begin] */
                ctrlError = TRUE;
                /* ['<global>::setError' end] */
                state = ID_POLPOSCONTROL_STOP;
            } else if (posMode != CFG_POS_MODE_UP) {
                /* Transition ID: ID_POLPOSCONTROL_CANCEL */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_POL_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                state = ID_POLPOSCONTROL_STOP;
            } else if (loadPosUpSwchAcq == TRUE) {
                /* Transition ID: ID_POLPOSCONTROL_FINISHED */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_POL_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                /* ['<global>::notifyAchieved' begin] */
                posAchieved = TRUE;
                /* ['<global>::notifyAchieved' end] */
                state = ID_POLPOSCONTROL_STOP;
            }
            break;
        }
            /* State ID: ID_POLPOSCONTROL_GOINGDOWN */
        case ID_POLPOSCONTROL_GOINGDOWN:
        {
            if ((currentError == TRUE) || (brokenChainError == TRUE) || (stuckActError == TRUE)) {
                /* Transition ID: ID_POLPOSCONTROL_ERROR */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_POL_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                /* ['<global>::setError' begin] */
                ctrlError = TRUE;
                /* ['<global>::setError' end] */
                state = ID_POLPOSCONTROL_STOP;
            } else if (posMode != CFG_POS_MODE_DOWN) {
                /* Transition ID: ID_POLPOSCONTROL_CANCEL */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_POL_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                state = ID_POLPOSCONTROL_STOP;
            } else if (loadPosDownSwchAcq == TRUE) {
                /* Transition ID: ID_POLPOSCONTROL_FINISHED */
                /* Actions: */
                /* ['<global>::stopAction' begin] */
                actAction = CFG_POL_ACT_ACTION_STOP;
                /* ['<global>::stopAction' end] */
                /* ['<global>::notifyAchieved' begin] */
                posAchieved = TRUE;
                /* ['<global>::notifyAchieved' end] */
                state = ID_POLPOSCONTROL_STOP;
            }
            break;
        }
    }
}
/* ['POLPosControl' end (DON'T REMOVE THIS LINE!)] */

/* ['POLModeSelector' begin (DON'T REMOVE THIS LINE!)] */
void POLModeSelector() {
    /* set initial state */
    static STATE_T state = ID_POLMODESELECTOR_INIT;

    switch (state) {
            /* State ID: ID_POLMODESELECTOR_INIT */
        case ID_POLMODESELECTOR_INIT:
        {
            /* Transition ID: ID_POLMODESELECTOR_INITIAL */
            /* Actions: */
            /* ['<global>::setStopMode' begin] */
            posMode = CFG_POS_MODE_STOP;
            /* ['<global>::setStopMode' end] */
            state = ID_POLMODESELECTOR_STOP;
            break;
        }
            /* State ID: ID_POLMODESELECTOR_STOP */
        case ID_POLMODESELECTOR_STOP:
        {
            if (upReqAcq == TRUE && downReqAcq == FALSE) {
                /* Transition ID: ID_POLMODESELECTOR_TOUP */
                /* Actions: */
                /* ['<global>::setUpMode' begin] */
                posMode = CFG_POS_MODE_UP;
                /* ['<global>::setUpMode' end] */
                state = ID_POLMODESELECTOR_UP;
            } else if (downReqAcq == TRUE) {
                /* Transition ID: ID_POLMODESELECTOR_TODOWN */
                /* Actions: */
                /* ['<global>::setDownMode' begin] */
                posMode = CFG_POS_MODE_DOWN;
                /* ['<global>::setDownMode' end] */
                state = ID_POLMODESELECTOR_DOWN;
            }
            break;
        }
            /* State ID: ID_POLMODESELECTOR_UP */
        case ID_POLMODESELECTOR_UP:
        {
            if ((downReqAcq == TRUE) || (ctrlError == TRUE) || (posAchieved == TRUE)) {
                /* Transition ID: ID_POLMODESELECTOR_OPTIMIZED_TRANSITION_1 */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_POLMODESELECTOR_STOPWAIT;
            }
            break;
        }
            /* State ID: ID_POLMODESELECTOR_STOPWAIT */
        case ID_POLMODESELECTOR_STOPWAIT:
        {
            if ((downReqAcq == FALSE && upReqAcq == FALSE)) {
                /* Transition ID: ID_POLMODESELECTOR_RELEASE */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_POLMODESELECTOR_STOP;
            }
            break;
        }
            /* State ID: ID_POLMODESELECTOR_DOWN */
        case ID_POLMODESELECTOR_DOWN:
        {
            if ((upReqAcq == TRUE && downReqAcq == FALSE) || (ctrlError == TRUE) || (posAchieved == TRUE)) {
                /* Transition ID: ID_POLMODESELECTOR_OPTIMIZED_TRANSITION_1 */
                /* Actions: */
                /* ['<global>::setStopMode' begin] */
                posMode = CFG_POS_MODE_STOP;
                /* ['<global>::setStopMode' end] */
                state = ID_POLMODESELECTOR_STOPWAIT;
            }
            break;
        }
    }
}
/* ['POLModeSelector' end (DON'T REMOVE THIS LINE!)] */

/* ['POLUpButAcq' begin (DON'T REMOVE THIS LINE!)] */
void POLUpButAcq() {
    /* set initial state */
    static STATE_T state = ID_POLUPBUTACQ_INIT;

    switch (state) {
            /* State ID: ID_POLUPBUTACQ_INIT */
        case ID_POLUPBUTACQ_INIT:
        {
            /* Transition ID: ID_POLUPBUTACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetUpButTimer' begin] */
            upButTimer = 0L;
            /* ['<global>::resetUpButTimer' end] */
            /* ['<global>::clearUpButton' begin] */
            upReqAcq = FALSE;
            /* ['<global>::clearUpButton' end] */
            state = ID_POLUPBUTACQ_NOTPRESSED;
            break;
        }
            /* State ID: ID_POLUPBUTACQ_NOTPRESSED */
        case ID_POLUPBUTACQ_NOTPRESSED:
        {
            if (((upReqDI == TRUE) || (hmibuttons & CFG_POL_BUTACQ_HMI_UP_MASK)) && (upButTimer > CFG_POL_UP_BUT_PRESS_TIMER)) {
                /* Transition ID: ID_POLUPBUTACQ_PRESS */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
                /* ['<global>::setUpButton' begin] */
                upReqAcq = TRUE;
                /* ['<global>::setUpButton' end] */
                state = ID_POLUPBUTACQ_PRESSED;
            } else if (((upReqDI == TRUE) || (hmibuttons & CFG_POL_BUTACQ_HMI_UP_MASK))) {
                /* Transition ID: ID_POLUPBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpButTimer' begin] */
                upButTimer++;
                /* ['<global>::incrementUpButTimer' end] */
            } else if (((upReqDI == FALSE) && !(hmibuttons & CFG_POL_BUTACQ_HMI_UP_MASK))) {
                /* Transition ID: ID_POLUPBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
            }
            break;
        }
            /* State ID: ID_POLUPBUTACQ_PRESSED */
        case ID_POLUPBUTACQ_PRESSED:
        {
            if (((upReqDI == FALSE) && !(hmibuttons & CFG_POL_BUTACQ_HMI_UP_MASK)) && (upButTimer > CFG_POL_UP_BUT_UNPRESS_TIMER)
                    ) {
                /* Transition ID: ID_POLUPBUTACQ_UNPRESS */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
                /* ['<global>::clearUpButton' begin] */
                upReqAcq = FALSE;
                /* ['<global>::clearUpButton' end] */
                state = ID_POLUPBUTACQ_NOTPRESSED;
            } else if (((upReqDI == FALSE) && !(hmibuttons & CFG_POL_BUTACQ_HMI_UP_MASK))) {
                /* Transition ID: ID_POLUPBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementUpButTimer' begin] */
                upButTimer++;
                /* ['<global>::incrementUpButTimer' end] */
            } else if (((upReqDI == TRUE) || (hmibuttons & CFG_POL_BUTACQ_HMI_UP_MASK))) {
                /* Transition ID: ID_POLUPBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetUpButTimer' begin] */
                upButTimer = 0L;
                /* ['<global>::resetUpButTimer' end] */
            }
            break;
        }
    }
}
/* ['POLUpButAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['POLDownButAcq' begin (DON'T REMOVE THIS LINE!)] */
void POLDownButAcq() {
    /* set initial state */
    static STATE_T state = ID_POLDOWNBUTACQ_INIT;

    switch (state) {
            /* State ID: ID_POLDOWNBUTACQ_INIT */
        case ID_POLDOWNBUTACQ_INIT:
        {
            /* Transition ID: ID_POLDOWNBUTACQ_INITIAL */
            /* Actions: */
            /* ['<global>::resetDownButTimer' begin] */
            downButTimer = 0L;
            /* ['<global>::resetDownButTimer' end] */
            /* ['<global>::clearDownButton' begin] */
            downReqAcq = FALSE;
            /* ['<global>::clearDownButton' end] */
            state = ID_POLDOWNBUTACQ_NOTPRESSED;
            break;
        }
            /* State ID: ID_POLDOWNBUTACQ_NOTPRESSED */
        case ID_POLDOWNBUTACQ_NOTPRESSED:
        {
            if (((downReqDI == TRUE) || (hmibuttons & CFG_POL_BUTACQ_HMI_DOWN_MASK)) && (downButTimer > CFG_POL_DWN_BUT_PRESS_TIMER)) {
                /* Transition ID: ID_POLDOWNBUTACQ_PRESS */
                /* Actions: */
                /* ['<global>::resetDownButTimer' begin] */
                downButTimer = 0L;
                /* ['<global>::resetDownButTimer' end] */
                /* ['<global>::setDownButton' begin] */
                downReqAcq = TRUE;
                /* ['<global>::setDownButton' end] */
                state = ID_POLDOWNBUTACQ_PRESSED;
            } else if (((downReqDI == TRUE) || (hmibuttons & CFG_POL_BUTACQ_HMI_DOWN_MASK))) {
                /* Transition ID: ID_POLDOWNBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementDownButTimer' begin] */
                downButTimer++;
                /* ['<global>::incrementDownButTimer' end] */
            } else if (((downReqDI == FALSE) && !(hmibuttons & CFG_POL_BUTACQ_HMI_DOWN_MASK)) && (downButTimer > CFG_POL_DWN_BUT_UNPRESS_TIMER)) {
                /* Transition ID: ID_POLDOWNBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetDownButTimer' begin] */
                downButTimer = 0L;
                /* ['<global>::resetDownButTimer' end] */
            }
            break;
        }
            /* State ID: ID_POLDOWNBUTACQ_PRESSED */
        case ID_POLDOWNBUTACQ_PRESSED:
        {
            if (((downReqDI == FALSE) && !(hmibuttons & CFG_POL_BUTACQ_HMI_DOWN_MASK)) && (downButTimer > CFG_POL_DWN_BUT_UNPRESS_TIMER)) {
                /* Transition ID: ID_POLDOWNBUTACQ_UNPRESS */
                /* Actions: */
                /* ['<global>::resetDownButTimer' begin] */
                downButTimer = 0L;
                /* ['<global>::resetDownButTimer' end] */
                /* ['<global>::clearDownButton' begin] */
                downReqAcq = FALSE;
                /* ['<global>::clearDownButton' end] */
                state = ID_POLDOWNBUTACQ_NOTPRESSED;
            } else if (((downReqDI == FALSE) && !(hmibuttons & CFG_POL_BUTACQ_HMI_DOWN_MASK))) {
                /* Transition ID: ID_POLDOWNBUTACQ_TIMERINCREMENT */
                /* Actions: */
                /* ['<global>::incrementDownButTimer' begin] */
                downButTimer++;
                /* ['<global>::incrementDownButTimer' end] */
            } else if (((downReqDI == TRUE) || (hmibuttons & CFG_POL_BUTACQ_HMI_DOWN_MASK))) {
                /* Transition ID: ID_POLDOWNBUTACQ_LOOP */
                /* Actions: */
                /* ['<global>::resetDownButTimer' begin] */
                downButTimer = 0L;
                /* ['<global>::resetDownButTimer' end] */
            }
            break;
        }
    }
}
/* ['POLDownButAcq' end (DON'T REMOVE THIS LINE!)] */
