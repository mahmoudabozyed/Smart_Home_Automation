/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: LCD.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Mahmoud Abouzeid
 *
 *******************************************************************************/

#include "LCD.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "../../MCAL/GPIO/common_macros.h"
#include <util/delay.h>
#include <stdlib.h>

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the direction of RS, E, and Data bus pins.
 * 2. Send initialization commands to configure LCD.
 */
void LCD_init(void){
	GPIO_setupPinDirection(LCD_RS_PORT,LCD_RS_PIN,pin_output);   // RS pin as output
	GPIO_setupPinDirection(LCD_E_PORT,LCD_E_PIN,pin_output);     // E pin as output
	_delay_ms(20); 												 // Wait for LCD power up
#if(LCD_DATA_BITS_MODE == 4)

	GPIO_setupPinDirection(LCD_DATA_BUS,LCD_DB4_PIN_ID,pin_output);
	GPIO_setupPinDirection(LCD_DATA_BUS,LCD_DB5_PIN_ID,pin_output);
	GPIO_setupPinDirection(LCD_DATA_BUS,LCD_DB6_PIN_ID,pin_output);
	GPIO_setupPinDirection(LCD_DATA_BUS,LCD_DB7_PIN_ID,pin_output);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommond(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommond(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommond(LCD_TWO_LINES_FOUR_BITS_MODE);


#else
	GPIO_setupPortDirection(LCD_DATA_BUS,port_output);           // Data bus as output

	LCD_sendCommond(LCD_TWO_LINES_EIGHT_BITS_MODE);              // Function set: 2 lines, 8-bit mode
#endif
	LCD_sendCommond(LCD_CURSOR_OFF);                             // Turn cursor off
	LCD_sendCommond(LCD_CLEAR_SCREEN);                           // Clear display
}

/*
 * Description :
 * Send a command to the LCD
 */
void LCD_sendCommond(uint8 commond){
	GPIO_writePin(LCD_RS_PORT,LCD_RS_PIN,LOW);    // RS=0 for command mode
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT,LCD_E_PIN,HIGH);     // Enable = 1
	_delay_ms(1);
#if (LCD_DATA_BITS_MODE == 4)
	GPIO_writePin(LCD_DATA_BUS,LCD_DB4_PIN_ID,GET_BIT(commond,4));
	GPIO_writePin(LCD_DATA_BUS,LCD_DB5_PIN_ID,GET_BIT(commond,5));
	GPIO_writePin(LCD_DATA_BUS,LCD_DB6_PIN_ID,GET_BIT(commond,6));
	GPIO_writePin(LCD_DATA_BUS,LCD_DB7_PIN_ID,GET_BIT(commond,7));

	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT,LCD_E_PIN,LOW);      // Enable = 0 (Latch data)
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT,LCD_E_PIN,HIGH);      // Enable = 1 (Latch data)

	GPIO_writePin(LCD_DATA_BUS,LCD_DB4_PIN_ID,GET_BIT(commond,0));
	GPIO_writePin(LCD_DATA_BUS,LCD_DB5_PIN_ID,GET_BIT(commond,1));
	GPIO_writePin(LCD_DATA_BUS,LCD_DB6_PIN_ID,GET_BIT(commond,2));
	GPIO_writePin(LCD_DATA_BUS,LCD_DB7_PIN_ID,GET_BIT(commond,3));

	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT,LCD_E_PIN,LOW);      // Enable = 0 (Latch data)
	_delay_ms(1);
#else
	GPIO_writePort(LCD_DATA_BUS,commond);         // Send command on data bus
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT,LCD_E_PIN,LOW);      // Enable = 0 (Latch data)
	_delay_ms(1);
#endif
}

/*
 * Description :
 * Display a single character on the LCD
 */
void LCD_displayChar(uint8 data){
	GPIO_writePin(LCD_RS_PORT,LCD_RS_PIN,HIGH);    // RS=1 for char mode
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT,LCD_E_PIN,HIGH);     // Enable = 1
	_delay_ms(1);
#if (LCD_DATA_BITS_MODE == 4)
	GPIO_writePin(LCD_DATA_BUS,LCD_DB4_PIN_ID,GET_BIT(data,4));
	GPIO_writePin(LCD_DATA_BUS,LCD_DB5_PIN_ID,GET_BIT(data,5));
	GPIO_writePin(LCD_DATA_BUS,LCD_DB6_PIN_ID,GET_BIT(data,6));
	GPIO_writePin(LCD_DATA_BUS,LCD_DB7_PIN_ID,GET_BIT(data,7));

	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT,LCD_E_PIN,LOW);      // Enable = 0 (Latch data)
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT,LCD_E_PIN,HIGH);      // Enable = 1 (Latch data)

	GPIO_writePin(LCD_DATA_BUS,LCD_DB4_PIN_ID,GET_BIT(data,0));
	GPIO_writePin(LCD_DATA_BUS,LCD_DB5_PIN_ID,GET_BIT(data,1));
	GPIO_writePin(LCD_DATA_BUS,LCD_DB6_PIN_ID,GET_BIT(data,2));
	GPIO_writePin(LCD_DATA_BUS,LCD_DB7_PIN_ID,GET_BIT(data,3));

	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT,LCD_E_PIN,LOW);      // Enable = 0 (Latch data)
	_delay_ms(1);
#else
	GPIO_writePort(LCD_DATA_BUS,data);         // Send command on data bus
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT,LCD_E_PIN,LOW);      // Enable = 0 (Latch data)
	_delay_ms(1);
#endif
}

/*
 * Description :
 * Display a string on the LCD
 */
void LCD_displayString(uint8 *str){
	uint8 i = 0;
	while(str[i] != '\0'){                        // Loop until end of string
		LCD_displayChar(str[i]);                  // Display each character
		i++;
	}
}

/*
 * Description :
 * Move the cursor to a specific row and column
 */
void LCD_moveCursur(uint8 row, uint8 col){
	uint8 lcd_memory_address;

	switch(row){
	case 0:
		lcd_memory_address = col;
		break;
	case 1:
		lcd_memory_address = col + 0x40;
		break;
	case 2:
		lcd_memory_address = col + 0x10;
		break;
	case 3:
		lcd_memory_address = col + 0x50;
		break;
	}
	LCD_sendCommond(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display a string starting from a specific row and column
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursur(row,col);   // Move cursor to required position
	LCD_displayString(Str);    // Display string
}

/*
 * Description :
 * Convert an integer value to string and display it on the LCD
 */
void LCD_itos(uint8 data){
	uint8 buff[16];                 // Buffer to store string result
	itoa(data,buff,10);             // Convert integer to string (base 10)
	LCD_displayString(buff);        // Display string on LCD
}

/*
 * Description :
 * Clear the LCD screen
 */
void LCD_clearScreen(void){
	LCD_sendCommond(LCD_CLEAR_SCREEN);
}
