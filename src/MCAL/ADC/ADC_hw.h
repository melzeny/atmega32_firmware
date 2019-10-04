/*
 * ADC_hw.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_ADC_ADC_HW_H_
#define F15_REPO_SRC_MCAL_ADC_ADC_HW_H_

#define ADMUX				*((uint8*)0x27)
#define ADCSRA				*((uint8*)0x26)
#define SFIOR				*((uint8*)0x50)
#define ADCLH				*((uint16*)0x24)

#endif /* F15_REPO_SRC_MCAL_ADC_ADC_HW_H_ */
