#include"stm32f4xx.h"
void led_init()
{
	RCC->AHB1ENR |= 0x1;
	GPIOA->MODER |= 0x400;
}
void sw_init()
{
	RCC->AHB1ENR |= 0x4;
	GPIOC->MODER |= 0x0;
}
void operation()
{
	if(GPIOC->IDR & 0x2000)
			{
				GPIOA->BSRR |= 0x200000;
			}
			else
			{
				GPIOA->BSRR |= 0x20;
			}
}
int main()
{
	led_init();
	sw_init();
	while(1)
	{
		operation();
	}
}
