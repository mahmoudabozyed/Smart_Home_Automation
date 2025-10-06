/******************************************************************************
*
* Module: LED
*
* File Name: LED.h
*
* Description: Header file for the LED driver
*
* Author: Mahmoud Abouzeid
*
*******************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "../../MCAL/GPIO/std_type.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* LED connection type:
 * - POSITIVE_LOGIC: LED ON = HIGH, OFF = LOW
 * - NEGATIVE_LOGIC: LED ON = LOW,  OFF = HIGH
 */
#define CONNECTION_TYPE         POSITVE_LOGIC

#if (CONNECTION_TYPE == POSITVE_LOGIC)
#define ON      HIGH
#define OFF     LOW
#elif (CONNECTION_TYPE == NEGATIVE_LOGIC)
#define ON      LOW
#define OFF     HIGH
#endif

/* Red LED hardware connection */
#define RED_LED_PORT            PORTB_ID
#define RED_LED_PIN             PIN5_ID

/* Green LED hardware connection */
#define GREEN_LED_PORT          PORTB_ID
#define GREEN_LED_PIN           PIN6_ID

/* Blue LED hardware connection */
#define BLUE_LED_PORT           PORTB_ID
#define BLUE_LED_PIN            PIN7_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/*
 * LED_ID:
 * Enumeration for identifying each LED (Red, Green, Blue).
 */
typedef enum {
    RED_LED,
    GREEN_LED,
    BLUE_LED
} LED_ID;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description:
 * Initialize all LEDs:
 * - Set Red, Green, and Blue pins as output.
 * - Ensure all LEDs are OFF initially.
 */
void LEDS_init(void);

/*
 * Description:
 * Turn ON a specific LED (Red, Green, or Blue).
 */
void LED_on(LED_ID id);

/*
 * Description:
 * Turn OFF a specific LED (Red, Green, or Blue).
 */
void LED_off(LED_ID id);

#endif /* LED_H_ */
