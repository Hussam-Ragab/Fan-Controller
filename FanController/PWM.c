/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.c
 *
 * Description: Source file of PWM Driver
 *
 * Author: Hossam-Ragab
 *
 *******************************************************************************/

#include <avr/io.h>
#include "PWM.h"

void PWM_Timer0_Start(uint8 DutyCycle)
{

	uint8 MotorSpeed;

	MotorSpeed = (((float32)DutyCycle/100)*255);

	DDRB |= (1<<PB3); //Data Direction Register PB3 as output to enable OC0

	/*
	 * Waveform Generation Fast PWM Mode:
	 * 1) Set WGM01 & WGM00
	 * 2) Compare Output Mode, Fast PWM Mode Non inverting Mode Set COM01
	 * 3) according to equation in Timer0 PWM --- prescaler = 8
	 * 		F_PWM = F_CPU/N*256
	 * 		4000 = (8*10^6)/N*256
	 * 		N = 8
	 *	Set CS01 for prescaler 8
	 *
	 *
	 * */

	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

	TCNT0 = 0;

	OCR0 = MotorSpeed;
}
