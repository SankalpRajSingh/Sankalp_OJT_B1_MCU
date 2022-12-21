#include"stm32f4xx.h"
void led_SW_led_init()
{
	RCC->AHB1ENR |= 5;
	GPIOA->MODER |= 0x10000;                                   //FOR PIN PA8 FOR LED
	GPIOA->MODER |= 0x40000;                                   //FOR PIN PA9 FOR LED
	GPIOC->MODER |= 0x10000;                                   //FOR PIN PC8 FOR SWITCH
	GPIOC->MODER |= 0x40000;                                   //FOR PIN PC9 FOR SWITCH
}
void sw_init()
{
	RCC->AHB1ENR |= 0x4;
	GPIOC->MODER |= 0x0;
}
void operation()
{
	if(GPIOC->IDR & 0x100)                                      // WHEN LED 1 IS ON AND LED 2 IS OFF
	{
		if(GPIOC->IDR & 0x200)
		{
			GPIOA->BSRR |= 0x100;
			GPIOA->BSRR |= 0x2000000;
		}
		else
		{
			GPIOA->BSRR |= 0x100;
			GPIOA->BSRR |= 0x2000000;
		}
	}
	else if(GPIOC->IDR & 0x200)                                 // WHEN LED 2 IS ON AND LED 1 IS OFF
	{
		if(GPIOC->IDR & 0x100)
		{
			GPIOA->BSRR |= 0x200;
			GPIOA->BSRR |= 0x1000000;
		}
		else
		{
			GPIOA->BSRR |= 0x200;
			GPIOA->BSRR |= 0x1000000;
		}
	}
	else                                                        //BOTH LEDS ARE IN OFF STATE
	{
		GPIOA->BSRR |= 0x1000000;
		GPIOA->BSRR |= 0x2000000;
	}
}
int main()
{
	led_SW_led_init();
	sw_init();
	while(1)
	{
		operation();
	}
}
