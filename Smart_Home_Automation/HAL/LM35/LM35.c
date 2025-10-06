/******************************************************************************
 *
 * Module: LM35
 *
 * File Name: LM35.c
 *
 * Description: Source file for the LM35 Temperature Sensor driver
 *
 * Author: Mahmoud Abouzied
 *
 *******************************************************************************/

#include "../../HAL/LM35/LM35.h"
#include "../../MCAL/ADC/ADC.h"

/*
 * Description:
 * Get the current temperature from the LM35 sensor.
 *
 * Steps:
 *  1. Read the ADC digital value from the LM35 channel.
 *  2. Convert the digital value into temperature (°C) using the sensor formula:
 *     Temp = (ADC_value * Max_Temperature * Vref) / (Max_Voltage * ADC_Max)
 *
 * Returns:
 *  - Temperature in Celsius (0 → SENSOR_MAX_TEMPERATURE).
 */
uint8 LM35_getTemperature(void){
    uint8 temp_value = 0;       /* Final temperature value in °C */
    uint16 adc_digital_value = 0; /* Raw ADC digital value */

    /* Step 1: Read ADC value from LM35 sensor channel */
    adc_digital_value = ADC_readChannel(SENSOR_CHANNEL_ID);

    /* Step 2: Convert ADC value to temperature (°C) */
    temp_value = (uint8)(((uint32)adc_digital_value * SENSOR_MAX_TEMPERATURE * ADC_REF_VOLT_VALUE)
                         / (SENSOR_MAX_VOLT_VALUE * ADC_MAXIMUM_VALUE));

    return temp_value;
}
