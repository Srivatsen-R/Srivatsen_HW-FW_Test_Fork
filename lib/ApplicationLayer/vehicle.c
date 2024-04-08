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

           .odometer=0.0,
           .speed=0.0,
           .trip=0.0,
           .odo_change_status=0.0,
           .calculate_ots = Calculate_OTS
                    };

extern can_t can;
extern foc_t foc;
extern terminal_t terminal;
extern __IO float dc_current;
extern sanity_t fault;
extern motorControl_t motorControl;
extern adc_t analog;
extern float Duty;
extern volatile uint32_t z_trig;
extern uint8_t start_flag;

static float kmph_can;
static float trip_can;
static float odo_can;

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
         target_speed_reference   = 0,
         target_speed_reference_prev = 0;

__IO float speed_filtered         = 0;         

extern int count_duty;

void  Calculate_OTS(uint32_t wheel_rpm)
{
  vehicle.speed = wheel_rpm*RPM_TO_KMPH;
  vehicle.trip = vehicle.trip + (vehicle.speed*(0.5/3600.0));
  vehicle.odometer = vehicle.odometer + (vehicle.speed*(0.5/3600.0));
}


void CAN_Logging()
{
  //Logging CAN data.
    can.dataLoggingForPythonScript(terminal, 
                                  dc_current, 
                                  fault.status, 
                                  motorControl.temperature.motor, 
                                  motorControl, 
                                  analog, 
                                  Duty,
                                  z_trig, 
                                  odo_can, 
                                  kmph_can, 
                                  trip_can, 
                                  fault.fault_code, 
                                  avg_board_temp, 
                                  v_rms);
}


void CAN_Communication(float odo, float trip, float kmph)
{
      kmph_can = kmph*KMPH_CAN_SCALING;
      odo_can = odo*ODO_CAN_SCALING;
      trip_can =trip*10.0;

  
      // 705
      can.txMsg[0][0] = (uint8_t) (motorControl.temperature.motor + 50.0);
      can.txMsg[0][1] = (uint8_t) (avg_board_temp + 50.0);
      can.txMsg[0][2] = (uint8_t)(35);
      can.txMsg[0][4] = ((uint32_t) odo_can & 0x00FF);
      can.txMsg[0][5] = ((uint32_t) odo_can)>>8;
      can.txMsg[0][6] = ((uint32_t) odo_can)>>16;
      can.txMsg[0][7] = ((uint32_t) odo_can)>>24;

      // 706
      if(forward_pin_state == 0 && reverse_pin_state == 1){can.txMsg[1][0] = 0x02;}
      else if(forward_pin_state == 1 && reverse_pin_state == 0){can.txMsg[1][0] = 0x04;}
      else if(forward_pin_state == 1 && reverse_pin_state == 1){can.txMsg[1][0] = 0x01;}

      if (forward_flag)
      {
        if (terminal.iq.sen >= 0.0)
        {
          can.txMsg[1][1] = 0x00;
        }
        else if (terminal.iq.sen < 0.0)
        {
          can.txMsg[1][1] = 0x01;
        }
      }

      if (reverse_flag)
      {
        if (terminal.iq.sen <= 0.0)
        {
          can.txMsg[1][1] = 0x00;
        }
        else if (terminal.iq.sen > 0.0)
        {
          can.txMsg[1][1] = 0x01;
        }
      }

      if (neutral_flag)
      {
        if (motorControl.drive.fnr_status == 1)
        {
          if (terminal.iq.sen >= 0.0)
          {
            can.txMsg[1][1] = 0x00;
          }
          else if (terminal.iq.sen < 0.0)
          {
            can.txMsg[1][1] = 0x01;
          }
        }
        else if (motorControl.drive.fnr_status == 2)
        {
          if (terminal.iq.sen <= 0.0)
          {
            can.txMsg[1][1] = 0x00;
          }
          else if (terminal.iq.sen > 0.0)
          {
            can.txMsg[1][1] = 0x01;
          }
        }
      }

      can.txMsg[1][2] = 0xFF;

      can.txMsg[1][3] = (uint8_t)fault.status;

      can.txMsg[1][4] = (uint8_t) ((uint16_t)(kmph_can * 1.1) & 0x00FF);
      can.txMsg[1][5] = (uint8_t) (((uint16_t)(kmph_can * 1.1) & 0xFF00)>>8);

      can.txMsg[1][6] = (uint8_t) ((uint16_t)trip_can & 0x00FF);
      can.txMsg[1][7] = (uint8_t) (((uint16_t)trip_can & 0xFF00)>>8);

      //710
      can.txMsg[3][0] = (uint8_t)(throttle_percent);
      can.txMsg[3][3] = (uint8_t)(throttle_adc_voltage*THROTTLE_CAN_ADC_SCALING);

      //715
      can.txMsg[4][4] = (uint8_t)busVoltage;
      can.txMsg[4][6] = (uint8_t)((uint16_t)terminal.w.sen & 0x00FF);
      can.txMsg[4][7] = (uint8_t)(((uint16_t)terminal.w.sen & 0xFF00) >> 8);

      //716
      volatile float temp_current = terminal.iq.sen + 1000.0;
      volatile float temp_current_dc = dc_current + 1000.0;
      can.txMsg[5][4] = (uint8_t)(((uint16_t)(temp_current_dc)) & 0x00FF);
      can.txMsg[5][5] = (uint8_t)(((uint16_t)(temp_current_dc) & 0xFF00) >> 8);
      can.txMsg[5][6] = (uint8_t)(((uint16_t)(temp_current)) & 0x00FF);
      can.txMsg[5][7] = (uint8_t)((((uint16_t)(temp_current)) & 0xFF00) >> 8);

      //717
      can.txMsg[6][0] = (uint8_t)((uint16_t)freq_rpm & 0x00FF);
      can.txMsg[6][1] = (uint8_t)(((uint16_t)freq_rpm & 0xFF00) >> 8);

      //724
      can.txMsg[7][0] = (uint8_t)(motorControl.temperature.u + 50.0);
      can.txMsg[7][1] = (uint8_t)(motorControl.temperature.v + 50.0);
      can.txMsg[7][2] = (uint8_t)(motorControl.temperature.w + 50.0);
      can.txMsg[7][3] = (uint8_t)(v_rms);

      //726
      can.txMsg[8][0] = 0x03;
      can.txMsg[8][1] = 0x01;
      can.txMsg[8][2] = 0x01;
      can.txMsg[8][3] = 0x00;
      can.txMsg[8][4] = 0x01;
      can.txMsg[8][5] = 0x01;
      can.txMsg[8][6] = 0x02;
      can.txMsg[8][7] = 0x03;

      //7A0
      can.txMsg[9][0] = 0x03;
      can.txMsg[9][1] = 0x01;
      can.txMsg[9][2] = 0x01;
      can.txMsg[9][3] = 0x02;
      #if APP1
        can.txMsg[9][7] = 0x01;
      #endif
      #if APP2
        can.txMsg[9][7] = 0x02;
      #endif

      can.write();

      // HAL_Delay(10);

}


void READ_FNR()
{
        reverse_pin_state = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_4);
        forward_pin_state = HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3);

        //if speed less than 100 rpm
        if(abs((int)terminal.w.sen) <= 100 && analog.bufferData[THROTTLE] <= 9000.0)
        {
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
        //if(throttle_enable_flag){throttle_input    = moving_Throttle_measured_fun(Read_Throttle(analog.bufferData[THROTTLE]),1);}
        if(reverse_pin_state == 1 && forward_pin_state == 1)
        {
          target_speed_reference -= 5000;
          if(target_speed_reference <= 0){target_speed_reference = 0;}

        }
        else if(forward_pin_state == 0 && motorControl.drive.fnr_status==1) 
        {
          throttle_input    = moving_Throttle_measured_fun(Read_Throttle(analog.bufferData[THROTTLE]),1);
          target_speed_reference  = Rpm_Target_Function(throttle_input);    
        }
        else if(reverse_pin_state == 0 && motorControl.drive.fnr_status==2)
        {
          throttle_input    = moving_Throttle_measured_fun(Read_Throttle(analog.bufferData[THROTTLE]),1);
          target_speed_reference  = Rpm_Target_Function(throttle_input); 
        }

        if(forward_pin_state == 0 && motorControl.drive.fnr_status==2)
        {
          target_speed_reference -= 5000;
          if(target_speed_reference <= 0){target_speed_reference = 0;} 
        }
        else if (reverse_pin_state == 0 && motorControl.drive.fnr_status==1)
        {
          target_speed_reference -= 5000;
          if(target_speed_reference <= 0){target_speed_reference = 0;} 
        }
        
        if (forward_flag)
        {
          if (foc.speed_sense * SPEED_PU_TO_RPM <= 1500.0)
          {
            if (target_speed_reference > target_speed_reference_prev + 60.0 * T_THR)
            {
              target_speed_reference = target_speed_reference_prev + 60.0 * T_THR;
            }
            else if (target_speed_reference < target_speed_reference_prev - 25.0 * T_THR)
            {
              target_speed_reference = target_speed_reference_prev - 25.0 * T_THR;
            }
          }
          else
          {
            if (target_speed_reference > target_speed_reference_prev + 60.0 * T_THR)
            {
              target_speed_reference = target_speed_reference_prev + 60.0 * T_THR;
            }
            else if (target_speed_reference < target_speed_reference_prev - 35.0 * T_THR)
            {
              target_speed_reference = target_speed_reference_prev - 35.0 * T_THR;
            }
          }
        }
        else if (reverse_flag)
        {
          if (target_speed_reference > target_speed_reference_prev + 60.0 * T_THR)
          {
            target_speed_reference = target_speed_reference_prev + 60.0 * T_THR;
          }
          else if (target_speed_reference < target_speed_reference_prev - 20.0 * T_THR)
          {
            target_speed_reference = target_speed_reference_prev - 20.0 * T_THR;
          }
        }
        else if (neutral_flag)
        {
          if (target_speed_reference > target_speed_reference_prev + 60.0 * T_THR)
          {
            target_speed_reference = target_speed_reference_prev + 60.0 * T_THR;
          }
          else if (target_speed_reference < target_speed_reference_prev - 20.0 * T_THR)
          {
            target_speed_reference = target_speed_reference_prev - 20.0 * T_THR;
          }
        }
        // speed_filtered = Throttle_Control(target_speed_reference,speed_filtered,forward_flag,reverse_flag);                  
        ref_output = target_speed_reference;

        target_speed_reference_prev = target_speed_reference;

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





