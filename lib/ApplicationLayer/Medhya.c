/*
* Medhya.c
*
* Code generation for model "Medhya".
*
* Model version              : 18.86
* Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
* C source code generated on : Thu Feb 20 19:35:36 2025
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
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"
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
  real_T Tas;
  real_T Tbs;
  real_T Toffset;
  real_T Tsw;
  real_T Tswh;
  real_T rtb_Add1_o;
  real_T rtb_Add3;
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_Gain4;
  real_T rtb_Gain_m_idx_0;
  real_T rtb_Gain_m_idx_1;
  real_T rtb_MathFunction;
  real_T rtb_Saturation;
  real_T rtb_Saturation1;
  real_T rtb_SignChange;
  real_T rtb_Sum;
  real_T rtb_Switch1_a;
  real_T rtb_Switch_idx_1;
  real_T rtb_Switch_p;
  real_T rtb_UkYk1;
  real_T rtb_b;
  real_T rtb_c;
  real_T rtb_deltafalllimit;
  real_T rtb_uDLookupTableLq;
  int16_T i;
  boolean_T rtb_LogicalOperator3_idx_0;
  boolean_T rtb_LogicalOperator3_idx_1;
  boolean_T rtb_LogicalOperator_0;
  boolean_T rtb_LogicalOperator_idx_0;
  boolean_T rtb_LogicalOperator_idx_1;
  boolean_T rtb_RelationalOperator1;

  /* RelationalOperator: '<S18>/Relational Operator1' incorporates:
   *  Constant: '<S18>/Constant3'
   */
  rtb_RelationalOperator1 = (Medhya_DW.DiscreteTimeIntegrator1_DSTATE > 0.0001);

  /* InitialCondition: '<S18>/Initial' */
  if (Medhya_DW.Initial_FirstOutputTime) {
    Medhya_DW.Initial_FirstOutputTime = false;

    /* InitialCondition: '<S18>/Initial' */
    Medhya_B.Initial = 0.0;
  } else {
    /* InitialCondition: '<S18>/Initial' incorporates:
     *  Constant: '<S18>/Constant3'
     *  Sum: '<S18>/Add3'
     */
    Medhya_B.Initial = Medhya_DW.DiscreteTimeIntegrator1_DSTATE - 0.0001;
  }

  /* End of InitialCondition: '<S18>/Initial' */

  /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator1' */
  if (rtb_RelationalOperator1 && (Medhya_DW.DiscreteTimeIntegrator1_PrevRes <= 0))
  {
    Medhya_DW.DiscreteTimeIntegrator1_DSTATE = Medhya_B.Initial;
  }

  /* Product: '<S32>/delta rise limit' incorporates:
   *  Inport: '<Root>/VdVqManualControlRampRate'
   *  Product: '<S33>/delta rise limit'
   *  SampleTimeMath: '<S32>/sample time'
   *
   * About '<S32>/sample time':
   *  y = K where K = ( w * Ts )
   *   */
  rtb_deltafalllimit = Medhya_U.VdVqManualControlRampRate * 1.0E-6;
  rtb_DiscreteTimeIntegrator = rtb_deltafalllimit;

  /* Delay: '<S32>/Delay' incorporates:
   *  Inport: '<Root>/VdRefManual'
   */
  if (Medhya_DW.icLoad) {
    Medhya_DW.Delay_DSTATE = Medhya_U.VdRefManual;
  }

  /* Sum: '<S32>/Difference Inputs1' incorporates:
   *  Delay: '<S32>/Delay'
   *  Inport: '<Root>/VdRefManual'
   */
  rtb_UkYk1 = Medhya_U.VdRefManual - Medhya_DW.Delay_DSTATE;

  /* Switch: '<S36>/Switch2' incorporates:
   *  Product: '<S32>/delta rise limit'
   *  RelationalOperator: '<S36>/LowerRelop1'
   */
  if (!(rtb_UkYk1 > rtb_deltafalllimit)) {
    /* Product: '<S32>/delta fall limit' incorporates:
     *  Gain: '<S28>/Gain3'
     *  Inport: '<Root>/VdVqManualControlRampRate'
     *  SampleTimeMath: '<S32>/sample time'
     *
     * About '<S32>/sample time':
     *  y = K where K = ( w * Ts )
     *   */
    rtb_DiscreteTimeIntegrator = 1.0E-6 * -Medhya_U.VdVqManualControlRampRate;

    /* Switch: '<S36>/Switch' incorporates:
     *  RelationalOperator: '<S36>/UpperRelop'
     */
    if (!(rtb_UkYk1 < rtb_DiscreteTimeIntegrator)) {
      rtb_DiscreteTimeIntegrator = rtb_UkYk1;
    }

    /* End of Switch: '<S36>/Switch' */
  }

  /* End of Switch: '<S36>/Switch2' */

  /* Sum: '<S32>/Difference Inputs2' incorporates:
   *  Delay: '<S32>/Delay'
   */
  rtb_UkYk1 = rtb_DiscreteTimeIntegrator + Medhya_DW.Delay_DSTATE;

  /* Product: '<S7>/delta rise limit' incorporates:
   *  Constant: '<S2>/Constant11'
   *  SampleTimeMath: '<S7>/sample time'
   *
   * About '<S7>/sample time':
   *  y = K where K = ( w * Ts )
   *   */
  rtb_DiscreteTimeIntegrator = 0.049999999999999996;

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Inport: '<Root>/IdRef'
   */
  if (Medhya_U.IdRef > 0.0) {
    rtb_Saturation = 0.0;
  } else if (Medhya_U.IdRef < -50.0) {
    rtb_Saturation = -50.0;
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

  /* Switch: '<S10>/Switch2' incorporates:
   *  RelationalOperator: '<S10>/LowerRelop1'
   */
  if (!(rtb_Saturation > 0.049999999999999996)) {
    /* Switch: '<S10>/Switch' incorporates:
     *  RelationalOperator: '<S10>/UpperRelop'
     */
    if (rtb_Saturation < -0.049999999999999996) {
      rtb_DiscreteTimeIntegrator = -0.049999999999999996;
    } else {
      rtb_DiscreteTimeIntegrator = rtb_Saturation;
    }

    /* End of Switch: '<S10>/Switch' */
  }

  /* End of Switch: '<S10>/Switch2' */

  /* Sum: '<S7>/Difference Inputs2' incorporates:
   *  Delay: '<S7>/Delay'
   */
  rtb_DiscreteTimeIntegrator += Medhya_DW.Delay_DSTATE_k;

  /* Math: '<S40>/Mod' incorporates:
   *  Constant: '<S40>/Constant2'
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   *  Inport: '<Root>/ManualPositionOffset'
   *  Sum: '<S40>/Add'
   */
  rtb_Saturation = rt_modd_snf(Medhya_DW.DiscreteTimeIntegrator_DSTATE +
    Medhya_U.ManualPositionOffset, 6.2831853071795862);

  /* Math: '<S38>/Math Function' incorporates:
   *  Constant: '<S38>/2*pi'
   *  Delay: '<S14>/Delay1'
   *  Gain: '<S38>/pole pairs '
   */
  rtb_MathFunction = rt_modd_snf(3.0 * Medhya_DW.Delay1_DSTATE[1],
    6.2831853071795862);

  /* Switch: '<S14>/Switch' incorporates:
   *  Inport: '<Root>/EnableManualPosition'
   */
  if (Medhya_U.EnableManualPosition > 0.0) {
    rtb_Switch_p = rtb_Saturation;
  } else {
    rtb_Switch_p = rtb_MathFunction;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Fcn: '<S39>/d' incorporates:
   *  Fcn: '<S15>/a'
   */
  Tas = sin(rtb_Switch_p + 1.5707963267948966);

  /* Fcn: '<S39>/q' incorporates:
   *  Fcn: '<S15>/a'
   */
  Tbs = cos(rtb_Switch_p + 1.5707963267948966);

  /* Fcn: '<S39>/d' incorporates:
   *  Fcn: '<S15>/b'
   */
  rtb_b = sin((rtb_Switch_p + 1.5707963267948966) - 2.0943951023931953);

  /* Fcn: '<S39>/q' incorporates:
   *  Fcn: '<S15>/b'
   */
  Tsw = cos((rtb_Switch_p + 1.5707963267948966) - 2.0943951023931953);

  /* Fcn: '<S39>/d' incorporates:
   *  Fcn: '<S15>/c'
   */
  rtb_c = sin((rtb_Switch_p + 1.5707963267948966) + 2.0943951023931953);

  /* Fcn: '<S39>/q' incorporates:
   *  Fcn: '<S15>/c'
   */
  Tswh = cos((rtb_Switch_p + 1.5707963267948966) + 2.0943951023931953);

  /* Gain: '<S39>/Gain1' incorporates:
   *  Delay: '<S14>/Delay'
   *  Fcn: '<S39>/d'
   *  Fcn: '<S39>/q'
   */
  rtb_Gain_m_idx_0 = ((Tas * Medhya_DW.Delay_DSTATE_b[0] + rtb_b *
                       Medhya_DW.Delay_DSTATE_b[1]) + rtb_c *
                      Medhya_DW.Delay_DSTATE_b[2]) * 0.66666666666666663;
  rtb_Gain_m_idx_1 = ((Tbs * Medhya_DW.Delay_DSTATE_b[0] + Tsw *
                       Medhya_DW.Delay_DSTATE_b[1]) + Tswh *
                      Medhya_DW.Delay_DSTATE_b[2]) * 0.66666666666666663;

  /* Sum: '<S29>/Sum' */
  rtb_Sum = rtb_DiscreteTimeIntegrator - rtb_Gain_m_idx_0;

  /* Outputs for Atomic SubSystem: '<S13>/PI D-axis reg1' */
  /* Outputs for Atomic SubSystem: '<S13>/PI D-axis reg' */
  /* Logic: '<S26>/NOT' incorporates:
   *  Inport: '<Root>/PwmEnable'
   *  Logic: '<S27>/NOT'
   */
  rtb_LogicalOperator_0 = !(Medhya_U.PwmEnable != 0.0);

  /* End of Outputs for SubSystem: '<S13>/PI D-axis reg1' */

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Constant'
   *  Logic: '<S26>/NOT'
   */
  if (rtb_LogicalOperator_0) {
    rtb_Switch_p = 0.0;
  } else {
    /* Sum: '<S26>/Subtract2' incorporates:
     *  Inport: '<Root>/Inport1'
     *  Inport: '<Root>/Inport2'
     *  Product: '<S26>/Product'
     *  Product: '<S26>/Product1'
     *  Sum: '<S26>/Subtract3'
     *  UnaryMinus: '<S26>/Unary Minus1'
     *  UnitDelay: '<S26>/Unit Delay'
     *  UnitDelay: '<S26>/Unit Delay1'
     *  UnitDelay: '<S26>/Unit Delay2'
     */
    rtb_Switch_p = (((Medhya_U.KiD + Medhya_U.KpD) * rtb_Sum +
                     Medhya_DW.UnitDelay1_DSTATE_m * -Medhya_U.KpD) +
                    Medhya_DW.UnitDelay_DSTATE_b) +
      Medhya_DW.UnitDelay2_DSTATE_m;

    /* Switch: '<S30>/Switch2' incorporates:
     *  Constant: '<S26>/Constant1'
     *  RelationalOperator: '<S30>/LowerRelop1'
     *  RelationalOperator: '<S30>/UpperRelop'
     *  Switch: '<S30>/Switch'
     *  UnaryMinus: '<S26>/Unary Minus'
     */
    if (rtb_Switch_p > 33.4863156129983) {
      rtb_Switch_p = 33.4863156129983;
    } else if (rtb_Switch_p < -33.4863156129983) {
      /* Switch: '<S30>/Switch' incorporates:
       *  UnaryMinus: '<S26>/Unary Minus'
       */
      rtb_Switch_p = -33.4863156129983;
    }

    /* End of Switch: '<S30>/Switch2' */
  }

  /* End of Switch: '<S26>/Switch' */

  /* Update for UnitDelay: '<S26>/Unit Delay1' */
  Medhya_DW.UnitDelay1_DSTATE_m = rtb_Sum;

  /* Update for UnitDelay: '<S26>/Unit Delay' */
  Medhya_DW.UnitDelay_DSTATE_b = rtb_Switch_p;

  /* Update for UnitDelay: '<S26>/Unit Delay2' incorporates:
   *  Constant: '<S13>/Constant'
   *  Product: '<S26>/Product2'
   */
  Medhya_DW.UnitDelay2_DSTATE_m = rtb_Sum * 0.0;

  /* End of Outputs for SubSystem: '<S13>/PI D-axis reg' */

  /* Product: '<S8>/delta rise limit' incorporates:
   *  Constant: '<S2>/Constant11'
   *  SampleTimeMath: '<S8>/sample time'
   *
   * About '<S8>/sample time':
   *  y = K where K = ( w * Ts )
   *   */
  rtb_Sum = 0.049999999999999996;

  /* Saturate: '<S2>/Saturation1' incorporates:
   *  Inport: '<Root>/IqRef'
   */
  if (Medhya_U.IqRef > 50.0) {
    rtb_Saturation1 = 50.0;
  } else if (Medhya_U.IqRef < -50.0) {
    rtb_Saturation1 = -50.0;
  } else {
    rtb_Saturation1 = Medhya_U.IqRef;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Delay: '<S8>/Delay' */
  if (Medhya_DW.icLoad_iz) {
    Medhya_DW.Delay_DSTATE_h = rtb_Saturation1;
  }

  /* Sum: '<S8>/Difference Inputs1' incorporates:
   *  Delay: '<S8>/Delay'
   */
  rtb_Saturation1 -= Medhya_DW.Delay_DSTATE_h;

  /* Switch: '<S11>/Switch2' incorporates:
   *  RelationalOperator: '<S11>/LowerRelop1'
   */
  if (!(rtb_Saturation1 > 0.049999999999999996)) {
    /* Switch: '<S11>/Switch' incorporates:
     *  RelationalOperator: '<S11>/UpperRelop'
     */
    if (rtb_Saturation1 < -0.049999999999999996) {
      rtb_Sum = -0.049999999999999996;
    } else {
      rtb_Sum = rtb_Saturation1;
    }

    /* End of Switch: '<S11>/Switch' */
  }

  /* End of Switch: '<S11>/Switch2' */

  /* Sum: '<S8>/Difference Inputs2' incorporates:
   *  Delay: '<S8>/Delay'
   */
  rtb_Gain4 = rtb_Sum + Medhya_DW.Delay_DSTATE_h;

  /* Abs: '<S4>/Abs' */
  rtb_Sum = fabs(rtb_Gain4);

  /* Lookup_n-D: '<S4>/2-D Lookup Table Lq' incorporates:
   *  Sum: '<S22>/Add1'
   *  Sum: '<S7>/Difference Inputs2'
   */
  rtb_uDLookupTableLq = look2_binlcpw(rtb_DiscreteTimeIntegrator, rtb_Sum,
    Medhya_ConstP.pooled9, Medhya_ConstP.pooled10,
    Medhya_ConstP.uDLookupTableLq_tableData, Medhya_ConstP.pooled11, 21UL);

  /* Gain: '<S38>/pole pairs' incorporates:
   *  Delay: '<S14>/Delay1'
   */
  rtb_Switch1_a = 3.0 * Medhya_DW.Delay1_DSTATE[0];

  /* Lookup_n-D: '<S4>/2-D Lookup Table Ld' incorporates:
   *  Sum: '<S22>/Add1'
   *  Sum: '<S7>/Difference Inputs2'
   */
  rtb_Saturation1 = look2_binlcapw(rtb_DiscreteTimeIntegrator, rtb_Sum,
    Medhya_ConstP.pooled9, Medhya_ConstP.pooled10,
    Medhya_ConstP.uDLookupTableLd_tableData, Medhya_ConstP.pooled11, 21UL);

  /* Lookup_n-D: '<S4>/2-D Lookup Table Psim' incorporates:
   *  Sum: '<S22>/Add1'
   *  Sum: '<S7>/Difference Inputs2'
   */
  rtb_Sum = look2_binlcpw(rtb_DiscreteTimeIntegrator, rtb_Sum,
    Medhya_ConstP.pooled9, Medhya_ConstP.pooled10,
    Medhya_ConstP.uDLookupTablePsim_tableData, Medhya_ConstP.pooled11, 21UL);

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Product: '<S25>/Product2'
   *  Product: '<S25>/Product3'
   *  Product: '<S25>/Product5'
   *  Sum: '<S25>/Sum1'
   *  Sum: '<S25>/Sum3'
   */
  rtb_Switch_idx_1 = (rtb_DiscreteTimeIntegrator * rtb_Saturation1 *
                      rtb_Switch1_a + rtb_Sum * rtb_Switch1_a) + rtb_Gain4 *
    0.0107;

  /* Switch: '<S28>/Switch' incorporates:
   *  Inport: '<Root>/EnableVdVqControl'
   */
  if (Medhya_U.EnableVdVqControl != 0.0) {
    rtb_Add3 = rtb_UkYk1;
  } else {
    /* Sum: '<S13>/Add1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Product: '<S25>/Product1'
     *  Product: '<S25>/Product4'
     *  Sum: '<S25>/Sum2'
     */
    rtb_Add1_o = (0.0107 * rtb_DiscreteTimeIntegrator - rtb_Gain4 *
                  rtb_uDLookupTableLq * rtb_Switch1_a) + rtb_Switch_p;

    /* Switch: '<S34>/Switch2' incorporates:
     *  RelationalOperator: '<S34>/LowerRelop1'
     *  RelationalOperator: '<S34>/UpperRelop'
     *  Switch: '<S34>/Switch'
     */
    if (rtb_Add1_o > 33.4863156129983) {
      rtb_Add3 = 33.4863156129983;
    } else if (rtb_Add1_o < -33.4863156129983) {
      /* Switch: '<S34>/Switch' */
      rtb_Add3 = -33.4863156129983;
    } else {
      rtb_Add3 = rtb_Add1_o;
    }

    /* End of Switch: '<S34>/Switch2' */
  }

  /* End of Switch: '<S28>/Switch' */

  /* Product: '<S33>/delta rise limit' */
  rtb_Switch1_a = rtb_deltafalllimit;

  /* Delay: '<S33>/Delay' incorporates:
   *  Inport: '<Root>/VqRefManual'
   */
  if (Medhya_DW.icLoad_f) {
    Medhya_DW.Delay_DSTATE_n = Medhya_U.VqRefManual;
  }

  /* Sum: '<S33>/Difference Inputs1' incorporates:
   *  Delay: '<S33>/Delay'
   *  Inport: '<Root>/VqRefManual'
   */
  rtb_Add1_o = Medhya_U.VqRefManual - Medhya_DW.Delay_DSTATE_n;

  /* Switch: '<S37>/Switch2' incorporates:
   *  RelationalOperator: '<S37>/LowerRelop1'
   */
  if (!(rtb_Add1_o > rtb_deltafalllimit)) {
    /* Product: '<S33>/delta fall limit' incorporates:
     *  Gain: '<S28>/Gain1'
     *  Inport: '<Root>/VdVqManualControlRampRate'
     *  SampleTimeMath: '<S33>/sample time'
     *
     * About '<S33>/sample time':
     *  y = K where K = ( w * Ts )
     *   */
    rtb_deltafalllimit = 1.0E-6 * -Medhya_U.VdVqManualControlRampRate;

    /* Switch: '<S37>/Switch' incorporates:
     *  RelationalOperator: '<S37>/UpperRelop'
     */
    if (rtb_Add1_o < rtb_deltafalllimit) {
      rtb_Switch1_a = rtb_deltafalllimit;
    } else {
      rtb_Switch1_a = rtb_Add1_o;
    }

    /* End of Switch: '<S37>/Switch' */
  }

  /* End of Switch: '<S37>/Switch2' */

  /* Sum: '<S33>/Difference Inputs2' incorporates:
   *  Delay: '<S33>/Delay'
   */
  rtb_Add1_o = rtb_Switch1_a + Medhya_DW.Delay_DSTATE_n;

  /* Sum: '<S29>/Sum1' */
  rtb_Switch1_a = rtb_Gain4 - rtb_Gain_m_idx_1;

  /* Outputs for Atomic SubSystem: '<S13>/PI D-axis reg1' */
  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   */
  if (rtb_LogicalOperator_0) {
    rtb_deltafalllimit = 0.0;
  } else {
    /* Sum: '<S27>/Subtract2' incorporates:
     *  Inport: '<Root>/Inport3'
     *  Inport: '<Root>/Inport4'
     *  Product: '<S27>/Product'
     *  Product: '<S27>/Product1'
     *  Sum: '<S27>/Subtract3'
     *  UnaryMinus: '<S27>/Unary Minus1'
     *  UnitDelay: '<S27>/Unit Delay'
     *  UnitDelay: '<S27>/Unit Delay1'
     *  UnitDelay: '<S27>/Unit Delay2'
     */
    rtb_deltafalllimit = (((Medhya_U.KiQ + Medhya_U.KpQ) * rtb_Switch1_a +
      Medhya_DW.UnitDelay1_DSTATE * -Medhya_U.KpQ) + Medhya_DW.UnitDelay_DSTATE)
      + Medhya_DW.UnitDelay2_DSTATE;

    /* Switch: '<S31>/Switch2' incorporates:
     *  Constant: '<S27>/Constant1'
     *  RelationalOperator: '<S31>/LowerRelop1'
     *  RelationalOperator: '<S31>/UpperRelop'
     *  Switch: '<S31>/Switch'
     *  UnaryMinus: '<S27>/Unary Minus'
     */
    if (rtb_deltafalllimit > 33.4863156129983) {
      rtb_deltafalllimit = 33.4863156129983;
    } else if (rtb_deltafalllimit < -33.4863156129983) {
      /* Switch: '<S31>/Switch' incorporates:
       *  UnaryMinus: '<S27>/Unary Minus'
       */
      rtb_deltafalllimit = -33.4863156129983;
    }

    /* End of Switch: '<S31>/Switch2' */
  }

  /* End of Switch: '<S27>/Switch' */

  /* Update for UnitDelay: '<S27>/Unit Delay1' */
  Medhya_DW.UnitDelay1_DSTATE = rtb_Switch1_a;

  /* Update for UnitDelay: '<S27>/Unit Delay' */
  Medhya_DW.UnitDelay_DSTATE = rtb_deltafalllimit;

  /* Update for UnitDelay: '<S27>/Unit Delay2' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Product: '<S27>/Product2'
   */
  Medhya_DW.UnitDelay2_DSTATE = rtb_Switch1_a * 0.0;

  /* End of Outputs for SubSystem: '<S13>/PI D-axis reg1' */

  /* Switch: '<S28>/Switch1' incorporates:
   *  Inport: '<Root>/EnableVdVqControl'
   */
  if (Medhya_U.EnableVdVqControl != 0.0) {
    rtb_Switch1_a = rtb_Add1_o;
  } else {
    /* Sum: '<S13>/Add2' */
    rtb_Switch1_a = rtb_deltafalllimit + rtb_Switch_idx_1;

    /* Switch: '<S35>/Switch2' incorporates:
     *  RelationalOperator: '<S35>/LowerRelop1'
     *  RelationalOperator: '<S35>/UpperRelop'
     *  Switch: '<S35>/Switch'
     */
    if (rtb_Switch1_a > 33.4863156129983) {
      rtb_Switch1_a = 33.4863156129983;
    } else if (rtb_Switch1_a < -33.4863156129983) {
      /* Switch: '<S35>/Switch' */
      rtb_Switch1_a = -33.4863156129983;
    }

    /* End of Switch: '<S35>/Switch2' */
  }

  /* End of Switch: '<S28>/Switch1' */

  /* Fcn: '<S15>/a' */
  rtb_Switch_idx_1 = Tas * rtb_Add3 + Tbs * rtb_Switch1_a;

  /* Fcn: '<S15>/b' */
  rtb_b = rtb_b * rtb_Add3 + Tsw * rtb_Switch1_a;

  /* Fcn: '<S15>/c' */
  rtb_c = rtb_c * rtb_Add3 + Tswh * rtb_Switch1_a;

  /* MATLAB Function: '<S16>/Switching Time Calculation' incorporates:
   *  SignalConversion generated from: '<S19>/ SFunction '
   */
  /* MATLAB Function 'PWM Generator (Three-phase, Two-level)/Switching Time Calculation': '<S19>:1' */
  /* '<S19>:1:3' */
  Tsw = rtb_Switch_idx_1 * 5.0E-5 / 58.0;
  Tswh = rtb_b * 5.0E-5 / 58.0;
  rtb_Switch1_a = rtb_c * 5.0E-5 / 58.0 + 2.5E-5;
  Toffset = 5.0E-5 - (Tsw + 2.5E-5);
  rtb_Add3 = 5.0E-5 - (Tswh + 2.5E-5);
  rtb_SignChange = 5.0E-5 - rtb_Switch1_a;
  Tas = (Tsw + 2.5E-5) + 5.0E-5;
  Tbs = (Tswh + 2.5E-5) + 5.0E-5;
  rtb_Switch1_a += 5.0E-5;
  if (5.0E-5 - (Tsw + 2.5E-5) < 0.0) {
    Toffset = 0.0;
  } else if (5.0E-5 - (Tsw + 2.5E-5) > 5.0E-5) {
    Toffset = 5.0E-5;
  }

  if (5.0E-5 - (Tswh + 2.5E-5) < 0.0) {
    rtb_Add3 = 0.0;
  } else if (5.0E-5 - (Tswh + 2.5E-5) > 5.0E-5) {
    rtb_Add3 = 5.0E-5;
  }

  if (rtb_SignChange < 0.0) {
    rtb_SignChange = 0.0;
  } else if (rtb_SignChange > 5.0E-5) {
    rtb_SignChange = 5.0E-5;
  }

  if ((Tsw + 2.5E-5) + 5.0E-5 < 5.0E-5) {
    Tas = 5.0E-5;
  } else if ((Tsw + 2.5E-5) + 5.0E-5 > 0.0001) {
    Tas = 0.0001;
  }

  if ((Tswh + 2.5E-5) + 5.0E-5 < 5.0E-5) {
    Tbs = 5.0E-5;
  } else if ((Tswh + 2.5E-5) + 5.0E-5 > 0.0001) {
    Tbs = 0.0001;
  }

  if (rtb_Switch1_a < 5.0E-5) {
    rtb_Switch1_a = 5.0E-5;
  } else if (rtb_Switch1_a > 0.0001) {
    rtb_Switch1_a = 0.0001;
  }

  /* Switch: '<S12>/Switch1' incorporates:
   *  Inport: '<Root>/PwmEnable'
   */
  /* '<S19>:1:3' */
  if (Medhya_U.PwmEnable > 0.0) {
    /* Logic: '<S18>/Logical Operator' incorporates:
     *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator1'
     *  MATLAB Function: '<S16>/Switching Time Calculation'
     *  RelationalOperator: '<S18>/Relational Operator'
     *  RelationalOperator: '<S18>/Relational Operator3'
     */
    rtb_LogicalOperator_0 = (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >= Toffset)
      ^ (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >= Tas);
    rtb_LogicalOperator_idx_0 = rtb_LogicalOperator_0;

    /* Logic: '<S18>/Logical Operator3' */
    rtb_LogicalOperator3_idx_0 = !rtb_LogicalOperator_0;

    /* Logic: '<S18>/Logical Operator' incorporates:
     *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator1'
     *  MATLAB Function: '<S16>/Switching Time Calculation'
     *  RelationalOperator: '<S18>/Relational Operator'
     *  RelationalOperator: '<S18>/Relational Operator3'
     */
    rtb_LogicalOperator_0 = (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >=
      rtb_Add3) ^ (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >= Tbs);
    rtb_LogicalOperator_idx_1 = rtb_LogicalOperator_0;

    /* Logic: '<S18>/Logical Operator3' */
    rtb_LogicalOperator3_idx_1 = !rtb_LogicalOperator_0;

    /* Logic: '<S18>/Logical Operator' incorporates:
     *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator1'
     *  MATLAB Function: '<S16>/Switching Time Calculation'
     *  RelationalOperator: '<S18>/Relational Operator'
     *  RelationalOperator: '<S18>/Relational Operator3'
     */
    rtb_LogicalOperator_0 = (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >=
      rtb_SignChange) ^ (Medhya_DW.DiscreteTimeIntegrator1_DSTATE >=
                         rtb_Switch1_a);

    /* Outport: '<Root>/G' incorporates:
     *  DataTypeConversion: '<S16>/Data Type Conversion'
     *  Logic: '<S18>/Logical Operator'
     *  Logic: '<S18>/Logical Operator3'
     */
    Medhya_Y.G[0] = rtb_LogicalOperator_idx_0;
    Medhya_Y.G[1] = rtb_LogicalOperator3_idx_0;
    Medhya_Y.G[2] = rtb_LogicalOperator_idx_1;
    Medhya_Y.G[3] = rtb_LogicalOperator3_idx_1;
    Medhya_Y.G[4] = rtb_LogicalOperator_0;
    Medhya_Y.G[5] = !rtb_LogicalOperator_0;
  } else {
    /* Outport: '<Root>/G' */
    for (i = 0; i < 6; i++) {
      Medhya_Y.G[i] = 0.0;
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
  Medhya_Y.VqControl = rtb_deltafalllimit;

  /* Outport: '<Root>/IdqFeedback' */
  Medhya_Y.IdqFeedback[0] = rtb_Gain_m_idx_0;

  /* Outport: '<Root>/ModWave' incorporates:
   *  MATLAB Function: '<S16>/Switching Time Calculation'
   */
  Medhya_Y.ModWave[0] = (Tas - Toffset) / 0.0001 * 2.0 - 1.0;

  /* Outport: '<Root>/IdqFeedback' */
  Medhya_Y.IdqFeedback[1] = rtb_Gain_m_idx_1;

  /* Outport: '<Root>/ModWave' incorporates:
   *  MATLAB Function: '<S16>/Switching Time Calculation'
   */
  Medhya_Y.ModWave[1] = (Tbs - rtb_Add3) / 0.0001 * 2.0 - 1.0;

  /* Outport: '<Root>/IdqFeedback' incorporates:
   *  Delay: '<S14>/Delay'
   *  Fcn: '<S39>/0'
   *  Gain: '<S39>/Gain1'
   */
  Medhya_Y.IdqFeedback[2] = ((Medhya_DW.Delay_DSTATE_b[0] +
    Medhya_DW.Delay_DSTATE_b[1]) + Medhya_DW.Delay_DSTATE_b[2]) * 0.5 *
    0.66666666666666663;

  /* Outport: '<Root>/ModWave' incorporates:
   *  MATLAB Function: '<S16>/Switching Time Calculation'
   */
  Medhya_Y.ModWave[2] = (rtb_Switch1_a - rtb_SignChange) / 0.0001 * 2.0 - 1.0;

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
  Medhya_Y.TorqueCalc = ((rtb_Saturation1 - rtb_uDLookupTableLq) *
    rtb_DiscreteTimeIntegrator * rtb_Gain4 + rtb_Sum * rtb_Gain4) * 3.0 * 1.5;

  /* Product: '<S6>/delta rise limit' incorporates:
   *  Constant: '<S2>/Constant10'
   *  SampleTimeMath: '<S6>/sample time'
   *
   * About '<S6>/sample time':
   *  y = K where K = ( w * Ts )
   *   */
  rtb_Saturation1 = 0.5;

  /* Saturate: '<S2>/Saturation2' incorporates:
   *  Inport: '<Root>/SpeedRef'
   */
  if (Medhya_U.SpeedRef > 1000.0) {
    rtb_Saturation = 1000.0;
  } else if (Medhya_U.SpeedRef < 0.0) {
    rtb_Saturation = 0.0;
  } else {
    rtb_Saturation = Medhya_U.SpeedRef;
  }

  /* End of Saturate: '<S2>/Saturation2' */

  /* Delay: '<S6>/Delay' */
  if (Medhya_DW.icLoad_g) {
    Medhya_DW.Delay_DSTATE_o = rtb_Saturation;
  }

  /* Sum: '<S6>/Difference Inputs1' incorporates:
   *  Delay: '<S6>/Delay'
   */
  rtb_Saturation -= Medhya_DW.Delay_DSTATE_o;

  /* Switch: '<S9>/Switch2' incorporates:
   *  RelationalOperator: '<S9>/LowerRelop1'
   */
  if (!(rtb_Saturation > 0.5)) {
    /* Switch: '<S9>/Switch' incorporates:
     *  RelationalOperator: '<S9>/UpperRelop'
     */
    if (rtb_Saturation < -0.5) {
      rtb_Saturation1 = -0.5;
    } else {
      rtb_Saturation1 = rtb_Saturation;
    }

    /* End of Switch: '<S9>/Switch' */
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Sum: '<S6>/Difference Inputs2' incorporates:
   *  Delay: '<S6>/Delay'
   */
  rtb_Saturation = rtb_Saturation1 + Medhya_DW.Delay_DSTATE_o;

  /* Outport: '<Root>/SpeedRef_out' */
  Medhya_Y.SpeedRef_out = rtb_Saturation;

  /* Gain: '<S23>/one_by_two' incorporates:
   *  MinMax: '<S23>/Max'
   *  MinMax: '<S23>/Min'
   *  Sum: '<S23>/Add'
   */
  rtb_Saturation1 = (fmax(fmax(rtb_Switch_idx_1, rtb_b), rtb_c) + fmin(fmin
    (rtb_Switch_idx_1, rtb_b), rtb_c)) * -0.5;

  /* Outport: '<Root>/Va' incorporates:
   *  Gain: '<S22>/Gain'
   *  Sum: '<S22>/Add3'
   */
  Medhya_Y.Va = (rtb_Switch_idx_1 + rtb_Saturation1) * 1.1547005383792517;

  /* Outport: '<Root>/Vb' incorporates:
   *  Gain: '<S22>/Gain'
   *  Sum: '<S22>/Add1'
   */
  Medhya_Y.Vb = (rtb_b + rtb_Saturation1) * 1.1547005383792517;

  /* Outport: '<Root>/Vc' incorporates:
   *  Gain: '<S22>/Gain'
   *  Sum: '<S22>/Add2'
   */
  Medhya_Y.Vc = (rtb_Saturation1 + rtb_c) * 1.1547005383792517;

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S18>/Constant2'
   */
  Medhya_DW.DiscreteTimeIntegrator1_DSTATE += 1.0E-6;
  Medhya_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)rtb_RelationalOperator1;

  /* Update for Delay: '<S32>/Delay' */
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

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S40>/Constant1'
   *  Gain: '<S40>/Gain'
   *  Inport: '<Root>/ManualSpeedRef'
   *  Product: '<S40>/Divide'
   */
  Medhya_DW.DiscreteTimeIntegrator_DSTATE += 0.05 * Medhya_U.ManualSpeedRef *
    6.2831853071795862 * 1.0E-6;

  /* Update for Delay: '<S14>/Delay1' incorporates:
   *  Inport: '<Root>/Inport5'
   */
  Medhya_DW.Delay1_DSTATE[0] = Medhya_U.Speed_Anlge_feedback[0];
  Medhya_DW.Delay1_DSTATE[1] = Medhya_U.Speed_Anlge_feedback[1];

  /* Update for Delay: '<S8>/Delay' */
  Medhya_DW.icLoad_iz = false;
  Medhya_DW.Delay_DSTATE_h = rtb_Gain4;

  /* Update for Delay: '<S33>/Delay' */
  Medhya_DW.icLoad_f = false;
  Medhya_DW.Delay_DSTATE_n = rtb_Add1_o;

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

  /* Start for InitialCondition: '<S18>/Initial' */
  Medhya_B.Initial = 0.0;

  /* Start for InitialCondition: '<S18>/Initial' */
  Medhya_DW.Initial_FirstOutputTime = true;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator1' */
  Medhya_DW.DiscreteTimeIntegrator1_DSTATE = Medhya_B.Initial;
  Medhya_DW.DiscreteTimeIntegrator1_PrevRes = 2;

  /* InitializeConditions for Delay: '<S32>/Delay' */
  Medhya_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S7>/Delay' */
  Medhya_DW.icLoad_i = true;

  /* InitializeConditions for Delay: '<S14>/Delay' */
  Medhya_DW.Delay_DSTATE_b[0] = 0.0;
  Medhya_DW.Delay_DSTATE_b[1] = 0.0;
  Medhya_DW.Delay_DSTATE_b[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  Medhya_DW.DiscreteTimeIntegrator_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S14>/Delay1' */
  Medhya_DW.Delay1_DSTATE[0] = 0.0;
  Medhya_DW.Delay1_DSTATE[1] = 0.0;

  /* InitializeConditions for Delay: '<S8>/Delay' */
  Medhya_DW.icLoad_iz = true;

  /* InitializeConditions for Delay: '<S33>/Delay' */
  Medhya_DW.icLoad_f = true;

  /* InitializeConditions for Delay: '<S6>/Delay' */
  Medhya_DW.icLoad_g = true;

  /* SystemInitialize for Atomic SubSystem: '<S13>/PI D-axis reg' */
  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay1' */
  Medhya_DW.UnitDelay1_DSTATE_m = 0.0;

  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay' */
  Medhya_DW.UnitDelay_DSTATE_b = 0.0;

  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay2' */
  Medhya_DW.UnitDelay2_DSTATE_m = 0.0;

  /* End of SystemInitialize for SubSystem: '<S13>/PI D-axis reg' */

  /* SystemInitialize for Atomic SubSystem: '<S13>/PI D-axis reg1' */
  /* InitializeConditions for UnitDelay: '<S27>/Unit Delay1' */
  Medhya_DW.UnitDelay1_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S27>/Unit Delay' */
  Medhya_DW.UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay2' */
  Medhya_DW.UnitDelay2_DSTATE = 0.0;

  Medhya_U.PwmEnable = 1.0;
  Medhya_U.ManualSpeedRef = 500.0;
  
  Medhya_U.IdRef = -50.0;
  Medhya_U.IqRef = 50.0;

  Medhya_U.SpeedRef = 500.0;
  Medhya_U.ManualPositionOffset = -0.523598775598;
  Medhya_U.EnableManualPosition = 1.0;

  Medhya_U.VdRefManual = -6;
  Medhya_U.VqRefManual = 9;
    
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
