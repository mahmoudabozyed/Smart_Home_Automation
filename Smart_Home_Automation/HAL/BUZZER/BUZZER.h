/******************************************************************************
 *
 * Module: BUZZER
 *
 * File Name: BUZZER.h
 *
 * Description: Header file for the BUZZER driver
 *
 * Author: Mahmoud Abouzeid
 *
 *******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Buzzer hardware connection */
#define BUZZER_PORT		PORTD_ID   /* Buzzer connected to PORTD */
#define BUZZER_PIN		PIN3_ID    /* Buzzer connected on Pin 3 */

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description:
 * Initialize the buzzer:
 * - Configure buzzer pin as output
 * - Ensure buzzer is OFF at the beginning
 */
void Buzzer_init(void);

/*
 * Description:
 * Turn the buzzer ON (logic HIGH).
 */
void Buzzer_on(void);

/*
 * Description:
 * Turn the buzzer OFF (logic LOW).
 */
void Buzzer_off(void);

#endif /* BUZZER_H_ */
