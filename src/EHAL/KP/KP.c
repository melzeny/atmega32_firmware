/*
 * KP.c
 *
 *  Created on: Jul 5, 2019
 *      Author: Toka.Kamal
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/Std_Types.h"
#include "../../config/KP_cfg.h"
#include "../../MCAL/DIO/DIO.h"

static void KP_CheckCol(uint8 ActivatedRow);
static uint8 PressedSwitch = KP_RELEASED ;
static const uint8 MapArr[16] = {
		KP_BUTON_0,KP_BUTON_1,KP_BUTON_2,KP_BUTON_3,
		KP_BUTON_4,KP_BUTON_5,KP_BUTON_6,KP_BUTON_7,
		KP_BUTON_8,KP_BUTON_9,KP_BUTON_10,KP_BUTON_11,
		KP_BUTON_12,KP_BUTON_13,KP_BUTON_14,KP_BUTON_15};
void KP_init(void)
{
#if KP_INTERNAL_PULL_UP_RESISTOR_EN
	/* attach Internal Pull-up Resistor*/
	Dio_WriteChannel(KP_PIN_COL_0,STD_high);
	Dio_WriteChannel(KP_PIN_COL_1,STD_high);
	Dio_WriteChannel(KP_PIN_COL_2,STD_high);
	Dio_WriteChannel(KP_PIN_COL_3,STD_high);
#endif
}
uint8 KP_getPressedSwitch(void)
{
	PressedSwitch = KP_RELEASED;
	/*de-active all rows except row 0*/
	Dio_WriteChannel(KP_PIN_ROW_0,KP_ACTIVE_TYPE);
	Dio_WriteChannel(KP_PIN_ROW_1,!KP_ACTIVE_TYPE);
	Dio_WriteChannel(KP_PIN_ROW_2,!KP_ACTIVE_TYPE);
	Dio_WriteChannel(KP_PIN_ROW_3,!KP_ACTIVE_TYPE);
	KP_CheckCol(0);
	if(PressedSwitch != KP_RELEASED)return MapArr[PressedSwitch];
	/********************************************/

	Dio_WriteChannel(KP_PIN_ROW_0,!KP_ACTIVE_TYPE);
	Dio_WriteChannel(KP_PIN_ROW_1,KP_ACTIVE_TYPE);
	Dio_WriteChannel(KP_PIN_ROW_2,!KP_ACTIVE_TYPE);
	Dio_WriteChannel(KP_PIN_ROW_3,!KP_ACTIVE_TYPE);
	KP_CheckCol(1);
	if(PressedSwitch != KP_RELEASED)return MapArr[PressedSwitch];
	/********************************************/
	Dio_WriteChannel(KP_PIN_ROW_0,!KP_ACTIVE_TYPE);
	Dio_WriteChannel(KP_PIN_ROW_1,!KP_ACTIVE_TYPE);
	Dio_WriteChannel(KP_PIN_ROW_2,KP_ACTIVE_TYPE);
	Dio_WriteChannel(KP_PIN_ROW_3,!KP_ACTIVE_TYPE);
	KP_CheckCol(2);
	if(PressedSwitch != KP_RELEASED)return MapArr[PressedSwitch];

	/********************************************/
	Dio_WriteChannel(KP_PIN_ROW_0,!KP_ACTIVE_TYPE);
	Dio_WriteChannel(KP_PIN_ROW_1,!KP_ACTIVE_TYPE);
	Dio_WriteChannel(KP_PIN_ROW_2,!KP_ACTIVE_TYPE);
	Dio_WriteChannel(KP_PIN_ROW_3,KP_ACTIVE_TYPE);
	KP_CheckCol(3);
	if(PressedSwitch != KP_RELEASED)return MapArr[PressedSwitch];
	/********************************************/
	return PressedSwitch;
}
static void KP_CheckCol(uint8 ActivatedRow)
{
	/*check for all cols*/
	if(Dio_ReadChannel(KP_PIN_COL_0) == KP_ACTIVE_TYPE)
	{
		/*assign PressedSwitch with 0*/
		PressedSwitch =ActivatedRow *4;
	}
	else if(Dio_ReadChannel(KP_PIN_COL_1) == KP_ACTIVE_TYPE)
	{
		/*assign PressedSwitch with 1*/
		PressedSwitch =(ActivatedRow *4) +1;
	}
	else if(Dio_ReadChannel(KP_PIN_COL_2) == KP_ACTIVE_TYPE)
	{
		PressedSwitch =(ActivatedRow *4) +2;
	}
	else if(Dio_ReadChannel(KP_PIN_COL_3) == KP_ACTIVE_TYPE)
	{
		PressedSwitch =(ActivatedRow *4) +3;
	}
	else
	{

	}

}
