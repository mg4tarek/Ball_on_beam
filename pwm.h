 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the PWM driver
 *
 * Author: Mohamed Gamal
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

/****************************************/

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*
 * Define the maximum overflow value for Timer0.
 * This is used to set the maximum count for an 8-bit timer, which is 255.
 */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Function to start PWM on Timer0 with a specified duty cycle.
 * It allows the user to control the brightness of an LED or the speed of a motor.
 */
void PWM_Timer1_start(uint16 duty_cycle);

#endif /* PWM_H_ */

