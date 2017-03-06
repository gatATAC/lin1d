#include "monitor.h"
#include "DRE.h"


#include <TM1638.h>

extern TM1638 module;
extern t_dre dre;

#include "lin1dFSM_CI.h"
extern STATE_T state;

void monitorInit(){
  dre.hmileds=0x00;
  dre.hmidigits=0;
  module.setLEDs(dre.hmileds);
  module.setDisplayToDecNumber(dre.hmidigits, 0);
}

extern STATE_T state;

void monitorExec(){
  
  // Calculate leds
  dre.hmileds=0x00;
  if (dre.posMode==CFG_POS_MODE_UP){
    dre.hmileds |= CFG_HMILEDS_POSMODE_UP_MASK;
  }
  if (dre.posMode==CFG_POS_MODE_DOWN){
    dre.hmileds |= CFG_HMILEDS_POSMODE_DOWN_MASK;
  }
  if (dre.loadPosUpSwchAcq == TRUE){
    dre.hmileds |= CFG_HMILEDS_SWITCH_UP_MASK;
  }
  if (dre.loadPosDownSwchAcq == TRUE){
    dre.hmileds |= CFG_HMILEDS_SWITCH_DOWN_MASK;
  }
  if (dre.upReqAcq == TRUE){
    dre.hmileds |= CFG_HMILEDS_REQ_UP_MASK;
  }
  if (dre.downReqAcq == TRUE){
    dre.hmileds |= CFG_HMILEDS_REQ_DOWN_MASK;
  }

  int i;
  uint8_t ret=0;
  
  for (i=0;i<9;i++){
    if ((dre.hmibuttons >> (i-1)) & 0x01) {
      ret = i;
      i=10;
    }
  }
  
  // Calculate digits
  //dre.hmidigits=dre.posMode * 10000000 + ret * 10000000 + dre.downSwitchTimer + 1000 * state + dre.upSwitchTimer + dre.downButTimer + dre.upButTimer;
  dre.hmidigits = ret * 10000000;
  dre.hmidigits += 100000 * (dre.downButTimer + dre.upButTimer);
  dre.hmidigits += 1000 * (dre.downSwitchTimer + dre.upSwitchTimer);

  // Set leds & digits
  module.setLEDs(dre.hmileds);
  module.setDisplayToDecNumber(dre.hmidigits, 0);
}


