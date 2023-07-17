/******************************************************************************
 *
 * Module: LM35
 *
 * File Name: LM35.h
 *
 * Description: Header file of LM35 Driver
 *
 * Author: Hossam-Ragab
 *
 *******************************************************************************/
#ifndef LM35_H_
#define LM35_H_

#include "Standard_Types.h"

/*******************************************************************************
 *                         Macros For making LM35 driver more readable        *
 *******************************************************************************/
#define SENSOR_MAX_VOLTAGE	      1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                                Functions Prototypes                         *
 *******************************************************************************/
uint8 LM35_GetTemperature(void);

#endif /* LM35_H_ */
