#ifndef __TIMER1_MOJE_H__
#define __TIMER1_MOJE_H__

#include <stdint.h>
#include <ADC_moje.h>

unsigned int getPrescalarForUs(uint8_t timerPclkBit);

//Set up timer 1, argument is a frequency of generated sine wave.
//Timer interrupts are generated according to number of sine array elements.
void Set_Timer1(double frequency, char typeOfOutput, int _SIN_TAB_quantity);




#endif
