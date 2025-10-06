/******************************************************************************
 *
 * Module: FLAME
 *
 * File Name: FLAME.c
 *
 * Description: Source file for the Flame Sensor driver
 *
 * Author: Mahmoud Abouzeid
 *
 *******************************************************************************/

#include "FLAME.h"
#include "../../MCAL/GPIO/GPIO.h"

/*
 * Description:
 * Initialize the Flame Sensor:
 * - Configure the sensor pin as input (because we read its value).
 */
void FlameSensor_init(void){
    GPIO_setupPinDirection(FLAME_SENSOR_PORT, FLAME_SENSOR_PIN, pin_input);
}

/*
 * Description:
 * Read the digital value from the Flame Sensor.
 *
 * Returns:
 *  - 0 (LOW): No flame detected
 *  - 1 (HIGH): Flame detected
 */
uint8 FlameSensor_getValue(void){
    uint8 FlameSensorValue = GPIO_readPin(FLAME_SENSOR_PORT, FLAME_SENSOR_PIN);
    return FlameSensorValue;
}
