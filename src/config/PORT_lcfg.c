/*
 * PORT_lcfg.c
 *
 *  Created on: Jun 29, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../MCAL/PORT_DRIVER/PORT_Types.h"

#define DIR_INPUT			0
#define DIR_OUTPUT			1

const PORT_PinDirType PortCfg = {{

	/*Pin_Dir_A0 */	DIR_OUTPUT,
	/*Pin_Dir_A1 */	DIR_OUTPUT,
	/*Pin_Dir_A2 */	DIR_OUTPUT,
	/*Pin_Dir_A3 */	DIR_OUTPUT,
	/*Pin_Dir_A4 */	DIR_OUTPUT,
	/*Pin_Dir_A5 */	DIR_OUTPUT,
	/*Pin_Dir_A6 */	DIR_OUTPUT,
	/*Pin_Dir_A7 */	DIR_OUTPUT,

	/*Pin_Dir_B0 */	DIR_OUTPUT,
	/*Pin_Dir_B1 */	DIR_OUTPUT,
	/*Pin_Dir_B2 */	DIR_OUTPUT,
	/*Pin_Dir_B3 */	DIR_OUTPUT,
	/*Pin_Dir_B4 */	DIR_OUTPUT,
	/*Pin_Dir_B5 */	DIR_OUTPUT,
	/*Pin_Dir_B6 */	DIR_OUTPUT,
	/*Pin_Dir_B7 */	DIR_OUTPUT,

	/*Pin_Dir_C0 */	DIR_INPUT,
	/*Pin_Dir_C1 */	DIR_INPUT,
	/*Pin_Dir_C2 */	DIR_OUTPUT,
	/*Pin_Dir_C3 */	DIR_OUTPUT,
	/*Pin_Dir_C4 */	DIR_OUTPUT,
	/*Pin_Dir_C5 */	DIR_OUTPUT,
	/*Pin_Dir_C6 */	DIR_OUTPUT,
	/*Pin_Dir_C7 */	DIR_OUTPUT,

	/*Pin_Dir_D0 */	DIR_INPUT,  /*UART Rx*/
	/*Pin_Dir_D1 */	DIR_OUTPUT, /*Uart Tx*/
	/*Pin_Dir_D2 */	DIR_OUTPUT,
	/*Pin_Dir_D3 */	DIR_OUTPUT,
	/*Pin_Dir_D4 */	DIR_OUTPUT,
	/*Pin_Dir_D5 */	DIR_OUTPUT,
	/*Pin_Dir_D6 */	DIR_OUTPUT,
	/*Pin_Dir_D7 */	DIR_OUTPUT
}};
