#include "../inc/cao_ultrasonic.h"
#include <stdio.h>


uint32_t timer_click = 0;
uint8_t capture_channel = 1;
uint8_t count_period = 0;

Capture ultrasonic_capture = {0, 0, 0, 0};

void delay_us(__IO uint32_t us)
{
	uint32_t i;
	for(i=0; i<us; i++)
	{
		uint8_t uc = 12;
		while(uc--);
	}
}



void capture_init(void)
{
		timer_click = HAL_RCC_GetHCLKFreq(); //GENERAL_TIM_PRESCALER;    
  	HAL_TIM_Base_Start_IT(&htim1);  
  	HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);
	
		count_period = 0;
		ultrasonic_capture.start = 0;
		ultrasonic_capture.finish = 0;
}

uint32_t ultrasonic_measure(void)
{
	uint32_t distance = 0;
	switch(capture_channel)
	{
		case 1:
			HAL_GPIO_WritePin(ultrasonic_trig_GPIO_Port, ultrasonic_trig_Pin, GPIO_PIN_SET);
			delay_us(20);
			//HAL_Delay(20);
			HAL_GPIO_WritePin(ultrasonic_trig_GPIO_Port, ultrasonic_trig_Pin, GPIO_PIN_RESET);
			break;
		
		default:
			break;
	}
	
	if(ultrasonic_capture.finish == 1)
	{
		distance = ((ultrasonic_capture.count + (ultrasonic_capture.period * 65535))* 340)/(10000*2);
		ultrasonic_capture.finish = 0;
		printf("period:%d \t", ultrasonic_capture.period);
		printf("distance:%d \n", distance);
	}
	
	return distance;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  count_period ++;
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim == &htim1)
	{
		if(ultrasonic_capture.start == 0)
		{
			ultrasonic_capture.period = 0;
			ultrasonic_capture.count = 0;
			count_period = 0;
			switch(capture_channel)
			{
				case 1:
					__HAL_TIM_DISABLE(&htim1); 
					__HAL_TIM_SET_COUNTER(&htim1, 0);
					TIM_RESET_CAPTUREPOLARITY(&htim1, TIM_CHANNEL_1);
					TIM_SET_CAPTUREPOLARITY(&htim1, TIM_CHANNEL_1, TIM_ICPOLARITY_FALLING); 
					__HAL_TIM_ENABLE(&htim1); 
				break;

				default:
					break;
			}
			ultrasonic_capture.start = 1;
		}
		else if(ultrasonic_capture.start == 1)
		{
			switch(capture_channel)
			{
				case 1:
					ultrasonic_capture.period = count_period;
					ultrasonic_capture.count = HAL_TIM_ReadCapturedValue(&htim1, TIM_CHANNEL_1);
					TIM_RESET_CAPTUREPOLARITY(&htim1, TIM_CHANNEL_1);
					TIM_SET_CAPTUREPOLARITY(&htim1, TIM_CHANNEL_1, TIM_ICPOLARITY_RISING);	
					//int distance = ((ultrasonic_capture.count % timer_click) * 340)/(1000*2);
					//int distance = ((ultrasonic_capture.count + (ultrasonic_capture.period * 65535))* 340)/(10000*2);
					//printf("period:%d \t", ultrasonic_capture.period);
					//printf("count:%d \t", ultrasonic_capture.count);
					//printf("distance:%d \n", distance);
				break;

				default:
					break;
			}
			ultrasonic_capture.start = 0;
			ultrasonic_capture.finish = 1;
		}
	}
}
