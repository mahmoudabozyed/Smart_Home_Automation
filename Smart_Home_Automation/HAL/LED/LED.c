/******************************************************************************
*
* Module: LED
*
* File Name: LED.c
*
* Description: Source file for the LED driver
*
* Author: Mahmoud Abouzeid
*
*******************************************************************************/

#include "LED.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/GPIO/common_macros.h"

/*
 * Description:
 * Initialize all LEDs:
 * - Set Red, Green, and Blue pins as output.
 * - Turn OFF all LEDs at the beginning.
 */
void LEDS_init(void){
	GPIO_setupPinDirection(RED_LED_PORT, RED_LED_PIN, pin_output);
	GPIO_setupPinDirection(GREEN_LED_PORT, GREEN_LED_PIN, pin_output);
	GPIO_setupPinDirection(BLUE_LED_PORT, BLUE_LED_PIN, pin_output);

	GPIO_writePin(RED_LED_PORT, RED_LED_PIN, OFF);
	GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, OFF);
	GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, OFF);
}

/*
 * Description:
 * Turn ON a specific LED (Red, Green, or Blue).
 *
 * Input:
 * - id: LED_ID (RED_LED, GREEN_LED, BLUE_LED)
 */
void LED_on(LED_ID id){
	switch(id){
	case RED_LED:
		GPIO_writePin(RED_LED_PORT, RED_LED_PIN, ON);
		break;
	case GREEN_LED:
		GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, ON);
		break;
	case BLUE_LED:
		GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, ON);
		break;
	}
}

/*
 * Description:
 * Turn OFF a specific LED (Red, Green, or Blue).
 *
 * Input:
 * - id: LED_ID (RED_LED, GREEN_LED, BLUE_LED)
 */
void LED_off(LED_ID id){
	switch(id){
	case RED_LED:
		GPIO_writePin(RED_LED_PORT, RED_LED_PIN, OFF);
		break;
	case GREEN_LED:
		GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, OFF);
		break;
	case BLUE_LED:
		GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, OFF);
		break;
	}
}
