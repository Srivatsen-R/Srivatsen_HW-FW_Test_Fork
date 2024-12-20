#include "pvd.h"
#include "eeprom_AL.h"

extern uint8_t pvd_trig_flag;
extern uint32_t pvd_counter;

void Configure_PVD(void)
{
    // Configure PVD level and mode
    PWR_PVDTypeDef sConfigPVD;
    sConfigPVD.PVDLevel = PWR_PVDLEVEL_2; // 2.25V threshold
    sConfigPVD.Mode = PWR_PVD_MODE_IT_RISING; // Interrupt on rising edge
    HAL_PWR_ConfigPVD(&sConfigPVD);

    // Enable PVD
    HAL_PWR_EnablePVD();

    // Configure and enable EXTI line 16 for PVD
    HAL_NVIC_SetPriority(PVD_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(PVD_IRQn);
}

void PVD_Counter_Update()
{   
    if (pvd_trig_flag)
    {
        EEPROM_Read_Data_PVD_Counter(&pvd_counter);
        pvd_counter += 1;
        EEPROM_Write_Data_PVD_Counter(pvd_counter);
        pvd_trig_flag = 0;
    }
    else 
    {
        //nothing
    }
}