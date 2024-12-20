/*
Pegasus - Motor Controller Unit software for HL,HLP,Storm,Vortex and future projects.

Contributors: Pujit Gandhi,Pratik Rout,Olay,Saksham

This file contains functions associated with sanity checks for vehicle.

*/

#include <stdlib.h>
#include <math.h>
#include "vehicle.h"
#include "motor_param.h"
#include "vector_control.h"
#include "sanity.h"
#include "adc_AL.h"
#include "dr_devices.h"
#include "FOC.h"
#include "main.h"

#define FDCAN_ERROR_BIT (0x4000A400 + 0x0044)

sanity_t fault = {
        .boardTemperature_u = 0,
        .boardTemperature_v = 0,
        .boardTemperature_w = 0,
        .motorTemperature = 0,
        .motorStall       = 0,
        .busVoltage       = 0,
        .throttle         = 0,
        .currentSensor    = 0,
        .encoder          = 0,
        .overCurrent      = 0,
        .throttleStarting = 0,
        .status           = 0,
        .generic          = 0,
        .fault_code       = 0,
        .run_sanity = RUN_SANITY
};

motorControl_t motorControl = {
        .temperature.u      = 0.0,
        .temperature.v      = 0.0,
        .temperature.w      = 0.0,
        .temperature.motor  = 0.0,
        .encoder.errorCount = 0,
        .encoder.previous   = 0,
        .encoder.value      = 0,
        .drive.check        = 0,
        .drive.status       = 0,
        .drive.fnr_status  =  0,
       
};

extern adc_t          analog;
extern ExtU_FOC_T     FOC_U;
extern ExtY_FOC_T     FOC_Y;
extern FOC_Flag_T     FOC_F_T;
extern terminal_t     terminal;
extern motorControl_t mControl;

float busVoltage = 0.0f;
float avg_board_temp = 0.0f;
float v_rms = 0.0f;
float torque_calc = 0.0f;
float irms_calc = 0.0f;

void FAULT_DETECTION()
{
        uint32_t time_tick_count = HAL_GetTick();
        static uint32_t prev_count_iq = 0;
        static uint32_t prev_count_temp_OT = 0;
        static uint32_t prev_count_phase_curr = 0;
        static uint8_t count_iq = 0;
        static uint8_t count_OT = 0;
        static uint8_t count_phase_Curr = 0;

        if (time_tick_count - prev_count_iq >= 10)
        {
                if (FOC_Y.Iq >= 550.0)
                        count_iq++;

                if (count_iq >= 10.0)
                {
                        count_iq = 0;
                        FOC_F_T.Iq_OL_Flag = 1;
                        motorControl.drive.check = DRIVE_DISABLE;
                }

                prev_count_iq = time_tick_count;
        }

        if (time_tick_count - prev_count_temp_OT >= 10)
        {
                if (avg_board_temp >= 100.0 || motorControl.temperature.motor >= 120.0)
                        count_OT++;

                if (count_OT >= 5.0)
                {
                        count_OT = 0;
                        FOC_F_T.OT_Cont_Flag = 1;
                        motorControl.drive.check = DRIVE_DISABLE;
                }

                prev_count_temp_OT = time_tick_count;
        }

        if (time_tick_count - prev_count_phase_curr >= 10)
        {
                if ((FOC_U.PhaseCurrent[0] >= 550.0 || FOC_U.PhaseCurrent[0] <= -550.0) || (FOC_U.PhaseCurrent[1] >= 550.0 || FOC_U.PhaseCurrent[1] <= -550.0) || (FOC_U.PhaseCurrent[2] >= 550.0 || FOC_U.PhaseCurrent[2] <= -550.0))
                        count_phase_Curr++;

                if (count_phase_Curr >= 10.0)
                {
                        count_phase_Curr = 0;
                        FOC_F_T.Ph_OC_Flag = 1;
                        motorControl.drive.check = DRIVE_DISABLE;
                }

                prev_count_phase_curr = time_tick_count;
        }

        #if DISABLE_ON_NEUTRAL
        if (fnr.current_state == NEUTRAL)
        {       
                FOC_F_T.N_Flag = 1;
                motorControl.drive.check = DRIVE_DISABLE;
        }
        #endif
}

void ANALOG_READING()
{
     //controller temperature 
     motorControl.temperature.u     = moving_Temperature_measured_fun_u(mControl.temperature.read(analog.read(BOARD_TEMP_U)),TEMP_AVG);
     motorControl.temperature.v     = moving_Temperature_measured_fun_v(mControl.temperature.read(analog.read(BOARD_TEMP_V)),TEMP_AVG);
     motorControl.temperature.w     = moving_Temperature_measured_fun_w(mControl.temperature.read(analog.read(BOARD_TEMP_W)),TEMP_AVG);
     avg_board_temp = (motorControl.temperature.u + motorControl.temperature.v + motorControl.temperature.w)/3.0;

     //motor temperature
     double resistance = (analog.bufferData[MOTOR_TEMP_SENSE] * 10000)/(Adc_max_COUNT - analog.bufferData[MOTOR_TEMP_SENSE]);
     double temp_K = resistance/NTC_PULL_UP_RESISTOR;
     temp_K = log(temp_K);
     temp_K /= BETA_VALUE;
     temp_K += 1.0/(T_AMBIENT + KELVIN_TO_CELSIUS);
     temp_K = 1.0/temp_K;
     temp_K -= KELVIN_TO_CELSIUS;
     motorControl.temperature.motor = moving_Temperature_measured_fun_M(temp_K, TEMP_AVG);

     torque_calc = fmax((1.5 * POLEPAIRS * (FOC_U.Lamda * FOC_Y.Iq + (FOC_U.Ld - FOC_U.Lq) * FOC_Y.Id * FOC_Y.Iq)), torque_calc);
     irms_calc = fmax(sqrtf(FOC_Y.Iq * FOC_Y.Iq + FOC_Y.Id * FOC_Y.Id), irms_calc) / sqrtf(2.0f);
     v_rms = sqrtf(FOC_Y.Vq * FOC_Y.Vq + FOC_Y.Vd * FOC_Y.Vd) / sqrtf(2.0f);

     //bus voltage
     busVoltage = moving_Batt_voltage_measured_fun(0.00211*analog.bufferData[BUS_VOLTAGE],VOLTAGE_AVG); 
     terminal.volt.bus_volt = busVoltage; 
     FOC_U.BusVoltage_V = busVoltage;

     FOC_U.MotorTemperature_C = motorControl.temperature.motor;
     FOC_U.MCTemperature_C = avg_board_temp;
}
