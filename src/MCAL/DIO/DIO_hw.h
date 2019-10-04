/*
 * DIO_hw.h
 *
 *  Created on: Jun 28, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_DIO_DIO_HW_H_
#define F15_REPO_SRC_MCAL_DIO_DIO_HW_H_

#define PORTA_Reg		*((volatile uint8*)0x3B)
#define PINA_Reg		*((const volatile uint8*)0x39)

#define PORTB_Reg		*((volatile uint8*)0x38)
#define PINB_Reg		*((const volatile uint8*)0x36)

#define PORTC_Reg		*((volatile uint8*)0x35)
#define PINC_Reg		*((const volatile uint8*)0x33)

#define PORTD_Reg		*((volatile uint8*)0x32)
#define PIND_Reg		*((const volatile uint8*)0x30)




#endif /* F15_REPO_SRC_MCAL_DIO_DIO_HW_H_ */
