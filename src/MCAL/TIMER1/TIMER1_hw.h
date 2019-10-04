/*
 * TIMER1_hw.c
 *
 *  Created on: Jul 20, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_TIMER1_TIMER1_HW_C_
#define F15_REPO_SRC_MCAL_TIMER1_TIMER1_HW_C_

#define TIMSK		*((volatile uint8*)0x59)
#define TIFR		*((volatile uint8*)0x58)
#define TCCR1A		*((volatile uint8*)0x4F)
#define TCCR1B		*((volatile uint8*)0x4E)

#define TCNT1		*((volatile uint16*)0x4C)
#define OCR1A		*((volatile uint16*)0x4A)
#define OCR1B		*((volatile uint16*)0x48)
#define ICR			*((volatile uint16*)0x46)

#endif /* F15_REPO_SRC_MCAL_TIMER1_TIMER1_HW_C_ */
