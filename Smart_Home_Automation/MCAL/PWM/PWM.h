/******************************************************************************
*
* Module: PWM
*
* File Name: PWM.h
*
* Description: Header file for the PWM driver
*
* Author: Mahmoud Abouzied
*
*******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "../../MCAL/GPIO/std_type.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Maximum value for 8-bit Timer0 (0 → 255) */
#define PWM_MAX_VALUE   255u

/* Offset for duty cycle calculation (100% scale) */
#define PWM_OFFSET      100u

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description:
 * Start PWM on Timer0 with the required duty cycle.
 *
 * Input:
 *  - duty_cycle: Percentage of PWM duty cycle (0 → 100).
 *
 * Notes:
 *  - Fast PWM mode is used.
 *  - Non-inverting output mode.
 *  - Prescaler = F_CPU/1024.
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
