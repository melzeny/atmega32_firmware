/*
 * SWITCH_lcfg.c
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../EHAL/Switch/Switch_types.h"
#include "../utils/Std_Types.h"
#include "../MCAL/DIO/DIO_types.h"

SW_SwitchType SW_CfgArr[MaxNumOfSwitches] =
{
		{SW_Name_0, Dio_Channel_C0, Active_low},
		{SW_Name_1, Dio_Channel_C1, Active_low},
		{SW_Name_2, Dio_Channel_C2, Active_low},
		{SW_Name_3, Dio_Channel_C3, Active_high},
		{SW_Name_4, Dio_Channel_C4, Active_low},
		{SW_Name_5, Dio_Channel_C5, Active_low},
		{SW_Name_6, Dio_Channel_C6, Active_high},
		{SW_Name_7, Dio_Channel_C7, Active_low},

};
