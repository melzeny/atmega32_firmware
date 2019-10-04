/*
 * TIMER1.c
 *
 *  Created on: Jul 20, 2019
 *      Author: Muhammad.Elzeiny
 */
/*==============================================================
 * DEFINES
==============================================================*/
#define TIMER1_MODE_NORAMAL 							0

#define TIMER1_MODE_PHASE_CORRECT_8                     1
#define TIMER1_MODE_PHASE_CORRECT_9                     2
#define TIMER1_MODE_PHASE_CORRECT_10                    3
#define TIMER1_MODE_PHASE_CORRECT_TOP_ICR1              4
#define TIMER1_MODE_PHASE_CORRECT_TOP_OCR1A             5

#define TIMER1_MODE_FAST_PWM_8                          6
#define TIMER1_MODE_FAST_PWM_9                          7
#define TIMER1_MODE_FAST_PWM_10                         8
#define TIMER1_MODE_FAST_PWM_TOP_ICR1                   9
#define TIMER1_MODE_FAST_PWM_TOP_OCR1A                  10

#define TIMER1_MODE_FREQ_PHASE_CORRECT_TOP_ICR          11
#define TIMER1_MODE_FREQ_PHASE_CORRECT_TOP_OCR1A        12

#define TIMER1_MODE_CTC_TOP_OCR1A                       13
#define TIMER1_MODE_CTC_TOP_ICR1                        14

#define TIMER1_OCU_OPERATION_DISCONNECTED				0
#define TIMER1_OCU_OPERATION_TOGGLE       				1
#define TIMER1_OCU_OPERATION_CLEAR        				2
#define TIMER1_OCU_OPERATION_SET          				3

#define TIMER1_ICU_EDGE_RISING							1
#define TIMER1_ICU_EDGE_FALLING							0

#define TIMER1_PRESCALER_clr_msk				0b11111000
#define TIMER1_PRESCALER_1_msk  				0b00000001
#define TIMER1_PRESCALER_8_msk   				0b00000010
#define TIMER1_PRESCALER_64_msk  				0b00000011
#define TIMER1_PRESCALER_256_msk 				0b00000100
#define TIMER1_PRESCALER_1024_msk				0b00000101


/*==============================================================
 * INCLUDES
 ============================================================== */
#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../utils/Interrupts.h"

#include "TIMER1_hw.h"
#include "Timer1_types.h"
#include "../../config/TIMER1_cfg.h"
#include "TIMER1.h"

/*=============================================================
 * STATIC GLOBAL VARIABLES
 *============================================================*/
static uint16 Ton_steps,Tpwm_steps;
static uint32 TIMER1_Freq_Hz=0;
static uint8  TIMER1_DutyCycle=0;
/*==============================================================
 * FUNCTION DEFINATIONS
==============================================================*/
void TIMER1_init(void)
{
	/* set mode - TCCR1A */
#if TIMER1_MODE_SELECTOR == TIMER1_MODE_NORAMAL
	Clr_Bit(TCCR1A,0);
	Clr_Bit(TCCR1A,1);
	Clr_Bit(TCCR1B,3);
	Clr_Bit(TCCR1B,4);
#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_PHASE_CORRECT_8
#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_PHASE_CORRECT_9
#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_PHASE_CORRECT_10
#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_PHASE_CORRECT_TOP_ICR1
#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_PHASE_CORRECT_TOP_OCR1A

#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_FAST_PWM_8
#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_FAST_PWM_9
#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_FAST_PWM_10
#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_FAST_PWM_TOP_ICR1
#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_FAST_PWM_TOP_OCR1A

#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_FREQ_PHASE_CORRECT_TOP_ICR
#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_FREQ_PHASE_CORRECT_TOP_OCR1A

#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_CTC_TOP_OCR1A
	Clr_Bit(TCCR1A,0);
	Clr_Bit(TCCR1A,1);
	Set_Bit(TCCR1B,3);
	Clr_Bit(TCCR1B,4);
#elif TIMER1_MODE_SELECTOR == TIMER1_MODE_CTC_TOP_ICR1
	Clr_Bit(TCCR1A,0);
	Clr_Bit(TCCR1A,1);
	Set_Bit(TCCR1B,3);
	Set_Bit(TCCR1B,4);
#endif
	/*set OCU - TCCR1A*/
#if TIMER1_OCU_A_OPERATION_SELECTOR == TIMER1_OCU_OPERATION_DISCONNECTED
	Clr_Bit(TCCR1A,6);
	Clr_Bit(TCCR1A,7);
#elif TIMER1_OCU_A_OPERATION_SELECTOR == TIMER1_OCU_OPERATION_TOGGLE
	Set_Bit(TCCR1A,6);
	Clr_Bit(TCCR1A,7);
#elif TIMER1_OCU_A_OPERATION_SELECTOR == TIMER1_OCU_OPERATION_CLEAR
	Clr_Bit(TCCR1A,6);
	Set_Bit(TCCR1A,7);
#elif TIMER1_OCU_A_OPERATION_SELECTOR == TIMER1_OCU_OPERATION_SET
	Set_Bit(TCCR1A,6);
	Set_Bit(TCCR1A,7);
#endif

#if TIMER1_OCU_B_OPERATION_SELECTOR == TIMER1_OCU_OPERATION_DISCONNECTED
	Clr_Bit(TCCR1A,4);
	Clr_Bit(TCCR1A,5);
#elif TIMER1_OCU_B_OPERATION_SELECTOR == TIMER1_OCU_OPERATION_TOGGLE
	Set_Bit(TCCR1A,4);
	Clr_Bit(TCCR1A,5);
#elif TIMER1_OCU_B_OPERATION_SELECTOR == TIMER1_OCU_OPERATION_CLEAR
	Clr_Bit(TCCR1A,4);
	Set_Bit(TCCR1A,5);
#elif TIMER1_OCU_B_OPERATION_SELECTOR == TIMER1_OCU_OPERATION_SET
	Set_Bit(TCCR1A,4);
	Set_Bit(TCCR1A,5);
#endif

	/*set noise cancellation for ICU config*/
	TCCR1B |= TIMER1_NOISE_CANCEL_EN<<7;

	/*set ICU Edge */
	TCCR1B |= TIMER1_ICU_EDGE_SELECTOR<<6;

	/*set steps to A and B compare register */
	OCR1A = TIMER1_STEPS_COMPA;
	OCR1B = TIMER1_STEPS_COMPB;

	/*set Prescaler */
	TCCR1B &= TIMER1_PRESCALER_clr_msk;
	TCCR1B |= TIMER1_PRESCALER_SELECTOR;
}
void TIMER1_enInterrupt(TIMER1_IntType Int)
{
	switch (Int) {
	case TIMER1_INT_OVF:
		Set_Bit(TIMSK,2);
		break;
	case TIMER1_INT_COMPA:
		Set_Bit(TIMSK,4);
		break;
	case TIMER1_INT_COMPB:
		Set_Bit(TIMSK,3);
		break;
	case TIMER1_INT_ICU:
		Set_Bit(TIMSK,5);
		break;
	default:
		break;
	}
}
void TIMER1_diInterrupt(TIMER1_IntType Int)
{
	switch (Int) {
	case TIMER1_INT_OVF:
		Clr_Bit(TIMSK,2);
		break;
	case TIMER1_INT_COMPA:
		Clr_Bit(TIMSK,4);
		break;
	case TIMER1_INT_COMPB:
		Clr_Bit(TIMSK,3);
		break;
	case TIMER1_INT_ICU:
		Clr_Bit(TIMSK,5);
		break;
	default:
		break;
	}
}
void TIMER1_setCompareSteps(uint16 COMPA,uint16 COMPB)
{
	OCR1A = COMPA;
	OCR1B = COMPB;

}
void TIMER1_ReadPwm(uint32* Freq_hz_Ptr, uint8* DutyCyclePtr)
{
	*Freq_hz_Ptr = TIMER1_Freq_Hz;
	*DutyCyclePtr = TIMER1_DutyCycle ;
}
uint32 TIMER1_getHiLevelTime(void)
{
	return (Ton_steps*TIMER1_SINGLE_STEP_TIME_us);
}

void ISR(TIMER1_CAPT)
{
	static uint8 flag =0;
	if(flag == 0)
	{
		TCNT1 = 0; /*t0_steps = 0*/
		Clr_Bit(TCCR1B,6); /*set next edge to be Falling Edge */
		flag = 1;
	}
	else if(flag == 1)
	{
		Ton_steps = ICR;
		Set_Bit(TCCR1B,6); /* set next edge to be Rising Edge */
		flag = 2;
	}
	else if(flag == 2)
	{
		Tpwm_steps = ICR;
		 /* keep next edge to be Rising Edge */
		flag = 0;

		/*calc*/
		TIMER1_Freq_Hz = 1000000 /( Tpwm_steps * TIMER1_SINGLE_STEP_TIME_us);
		TIMER1_DutyCycle = 100 * (Ton_steps / Tpwm_steps) ;
	}

}

