#include "display_seg_led.h"

sevenSEG_ANODE_t LED_segment;

void init_display(GPIO_TypeDef *A_GPIOx, uint16_t A_Pin,
					GPIO_TypeDef *B_GPIOx, uint16_t B_Pin,
					GPIO_TypeDef *C_GPIOx, uint16_t C_Pin,
					GPIO_TypeDef *D_GPIOx, uint16_t D_Pin,
					GPIO_TypeDef *E_GPIOx, uint16_t E_Pin,
					GPIO_TypeDef *F_GPIOx, uint16_t F_Pin,
					GPIO_TypeDef *G_GPIOx, uint16_t G_Pin){
	LED_segment.A_seg.SEG_GPIOx = A_GPIOx;
	LED_segment.A_seg.SEG_Pin = A_Pin;

	LED_segment.B_seg.SEG_GPIOx = B_GPIOx;
	LED_segment.B_seg.SEG_Pin = B_Pin;

	LED_segment.C_seg.SEG_GPIOx = C_GPIOx;
	LED_segment.C_seg.SEG_Pin = C_Pin;

	LED_segment.D_seg.SEG_GPIOx = D_GPIOx;
	LED_segment.D_seg.SEG_Pin = D_Pin;

	LED_segment.E_seg.SEG_GPIOx = E_GPIOx;
	LED_segment.E_seg.SEG_Pin = E_Pin;

	LED_segment.F_seg.SEG_GPIOx = F_GPIOx;
	LED_segment.F_seg.SEG_Pin = F_Pin;

	LED_segment.G_seg.SEG_GPIOx = G_GPIOx;
	LED_segment.G_seg.SEG_Pin = G_Pin;
}

void display7SEG(uint8_t A_LED, uint8_t B_LED, uint8_t C_LED, uint8_t D_LED,
				 uint8_t E_LED, uint8_t F_LED, uint8_t G_LED){
	HAL_GPIO_WritePin(LED_segment.A_seg.SEG_GPIOx, LED_segment.A_seg.SEG_Pin, A_LED);
	HAL_GPIO_WritePin(LED_segment.B_seg.SEG_GPIOx, LED_segment.B_seg.SEG_Pin, B_LED);
	HAL_GPIO_WritePin(LED_segment.C_seg.SEG_GPIOx, LED_segment.C_seg.SEG_Pin, C_LED);
	HAL_GPIO_WritePin(LED_segment.D_seg.SEG_GPIOx, LED_segment.D_seg.SEG_Pin, D_LED);
	HAL_GPIO_WritePin(LED_segment.E_seg.SEG_GPIOx, LED_segment.E_seg.SEG_Pin, E_LED);
	HAL_GPIO_WritePin(LED_segment.F_seg.SEG_GPIOx, LED_segment.F_seg.SEG_Pin, F_LED);
	HAL_GPIO_WritePin(LED_segment.G_seg.SEG_GPIOx, LED_segment.G_seg.SEG_Pin, G_LED);
}

void execute_7SEG_LED(SEG_state state){
	switch(state)
	{
		case ZERO:
			display7SEG(SEG_ON, SEG_ON, SEG_ON, SEG_ON, SEG_ON, SEG_ON, SEG_OFF);
			break;
		case ONE:
			display7SEG(SEG_OFF, SEG_ON, SEG_ON, SEG_OFF, SEG_OFF, SEG_OFF, SEG_OFF);
			break;
		case TWO:
			display7SEG(SEG_ON, SEG_ON, SEG_OFF, SEG_ON, SEG_ON, SEG_OFF, SEG_ON);
			break;
		case THREE:
			display7SEG(SEG_ON, SEG_ON, SEG_ON, SEG_ON, SEG_OFF, SEG_OFF, SEG_ON);
			break;
		case FOUR:
			display7SEG(SEG_OFF, SEG_ON, SEG_ON, SEG_OFF, SEG_OFF, SEG_ON, SEG_ON);
			break;
		case FIVE:
			display7SEG(SEG_ON, SEG_OFF, SEG_ON, SEG_ON, SEG_OFF, SEG_ON, SEG_ON);
			break;
		case SIX:
			display7SEG(SEG_ON, SEG_OFF, SEG_ON, SEG_ON, SEG_ON, SEG_ON, SEG_ON);
			break;
		case SEVEN:
			display7SEG(SEG_ON, SEG_ON, SEG_ON, SEG_OFF, SEG_OFF, SEG_OFF, SEG_OFF);
			break;
		case EIGHT:
			display7SEG(SEG_ON, SEG_ON, SEG_ON, SEG_ON, SEG_ON, SEG_ON, SEG_ON);
			break;
		case NINE:
			display7SEG(SEG_ON, SEG_ON, SEG_ON, SEG_ON, SEG_OFF, SEG_ON, SEG_ON);
			break;
//		default:
//			break;
	}
}

//void exercise4_run(){
//	if(counter < 0) counter = 9;
//	execute_7SEG_LED(counter--);
//}

















