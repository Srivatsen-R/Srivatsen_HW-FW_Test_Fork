/*
Pegasus - Motor Controller Unit software for HL,HLP,Storm,Vortex and future projects.

Contributors: Pujit Gandhi,Pratik Rout,Olay,Saksham

This file contains functions associated with vehicle such as throttle, FNR , CAN communication.

*/

#include "main.h"

extern motorControl_t motorControl;
extern adc_t analog;

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

  volatile float final_FilteredValue_a = 0.0;
  volatile float final_FilteredValue_b = 0.0;

  static float prevFilteredValue_a = 0.0;
  static float prevFilteredValue_b = 0.0;
  static float final_prevFilteredValue_a = 0.0;
  static float final_prevFilteredValue_b = 0.0;

  filteredValue_a = analog.bufferData[PHASE_CURRENT_W] - curr_off.W_Phase_Offset;
  filteredValue_b = analog.bufferData[PHASE_CURRENT_V] - curr_off.V_Phase_Offset;

  final_FilteredValue_a = CURRENT_FILTER(filteredValue_a, prevFilteredValue_a, final_prevFilteredValue_a);
  final_FilteredValue_b = CURRENT_FILTER(filteredValue_b, prevFilteredValue_b, final_prevFilteredValue_b);

  #if PEG3W
    FOC_U.PhaseCurrent[0] = (filteredValue_a * 3.297 * 800.0) / 65535.0;
    FOC_U.PhaseCurrent[1] = (filteredValue_b * 3.297 * 800.0) / 65535.0;
    FOC_U.PhaseCurrent[2] = (-FOC_U.PhaseCurrent[0]) + (-FOC_U.PhaseCurrent[1]);
  #endif

  #if PEG4W
    Medhya_U.I_abc[2] = (filteredValue_a * 3.297 * 800.0) / 65535.0;
    Medhya_U.I_abc[1] = (filteredValue_b * 3.297 * 800.0) / 65535.0;
    Medhya_U.I_abc[0] = (-Medhya_U.I_abc[2]) + (-Medhya_U.I_abc[1]);
  #endif

  foc_log.Ia = Medhya_U.I_abc[0];
  foc_log.Ib = Medhya_U.I_abc[1];
  foc_log.Ic = Medhya_U.I_abc[2];

  prevFilteredValue_a = filteredValue_a;
  prevFilteredValue_b = filteredValue_b;
  final_prevFilteredValue_a = final_FilteredValue_a;
  final_prevFilteredValue_b = final_FilteredValue_b;

}
void READ_MOTOR_POSITION()
{
  motorControl.encoder.value =  TIM2->CNT;   // Encoder Count 
}
