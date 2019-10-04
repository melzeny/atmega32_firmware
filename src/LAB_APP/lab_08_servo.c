/*
 * lab_08_servo.c
 *
 *  Created on: Jul 12, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../EHAL/Servo/Servo.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
#include <util/delay.h>
void lab_08_servo(void)
{
	uint8 i,flag;
	PORT_init();
	SERVO_setAngle(170);
	SERVO_init();

	while(1)
	{

		SERVO_setAngle(i);
		if(i==180)flag=0;
		else if (i==0)flag=1;
		if(flag)i++;
		else i--;
		_delay_ms(30);

	}

}
