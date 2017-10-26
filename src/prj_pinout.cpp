#include "gttc_types.h"
#include "prj_cfg.h"
#include "prj_pinout.h"
#include "FM1DRE.h"
#include "POLDRE.h"
#include <Arduino.h>

#include <TM1638.h>
extern TM1638 module;

void pinoutInit(void) {

    uint8_t i;

    setup_FM1loadPosUpSwchDI();
    setup_POLloadPosUpSwchDI();
    setup_FM1loadPosDownSwchDI();
    setup_POLloadPosDownSwchDI();

    pinMode(CFG_SLIDER_DTA_PIN, INPUT);
    pinMode(CFG_SLIDER_DTB_PIN, INPUT);

    module.setDisplayToDecNumber(101010, 0);

#ifdef CFG_FM1_USE_MOTORCTRL
    analogWriteFrequency(PORT_FM1pwmActAction, CFG_MOTORCTRL_FREQUENCY);
    pinMode(PORT_FM1pwmActAction, OUTPUT);
    pinMode(PORT_FM1doDirFw, OUTPUT);
    pinMode(PORT_FM1doDirBw, OUTPUT);
#endif
}
