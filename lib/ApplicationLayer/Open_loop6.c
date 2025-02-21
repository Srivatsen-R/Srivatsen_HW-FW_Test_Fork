/*
 * File: Open_loop6.c
 *
 * Code generated for Simulink model 'Open_loop6'.
 *
 * Model version                  : 1.67
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Feb 20 18:50:11 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Open_loop6.h"
#include "rtwtypes.h"
#include <math.h>
#include "math.h"

/* Named constants for Chart: '<S1>/Chart' */
#define IN_Count                       ((uint8_T)1U)
#define IN_Count_1                     ((uint8_T)2U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
real_T rtNaN = -(real_T)NAN;
real_T rtInf = (real_T)INFINITY;
real_T rtMinusInf = -(real_T)INFINITY;
real32_T rtNaNF = -(real32_T)NAN;
real32_T rtInfF = (real32_T)INFINITY;
real32_T rtMinusInfF = -(real32_T)INFINITY;

/* Return rtNaN needed by the generated code. */
static real_T rtGetNaN(void)
{
  return rtNaN;
}

/* Return rtNaNF needed by the generated code. */
static real32_T rtGetNaNF(void)
{
  return rtNaNF;
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)isinf(value);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)isinf(value);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

/* Model step function */
void Open_loop6_step(void)
{
  real_T q;
  real_T rtb_Merge_n_idx_0;
  real_T rtb_Merge_n_idx_1;
  real_T total_count;
  real_T yTemp;
  boolean_T rEQ0;
  boolean_T rtb_LogicalOperator1_j;

  /* MATLABSystem: '<S1>/Modulo by Constant' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   */
  if (rtIsNaN(rtDW.DiscreteTimeIntegrator_DSTATE) || rtIsInf
      (rtDW.DiscreteTimeIntegrator_DSTATE)) {
    yTemp = (rtNaN);
  } else if (rtDW.DiscreteTimeIntegrator_DSTATE == 0.0) {
    yTemp = 0.0;
  } else {
    yTemp = fmod(rtDW.DiscreteTimeIntegrator_DSTATE, 18.849555921538759);
    rEQ0 = (yTemp == 0.0);
    if (!rEQ0) {
      q = fabs(rtDW.DiscreteTimeIntegrator_DSTATE / 18.849555921538759);
      rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      yTemp = 0.0;
    } else if (yTemp < 0.0) {
      yTemp += 18.849555921538759;
    }
  }

  /* Delay: '<S6>/Delay One Step' */
  q = rtDW.DelayOneStep_DSTATE;

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Logic: '<S6>/Logical Operator1'
   *  Logic: '<S6>/Logical Operator2'
   *  MATLABSystem: '<S1>/Modulo by Constant'
   *  RelationalOperator: '<S6>/Relational Operator2'
   *  RelationalOperator: '<S6>/Relational Operator3'
   *  RelationalOperator: '<S6>/Relational Operator4'
   *  RelationalOperator: '<S6>/Relational Operator5'
   */
  rEQ0 = (((!(yTemp >= q)) || (!(q < 0.0))) && ((!(yTemp <= q)) || (!(q > 0.0))));

  /* Outputs for Enabled SubSystem: '<S19>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  if (rtConstB.MultiportSwitch[0] > 0.0) {
    /* RelationalOperator: '<S21>/Relational Operator1' incorporates:
     *  UnitDelay: '<S19>/Unit Delay'
     */
    rtDW.RelationalOperator1 = ((int32_T)rEQ0 > (int32_T)rtDW.UnitDelay_DSTATE);
  }

  /* End of Outputs for SubSystem: '<S19>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S19>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  if (rtConstB.MultiportSwitch[1] > 0.0) {
    /* RelationalOperator: '<S20>/Relational Operator1' incorporates:
     *  UnitDelay: '<S19>/Unit Delay'
     */
    rtDW.RelationalOperator1_h = ((int32_T)rtDW.UnitDelay_DSTATE > (int32_T)rEQ0);
  }

  /* End of Outputs for SubSystem: '<S19>/NEGATIVE Edge' */

  /* Logic: '<S19>/Logical Operator1' */
  rtb_LogicalOperator1_j = (rtDW.RelationalOperator1 ||
    rtDW.RelationalOperator1_h);

  /* Chart: '<S1>/Chart' */
  if (rtDW.is_active_c12_Open_loop6 == 0) {
    rtDW.is_active_c12_Open_loop6 = 1U;
    rtDW.is_c12_Open_loop6 = IN_Count;

    /* Outport: '<Root>/ZCD_count' */
    rtY.ZCD_count = 0.0;
  } else if (rtDW.is_c12_Open_loop6 == IN_Count) {
    if (rtb_LogicalOperator1_j) {
      rtDW.is_c12_Open_loop6 = IN_Count_1;

      /* Outport: '<Root>/ZCD_count' */
      rtY.ZCD_count++;
    }

    /* case IN_Count_1: */
  } else if (rtb_LogicalOperator1_j) {
    rtDW.is_c12_Open_loop6 = IN_Count_1;

    /* Outport: '<Root>/ZCD_count' */
    rtY.ZCD_count++;
  }

  /* End of Chart: '<S1>/Chart' */

  /* If: '<S4>/If' incorporates:
   *  Inport: '<Root>/Fwd//Rev'
   *  Outport: '<Root>/ZCD_count'
   */
  rtb_LogicalOperator1_j = ((rtY.ZCD_count > 150.0) && (rtY.ZCD_count <= 250.0));
  if (((rtY.ZCD_count <= 100.0) && (rtU.FwdRev == 0.0)) ||
      (rtb_LogicalOperator1_j && (rtU.FwdRev == 1.0))) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* SignalConversion generated from: '<S8>/Out1' incorporates:
     *  Gain: '<S8>/Gain'
     *  MATLABSystem: '<S1>/Modulo by Constant'
     */
    rtb_Merge_n_idx_0 = yTemp;
    rtb_Merge_n_idx_1 = 0.33333333333333331 * yTemp;

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem' */
  } else if (((rtY.ZCD_count <= 100.0) && (rtU.FwdRev == 1.0)) ||
             (rtb_LogicalOperator1_j && (rtU.FwdRev == 0.0))) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* SignalConversion generated from: '<S10>/Out1' incorporates:
     *  Constant: '<S10>/Constant'
     *  Gain: '<S10>/Gain'
     *  Gain: '<S10>/Gain1'
     *  MATLABSystem: '<S1>/Modulo by Constant'
     *  Sum: '<S10>/Add'
     */
    rtb_Merge_n_idx_0 = -yTemp + 18.849555921538759;
    rtb_Merge_n_idx_1 = (-yTemp + 18.849555921538759) * 0.33333333333333331;

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem2' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* SignalConversion generated from: '<S9>/Out1' incorporates:
     *  Constant: '<S9>/Constant'
     */
    rtb_Merge_n_idx_0 = 0.0;
    rtb_Merge_n_idx_1 = 0.0;

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem1' */
  }

  /* End of If: '<S4>/If' */

  /* Sum: '<S5>/Subtract1' incorporates:
   *  Gain: '<S13>/Gain'
   *  Gain: '<S14>/Gain'
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/Encoder_count'
   */
  q = 0.0015339807878856412 * rtU.Encoder_count * 57.295779513082323 -
    57.295779513082323 * rtb_Merge_n_idx_1;

  /* If: '<S15>/If' */
  if (!(q >= 0.0)) {
    /* Outputs for IfAction SubSystem: '<S15>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Bias: '<S17>/Bias' */
    q += 360.0;

    /* End of Outputs for SubSystem: '<S15>/If Action Subsystem1' */
  }

  /* End of If: '<S15>/If' */

  /* MATLAB Function: '<S5>/MATLAB Function4' incorporates:
   *  Inport: '<Root>/Fwd//Rev'
   *  Outport: '<Root>/ZCD_count'
   */
  if (rtU.FwdRev == 0.0) {
    if ((rtY.ZCD_count >= 1.0) && (rtY.ZCD_count <= 100.0)) {
      rtDW.sum_samples += q;
      rtDW.count_samples++;
    }

    if ((rtY.ZCD_count >= 151.0) && (rtY.ZCD_count <= 250.0)) {
      rtDW.sum_offset = (rtDW.sum_offset - q) + 360.0;
      rtDW.count_offset_samples++;
    }
  } else if (rtU.FwdRev == 1.0) {
    if ((rtY.ZCD_count >= 1.0) && (rtY.ZCD_count <= 100.0)) {
      rtDW.sum_offset = (rtDW.sum_offset - q) + 360.0;
      rtDW.count_offset_samples++;
    }

    if ((rtY.ZCD_count >= 151.0) && (rtY.ZCD_count <= 250.0)) {
      rtDW.sum_samples += q;
      rtDW.count_samples++;
    }
  }

  q = 0.0;
  total_count = rtDW.count_samples + rtDW.count_offset_samples;
  if (total_count > 0.0) {
    q = (rtDW.sum_samples + rtDW.sum_offset) / total_count;
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function4' */

  /* Outport: '<Root>/Offset_deg' */
  rtY.Offset_deg = q;

  /* Outport: '<Root>/Offset_rad' incorporates:
   *  Gain: '<S11>/Gain1'
   */
  rtY.Offset_rad = 0.017453292519943295 * q;

  /* Product: '<S3>/Product3' incorporates:
   *  Gain: '<S3>/rpm_to_freq'
   *  Inport: '<Root>/Ref_Speed_rpm'
   *  Inport: '<Root>/V//F ratio'
   */
  q = 0.05 * rtU.Ref_Speed_rpm * rtU.VFratio;

  /* Switch: '<S7>/Switch2' incorporates:
   *  Inport: '<Root>/V_low_limit'
   *  Inport: '<Root>/V_up_limit'
   *  RelationalOperator: '<S7>/LowerRelop1'
   *  RelationalOperator: '<S7>/UpperRelop'
   *  Switch: '<S7>/Switch'
   */
  if (q > rtU.V_up_limit) {
    total_count = rtU.V_up_limit;
  } else if (q < rtU.V_low_limit) {
    /* Switch: '<S7>/Switch' incorporates:
     *  Inport: '<Root>/V_low_limit'
     */
    total_count = rtU.V_low_limit;
  } else {
    total_count = q;
  }

  /* End of Switch: '<S7>/Switch2' */

  /* Outport: '<Root>/V_abc' incorporates:
   *  Constant: '<S3>/-2pi//3'
   *  Constant: '<S3>/2pi//3'
   *  Product: '<S3>/Va'
   *  Product: '<S3>/Vb'
   *  Product: '<S3>/Vc'
   *  Sum: '<S3>/Add'
   *  Sum: '<S3>/Add1'
   *  Trigonometry: '<S3>/sin_wt'
   *  Trigonometry: '<S3>/sin_wt+2pi//3'
   *  Trigonometry: '<S3>/sin_wt-2pi//3'
   */
  rtY.V_abc[0] = total_count * sin(rtb_Merge_n_idx_0);
  rtY.V_abc[1] = sin(rtb_Merge_n_idx_0 - 2.0943951023931953) * total_count;
  rtY.V_abc[2] = sin(rtb_Merge_n_idx_0 + 2.0943951023931953) * total_count;

  /* Outport: '<Root>/Vdc_sat' */
  rtY.Vdc_sat = total_count;

  /* Outport: '<Root>/Vdc' */
  rtY.Vdc = q;

  /* Outport: '<Root>/ref_angle_6*pi' */
  rtY.ref_angle_6pi = rtb_Merge_n_idx_0;

  /* Outport: '<Root>/ref_angle_2*pi' */
  rtY.ref_angle_2pi = rtb_Merge_n_idx_1;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S1>/rpm_to_rad//s'
   *  Inport: '<Root>/Ref_Speed_rpm'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.10471975511965977 * rtU.Ref_Speed_rpm *
    0.0001;

  /* Update for Delay: '<S6>/Delay One Step' incorporates:
   *  MATLABSystem: '<S1>/Modulo by Constant'
   */
  rtDW.DelayOneStep_DSTATE = yTemp;

  /* Update for UnitDelay: '<S19>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rEQ0;


}

/* Model initialize function */
void Open_loop6_initialize(void)
{
  /* (no initialization code required) (???) */
  
  rtU.Ref_Speed_rpm = 500.0;
  rtU.V_low_limit = 0.0;
  rtU.V_up_limit = 66.0;
  rtU.VFratio = 0.1992;
  rtU.FwdRev = 1.0;
  //PWM_Enable = 
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);

}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
