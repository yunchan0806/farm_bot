/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usart.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
extern MOTOR motor1;
extern MOTOR motor2;
extern MOTOR motor3;
extern MOTOR motor4;
extern SWITCHS switch_pin[6];

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for myTask02 */
osThreadId_t myTask02Handle;
const osThreadAttr_t myTask02_attributes = {
  .name = "myTask02",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartTask02(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of myTask02 */
  myTask02Handle = osThreadNew(StartTask02, NULL, &myTask02_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
	const char *message = "task1\n";
	for(;;)
	{

		if(HAL_GPIO_ReadPin(switch_pin[4].pin_port, switch_pin[4].pin) == GPIO_PIN_RESET){
			if(HAL_GPIO_ReadPin(motor1.DIR_PORT, motor1.DIR) == GPIO_PIN_SET){
				HAL_GPIO_WritePin(motor1.ENA_PORT, motor1.ENA, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
			}
		}
		if(HAL_GPIO_ReadPin(switch_pin[5].pin_port, switch_pin[5].pin) == GPIO_PIN_RESET){
			if(HAL_GPIO_ReadPin(motor1.DIR_PORT, motor1.DIR) == GPIO_PIN_RESET){
				HAL_GPIO_WritePin(motor1.ENA_PORT, motor1.ENA, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
			}
		}
		if(HAL_GPIO_ReadPin(switch_pin[3].pin_port, switch_pin[3].pin) == GPIO_PIN_RESET){
			if(HAL_GPIO_ReadPin(motor3.DIR_PORT, motor3.DIR) == GPIO_PIN_SET){
				HAL_GPIO_WritePin(motor3.ENA_PORT, motor3.ENA, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
			}
		}

		if(HAL_GPIO_ReadPin(switch_pin[2].pin_port, switch_pin[2].pin) == GPIO_PIN_RESET){
			if(HAL_GPIO_ReadPin(motor2.DIR_PORT, motor2.DIR) == GPIO_PIN_SET){
				HAL_GPIO_WritePin(motor2.ENA_PORT, motor2.ENA, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
			}
		}

		if(HAL_GPIO_ReadPin(switch_pin[1].pin_port, switch_pin[1].pin) == GPIO_PIN_RESET){
			if(HAL_GPIO_ReadPin(motor3.DIR_PORT, motor3.DIR) == GPIO_PIN_RESET){
				HAL_GPIO_WritePin(motor3.ENA_PORT, motor3.ENA, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
			}
		}

		if(HAL_GPIO_ReadPin(switch_pin[0].pin_port, switch_pin[0].pin) == GPIO_PIN_RESET){
			if(HAL_GPIO_ReadPin(motor2.DIR_PORT, motor2.DIR) == GPIO_PIN_RESET){
				HAL_GPIO_WritePin(motor2.ENA_PORT, motor2.ENA, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
			}
		}

		if(HAL_GPIO_ReadPin(switch_pin[6].pin_port, switch_pin[6].pin) == GPIO_PIN_RESET){
			if(HAL_GPIO_ReadPin(motor4.DIR_PORT, motor4.DIR) == GPIO_PIN_SET){
				HAL_GPIO_WritePin(motor4.ENA_PORT, motor4.ENA, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
			}
		}

		if(HAL_GPIO_ReadPin(switch_pin[7].pin_port, switch_pin[7].pin) == GPIO_PIN_RESET){
			if(HAL_GPIO_ReadPin(motor4.DIR_PORT, motor4.DIR) == GPIO_PIN_RESET){
				HAL_GPIO_WritePin(motor4.ENA_PORT, motor4.ENA, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
			}
		}


	osDelay(1); // osDelayï¿??????? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½ï¿??????? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ï¿??????? ?ï¿½ï¿½?ï¿½ï¿½?ï¿½ï¿½ ?ï¿½ï¿½ ?ï¿½ï¿½?ï¿½ï¿½ï¿??????? ?ï¿½ï¿½
	}
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void *argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */
  char RxBuffer[100];
  char TxBuffer[100];
  uint16_t RxIndex = 0;
  uint16_t RxSize = sizeof(RxBuffer);

  for(;;)
  {
    uint8_t receivedByte;
    if (HAL_UART_Receive(&huart2, &receivedByte, 1, HAL_MAX_DELAY) == HAL_OK) {
      RxBuffer[RxIndex++] = receivedByte;

      if (receivedByte == '\n') {
        RxBuffer[RxIndex] = '\0';

        if (RxIndex >= 4) {
          uint16_t halfLength = RxIndex / 2;

          strncpy(TxBuffer, RxBuffer, halfLength);
          TxBuffer[halfLength] = '\0';

          if (strncmp(TxBuffer, "01", halfLength) == 0) {
              motor2.go_way(&motor2);
              motor3.go_way(&motor3);
              HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
          }
          else if (strncmp(TxBuffer, "10", halfLength) == 0) {
              motor2.back_way(&motor2);
              motor3.back_way(&motor3);
              HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
          }
          else if (strncmp(TxBuffer, "11", halfLength) == 0) {
              motor2.stop(&motor2);
              motor3.stop(&motor3);

              HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
          }

          if (strncmp(RxBuffer + halfLength, "01", 2) == 0) {
              motor1.go_way(&motor1);
          }
          else if (strncmp(RxBuffer + halfLength, "10", 2) == 0) {
              motor1.back_way(&motor1);
          }
          else if (strncmp(RxBuffer + halfLength, "11", 2) == 0) {
              motor1.stop(&motor1);
          }
        } else if (RxIndex >=  2) {
          if (strncmp(RxBuffer, "31", 2) == 0) {
              motor4.go_way(&motor4);
          }
          else if (strncmp(RxBuffer, "32", 2) == 0) {
              motor4.back_way(&motor4);
          }
          else if (strncmp(RxBuffer, "33", 2) == 0) {
              motor4.stop(&motor4);
          }
        }

        RxIndex = 0;
        memset(RxBuffer, 0, RxSize);
      }

      if (RxIndex >= RxSize) {
        RxIndex = 0;
      }
    }
  }
  /* USER CODE END StartTask02 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

