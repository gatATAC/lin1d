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

extern t_dre dre;
extern t_diag diag;

#endif /* _DRE_H */
