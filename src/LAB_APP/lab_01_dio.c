/*
 * lab_01_dio.c
 *
 *  Created on: Jun 28, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/DIO/DIO.h"

void lab_01_dio(void)
{
	STD_levelType CurrentStatus=STD_low,PrevStatus = STD_low;
	PORT_init();
	/*attach internal pull up resistor*/
	Dio_WriteChannel(Dio_Channel_A0,STD_high);
	while(1)
	{
		CurrentStatus = Dio_ReadChannel(Dio_Channel_D0);
		/*if switch pressed*/
		if(CurrentStatus == STD_high)
		{
			if(PrevStatus == STD_low)
			/*led on */
			{
				Dio_FlipChannel(Dio_Channel_D7);
			}
		}
		PrevStatus = CurrentStatus;
	}
}
