#include "Lin1DCmdDRE.h"

// --- DRE data structure declaration ---
t_dreLin1DCmd dre;

void dre_init(void){
  dre.m1.en = false;
  dre.m2.en = false;
  dre.m3.en = false;
  dre.m1.cmd = "";
  dre.m2.cmd = "";
  dre.m3.cmd = "";
  dre.m1.req = false;
  dre.m2.req = false;
  dre.m3.req = false;
  dre.m1.resp = "";
  dre.m2.resp = "";
  dre.m3.resp = "";
  dre.m1.la = false;
  dre.m2.la = false;
  dre.m3.la = false;
  dre.m1.np = false;
  dre.m2.np = false;
  dre.m3.np = false;
  dre.m1.reqpos = false;
  dre.m2.reqpos = false;
  dre.m3.reqpos = false;
  dre.m1.m = false;
  dre.m2.m = false;
  dre.m3.m = false;
  dre.m1.spd = false;
  dre.m2.spd = false;
  dre.m3.spd = false;

  dre.m1.spdarg = 0;
  dre.m2.spdarg = 0;
  dre.m3.spdarg = 0;
  dre.m1.posarg = 0;
  dre.m2.posarg = 0;
  dre.m3.posarg = 0;
  dre.m1.pos = 0;
  dre.m2.pos = 0;
  dre.m3.pos = 0;
  dre.m1.spdarg = dre.m1.pos;
  dre.m2.spdarg = dre.m2.pos;
  dre.m3.spdarg = dre.m3.pos;

  dre.m1.npflag = false;
  dre.m2.npflag = false;
  dre.m3.npflag = false;
  dre.m1.laflag = false;
  dre.m2.laflag = false;
  dre.m3.laflag = false;
  dre.m1.simstop = false;
  dre.m2.simstop = false;
  dre.m3.simstop = false;
  dre.m1.hosp = false;
  dre.m2.hosp = false;
  dre.m3.hosp = false;
  dre.m1.goix = false;
  dre.m2.goix = false;
  dre.m3.goix = false;
  dre.m1.apl = false;
  dre.m2.apl = false;
  dre.m3.apl = false;
  dre.m1.gohoseq = false;
  dre.m2.gohoseq = false;
  dre.m3.gohoseq = false;
  dre.m1.error = false;
  dre.m2.error = false;
  dre.m3.error = false;


  dre.lastconnection = NULL;
  dre.mX = &dre.m1;
  dre.rx_buffer = "";
  dre.command_rx_buf = "";
  dre.char_read = 0;
  dre.command_tx_buf = "";
  dre.cte_use_socket = false;
  dre.response = "Wey";
  dre.activeMotorPrefix = "";
  dre.m1port = 0;
  dre.m2port = 0;
  dre.m3port = 0;
  dre.disable_untimely_resp = false;
  dre.dispatcher_idx = 0;
  dre.port = "";
}
