/*
 * TIMER2.c
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */
/*
 * =============================================
 * Private Defines
 * ============================================*/
#define TIMER2_PRESCALER_CLR_msk		0b11111000
#define TIMER2_PRESCALER_1_msk			0b00000001
#define TIMER2_PRESCALER_8_msk			0b00000010
#define TIMER2_PRESCALER_32_msk			0b00000011
#define TIMER2_PRESCALER_64_msk			0b00000100
#define TIMER2_PRESCALER_128_msk		0b00000101
#define TIMER2_PRESCALER_256_msk		0b00000110
#define TIMER2_PRESCALER_1024_msk		0b00000111

#define TIMER2_MODE_CLR_msk				0b10110111
#define TIMER2_MODE_NORMAL_msk			0b00000000
#define TIMER2_MODE_PHASE_CORRECT_msk	0b01000000
#define TIMER2_MODE_CTC_msk				0b00001000
#define TIMER2_MODE_FAST_PWM_msk		0b01001000

#define TIMER2_NON_PWM_OC2_clr_msk		0b11001111
#define TIMER2_NON_PWM_OC2_DISBALE 		0b00000000
#define TIMER2_NON_PWM_OC2_TOGGLE  		0b00010000
#define TIMER2_NON_PWM_OC2_CLR     		0b00100000
#define TIMER2_NON_PWM_OC2_SET     		0b00110000

#define TIMER2_PWM_OC2_clr_msk			0b11001111
#define TIMER2_PWM_OC2_DISBALE			0b00000000
#define TIMER2_PWM_OC2_NON_INVERTING	0b00100000
#define TIMER2_PWM_OC2_INVERTING		0b00110000

#define TIMER2_OCU_MODE_clr_msk					0b11001111
#define TIMER2_OCU_MODE_DISCONNECTED_msk		0b00000000
#define TIMER2_OCU_MODE_INVERTING_msk			0b00110000
#define TIMER2_OCU_MODE_NONINVERTING_msk		0b00100000

/* =============================================
 * INCLUDES
 * ============================================*/
#include "../../utils/Bit_Math.h"
#include "../../utils/Std_Types.h"
#include "../../config/TIMER2_cfg.h"
#include "TIMER2_hw.h"
#include "TIMER2.h"

/* =============================================
 * FUNCTIONS DEFINITIONS
 * ============================================*/
void TIMER2_init(void)
{

	/*set Pre-scaler*/
	TCCR2 &= TIMER2_PRESCALER_CLR_msk;
	TCCR2 |= TIMER2_PRESCALER_SELECTOR_msk;

	/* set timer mode */
	TCCR2 &= TIMER2_MODE_CLR_msk;
	TCCR2 |= TIMER2_MODE_TYPE_SELECTOR_msk;

	/*set OCU mode */
	TCCR2 &= TIMER2_OCU_MODE_clr_msk;
	TCCR2 |= TIMER2_OCU_MODE_SELECTOR;

	/*set Steps to count */
	TIMER2_setCounterSteps(TIMER2_STEPS_TO_COUNT);

	/*enable Interrupt */
	TIMER2_enInterrupt();

}

void TIMER2_enInterrupt(void)
{
#if TIMER2_MODE_TYPE_SELECTOR_msk == TIMER2_MODE_CTC_msk
	Set_Bit(TIMSK,7);
#elif TIMER2_MODE_TYPE_SELECTOR_msk == TIMER2_MODE_NORMAL_msk
	Set_Bit(TIMSK,6);
#endif
}
void TIMER2_diInterrupt(void)
{
#if TIMER2_MODE_TYPE_SELECTOR_msk == TIMER2_MODE_CTC_msk
	Clr_Bit(TIMSK,7);
#elif TIMER2_MODE_TYPE_SELECTOR_msk == TIMER2_MODE_NORMAL_msk
	Clr_Bit(TIMSK,6);
#endif
}
void TIMER2_setCounterSteps(uint8 StepsToCount)
{
#if (TIMER2_MODE_TYPE_SELECTOR_msk == TIMER2_MODE_CTC_msk)				 || \
		(TIMER2_MODE_TYPE_SELECTOR_msk == TIMER2_MODE_PHASE_CORRECT_msk) || \
		(TIMER2_MODE_TYPE_SELECTOR_msk == TIMER2_MODE_FAST_PWM_msk)
	OCR2 = StepsToCount;
	TCNT2 = 0x00 ;
#elif TIMER2_MODE_TYPE_SELECTOR_msk == TIMER2_MODE_NORMAL_msk
	TCNT2 = 255 - StepsToCount;
#endif
}
uint8 TIMER2_readCounterSteps(void)
{
	return TCNT2;
}
