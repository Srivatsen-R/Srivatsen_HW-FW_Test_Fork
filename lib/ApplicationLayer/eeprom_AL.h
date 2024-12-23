#ifndef __EEPROM_AL_H
#define __EEPROM_AL_H


#include <string.h>

#include "main.h"
#include "i2c.h"
#include "enums.h"
#include "dr_devices.h"
#include "structures.h"


EEPROM_STATUS EEPROM_Write (I2C_HandleTypeDef* hi2c, uint16_t devAddress, uint16_t memAddress, uint8_t  *pData);
EEPROM_STATUS EEPROM_Read (I2C_HandleTypeDef* hi2c,  uint16_t devAddress, uint16_t memAddress, uint8_t  *pData, uint16_t size);

void EEPROM_Read_Data_odo(void);
void EEPROM_Read_Data_trip(void);
void EEPROM_Write_Data_odo(uint32_t);
void EEPROM_Write_Data_trip(uint32_t);
void EEPROM_Read_Data_Boot_Counter(uint32_t*);
void EEPROM_Write_Data_Boot_Counter(uint32_t);
void EEPROM_Read_Data_BOR_Counter(uint32_t*);
void EEPROM_Write_Data_BOR_Counter(uint32_t);
void EEPROM_Read_Data_PVD_Counter(uint32_t*);
void EEPROM_Write_Data_PVD_Counter(uint32_t);
void EEPROM_Read_Data_PC_Register(uint32_t*);
void EEPROM_Write_Data_PC_Register(uint32_t);
void EEPROM_Read_Data_LR_Register(uint32_t*);
void EEPROM_Write_Data_LR_Register(uint32_t);

#endif