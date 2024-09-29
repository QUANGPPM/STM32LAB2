/*
 * MATRIX_LED.c
 *
 *  Created on: Sep 28, 2024
 *      Author: PC
 */

#include "MATRIX_LED.h"



uint8_t col[8];
uint8_t row[8] = {1, 2, 4, 8, 16, 32, 64, 128};

uint8_t characterHEX[][8] = {
		{0x18,0x3C,0x66,0x66,0x7E,0x66,0x66,0x66},//A
		{0x78,0x64,0x68,0x78,0x64,0x66,0x66,0x7C},//B
		{0x3C,0x62,0x60,0x60,0x60,0x62,0x62,0x3C},//C
		{0x78,0x64,0x66,0x66,0x66,0x66,0x64,0x78},//D
		{0x3C,0x66,0x66,0x6E,0x76,0x66,0x66,0x3C},//0
		{0x18,0x38,0x58,0x18,0x18,0x18,0x18,0x7E},//1
		{0x3C,0x66,0x66,0x0C,0x18,0x30,0x7E,0x7E},//2
		{0x7E,0x0C,0x18,0x3C,0x06,0x06,0x46,0x3C},//3
		{0x0C,0x18,0x30,0x6C,0x6C,0x7E,0x0C,0x0C},//4
		{0x7E,0x60,0x60,0x7C,0x06,0x06,0x46,0x3C},//5
		{0x04,0x08,0x10,0x38,0x6C,0x66,0x66,0x3C},//6
		{0x7E,0x46,0x0C,0x18,0x18,0x18,0x18,0x18},//7
		{0x3C,0x66,0x66,0x3C,0x66,0x66,0x66,0x3C},//8
		{0x3C,0x66,0x66,0x36,0x1C,0x08,0x10,0x20},//9
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},// khoảng trắng
		{0x00,0x66,0xFF,0xFF,0x7E,0x3C,0x18,0x00}// hình trái tim, kí hiệu là '&'
};

char character[] = {'A','B','C','D','0','1','2','3','4','5','6','7','8','9',' ','&'};

void matrix_init(){

}


void setup_matrix(uint8_t image, uint8_t row){
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, !(image>>7 & 0b1));
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, !(image>>6 & 0b1));
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, !(image>>5 & 0b1));
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, !(image>>4 & 0b1));
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, !(image>>3 & 0b1));
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, !(image>>2 & 0b1));
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, !(image>>1 & 0b1));
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, !(image>>0 & 0b1));

	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, !(row>>0 & 0b1));
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, !(row>>1 & 0b1));
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, !(row>>2 & 0b1));
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, !(row>>3 & 0b1));
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, !(row>>4 & 0b1));
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, !(row>>5 & 0b1));
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, !(row>>6 & 0b1));
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, !(row>>7 & 0b1));
}



void displayImage(uint8_t *image, uint32_t duration){
	static uint8_t i = 0;
	static uint8_t scroll;
	static uint8_t shift;
	if(i >= 8){
		i = 0;
		scroll++;

	}
	if(scroll >= 1){
		scroll = 0;
		shift++;
	}
	if(shift >= 16){
		shift = 0;
	}
	uint16_t temp_char = (uint16_t)image[i] << 8;

	setup_matrix(temp_char>>shift, row[i]);
	i++;
}

void clearImage(){
	setup_matrix(0x00, 0x00);
}


void display_on_screen(uint8_t k, uint32_t time_delay){

	static uint8_t comfirm_char;
	static uint8_t index;
	if(!comfirm_char){
		for(uint8_t i = 0; i < sizeof(character); i++){
			if(k == character[i]){
				index = i;
			}
		}
		comfirm_char = 1;
	}

	if(timer_flag[2] == 1){
		displayImage(characterHEX[index], 0);
		setTimer(2, time_delay);
	}

}




