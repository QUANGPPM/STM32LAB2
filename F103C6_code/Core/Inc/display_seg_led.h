#ifndef  DISPLAY_SEG_LED__
#define  DISPLAY_SEG_LED__

#include "main.h"
#define SEG_ON GPIO_PIN_RESET	//because GPIO pin connect to negative pin of LED
#define SEG_OFF GPIO_PIN_SET

typedef struct{
	GPIO_TypeDef *SEG_GPIOx;
	uint16_t SEG_Pin;
}com_t;

typedef enum{
	ZERO = 0u,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE
}SEG_state;
typedef struct{
	com_t A_seg;
	com_t B_seg;
	com_t C_seg;
	com_t D_seg;
	com_t E_seg;
	com_t F_seg;
	com_t G_seg;
	SEG_state state;
}sevenSEG_ANODE_t;


void init_display(GPIO_TypeDef *A_GPIOx, uint16_t A_Pin,
					GPIO_TypeDef *B_GPIOx, uint16_t B_Pin,
					GPIO_TypeDef *C_GPIOx, uint16_t C_Pin,
					GPIO_TypeDef *D_GPIOx, uint16_t D_Pin,
					GPIO_TypeDef *E_GPIOx, uint16_t E_Pin,
					GPIO_TypeDef *F_GPIOx, uint16_t F_Pin,
					GPIO_TypeDef *G_GPIOx, uint16_t G_Pin);
void clear_all_LED();
void execute_7SEG_LED(SEG_state state);
void exercise4_run();


#endif
