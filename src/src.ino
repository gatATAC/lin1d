/* --------- This file is an example of a main file in an Arduino project -----------------------------
 -- Additional files with gttc_ prefix are the gatArduinOSEK files, not to be modified in normal use --
 -- Additional files with prj_ prefix are the ones that must be configured for each project, they    --
 -- are part of the example.                                                                         --
 -- Project Functionality:
 -- This project uses 4 buttons and 4 leds and the serial port of the arduino.
 -- Buttons are read and the statuses are sent through the serial console.
 -- The user can send commands through the serial console to light the leds.
 -- Buttons and leds are connected to pins configured in prj_pinout.h
 -- Global variables of the project are shared through a DRE (Data Runtime Environment) defined in prj_dre.h and prj_dre.c
 -- The serial console commands are processed in prj_tty_cmds.h and prj_tty_cmds.c
 -- The serial console broadcast of the input statuses is done in prj_tty_brcast.h and prj_tty_brcast.c
 -- Please visit the wiki page for this project in http://gatatac.org/projects/gttcosarduino/wiki/GatArduinOSEKino_example_1


 ***** Project configuration include (before OSEK includes to allow OSEK configuration ******/
#include <Arduino.h>

#include "prj_cfg.h"

/***** gatArduinOSEK includes *****/
/*** Types ***/
#include <gttc_types.h>
/*** Timer ***/
//#define TIMEBASE_USE_MS 1  // <-- Normally the timer unit is the us (microseconds) but you can use this define to use ms (milliseconds)
#include <gttc_timer.h>

/* ---------------------------------------*/

/***** Project includes *****/
#include "prj_pinout.h" // <-- The pinout of the project
#include "FM1DRE.h"    // <-- The DRE of the project (global variables pools to share)
#include "POLDRE.h"    // <-- The DRE of the project (global variables pools to share)
#include "prj_input.h"  // <-- The input module reads the microcontroller pinout
#include "prj_output.h"  // <-- The output module writes the microcontroller pinout
#include "FM1lin1dFSM.h"
#include "POLlin1dFSM.h"
#include "monitor.h"

#include <TM1638.h>

// define a module on data pin 11, clock pin 2 and strobe pin 12
TM1638 module(PORT_FM1hmidata, PORT_FM1hmiclock, PORT_FM1hmistrobe);
//TM1638 module(PORT_POLhmidata, PORT_POLhmiclock, PORT_POLhmistrobe); // Both subsystems (POL and FM1) share same hmi

extern t_dreFM1 dreFM1;
extern t_drePOL drePOL;

void dreInit() {
    dreFM1.upReqAcq = FALSE;
    dreFM1.downReqAcq = FALSE;
    dreFM1.upReqDI = FALSE;
    dreFM1.downReqDI = FALSE;
    dreFM1.posMode = CFG_POS_MODE_STOP;
    dreFM1.actAction = 0;
    dreFM1.pwmActAction = 0;
    dreFM1.doDirFw = FALSE;
    dreFM1.doDirBw = FALSE;
    dreFM1.actEnable = TRUE;
    dreFM1.actDirection = CFG_ACT_DIRECTION_QUIET;
    dreFM1.rectifiedActAction = 0;
    dreFM1.loadPosAcq = 0;
    dreFM1.appliedActDirection = CFG_ACT_DIRECTION_QUIET;
    dreFM1.actDrvTimer = 0L;
    dreFM1.loadPosAI = 0;
    dreFM1.upButTimer = 0L;
    dreFM1.downButTimer = 0L;
    dreFM1.loadPosUpSwchDI = FALSE;
    dreFM1.loadPosDownSwchDI = FALSE;
    dreFM1.posAchieved = FALSE;
    dreFM1.ctrlError = FALSE;
    dreFM1.driveCurrentAI = 0;
    dreFM1.driveCurrentAcq = 0;
    dreFM1.currentError = FALSE;
    dreFM1.brokenChainError = FALSE;
    dreFM1.stuckActError = FALSE;
    dreFM1.loadPosUpSwchAcq = FALSE;
    dreFM1.loadPosDownSwchAcq = FALSE;
    dreFM1.upSwitchTimer = 0L;
    dreFM1.downSwitchTimer = 0L;
    dreFM1.hmibuttons = 0;
    dreFM1.hmileds = 0;
    dreFM1.hmidigits = 0L;
    dreFM1.forcedPos = 0L;
    dreFM1.stepperSetPoint = 0L;
    dreFM1.stepperEnable = FALSE;
    dreFM1.stepCtrlA = FALSE;
    dreFM1.stepCtrlB = FALSE;
    dreFM1.pwmServoAngleFdback = 0L;
    dreFM1.pwmServoEnable = FALSE;
    dreFM1.pwmServoSetPoint = 0L;
    dreFM1.pwmServoActive = FALSE;
    dreFM1.pwmServoPwm = 0;
    dreFM1.stepperServoActive = FALSE;
    dreFM1.stepperAngleFdback = 0L;

    drePOL.upReqAcq = FALSE;
    drePOL.downReqAcq = FALSE;
    drePOL.upReqDI = FALSE;
    drePOL.downReqDI = FALSE;
    drePOL.posMode = CFG_POS_MODE_STOP;
    drePOL.actAction = 0;
    drePOL.pwmActAction = 0;
    drePOL.doDirFw = FALSE;
    drePOL.doDirBw = FALSE;
    drePOL.actEnable = TRUE;
    drePOL.actDirection = CFG_ACT_DIRECTION_QUIET;
    drePOL.rectifiedActAction = 0;
    drePOL.loadPosAcq = 0;
    drePOL.appliedActDirection = CFG_ACT_DIRECTION_QUIET;
    drePOL.actDrvTimer = 0L;
    drePOL.loadPosAI = 0;
    drePOL.upButTimer = 0L;
    drePOL.downButTimer = 0L;
    drePOL.loadPosUpSwchDI = FALSE;
    drePOL.loadPosDownSwchDI = FALSE;
    drePOL.posAchieved = FALSE;
    drePOL.ctrlError = FALSE;
    drePOL.driveCurrentAI = 0;
    drePOL.driveCurrentAcq = 0;
    drePOL.currentError = FALSE;
    drePOL.brokenChainError = FALSE;
    drePOL.stuckActError = FALSE;
    drePOL.loadPosUpSwchAcq = FALSE;
    drePOL.loadPosDownSwchAcq = FALSE;
    drePOL.upSwitchTimer = 0L;
    drePOL.downSwitchTimer = 0L;
    drePOL.hmibuttons = 0;
    drePOL.hmileds = 0;
    drePOL.hmidigits = 0L;
    drePOL.forcedPos = 0L;
    drePOL.stepperSetPoint = 0L;
    drePOL.stepperEnable = FALSE;
    drePOL.stepCtrlA = FALSE;
    drePOL.stepCtrlB = FALSE;
    drePOL.pwmServoAngleFdback = 0L;
    drePOL.pwmServoEnable = FALSE;
    drePOL.pwmServoSetPoint = 0L;
    drePOL.pwmServoActive = FALSE;
    drePOL.pwmServoPwm = 0;
    drePOL.stepperServoActive = FALSE;
    drePOL.stepperAngleFdback = 0L;
}

/* ---------------------------------------*/

/***** FSM tasks *****/
void fsmTasks(void) {
    // Acquisition
    FM1UpButAcq();
    FM1DownButAcq();
    FM1upSwitchAcq();
    FM1downSwitchAcq();

    // Government
    if (CFG_USE_DIRECT_INTERFACE) {
      if (dreFM1.upReqAcq) {
        dreFM1.posMode = CFG_POS_MODE_UP;
      } else {
        if (dreFM1.downReqAcq) {
          dreFM1.posMode = CFG_POS_MODE_DOWN;
        } else {
          dreFM1.posMode = CFG_POS_MODE_STOP;
        }
      }
    } else {
      FM1ModeSelector();
    }
    FM1PosControl();

    // Actuation
    FM1ActEnabler();
    FM1ActDriving();

    // Acquisition
    POLUpButAcq();
    POLDownButAcq();
    POLupSwitchAcq();
    POLdownSwitchAcq();

    // Government
    if (CFG_USE_DIRECT_INTERFACE) {
      if (drePOL.upReqAcq) {
        drePOL.posMode = CFG_POS_MODE_UP;
      } else {
        if (drePOL.downReqAcq) {
          drePOL.posMode = CFG_POS_MODE_DOWN;
        } else {
          drePOL.posMode = CFG_POS_MODE_STOP;
        }
      }
    } else {
      POLModeSelector();
    }
    POLPosControl();

    // Actuation
    POLActEnabler();
    POLActDriving();
}

/***** Setup & Startup functions *****/

void setup() {

    ////////////// Platform init
    timerSetCycleTime(CYCLE_TIME_IN_MICROS);

    ////////////// DRE init
    dreInit();

    ////////////// Pinout init
    //pinoutInit();

    ////////////// Input init
    prjInputInit();

    ////////////// FSM init
    fsmTasks();

    ////////////// Output Init
    prjOutputInit();

    ////////////// Monitor Init
    monitorInit();
}

/* ---------------------------------------*/

/***** Main Loop *****/
int atencion=0;
bool llamado_atencion=false;
void loop() {
    // ----------- Functionality ----------------

    ////////////// Input task
    prjInput();

    ////////////// FSM tasks
    fsmTasks();

    ////////////// Monitoring tasks
    monitorExec();

    // ----------- End of Cycle Synchronization ----------------
#if 1
    llamado_atencion=false;
    // Now the microcontroller will loose time until the end of cycle sincronization time expires
    boolean timSync = timerSync();
    if (timSync) {
      Serial.print("Ciclo violado!");
    }
    if ((CYCLE_TIME_IN_MICROS - elapsedMicros) < CYCLE_SECURITY_TIME_MICROS) {
        Serial.print("Atencion!"); Serial.println(atencion++);
        Serial.println(elapsedMicros);
    }
    while (timSync == false) {
        // timerSync returns true when the end of cycle syncronization time expired.
        timSync = timerSync();
    }
#endif

    ////////////// Output task
    prjOutput();

}
