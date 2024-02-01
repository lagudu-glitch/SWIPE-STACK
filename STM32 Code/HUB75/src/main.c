/**
  ******************************************************************************
  * @file    main.c
  * @author  Vishnu Lagudu
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f0xx.h"

// user defined functions
void init_io (void);
void nano_wait (unsigned int n);


int main(void)
{
	// initialize the GPIO ports
	init_io ();

//	while (1)
//	{
	// set address to the first row
	GPIOA -> ODR &= ~(0x1f << 6);

	// set the Blank Pin high
	GPIOB -> ODR |= 0x1;

	// set the color to green
//	GPIOA -> ODR &= ~0xff;
//	GPIOA -> ODR |= 0x12;
	GPIOA -> ODR |= 0x38;

	// clock the CLK of the LED matrix
	nano_wait (5000000);
	GPIOA -> ODR |= 0x1 << 11;
	nano_wait (5000000);
	GPIOA -> ODR &= ~(0x1 << 11);

	// latch the row
	nano_wait (5000000);
	GPIOA -> ODR |= 0x1 << 12;
	nano_wait (5000000);
	GPIOA -> ODR &= ~(0x1 << 12);

	// set the Blank Pin low
	GPIOB -> ODR &= ~0x1;
//	}

//	for(;;);
}

// 	inline asm to waste time
void nano_wait(unsigned int n) {
    asm(    "        mov r0,%0\n"
            "repeat: sub r0,#83\n"
            "        bgt repeat\n" : : "r"(n) : "r0", "cc");
}

// Function to initialize GPIOA ports (0 - 13)
// for outputs to LED Dot Matrix
void init_io (void)
{
	// Start the RCC clock
	RCC -> AHBENR |= RCC_AHBENR_GPIOAEN;
	RCC -> AHBENR |= RCC_AHBENR_GPIOBEN;

	GPIOA -> MODER &= 0xfC000000;
	GPIOA -> MODER |= 0x01555555;

	GPIOB -> MODER &= ~0x3;
	GPIOB -> MODER |= 0x1;
}
