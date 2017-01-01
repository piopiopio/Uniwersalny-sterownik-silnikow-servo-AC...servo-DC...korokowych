/***********************************************************************//**
 * @file		board.h
 * @brief		Define ZLG Easy CortexM3 LPC1752 board peripheral
 * @version		1.0
 * @date		12. June. 2013
 * @author		jerry2012cn(tudengqian@gmail.com)
 **************************************************************************/
#ifndef __UART_MOJE_H__
#define __UART_MOJE_H__

/** Includes--------------------------------------------------------------------*/
#include "lpc17xx_uart.h"


/** UART--------- ------------------------------------------------------------*/
#define UART0_PORT		(0)
#define UART0_TX		(2)
#define UART0_RX		(3)

//Initialize uart0 with given baudrate.
//Used pins: P0.2- tx, P0.3- rx.
void Set_Uart0(int BaudRate);


void UartTest(void);
void UART0_Init(int BaudRate);
void Uart_PutChar(LPC_UART_TypeDef* UARTx, uint8_t ch);
void Uart_PutString(LPC_UART_TypeDef* UARTx, uint8_t * str);
void Uart_PutNumber(LPC_UART_TypeDef* UARTx, uint32_t x);
void Uart_PutDouble(LPC_UART_TypeDef* UARTx, double num);
void Uart0_Print(const char *pFormat, ...);

#endif /** __BOARD_H__ */
/*------- --------------------------End File------------------------------- */

