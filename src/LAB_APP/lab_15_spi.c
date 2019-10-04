/*
 * lab_15_spi.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../utils/Std_Types.h"
#include "../MCAL/GLOBAL_INTERRUPT/Global_Int.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/SPI/SPI.h"
#include "../Scheduler/Scheduler.h"
#include "../EHAL/LCD/LCD.h"

void Master_Task(void)
{
	uint8 i,arrSize;
	uint8 arr[]="From Master...";
	arrSize = (sizeof(arr)/sizeof(arr[0]));

	for (i = 0; i < arrSize; ++i)
	{
		SPI_startTransmission(arr[i]);
	}

}
void Slave_Task(void)
{
	uint8 i, TempArr[50]={0}, MsgLen = 0;

	SPI_getReceiveMsg(TempArr,&MsgLen);
	for (i = 0; i < MsgLen; ++i)
	{
		LCD_writeData(TempArr[i]);
	}
}
void lab_15_spi(void)
{
	PORT_init();
	LCD_init();
	SPI_init();
	Scheduler_createTask(0,Master_Task,20,STD_active);
	Scheduler_init();
	GI_en();

	while(1)
	{
		;
	}

}
