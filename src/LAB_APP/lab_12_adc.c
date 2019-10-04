/*
 * lab_12_adc.c
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../utils/Interrupts.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/ADC/ADC.h"
#include "../EHAL/LCD/LCD.h"
#include "../MCAL/GLOBAL_INTERRUPT/Global_Int.h"
#include <stdlib.h>
#include <util/delay.h>

void lab_12_adc(void)
{
	uint8 buff[8];
	uint16 Voltage = 0;
	PORT_init();
	LCD_init();
	ADC_init();

	ADC_startConversion(ADC_Channel_0);

	while(1)
	{
		Voltage = ADC_getVoltage_mv();
		itoa(Voltage,buff,10);
		LCD_writeCmd(LCD_CMD_CLEAR);
		LCD_writeString("Voltage in mv ...",0,0);
		LCD_writeString(buff,1,0);
		_delay_ms(300);
	}
}

/*when conversion completes*/
void ISR(ADC)
{



}
