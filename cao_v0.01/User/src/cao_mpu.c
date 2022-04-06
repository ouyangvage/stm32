#include "../inc/cao_mpu.h"
#include<stdio.h>

uint8_t iic_buff[6];

void iic_write(uint8_t dev_address, uint8_t mem_address, uint8_t data)
{
	HAL_I2C_Mem_Write(&hi2c1, dev_address, mem_address, I2C_MEMADD_SIZE_8BIT, &data, 1, 2);
}

void iic_read(uint8_t dev_address, uint8_t mem_address, uint8_t *buff, uint8_t length)
{
	HAL_I2C_Mem_Read(&hi2c1, dev_address, mem_address, I2C_MEMADD_SIZE_8BIT, buff, length, 2);
}

void init_mpu9250(void)
{
	iic_write(GYRO_ADDRESS, PWR_MGMT_1, 0x00);	//½â³ýÐÝÃß×´Ì¬
	iic_write(GYRO_ADDRESS, SMPLRT_DIV, 0x07);
	iic_write(GYRO_ADDRESS, CONFIG, 0x06);
	iic_write(GYRO_ADDRESS, GYRO_CONFIG, 0x18);
	iic_write(GYRO_ADDRESS, ACCEL_CONFIG, 0x01);
}

Accel read_mpu_accel(void)
{
	Accel accel;
	iic_read(ACCEL_ADDRESS, ACCEL_XOUT_H, iic_buff, 6);
	accel.x = ((iic_buff[0] << 8) | iic_buff[1]); 
	accel.y = ((iic_buff[2] << 8) | iic_buff[3]); 
	accel.z = ((iic_buff[4] << 8) | iic_buff[5]); 
	
	printf("accel_x:");
	printf("%d", accel.x);
	printf("\t");
	
	printf("accel_y:");
	printf("%d", accel.y);
	printf("\t");
	
	printf("accel_z:");
	printf("%d", accel.z);
	printf("\n");
	
	return accel;
}

Gyro read_mpu_gyro(void)
{
	Gyro gyro;
	iic_read(GYRO_ADDRESS, GYRO_XOUT_H, iic_buff, 6);
	gyro.x = ((iic_buff[0] << 8) | iic_buff[1]); 
	gyro.y = ((iic_buff[2] << 8) | iic_buff[3]); 
	gyro.z = ((iic_buff[4] << 8) | iic_buff[5]); 
	
	printf("gyro_x:");
	printf("%d", gyro.x);
	printf("\t");
	
	printf("gyro_y:");
	printf("%d", gyro.y);
	printf("\t");
	
	printf("gyro_z:");
	printf("%d", gyro.z);
	printf("\n");
	return gyro;
}

Magnetic read_mpu_magnetic(void)
{
	Magnetic magnetic;
	//iic_write(GYRO_ADDRESS,0x37,0x02);//turn on Bypass Mode 
	//HAL_Delay(10);	
	iic_write(MAG_ADDRESS, 0x0A, 0x01);
	HAL_Delay(10);	
	
	iic_read(MAG_ADDRESS, MAG_XOUT_L, iic_buff, 6);
	magnetic.x = ((iic_buff[1] << 8) | iic_buff[0]); 
	magnetic.y = ((iic_buff[3] << 8) | iic_buff[2]); 
	magnetic.z = ((iic_buff[5] << 8) | iic_buff[4]); 
	
	printf("magnetic_x:");
	printf("%d", magnetic.x);
	printf("\t");
	
	printf("magnetic_y:");
	printf("%d", magnetic.y);
	printf("\t");
	
	printf("magnetic_z:");
	printf("%d", magnetic.z);
	printf("\n");
	
	return magnetic;
}

/*
short read_mpu_temperature(void)
{
	short tempertuare;
	iic_read(GYRO_ADDRESS, TEMP_OUT_H, iic_buff, 2);
	tempertuare = ((iic_buff[1] << 8) | iic_buff[0]); 
	tempertuare = 35+ ((double) (tempertuare + 13200)) / 280;// ¶ÁÈ¡¼ÆËã³öÎÂ¶È
	printf("tempertuare:");
	printf("%d", tempertuare);
	printf("\n");
	return tempertuare;
}
*/
