/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef struct motor
{
  GPIO_TypeDef* PUL_PORT;
  const int PUL;
  GPIO_TypeDef* DIR_PORT;
  const int DIR;
  GPIO_TypeDef* ENA_PORT;
  const int ENA;
  bool enaState;
  void (*go_way)(struct motor* self);
  void (*back_way)(struct motor* self);
  void (*stop)(struct motor* self);
} MOTOR;
typedef struct switchs {
  GPIO_TypeDef* pin_port; // GPIO ?��?��?�� ???�� ?��?��?��
  const int pin; // GPIO ?? 번호
} SWITCHS;

void MotorGoWay(MOTOR* motor);
void MotorBackWay(MOTOR* motor);
void MotorStop(MOTOR* motor);
void delay_us(uint32_t us);
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
