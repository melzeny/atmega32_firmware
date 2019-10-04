/*
 * SWITCH.c
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../config/Switch_cfg.h"
#include "../../utils/Std_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../Scheduler/Scheduler.h"
#include "Switch_types.h"
#include "Switch.h"

static void SW_setSwitchStatus_Task(void);
extern SW_SwitchType SW_CfgArr[];

void SW_init(void)
{
	Scheduler_createTask(0,SW_setSwitchStatus_Task,1,STD_active);
	Scheduler_init();

}

SW_StatusType SW_getSwitchStatus(SW_NameType SwName)
{
	return SW_CfgArr[SwName].FinalStatus;
}

static void SW_setSwitchStatus_Task(void)
{
	uint8 SwitchIndex;

	for(SwitchIndex=0;SwitchIndex<MaxNumOfSwitches;SwitchIndex++)
	{

		if(SW_CfgArr[SwitchIndex].ModeType == Active_high)
		{
			SW_CfgArr[SwitchIndex].CurrStatus = Dio_ReadChannel( SW_CfgArr[SwitchIndex].Channel);
		}
		else
		{
			SW_CfgArr[SwitchIndex].CurrStatus = !Dio_ReadChannel( SW_CfgArr[SwitchIndex].Channel);
		}

		if(SW_CfgArr[SwitchIndex].CurrStatus == SW_CfgArr[SwitchIndex].PrevStatus)
		{
			SW_CfgArr[SwitchIndex].DebounceCounter++;
		}
		else
		{
			SW_CfgArr[SwitchIndex].DebounceCounter = 0;
		}

		if(SW_CfgArr[SwitchIndex].DebounceCounter == SWITCH_MAX_DEBOUNCE_COUNTER)
		{
			SW_CfgArr[SwitchIndex].FinalStatus = SW_CfgArr[SwitchIndex].CurrStatus;
			SW_CfgArr[SwitchIndex].DebounceCounter = 0;
		}
		SW_CfgArr[SwitchIndex].PrevStatus = SW_CfgArr[SwitchIndex].CurrStatus;
	}
}
