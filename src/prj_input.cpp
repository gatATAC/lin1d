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

#ifdef CFG_SWITCHES_EMULATED_BY_HMI
void prjInputDiag(void){
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
}
#endif

void prjInput(void) {
    // Acquire TM1638 buttons
    dreFM1.hmibuttons = module.getButtons();

#ifdef CFG_SWITCHES_EMULATED_BY_HMI
    prjInputDiag();
#else
    diagFM1.enable_loadPosUpSwchDI = FALSE;
    diagFM1.enable_loadPosDownSwchDI = FALSE;
#endif

#ifdef CFG_SWITCHES_EMULATED_BY_HMI
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
    #if _DEBUG_FM1_UPSWITCH
    if (dreFM1.loadPosUpSwchDI == 0) {
      Serial.println("FM1 Arriba!");
    }
    #endif
    dreFM1.loadPosDownSwchDI = adquirir_FM1loadPosDownSwchDI();
    #if _DEBUG_FM1_DOWNSWITCH    
    if (dreFM1.loadPosDownSwchDI == 0) {
      Serial.println("FM1 Abajo!");
    }
    #endif
    // Acquire end-of-travels for POL
    drePOL.loadPosUpSwchDI = adquirir_POLloadPosUpSwchDI();
    #if _DEBUG_POL_UPSWITCH
    if (drePOL.loadPosUpSwchDI == 0) {
      Serial.println("POL Arriba!");
    }
    #endif
    drePOL.loadPosDownSwchDI = adquirir_POLloadPosDownSwchDI();
    #if _DEBUG_POL_DOWNSWITCH
    if (drePOL.loadPosDownSwchDI == 0) {
      Serial.println("POL Abajo!");
    }
    #endif

#ifdef CFG_FM1_USE_SLIDER
    dreFM1.loadPosAI = acquire_FM1loadPosAI();
#endif

}
