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
#include "Position_Calculation.h"
#include "FOC.h"
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

extern ExtU_FOC_T FOC_U;
extern ExtY_FOC_T FOC_Y;

extern ExtU_Angle rtU_Angle;
extern ExtY_Angle rtY_Angle;
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

uint16_t offset_cal_w = 0;
uint16_t offset_cal_v = 0;

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

float lowPassFilter(float input, float prevFilteredValue) {
    // Apply the exponential moving average (EMA) filter
    prevFilteredValue = (ALPHA * input) + ((1.0 - ALPHA) * (prevFilteredValue));
    return prevFilteredValue;
}

void READ_MOTOR_PHASE_CURRENT()
{
  volatile float filteredValue_a = 0.0;
  volatile float filteredValue_b = 0.0;

  for (uint8_t i = 0; i < 10; i++)
  {
    filteredValue_a = lowPassFilter((float)(analog.bufferData[PHASE_CURRENT_W] - offset_cal_w), filteredValue_a);
    filteredValue_b = lowPassFilter((float)(analog.bufferData[PHASE_CURRENT_V] - offset_cal_v), filteredValue_b);
  }

  #if PEG3W
    FOC_U.PhaseCurrent[0] = (filteredValue_a * 3.297 * 400.0) / 65535.0;
    FOC_U.PhaseCurrent[1] = (filteredValue_b * 3.297 * 400.0) / 65535.0;
    FOC_U.PhaseCurrent[2] = (-FOC_U.PhaseCurrent[0]) + (-FOC_U.PhaseCurrent[1]);
  #endif

  #if PEG4W
    FOC_U.PhaseCurrent[2] = (filteredValue_a * 3.297 * 400.0) / 65535.0;
    FOC_U.PhaseCurrent[1] = (filteredValue_b * 3.297 * 400.0) / 65535.0;
    FOC_U.PhaseCurrent[0] = (-FOC_U.PhaseCurrent[2]) + (-FOC_U.PhaseCurrent[1]);
  #endif

}
void READ_MOTOR_POSITION()
{
  motorControl.encoder.value =  TIM2->CNT;   // Encoder Count 
  rtU_Angle.Encoder_Cnt = motorControl.encoder.value;
}
