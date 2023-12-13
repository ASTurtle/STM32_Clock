/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

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
#define LED0_Pin GPIO_PIN_13
#define LED0_GPIO_Port GPIOC
#define GM_Pin GPIO_PIN_0
#define GM_GPIO_Port GPIOA
#define RM_Pin GPIO_PIN_1
#define RM_GPIO_Port GPIOA
#define G_Pin GPIO_PIN_2
#define G_GPIO_Port GPIOA
#define F_Pin GPIO_PIN_3
#define F_GPIO_Port GPIOA
#define A_Pin GPIO_PIN_4
#define A_GPIO_Port GPIOA
#define B_Pin GPIO_PIN_5
#define B_GPIO_Port GPIOA
#define KEY0_Pin GPIO_PIN_6
#define KEY0_GPIO_Port GPIOA
#define KEY0_EXTI_IRQn EXTI9_5_IRQn
#define KEY1_Pin GPIO_PIN_7
#define KEY1_GPIO_Port GPIOA
#define KEY1_EXTI_IRQn EXTI9_5_IRQn
#define KEY2_Pin GPIO_PIN_0
#define KEY2_GPIO_Port GPIOB
#define KEY2_EXTI_IRQn EXTI0_IRQn
#define BEEP_Pin GPIO_PIN_12
#define BEEP_GPIO_Port GPIOB
#define DS_SCK_Pin GPIO_PIN_13
#define DS_SCK_GPIO_Port GPIOB
#define DS_DAT_Pin GPIO_PIN_14
#define DS_DAT_GPIO_Port GPIOB
#define DS_RST_Pin GPIO_PIN_15
#define DS_RST_GPIO_Port GPIOB
#define COM1_Pin GPIO_PIN_15
#define COM1_GPIO_Port GPIOA
#define COM2_Pin GPIO_PIN_3
#define COM2_GPIO_Port GPIOB
#define COM3_Pin GPIO_PIN_4
#define COM3_GPIO_Port GPIOB
#define COM4_Pin GPIO_PIN_5
#define COM4_GPIO_Port GPIOB
#define DP_Pin GPIO_PIN_6
#define DP_GPIO_Port GPIOB
#define C_Pin GPIO_PIN_7
#define C_GPIO_Port GPIOB
#define D_Pin GPIO_PIN_8
#define D_GPIO_Port GPIOB
#define E_Pin GPIO_PIN_9
#define E_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
