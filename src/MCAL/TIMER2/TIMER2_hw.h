/*
 * TIMER0_hw.h
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_TIMER2_TIMER0_HW_H_
#define F15_REPO_SRC_MCAL_TIMER2_TIMER0_HW_H_

#define TCCR2				*((volatile uint8*)0x45)
#define TCNT2				*((volatile uint8*)0x44)
#define OCR2				*((volatile uint8*)0x43)
#define TIMSK				*((volatile uint8*)0x59)
#define TIFR				*((volatile uint8*)0x58)

#endif /* F15_REPO_SRC_MCAL_TIMER0_TIMER0_HW_H_ */
