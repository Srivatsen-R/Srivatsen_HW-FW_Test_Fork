#ifndef __GET_FLAGS_H__
#define __GET_FLAGS_H__

#include "stm32h7xx_hal.h"
#include "stm32h743xx.h"
#include "stm32h7xx_hal_rcc.h"

/// @brief  Possible STM32 system reset causes
typedef enum reset_cause_e
{
    RESET_CAUSE_UNKNOWN = 0,
    RESET_CAUSE_LOW_POWER_RESET,
    RESET_CAUSE_WINDOW_WATCHDOG_RESET,
    RESET_CAUSE_INDEPENDENT_WATCHDOG_RESET,
    RESET_CAUSE_SOFTWARE_RESET,
    RESET_CAUSE_POWER_ON_POWER_DOWN_RESET,
    RESET_CAUSE_EXTERNAL_RESET_PIN_RESET,
    RESET_CAUSE_BROWNOUT_RESET,
} reset_cause_t;

void Update_Reset_Cause(void);

reset_cause_t reset_cause_get(void);

const char * reset_cause_get_name(reset_cause_t reset_cause);

extern reset_cause_t reset_cause;

#endif