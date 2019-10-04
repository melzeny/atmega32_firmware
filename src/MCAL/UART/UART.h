/*
 * UART.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_UART_UART_H_
#define F15_REPO_SRC_MCAL_UART_UART_H_

#include "../../utils/Std_Types.h"
#include "UART_types.h"

void UART_init(void);
STD_RetType UART_sendMsg(const uint8 Msg[],uint8 MsgLength);
void UART_getReceiveMsg(uint8* MsgPtr, uint8* MsgLength);
void UART_enInterrupt(UART_IntType Interrupt);
void UART_diInterrupt(UART_IntType Interrupt);


#endif /* F15_REPO_SRC_MCAL_UART_UART_H_ */
