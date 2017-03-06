#include "prj_cfg.h"
#include "prj_input.h"
#include "prj_pinout.h"
#include "DRE.h"
#include <Arduino.h>
#include <TM1638.h>

extern TM1638 module;

extern t_dre dre;
extern t_diag diag;

void prjInputInit(void) {

}

void prjInput(void) {
  // Acquire TM1638 buttons
  dre.hmibuttons = module.getButtons();

#define DEBUG_SWITCHES

#ifdef DEBUG_SWITCHES
  diag.enable_loadPosUpSwchDI = TRUE;
  if (dre.hmibuttons & CFG_HMIBUT_SWITCH_UP_MASK) {
    diag.loadPosUpSwchDI = TRUE;
  } else {
    diag.loadPosUpSwchDI = FALSE;    
  }
    
  diag.enable_loadPosDownSwchDI = TRUE;
  if (dre.hmibuttons & CFG_HMIBUT_SWITCH_DOWN_MASK) {
    diag.loadPosDownSwchDI = TRUE;
  } else {
    diag.loadPosDownSwchDI = FALSE;    
  }
#else
  diag.enable_loadPosUpSwchDI = FALSE;
  diag.enable_loadPosDownSwchDI = FALSE;  
#endif

    // Acquire end-of-travels
    dre.loadPosUpSwchDI = adquirir_loadPosUpSwchDI();
    dre.loadPosDownSwchDI = adquirir_loadPosDownSwchDI();

    //  dre.sliderA=analogRead(CFG_SLIDER_DTA_PIN);
    //  dre.sliderB=analogRead(CFG_SLIDER_DTB_PIN);

}


