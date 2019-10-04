/*
 * SPI_hw.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_SPI_SPI_HW_H_
#define F15_REPO_SRC_MCAL_SPI_SPI_HW_H_

#define SPCR				*((volatile uint8*)0x2D)
#define SPSR				*((volatile uint8*)0x2E)
#define SPDR				*((volatile uint8*)0x2F)

#endif /* F15_REPO_SRC_MCAL_SPI_SPI_HW_H_ */
