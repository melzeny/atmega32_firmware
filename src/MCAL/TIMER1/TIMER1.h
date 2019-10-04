/*
 * TIMER1.h
 *
 *  Created on: Jul 20, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_TIMER1_TIMER1_H_
#define F15_REPO_SRC_MCAL_TIMER1_TIMER1_H_

#include "../../utils/Std_Types.h"
#include "Timer1_types.h"

void TIMER1_init(void);
void TIMER1_enInterrupt(TIMER1_IntType Int);
void TIMER1_diInterrupt(TIMER1_IntType Int);
void TIMER1_setCompareSteps(uint16 COMPA,uint16 COMPB);
void TIMER1_ReadPwm(uint32* Freq_hz_Ptr, uint8* DutyCyclePtr);
uint32 TIMER1_getHiLevelTime(void);
#endif /* F15_REPO_SRC_MCAL_TIMER1_TIMER1_H_ */
