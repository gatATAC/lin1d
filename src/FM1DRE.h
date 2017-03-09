#ifndef _FM1_DRE_H
#define _FM1_DRE_H

#include "ProjectTypes.h"
#include "ProjectFlows.h"


typedef struct {
// Button -- Does not need declaration upReq;
// Button -- Does not need declaration downReq;
// Position -- Does not need declaration loadPos;
t_upreqacq upReqAcq;
t_downreqacq downReqAcq;
BOOL upReqDI;
BOOL downReqDI;
t_posmode posMode;
t_actaction actAction;
t_pwm pwmActAction;
BOOL doDirFw;
BOOL doDirBw;
t_actenable actEnable;
t_actdirection actDirection;
t_pwm_duty appliedActAction;
uint16_t loadPosAcq;
t_appliedactdirection appliedActDirection;
t_timer actDrvTimer;
// Power -- Does not need declaration loadTorque;
// Power -- Does not need declaration actPosPow;
// Power -- Does not need declaration actNegPow;
uint16_t loadPosAI;
t_timer upButTimer;
t_timer downButTimer;
// Switch -- Does not need declaration loadPosUpSwch;
// Switch -- Does not need declaration loadPosDownSwch;
BOOL loadPosUpSwchDI;
BOOL loadPosDownSwchDI;
BOOL posAchieved;
BOOL ctrlError;
// Current -- Does not need declaration driveCurrent;
uint16_t driveCurrentAI;
t_drivecurrentacq driveCurrentAcq;
BOOL currentError;
BOOL brokenChainError;
BOOL stuckActError;
BOOL loadPosUpSwchAcq;
BOOL loadPosDownSwchAcq;
t_timer upSwitchTimer;
t_timer downSwitchTimer;
// Button -- Does not need declaration hmibut0;
// Button -- Does not need declaration hmibut1;
// Button -- Does not need declaration hmibut2;
// Button -- Does not need declaration hmibut3;
// Button -- Does not need declaration hmibut4;
// Button -- Does not need declaration hmibut5;
// Button -- Does not need declaration hmibut6;
// Button -- Does not need declaration hmibut7;
// LED -- Does not need declaration hmiled0;
// LED -- Does not need declaration hmiled1;
// LED -- Does not need declaration hmiled2;
// LED -- Does not need declaration hmiled3;
// LED -- Does not need declaration hmiled4;
// LED -- Does not need declaration hmiled5;
// LED -- Does not need declaration hmiled6;
// LED -- Does not need declaration hmiled7;
// DIGIT -- Does not need declaration hmidigit0;
// DIGIT -- Does not need declaration hmidigit1;
// DIGIT -- Does not need declaration hmidigit2;
// DIGIT -- Does not need declaration hmidigit3;
// DIGIT -- Does not need declaration hmidigit4;
// DIGIT -- Does not need declaration hmidigit5;
// DIGIT -- Does not need declaration hmidigit6;
// DIGIT -- Does not need declaration hmidigit7;
// Bus -- Does not need declaration hmidata;
// Clock -- Does not need declaration hmiclock;
// Bus -- Does not need declaration hmistrobe;
t_hmibuttons hmibuttons;
t_hmileds hmileds;
t_hmidigits hmidigits;
t_pwm_duty rectifiedActAction;

} t_dreFM1;

typedef struct {
// (null) No diag variables for upReq
// (null) No diag variables for downReq
// (null) No diag variables for loadPos
BOOL enable_upReqAcq;
t_upreqacq upReqAcq;
BOOL enable_downReqAcq;
t_downreqacq downReqAcq;
BOOL enable_upReqDI;
BOOL upReqDI;
BOOL enable_downReqDI;
BOOL downReqDI;
BOOL enable_posMode;
t_posmode posMode;
BOOL enable_actAction;
t_actaction actAction;
BOOL enable_pwmActAction;
t_pwm pwmActAction;
BOOL enable_doDirFw;
BOOL doDirFw;
BOOL enable_doDirBw;
BOOL doDirBw;
BOOL enable_actEnable;
t_actenable actEnable;
BOOL enable_actDirection;
t_actdirection actDirection;
BOOL enable_appliedActAction;
t_pwm_duty appliedActAction;
BOOL enable_loadPosAcq;
uint16_t loadPosAcq;
BOOL enable_appliedActDirection;
t_appliedactdirection appliedActDirection;
BOOL enable_actDrvTimer;
t_timer actDrvTimer;
// (null) No diag variables for loadTorque
// (null) No diag variables for actPosPow
// (null) No diag variables for actNegPow
BOOL enable_loadPosAI;
uint16_t loadPosAI;
BOOL enable_upButTimer;
t_timer upButTimer;
BOOL enable_downButTimer;
t_timer downButTimer;
// (null) No diag variables for loadPosUpSwch
// (null) No diag variables for loadPosDownSwch
BOOL enable_loadPosUpSwchDI;
BOOL loadPosUpSwchDI;
BOOL enable_loadPosDownSwchDI;
BOOL loadPosDownSwchDI;
BOOL enable_posAchieved;
BOOL posAchieved;
BOOL enable_ctrlError;
BOOL ctrlError;
// (null) No diag variables for driveCurrent
BOOL enable_driveCurrentAI;
uint16_t driveCurrentAI;
BOOL enable_driveCurrentAcq;
t_drivecurrentacq driveCurrentAcq;
BOOL enable_currentError;
BOOL currentError;
BOOL enable_brokenChainError;
BOOL brokenChainError;
BOOL enable_stuckActError;
BOOL stuckActError;
BOOL enable_loadPosUpSwchAcq;
BOOL loadPosUpSwchAcq;
BOOL enable_loadPosDownSwchAcq;
BOOL loadPosDownSwchAcq;
BOOL enable_upSwitchTimer;
t_timer upSwitchTimer;
BOOL enable_downSwitchTimer;
t_timer downSwitchTimer;
// (null) No diag variables for hmibut0
// (null) No diag variables for hmibut1
// (null) No diag variables for hmibut2
// (null) No diag variables for hmibut3
// (null) No diag variables for hmibut4
// (null) No diag variables for hmibut5
// (null) No diag variables for hmibut6
// (null) No diag variables for hmibut7
// (null) No diag variables for hmiled0
// (null) No diag variables for hmiled1
// (null) No diag variables for hmiled2
// (null) No diag variables for hmiled3
// (null) No diag variables for hmiled4
// (null) No diag variables for hmiled5
// (null) No diag variables for hmiled6
// (null) No diag variables for hmiled7
// (null) No diag variables for hmidigit0
// (null) No diag variables for hmidigit1
// (null) No diag variables for hmidigit2
// (null) No diag variables for hmidigit3
// (null) No diag variables for hmidigit4
// (null) No diag variables for hmidigit5
// (null) No diag variables for hmidigit6
// (null) No diag variables for hmidigit7
// (null) No diag variables for hmidata
// (null) No diag variables for hmiclock
// (null) No diag variables for hmistrobe
BOOL enable_hmibuttons;
t_hmibuttons hmibuttons;
BOOL enable_hmileds;
t_hmileds hmileds;
BOOL enable_hmidigits;
t_hmidigits hmidigits;
BOOL enable_rectifiedActAction;
t_pwm_duty rectifiedActAction;

} t_diagFM1;

// Initialization functions

  
// upReq flow acquisition
// (setup input disabled for Button type);
// upReq flow synthesis
// (output disabled for Button type);
  
// downReq flow acquisition
// (setup input disabled for Button type);
// downReq flow synthesis
// (output disabled for Button type);
  
// loadPos flow acquisition
// (setup input disabled for Position type);
// loadPos flow synthesis
// (output disabled for Position type);
  
// upReqAcq flow acquisition
// (setup input disabled for Variable type);
// upReqAcq flow synthesis
// (output disabled for Variable type);
  
// downReqAcq flow acquisition
// (setup input disabled for Variable type);
// downReqAcq flow synthesis
// (output disabled for Variable type);
  
// upReqDI flow acquisition
void setup_FM1upReqDI(void);
// upReqDI flow synthesis
// (output disabled for DI_pu type);
  
// downReqDI flow acquisition
void setup_FM1downReqDI(void);
// downReqDI flow synthesis
// (output disabled for DI_pu type);
  
// posMode flow acquisition
// (setup input disabled for Variable type);
// posMode flow synthesis
// (output disabled for Variable type);
  
// actAction flow acquisition
// (setup input disabled for Variable type);
// actAction flow synthesis
// (output disabled for Variable type);
  
// pwmActAction flow acquisition
// (setup input disabled for PWM type);
// pwmActAction flow synthesis
void setup_FM1pwmActAction(void);
  
// doDirFw flow acquisition
void setup_FM1doDirFw_input(void);
// doDirFw flow synthesis
void setup_FM1doDirFw_output(void);
  
// doDirBw flow acquisition
void setup_FM1doDirBw_input(void);
// doDirBw flow synthesis
void setup_FM1doDirBw_output(void);
  
// actEnable flow acquisition
// (setup input disabled for Variable type);
// actEnable flow synthesis
// (output disabled for Variable type);
  
// actDirection flow acquisition
// (setup input disabled for Variable type);
// actDirection flow synthesis
// (output disabled for Variable type);
  
// appliedActAction flow acquisition
// (setup input disabled for PWMDuty type);
// appliedActAction flow synthesis
// (output disabled for PWMDuty type);
  
// loadPosAcq flow acquisition

// loadPosAcq flow synthesis
// (output disabled for ADC type);
  
// appliedActDirection flow acquisition
// (setup input disabled for Variable type);
// appliedActDirection flow synthesis
// (output disabled for Variable type);
  
// actDrvTimer flow acquisition
// (setup input disabled for Timer type);
// actDrvTimer flow synthesis
// (output disabled for Timer type);
  
// loadTorque flow acquisition
// (setup input disabled for Power type);
// loadTorque flow synthesis
// (output disabled for Power type);
  
// actPosPow flow acquisition
// (setup input disabled for Power type);
// actPosPow flow synthesis
// (output disabled for Power type);
  
// actNegPow flow acquisition
// (setup input disabled for Power type);
// actNegPow flow synthesis
// (output disabled for Power type);
  
// loadPosAI flow acquisition

// loadPosAI flow synthesis
// (output disabled for ADC type);
  
// upButTimer flow acquisition
// (setup input disabled for Timer type);
// upButTimer flow synthesis
// (output disabled for Timer type);
  
// downButTimer flow acquisition
// (setup input disabled for Timer type);
// downButTimer flow synthesis
// (output disabled for Timer type);
  
// loadPosUpSwch flow acquisition
// (setup input disabled for Switch type);
// loadPosUpSwch flow synthesis
// (output disabled for Switch type);
  
// loadPosDownSwch flow acquisition
// (setup input disabled for Switch type);
// loadPosDownSwch flow synthesis
// (output disabled for Switch type);
  
// loadPosUpSwchDI flow acquisition
void setup_FM1loadPosUpSwchDI(void);
// loadPosUpSwchDI flow synthesis
// (output disabled for DI_pu type);
  
// loadPosDownSwchDI flow acquisition
void setup_FM1loadPosDownSwchDI(void);
// loadPosDownSwchDI flow synthesis
// (output disabled for DI_pu type);
  
// posAchieved flow acquisition
// (setup input disabled for Flag type);
// posAchieved flow synthesis
// (output disabled for Flag type);
  
// ctrlError flow acquisition
// (setup input disabled for Flag type);
// ctrlError flow synthesis
// (output disabled for Flag type);
  
// driveCurrent flow acquisition
// (setup input disabled for Current type);
// driveCurrent flow synthesis
// (output disabled for Current type);
  
// driveCurrentAI flow acquisition

// driveCurrentAI flow synthesis
// (output disabled for ADC type);
  
// driveCurrentAcq flow acquisition
// (setup input disabled for Variable type);
// driveCurrentAcq flow synthesis
// (output disabled for Variable type);
  
// currentError flow acquisition
// (setup input disabled for Flag type);
// currentError flow synthesis
// (output disabled for Flag type);
  
// brokenChainError flow acquisition
// (setup input disabled for Flag type);
// brokenChainError flow synthesis
// (output disabled for Flag type);
  
// stuckActError flow acquisition
// (setup input disabled for Flag type);
// stuckActError flow synthesis
// (output disabled for Flag type);
  
// loadPosUpSwchAcq flow acquisition
// (setup input disabled for Flag type);
// loadPosUpSwchAcq flow synthesis
// (output disabled for Flag type);
  
// loadPosDownSwchAcq flow acquisition
// (setup input disabled for Flag type);
// loadPosDownSwchAcq flow synthesis
// (output disabled for Flag type);
  
// upSwitchTimer flow acquisition
// (setup input disabled for Timer type);
// upSwitchTimer flow synthesis
// (output disabled for Timer type);
  
// downSwitchTimer flow acquisition
// (setup input disabled for Timer type);
// downSwitchTimer flow synthesis
// (output disabled for Timer type);
  
// hmibut0 flow acquisition
// (setup input disabled for Button type);
// hmibut0 flow synthesis
// (output disabled for Button type);
  
// hmibut1 flow acquisition
// (setup input disabled for Button type);
// hmibut1 flow synthesis
// (output disabled for Button type);
  
// hmibut2 flow acquisition
// (setup input disabled for Button type);
// hmibut2 flow synthesis
// (output disabled for Button type);
  
// hmibut3 flow acquisition
// (setup input disabled for Button type);
// hmibut3 flow synthesis
// (output disabled for Button type);
  
// hmibut4 flow acquisition
// (setup input disabled for Button type);
// hmibut4 flow synthesis
// (output disabled for Button type);
  
// hmibut5 flow acquisition
// (setup input disabled for Button type);
// hmibut5 flow synthesis
// (output disabled for Button type);
  
// hmibut6 flow acquisition
// (setup input disabled for Button type);
// hmibut6 flow synthesis
// (output disabled for Button type);
  
// hmibut7 flow acquisition
// (setup input disabled for Button type);
// hmibut7 flow synthesis
// (output disabled for Button type);
  
// hmiled0 flow acquisition
// (setup input disabled for LED type);
// hmiled0 flow synthesis
// (output disabled for LED type);
  
// hmiled1 flow acquisition
// (setup input disabled for LED type);
// hmiled1 flow synthesis
// (output disabled for LED type);
  
// hmiled2 flow acquisition
// (setup input disabled for LED type);
// hmiled2 flow synthesis
// (output disabled for LED type);
  
// hmiled3 flow acquisition
// (setup input disabled for LED type);
// hmiled3 flow synthesis
// (output disabled for LED type);
  
// hmiled4 flow acquisition
// (setup input disabled for LED type);
// hmiled4 flow synthesis
// (output disabled for LED type);
  
// hmiled5 flow acquisition
// (setup input disabled for LED type);
// hmiled5 flow synthesis
// (output disabled for LED type);
  
// hmiled6 flow acquisition
// (setup input disabled for LED type);
// hmiled6 flow synthesis
// (output disabled for LED type);
  
// hmiled7 flow acquisition
// (setup input disabled for LED type);
// hmiled7 flow synthesis
// (output disabled for LED type);
  
// hmidigit0 flow acquisition
// (setup input disabled for DIGIT type);
// hmidigit0 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit1 flow acquisition
// (setup input disabled for DIGIT type);
// hmidigit1 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit2 flow acquisition
// (setup input disabled for DIGIT type);
// hmidigit2 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit3 flow acquisition
// (setup input disabled for DIGIT type);
// hmidigit3 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit4 flow acquisition
// (setup input disabled for DIGIT type);
// hmidigit4 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit5 flow acquisition
// (setup input disabled for DIGIT type);
// hmidigit5 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit6 flow acquisition
// (setup input disabled for DIGIT type);
// hmidigit6 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit7 flow acquisition
// (setup input disabled for DIGIT type);
// hmidigit7 flow synthesis
// (output disabled for DIGIT type);
  
// hmidata flow acquisition
// (setup input disabled for Bus type);
// hmidata flow synthesis
// (output disabled for Bus type);
  
// hmiclock flow acquisition
// (setup input disabled for Clock type);
// hmiclock flow synthesis
// (output disabled for Clock type);
  
// hmistrobe flow acquisition
// (setup input disabled for Bus type);
// hmistrobe flow synthesis
// (output disabled for Bus type);
  
// hmibuttons flow acquisition
// (setup input disabled for Variable type);
// hmibuttons flow synthesis
// (output disabled for Variable type);
  
// hmileds flow acquisition
// (setup input disabled for Variable type);
// hmileds flow synthesis
// (output disabled for Variable type);
  
// hmidigits flow acquisition
// (setup input disabled for Variable type);
// hmidigits flow synthesis
// (output disabled for Variable type);
  
// rectifiedActAction flow acquisition
// (setup input disabled for PWMDuty type);
// rectifiedActAction flow synthesis
// (output disabled for PWMDuty type);

// Input / Output functions

  
// upReq flow acquisition
// (input disabled for Button type);
// upReq flow synthesis
// (output disabled for Button type);
  
// downReq flow acquisition
// (input disabled for Button type);
// downReq flow synthesis
// (output disabled for Button type);
  
// loadPos flow acquisition
// (input disabled for Position type);
// loadPos flow synthesis
// (output disabled for Position type);
  
// upReqAcq flow acquisition
// (input disabled for Variable type);
// upReqAcq flow synthesis
// (output disabled for Variable type);
  
// downReqAcq flow acquisition
// (input disabled for Variable type);
// downReqAcq flow synthesis
// (output disabled for Variable type);
  
// upReqDI flow acquisition
BOOL adquirir_FM1upReqDI(void);
// upReqDI flow synthesis
// (output disabled for DI_pu type);
  
// downReqDI flow acquisition
BOOL adquirir_FM1downReqDI(void);
// downReqDI flow synthesis
// (output disabled for DI_pu type);
  
// posMode flow acquisition
// (input disabled for Variable type);
// posMode flow synthesis
// (output disabled for Variable type);
  
// actAction flow acquisition
// (input disabled for Variable type);
// actAction flow synthesis
// (output disabled for Variable type);
  
// pwmActAction flow acquisition
// (input disabled for PWM type);
// pwmActAction flow synthesis
void synthesize_FM1pwmActAction(t_pwm value);
  
// doDirFw flow acquisition
BOOL adquirir_FM1doDirFw(void);
// doDirFw flow synthesis
void sintetizar_FM1doDirFw(BOOL valor);
  
// doDirBw flow acquisition
BOOL adquirir_FM1doDirBw(void);
// doDirBw flow synthesis
void sintetizar_FM1doDirBw(BOOL valor);
  
// actEnable flow acquisition
// (input disabled for Variable type);
// actEnable flow synthesis
// (output disabled for Variable type);
  
// actDirection flow acquisition
// (input disabled for Variable type);
// actDirection flow synthesis
// (output disabled for Variable type);
  
// appliedActAction flow acquisition
// (input disabled for PWMDuty type);
// appliedActAction flow synthesis
// (output disabled for PWMDuty type);
  
// loadPosAcq flow acquisition
uint16_t acquire_FM1loadPosAcq(void);
// loadPosAcq flow synthesis
// (output disabled for ADC type);
  
// appliedActDirection flow acquisition
// (input disabled for Variable type);
// appliedActDirection flow synthesis
// (output disabled for Variable type);
  
// actDrvTimer flow acquisition
// (input disabled for Timer type);
// actDrvTimer flow synthesis
// (output disabled for Timer type);
  
// loadTorque flow acquisition
// (input disabled for Power type);
// loadTorque flow synthesis
// (output disabled for Power type);
  
// actPosPow flow acquisition
// (input disabled for Power type);
// actPosPow flow synthesis
// (output disabled for Power type);
  
// actNegPow flow acquisition
// (input disabled for Power type);
// actNegPow flow synthesis
// (output disabled for Power type);
  
// loadPosAI flow acquisition
uint16_t acquire_FM1loadPosAI(void);
// loadPosAI flow synthesis
// (output disabled for ADC type);
  
// upButTimer flow acquisition
// (input disabled for Timer type);
// upButTimer flow synthesis
// (output disabled for Timer type);
  
// downButTimer flow acquisition
// (input disabled for Timer type);
// downButTimer flow synthesis
// (output disabled for Timer type);
  
// loadPosUpSwch flow acquisition
// (input disabled for Switch type);
// loadPosUpSwch flow synthesis
// (output disabled for Switch type);
  
// loadPosDownSwch flow acquisition
// (input disabled for Switch type);
// loadPosDownSwch flow synthesis
// (output disabled for Switch type);
  
// loadPosUpSwchDI flow acquisition
BOOL adquirir_FM1loadPosUpSwchDI(void);
// loadPosUpSwchDI flow synthesis
// (output disabled for DI_pu type);
  
// loadPosDownSwchDI flow acquisition
BOOL adquirir_FM1loadPosDownSwchDI(void);
// loadPosDownSwchDI flow synthesis
// (output disabled for DI_pu type);
  
// posAchieved flow acquisition
// (input disabled for Flag type);
// posAchieved flow synthesis
// (output disabled for Flag type);
  
// ctrlError flow acquisition
// (input disabled for Flag type);
// ctrlError flow synthesis
// (output disabled for Flag type);
  
// driveCurrent flow acquisition
// (input disabled for Current type);
// driveCurrent flow synthesis
// (output disabled for Current type);
  
// driveCurrentAI flow acquisition
uint16_t acquire_FM1driveCurrentAI(void);
// driveCurrentAI flow synthesis
// (output disabled for ADC type);
  
// driveCurrentAcq flow acquisition
// (input disabled for Variable type);
// driveCurrentAcq flow synthesis
// (output disabled for Variable type);
  
// currentError flow acquisition
// (input disabled for Flag type);
// currentError flow synthesis
// (output disabled for Flag type);
  
// brokenChainError flow acquisition
// (input disabled for Flag type);
// brokenChainError flow synthesis
// (output disabled for Flag type);
  
// stuckActError flow acquisition
// (input disabled for Flag type);
// stuckActError flow synthesis
// (output disabled for Flag type);
  
// loadPosUpSwchAcq flow acquisition
// (input disabled for Flag type);
// loadPosUpSwchAcq flow synthesis
// (output disabled for Flag type);
  
// loadPosDownSwchAcq flow acquisition
// (input disabled for Flag type);
// loadPosDownSwchAcq flow synthesis
// (output disabled for Flag type);
  
// upSwitchTimer flow acquisition
// (input disabled for Timer type);
// upSwitchTimer flow synthesis
// (output disabled for Timer type);
  
// downSwitchTimer flow acquisition
// (input disabled for Timer type);
// downSwitchTimer flow synthesis
// (output disabled for Timer type);
  
// hmibut0 flow acquisition
// (input disabled for Button type);
// hmibut0 flow synthesis
// (output disabled for Button type);
  
// hmibut1 flow acquisition
// (input disabled for Button type);
// hmibut1 flow synthesis
// (output disabled for Button type);
  
// hmibut2 flow acquisition
// (input disabled for Button type);
// hmibut2 flow synthesis
// (output disabled for Button type);
  
// hmibut3 flow acquisition
// (input disabled for Button type);
// hmibut3 flow synthesis
// (output disabled for Button type);
  
// hmibut4 flow acquisition
// (input disabled for Button type);
// hmibut4 flow synthesis
// (output disabled for Button type);
  
// hmibut5 flow acquisition
// (input disabled for Button type);
// hmibut5 flow synthesis
// (output disabled for Button type);
  
// hmibut6 flow acquisition
// (input disabled for Button type);
// hmibut6 flow synthesis
// (output disabled for Button type);
  
// hmibut7 flow acquisition
// (input disabled for Button type);
// hmibut7 flow synthesis
// (output disabled for Button type);
  
// hmiled0 flow acquisition
// (input disabled for LED type);
// hmiled0 flow synthesis
// (output disabled for LED type);
  
// hmiled1 flow acquisition
// (input disabled for LED type);
// hmiled1 flow synthesis
// (output disabled for LED type);
  
// hmiled2 flow acquisition
// (input disabled for LED type);
// hmiled2 flow synthesis
// (output disabled for LED type);
  
// hmiled3 flow acquisition
// (input disabled for LED type);
// hmiled3 flow synthesis
// (output disabled for LED type);
  
// hmiled4 flow acquisition
// (input disabled for LED type);
// hmiled4 flow synthesis
// (output disabled for LED type);
  
// hmiled5 flow acquisition
// (input disabled for LED type);
// hmiled5 flow synthesis
// (output disabled for LED type);
  
// hmiled6 flow acquisition
// (input disabled for LED type);
// hmiled6 flow synthesis
// (output disabled for LED type);
  
// hmiled7 flow acquisition
// (input disabled for LED type);
// hmiled7 flow synthesis
// (output disabled for LED type);
  
// hmidigit0 flow acquisition
// (input disabled for DIGIT type);
// hmidigit0 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit1 flow acquisition
// (input disabled for DIGIT type);
// hmidigit1 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit2 flow acquisition
// (input disabled for DIGIT type);
// hmidigit2 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit3 flow acquisition
// (input disabled for DIGIT type);
// hmidigit3 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit4 flow acquisition
// (input disabled for DIGIT type);
// hmidigit4 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit5 flow acquisition
// (input disabled for DIGIT type);
// hmidigit5 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit6 flow acquisition
// (input disabled for DIGIT type);
// hmidigit6 flow synthesis
// (output disabled for DIGIT type);
  
// hmidigit7 flow acquisition
// (input disabled for DIGIT type);
// hmidigit7 flow synthesis
// (output disabled for DIGIT type);
  
// hmidata flow acquisition
// (input disabled for Bus type);
// hmidata flow synthesis
// (output disabled for Bus type);
  
// hmiclock flow acquisition
// (input disabled for Clock type);
// hmiclock flow synthesis
// (output disabled for Clock type);
  
// hmistrobe flow acquisition
// (input disabled for Bus type);
// hmistrobe flow synthesis
// (output disabled for Bus type);
  
// hmibuttons flow acquisition
// (input disabled for Variable type);
// hmibuttons flow synthesis
// (output disabled for Variable type);
  
// hmileds flow acquisition
// (input disabled for Variable type);
// hmileds flow synthesis
// (output disabled for Variable type);
  
// hmidigits flow acquisition
// (input disabled for Variable type);
// hmidigits flow synthesis
// (output disabled for Variable type);
  
// rectifiedActAction flow acquisition
// (input disabled for PWMDuty type);
// rectifiedActAction flow synthesis
// (output disabled for PWMDuty type);

#endif /* _DRE_H */








