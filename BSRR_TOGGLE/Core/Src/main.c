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
	int LED;
	RCC->AHB1ENR |= 1;
	GPIOA->MODER |= 0x400;
	while(1)
	{
		GPIOA->ODR |= 0x20;
		delay(100);
		GPIOA->ODR &= ~0x20;
		delay(100);
	}
}
