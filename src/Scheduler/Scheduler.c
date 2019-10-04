/*
 * Scheduler.c
 *
 *  Created on: Jul 19, 2019
 *      Author: Abou Elsharaf
 */
#include "../utils/Std_Types.h"
#include "../utils/Interrupts.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/GLOBAL_INTERRUPT/Global_Int.h"

#include "../config/Scheduler_cfg.h"
#include "Scheduler_types.h"
#include "Scheduler.h"

static Scheduler_TaskType TasksArr[SCHEDULER_MAX_NUMBER_OF_TASKS];

void Scheduler_init(void)
{
	GI_en();
	TIMER0_init();

}

void Scheduler_createTask(uint8 Index,
		Ptr2FuncType TaskPtr,
		uint32 TaskPeriodicity,
		STD_StatusType Status
)
{
	if(Index < SCHEDULER_MAX_NUMBER_OF_TASKS)
	{
		TasksArr[Index].TaskId = Index;
		TasksArr[Index].Ptr2task = TaskPtr;
		TasksArr[Index].Periodicity = TaskPeriodicity;
		TasksArr[Index].Status = Status;
	}

}

void Scheduler_setPeriodicity(uint8 Id, uint32 Periodicity)
{
	TasksArr[Id].Periodicity = Periodicity;
}


void Scheduler_setSatus(uint8 Id, STD_StatusType Status)
{
	TasksArr[Id].Status = Status;
}

/*Period: TICK_SYS*/
void ISR(TIMER0_COMP)
{
	uint8 i;
	static uint32 counter = 0;
	for(i=0;i<SCHEDULER_MAX_NUMBER_OF_TASKS;i++)
	{
		if(TasksArr[i].Ptr2task != 0)
		{
			if(counter % TasksArr[i].Periodicity == 0)
			{
				if(TasksArr[i].Status == STD_active)
				{
					TasksArr[i].Ptr2task();
				}

			}
		}
	}
	counter++;
}
