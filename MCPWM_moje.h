#ifndef __MCPWM_MOJE_H
#define __MCPWM_MOJE_H

#include <stdint.h>



//Set up motor control PWM.
//Argument1: Output type "s"- sine wave, "k"- stepper motor.
//Argument2: value of frequency
//Argument3: sine range (2*amplitude).
//Used pins: P1.19-MC0A; P1.25-MC1A; P1.28-MC2A.
//Used pins: P1.22-MC0B; P1.26-MC1B; P1.29-MC2B.
//Used pins: P1.21 MCABORT.
int Set_MCPWM(char parameter, double frequency, int _sineValuesRange);

//Change frequency of sinus wave and it's amplitude.
//Amplitude value must be from range <0, SIN_TAB_RESOLUTION/2>
void Change_MCPWM(double frequency, int* amplitude);

//In case of emergency lock MCPWM outputs.
void Lock_MCPWM();

//This function can unlock MCPWM outputs.
void Unlock_MCPWM();

//Function responsible for set new value in MCPWM register to get sin wave.
//It is called in TIMER1 interrupt routine.
void SineOutput(volatile int* currentSampleNumber);

//Function responsible for setting MCPWM outputs to control stepper motor.
void StepperMotorCommutation();

//Function responsible for printing setted PWM value on each of three MCPWM output.
void PrintThreePhaseMCPWMSettedOutput();

#endif



