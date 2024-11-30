/******************************************************************************
 *
 * Module: Motor
 *
 * File Name: motor.c
 *
 * Description: Source file for the Motor driver
 *
 * Author: Mohamed Gamal
 *
 *******************************************************************************/
#include "motor.h"
#include "gpio.h"
#include "pwm.h"


void Motor_init(void)
{
	GPIO_setupPinDirection(PORTD_ID, PIN4_ID, PIN_OUTPUT);

}


void setServoPosition(sint32 angle)
{

	uint16 pulseWidth = (angle / 180.0) * 1000 + 1000;  // Map angle to pulse width (1000-2000 microseconds)

	uint16 duty_cycle = (pulseWidth * 40000) / 20000;  // scaling to match 40000 timer counts for 20ms period

	PWM_Timer1_start(duty_cycle);  // Set duty cycle for PWM (OCR1B controls the servo)

}

