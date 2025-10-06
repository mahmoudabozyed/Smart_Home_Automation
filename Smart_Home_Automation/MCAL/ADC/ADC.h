 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Mahmoud Abouzeid
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "../../MCAL/GPIO/std_type.h"

/*******************************************************************************
*                                Definitions                                  *
*******************************************************************************/

#define ADC_MAXIMUM_VALUE    1023ul
#define ADC_REF_VOLT_VALUE   2.56


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);


#endif /* ADC_H_ */
