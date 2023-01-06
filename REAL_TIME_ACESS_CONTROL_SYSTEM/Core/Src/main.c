/* USER CODE BEGIN Header */
/**
  **********
  * @file           : main.c
  * @brief          : Main program body
  **********
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  **********
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include<stdio.h>
#include "main.h"
#include<string.h>
#include"lcd.h"
#include"RTC.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

RTC_HandleTypeDef hrtc;

UART_HandleTypeDef huart1;


RTC_HandleTypeDef hrtc;
RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;
/* USER CODE BEGIN PV */
void MOTOR_Init(void);
void Rfid_Init(void);
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_RTC_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */
#define TRUE 1
#define FALSE 0
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
char *USER_DATA="Sankalp!";
uint8_t recvd_data;
	uint8_t data_buf[50];
	uint8_t count=0;
	uint8_t rec_comp_data=FALSE;
	char str[20];
	char *buffer[15];
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  LCD_init();
//  RTC_init();
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_RTC_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  Rfid_Init();

  /* USER CODE END 2 */

    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}

void Rfid_Init()
{
	LCD_command(1);
	  uint16_t len_of_data=strlen(USER_DATA);
	   HAL_UART_Transmit(&huart1, (uint8_t*)USER_DATA,len_of_data, HAL_MAX_DELAY);
	   while(rec_comp_data != TRUE)
	   {
	 	  HAL_UART_Receive_IT(&huart1,&recvd_data,1);
	   }
	   MOTOR_Init();
	   while(1);
	   return 0;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	data_buf[count++]=recvd_data;
//	if(strcmp(data_buf,"18")==0)
//	{
//		LCD_command(1);
//		LCD_string("WELCOME ON BOARD");
//		LCD_command(0xC4);
//		LCD_string("SANKALP!");
//		LCD_command(1);
//		LCD_string("LOGIN TIME");
//		LCD_command(0xC4);
//		LCD_string(buffer1);
//		strcpy(data_buf,"/0");
//		MOTOR_Init();
//	}
//	else if(strcmp(data_buf,"3E")==0)
//	{
//		LCD_command(1);
//		LCD_string("WELCOME ON BOARD");
//		LCD_command(0xC4);
//		LCD_string("NARESH!");
//		LCD_command(1);
//		LCD_string("LOGIN TIME");
//		LCD_command(0xC4);
//		LCD_string(buffer1);
//		MOTOR_Init();
//	}
//	else if(strcmp(data_buf,"55")==0)
//	{
//		LCD_command(1);
//		LCD_string("WELCOME ON BOARD");
//		LCD_command(0xC4);
//		LCD_string("SANDEEP!");
//		LCD_command(1);
//		LCD_string("LOGIN TIME");
//		LCD_command(0xC4);
//		LCD_string(buffer1);
//		MOTOR_Init();
//	}
}


void MOTOR_Init()
{
	LCD_string(data_buf);
	HAL_Delay(100);
	strcpy(data_buf,'_');
	LCD_string(data_buf);
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);       //For Gate Open
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 0);
//	delay(3000);
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);        //Stop
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 0);
//	delay(2000);
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);       //For Gate Close
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 1);
//	delay(3000);
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);        //Stop
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, 0);
//	Rfid_Init();
}

/**
  * @brief System Clock Configuration
  * @retval None
  */


/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */


/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */


/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, MOTOR1_Output_Pin|MOTOR2_Output_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : MOTOR1_Output_Pin MOTOR2_Output_Pin */
  GPIO_InitStruct.Pin = MOTOR1_Output_Pin|MOTOR2_Output_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
