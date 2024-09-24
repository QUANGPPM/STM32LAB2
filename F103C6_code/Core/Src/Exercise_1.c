/*
 * Exercise_1.c
 *
 *  Created on: Sep 24, 2024
 *      Author: PC
 */

#include "Exercise_1.h"

uint8_t display_flag = 0;

void exercise_run(){
	if(!display_flag)
	{
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		execute_7SEG_LED(1);
		display_flag = 1;
	}
	else{
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		execute_7SEG_LED(2);
		display_flag = 0;
	}
}

