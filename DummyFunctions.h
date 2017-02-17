#ifndef _DUMMY_FUNCTIONS
#define _DUMMY_FUNCTIONS

#include "ProjectTypes.h"

typedef uint8_t bool;

void pinMode(uint8_t pin, uint8_t mode);
void analogWriteResolution(uint8_t resolution);
void analogWriteFrequency(uint8_t pin, uint16_t frequency);
bool digitalRead(uint8_t pin);
void analogWrite(uint8_t pin, uint16_t value);
void digitalWrite(uint8_t pin, bool value);
uint16_t analogRead(uint8_t pin);

#endif // _DUMMY_FUNCTIONS
