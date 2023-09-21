/*
Pegasus - Motor Controller Unit software for HL,HLP,Storm,Vortex and future projects.

Contributors: Pujit Gandhi,Pratik Rout,Olay,Saksham

This file contains functions associated with vehicle such as throttle, FNR , CAN communication.

*/



#include <math.h>
#include "math_func.h"
#include "vehicle.h"
#include "motor_param.h"
#include "vector_control.h"
#include "fdcan_AL.h"
#include "foc_blockset.h"


vehicle_t vehicle = {

           .odometer=0,
           .speed=0,
           .trip=0,
           .odo_change_status=0,
           .calculate_ots = Calculate_OTS
                    };

extern can_t can;
extern terminal_t terminal;
extern __IO float dc_current;
extern sanity_t fault;
extern float motorT;
extern motorControl_t motorControl;
extern adc_t analog;
extern float Duty;
extern volatile uint32_t angle;

static float kmph_can;
static float trip_can;
static uint32_t odo_can;

extern float avg_board_temp ;
extern float v_rms ;
extern float throttle_percent ;
float throttle_adc_voltage=0;
extern float busVoltage;
extern float freq_rpm;
int forward_flag=0;
int reverse_flag=0;
int neutral_flag=0;
float encoder_a_state=0;
float encoder_b_state=0;


int reverse_pin_state=1;
int forward_pin_state=1;
int throttle_enable_flag=0;
float ref_output=0;

__IO int a_current                = 0,
         b_current                = 0,
         throttle_input           = 0,
         target_speed_reference   = 0;

__IO float speed_filtered         = 0;         



void  Calculate_OTS(uint32_t wheel_rpm)
{

uint32_t odo_prev;

odo_prev = vehicle.odometer;
vehicle.speed = wheel_rpm*RPM_TO_KMPH;
vehicle.trip = vehicle.trip +(vehicle.speed*HOUR_TO_MS_100);
vehicle.odometer = vehicle.odometer + vehicle.trip;

if(vehicle.odometer>odo_prev)
{
    vehicle.odo_change_status = ODO_UPDATE;
}


}


void CAN_Logging()
{
  //Logging CAN data.
    can.dataLoggingForPythonScript(terminal, 
                                  dc_current, 
                                  fault.status, 
                                  motorT, 
                                  motorControl, 
                                  analog, 
                                  Duty,
                                  angle, (float)odo_can, (float)kmph_can, (float)trip_can, (float)fault.fault_code, forward_pin_state, reverse_pin_state);
                                  //angle, (float)odo_can, (float)kmph_can, (float)trip_can, (float)fault.fault_code, avg_board_temp, v_rms);
}


void CAN_Communication(uint32_t odo, float trip, float kmph)
{
  
      // odo = 54321;//0.1 scaling
      // trip = 200;//no scaling
      // kmph = 365;//0.1 scaling

      kmph_can = kmph*KMPH_CAN_SCALING;
      odo_can = odo*ODO_CAN_SCALING;
      trip_can =trip;

  
      // 705
      can.txMsg[0][0] = (uint8_t) motorControl.temperature.motor;
      can.txMsg[0][1] = (uint8_t) motorControl.temperature.u;
      can.txMsg[0][2] = (uint8_t) motorControl.temperature.v;
      can.txMsg[0][3] = (uint8_t) motorControl.temperature.w;
      can.txMsg[0][4] = ((uint32_t) odo_can & 0xFF);
      can.txMsg[0][5] = ((uint32_t) odo_can)>>8;
      can.txMsg[0][6] = ((uint32_t) odo_can)>>16;
      can.txMsg[0][7] = ((uint32_t) odo_can)>>24;

      // 706
      can.txMsg[1][0] = motorControl.direction & 0x07;
      can.txMsg[1][1] = motorControl.status;
      can.txMsg[1][2] = motorControl.assistGear;
      can.txMsg[1][3] = motorControl.alarm;
      can.txMsg[1][4] = ((uint16_t) kmph_can);
      can.txMsg[1][5] = ((uint16_t) kmph_can)>>8;
      can.txMsg[1][6] = ((uint16_t) trip_can);
      can.txMsg[1][7] = ((uint16_t) trip_can)>>8;

      // 708
      can.txMsg[2][0] = fault.boardTemperature_u;
      can.txMsg[2][1] = fault.busVoltage;
      can.txMsg[2][2] = fault.currentSensor;
      can.txMsg[2][3] = fault.encoder;
      can.txMsg[2][4] = fault.motorTemperature;
      can.txMsg[2][5] = fault.overCurrent;
      can.txMsg[2][6] = fault.throttle;
      can.txMsg[2][7] = fault.status;

      //710
      can.txMsg[3][0] = (uint8_t)((int)throttle_percent);
      can.txMsg[3][3] = (uint8_t)(throttle_adc_voltage*THROTTLE_CAN_ADC_SCALING);

      //715
      can.txMsg[4][4] = (uint8_t)busVoltage;
      can.txMsg[4][6] = (uint8_t)((int)terminal.w.sen & 0x0FF);
      can.txMsg[4][7] = (uint8_t)(((int)terminal.w.sen & 0xFF00) >> 8);

      //716
      can.txMsg[5][6] = (uint8_t)((int)terminal.iq.sen & 0x00FF);
      can.txMsg[5][7] = (uint8_t)(((int)terminal.iq.sen & 0xFF00) >> 8);

      //717
      can.txMsg[6][0] = (uint8_t)((int)freq_rpm & 0x00FF);
      can.txMsg[6][1] = (uint8_t)(((int)freq_rpm & 0xFF00) >> 8);

      //724
      if(forward_flag || reverse_flag){
        can.txMsg[7][4] = 0x01;
      }else{
        can.txMsg[7][4] = 0x00;
      }

      //726
      can.txMsg[8][3] = 0x6E;
      can.txMsg[8][4] = 0xE1;
      can.txMsg[8][6] = 0x01;
      can.txMsg[8][7] = 0x04;

      can.write();

}


void READ_FNR()
{
        reverse_pin_state = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3);
        forward_pin_state = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_4);

        //if speed less than 100 rpm
        if(abs((int)terminal.w.sen) <= 100){

          if(forward_pin_state==FW_DIRECTION)
          {
            forward_flag = 1;
            reverse_flag = 0;
            neutral_flag = 0;
            throttle_enable_flag = 1;
            motorControl.drive.fnr_status=1;
            
          }

          if(reverse_pin_state==RW_DIRECTION)
          {
            reverse_flag = 1;
            forward_flag = 0;
            neutral_flag = 0;
            throttle_enable_flag = 1;
            motorControl.drive.fnr_status=2;
            
          }

          if(reverse_pin_state == 1 && forward_pin_state == 1){
            reverse_flag = 0;
            forward_flag = 0;
            neutral_flag = 1;
            throttle_enable_flag = 0; 
          }
        }

        //if speed greater than 100rpm
        if(reverse_pin_state == 1 && forward_pin_state == 1){
            
            reverse_flag = 0;
            forward_flag = 0;
            neutral_flag = 1;
            throttle_enable_flag = 0; 
          }

}
void READ_THROTTLE()
{
        if(throttle_enable_flag)
        {
        throttle_input    = moving_Throttle_measured_fun(Read_Throttle(analog.bufferData[THROTTLE]),1);    // RAW ADC DATA. moving_Throttle_measured_fun   
        }

        if(reverse_pin_state == 1 && forward_pin_state == 1){
          target_speed_reference -= 1200;
          if(target_speed_reference <= 0){target_speed_reference = 0;}
        }else{
          target_speed_reference  = Rpm_Target_Function(throttle_input);
        }
        
        speed_filtered = Throttle_Control(target_speed_reference,speed_filtered,forward_flag,reverse_flag);                  
        ref_output = speed_filtered;

}
void READ_MOTOR_PHASE_CURRENT()
{

    int temp_a=0;
    int temp_b=0;
    int count=0;
  
    for (count=0;count<20;count++)
    {
            temp_a  = temp_a + ((analog.bufferData[PHASE_CURRENT_W]/DIV_FACTOR_CURRENT) - OFFSET_CURRENT);
            temp_b  = temp_b + ((analog.bufferData[PHASE_CURRENT_V]/DIV_FACTOR_CURRENT) - OFFSET_CURRENT);
    }    

    a_current = temp_a/CURRENT_AVG_FACTOR;
    b_current = temp_b/CURRENT_AVG_FACTOR;

    temp_a=0;
    temp_b=0;

}
void READ_MOTOR_POSITION()
{
  motorControl.encoder.value =  TIM2->CNT;   // Encoder Count 
  encoder_a_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15);
  encoder_b_state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
}





