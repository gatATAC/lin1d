#include "POLDRE.h"

// --- DRE data structure declaration ---
t_drePOL drePOL;
t_diagPOL diagPOL;

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
void setup_POLupReqDI(void){ 
pinMode(PORT_POLupReqDI, INPUT_PULLUP); 
};
// upReqDI flow synthesis
// (output disabled for DI_pu type)

  
// downReqDI flow acquisition
void setup_POLdownReqDI(void){ 
pinMode(PORT_POLdownReqDI, INPUT_PULLUP); 
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
void setup_POLpwmActAction(void){ 
#ifndef _PWM_RES_SET_
#define _PWM_RES_SET_
analogWriteResolution(CFG_PWM_RESOLUTION);
#endif
analogWriteFrequency(PORT_POLpwmActAction, PORT_POLpwmActAction_FREQ);
};


  
// doDirFw flow acquisition
void setup_POLdoDirFw_input(void){ 
pinMode(PORT_POLdoDirFw, INPUT);
};

// doDirFw flow synthesis
void setup_POLdoDirFw_output(void){ 
pinMode(PORT_POLdoDirFw, INPUT);
};

  
// doDirBw flow acquisition
void setup_POLdoDirBw_input(void){ 
pinMode(PORT_POLdoDirBw, INPUT);
};

// doDirBw flow synthesis
void setup_POLdoDirBw_output(void){ 
pinMode(PORT_POLdoDirBw, INPUT);
};

  
// actEnable flow acquisition
// (setup input disabled for Variable type)
// actEnable flow synthesis
// (output disabled for Variable type)

  
// actDirection flow acquisition
// (setup input disabled for Variable type)
// actDirection flow synthesis
// (output disabled for Variable type)

  
// appliedActAction flow acquisition
// (setup input disabled for PWMDuty type)
// appliedActAction flow synthesis
// (output disabled for PWMDuty type)

  
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

  
// dcTorque flow acquisition
// (setup input disabled for TBD type)
// dcTorque flow synthesis
// (output disabled for TBD type)

  
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
void setup_POLloadPosUpSwchDI(void){ 
pinMode(PORT_POLloadPosUpSwchDI, INPUT_PULLUP); 
};
// loadPosUpSwchDI flow synthesis
// (output disabled for DI_pu type)

  
// loadPosDownSwchDI flow acquisition
void setup_POLloadPosDownSwchDI(void){ 
pinMode(PORT_POLloadPosDownSwchDI, INPUT_PULLUP); 
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

  
// hmibut0 flow acquisition
// (setup input disabled for Button type)
// hmibut0 flow synthesis
// (output disabled for Button type)

  
// hmibut1 flow acquisition
// (setup input disabled for Button type)
// hmibut1 flow synthesis
// (output disabled for Button type)

  
// hmibut2 flow acquisition
// (setup input disabled for Button type)
// hmibut2 flow synthesis
// (output disabled for Button type)

  
// hmibut3 flow acquisition
// (setup input disabled for Button type)
// hmibut3 flow synthesis
// (output disabled for Button type)

  
// hmibut4 flow acquisition
// (setup input disabled for Button type)
// hmibut4 flow synthesis
// (output disabled for Button type)

  
// hmibut5 flow acquisition
// (setup input disabled for Button type)
// hmibut5 flow synthesis
// (output disabled for Button type)

  
// hmibut6 flow acquisition
// (setup input disabled for Button type)
// hmibut6 flow synthesis
// (output disabled for Button type)

  
// hmibut7 flow acquisition
// (setup input disabled for Button type)
// hmibut7 flow synthesis
// (output disabled for Button type)

  
// hmiled0 flow acquisition
// (setup input disabled for LED type)
// hmiled0 flow synthesis
// (output disabled for LED type)

  
// hmiled1 flow acquisition
// (setup input disabled for LED type)
// hmiled1 flow synthesis
// (output disabled for LED type)

  
// hmiled2 flow acquisition
// (setup input disabled for LED type)
// hmiled2 flow synthesis
// (output disabled for LED type)

  
// hmiled3 flow acquisition
// (setup input disabled for LED type)
// hmiled3 flow synthesis
// (output disabled for LED type)

  
// hmiled4 flow acquisition
// (setup input disabled for LED type)
// hmiled4 flow synthesis
// (output disabled for LED type)

  
// hmiled5 flow acquisition
// (setup input disabled for LED type)
// hmiled5 flow synthesis
// (output disabled for LED type)

  
// hmiled6 flow acquisition
// (setup input disabled for LED type)
// hmiled6 flow synthesis
// (output disabled for LED type)

  
// hmiled7 flow acquisition
// (setup input disabled for LED type)
// hmiled7 flow synthesis
// (output disabled for LED type)

  
// hmidigit0 flow acquisition
// (setup input disabled for DIGIT type)
// hmidigit0 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit1 flow acquisition
// (setup input disabled for DIGIT type)
// hmidigit1 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit2 flow acquisition
// (setup input disabled for DIGIT type)
// hmidigit2 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit3 flow acquisition
// (setup input disabled for DIGIT type)
// hmidigit3 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit4 flow acquisition
// (setup input disabled for DIGIT type)
// hmidigit4 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit5 flow acquisition
// (setup input disabled for DIGIT type)
// hmidigit5 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit6 flow acquisition
// (setup input disabled for DIGIT type)
// hmidigit6 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit7 flow acquisition
// (setup input disabled for DIGIT type)
// hmidigit7 flow synthesis
// (output disabled for DIGIT type)

  
// hmidata flow acquisition
// (setup input disabled for Bus type)
// hmidata flow synthesis
// (output disabled for Bus type)

  
// hmiclock flow acquisition
// (setup input disabled for Clock type)
// hmiclock flow synthesis
// (output disabled for Clock type)

  
// hmistrobe flow acquisition
// (setup input disabled for Bus type)
// hmistrobe flow synthesis
// (output disabled for Bus type)

  
// hmibuttons flow acquisition
// (setup input disabled for Variable type)
// hmibuttons flow synthesis
// (output disabled for Variable type)

  
// hmileds flow acquisition
// (setup input disabled for Variable type)
// hmileds flow synthesis
// (output disabled for Variable type)

  
// hmidigits flow acquisition
// (setup input disabled for Variable type)
// hmidigits flow synthesis
// (output disabled for Variable type)

  
// rectifiedActAction flow acquisition
// (setup input disabled for PWMDuty type)
// rectifiedActAction flow synthesis
// (output disabled for PWMDuty type)

  
// forcedPos flow acquisition
// (setup input disabled for Variable type)
// forcedPos flow synthesis
// (output disabled for Variable type)

  
// stepperAngle flow acquisition
// (setup input disabled for Position type)
// stepperAngle flow synthesis
// (output disabled for Position type)

  
// stepperSetPoint flow acquisition
// (setup input disabled for Variable type)
// stepperSetPoint flow synthesis
// (output disabled for Variable type)

  
// stepperEnable flow acquisition
// (setup input disabled for Flag type)
// stepperEnable flow synthesis
// (output disabled for Flag type)

  
// stepCtrlA flow acquisition
void setup_POLstepCtrlA_input(void){ 
pinMode(PORT_POLstepCtrlA, INPUT);
};

// stepCtrlA flow synthesis
void setup_POLstepCtrlA_output(void){ 
pinMode(PORT_POLstepCtrlA, INPUT);
};

  
// stepCtrlB flow acquisition
void setup_POLstepCtrlB_input(void){ 
pinMode(PORT_POLstepCtrlB, INPUT);
};

// stepCtrlB flow synthesis
void setup_POLstepCtrlB_output(void){ 
pinMode(PORT_POLstepCtrlB, INPUT);
};

  
// stepA flow acquisition
// (setup input disabled for Power type)
// stepA flow synthesis
// (output disabled for Power type)

  
// stepB flow acquisition
void setup_POLstepB_input(void){ 
pinMode(PORT_POLstepB, INPUT);
};

// stepB flow synthesis
void setup_POLstepB_output(void){ 
pinMode(PORT_POLstepB, INPUT);
};

  
// pwmServoAngleFdback flow acquisition
// (setup input disabled for Variable type)
// pwmServoAngleFdback flow synthesis
// (output disabled for Variable type)

  
// pwmServoEnable flow acquisition
// (setup input disabled for Variable type)
// pwmServoEnable flow synthesis
// (output disabled for Variable type)

  
// pwmServoSetPoint flow acquisition
// (setup input disabled for Variable type)
// pwmServoSetPoint flow synthesis
// (output disabled for Variable type)

  
// pwmServoActive flow acquisition
// (setup input disabled for Flag type)
// pwmServoActive flow synthesis
// (output disabled for Flag type)

  
// pwmServoPwm flow acquisition
// (setup input disabled for Flag type)
// pwmServoPwm flow synthesis
// (output disabled for Flag type)

  
// pwmServoAngle flow acquisition
// (setup input disabled for Position type)
// pwmServoAngle flow synthesis
// (output disabled for Position type)

  
// loadTorque flow acquisition
// (setup input disabled for TBD type)
// loadTorque flow synthesis
// (output disabled for TBD type)



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
BOOL adquirir_POLupReqDI(void){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_upReqDI==TRUE) { 
return diagPOL.upReqDI; 
} else { 
#endif 
return digitalRead(PORT_POLupReqDI); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};
// upReqDI flow synthesis
// (output disabled for DI_pu type)

  
// downReqDI flow acquisition
BOOL adquirir_POLdownReqDI(void){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_downReqDI==TRUE) { 
return diagPOL.downReqDI; 
} else { 
#endif 
return digitalRead(PORT_POLdownReqDI); 
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
void synthesize_POLpwmActAction(t_pwm value){ 
analogWrite(PORT_POLpwmActAction, value); 
};

  
// doDirFw flow acquisition
BOOL adquirir_POLdoDirFw(void){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_doDirFw==TRUE) { 
return diagPOL.doDirFw; 
} else { 
#endif 
return digitalRead(PORT_POLdoDirFw); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};
// doDirFw flow synthesis
void sintetizar_POLdoDirFw(BOOL valor){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_doDirFw==TRUE) { 
digitalWrite(PORT_POLdoDirFw,diagPOL.doDirFw); 
} else { 
#endif 
digitalWrite(PORT_POLdoDirFw,valor); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};

  
// doDirBw flow acquisition
BOOL adquirir_POLdoDirBw(void){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_doDirBw==TRUE) { 
return diagPOL.doDirBw; 
} else { 
#endif 
return digitalRead(PORT_POLdoDirBw); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};
// doDirBw flow synthesis
void sintetizar_POLdoDirBw(BOOL valor){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_doDirBw==TRUE) { 
digitalWrite(PORT_POLdoDirBw,diagPOL.doDirBw); 
} else { 
#endif 
digitalWrite(PORT_POLdoDirBw,valor); 
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

  
// appliedActAction flow acquisition
// (input disabled for PWMDuty type)
// appliedActAction flow synthesis
// (output disabled for PWMDuty type)

  
// loadPosAcq flow acquisition
uint16_t acquire_POLloadPosAcq(void){ 
return analogRead(PORT_POLloadPosAcq); 
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

  
// dcTorque flow acquisition
// (input disabled for TBD type)
// dcTorque flow synthesis
// (output disabled for TBD type)

  
// actPosPow flow acquisition
// (input disabled for Power type)
// actPosPow flow synthesis
// (output disabled for Power type)

  
// actNegPow flow acquisition
// (input disabled for Power type)
// actNegPow flow synthesis
// (output disabled for Power type)

#define MINDELTA 10
uint16_t filtervalue = 0;  
uint16_t newvalue = 0;  

// loadPosAI flow acquisition
uint16_t acquire_POLloadPosAI(void){ 
    newvalue=analogRead(PORT_POLloadPosAI);
    if (newvalue > (filtervalue + MINDELTA)){
        filtervalue = newvalue;
    } else {
        if (newvalue < ( MAX(MINDELTA,filtervalue) - MINDELTA)){
            filtervalue = newvalue;
        }
    }
return filtervalue;
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
BOOL adquirir_POLloadPosUpSwchDI(void){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_loadPosUpSwchDI==TRUE) { 
return diagPOL.loadPosUpSwchDI; 
} else { 
#endif 
return digitalRead(PORT_POLloadPosUpSwchDI); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};
// loadPosUpSwchDI flow synthesis
// (output disabled for DI_pu type)

  
// loadPosDownSwchDI flow acquisition
BOOL adquirir_POLloadPosDownSwchDI(void){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_loadPosDownSwchDI==TRUE) { 
return diagPOL.loadPosDownSwchDI; 
} else { 
#endif 
return digitalRead(PORT_POLloadPosDownSwchDI); 
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
uint16_t acquire_POLdriveCurrentAI(void){ 
return analogRead(PORT_POLdriveCurrentAI); 
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

  
// hmibut0 flow acquisition
// (input disabled for Button type)
// hmibut0 flow synthesis
// (output disabled for Button type)

  
// hmibut1 flow acquisition
// (input disabled for Button type)
// hmibut1 flow synthesis
// (output disabled for Button type)

  
// hmibut2 flow acquisition
// (input disabled for Button type)
// hmibut2 flow synthesis
// (output disabled for Button type)

  
// hmibut3 flow acquisition
// (input disabled for Button type)
// hmibut3 flow synthesis
// (output disabled for Button type)

  
// hmibut4 flow acquisition
// (input disabled for Button type)
// hmibut4 flow synthesis
// (output disabled for Button type)

  
// hmibut5 flow acquisition
// (input disabled for Button type)
// hmibut5 flow synthesis
// (output disabled for Button type)

  
// hmibut6 flow acquisition
// (input disabled for Button type)
// hmibut6 flow synthesis
// (output disabled for Button type)

  
// hmibut7 flow acquisition
// (input disabled for Button type)
// hmibut7 flow synthesis
// (output disabled for Button type)

  
// hmiled0 flow acquisition
// (input disabled for LED type)
// hmiled0 flow synthesis
// (output disabled for LED type)

  
// hmiled1 flow acquisition
// (input disabled for LED type)
// hmiled1 flow synthesis
// (output disabled for LED type)

  
// hmiled2 flow acquisition
// (input disabled for LED type)
// hmiled2 flow synthesis
// (output disabled for LED type)

  
// hmiled3 flow acquisition
// (input disabled for LED type)
// hmiled3 flow synthesis
// (output disabled for LED type)

  
// hmiled4 flow acquisition
// (input disabled for LED type)
// hmiled4 flow synthesis
// (output disabled for LED type)

  
// hmiled5 flow acquisition
// (input disabled for LED type)
// hmiled5 flow synthesis
// (output disabled for LED type)

  
// hmiled6 flow acquisition
// (input disabled for LED type)
// hmiled6 flow synthesis
// (output disabled for LED type)

  
// hmiled7 flow acquisition
// (input disabled for LED type)
// hmiled7 flow synthesis
// (output disabled for LED type)

  
// hmidigit0 flow acquisition
// (input disabled for DIGIT type)
// hmidigit0 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit1 flow acquisition
// (input disabled for DIGIT type)
// hmidigit1 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit2 flow acquisition
// (input disabled for DIGIT type)
// hmidigit2 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit3 flow acquisition
// (input disabled for DIGIT type)
// hmidigit3 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit4 flow acquisition
// (input disabled for DIGIT type)
// hmidigit4 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit5 flow acquisition
// (input disabled for DIGIT type)
// hmidigit5 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit6 flow acquisition
// (input disabled for DIGIT type)
// hmidigit6 flow synthesis
// (output disabled for DIGIT type)

  
// hmidigit7 flow acquisition
// (input disabled for DIGIT type)
// hmidigit7 flow synthesis
// (output disabled for DIGIT type)

  
// hmidata flow acquisition
// (input disabled for Bus type)
// hmidata flow synthesis
// (output disabled for Bus type)

  
// hmiclock flow acquisition
// (input disabled for Clock type)
// hmiclock flow synthesis
// (output disabled for Clock type)

  
// hmistrobe flow acquisition
// (input disabled for Bus type)
// hmistrobe flow synthesis
// (output disabled for Bus type)

  
// hmibuttons flow acquisition
// (input disabled for Variable type)
// hmibuttons flow synthesis
// (output disabled for Variable type)

  
// hmileds flow acquisition
// (input disabled for Variable type)
// hmileds flow synthesis
// (output disabled for Variable type)

  
// hmidigits flow acquisition
// (input disabled for Variable type)
// hmidigits flow synthesis
// (output disabled for Variable type)

  
// rectifiedActAction flow acquisition
// (input disabled for PWMDuty type)
// rectifiedActAction flow synthesis
// (output disabled for PWMDuty type)

  
// forcedPos flow acquisition
// (input disabled for Variable type)
// forcedPos flow synthesis
// (output disabled for Variable type)

  
// stepperAngle flow acquisition
// (input disabled for Position type)
// stepperAngle flow synthesis
// (output disabled for Position type)

  
// stepperSetPoint flow acquisition
// (input disabled for Variable type)
// stepperSetPoint flow synthesis
// (output disabled for Variable type)

  
// stepperEnable flow acquisition
// (input disabled for Flag type)
// stepperEnable flow synthesis
// (output disabled for Flag type)

  
// stepCtrlA flow acquisition
BOOL adquirir_POLstepCtrlA(void){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_stepCtrlA==TRUE) { 
return diagPOL.stepCtrlA; 
} else { 
#endif 
return digitalRead(PORT_POLstepCtrlA); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};
// stepCtrlA flow synthesis
void sintetizar_POLstepCtrlA(BOOL valor){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_stepCtrlA==TRUE) { 
digitalWrite(PORT_POLstepCtrlA,diagPOL.stepCtrlA); 
} else { 
#endif 
digitalWrite(PORT_POLstepCtrlA,valor); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};

  
// stepCtrlB flow acquisition
BOOL adquirir_POLstepCtrlB(void){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_stepCtrlB==TRUE) { 
return diagPOL.stepCtrlB; 
} else { 
#endif 
return digitalRead(PORT_POLstepCtrlB); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};
// stepCtrlB flow synthesis
void sintetizar_POLstepCtrlB(BOOL valor){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_stepCtrlB==TRUE) { 
digitalWrite(PORT_POLstepCtrlB,diagPOL.stepCtrlB); 
} else { 
#endif 
digitalWrite(PORT_POLstepCtrlB,valor); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};

  
// stepA flow acquisition
// (input disabled for Power type)
// stepA flow synthesis
// (output disabled for Power type)

  
// stepB flow acquisition
BOOL adquirir_POLstepB(void){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_stepB==TRUE) { 
return diagPOL.stepB; 
} else { 
#endif 
return digitalRead(PORT_POLstepB); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};
// stepB flow synthesis
void sintetizar_POLstepB(BOOL valor){ 
#ifdef _DIAG_ACTIVE 
if (diagPOL.enable_stepB==TRUE) { 
digitalWrite(PORT_POLstepB,diagPOL.stepB); 
} else { 
#endif 
digitalWrite(PORT_POLstepB,valor); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};

  
// pwmServoAngleFdback flow acquisition
// (input disabled for Variable type)
// pwmServoAngleFdback flow synthesis
// (output disabled for Variable type)

  
// pwmServoEnable flow acquisition
// (input disabled for Variable type)
// pwmServoEnable flow synthesis
// (output disabled for Variable type)

  
// pwmServoSetPoint flow acquisition
// (input disabled for Variable type)
// pwmServoSetPoint flow synthesis
// (output disabled for Variable type)

  
// pwmServoActive flow acquisition
// (input disabled for Flag type)
// pwmServoActive flow synthesis
// (output disabled for Flag type)

  
// pwmServoPwm flow acquisition
// (input disabled for Flag type)
// pwmServoPwm flow synthesis
// (output disabled for Flag type)

  
// pwmServoAngle flow acquisition
// (input disabled for Position type)
// pwmServoAngle flow synthesis
// (output disabled for Position type)

  
// loadTorque flow acquisition
// (input disabled for TBD type)
// loadTorque flow synthesis
// (output disabled for TBD type)