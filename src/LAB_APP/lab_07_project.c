/*
 * lab_07_project.c
 *
 *  Created on: Jul 19, 2019
 *      Author: Ahmed.Ali	Asmaa.Ahmed
 */
#define TASK_REFRESH_SEVSEGMENTS_ID					0
#define TASK_UPDATE_COUNTER_ID						1
#define	TASK_INPUT_PSW								2
#define KEYPAD_NOT_PRESSED							255
/*
 *
 *
 * */
#include "../utils/Std_Types.h"
#include "../utils/Bit_Math.h"

#include "../MCAL/GLOBAL_INTERRUPT/Global_Int.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER2/TIMER2.h"

#include "../EHAL/LCD/LCD.h"
#include "../EHAL/KP/KP.h"
#include "../EHAL/BcdSevSeg/BcdSevSeg.h"
#include "../utils/Interrupts.h"
#include "../Scheduler/Scheduler.h"


static uint8 DisplayedNum = 59;
void Task_refreshBcdSevSeg(void)
{
	/*periodic Task : 10ms*/
	static uint8 counter =0;
	counter++;
	if(counter == 1)
	{
		/*refresh sev segments 1*/
		BcdSevSeg_disable_2();
		BcdSevSeg_DisplayNum(DisplayedNum%10);
		BcdSevSeg_enable_1();

	}
	else if(counter == 2)
	{
		/*refresh sev segments 2*/
		BcdSevSeg_disable_1();
		BcdSevSeg_DisplayNum(DisplayedNum/10);
		BcdSevSeg_enable_2();
		counter=0;
	}
}


void Task_updateCounter(void)
{
	/*periodic Task : 1000ms and changable*/
	DisplayedNum--;
	if (DisplayedNum==0)
	{
		Dio_WriteChannel(Dio_Channel_D4,1);
		Scheduler_setSatus(TASK_UPDATE_COUNTER_ID,STD_suspended);
	}



}
void Task_InputPassword(void)
{
	/*periodic Task : 30ms*/

	uint8 CurrPressedButton;
	uint8 ErrorFlag=0;
	uint8 i;
	const uint8 arr_1[8]={'7','5','4','0','4','1','6','9'};

	static uint8 InputArrIndex;
	static uint8 InpuArr[8];
	static uint8 PrevPressed=KEYPAD_NOT_PRESSED;
	static uint32 CurrCounterTask_Periodicity = 100;


	CurrPressedButton = KP_getPressedSwitch();
	/*Check if any button has been pressed*/
	if(CurrPressedButton != KEYPAD_NOT_PRESSED)
	{
		if(PrevPressed == KEYPAD_NOT_PRESSED)
		{
			if(CurrPressedButton == '*' || InputArrIndex >= 8 )
			{
				/* match input with password */
				for(i=0;i<8;i++)
				{
					if(InpuArr[i] != arr_1[i])
					{
						ErrorFlag ++;
					}
				}

				if(ErrorFlag==0)
				{
					/*password is correct*/
					Scheduler_setSatus(TASK_UPDATE_COUNTER_ID,STD_suspended);
				}
				else
				{
					/*Wrong password*/
					LCD_writeCmd(0x01); /*clear LCD */
					InputArrIndex = 0;
					CurrCounterTask_Periodicity /= 2;
					Scheduler_setPeriodicity(TASK_UPDATE_COUNTER_ID,CurrCounterTask_Periodicity);
				}

			}
			else
			{
				InpuArr[InputArrIndex++]=CurrPressedButton;
				LCD_writeData(CurrPressedButton);
			}
		}
	}
	PrevPressed = CurrPressedButton;
}




void lab_07_project(void)
{
	PORT_init();
	KP_init();
	LCD_init();

	Scheduler_createTask(TASK_REFRESH_SEVSEGMENTS_ID,Task_refreshBcdSevSeg,1,STD_active );
	Scheduler_createTask(TASK_UPDATE_COUNTER_ID,Task_updateCounter,100,STD_active );
	Scheduler_createTask(TASK_INPUT_PSW,Task_InputPassword,3,STD_active );
	Scheduler_init();

	while(1)
	{



	}



}
