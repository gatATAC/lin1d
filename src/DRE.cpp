#include "DRE.h"

// --- DRE data structure declaration ---
t_dre dre;
t_diag diag;

// --- DRE flow initialization functions ---



// upReq flow acquisition
// (setup input disabled for Button type)
// upReq flow synthesis
// (output disabled for Button type)


// downReq flow acquisition
// (setup input disabled for Button type)
// downReq flow synthesis
// (output disabled for Button type)


// loadPos flow acquisition
// (setup input disabled for Position type)
// loadPos flow synthesis
// (output disabled for Position type)


// upReqAcq flow acquisition
// (setup input disabled for Variable type)
// upReqAcq flow synthesis
// (output disabled for Variable type)


// downReqAcq flow acquisition
// (setup input disabled for Variable type)
// downReqAcq flow synthesis
// (output disabled for Variable type)


// upReqDI flow acquisition

void setup_upReqDI(void) {
    pinMode(PORT_upReqDI, INPUT_PULLUP);
};
// upReqDI flow synthesis
// (output disabled for DI_pu type)


// downReqDI flow acquisition

void setup_downReqDI(void) {
    pinMode(PORT_downReqDI, INPUT_PULLUP);
};
// downReqDI flow synthesis
// (output disabled for DI_pu type)


// posMode flow acquisition
// (setup input disabled for Variable type)
// posMode flow synthesis
// (output disabled for Variable type)


// actAction flow acquisition
// (setup input disabled for Variable type)
// actAction flow synthesis
// (output disabled for Variable type)


// pwmActAction flow acquisition
// (setup input disabled for PWM type)
// pwmActAction flow synthesis

void setup_pwmActAction(void) {
#ifndef _PWM_RES_SET_
#define _PWM_RES_SET_
    analogWriteResolution(CFG_PWM_RESOLUTION);
#endif
    analogWriteFrequency(PORT_pwmActAction, PORT_pwmActAction_FREQ);
};



// doDirFw flow acquisition

void setup_doDirFw_input(void) {
    pinMode(PORT_doDirFw, INPUT);
};

// doDirFw flow synthesis

void setup_doDirFw_output(void) {
    pinMode(PORT_doDirFw, INPUT);
};


// doDirBw flow acquisition

void setup_doDirBw_input(void) {
    pinMode(PORT_doDirBw, INPUT);
};

// doDirBw flow synthesis

void setup_doDirBw_output(void) {
    pinMode(PORT_doDirBw, INPUT);
};


// actEnable flow acquisition
// (setup input disabled for Variable type)
// actEnable flow synthesis
// (output disabled for Variable type)


// actDirection flow acquisition
// (setup input disabled for Variable type)
// actDirection flow synthesis
// (output disabled for Variable type)


// rectifiedActAction flow acquisition
// (setup input disabled for PWMDuty type)
// rectifiedActAction flow synthesis
// (output disabled for PWMDuty type)


// rectifiedActDirection flow acquisition
// (setup input disabled for Variable type)
// rectifiedActDirection flow synthesis
// (output disabled for Variable type)


// loadPosAcq flow acquisition

// loadPosAcq flow synthesis
// (output disabled for ADC type)


// appliedActDirection flow acquisition
// (setup input disabled for Variable type)
// appliedActDirection flow synthesis
// (output disabled for Variable type)


// actDrvTimer flow acquisition
// (setup input disabled for Timer type)
// actDrvTimer flow synthesis
// (output disabled for Timer type)


// loadTorque flow acquisition
// (setup input disabled for Power type)
// loadTorque flow synthesis
// (output disabled for Power type)


// actPosPow flow acquisition
// (setup input disabled for Power type)
// actPosPow flow synthesis
// (output disabled for Power type)


// actNegPow flow acquisition
// (setup input disabled for Power type)
// actNegPow flow synthesis
// (output disabled for Power type)


// loadPosAI flow acquisition

// loadPosAI flow synthesis
// (output disabled for ADC type)


// upButTimer flow acquisition
// (setup input disabled for Timer type)
// upButTimer flow synthesis
// (output disabled for Timer type)


// downButTimer flow acquisition
// (setup input disabled for Timer type)
// downButTimer flow synthesis
// (output disabled for Timer type)


// loadPosUpSwch flow acquisition
// (setup input disabled for Switch type)
// loadPosUpSwch flow synthesis
// (output disabled for Switch type)


// loadPosDownSwch flow acquisition
// (setup input disabled for Switch type)
// loadPosDownSwch flow synthesis
// (output disabled for Switch type)


// loadPosUpSwchDI flow acquisition

void setup_loadPosUpSwchDI(void) {
    pinMode(PORT_loadPosUpSwchDI, INPUT_PULLUP);
};
// loadPosUpSwchDI flow synthesis
// (output disabled for DI_pu type)


// loadPosDownSwchDI flow acquisition

void setup_loadPosDownSwchDI(void) {
    pinMode(PORT_loadPosDownSwchDI, INPUT_PULLUP);
};
// loadPosDownSwchDI flow synthesis
// (output disabled for DI_pu type)


// posAchieved flow acquisition
// (setup input disabled for Flag type)
// posAchieved flow synthesis
// (output disabled for Flag type)


// ctrlError flow acquisition
// (setup input disabled for Flag type)
// ctrlError flow synthesis
// (output disabled for Flag type)


// driveCurrent flow acquisition
// (setup input disabled for Current type)
// driveCurrent flow synthesis
// (output disabled for Current type)


// driveCurrentAI flow acquisition

// driveCurrentAI flow synthesis
// (output disabled for ADC type)


// driveCurrentAcq flow acquisition
// (setup input disabled for Variable type)
// driveCurrentAcq flow synthesis
// (output disabled for Variable type)


// currentError flow acquisition
// (setup input disabled for Flag type)
// currentError flow synthesis
// (output disabled for Flag type)


// brokenChainError flow acquisition
// (setup input disabled for Flag type)
// brokenChainError flow synthesis
// (output disabled for Flag type)


// stuckActError flow acquisition
// (setup input disabled for Flag type)
// stuckActError flow synthesis
// (output disabled for Flag type)


// loadPosUpSwchAcq flow acquisition
// (setup input disabled for Flag type)
// loadPosUpSwchAcq flow synthesis
// (output disabled for Flag type)


// loadPosDownSwchAcq flow acquisition
// (setup input disabled for Flag type)
// loadPosDownSwchAcq flow synthesis
// (output disabled for Flag type)


// upSwitchTimer flow acquisition
// (setup input disabled for Timer type)
// upSwitchTimer flow synthesis
// (output disabled for Timer type)


// downSwitchTimer flow acquisition
// (setup input disabled for Timer type)
// downSwitchTimer flow synthesis
// (output disabled for Timer type)



// --- DRE flow acquisition and flow synthesis functions ---


// upReq flow acquisition
// (input disabled for Button type)
// upReq flow synthesis
// (output disabled for Button type)


// downReq flow acquisition
// (input disabled for Button type)
// downReq flow synthesis
// (output disabled for Button type)


// loadPos flow acquisition
// (input disabled for Position type)
// loadPos flow synthesis
// (output disabled for Position type)


// upReqAcq flow acquisition
// (input disabled for Variable type)
// upReqAcq flow synthesis
// (output disabled for Variable type)


// downReqAcq flow acquisition
// (input disabled for Variable type)
// downReqAcq flow synthesis
// (output disabled for Variable type)


// upReqDI flow acquisition

BOOL adquirir_upReqDI(void) {
#ifdef _DIAG_ACTIVE 
    if (diag.enable_upReqDI == TRUE) {
        return diag.upReqDI;
    } else {
#endif 
        return digitalRead(PORT_upReqDI);
#ifdef _DIAG_ACTIVE 
    }
#endif 
};
// upReqDI flow synthesis
// (output disabled for DI_pu type)


// downReqDI flow acquisition

BOOL adquirir_downReqDI(void) {
#ifdef _DIAG_ACTIVE 
    if (diag.enable_downReqDI == TRUE) {
        return diag.downReqDI;
    } else {
#endif 
        return digitalRead(PORT_downReqDI);
#ifdef _DIAG_ACTIVE 
    }
#endif 
};
// downReqDI flow synthesis
// (output disabled for DI_pu type)


// posMode flow acquisition
// (input disabled for Variable type)
// posMode flow synthesis
// (output disabled for Variable type)


// actAction flow acquisition
// (input disabled for Variable type)
// actAction flow synthesis
// (output disabled for Variable type)


// pwmActAction flow acquisition
// (input disabled for PWM type)
// pwmActAction flow synthesis

void synthesize_pwmActAction(t_pwm value) {
    analogWrite(PORT_pwmActAction, value);
};


// doDirFw flow acquisition

BOOL adquirir_doDirFw(void) {
#ifdef _DIAG_ACTIVE 
    if (diag.enable_doDirFw == TRUE) {
        return diag.doDirFw;
    } else {
#endif 
        return digitalRead(PORT_doDirFw);
#ifdef _DIAG_ACTIVE 
    }
#endif 
};
// doDirFw flow synthesis

void sintetizar_doDirFw(BOOL valor) {
#ifdef _DIAG_ACTIVE 
    if (diag.enable_doDirFw == TRUE) {
        digitalWrite(PORT_doDirFw, diag.doDirFw);
    } else {
#endif 
        digitalWrite(PORT_doDirFw, valor);
#ifdef _DIAG_ACTIVE 
    }
#endif 
};


// doDirBw flow acquisition

BOOL adquirir_doDirBw(void) {
#ifdef _DIAG_ACTIVE 
    if (diag.enable_doDirBw == TRUE) {
        return diag.doDirBw;
    } else {
#endif 
        return digitalRead(PORT_doDirBw);
#ifdef _DIAG_ACTIVE 
    }
#endif 
};
// doDirBw flow synthesis

void sintetizar_doDirBw(BOOL valor) {
#ifdef _DIAG_ACTIVE 
    if (diag.enable_doDirBw == TRUE) {
        digitalWrite(PORT_doDirBw, diag.doDirBw);
    } else {
#endif 
        digitalWrite(PORT_doDirBw, valor);
#ifdef _DIAG_ACTIVE 
    }
#endif 
};


// actEnable flow acquisition
// (input disabled for Variable type)
// actEnable flow synthesis
// (output disabled for Variable type)


// actDirection flow acquisition
// (input disabled for Variable type)
// actDirection flow synthesis
// (output disabled for Variable type)


// rectifiedActAction flow acquisition
// (input disabled for PWMDuty type)
// rectifiedActAction flow synthesis
// (output disabled for PWMDuty type)


// rectifiedActDirection flow acquisition
// (input disabled for Variable type)
// rectifiedActDirection flow synthesis
// (output disabled for Variable type)


// loadPosAcq flow acquisition

uint16_t acquire_loadPosAcq(void) {
    return analogRead(PORT_loadPosAcq);
};
// loadPosAcq flow synthesis
// (output disabled for ADC type)


// appliedActDirection flow acquisition
// (input disabled for Variable type)
// appliedActDirection flow synthesis
// (output disabled for Variable type)


// actDrvTimer flow acquisition
// (input disabled for Timer type)
// actDrvTimer flow synthesis
// (output disabled for Timer type)


// loadTorque flow acquisition
// (input disabled for Power type)
// loadTorque flow synthesis
// (output disabled for Power type)


// actPosPow flow acquisition
// (input disabled for Power type)
// actPosPow flow synthesis
// (output disabled for Power type)


// actNegPow flow acquisition
// (input disabled for Power type)
// actNegPow flow synthesis
// (output disabled for Power type)


// loadPosAI flow acquisition

uint16_t acquire_loadPosAI(void) {
    return analogRead(PORT_loadPosAI);
};
// loadPosAI flow synthesis
// (output disabled for ADC type)


// upButTimer flow acquisition
// (input disabled for Timer type)
// upButTimer flow synthesis
// (output disabled for Timer type)


// downButTimer flow acquisition
// (input disabled for Timer type)
// downButTimer flow synthesis
// (output disabled for Timer type)


// loadPosUpSwch flow acquisition
// (input disabled for Switch type)
// loadPosUpSwch flow synthesis
// (output disabled for Switch type)


// loadPosDownSwch flow acquisition
// (input disabled for Switch type)
// loadPosDownSwch flow synthesis
// (output disabled for Switch type)


// loadPosUpSwchDI flow acquisition

BOOL adquirir_loadPosUpSwchDI(void) {
#ifdef _DIAG_ACTIVE 
    if (diag.enable_loadPosUpSwchDI == TRUE) {
        return diag.loadPosUpSwchDI;
    } else {
#endif 
        return digitalRead(PORT_loadPosUpSwchDI);
#ifdef _DIAG_ACTIVE 
    }
#endif 
};
// loadPosUpSwchDI flow synthesis
// (output disabled for DI_pu type)


// loadPosDownSwchDI flow acquisition

BOOL adquirir_loadPosDownSwchDI(void) {
#ifdef _DIAG_ACTIVE 
    if (diag.enable_loadPosDownSwchDI == TRUE) {
        return diag.loadPosDownSwchDI;
    } else {
#endif 
        return digitalRead(PORT_loadPosDownSwchDI);
#ifdef _DIAG_ACTIVE 
    }
#endif 
};
// loadPosDownSwchDI flow synthesis
// (output disabled for DI_pu type)


// posAchieved flow acquisition
// (input disabled for Flag type)
// posAchieved flow synthesis
// (output disabled for Flag type)


// ctrlError flow acquisition
// (input disabled for Flag type)
// ctrlError flow synthesis
// (output disabled for Flag type)


// driveCurrent flow acquisition
// (input disabled for Current type)
// driveCurrent flow synthesis
// (output disabled for Current type)


// driveCurrentAI flow acquisition

uint16_t acquire_driveCurrentAI(void) {
    return analogRead(PORT_driveCurrentAI);
};
// driveCurrentAI flow synthesis
// (output disabled for ADC type)


// driveCurrentAcq flow acquisition
// (input disabled for Variable type)
// driveCurrentAcq flow synthesis
// (output disabled for Variable type)


// currentError flow acquisition
// (input disabled for Flag type)
// currentError flow synthesis
// (output disabled for Flag type)


// brokenChainError flow acquisition
// (input disabled for Flag type)
// brokenChainError flow synthesis
// (output disabled for Flag type)


// stuckActError flow acquisition
// (input disabled for Flag type)
// stuckActError flow synthesis
// (output disabled for Flag type)


// loadPosUpSwchAcq flow acquisition
// (input disabled for Flag type)
// loadPosUpSwchAcq flow synthesis
// (output disabled for Flag type)


// loadPosDownSwchAcq flow acquisition
// (input disabled for Flag type)
// loadPosDownSwchAcq flow synthesis
// (output disabled for Flag type)


// upSwitchTimer flow acquisition
// (input disabled for Timer type)
// upSwitchTimer flow synthesis
// (output disabled for Timer type)


// downSwitchTimer flow acquisition
// (input disabled for Timer type)
// downSwitchTimer flow synthesis
// (output disabled for Timer type)