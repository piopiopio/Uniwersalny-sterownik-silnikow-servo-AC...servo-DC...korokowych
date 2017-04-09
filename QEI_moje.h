#ifndef __QEI_MOJE_H
#define __QEI_MOJE_H

#include <stdint.h>

//Set up quadrature encoder interface, input argument: encoder resolution.
//OUT_A(Black): P1.20
//OUT_B (White): P1.23
//OUT_Z(Orange)- P1.24
//GND(Blue): GND
//VCC(Brown):	5v
//Used pins: P1.20- MCI0; P1.23-MCI1; P1.24-MCI2
void Set_QEI(int encoderResolution);

//Return velocity, if input argument: "m"-revolution per minute,"s"-revolution per minute,"d"-degree per second.
double GetVelocity(char a);

//Return current position
long int GetPosition();
#endif



