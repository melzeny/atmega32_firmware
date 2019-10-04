/*
 * SevSeg_cfg.h
 *
 *  Created on: Jun 29, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_CONFIG_SEVSEG_CFG_H_
#define F15_REPO_SRC_CONFIG_SEVSEG_CFG_H_

#include "../MCAL/DIO/DIO_types.h"

/* configuration */
#define SevSeg_PIN_a		Dio_Channel_C0
#define SevSeg_PIN_b		Dio_Channel_C1
#define SevSeg_PIN_c		Dio_Channel_C2
#define SevSeg_PIN_d		Dio_Channel_C3
#define SevSeg_PIN_e		Dio_Channel_C4
#define SevSeg_PIN_f		Dio_Channel_C5
#define SevSeg_PIN_g		Dio_Channel_C6

#define SevSeg_PIN_EN_1		Dio_Channel_D0
#define SevSeg_PIN_EN_2		Dio_Channel_D1


/*
 * define Common Type with the following options
 * SevSeg_COMMON_CATHOD
 * SevSeg_COMMON_ANOD
 * */
#define SevSeg_COMMON_TYPE	SEvSeg_COMMON_CATHOD



#endif /* F15_REPO_SRC_CONFIG_SEVSEG_CFG_H_ */
