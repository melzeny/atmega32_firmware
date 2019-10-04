/*
 * ADC.c
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */
/*===========================================================*/
/* DEFINES													*/
/*=========================================================*/
#define ADC_VOLTAGE_REF_clr_msk						0b00111111
#define ADC_VOLTAGE_REF_AVCC						0b01000000
#define ADC_VOLTAGE_REF_AREF						0b00000000
#define ADC_VOLTAGE_REF_2_56v						0b11000000

#define ADC_MODE_AUTO_TRIGGER						1
#define ADC_MODE_SINGLE_CONVERSION					0

#define ADC_PRESCALER_clr_msk						0b11111000
#define ADC_PRESCALER_2_msk							0b00000000
#define ADC_PRESCALER_4_msk							0b00000010
#define ADC_PRESCALER_8_msk							0b00000011
#define ADC_PRESCALER_16_msk		   				0b00000100
#define ADC_PRESCALER_32_msk						0b00000101
#define ADC_PRESCALER_64_msk						0b00000110
#define ADC_PRESCALER_128_msk						0b00000111

#define ADC_AUTO_TRIG_SRC_clr_msk					0b00011111
#define ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk			0b00000000
#define ADC_AUTO_TRIG_SRC_ANALOG_COMP_msk			0b00100000
#define ADC_AUTO_TRIG_SRC_EXTI0_msk					0b01000000
#define ADC_AUTO_TRIG_SRC_TIMER0_COMP_msk			0b01100000
#define ADC_AUTO_TRIG_SRC_TIMER0_OVF_msk			0b10000000
#define ADC_AUTO_TRIG_SRC_TIMER1_COMP_msk			0b10100000
#define ADC_AUTO_TRIG_SRC_TIMER1_OVF_msk			0b11000000
#define ADC_AUTO_TRIG_SRC_TIMER1_CAPT_msk			0b11100000

#define ADC_CHANNEL_SELECTOR_clr_msk				0b11100000

/*===========================================================*/
/* INCLUDES													*/
/*=========================================================*/

#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/ADC_cfg.h"
#include "ADC_hw.h"
#include "ADC.h"

/*===========================================================*/
/* FUNCTION DEFINITIONS										*/
/*=========================================================*/
void ADC_init(void)
{
	/* select voltage reference*/
	ADMUX &= ADC_VOLTAGE_REF_clr_msk;
	ADMUX |= ADC_VOLTAGE_REF_SELECTOR_msk;

	/*select ADC mode */
#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
	Set_Bit(ADCSRA,5);
	/*select auto trigger source */
	SFIOR &= ADC_AUTO_TRIG_SRC_clr_msk;
	SFIOR |= ADC_AUTO_TRIG_SRCE_SELECTOR;

#elif ADC_MODE_SELECTOR = ADC_MODE_SINGLE_CONVERSION
	Clr_Bit(ADCSRA,5);
#endif

	/*Enable ADC */
	Set_Bit(ADCSRA,7);

}

void ADC_startConversion(ADC_ChannelType Channel)
{
	/*select ADC channel using MUX in ADMUX */
	ADMUX &= ADC_CHANNEL_SELECTOR_clr_msk;
	ADMUX |= Channel;

	/*start conversion using ADSC in ADCSRA */
	Set_Bit(ADCSRA,6);
}
uint16 ADC_getVoltage_mv(void)
{
	uint32 timeout = 1000;
	uint16 DigitalVal_steps = 0;
	uint16 Voltage_mv = 0;

	/*wait for ADIF to be set - conversion complete*/
	while( (Get_Bit(ADCSRA,4) == 0) && (timeout-- != 0) )
	{
		;
	}
	/*read ADCL and ADC H  */
	DigitalVal_steps = ADCLH;
	/* calculate Voltage_mv*/
	Voltage_mv = (DigitalVal_steps * ADC_VOLTAGE_REF_mv ) / ADC_MAX_NUMBER_OF_STEPS;
	/*return Voltage_mv*/
	return Voltage_mv;
}

void ADC_enInterrupt(void)
{
	/*set ADIE in ADCSRA */
	Set_Bit(ADCSRA,3);
}
void ADC_diInterrupt(void)
{
	/*clear ADIE in ADCSRA */
	Clr_Bit(ADCSRA,3);
}
