#include "stm32g0xx.h"

void clearSSD(void);
void setSSD(int);

void set_Rows_Keypad(void);
void clear_Rows_Keypad(void);


void keypad_setup(void){

		// Enable GPIOA clock
		    RCC->IOPENR |= (1U << 0);

		// Enable GPIOB clock
		    RCC->IOPENR |= (1U << 1);

		// Setup pa8, pb9, pb5, pb4 as output rows
		    GPIOA->MODER &= ~(3U << 2*8);
		    GPIOA->MODER |= (1U << 2*8);

		    GPIOB->MODER &= ~(3U << 2*9);
		    GPIOB->MODER |= (1U << 2*9);

		    GPIOB->MODER &= ~(3U << 2*5);
		    GPIOB->MODER |= (1U << 2*5);

		    GPIOB->MODER &= ~(3U << 2*4);
		    GPIOB->MODER |= (1U << 2*4);

		//Setup pa9, pb0, pb2, pb8 as input columns
		    GPIOA->MODER &= ~(3U << 2*9);
		    GPIOA->PUPDR |= (2U << 2*9);

		    GPIOB->MODER &= ~(3U << 0);
		    GPIOB->PUPDR |= (2U << 0);

		    GPIOB->MODER &= ~(3U << 2*2);
		    GPIOB->PUPDR |= (2U << 2*2);

		    GPIOB->MODER &= ~(3U << 2*8);
		    GPIOB->PUPDR |= (2U << 2*8);

		// Setup interrupts for pa9, pb0,pb2,pb8
		    EXTI->EXTICR[2] |= (0U << 8*1); //pa9
		    EXTI->EXTICR[0] |= (1U << 0);   //pb0
		    EXTI->EXTICR[0] |= (1U << 8*2); //pb2
		    EXTI->EXTICR[2] |= (1U << 0);   //pb8

		//rising edge selected for pa9, pb0,pb2,pb8
		    EXTI->RTSR1 |= (1U << 9);
		    EXTI->RTSR1 |= (1U << 0);
		    EXTI->RTSR1 |= (1U << 2);
		    EXTI->RTSR1 |= (1U << 8);

		//mask register selected for pa9, pb0,pb2,pb8
		    EXTI->IMR1 |= (1U << 9);
		    EXTI->IMR1 |= (1U << 0);
		    EXTI->IMR1 |= (1U << 2);
		    EXTI->IMR1 |= (1U << 8);

		// enable NVIC and set interrupt priority
		    NVIC_SetPriority(EXTI0_1_IRQn, 0);
		    NVIC_EnableIRQ(EXTI0_1_IRQn);

		    NVIC_SetPriority(EXTI2_3_IRQn, 0);
		    NVIC_EnableIRQ(EXTI2_3_IRQn);

		    NVIC_SetPriority(EXTI4_15_IRQn, 0);
		    NVIC_EnableIRQ(EXTI4_15_IRQn);


			 // SSD codes
			/* Setup PA0 as output */
			GPIOA->MODER &= ~(3U << 2 * 0);
			GPIOA->MODER |= (1U << 2 * 0);
			/* Setup PA1 as output */
			GPIOA->MODER &= ~(3U << 2 * 1);
			GPIOA->MODER |= (1U << 2 * 1);
			/* Setup PA4 as output */
			GPIOA->MODER &= ~(3U << 2 * 4);
			GPIOA->MODER |= (1U << 2 * 4);
			/* Setup PA5 as output */
			GPIOA->MODER &= ~(3U << 2 * 5);
			GPIOA->MODER |= (1U << 2 * 5);
			/* Setup PA6 as output */
			GPIOA->MODER &= ~(3U << 2 * 6);
			GPIOA->MODER |= (1U << 2 * 6);
			/* Setup PA11 as output */
			GPIOA->MODER &= ~(3U << 2 * 11);
			GPIOA->MODER |= (1U << 2 * 11);
			/* Setup PA12 as output */
			GPIOA->MODER &= ~(3U << 2 * 12);
			GPIOA->MODER |= (1U << 2 * 12);


			GPIOA -> ODR |= (1U << 8);  //PA0 A
			GPIOB -> ODR |= (1U << 9);  //PB1 B
			GPIOB -> ODR |= (1U << 5);  //PB2 C
			GPIOB -> ODR |= (1U << 4);  //PB3 D

			clearSSD();
}

void EXTI0_1_IRQHandler(void){ //interrupt from pb0
	clear_Rows_Keypad();

	GPIOA->ODR ^= (1U << 8);

	GPIOB->ODR ^= (1U << 9); //pb9
	if ((GPIOB -> IDR >>0)& 1){
			setSSD(9);
		}
	GPIOB->ODR ^= (1U << 9); //pb9


	GPIOB->ODR ^= (1U << 5); //pb5
		if ((GPIOB -> IDR >>0)& 1){
				setSSD(6);
			}
	GPIOB->ODR ^= (1U << 5); //pb5


	GPIOB->ODR ^= (1U << 4); //pb4
		if ((GPIOB -> IDR >>0)& 1){
				setSSD(3);
			}
	GPIOB->ODR ^= (1U << 4); //pb4

	EXTI->RPR1 |= (1U << 0); //clear interrupt flag
	set_Rows_Keypad();

}

void EXTI2_3_IRQHandler(void){ //interrupt from PB2
	clear_Rows_Keypad();
	GPIOA->ODR ^= (1U << 8);
	if((GPIOB->IDR >>2) &1){
		setSSD(0);
	}
	GPIOA->ODR ^= (1U << 8); //pa8


	GPIOB->ODR ^= (1U << 9); //pb9
	if((GPIOB->IDR >>2) &1){
		setSSD(8);
	}
	GPIOB->ODR ^= (1U << 9); //pb9


	GPIOB->ODR ^= (1U << 5); //pb5
	if((GPIOB->IDR >>2) &1){
		setSSD(5);
	}
	GPIOB->ODR ^= (1U << 5); //pb5


	GPIOB->ODR ^= (1U << 4); //pb4
	if((GPIOB->IDR >>2) &1){
		setSSD(2);
	}
	GPIOB->ODR ^= (1U << 4); //pb4

	EXTI->RPR1 |= (1U << 2); //clear interrupt flag
	set_Rows_Keypad();
}

void EXTI4_15_IRQHandler(void){ //pb8 and pa9

	if((GPIOB->IDR >>8) &1){

		clear_Rows_Keypad();


		GPIOB->ODR ^= (1U << 9); //pb9
		if((GPIOB->IDR >>8) &1){
			setSSD(7);
		}
		GPIOB->ODR ^= (1U << 9); //pb9


		GPIOB->ODR ^= (1U << 5); //pb5
		if((GPIOB->IDR >>8) &1){
			setSSD(4);
		}
		GPIOB->ODR ^= (1U << 5); //pb5


		GPIOB->ODR ^= (1U << 4); //pb4
		if((GPIOB->IDR >>8) &1){
			setSSD(1);
		}
		GPIOB->ODR ^= (1U << 4); //pb4
		EXTI->RPR1 |= (1U << 8); //clear interrupt flag
		set_Rows_Keypad();
	}

}

void clearSSD(void){

	GPIOA -> ODR |= (1U << 0);  //PA0 A
	GPIOA -> ODR |= (1U << 1);  //PA1 B
	GPIOA -> ODR |= (1U << 4);  //PA2 C
	GPIOA -> ODR |= (1U << 5);  //PA3 D
	GPIOA -> ODR |= (1U << 12); //PA4 E
	GPIOA -> ODR |= (1U << 11); //PA5 F
	GPIOA -> ODR |= (1U << 6);  //PA6 G
}


void setSSD(int x){
	clearSSD();
	switch(x){
		case 0:
			GPIOA -> ODR &= ~(1U << 0);  //PA0 A
			GPIOA -> ODR &= ~(1U << 1);  //PA1 B
			GPIOA -> ODR &= ~(1U << 4);  //PA2 C
			GPIOA -> ODR &= ~(1U << 5);  //PA3 D
			GPIOA -> ODR &= ~(1U << 12); //PA4 E
			GPIOA -> ODR &= ~(1U << 11); //PA5 F
			break;

		case 1:
			GPIOA -> ODR &= ~(1U << 1);  //PA1 B
			GPIOA -> ODR &= ~(1U << 4);  //PA2 C
			break;

		case 2:
			GPIOA -> ODR &= ~(1U << 0);  //PA0 A
			GPIOA -> ODR &= ~(1U << 1);  //PA1 B
			GPIOA -> ODR &= ~(1U << 5);  //PA3 D
			GPIOA -> ODR &= ~(1U << 12); //PA4 E
			GPIOA -> ODR &= ~(1U << 6);  //PA6 G
			break;

		case 3:
			GPIOA -> ODR &= ~(1U << 0);  //PA0 A
			GPIOA -> ODR &= ~(1U << 1);  //PA1 B
			GPIOA -> ODR &= ~(1U << 4);  //PA2 C
			GPIOA -> ODR &= ~(1U << 5);  //PA3 D
			GPIOA -> ODR &= ~(1U << 6);  //PA6 G
			break;
		case 4:
			GPIOA -> ODR &= ~(1U << 1);  //PA1 B
			GPIOA -> ODR &= ~(1U << 4);  //PA2 C
			GPIOA -> ODR &= ~(1U << 11); //PA5 F
			GPIOA -> ODR &= ~(1U << 6);  //PA6 G
			break;

		case 5:
			GPIOA -> ODR &= ~(1U << 0);  //PA0 A
			GPIOA -> ODR &= ~(1U << 4);  //PA2 C
			GPIOA -> ODR &= ~(1U << 5);  //PA3 D
			GPIOA -> ODR &= ~(1U << 11); //PA5 F
			GPIOA -> ODR &= ~(1U << 6);  //PA6 G
			break;

		case 6:
			GPIOA -> ODR &= ~(1U << 0);  //PA0 A
			GPIOA -> ODR &= ~(1U << 4);  //PA2 C
			GPIOA -> ODR &= ~(1U << 5);  //PA3 D
			GPIOA -> ODR &= ~(1U << 12); //PA4 E
			GPIOA -> ODR &= ~(1U << 11); //PA5 F
			GPIOA -> ODR &= ~(1U << 6);  //PA6 G
			break;

		case 7:
			GPIOA -> ODR &= ~(1U << 0);  //PA0 A
			GPIOA -> ODR &= ~(1U << 1);  //PA1 B
			GPIOA -> ODR &= ~(1U << 4);  //PA2 C
			break;

		case 8:
			GPIOA -> ODR &= ~(1U << 0);  //PA0 A
			GPIOA -> ODR &= ~(1U << 1);  //PA1 B
			GPIOA -> ODR &= ~(1U << 4);  //PA2 C
			GPIOA -> ODR &= ~(1U << 5);  //PA3 D
			GPIOA -> ODR &= ~(1U << 12); //PA4 E
			GPIOA -> ODR &= ~(1U << 11); //PA5 F
			GPIOA -> ODR &= ~(1U << 6);  //PA6 G
			break;

		case 9:
			GPIOA -> ODR &= ~(1U << 0);  //PA0 A
			GPIOA -> ODR &= ~(1U << 1);  //PA1 B
			GPIOA -> ODR &= ~(1U << 4);  //PA2 C
			GPIOA -> ODR &= ~(1U << 5);  //PA3 D
			GPIOA -> ODR &= ~(1U << 11); //PA5 F
			GPIOA -> ODR &= ~(1U << 6);  //PA6 G
            break;

	}
}

void clear_Rows_Keypad(void){
	GPIOA -> ODR &= ~(1U << 8);  //PA8
	GPIOB -> ODR &= ~(1U << 9);  //PB9
	GPIOB -> ODR &= ~(1U << 5);  //PB5
	GPIOB -> ODR &= ~(1U << 4);  //PB4
}

void set_Rows_Keypad(void){
	GPIOA -> ODR |= (1U << 8);  //PA8
	GPIOB -> ODR |= (1U << 9);  //PB9
	GPIOB -> ODR |= (1U << 5);  //PB5
	GPIOB -> ODR |= (1U << 4);  //PB4
}

int main(void) {

		keypad_setup();

    while(1) {

    }

    return 0;
}
