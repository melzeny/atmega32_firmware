/*
 * LCD.c
 *
 *  Created on: Jul 5, 2019
 *      Author: John Medhat _ Mostafa Serag
 */

/********************************************/
/*			Local Defines					*/
/********************************************/
#define LCD_MODE_4_PIN		0
#define LCD_MODE_8_PIN		1
/********************************************/
/*			INCLUDES						*/
/********************************************/
#include "../../utils/Bit_Math.h"
#include "../../utils/Std_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../config/LCD_cfg.h"
#include "LCD.h"
#include <util/delay.h>
/********************************************/
/*			Local Functions ProtoTypes		*/
/********************************************/
inline static void LCD_writePort(uint8 PortData);
/*******************************************/
/*			 Functions Definitions	 		*/
/*******************************************/
void LCD_init(void)
{
	_delay_ms(15);
#if LCD_MODE_PIN == LCD_MODE_8_PIN
	LCD_writeCmd(0x38);


#elif LCD_MODE_PIN == LCD_MODE_4_PIN
	LCD_writeCmd(0x23);
	LCD_writeCmd(0x22);
	LCD_writeCmd(0x28);
#endif
	LCD_writeCmd(0x0E);
	LCD_writeCmd(0x01);	/*LCD clear*/
	_delay_ms(3);
}
void LCD_writeData(uint8 Data)
{
	/*write RS = 1*/
	Dio_WriteChannel(LCD_PIN_RS,STD_high);

	/*write RW = 0*/
	Dio_WriteChannel(LCD_PIN_RW,STD_low);
	LCD_writePort(Data);
}

void LCD_writeCmd(uint8 Cmd)
{
	/*write RS = 0*/
	Dio_WriteChannel(LCD_PIN_RS,STD_low);

	/*write RW = 0*/
	Dio_WriteChannel(LCD_PIN_RW,STD_low);

	LCD_writePort(Cmd);
	_delay_us(100);
}
inline static void LCD_writePort(uint8 PortData)
{
#if LCD_MODE_PIN == LCD_MODE_8_PIN
	Dio_WriteChannel(LCD_PIN_D0,Get_Bit(PortData,0));
	Dio_WriteChannel(LCD_PIN_D1,Get_Bit(PortData,1));
	Dio_WriteChannel(LCD_PIN_D2,Get_Bit(PortData,2));
	Dio_WriteChannel(LCD_PIN_D3,Get_Bit(PortData,3));
	Dio_WriteChannel(LCD_PIN_D4,Get_Bit(PortData,4));
	Dio_WriteChannel(LCD_PIN_D5,Get_Bit(PortData,5));
	Dio_WriteChannel(LCD_PIN_D6,Get_Bit(PortData,6));
	Dio_WriteChannel(LCD_PIN_D7,Get_Bit(PortData,7));
#elif LCD_MODE_PIN == LCD_MODE_4_PIN
	Dio_WriteChannel(LCD_PIN_D4,Get_Bit(PortData,4));
	Dio_WriteChannel(LCD_PIN_D5,Get_Bit(PortData,5));
	Dio_WriteChannel(LCD_PIN_D6,Get_Bit(PortData,6));
	Dio_WriteChannel(LCD_PIN_D7,Get_Bit(PortData,7));

	/*latch Enable PIn*/
	Dio_WriteChannel(LCD_PIN_EN,STD_high);
	_delay_us(2);
	Dio_WriteChannel(LCD_PIN_EN,STD_low);

	Dio_WriteChannel(LCD_PIN_D4,Get_Bit(PortData,0));
	Dio_WriteChannel(LCD_PIN_D5,Get_Bit(PortData,1));
	Dio_WriteChannel(LCD_PIN_D6,Get_Bit(PortData,2));
	Dio_WriteChannel(LCD_PIN_D7,Get_Bit(PortData,3));

#endif
	/*latch Enable PIn*/
	Dio_WriteChannel(LCD_PIN_EN,STD_high);
	_delay_us(2);
	Dio_WriteChannel(LCD_PIN_EN,STD_low);
}
void LCD_writeString(uint8* str, uint8 row, uint8 col)
{
	uint8 i=0;
	LCD_goTo(row, col);
	while(str[i] != '\0' && i < 32)
	{
		if(i==16){LCD_goTo(1,0);}
		LCD_writeData(str[i]);
		i++;
	}
}
void LCD_goTo( uint8 row, uint8 col)
{
	/*Ac -> DDRAM[row][col]*/
	/* LCD_writeCmd( 0x80 | col | (row<<6) ); */
	LCD_writeCmd( 0x80 + col + row*(0x40));
}
void LCD_storeCustomChar(uint8* CustomChar, uint8 Index)
{
	uint8 i;
	uint8 CGRamAddr = Index *8;
	LCD_writeCmd(0x40 | CGRamAddr);
	for(i=0;i<8;i++)
	{
		LCD_writeData(CustomChar[i]);
	}
	/*Return Home*/
	LCD_writeCmd(0x02);

}
void LCD_displayCustomChar(uint8 index,uint8 row, uint8 col)
{
	LCD_goTo(row, col);
	LCD_writeData(index);
}
