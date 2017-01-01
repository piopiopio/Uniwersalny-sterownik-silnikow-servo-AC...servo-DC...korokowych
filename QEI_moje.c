#include <LPC17xx.h>
#include <QEI_moje.h>

int resolution = 0;
int timerRange = 1000000;
double velocity = 99999999;
unsigned int pclk;

void Set_QEI(int encoderResolution)
{ //encoderResolution- number of phase pulses per revolution.

//TODO:Dopisaæ sprawdzanie czy nie zgubiono imulsów na podstawie encoderResolution
//(Czy w momencie wyst¹pienia sygna³u indeksu jest odpowiednia wielokotnoæ w POS.

	//Set global variable resolution with set encoderResolution value.
	resolution = encoderResolution;

	//Set power for QEI.
	LPC_SC->PCONP |= (1 << 18);

	//Set clock prescaler for QEI, pclk=100MHz.
	LPC_SC->PCLKSEL1 |= (1 << 0);

	//Set maximal position value.
	LPC_QEI->QEIMAXPOS = 0xffffffff;

	//Set function of P1.20- MCI0; P1.23-MCI1; P1.24-MCI2.
	LPC_PINCON->PINSEL3 |= (1 << 8) | (1 << 14) | (1 << 16);

	//Set counting all edge Ph0 and Ph1.
	LPC_QEI->QEICONF |= (1 << 2);

	// Enable QEI Interrupt.
	//NVIC_EnableIRQ(QEI_IRQn);

	//velocity timer max value.
	LPC_QEI->QEILOAD = timerRange;

	//Disable reset position and velocity when an index pulse occurs.
	LPC_QEI->QEICON = 0b1101;

}

double GetVelocity(char a)
{
	//Velocity unit selection
	switch (a)
	{
	case 'm':
		//Velocity: revolution per minute
		velocity = ((double) (pclk * (LPC_QEI->QEICAP) * 60))
				/ ((double) ((timerRange) * resolution * 4));
		break;
	case 's':
		//Velocity: revolution per second
		velocity = ((double) (pclk * (LPC_QEI->QEICAP) * 60))
				/ (60 * (double) ((timerRange) * resolution * 4));
		break;
	case 'd':
		//Velocity: degree per second
		velocity = 360 * ((double) (pclk * (LPC_QEI->QEICAP) * 60))
				/ (60 * (double) ((timerRange) * resolution * 4));
	default:
		//Velocity: error value
		velocity = 9999999999;
		break;
	}
	return velocity;
}

long int GetPosition()
{
	return (long int) (LPC_QEI->QEIPOS);
}
