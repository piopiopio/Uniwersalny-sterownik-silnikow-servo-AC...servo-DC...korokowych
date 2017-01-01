#ifndef __PID_CURRENT_MOJE_H
#define __PID_CURRENT_MOJE_H

#include <stdint.h>


//Function run RunAdcMeasurementSeries and then CurrentPID.
void StartCurrentPID();

//Current regulating PID Loop.
double CurrentPID(int adcInputChannelNumber);

void Set_PIDcurrent(int _historySampleQuantity);
#endif



