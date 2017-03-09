#include "FM1DRE.h"

// --- DRE data structure declaration ---
t_dreFM1 dreFM1;
t_diagFM1 diagFM1;

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
void setup_FM1upReqDI(void){ 
pinMode(PORT_FM1upReqDI, INPUT_PULLUP); 
};
// upReqDI flow synthesis
// (output disabled for DI_pu type)

  
// downReqDI flow acquisition
void setup_FM1downReqDI(void){ 
pinMode(PORT_FM1downReqDI, INPUT_PULLUP); 
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
void setup_FM1pwmActAction(void){ 
#ifndef _PWM_RES_SET_
#define _PWM_RES_SET_
analogWriteResolution(CFG_PWM_RESOLUTION);
#endif
analogWriteFrequency(PORT_FM1pwmActAction, PORT_FM1pwmActAction_FREQ);
};


  
// doDirFw flow acquisition
void setup_FM1doDirFw_input(void){ 
pinMode(PORT_FM1doDirFw, INPUT);
};

// doDirFw flow synthesis
void setup_FM1doDirFw_output(void){ 
pinMode(PORT_FM1doDirFw, INPUT);
};

  
// doDirBw flow acquisition
void setup_FM1doDirBw_input(void){ 
pinMode(PORT_FM1doDirBw, INPUT);
};

// doDirBw flow synthesis
void setup_FM1doDirBw_output(void){ 
pinMode(PORT_FM1doDirBw, INPUT);
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
void setup_FM1loadPosUpSwchDI(void){ 
pinMode(PORT_FM1loadPosUpSwchDI, INPUT_PULLUP); 
};
// loadPosUpSwchDI flow synthesis
// (output disabled for DI_pu type)

  
// loadPosDownSwchDI flow acquisition
void setup_FM1loadPosDownSwchDI(void){ 
pinMode(PORT_FM1loadPosDownSwchDI, INPUT_PULLUP); 
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
BOOL adquirir_FM1upReqDI(void){ 
#ifdef _DIAG_ACTIVE 
if (diagFM1.enable_upReqDI==TRUE) { 
return diagFM1.upReqDI; 
} else { 
#endif 
return digitalRead(PORT_FM1upReqDI); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};
// upReqDI flow synthesis
// (output disabled for DI_pu type)

  
// downReqDI flow acquisition
BOOL adquirir_FM1downReqDI(void){ 
#ifdef _DIAG_ACTIVE 
if (diagFM1.enable_downReqDI==TRUE) { 
return diagFM1.downReqDI; 
} else { 
#endif 
return digitalRead(PORT_FM1downReqDI); 
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
void synthesize_FM1pwmActAction(t_pwm value){ 
analogWrite(PORT_FM1pwmActAction, value); 
};

  
// doDirFw flow acquisition
BOOL adquirir_FM1doDirFw(void){ 
#ifdef _DIAG_ACTIVE 
if (diagFM1.enable_doDirFw==TRUE) { 
return diagFM1.doDirFw; 
} else { 
#endif 
return digitalRead(PORT_FM1doDirFw); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};
// doDirFw flow synthesis
void sintetizar_FM1doDirFw(BOOL valor){ 
#ifdef _DIAG_ACTIVE 
if (diagFM1.enable_doDirFw==TRUE) { 
digitalWrite(PORT_FM1doDirFw,diagFM1.doDirFw); 
} else { 
#endif 
digitalWrite(PORT_FM1doDirFw,valor); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};

  
// doDirBw flow acquisition
BOOL adquirir_FM1doDirBw(void){ 
#ifdef _DIAG_ACTIVE 
if (diagFM1.enable_doDirBw==TRUE) { 
return diagFM1.doDirBw; 
} else { 
#endif 
return digitalRead(PORT_FM1doDirBw); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};
// doDirBw flow synthesis
void sintetizar_FM1doDirBw(BOOL valor){ 
#ifdef _DIAG_ACTIVE 
if (diagFM1.enable_doDirBw==TRUE) { 
digitalWrite(PORT_FM1doDirBw,diagFM1.doDirBw); 
} else { 
#endif 
digitalWrite(PORT_FM1doDirBw,valor); 
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
uint16_t acquire_FM1loadPosAcq(void){ 
return analogRead(PORT_FM1loadPosAcq); 
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
uint16_t acquire_FM1loadPosAI(void){ 
return analogRead(PORT_FM1loadPosAI); 
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
BOOL adquirir_FM1loadPosUpSwchDI(void){ 
#ifdef _DIAG_ACTIVE 
if (diagFM1.enable_loadPosUpSwchDI==TRUE) { 
return diagFM1.loadPosUpSwchDI; 
} else { 
#endif 
return digitalRead(PORT_FM1loadPosUpSwchDI); 
#ifdef _DIAG_ACTIVE 
} 
#endif 
};
// loadPosUpSwchDI flow synthesis
// (output disabled for DI_pu type)

  
// loadPosDownSwchDI flow acquisition
BOOL adquirir_FM1loadPosDownSwchDI(void){ 
#ifdef _DIAG_ACTIVE 
if (diagFM1.enable_loadPosDownSwchDI==TRUE) { 
return diagFM1.loadPosDownSwchDI; 
} else { 
#endif 
return digitalRead(PORT_FM1loadPosDownSwchDI); 
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
uint16_t acquire_FM1driveCurrentAI(void){ 
return analogRead(PORT_FM1driveCurrentAI); 
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








