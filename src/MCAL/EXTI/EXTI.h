/*
 * EXTI.h
 *
 *  Created on: Jul 12, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_EXTI_EXTI_H_
#define F15_REPO_SRC_MCAL_EXTI_EXTI_H_

#include "../../utils/Std_Types.h"
#include "EXTI_types.h"


void EXTI_init(void);
void EXTI_disInterrupt(EXTI_IntType IntNum);
void EXTI_enInterrupt(EXTI_IntType IntNum);
void EXTI_setCallBackFunc(EXTI_IntType IntNum, Ptr2FuncType Func);

#endif /* F15_REPO_SRC_MCAL_EXTI_EXTI_H_ */
