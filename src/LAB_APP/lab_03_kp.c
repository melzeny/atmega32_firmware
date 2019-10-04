/*
 * lab_03_kp.c
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../utils/Std_Types.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/DIO/DIO.h"
#include "../EHAL/SevSeg/SevSeg.h"
#include "../EHAL/KP/KP.h"
#include <util/delay.h>

void lab_03_kp(void)
{
	uint8 Num;

	PORT_init();
	KP_init();

	while(1)
	{
		Num = KP_getPressedSwitch();
		if(Num != 255)
		{
			SevSeg_disable_2();
			SevSeg_DisplayNum(Num%10);
			SevSeg_enable_1();
			_delay_ms(7);

			SevSeg_disable_1();
			SevSeg_DisplayNum(Num/10);
			SevSeg_enable_2();
			_delay_ms(7);
		}
		else
		{
			SevSeg_disable_1();
			SevSeg_disable_2();
		}
	}
}
