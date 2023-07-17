/******************************************************************************
 *
 * Module: LM35
 *
 * File Name: LM35.c
 *
 * Description: Source file of LM35 Driver
 *
 * Author: Hossam-Ragab
 *
 *******************************************************************************/
#include "LM35.h"
#include "ADC.h"


#if (ADC_TECHNIQUE == INTERRUPT)
#include <util/delay.h>
extern uint16 g_AdcValue;
#endif

uint8 LM35_GetTemperature(void)
{
	uint8 Temp_Value = 0;

#if (ADC_TECHNIQUE == INTERRUPT)
	ADC_ReadChannel(ADC2);
	_delay_ms(5);
	Temp_Value = (uint8)(((uint32)g_AdcValue*SENSOR_MAX_TEMPERATURE*ADC_REFRENCE_VOLTAGE)/(ADC_MAX_DIGITAL_VALUE*SENSOR_MAX_VOLTAGE));

#elif (ADC_TECHNIQUE == POLLING)
	uint16 Adc_Value = 0;
	Adc_Value = ADC_ReadChannel(ADC2);/*Read temperature from channel number 2*/
	Temp_Value = (uint8)(((uint32)Adc_Value*SENSOR_MAX_TEMPERATURE*ADC_REFRENCE_VOLTAGE)/(ADC_MAX_DIGITAL_VALUE*SENSOR_MAX_VOLTAGE));
#endif

	return Temp_Value;

}
