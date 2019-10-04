/*
 * LCD.h
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_EHAL_LCD_LCD_H_
#define F15_REPO_SRC_EHAL_LCD_LCD_H_
#include "../../utils/Std_Types.h"

#define LCD_CMD_CLEAR				0x01
void LCD_init(void);
void LCD_writeData(uint8 Data);
void LCD_writeCmd(uint8 Cmd);
void LCD_goTo( uint8 row, uint8 col);
void LCD_storeCustomChar(uint8* CustomChar, uint8 Index);
void LCD_displayCustomChar(uint8 index,uint8 row, uint8 col);
void LCD_writeString(uint8* str, uint8 row, uint8 col);

#endif /* F15_REPO_SRC_EHAL_LCD_LCD_H_ */
