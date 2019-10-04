/*
 * LCD_cfg.h
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_CONFIG_LCD_CFG_H_
#define F15_REPO_SRC_CONFIG_LCD_CFG_H_


/*
 * choose between
 * LCD_MODE_4_PIN
 * LCD_MODE_8_PIN
 * */
#define LCD_MODE_PIN		LCD_MODE_4_PIN

#define LCD_PIN_D0			Dio_Channel_A0
#define LCD_PIN_D1			Dio_Channel_A1
#define LCD_PIN_D2			Dio_Channel_A2
#define LCD_PIN_D3			Dio_Channel_A3
#define LCD_PIN_D4			Dio_Channel_A4
#define LCD_PIN_D5			Dio_Channel_A5
#define LCD_PIN_D6			Dio_Channel_A6
#define LCD_PIN_D7			Dio_Channel_A7

#define LCD_PIN_RS			Dio_Channel_B1
#define LCD_PIN_RW			Dio_Channel_B2
#define LCD_PIN_EN			Dio_Channel_B3

#endif /* F15_REPO_SRC_CONFIG_LCD_CFG_H_ */
