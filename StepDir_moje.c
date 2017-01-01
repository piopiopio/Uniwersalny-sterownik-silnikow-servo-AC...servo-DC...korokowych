#include <LPC17xx.h>
#include <StepDir_moje.h>
#include <MCPWM_moje.h>

long long int stepDirPosition = 0;

//TODO: Skasowaæ stepDirpositionsteppermotor
long long int stepDirPositionStepperMotor = 0;

void Set_StepDir()
{//P0.4-step, P0.6-direction.

  //Set up P0.4 and P0.6 as GPIO(as default).
	LPC_PINCON->PINSEL0 &= ~(((1 << 8) | (1 << 9)) | (1 << 12) | (1 << 13));

	//Set up P0.4 and P0.6 as input(as default).
	LPC_GPIO0->FIODIR &= ~((1 << 4) | (1 << 6));

	//Set pull down resistor to P0.4 pin.
	LPC_PINCON->PINMODE0 |= (1 << 8) | (1 << 9);

	//Enable P0.4 interrupt on rising edge.
	LPC_GPIOINT->IO0IntEnR |= (1 << 4);

	//Enable interrupt, external interrupt 3.
	NVIC_EnableIRQ(EINT3_IRQn);

}

void EINT3_IRQHandler(void)
{
	// Clear pending interrupt.
	LPC_GPIOINT->IO0IntClr |= (1 << 4);

	if ((LPC_GPIO0->FIOPIN0) & (1 << 6))
	{
		stepDirPosition++;
		stepDirPositionStepperMotor++;
	}

	else
	{
		stepDirPosition--;
		stepDirPositionStepperMotor--;
	}


	StepperMotorCommutation();
}

long long int GetstepDirPosition()
{
	return stepDirPosition;
}



