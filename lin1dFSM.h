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
#define ID_ACTDRIVING_WORK 5
#define ID_ACTDRIVING_STABILIZE 6
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
#define ID_UPBUTACQ_INIT 11
#define ID_UPBUTACQ_NOTPRESSED 12
#define ID_UPBUTACQ_PRESSED 13

void UpButAcq(  );
/* ['UpButAcq' end (DON'T REMOVE THIS LINE!)] */

/* ['DownButAcq' begin (DON'T REMOVE THIS LINE!)] */
/* State IDs */
#define ID_DOWNBUTACQ_INIT 14
#define ID_DOWNBUTACQ_PRESSED 15
#define ID_DOWNBUTACQ_NOTPRESSED 16

void DownButAcq(  );
/* ['DownButAcq' end (DON'T REMOVE THIS LINE!)] */
