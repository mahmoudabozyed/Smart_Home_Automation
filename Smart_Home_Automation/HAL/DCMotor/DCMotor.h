/******************************************************************************
*
* Module: DC Motor
*
* File Name: DCMotor.h
*
* Description: Header file for the DC Motor driver
*
* Author: Mahmoud Abouzeid
*
*******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "../../MCAL/GPIO/std_type.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Motor input pins for controlling direction */
#define MOTOR_PORT_IN1      PORTB_ID   /* IN1 pin port */
#define MOTOR_PIN_IN1       PIN0_ID    /* IN1 pin number */

#define MOTOR_PORT_IN2      PORTB_ID   /* IN2 pin port */
#define MOTOR_PIN_IN2       PIN1_ID    /* IN2 pin number */

/* Motor enable pin (PWM) */
#define MOTOR_PORT_EN1      PORTB_ID   /* Enable pin port */
#define MOTOR_PIN_EN1       PIN3_ID    /* Enable pin number */

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/*
 * DcMotor_State:
 * Enumeration for the motor state:
 *  - Stop  : Motor stopped
 *  - CW    : Rotate clockwise
 *  - A_CW  : Rotate anti-clockwise
 */
typedef enum
{
	Stop,   /* 0 */
	CW,     /* 1 */
	A_CW    /* 2 */
} DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Initialize the DC motor:
 * - Configure IN1, IN2, and EN1 pins as output
 * - Stop the motor at the beginning
 */
void DcMotor_Init(void);

/*
 * Description:
 * Rotate the DC motor in the specified state and with the given speed.
 *
 * Inputs:
 *  - state: Motor state (Stop, CW, A_CW)
 *  - speed: Motor speed (0 → 100), percentage duty cycle for PWM
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DCMOTOR_H_ */
