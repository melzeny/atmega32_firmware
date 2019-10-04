/*
 * SPI.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Muhammad.Elzeiny
 */
/*============================================================
 * DEFINES
 * ============================================================*/
#define SPI_ENABLE_msk					0b01000000

#define SPI_DATA_ORDER_LSB_msk			0b00100000
#define SPI_DATA_ORDER_MSB_msk			0b00000000

#define SPI_OPERATION_MODE_MASTER_msk	0b00010000
#define SPI_OPERATION_MODE_SLAVE_msk	0b00000000

#define SPI_SCK_IDLE_LEVEL_HIGH			0b00001000
#define SPI_SCK_IDLE_LEVEL_LOW			0b00000000

#define SPI_LEADING_EDGE_OPR_SAMPLE		0b00000000
#define SPI_LEADING_EDGE_OPR_SETUP		0b00000100

#define SPI_PRESCALER_4					0b00000000
#define SPI_PRESCALER_16				0b00000001
#define SPI_PRESCALER_64				0b00000010
#define SPI_PRESCALER_128				0b00000011

/*============================================================
 * INCLUDES
 *============================================================ */
#include "../../utils/Bit_Math.h"
#include "../../utils/Std_Types.h"
#include "../../utils/Interrupts.h"

#include "../../config/SPI_cfg.h"
#include "SPI_hw.h"
#include "SPI.h"

/*============================================================
 * LOCAL VARIABLES
 *============================================================ */
static uint8 SPI_RxBuffer[SPI_RX_BUFFER_SIZE],SPI_RxBuffIndex=0;
/*============================================================
 * FUNCTION DEFINITIONS
 *============================================================ */
void SPI_init(void)
{

	SPCR =  SPI_ENABLE_msk              |				/*enable SPI*/
			SPI_DATA_ORDER_SELECTOR     |				/*configure Data Order*/
			SPI_OPERATION_MODE_SELECTOR |
			SPI_SCK_IDLE_LEVEL_SELECTOR |
			SPI_LEADING_EDGE_OPR_SELCTOR|
			SPI_PRESCALER_SELECTOR      ;

	SPSR |= SPI_DOUBLE_SPEED;

#if SPI_OPERATION_MODE_SELECTOR == SPI_OPERATION_MODE_SLAVE_msk
	SPI_enInterrupt(void);
#endif

}
void SPI_enInterrupt(void)
{
	Set_Bit(SPCR,7);
}
void SPI_diInterrupt(void)
{
	Clr_Bit(SPCR,7);
}
uint8 SPI_startTransmission(uint8 CharToSend)
{
	uint8 ReceivedMsg;
	SPDR = CharToSend;
	/*wait for transmission complete flag to be set*/
	while(Get_Bit(SPSR,7) == 0)
	{
		;
	}
	ReceivedMsg = SPDR;

	return ReceivedMsg;
}

void SPI_getReceiveMsg(uint8* MsgPtr, uint8* MsgLengthPtr)
{
	uint8 i;
	for (i = 0; i < SPI_RxBuffIndex; ++i)
	{
		MsgPtr[i] = SPI_RxBuffer[i];
	}
	*MsgLengthPtr = SPI_RxBuffIndex;
	SPI_RxBuffIndex = 0;
}
void ISR(SPI_STC)
{
	SPI_RxBuffer[SPI_RxBuffIndex++] = SPDR;
}

