/******************************************************************************
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: Hossam-Ragab
 *
 *******************************************************************************/

#include "ADC.h"
#include "Common_Macros.h"
#include <avr/interrupt.h>

#if (ADC_TECHNIQUE == INTERRUPT)
volatile uint16 g_AdcValue = 0;
#endif

/*
 * Description :
 * function to InItialize ADC Register
 */
void ADC_Init(const ADC_Configure *Configure_Ptr)
{

	/*Voltage Reference Selection*/
	ADMUX_REG = (ADMUX_REG & 0x3F) | ((Configure_Ptr->Refrence)<<6);
	/*Analog Channel and Gain Selection Bits*/
	ADMUX_REG = (ADMUX_REG & 0xE0) | (Configure_Ptr->Channel);
	/*Representation of the ADC conversion result in ADC Data Register*/
	ADMUX_REG = (ADMUX_REG & 0xDF) | ((Configure_Ptr->Represent)<<5);
	/*ADC Enable*/
	ADCSRA_REG |= (1<<ADEN_PIN7) ;
	/*ADC Pre-scaler Select Bits*/
	ADCSRA_REG = (ADCSRA_REG & 0xF8) | (Configure_Ptr->Clock);

#if (ADC_TECHNIQUE == INTERRUPT)
	/*ADC Enable Interrupt Pin*/
	ADCSRA_REG |= (1<<ADIE_PIN3);
#endif

	/*Source trigger an ADC conversion*/
	SFIOR_REG = ((Configure_Ptr->Trigger_Mode)<<5);

}

#if (ADC_TECHNIQUE == INTERRUPT)
/*
 * Description :
 * function to return digital value from ADC after conversion
 */
void ADC_ReadChannel(uint8 Channel_Number)
{
	/* Insert Channel Number inside ADMUX_REG to start conversion on this Channel Number*/
	ADMUX_REG = (ADMUX_REG & 0xE0) | (Channel_Number);
	/* Start conversion */
	SET_BIT(ADCSRA_REG,ADSC_PIN6);
}

ISR(ADC_vect)
{
	g_AdcValue = ADC_REG;

}

#elif	(ADC_TECHNIQUE == POLLING)
/*
 * Description :
 * function to return digital value from ADC after conversion
 */
uint16 ADC_ReadChannel(uint8 Channel_Number)
{
	/* Insert Channel Number inside ADMUX_REG to start conversion on this Channel Number*/
	ADMUX_REG = (ADMUX_REG & 0xE0) | (Channel_Number & 0x07);
	/* Start conversion */
	SET_BIT(ADCSRA_REG,ADSC_PIN6);
	/*polling until conversion complete that makes ADIF = 1 */
	while(BIT_IS_CLEAR(ADCSRA_REG,ADIF_PIN4)){}
	/* clear ADIF by set this bit by one */
	SET_BIT(ADCSRA_REG,ADIF_PIN4);
	/*return data after conversion from ADC Register*/
	return ADC_REG;
}

#endif
