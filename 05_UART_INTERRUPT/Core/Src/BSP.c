#include "stm32g0xx.h"
#include "bsp.h"

static volatile uint32_t tick=0;

void SysTick_Handler(void){
	if(tick>0){
		--tick;
	}
}

void delay_ms( uint32_t s) {
  tick=s;
  while(tick);
}

void USART2_IRQHandler(uint16_t data){
	 data = (uint8_t)USART2 ->RDR;
	printChar(data);
}

void _print(int fd, char *ptr, int len){
	(void)fd;
	for(int i=0; i<len ; ++i){
		printChar(ptr[i]);
	}

}

void printChar(uint8_t c){
    USART2->TDR =(uint16_t)c;
    while(!( USART2->ISR & (1<<6)));
}

void BSP_UART_init(uint32_t baud){
	RCC->IOPENR  |= (1U << 0);
	RCC->APBENR1 |= (1U << 17);

	//SETUP PA2 AS AF1
	GPIOA->MODER &= ~(3U<< 2*2);
	GPIOA->MODER |=  (2U<< 2*2);
	//CHOOSE AF1 FROM MUX
    GPIOA->AFR[0] &= ~(0xFU << 4*2);
    GPIOA->AFR[0] |= (1U<< 4*2);

	//SETUP PA3 AS AF1
	GPIOA->MODER &= ~(3U<< 2*3);
	GPIOA->MODER |=  (2U<< 2*3);
	//CHOOSE AF1 FROM MUX
    GPIOA->AFR[0] &= ~(0xFU << 4*3);
    GPIOA->AFR[0] |= (1U<< 4*3);

    //SETUP UART2
    USART2->CR1  = 0; //RESET UART2 WITH CR1
    USART2->CR1 |= (1 << 3); //TE
    USART2->CR1 |= (1 << 2); //RE
    USART2->CR1 |= (1 << 5); //RXNEIE
    USART2->BRR  = (uint16_t)(SystemCoreClock / baud);
    USART2->CR1 |= (1 << 0); //UE
/*
    NVIC_SetPriority(USART2_IRQn,1);
    NVIC_EnableIRQ(USART2_IRQn);
*/
}




