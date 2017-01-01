#include "ADC_moje.h"
#include "Uart_moje.h"
#include "MCPWM_moje.h"


int historySampleQuantity=0;
// TODO: Wczytywanie ustawieñ z pliku, i mo¿liosc edycji ustawien z terminala
struct PID_parameters
{
	double Kp;
	double Kd;
	double Ki;
	double uchyb_1;
	double I_1;
	double P;
	double I;
	double D;
	int y_max; //ograniczenie na sygna³ z góry
	int y_min; // ograniczenie na dygna³ z do³u
	long int uchyb;
	int SettedCurrent;
	int y;
};

int PID_LastResult[2]={0};

//Create array of PID_parameters
struct PID_parameters danePID[2] =
{
{ .Kp = 0.02, .Kd = 1, .Ki = 0.001, .uchyb_1 = 0, .I_1 = 0, .y_max = 127, .y_min =
		0, .P = 0, .I = 0, .D = 0, .uchyb = 0, .SettedCurrent = 3080, .y=0 },
{ .Kp = 0.02, .Kd = 1, .Ki = 0.001, .uchyb_1 = 0, .I_1 = 0, .y_max = 127, .y_min =
		0, .P = 0, .I = 0, .D = 0, .uchyb = 0, .SettedCurrent = 3080, .y=0 } };

void Set_PIDcurrent(int _historySampleQuantity)
{
	historySampleQuantity=_historySampleQuantity;
}

double CurrentPID(int adcInputChannelNumber)
{ //TODO: Sprawdzic czy dziala
//TODO: Zamienic PID aby dzialac tylko na int'ach
//TODO: Zlikwidowac rzutowanie wartosci double y na long int test
//PID wywolywana jest co "max_przepelnien_PID" przerwañ wewnêtrznych od przepe³nienia timera sterujacego PWM.

	//Count current error between setted current value and MovingAverage from value of current.
	danePID[adcInputChannelNumber].uchyb =
			danePID[adcInputChannelNumber].SettedCurrent
					- MovingAverage(adcInputChannelNumber);

	//Count P, I, D member.
	danePID[adcInputChannelNumber].P = danePID[adcInputChannelNumber].Kp
			* danePID[adcInputChannelNumber].uchyb;

	danePID[adcInputChannelNumber].I = danePID[adcInputChannelNumber].Ki
			* (danePID[adcInputChannelNumber].uchyb
					+ danePID[adcInputChannelNumber].uchyb_1) / 2
			+ danePID[adcInputChannelNumber].I_1; //Ca³kujê metod¹ trapezów

	danePID[adcInputChannelNumber].D = danePID[adcInputChannelNumber].Kd
			* (danePID[adcInputChannelNumber].uchyb
					- danePID[adcInputChannelNumber].uchyb_1);

	//Count total value of PID output.
	danePID[adcInputChannelNumber].y = danePID[adcInputChannelNumber].P
			+ danePID[adcInputChannelNumber].I
			+ danePID[adcInputChannelNumber].D;

	//Copy value of uchyb to uchyb_1.
	danePID[adcInputChannelNumber].uchyb_1 =
			danePID[adcInputChannelNumber].uchyb;
	danePID[adcInputChannelNumber].I_1 = danePID[adcInputChannelNumber].I;

	//Windup protection, it counted value over range it will limit it.
	if ((danePID[adcInputChannelNumber].y < danePID[adcInputChannelNumber].y_min))
	{
		danePID[adcInputChannelNumber].y = danePID[adcInputChannelNumber].y_min;

	}
	else if (danePID[adcInputChannelNumber].y
			> danePID[adcInputChannelNumber].y_max)
	{
		danePID[adcInputChannelNumber].y = danePID[adcInputChannelNumber].y_max;

	}

	//Change amplitude
	//StepperMotorChangeAmplitude(adcInputChannelNumber,
	//		danePID[adcInputChannelNumber].y);


//	Uart0_Print("\n\rInput number: %d\t ",adcInputChannelNumber);
//	Uart0_Print("Error: %d\t ",danePID[adcInputChannelNumber].uchyb);
//	Uart0_Print("Result: %d\n\r ",danePID[adcInputChannelNumber].y);

	return danePID[adcInputChannelNumber].y;
}

void StartCurrentPID()
{
	//Start adc conversions,
	RunAdcMeasurementSeries(historySampleQuantity);


	Uart0_Print("MovingAverage0: %d\t", MovingAverage(0));
	Uart0_Print("MovingAverage1: %d", MovingAverage(1));
	PID_LastResult[0]=CurrentPID(0);
	PID_LastResult[1]=CurrentPID(1);

	Uart0_Print("\n\ry1: %d\t ",PID_LastResult[0]);
	Uart0_Print("y2: %d\n\r ",PID_LastResult[1]);
	PrintThreePhaseMCPWMSettedOutput();
	Change_MCPWM(1,PID_LastResult);
}
