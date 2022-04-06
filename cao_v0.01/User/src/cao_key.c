#include "../inc/cao_key.h"

// do not user HAl_Delay(), then will death
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == key_2_Pin)
	{
		if (HAL_GPIO_ReadPin(key_2_GPIO_Port, key_2_Pin) == KEY_DOWN_LEVEL) 
		{
			HAL_GPIO_TogglePin(led_1_GPIO_Port, led_1_Pin);
		}
		__HAL_GPIO_EXTI_CLEAR_IT(key_2_Pin);
	} 
	else if (GPIO_Pin == key_3_Pin) 
	{
		if (HAL_GPIO_ReadPin(key_3_GPIO_Port, key_3_Pin) == KEY_DOWN_LEVEL) {
			HAL_GPIO_TogglePin(led_2_GPIO_Port, led_2_Pin);
		}
		__HAL_GPIO_EXTI_CLEAR_IT(key_3_Pin);
	}
}
