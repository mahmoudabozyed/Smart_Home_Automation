/******************************************************************************
 *
 * Module: LDR
 *
 * File Name: LDR.c
 *
 * Description: Source file for the LDR driver
 *
 * Author: Mahmoud Abouzied
 *
 *******************************************************************************/

#include "LDR.h"
#include "../../MCAL/ADC/ADC.h"

/*
 * Description:
 * Read the light intensity from the LDR sensor.
 *
 * Steps:
 *  1. Read the ADC digital value from the LDR channel.
 *  2. Convert the digital ADC value into a percentage (0% → 100%)
 *     using the maximum ADC value and sensor configuration.
 *
 * Returns:
 *  - Light intensity as a percentage (0 → 100).
 */
uint16 LDR_getLightIntensity(void){
    /* Step 1: Read digital value from the ADC channel connected to the LDR */
    uint16 adc_digital_value = (uint16)ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

    /* Step 2: Scale the ADC value into a percentage (0–100%) */
    uint16 ldr_value = (uint16)(((uint32)adc_digital_value * LDR_SENSOR_MAX_LIGHT_INTENSITY) / ADC_MAXIMUM_VALUE);

    return ldr_value;
}
