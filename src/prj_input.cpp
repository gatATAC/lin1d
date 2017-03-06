#include "prj_cfg.h"
#include "prj_input.h"
#include "prj_pinout.h"
#include "DRE.h"
#include <Arduino.h>
#include <TM1638.h>

extern TM1638 module;

extern t_dre dre;

void prjInputInit(void) {

}

void prjInput(void) {
    uint8_t i;

    byte keys = module.getButtons();
    for (i = 0; i < NUM_BUTTONS; i++) {
        //    dre.buttonState[i] = (keys & (0x01<<i))>0;
    }
    //  dre.sliderA=analogRead(CFG_SLIDER_DTA_PIN);
    //  dre.sliderB=analogRead(CFG_SLIDER_DTB_PIN);
    dre.loadPosUpSwchDI = adquirir_loadPosUpSwchDI();
    dre.loadPosDownSwchDI = adquirir_loadPosDownSwchDI();
}
