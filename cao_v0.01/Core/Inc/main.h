/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define key_2_Pin GPIO_PIN_0
#define key_2_GPIO_Port GPIOC
#define key_2_EXTI_IRQn EXTI0_IRQn
#define key_3_Pin GPIO_PIN_1
#define key_3_GPIO_Port GPIOC
#define key_3_EXTI_IRQn EXTI1_IRQn
#define motor_left_pa0_pwm_Pin GPIO_PIN_0
#define motor_left_pa0_pwm_GPIO_Port GPIOA
#define motor_right_pa1_pwm_Pin GPIO_PIN_1
#define motor_right_pa1_pwm_GPIO_Port GPIOA
#define motor_left_a2_input1_Pin GPIO_PIN_2
#define motor_left_a2_input1_GPIO_Port GPIOA
#define motor_left_a3_input2_Pin GPIO_PIN_3
#define motor_left_a3_input2_GPIO_Port GPIOA
#define motor_left_a4_brake_Pin GPIO_PIN_4
#define motor_left_a4_brake_GPIO_Port GPIOA
#define motor_right_a5_input1_Pin GPIO_PIN_5
#define motor_right_a5_input1_GPIO_Port GPIOA
#define motor_right_a6_input2_Pin GPIO_PIN_6
#define motor_right_a6_input2_GPIO_Port GPIOA
#define motor_right_a7_brake_Pin GPIO_PIN_7
#define motor_right_a7_brake_GPIO_Port GPIOA
#define ultrasonic_trig_Pin GPIO_PIN_8
#define ultrasonic_trig_GPIO_Port GPIOC
#define uart1_a9_tx_Pin GPIO_PIN_9
#define uart1_a9_tx_GPIO_Port GPIOA
#define uart1_a10_rx_Pin GPIO_PIN_10
#define uart1_a10_rx_GPIO_Port GPIOA
#define iic_b6_scl_Pin GPIO_PIN_6
#define iic_b6_scl_GPIO_Port GPIOB
#define iic_b7_sda_Pin GPIO_PIN_7
#define iic_b7_sda_GPIO_Port GPIOB
#define led_2_Pin GPIO_PIN_8
#define led_2_GPIO_Port GPIOB
#define led_1_Pin GPIO_PIN_9
#define led_1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
