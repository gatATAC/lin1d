/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "Lin1DCmd_CI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

/* ['M3Sim' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_M3SIM_INITIAL 0
#define ID_M3SIM_FINAL 1
#define ID_M3SIM_IDLE 2
#define ID_M3SIM_MOVING 3

STATE_T M3Sim(  );
/* ['M3Sim' end (DON'T REMOVE THIS LINE!)] */

/* ['M3' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_M3_INITIAL 4
#define ID_M3_FINAL 5
#define ID_M3_WAITING 6

STATE_T M3(  );
/* ['M3' end (DON'T REMOVE THIS LINE!)] */

/* ['M2Sim' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_M2SIM_INITIAL 7
#define ID_M2SIM_FINAL 8
#define ID_M2SIM_IDLE 9
#define ID_M2SIM_MOVING 10

STATE_T M2Sim(  );
/* ['M2Sim' end (DON'T REMOVE THIS LINE!)] */

/* ['M2' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_M2_INITIAL 11
#define ID_M2_FINAL 12
#define ID_M2_WAITING 13

STATE_T M2(  );
/* ['M2' end (DON'T REMOVE THIS LINE!)] */

/* ['M1Sim' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_M1SIM_INITIAL 14
#define ID_M1SIM_FINAL 15
#define ID_M1SIM_MOVING 16
#define ID_M1SIM_IDLE 17

STATE_T M1Sim(  );
/* ['M1Sim' end (DON'T REMOVE THIS LINE!)] */

/* ['M1' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_M1_INITIAL 18
#define ID_M1_FINAL 19
#define ID_M1_WAITING 20

STATE_T M1(  );
/* ['M1' end (DON'T REMOVE THIS LINE!)] */

/* ['DecodeMotorCmd' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_DECODEMOTORCMD_INITIAL 21
#define ID_DECODEMOTORCMD_FINAL 22
#define ID_DECODEMOTORCMD_ERROR 23
#define ID_DECODEMOTORCMD_NRECEIVED 24
#define ID_DECODEMOTORCMD_SRECEIVED 25
#define ID_DECODEMOTORCMD_PORECEIVED 26
#define ID_DECODEMOTORCMD_PRECEIVED 27
#define ID_DECODEMOTORCMD_LRECEIVED 28
#define ID_DECODEMOTORCMD_GRECEIVED 29

STATE_T DecodeMotorCmd(  );
/* ['DecodeMotorCmd' end (DON'T REMOVE THIS LINE!)] */

/* ['ProgramMotors' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_PROGRAMMOTORS_INITIAL 30
#define ID_PROGRAMMOTORS_FINAL 31
#define ID_PROGRAMMOTORS_M2BYPASS 32
#define ID_PROGRAMMOTORS_M1BYPASS 33
#define ID_PROGRAMMOTORS_M2DECODED 34
#define ID_PROGRAMMOTORS_M3DECODED 35
#define ID_PROGRAMMOTORS_M1DECODED 36

STATE_T ProgramMotors(  );
/* ['ProgramMotors' end (DON'T REMOVE THIS LINE!)] */

/* ['CmdDispatcher' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_CMDDISPATCHER_INITIAL 37
#define ID_CMDDISPATCHER_FINAL 38
#define ID_CMDDISPATCHER_DECODEENGINE 39
#define ID_CMDDISPATCHER_PROGRAMMOTORS 40

STATE_T CmdDispatcher(  );
/* ['CmdDispatcher' end (DON'T REMOVE THIS LINE!)] */

/* ['sendCtrlResponse' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_SENDCTRLRESPONSE_INITIAL 41
#define ID_SENDCTRLRESPONSE_FINAL 42

STATE_T sendCtrlResponse(  );
/* ['sendCtrlResponse' end (DON'T REMOVE THIS LINE!)] */

/* ['getCtrlCommand' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_GETCTRLCOMMAND_INITIAL 43
#define ID_GETCTRLCOMMAND_FINAL 44
#define ID_GETCTRLCOMMAND_READING 45
#define ID_GETCTRLCOMMAND_PREVBUF 46

STATE_T getCtrlCommand(  );
/* ['getCtrlCommand' end (DON'T REMOVE THIS LINE!)] */

/* ['sendCtrlCommand' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_SENDCTRLCOMMAND_INITIAL 47
#define ID_SENDCTRLCOMMAND_FINAL 48

STATE_T sendCtrlCommand(  );
/* ['sendCtrlCommand' end (DON'T REMOVE THIS LINE!)] */

/* ['getCtrlResponse' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_GETCTRLRESPONSE_INITIAL 49
#define ID_GETCTRLRESPONSE_FINAL 50
#define ID_GETCTRLRESPONSE_READING 51
#define ID_GETCTRLRESPONSE_FINISHING 52

STATE_T getCtrlResponse(  );
/* ['getCtrlResponse' end (DON'T REMOVE THIS LINE!)] */
