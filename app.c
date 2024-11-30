/*
 * app.c
 *
 *  Created on: Nov 26, 2024
 *      Author: Lenovo
 */
#include "motor.h"
#include "ultrasonic.h"
#include "util/delay.h"
#include "gpio.h"
#include "avr/io.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define KP 42.08
#define KI 17.11
#define KD 25.29
#define SET_POINT 15
#define MAP(x, in_min, in_max, out_min, out_max)  \
    ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
/*******************************************************************************
 *                                                                             *
 *******************************************************************************/

float32 priError = 0;
float32 toError = 0;

int main()
{
	SREG|=(1<<7);
	uint16 distance, setpoint;
	sint16 error, servoAngle;
	float32 Pvalue, Ivalue, Dvalue, PIDvalue;

	Motor_init();
	Ultrasonic_init();


	for(;;)
	{
		distance = Ultrasonic_readDistance();
		setpoint = SET_POINT;

		error = (sint16)(setpoint - distance);
		Pvalue = error * KP;
		Ivalue = toError * KI;
		Dvalue = (error - priError) * KD;

		PIDvalue = Pvalue + Ivalue + Dvalue;

		priError = error;
		toError += error;

		servoAngle = (sint32)PIDvalue;

		servoAngle = MAP(servoAngle, -135, 135, 135, 0);
		if (servoAngle > 135)
		{
			servoAngle = 135;
		}
		if (servoAngle < 0)
		{
			servoAngle = 0;
		}

		setServoPosition(servoAngle);
		_delay_ms(20);
	}

}
