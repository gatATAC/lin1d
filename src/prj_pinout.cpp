#include "gttc_types.h"
#include "prj_cfg.h"
#include "prj_pinout.h"
#include <Arduino.h>

#include <TM1638.h>
extern TM1638 module;

void pinoutInit(void) {

    uint8_t i;

    pinMode(CFG_ENDSWITCH_1_PIN, INPUT_PULLUP);

    pinMode(CFG_ENDSWITCH_2_PIN, INPUT_PULLUP);

    pinMode(CFG_SLIDER_DTA_PIN, INPUT);
    pinMode(CFG_SLIDER_DTB_PIN, INPUT);

    module.setDisplayToDecNumber(101010, 0);

#ifdef CFG_USE_MOTORCTRL

    analogWriteFrequency(CFG_MOTORCTRL_PWM_PIN, CFG_MOTORCTRL_FREQUENCY);
    pinMode(CFG_MOTORCTRL_PWM_PIN, OUTPUT);
    pinMode(CFG_MOTORCTRL_IN3_PIN, OUTPUT);
    pinMode(CFG_MOTORCTRL_IN4_PIN, OUTPUT);

#endif
}
