/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DCMotor.c
 *
 * Description: Source file for the DC Motor driver
 *
 * Author: Mahmoud Abouzeid
 *
 *******************************************************************************/

#include "DCMotor.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/PWM/PWM.h"

/*
 * Description:
 * Initialize the DC motor:
 * - Configure motor control pins (IN1, IN2, EN1) as output.
 * - Set motor initially to stopped state.
 * - Initialize PWM with 0% duty cycle (motor OFF).
 */
void DcMotor_Init(void){
	GPIO_setupPinDirection(MOTOR_PORT_IN1, MOTOR_PIN_IN1, pin_output);
	GPIO_setupPinDirection(MOTOR_PORT_IN2, MOTOR_PIN_IN2, pin_output);

	GPIO_setupPinDirection(MOTOR_PORT_EN1, MOTOR_PIN_EN1, pin_output);

	/* Motor stopped at the beginning */
	GPIO_writePin(MOTOR_PORT_IN1, MOTOR_PIN_IN1, LOW);
	GPIO_writePin(MOTOR_PORT_IN2, MOTOR_PIN_IN2, LOW);

	/* Start PWM with 0% duty cycle */
	PWM_Timer0_Start(0);
}

/*
 * Description:
 * Rotate the DC motor in a specific direction with a given speed.
 *
 * Inputs:
 *  - state: Motor direction (Stop, CW, A_CW).
 *  - speed: Motor speed as a percentage (0–100), used for PWM duty cycle.
 *
 * Functionality:
 *  - Stop: Both IN1 & IN2 = LOW (motor stopped).
 *  - CW (Clockwise): IN1 = HIGH, IN2 = LOW.
 *  - A_CW (Anti-Clockwise): IN1 = LOW, IN2 = HIGH.
 *  - Apply PWM to control motor speed.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed){
	switch (state){
	case Stop:
		GPIO_writePin(MOTOR_PORT_IN1, MOTOR_PIN_IN1, LOW);
		GPIO_writePin(MOTOR_PORT_IN2, MOTOR_PIN_IN2, LOW);
		break;

	case CW:
		GPIO_writePin(MOTOR_PORT_IN1, MOTOR_PIN_IN1, HIGH);
		GPIO_writePin(MOTOR_PORT_IN2, MOTOR_PIN_IN2, LOW);
		break;

	case A_CW:
		GPIO_writePin(MOTOR_PORT_IN1, MOTOR_PIN_IN1, LOW);
		GPIO_writePin(MOTOR_PORT_IN2, MOTOR_PIN_IN2, HIGH);
		break;
	}

	/* Set PWM duty cycle according to required speed */
	PWM_Timer0_Start(speed);
}
