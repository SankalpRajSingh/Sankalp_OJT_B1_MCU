#include"stm32f4xx.h"
void led_SW_Buzzer_init()
{
	RCC->AHB1ENR |= 7;
	GPIOA->MODER |= 0x10000; //FOR PIN PA8 FOR LED
	GPIOB->MODER |= 0x10000; //FOR PIN PB8 FOR BUZZER
	GPIOC->MODER |= 0x40000; //FOR PIN PC9 FOR SWITCH
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
				GPIOA->BSRR |= 0x100;
				GPIOB->BSRR |= 0x100;
			}
			else
			{
				GPIOA->BSRR |= 0x1000000;
				GPIOB->BSRR |= 0x1000000;
			}
}
int main()
{
	led_SW_Buzzer_init();
	sw_init();
	while(1)
	{
		operation();
	}
}
