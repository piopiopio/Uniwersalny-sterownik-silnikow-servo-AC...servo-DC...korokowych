#ifndef ADC_MOJE_H_
#define ADC_MOJE_H_
#include <stdint-gcc.h>

volatile uint32_t ADCValue[8];
int ADCValueHistory[8][40];//TODO: skasowac - ustawic getter
//Set ADC, channel 0.
//Argument 1.: "1"-overcurrent protection latch is on, "0"- overcurrent protection latch is off.
//Argument 2.: Current value that will  trigger overcurrent protection. Both polarization are acceptable.
//Argument 3.: Measured value when non current flow.
//Argument 4.: Number of used adc inputs, value from 0 to 7.
//Used pins: P0.23- AD0.0(current A); P0.24- AD0.1(current B); P0.25 as AD0.2;
//P0.26 as AD0.3; P1.30 as AD0.4; P1.31 as AD0.5; P0.03 as AD0.6; P0.02 as AD0.7.
//P3.25 OverCurrent_LED
int Set_ADC(int _overCurrent, int _zeroCurrent, int _adcInputsNuber);

//Function return moving average of ADC measured values based on values in [ADC0ValueHistory].
//Number of samples take into account is determined by [historySampleQuantity].
int MovingAverage(int adcInputNumber);

//Function made to test ADC quality.
//Arguments are a number of samples take in account and expectedLeastTestValue.
//As a results it return number of the same results (maximum range is <expectedLeastTestValue, expectedLeastTestValue+19>.
//ADC must be set up before running this test.
//Example: TestADC(1000000,0);
void TestADC(int numberOfSamples, int expectedLeastTestValue_);

// Function responsible for putting new measured value in proper place in ADCValue[adcInputNumber] and also in ADCValueHistory[adcInputNumber][sampleNumber].
void AdcValue(int adcInputNumber);

// Function responsible for checking if overcurrent occur, if yes then it calls Lock_MCPWM().
void CheckOverCurrent();

void StepperMotorChangeAmplitude(int adcInputChannelNumber, int newAmplitude);

//Do measurement, it can do [number of series to do] measurement. [0,1,2] or [0,1,3] etc.
void RunAdcMeasurementSeries();
#endif /* ADC_H_ */

