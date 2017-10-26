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
#if CFG_FM1_USE_ACCELSTEPPER_DRIVERMODE
AccelStepper fm1Stepper(AccelStepper::DRIVER, CFG_FM1_ACCELSTEPPER_IN1_STP_PIN, CFG_FM1_ACCELSTEPPER_IN2_DIR_PIN);
#else
AccelStepper fm1Stepper(AccelStepper::FULL4WIRE, CFG_FM1_ACCELSTEPPER_IN1_STP_PIN, CFG_FM1_ACCELSTEPPER_IN2_DIR_PIN, CFG_FM1_ACCELSTEPPER_IN3_PIN, CFG_FM1_ACCELSTEPPER_IN4_PIN);
#endif

bool working = true;
#ifdef DEBUG_ACTUATION
bool antEnable = false;
#endif

// Variables to apply changes only when something happens
bool antDwnSwitch = false;
int tmpSpeed = 0;
int antSpeed = 0;

void processFM1AccelStepper() {
    if (antDwnSwitch == TRUE && dreFM1.loadPosDownSwchAcq == FALSE) {
      fm1Stepper.setCurrentPosition(0);
#ifdef DEBUG_ACTUATION
      Serial.println("Homing!");
#endif
    }
    antDwnSwitch = dreFM1.loadPosDownSwchAcq;

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
    dreFM1.stepperAngleFdback = fm1Stepper.currentPosition();
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
    tmpSpeed = min(CFG_FM1_ACCELSTEPPER_MAX_SPEED,dreFM1.appliedActAction);
    tmpSpeed = max(-CFG_FM1_ACCELSTEPPER_MAX_SPEED,dreFM1.appliedActAction);
    if (tmpSpeed != antSpeed){
      fm1Stepper.setMaxSpeed(tmpSpeed);
      antSpeed = tmpSpeed;
#ifdef DEBUG_ACTUATION
      Serial.print("spd: "); Serial.println(tmpSpeed);
#endif
    }
#ifdef DEBUG_ACTUATION
    if (antEnable != dreFM1.stepperEnable){
      Serial.print("enab: ");Serial.println(dreFM1.stepperEnable);
      antEnable = dreFM1.stepperEnable;
    }
#endif
    if (dreFM1.stepperEnable) {
        fm1Stepper.enableOutputs();
        fm1Stepper.moveTo(dreFM1.stepperSetPoint);
        working = true;
    } else {
        if (working){
            working = false;
            fm1Stepper.moveTo(dreFM1.stepperAngleFdback);
        }
        fm1Stepper.disableOutputs();
    }
    fm1Stepper.run();
}
#endif

#ifdef CFG_POL_USE_ACCELSTEPPER
#include <AccelStepper.h>

#if CFG_POL_USE_ACCELSTEPPER_DRIVERMODE
AccelStepper polStepper(AccelStepper::DRIVER, CFG_POL_ACCELSTEPPER_IN1_STP_PIN, CFG_POL_ACCELSTEPPER_IN2_DIR_PIN);
#else
AccelStepper polStepper(AccelStepper::FULL4WIRE, CFG_POL_ACCELSTEPPER_IN1_STP_PIN, CFG_POL_ACCELSTEPPER_IN3_PIN, CFG_POL_ACCELSTEPPER_IN2_DIR_PIN, CFG_POL_ACCELSTEPPER_IN4_PIN);
#endif

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
    polStepper.setMaxSpeed(min(CFG_POL_ACCELSTEPPER_MAX_SPEED,drePOL.appliedActAction));
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

#ifdef CFG_FM1_USE_MOTORCTRL
void processFM1MotorCtrl(void) {
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

#ifdef CFG_POL_USE_MOTORCTRL
void processPOLMotorCtrl(void) {
    if (drePOL.appliedActDirection == CFG_MOTORCTRL_DIR_FW) {
        digitalWrite(PORT_POLdoDirFw, HIGH);
    } else {
        digitalWrite(PORT_POLdoDirBw, LOW);
    }
    if (drePOL.appliedActDirection == CFG_MOTORCTRL_DIR_BW) {
        digitalWrite(PORT_POLdoDirFw, LOW);
    } else {
        digitalWrite(PORT_POLdoDirBw, HIGH);
    }
    analogWrite(PORT_POLpwmActAction, drePOL.appliedActAction);
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
#ifdef CFG_FM1_USE_MOTORCTRL
    processFM1MotorCtrl();
#endif
#ifdef CFG_POL_USE_MOTORCTRL
    processPOLMotorCtrl();
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
#ifdef CFG_FM1_USE_MOTORCTRL
    processFM1MotorCtrl();
#endif
#ifdef CFG_POL_USE_MOTORCTRL
    processPOLMotorCtrl();
#endif
}
