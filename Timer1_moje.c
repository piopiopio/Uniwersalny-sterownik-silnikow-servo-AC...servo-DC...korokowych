#include <math.h>

#include "Timer1_moje.h"
#include <LPC17xx.h>
#include <PID_current.h>

const int AdcMeasurementBeforePidCurrent = 6;

char _typeOfOutput;

int TIMER1_IRQHandlerIterator = 0;

//CurrentSampleNumber current number of MCPWMx value.
//SIN_TAB_quantity number of elements in array of sinus values.
//Angle between phases- 120 degrees.
volatile int currentSampleNumber[3];

void Set_Timer1(double frequency, char _typeOfOutput, int _SIN_TAB_quantity)
{
	//frequency- of sinus wave
	currentSampleNumber[0] = 0;
	currentSampleNumber[1] = _SIN_TAB_quantity / 3;
	currentSampleNumber[2] = 2 * _SIN_TAB_quantity / 3;

	_typeOfOutput = _typeOfOutput;

	//Power ON Timer1.
	LPC_SC->PCONP |= (1 << 2);

	//Peripherial clock selection,  timer1 BIT 5:4; 01 prescaler 1.
	LPC_SC->PCLKSEL0 |= (1 << 4);

	//Clear TC on MR0 match and Generate Interrupt.
	LPC_TIM1->MCR = (1 << 0) | (1 << 1);

	// Prescaler for 1us.
	//LPC_TIM1->PR = getPrescalarForUs(4);
	LPC_TIM1->PR=0;

	switch (_typeOfOutput)
	{
	case 's':
		// Load timer value to generate set frequency.
		LPC_TIM1->MR0 = (int) (round(
				1000000 / (frequency * (_SIN_TAB_quantity - 1))));
		break;

	case 'k':
		// Load timer value to generate timer frequency equal to 30kHz. CURRENT loop control frequency.
		LPC_TIM1->MR0 = 500000000;

		break;

	default:
		break;
	}

	// Start timer by setting the Counter Enable.
	LPC_TIM1->TCR = (1 << 0);

	// Enable Timer1 Interrupt.
	NVIC_EnableIRQ(TIMER1_IRQn);

	NVIC_SetPriority(TIMER1_IRQn,5);

}

void TIMER1_IRQHandler()
{
	//Interrupt Register. The IR can be written to clear interrupts.
	LPC_TIM1->IR = LPC_TIM1->IR;

	if (_typeOfOutput == 's')
	{
//		SineOutput(currentSampleNumber);
		//Increment for next step.
//		currentSampleNumber[0]++;
//		currentSampleNumber[1]++;
//		currentSampleNumber[2]++;
	}
	else if (_typeOfOutput == 'k')
	{
		StartCurrentPID();
	}

}

unsigned int getPrescalarForUs(uint8_t timerPclkBit)
{
	unsigned int pclk, prescalarForUs;

	//Get the pclk info for required timer.
	pclk = (LPC_SC->PCLKSEL0 >> timerPclkBit) & 0x03;

	//Decode the bits to determine the pclk.
	switch (pclk)
	{
	case 0b00:
		pclk = SystemCoreClock / 4;
		break;

	case 0b01:
		pclk = SystemCoreClock;
		break;

	case 0b10:
		pclk = SystemCoreClock / 2;
		break;

	case 0b11:
		pclk = SystemCoreClock / 8;
		break;

	default:
		pclk = SystemCoreClock / 4;
		break;
	}

	//Prescaler value, remark: PC counts from 0.
	prescalarForUs = pclk / 1000000 - 1; /* Prescalar for 1us (1000000Counts/sec) */

	return prescalarForUs;
}
