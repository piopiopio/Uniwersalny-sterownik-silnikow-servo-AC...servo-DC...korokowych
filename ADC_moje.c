#include "lpc17xx.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_clkpwr.h"
#include "ADC_moje.h"
#include "Uart_moje.h"
#include "math.h"
#include "MCPWM_moje.h"

volatile int adcSeriesDone = 1;

//OVER_CURRENT:

//Maximum overcurrent, current above this value cause error, and block driver.
int overCurrent = 0;

//Analog references for non current flow through ACS712.
int zeroCurrent = 0;

//Number of current measure inputs it can be: 0,1,2.
int overCurrentInputs = 2;

//Local control,
int overCurrentFlag = 0;

//MOVING_AVERAG:

//Be careful AD0.6 and AD0.7 are UART0 pins.
int numberOfUsedAdcInput = 0;

//Current state of adc routine, there are 6 states from 2 to 7, because 0 and 1 adc input are reserved for current measuring.
int adcState = 2;

//Iterator used to get adc measuring sequence: 0,1,2,0,1,3,0,1,4... .
int adcStateIterator = 0;

//Iterator used to get adc measuring sequence: 0,1,2,0,1,3,0,1,4... . It is used locally in IncrementAdcStateIterator.
int adcStateIteratorLocal = 1;

//Number of samples to count moving average.
#define  historySampleQuantity 40

#define maxAdcInputs 8

//ADC values used to calculate moving average.
int ADCValueHistory[maxAdcInputs][historySampleQuantity];

//Variable contain ADC measured value for each channel, current sensor.
volatile uint32_t ADCValue[maxAdcInputs] =
{ 0 };

//ADC0ValueHistoryInicialized is changed to 1 when ADC0ValueHistory is fully initialized.
int ADC0ValueHistoryInicialized[maxAdcInputs] =
{ 0 };

//ADC interruts timer, overflow after [historySampleQuantity] ticks.
int ADC_IRQHandlerIterator[maxAdcInputs] =
{ 0 };

//Value of moving average function is stored here, it can be first count after [historySampleQuantity] ADC measures.
int MovingAverageValue[maxAdcInputs] =
{ 0 };

//TEST:

//When TestADC is in progress, this flag is set to 1.
int testFlag = 0;

//Number of collected test samples.
int testPeriod = 0;

//Number of different samples take into test.
#define resultRange 20

//This array contains number of each values returned by ADC.
int testResults[resultRange];

//Expected test value, used to center testResults.
int expectedLeastTestValue = 0;

int Set_ADC(int _overCurrent, int _zeroCurrent, int _adcInputsNuber)
{
	//Set number of used adc inputs. Always it is used in sequence 0,1,2...
	numberOfUsedAdcInput = _adcInputsNuber;

	//Set over current value.
	overCurrent = _overCurrent;

	//Set non current flow value.
	zeroCurrent = _zeroCurrent;

	//ADC set power on.
	LPC_SC->PCONP |= (1 << 12);

	//Set P0.23 as AD0.0- ADC input; Pinsel1, Pins 15, 14 : 01.
	LPC_PINCON->PINSEL1 &= ~(1 << 15);
	LPC_PINCON->PINSEL1 |= (1 << 14);

	//Set P0.24 as AD0.1- ADC input; Pinsel1, Pins 17, 16 : 01.
	LPC_PINCON->PINSEL1 &= ~(1 << 17);
	LPC_PINCON->PINSEL1 |= (1 << 16);

	//Set P0.25 as AD0.2- ADC input; Pinsel1, Pins 19, 18 : 01.
	LPC_PINCON->PINSEL1 &= ~(1 << 19);
	LPC_PINCON->PINSEL1 |= (1 << 18);

	//Set P0.26 as AD0.3- ADC input; Pinsel1, Pins 21, 20 : 01.
	LPC_PINCON->PINSEL1 &= ~(1 << 21);
	LPC_PINCON->PINSEL1 |= (1 << 20);

	//Set P0.26 as AD0.3- ADC input; Pinsel1, Pins 21, 20 : 01.
	LPC_PINCON->PINSEL1 &= ~(1 << 21);
	LPC_PINCON->PINSEL1 |= (1 << 20);

	//Set P1.30 as AD0.4- ADC input; Pinsel3, Pins 29, 28 : 01.
	LPC_PINCON->PINSEL3 |= ((1 << 29) | (1 << 28));

	//Set P1.33 as AD0.5- ADC input; Pinsel3, Pins 31, 30 : 01.
	LPC_PINCON->PINSEL3 |= (1 << 31) | (1 << 30);

	//Set P0.03 as AD0.6- ADC input; Pinsel0, Pins 7, 6 : 01.
//	LPC_PINCON->PINSEL3 &= ~(1 << 6);
//	LPC_PINCON->PINSEL3 |= (1 << 7);

	//Set P0.02 as AD0.7- ADC input; Pinsel0, Pins 5,4 : 01.
//	LPC_PINCON->PINSEL0 &= ~(1 << 4);
//	LPC_PINCON->PINSEL0 |= (1 << 5);

	//Turn off pull up and down AD0.0
	LPC_PINCON->PINMODE1 |= (1 << 15);
	LPC_PINCON->PINMODE1 &= ~(1 << 14);

	//Turn off pull up and down AD0.1
	LPC_PINCON->PINMODE1 |= (1 << 17);
	LPC_PINCON->PINMODE1 &= ~(1 << 16);

	//Turn off pull up and down AD0.2
//	LPC_PINCON->PINMODE1 |= (1 << 18);
//	LPC_PINCON->PINMODE1 &= ~(1 << 19);

	//Turn off pull up and down AD0.3
//	LPC_PINCON->PINMODE1 |= (1 << 20);
//	LPC_PINCON->PINMODE1 &= ~(1 << 21);

	//Select channel 0.
	LPC_ADC->ADCR |= (1 << 0);

	//Set up clock divider (CLKDIV = Fpclk / (ADC_Clk - 1)).
	LPC_ADC->ADCR |= (7 << 8);

	//ADC enable.
	LPC_ADC->ADCR = (1 << 21);

	// Start first conversion.
	//LPC_ADC->ADCR |= (1 << 24);

	//Enable interrupt: Completion of a conversion on ADC.
	LPC_ADC->ADINTEN = (0b1111111);

	//Enable interrupt in NVIC.
	NVIC_EnableIRQ(ADC_IRQn);
	NVIC_SetPriority(ADC_IRQn, 2);
	NVIC->ISER[0] = (1 << ((uint32_t) (22) & 0x1F));

	//Set P3.25 as GPIO- OverCurrent_LED.
	//TODO: Zmienic- pin wykorzystany jako wyjscie dla silnika
	LPC_PINCON->PINSEL7 &= ~((1 << 18) | (1 << 19));

	//Set P3.25 direction.
	LPC_GPIO3->FIODIR |= (1 << 25);

	//Set high state onP3.25 .
	LPC_GPIO3->FIOSET |= (1 << 25);
	return historySampleQuantity;
}

void AdcValue(int adcInputNumber)
{
	switch (adcInputNumber)
	{
	case 0:
		//Get ADC measured value.
		ADCValue[adcInputNumber] = (LPC_ADC->ADDR0 >> 4) & 0xFFF;
		//Uart0_Print("Kanal 0: %d\r\n", ADCValue[adcInputNumber]);
		break;
	case 1:
		//Get ADC measured value.
		ADCValue[adcInputNumber] = (LPC_ADC->ADDR1 >> 4) & 0xFFF;
		//Uart0_Print("Kanal 1: %d\r\n", ADCValue[adcInputNumber]);
		break;
	case 2:
		//Get ADC measured value.
		ADCValue[adcInputNumber] = (LPC_ADC->ADDR2 >> 4) & 0xFFF;
		//Uart0_Print("Kanal 2 : %d\r\n", ADCValue[adcInputNumber]);
		break;
	case 3:
		//Get ADC measured value.
		ADCValue[adcInputNumber] = (LPC_ADC->ADDR3 >> 4) & 0xFFF;
		//Uart0_Print("Kanal 3 : %d\r\n", ADCValue[adcInputNumber]);
		break;
	case 4:
		//Get ADC measured value.
		ADCValue[adcInputNumber] = (LPC_ADC->ADDR4 >> 4) & 0xFFF;
		//Uart0_Print("Kanal 4 : %d\r\n", ADCValue[adcInputNumber]);
		break;
	case 5:
		//Get ADC measured value.
		ADCValue[adcInputNumber] = (LPC_ADC->ADDR5 >> 4) & 0xFFF;
		//Uart0_Print("Kanal 5 : %d\r\n", ADCValue[adcInputNumber]);
		break;
	case 6:
		//Get ADC measured value.
		ADCValue[adcInputNumber] = (LPC_ADC->ADDR6 >> 4) & 0xFFF;
		//Uart0_Print("Kanal 6 : %d\r\n", ADCValue[adcInputNumber]);
		break;
	case 7:
		//Get ADC measured value.
		ADCValue[adcInputNumber] = (LPC_ADC->ADDR7 >> 4) & 0xFFF;
		//Uart0_Print("Kanal 7 : %d\r\n", ADCValue[adcInputNumber]);
		break;

	default:
		break;
	}

	//Copy ADCValue[x] to ADC0ValueHistory[x].
	ADCValueHistory[adcInputNumber][ADC_IRQHandlerIterator[adcInputNumber]] =
			ADCValue[adcInputNumber];

	//If [ADC_IRQHandlerIterator] is equal to [(historySampleQuantity - 1)] then set [ADC_IRQHandlerIterator] to zero.
	//This override result in place new value on the oldest value in [ADC0ValueHistory].
	if (ADC_IRQHandlerIterator[adcInputNumber] >= (historySampleQuantity - 1))
	{
		ADC_IRQHandlerIterator[adcInputNumber] = 0;
		ADC0ValueHistoryInicialized[adcInputNumber] = 1;
	}
	else
	{
		ADC_IRQHandlerIterator[adcInputNumber]++;
	}

	//Count MovingAvereage for adcInputNumber.
	//MovingAverage(adcInputNumber);

}

void CheckOverCurrent(int adcStateIterator)
{
	//Check if there was no overcurrent.

//	if (adcStateIterator < overCurrentInputs)
//	{
//		//If this occur then set outputs to passive state.
//		//TODO: Sprawdzac nie jeden pomiar a wszsytkie w historii.? Jesli tak to wywo³ywac raz podczas calej serii
//
//		if (((int) ADCValue[adcStateIterator] > (zeroCurrent + overCurrent))
//				|| ((int) ADCValue[adcStateIterator]
//						< (zeroCurrent - overCurrent)))
//		{
//			Lock_MCPWM();
//
//			//Set low state onP3.25 .
//			LPC_GPIO3->FIOCLR |= (1 << 25);
//		}
//	}
	overCurrentFlag = 1;
	if (adcStateIterator < overCurrentInputs)
	{

		for (int var = 0; var < historySampleQuantity; ++var)
		{
			if (((zeroCurrent - overCurrent)
					< (int) ADCValueHistory[adcStateIterator][var])
					&& ((int) ADCValueHistory[adcStateIterator][var]
							< (zeroCurrent + overCurrent)))
			{ //TODO: zmieni³em: teraz ca³¹ seria musi byæ overcurrent zeby wyzwolic blokade.
				//All ADCValueHistory elements must be overcurrent to run protection.
				//If one element of ADCValueHistory is not overcurrent there are no overcurrent protection.
				overCurrentFlag = 0;
			}
		}
	}
	if (overCurrentFlag)
	{
		Lock_MCPWM();

		//Set low state onP3.25 .
		LPC_GPIO3->FIOCLR |= (1 << 25);
	}
}

void IncrementAdcStateIterator()
{ //channels 0 and 1 are reserved for current measuring.
//Measuring sequence 0,1,2,0,1,3,0,1,4,0,1,5,0,1,6,0,1,7. (0,1,x)-where x is next adc input.
	switch (adcStateIteratorLocal)
	{
	case 0:
		//If in use is more than 1 adc inputs then set adcStateIterator to 1.
		if (1 < numberOfUsedAdcInput)
		{
			adcStateIteratorLocal = 1;
		}
		//If in use is 1 adc input then set adcStateIterator to 0.
		else if (1 == numberOfUsedAdcInput)
		{
			adcStateIteratorLocal = 0;
		}
		//If in use is 0 adc input then quit this interrupt routine, without initiate new probe.
		else if (0 == numberOfUsedAdcInput)
		{
			return;
		}

		//Select 0 channel
		LPC_ADC->ADCR &= ~(0b11111111);
		LPC_ADC->ADCR |= (1 << 0);
		adcStateIterator = 0;
		adcSeriesDone = 1;

		//Print this text only to organize console.
		//Uart0_Print("Kanal 000000000000000000000000\n\r");
		break;

	case 1:
		adcState++;

		//Check if adcState is bigger or equal to numberOfUsedAdcInput. If yes then adcState must be set to initial value.
		if (adcState >= numberOfUsedAdcInput)
		{
			//If in use is more than 2 adc inputs then adcState initial value is 2.
			if (2 < numberOfUsedAdcInput)
			{
				adcState = 2;
			}
		}

		//If in use is less than 2 adc inputs then adcState initial value is 0.
		if (2 >= numberOfUsedAdcInput)
		{
			adcState = 0;
		}
		//In next interrupt routine execution jump to case number adcState.
		adcStateIteratorLocal = adcState;

		//Select 0 channel
		LPC_ADC->ADCR &= ~(0b11111111);
		LPC_ADC->ADCR |= (1 << 1);
		adcStateIterator = 1;

		//Print this text only to organize console.
		//Uart0_Print("Kanal 11111111111111111111111111\n\r");

		//Start conversion now.
		LPC_ADC->ADCR |= (1 << 24);
		break;

	case 2:
		//Select 0 channel
		LPC_ADC->ADCR &= ~(0b11111111);
		LPC_ADC->ADCR |= (1 << 2);
		adcStateIterator = 2;
		adcStateIteratorLocal = 0;
		//Uart0_Print("Kanal 22222222222222222222222222222\n\r");

		//Start conversion now.
		LPC_ADC->ADCR |= (1 << 24);
		break;

	case 3:
		//Select 0 channel
		LPC_ADC->ADCR &= ~(0b11111111);
		LPC_ADC->ADCR |= (1 << 3);
		adcStateIterator = 3;
		adcStateIteratorLocal = 0;

		//Start conversion now.
		LPC_ADC->ADCR |= (1 << 24);
		break;

	case 4:
		//Select 0 channel
		LPC_ADC->ADCR &= ~(0b11111111);
		LPC_ADC->ADCR |= (1 << 4);
		adcStateIterator = 4;
		adcStateIteratorLocal = 0;

		//Start conversion now.
		LPC_ADC->ADCR |= (1 << 24);
		break;

	case 5:
		//Select 0 channel
		LPC_ADC->ADCR &= ~(0b11111111);
		LPC_ADC->ADCR |= (1 << 5);
		adcStateIterator = 5;
		adcStateIteratorLocal = 0;

		//Start conversion now.
		LPC_ADC->ADCR |= (1 << 24);
		break;

	case 6:
		//Select 0 channel
		LPC_ADC->ADCR &= ~(0b11111111);
		LPC_ADC->ADCR |= (1 << 6);
		adcStateIterator = 6;
		adcStateIteratorLocal = 0;

		//Start conversion now.
		LPC_ADC->ADCR |= (1 << 24);
		break;

	case 7:
		//Select 0 channel
		LPC_ADC->ADCR &= ~(0b11111111);
		LPC_ADC->ADCR |= (1 << 7);
		adcStateIterator = 7;
		adcStateIteratorLocal = 0;

		//Start conversion now.
		LPC_ADC->ADCR |= (1 << 24);
		break;

	default:
		Uart0_Print("ADC Error\n\r");
		break;
	}
}

void TestADC(int numberOfSamples, int expectedLeastTestValue_)
{ //TODO: dodaæ ustawianie w zale¿nosci od kana³u.
	expectedLeastTestValue = expectedLeastTestValue_;
	for (int var = 0; var <= (resultRange - 1); ++var)
	{
		testResults[var] = 0;
	}
	testFlag = 1;
	testPeriod = numberOfSamples;
	while (testPeriod > 0)
	{
		//Wait until test is ended.
	}
	testFlag = 0;
	LPC_ADC->ADCR &= ~(1 << 24);
	for (int var = 0; var <= (resultRange - 1); var++)
	{
		Uart0_Print("%d\t%d\n\r", var, testResults[var]);
	}

}

int MovingAverage(int adcInputNumber)
{ //TODO: Sprawdzic czy dzia³a dla róznychkana³óów

//	//Clear MovingAverageValue, sum values from [ADC0ValueHistory] and then divide by [historySampleQuantity].
	MovingAverageValue[adcInputNumber] = 0;
//
//	//Check if ADC0ValueHistory fully initialized, if yes then sum all values from [ADC0ValueHistory].
//	if (ADC0ValueHistoryInicialized[adcInputNumber] == 1)
//	{
		for (int var = 0; var < historySampleQuantity; var++)
		{
			MovingAverageValue[adcInputNumber] =
					MovingAverageValue[adcInputNumber]
							+ ADCValueHistory[adcInputNumber][var];
		}
		//Divide sum of all values by historySampleQuantity.
		MovingAverageValue[adcInputNumber] = (int) round(
				(double) MovingAverageValue[adcInputNumber]
						/ historySampleQuantity);
//	}
//
//	//Check if ADC0ValueHistory fully initialized, if no then sum [ADC_IRQHandlerIterator] values from [ADC0ValueHistory].
//	else
//	{
//		for (int var = 0; var < ADC_IRQHandlerIterator[adcInputNumber]; var++)
//		{
//			MovingAverageValue[adcInputNumber] =
//					MovingAverageValue[adcInputNumber]
//							+ ADCValueHistory[adcInputNumber][var];
//		}
//		//Divide sum of all values by ADC_IRQHandlerIterator.
//		MovingAverageValue[adcInputNumber] = (int) round(
//				(double) MovingAverageValue[adcInputNumber]
//						/ ADC_IRQHandlerIterator[adcInputNumber]);
//	}

	return MovingAverageValue[adcInputNumber];
}

void RunAdcMeasurementSeries()
{ //TODO: Zmiana nazwy na co bardziej w stylu: Uruchom PID
//TODO: Zerowanie ADCHistor[0] oraz ADChistory[1]

	for (int var = 0; var < historySampleQuantity; ++var)
	{
		while (adcSeriesDone == 0)
		{
			//Wait until end of first series
		}

		adcSeriesDone = 0;
		//Start conversion now.
		LPC_ADC->ADCR |= (1 << 24);

	}
	while (adcSeriesDone == 0)
	{
		//Wait until end of first series
	}
	//TODO: Wyzwalanie PID_current



}

//Interrupt service routine.
void ADC_IRQHandler(void)
{

	//Stop adc conversion now until finish executing this routine.
	LPC_ADC->ADCR &= ~(1 << 24);
	AdcValue(adcStateIterator);

	//TestADC counting values.
	if (testFlag && testPeriod)
	{
		for (int var = 0; var < resultRange - 1; var++)
		{
			if (ADCValue[0] == (expectedLeastTestValue + var))
			{
				testResults[var]++;
			}

		}
		testPeriod--;
	}

	//Increment AdcStateIterator to achieve measuring sequence 0,1,2,0,1,3,0,1,4,0,1,5,0,1,6,0,1,7. (0,1,x)-where x is next adc input.
	IncrementAdcStateIterator();

	//PrintThreePhaseMCPWMSettedOutput();

	//TODO: WyzwwalanieADC z timera. (tego samego co zmiana w MCPWM  (pomiar ADC kilka razy czesciej)

	return;
}
