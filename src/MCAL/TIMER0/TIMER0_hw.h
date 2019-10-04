/*
 * TIMER0_hw.h
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_TIMER0_TIMER0_HW_H_
#define F15_REPO_SRC_MCAL_TIMER0_TIMER0_HW_H_

#define TCNT0		(*(volatile uint8*)0x52)
#define TCCR0		(*(volatile uint8*)0x53)
#define OCR0		(*(volatile uint8*)0x5C)
#define TIMSK		(*(volatile uint8*)0x59)
#define TIFR		(*(volatile uint8*)0x58)

#endif /* F15_REPO_SRC_MCAL_TIMER0_TIMER0_HW_H_ */
