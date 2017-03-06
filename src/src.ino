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
#include "DRE.h"    // <-- The DRE of the project (global variables pools to share)
#include "prj_input.h"  // <-- The input module reads the microcontroller pinout
#include "prj_output.h"  // <-- The output module writes the microcontroller pinout

#include <TM1638.h>

// define a module on data pin 11, clock pin 2 and strobe pin 12
TM1638 module(CFG_TM1638_DATA_PIN, CFG_TM1638_CLOCK_PIN, CFG_TM1638_STROBE_PIN);


void dreInit(){
      // Button -- Does not need declaration upReq;
    // Button -- Does not need declaration downReq;
    // Position -- Does not need declaration loadPos;
    dre.upReqAcq = FALSE;
    dre.downReqAcq = FALSE;
    dre.upReqDI = FALSE;
    dre.downReqDI = FALSE;
    dre.posMode = CFG_POS_MODE_STOP;
    dre.actAction = 0;
    dre.pwmActAction = 0;
    dre.doDirFw = FALSE;
    dre.doDirBw = FALSE;
    dre.actEnable = FALSE;
    dre.actDirection = CFG_ACT_DIRECTION_QUIET;
    dre.rectifiedActAction = 0;
    dre.rectifiedActDirection = CFG_ACT_DIRECTION_QUIET;
    dre.loadPosAcq = 0;
    dre.appliedActDirection = CFG_ACT_DIRECTION_QUIET;
    dre.actDrvTimer = 0L;
    // Power -- Does not need declaration loadTorque;
    // Power -- Does not need declaration actPosPow;
    // Power -- Does not need declaration actNegPow;
    dre.loadPosAI = 0;
    dre.upButTimer = 0L;
    dre.downButTimer = 0L;
    dre.loadPosUpSwchDI = FALSE;
    dre.loadPosDownSwchDI = FALSE;
    dre.posAchieved = FALSE;
    dre.ctrlError = FALSE;
    // Current -- Does not need declaration driveCurrent;
    dre.driveCurrentAI = 0;
    dre.driveCurrentAcq = O;
    dre.currentError = FALSE;
    dre.brokenChainError = FALSE;
    dre.stuckActError = FALSE;
    dre.loadPosUpSwchAcq = FALSE;
    dre.loadPosDownSwchAcq = FALSE;
    dre.upSwitchTimer = 0L;
    dre.downSwitchTimer = 0L;
}

/* ---------------------------------------*/

/***** Setup & Startup functions *****/

void setup() {

  ////////////// Platform init
  timerSetCycleTime(CYCLE_TIME_IN_MICROS);

  ////////////// DRE init
  dreInit();

  ////////////// Pinout init
  pinoutInit();

  ////////////// Input init
  prjInputInit();

  ////////////// FSM init

  ////////////// Output Init
  prjOutputInit();

  ////////////// Comms init 
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

}

/* ---------------------------------------*/

/***** Main Loop *****/

void loop()
{
  // ----------- Functionality ----------------

  ////////////// Input task 
  prjInput();

  ////////////// FSM tasks

  // ----------- End of Cycle Synchronization ----------------
#if 1
  // Now the microcontroller will loose time until the end of cycle sincronization time expires
  boolean timSync=timerSync();
  while(timSync==false){
    if ((CYCLE_TIME_MICROS-elapsedMicros)>CYCLE_SECURITY_TIME_MICROS){
    }
    // timerSync returns true when the end of cycle syncronization time expired.
    timSync=timerSync();
  }
#endif  

  ////////////// Output task 
  prjOutput();

}
