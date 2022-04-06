#include "../inc/cao_task.h"
#include<stdio.h>


uint32_t start_time = UINT32_MAX;
uint32_t end_time = UINT32_MAX;

void task_start(uint32_t duration_time)
{
	start_time = HAL_GetTick();
	end_time = start_time + duration_time;
}

void task_run()
{
	uint32_t current_time = HAL_GetTick();
	if(current_time >= end_time)
	{
		start_time = UINT32_MAX;
		end_time = UINT32_MAX;
	}
	else
	{
		printf("current_time:" );
		printf("%d", current_time);
		printf("\n");
	}
}

