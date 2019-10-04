/*==========================================================
 * Configuration
 *==========================================================*/
#define MAX_NUMBER_OF_PSW				4
#define LOCK_TIME_OUT					10
/*==========================================================
 * DEFINES
 *==========================================================*/
#define TASK_INDEX_Bcd_SevSeg_Ref				0
#define TASK_INDEX_Bcd_SevSeg_Count				1
#define TASK_INDEX_Update_Canon					2
#define TASK_INDEX_Kp							3
#define TASK_INDEX_Upd_Distance					4
#define TASK_INDEX_Fire							5

#define BUZZER_PIN					Dio_Channel_D4
#define LED1_PIN					Dio_Channel_D5
#define LED2_PIN					Dio_Channel_D6
#define LED3_PIN					Dio_Channel_D7


/*
 *
 * INCLUDES
 *
 * */


#include "../MCAL/ADC/ADC.h"
#include "../MCAL/TIMER1/TIMER1.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/PORT_DRIVER/PORT.h"

#include "../EHAL/BcdSevSeg/BcdSevSeg.h"
#include "../EHAL/KP/KP.h"
#include "../EHAL/LCD/LCD.h"
#include "../EHAL/ULS/ULS.h"

#include "../Scheduler/Scheduler.h"
#include "../utils/Std_Types.h"
#include "../utils/Bit_Math.h"

#include <stdlib.h>
#include <util/delay.h>



#define KEYPAD_NOT_PRESSED							255

/*==========================================================
 * STATIC VARIABLES
 *==========================================================*/

static uint8 DisplayedNum = LOCK_TIME_OUT;
static const uint8 PSW_ARR[MAX_NUMBER_OF_PSW]={'7','5','3','6'};
static uint8 InputArrIndex=0;
static uint8 InpuArr[MAX_NUMBER_OF_PSW];

/**********************************************************************************/
/* FUNCTION DEFINITIONS
/**********************************************************************************/
static void Task_Bcd_SevSeg_Ref (void)
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
	else
	{
		/*refresh sev segments 2*/
		BcdSevSeg_disable_1();
		BcdSevSeg_DisplayNum(DisplayedNum/10);
		BcdSevSeg_enable_2();
		counter=0;
	}
}
/**********************************************************************************/

/**********************************************************************************/
static void Task_Bcd_SevSeg_Count(void)
{
	uint8 i;
	/*periodic Task : 1000ms and */
	DisplayedNum--;
	if(DisplayedNum==0)
	{
		/*Reset Displayed NUmber */
		DisplayedNum = LOCK_TIME_OUT;

		BcdSevSeg_disable_1();
		BcdSevSeg_disable_2();

		Scheduler_setSatus(TASK_INDEX_Bcd_SevSeg_Ref,STD_suspended);
		Scheduler_setSatus(TASK_INDEX_Bcd_SevSeg_Count,STD_suspended);
		Scheduler_setSatus(TASK_INDEX_Update_Canon,STD_active);


		LCD_writeString("                ",1,0);
		LCD_writeString("Target Unlocked",1,0);

		/*Reset Input Array */
		InputArrIndex = 0;
		for(i=0;i<MAX_NUMBER_OF_PSW;i++)InpuArr[i]=0;


	}
}
/**********************************************************************************/

/**********************************************************************************/
static void Task_Update_Canon(void)
{
	uint16 Voltage = 0;
	uint8 Angle=0;
	Voltage = ADC_getVoltage_mv();
	Angle=((Voltage*180)/5000);
	SERVO_setAngle(Angle);
}
/**********************************************************************************/

/**********************************************************************************/
void Task_Kp(void)
{
	/*periodic Task : 30ms*/

	uint8 CurrPressedButton,i,WrongPswFlag;
	static uint8 PrevPressed=KEYPAD_NOT_PRESSED;
	static LockFlag=0;

	CurrPressedButton = KP_getPressedSwitch();
	if(CurrPressedButton != KEYPAD_NOT_PRESSED)
	{
		if(PrevPressed == KEYPAD_NOT_PRESSED)
		{
			switch(CurrPressedButton)
			{
			case '#':
				/*lock Target*/
				LockFlag = 1;
				LCD_writeString("                ",1,0);
				LCD_writeString("Target locked",1,0);

				Scheduler_setSatus(TASK_INDEX_Bcd_SevSeg_Count,STD_active);
				Scheduler_setSatus(TASK_INDEX_Bcd_SevSeg_Ref,STD_active);
				Scheduler_setSatus(TASK_INDEX_Update_Canon,STD_suspended);
				break;
			case '*':
				/* fire */
				LockFlag=0;
				/* Check for Password */
				if(InputArrIndex == MAX_NUMBER_OF_PSW)
				{
					for(i=0;i<InputArrIndex;i++)
					{
						if(PSW_ARR[i] != InpuArr[i])
						{
							WrongPswFlag = 1;
							break;
						}
					}
					if(WrongPswFlag == 1)
					{
						/*return to unlock */
						LCD_writeString("                ",1,0);
						LCD_writeString("Target Unlocked",1,0);

						Scheduler_setSatus(TASK_INDEX_Bcd_SevSeg_Count,STD_suspended);
						Scheduler_setSatus(TASK_INDEX_Bcd_SevSeg_Ref,STD_suspended);
						Scheduler_setSatus(TASK_INDEX_Update_Canon,STD_active);
					}
					else
					{
						/*Firing state*/
						Scheduler_setSatus(TASK_INDEX_Fire,STD_active);

					}
				}

				break;
			default:
				/*ENter Password */
				if(LockFlag == 1)
				{
					InpuArr[InputArrIndex++]=CurrPressedButton;

				}
				break;
			}
		}
	}


	PrevPressed = CurrPressedButton;
}
/**********************************************************************************/

/**********************************************************************************/
static void Task_Upd_Distance(void)
{
	uint32 buff[8];
	itoa(ULS_getDistance(), buff , 10);
	LCD_writeString("                ",0,0);
	LCD_writeString("Dis = ",0,0);
	LCD_writeString(buff,0,8);
}
/**********************************************************************************/

/**********************************************************************************/
void Task_Fire(void)
{
	/* Periodicity : 1000ms */
	uint8 i =0;
	static uint8 counter =0;

	if (counter==0)
	{
		LCD_writeString("                ",1,0);
		LCD_writeString("FIRING...",1,0);

		/*active led and buzzer*/
		Dio_WriteChannel(BUZZER_PIN	,STD_high);
		Dio_WriteChannel(LED1_PIN	,STD_high);
		Dio_WriteChannel(LED2_PIN	,STD_high);
		Dio_WriteChannel(LED3_PIN	,STD_high);

		/* deactive sev segments */
		BcdSevSeg_disable_1();
		BcdSevSeg_disable_2();
		Scheduler_setSatus(TASK_INDEX_Bcd_SevSeg_Ref,STD_suspended);
		Scheduler_setSatus(TASK_INDEX_Bcd_SevSeg_Count,STD_suspended);
		Scheduler_setSatus(TASK_INDEX_Kp,STD_suspended);

		counter = 1;

	}
	else if (counter==1)
	{
		Dio_WriteChannel(LED1_PIN	,STD_low);

		/* active sev segments */
		Scheduler_setSatus(TASK_INDEX_Bcd_SevSeg_Ref,STD_active);

		counter=2;
	}

	else if (counter==2)
	{
		/* deactive sev segments */
		BcdSevSeg_disable_1();
		BcdSevSeg_disable_2();
		Scheduler_setSatus(TASK_INDEX_Bcd_SevSeg_Ref,STD_suspended);

		Dio_WriteChannel(LED2_PIN	,STD_low);

		counter=3;
	}
	else if (counter==3)
	{
		Dio_WriteChannel(LED3_PIN	,STD_low);

		/* active sev segments */
		Scheduler_setSatus(TASK_INDEX_Bcd_SevSeg_Ref,STD_active);

		counter = 4;
	}
	else if (counter==2)
	{
		counter=0;
		LCD_writeString("                ",1,0);
		LCD_writeString("TARGET UNLOCKED...",1,0);

		/* deactive sev segments */
		BcdSevSeg_disable_1();
		BcdSevSeg_disable_2();
		Scheduler_setSatus(TASK_INDEX_Bcd_SevSeg_Ref,STD_suspended);

		/*active KP Task */
		Scheduler_setSatus(TASK_INDEX_Kp,STD_active);
		/*active canon Task */
		Scheduler_setSatus(TASK_INDEX_Update_Canon,STD_active);
		/*Reset DisplayedNUmber*/
		DisplayedNum = LOCK_TIME_OUT;
		/*Reset Password Input Array*/
		InputArrIndex = 0;
		for(i=0;i<MAX_NUMBER_OF_PSW;i++)InpuArr[i]=0;
		Scheduler_setSatus(TASK_INDEX_Fire,STD_suspended);
	}


}
/**********************************************************************************/

/**********************************************************************************/
void canon_main(void)
{
	/*INIT*/
	PORT_init();
	ADC_init();
	LCD_init();
	KP_init();
	ULS_init();
	SERVO_init();

	ADC_startConversion(ADC_Channel_0);

	Scheduler_createTask(TASK_INDEX_Bcd_SevSeg_Ref,Task_Bcd_SevSeg_Ref,1,STD_suspended);
	Scheduler_createTask(TASK_INDEX_Bcd_SevSeg_Count,Task_Bcd_SevSeg_Count,100,STD_suspended);
	Scheduler_createTask(TASK_INDEX_Update_Canon,Task_Update_Canon,10,STD_active);
	Scheduler_createTask(TASK_INDEX_Kp,Task_Kp,3,STD_active);
	Scheduler_createTask(TASK_INDEX_Upd_Distance,Task_Upd_Distance,1,STD_active);
	Scheduler_createTask(TASK_INDEX_Fire,Task_Fire,1,STD_suspended);

	while(1)
	{

	}
}
