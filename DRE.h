#ifndef _DRE_H
#define _DRE_H

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
t_pwm_duty rectifiedActAction;
t_rectifiedactdirection rectifiedActDirection;
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

} t_dre;

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
BOOL enable_rectifiedActAction;
t_pwm_duty rectifiedActAction;
BOOL enable_rectifiedActDirection;
t_rectifiedactdirection rectifiedActDirection;
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

} t_diag;

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
void setup_upReqDI(void);
// upReqDI flow synthesis
// (output disabled for DI_pu type);
  
// downReqDI flow acquisition
void setup_downReqDI(void);
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
void setup_pwmActAction(void);
  
// doDirFw flow acquisition
void setup_doDirFw_input(void);
// doDirFw flow synthesis
void setup_doDirFw_output(void);
  
// doDirBw flow acquisition
void setup_doDirBw_input(void);
// doDirBw flow synthesis
void setup_doDirBw_output(void);
  
// actEnable flow acquisition
// (setup input disabled for Variable type);
// actEnable flow synthesis
// (output disabled for Variable type);
  
// actDirection flow acquisition
// (setup input disabled for Variable type);
// actDirection flow synthesis
// (output disabled for Variable type);
  
// rectifiedActAction flow acquisition
// (setup input disabled for PWMDuty type);
// rectifiedActAction flow synthesis
// (output disabled for PWMDuty type);
  
// rectifiedActDirection flow acquisition
// (setup input disabled for Variable type);
// rectifiedActDirection flow synthesis
// (output disabled for Variable type);
  
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
void setup_loadPosUpSwchDI(void);
// loadPosUpSwchDI flow synthesis
// (output disabled for DI_pu type);
  
// loadPosDownSwchDI flow acquisition
void setup_loadPosDownSwchDI(void);
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
BOOL adquirir_upReqDI(void);
// upReqDI flow synthesis
// (output disabled for DI_pu type);
  
// downReqDI flow acquisition
BOOL adquirir_downReqDI(void);
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
void synthesize_pwmActAction(t_pwm value);
  
// doDirFw flow acquisition
BOOL adquirir_doDirFw(void);
// doDirFw flow synthesis
void sintetizar_doDirFw(BOOL valor);
  
// doDirBw flow acquisition
BOOL adquirir_doDirBw(void);
// doDirBw flow synthesis
void sintetizar_doDirBw(BOOL valor);
  
// actEnable flow acquisition
// (input disabled for Variable type);
// actEnable flow synthesis
// (output disabled for Variable type);
  
// actDirection flow acquisition
// (input disabled for Variable type);
// actDirection flow synthesis
// (output disabled for Variable type);
  
// rectifiedActAction flow acquisition
// (input disabled for PWMDuty type);
// rectifiedActAction flow synthesis
// (output disabled for PWMDuty type);
  
// rectifiedActDirection flow acquisition
// (input disabled for Variable type);
// rectifiedActDirection flow synthesis
// (output disabled for Variable type);
  
// loadPosAcq flow acquisition
uint16_t acquire_loadPosAcq(void);
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
uint16_t acquire_loadPosAI(void);
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
BOOL adquirir_loadPosUpSwchDI(void);
// loadPosUpSwchDI flow synthesis
// (output disabled for DI_pu type);
  
// loadPosDownSwchDI flow acquisition
BOOL adquirir_loadPosDownSwchDI(void);
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
uint16_t acquire_driveCurrentAI(void);
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

#endif /* _DRE_H */