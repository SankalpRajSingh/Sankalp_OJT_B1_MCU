#include "stm32f4xx.h"

void delay(int T)
{
	while(T--){
		for(int i=0;i<3000;i++);
	}
}

void LED_Init()
{
	RCC->AHB1ENR |=0X1;
	GPIOA->MODER |=0X400;
	GPIOA->MODER |=0X1000;
}
void Button_Init()
{
	RCC->AHB1ENR |=0X4;
	GPIOC->MODER |=0X0;
}
/*void Toggle_pin()
{
	GPIOA->ODR  ^= 0X20;
	delay(100);
}
*/
void EXTISankalp(void)
	{
		GPIOA->ODR  ^= 0x20;
		GPIOA->ODR  ^= 0x40;
			delay(100);
		EXTI->PR |= 0x2000;
	}

int main()
{
	__disable_irq();
	LED_Init();
    Button_Init();
	RCC->APB2ENR      |=0x4000;
	SYSCFG->EXTICR[3] |=0X20;
	EXTI->IMR         |=0x2000;
	EXTI->FTSR        |=0x2000;
	NVIC_EnableIRQ(EXTI15_10_IRQn);

__enable_irq();
	while(1)
	{	}

}
