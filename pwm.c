 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the PWM driver
 *
 * Author: Mohamed Gamal
 *
 *******************************************************************************/
//2000 ocr1b 0 //1600
//3000  0
//4000 -90 //5250

#include "pwm.h"
#include "gpio.h"
#include "avr/io.h"
#include "util/delay.h"

void PWM_Timer1_start(uint16 duty_cycle)
{
	TCNT1 = 0;
	OCR1A = 39999;

	OCR1B = duty_cycle;

	TCCR1A = (1<<WGM10)| (1<<WGM11) | (1<<COM1B1);

	TCCR1B = (1<<WGM12) | (1<<WGM13) | (1<<CS11);

}

