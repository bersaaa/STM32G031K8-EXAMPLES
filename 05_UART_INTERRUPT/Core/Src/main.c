#include "stm32g0xx.h" #include "bsp.h"
#define LEDDELAY 1600000
void delay(volatile uint32_t);
int main(void) {
	//led_init();
	//button_init();
	//SysTick_Config(SystemCoreClock / 1000);
	BSP_UART_init(9600);
	while(1) {
		//delay_ms(1000);
		_print(0,"KABA-KUZ-BULUT - 1801022018\n",31);
		//USART2_IRQHandler("MUSTAFA OGUZ OZCAN - 1801022032");
		delay_ms (1000);
}

return 0;

}
