/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 * Author: Mahmoud Abouzeid
 *
 *******************************************************************************/

#include "common_macros.h"
#include "GPIO.h"
#include <avr/io.h>

/*
 * Description:
 * Setup the direction of a specific pin (input or output).
 *
 * Inputs:
 *  - port_num : ID of the port (PORTA_ID → PORTD_ID)
 *  - pin_num  : ID of the pin (0 → 7)
 *  - status   : pin_input or pin_output
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, pinDirection status){
	if((port_num > NUM_OF_PORTS)|| (pin_num > NUM_OF_PIN_PER_PORT)){
		/* Invalid port or pin, do nothing */
	}else{
		switch(port_num){
		case PORTA_ID:
			if(status == pin_output){
				SET_BIT(DDRA, pin_num);
			}else{
				CLEAR_BIT(DDRA, pin_num);
			}
			break;
		case PORTB_ID:
			if(status == pin_output){
				SET_BIT(DDRB, pin_num);
			}else{
				CLEAR_BIT(DDRB, pin_num);
			}
			break;
		case PORTC_ID:
			if(status == pin_output){
				SET_BIT(DDRC, pin_num);
			}else{
				CLEAR_BIT(DDRC, pin_num);
			}
			break;
		case PORTD_ID:
			if(status == pin_output){
				SET_BIT(DDRD, pin_num);
			}else{
				CLEAR_BIT(DDRD, pin_num);
			}
			break;
		}
	}
}

/*
 * Description:
 * Write a logic value (HIGH or LOW) on a specific pin.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value){
	if((port_num > NUM_OF_PORTS)|| (pin_num > NUM_OF_PIN_PER_PORT)){
		/* Invalid port or pin, do nothing */
	}else{
		switch(port_num){
		case PORTA_ID:
			if(value == HIGH){
				SET_BIT(PORTA, pin_num);
			}else{
				CLEAR_BIT(PORTA, pin_num);
			}
			break;
		case PORTB_ID:
			if(value == HIGH){
				SET_BIT(PORTB, pin_num);
			}else{
				CLEAR_BIT(PORTB, pin_num);
			}
			break;
		case PORTC_ID:
			if(value == HIGH){
				SET_BIT(PORTC, pin_num);
			}else{
				CLEAR_BIT(PORTC, pin_num);
			}
			break;
		case PORTD_ID:
			if(value == HIGH){
				SET_BIT(PORTD, pin_num);
			}else{
				CLEAR_BIT(PORTD, pin_num);
			}
			break;
		}
	}
}

/*
 * Description:
 * Read the logic value (HIGH or LOW) from a specific pin.
 *
 * Returns:
 *  - HIGH if the pin is set
 *  - LOW  if the pin is cleared
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num){
	uint8 status = LOW;
	if((port_num > NUM_OF_PORTS)|| (pin_num > NUM_OF_PIN_PER_PORT)){
		/* Invalid port or pin, return LOW */
	}else{
		switch(port_num){
		case PORTA_ID:
			status = (BIT_IS_SET(PINA, pin_num)) ? HIGH : LOW;
			break;
		case PORTB_ID:
			status = (BIT_IS_SET(PINB, pin_num)) ? HIGH : LOW;
			break;
		case PORTC_ID:
			status = (BIT_IS_SET(PINC, pin_num)) ? HIGH : LOW;
			break;
		case PORTD_ID:
			status = (BIT_IS_SET(PIND, pin_num)) ? HIGH : LOW;
			break;
		}
	}
	return status;
}

/*
 * Description:
 * Setup the direction of an entire port (input or output).
 */
void GPIO_setupPortDirection(uint8 port_num, portDirection status){
	if(port_num > NUM_OF_PORTS){
		/* Invalid port, do nothing */
	}else{
		switch(port_num){
		case PORTA_ID:
			DDRA = status;
			break;
		case PORTB_ID:
			DDRB = status;
			break;
		case PORTC_ID:
			DDRC = status;
			break;
		case PORTD_ID:
			DDRD = status;
			break;
		}
	}
}

/*
 * Description:
 * Write a value (0x00 → 0xFF) on an entire port.
 */
void GPIO_writePort(uint8 port_num, uint8 value){
	if(port_num > NUM_OF_PORTS){
		/* Invalid port, do nothing */
	}else{
		switch(port_num){
		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		}
	}
}

/*
 * Description:
 * Read the current value of an entire port (8 bits).
 *
 * Returns:
 *  - Value of the port (0x00 → 0xFF).
 */
uint8 GPIO_readPort(uint8 port_num){
	uint8 status = 0x00;
	if(port_num > NUM_OF_PORTS){
		/* Invalid port, return 0x00 */
	}else{
		switch(port_num){
		case PORTA_ID:
			status = PINA;
			break;
		case PORTB_ID:
			status = PINB;
			break;
		case PORTC_ID:
			status = PINC;
			break;
		case PORTD_ID:
			status = PIND;
			break;
		}
	}
	return status;
}
