/*
 * Medhya.c
 *
 * Code generation for model "Medhya".
 *
 * Model version              : 18.83
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Thu Feb 13 12:24:30 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Medhya.h"
#include "Medhya_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <string.h>
#include <float.h>

/* Block signals (default storage) */
B_Medhya_T Medhya_B;

/* Block states (default storage) */
DW_Medhya_T Medhya_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Medhya_T Medhya_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Medhya_T Medhya_Y;

/* Real-time model */
static RT_MODEL_Medhya_T Medhya_M_;
RT_MODEL_Medhya_T *const Medhya_M = &Medhya_M_;
real_T look2_binlcpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0UL]]) {
    /* Binary Search */
    bpIdx = maxIndex[0UL] >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex[0UL];
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0UL] - 1UL;
    frac = 1.0;
  }

  fractions[0UL] = frac;
  bpIndices[0UL] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0UL]) {
    iLeft = 0UL;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1UL]]) {
    /* Binary Search */
    bpIdx = maxIndex[1UL] >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex[1UL];
    while (iRght - iLeft > 1UL) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1UL] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1UL] - 1UL;
    frac = 1.0;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0UL];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1UL] - yL_0d0) * fractions[0UL];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1UL] - yL_0d1) * fractions[0UL] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

real_T look2_binlcapw(real_T u0, real_T u1, const real_T bp0[], const real_T
                      bp1[], const real_T table[], const uint32_T maxIndex[],
                      uint32_T stride)
{
  real_T fractions[2];
  real_T frac;
  real_T y;
  real_T yL_0d0;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0UL]]) {
    /* Binary Search */
    bpIdx = maxIndex[0UL] >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex[0UL];
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0UL];
    frac = 0.0;
  }

  fractions[0UL] = frac;
  bpIndices[0UL] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0UL]) {
    iLeft = 0UL;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1UL]]) {
    /* Binary Search */
    bpIdx = maxIndex[1UL] >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex[1UL];
    while (iRght - iLeft > 1UL) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1UL] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1UL];
    frac = 0.0;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0UL];
  if (bpIndices[0UL] == maxIndex[0UL]) {
    y = table[bpIdx];
  } else {
    yL_0d0 = table[bpIdx];
    y = (table[bpIdx + 1UL] - yL_0d0) * fractions[0UL] + yL_0d0;
  }

  if (iLeft == maxIndex[1UL]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0UL] == maxIndex[0UL]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      yL_0d0 += (table[bpIdx + 1UL] - yL_0d0) * fractions[0UL];
    }

    y += (yL_0d0 - y) * frac;
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void Medhya_step(void)
{
  real_T rtb_Gain1_a[3];
  real_T Tas;
  real_T Tbs;
  real_T Tmax;
  real_T Tmin;
  real_T Toffset;
  real_T Tswh;
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_Gain1;
  real_T rtb_Gain1_j_idx_0;
  real_T rtb_Gain1_j_idx_1;
  real_T rtb_Gain4;
  real_T rtb_MathFunction;
  real_T rtb_Saturation;
  real_T rtb_SignChange;
  real_T rtb_Sum;
  real_T rtb_Switch1_a;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  real_T rtb_Switch_p;
  real_T rtb_UkYk1;
  real_T rtb_UnaryMinus;
  real_T rtb_UnaryMinus_p;
  real_T rtb_avoiddivisionby0;
  real_T rtb_c;
  real_T rtb_uDLookupTableLd;
  real_T rtb_uDLookupTablePsim;
  int16_T idx;
  int16_T k;
  boolean_T exitg1;
  boolean_T rtb_LogicalOperator3_idx_0;
  boolean_T rtb_LogicalOperator3_idx_1;
  boolean_T rtb_LogicalOperator_0;
  boolean_T rtb_LogicalOperator_idx_0;
  boolean_T rtb_LogicalOperator_idx_1;
  boolean_T rtb_RelationalOperator1;

  /* RelationalOperator: '<S17>/Relational Operator1' incorporates:
   *  Constant: '<S17>/Constant3'
   */
  rtb_RelationalOperator1 = (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >
    Medhya_P.Constant3_Value);

  /* InitialCondition: '<S17>/Initial' */
  if (Medhya_DW.Initial_FirstOutputTime) {
    Medhya_DW.Initial_FirstOutputTime = false;

    /* InitialCondition: '<S17>/Initial' */
    Medhya_B.Initial = Medhya_P.Initial_Value;
  } else {
    /* InitialCondition: '<S17>/Initial' incorporates:
     *  Constant: '<S17>/Constant3'
     *  Sum: '<S17>/Add3'
     */
    Medhya_B.Initial = Medhya_DW.DiscreteTimeIntegrator1_DSTATE -
      Medhya_P.Constant3_Value;
  }

  /* End of InitialCondition: '<S17>/Initial' */

  /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' */
  if (rtb_RelationalOperator1 && (Medhya_DW.DiscreteTimeIntegrator1_PrevRes <= 0))
  {
    Medhya_DW.DiscreteTimeIntegrator1_DSTATE = Medhya_B.Initial;
  }

  /* Product: '<S26>/delta rise limit' incorporates:
   *  Inport: '<Root>/VdVqManualControlRampRate'
   *  SampleTimeMath: '<S26>/sample time'
   *
   * About '<S26>/sample time':
   *  y = K where K = ( w * Ts )
   *   */
  rtb_DiscreteTimeIntegrator = Medhya_U.VdVqManualControlRampRate *
    Medhya_P.sampletime_WtEt;

  /* Delay: '<S26>/Delay' incorporates:
   *  Inport: '<Root>/VdRefManual'
   */
  if (Medhya_DW.icLoad) {
    Medhya_DW.Delay_DSTATE = Medhya_U.VdRefManual;
  }

  /* Sum: '<S26>/Difference Inputs1' incorporates:
   *  Delay: '<S26>/Delay'
   *  Inport: '<Root>/VdRefManual'
   */
  rtb_UkYk1 = Medhya_U.VdRefManual - Medhya_DW.Delay_DSTATE;

  /* Switch: '<S30>/Switch2' incorporates:
   *  RelationalOperator: '<S30>/LowerRelop1'
   */
  if (!(rtb_UkYk1 > rtb_DiscreteTimeIntegrator)) {
    /* Product: '<S26>/delta fall limit' incorporates:
     *  Gain: '<S22>/Gain3'
     *  Inport: '<Root>/VdVqManualControlRampRate'
     *  SampleTimeMath: '<S26>/sample time'
     *
     * About '<S26>/sample time':
     *  y = K where K = ( w * Ts )
     *   */
    rtb_DiscreteTimeIntegrator = Medhya_P.Gain3_Gain_l *
      Medhya_U.VdVqManualControlRampRate * Medhya_P.sampletime_WtEt;

    /* Switch: '<S30>/Switch' incorporates:
     *  RelationalOperator: '<S30>/UpperRelop'
     */
    if (!(rtb_UkYk1 < rtb_DiscreteTimeIntegrator)) {
      rtb_DiscreteTimeIntegrator = rtb_UkYk1;
    }

    /* End of Switch: '<S30>/Switch' */
  }

  /* End of Switch: '<S30>/Switch2' */

  /* Sum: '<S26>/Difference Inputs2' incorporates:
   *  Delay: '<S26>/Delay'
   */
  rtb_UkYk1 = rtb_DiscreteTimeIntegrator + Medhya_DW.Delay_DSTATE;

  /* Gain: '<S14>/Gain1' incorporates:
   *  Constant: '<S2>/Vdc1'
   */
  rtb_Gain1 = Medhya_P.Gain1_Gain_d * Medhya_P.VDC;

  /* Product: '<S7>/delta rise limit' incorporates:
   *  Constant: '<S2>/Constant11'
   *  SampleTimeMath: '<S7>/sample time'
   *
   * About '<S7>/sample time':
   *  y = K where K = ( w * Ts )
   *   */
  rtb_DiscreteTimeIntegrator = Medhya_P.Constant11_Value *
    Medhya_P.sampletime_WtEt_e;

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Inport: '<Root>/IdRef'
   */
  if (Medhya_U.IdRef > Medhya_P.IdCurRefSatLimitHigh) {
    rtb_Saturation = Medhya_P.IdCurRefSatLimitHigh;
  } else if (Medhya_U.IdRef < Medhya_P.IdCurRefSatLimitLow) {
    rtb_Saturation = Medhya_P.IdCurRefSatLimitLow;
  } else {
    rtb_Saturation = Medhya_U.IdRef;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Delay: '<S7>/Delay' */
  if (Medhya_DW.icLoad_i) {
    Medhya_DW.Delay_DSTATE_k = rtb_Saturation;
  }

  /* Sum: '<S7>/Difference Inputs1' incorporates:
   *  Delay: '<S7>/Delay'
   */
  rtb_Saturation -= Medhya_DW.Delay_DSTATE_k;

  /* Gain: '<S2>/Gain4' incorporates:
   *  Constant: '<S2>/Constant11'
   */
  rtb_Gain4 = Medhya_P.Gain4_Gain * Medhya_P.Constant11_Value;

  /* Switch: '<S10>/Switch2' incorporates:
   *  RelationalOperator: '<S10>/LowerRelop1'
   */
  if (!(rtb_Saturation > rtb_DiscreteTimeIntegrator)) {
    /* Product: '<S7>/delta fall limit' incorporates:
     *  SampleTimeMath: '<S7>/sample time'
     *
     * About '<S7>/sample time':
     *  y = K where K = ( w * Ts )
     *   */
    rtb_DiscreteTimeIntegrator = Medhya_P.sampletime_WtEt_e * rtb_Gain4;

    /* Switch: '<S10>/Switch' incorporates:
     *  RelationalOperator: '<S10>/UpperRelop'
     */
    if (!(rtb_Saturation < rtb_DiscreteTimeIntegrator)) {
      rtb_DiscreteTimeIntegrator = rtb_Saturation;
    }

    /* End of Switch: '<S10>/Switch' */
  }

  /* End of Switch: '<S10>/Switch2' */

  /* Sum: '<S7>/Difference Inputs2' incorporates:
   *  Delay: '<S7>/Delay'
   */
  rtb_DiscreteTimeIntegrator += Medhya_DW.Delay_DSTATE_k;

  /* Math: '<S34>/Mod' incorporates:
   *  Constant: '<S34>/Constant2'
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   *  Inport: '<Root>/ManualPositionOffset'
   *  Sum: '<S34>/Add'
   */
  rtb_Saturation = rt_modd_snf(Medhya_DW.DiscreteTimeIntegrator_DSTATE +
    Medhya_U.ManualPositionOffset, Medhya_P.Constant2_Value);

  /* Math: '<S32>/Math Function' incorporates:
   *  Constant: '<S32>/2*pi'
   *  Delay: '<S14>/Delay1'
   *  Gain: '<S32>/pole pairs '
   */
  rtb_MathFunction = rt_modd_snf(Medhya_P.polepairs * Medhya_DW.Delay1_DSTATE[1],
    Medhya_P.upi_Value);

  /* Switch: '<S14>/Switch' incorporates:
   *  Inport: '<Root>/EnableManualPosition'
   */
  if (Medhya_U.EnableManualPosition > Medhya_P.Switch_Threshold) {
    rtb_Switch_p = rtb_Saturation;
  } else {
    rtb_Switch_p = rtb_MathFunction;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Fcn: '<S33>/d' incorporates:
   *  Fcn: '<S15>/a'
   */
  Tswh = sin(rtb_Switch_p + 1.5707963267948966);

  /* Fcn: '<S33>/q' incorporates:
   *  Fcn: '<S15>/a'
   */
  Tas = cos(rtb_Switch_p + 1.5707963267948966);

  /* Fcn: '<S33>/d' incorporates:
   *  Fcn: '<S15>/b'
   */
  Tbs = sin((rtb_Switch_p + 1.5707963267948966) - 2.0943951023931953);

  /* Fcn: '<S33>/q' incorporates:
   *  Fcn: '<S15>/b'
   */
  rtb_avoiddivisionby0 = cos((rtb_Switch_p + 1.5707963267948966) -
    2.0943951023931953);

  /* Fcn: '<S33>/d' incorporates:
   *  Fcn: '<S15>/c'
   */
  Tmax = sin((rtb_Switch_p + 1.5707963267948966) + 2.0943951023931953);

  /* Fcn: '<S33>/q' incorporates:
   *  Fcn: '<S15>/c'
   */
  Tmin = cos((rtb_Switch_p + 1.5707963267948966) + 2.0943951023931953);

  /* Gain: '<S33>/Gain1' incorporates:
   *  Delay: '<S14>/Delay'
   *  Fcn: '<S33>/d'
   *  Fcn: '<S33>/q'
   */
  rtb_Gain1_j_idx_0 = ((Tswh * Medhya_DW.Delay_DSTATE_b[0] + Tbs *
                        Medhya_DW.Delay_DSTATE_b[1]) + Tmax *
                       Medhya_DW.Delay_DSTATE_b[2]) * Medhya_P.Gain1_Gain_n;
  rtb_Gain1_j_idx_1 = ((Tas * Medhya_DW.Delay_DSTATE_b[0] + rtb_avoiddivisionby0
                        * Medhya_DW.Delay_DSTATE_b[1]) + Tmin *
                       Medhya_DW.Delay_DSTATE_b[2]) * Medhya_P.Gain1_Gain_n;

  /* Sum: '<S23>/Sum' */
  rtb_Sum = rtb_DiscreteTimeIntegrator - rtb_Gain1_j_idx_0;

  /* Outputs for Atomic SubSystem: '<S13>/PI D-axis reg1' */
  /* Outputs for Atomic SubSystem: '<S13>/PI D-axis reg' */
  /* Logic: '<S20>/NOT' incorporates:
   *  Inport: '<Root>/PwmEnable'
   *  Logic: '<S21>/NOT'
   */
  rtb_LogicalOperator_0 = !(Medhya_U.PwmEnable != 0.0);

  /* End of Outputs for SubSystem: '<S13>/PI D-axis reg1' */

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/Constant'
   *  Logic: '<S20>/NOT'
   */
  if (rtb_LogicalOperator_0) {
    rtb_Switch_p = Medhya_P.Constant_Value;
  } else {
    /* Sum: '<S20>/Subtract2' incorporates:
     *  Inport: '<Root>/Inport1'
     *  Inport: '<Root>/Inport2'
     *  Product: '<S20>/Product'
     *  Product: '<S20>/Product1'
     *  Sum: '<S20>/Subtract3'
     *  UnaryMinus: '<S20>/Unary Minus1'
     *  UnitDelay: '<S20>/Unit Delay'
     *  UnitDelay: '<S20>/Unit Delay1'
     *  UnitDelay: '<S20>/Unit Delay2'
     */
    rtb_Switch_p = (((Medhya_U.KiD + Medhya_U.KpD) * rtb_Sum +
                     Medhya_DW.UnitDelay1_DSTATE_m * -Medhya_U.KpD) +
                    Medhya_DW.UnitDelay_DSTATE_b) +
      Medhya_DW.UnitDelay2_DSTATE_m;

    /* Switch: '<S24>/Switch2' incorporates:
     *  Constant: '<S20>/Constant1'
     *  RelationalOperator: '<S24>/LowerRelop1'
     */
    if (rtb_Switch_p > Medhya_P.VDC / 1.7320508075688772) {
      rtb_Switch_p = Medhya_P.VDC / 1.7320508075688772;
    } else {
      /* UnaryMinus: '<S20>/Unary Minus' */
      rtb_UnaryMinus_p = -(Medhya_P.VDC / 1.7320508075688772);

      /* Switch: '<S24>/Switch' incorporates:
       *  RelationalOperator: '<S24>/UpperRelop'
       */
      if (rtb_Switch_p < rtb_UnaryMinus_p) {
        rtb_Switch_p = rtb_UnaryMinus_p;
      }

      /* End of Switch: '<S24>/Switch' */
    }

    /* End of Switch: '<S24>/Switch2' */
  }

  /* End of Switch: '<S20>/Switch' */

  /* Update for UnitDelay: '<S20>/Unit Delay1' */
  Medhya_DW.UnitDelay1_DSTATE_m = rtb_Sum;

  /* Update for UnitDelay: '<S20>/Unit Delay' */
  Medhya_DW.UnitDelay_DSTATE_b = rtb_Switch_p;

  /* Update for UnitDelay: '<S20>/Unit Delay2' incorporates:
   *  Constant: '<S13>/Constant'
   *  Gain: '<S20>/Gain'
   *  Product: '<S20>/Product2'
   */
  Medhya_DW.UnitDelay2_DSTATE_m = Medhya_P.Gain_Gain * rtb_Sum *
    Medhya_P.Constant_Value_o;

  /* End of Outputs for SubSystem: '<S13>/PI D-axis reg' */

  /* Product: '<S8>/delta rise limit' incorporates:
   *  Constant: '<S2>/Constant11'
   *  SampleTimeMath: '<S8>/sample time'
   *
   * About '<S8>/sample time':
   *  y = K where K = ( w * Ts )
   *   */
  rtb_c = Medhya_P.Constant11_Value * Medhya_P.sampletime_WtEt_c;

  /* Saturate: '<S2>/Saturation1' incorporates:
   *  Inport: '<Root>/IqRef'
   */
  if (Medhya_U.IqRef > Medhya_P.IqCurRefSatLimitHigh) {
    rtb_Sum = Medhya_P.IqCurRefSatLimitHigh;
  } else if (Medhya_U.IqRef < Medhya_P.IqCurRefSatLimitLow) {
    rtb_Sum = Medhya_P.IqCurRefSatLimitLow;
  } else {
    rtb_Sum = Medhya_U.IqRef;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Delay: '<S8>/Delay' */
  if (Medhya_DW.icLoad_iz) {
    Medhya_DW.Delay_DSTATE_h = rtb_Sum;
  }

  /* Sum: '<S8>/Difference Inputs1' incorporates:
   *  Delay: '<S8>/Delay'
   */
  rtb_Sum -= Medhya_DW.Delay_DSTATE_h;

  /* Switch: '<S11>/Switch2' incorporates:
   *  RelationalOperator: '<S11>/LowerRelop1'
   */
  if (!(rtb_Sum > rtb_c)) {
    /* Product: '<S8>/delta fall limit' incorporates:
     *  SampleTimeMath: '<S8>/sample time'
     *
     * About '<S8>/sample time':
     *  y = K where K = ( w * Ts )
     *   */
    rtb_Gain4 *= Medhya_P.sampletime_WtEt_c;

    /* Switch: '<S11>/Switch' incorporates:
     *  RelationalOperator: '<S11>/UpperRelop'
     */
    if (rtb_Sum < rtb_Gain4) {
      rtb_c = rtb_Gain4;
    } else {
      rtb_c = rtb_Sum;
    }

    /* End of Switch: '<S11>/Switch' */
  }

  /* End of Switch: '<S11>/Switch2' */

  /* Sum: '<S8>/Difference Inputs2' incorporates:
   *  Delay: '<S8>/Delay'
   */
  rtb_Gain4 = rtb_c + Medhya_DW.Delay_DSTATE_h;

  /* Abs: '<S4>/Abs' */
  rtb_c = fabs(rtb_Gain4);

  /* Lookup_n-D: '<S4>/2-D Lookup Table Lq' incorporates:
   *  Fcn: '<S15>/c'
   *  Sum: '<S7>/Difference Inputs2'
   */
  rtb_UnaryMinus_p = look2_binlcpw(rtb_DiscreteTimeIntegrator, rtb_c,
    Medhya_P.uDLookupTableLq_bp01Data, Medhya_P.uDLookupTableLq_bp02Data,
    Medhya_P.uDLookupTableLq_tableData, Medhya_P.uDLookupTableLq_maxIndex, 21UL);

  /* Lookup_n-D: '<S4>/2-D Lookup Table Ld' incorporates:
   *  Fcn: '<S15>/c'
   *  Sum: '<S7>/Difference Inputs2'
   */
  rtb_uDLookupTableLd = look2_binlcapw(rtb_DiscreteTimeIntegrator, rtb_c,
    Medhya_P.uDLookupTableLd_bp01Data, Medhya_P.uDLookupTableLd_bp02Data,
    Medhya_P.uDLookupTableLd_tableData, Medhya_P.uDLookupTableLd_maxIndex, 21UL);

  /* Lookup_n-D: '<S4>/2-D Lookup Table Psim' incorporates:
   *  Fcn: '<S15>/c'
   *  Sum: '<S7>/Difference Inputs2'
   */
  rtb_uDLookupTablePsim = look2_binlcpw(rtb_DiscreteTimeIntegrator, rtb_c,
    Medhya_P.uDLookupTablePsim_bp01Data, Medhya_P.uDLookupTablePsim_bp02Data,
    Medhya_P.uDLookupTablePsim_tableData, Medhya_P.uDLookupTablePsim_maxIndex,
    21UL);

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Zero vector'
   *  Constant: '<S4>/Constant1'
   *  Product: '<S19>/Product1'
   *  Product: '<S19>/Product2'
   *  Product: '<S19>/Product3'
   *  Product: '<S19>/Product4'
   *  Product: '<S19>/Product5'
   *  Sum: '<S19>/Sum1'
   *  Sum: '<S19>/Sum2'
   *  Sum: '<S19>/Sum3'
   */
  if (Medhya_P.Constant_Value_n > Medhya_P.Switch_Threshold_b) {
    /* Gain: '<S32>/pole pairs' incorporates:
     *  Delay: '<S14>/Delay1'
     */
    rtb_Sum = Medhya_P.polepairs * Medhya_DW.Delay1_DSTATE[0];
    rtb_Switch_idx_0 = Medhya_P.Rs * rtb_DiscreteTimeIntegrator - rtb_Gain4 *
      rtb_UnaryMinus_p * rtb_Sum;
    rtb_Switch_idx_1 = (rtb_DiscreteTimeIntegrator * rtb_uDLookupTableLd *
                        rtb_Sum + rtb_uDLookupTablePsim * rtb_Sum) + rtb_Gain4 *
      Medhya_P.Rs;
  } else {
    rtb_Switch_idx_0 = Medhya_P.Zerovector_Value[0];
    rtb_Switch_idx_1 = Medhya_P.Zerovector_Value[1];
  }

  /* End of Switch: '<S19>/Switch' */

  /* Gain: '<S22>/Sign Change' */
  rtb_SignChange = Medhya_P.SignChange_Gain * rtb_Gain1;

  /* Switch: '<S22>/Switch' incorporates:
   *  Inport: '<Root>/EnableVdVqControl'
   */
  if (Medhya_U.EnableVdVqControl != 0.0) {
    rtb_c = rtb_UkYk1;
  } else {
    /* Sum: '<S13>/Add1' */
    rtb_Sum = rtb_Switch_p + rtb_Switch_idx_0;

    /* Switch: '<S28>/Switch2' incorporates:
     *  RelationalOperator: '<S28>/LowerRelop1'
     *  RelationalOperator: '<S28>/UpperRelop'
     *  Switch: '<S28>/Switch'
     */
    if (rtb_Sum > rtb_Gain1) {
      rtb_c = rtb_Gain1;
    } else if (rtb_Sum < rtb_SignChange) {
      /* Switch: '<S28>/Switch' */
      rtb_c = rtb_SignChange;
    } else {
      rtb_c = rtb_Sum;
    }

    /* End of Switch: '<S28>/Switch2' */
  }

  /* End of Switch: '<S22>/Switch' */

  /* Product: '<S27>/delta rise limit' incorporates:
   *  Inport: '<Root>/VdVqManualControlRampRate'
   *  SampleTimeMath: '<S27>/sample time'
   *
   * About '<S27>/sample time':
   *  y = K where K = ( w * Ts )
   *   */
  rtb_Switch1_a = Medhya_U.VdVqManualControlRampRate *
    Medhya_P.sampletime_WtEt_b;

  /* Delay: '<S27>/Delay' incorporates:
   *  Inport: '<Root>/VqRefManual'
   */
  if (Medhya_DW.icLoad_f) {
    Medhya_DW.Delay_DSTATE_n = Medhya_U.VqRefManual;
  }

  /* Sum: '<S27>/Difference Inputs1' incorporates:
   *  Delay: '<S27>/Delay'
   *  Inport: '<Root>/VqRefManual'
   */
  rtb_Sum = Medhya_U.VqRefManual - Medhya_DW.Delay_DSTATE_n;

  /* Switch: '<S31>/Switch2' incorporates:
   *  RelationalOperator: '<S31>/LowerRelop1'
   */
  if (!(rtb_Sum > rtb_Switch1_a)) {
    /* Product: '<S27>/delta fall limit' incorporates:
     *  Gain: '<S22>/Gain1'
     *  Inport: '<Root>/VdVqManualControlRampRate'
     *  SampleTimeMath: '<S27>/sample time'
     *
     * About '<S27>/sample time':
     *  y = K where K = ( w * Ts )
     *   */
    rtb_Switch_idx_0 = Medhya_P.Gain1_Gain * Medhya_U.VdVqManualControlRampRate *
      Medhya_P.sampletime_WtEt_b;

    /* Switch: '<S31>/Switch' incorporates:
     *  RelationalOperator: '<S31>/UpperRelop'
     */
    if (rtb_Sum < rtb_Switch_idx_0) {
      rtb_Switch1_a = rtb_Switch_idx_0;
    } else {
      rtb_Switch1_a = rtb_Sum;
    }

    /* End of Switch: '<S31>/Switch' */
  }

  /* End of Switch: '<S31>/Switch2' */

  /* Sum: '<S27>/Difference Inputs2' incorporates:
   *  Delay: '<S27>/Delay'
   */
  rtb_Sum = rtb_Switch1_a + Medhya_DW.Delay_DSTATE_n;

  /* Sum: '<S23>/Sum1' */
  rtb_Switch1_a = rtb_Gain4 - rtb_Gain1_j_idx_1;

  /* Outputs for Atomic SubSystem: '<S13>/PI D-axis reg1' */
  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Constant'
   */
  if (rtb_LogicalOperator_0) {
    rtb_Switch_idx_0 = Medhya_P.Constant_Value_c;
  } else {
    /* Sum: '<S21>/Subtract2' incorporates:
     *  Inport: '<Root>/Inport3'
     *  Inport: '<Root>/Inport4'
     *  Product: '<S21>/Product'
     *  Product: '<S21>/Product1'
     *  Sum: '<S21>/Subtract3'
     *  UnaryMinus: '<S21>/Unary Minus1'
     *  UnitDelay: '<S21>/Unit Delay'
     *  UnitDelay: '<S21>/Unit Delay1'
     *  UnitDelay: '<S21>/Unit Delay2'
     */
    rtb_Switch_idx_0 = (((Medhya_U.KiQ + Medhya_U.KpQ) * rtb_Switch1_a +
                         Medhya_DW.UnitDelay1_DSTATE * -Medhya_U.KpQ) +
                        Medhya_DW.UnitDelay_DSTATE) +
      Medhya_DW.UnitDelay2_DSTATE;

    /* Switch: '<S25>/Switch2' incorporates:
     *  Constant: '<S21>/Constant1'
     *  RelationalOperator: '<S25>/LowerRelop1'
     */
    if (rtb_Switch_idx_0 > Medhya_P.VDC / 1.7320508075688772) {
      rtb_Switch_idx_0 = Medhya_P.VDC / 1.7320508075688772;
    } else {
      /* UnaryMinus: '<S21>/Unary Minus' */
      rtb_UnaryMinus = -(Medhya_P.VDC / 1.7320508075688772);

      /* Switch: '<S25>/Switch' incorporates:
       *  RelationalOperator: '<S25>/UpperRelop'
       */
      if (rtb_Switch_idx_0 < rtb_UnaryMinus) {
        rtb_Switch_idx_0 = rtb_UnaryMinus;
      }

      /* End of Switch: '<S25>/Switch' */
    }

    /* End of Switch: '<S25>/Switch2' */
  }

  /* End of Switch: '<S21>/Switch' */

  /* Update for UnitDelay: '<S21>/Unit Delay1' */
  Medhya_DW.UnitDelay1_DSTATE = rtb_Switch1_a;

  /* Update for UnitDelay: '<S21>/Unit Delay' */
  Medhya_DW.UnitDelay_DSTATE = rtb_Switch_idx_0;

  /* Update for UnitDelay: '<S21>/Unit Delay2' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Gain: '<S21>/Gain'
   *  Product: '<S21>/Product2'
   */
  Medhya_DW.UnitDelay2_DSTATE = Medhya_P.Gain_Gain_i * rtb_Switch1_a *
    Medhya_P.Constant1_Value;

  /* End of Outputs for SubSystem: '<S13>/PI D-axis reg1' */

  /* Switch: '<S22>/Switch1' incorporates:
   *  Inport: '<Root>/EnableVdVqControl'
   */
  if (Medhya_U.EnableVdVqControl != 0.0) {
    rtb_Switch1_a = rtb_Sum;
  } else {
    /* Sum: '<S13>/Add2' */
    rtb_Switch1_a = rtb_Switch_idx_0 + rtb_Switch_idx_1;

    /* Switch: '<S29>/Switch2' incorporates:
     *  RelationalOperator: '<S29>/LowerRelop1'
     *  RelationalOperator: '<S29>/UpperRelop'
     *  Switch: '<S29>/Switch'
     */
    if (rtb_Switch1_a > rtb_Gain1) {
      rtb_Switch1_a = rtb_Gain1;
    } else if (rtb_Switch1_a < rtb_SignChange) {
      /* Switch: '<S29>/Switch' */
      rtb_Switch1_a = rtb_SignChange;
    }

    /* End of Switch: '<S29>/Switch2' */
  }

  /* End of Switch: '<S22>/Switch1' */

  /* Gain: '<S15>/Gain1' incorporates:
   *  Constant: '<S12>/Constant'
   *  Fcn: '<S15>/a'
   *  Fcn: '<S15>/b'
   */
  rtb_Gain1_a[0] = ((Tswh * rtb_c + Tas * rtb_Switch1_a) +
                    Medhya_P.Constant_Value_ne) * Medhya_P.Gain1_Gain_o;
  rtb_Gain1_a[1] = ((Tbs * rtb_c + rtb_avoiddivisionby0 * rtb_Switch1_a) +
                    Medhya_P.Constant_Value_ne) * Medhya_P.Gain1_Gain_o;

  /* Saturate: '<S16>/avoid division by 0' incorporates:
   *  Constant: '<S2>/Vdc1'
   */
  if (Medhya_P.VDC > Medhya_P.avoiddivisionby0_UpperSat) {
    rtb_avoiddivisionby0 = Medhya_P.avoiddivisionby0_UpperSat;
  } else if (Medhya_P.VDC < Medhya_P.avoiddivisionby0_LowerSat) {
    rtb_avoiddivisionby0 = Medhya_P.avoiddivisionby0_LowerSat;
  } else {
    rtb_avoiddivisionby0 = Medhya_P.VDC;
  }

  /* End of Saturate: '<S16>/avoid division by 0' */

  /* MATLAB Function: '<S16>/Switching Time Calculation' incorporates:
   *  Constant: '<S12>/Constant'
   *  Fcn: '<S15>/c'
   *  Gain: '<S15>/Gain1'
   */
  /* MATLAB Function 'PWM Generator (Three-phase, Two-level)/Switching Time Calculation': '<S18>:1' */
  /* '<S18>:1:3' */
  rtb_Gain1 = 1.0 / Medhya_P.SwitchingTimeCalculation_fsw;
  Tswh = 0.5 * rtb_Gain1;
  Tas = rtb_Gain1_a[0] * Tswh / rtb_avoiddivisionby0;
  Tbs = rtb_Gain1_a[1] * Tswh / rtb_avoiddivisionby0;
  rtb_avoiddivisionby0 = ((Tmax * rtb_c + Tmin * rtb_Switch1_a) +
    Medhya_P.Constant_Value_ne) * Medhya_P.Gain1_Gain_o * Tswh /
    rtb_avoiddivisionby0;
  rtb_Gain1_a[0] = Tas;
  rtb_Gain1_a[1] = Tbs;
  rtb_Gain1_a[2] = rtb_avoiddivisionby0;
  rtb_LogicalOperator_0 = !rtIsNaN(Tas);
  if (rtb_LogicalOperator_0) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!rtIsNaN(rtb_Gain1_a[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    Tmax = Tas;
  } else {
    Tmax = rtb_Gain1_a[idx - 1];
    for (k = idx + 1; k < 4; k++) {
      rtb_Switch_idx_1 = rtb_Gain1_a[k - 1];
      if (Tmax < rtb_Switch_idx_1) {
        Tmax = rtb_Switch_idx_1;
      }
    }
  }

  if (rtb_LogicalOperator_0) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!rtIsNaN(rtb_Gain1_a[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    Tmin = Tas;
  } else {
    Tmin = rtb_Gain1_a[idx - 1];
    for (k = idx + 1; k < 4; k++) {
      rtb_Switch_idx_1 = rtb_Gain1_a[k - 1];
      if (Tmin > rtb_Switch_idx_1) {
        Tmin = rtb_Switch_idx_1;
      }
    }
  }

  switch ((int16_T)Medhya_P.SwitchingTimeCalculation_PWM) {
   case 1:
    Toffset = 0.5 * Tswh;
    break;

   case 2:
    Toffset = (Tswh - (Tmax - Tmin)) / 2.0 - Tmin;
    break;

   case 3:
    if (Tmin + Tmax >= 0.0) {
      Toffset = Tswh - Tmax;
    } else {
      Toffset = -Tmin;
    }
    break;

   case 4:
    if ((Tas == Tmax) && (rtb_avoiddivisionby0 == Tmin)) {
      Toffset = Tswh - Tmax;
    } else if ((Tbs == Tmax) && (rtb_avoiddivisionby0 == Tmin)) {
      Toffset = -Tmin;
    } else if ((Tbs == Tmax) && (Tas == Tmin)) {
      Toffset = Tswh - Tmax;
    } else if ((rtb_avoiddivisionby0 == Tmax) && (Tas == Tmin)) {
      Toffset = -Tmin;
    } else if ((rtb_avoiddivisionby0 == Tmax) && (Tbs == Tmin)) {
      Toffset = Tswh - Tmax;
    } else if ((Tas == Tmax) && (Tbs == Tmin)) {
      Toffset = -Tmin;
    }
    break;

   case 5:
    if ((Tas == Tmax) && (rtb_avoiddivisionby0 == Tmin)) {
      Toffset = -Tmin;
    } else if ((Tbs == Tmax) && (rtb_avoiddivisionby0 == Tmin)) {
      Toffset = Tswh - Tmax;
    } else if ((Tbs == Tmax) && (Tas == Tmin)) {
      Toffset = -Tmin;
    } else if ((rtb_avoiddivisionby0 == Tmax) && (Tas == Tmin)) {
      Toffset = Tswh - Tmax;
    } else if ((rtb_avoiddivisionby0 == Tmax) && (Tbs == Tmin)) {
      Toffset = -Tmin;
    } else if ((Tas == Tmax) && (Tbs == Tmin)) {
      Toffset = Tswh - Tmax;
    }
    break;

   case 6:
    if (Tmin + Tmax >= 0.0) {
      Toffset = -Tmin;
    } else {
      Toffset = Tswh - Tmax;
    }
    break;

   case 7:
    Toffset = Tswh - Tmax;
    break;

   case 8:
    Toffset = -Tmin;
    break;
  }

  Tas += Toffset;
  Tbs += Toffset;
  Tmin = rtb_avoiddivisionby0 + Toffset;
  Toffset = Tswh - Tas;
  rtb_avoiddivisionby0 = Tswh - Tbs;
  Tmax = Tswh - Tmin;
  Tas += Tswh;
  Tbs += Tswh;
  Tmin += Tswh;
  if (Toffset < 0.0) {
    Toffset = 0.0;
  } else if (Toffset > Tswh) {
    Toffset = Tswh;
  }

  if (rtb_avoiddivisionby0 < 0.0) {
    rtb_avoiddivisionby0 = 0.0;
  } else if (rtb_avoiddivisionby0 > Tswh) {
    rtb_avoiddivisionby0 = Tswh;
  }

  if (Tmax < 0.0) {
    Tmax = 0.0;
  } else if (Tmax > Tswh) {
    Tmax = Tswh;
  }

  if (Tas < Tswh) {
    Tas = Tswh;
  } else if (Tas > rtb_Gain1) {
    Tas = rtb_Gain1;
  }

  if (Tbs < Tswh) {
    Tbs = Tswh;
  } else if (Tbs > rtb_Gain1) {
    Tbs = rtb_Gain1;
  }

  if (Tmin < Tswh) {
    Tmin = Tswh;
  } else if (Tmin > rtb_Gain1) {
    Tmin = rtb_Gain1;
  }

  /* Switch: '<S12>/Switch1' incorporates:
   *  Inport: '<Root>/PwmEnable'
   */
  /* '<S18>:1:3' */
  if (Medhya_U.PwmEnable > Medhya_P.Switch1_Threshold) {
    /* Logic: '<S17>/Logical Operator' incorporates:
     *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator1'
     *  MATLAB Function: '<S16>/Switching Time Calculation'
     *  RelationalOperator: '<S17>/Relational Operator'
     *  RelationalOperator: '<S17>/Relational Operator3'
     */
    rtb_LogicalOperator_0 = (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >= Toffset)
      ^ (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >= Tas);
    rtb_LogicalOperator_idx_0 = rtb_LogicalOperator_0;

    /* Logic: '<S17>/Logical Operator3' */
    rtb_LogicalOperator3_idx_0 = !rtb_LogicalOperator_0;

    /* Logic: '<S17>/Logical Operator' incorporates:
     *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator1'
     *  MATLAB Function: '<S16>/Switching Time Calculation'
     *  RelationalOperator: '<S17>/Relational Operator'
     *  RelationalOperator: '<S17>/Relational Operator3'
     */
    rtb_LogicalOperator_0 = (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >=
      rtb_avoiddivisionby0) ^ (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >= Tbs);
    rtb_LogicalOperator_idx_1 = rtb_LogicalOperator_0;

    /* Logic: '<S17>/Logical Operator3' */
    rtb_LogicalOperator3_idx_1 = !rtb_LogicalOperator_0;

    /* Logic: '<S17>/Logical Operator' incorporates:
     *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator1'
     *  MATLAB Function: '<S16>/Switching Time Calculation'
     *  RelationalOperator: '<S17>/Relational Operator'
     *  RelationalOperator: '<S17>/Relational Operator3'
     */
    rtb_LogicalOperator_0 = (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >= Tmax) ^
      (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >= Tmin);

    /* Outport: '<Root>/G' incorporates:
     *  DataTypeConversion: '<S16>/Data Type Conversion'
     *  Logic: '<S17>/Logical Operator'
     *  Logic: '<S17>/Logical Operator3'
     */
    Medhya_Y.G[0] = rtb_LogicalOperator_idx_0;
    Medhya_Y.G[1] = rtb_LogicalOperator3_idx_0;
    Medhya_Y.G[2] = rtb_LogicalOperator_idx_1;
    Medhya_Y.G[3] = rtb_LogicalOperator3_idx_1;
    Medhya_Y.G[4] = rtb_LogicalOperator_0;
    Medhya_Y.G[5] = !rtb_LogicalOperator_0;
  } else {
    /* Outport: '<Root>/G' incorporates:
     *  Constant: '<S12>/Zero  vector'
     */
    for (idx = 0; idx < 6; idx++) {
      Medhya_Y.G[idx] = Medhya_P.Zerovector_Value_n[idx];
    }
  }

  /* End of Switch: '<S12>/Switch1' */

  /* Outport: '<Root>/ManualPos' */
  Medhya_Y.ManualPos = rtb_Saturation;

  /* Outport: '<Root>/ThetaSensed' */
  Medhya_Y.ThetaSensed = rtb_MathFunction;

  /* Outport: '<Root>/VdControl' */
  Medhya_Y.VdControl = rtb_Switch_p;

  /* Outport: '<Root>/VqControl' */
  Medhya_Y.VqControl = rtb_Switch_idx_0;

  /* Outport: '<Root>/IdqFeedback' */
  Medhya_Y.IdqFeedback[0] = rtb_Gain1_j_idx_0;

  /* Outport: '<Root>/ModWave' incorporates:
   *  MATLAB Function: '<S16>/Switching Time Calculation'
   */
  Medhya_Y.ModWave[0] = (Tas - Toffset) / rtb_Gain1 * 2.0 - 1.0;

  /* Outport: '<Root>/IdqFeedback' */
  Medhya_Y.IdqFeedback[1] = rtb_Gain1_j_idx_1;

  /* Outport: '<Root>/ModWave' incorporates:
   *  MATLAB Function: '<S16>/Switching Time Calculation'
   */
  Medhya_Y.ModWave[1] = (Tbs - rtb_avoiddivisionby0) / rtb_Gain1 * 2.0 - 1.0;

  /* Outport: '<Root>/IdqFeedback' incorporates:
   *  Delay: '<S14>/Delay'
   *  Fcn: '<S33>/0'
   *  Gain: '<S33>/Gain1'
   */
  Medhya_Y.IdqFeedback[2] = ((Medhya_DW.Delay_DSTATE_b[0] +
    Medhya_DW.Delay_DSTATE_b[1]) + Medhya_DW.Delay_DSTATE_b[2]) * 0.5 *
    Medhya_P.Gain1_Gain_n;

  /* Outport: '<Root>/ModWave' incorporates:
   *  MATLAB Function: '<S16>/Switching Time Calculation'
   */
  Medhya_Y.ModWave[2] = (Tmin - Tmax) / rtb_Gain1 * 2.0 - 1.0;

  /* Outport: '<Root>/IdRef_out' */
  Medhya_Y.IdRef_out = rtb_DiscreteTimeIntegrator;

  /* Outport: '<Root>/IqRef_out' */
  Medhya_Y.IqRef_out = rtb_Gain4;

  /* Outport: '<Root>/TorqueCalc' incorporates:
   *  Constant: '<S5>/Constant12'
   *  Constant: '<S5>/Constant13'
   *  Product: '<S5>/Divide'
   *  Product: '<S5>/Divide1'
   *  Product: '<S5>/Divide2'
   *  Sum: '<S5>/Add'
   *  Sum: '<S5>/Add1'
   */
  Medhya_Y.TorqueCalc = ((rtb_uDLookupTableLd - rtb_UnaryMinus_p) *
    rtb_DiscreteTimeIntegrator * rtb_Gain4 + rtb_uDLookupTablePsim * rtb_Gain4) *
    Medhya_P.polepairs * Medhya_P.Constant13_Value;

  /* Product: '<S6>/delta rise limit' incorporates:
   *  Constant: '<S2>/Constant10'
   *  SampleTimeMath: '<S6>/sample time'
   *
   * About '<S6>/sample time':
   *  y = K where K = ( w * Ts )
   *   */
  rtb_Saturation = Medhya_P.Constant10_Value * Medhya_P.sampletime_WtEt_cx;

  /* Saturate: '<S2>/Saturation2' incorporates:
   *  Inport: '<Root>/SpeedRef'
   */
  if (Medhya_U.SpeedRef > Medhya_P.SpeedRefSatLimitHigh) {
    rtb_MathFunction = Medhya_P.SpeedRefSatLimitHigh;
  } else if (Medhya_U.SpeedRef < Medhya_P.SpeedRefSatLimitLow) {
    rtb_MathFunction = Medhya_P.SpeedRefSatLimitLow;
  } else {
    rtb_MathFunction = Medhya_U.SpeedRef;
  }

  /* End of Saturate: '<S2>/Saturation2' */

  /* Delay: '<S6>/Delay' */
  if (Medhya_DW.icLoad_g) {
    Medhya_DW.Delay_DSTATE_o = rtb_MathFunction;
  }

  /* Sum: '<S6>/Difference Inputs1' incorporates:
   *  Delay: '<S6>/Delay'
   */
  rtb_MathFunction -= Medhya_DW.Delay_DSTATE_o;

  /* Switch: '<S9>/Switch2' incorporates:
   *  RelationalOperator: '<S9>/LowerRelop1'
   */
  if (!(rtb_MathFunction > rtb_Saturation)) {
    /* Product: '<S6>/delta fall limit' incorporates:
     *  Constant: '<S2>/Constant10'
     *  Gain: '<S2>/Gain3'
     *  SampleTimeMath: '<S6>/sample time'
     *
     * About '<S6>/sample time':
     *  y = K where K = ( w * Ts )
     *   */
    rtb_Saturation = Medhya_P.Gain3_Gain * Medhya_P.Constant10_Value *
      Medhya_P.sampletime_WtEt_cx;

    /* Switch: '<S9>/Switch' incorporates:
     *  RelationalOperator: '<S9>/UpperRelop'
     */
    if (!(rtb_MathFunction < rtb_Saturation)) {
      rtb_Saturation = rtb_MathFunction;
    }

    /* End of Switch: '<S9>/Switch' */
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Sum: '<S6>/Difference Inputs2' incorporates:
   *  Delay: '<S6>/Delay'
   */
  rtb_Saturation += Medhya_DW.Delay_DSTATE_o;

  /* Outport: '<Root>/SpeedRef_out' */
  Medhya_Y.SpeedRef_out = rtb_Saturation;

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S17>/Constant2'
   */
  Medhya_DW.DiscreteTimeIntegrator1_DSTATE +=
    Medhya_P.DiscreteTimeIntegrator1_gainval * Medhya_P.Constant2_Value_m;
  Medhya_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)rtb_RelationalOperator1;

  /* Update for Delay: '<S26>/Delay' */
  Medhya_DW.icLoad = false;
  Medhya_DW.Delay_DSTATE = rtb_UkYk1;

  /* Update for Delay: '<S7>/Delay' */
  Medhya_DW.icLoad_i = false;
  Medhya_DW.Delay_DSTATE_k = rtb_DiscreteTimeIntegrator;

  /* Update for Delay: '<S14>/Delay' incorporates:
   *  Inport: '<Root>/Inport6'
   */
  Medhya_DW.Delay_DSTATE_b[0] = Medhya_U.I_abc[0];
  Medhya_DW.Delay_DSTATE_b[1] = Medhya_U.I_abc[1];
  Medhya_DW.Delay_DSTATE_b[2] = Medhya_U.I_abc[2];

  /* Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S34>/Constant1'
   *  Gain: '<S34>/Gain'
   *  Inport: '<Root>/ManualSpeedRef'
   *  Product: '<S34>/Divide'
   */
  Medhya_DW.DiscreteTimeIntegrator_DSTATE += Medhya_P.polepairs / 60.0 *
    Medhya_U.ManualSpeedRef * Medhya_P.Constant1_Value_c *
    Medhya_P.DiscreteTimeIntegrator_gainval;

  /* Update for Delay: '<S14>/Delay1' incorporates:
   *  Inport: '<Root>/Inport5'
   */
  Medhya_DW.Delay1_DSTATE[0] = Medhya_U.Speed_Anlge_feedback[0];
  Medhya_DW.Delay1_DSTATE[1] = Medhya_U.Speed_Anlge_feedback[1];

  /* Update for Delay: '<S8>/Delay' */
  Medhya_DW.icLoad_iz = false;
  Medhya_DW.Delay_DSTATE_h = rtb_Gain4;

  /* Update for Delay: '<S27>/Delay' */
  Medhya_DW.icLoad_f = false;
  Medhya_DW.Delay_DSTATE_n = rtb_Sum;

  /* Update for Delay: '<S6>/Delay' */
  Medhya_DW.icLoad_g = false;
  Medhya_DW.Delay_DSTATE_o = rtb_Saturation;
}

/* Model initialize function */
void Medhya_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Medhya_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Medhya_B), 0,
                sizeof(B_Medhya_T));

  /* states (dwork) */
  (void) memset((void *)&Medhya_DW, 0,
                sizeof(DW_Medhya_T));

  /* external inputs */
  (void)memset(&Medhya_U, 0, sizeof(ExtU_Medhya_T));

  /* external outputs */
  (void)memset(&Medhya_Y, 0, sizeof(ExtY_Medhya_T));

  /* Start for InitialCondition: '<S17>/Initial' */
  Medhya_B.Initial = Medhya_P.Initial_Value;

  /* Start for InitialCondition: '<S17>/Initial' */
  Medhya_DW.Initial_FirstOutputTime = true;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' */
  Medhya_DW.DiscreteTimeIntegrator1_DSTATE = Medhya_B.Initial;
  Medhya_DW.DiscreteTimeIntegrator1_PrevRes = 2;

  /* InitializeConditions for Delay: '<S26>/Delay' */
  Medhya_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S7>/Delay' */
  Medhya_DW.icLoad_i = true;

  /* InitializeConditions for Delay: '<S14>/Delay' */
  Medhya_DW.Delay_DSTATE_b[0] = Medhya_P.Delay_InitialCondition;
  Medhya_DW.Delay_DSTATE_b[1] = Medhya_P.Delay_InitialCondition;
  Medhya_DW.Delay_DSTATE_b[2] = Medhya_P.Delay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
  Medhya_DW.DiscreteTimeIntegrator_DSTATE = Medhya_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Delay: '<S14>/Delay1' */
  Medhya_DW.Delay1_DSTATE[0] = Medhya_P.Delay1_InitialCondition;
  Medhya_DW.Delay1_DSTATE[1] = Medhya_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S8>/Delay' */
  Medhya_DW.icLoad_iz = true;

  /* InitializeConditions for Delay: '<S27>/Delay' */
  Medhya_DW.icLoad_f = true;

  /* InitializeConditions for Delay: '<S6>/Delay' */
  Medhya_DW.icLoad_g = true;

  /* SystemInitialize for Atomic SubSystem: '<S13>/PI D-axis reg' */
  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
  Medhya_DW.UnitDelay1_DSTATE_m = Medhya_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay' */
  Medhya_DW.UnitDelay_DSTATE_b = Medhya_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay2' */
  Medhya_DW.UnitDelay2_DSTATE_m = Medhya_P.UnitDelay2_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S13>/PI D-axis reg' */

  /* SystemInitialize for Atomic SubSystem: '<S13>/PI D-axis reg1' */
  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay1' */
  Medhya_DW.UnitDelay1_DSTATE = Medhya_P.UnitDelay1_InitialCondition_e;

  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay' */
  Medhya_DW.UnitDelay_DSTATE = Medhya_P.UnitDelay_InitialCondition_o;

  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay2' */
  Medhya_DW.UnitDelay2_DSTATE = Medhya_P.UnitDelay2_InitialCondition_e;

  Medhya_U.PwmEnable = 1.0;
  Medhya_U.ManualSpeedRef = 500.0;
  
  Medhya_U.IdRef = -50.0;
  Medhya_U.IqRef = 50.0;

  Medhya_U.SpeedRef = 500.0;
  Medhya_U.ManualPositionOffset = 1.396263;
  Medhya_U.EnableManualPosition = 1.0;

  Medhya_U.VdRefManual = -0;
  Medhya_U.VqRefManual = 9.93;
    
  // Vd       	Vq
  // -0.8025	8.10E+00
  // -0.535	  8.64E+00
  // -0.2675	9.26E+00
  // 0	      9.93E+00

  Medhya_U.EnableVdVqControl = 1.0;
  Medhya_U.VdVqManualControlRampRate = 100.0; 

  Medhya_U.KpD = 0.5;
  Medhya_U.KiD = 0.001;
  Medhya_U.KpQ = 0.5;
  Medhya_U.KiQ = 0.001;

  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);

  /* End of SystemInitialize for SubSystem: '<S13>/PI D-axis reg1' */
}

/* Model terminate function */
void Medhya_terminate(void)
{
  /* (no terminate code required) */
}
