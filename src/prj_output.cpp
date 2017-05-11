#include "gttc_timer.h"
#include "prj_cfg.h"
#include "prj_output.h"
#include "prj_pinout.h"
#include "FM1DRE.h"
#include "POLDRE.h"
#include "PwmServoCtrl.h"
#include <Arduino.h>

#include <TM1638.h>
extern TM1638 module;

extern t_dreFM1 dreFM1;
extern t_drePOL drePOL;

#ifdef CFG_FM1_USE_ACCELSTEPPER
#include <AccelStepper.h>

AccelStepper fm1Stepper(AccelStepper::FULL4WIRE, CFG_FM1_ACCELSTEPPER_IN1_PIN, CFG_FM1_ACCELSTEPPER_IN2_PIN, CFG_FM1_ACCELSTEPPER_IN3_PIN, CFG_FM1_ACCELSTEPPER_IN4_PIN);

void processFM1AccelStepper() {
    if (dreFM1.loadPosDownSwchAcq) {
        polStepper.setCurrentPosition(0);
    }

#ifdef CFG_FM1_USE_ACCELSTEPPER_SETPOINT 
    if (dreFM1.posMode == CFG_POS_MODE_UP) {
        dreFM1.stepperEnable = true;
        dreFM1.stepperSetPoint = CFG_FM1_ACCELSTEPPER_ACTIVE_POS;
    } else {
        if (dreFM1.posMode == CFG_POS_MODE_DOWN) {
            dreFM1.stepperEnable = true;
            dreFM1.stepperSetPoint = CFG_FM1_ACCELSTEPPER_PARKED_POS;
        } else {
            dreFM1.stepperEnable = false;
        }
    }
#else
    dreFM1.stepperAngleFdback = polStepper.currentPosition();
    if (dreFM1.posMode == CFG_POS_MODE_UP && !dreFM1.loadPosUpSwchAcq) {
        dreFM1.stepperEnable = true;
        dreFM1.stepperSetPoint = dreFM1.stepperAngleFdback + CFG_FM1_ACCELSTEPPER_INCREMENT;
    } else {
        if (dreFM1.posMode == CFG_POS_MODE_DOWN && !dreFM1.loadPosDownSwchAcq) {
            dreFM1.stepperEnable = true;
            dreFM1.stepperSetPoint = dreFM1.stepperAngleFdback - CFG_FM1_ACCELSTEPPER_INCREMENT;
        } else {
            dreFM1.stepperEnable = false;
        }
    }
#endif
    polStepper.setMaxSpeed(CFG_FM1_ACCELSTEPPER_MAX_SPEED);
    if (dreFM1.stepperEnable) {
        polStepper.enableOutputs();
        polStepper.moveTo(dreFM1.stepperSetPoint);
    } else {
        polStepper.moveTo(dreFM1.stepperAngleFdback);
        polStepper.disableOutputs();
    }
    polStepper.run();
}

#endif
#ifdef CFG_POL_USE_ACCELSTEPPER
#include <AccelStepper.h>

AccelStepper polStepper(AccelStepper::FULL4WIRE, CFG_POL_ACCELSTEPPER_IN1_PIN, CFG_POL_ACCELSTEPPER_IN2_PIN, CFG_POL_ACCELSTEPPER_IN3_PIN, CFG_POL_ACCELSTEPPER_IN4_PIN);

void processPOLAccelStepper() {
    if (drePOL.loadPosDownSwchAcq) {
        polStepper.setCurrentPosition(0);
    }

#ifdef CFG_POL_USE_ACCELSTEPPER_SETPOINT 
    if (drePOL.posMode == CFG_POS_MODE_UP) {
        drePOL.stepperEnable = true;
        drePOL.stepperSetPoint = CFG_POL_ACCELSTEPPER_ACTIVE_POS;
    } else {
        if (drePOL.posMode == CFG_POS_MODE_DOWN) {
            drePOL.stepperEnable = true;
            drePOL.stepperSetPoint = CFG_POL_ACCELSTEPPER_PARKED_POS;
        } else {
            drePOL.stepperEnable = false;
        }
    }
#else
    drePOL.stepperAngleFdback = polStepper.currentPosition();
    if (drePOL.posMode == CFG_POS_MODE_UP && !drePOL.loadPosUpSwchAcq) {
        drePOL.stepperEnable = true;
        drePOL.stepperSetPoint = drePOL.stepperAngleFdback + CFG_POL_ACCELSTEPPER_INCREMENT;
    } else {
        if (drePOL.posMode == CFG_POS_MODE_DOWN && !drePOL.loadPosDownSwchAcq) {
            drePOL.stepperEnable = true;
            drePOL.stepperSetPoint = drePOL.stepperAngleFdback - CFG_POL_ACCELSTEPPER_INCREMENT;
        } else {
            drePOL.stepperEnable = false;
        }
    }
#endif
    polStepper.setMaxSpeed(CFG_POL_ACCELSTEPPER_MAX_SPEED);
    if (drePOL.stepperEnable) {
        polStepper.enableOutputs();
        polStepper.moveTo(drePOL.stepperSetPoint);
    } else {
        polStepper.moveTo(drePOL.stepperAngleFdback);
        polStepper.disableOutputs();
    }
    polStepper.run();
}
#endif
#ifdef CFG_USE_MOTORCTRL
void processMotorCtrl(void) {
    if (dreFM1.appliedActDirection == CFG_MOTORCTRL_DIR_FW) {
        digitalWrite(PORT_FM1doDirFw, HIGH);
    } else {
        digitalWrite(PORT_FM1doDirBw, LOW);
    }
    if (dreFM1.appliedActDirection == CFG_MOTORCTRL_DIR_BW) {
        digitalWrite(PORT_FM1doDirFw, LOW);
    } else {
        digitalWrite(PORT_FM1doDirBw, HIGH);
    }
    analogWrite(PORT_FM1pwmActAction, dreFM1.appliedActAction);
}
#endif

void prjOutputInit(void) {

#ifdef CFG_FM1_USE_SERVO
    fm1PwmServoCtrlInit();
#endif
#ifdef CFG_POL_USE_SERVO
    polPwmServoCtrlInit();
#endif
#ifdef CFG_FM1_USE_ACCELSTEPPER
    fm1Stepper.setAcceleration(CFG_FM1_ACCELSTEPPER_ACCEL); // 1000 para zapp  // 4000 para sanyo denki
#endif
#ifdef CFG_POL_USE_ACCELSTEPPER
    polStepper.setAcceleration(CFG_POL_ACCELSTEPPER_ACCEL); // 1000 para zapp  // 4000 para sanyo denki
#endif
#ifdef CFG_USE_MOTORCTRL
    //analogWrite(CFG_MOTORCTRL_DEBUGPWM_PIN,10);
    processMotorCtrl();
#endif

    // If motor works, then the status led will be light on
    if (dreFM1.appliedActAction > 0) {
        digitalWrite(CFG_LED_STATUS, HIGH);
    } else {
        digitalWrite(CFG_LED_STATUS, LOW);
    }
}

void prjOutput(void) {
    
#ifdef CFG_FM1_USE_SERVO
    fm1PwmServoCtrl();
#endif
#ifdef CFG_POL_USE_SERVO
    polPwmServoCtrl();
#endif
#ifdef CFG_FM1_USE_ACCELSTEPPER
    processFM1AccelStepper();
#endif
#ifdef CFG_POL_USE_ACCELSTEPPER
    processPOLAccelStepper();
#endif
#ifdef CFG_USE_MOTORCTRL
    processMotorCtrl();
#endif
}
