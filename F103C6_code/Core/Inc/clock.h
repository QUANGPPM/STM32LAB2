/*
 * clock.h
 *
 *  Created on: Oct 4, 2024
 *      Author: PC
 */

#ifndef INC_CLOCK_H_
#define INC_CLOCK_H_

#include "main.h"

#define LED_OFF GPIO_PIN_RESET	//because GPIO pin connect to postive pin of LED
#define LED_ON GPIO_PIN_SET


void update_LED(uint8_t* buffer);
void full_clock_run();

#endif /* INC_CLOCK_H_ */
