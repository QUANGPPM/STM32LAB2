/*
 * clock.c
 *
 *  Created on: Oct 4, 2024
 *      Author: PC
 */
#include <clock.h>

uint8_t second = 55;
uint8_t minute = 59;

uint8_t second_LED = 0;
uint8_t minute_LED = 59;
uint8_t hour_LED = 12;
uint8_t old_second_LED = 0;
uint8_t old_minute_LED = 0;
uint8_t old_hour_LED = 0;


void update_LED(uint8_t* buffer){
	buffer[0] = hour_LED / 10;
	buffer[1] = hour_LED % 10;

	buffer[2] = minute_LED /10;
	buffer[3] = minute_LED % 10;
}

uint8_t second_run(){
	//increase second
	second++;
	//update LED
	if(second % 5 == 0){
		second_LED = second/5;
	}
	//update infor to minute_run()
	if(second >= 60)
	{
		second = 0;
		second_LED = 0;
		return 1;
	}
	return 0;
}
uint8_t minute_run(){

	if(second_run())
	{
		//increase minute
		minute++;
		//update LED
		if(minute % 5 == 0){
			minute_LED = minute/5;
		}
		//update infor to hour_run()
		if(minute >= 60)
		{
			minute = 0;
			minute_LED = 0;
			return 1;
		}
	}
	return 0;
}
uint8_t clock_count(){
	if(minute_run())
	{
		hour_LED++;

		if(hour_LED >= 11)
		{
			hour_LED = 1;
			return 1;
		}
	}
	return 0;
}
void full_clock_run(){
	clock_count();
}








