/*
 * TIM10_reg.c
 *
 *  Created on: Nov 30, 2022
 *      Author: PHY202209EF07
 */

#include"main.h"
void timer_delay()
{
	RCC->APB2ENR |= 0x20000;
	GPIOB->MODER |= 0x20000;
	GPIOB->AFR[1] |= 0x3;
	TIM10->PSC |= 15999-1;
	TIM10->ARR |= 1000-1;
	TIM10->CNT |= 0x0;
	TIM10->CR1 |= 0x1;
}

int main()
{
	/*ENABLE  GPIO*/
	RCC->AHB1ENR |= 0x3;
	GPIOA->MODER |= 0x400;
	timer_delay();

	while(1)
	{
		while(!(TIM10->SR & 1));
		GPIOA->ODR ^= 0x20;
			TIM10->SR |= 0x0;
	}
}
