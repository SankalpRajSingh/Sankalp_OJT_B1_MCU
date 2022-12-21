/* This program checks a 4x4 matrix keypad to see whether a key is
pressed or not. When a key is pressed, it turns on the LED.
*
* PC0-3 are connected to the columns as Input to MCU
*  PC4-7 are connected to the rows of the keypad as Output of MCU.
*  LED connected to PA8 */

#include "stm32f4xx.h"
void delay(void);
void keypad_init(void);
char keypad_control(void);
int main(void)
{
	keypad_init();
// enable PA8 for LED
	RCC->AHB1ENR |= 1; 						/* enable GPIOA clock */
	GPIOA->MODER &= ~(3<<16); 	//0x30000		/* clear pin mode */
	GPIOA->MODER |= (1<<16); 			/* set pin output mode */
	while(1)
	{
		if (keypad_control() != 0) 				/* if a key is pressed */
			GPIOA->BSRR = (1<<8); 			/* turn on LED */
		else
			GPIOA->BSRR = (1<<24); 			/* turn off LED */
	}
}

/* this function initializes PC0-3 (column) and PC4-7 (row).
* The column pins need to have the pull-up resistors enabled.
*/

void keypad_init(void)
{
	RCC->AHB1ENR |= 0x4;						 /* enable GPIOC clock */
	GPIOC->MODER &= ~0xFF; 				/* clear pin mode to input */
	GPIOC->PUPDR = 0x00000055; 					/* enable pull up resistors for column pins */
}

/* This is a non-blocking function.
* If a key is pressed, it returns 1. Otherwise, it returns a 0. */

char keypad_control(void)
{
	int col;
	GPIOC->MODER = 0x00005500; 					/* make all row pins output */
	GPIOC->BSRR = 0x00F00000; 					/* drive all row pins low */
	delay(); 									/* wait for signals to settle */
	col = GPIOC->IDR & 0x000F; 					/* read all column pins */
	GPIOC->MODER &= ~0x0000FF00; 				/* disable all row pins drive */
	if (col == 0x000F) 							/* if all columns are high */
		return 0;								/* no key pressed */
	else
		return 1; 								/* a key is pressed */
}

/* make a small delay */
void delay(void)
{
	int i;
	for (i = 0; i < 20; i++) ;
}
