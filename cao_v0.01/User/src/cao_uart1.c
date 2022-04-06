#include"../inc/cao_uart1.h"
#include<stdio.h>

uint8_t rx_buff[255];
uint8_t tx_buff[255];

int fputc(int ch, FILE *f)
{
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
	return ch;
}

int fgetc(FILE * f)
{
	uint8_t ch = 0;
	HAL_UART_Receive(&huart1,&ch, 1, 0xffff);
	return ch;
}

void read_command()
{
	char command = 0;
	scanf("%c", &command); //getchar();
	switch(command)
	{
		case '0':
			printf("123\n");
			break;
		
		default:
			break;
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	HAL_UART_Transmit(&huart1, rx_buff, 1, 0);
	HAL_UART_Receive_IT(&huart1,rx_buff,1);
}
