#include "gttc_timer.h"
#include "prj_cfg.h"
#include "prj_output.h"
#include "prj_pinout.h"
#include "DRE.h"
#include <Arduino.h>

#include <TM1638.h>
extern TM1638 module;

extern t_dreFM1 dreFM1;

#ifdef CFG_USE_ACCELSTEPPER
#include <AccelStepper.h>

AccelStepper stepper1(AccelStepper::FULL4WIRE, CFG_ACCELSTEPPER_IN1_PIN, CFG_ACCELSTEPPER_IN2_PIN, CFG_ACCELSTEPPER_IN3_PIN, CFG_ACCELSTEPPER_IN4_PIN);
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
    analogWrite(PORT_pwmActAction, dreFM1.rectifiedActAction);

    // If motor works, then the status led will be light on
    if (dreFM1.rectifiedActAction > 0) {
        digitalWrite(CFG_LED_STATUS, HIGH);
    } else {
        digitalWrite(CFG_LED_STATUS, LOW);
    }
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

}






