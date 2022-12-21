#include"stm32f4xx.h"
void delayMs(int n);
int main(void)
{
//	config. PA5 as output of TIM2 CH1
	RCC->AHB1ENR |= 1;				//ENABLE GPIOA CLOCK
	GPIOA -> MODER &=~(3<<10);		//CLEAR PIN MODE
	GPIOA->MODER |=(1<<11);			//SET PIN TO ALTERNATE FUNCTION
	GPIOA->AFR[0] &= (0XF<<20);		//CLEAR PIN AF BITS
	GPIOA->AFR[0] |= 1<<20;			//SET PIN TO AF1 FOR TIM2 CH1

//	SETUP TIM2
	RCC->APB1ENR |= 1;
	TIM2->PSC10-1;
	TIM2->ARR = 32000-1;
	TIM2->CNT = 0;
	TIM2->CCMR1 = 0X0068;
	TIM2->CCER = 1;
	TIM2->CCR1 = 32;
	TIM2->BDTR |= 0X8000;
	TIM->CR1 = 1;
	WHILE(1)
	{
		TIM2-> CCR1 = TIM2->CCR1 *110 / 100;
		if(TIM2->CCR1 > 32000)
			TIM2->CCR1 = 32;
		delayMs(20);
	}
}
