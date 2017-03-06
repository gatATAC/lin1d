/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "lin1dFSM_CI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

/* ['downSwitchAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_DOWNSWITCHACQ_INIT 0
#define ID_DOWNSWITCHACQ_NOTDETECTED 1
#define ID_DOWNSWITCHACQ_DETECTED 2

void downSwitchAcq(  );
/* ['downSwitchAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['upSwitchAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_UPSWITCHACQ_INIT 3
#define ID_UPSWITCHACQ_NOTDETECTED 4
#define ID_UPSWITCHACQ_DETECTED 5

void upSwitchAcq(  );
/* ['upSwitchAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['ActRectifier' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_ACTRECTIFIER_INIT 6
#define ID_ACTRECTIFIER_QUIET 7
#define ID_ACTRECTIFIER_FW 8
#define ID_ACTRECTIFIER_BW 9

void ActRectifier(  );
/* ['ActRectifier' end (DON'T REMOVE THIS LINE!)] */

/* ['ActDriving' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_ACTDRIVING_INIT 10
#define ID_ACTDRIVING_STABILIZE 11
#define ID_ACTDRIVING_WORK 12
#define ID_ACTDRIVING_DISSIPATE 13

void ActDriving(  );
/* ['ActDriving' end (DON'T REMOVE THIS LINE!)] */

/* ['ActEnabler' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_ACTENABLER_INIT 14
#define ID_ACTENABLER_DISABLED 15
#define ID_ACTENABLER_ENABLED 16

void ActEnabler(  );
/* ['ActEnabler' end (DON'T REMOVE THIS LINE!)] */

/* ['PosControl' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_POSCONTROL_INIT 17
#define ID_POSCONTROL_STOP 18
#define ID_POSCONTROL_GOINGUP 19
#define ID_POSCONTROL_GOINGDOWN 20

void PosControl(  );
/* ['PosControl' end (DON'T REMOVE THIS LINE!)] */

/* ['ModeSelector' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_MODESELECTOR_INIT 21
#define ID_MODESELECTOR_STOP 22
#define ID_MODESELECTOR_UP 23
#define ID_MODESELECTOR_DOWN 24
#define ID_MODESELECTOR_STOPWAIT 25

void ModeSelector(  );
/* ['ModeSelector' end (DON'T REMOVE THIS LINE!)] */

/* ['UpButAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_UPBUTACQ_INIT 26
#define ID_UPBUTACQ_NOTPRESSED 27
#define ID_UPBUTACQ_PRESSED 28

void UpButAcq(  );
/* ['UpButAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['DownButAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_DOWNBUTACQ_INIT 29
#define ID_DOWNBUTACQ_NOTPRESSED 30
#define ID_DOWNBUTACQ_PRESSED 31

void DownButAcq(  );
/* ['DownButAcq' end (DON'T REMOVE THIS LINE!)] */
