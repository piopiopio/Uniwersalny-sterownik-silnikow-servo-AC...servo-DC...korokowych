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
{	long int Testperiod=60000;
int amplitude[2] ={ 511, 511};
int sign[2] ={ 1, 1};


	int SIN_TAB_quantity = Set_MCPWM(typeOfOutput, frequency);
	Set_Timer1(frequency, typeOfOutput, SIN_TAB_quantity);
	Set_StepDir();
	Set_QEI(2000);
	Set_Uart0(460800, 1);
	int historySampleQuantity = Set_ADC(4000, 2866, 3); //Ustawiona taka wysoka wartoæ overcurrent,  ¿eby nie wyzwalac blokady w czasie testow.






	//Set_PIDcurrent(historySampleQuantity);




	LPC_PINCON->PINSEL7&=~((1<<18)|(1<<19)|(1<<20)|(1<<21));
	LPC_GPIO3->FIODIR|=(1<<25)|(1<<26);
	LPC_GPIO3->FIOCLR=(1<<25)|(1<<26);


//			LPC_PINCON->PINSEL3&=~((1<<25)|(1<<24)|(1<<26)|(1<<27));
//			LPC_GPIO1->FIODIR|=((1<<28)|(1<<29));
////			LPC_GPIO1->FIOSET=(1<<28)|(1<<29);
//
//			LPC_PINCON->PINSEL3&=~((1<<7)|(1<<6)|(1<<13)|(1<<12));
//			LPC_GPIO1->FIODIR|=(1<<22)|(1<<19);
////			LPC_GPIO1->FIOSET=(1<<22)|(1<<19);
//
//			LPC_PINCON->PINSEL3&=~((1<<19)|(1<<18)|(1<<20)|(1<<21));
//			LPC_GPIO1->FIODIR|=(1<<25)|(1<<26);
////			LPC_GPIO1->FIOSET=(1<<25)|(1<<26);

//			LPC_PINCON->PINSEL7&=~((1<<18)|(1<<19)|(1<<20)|(1<<21));
//			LPC_GPIO3->FIODIR=(1<<25)|(1<<26);
//			LPC_GPIO3->FIOSET=(1<<25)|(1<<26);


	amplitude[0] = 300;
	amplitude[1] = 150;
	Change_MCPWM(1, amplitude,sign);
	while (1)

	{
//
//		LPC_GPIO1->FIOCLR=(1<<28);
//		LPC_GPIO1->FIOSET=(1<<29);
//
//		for (long int var = 0; var < Testperiod; ++var)
//		{
//
//		}
//
//
//
//
//		LPC_GPIO1->FIOCLR=(1<<19);
//		LPC_GPIO1->FIOSET=(1<<22);
//		LPC_GPIO1->FIOCLR=(1<<26);
//		LPC_GPIO1->FIOSET=(1<<25);
//
//		for (long int var = 0; var < Testperiod; ++var)
//		{
//
//		}
//
//
//
//		LPC_GPIO1->FIOCLR=(1<<29);
//		LPC_GPIO1->FIOSET=(1<<28);
//
//		for (long int var = 0; var < Testperiod; ++var)
//		{
//
//		}
//
//
//
//		LPC_GPIO1->FIOCLR=(1<<22);
//		LPC_GPIO1->FIOSET=(1<<19);
//		LPC_GPIO1->FIOCLR=(1<<25);
//		LPC_GPIO1->FIOSET=(1<<26);
//
//		for (long int var = 0; var < Testperiod; ++var)
//		{
//
//		}






		sign[0]=1;
		sign[1]=1;
		amplitude[0]=CurrentPID(0);
		amplitude[1]=CurrentPID(1);
//		Change_MCPWM(1, amplitude, sign);
		Uart0_Print("%d,", amplitude[0]);
		Uart0_Print("%d,", amplitude[0]);
		Uart0_Print("%d,", amplitude[1]);

//
//		//Cala seria 19us
		RunAdcMeasurementSeries();
//
//		for (long int var = 0; var < Testperiod; ++var)
//		{
//
//		}
//
//		//LPC_GPIO3->FIOSET=(1<<26);
//		//Wykonanie trzech poni¿szych linii zajmuje 335us
////		Uart0_Print("%d,", ADCValue[0]);
////		Uart0_Print("%d,", ADCValue[1]);
////		Uart0_Print("%d\r\n", ADCValue[2]);
//		Uart0_Print("%d,", MovingAverage(0));
//		Uart0_Print("%d,", MovingAverage(1));
//		Uart0_Print("%d\r\n", MovingAverage(2));
//
//		//LPC_GPIO3->FIOCLR=(1<<26);
//		test[0] = 2500;
//		test[1] = -2500;
//		Change_MCPWM(1, test);
//		for (long int var = 0; var < Testperiod; ++var)
//		{
//
//		}
//		//		Uart0_Print("%d,", ADCValue[0]);
//		//		Uart0_Print("%d,", ADCValue[1]);
//		//		Uart0_Print("%d\r\n", ADCValue[2]);
//				Uart0_Print("%d,", MovingAverage(0));
//				Uart0_Print("%d,", MovingAverage(1));
//				Uart0_Print("%d\r\n", MovingAverage(2));
//		test[0] = -2500;
//		test[1] = -2500;
//		Change_MCPWM(1, test);
//		for (long int var = 0; var < Testperiod; ++var)
//		{
//
//		}
//		//		Uart0_Print("%d,", ADCValue[0]);
//		//		Uart0_Print("%d,", ADCValue[1]);
//		//		Uart0_Print("%d\r\n", ADCValue[2]);
//				Uart0_Print("%d,", MovingAverage(0));
//				Uart0_Print("%d,", MovingAverage(1));
//				Uart0_Print("%d\r\n", MovingAverage(2));
//		test[0] = -2500;
//		test[1] = 2500;
//		Change_MCPWM(1, amplitude);
		for (long int var = 0; var < Testperiod; ++var)
		{

		}
		//		Uart0_Print("%d,", ADCValue[0]);
		//		Uart0_Print("%d,", ADCValue[1]);
		//		Uart0_Print("%d\r\n", ADCValue[2]);
				Uart0_Print("%d,", MovingAverage(0));
				Uart0_Print("%d,", MovingAverage(1));
				Uart0_Print("%d\r\n", MovingAverage(2));


//		Uart0_Print("%d\t", MovingAverage(1));
//		Uart0_Print("%d\t\r\n", ADCValue[6]);
//		Uart0_Print("%ld\r", GetPosition());

//
//		RunAdcMeasurementSeries();
//		Uart0_Print("%d,", ADCValue[0]);
//		Uart0_Print("%d,", ADCValue[1]);
//		Uart0_Print("%d\r\n", ADCValue[2]);


		SecurityCheck();
	}

}
