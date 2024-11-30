 /******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for the Ultrasonic driver
 *
 * Author: Mohamed Gamal
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "std_types.h"

#define TRIGGER_PORT    PORTD_ID
#define TRIGGER_PIN  	PIN7_ID


void Ultrasonic_init(void);
uint16 Ultrasonic_readDistance(void);

#endif /* ULTRASONIC_H_ */
