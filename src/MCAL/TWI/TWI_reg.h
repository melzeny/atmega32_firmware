/*
 * TWI_reg.h
 *
 *  Created on: Apr 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_TWI_TWI_REG_H_
#define J7_LAB_SRC_MCAL_TWI_TWI_REG_H_

#define TWDR      		*((volatile uint8*)0x23)
#define TWAR			*((volatile uint8*)0x22)
#define TWCR			*((volatile uint8*)0x56)
#define TWSR			*((volatile uint8*)0x21)
#define TWBR			*((volatile uint8*)0x20)

#endif /* J7_LAB_SRC_MCAL_TWI_TWI_REG_H_ */
