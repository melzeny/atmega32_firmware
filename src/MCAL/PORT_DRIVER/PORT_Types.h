/*
 * PORT_Types.h
 *
 *  Created on: Jun 29, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_PORT_DRIVER_PORT_TYPES_H_
#define F15_REPO_SRC_MCAL_PORT_DRIVER_PORT_TYPES_H_

#include "../../utils/Std_Types.h"

typedef struct
{
	uint8 PinDir_A0:1;
	uint8 PinDir_A1:1;
	uint8 PinDir_A2:1;
	uint8 PinDir_A3:1;
	uint8 PinDir_A4:1;
	uint8 PinDir_A5:1;
	uint8 PinDir_A6:1;
	uint8 PinDir_A7:1;

	uint8 PinDir_B0:1;
	uint8 PinDir_B1:1;
	uint8 PinDir_B2:1;
	uint8 PinDir_B3:1;
	uint8 PinDir_B4:1;
	uint8 PinDir_B5:1;
	uint8 PinDir_B6:1;
	uint8 PinDir_B7:1;

	uint8 PinDir_C0:1;
	uint8 PinDir_C1:1;
	uint8 PinDir_C2:1;
	uint8 PinDir_C3:1;
	uint8 PinDir_C4:1;
	uint8 PinDir_C5:1;
	uint8 PinDir_C6:1;
	uint8 PinDir_C7:1;

	uint8 PinDir_D0:1;
	uint8 PinDir_D1:1;
	uint8 PinDir_D2:1;
	uint8 PinDir_D3:1;
	uint8 PinDir_D4:1;
	uint8 PinDir_D5:1;
	uint8 PinDir_D6:1;
	uint8 PinDir_D7:1;
}PORT_PinStructType;

typedef union
{
	PORT_PinStructType Bit;
	uint8 Byte[4];
}PORT_PinDirType;
#endif /* F15_REPO_SRC_MCAL_PORT_DRIVER_PORT_TYPES_H_ */
