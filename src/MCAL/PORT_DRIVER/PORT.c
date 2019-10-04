/*
 * PORT.c
 *
 *  Created on: Jun 29, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "PORT_hw.h"
#include "PORT_Types.h"
#include "PORT.h"

extern PORT_PinDirType PortCfg ;

void PORT_init(void)
{
	/*
	 * set pins directions according to
	 * user configuration
	 * */
	DDRA_Reg = PortCfg.Byte[0];
	DDRB_Reg = PortCfg.Byte[1];
	DDRC_Reg = PortCfg.Byte[2];
	DDRD_Reg = PortCfg.Byte[3];

}
