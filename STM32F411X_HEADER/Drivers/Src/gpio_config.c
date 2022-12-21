/*
 * gpio_config.c
 *
 *  Created on: Nov 17, 2022
 *      Author: PHY202209EF07
 */
#include <stdint.h>
#include "stm32f411.h"
#include "stdio.h"

void gpio_config()
{
	GPIO_Handle_t GpioLed;

		GpioLed.pGPIOx = GPIOA;
		GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
		GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
		GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
		GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

		GPIO_PeriClockControl(GPIOA,ENABLE);

		GPIO_Init(&GpioLed);
}
