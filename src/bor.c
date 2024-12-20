#include "bor.h"
#include "eeprom_AL.h"

extern uint32_t bor_counter;
extern uint8_t bor_counter_trig;

void Configure_BOR_Level(void)
{
    // Unlock the Flash memory interface
    HAL_FLASH_Unlock();
    HAL_FLASH_OB_Unlock();

    // Initialize the Option Bytes structure
    FLASH_OBProgramInitTypeDef OBInit;
    HAL_FLASHEx_OBGetConfig(&OBInit);

    // Set the desired BOR level
    OBInit.OptionType = OPTIONBYTE_BOR;
    OBInit.BORLevel = OB_BOR_LEVEL3; // Set to BOR Level 0 (2.7V)

    // Program the Option Bytes
    if (HAL_FLASHEx_OBProgram(&OBInit) != HAL_OK) {
        // Handle error
    }

    // Launch the Option Bytes loading
    if (HAL_FLASH_OB_Launch() != HAL_OK) {
        // Handle error
    }

    // Lock the Flash memory interface
    HAL_FLASH_OB_Lock();
    HAL_FLASH_Lock();
}

void Check_Reset_Source(void) 
{
    // Check if a BOR reset occurred
    if (__HAL_RCC_GET_FLAG(RCC_FLAG_BORRST)) {
        // BOR reset occurred
        // Implement your handling code here

        bor_counter_trig = 1;

        // Clear the BOR reset flag
        __HAL_RCC_CLEAR_RESET_FLAGS();
    }
    else {
        bor_counter_trig = 0;
    }
}

void Update_BOR_Counter()
{
    if (bor_counter_trig)
    {
        EEPROM_Read_Data_BOR_Counter(&bor_counter);
        bor_counter += 1;
        EEPROM_Write_Data_BOR_Counter(bor_counter);
        bor_counter_trig = 0;
    }
    else
    {
        //nothing
    }
}