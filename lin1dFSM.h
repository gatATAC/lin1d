/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "lin1dFSM_CI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */

/* ['ActRectifier' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_ACTRECTIFIER_INIT 0
#define ID_ACTRECTIFIER_QUIET 1
#define ID_ACTRECTIFIER_FW 2
#define ID_ACTRECTIFIER_BW 3

void ActRectifier(  );
/* ['ActRectifier' end (DON'T REMOVE THIS LINE!)] */

/* ['ActDriving' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_ACTDRIVING_INIT 4
#define ID_ACTDRIVING_STABILIZE 5
#define ID_ACTDRIVING_WORK 6
#define ID_ACTDRIVING_DISSIPATE 7

void ActDriving(  );
/* ['ActDriving' end (DON'T REMOVE THIS LINE!)] */

/* ['ActEnabler' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_ACTENABLER_INIT 8
#define ID_ACTENABLER_DISABLED 9
#define ID_ACTENABLER_ENABLED 10

void ActEnabler(  );
/* ['ActEnabler' end (DON'T REMOVE THIS LINE!)] */

/* ['UpButAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_UPBUTACQ_INIT 20
#define ID_UPBUTACQ_NOTPRESSED 21
#define ID_UPBUTACQ_PRESSED 22

void UpButAcq(  );
/* ['UpButAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['DownButAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_DOWNBUTACQ_INIT 23
#define ID_DOWNBUTACQ_NOTPRESSED 24
#define ID_DOWNBUTACQ_PRESSED 25

void DownButAcq(  );
/* ['DownButAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['PosControl' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_POSCONTROL_INIT 11
#define ID_POSCONTROL_STOP 12
#define ID_POSCONTROL_GOINGUP 13
#define ID_POSCONTROL_GOINGDOWN 14

void PosControl(  );
/* ['PosControl' end (DON'T REMOVE THIS LINE!)] */

/* ['ModeSelector' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_MODESELECTOR_INIT 15
#define ID_MODESELECTOR_STOP 16
#define ID_MODESELECTOR_UP 17
#define ID_MODESELECTOR_DOWN 18
#define ID_MODESELECTOR_STOPWAIT 19

void ModeSelector(  );
/* ['ModeSelector' end (DON'T REMOVE THIS LINE!)] */
