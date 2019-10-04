/*
 * SevSeg.c
 *
 *  Created on: Jun 29, 2019
 *      Author: Muhammad.Elzeiny
 */
/*private defines */
#define SEvSeg_COMMON_CATHOD		0
#define SEvSeg_COMMON_ANOD			1

#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../MCAL/DIO/DIO.h"

#include "../../config/SevSeg_cfg.h"
#include "SevSeg.h"

const uint8 MapArr[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
/*Function Implementation*/
void SevSeg_DisplayNum(uint8 DisplayedNum)
{
	uint8 DisplayedPattern=MapArr[DisplayedNum];

#if SevSeg_COMMON_TYPE == SEvSeg_COMMON_CATHOD
	Dio_WriteChannel(SevSeg_PIN_a, Get_Bit(DisplayedPattern,0));/*DisplayedPattern-Bit0*/
	Dio_WriteChannel(SevSeg_PIN_b, Get_Bit(DisplayedPattern,1));/*DisplayedPattern-Bit1*/
	Dio_WriteChannel(SevSeg_PIN_c, Get_Bit(DisplayedPattern,2));
	Dio_WriteChannel(SevSeg_PIN_d, Get_Bit(DisplayedPattern,3));
	Dio_WriteChannel(SevSeg_PIN_e, Get_Bit(DisplayedPattern,4));
	Dio_WriteChannel(SevSeg_PIN_f, Get_Bit(DisplayedPattern,5));
	Dio_WriteChannel(SevSeg_PIN_g, Get_Bit(DisplayedPattern,6));
#elif SevSeg_COMMON_TYPE == SEvSeg_COMMON_ANOD
	Dio_WriteChannel(SevSeg_PIN_a, !Get_Bit(DisplayedPattern,0));/*DisplayedPattern-Bit0*/
	Dio_WriteChannel(SevSeg_PIN_b, !Get_Bit(DisplayedPattern,1));/*DisplayedPattern-Bit1*/
	Dio_WriteChannel(SevSeg_PIN_c, !Get_Bit(DisplayedPattern,2));
	Dio_WriteChannel(SevSeg_PIN_d, !Get_Bit(DisplayedPattern,3));
	Dio_WriteChannel(SevSeg_PIN_e, !Get_Bit(DisplayedPattern,4));
	Dio_WriteChannel(SevSeg_PIN_f, !Get_Bit(DisplayedPattern,5));
	Dio_WriteChannel(SevSeg_PIN_g, !Get_Bit(DisplayedPattern,6));
#endif

}
void SevSeg_enable_1(void)
{
	Dio_WriteChannel(SevSeg_PIN_EN_1,SevSeg_COMMON_TYPE);/*enable pin */

}
void SevSeg_disable_1(void)
{
	Dio_WriteChannel(SevSeg_PIN_EN_1,!SevSeg_COMMON_TYPE);/*enable pin */

}
void SevSeg_enable_2(void)
{
	Dio_WriteChannel(SevSeg_PIN_EN_2,SevSeg_COMMON_TYPE);/*enable pin */

}
void SevSeg_disable_2(void)
{
	Dio_WriteChannel(SevSeg_PIN_EN_2,!SevSeg_COMMON_TYPE);/*enable pin */

}
