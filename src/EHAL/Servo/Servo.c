/*
 * Servo.c
 *
 *  Created on: Jul 12, 2019
 *      Author: Muhammad.Elzeiny
 */
/*give unique number to servo module to use Timer2 ISR */
#define ISR_USER_SERVO_DRIVER			337

#include "../../utils/STD_Types.h"
#include "../../utils/Interrupts.h"
#include "../../MCAL/GLOBAL_INTERRUPT/Global_Int.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER2/TIMER2.h"
#include "../../config/Servo_cfg.h"
#include "Servo.h"


static uint8 Ton_Steps=255,Toff_Steps=255;

void SERVO_init(void)
{
	GI_en();
	TIMER2_init();
}
void SERVO_setAngle(uint8 Angle)
{
	/*
	 * apply First Degree Linear equation
	 *
	 * x-x1   x2-x1
	 * ---- = ----
	 * y-y1   y2-y1
	 *
	 * assume x:Ton_Steps	x1:SERVO_MIN_ANGLE_STEPS	x2:SERVO_MAX_ANGLE_STEPS
	 *        y:Angle		y1:SERVO_MIN_ANGLE_DEGREE   y2:SERVO_MAX_ANGLE_DEGREE
	 * */
	Ton_Steps = (
				( (Angle - SERVO_MIN_ANGLE_DEGREE) * (SERVO_MAX_ANGLE_STEPS - SERVO_MIN_ANGLE_STEPS) )
			/*------------------------------------------------------------------------------------------*/
				/ ( SERVO_MAX_ANGLE_DEGREE - SERVO_MIN_ANGLE_DEGREE )
				)
				+   SERVO_MIN_ANGLE_STEPS;
	Toff_Steps = SERVO_PWM_SIGNAL_DUARTION_STEPS_DIV_BY_FACTOR - Ton_Steps/SERVO_PWM_SIGNAL_FACTOR;
}


#if (TIMER2_COMP_USER == ISR_USER_SERVO_DRIVER)
void ISR(TIMER2_COMP)
{
	static uint8 counter =0;
	if(counter == 0)
	{
		TIMER2_setCounterSteps((uint8)Toff_Steps);
		Dio_WriteChannel(SERVO_SIGNAL_PIN,STD_low);
		counter++;
	}
	else if (counter == SERVO_PWM_SIGNAL_FACTOR+1)
	{
		TIMER2_setCounterSteps((uint8)Ton_Steps);
		Dio_WriteChannel(SERVO_SIGNAL_PIN,STD_high);
		counter = 0;
	}
	else
	{
		counter++;
	}
}
#endif
