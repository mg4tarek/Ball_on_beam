/******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: ultrasonic.c
 *
 * Description: Source file for the Ultrasonic driver
 *
 * Author: Mohamed Gamal
 *
 *******************************************************************************/
#include "ultrasonic.h"
#include "icu.h"
#include "gpio.h"
#include <util/delay.h>

// Static variables to restrict their scope to this file
static uint8 g_edgeCount = 0; // Counter for edge detection
static uint16 g_timeHigh = 0;  // Time duration for echo signal
static uint16 distance_cm = 0; // Calculated distance in cm

static ICU_ConfigType ICU_Configurations = {F_CPU_8, RAISING}; // ICU configuration

// Edge processing function called on edge detection
static void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeHigh = ICU_getInputCaptureValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);
		ICU_clearTimerValue();
	}

}

// Initialization function for the ultrasonic sensor
void Ultrasonic_init(void)
{
	ICU_init(&ICU_Configurations); // Initialize ICU
	ICU_setCallBack(&Ultrasonic_edgeProcessing); // Set edge processing callback
	GPIO_setupPinDirection(TRIGGER_PORT, TRIGGER_PIN, PIN_OUTPUT); // Set trigger pin as output
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_LOW); // Ensure trigger pin is low
}

// Trigger the ultrasonic sensor
static void Ultrasonic_Trigger(void)
{
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_HIGH); // Send trigger signal
	_delay_us(10); // Trigger pulse width for HC-SR04
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_LOW); // Set trigger pin low
}

// Read distance from the ultrasonic sensor
uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();

	while (g_edgeCount < 2);
	g_edgeCount = 0;

	distance_cm = (uint16)( (float32)(g_timeHigh ) / 117.6 );

	return (distance_cm+1);
}
