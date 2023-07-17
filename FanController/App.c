/******************************************************************************
 * Module: Application
 *
 * File Name: App.c
 *
 * Description: Fan Controller project to control speed of Dc-Motor according to sensor temperature
 *
 * Author: Hossam-Ragab
 *
 *******************************************************************************/


#include "ADC.h"
#include "LCD.h"
#include "LM35.h"
#include "Motor.h"

int main(void)
{
	uint16 Temperature;
	ADC_Configure Configure = {Internal_Vref, ADC0, ADLAR_Low, F_CPU_8, Free_Running_mode};
	LCD_Init(); /*Initialize LCD driver */
	ADC_Init(&Configure); /*Initialize ADC driver */
	DcMotor_Init();/*Initialize Dc-Motor driver */
	LCD_MoveCursor(1,2);
	LCD_DisplayString("Temp =    C");
	while(1)
	{
		Temperature = LM35_GetTemperature();
		/* Display the temperature value every time at same position */
		LCD_MoveCursor(1,9);
		if(Temperature < 30)
		{
			DcMotor_Rotate(Stop, 0);
			LCD_IntegerToString(Temperature);
			LCD_MoveCursor(0,2);
			LCD_DisplayString("FAN IS OFF");
		}
		else if(Temperature >= 30 && Temperature < 60)
		{
			DcMotor_Rotate(ClockWise, 25);
			LCD_IntegerToString(Temperature);
			LCD_MoveCursor(0,2);
			LCD_DisplayString("FAN IS ON ");
		}
		else if(Temperature >= 60 && Temperature < 90)
		{
			DcMotor_Rotate(ClockWise, 50);
			LCD_IntegerToString(Temperature);
			LCD_MoveCursor(0,2);
			LCD_DisplayString("FAN IS ON ");
		}
		else if(Temperature >= 90 && Temperature < 120)
		{
			DcMotor_Rotate(ClockWise, 75);
			LCD_IntegerToString(Temperature);
			if(Temperature < 100)
			{
				LCD_MoveCursor(1,11);
				LCD_DisplayCharacter(' ');
			}
			LCD_MoveCursor(0,2);
			LCD_DisplayString("FAN IS ON ");
		}
		else
		{
			DcMotor_Rotate(ClockWise, 100);
			LCD_IntegerToString(Temperature);
			LCD_MoveCursor(0,2);
			LCD_DisplayString("FAN IS ON ");
		}
	}
}
