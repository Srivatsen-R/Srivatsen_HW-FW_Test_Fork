/*
 * File: Pegasus_MBD.c
 *
 * Code generated for Simulink model 'Pegasus_MBD'.
 *
 * Model version                  : 1.137
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon May 20 14:05:05 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. Execution efficiency
 * Validation result: Not run
 */

#include "Pegasus_MBD.h"
#include <math.h>
#include "rtwtypes.h"
#include "vector_control.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void Pegasus_MBD_step(void)
{
  real_T rtb_NProdOut;
  real_T rtb_NProdOut_n;
  real_T rtb_Saturation2;
  real_T rtb_Sum;
  real_T rtb_Sum_b;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  real_T rtb_Switch_k;
  real_T tmp;
  real32_T rtb_Add3;
  real32_T rtb_DataTypeConversion7;
  real32_T rtb_MtrPos_rad;
  real32_T rtb_Saturation;
  real32_T rtb_Sin_tmp;
  real32_T rtb_Switch_n_idx_0;

  /* Gain: '<S2>/Gain' incorporates:
   *  Inport: '<Root>/MtrPos_rad'
   */
  rtb_MtrPos_rad = 3.0F * rtU.MtrPos_rad;

  /* Trigonometry: '<S6>/Sin' incorporates:
   *  BusCreator: '<S2>/Bus Creator1'
   *  Trigonometry: '<S6>/Sin1'
   */
  rtb_Sin_tmp = sinf(rtb_MtrPos_rad);

  /* Outputs for Atomic SubSystem: '<S6>/Clarke Transform' */
  /* Gain: '<S7>/one_by_sqrt3' incorporates:
   *  Inport: '<Root>/I_a'
   *  Inport: '<Root>/I_b'
   *  Sum: '<S7>/a_plus_2b'
   */
  rtb_DataTypeConversion7 = (rtU.I_a + rtU.I_b + rtU.I_b) * 0.577350259F;

  /* End of Outputs for SubSystem: '<S6>/Clarke Transform' */

  /* Trigonometry: '<S6>/Cos' incorporates:
   *  BusCreator: '<S2>/Bus Creator1'
   *  Trigonometry: '<S6>/Cos1'
   */
  rtb_MtrPos_rad = cosf(rtb_MtrPos_rad);

  /* Outputs for Atomic SubSystem: '<S6>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S6>/Clarke Transform' */
  /* Switch: '<S110>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S7>/a16'
   *  Inport: '<Root>/I_a'
   *  Product: '<S12>/acos'
   *  Product: '<S12>/asin'
   *  Product: '<S12>/bcos'
   *  Product: '<S12>/bsin'
   *  Sum: '<S12>/sum_Ds'
   *  Sum: '<S12>/sum_Qs'
   *  Trigonometry: '<S6>/Cos'
   *  Trigonometry: '<S6>/Sin'
   */
  rtb_Switch_n_idx_0 = (rtU.I_a * rtb_MtrPos_rad) + (rtb_DataTypeConversion7 *
    rtb_Sin_tmp);
  rtb_DataTypeConversion7 = (rtb_DataTypeConversion7 * rtb_MtrPos_rad) -
    (rtU.I_a * rtb_Sin_tmp);

  /* End of Outputs for SubSystem: '<S6>/Clarke Transform' */

  /* Product: '<S96>/NProd Out' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   *  Constant: '<S6>/Constant3'
   *  DiscreteIntegrator: '<S88>/Filter'
   *  Inport: '<Root>/FilterCoefficient'
   *  Inport: '<Root>/Gain_Dd'
   *  Product: '<S87>/DProd Out'
   *  Sum: '<S6>/Add2'
   *  Sum: '<S88>/SumD'
   */
  rtb_NProdOut = (((real_T)((real32_T)(0.0F - rtb_Switch_n_idx_0)) * rtU.Dd) -
                  rtDW.Filter_DSTATE) * rtU.FilterCoefficient;

  /* Sum: '<S102>/Sum' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   *  Constant: '<S6>/Constant3'
   *  DiscreteIntegrator: '<S93>/Integrator'
   *  Inport: '<Root>/Gain_Pd'
   *  Product: '<S98>/PProd Out'
   *  Sum: '<S6>/Add2'
   */
  rtb_Sum = ((real_T)((real32_T)(0.0F - rtb_Switch_n_idx_0)) * rtU.Pd) +
    rtDW.Integrator_DSTATE + rtb_NProdOut;

  /* End of Outputs for SubSystem: '<S6>/Park Transform' */

  /* Outport: '<Root>/Vd_Calculated' */
  rtY.Vd_Calculated = rtb_Sum;

  /* Product: '<S6>/Product' incorporates:
   *  Inport: '<Root>/Iq_Torque_ratio'
   *  Inport: '<Root>/Torque'
   */
  rtb_Saturation = rtU.Torque * rtU.Iq_Torque_ratio;

  /* Saturate: '<S6>/Saturation' */
  if (rtb_Saturation > 40.0F) {
    rtb_Saturation = 40.0F;
  } else if (rtb_Saturation < -40.0F) {
    rtb_Saturation = -40.0F;
  } else {
    /* no actions */
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S6>/Park Transform' */
  /* Sum: '<S6>/Add3' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   */
  rtb_Add3 = rtb_Saturation - rtb_DataTypeConversion7;

  /* End of Outputs for SubSystem: '<S6>/Park Transform' */

  /* Product: '<S48>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S40>/Filter'
   *  Inport: '<Root>/FilterCoefficient'
   *  Inport: '<Root>/Gain_Dq'
   *  Product: '<S39>/DProd Out'
   *  Sum: '<S40>/SumD'
   */
  rtb_NProdOut_n = (((real_T)rtb_Add3 * rtU.Dq) - rtDW.Filter_DSTATE_f) *
    rtU.FilterCoefficient;

  /* Sum: '<S54>/Sum' incorporates:
   *  DiscreteIntegrator: '<S45>/Integrator'
   *  Inport: '<Root>/Gain_Pq'
   *  Product: '<S50>/PProd Out'
   */
  rtb_Sum_b = ((real_T)rtb_Add3 * rtU.Pq) + rtDW.Integrator_DSTATE_e +
    rtb_NProdOut_n;

  /* Outputs for Atomic SubSystem: '<S6>/Inverse Park Transform' */
  /* Switch: '<S13>/Switch' incorporates:
   *  Product: '<S9>/dcos'
   *  Product: '<S9>/dsin'
   *  Product: '<S9>/qcos'
   *  Product: '<S9>/qsin'
   *  Sum: '<S9>/sum_alpha'
   *  Sum: '<S9>/sum_beta'
   */
  rtb_Switch_idx_0 = (rtb_Sum * (real_T)rtb_MtrPos_rad) - (rtb_Sum_b * (real_T)
    rtb_Sin_tmp);
  rtb_Switch_idx_1 = (rtb_Sum_b * (real_T)rtb_MtrPos_rad) + (rtb_Sum * (real_T)
    rtb_Sin_tmp);

  /* Gain: '<S8>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   */
  rtb_Sum = 0.5 * rtb_Switch_idx_0;

  /* Gain: '<S8>/sqrt3_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   */
  rtb_Switch_idx_1 *= 0.8660254037844386;

  /* Saturate: '<S6>/Saturation1' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   */
  if (rtb_Switch_idx_0 > 60.0) {
    rtb_Switch_idx_0 = 60.0;
  } else if (rtb_Switch_idx_0 < -60.0) {
    rtb_Switch_idx_0 = -60.0;
  } else {
    /* no actions */
  }

  /* End of Saturate: '<S6>/Saturation1' */
  /* End of Outputs for SubSystem: '<S6>/Inverse Park Transform' */

  /* Sum: '<S8>/add_b' */
  rtb_Saturation2 = rtb_Switch_idx_1 - rtb_Sum;

  /* Saturate: '<S6>/Saturation2' */
  if (rtb_Saturation2 > 60.0) {
    rtb_Saturation2 = 60.0;
  } else if (rtb_Saturation2 < -60.0) {
    rtb_Saturation2 = -60.0;
  } else {
    /* no actions */
  }

  /* End of Saturate: '<S6>/Saturation2' */

  /* Outport: '<Root>/Vb' */
  rtY.Vb = rtb_Saturation2;

  /* Product: '<S4>/Divide' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion7'
   *  Inport: '<Root>/Thresholds'
   */
  rtb_Switch_k = rtb_Saturation2 / (real_T)((real32_T)
    rtU.Thresholds.MaxBusVoltage_V);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Zero'
   */
  if (rtb_Saturation2 > 0.0) {
    tmp = rtb_Switch_k;
  } else {
    tmp = 0.0;
  }

  /* Outport: '<Root>/Duty_b+' incorporates:
   *  Abs: '<S4>/Abs'
   *  Switch: '<S4>/Switch'
   */
  rtY.Duty_b = fabs(tmp);

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/Zero'
   *  Gain: '<S4>/Gain'
   */
  if (-rtb_Saturation2 <= 0.0) {
    rtb_Switch_k = 0.0;
  }

  /* Outport: '<Root>/Duty_b-' incorporates:
   *  Abs: '<S4>/Abs1'
   *  Switch: '<S4>/Switch1'
   */
  rtY.Duty_b_a = fabs(rtb_Switch_k);

  /* Product: '<S3>/Divide' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion7'
   *  Inport: '<Root>/Thresholds'
   */
  rtb_Saturation2 = rtb_Switch_idx_0 / (real_T)((real32_T)
    rtU.Thresholds.MaxBusVoltage_V);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Zero'
   */
  if (rtb_Switch_idx_0 > 0.0) {
    tmp = rtb_Saturation2;
  } else {
    tmp = 0.0;
  }

  /* Outport: '<Root>/Duty_a+' incorporates:
   *  Abs: '<S3>/Abs'
   *  Switch: '<S3>/Switch'
   */
  rtY.Duty_a = fabs(tmp);

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/Zero'
   *  Gain: '<S3>/Gain'
   */
  if (-rtb_Switch_idx_0 <= 0.0) {
    rtb_Saturation2 = 0.0;
  }

  /* Outport: '<Root>/Duty_a-' incorporates:
   *  Abs: '<S3>/Abs1'
   *  Switch: '<S3>/Switch1'
   */
  rtY.Duty_a_f = fabs(rtb_Saturation2);

  /* Sum: '<S8>/add_c' */
  rtb_Sum = 0.0 - rtb_Sum - rtb_Switch_idx_1;

  /* Saturate: '<S6>/Saturation3' */
  if (rtb_Sum > 60.0) {
    rtb_Sum = 60.0;
  } else if (rtb_Sum < -60.0) {
    rtb_Sum = -60.0;
  } else {
    /* no actions */
  }

  /* End of Saturate: '<S6>/Saturation3' */

  /* Product: '<S5>/Divide' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion7'
   *  Inport: '<Root>/Thresholds'
   */
  rtb_Saturation2 = rtb_Sum / (real_T)((real32_T)rtU.Thresholds.MaxBusVoltage_V);

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Zero'
   */
  if (rtb_Sum > 0.0) {
    tmp = rtb_Saturation2;
  } else {
    tmp = 0.0;
  }

  /* Outport: '<Root>/Duty_c+' incorporates:
   *  Abs: '<S5>/Abs'
   *  Switch: '<S5>/Switch'
   */
  rtY.Duty_c = fabs(tmp);

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Zero'
   *  Gain: '<S5>/Gain'
   */
  if (-rtb_Sum <= 0.0) {
    rtb_Saturation2 = 0.0;
  }

  /* Outport: '<Root>/Duty_c-' incorporates:
   *  Abs: '<S5>/Abs1'
   *  Switch: '<S5>/Switch1'
   */
  rtY.Duty_c_h = fabs(rtb_Saturation2);

  /* Outport: '<Root>/Vc' */
  rtY.Vc = rtb_Sum;

  /* Outport: '<Root>/Va' */
  rtY.Va = rtb_Switch_idx_0;

  /* Outport: '<Root>/Vq_Calculated' */
  rtY.Vq_Calculated = rtb_Sum_b;

  /* Outport: '<Root>/Iq_Refer' */
  rtY.Iq_Refer = rtb_Saturation;

  /* Outputs for Atomic SubSystem: '<S6>/Park Transform' */
  /* Outport: '<Root>/Iq_Calculated' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   */
  rtY.Iq_Calculated = rtb_DataTypeConversion7;

  /* Update for DiscreteIntegrator: '<S93>/Integrator' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   *  Constant: '<S6>/Constant3'
   *  Inport: '<Root>/Gain_Id'
   *  Product: '<S90>/IProd Out'
   *  Sum: '<S6>/Add2'
   */
  rtDW.Integrator_DSTATE += ((real_T)((real32_T)(0.0F - rtb_Switch_n_idx_0)) *
    rtU.Id) * 5.0E-5;

  /* End of Outputs for SubSystem: '<S6>/Park Transform' */

  /* Update for DiscreteIntegrator: '<S88>/Filter' */
  rtDW.Filter_DSTATE += 5.0E-5 * rtb_NProdOut;

  /* Update for DiscreteIntegrator: '<S45>/Integrator' incorporates:
   *  Inport: '<Root>/Gain_Iq'
   *  Product: '<S42>/IProd Out'
   */
  rtDW.Integrator_DSTATE_e += ((real_T)rtb_Add3 * rtU.Iq) * 5.0E-5;

  /* Update for DiscreteIntegrator: '<S40>/Filter' */
  rtDW.Filter_DSTATE_f += 5.0E-5 * rtb_NProdOut_n;
}

/* Model initialize function */
void Pegasus_MBD_initialize(void)
{
  /* (no initialization code required) */
  rtU.Pole_pairs = POLEPAIRS;
  rtU.Rs = 0.0107;
  rtU.Ld = 0.000146;
  rtU.Lq = 0.000387;
  rtU.Lambda_m = 0.0263;
  rtU.Iq_Torque_ratio = 4.424;
  rtU.Pq = 7;
  rtU.Iq = 8;
  rtU.Dq = 0.0010;
  rtU.Pd = 5;
  rtU.Id = 5;
  rtU.Dd = 0.0010;
  rtU.FilterCoefficient = 20;
  rtU.Thresholds.MaxBusVoltage_V = 65.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
