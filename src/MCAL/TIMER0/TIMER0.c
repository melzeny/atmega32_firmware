/*
 * TIMER0.c
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#define TIMER0_MODE_CTC             			100
#define TIMER0_MODE_NORMAL          			101
#define TIMER0_MODE_FAST_PWM        			102
#define TIMER0_MODE_PHASE_CORRECTION			103

#define TIMER0_PRESCALER_clr_msk				0b11111000
#define TIMER0_PRESCALER_1_msk  				0b00000001
#define TIMER0_PRESCALER_8_msk   				0b00000010
#define TIMER0_PRESCALER_64_msk  				0b00000011
#define TIMER0_PRESCALER_256_msk 				0b00000100
#define TIMER0_PRESCALER_1024_msk				0b00000101

#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"

#include "../../config/TIMER0_cfg.h"
#include "TIMER0_hw.h"
#include "TIMER0.h"

void TIMER0_init(void)
{
	/* set mode */
#if TIMER0_MODE_SELECTOR == TIMER0_MODE_CTC

	Clr_Bit(TCCR0,6);
	Set_Bit(TCCR0,3);
	/*set steps to count */
	OCR0 = TIMER0_STEPS_TO_COUNT;

#elif TIMER0_MODE_SELECTOR == TIMER0_MODE_NORMAL
	Clr_Bit(TCCR0,6);
	Clr_Bit(TCCR0,3);
	/*set steps to count */
	TCNT0 = 255 - TIMER0_STEPS_TO_COUNT;
#endif
	/*enable interrupt*/
	TIMER0_enInterrupt();

	/*set prescaler*/
	TCCR0 &= TIMER0_PRESCALER_clr_msk;
	TCCR0 |= TIMER0_PRESCALER_SELECTOR_msk;
}
void TIMER0_enInterrupt(void)
{
#if TIMER0_MODE_SELECTOR == TIMER0_MODE_CTC
	Set_Bit(TIMSK,1);
#elif TIMER0_MODE_SELECTOR == TIMER0_MODE_NORMAL
	Set_Bit(TIMSK,0);
#endif

}
void TIMER0_disInterrupt(void)
{
#if TIMER0_MODE_SELECTOR == TIMER0_MODE_CTC
	Clr_Bit(TIMSK,1);
#elif TIMER0_MODE_SELECTOR == TIMER0_MODE_NORMAL
	Clr_Bit(TIMSK,0);
#endif
}

