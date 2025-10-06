/******************************************************************************
 *
 * Module: BUZZER
 *
 * File Name: BUZZER.c
 *
 * Description: Source file for the BUZZER driver
 *
 * Author: Mahmoud Abouzeid
 *
 *******************************************************************************/

#include "BUZZER.h"
#include "../../MCAL/GPIO/GPIO.h"

/*
 * Description:
 * Initialize the buzzer:
 * - Set the buzzer pin as output.
 * - Start with buzzer OFF (logic LOW).
 */
void Buzzer_init(void){
	GPIO_setupPinDirection(BUZZER_PORT, BUZZER_PIN, pin_output);
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOW);
}

/*
 * Description:
 * Turn the buzzer ON (logic HIGH).
 */
void Buzzer_on(void){
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, HIGH);
}

/*
 * Description:
 * Turn the buzzer OFF (logic LOW).
 */
void Buzzer_off(void){
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOW);
}
