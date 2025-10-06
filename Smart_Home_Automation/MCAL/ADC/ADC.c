/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: source file for the ATmega32 ADC driver
 *
 * Author: Mahmoud Abouzeid
 *
 *******************************************************************************/

#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/GPIO/common_macros.h"
#include "../../MCAL/ADC/ADC.h"
#include "../../HAL/LDR/LDR.h"
#include "../../HAL/LM35/LM35.h"
#include <avr/io.h>

void ADC_init(void){
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);
	SET_BIT(ADCSRA, ADEN);
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);

	GPIO_setupPinDirection(LM35_PORT_ID, LM35_PIN_ID, pin_input);
	GPIO_setupPinDirection(LDR_PORT_ID, LDR_PIN_ID, pin_input);
}

uint16 ADC_readChannel(uint8 channel_num){
	ADMUX &= 0xE0;
	ADMUX |= channel_num;
	SET_BIT(ADCSRA, ADSC);
	while(BIT_IS_CLEAR(ADCSRA, ADIF));
	SET_BIT(ADCSRA, ADIF);
	return ADC;
}
