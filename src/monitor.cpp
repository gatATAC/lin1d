#include "monitor.h"
#include "FM1DRE.h"
#include "POLDRE.h"

#include <TM1638.h>
extern TM1638 module;

extern t_dreFM1 dreFM1;
extern t_drePOL drePOL;

void monitorInit(){
  dreFM1.hmileds=0x00;
  dreFM1.hmidigits=0;
  module.setLEDs(dreFM1.hmileds);
  module.setDisplayToDecNumber(dreFM1.hmidigits, 0);
}

void monitorExec(){
  
  // Calculate leds
  dreFM1.hmileds=0x00;

  // FM1 related leds
  if (dreFM1.posMode==CFG_POS_MODE_UP){
    dreFM1.hmileds |= CFG_FM1_HMILEDS_POSMODE_UP_MASK;
  }
  if (dreFM1.posMode==CFG_POS_MODE_DOWN){
    dreFM1.hmileds |= CFG_FM1_HMILEDS_POSMODE_DOWN_MASK;
  }
  if (dreFM1.loadPosUpSwchAcq == TRUE){
    dreFM1.hmileds |= CFG_FM1_HMILEDS_SWITCH_UP_MASK;
  }
  if (dreFM1.loadPosDownSwchAcq == TRUE){
    dreFM1.hmileds |= CFG_FM1_HMILEDS_SWITCH_DOWN_MASK;
  }
  if (dreFM1.upReqAcq == TRUE){
    dreFM1.hmileds |= CFG_FM1_HMILEDS_REQ_UP_MASK;
  }
  if (dreFM1.downReqAcq == TRUE){
    dreFM1.hmileds |= CFG_FM1_HMILEDS_REQ_DOWN_MASK;
  }

  // POL related leds
  if (drePOL.posMode==CFG_POS_MODE_UP){
    dreFM1.hmileds |= CFG_POL_HMILEDS_POSMODE_UP_MASK;  // Both subsystems (POL and FM1) share same hmi
  }
  if (drePOL.posMode==CFG_POS_MODE_DOWN){
    dreFM1.hmileds |= CFG_POL_HMILEDS_POSMODE_DOWN_MASK;  // Both subsystems (POL and FM1) share same hmi
  }
  if (drePOL.loadPosUpSwchAcq == TRUE){
    dreFM1.hmileds |= CFG_POL_HMILEDS_SWITCH_UP_MASK;  // Both subsystems (POL and FM1) share same hmi
  }
  if (drePOL.loadPosDownSwchAcq == TRUE){
    dreFM1.hmileds |= CFG_POL_HMILEDS_SWITCH_DOWN_MASK;  // Both subsystems (POL and FM1) share same hmi
  }
  if (drePOL.upReqAcq == TRUE){
    dreFM1.hmileds |= CFG_POL_HMILEDS_REQ_UP_MASK;  // Both subsystems (POL and FM1) share same hmi
  }
  if (drePOL.downReqAcq == TRUE){
    dreFM1.hmileds |= CFG_POL_HMILEDS_REQ_DOWN_MASK;  // Both subsystems (POL and FM1) share same hmi
  }

  // Calculate digits
  dreFM1.hmidigits = 0L;
  
#ifdef DEBUG_HMI_BUTTONS  
#ifdef DEBUG_SHOW_BUTTON
  int i;
  uint8_t ret=0;
  for (i=0;i<9;i++){
    if ((dreFM1.hmibuttons >> (i-1)) & 0x01) {
      ret = i;
      i=10;
    }
  }
  dreFM1.hmidigits += ret * 10000000L;
#endif  
  dreFM1.hmidigits += 1000000L * (drePOL.downButTimer + drePOL.upButTimer);  // Both subsystems (POL and FM1) share same hmi
  dreFM1.hmidigits += 10000L * (drePOL.downSwitchTimer + drePOL.upSwitchTimer);  // Both subsystems (POL and FM1) share same hmi
  dreFM1.hmidigits += 100L * (dreFM1.downButTimer + dreFM1.upButTimer);
  dreFM1.hmidigits += 1L * (dreFM1.downSwitchTimer + dreFM1.upSwitchTimer);
#else
    //dreFM1.hmidigits += 10000L * abs(dreFM1.actAction);
    //dreFM1.hmidigits += abs(drePOL.actAction);
    dreFM1.hmidigits += 1000000L * dreFM1.appliedActAction/100;
    //dreFM1.hmidigits += 1000000L * dreFM1.pwmServoEnable;
    dreFM1.hmidigits += 10000L * ((dreFM1.actDrvTimer/100)*(CYCLE_TIME_IN_MICROS))/1000L;
    dreFM1.hmidigits += 100L * drePOL.appliedActAction/100;  // Both subsystems (POL and FM1) share same hmi
    dreFM1.hmidigits += ((drePOL.actDrvTimer/100)*(CYCLE_TIME_IN_MICROS))/1000L;  // Both subsystems (POL and FM1) share same hmi
#endif  

  // Set leds & digits
  module.setLEDs(dreFM1.hmileds);
  module.setDisplayToDecNumber(dreFM1.hmidigits, 0);
}












