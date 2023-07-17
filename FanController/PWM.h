/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.h
 *
 * Description: Header file of PWM Driver
 *
 * Author: Hossam-Ragab
 *
 *******************************************************************************/
#ifndef PWM_H_
#define PWM_H_

#include "Standard_Types.h"

/*******************************************************************************
 *                                Functions Prototypes                         *
 *******************************************************************************/

/*
 * Description :
 * function to Trigger PWM through Timer0
 */
void PWM_Timer0_Start(uint8 DutyCycle);

#endif /* PWM_H_ */
