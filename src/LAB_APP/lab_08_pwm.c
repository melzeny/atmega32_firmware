/*
 * lab_08_pwm.c
 *
 *  Created on: Jul 20, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../MCAL/TIMER2/TIMER2.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/GLOBAL_INTERRUPT/Global_Int.h"
#include "../utils/Interrupts.h"


void lab_08_pwm(void)
{
	PORT_init();
	TIMER2_init();
	GI_en();

	while(1)
	{

	}

}
/*
 * 200us on
 * 500us off
 * */
/*ISR periodic: 100us*/
void ISR(TIMER2_COMP)
{
	Dio_FlipChannel(Dio_Channel_A1);
	static uint8 counter = 1;
	if(counter == 1)
	{
		Dio_WriteChannel(Dio_Channel_A0,STD_high);
	}
	else if(counter == 3)
	{
		Dio_WriteChannel(Dio_Channel_A0,STD_low);
	}
	else if(counter == 7)
	{
		counter=0;
	}
		counter++;
}
