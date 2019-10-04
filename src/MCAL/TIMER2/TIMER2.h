/*
 * TIMER2.h
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_TIMER2_TIMER2_H_
#define F15_REPO_SRC_MCAL_TIMER2_TIMER2_H_

#include "../../utils/STD_Types.h"

void TIMER2_init(void);
void TIMER2_enInterrupt(void);
void TIMER2_diInterrupt(void);
void TIMER2_setCounterSteps(uint8 StepsToCount);
uint8 TIMER2_readCounterSteps(void);

#endif /* F15_REPO_SRC_MCAL_TIMER2_TIMER2_H_ */
