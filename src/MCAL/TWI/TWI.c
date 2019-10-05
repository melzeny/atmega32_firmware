/*
 * TWI.c
 *
 *  Created on: Apr 5, 2019
 *      Author: Muhammad.Elzeiny
 */
typedef enum
{
	BusError=0,

	Master_Start_Condition = 0x08,
	Master_RepeatedStart_Condition = 0x10,

	MasterTx_SlaWbTx_AckRx = 0x18,
	MasterTx_SlaWbTx_NotAckRx =0x20,
	MasterTx_DataTx_AckRx=0x28,
	MasterTx_DataTx_NotAckRx=0x30,

	Master_ArbitrationLost=0x38,

	MasterRx_SlaRbTx_AckRx = 0x40,
	MasterRx_SlaRbTx_NotAckRx =0x48,
	MasterRx_DataRx_AckTx=0x50,
	MasterRx_DataRx_NotAckTx=0x58,

	SlaveRx_SlaWbRx_AckTx = 0x60,
	SlaveRx_ArbitrationLost_SlaWbRx_AckTx = 0x68,
	SlaveRx_BroadcastAddrRx_AckTx = 0x70,
	SlaveRx_ArbitrationLost_BroadcastAddrRx_AckTx = 0x78,

	SlaveRx_PrevSlaWbRx_AckTx = 0x80,
	SlaveRx_PrevArbitrationLost_SlaWbRx_AckTx = 0x88,
	SlaveRx_PrevBroadcastAddrRx_AckTx = 0x90,
	SlaveRx_PrevArbitrationLost_BroadcastAddrRx_AckTx = 0x98,

	SlaveRx_StopCondition_Or_RepeatedStartCondition = 0xA0,

	SlaveTx_SlaRbRx_AckTx = 0xA8,
	SlaveTx_ArbitrationLost_SlaRbRx_AckTx = 0xB0,

	SlaveTx_DataTx_AckRx = 0xB8,
	SlaveTx_DataTx_NotAckRx = 0xC0,
	SlaveTx_LastDataTx_AckRx = 0xC8,

	NoRelevantState = 0xF8

}TWI_status_t;

#define TWI_PRESCALER_clr_msk		  0x11111100
#define TWI_PRESCALER_1_msk           0x00000000
#define TWI_PRESCALER_4_msk           0x00000001
#define TWI_PRESCALER_16_msk          0x00000010
#define TWI_PRESCALER_64_msk          0x00000011

#include "../../utils/BIT_MATH.h"
#include "../../utils/STD_TYPES.h"

#include "TWI_reg.h"
#include "../../config/TWI_cfg.h"
#include "TWI.h"

uint8 TWI_SlaWR = 0;

static uint8 TWI_Tx_Buffer[TWI_TX_BUFFER_SIZE_Byte]={0},
		TWI_Tx_Buffer_Index=0,
		TWI_Tx_Buffer_Size =0;

static uint8 TWI_Rx_Buffer[TWI_RX_BUFFER_SIZE_Byte]={0},
		TWI_Rx_Buffer_Index=0,
		TWI_Rx_Buffer_Size = 0;

void TWI_init(void)
{
	/*init cfg*/
	TWBR = TWI_BITRATE_TWBR_VAL;

	TWSR &= TWI_PRESCALER_clr_msk;
	TWSR |= TWI_PRESCALER_SELECTOR_msk;

	TWAR = TWI_NODE_ADDRESS<<1;

	Clr_Bit(TWAR,0);
	TWAR |= TWI_BROADCAST_EN<<0;

	/*enable TWI*/
	Set_Bit(TWCR,2);
}

void TWI_diAck(void)
{
	Clr_Bit(TWCR,6);
}
void TWI_enAck(void)
{
	Set_Bit(TWCR,6);
}
void TWI_START_CONDITION(void)
{
	Set_Bit(TWCR,5);
}
void TWI_STOP_CONDITION(void)
{
	Set_Bit(TWCR,4);
}
void TWI_enInterrupt(void)
{
	Set_Bit(TWCR,0);
}

void TWI_diInterrupt(void)
{
	Clr_Bit(TWCR,0);
}
STD_RetType TWI_sendMsg(uint8 SlaveAddress,uint8 TxMsg[],uint8 SizeCpy)
{
	STD_RetType ret;
	uint8 i=0;
	if(TWI_Tx_Buffer_Size == 0)
	{
		TWI_Tx_Buffer_Size = SizeCpy;
		TWI_SlaWR = SlaveAddress;

		for(i=0;i<SizeCpy;i++)
		{
			TWI_Tx_Buffer[i]= TxMsg[i];
		}
		TWI_enInterrupt();
		TWI_START_CONDITION();
		ret =  STD_ok;
	}
	else
	{
		ret =  STD_not_ok;
	}
	return ret;
}
void TWI_startReading(uint8 SlaveAddress, uint8 SizeCpy)
{
	if(TWI_Rx_Buffer_Size == 0)
	{
		TWI_SlaWR = SlaveAddress;
		Set_Bit(TWI_SlaWR,0);
		TWI_Rx_Buffer_Size = SizeCpy;

		TWI_enAck();
		TWI_enInterrupt();
		TWI_START_CONDITION();
	}
}
STD_RetType TWI_getlastRxMsg(uint8 RxMsg[],uint8* SizePtr)
{
	uint8 i =0;
	STD_RetType ret;
	if(TWI_Rx_Buffer_Size != 0)
	{
		for(i=0;i<TWI_Rx_Buffer_Index;i++)
		{
			RxMsg[i] = TWI_Rx_Buffer[i];
		}
		*SizePtr = TWI_Rx_Buffer_Index;
		TWI_Rx_Buffer_Index = 0;
		TWI_Rx_Buffer_Size = 0;
		ret = STD_ok;
	}
	else
	{
		ret = STD_not_ok;
	}
	return ret;
}
void __vector_19(void) __attribute__((signal,used));
void __vector_19(void)
{
	TWI_status_t CurrentStatus = TWSR & 0b11111100;
	switch(CurrentStatus)
	{
	case BusError :

		break;
	case Master_RepeatedStart_Condition :
	case Master_Start_Condition :
		/*TWDR*/
		TWDR = TWI_SlaWR;
		Clr_Bit(TWCR,5);
		break;

	case MasterTx_SlaWbTx_NotAckRx :
	case MasterTx_SlaWbTx_AckRx :
		TWDR = TWI_Tx_Buffer[TWI_Tx_Buffer_Index++];
		break;

	case MasterTx_DataTx_NotAckRx :
	case MasterTx_DataTx_AckRx :
		if(TWI_Tx_Buffer_Index < TWI_Tx_Buffer_Size)
		{
			TWDR = TWI_Tx_Buffer[TWI_Tx_Buffer_Index++];
		}
		else
		{
			TWI_Tx_Buffer_Index = 0;
			TWI_Tx_Buffer_Size = 0;
			TWI_STOP_CONDITION();
		}
		break;

	case Master_ArbitrationLost :

		break;
	case MasterRx_SlaRbTx_AckRx :

		break;
	case MasterRx_SlaRbTx_NotAckRx :

		break;
	case MasterRx_DataRx_AckTx :
		if(TWI_Rx_Buffer_Index<TWI_Rx_Buffer_Size)
		{
			TWI_Rx_Buffer[TWI_Rx_Buffer_Index++] = TWDR;
		}
		else
		{
			TWI_diAck();
		}
		break;
	case MasterRx_DataRx_NotAckTx :
		TWI_STOP_CONDITION();
		break;
	case SlaveRx_SlaWbRx_AckTx :

		break;
	case SlaveRx_ArbitrationLost_SlaWbRx_AckTx:

		break;
	case SlaveRx_BroadcastAddrRx_AckTx:

		break;
	case SlaveRx_ArbitrationLost_BroadcastAddrRx_AckTx:

		break;
	case SlaveRx_PrevSlaWbRx_AckTx:

		break;
	case SlaveRx_PrevArbitrationLost_SlaWbRx_AckTx:

		break;
	case SlaveRx_PrevBroadcastAddrRx_AckTx:

		break;
	case SlaveRx_PrevArbitrationLost_BroadcastAddrRx_AckTx:

		break;
	case SlaveRx_StopCondition_Or_RepeatedStartCondition:

		break;
	case SlaveTx_SlaRbRx_AckTx:

		break;
	case SlaveTx_ArbitrationLost_SlaRbRx_AckTx:

		break;
	case SlaveTx_DataTx_AckRx:

		break;
	case SlaveTx_DataTx_NotAckRx:

		break;
	case SlaveTx_LastDataTx_AckRx:

		break;
	case NoRelevantState:
		break;
	default:
		break;

	}

	/*interrupt flag should be cleared
	 * by writing one to it*/
	Set_Bit(TWCR,7);
}

