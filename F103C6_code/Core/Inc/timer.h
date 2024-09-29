/*
 * timer.h
 *
 *  Created on: Sep 29, 2024
 *      Author: PC
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "main.h"

#define TICK 10

extern uint8_t timer_flag[10];

void timerInit();
void setTimer(uint32_t index, uint32_t counter);

#endif /* INC_TIMER_H_ */
