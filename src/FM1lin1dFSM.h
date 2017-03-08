/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "FM1lin1dFSM_CI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1downSwitchAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_FM1DOWNSWITCHACQ_INIT 0
#define ID_FM1DOWNSWITCHACQ_NOTDETECTED 1
#define ID_FM1DOWNSWITCHACQ_DETECTED 2

void FM1downSwitchAcq(  );
/* ['FM1downSwitchAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1upSwitchAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_FM1UPSWITCHACQ_INIT 3
#define ID_FM1UPSWITCHACQ_NOTDETECTED 4
#define ID_FM1UPSWITCHACQ_DETECTED 5

void FM1upSwitchAcq(  );
/* ['FM1upSwitchAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1ActRectifier' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_FM1ACTRECTIFIER_INIT 6
#define ID_FM1ACTRECTIFIER_BW 7
#define ID_FM1ACTRECTIFIER_FW 8
#define ID_FM1ACTRECTIFIER_QUIET 9

void FM1ActRectifier(  );
/* ['FM1ActRectifier' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1ActDriving' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_FM1ACTDRIVING_INIT 10
#define ID_FM1ACTDRIVING_DISSIPATE 11
#define ID_FM1ACTDRIVING_STABILIZE 12
#define ID_FM1ACTDRIVING_WORK 13

void FM1ActDriving(  );
/* ['FM1ActDriving' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1ActEnabler' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_FM1ACTENABLER_INIT 14
#define ID_FM1ACTENABLER_ENABLED 15
#define ID_FM1ACTENABLER_DISABLED 16

void FM1ActEnabler(  );
/* ['FM1ActEnabler' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1PosControl' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_FM1POSCONTROL_INIT 17
#define ID_FM1POSCONTROL_STOP 18
#define ID_FM1POSCONTROL_GOINGUP 19
#define ID_FM1POSCONTROL_GOINGDOWN 20

void FM1PosControl(  );
/* ['FM1PosControl' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1ModeSelector' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_FM1MODESELECTOR_INIT 21
#define ID_FM1MODESELECTOR_STOP 22
#define ID_FM1MODESELECTOR_UP 23
#define ID_FM1MODESELECTOR_DOWN 24
#define ID_FM1MODESELECTOR_STOPWAIT 25

void FM1ModeSelector(  );
/* ['FM1ModeSelector' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1UpButAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_FM1UPBUTACQ_INIT 26
#define ID_FM1UPBUTACQ_NOTPRESSED 27
#define ID_FM1UPBUTACQ_PRESSED 28

void FM1UpButAcq(  );
/* ['FM1UpButAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['FM1DownButAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_FM1DOWNBUTACQ_INIT 29
#define ID_FM1DOWNBUTACQ_NOTPRESSED 30
#define ID_FM1DOWNBUTACQ_PRESSED 31

void FM1DownButAcq(  );
/* ['FM1DownButAcq' end (DON'T REMOVE THIS LINE!)] */

