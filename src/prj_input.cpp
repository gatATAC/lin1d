#include "prj_cfg.h"
#include "prj_input.h"
#include "prj_pinout.h"
#include "DRE.h"
#include <Arduino.h>
#include <TM1638.h>

extern TM1638 module;

extern t_dreFM1 dreFM1;
extern t_diagFM1 diagFM1;

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

    // Acquire end-of-travels
    dreFM1.loadPosUpSwchDI = adquirir_FM1loadPosUpSwchDI();
    dreFM1.loadPosDownSwchDI = adquirir_FM1loadPosDownSwchDI();

    //  dreFM1.sliderA=analogRead(CFG_SLIDER_DTA_PIN);
    //  dreFM1.sliderB=analogRead(CFG_SLIDER_DTB_PIN);

}






