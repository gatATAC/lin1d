#ifndef _LIN1DCMD_DRE_H
#define _LIN1DCMD_DRE_H

#include <Arduino.h>
#include "ProjectTypes.h"
#include "ProjectFlows.h"

typedef struct {
  bool en;
  String cmd;
  bool req;
  String resp;

  bool la;
  bool np;

  bool reqpos;
  bool m;
  bool spd;

  int spdarg;
  int posarg;
  int pos;
  int setpoint;

  bool npflag;
  bool laflag;
  bool simstop;

  bool hosp;
  bool goix;
  bool apl;
  bool gohoseq;

  bool error;
}t_motor;

typedef struct {
      void *lastconnection;
      t_motor m1;
      t_motor m2;
      t_motor m3;
      t_motor *mX;
      String rx_buffer;
      String command_rx_buf;
      char char_read;
      String command_tx_buf;
      bool cte_use_socket;
      String response;
      String activeMotorPrefix;
      int m1port;
      int m2port;
      int m3port;
      bool disable_untimely_resp;
      int dispatcher_idx;
      int tmpInt;
      String tmpBuf;
      String port;
} t_dreLin1DCmd;

void dre_init();

#endif /* lIN1DCMD_DRE_H */
