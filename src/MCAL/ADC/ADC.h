/*
 * ADC.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_ADC_ADC_H_
#define F15_REPO_SRC_MCAL_ADC_ADC_H_

#include "../../utils/Std_Types.h"
#include "ADC_types.h"

void ADC_init(void);
void ADC_startConversion(ADC_ChannelType Channel);
uint16 ADC_getVoltage_mv(void);
void ADC_enInterrupt(void);
void ADC_diInterrupt(void);

#endif /* F15_REPO_SRC_MCAL_ADC_ADC_H_ */
