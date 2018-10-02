#ifndef _POL_DRE_H
#define _POL_DRE_H

#include "ProjectTypes.h"
#include "ProjectFlows.h"

typedef struct {
    // Button -- Does not need declaration upReq;
    // Button -- Does not need declaration downReq;
    // Position -- Does not need declaration loadPos;
    t_upreqacq upReqAcq;
    t_downreqacq downReqAcq;
    bool upReqDI;
    bool downReqDI;
    t_posmode posMode;
    t_actaction actAction;
    t_pwm pwmActAction;
    bool doDirFw;
    bool doDirBw;
    t_actenable actEnable;
    t_actdirection actDirection;
    t_pwm_duty appliedActAction;
    uint16_t loadPosAcq;
    t_appliedactdirection appliedActDirection;
    t_timer actDrvTimer;
    // TBD -- Does not need declaration dcTorque;
    // Power -- Does not need declaration actPosPow;
    // Power -- Does not need declaration actNegPow;
    uint16_t loadPosAI;
    t_timer upButTimer;
    t_timer downButTimer;
    // Switch -- Does not need declaration loadPosUpSwch;
    // Switch -- Does not need declaration loadPosDownSwch;
    bool loadPosUpSwchDI;
    bool loadPosDownSwchDI;
    bool posAchieved;
    bool ctrlError;
    // Current -- Does not need declaration driveCurrent;
    uint16_t driveCurrentAI;
    t_drivecurrentacq driveCurrentAcq;
    bool currentError;
    bool brokenChainError;
    bool stuckActError;
    bool loadPosUpSwchAcq;
    bool loadPosDownSwchAcq;
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
    t_forcedpos forcedPos;
    // Position -- Does not need declaration stepperAngle;
    t_steppersetpoint stepperSetPoint;
    bool stepperEnable;
    bool stepCtrlA;
    bool stepCtrlB;
    // Power -- Does not need declaration stepA;
    // Power -- Does not need declaration stepB;
    t_pwmservoanglefdback pwmServoAngleFdback;
    t_pwmservoenable pwmServoEnable;
    t_pwmservosetpoint pwmServoSetPoint;
    bool pwmServoActive;
    bool pwmServoPwm;
    // Position -- Does not need declaration pwmServoAngle;
    // TBD -- Does not need declaration loadTorque;
    bool stepperServoActive;
    t_stepperanglefdback stepperAngleFdback;

} t_drePOL;

typedef struct {
    // (null) No diag variables for upReq
    // (null) No diag variables for downReq
    // (null) No diag variables for loadPos
    bool enable_upReqAcq;
    t_upreqacq upReqAcq;
    bool enable_downReqAcq;
    t_downreqacq downReqAcq;
    bool enable_upReqDI;
    bool upReqDI;
    bool enable_downReqDI;
    bool downReqDI;
    bool enable_posMode;
    t_posmode posMode;
    bool enable_actAction;
    t_actaction actAction;
    bool enable_pwmActAction;
    t_pwm pwmActAction;
    bool enable_doDirFw;
    bool doDirFw;
    bool enable_doDirBw;
    bool doDirBw;
    bool enable_actEnable;
    t_actenable actEnable;
    bool enable_actDirection;
    t_actdirection actDirection;
    bool enable_appliedActAction;
    t_pwm_duty appliedActAction;
    bool enable_loadPosAcq;
    uint16_t loadPosAcq;
    bool enable_appliedActDirection;
    t_appliedactdirection appliedActDirection;
    bool enable_actDrvTimer;
    t_timer actDrvTimer;
    // (null) No diag variables for dcTorque
    // (null) No diag variables for actPosPow
    // (null) No diag variables for actNegPow
    bool enable_loadPosAI;
    uint16_t loadPosAI;
    bool enable_upButTimer;
    t_timer upButTimer;
    bool enable_downButTimer;
    t_timer downButTimer;
    // (null) No diag variables for loadPosUpSwch
    // (null) No diag variables for loadPosDownSwch
    bool enable_loadPosUpSwchDI;
    bool loadPosUpSwchDI;
    bool enable_loadPosDownSwchDI;
    bool loadPosDownSwchDI;
    bool enable_posAchieved;
    bool posAchieved;
    bool enable_ctrlError;
    bool ctrlError;
    // (null) No diag variables for driveCurrent
    bool enable_driveCurrentAI;
    uint16_t driveCurrentAI;
    bool enable_driveCurrentAcq;
    t_drivecurrentacq driveCurrentAcq;
    bool enable_currentError;
    bool currentError;
    bool enable_brokenChainError;
    bool brokenChainError;
    bool enable_stuckActError;
    bool stuckActError;
    bool enable_loadPosUpSwchAcq;
    bool loadPosUpSwchAcq;
    bool enable_loadPosDownSwchAcq;
    bool loadPosDownSwchAcq;
    bool enable_upSwitchTimer;
    t_timer upSwitchTimer;
    bool enable_downSwitchTimer;
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
    bool enable_hmibuttons;
    t_hmibuttons hmibuttons;
    bool enable_hmileds;
    t_hmileds hmileds;
    bool enable_hmidigits;
    t_hmidigits hmidigits;
    bool enable_rectifiedActAction;
    t_pwm_duty rectifiedActAction;
    bool enable_forcedPos;
    t_forcedpos forcedPos;
    // (null) No diag variables for stepperAngle
    bool enable_stepperSetPoint;
    t_steppersetpoint stepperSetPoint;
    bool enable_stepperEnable;
    bool stepperEnable;
    bool enable_stepCtrlA;
    bool stepCtrlA;
    bool enable_stepCtrlB;
    bool stepCtrlB;
    // (null) No diag variables for stepA
    // (null) No diag variables for stepB
    bool enable_pwmServoAngleFdback;
    t_pwmservoanglefdback pwmServoAngleFdback;
    bool enable_pwmServoEnable;
    t_pwmservoenable pwmServoEnable;
    bool enable_pwmServoSetPoint;
    t_pwmservosetpoint pwmServoSetPoint;
    bool enable_pwmServoActive;
    bool pwmServoActive;
    bool enable_pwmServoPwm;
    bool pwmServoPwm;
    // (null) No diag variables for pwmServoAngle
    // (null) No diag variables for loadTorque
    bool enable_stepperServoActive;
    bool stepperServoActive;
    bool enable_stepperAngleFdback;
    t_stepperanglefdback stepperAngleFdback;

} t_diagPOL;

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
void setup_POLupReqDI(void);
// upReqDI flow synthesis
// (output disabled for DI_pu type);

// downReqDI flow acquisition
void setup_POLdownReqDI(void);
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
void setup_POLpwmActAction(void);

// doDirFw flow acquisition
void setup_POLdoDirFw_input(void);
// doDirFw flow synthesis
void setup_POLdoDirFw_output(void);

// doDirBw flow acquisition
void setup_POLdoDirBw_input(void);
// doDirBw flow synthesis
void setup_POLdoDirBw_output(void);

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

// dcTorque flow acquisition
// (setup input disabled for TBD type);
// dcTorque flow synthesis
// (output disabled for TBD type);

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
void setup_POLloadPosUpSwchDI(void);
// loadPosUpSwchDI flow synthesis
// (output disabled for DI_pu type);

// loadPosDownSwchDI flow acquisition
void setup_POLloadPosDownSwchDI(void);
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

// forcedPos flow acquisition
// (setup input disabled for Variable type);
// forcedPos flow synthesis
// (output disabled for Variable type);

// stepperAngle flow acquisition
// (setup input disabled for Position type);
// stepperAngle flow synthesis
// (output disabled for Position type);

// stepperSetPoint flow acquisition
// (setup input disabled for Variable type);
// stepperSetPoint flow synthesis
// (output disabled for Variable type);

// stepperEnable flow acquisition
// (setup input disabled for Flag type);
// stepperEnable flow synthesis
// (output disabled for Flag type);

// stepCtrlA flow acquisition
void setup_POLstepCtrlA_input(void);
// stepCtrlA flow synthesis
void setup_POLstepCtrlA_output(void);

// stepCtrlB flow acquisition
void setup_POLstepCtrlB_input(void);
// stepCtrlB flow synthesis
void setup_POLstepCtrlB_output(void);

// stepA flow acquisition
// (setup input disabled for Power type);
// stepA flow synthesis
// (output disabled for Power type);

// stepB flow acquisition
// (setup input disabled for Power type);
// stepB flow synthesis
// (output disabled for Power type);

// pwmServoAngleFdback flow acquisition
// (setup input disabled for Variable type);
// pwmServoAngleFdback flow synthesis
// (output disabled for Variable type);

// pwmServoEnable flow acquisition
// (setup input disabled for Variable type);
// pwmServoEnable flow synthesis
// (output disabled for Variable type);

// pwmServoSetPoint flow acquisition
// (setup input disabled for Variable type);
// pwmServoSetPoint flow synthesis
// (output disabled for Variable type);

// pwmServoActive flow acquisition
// (setup input disabled for Flag type);
// pwmServoActive flow synthesis
// (output disabled for Flag type);

// pwmServoPwm flow acquisition
// (setup input disabled for Flag type);
// pwmServoPwm flow synthesis
// (output disabled for Flag type);

// pwmServoAngle flow acquisition
// (setup input disabled for Position type);
// pwmServoAngle flow synthesis
// (output disabled for Position type);

// loadTorque flow acquisition
// (setup input disabled for TBD type);
// loadTorque flow synthesis
// (output disabled for TBD type);

// stepperServoActive flow acquisition
// (setup input disabled for Flag type);
// stepperServoActive flow synthesis
// (output disabled for Flag type);

// stepperAngleFdback flow acquisition
// (setup input disabled for Variable type);
// stepperAngleFdback flow synthesis
// (output disabled for Variable type);

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
bool adquirir_POLupReqDI(void);
// upReqDI flow synthesis
// (output disabled for DI_pu type);

// downReqDI flow acquisition
bool adquirir_POLdownReqDI(void);
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
void synthesize_POLpwmActAction(t_pwm value);

// doDirFw flow acquisition
bool adquirir_POLdoDirFw(void);
// doDirFw flow synthesis
void sintetizar_POLdoDirFw(bool valor);

// doDirBw flow acquisition
bool adquirir_POLdoDirBw(void);
// doDirBw flow synthesis
void sintetizar_POLdoDirBw(bool valor);

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
uint16_t acquire_POLloadPosAcq(void);
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

// dcTorque flow acquisition
// (input disabled for TBD type);
// dcTorque flow synthesis
// (output disabled for TBD type);

// actPosPow flow acquisition
// (input disabled for Power type);
// actPosPow flow synthesis
// (output disabled for Power type);

// actNegPow flow acquisition
// (input disabled for Power type);
// actNegPow flow synthesis
// (output disabled for Power type);

// loadPosAI flow acquisition
uint16_t acquire_POLloadPosAI(void);
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
bool adquirir_POLloadPosUpSwchDI(void);
// loadPosUpSwchDI flow synthesis
// (output disabled for DI_pu type);

// loadPosDownSwchDI flow acquisition
bool adquirir_POLloadPosDownSwchDI(void);
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
uint16_t acquire_POLdriveCurrentAI(void);
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

// forcedPos flow acquisition
// (input disabled for Variable type);
// forcedPos flow synthesis
// (output disabled for Variable type);

// stepperAngle flow acquisition
// (input disabled for Position type);
// stepperAngle flow synthesis
// (output disabled for Position type);

// stepperSetPoint flow acquisition
// (input disabled for Variable type);
// stepperSetPoint flow synthesis
// (output disabled for Variable type);

// stepperEnable flow acquisition
// (input disabled for Flag type);
// stepperEnable flow synthesis
// (output disabled for Flag type);

// stepCtrlA flow acquisition
bool adquirir_POLstepCtrlA(void);
// stepCtrlA flow synthesis
void sintetizar_POLstepCtrlA(bool valor);

// stepCtrlB flow acquisition
bool adquirir_POLstepCtrlB(void);
// stepCtrlB flow synthesis
void sintetizar_POLstepCtrlB(bool valor);

// stepA flow acquisition
// (input disabled for Power type);
// stepA flow synthesis
// (output disabled for Power type);

// stepB flow acquisition
// (input disabled for Power type);
// stepB flow synthesis
// (output disabled for Power type);

// pwmServoAngleFdback flow acquisition
// (input disabled for Variable type);
// pwmServoAngleFdback flow synthesis
// (output disabled for Variable type);

// pwmServoEnable flow acquisition
// (input disabled for Variable type);
// pwmServoEnable flow synthesis
// (output disabled for Variable type);

// pwmServoSetPoint flow acquisition
// (input disabled for Variable type);
// pwmServoSetPoint flow synthesis
// (output disabled for Variable type);

// pwmServoActive flow acquisition
// (input disabled for Flag type);
// pwmServoActive flow synthesis
// (output disabled for Flag type);

// pwmServoPwm flow acquisition
// (input disabled for Flag type);
// pwmServoPwm flow synthesis
// (output disabled for Flag type);

// pwmServoAngle flow acquisition
// (input disabled for Position type);
// pwmServoAngle flow synthesis
// (output disabled for Position type);

// loadTorque flow acquisition
// (input disabled for TBD type);
// loadTorque flow synthesis
// (output disabled for TBD type);

// stepperServoActive flow acquisition
// (input disabled for Flag type);
// stepperServoActive flow synthesis
// (output disabled for Flag type);

// stepperAngleFdback flow acquisition
// (input disabled for Variable type);
// stepperAngleFdback flow synthesis
// (output disabled for Variable type);

#endif /* _DRE_H */