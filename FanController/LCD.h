/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: LCD.h
 *
 * Description: Header file of AVR LCD Driver
 *
 * Author: Hossam-Ragab
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "Standard_Types.h"

/*******************************************************************************
 *                         Macros For making LCD driver more readable        *
 *******************************************************************************/

#define 	LCD_DATA_MODE	8

#define 	ROW0_ID			0
#define 	ROW1_ID			1
#define 	ROW2_ID			2
#define 	ROW3_ID			3

/*******************************************************************************
 *                         Macros For Defining Commands of LCD              *
 *******************************************************************************/
#define		LCD_TWO_LINES_8_BITS			 0x38
#define 	LCD_TWO_LINES_4_BITS			 0x28
#define 	LCD_CLEAR_DISPLAY				 0x01
#define 	LCD_CURSOR_OFF					 0x0C
#define 	LCD_SET_CURSOR_LOCATION  		 0x80

/*******************************************************************************
 *                                Functions Prototypes                         *
 *******************************************************************************/
void LCD_Init(void);
void LCD_SendCommand(uint8 Command);
void LCD_DisplayCharacter(char Character);
void LCD_DisplayString(const char *String);
void LCD_MoveCursor(uint8 Row, uint8 Column);
void LCD_DisplayStringRowColumn(uint8 Row, uint8 Column, const char *String);
void LCD_IntegerToString(int Data);
void LCD_ClearDiplay(void);


#endif /* LCD_H_ */
