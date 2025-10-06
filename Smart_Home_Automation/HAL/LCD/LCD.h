/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: LCD.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Mahmoud Abouzeid
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "../../MCAL/GPIO/std_type.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


#define LCD_DATA_BITS_MODE 		 8

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

/* LCD Data Bus connected to Port C */
#define LCD_DATA_BUS             PORTC_ID
/* LCD Control pins (RS, E) connections */
#define LCD_RS_PORT              PORTD_ID
#define LCD_RS_PIN               PIN0_ID

#define LCD_E_PORT               PORTD_ID
#define LCD_E_PIN                PIN1_ID


#if (LCD_DATA_BITS_MODE == 4)

#define LCD_DB4_PIN_ID                 PIN3_ID
#define LCD_DB5_PIN_ID                 PIN4_ID
#define LCD_DB6_PIN_ID                 PIN5_ID
#define LCD_DB7_PIN_ID                 PIN6_ID

#endif

/* LCD Commands */
#define LCD_TWO_LINES_EIGHT_BITS_MODE   	 0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                  	 0x0C
#define LCD_CLEAR_SCREEN               	 	 0x01
#define LCD_SET_CURSOR_LOCATION         	 0x80

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions using the GPIO driver.
 * 2. Send the required commands to configure the LCD.
 */
void LCD_init(void);

/*
 * Description :
 * Send the required command to the LCD
 */
void LCD_sendCommond(uint8 commond);

/*
 * Description :
 * Display the required character on the LCD
 */
void LCD_displayChar(uint8 data);

/*
 * Description :
 * Display the required string on the LCD
 */
void LCD_displayString(uint8 *str);

/*
 * Description :
 * Display the required string in a specified row and column on the LCD
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);

/*
 * Description :
 * Move the cursor to a specified row and column on the LCD
 */
void LCD_moveCursur(uint8 row, uint8 col);

/*
 * Description :
 * Convert an integer value to string and display it on the LCD
 */
void LCD_itos(uint8 data);

/*
 * Description :
 * Clear the LCD screen
 */
void LCD_clearScreen(void);

#endif /* LCD_H_ */
