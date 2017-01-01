#ifndef __STEP_DIR_MOJE_H
#define __STEP_DIR_MOJE_H

//Contain given position.
long long int stepDirPosition;

//Contain error between set numbers of steps and done numbers of steps.
long long int stepDirPositionStepperMotor;

//Set step-direction communication.
//Used pins: P0.4- step, P0.6-direction.
void Set_StepDir();

#endif



