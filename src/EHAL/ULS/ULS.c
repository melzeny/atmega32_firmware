/*
 * ULS.c
 *
 *  Created on: Jul 27, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../../utils/Std_Types.h"

#include "../../MCAL/TIMER1/TIMER1.h"
#include "../../MCAL/GLOBAL_INTERRUPT/Global_Int.h"
#include "../../MCAL/PORT_DRIVER/PORT.h"
#include "../../MCAL/DIO/DIO.h"

#include "../../config/ULS_cfg.h"
#include "ULS.h"
#include "../../Scheduler/Scheduler.h"
#include <util/delay.h>

#define ULS_WAVE_SPEED_M_PER_S				340
#define ULS_S_TO_uS							1000000
#define ULS_M_TO_Cm							100

static void ULS_Trigger_task(void)
{
	Dio_WriteChannel(ULS_TRIGGER_PIN,STD_high);
	_delay_us(10);
	Dio_WriteChannel(ULS_TRIGGER_PIN,STD_low);

}
void ULS_init(void)
{
	GI_en();
	TIMER1_enInterrupt(TIMER1_INT_ICU);
	TIMER1_init();

	Scheduler_createTask(ULS_TRIGGER_TASK_INDEX,
			ULS_Trigger_task,
			ULS_TRIGGER_TASK_PERIODICITY,
			STD_active);

	Scheduler_init();

}
uint16 ULS_getDistance(void)
{
	uint16 Distance_cm;
	uint32 EchoHiLevel_Time_us;
	EchoHiLevel_Time_us = TIMER1_getHiLevelTime();
	/* Calculate Distance */
	Distance_cm = ((EchoHiLevel_Time_us * ULS_WAVE_SPEED_M_PER_S ) * ( ULS_M_TO_Cm / ULS_S_TO_uS)) /2;

	return Distance_cm;
}
