/*
Pegasus - Motor Controller Unit software for HL,HLP,Storm,Vortex and future projects.

Contributors: Pujit Gandhi,Pratik Rout,Olay,Saksham

This file contains functions associated with vehicle such as throttle, FNR , CAN communication.

*/

#include <math.h>
#include "vehicle.h"
#include "motor_param.h"
#include "vector_control.h"
#include "sanity.h"
#include "foc_blockset.h"
#include "FOC.h"

extern motorControl_t motorControl;
extern adc_t analog;

uint16_t offset_cal_w = 32996;
uint16_t offset_cal_v = 32996;

float lowPassFilter(float input, float prevFilteredValue) 
{
  // Apply the exponential moving average (EMA) filter
  prevFilteredValue = (ALPHA * input) + ((1.0 - ALPHA) * (prevFilteredValue));
  return prevFilteredValue;
}

void READ_MOTOR_PHASE_CURRENT()
{
  volatile float filteredValue_a = 0.0;
  volatile float filteredValue_b = 0.0;

  for (uint8_t i = 0; i < 20; i++)
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
}
