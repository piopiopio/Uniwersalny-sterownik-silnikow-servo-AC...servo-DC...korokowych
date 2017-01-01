//Used pins:
//P1.19-MC0A; P1.25-MC1A; P1.28-MC2A;
//P1.22-MC0B; P1.26-MC1B; P1.29-MC2B;

#include <LPC17xx.h>
#include <math.h>
#include <MCPWM_moje.h>
#include <SIN_TAB.h>
#include <StepDir_moje.h>
#include <Uart_moje.h>
#include <ADC_moje.h>


int aDir = 0;

int bDir = 0;

//Set rage of values for stepper motor.
int stepperMotorValuesRange[2] =
{ 255, 255 };

//Set outputs type: sin wave, stepper motor.
char _typeOfOutput = 's';

//Stepper motor state
int stepperMotorState = 0;

//Values range for sine wave.
//This variable can be modify by Change_MCPWM.
int _valuesRange;

//Amplitude
int AmplitudeValue[3]={0};

//Error flag, when 1=driver blocked, 0-driver normal working.
int errorLatch = 0;

int Set_MCPWM(char typeOfOutput, double frequency, int sineValuesRange)
{
	//Set output type
	_typeOfOutput = typeOfOutput;

	//MCPWM power on
	LPC_SC->PCONP |= 1 << 17;

	// PCLK = CCLK (100MHz in our case)
	LPC_SC->PCLKSEL1 |= 1 << 30;

	// Configuring P1.19-MC0A; P1.25-MC1A; P1.28-MC2A;
	LPC_PINCON->PINSEL3 |= (1 << 6) | (1 << 18) | (1 << 24);

	// Configuration P1.22-MC0B; P1.26-MC1B; P1.29-MC2B
	LPC_PINCON->PINSEL3 |= (1 << 12) | (1 << 20) | (1 << 26);

	//Configure P1.21 MCABORT
	LPC_PINCON->PINSEL3 |= (1 << 10);

	//Set pull-down only for test.
	//LPC_PINCON->PINMODE3|=(1<<10) | (1<<11);
	LPC_MCPWM->MCINTEN_SET |= (1 << 15);

	// Set the Limit register (MCLIM0-2 is named as MCPER0-2 in CMSIS source file)
	LPC_MCPWM->MCPER0 = SIN_TAB_RESOLUTION;
	LPC_MCPWM->MCPER1 = SIN_TAB_RESOLUTION;
	LPC_MCPWM->MCPER2 = SIN_TAB_RESOLUTION;

	//  Start MCPWM channels 1 and 2 and POLA = 1,Set dead-time feature on.
	LPC_MCPWM->MCCON_CLR = 0xffffffff;
	LPC_MCPWM->MCCON_SET = (1 << 0) | (1 << 8) | (1 << 16) | (1 << 3)
			| (1 << 11) | (1 << 19) | (1 << 30);

	//Set dead-time for all channel
	LPC_MCPWM->MCDEADTIME = (1 << 0) | (1 << 10) | (1 < 20);

	//Set amplitude value, from range <0, SIN_TAB_RESOLUTION/2>
	_valuesRange = sineValuesRange;

return SIN_TAB_quantity;
}

void Change_MCPWM(double frequency, int* amplitude)
{
	//AmplitudeValue=amplitude;

	
	if (_typeOfOutput == 's')
	{//TODO: Robi³em zmiany dla silnika krokowego które wp³yne³y na wyjscie sine, uaktualnic.
		//Set new amplitude value from range <0, SIN_TAB_RESOLUTION/2>
		_valuesRange = 2*amplitude[0];

		//Change timer value to generate set frequency.
		LPC_TIM1->MR0 = (int) (round(
				1000000 / (frequency * (SIN_TAB_quantity - 1))));
	}

	else if (_typeOfOutput == 'k')
	{
		LPC_MCPWM->MCPW0 = _valuesRange/2 + amplitude[0] * aDir;
		LPC_MCPWM->MCPW1 = _valuesRange/2 + amplitude[1] * bDir;
	}

}

void StepperMotorCommutation()
{
	//Check if step should be done.
	if (stepDirPositionStepperMotor != 0)
	{

		//Check step direction direction.
		if (stepDirPositionStepperMotor > 0)
		{
			stepperMotorState++;
			stepDirPositionStepperMotor--;
			if (stepperMotorState > 3)
			{
				stepperMotorState = 0;
			}
		}
		else if (stepDirPositionStepperMotor < 0)
		{
			stepperMotorState--;
			stepDirPositionStepperMotor++;
			if (stepperMotorState < 0)
			{
				stepperMotorState = 3;
			}
		}

		//Check up-to-date stepper motor state and do action.
		switch (stepperMotorState)
		{
		case 0:
			//A-;B-
			aDir = 0;
			bDir = 0;
			break;

		case 1:
			//A-;B+
			aDir = 0;
			bDir = 1;
			break;

		case 2:
			//A+;B+
			aDir = 1;
			bDir = 1;
			break;

		case 3:
			//A+;B-
			aDir = 1;
			bDir = 0;
			break;

		default:
			while (1)
				;
			break;
		}

	}
	//TODO: CURRENT LIMITATION PID!!!

	//Switch coils current, change direction
	LPC_MCPWM->MCPW0 = stepperMotorValuesRange[0] * aDir;
	LPC_MCPWM->MCPW1 = stepperMotorValuesRange[1] * bDir;

}

//void StepperMotorChangeAmplitude(int adcInputChannelNumber, int newAmplitude)
//{
//	//Switch coils current, change amplitude.
//	switch (adcInputChannelNumber)
//	{
//	case 0:
//		LPC_MCPWM->MCPW0 = newAmplitude * aDir;
//		break;
//
//	case 1:
//		LPC_MCPWM->MCPW1 = newAmplitude * bDir;
//		break;
//	default:
//		break;
//	}
//
//}

void SineOutput(volatile int* currentSampleNumber)
{
	//Test if CurrentSampleNumber greater than SIN_TAB_quantity,
	//if yes then set 0.
	if (currentSampleNumber[0] >= SIN_TAB_quantity)
	{
		currentSampleNumber[0] = 0;
	}

	if (currentSampleNumber[1] >= SIN_TAB_quantity)
	{
		currentSampleNumber[1] = 0;
	}

	if (currentSampleNumber[2] >= SIN_TAB_quantity)
	{
		currentSampleNumber[2] = 0;
	}

	//Set PWM value on each of three channel.
	//MC0A	P1.19.
	LPC_MCPWM->MCPW0 = (_valuesRange * SIN_TAB[currentSampleNumber[0]] >> 8)
			+ (255 - _valuesRange) / 2;

	//MC1A P1.25.
	LPC_MCPWM->MCPW1 = (_valuesRange * SIN_TAB[currentSampleNumber[1]] >> 8)
			+ (255 - _valuesRange) / 2;

	//MC2A P1.28.
	LPC_MCPWM->MCPW2 = (_valuesRange * SIN_TAB[currentSampleNumber[2]] >> 8)
			+ (255 - _valuesRange) / 2;
}

void PrintThreePhaseMCPWMSettedOutput()
{
	Uart0_Print("%d,", (LPC_MCPWM->MCPW0));
	Uart0_Print("%d,", (LPC_MCPWM->MCPW1));
	Uart0_Print("%d,\n\r", (LPC_MCPWM->MCPW2));
}

void Lock_MCPWM()
{
	//Set ABORT interrupt flag
	LPC_MCPWM->MCINTFLAG_SET = (1 << 15);

	//TODO: Sygnalizacyjne diody LED: Overcurrent, overheating...
}

void Unlock_MCPWM()
{
	//Clear ABORT interrupt flag
	LPC_MCPWM->MCINTFLAG_CLR = (1 << 15);
}

