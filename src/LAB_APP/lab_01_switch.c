/*
 * lab_01_switch.c
 *
 *  Created on: Jul 7, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../MCAL/DIO/DIO.h"
#include "../EHAL/Switch/Switch.h"
#include "../MCAL/PORT_DRIVER/PORT.h"

void lab_01_switch(void)
{
	PORT_init();
	while(1)
	{
		if(SW_getSwitchStatus(SW_Name_0) == SW_Status_Pressed)
		{
			Dio_WriteChannel(Dio_Channel_D0,STD_high);
		}
		else
		{
			Dio_WriteChannel(Dio_Channel_D0,STD_low);
		}

		if(SW_getSwitchStatus(SW_Name_4) == SW_Status_Pressed)
		{
			Dio_WriteChannel(Dio_Channel_D4,STD_high);
		}
		else
		{
			Dio_WriteChannel(Dio_Channel_D4,STD_low);
		}

	}

}
