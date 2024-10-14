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
#include "stm32g4xx_hal.h"

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
#define LCD_DC_Pin GPIO_PIN_6
#define LCD_DC_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_4
#define LCD_CS_GPIO_Port GPIOC
#define KEY_H1_Pin GPIO_PIN_0
#define KEY_H1_GPIO_Port GPIOB
#define KEY_H2_Pin GPIO_PIN_1
#define KEY_H2_GPIO_Port GPIOB
#define KEY_H3_Pin GPIO_PIN_2
#define KEY_H3_GPIO_Port GPIOB
#define SW1_Pin GPIO_PIN_10
#define SW1_GPIO_Port GPIOB
#define SW2_Pin GPIO_PIN_11
#define SW2_GPIO_Port GPIOB
#define KEY_S1_Pin GPIO_PIN_12
#define KEY_S1_GPIO_Port GPIOB
#define KEY_S2_Pin GPIO_PIN_13
#define KEY_S2_GPIO_Port GPIOB
#define KEY_S3_Pin GPIO_PIN_14
#define KEY_S3_GPIO_Port GPIOB
#define KEY_S4_Pin GPIO_PIN_15
#define KEY_S4_GPIO_Port GPIOB
#define LCD_BLK_Pin GPIO_PIN_8
#define LCD_BLK_GPIO_Port GPIOA
#define LCD_RST_Pin GPIO_PIN_15
#define LCD_RST_GPIO_Port GPIOA
#define KEY_H4_Pin GPIO_PIN_3
#define KEY_H4_GPIO_Port GPIOB
#define SW_CH03_Pin GPIO_PIN_5
#define SW_CH03_GPIO_Port GPIOB
#define SW_CH02_Pin GPIO_PIN_6
#define SW_CH02_GPIO_Port GPIOB
#define SW_CH01_Pin GPIO_PIN_7
#define SW_CH01_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
