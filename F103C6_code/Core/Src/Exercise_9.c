/*
 * Exercise_1.c
 *
 *  Created on: Sep 24, 2024
 *      Author: PC
 */

#include <Exercise_9.h>

#define DELAY 100

const uint8_t MAX_LED_MATRIX = 8;
uint8_t index_led_matrix = 0;
uint8_t matrix_buffer[8] = {'&','2','3','4','5','6','7','A'};


void updateLEDMatrix(uint8_t index){
	switch(index){
		case 0:
			display_on_screen(matrix_buffer[0], DELAY);
			break;
		case 1:
			display_on_screen(matrix_buffer[1], DELAY);
			break;
		case 2:
			display_on_screen(matrix_buffer[2], DELAY);
			break;
		case 3:
			display_on_screen(matrix_buffer[3], DELAY);
			break;
		case 4:
			display_on_screen(matrix_buffer[4], DELAY);
			break;
		case 5:
			display_on_screen(matrix_buffer[5], DELAY);
			break;
		case 6:
			display_on_screen(matrix_buffer[6], DELAY);
			break;
		case 7:
			display_on_screen(matrix_buffer[7], DELAY);
			break;
	}
}


void exercise_run(){

	updateLEDMatrix(0);
}

