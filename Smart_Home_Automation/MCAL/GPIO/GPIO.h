/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO.h
 *
 * Description: Header file for the AVR GPIO driver
 *
 * Author: Mahmoud Abouzeid
 *
 *******************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

#include "std_type.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Number of available ports and pins per port */
#define NUM_OF_PORTS                4
#define NUM_OF_PIN_PER_PORT         8

/* Ports IDs */
#define PORTA_ID                    0
#define PORTB_ID                    1
#define PORTC_ID                    2
#define PORTD_ID                    3

/* Pins IDs */
#define PIN0_ID                     0
#define PIN1_ID                     1
#define PIN2_ID                     2
#define PIN3_ID                     3
#define PIN4_ID                     4
#define PIN5_ID                     5
#define PIN6_ID                     6
#define PIN7_ID                     7

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* Pin direction: input or output */
typedef enum{
    pin_input,
    pin_output
} pinDirection;

/* Port direction: input (all pins input) or output (all pins output) */
typedef enum{
    port_input,
    port_output = 0xFF
} portDirection;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description:
 * Setup the direction of a specific pin (input or output).
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, pinDirection status);

/*
 * Description:
 * Write a logic value (HIGH or LOW) to a specific pin.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);

/*
 * Description:
 * Read the current logic value of a specific pin (HIGH or LOW).
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);

/*
 * Description:
 * Setup the direction of an entire port (input or output).
 */
void GPIO_setupPortDirection(uint8 port_num, portDirection status);

/*
 * Description:
 * Write a value (0x00 → 0xFF) to an entire port.
 */
void GPIO_writePort(uint8 port_num, uint8 value);

/*
 * Description:
 * Read the current value of an entire port (8 bits).
 */
uint8 GPIO_readPort(uint8 port_num);

#endif /* GPIO_H_ */
