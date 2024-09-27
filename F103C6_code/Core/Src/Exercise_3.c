/*
 * Exercise_1.c
 *
 *  Created on: Sep 24, 2024
 *      Author: PC
 */

#include <Exercise_3.h>

#define EN GPIO_PIN_RESET
#define DIS GPIO_PIN_SET

const uint8_t MAX_LED = 4;
uint8_t index_led = 0;
uint8_t led_buffer[4] = {3, 3, 3, 4};

void init_exercise(uint8_t index){
	index_led  = index;
}

void enableSEG(uint8_t EN0, uint8_t EN1, uint8_t EN2, uint8_t EN3){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, EN0);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, EN1);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, EN2);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, EN3);
}

void update7SEG(uint8_t index){
	switch(index){
		case 0:
			enableSEG(EN, DIS, DIS, DIS);
			execute_7SEG_LED(led_buffer[0]);
			break;
		case 1:
			enableSEG(DIS, EN, DIS, DIS);
			execute_7SEG_LED(led_buffer[1]);
			break;
		case 2:
			enableSEG(DIS, DIS, EN, DIS);
			execute_7SEG_LED(led_buffer[2]);
			break;
		case 3:
			enableSEG(DIS, DIS, DIS, EN);
			execute_7SEG_LED(led_buffer[3]);
			break;
		default:
			break;
	}

}

void exercise_run(){
	if(index_led > 3){
		index_led = 0;
	}
	update7SEG(index_led++);

}

