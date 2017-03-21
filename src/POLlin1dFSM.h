/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "POLlin1dFSM_CI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

/* ['POLdownSwitchAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_POLDOWNSWITCHACQ_INIT 0
#define ID_POLDOWNSWITCHACQ_NOTDETECTED 1
#define ID_POLDOWNSWITCHACQ_DETECTED 2

void POLdownSwitchAcq();
/* ['POLdownSwitchAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['POLupSwitchAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_POLUPSWITCHACQ_INIT 3
#define ID_POLUPSWITCHACQ_NOTDETECTED 4
#define ID_POLUPSWITCHACQ_DETECTED 5

void POLupSwitchAcq();
/* ['POLupSwitchAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['POLActRectifier' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_POLACTRECTIFIER_INIT 6
#define ID_POLACTRECTIFIER_QUIET 7
#define ID_POLACTRECTIFIER_FW 8
#define ID_POLACTRECTIFIER_BW 9

void POLActRectifier();
/* ['POLActRectifier' end (DON'T REMOVE THIS LINE!)] */

/* ['POLActDriving' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_POLACTDRIVING_INIT 10
#define ID_POLACTDRIVING_STABILIZE 11
#define ID_POLACTDRIVING_WORK 12
#define ID_POLACTDRIVING_DISSIPATE 13

void POLActDriving();
/* ['POLActDriving' end (DON'T REMOVE THIS LINE!)] */

/* ['POLActEnabler' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_POLACTENABLER_INIT 14
#define ID_POLACTENABLER_DISABLED 15
#define ID_POLACTENABLER_ENABLED 16

void POLActEnabler();
/* ['POLActEnabler' end (DON'T REMOVE THIS LINE!)] */

/* ['POLPosControl' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_POLPOSCONTROL_INIT 17
#define ID_POLPOSCONTROL_STOP 18
#define ID_POLPOSCONTROL_GOINGUP 19
#define ID_POLPOSCONTROL_GOINGDOWN 20

void POLPosControl();
/* ['POLPosControl' end (DON'T REMOVE THIS LINE!)] */

/* ['POLModeSelector' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_POLMODESELECTOR_INIT 21
#define ID_POLMODESELECTOR_STOP 22
#define ID_POLMODESELECTOR_UP 23
#define ID_POLMODESELECTOR_DOWN 24
#define ID_POLMODESELECTOR_STOPWAIT 25

void POLModeSelector();
/* ['POLModeSelector' end (DON'T REMOVE THIS LINE!)] */

/* ['POLUpButAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_POLUPBUTACQ_INIT 26
#define ID_POLUPBUTACQ_NOTPRESSED 27
#define ID_POLUPBUTACQ_PRESSED 28

void POLUpButAcq();
/* ['POLUpButAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['POLDownButAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_POLDOWNBUTACQ_INIT 29
#define ID_POLDOWNBUTACQ_NOTPRESSED 30
#define ID_POLDOWNBUTACQ_PRESSED 31

void POLDownButAcq();
/* ['POLDownButAcq' end (DON'T REMOVE THIS LINE!)] */
