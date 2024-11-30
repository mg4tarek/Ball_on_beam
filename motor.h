 /******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.h
 *
 * Description: Header file for the Motor driver
 *
 * Author: Mohamed Gamal
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*
 * Define the port and control pins for the DC motor.
 * These macros are used to specify the connections for controlling the motor.
 */


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


void setServoPosition(sint32 angle);
void Motor_init(void);

#endif /* MOTOR_H_ */

