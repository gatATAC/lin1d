#include "prj_cfg.h"
#include "prj_input.h"
#include "prj_pinout.h"
#include "FM1DRE.h"
#include "POLDRE.h"
#include <Arduino.h>
#include <TM1638.h>

extern TM1638 module;

extern t_dreFM1 dreFM1;
extern t_diagFM1 diagFM1;

extern t_drePOL drePOL;
extern t_diagPOL diagPOL;

void prjInputInit(void) {

}

void prjInput(void) {
    // Acquire TM1638 buttons
    dreFM1.hmibuttons = module.getButtons();

#define DEBUG_SWITCHES

#ifdef DEBUG_SWITCHES
    diagFM1.enable_loadPosUpSwchDI = TRUE;
    if (dreFM1.hmibuttons & CFG_FM1_HMIBUT_SWITCH_UP_MASK) {
        diagFM1.loadPosUpSwchDI = TRUE;
    } else {
        diagFM1.loadPosUpSwchDI = FALSE;
    }

    diagFM1.enable_loadPosDownSwchDI = TRUE;
    if (dreFM1.hmibuttons & CFG_FM1_HMIBUT_SWITCH_DOWN_MASK) {
        diagFM1.loadPosDownSwchDI = TRUE;
    } else {
        diagFM1.loadPosDownSwchDI = FALSE;
    }
#else
    diagFM1.enable_loadPosUpSwchDI = FALSE;
    diagFM1.enable_loadPosDownSwchDI = FALSE;
#endif

#ifdef DEBUG_SWITCHES
    diagPOL.enable_loadPosUpSwchDI = TRUE;
    if (dreFM1.hmibuttons & CFG_POL_HMIBUT_SWITCH_UP_MASK) { // Both subsystems (POL and FM1) share same hmi
        diagPOL.loadPosUpSwchDI = TRUE;
    } else {
        diagPOL.loadPosUpSwchDI = FALSE;
    }

    diagPOL.enable_loadPosDownSwchDI = TRUE;
    if (dreFM1.hmibuttons & CFG_POL_HMIBUT_SWITCH_DOWN_MASK) { // Both subsystems (POL and FM1) share same hmi
        diagPOL.loadPosDownSwchDI = TRUE;
    } else {
        diagPOL.loadPosDownSwchDI = FALSE;
    }
#else
    diagPOL.enable_loadPosUpSwchDI = FALSE;
    diagPOL.enable_loadPosDownSwchDI = FALSE;
#endif

    // Acquire end-of-travels for FM1
    dreFM1.loadPosUpSwchDI = adquirir_FM1loadPosUpSwchDI();
    dreFM1.loadPosDownSwchDI = adquirir_FM1loadPosDownSwchDI();

    // Acquire end-of-travels for POL
    drePOL.loadPosUpSwchDI = adquirir_POLloadPosUpSwchDI();
    drePOL.loadPosDownSwchDI = adquirir_POLloadPosDownSwchDI();

#ifdef CFG_POL_USE_SLIDER
    dreFM1.loadPosAI = acquire_FM1loadPosAI();
#endif

}
