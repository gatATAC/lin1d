#include "gttc_timer.h"
#include "prj_cfg.h"
#include "prj_output.h"
#include "prj_pinout.h"
#include "DRE.h"
#include <Arduino.h>

#include <TM1638.h>
extern TM1638 module;

extern t_dre dre;

#ifdef CFG_USE_ACCELSTEPPER
#include <AccelStepper.h>

AccelStepper stepper1(AccelStepper::FULL4WIRE, CFG_ACCELSTEPPER_IN1_PIN, CFG_ACCELSTEPPER_IN2_PIN, CFG_ACCELSTEPPER_IN3_PIN, CFG_ACCELSTEPPER_IN4_PIN);
#endif

#ifdef CFG_USE_MOTORCTRL

void processMotorCtrl(void) {
    if (dre.direction == CFG_MOTORCTRL_DIR_FW) {
        digitalWrite(CFG_MOTORCTRL_IN3_PIN, HIGH);
    } else {
        digitalWrite(CFG_MOTORCTRL_IN3_PIN, LOW);
    }
    if (dre.direction == CFG_MOTORCTRL_DIR_BW) {
        digitalWrite(CFG_MOTORCTRL_IN4_PIN, HIGH);
    } else {
        digitalWrite(CFG_MOTORCTRL_IN4_PIN, LOW);
    }
    if (dre.motorCtrlDuty > 0) {
        digitalWrite(CFG_LED_STATUS, HIGH);
    } else {
        digitalWrite(CFG_LED_STATUS, LOW);
    }
    //dre.motorCtrlDuty = 0;
    analogWrite(CFG_MOTORCTRL_PWM_PIN, dre.motorCtrlDuty);
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
}

char buf[17];
uint8_t counter = 0;
uint16_t ledMask = 0x0000;

void prjOutput(void) {

    Serial.println("ledmask!");
    counter = 0;

    /*
      uint8_t i;
      ledMask=0x0000;
      for (i=0;i<NUM_LEDS;i++){
        if(dre.buttonState[i]) {
          dre.ledState[i]=2;
        } else {
          dre.ledState[i]=0;
        }
        if (dre.ledState[i]>0){
          if (dre.ledState[i]>1){
            ledMask |= (0x0100 << i);
          }
          else {
            ledMask |= (0x0100 << i);
          }
        }
      }
        module.setDisplayToDecNumber(CYCLE_TIME_MICROS, 0);
        module.setLEDs(ledMask);
     */

#ifdef CFG_USE_MOTORCTRL
    processMotorCtrl();
#endif

#ifdef CFG_USE_ACCELSTEPPER
    long dist;
    bool stopped = false;

    dre.maxSpeed = (dre.sliderA * CFG_ACCELSTEPPER_SPEED_SLIDERA_FACTOR) + CFG_ACCELSTEPPER_SPEED_SLIDERA_OFFSET;
    stepper1.setMaxSpeed(dre.maxSpeed);
    if (dre.stepper1status == CFG_ACCELSTEPPER_STATUS_QUIET) {
        stepper1.moveTo(dre.currentTarget);
        dre.stepper1status = CFG_ACCELSTEPPER_STATUS_MOVING;
    } else {
        dist = stepper1.distanceToGo();
        if (dist < 10 && dist > -10) {
            Serial.printf("dist: %d\n", dist);
            if (dist == 0) {
                //stepper1.moveTo(-stepper1.currentPosition());
                dre.stepper1status = CFG_ACCELSTEPPER_STATUS_QUIET;
                dre.currentTarget = -dre.currentTarget;
                stepper1.disableOutputs();
            } else {
                if (!dre.loadPosUpSwchAcq && dre.loadPosDownSwchAcq) {
                    stepper1.run();
                } else {
                    stepper1.disableOutputs();
                }
            }
        } else {
            if (!dre.loadPosUpSwchAcq && dre.loadPosDownSwchAcq) {
                stepper1.run();
            } else {
                stepper1.disableOutputs();
            }
        }
    }

#endif

}
