#include "gttc_types.h"
#include "prj_cfg.h"
#include "prj_pinout.h"
#include <Arduino.h>

#include <TM1638.h>
extern TM1638 module;

void pinoutInit(void) {

    uint8_t i;

    pinMode(PORT_FM1loadPosUpSwchDI, INPUT_PULLUP);
    pinMode(PORT_FM1loadPosDownSwchDI, INPUT_PULLUP);

    pinMode(CFG_SLIDER_DTA_PIN, INPUT);
    pinMode(CFG_SLIDER_DTB_PIN, INPUT);

    module.setDisplayToDecNumber(101010, 0);

#ifdef CFG_USE_MOTORCTRL
    analogWriteFrequency(PORT_FM1pwmActAction, CFG_MOTORCTRL_FREQUENCY);
    pinMode(PORT_FM1pwmActAction, OUTPUT);
    pinMode(PORT_FM1doDirFw, OUTPUT);
    pinMode(PORT_FM1doDirBw, OUTPUT);
#endif
}












