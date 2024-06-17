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
#include "Pegasus_MBD.h"
#include "rtwtypes.h"


vehicle_t vehicle = {

           .odometer=0.0,
           .speed=0.0,
           .trip=0.0,
           .odo_change_status=0.0,
           .calculate_ots = Calculate_OTS
                    };

extern can_t can;
extern ExtU rtU;
extern ExtY rtY;
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

    rtU.I_a = (a_current * 3.297 * 400.0) / 65535.0;
    rtU.I_b = (b_current * 3.297 * 400.0) / 65535.0;
    rtU.I_c = (-rtU.I_a) + (-rtU.I_b);

    temp_a=0;
    temp_b=0;

}
void READ_MOTOR_POSITION()
{
  motorControl.encoder.value =  TIM2->CNT;   // Encoder Count 
}





