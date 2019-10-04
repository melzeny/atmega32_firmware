/*
 * lab_10_PwmMeter.c
 *
 *  Created on: Jul 27, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../utils/Std_Types.h"
#include "../utils/Bit_Math.h"

#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/TIMER1/TIMER1.h"
#include "../MCAL/GLOBAL_INTERRUPT/Global_Int.h"

#include "../EHAL/LCD/LCD.h"
#include "../Scheduler/Scheduler.h"
#include <stdlib.h>

void UpdatePwmMeter_Task(void)
{
	/* periodic Task ever 300ms */
	uint32 Freq;
	uint8 DutyCycle;
	uint8 Buff[8];

	TIMER1_ReadPwm(&Freq, &DutyCycle);
	utoa(Freq,Buff,10);

	LCD_writeCmd(LCD_CMD_CLEAR);
	LCD_writeString("Freq = ",0,0);
	LCD_writeString("DutCyc=",1,0);

	LCD_writeString(Buff,0,10);
	utoa(DutyCycle,Buff,10);
	LCD_writeString(Buff,1,10);
}

void lab_10_PwmMeter(void)
{
	PORT_init();
	LCD_init();
	TIMER1_enInterrupt(TIMER1_INT_ICU);
	GI_en();
	TIMER1_init();

	Scheduler_createTask(1,UpdatePwmMeter_Task,30,STD_active);
	Scheduler_init();

	while(1)
	{
		;
	}


}
