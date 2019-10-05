/*
 * TWI.h
 *
 *  Created on: Apr 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_TWI_TWI_H_
#define J7_LAB_SRC_MCAL_TWI_TWI_H_

STD_RetType TWI_sendMsg(uint8 SlaveAddress,uint8 TxMsg[],uint8 SizeCpy);
void TWI_init(void);
void TWI_startReading(uint8 SlaveAddress, uint8 SizeCpy);
STD_RetType TWI_getlastRxMsg(uint8 RxMsg[],uint8* SizePtr);

#endif /* J7_LAB_SRC_MCAL_TWI_TWI_H_ */
