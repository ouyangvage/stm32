#include "../inc/cao_motor.h"
#include<stdio.h>

void motor_left(int16_t pwm)
{
  if(pwm > 0) // motor corotation
  {
		HAL_GPIO_WritePin(motor_left_a2_input1_GPIO_Port, motor_left_a2_input1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(motor_left_a3_input2_GPIO_Port, motor_left_a3_input2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motor_left_a4_brake_GPIO_Port, motor_left_a4_brake_Pin, GPIO_PIN_RESET);
		
		//HAL_TIM_Base_Start_IT(&htim2);
		htim2.Instance->CCR1 = pwm;
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  }
  else if(pwm < 0) //motor inversion
  {
		HAL_GPIO_WritePin(motor_left_a2_input1_GPIO_Port, motor_left_a2_input1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motor_left_a3_input2_GPIO_Port, motor_left_a3_input2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(motor_left_a4_brake_GPIO_Port, motor_left_a4_brake_Pin, GPIO_PIN_RESET);
		
		//HAL_TIM_Base_Start_IT(&htim2);
		htim2.Instance->CCR1 = -pwm;
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  }
	else	//motor brake
	{ 
		htim2.Instance->CCR1 = 0;
		HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
		HAL_GPIO_WritePin(motor_left_a2_input1_GPIO_Port, motor_left_a2_input1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motor_left_a3_input2_GPIO_Port, motor_left_a3_input2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motor_left_a4_brake_GPIO_Port, motor_left_a4_brake_Pin, GPIO_PIN_SET);
	}
}

void motor_right(int16_t pwm)
{
  if(pwm > 0) // motor corotation
  {
		HAL_GPIO_WritePin(motor_right_a5_input1_GPIO_Port, motor_right_a5_input1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(motor_right_a6_input2_GPIO_Port, motor_right_a6_input2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motor_right_a7_brake_GPIO_Port, motor_right_a7_brake_Pin, GPIO_PIN_RESET);
		
		//HAL_TIM_Base_Start_IT(&htim2);
		htim2.Instance->CCR2 = pwm;
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  }
  else if(pwm < 0) //motor inversion
  {
		HAL_GPIO_WritePin(motor_right_a5_input1_GPIO_Port, motor_right_a5_input1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motor_right_a6_input2_GPIO_Port, motor_right_a6_input2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(motor_right_a7_brake_GPIO_Port, motor_right_a7_brake_Pin, GPIO_PIN_RESET);
		
		//HAL_TIM_Base_Start_IT(&htim2);
		htim2.Instance->CCR2 = -pwm;
		HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  }
	else	//motor brake
	{ 
		htim2.Instance->CCR2 = 0;
		HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
		
		HAL_GPIO_WritePin(motor_right_a5_input1_GPIO_Port, motor_right_a5_input1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motor_right_a6_input2_GPIO_Port, motor_right_a6_input2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motor_right_a7_brake_GPIO_Port, motor_right_a7_brake_Pin, GPIO_PIN_SET);
	}
}

void differential_device(Velocity velocity)
{
	int32_t velocity_left_pwm = velocity.line + velocity.angular;
	int32_t velocity_right_pwm = velocity.line - velocity.angular;
	
	printf("velocity_left_pwm:");
	printf("%d", velocity_left_pwm);
	printf("\t");
	
	printf("velocity_right_pwm:");
	printf("%d", velocity_right_pwm);
	printf("\n");
	
	if(velocity_left_pwm > 255)
	{
		velocity_left_pwm = 255;
	}
	else if(velocity_left_pwm < -255)
	{
		velocity_left_pwm = -255;
	}
	
	if(velocity_right_pwm > 255)
	{
		velocity_right_pwm = 255;
	}
	else if(velocity_right_pwm < -255)
	{
		velocity_right_pwm = -255;
	}
	motor_left(velocity_left_pwm);
	motor_right(velocity_right_pwm);
}

	
