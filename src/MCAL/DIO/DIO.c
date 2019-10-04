/*
 * DIO.c
 *
 *  Created on: Jun 28, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../../utils/Bit_Math.h"
#include "../../utils/Std_Types.h"

#include "DIO_hw.h"
#include "DIO_types.h"
#include "DIO.h"


STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	STD_levelType ret;
	Dio_PortType PortId = ChannelId /8;
	uint8 ChannelPos = ChannelId % 8;
	switch(PortId)
	{
	case Dio_Port_A:
		ret = Get_Bit(PINA_Reg,ChannelPos);
		break;
	case Dio_Port_B:
		ret = Get_Bit(PINB_Reg,ChannelPos);
		break;
	case Dio_Port_C:
		ret = Get_Bit(PINC_Reg,ChannelPos);
		break;
	case Dio_Port_D:
		ret = Get_Bit(PIND_Reg,ChannelPos);
		break;
	}
	return ret;
}
void Dio_WriteChannel(Dio_ChannelType ChannelId, STD_levelType Level)
{
	Dio_PortType PortId = ChannelId /8;
	uint8 ChannelPos = ChannelId % 8;
	switch(PortId)
	{
	case Dio_Port_A:
		if(Level == STD_low)
		{
			Clr_Bit(PORTA_Reg,ChannelPos);
		}
		else
		{
			Set_Bit(PORTA_Reg,ChannelPos);
		}
		break;
	case Dio_Port_B:
		if(Level == STD_low)
		{
			Clr_Bit(PORTB_Reg,ChannelPos);
		}
		else
		{
			Set_Bit(PORTB_Reg,ChannelPos);
		}
		break;
	case Dio_Port_C:
		if(Level == STD_low)
		{
			Clr_Bit(PORTC_Reg,ChannelPos);
		}
		else
		{
			Set_Bit(PORTC_Reg,ChannelPos);
		}
		break;
	case Dio_Port_D:
		if(Level == STD_low)
		{
			Clr_Bit(PORTD_Reg,ChannelPos);
		}
		else
		{
			Set_Bit(PORTD_Reg,ChannelPos);
		}
		break;
	}
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
	uint8 ret;
	switch(PortId)
	{
	case Dio_Port_A:
		ret = PINA_Reg;
		break;
	case Dio_Port_B:
		ret = PINB_Reg;
		break;
	case Dio_Port_C:
		ret = PINC_Reg;
		break;
	case Dio_Port_D:
		ret = PIND_Reg;
		break;
	}

	return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 val)
{
	switch(PortId)
	{
	case Dio_Port_A:
		PORTA_Reg = val;
		break;
	case Dio_Port_B:
		PORTB_Reg = val;;
		break;
	case Dio_Port_C:
		PORTC_Reg = val;;
		break;
	case Dio_Port_D:
		PORTD_Reg = val;;
		break;
	}

}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
	Dio_PortType PortId = ChannelId /8;
	uint8 ChannelPos = ChannelId % 8;
	switch(PortId)
	{
	case Dio_Port_A:
		Toggle_Bit(PORTA_Reg,ChannelPos);
		break;
	case Dio_Port_B:
		Toggle_Bit(PORTB_Reg,ChannelPos);
		break;
	case Dio_Port_C:
		Toggle_Bit(PORTC_Reg,ChannelPos);
		break;
	case Dio_Port_D:
		Toggle_Bit(PORTD_Reg,ChannelPos);
		break;
	}
}
void Dio_FlipPort(Dio_PortType PortId)
{
	switch(PortId)
	{
	case Dio_Port_A:
		PORTA_Reg = ~PORTA_Reg;
		break;
	case Dio_Port_B:
		PORTB_Reg = ~PORTB_Reg;;
		break;
	case Dio_Port_C:
		PORTC_Reg = ~PORTC_Reg;;
		break;
	case Dio_Port_D:
		PORTD_Reg = ~PORTD_Reg;;
		break;
	}
}
