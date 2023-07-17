/******************************************************************************
 *
 * Module: Motor
 *
 * File Name: Motor.h
 *
 * Description: Header file of Dc-Motor Driver
 *
 * Author: Hossam-Ragab
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_

#include "Standard_Types.h"

/*******************************************************************************
 *                         Macros For making LM35 driver more readable        *
 *******************************************************************************/

#define 	MOTOR_PORT_ID		PORTB_ID
#define 	MOTOR_PIN0_ID		PIN0_ID
#define 	MOTOR_PIN1_ID		PIN1_ID

/*******************************************************************************
 *                         Types Declaration of Dc-Motor         *
 *******************************************************************************/
typedef enum{
	Stop,
	ClockWise,
	Anti_ClockWise
}DcMotor_State;

/*******************************************************************************
 *                                Functions Prototypes                         *
 *******************************************************************************/

/*Initialization of Dc-Motor */
void DcMotor_Init(void);
/*
 * Description :
 * function to Rotate Dc-Motor according to State and Speed
 */
void DcMotor_Rotate(DcMotor_State State, uint8 Speed);

#endif /* MOTOR_H_ */
