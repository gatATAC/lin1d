#include "gttc_types.h"
#include "prj_cfg.h"
#include "prj_pinout.h"
#include <Arduino.h>

#include <TM1638.h>
extern TM1638 module;

void pinoutInit(void) {

    uint8_t i;

    pinMode(PORT_loadPosUpSwchDI, INPUT_PULLUP);

    pinMode(PORT_loadPosDownSwchDI, INPUT_PULLUP);

    pinMode(CFG_SLIDER_DTA_PIN, INPUT);
    pinMode(CFG_SLIDER_DTB_PIN, INPUT);

    module.setDisplayToDecNumber(101010, 0);

#ifdef CFG_USE_MOTORCTRL

    analogWriteFrequency(PORT_pwmActAction, CFG_MOTORCTRL_FREQUENCY);
    pinMode(PORT_pwmActAction, OUTPUT);
    pinMode(PORT_doDirFw, OUTPUT);
    pinMode(PORT_doDirBw, OUTPUT);

#endif
}


