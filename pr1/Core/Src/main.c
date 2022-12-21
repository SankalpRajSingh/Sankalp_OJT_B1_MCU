#include"stm32f4xx.h"
void delay(int T)
{
	int i;
	while(T--)
	{
		for(i=0;i<5000;i++);
	}
}
int main()
{
	RCC->AHB1ENR |= 7;
	GPIOA->MODER |= 0x10000; //FOR PIN PA8
	GPIOB->MODER |= 0x10000; //FOR PIN PB8
	GPIOC->MODER |= 0x40000; //FOR PIN PC9
	while(1)
	{
		GPIOA->ODR |= 0x100;
		delay(1000);
		GPIOA->ODR &= ~0x100;
		delay(1000);
		GPIOB->ODR |= 0x100;
		delay(1000);
		GPIOB->ODR &= ~0x100;
		delay(1000);
		GPIOC->ODR |= 0x200;
		delay(1000);
		GPIOC->ODR &= ~0x200;
		delay(1000);
	}
}
