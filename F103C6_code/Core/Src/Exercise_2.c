/*
 * Exercise_1.c
 *
 *  Created on: Sep 24, 2024
 *      Author: PC
 */

#include <Exercise_2.h>

Seg_active active_flag = SEGMENT_0;

void init_exercise(Seg_active flag){
	active_flag  = flag;
}

void exercise_run(){
	switch(active_flag){
		case SEGMENT_0:
			clear_all_LED();
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			execute_7SEG_LED(1);
			active_flag = SEGMENT_1;
			break;
		case SEGMENT_1:
			clear_all_LED();
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			execute_7SEG_LED(2);
			active_flag = SEGMENT_2;
			break;
		case SEGMENT_2:
			clear_all_LED();
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			execute_7SEG_LED(3);
			active_flag = SEGMENT_3;
			break;
		case SEGMENT_3:
			clear_all_LED();
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			execute_7SEG_LED(0);
			active_flag = SEGMENT_0;
			break;
	}


}

