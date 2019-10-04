/*
 * SPI.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_SPI_SPI_H_
#define F15_REPO_SRC_MCAL_SPI_SPI_H_

#include "../../utils/Std_Types.h"

void SPI_init(void);
void SPI_enInterrupt(void);
void SPI_diInterrupt(void);
uint8 SPI_startTransmission(uint8 CharToSend);
void SPI_getReceiveMsg(uint8* MsgPtr, uint8* MsgLengthPtr);


#endif /* F15_REPO_SRC_MCAL_SPI_SPI_H_ */
