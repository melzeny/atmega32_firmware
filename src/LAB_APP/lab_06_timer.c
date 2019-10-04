/*
 * lab_06_timer.c
 *
 *  Created on: Jul 13, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../utils/Std_Types.h"
#include "../utils/Bit_Math.h"

#include "../MCAL/GLOBAL_INTERRUPT/Global_Int.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER2/TIMER2.h"

#include "../EHAL/LCD/LCD.h"
#include "../EHAL/KP/KP.h"
#include "../EHAL/BcdSevSeg/BcdSevSeg.h"
#include "../utils/Interrupts.h"

void lab_06_timer(void)
{
	uint8 CurrPressedButton;
	uint8 PrevPressed;

	PORT_init();
	KP_init();
	LCD_init();
	GI_en();
	TIMER2_init();
	while(1)
	{
		CurrPressedButton = KP_getPressedSwitch();
		/*Check if any button has been pressed*/
		if(CurrPressedButton != 255)
		{
			if(PrevPressed == 255)
			{
				LCD_writeData(CurrPressedButton);
			}
		}
		PrevPressed = CurrPressedButton;
	}
}
#if 0
void ISR(TIMER2_COMP)
{
	static uint8 counter =0;
	static uint8 DisplayedNum = 0;
	static uint16 DisplayedNum_Counter=0;
	counter++;
	DisplayedNum_Counter++;
	if(counter == 1)
	{
		BcdSevSeg_disable_2();
		BcdSevSeg_DisplayNum(DisplayedNum%10);
		BcdSevSeg_enable_1();

	}
	else if(counter == 2)
	{
		BcdSevSeg_disable_1();
		BcdSevSeg_DisplayNum(DisplayedNum/10);
		BcdSevSeg_enable_2();
		counter=0;
	}
	if(DisplayedNum_Counter == 100)
	{
		DisplayedNum++;
		DisplayedNum_Counter=0;
	}

}
#endif
