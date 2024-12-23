#ifndef __BOR_H__
#define __BOR_H__

#include "stm32h7xx_hal.h"
#include "stm32h743xx.h"
#include "stm32h7xx_hal_flash_ex.h"
#include "flash.h"
#include "stm32h7xx_hal_rcc.h"

void Configure_BOR_Level(void);
void Check_Reset_Source(void);
void Update_BOR_Counter(void);

#endif