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

#ifdef CFG_USE_ACCELSTEPPER
#include <AccelStepper.h>

AccelStepper stepper1(AccelStepper::FULL4WIRE, CFG_ACCELSTEPPER_IN1_PIN, CFG_ACCELSTEPPER_IN2_PIN, CFG_ACCELSTEPPER_IN3_PIN, CFG_ACCELSTEPPER_IN4_PIN);
#endif

#ifdef CFG_FM1_USE_SERVO
#include <Servo.h>
Servo fm1Servo;  // create servo object to control a servo
#endif
#ifdef CFG_POL_USE_SERVO
#include <Servo.h>
Servo polServo;  // create servo object to control a servo
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

#ifdef CFG_USE_ACCELSTEPPER
    stepper1.setAcceleration(CFG_ACCELSTEPPER_ACCEL); // 1000 para zapp  // 4000 para sanyo denki
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

#ifdef CFG_USE_ACCELSTEPPER
    long dist;
    bool stopped = false;

    dreFM1.maxSpeed = (dreFM1.sliderA * CFG_ACCELSTEPPER_SPEED_SLIDERA_FACTOR) + CFG_ACCELSTEPPER_SPEED_SLIDERA_OFFSET;
    stepper1.setMaxSpeed(dreFM1.maxSpeed);
    if (dreFM1.stepper1status == CFG_ACCELSTEPPER_STATUS_QUIET) {
        stepper1.moveTo(dreFM1.currentTarget);
        dreFM1.stepper1status = CFG_ACCELSTEPPER_STATUS_MOVING;
    } else {
        dist = stepper1.distanceToGo();
        if (dist < 10 && dist > -10) {
            Serial.printf("dist: %d\n", dist);
            if (dist == 0) {
                //stepper1.moveTo(-stepper1.currentPosition());
                dreFM1.stepper1status = CFG_ACCELSTEPPER_STATUS_QUIET;
                dreFM1.currentTarget = -dreFM1.currentTarget;
                stepper1.disableOutputs();
            } else {
                if (!dreFM1.loadPosUpSwchAcq && dreFM1.loadPosDownSwchAcq) {
                    stepper1.run();
                } else {
                    stepper1.disableOutputs();
                }
            }
        } else {
            if (!dreFM1.loadPosUpSwchAcq && dreFM1.loadPosDownSwchAcq) {
                stepper1.run();
            } else {
                stepper1.disableOutputs();
            }
        }
    }

#endif

#ifdef CFG_FM1_USE_SERVO
    if (dreFM1.posMode == CFG_POS_MODE_UP){
      dreFM1.pwmServoEnable = TRUE;
      dreFM1.pwmServoSetPoint = CFG_FM1_ACTIVE_ANGLE;
    } else {
      if (dreFM1.posMode == CFG_POS_MODE_DOWN){
        dreFM1.pwmServoEnable = TRUE;
        dreFM1.pwmServoSetPoint = CFG_FM1_PARKED_ANGLE;
      } else {
        dreFM1.pwmServoEnable = FALSE;
        dreFM1.pwmServoSetPoint = 0;   
      }
    }
    if (dreFM1.pwmServoEnable) {
      fm1Servo.attach(CFG_FM1_SERVO_PIN);  // attaches the servo on pin CFG_FM1_SERVO_PIN to the servo object
      fm1Servo.write(dreFM1.pwmServoSetPoint);  
    } else {
      fm1Servo.detach();  // dettaches the servo
    }
#endif

#ifdef CFG_POL_USE_SERVO
    if (drePOL.posMode==CFG_POS_MODE_UP){
      drePOL.pwmServoEnable = TRUE;
      drePOL.pwmServoSetPoint = CFG_POL_ACTIVE_ANGLE;
    } else {
      if (drePOL.posMode==CFG_POS_MODE_DOWN){
        drePOL.pwmServoEnable = TRUE;
        drePOL.pwmServoSetPoint = CFG_POL_PARKED_ANGLE;        
      } else {
        drePOL.pwmServoEnable = FALSE;
        drePOL.pwmServoSetPoint = 0;
      }
    }
    if (drePOL.pwmServoEnable) {
      polServo.attach(CFG_POL_SERVO_PIN);  // attaches the servo on pin CFG_POL_SERVO_PIN  to the servo object
      polServo.write(drePOL.pwmServoSetPoint);
    } else {
      polServo.detach();  // dettaches the servo
    }
#endif
}

















