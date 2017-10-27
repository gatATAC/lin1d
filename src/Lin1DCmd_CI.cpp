/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "Lin1DCmd_CI.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */
#include "Lin1DCmdDRE.h"
#include "Lin1DCmd.h"
extern t_dreLin1DCmd dre;
/* ['Common definitions for 'Code items generator'' begin (DON'T REMOVE THIS LINE!)] */
/* Generic code items' definitions */
void sendUntimelyResponse( String resptosend )
{
    /* ['<global>::sendUntimelyResponse' begin] */
    if (!dre.disable_untimely_resp){

        Serial.println(resptosend);

    }

    /* ['<global>::sendUntimelyResponse' end] */
}
/* ['Common definitions for 'Code items generator'' end (DON'T REMOVE THIS LINE!)] */

/* ['Common definitions for 'Hierarchical State Chart generator'' begin (DON'T REMOVE THIS LINE!)] */
/* Code items' definitions */
char serialCharRead(  )
{
    /* ['<global>::serialCharRead' begin] */
    dre.char_read=Serial.read();
    /* ['<global>::serialCharRead' end] */
}
void decodeM1Cmd(  )
{
    /* ['<global>::decodeM1Cmd' begin] */
    // Prepare common decoder with M1 values
    dre.mX = &(dre.m1);
    
    // Call common decoder
    DecodeMotorCmd();
    /* ['<global>::decodeM1Cmd' end] */
}
void decodeM2Cmd(  )
{
    /* ['<global>::decodeM2Cmd' begin] */
    // Prepare common decoder with M2 values
    dre.mX =  &(dre.m2);
    
    // Call common decoder
    DecodeMotorCmd();
    /* ['<global>::decodeM2Cmd' end] */
}
void decodeM3Cmd(  )
{
    /* ['<global>::decodeM3Cmd' begin] */
    // Prepare common decoder with M3 values
    dre.mX = &(dre.m3);
    
    // Call common decoder
    DecodeMotorCmd();
    /* ['<global>::decodeM3Cmd' end] */
}
void resetDecoder(  )
{
    /* ['<global>::resetDecoder' begin] */
    // Flush commands from M1
    dre.mX->la = false;
    dre.mX->np = false;
    dre.mX->hosp = false;
    dre.mX->goix = false;
    dre.mX->apl = false;
    dre.mX->gohoseq = false;
    dre.mX->reqpos = false;
    dre.mX->m = false;
    dre.mX->spd = false;
    // Flush arguments from M1
    dre.mX->spdarg = 0;
    dre.mX->posarg = 0;
    // Flush error
    dre.mX->error = false;
    /* ['<global>::resetDecoder' end] */
}
void programGoHoSeq(  )
{
    /* ['<global>::programGoHoSeq' begin] */
    // Program GoHoSeq similar to program LA with setpoint = 0
    dre.mX->setpoint = 0;
    dre.mX->m = true;
    /* ['<global>::programGoHoSeq' end] */
}
bool checkCharAtPos( int idx, int cToCheck, int isEqual )
{
    /* ['<global>::checkCharAtPos' begin] */
    if (isEqual){
        return (dre.mX->cmd.charAt(idx) == cToCheck);
    } else {
        return (dre.mX->cmd.charAt(idx) != cToCheck);
    }
    /* ['<global>::checkCharAtPos' end] */
}
bool targetChange(  )
{
    /* ['<global>::targetChange' begin] */
    //(("#" in dre.command_rx_buf) or ("@" in dre.command_rx_buf))
    bool ret = false;
    
    dre.tmpInt = dre.command_rx_buf.indexOf('#');
    if (dre.tmpInt >= 0){
        ret = true;
    } else {
        dre.tmpInt = dre.command_rx_buf.indexOf('@');
        if (dre.tmpInt >= 0){
            ret = true;
        }
    }
    
    return ret;
    /* ['<global>::targetChange' end] */
}
/* ['Common definitions for 'Hierarchical State Chart generator'' end (DON'T REMOVE THIS LINE!)] */
