/*
Pegasus - Motor Controller Unit software for HL,HLP,Storm,Vortex and future projects.

Contributors: Pujit Gandhi,Pratik Rout,Olay,Saksham

This file contains functions associated with measuring, filtering , error and fault detection for 
various physical parameters such as throttle, voltage , current , temperature.

*/

#include <stdint.h>
#include "motor_param.h"
#include "vector_control.h"
#include "foc_blockset.h"


int moving_Throttle_measured_fun(int current_val,int MOV_AVG_SAMPLE )
{
    static float Prev_current_val;
    float Bus_Current_Error_value;
    Bus_Current_Error_value = (current_val - Prev_current_val);
    Prev_current_val += (Bus_Current_Error_value / MOV_AVG_SAMPLE);
    current_val = Prev_current_val ;
    return current_val ;
}

float moving_Temperature_measured_fun( float current_val , float MOV_AVG_SAMPLE)   // 0.1 amp Batt_current_measured
{
    static float Prev_current_val;
    float Bus_Current_Error_value;
    Bus_Current_Error_value = (current_val - Prev_current_val);
    Prev_current_val += (Bus_Current_Error_value / MOV_AVG_SAMPLE);
    current_val = Prev_current_val ;
    return current_val ;
}

float moving_Batt_voltage_measured_fun( float current_val , float MOV_AVG_SAMPLE)   // 0.1 amp Batt_current_measured
{
    static float Prev_current_val;
    float Bus_Current_Error_value;
    Bus_Current_Error_value = (current_val - Prev_current_val);
    Prev_current_val += (Bus_Current_Error_value / MOV_AVG_SAMPLE);
    current_val = Prev_current_val ;
    return current_val ;
}

float Throttle_Control(int target_speed,float prev_output)
{
    float th_increment,th_decrement;

        if(target_speed >= prev_output)
        {
            th_increment = 100 / F_SW;

            if(target_speed >= (prev_output + th_increment)) prev_output += th_increment ;
            else prev_output = target_speed ;

            FOC_F_T.Acc = 1;
            FOC_F_T.Deacc = 0;
        }
        else
        {
            th_decrement = 100 / F_SW;

            if(target_speed <= (prev_output - th_decrement)) prev_output -= th_decrement ;
            else prev_output = target_speed ;

            FOC_F_T.Acc = 0;
            FOC_F_T.Deacc = 1;
        }

    return prev_output;
}

int Rpm_Target_Function(int  throttle_input)
{
    int rpm_th_temp ;

    rpm_th_temp = ((throttle_input) - THROTTLE_ADC_OFFSET_COUNT)*SPEED_MUL_FACTOR ;// 0.27~7950
    if(rpm_th_temp<0){rpm_th_temp=0;}
    if(rpm_th_temp>MAX_SPEED*SPEED_MUL_FACTOR){rpm_th_temp=MAX_SPEED*SPEED_MUL_FACTOR;}
    return ((rpm_th_temp));
}

int Read_Throttle(int adc_data)
{
    adc_data  = adc_data - 8500 ;
 
    if(adc_data<0)
    {
        adc_data=0;
    }

    return adc_data;
}
