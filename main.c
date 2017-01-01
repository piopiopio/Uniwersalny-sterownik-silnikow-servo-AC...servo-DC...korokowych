#include <MCPWM_moje.h>
#include <LPC17xx.h>
#include <QEI_moje.h>
#include <Uart_moje.h>
#include <ADC_moje.h>
#include <stdint-gcc.h>
#include <StepDir_moje.h>
#include <Timer1_moje.h>
#include <PID_current.h>



char typeOfOutput='k';
double frequency=1;
int valuesRange=255;

volatile uint32_t ADCValue[8];

int main(void)
{
	int SIN_TAB_quantity=Set_MCPWM(typeOfOutput, frequency, valuesRange);
	Set_Timer1(frequency, typeOfOutput, SIN_TAB_quantity );
	Set_StepDir();
	Set_QEI(2000);
	Set_Uart0(460800);
	int historySampleQuantity=Set_ADC(4000, 3080, 2); //Ustawiona taka wysoka wartoæ overcurrent,  ¿eby nie wyzwalac blokady w czasie testow.
	Set_PIDcurrent(historySampleQuantity);




	while (1)
	{

//		PrintThreePhaseMCPWMSettedOutput();
//		Uart0_Print("%d\t", MovingAverage(1));
//		Uart0_Print("%d\t", ADCValue[0]);
//		Uart0_Print("%d\r\n", ADCValue[1]);
//		Uart0_Print("%ld\r", GetPosition());

	}

}
