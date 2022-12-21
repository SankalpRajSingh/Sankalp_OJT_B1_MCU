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
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= 0x10000; 		//FOR PORT A AND PIN NUMBER 8
	while(1)
	{
		GPIOA->ODR |= 0x100;
		delay(100);
		GPIOA->ODR &= ~0x100;
		delay(100);
		GPIOB->ODR |= 0x100;
		delay(100);
		GPIOB->ODR &= ~0x100;
		delay(100);
		GPIOC->ODR |= 0x100;
		delay(100);
		GPIOC->ODR &= ~0x100;
		delay(100);
	}
}
