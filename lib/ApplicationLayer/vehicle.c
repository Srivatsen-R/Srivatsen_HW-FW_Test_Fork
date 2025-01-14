/*
Pegasus - Motor Controller Unit software for HL,HLP,Storm,Vortex and future projects.

Contributors: Pujit Gandhi,Pratik Rout,Olay,Saksham

This file contains functions associated with vehicle such as throttle, FNR , CAN communication.

*/

#include "main.h"

extern motorControl_t motorControl;
extern adc_t analog;

uint16_t offset_cal_w = 32767;
uint16_t offset_cal_v = 32767;

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

  for (uint8_t i = 0; i < 25; i++)
  {
    filteredValue_a += analog.bufferData[PHASE_CURRENT_W];
    filteredValue_b += analog.bufferData[PHASE_CURRENT_V];
  }

  filteredValue_a = filteredValue_a / 25.0f - offset_cal_w;
  filteredValue_b = filteredValue_b / 25.0f - offset_cal_v;

  #if PEG3W
    FOC_U.PhaseCurrent[0] = (filteredValue_a * 3.297 * 800.0) / 65535.0;
    FOC_U.PhaseCurrent[1] = (filteredValue_b * 3.297 * 800.0) / 65535.0;
    FOC_U.PhaseCurrent[2] = (-FOC_U.PhaseCurrent[0]) + (-FOC_U.PhaseCurrent[1]);
  #endif

  #if PEG4W
    FOC_U.PhaseCurrent[2] = (filteredValue_a * 3.297 * 800.0) / 65535.0;
    FOC_U.PhaseCurrent[1] = (filteredValue_b * 3.297 * 800.0) / 65535.0;
    FOC_U.PhaseCurrent[0] = (-FOC_U.PhaseCurrent[2]) + (-FOC_U.PhaseCurrent[1]);
  #endif

}
void READ_MOTOR_POSITION()
{
  motorControl.encoder.value =  TIM2->CNT;   // Encoder Count 
}
