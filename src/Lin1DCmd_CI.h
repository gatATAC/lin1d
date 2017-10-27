/* ['Common headers' begin (DON'T REMOVE THIS LINE!)] */
#include <stdio.h>
#include <stdlib.h>
/* ['Common headers' end (DON'T REMOVE THIS LINE!)] */
#include <Arduino.h>
/* ['Common declarations for 'Code items generator'' begin (DON'T REMOVE THIS LINE!)] */
/* Generic code items' declarations */
void sendUntimelyResponse( String resptosend );
/* ['Common declarations for 'Code items generator'' end (DON'T REMOVE THIS LINE!)] */

/* ['Common declarations for 'Hierarchical State Chart generator'' begin (DON'T REMOVE THIS LINE!)] */
/* State ID data type */
typedef unsigned long STATE_T;

/* Declaration of code items used in state charts */
/*!
 * \brief Reads a character from the serial line
 * \return Value of type char
 */
char serialCharRead(  );
/*!
 * \brief Execute the command decoder with M1
 */
void decodeM1Cmd(  );
/*!
 * \brief Decode the M2 cmd
 */
void decodeM2Cmd(  );
/*!
 * \brief Decode the M3 command
 */
void decodeM3Cmd(  );
/*!
 * \brief Reset the decoder variables before decoding the new command.
 */
void resetDecoder(  );
/*!
 * \brief GoHoSeq command
 */
void programGoHoSeq(  );
/*!
 * \brief Check if a character at a given position is (or is not) equal to the given one.
 * \param idx Position index to check
 * \param cToCheck Character to compare to
 * \param isEqual true if the check is to equal and false to not equal.
 * \return Value of type bool
 */
bool checkCharAtPos( int idx, int cToCheck, int isEqual );
/*!
 * \brief Detects a change in the currently active motor
 * \return Value of type bool
 */
bool targetChange(  );
/* ['Common declarations for 'Hierarchical State Chart generator'' end (DON'T REMOVE THIS LINE!)] */
