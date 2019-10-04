/*
 * Global_Int.h
 *
 *  Created on: Jul 12, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_GLOBAL_INTERRUPT_GLOBAL_INT_H_
#define F15_REPO_SRC_MCAL_GLOBAL_INTERRUPT_GLOBAL_INT_H_

#include "../../utils/Bit_Math.h"
#include "../../utils/Std_Types.h"

#define SREG				*((volatile uint8*)0x5F)

#define GI_en()				Set_Bit(SREG,7);
#define GI_dis()			Clr_Bit(SREG,7);

#endif /* F15_REPO_SRC_MCAL_GLOBAL_INTERRUPT_GLOBAL_INT_H_ */
