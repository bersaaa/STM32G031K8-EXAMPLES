#ifndef BSP_H_
#define BSP_H_

//void led_init();
//void led_set();
//void led_toggle();
//void led_clear();
void delay(volatile uint32_t s);
//void button_init();
//int button_read();
void BSP_UART_init(uint32_t baud);
void _print(int fd, char *ptr, int len);


void printChar(uint8_t c);
void USART2_IRQHandler(uint16_t data);

#endif

