/*
 * lab_14_uart.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../utils/Std_Types.h"
#include "../MCAL/GLOBAL_INTERRUPT/Global_Int.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/UART/UART.h"
#include "../Scheduler/Scheduler.h"
#include "../EHAL/LCD/LCD.h"

void ReceiveTask(void)
{
	uint8 i, TempArr[50]={0}, MsgLen = 0;

	UART_getReceiveMsg(TempArr,&MsgLen);
	for (i = 0; i < MsgLen; ++i)
	{
		LCD_writeData(TempArr[i]);
	}
	UART_sendMsg("Ok..",4);

}
void lab_14_uart(void)
{
	PORT_init();
	LCD_init();
	UART_init();
	Scheduler_createTask(0,ReceiveTask,20,STD_active);
	Scheduler_init();
	GI_en();
	while(1)
	{



	}
}

