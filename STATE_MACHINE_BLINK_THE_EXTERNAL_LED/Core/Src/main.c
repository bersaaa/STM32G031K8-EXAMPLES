#include "stm32g0xx.h"
void delay(volatile uint32_t);
enum mode{mode0, mode1, mode2, mode3, mode4, mode5};
volatile enum mode state;
void EXTI2_3_IRQHandler(void) {
	if (state != 5) {
		state ++;
	}
	else {
		state = 0;
	}
	delay(100000);
	EXTI->RPR1 |= (1U << 3);
}
int main(void) {
	/* Enable GPIOB clock */
	RCC->IOPENR |= (1U << 1);
	/* Setup PB3 as input */
	GPIOB->MODER &= ~(3U << 2*3);
	/* Setup PB0 as output */
	GPIOB->MODER &= ~(3U);
	GPIOB->MODER |= (1U);
	EXTI->RTSR1 |= (1U << 3); // B3
	EXTI->EXTICR[0] |= (1U << 8*3);
	EXTI->IMR1 |= (1U << 3);
	NVIC_SetPriority(EXTI2_3_IRQn, 0);
	NVIC_EnableIRQ(EXTI2_3_IRQn);
	while(1) {
		switch(state){
		case 0:
			GPIOB->BRR |= (1U); // turn off led
			break;
		case 1:
			GPIOB->ODR ^= (1U);
			delay(3200000);
			break;
		case 2:
			GPIOB->ODR ^= (1U);
			delay(1600000);
			break;
		case 3:
			GPIOB->ODR ^= (1U);
			delay(800000);
			break;
		case 4:
			GPIOB->ODR ^= (1U);
			delay(160000);
			break;
		case 5:
			GPIOB->ODR |= (1U); // turn on led
			break;
		}
	}
	return 0;
}
void delay(volatile uint32_t s) {
	for(; s>0; s--);
}
