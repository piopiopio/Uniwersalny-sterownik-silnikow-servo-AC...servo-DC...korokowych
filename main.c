#include <MCPWM_moje.h>
#include <LPC17xx.h>
#include <QEI_moje.h>
#include <Uart_moje.h>
#include <ADC_moje.h>
#include <stdint-gcc.h>
#include <StepDir_moje.h>
#include <Timer1_moje.h>
#include <PID_current.h>

char typeOfOutput = 'k';
double frequency = 1;
//int valuesRange=254;

volatile uint32_t ADCValue[8];

int main(void)
{

	int SIN_TAB_quantity = Set_MCPWM(typeOfOutput, frequency);
	Set_Timer1(frequency, typeOfOutput, SIN_TAB_quantity);
	Set_StepDir();
	Set_QEI(2000);
	Set_Uart0(460800, 1);
	int historySampleQuantity = Set_ADC(4000, 2866, 8); //Ustawiona taka wysoka wartoæ overcurrent,  ¿eby nie wyzwalac blokady w czasie testow.

	Set_PIDcurrent(historySampleQuantity);

	long int Testperiod = 10000;
	//int test[2] =
	//{ 511, 511};

	LPC_PINCON->PINSEL7 &= ~((1 << 18) | (1 << 19) | (1 << 20) | (1 << 21));
	LPC_GPIO3->FIODIR |= (1 << 25) | (1 << 26);
	LPC_GPIO3->FIOCLR = (1 << 25) | (1 << 26);
	LPC_PINCON->PINSEL3 &= ~((1 << 25) | (1 << 24) | (1 << 26) | (1 << 27));
	LPC_GPIO1->FIODIR |= ((1 << 28) | (1 << 29));
	LPC_PINCON->PINSEL3 &= ~((1 << 7) | (1 << 6) | (1 << 13) | (1 << 12));
	LPC_GPIO1->FIODIR |= (1 << 22) | (1 << 19);
	LPC_PINCON->PINSEL3 &= ~((1 << 19) | (1 << 18) | (1 << 20) | (1 << 21));
	LPC_GPIO1->FIODIR |= (1 << 25) | (1 << 26);

	while (1)

	{
//		test[0] = 511;
//		test[1] = 511;
//		test[0] = 0;
//		test[1] = 0;
//		Change_MCPWM(1, test);
		LPC_GPIO1->FIOCLR = (1 << 28);
		LPC_GPIO1->FIOSET = (1 << 29);

		for (long int var = 0; var < Testperiod; ++var)
		{

		}
//		test[0] = 511;
//		test[1] = -511;
//		test[0] = 0;
//		test[1] = 0;
//		Change_MCPWM(1, test);
		LPC_GPIO1->FIOCLR = (1 << 19);
		LPC_GPIO1->FIOSET = (1 << 22);

		LPC_GPIO1->FIOCLR = (1 << 26);
		LPC_GPIO1->FIOSET = (1 << 25);
		for (long int var = 0; var < Testperiod; ++var)
		{

		}
//		test[0] = -511;
//		test[1] = -511;
//		test[0] = 0;
//		test[1] = 0;
//		Change_MCPWM(1, test);
		LPC_GPIO1->FIOCLR = (1 << 29);
		LPC_GPIO1->FIOSET = (1 << 28);
		for (long int var = 0; var < Testperiod; ++var)
		{

		}
//		test[0] = -511;
//		test[1] = 511;
//		test[0] = 0;
//		test[1] = 0;
//		Change_MCPWM(1, test);
		LPC_GPIO1->FIOCLR = (1 << 22);
		LPC_GPIO1->FIOSET = (1 << 19);
		LPC_GPIO1->FIOCLR = (1 << 25);
		LPC_GPIO1->FIOSET = (1 << 26);

		for (long int var = 0; var < Testperiod; ++var)
		{

		}
		RunAdcMeasurementSeries();
//		Uart0_Print("%d\t", MovingAverage(1));
		Uart0_Print("%d,", ADCValue[1]);
		Uart0_Print("%d,", ADCValue[6]);
		Uart0_Print("%d\r\n", ADCValue[7]);

//		if (ADCValue[6] < 3000)
//		{
//			LPC_GPIO3->FIOCLR = (1 << 25);
//		}
//		else
//		{
//			LPC_GPIO3->FIOSET = (1 << 25);
//		}
//
//
//
//		if (ADCValue[7] < 3000)
//		{
//			LPC_GPIO3->FIOCLR = (1 << 26);
//		}
//		else
//		{
//			LPC_GPIO3->FIOSET = (1 << 26);
//		}
//		Uart0_Print("%ld\r", GetPosition());

//Test mosfet short circuit protection
//		LPC_PINCON->PINSEL3&=~((1<<25)|(1<<24)|(1<<26)|(1<<27));
//		LPC_GPIO1->FIODIR=(1<<28)|(1<<29);
//		LPC_GPIO1->FIOSET=(1<<28)|(1<<29);

//		LPC_PINCON->PINSEL3&=~((1<<7)|(1<<6)|(1<<13)|(1<<12));
//		LPC_GPIO1->FIODIR=(1<<22)|(1<<19);
//		LPC_GPIO1->FIOSET=(1<<22)|(1<<19);

//		LPC_PINCON->PINSEL3&=~((1<<19)|(1<<18)|(1<<20)|(1<<21));
//		LPC_GPIO1->FIODIR=(1<<25)|(1<<26);
//		LPC_GPIO1->FIOSET=(1<<25)|(1<<26);

//		LPC_PINCON->PINSEL7&=~((1<<18)|(1<<19)|(1<<20)|(1<<21));
//		LPC_GPIO3->FIODIR=(1<<25)|(1<<26);
//		LPC_GPIO3->FIOSET=(1<<25)|(1<<26);

		SecurityCheck();
	}

}
