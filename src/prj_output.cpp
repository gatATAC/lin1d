#include "gttc_timer.h"
#include "prj_cfg.h"
#include "prj_output.h"
#include "prj_pinout.h"
#include "FM1DRE.h"
#include "POLDRE.h"
#include <Arduino.h>

#include <TM1638.h>
extern TM1638 module;

extern t_dreFM1 dreFM1;
extern t_drePOL drePOL;

#ifdef CFG_FM1_USE_ACCELSTEPPER
#include <AccelStepper.h>

AccelStepper fm1Stepper(AccelStepper::FULL4WIRE, CFG_FM1_ACCELSTEPPER_IN1_PIN, CFG_FM1_ACCELSTEPPER_IN2_PIN, CFG_FM1_ACCELSTEPPER_IN3_PIN, CFG_FM1_ACCELSTEPPER_IN4_PIN);
#endif
#ifdef CFG_POL_USE_ACCELSTEPPER
#include <AccelStepper.h>

AccelStepper polStepper(AccelStepper::FULL4WIRE, CFG_POL_ACCELSTEPPER_IN1_PIN, CFG_POL_ACCELSTEPPER_IN2_PIN, CFG_POL_ACCELSTEPPER_IN3_PIN, CFG_POL_ACCELSTEPPER_IN4_PIN);
#endif

#ifdef CFG_FM1_USE_SERVO
#include <Servo.h>
Servo fm1Servo; // create servo object to control a servo
#endif
#ifdef CFG_POL_USE_SERVO
#include <Servo.h>
Servo polServo; // create servo object to control a servo
#endif

#ifdef CFG_USE_MOTORCTRL

void processMotorCtrl(void) {
    if (dreFM1.appliedActDirection == CFG_MOTORCTRL_DIR_FW) {
        digitalWrite(PORT_doDirFw, HIGH);
    } else {
        digitalWrite(PORT_doDirBw, LOW);
    }
    if (dreFM1.appliedActDirection == CFG_MOTORCTRL_DIR_BW) {
        digitalWrite(PORT_doDirFw, LOW);
    } else {
        digitalWrite(PORT_doDirBw, HIGH);
    }
    analogWrite(PORT_pwmActAction, dreFM1.appliedActAction);
}
#endif

void prjOutputInit(void) {

#ifdef CFG_FM1_USE_ACCELSTEPPER
    fm1Stepper.setAcceleration(CFG_FM1_ACCELSTEPPER_ACCEL); // 1000 para zapp  // 4000 para sanyo denki
    fm1Stepper.setMaxSpeed(CFG_FM1_ACCELSTEPPER_MAX_SPEED);
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

char buf[17];
uint8_t counter = 0;
uint16_t ledMask = 0x0000;

void prjOutput(void) {

    Serial.println("ledmask!");
    counter = 0;

#ifdef CFG_USE_MOTORCTRL
    processMotorCtrl();
#endif

#ifdef CFG_FM1_USE_ACCELSTEPPER
    if (dreFM1.posMode == CFG_POS_MODE_UP) {
        dreFM1.stepperEnable = TRUE;
        dreFM1.stepperSetPoint = CFG_FM1_ACCELSTEPPER_ACTIVE_POS;
    } else {
        if (dreFM1.posMode == CFG_POS_MODE_DOWN) {
            dreFM1.stepperEnable = TRUE;
            dreFM1.stepperSetPoint = CFG_FM1_ACCELSTEPPER_PARKED_POS;
        } else {
            dreFM1.stepperEnable = FALSE;
        }
    }
    if (dreFM1.stepperEnable) {
        fm1Stepper.enableOutputs();
        fm1Stepper.moveTo(dreFM1.stepperSetPoint);
    } else {
        fm1Stepper.disableOutputs();
    }
    fm1Stepper.run();
#endif

#ifdef CFG_POL_USE_ACCELSTEPPER
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
    polStepper.setMaxSpeed(CFG_POL_ACCELSTEPPER_MAX_SPEED);
    drePOL.stepperAngleFdback = polStepper.currentPosition();
    if (drePOL.stepperEnable) {
        polStepper.enableOutputs();
        polStepper.moveTo(drePOL.stepperSetPoint);
    } else {
        polStepper.moveTo(drePOL.stepperAngleFdback);
        polStepper.disableOutputs();
    }
    polStepper.run();
#endif

#ifdef CFG_FM1_USE_SERVO
    if (dreFM1.posMode == CFG_POS_MODE_UP) {
        dreFM1.pwmServoEnable = TRUE;
        dreFM1.pwmServoSetPoint = CFG_FM1_SERVO_ACTIVE_ANGLE;
    } else {
        if (dreFM1.posMode == CFG_POS_MODE_DOWN) {
            dreFM1.pwmServoEnable = TRUE;
            dreFM1.pwmServoSetPoint = CFG_FM1_SERVO_PARKED_ANGLE;
        } else {
            dreFM1.pwmServoEnable = FALSE;
            dreFM1.pwmServoSetPoint = 0;
        }
    }
    if (dreFM1.pwmServoEnable) {
        fm1Servo.attach(CFG_FM1_SERVO_PIN); // attaches the servo on pin CFG_FM1_SERVO_PIN to the servo object
        fm1Servo.write(dreFM1.pwmServoSetPoint);
    } else {
        fm1Servo.detach(); // dettaches the servo
    }
#endif

#ifdef CFG_POL_USE_SERVO
    if (drePOL.posMode == CFG_POS_MODE_UP) {
        drePOL.pwmServoEnable = TRUE;
        drePOL.pwmServoSetPoint = CFG_POL_SERVO_ACTIVE_ANGLE;
    } else {
        if (drePOL.posMode == CFG_POS_MODE_DOWN) {
            drePOL.pwmServoEnable = TRUE;
            drePOL.pwmServoSetPoint = CFG_POL_SERVO_PARKED_ANGLE;
        } else {
            drePOL.pwmServoEnable = FALSE;
            drePOL.pwmServoSetPoint = 0;
        }
    }
    if (drePOL.pwmServoEnable) {
        polServo.attach(CFG_POL_SERVO_PIN); // attaches the servo on pin CFG_POL_SERVO_PIN  to the servo object
        polServo.write(drePOL.pwmServoSetPoint);
    } else {
        polServo.detach(); // dettaches the servo
    }
#endif
}

















