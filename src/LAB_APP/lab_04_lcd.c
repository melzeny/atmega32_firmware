/*
 * lab_04_lcd.c
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../utils/Std_Types.h"
#include "../EHAL/LCD/LCD.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
void lab_04_lcd(void)
{
	uint8 mArr[8]={0, 0, 15, 1, 15, 0, 0, 0};
	PORT_init();
	LCD_init();
	LCD_storeCustomChar(mArr,0);
	LCD_displayCustomChar(0,0,0);
	while(1)
	{


	}
}
