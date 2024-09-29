/*
 * MATRIX_LED.h
 *
 *  Created on: Sep 28, 2024
 *      Author: PC
 */

#ifndef INC_MATRIX_LED_H_
#define INC_MATRIX_LED_H_
#include "main.h"
#include <timer.h>

#define EN  GPIO_PIN_RESET
#define DIS GPIO_PIN_SET

void setup_matrix(uint8_t image, uint8_t row);

void display_on_screen(uint8_t k, uint32_t time_delay);

#endif /* INC_MATRIX_LED_H_ */
