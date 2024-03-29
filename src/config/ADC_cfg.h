/*
 * ADC_cfg.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_CONFIG_ADC_CFG_H_
#define F15_REPO_SRC_CONFIG_ADC_CFG_H_

/*
 * Please choose voltage refrence from followings:
 * ADC_VOLTAGE_REF_AVCC
 * ADC_VOLTAGE_REF_AREF
 * ADC_VOLTAGE_REF_2_56v
 * */
#define ADC_VOLTAGE_REF_SELECTOR_msk			ADC_VOLTAGE_REF_AVCC

#define ADC_VOLTAGE_REF_mv						5000
#define ADC_MAX_NUMBER_OF_STEPS					1024
/*choose adc mode from followings
 * ADC_MODE_AUTO_TRIGGER
 * ADC_MODE_SINGLE_CONVERSION
 *
 * */
#define ADC_MODE_SELECTOR						ADC_MODE_AUTO_TRIGGER

/*
 * Choose ADC prescaler from followings
 *	ADC_PRESCALER_2_msk
 * ADC_PRESCALER_4_msk
 * ADC_PRESCALER_8_msk
 * ADC_PRESCALER_16_msk
 * ADC_PRESCALER_32_msk
 * ADC_PRESCALER_64_msk
 * ADC_PRESCALER_128_msk
 * */
#define ADC_PRESCALER_SELECTOR_msk				ADC_PRESCALER_64_msk

/*
 * Choose trigger source from the followings
 *	ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk
 *  ADC_AUTO_TRIG_SRC_ANALOG_COMP_msk
 *  ADC_AUTO_TRIG_SRC_EXTI0_msk
 *  ADC_AUTO_TRIG_SRC_TIMER0_COMP_msk
 *  ADC_AUTO_TRIG_SRC_TIMER0_OVF_msk
 *  ADC_AUTO_TRIG_SRC_TIMER1_COMP_msk
 *  ADC_AUTO_TRIG_SRC_TIMER1_OVF_msk
 *  ADC_AUTO_TRIG_SRC_TIMER1_CAPT_msk
 *
 * */
#define ADC_AUTO_TRIG_SRCE_SELECTOR				ADC_AUTO_TRIG_SRC_FREE_RUNNING_msk

#endif /* F15_REPO_SRC_CONFIG_ADC_CFG_H_ */
