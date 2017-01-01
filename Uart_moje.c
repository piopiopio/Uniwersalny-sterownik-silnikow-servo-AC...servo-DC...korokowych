#define MessageMaxSize	36

#include "Uart_moje.h"
#include "lpc17xx_clkpwr.h"
#include "lpc17xx_pinsel.h"
#include <stdio.h>
#include <stdarg.h>

uint8_t rxBuf[16] = { 0 }; /** UART0 receive data buf */
uint32_t rxCnt = 0;
volatile Bool rxFlag = FALSE;
int enable=1;
//Set Uart0
void Set_Uart0(int BaudRate,int enableDisable) {
	/** System init */
	//SystemInit();
	//SystemCoreClockUpdate();
	/** LED init */
	//CLKPWR_ConfigPPWR(CLKPWR_PCONP_PCGPIO, ENABLE);	/** Enable GPIO Power */
	/* Pin configuration for UART0 */
	PINSEL_CFG_Type PinCfg;

	/*
	 * Initialize UART0 pin connect
	 */
	enable=enableDisable;
	PinCfg.Funcnum = 1;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Portnum = UART0_PORT;
	PinCfg.Pinnum = UART0_TX;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = UART0_RX;
	PINSEL_ConfigPin(&PinCfg);

	UART0_Init(BaudRate);
}

//Test uart0, from scratch self initialising.
void UartTest() {
	/** System init */
	SystemInit();
	SystemCoreClockUpdate();

	/** LED init */
	CLKPWR_ConfigPPWR(CLKPWR_PCONP_PCGPIO, ENABLE); /** Enable GPIO Power */

	/** UART init */
	/* Pin configuration for UART0 */
	PINSEL_CFG_Type PinCfg;

	/*
	 * Initialize UART0 pin connect
	 */
	PinCfg.Funcnum = 1;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Portnum = UART0_PORT;
	PinCfg.Pinnum = UART0_TX;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = UART0_RX;
	PINSEL_ConfigPin(&PinCfg);

	UART0_Init(9600);

	/* print a string */
	UART_Send(LPC_UART0, (uint8_t *) "hello word\n", sizeof("hello word\n"),
			NONE_BLOCKING);

//	while (1) {
//
//		if (rxFlag == TRUE) {
//			rxFlag = FALSE;
//			LEDx_ON(LED0);
//			UART_Send(LPC_UART0, rxBuf, rxCnt, BLOCKING);
//
//		} else {
//			LEDx_OFF(LED0);
//		}
//	}

}

//Inicialisation function for uart0
void UART0_Init(int BaudRate) {
	LPC_UART_TypeDef *UARTx = (LPC_UART_TypeDef *) LPC_UART0;

	/* UART Configuration structure variable */
	UART_CFG_Type UARTConfigStruct;

	/* UART FIFO configuration Struct variable */
	UART_FIFO_CFG_Type UARTFIFOConfigStruct;

	/* Initialize UART Configuration parameter structure to default state:
	 * Baudrate = 9600bps
	 * 8 data bit
	 * 1 Stop bit
	 * None parity
	 */
	UART_ConfigStructInit(&UARTConfigStruct);

	/* Set Baudrate */
	UARTConfigStruct.Baud_rate = BaudRate;

	/* Initialize UART0 peripheral with given to corresponding parameter */
	UART_Init(UARTx, &UARTConfigStruct);

	/* Initialize FIFOConfigStruct to default state:
	 * 				- FIFO_DMAMode = DISABLE
	 * 				- FIFO_Level = UART_FIFO_TRGLEV0
	 * 				- FIFO_ResetRxBuf = ENABLE
	 * 				- FIFO_ResetTxBuf = ENABLE
	 * 				- FIFO_State = ENABLE
	 */
	UART_FIFOConfigStructInit(&UARTFIFOConfigStruct);
	UARTFIFOConfigStruct.FIFO_Level = UART_FIFO_TRGLEV2; /* 8 Bytes */

	/* Initialize FIFO for UART0 peripheral */
	UART_FIFOConfig(UARTx, &UARTFIFOConfigStruct);

	/** config and enable interrupter */
	UART_IntConfig(UARTx, UART_INTCFG_RBR, ENABLE);

	/** NVIC enable interrupter , it's request锛�*/
	NVIC_EnableIRQ(UART0_IRQn);
	NVIC_SetPriority(UART0_IRQn,1);

	/*  Enable UART Transmit */
	UART_TxCmd(UARTx, ENABLE);
}

//@brief UART0 interrupter
void UART0_IRQHandler(void)

{
	uint8_t ReceiveValue;
	uint8_t i;
	uint32_t IIRValue;

	rxCnt = 0;
	IIRValue = UART_GetIntId(LPC_UART0);

	while ((IIRValue & 0x01) == 0) { /* if have another interrupter hand on */
		switch (IIRValue & 0x0E) { /* flag */
		case UART_IIR_INTID_RDA:
			for (i = 0; i < 8; i++) {
				rxFlag = TRUE;
				ReceiveValue = UART_ReceiveByte(LPC_UART0);
				rxBuf[rxCnt++] = ReceiveValue;
			}
			break;
		case UART_IIR_INTID_CTI:
			rxFlag = TRUE;
			ReceiveValue = UART_ReceiveByte(LPC_UART0);
			rxBuf[rxCnt++] = ReceiveValue;
			break;
		default:
			break;
		}
		IIRValue = UART_GetIntId(LPC_UART0);
	}
}

//Send character to uart
void Uart_PutChar(LPC_UART_TypeDef* UARTx, uint8_t ch) { //Example: Uart_PutChar(LPC_UART0, 'a');
//TODO: Add not directly to LSR but to fifo
//Check if something is in the THR
	while (~(LPC_UART0->LSR) & (1 << 5)) {
		//Waiting;
	}
	UART_SendByte(LPC_UART0, ch);
}

void Uart_PutString(LPC_UART_TypeDef* UARTx, uint8_t * str) { //Example: Uart_PutString(LPC_UART0, (uint8_t*)"EMBEDONIX.COM");
	while (*str != 0) {
		Uart_PutChar(UARTx, *str);
		str++;
	}
}

void Uart_PutNumber(LPC_UART_TypeDef* UARTx, uint32_t x) { //Example: Uart_PutNumber(LPC_UART0, g);
	char value[10]; //a temp array to hold results of conversion
	int i = 0; //loop index

	do {
		value[i++] = (char) (x % 10) + '0'; //convert integer to character
		x /= 10;
	} while (x);

	//send data
	while (i)
	{
		Uart_PutChar(UARTx, value[--i]);
	}
}

void Uart_PutDouble(LPC_UART_TypeDef* UARTx, double num) { //Example: Uart_PutDouble(LPC_UART0, g);

	//Convert double to string (Double must not exceed 20 digits, without changing size of retnum array)
	static char retnum[21]; // Enough for 20 digits plus NUL from a 64-bit uint.
	sprintf(retnum, "%f", num);

	//Send string
	//TODO: LPC_UART0->UARTX
	Uart_PutString(LPC_UART0, (uint8_t*) retnum);

}

void Uart0_Print(const char *pFormat, ...) {
if (enable){
	va_list ap;
	va_start(ap, pFormat);
	static char retnum[MessageMaxSize];
	vsnprintf(retnum, MessageMaxSize, pFormat, ap);
	Uart_PutString(LPC_UART0, (uint8_t*) retnum);
	va_end(ap);
}

}
