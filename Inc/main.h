
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stm32h7xx_hal.h"
#include "stm32h743xx.h"

#include "adc.h"
#include "dma.h"
#include "fdcan.h"
#include "tim.h"
#include "gpio.h"
#include "i2c.h"
#include "bor.h"
#include "pvd.h"

#include "adc_AL.h"
#include "fdcan_AL.h"
#include "temp_AL.h"

#include "vector_control.h"

#include "motor_param.h"
#include "eeprom_AL.h"
#include "flash.h"
#include "vehicle.h"
#include "sanity.h"
#include "foc_blockset.h"
#include "microcontroller.h"
#include "dr_devices.h"
#include "structures.h"

#include "config.h"
#include "can_tp_app.h"
#include "bootloaderFunctions.h"
#include "firmware_upgrade_app.h"
#include "isotp/isotp_types.h"

#include "FOC.h"
#include "Medhya.h"

#define __IO volatile

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);
uint8_t get_conifg_flag();
void set_config_flag(uint8_t value);
void set_interrupt_flag(uint8_t value);
uint8_t get_interrupt_flag();
void switch_partition_and_reset();
float rate_limiter(float target_rpm);
void get_UIID(void);
void send_on_300(void);
void send_on_301(void);
void send_on_302(void);
void send_on_303(void);
void send_on_304(void);
void send_on_305(void);
void send_on_306(void);
void send_on_307(void);
void send_on_308(void);
void send_on_705(void);
void send_on_706(void);
void send_on_710(void);
void send_on_715(void);
void send_on_716(void);
void send_on_717(void);
void send_on_724(void);
void send_on_726(void);
void send_on_7A0(void);
void send_on_6F0(uint8_t* UIID_Arr);
void send_on_6F1(uint8_t* UIID_Arr);
void send_on_6F2(uint8_t* UIID_Arr);
void Current_Sensor_offset_cal(void);
void CAN_Transmit_routine(void);
void Throttle_Control_routine(void);
void Get_and_Send_UIID(void);
void Boot_Counter(void);
void Led_Toggle(void);
void hard_fault_handler_c(uint32_t*);
void read_hard_fault_cause(void);

/* Private defines -----------------------------------------------------------*/
#define Ibus_U_Pin                GPIO_PIN_0
#define Ibus_U_GPIO_Port          GPIOA
#define Ibus_V_Pin                GPIO_PIN_1
#define Ibus_V_GPIO_Port          GPIOA
#define Ibus_W_Pin                GPIO_PIN_2
#define Ibus_W_GPIO_Port          GPIOA
#define Vbus_sense_Pin            GPIO_PIN_3
#define Vbus_sense_GPIO_Port      GPIOA
#define UCurrent_sensor_Pin       GPIO_PIN_4
#define UCurrent_sensor_GPIO_Port GPIOA
#define VCurrent_sensor_Pin       GPIO_PIN_5
#define VCurrent_sensor_GPIO_Port GPIOA
#define WCurrent_sensor_Pin       GPIO_PIN_6
#define WCurrent_sensor_GPIO_Port GPIOA
#define Utemp_sensor_Pin          GPIO_PIN_4
#define Utemp_sensor_GPIO_Port    GPIOC
#define motor_temp_Pin            GPIO_PIN_5
#define motor_temp_GPIO_Port      GPIOC
#define Vtemp_sensor_Pin          GPIO_PIN_0
#define Vtemp_sensor_GPIO_Port    GPIOB
#define Wtemp_sensor_Pin          GPIO_PIN_1
#define Wtemp_sensor_GPIO_Port    GPIOB
#define brake_pot_Pin             GPIO_PIN_11
#define brake_pot_GPIO_Port       GPIOF
#define throttle_pot_Pin          GPIO_PIN_12
#define throttle_pot_GPIO_Port    GPIOF
#define Hs_W_N_Pin                GPIO_PIN_8
#define Hs_W_N_GPIO_Port          GPIOE
#define Hs_W_Pin                  GPIO_PIN_9
#define Hs_W_GPIO_Port            GPIOE
#define Hs_V_N_Pin                GPIO_PIN_10
#define Hs_V_N_GPIO_Port          GPIOE
#define Hs_V_Pin                  GPIO_PIN_11
#define Hs_V_GPIO_Port            GPIOE
#define Hs_U_N_Pin                GPIO_PIN_12
#define Hs_U_N_GPIO_Port          GPIOE
#define Hs_U_Pin                  GPIO_PIN_13
#define Hs_U_GPIO_Port            GPIOE
#define serial_tx_Pin             GPIO_PIN_14
#define serial_tx_GPIO_Port       GPIOB
#define serial_rx_Pin             GPIO_PIN_15
#define serial_rx_GPIO_Port       GPIOB
#define LED_R_Pin                 GPIO_PIN_10
#define LED_R_GPIO_Port           GPIOD
#define LED_G_Pin                 GPIO_PIN_11
#define LED_G_GPIO_Port           GPIOD
#define LED_B_Pin                 GPIO_PIN_12
#define LED_B_GPIO_Port           GPIOD
#define DRV1_Pin                  GPIO_PIN_13
#define DRV1_GPIO_Port            GPIOD
#define DRV2_Pin                  GPIO_PIN_14
#define DRV2_GPIO_Port            GPIOD
#define DRV3_Pin                  GPIO_PIN_15
#define DRV3_GPIO_Port            GPIOD
#define FWD_Pin                   GPIO_PIN_0
#define FWD_GPIO_Port             GPIOD
#define BKW_Pin                   GPIO_PIN_1
#define BKW_GPIO_Port             GPIOD
#define SW4_Pin                   GPIO_PIN_2
#define SW4_GPIO_Port             GPIOD
#define SW5_Pin                   GPIO_PIN_3
#define SW5_GPIO_Port             GPIOD
#define SW6_Pin                   GPIO_PIN_4
#define SW6_GPIO_Port             GPIOD
#define SW7_Pin                   GPIO_PIN_5
#define SW7_GPIO_Port             GPIOD
#define SW8_Pin                   GPIO_PIN_6
#define SW8_GPIO_Port             GPIOD
#define SW16_Pin                  GPIO_PIN_7
#define SW16_GPIO_Port            GPIOD
/* USER CODE BEGIN Private defines */
typedef struct {
    uint8_t current_state;
    uint8_t previous_state;
    uint8_t throttle_disabled;
} fnr_states;

typedef struct {
    /* data */
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t pc;
    uint32_t psr;
    uint32_t hfsr;
    uint32_t cfsr;
    uint32_t bfar;
    uint32_t mmfar;
} hard_fault_cause;

typedef struct {
    uint16_t W_Phase_Offset;
    uint16_t V_Phase_Offset;
} Current_Off_Calc;

typedef enum {
    FORWARD,
    NEUTRAL,
    REVERSE
} fnr_codes;
typedef struct FOC_Logging {
    float Va;
    float Vb;
    float Vc;
    float Ia;
    float Ib;
    float Ic;
    float G0;
    float G1;
    float G2;
    float G3;
    float G4;
    float G5;
    // float Id;
    // float Iq;
    // float Iq_ref;
    // float Id_ref;
    // float RefSpeed;
    // float ActualSpeed;
    // float Vd;
    // float Vq;
    // float Angle_elec;
    // float Angle_mech;
    // float Angle_intg;
    // float Angle_intg_noml;
    // float Ld_table;
    // float Lq_table;
    // float Lambda_table;
    // uint8_t FWD;
    // uint8_t REV;
    // uint8_t ACC;
    // uint8_t DEACC;
    // uint32_t z_count;
} FOC_Logging;


extern fnr_states fnr;
extern hard_fault_cause hard_fault_c;
extern Current_Off_Calc curr_off;
extern FOC_Logging foc_Log;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
