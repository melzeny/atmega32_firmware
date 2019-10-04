/*
 * EXTI.c
 *
 *  Created on: Jul 12, 2019
 *      Author: Muhammad.Elzeiny
 */
#define	EXTI_EDGE_clr_msk_0						0b11111100
#define	EXTI_EDGE_clr_msk_1						0b11110011

#define EXTI_EDGE_LOW_LEVEL_msk					0b00000000
#define EXTI_EDGE_BOTH_msk						0b00000001
#define EXTI_EDGE_RISING_msk					0b00000011
#define EXTI_EDGE_FALLING_msk					0b00000010



#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"

#include "EXTI_hw.h"
#include "../../config/EXTI_cfg.h"
#include "EXTI_types.h"
#include "EXTI.h"
#include "../GLOBAL_INTERRUPT/Global_Int.h"


static Ptr2FuncType CallBackFunc_INT0,CallBackFunc_INT1,CallBackFunc_INT2;

void EXTI_init(void)
{
#if EXTI_ENABLE_INT0 == ENABLE
	MCUCR &= EXTI_EDGE_clr_msk_0;
	MCUCR |= EXTI_EDGE_SELECTOR_INT0_msk;
	EXTI_enInterrupt(EXTI_int0);
#endif

#if EXTI_ENABLE_INT1 == ENABLE
	MCUCR &= EXTI_EDGE_clr_msk_1;
	MCUCR |= (EXTI_EDGE_SELECTOR_INT1_msk<<2);
	EXTI_enInterrupt(EXTI_int1);
#endif

#if EXTI_ENABLE_INT2 == ENABLE
#if EXTI_ENABLE_INT2 == EXTI_EDGE_RISING_msk
	Set_Bit(MCUCSR,6);
#elif EXTI_ENABLE_INT2 == EXTI_EDGE_FALLING_msk
	Clr_Bit(MCUCSR,6);
#endif
	EXTI_enInterrupt(EXTI_int2);
#endif
}
void EXTI_disInterrupt(EXTI_IntType IntNum)
{
	switch (IntNum) {
	case EXTI_int0:
		Clr_Bit(GICR,6);
		break;
	case EXTI_int1:
		Clr_Bit(GICR,7);
		break;
	case EXTI_int2:
		Clr_Bit(GICR,5);
		break;
	default:

		break;
	}
}
void EXTI_enInterrupt(EXTI_IntType IntNum)
{
	switch (IntNum) {
	case EXTI_int0:
		Set_Bit(GICR,6);
		break;
	case EXTI_int1:
		Set_Bit(GICR,7);
		break;
	case EXTI_int2:
		Set_Bit(GICR,5);
		break;
	default:

		break;
	}

}
void EXTI_setCallBackFunc(EXTI_IntType IntNum, Ptr2FuncType FuncPtr)
{
	switch (IntNum) {
	case EXTI_int0:
		CallBackFunc_INT0 = FuncPtr;
		break;
	case EXTI_int1:
		CallBackFunc_INT1 = FuncPtr;
		break;
	case EXTI_int2:
		CallBackFunc_INT2 = FuncPtr;
		break;
	default:

		break;
	}

}
/*ISR for EXTI_INT0 */
void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	if(CallBackFunc_INT0 != 0)
	{
		CallBackFunc_INT0();
	}

}
/*ISR for EXTI_INT1 */
void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	if(CallBackFunc_INT1 != 0)
	{
		CallBackFunc_INT1();
	}

}
/*ISR for EXTI_INT2 */
void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	if(CallBackFunc_INT2 != 0)
	{
		CallBackFunc_INT2();
	}

}
