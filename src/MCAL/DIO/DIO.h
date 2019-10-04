/*
 * DIO.h
 *
 *  Created on: Jun 28, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_DIO_DIO_H_
#define F15_REPO_SRC_MCAL_DIO_DIO_H_
#include "../../utils/Std_Types.h"
#include "DIO_types.h"

STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, STD_levelType Level);
uint8 Dio_ReadPort(Dio_PortType PortId );
void Dio_WritePort( Dio_PortType PortId, uint8 val);
void Dio_FlipChannel( Dio_ChannelType ChannelId);
void Dio_FlipPort(Dio_PortType PortId);



#endif /* F15_REPO_SRC_MCAL_DIO_DIO_H_ */
