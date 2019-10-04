/*
 * SWITCH_cfg.h
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_EHAL_SWITCH_SWITCH_TYPES_H_
#define F15_REPO_SRC_EHAL_SWITCH_SWITCH_TYPES_H_

#include "../../config/Switch_cfg.h"
#include "../../utils/Std_Types.h"
#include "../../MCAL/DIO/DIO_types.h"


typedef enum
{
	Active_high,
	Active_low

}SW_ActiveModeType;

typedef enum
{
	SW_Status_Released,
	SW_Status_Pressed
}SW_StatusType;

typedef struct
{
	SW_NameType 		Name;
	Dio_ChannelType 	Channel;
	SW_ActiveModeType	ModeType;
	uint8				DebounceCounter;
	SW_StatusType 		CurrStatus;
	SW_StatusType 		PrevStatus;
	SW_StatusType 		FinalStatus;

}SW_SwitchType;


#endif /* F15_REPO_SRC_EHAL_SWITCH_SWITCH_TYPES_H_ */
