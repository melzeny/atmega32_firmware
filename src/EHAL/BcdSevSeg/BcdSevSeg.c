/*
 * BcdSevSeg.c
 *
 *  Created on: Jun 29, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../../utils/Bit_Math.h"
#include "../../utils/Std_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../config/BcdSevSeg_cfg.h"
#include "BcdSevSeg.h"

void BcdSevSeg_DisplayNum(uint8 Num)
{
	Dio_WriteChannel(BcdSevSeg_PIN_A, Get_Bit(Num,0));
	Dio_WriteChannel(BcdSevSeg_PIN_B, Get_Bit(Num,1));
	Dio_WriteChannel(BcdSevSeg_PIN_C, Get_Bit(Num,2));
	Dio_WriteChannel(BcdSevSeg_PIN_D, Get_Bit(Num,3));
}
void BcdSevSeg_enable_1()
{
	Dio_WriteChannel(BcdSevSeg_PIN_EN_1,STD_high);
}
void BcdSevSeg_enable_2()
{
	Dio_WriteChannel(BcdSevSeg_PIN_EN_2,STD_high);
}
void BcdSevSeg_disable_1()
{
	Dio_WriteChannel(BcdSevSeg_PIN_EN_1,STD_low);
}
void BcdSevSeg_disable_2()
{
	Dio_WriteChannel(BcdSevSeg_PIN_EN_2,STD_low);
}
