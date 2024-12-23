/*
Pegasus - Motor Controller Unit software for HL,HLP,Storm,Vortex and future projects.

Contributors: Pujit Gandhi,Pratik Rout,Olay,Saksham

This file contains functions associated with EEPROM/I2C read/write.

*/

#include <math.h>
#include <stdlib.h>

#include "eeprom_AL.h"
#include "math_func.h"
#include "vehicle.h"
#include "usart.h"
#include "FOC.h"

extern vehicle_t vehicle;
extern struct uart_t  serial;


eeprom_t e24lc02 = {
         .size       = 8,
         .eepromI2C  = &hi2c2,
         .devAddress = 0xA0,
         .memAddress = 0x00,
         .read       = EEPROM_Read,
         .write      = EEPROM_Write,    
};

EEPROM_STATUS EEPROM_Write (I2C_HandleTypeDef* hi2c,  
                            uint16_t devAddress, 
                            uint16_t memAddress,
                            uint8_t  *pData) 
{
   EEPROM_STATUS eepromStatus = HAL_I2C_Mem_Write(hi2c, devAddress, memAddress, I2C_MEMADD_SIZE_8BIT, pData, strlen((char*)pData), 500);
   HAL_Delay(5);
   return eepromStatus;
}


EEPROM_STATUS EEPROM_Read (I2C_HandleTypeDef* hi2c,  
                            uint16_t devAddress, 
                            uint16_t memAddress,
                            uint8_t  *pData,
                            uint16_t size) 
{
   EEPROM_STATUS eepromStatus = HAL_I2C_Mem_Read(hi2c, devAddress, memAddress, I2C_MEMADD_SIZE_8BIT, (uint8_t*) &e24lc02.pData, 4, 500);
   return eepromStatus;
}

void EEPROM_Read_Data_odo()
{
      // Reading odometer data from EEPROM 
      e24lc02.status =  e24lc02.read(e24lc02.eepromI2C, e24lc02.devAddress, e24lc02.memAddress, (uint8_t*) &e24lc02.pData, e24lc02.size);
      if(e24lc02.status != EEPROM_OK) 
      serial.print(serial.uart1, "Failed to read Odometer value in EEPROM");
      vehicle.odometer = atof((char*) e24lc02.pData);
}

void EEPROM_Read_Data_Boot_Counter(uint32_t* boot_counter)
{
      // Reading boot counter data from EEPROM 
      e24lc02.status =  e24lc02.read(e24lc02.eepromI2C, e24lc02.devAddress, e24lc02.memAddress, (uint8_t*) &e24lc02.pData, e24lc02.size);
      if(e24lc02.status != EEPROM_OK){FOC_F_T.EEPROM_Error = 1;}
      *boot_counter = atoi((char*) e24lc02.pData);
}

void EEPROM_Read_Data_BOR_Counter(uint32_t* bor_counter)
{
      // Reading BOR counter data from EEPROM 
      e24lc02.status =  e24lc02.read(e24lc02.eepromI2C, e24lc02.devAddress, (e24lc02.memAddress + 12), (uint8_t*) &e24lc02.pData, e24lc02.size);
      if(e24lc02.status != EEPROM_OK){FOC_F_T.EEPROM_Error = 1;}
      *bor_counter = atoi((char*) e24lc02.pData);
}

void EEPROM_Read_Data_PVD_Counter(uint32_t* pvd_counter)
{
      // Reading PVD counter data from EEPROM 
      e24lc02.status =  e24lc02.read(e24lc02.eepromI2C, e24lc02.devAddress, (e24lc02.memAddress + 24), (uint8_t*) &e24lc02.pData, e24lc02.size);
      if(e24lc02.status != EEPROM_OK){FOC_F_T.EEPROM_Error = 1;}
      *pvd_counter = atoi((char*) e24lc02.pData);
}

void EEPROM_Read_Data_LR_Register(uint32_t* lr_reg)
{
      // Reading LR counter data from EEPROM 
      e24lc02.status =  e24lc02.read(e24lc02.eepromI2C, e24lc02.devAddress, (e24lc02.memAddress + 36), (uint8_t*) &e24lc02.pData, e24lc02.size);
      if(e24lc02.status != EEPROM_OK){FOC_F_T.EEPROM_Error = 1;}
      *lr_reg = atoi((char*) e24lc02.pData);
}

void EEPROM_Read_Data_PC_Register(uint32_t* pc_reg)
{
      // Reading PC counter data from EEPROM 
      e24lc02.status =  e24lc02.read(e24lc02.eepromI2C, e24lc02.devAddress, (e24lc02.memAddress + 48), (uint8_t*) &e24lc02.pData, e24lc02.size);
      if(e24lc02.status != EEPROM_OK){FOC_F_T.EEPROM_Error = 1;}
      *pc_reg = atoi((char*) e24lc02.pData);
}

void EEPROM_Read_Data_trip()
{
      // Reading odometer data from EEPROM 
      e24lc02.status =  e24lc02.read(e24lc02.eepromI2C, e24lc02.devAddress, 0x04, (uint8_t*) &e24lc02.pData, e24lc02.size);
      if(e24lc02.status != EEPROM_OK) 
      serial.print(serial.uart1, "Failed to read Odometer value in EEPROM");
      vehicle.trip = atof((char*) e24lc02.pData);
}

void EEPROM_Write_Data_odo(uint32_t odo)
{
      // Writing odometer data to EEPROM
      char msg[12] ={0};
      sprintf(msg, "%lu", odo);
      e24lc02.size = strlen((char*) msg);
      e24lc02.status = e24lc02.write(e24lc02.eepromI2C, e24lc02.devAddress, e24lc02.memAddress, (uint8_t*)msg);
      // e24lc02.status = e24lc02.write(e24lc02.eepromI2C, e24lc02.devAddress, e24lc02.memAddress, (uint8_t*)"        ");
      if(e24lc02.status != EEPROM_OK) 
      serial.print(serial.uart1, "Failed to write Odometer value to EEPROM");
}

void EEPROM_Write_Data_Boot_Counter(uint32_t boot_counter)
{
      // Writing boot counter data to EEPROM
      char msg[12] ={0};
      sprintf(msg, "%lu", boot_counter);
      e24lc02.size = strlen((char*) msg);
      e24lc02.status = e24lc02.write(e24lc02.eepromI2C, e24lc02.devAddress, e24lc02.memAddress, (uint8_t*)msg);
      if(e24lc02.status != EEPROM_OK){FOC_F_T.EEPROM_Error = 1;}
}

void EEPROM_Write_Data_BOR_Counter(uint32_t bor_counter)
{
      // Writing BOR counter data to EEPROM
      char msg[12] ={0};
      sprintf(msg, "%lu", bor_counter);
      e24lc02.size = strlen((char*) msg);
      e24lc02.status = e24lc02.write(e24lc02.eepromI2C, e24lc02.devAddress, (e24lc02.memAddress + 12), (uint8_t*)msg);
      if(e24lc02.status != EEPROM_OK){FOC_F_T.EEPROM_Error = 1;}
}

void EEPROM_Write_Data_PVD_Counter(uint32_t pvd_counter)
{
      // Writing PVD counter data to EEPROM
      char msg[12] ={0};
      sprintf(msg, "%lu", pvd_counter);
      e24lc02.size = strlen((char*) msg);
      e24lc02.status = e24lc02.write(e24lc02.eepromI2C, e24lc02.devAddress, (e24lc02.memAddress + 24), (uint8_t*)msg);
      if(e24lc02.status != EEPROM_OK){FOC_F_T.EEPROM_Error = 1;}
}

void EEPROM_Write_Data_LR_Register(uint32_t lr_reg)
{
      // Writing LR counter data to EEPROM
      char msg[12] ={0};
      sprintf(msg, "%lu", lr_reg);
      e24lc02.size = strlen((char*) msg);
      e24lc02.status = e24lc02.write(e24lc02.eepromI2C, e24lc02.devAddress, (e24lc02.memAddress + 36), (uint8_t*)msg);
      if(e24lc02.status != EEPROM_OK){FOC_F_T.EEPROM_Error = 1;}
}

void EEPROM_Write_Data_PC_Register(uint32_t pc_reg)
{
      // Writing PC counter data to EEPROM
      char msg[12] ={0};
      sprintf(msg, "%lu", pc_reg);
      e24lc02.size = strlen((char*) msg);
      e24lc02.status = e24lc02.write(e24lc02.eepromI2C, e24lc02.devAddress, (e24lc02.memAddress + 48), (uint8_t*)msg);
      if(e24lc02.status != EEPROM_OK){FOC_F_T.EEPROM_Error = 1;}
}

void EEPROM_Write_Data_trip(uint32_t trip)
{
      // Writing odometer data to EEPROM
      char msg[12] ={0};
      sprintf(msg, "%lu", trip);
      e24lc02.size = strlen((char*) msg);
      e24lc02.status = e24lc02.write(e24lc02.eepromI2C, e24lc02.devAddress, 0x04, (uint8_t*)msg);
      // e24lc02.status = e24lc02.write(e24lc02.eepromI2C, e24lc02.devAddress, e24lc02.memAddress, (uint8_t*)"        ");
      if(e24lc02.status != EEPROM_OK) 
      serial.print(serial.uart1, "Failed to write Odometer value to EEPROM");
}
