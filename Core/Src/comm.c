#include "comm.h"
#include "main.h"
#include "math.h"
#include "stdio.h"
#include "can.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

//Sensor register

#define ADDRESS_BMP280 0x77<<1
#define ADDRESS_ID 0xD0
#define ADDRESS_POWER_MODES 0xF4
#define ADDRESS_CALIB_00 0x88 //136
#define ADDRESS_CALIB_25 0xA1 //161

uint8_t buf[10];

uint8_t buf1[10];
uint32_t Timeout = 200;


void main_comm(){

	//HAL_I2C_Master_Transmit(&hi2c1, ADDRESS_BMP280, buf, 1, Timeout); inutile

	//Lecture Id
	HAL_I2C_Mem_Read(&hi2c1, ADDRESS_BMP280, ADDRESS_ID, I2C_MEMADD_SIZE_8BIT, buf, 1, Timeout);
	printf("0x%x\r\n",buf[0]);

	//Configuration BMP280
	buf1[0]=3;
	HAL_I2C_Mem_Write(&hi2c1,ADDRESS_BMP280,ADDRESS_POWER_MODES,I2C_MEMADD_SIZE_8BIT,buf1,2,Timeout);
	HAL_I2C_Mem_Read(&hi2c1,ADDRESS_BMP280,ADDRESS_POWER_MODES,I2C_MEMADD_SIZE_8BIT,buf,2,Timeout);
	printf("0x%x\r\n",buf[0]);

	//Etalonnage
	HAL_I2C_Mem_Read(&hi2c1, ADDRESS_BMP280, ADDRESS_CALIB_00, I2C_MEMADD_SIZE_8BIT, buf, 25, Timeout);
	int i;
	for(i=0;i<26;i++){
		printf("0x%x\r\n",buf[i]);
	}
}
