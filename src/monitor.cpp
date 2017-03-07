#include "monitor.h"
#include "FM1DRE.h"


#include <TM1638.h>

extern TM1638 module;
extern t_dreFM1 dreFM1;

#include "FM1lin1dFSM_CI.h"
extern STATE_T state;

void monitorInit(){
  dreFM1.hmileds=0x00;
  dreFM1.hmidigits=0;
  module.setLEDs(dreFM1.hmileds);
  module.setDisplayToDecNumber(dreFM1.hmidigits, 0);
}

extern STATE_T state;

void monitorExec(){
  
  // Calculate leds
  dreFM1.hmileds=0x00;
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

  int i;
  uint8_t ret=0;
  
  for (i=0;i<9;i++){
    if ((dreFM1.hmibuttons >> (i-1)) & 0x01) {
      ret = i;
      i=10;
    }
  }
  
  // Calculate digits
  //dreFM1.hmidigits=dreFM1.posMode * 10000000 + ret * 10000000 + dreFM1.downSwitchTimer + 1000 * state + dreFM1.upSwitchTimer + dreFM1.downButTimer + dreFM1.upButTimer;
  dreFM1.hmidigits = ret * 10000000;
  dreFM1.hmidigits += 100000 * (dreFM1.downButTimer + dreFM1.upButTimer);
  dreFM1.hmidigits += 1000 * (dreFM1.downSwitchTimer + dreFM1.upSwitchTimer);

  // Set leds & digits
  module.setLEDs(dreFM1.hmileds);
  module.setDisplayToDecNumber(dreFM1.hmidigits, 0);
}

