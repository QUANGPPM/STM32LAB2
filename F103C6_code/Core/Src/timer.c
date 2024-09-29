/*
 * timer.c
 *
 *  Created on: Sep 29, 2024
 *      Author: PC
 */
#include <timer.h>

uint32_t timer_counter[10];
uint8_t timer_flag[10];

void timerInit(){
	for(uint8_t i = 0; i < 10; i++){
		setTimer(i, 10);
	}
}

void setTimer(uint32_t index, uint32_t counter){
	timer_flag[index] = 0;
	timer_counter[index] = counter/TICK;
}

void timeRun(){
	for(uint32_t i = 0; i < 10; i++){
		if(timer_counter[i] >= 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0)
				timer_flag[i] = 1;
		}
	}
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	timeRun();
}
