/*
 * UART_hw.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_UART_UART_HW_H_
#define F15_REPO_SRC_MCAL_UART_UART_HW_H_


#define UDR					*((volatile uint8*)0x2C)
#define UCSRA				*((volatile uint8*)0x2B)
#define UCSRB				*((volatile uint8*)0x2A)
#define UCSRC				*((volatile uint8*)0x40)
#define UBRRH				*((volatile uint8*)0x40)
#define UBRRL				*((volatile uint8*)0x29)

#endif /* F15_REPO_SRC_MCAL_UART_UART_HW_H_ */
