/*
Pegasus - Motor Controller Unit software for HL,HLP,Storm,Vortex and future projects.

Contributors: Pujit Gandhi,Pratik Rout,Olay,Saksham

This file contains functions associated with sanity checks for vehicle.

*/

#include <stdlib.h>
#include <math.h>
#include "math_func.h"
#include "vehicle.h"
#include "motor_param.h"
#include "vector_control.h"
#include "sanity.h"
#include "adc_AL.h"
#include "dr_devices.h"
#include "Pegasus_MBD.h"
#include "rtwtypes.h"

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
        .fault_code       = 0x00000000,
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
extern ExtU           rtU;
extern terminal_t     terminal;
extern motorControl_t mControl;

__IO float dc_current = 0.0; 
extern __IO float speed_filtered;
float busVoltage=0;
float avg_board_temp=0;
float v_rms=0;

extern float encoder_a_state;
extern float encoder_b_state;
extern float Duty;
extern int counter_current_ms;
extern int counter_encoder_ms;
extern int counter_abnormal_run;
extern float throttle_adc_voltage;

extern int reverse_pin_state;
extern int forward_pin_state;

extern float freq_rpm;
extern float throttle_percent;

extern int count_duty;
extern int forward_flag;
extern int reverse_flag;

void FAULT_DETECTION()
{
        if (rtY.CurrentFlag == OC_Warning)
        {
                if (motorControl.drive.check == DRIVE_DISABLE)
                {
                        motorControl.drive.check = DRIVE_ENABLE;
                }
        }
        else if (rtY.CurrentFlag == OC_Error)
        {
                motorControl.drive.check = DRIVE_DISABLE;
        }

        if (rtU.MotorTemperature_C >= 130.0)
        {
                motorControl.drive.check = DRIVE_DISABLE;
        }
        else if (rtU.MotorTemperature_C < 100.0)
        {
                if (motorControl.drive.check == DRIVE_DISABLE)
                {
                        motorControl.drive.check = DRIVE_ENABLE;
                }
        }

        if (rtU.MotorControllerTemperature_C >= 100.0)
        {
                motorControl.drive.check = DRIVE_DISABLE;
        }
        else if (rtU.MotorControllerTemperature_C < 100.0)
        {
                if (motorControl.drive.check == DRIVE_DISABLE)
                {
                        motorControl.drive.check = DRIVE_ENABLE;
                }
        }

        // if (rtY.VoltageFlag == OV_Warning)
        // {
        //         if (motorControl.drive.check == DRIVE_DISABLE)
        //         {
        //                 motorControl.drive.check = DRIVE_ENABLE; 
        //         }
        // }
        // else if (rtY.VoltageFlag == OV_Error)
        // {
        //         motorControl.drive.check = DRIVE_DISABLE;
        // }

        // if (rtY.MCTempFlag == OT_Warning)
        // {
        //         if (motorControl.drive.check == DRIVE_DISABLE)
        //         {
        //                 motorControl.drive.check = DRIVE_ENABLE;
        //         }
        // }
        // else if (rtY.MCTempFlag == OT_Error)
        // {
        //         motorControl.drive.check = DRIVE_DISABLE;
        // }

        // float V_max = sqrtf(powf(rtY.FOC_Out.Vq_Calculated, 2.0f) + powf(rtY.FOC_Out.Vd_Calculated, 2.0f));

        // if (V_max >= rtU.BusVoltage_V)
        // {
        //         motorControl.drive.check = DRIVE_DISABLE;
        // }
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

     rtU.MotorControllerTemperature_C = avg_board_temp;
     rtU.MotorTemperature_C = motorControl.temperature.motor;

     //bus voltage
     busVoltage = moving_Batt_voltage_measured_fun(0.00211*analog.bufferData[BUS_VOLTAGE] +VBUS_OFFSET,VOLTAGE_AVG); 
     terminal.volt.bus_volt = busVoltage; 

     rtU.BusVoltage_V = 57.4;
}
