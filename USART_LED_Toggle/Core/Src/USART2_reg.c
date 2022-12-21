/*
 * USART2_reg.c
 *
 *  Created on: Nov 24, 2022
 *      Author: PHY202209EF07
 */


#include"main.h"
unsigned char uart_read()
{
	while(!(USART2->SR & 0x20)){}
	return USART2 -> DR;
}
void delay(int T)
{
	int i;
	while(T--)
	{
		for(i=0;i<100000;i++);
	}
}
void Sconfig_Init()
{
	RCC->APB1ENR |=0x20000;
	RCC->AHB1ENR |=0x1;
	GPIOA->MODER |=0xA0;
	GPIOA->AFR[0] |=0x7700;
	USART2->BRR |=0x683;    //9600 Baudrate
	USART2->CR1 |= 0xC;
	USART2->CR1 |= 0x2000;	// For UE
}
led init()
{
	GPIOA->MODER |= 0x400;
}
void led_toggle(int count)
{
	for(count%=10;count>0;count--)
	{
		GPIOA->BSRR |= 0x20;
		delay(1000);
		GPIOA->BSRR |= 0x200000;
		delay(1000);
	}
}
char data;
int main()
{
	Sconfig_Init();
	led_init();
	while(1)
	{
		data=uart_read();
		led_toggle(data);
	}
}
