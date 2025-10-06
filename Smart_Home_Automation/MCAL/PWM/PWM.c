/******************************************************************************
*
* Module: PWM
*
* File Name: PWM.c
*
* Description: Source file for the PWM driver
*
* Author: Mahmoud Abouzied
*
*******************************************************************************/

#include "PWM.h"
#include "avr/io.h"

/*
 * Description:
 * Start PWM generation on Timer0 with the required duty cycle.
 *
 * Input:
 *  - duty_cycle: The required duty cycle percentage (0 → 100).
 *
 * Implementation Details:
 *  - TCNT0 is initialized to 0.
 *  - OCR0 is set based on the duty cycle to control PWM output.
 *  - Fast PWM mode is enabled (WGM00 & WGM01).
 *  - Non-inverting mode is selected (COM01).
 *  - Prescaler = F_CPU/1024 (CS00 & CS02).
 */
void PWM_Timer0_Start(uint8 duty_cycle) {
    /* Reset Timer0 counter */
    TCNT0 = 0;

    /* Calculate and set Compare Match value (OCR0) based on duty cycle */
    OCR0 = (duty_cycle * PWM_MAX_VALUE) / PWM_OFFSET;

    /* Configure Timer0:
     * - Fast PWM mode
     * - Non-inverting mode
     * - Prescaler = F_CPU/1024
     */
    TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00) | (1<<CS02);
}
