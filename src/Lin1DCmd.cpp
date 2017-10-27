/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include "Lin1DCmd.h"
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */
#include <Arduino.h>
#include "Lin1DCmdDRE.h"
extern t_dreLin1DCmd dre;
/* ['M3Sim' begin (DON'T REMOVE THIS LINE!)] */
STATE_T M3Sim(  )
{
    /* set initial state */
    static STATE_T state = ID_M3SIM_INITIAL;

    /* State ID: ID_M3SIM_INITIAL */
    if( state==ID_M3SIM_INITIAL )
    {
        /* Transition ID: ID_M3SIM_TRANSITION_CONNECTION */
        state = ID_M3SIM_IDLE;
        return ID_M3SIM_INITIAL;
    }
    /* State ID: ID_M3SIM_IDLE */
    else if( state==ID_M3SIM_IDLE )
    {
        if( ((dre.m3.laflag) == (true)) )
        {
            /* Transition ID: ID_M3SIM_TRANSITION_CONNECTION */
            state = ID_M3SIM_MOVING;
        }
        else if( ((dre.m3.simstop) == (true)) )
        {
            /* Transition ID: ID_M3SIM_TRANSITION_CONNECTION */
            state = ID_M3SIM_FINAL;
        }
        return ID_M3SIM_IDLE;
    }
    /* State ID: ID_M3SIM_FINAL */
    else if( state==ID_M3SIM_FINAL )
    {
        state = ID_M3SIM_INITIAL;
        return ID_M3SIM_FINAL;
    }
    /* State ID: ID_M3SIM_MOVING */
    else if( state==ID_M3SIM_MOVING )
    {
        if( (dre.m3.setpoint > dre.m3.pos) )
        {
            /* Transition ID: ID_M3SIM_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::incrDelta' begin] */
            dre.tmpInt = dre.m3.pos;

            dre.m3.pos += 1;

            // print obtainVarName(dre.m3.pos)+":"+String((tmp)+"+"+String((1)+"="+String((dre.m3.pos)
            /* ['<global>::incrDelta' end] */
        }
        else if( (dre.m3.pos > dre.m3.setpoint) )
        {
            /* Transition ID: ID_M3SIM_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::incrDelta' begin] */
            dre.tmpInt = dre.m3.pos;

            dre.m3.pos += -1;

            // print obtainVarName(dre.m3.pos)+":"+String((tmp)+"+"+String((-1)+"="+String((dre.m3.pos)
            /* ['<global>::incrDelta' end] */
        }
        else
        {
            /* Transition ID: ID_M3SIM_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::NotifyEndM3Mv' begin] */
            if (dre.m3.npflag){

                Serial.println("notify M3 #1");

                dre.m3.npflag = false;

                Serial.println("notify M3 #2");

                dre.m3.laflag = false;

                Serial.println("notify M3 #3");

                sendUntimelyResponse("p");

                Serial.println("notify M3 #4");

            }

            /* ['<global>::NotifyEndM3Mv' end] */
            /* ['<global>::setFlag' begin] */
            dre.m3.laflag = false;

            /* ['<global>::setFlag' end] */
            state = ID_M3SIM_IDLE;
        }
        return ID_M3SIM_MOVING;
    }
}
/* ['M3Sim' end (DON'T REMOVE THIS LINE!)] */

/* ['M3' begin (DON'T REMOVE THIS LINE!)] */
STATE_T M3(  )
{
    /* set initial state */
    static STATE_T state = ID_M3_INITIAL;

    /* State ID: ID_M3_INITIAL */
    if( state==ID_M3_INITIAL )
    {
        /* Transition ID: ID_M3_TRANSITION_CONNECTION */
        /* Actions: */
        /* ['<global>::setM3Response' begin] */
        dre.m3.resp = "OK";
        /* ['<global>::setM3Response' end] */
        state = ID_M3_WAITING;
        return ID_M3_INITIAL;
    }
    /* State ID: ID_M3_WAITING */
    else if( state==ID_M3_WAITING )
    {
        if( ((dre.m3.reqpos) == (true)) )
        {
            /* Transition ID: ID_M3_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setM3Response' begin] */
            dre.m3.resp = String(dre.m3.pos);
            /* ['<global>::setM3Response' end] */
            state = ID_M3_FINAL;
        }
        else if( ((dre.m3.la) == (true)) )
        {
            /* Transition ID: ID_M3_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setVar' begin] */
            dre.m3.setpoint = (dre.m3.posarg);
            /* ['<global>::setVar' end] */
            state = ID_M3_FINAL;
        }
        else
        {
            /* Transition ID: ID_M3_OPTIMIZED_TRANSITION_1 */
            state = ID_M3_FINAL;
        }
        return ID_M3_WAITING;
    }
    /* State ID: ID_M3_FINAL */
    else if( state==ID_M3_FINAL )
    {
        state = ID_M3_INITIAL;
        return ID_M3_FINAL;
    }
}
/* ['M3' end (DON'T REMOVE THIS LINE!)] */

/* ['M2Sim' begin (DON'T REMOVE THIS LINE!)] */
STATE_T M2Sim(  )
{
    /* set initial state */
    static STATE_T state = ID_M2SIM_INITIAL;

    /* State ID: ID_M2SIM_INITIAL */
    if( state==ID_M2SIM_INITIAL )
    {
        /* Transition ID: ID_M2SIM_TRANSITION_CONNECTION */
        state = ID_M2SIM_IDLE;
        return ID_M2SIM_INITIAL;
    }
    /* State ID: ID_M2SIM_IDLE */
    else if( state==ID_M2SIM_IDLE )
    {
        if( ((dre.m2.laflag) == (true)) )
        {
            /* Transition ID: ID_M2SIM_TRANSITION_CONNECTION */
            state = ID_M2SIM_MOVING;
        }
        else if( ((dre.m2.simstop) == (true)) )
        {
            /* Transition ID: ID_M2SIM_TRANSITION_CONNECTION */
            state = ID_M2SIM_FINAL;
        }
        return ID_M2SIM_IDLE;
    }
    /* State ID: ID_M2SIM_FINAL */
    else if( state==ID_M2SIM_FINAL )
    {
        state = ID_M2SIM_INITIAL;
        return ID_M2SIM_FINAL;
    }
    /* State ID: ID_M2SIM_MOVING */
    else if( state==ID_M2SIM_MOVING )
    {
        if( (dre.m2.setpoint > dre.m2.pos) )
        {
            /* Transition ID: ID_M2SIM_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::incrDelta' begin] */
            dre.tmpInt = dre.m2.pos;

            dre.m2.pos += 1;

            // print obtainVarName(dre.m2.pos)+":"+String((tmp)+"+"+String((1)+"="+String((dre.m2.pos)
            /* ['<global>::incrDelta' end] */
        }
        else if( (dre.m2.pos > dre.m2.setpoint) )
        {
            /* Transition ID: ID_M2SIM_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::incrDelta' begin] */
            dre.tmpInt = dre.m2.pos;

            dre.m2.pos += -1;

            // print obtainVarName(dre.m2.pos)+":"+String((tmp)+"+"+String((-1)+"="+String((dre.m2.pos)
            /* ['<global>::incrDelta' end] */
        }
        else
        {
            /* Transition ID: ID_M2SIM_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::notifyEndM2Mv' begin] */
            if (dre.m2.npflag){

                Serial.println("notify M2 #1");

                dre.m2.npflag = false;

                Serial.println("notify M2 #2");

                dre.m2.laflag = false;

                Serial.println("notify M2 #3");

                sendUntimelyResponse("p");

                Serial.println("notify M2 #4");

            }

            /* ['<global>::notifyEndM2Mv' end] */
            /* ['<global>::setFlag' begin] */
            dre.m2.laflag = false;

            /* ['<global>::setFlag' end] */
            state = ID_M2SIM_IDLE;
        }
        return ID_M2SIM_MOVING;
    }
}
/* ['M2Sim' end (DON'T REMOVE THIS LINE!)] */

/* ['M2' begin (DON'T REMOVE THIS LINE!)] */
STATE_T M2(  )
{
    /* set initial state */
    static STATE_T state = ID_M2_INITIAL;

    /* State ID: ID_M2_INITIAL */
    if( state==ID_M2_INITIAL )
    {
        /* Transition ID: ID_M2_TRANSITION_CONNECTION */
        /* Actions: */
        /* ['<global>::setM2Response' begin] */
        dre.m2.resp = "OK";
        /* ['<global>::setM2Response' end] */
        state = ID_M2_WAITING;
        return ID_M2_INITIAL;
    }
    /* State ID: ID_M2_WAITING */
    else if( state==ID_M2_WAITING )
    {
        if( ((dre.m2.reqpos) == (true)) )
        {
            /* Transition ID: ID_M2_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setM2Response' begin] */
            dre.m2.resp = String(dre.m2.pos);
            /* ['<global>::setM2Response' end] */
            state = ID_M2_FINAL;
        }
        else if( ((dre.m2.la) == (true)) )
        {
            /* Transition ID: ID_M2_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setVar' begin] */
            dre.m2.setpoint = (dre.m2.posarg);
            /* ['<global>::setVar' end] */
            state = ID_M2_FINAL;
        }
        else
        {
            /* Transition ID: ID_M2_OPTIMIZED_TRANSITION_1 */
            state = ID_M2_FINAL;
        }
        return ID_M2_WAITING;
    }
    /* State ID: ID_M2_FINAL */
    else if( state==ID_M2_FINAL )
    {
        state = ID_M2_INITIAL;
        return ID_M2_FINAL;
    }
}
/* ['M2' end (DON'T REMOVE THIS LINE!)] */

/* ['M1Sim' begin (DON'T REMOVE THIS LINE!)] */
STATE_T M1Sim(  )
{
    /* set initial state */
    static STATE_T state = ID_M1SIM_INITIAL;

    /* State ID: ID_M1SIM_INITIAL */
    if( state==ID_M1SIM_INITIAL )
    {
        /* Transition ID: ID_M1SIM_TRANSITION_CONNECTION */
        state = ID_M1SIM_IDLE;
        return ID_M1SIM_INITIAL;
    }
    /* State ID: ID_M1SIM_IDLE */
    else if( state==ID_M1SIM_IDLE )
    {
        if( ((dre.m1.laflag) == (true)) )
        {
            /* Transition ID: ID_M1SIM_TRANSITION_CONNECTION */
            state = ID_M1SIM_MOVING;
        }
        else if( ((dre.m1.simstop) == (true)) )
        {
            /* Transition ID: ID_M1SIM_TRANSITION_CONNECTION */
            state = ID_M1SIM_FINAL;
        }
        return ID_M1SIM_IDLE;
    }
    /* State ID: ID_M1SIM_MOVING */
    else if( state==ID_M1SIM_MOVING )
    {
        if( (dre.m1.pos > dre.m1.setpoint) )
        {
            /* Transition ID: ID_M1SIM_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::incrDelta' begin] */
            dre.tmpInt = dre.m1.pos;

            dre.m1.pos += -1;

            // print obtainVarName(dre.m1.pos)+":"+String((tmp)+"+"+String((-1)+"="+String((dre.m1.pos)
            /* ['<global>::incrDelta' end] */
        }
        else if( (dre.m1.setpoint > dre.m1.pos) )
        {
            /* Transition ID: ID_M1SIM_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::incrDelta' begin] */
            dre.tmpInt = dre.m1.pos;

            dre.m1.pos += 1;

            // print obtainVarName(dre.m1.pos)+":"+String((tmp)+"+"+String((1)+"="+String((dre.m1.pos)
            /* ['<global>::incrDelta' end] */
        }
        else
        {
            /* Transition ID: ID_M1SIM_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::notifyEndM1Mv' begin] */
            if (dre.m1.npflag){

                Serial.println("notify M1 #1");

                dre.m1.npflag = false;

                Serial.println("notify M1 #2");

                dre.m1.laflag = false;

                Serial.println("notify M1 #3");

                sendUntimelyResponse("p");

                Serial.println("notify M1 #4");

            }
            /* ['<global>::notifyEndM1Mv' end] */
            /* ['<global>::setFlag' begin] */
            dre.m1.laflag = false;

            /* ['<global>::setFlag' end] */
            state = ID_M1SIM_IDLE;
        }
        return ID_M1SIM_MOVING;
    }
    /* State ID: ID_M1SIM_FINAL */
    else if( state==ID_M1SIM_FINAL )
    {
        state = ID_M1SIM_INITIAL;
        return ID_M1SIM_FINAL;
    }
}
/* ['M1Sim' end (DON'T REMOVE THIS LINE!)] */

/* ['M1' begin (DON'T REMOVE THIS LINE!)] */
STATE_T M1(  )
{
    /* set initial state */
    static STATE_T state = ID_M1_INITIAL;

    /* State ID: ID_M1_INITIAL */
    if( state==ID_M1_INITIAL )
    {
        /* Transition ID: ID_M1_TRANSITION_CONNECTION */
        /* Actions: */
        /* ['<global>::setM1Response' begin] */
        dre.m1.resp = "OK";
        /* ['<global>::setM1Response' end] */
        state = ID_M1_WAITING;
        return ID_M1_INITIAL;
    }
    /* State ID: ID_M1_WAITING */
    else if( state==ID_M1_WAITING )
    {
        if( ((dre.m1.reqpos) == (true)) )
        {
            /* Transition ID: ID_M1_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setM1Response' begin] */
            dre.m1.resp = String(dre.m1.pos);
            /* ['<global>::setM1Response' end] */
            state = ID_M1_FINAL;
        }
        else if( ((dre.m1.la) == (true)) )
        {
            /* Transition ID: ID_M1_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setVar' begin] */
            dre.m1.setpoint = (dre.m1.posarg);
            /* ['<global>::setVar' end] */
            state = ID_M1_FINAL;
        }
        else
        {
            /* Transition ID: ID_M1_OPTIMIZED_TRANSITION_1 */
            state = ID_M1_FINAL;
        }
        return ID_M1_WAITING;
    }
    /* State ID: ID_M1_FINAL */
    else if( state==ID_M1_FINAL )
    {
        state = ID_M1_INITIAL;
        return ID_M1_FINAL;
    }
}
/* ['M1' end (DON'T REMOVE THIS LINE!)] */

/* ['DecodeMotorCmd' begin (DON'T REMOVE THIS LINE!)] */
STATE_T DecodeMotorCmd(  )
{
    /* set initial state */
    static STATE_T state = ID_DECODEMOTORCMD_INITIAL;

    /* State ID: ID_DECODEMOTORCMD_INITIAL */
    if( state==ID_DECODEMOTORCMD_INITIAL )
    {
        if( checkCharAtPos(0, 'N', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            resetDecoder();
            state = ID_DECODEMOTORCMD_NRECEIVED;
        }
        else if( checkCharAtPos(0, 'L', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            resetDecoder();
            state = ID_DECODEMOTORCMD_LRECEIVED;
        }
        else if( checkCharAtPos(0, 'P', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            resetDecoder();
            state = ID_DECODEMOTORCMD_PRECEIVED;
        }
        else if( checkCharAtPos(0, 'M', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            resetDecoder();
            /* ['<global>::programM' begin] */
            dre.mX->m = true;
            /* ['<global>::programM' end] */
            state = ID_DECODEMOTORCMD_FINAL;
        }
        else if( checkCharAtPos(0, 'S', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            resetDecoder();
            state = ID_DECODEMOTORCMD_SRECEIVED;
        }
        else if( checkCharAtPos(0, 'G', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            resetDecoder();
            state = ID_DECODEMOTORCMD_GRECEIVED;
        }
        else
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            resetDecoder();
            state = ID_DECODEMOTORCMD_ERROR;
        }
        return ID_DECODEMOTORCMD_INITIAL;
    }
    /* State ID: ID_DECODEMOTORCMD_LRECEIVED */
    else if( state==ID_DECODEMOTORCMD_LRECEIVED )
    {
        if( checkCharAtPos(1, 'A', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::programLA' begin] */
            dre.mX->la = true;

            dre.tmpBuf = dre.mX->cmd;

            dre.tmpBuf.remove(0,2);
            dre.mX->posarg = dre.tmpBuf.toInt();
            /* ['<global>::programLA' end] */
            state = ID_DECODEMOTORCMD_FINAL;
        }
        else if( checkCharAtPos(1, 'R', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::programLR' begin] */
            // LR is similar to LA

            dre.mX->la = true;
            dre.tmpBuf = dre.mX->cmd;

            dre.tmpBuf.remove(0,2);

            dre.mX->posarg = dre.mX->pos + dre.tmpBuf.toInt();
            /* ['<global>::programLR' end] */
            state = ID_DECODEMOTORCMD_FINAL;
        }
        else
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            state = ID_DECODEMOTORCMD_ERROR;
        }
        return ID_DECODEMOTORCMD_LRECEIVED;
    }
    /* State ID: ID_DECODEMOTORCMD_ERROR */
    else if( state==ID_DECODEMOTORCMD_ERROR )
    {
        /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
        /* Actions: */
        /* ['<global>::decodeError' begin] */
        dre.mX->error = true;
        /* ['<global>::decodeError' end] */
        state = ID_DECODEMOTORCMD_FINAL;
        return ID_DECODEMOTORCMD_ERROR;
    }
    /* State ID: ID_DECODEMOTORCMD_FINAL */
    else if( state==ID_DECODEMOTORCMD_FINAL )
    {
        state = ID_DECODEMOTORCMD_INITIAL;
        return ID_DECODEMOTORCMD_FINAL;
    }
    /* State ID: ID_DECODEMOTORCMD_SRECEIVED */
    else if( state==ID_DECODEMOTORCMD_SRECEIVED )
    {
        if( checkCharAtPos(1, 'P', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::programSP' begin] */
            dre.mX->spd = true;
            dre.tmpBuf = dre.mX->cmd;

            dre.tmpBuf.remove(0,2);

            dre.mX->spdarg = dre.tmpBuf.toInt();
            /* ['<global>::programSP' end] */
            state = ID_DECODEMOTORCMD_FINAL;
        }
        else
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            state = ID_DECODEMOTORCMD_ERROR;
        }
        return ID_DECODEMOTORCMD_SRECEIVED;
    }
    /* State ID: ID_DECODEMOTORCMD_PRECEIVED */
    else if( state==ID_DECODEMOTORCMD_PRECEIVED )
    {
        if( checkCharAtPos(1, 'O', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            state = ID_DECODEMOTORCMD_PORECEIVED;
        }
        else
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            state = ID_DECODEMOTORCMD_ERROR;
        }
        return ID_DECODEMOTORCMD_PRECEIVED;
    }
    /* State ID: ID_DECODEMOTORCMD_PORECEIVED */
    else if( state==ID_DECODEMOTORCMD_PORECEIVED )
    {
        if( checkCharAtPos(2, 'S', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::programPOS' begin] */
            dre.mX->reqpos = true;
            /* ['<global>::programPOS' end] */
            state = ID_DECODEMOTORCMD_FINAL;
        }
        else
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            state = ID_DECODEMOTORCMD_ERROR;
        }
        return ID_DECODEMOTORCMD_PORECEIVED;
    }
    /* State ID: ID_DECODEMOTORCMD_GRECEIVED */
    else if( state==ID_DECODEMOTORCMD_GRECEIVED )
    {
        if( checkCharAtPos(2, 'H', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            programGoHoSeq();
            state = ID_DECODEMOTORCMD_FINAL;
        }
        else if( checkCharAtPos(2, 'I', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::programGoIx' begin] */
            // Program GoIx similar to program LA with setpoint = 0

            dre.mX->setpoint = 0;

            dre.mX->m = true;

            /* ['<global>::programGoIx' end] */
            state = ID_DECODEMOTORCMD_FINAL;
        }
        else
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            state = ID_DECODEMOTORCMD_ERROR;
        }
        return ID_DECODEMOTORCMD_GRECEIVED;
    }
    /* State ID: ID_DECODEMOTORCMD_NRECEIVED */
    else if( state==ID_DECODEMOTORCMD_NRECEIVED )
    {
        if( checkCharAtPos(1, 'P', true) )
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::programNP' begin] */
            dre.mX->np = true;
            /* ['<global>::programNP' end] */
            state = ID_DECODEMOTORCMD_FINAL;
        }
        else
        {
            /* Transition ID: ID_DECODEMOTORCMD_TRANSITION_CONNECTION */
            state = ID_DECODEMOTORCMD_ERROR;
        }
        return ID_DECODEMOTORCMD_NRECEIVED;
    }
}
/* ['DecodeMotorCmd' end (DON'T REMOVE THIS LINE!)] */

/* ['ProgramMotors' begin (DON'T REMOVE THIS LINE!)] */
STATE_T ProgramMotors(  )
{
    /* set initial state */
    STATE_T state = ID_PROGRAMMOTORS_INITIAL;

    // for( ;; )
    {
        /* State ID: ID_PROGRAMMOTORS_INITIAL */
        if( state==ID_PROGRAMMOTORS_INITIAL )
        {
            if( dre.m1.req == false )
            {
                /* Transition ID: ID_PROGRAMMOTORS_TRANSITION_CONNECTION */
                state = ID_PROGRAMMOTORS_M1BYPASS;
            }
            else if( dre.m1.req == true )
            {
                /* Transition ID: ID_PROGRAMMOTORS_TRANSITION_CONNECTION */
                /* Actions: */
                decodeM1Cmd();
                state = ID_PROGRAMMOTORS_M1DECODED;
            }
        }
        /* State ID: ID_PROGRAMMOTORS_M1DECODED */
        else if( state==ID_PROGRAMMOTORS_M1DECODED )
        {
            if( dre.m2.req == false )
            {
                /* Transition ID: ID_PROGRAMMOTORS_TRANSITION_CONNECTION */
                state = ID_PROGRAMMOTORS_M2BYPASS;
            }
            else if( dre.m2.req == true )
            {
                /* Transition ID: ID_PROGRAMMOTORS_TRANSITION_CONNECTION */
                /* Actions: */
                decodeM2Cmd();
                state = ID_PROGRAMMOTORS_M2DECODED;
            }
        }
        /* State ID: ID_PROGRAMMOTORS_M2DECODED */
        else if( state==ID_PROGRAMMOTORS_M2DECODED )
        {
            if( dre.m3.req == true )
            {
                /* Transition ID: ID_PROGRAMMOTORS_TRANSITION_CONNECTION */
                /* Actions: */
                decodeM3Cmd();
                state = ID_PROGRAMMOTORS_M3DECODED;
            }
            else if( dre.m3.req == false )
            {
                /* Transition ID: ID_PROGRAMMOTORS_TRANSITION_CONNECTION */
                state = ID_PROGRAMMOTORS_FINAL;
            }
        }
        /* State ID: ID_PROGRAMMOTORS_FINAL */
        else if( state==ID_PROGRAMMOTORS_FINAL )
        {
            return ID_PROGRAMMOTORS_FINAL;
        }
        /* State ID: ID_PROGRAMMOTORS_M3DECODED */
        else if( state==ID_PROGRAMMOTORS_M3DECODED )
        {
            /* Transition ID: ID_PROGRAMMOTORS_TRANSITION_CONNECTION */
            state = ID_PROGRAMMOTORS_FINAL;
        }
        /* State ID: ID_PROGRAMMOTORS_M2BYPASS */
        else if( state==ID_PROGRAMMOTORS_M2BYPASS )
        {
            if( dre.m3.req == true )
            {
                /* Transition ID: ID_PROGRAMMOTORS_TRANSITION_CONNECTION */
                /* Actions: */
                decodeM3Cmd();
                state = ID_PROGRAMMOTORS_M3DECODED;
            }
            else if( dre.m3.req == false )
            {
                /* Transition ID: ID_PROGRAMMOTORS_TRANSITION_CONNECTION */
                state = ID_PROGRAMMOTORS_FINAL;
            }
        }
        /* State ID: ID_PROGRAMMOTORS_M1BYPASS */
        else if( state==ID_PROGRAMMOTORS_M1BYPASS )
        {
            if( dre.m2.req == true )
            {
                /* Transition ID: ID_PROGRAMMOTORS_TRANSITION_CONNECTION */
                /* Actions: */
                decodeM2Cmd();
                state = ID_PROGRAMMOTORS_M2DECODED;
            }
            else if( dre.m2.req == false )
            {
                /* Transition ID: ID_PROGRAMMOTORS_TRANSITION_CONNECTION */
                state = ID_PROGRAMMOTORS_M2BYPASS;
            }
        }
    }
}
/* ['ProgramMotors' end (DON'T REMOVE THIS LINE!)] */

/* ['CmdDispatcher' begin (DON'T REMOVE THIS LINE!)] */
STATE_T CmdDispatcher(  )
{
    /* set initial state */
    static STATE_T state = ID_CMDDISPATCHER_INITIAL;

    /* State ID: ID_CMDDISPATCHER_INITIAL */
    if( state==ID_CMDDISPATCHER_INITIAL )
    {
        /* Transition ID: ID_CMDDISPATCHER_TRANSITION_CONNECTION */
        /* Actions: */
        /* ['<global>::resetDispatcher' begin] */
        dre.dispatcher_idx = 0;
        dre.m1.cmd = "";
        dre.m2.cmd = "";
        dre.m2.cmd = "";
        dre.m1.req = false;
        dre.m2.req = false;
        dre.m3.req = false;
        /* ['<global>::resetDispatcher' end] */
        state = ID_CMDDISPATCHER_DECODEENGINE;
        return ID_CMDDISPATCHER_INITIAL;
    }
    /* State ID: ID_CMDDISPATCHER_DECODEENGINE */
    else if( state==ID_CMDDISPATCHER_DECODEENGINE )
    {
        if( targetChange() )
        {
            /* Transition ID: ID_CMDDISPATCHER_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setNewTarget' begin] */
            dre.tmpInt = dre.command_rx_buf.indexOf('#');

            if (dre.tmpInt >= 0){

                dre.port = dre.command_rx_buf;

                dre.port.remove(0,dre.tmpInt);

                if (dre.port == String(dre.m1port)){

                    dre.activeMotorPrefix = String(1);

                }

                if (dre.port == String(dre.m2port)){

                    dre.activeMotorPrefix = String(2);

                }

                if (dre.port == String(dre.m3port)){

                    dre.activeMotorPrefix = String(3);

                }

            } else {

                //("@" in dre.command_rx_buf)

                dre.activeMotorPrefix = "";

            }

            /* ['<global>::setNewTarget' end] */
            /* ['<global>::sendAnticipatedResponse' begin] */
            Serial.println("");
            /* ['<global>::sendAnticipatedResponse' end] */
            state = ID_CMDDISPATCHER_PROGRAMMOTORS;
        }
        else if( String(1).charAt(0) == dre.command_rx_buf.charAt(0) )
        {
            /* Transition ID: ID_CMDDISPATCHER_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setM1Cmd' begin] */
            dre.m1.req = true;
            dre.m1.cmd = dre.command_rx_buf;

            dre.m1.cmd.remove(0,1);
            /* ['<global>::setM1Cmd' end] */
            state = ID_CMDDISPATCHER_PROGRAMMOTORS;
        }
        else if( String(2).charAt(0) == dre.command_rx_buf.charAt(0) )
        {
            /* Transition ID: ID_CMDDISPATCHER_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setM2Cmd' begin] */
            dre.m2.req = true;

            dre.m2.cmd = dre.command_rx_buf;

            dre.m2.cmd.remove(0,1);
            /* ['<global>::setM2Cmd' end] */
            state = ID_CMDDISPATCHER_PROGRAMMOTORS;
        }
        else if( String(3).charAt(0) == dre.command_rx_buf.charAt(0) )
        {
            /* Transition ID: ID_CMDDISPATCHER_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setM3Cmd' begin] */
            dre.m3.req = true;

            dre.m3.cmd = dre.command_rx_buf;

            dre.m3.cmd.remove(0,1);
            /* ['<global>::setM3Cmd' end] */
            state = ID_CMDDISPATCHER_PROGRAMMOTORS;
        }
        else if( //((""+chr(27)) in dre.command_rx_buf)

dre.command_rx_buf.indexOf(27) >= 0 )
        {
            /* Transition ID: ID_CMDDISPATCHER_TRANSITION_CONNECTION */
            state = ID_CMDDISPATCHER_FINAL;
        }
        else
        {
            /* Transition ID: ID_CMDDISPATCHER_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::setAllMotorsCmd' begin] */
            dre.m1.req = true;
            dre.m2.req = true;
            dre.m3.req = true;
            dre.m1.cmd = dre.command_rx_buf;
            dre.m2.cmd = dre.command_rx_buf;
            dre.m3.cmd = dre.command_rx_buf;
            /* ['<global>::setAllMotorsCmd' end] */
            state = ID_CMDDISPATCHER_PROGRAMMOTORS;
        }
        return ID_CMDDISPATCHER_DECODEENGINE;
    }
    /* State ID: ID_CMDDISPATCHER_PROGRAMMOTORS */
    else if( state==ID_CMDDISPATCHER_PROGRAMMOTORS )
    {
        /* call substate function */
        STATE_T programmotors_retval = ProgramMotors(  );
        /* Transition ID: ID_CMDDISPATCHER_TRANSITION_CONNECTION */
        state = ID_CMDDISPATCHER_FINAL;
        return ID_CMDDISPATCHER_PROGRAMMOTORS;
    }
    /* State ID: ID_CMDDISPATCHER_FINAL */
    else if( state==ID_CMDDISPATCHER_FINAL )
    {
        state = ID_CMDDISPATCHER_INITIAL;
        return ID_CMDDISPATCHER_FINAL;
    }
}
/* ['CmdDispatcher' end (DON'T REMOVE THIS LINE!)] */

/* ['sendCtrlResponse' begin (DON'T REMOVE THIS LINE!)] */
STATE_T sendCtrlResponse(  )
{
    /* set initial state */
    static STATE_T state = ID_SENDCTRLRESPONSE_INITIAL;

    /* State ID: ID_SENDCTRLRESPONSE_INITIAL */
    if( state==ID_SENDCTRLRESPONSE_INITIAL )
    {
        /* Transition ID: ID_SENDCTRLRESPONSE_TRANSITION_CONNECTION */
        /* Actions: */
        /* ['<global>::serialResposeWrite' begin] */
        Serial.println(dre.command_tx_buf);

        /* ['<global>::serialResposeWrite' end] */
        state = ID_SENDCTRLRESPONSE_FINAL;
        return ID_SENDCTRLRESPONSE_INITIAL;
    }
    /* State ID: ID_SENDCTRLRESPONSE_FINAL */
    else if( state==ID_SENDCTRLRESPONSE_FINAL )
    {
        state = ID_SENDCTRLRESPONSE_INITIAL;
        return ID_SENDCTRLRESPONSE_FINAL;
    }
}
/* ['sendCtrlResponse' end (DON'T REMOVE THIS LINE!)] */

/* ['getCtrlCommand' begin (DON'T REMOVE THIS LINE!)] */
STATE_T getCtrlCommand(  )
{
    /* set initial state */
    static STATE_T state = ID_GETCTRLCOMMAND_INITIAL;

    /* State ID: ID_GETCTRLCOMMAND_INITIAL */
    if( state==ID_GETCTRLCOMMAND_INITIAL )
    {
        if( (dre.rx_buffer.length() < 1) )
        {
            /* Transition ID: ID_GETCTRLCOMMAND_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::resetRxTask' begin] */
            dre.command_rx_buf="";
            /* ['<global>::resetRxTask' end] */
            serialCharRead();
            state = ID_GETCTRLCOMMAND_READING;
        }
        else
        {
            /* Transition ID: ID_GETCTRLCOMMAND_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::resetRxTask' begin] */
            dre.command_rx_buf="";
            /* ['<global>::resetRxTask' end] */
            /* ['<global>::bufferCharRead' begin] */
            dre.char_read = dre.rx_buffer.charAt(0);
            dre.rx_buffer.remove(0,1);
            /* ['<global>::bufferCharRead' end] */
            state = ID_GETCTRLCOMMAND_PREVBUF;
        }
        return ID_GETCTRLCOMMAND_INITIAL;
    }
    /* State ID: ID_GETCTRLCOMMAND_READING */
    else if( state==ID_GETCTRLCOMMAND_READING )
    {
        if( ((dre.char_read != 10) && (dre.char_read != 13)) )
        {
            /* Transition ID: ID_GETCTRLCOMMAND_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::appendCharToRxBuf' begin] */
            dre.command_rx_buf += dre.char_read;
            /* ['<global>::appendCharToRxBuf' end] */
            serialCharRead();
        }
        else if( (dre.char_read ==  10 || dre.char_read == 13) )
        {
            /* Transition ID: ID_GETCTRLCOMMAND_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::prependActiveMotor' begin] */
            dre.command_rx_buf = dre.activeMotorPrefix + dre.command_rx_buf;
            /* ['<global>::prependActiveMotor' end] */
            state = ID_GETCTRLCOMMAND_FINAL;
        }
        return ID_GETCTRLCOMMAND_READING;
    }
    /* State ID: ID_GETCTRLCOMMAND_FINAL */
    else if( state==ID_GETCTRLCOMMAND_FINAL )
    {
        state = ID_GETCTRLCOMMAND_INITIAL;
        return ID_GETCTRLCOMMAND_FINAL;
    }
    /* State ID: ID_GETCTRLCOMMAND_PREVBUF */
    else if( state==ID_GETCTRLCOMMAND_PREVBUF )
    {
        if( (dre.char_read ==  10 || dre.char_read == 13) )
        {
            /* Transition ID: ID_GETCTRLCOMMAND_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::prependActiveMotor' begin] */
            dre.command_rx_buf = dre.activeMotorPrefix + dre.command_rx_buf;
            /* ['<global>::prependActiveMotor' end] */
            state = ID_GETCTRLCOMMAND_FINAL;
        }
        else if( (dre.rx_buffer.length() < 1) )
        {
            /* Transition ID: ID_GETCTRLCOMMAND_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::appendCharToRxBuf' begin] */
            dre.command_rx_buf += dre.char_read;
            /* ['<global>::appendCharToRxBuf' end] */
            serialCharRead();
            state = ID_GETCTRLCOMMAND_READING;
        }
        else
        {
            /* Transition ID: ID_GETCTRLCOMMAND_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::bufferCharRead' begin] */
            dre.char_read = dre.rx_buffer.charAt(0);
            dre.rx_buffer.remove(0,1);
            /* ['<global>::bufferCharRead' end] */
            /* ['<global>::appendCharToRxBuf' begin] */
            dre.command_rx_buf += dre.char_read;
            /* ['<global>::appendCharToRxBuf' end] */
        }
        return ID_GETCTRLCOMMAND_PREVBUF;
    }
}
/* ['getCtrlCommand' end (DON'T REMOVE THIS LINE!)] */

/* ['sendCtrlCommand' begin (DON'T REMOVE THIS LINE!)] */
STATE_T sendCtrlCommand(  )
{
    /* set initial state */
    static STATE_T state = ID_SENDCTRLCOMMAND_INITIAL;

    /* State ID: ID_SENDCTRLCOMMAND_INITIAL */
    if( state==ID_SENDCTRLCOMMAND_INITIAL )
    {
        /* Transition ID: ID_SENDCTRLCOMMAND_TRANSITION_CONNECTION */
        /* Actions: */
        /* ['<global>::serialCommandWrite' begin] */
        Serial.println(dre.command_tx_buf);

        /* ['<global>::serialCommandWrite' end] */
        state = ID_SENDCTRLCOMMAND_FINAL;
        return ID_SENDCTRLCOMMAND_INITIAL;
    }
    /* State ID: ID_SENDCTRLCOMMAND_FINAL */
    else if( state==ID_SENDCTRLCOMMAND_FINAL )
    {
        state = ID_SENDCTRLCOMMAND_INITIAL;
        return ID_SENDCTRLCOMMAND_FINAL;
    }
}
/* ['sendCtrlCommand' end (DON'T REMOVE THIS LINE!)] */

/* ['getCtrlResponse' begin (DON'T REMOVE THIS LINE!)] */
STATE_T getCtrlResponse(  )
{
    /* set initial state */
    static STATE_T state = ID_GETCTRLRESPONSE_INITIAL;

    /* State ID: ID_GETCTRLRESPONSE_INITIAL */
    if( state==ID_GETCTRLRESPONSE_INITIAL )
    {
        /* Transition ID: ID_GETCTRLRESPONSE_TRANSITION_CONNECTION */
        /* Actions: */
        /* ['<global>::resetRxTask' begin] */
        dre.command_rx_buf="";
        /* ['<global>::resetRxTask' end] */
        serialCharRead();
        state = ID_GETCTRLRESPONSE_READING;
        return ID_GETCTRLRESPONSE_INITIAL;
    }
    /* State ID: ID_GETCTRLRESPONSE_READING */
    else if( state==ID_GETCTRLRESPONSE_READING )
    {
        if( (dre.char_read ==  10 || dre.char_read == 13) )
        {
            /* Transition ID: ID_GETCTRLRESPONSE_TRANSITION_CONNECTION */
            /* Actions: */
            serialCharRead();
            state = ID_GETCTRLRESPONSE_FINISHING;
        }
        else if( ((dre.char_read != 10) && (dre.char_read != 13)) )
        {
            /* Transition ID: ID_GETCTRLRESPONSE_TRANSITION_CONNECTION */
            /* Actions: */
            /* ['<global>::appendCharToRxBuf' begin] */
            dre.command_rx_buf += dre.char_read;
            /* ['<global>::appendCharToRxBuf' end] */
            serialCharRead();
        }
        return ID_GETCTRLRESPONSE_READING;
    }
    /* State ID: ID_GETCTRLRESPONSE_FINISHING */
    else if( state==ID_GETCTRLRESPONSE_FINISHING )
    {
        if( (dre.char_read ==  10 || dre.char_read == 13) )
        {
            /* Transition ID: ID_GETCTRLRESPONSE_TRANSITION_CONNECTION */
            state = ID_GETCTRLRESPONSE_FINAL;
        }
        else if( ((dre.char_read != 10) && (dre.char_read != 13)) )
        {
            /* Transition ID: ID_GETCTRLRESPONSE_TRANSITION_CONNECTION */
            /* Actions: */
            serialCharRead();
        }
        return ID_GETCTRLRESPONSE_FINISHING;
    }
    /* State ID: ID_GETCTRLRESPONSE_FINAL */
    else if( state==ID_GETCTRLRESPONSE_FINAL )
    {
        state = ID_GETCTRLRESPONSE_INITIAL;
        return ID_GETCTRLRESPONSE_FINAL;
    }
}
/* ['getCtrlResponse' end (DON'T REMOVE THIS LINE!)] */
