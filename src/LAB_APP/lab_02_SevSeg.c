/*
 * lab_02_SevSeg.c
 *
 *  Created on: Jun 29, 2019
 *      Author: Muhammad.Elzeiny
 */
#include <util/delay.h>
#include "../EHAL/BcdSevSeg/BcdSevSeg.h"
#include "../MCAL/PORT_DRIVER/PORT.h"

void lab_02_SevSeg(void)
{
	uint8 counter,i;
	PORT_init();
	BcdSevSeg_DisplayNum(5);
	BcdSevSeg_enable_1();
	BcdSevSeg_enable_2();
	while(1)
	{
		for(counter =99;counter!=0;counter--)
		{
			for(i=0;i<50;i++)
			{
				BcdSevSeg_disable_2();
				BcdSevSeg_DisplayNum(counter%10);
				BcdSevSeg_enable_1();
				_delay_ms(7);

				BcdSevSeg_disable_1();
				BcdSevSeg_DisplayNum(counter/10);
				BcdSevSeg_enable_2();
				_delay_ms(7);
			}
		}
	}
}
