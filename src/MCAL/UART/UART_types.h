/*
 * UART_types.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_UART_UART_TYPES_H_
#define F15_REPO_SRC_MCAL_UART_UART_TYPES_H_

typedef enum
{
	UART_Int_RxComplete,
	UART_Int_TxComplete,
	UART_Int_UdrReady,
}UART_IntType;


#endif /* F15_REPO_SRC_MCAL_UART_UART_TYPES_H_ */
