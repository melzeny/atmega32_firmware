/*
 * UART.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Muhammad.Elzeiny
 */
/*============================================================
 * DEFINES
 * ============================================================*/
#define UART_DATA_clr_msk                   0b11111001
#define UART_DATA_SIZE_5                    0b00000000
#define UART_DATA_SIZE_6                    0b00000010
#define UART_DATA_SIZE_7                    0b00000100
#define UART_DATA_SIZE_8                    0b00000110

#define UART_PARITY_clr_msk                 0b11001111
#define UART_PARITY_MODE_DISABLE            0b00000000
#define UART_PARITY_MODE_EVEN               0b00100000
#define UART_PARITY_MODE_ODD                0b00110000

#define UART_STOP_BIT_clr_msk				0b11110111
#define UART_STOP_BIT_1   					0b00000000
#define UART_STOP_BIT_2   					0b00001000

#define UART_UCSRC_ACCESS_msk				0b10000000
/*============================================================
 * INCLUDES
 *============================================================ */
#include "../../utils/Bit_Math.h"
#include "../../utils/Std_Types.h"
#include "../../utils/Interrupts.h"

#include "../../config/UART_cfg.h"
#include "UART_hw.h"
#include "UART_types.h"
#include "UART.h"

/*============================================================
 * LOCAL VARIABLES
 *============================================================ */
static uint8 UART_Tx_Buffer[UART_TX_BUFFER_SIZE],
UART_Rx_Buffer[UART_RX_BUFFER_SIZE],
UART_TX_Index,
UART_Rx_Index,
UART_Msg_TxLength;
static boolean UART_MSG_TxCompleteFlag = true;

/*============================================================
 * FUNCTION DEFINITIONS
 *============================================================ */

void UART_init(void)
{
	UCSRC = UART_UCSRC_ACCESS_msk     |
			UART_DATA_SIZE_SELECTOR   |
			UART_PARITY_MODE_SELECTOR |
			UART_STOP_BIT_SELECTOR;

	/*set baud rate*/
	UBRRL = UART_BAUDE_RATE_UBRR;

	/*enable Tx */
	Set_Bit(UCSRB,3);
	/*enable Rx */
	Set_Bit(UCSRB,4);

	UART_enInterrupt(UART_Int_RxComplete);
	UART_enInterrupt(UART_Int_TxComplete);
}
STD_RetType UART_sendMsg(const uint8 Msg[],uint8 MsgLength)
{
	uint8 i;
	STD_RetType ret;
	if(UART_MSG_TxCompleteFlag == true)
	{
		for (i = 0; i < MsgLength; ++i)
		{
			UART_Tx_Buffer[i] = Msg[i];
		}

		UART_MSG_TxCompleteFlag = false;
		UART_Msg_TxLength = MsgLength;

		UDR = UART_Tx_Buffer[UART_TX_Index++];
		ret = STD_ok;

	}
	else
	{
		ret =  STD_not_ok;
	}
	return ret;

}
void UART_getReceiveMsg(uint8* MsgPtr, uint8* MsgLengthPtr)
{
	uint8 i;
	for (i = 0; i < UART_Rx_Index; ++i)
	{
		MsgPtr[i] = UART_Rx_Buffer[i];
	}
	*MsgLengthPtr = UART_Rx_Index;
	UART_Rx_Index = 0;


}
void UART_enInterrupt(UART_IntType Interrupt)
{
	switch (Interrupt) {
	case UART_Int_RxComplete:
		Set_Bit(UCSRB,7);
		break;
	case UART_Int_TxComplete:
		Set_Bit(UCSRB,6);
		break;
	case UART_Int_UdrReady:
		Set_Bit(UCSRB,5);
		break;
		default:
			break;
	}
}
void UART_diInterrupt(UART_IntType Interrupt)
{
	switch (Interrupt) {
	case UART_Int_RxComplete:
		Clr_Bit(UCSRB,7);
		break;
	case UART_Int_TxComplete:
		Clr_Bit(UCSRB,6);
		break;
	case UART_Int_UdrReady:
		Clr_Bit(UCSRB,5);
		break;
		default:
			break;
	}
}

void ISR(USART_TXC)
{

	if(UART_TX_Index == UART_Msg_TxLength)
	{
		UART_MSG_TxCompleteFlag = true;
		UART_TX_Index = 0;
		UART_Msg_TxLength = 0;

	}
	else
	{
		UDR = UART_Tx_Buffer[UART_TX_Index++];
	}

}
void ISR(USART_RXC)
{
	if(UART_Rx_Index < UART_RX_BUFFER_SIZE)
	{
		UART_Rx_Buffer[UART_Rx_Index++] = UDR;
	}
}
void ISR(USART_UDRE)
{


}
