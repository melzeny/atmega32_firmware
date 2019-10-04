/*
 * lab_05_exti.c
 *
 *  Created on: Jul 12, 2019
 *      Author: Muhammad.Elzeiny
 */
/*
 * 1-toggle led
 * 2- step down counter
 * */
#include "../MCAL/GLOBAL_INTERRUPT/Global_Int.h"
#include "../MCAL/EXTI/EXTI.h"
#include "../MCAL/DIO/DIO.h"

static void Task_1(void)
{
	Dio_FlipChannel(Dio_Channel_D7);

}
void lab_05_exti(void)
{
	GI_en();
	EXTI_setCallBackFunc(EXTI_int0,&Task_1);
	EXTI_init();

	while(1)
	{

	}



}
