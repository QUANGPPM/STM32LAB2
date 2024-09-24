/*
 * Exercise_1.h
 *
 *  Created on: Sep 24, 2024
 *      Author: PC
 */

#ifndef INC_EXERCISE_2_H_
#define INC_EXERCISE_2_H_
#include "display_seg_led.h"

typedef enum{
	SEGMENT_0,
	SEGMENT_1,
	SEGMENT_2,
	SEGMENT_3
}Seg_active;

extern uint8_t display_flag;

void init_exercise(Seg_active flag);

void exercise_run();

#endif /* INC_EXERCISE_2_H_ */
