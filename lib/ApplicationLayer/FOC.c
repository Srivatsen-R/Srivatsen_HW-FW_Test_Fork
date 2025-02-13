/*
 * FOC.c
 *
 * Code generation for model "FOC".
 *
 * Model version              : 18.115
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Jan 24 14:55:07 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FOC.h"
#include "rtwtypes.h"
#include "FOC_types.h"
#include <math.h>
#include <string.h>

/* Block signals (default storage) */
B_FOC_T FOC_B;

/* Block states (default storage) */
DW_FOC_T FOC_DW;

/* External inputs (root inport signals with default storage) */
ExtU_FOC_T FOC_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FOC_T FOC_Y;

FOC_Flag_T FOC_F_T;

/* Real-time model */
static RT_MODEL_FOC_T FOC_M_;
RT_MODEL_FOC_T *const FOC_M = &FOC_M_;

/* Forward declaration for local functions */
static void FOC_VoltageProtection(void);

/* Function for Chart: '<S3>/Protection_States' */
static void FOC_VoltageProtection(void)
{
  switch (FOC_DW.is_VoltageProtection) {
   case FOC_IN_OV_Error:
    /* Outport: '<Root>/VoltageFlag' */
    FOC_Y.VoltageFlag = OV_Error;
    if (FOC_DW.durationCounter_1_m > 1000U) {
      FOC_DW.durationCounter_2_c0 = 0U;
      FOC_DW.durationCounter_1_h = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_VoltageSafe;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = SafeVoltage;
    } else if (FOC_DW.durationCounter_2_d > 1000U) {
      FOC_DW.durationCounter_2_bq = 0U;
      FOC_DW.durationCounter_1_f = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_OV_Warning;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = OV_Warning;
    }
    break;

   case FOC_IN_OV_Warning:
    /* Outport: '<Root>/VoltageFlag' */
    FOC_Y.VoltageFlag = OV_Warning;
    FOC_DW.durationCounter_2_bq = 0U;
    if (FOC_DW.durationCounter_1_f > 1000U) {
      FOC_DW.durationCounter_2_c0 = 0U;
      FOC_DW.durationCounter_1_h = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_VoltageSafe;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = SafeVoltage;
    }
    break;

   case FOC_IN_UV_Error:
    /* Outport: '<Root>/VoltageFlag' */
    FOC_Y.VoltageFlag = UV_Error;

    /* Inport: '<Root>/BusVoltage_V' */
    /* Inport: '<Root>/BusVoltage_V' */
    if (!(FOC_U.BusVoltage_V > -80.0F)) {
      FOC_DW.durationCounter_1_e3 = 0U;
    }

    if (FOC_DW.durationCounter_1_e3 > 1000U) {
      FOC_DW.durationCounter_2_k = 0U;
      FOC_DW.durationCounter_1_o = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_UV_Warning;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = UV_Warning;
    } else {
      if (!(FOC_U.BusVoltage_V > -60.0F)) {
        FOC_DW.durationCounter_2_n = 0U;
      }

      if (FOC_DW.durationCounter_2_n > 1000U) {
        FOC_DW.durationCounter_2_c0 = 0U;
        FOC_DW.durationCounter_1_h = 0U;
        FOC_DW.is_VoltageProtection = FOC_IN_VoltageSafe;

        /* Outport: '<Root>/VoltageFlag' */
        FOC_Y.VoltageFlag = SafeVoltage;
      }
    }
    break;

   case FOC_IN_UV_Warning:
    /* Outport: '<Root>/VoltageFlag' */
    FOC_Y.VoltageFlag = UV_Warning;

    /* Inport: '<Root>/BusVoltage_V' */
    /* Inport: '<Root>/BusVoltage_V' */
    if (!(FOC_U.BusVoltage_V < -80.0F)) {
      FOC_DW.durationCounter_1_o = 0U;
    }

    if (FOC_DW.durationCounter_1_o > 1000U) {
      FOC_DW.durationCounter_2_n = 0U;
      FOC_DW.durationCounter_1_e3 = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_UV_Error;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = UV_Error;
    } else {
      if (!(FOC_U.BusVoltage_V > -60.0F)) {
        FOC_DW.durationCounter_2_k = 0U;
      }

      if (FOC_DW.durationCounter_2_k > 1000U) {
        FOC_DW.durationCounter_2_c0 = 0U;
        FOC_DW.durationCounter_1_h = 0U;
        FOC_DW.is_VoltageProtection = FOC_IN_VoltageSafe;

        /* Outport: '<Root>/VoltageFlag' */
        FOC_Y.VoltageFlag = SafeVoltage;
      }
    }
    break;

   default:
    /* Outport: '<Root>/VoltageFlag' */
    /* case IN_VoltageSafe: */
    FOC_Y.VoltageFlag = SafeVoltage;
    FOC_DW.durationCounter_2_c0 = 0U;

    /* Inport: '<Root>/BusVoltage_V' */
    if (!(FOC_U.BusVoltage_V < -60.0F)) {
      FOC_DW.durationCounter_1_h = 0U;
    }

    if (FOC_DW.durationCounter_1_h > 1000U) {
      FOC_DW.durationCounter_2_k = 0U;
      FOC_DW.durationCounter_1_o = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_UV_Warning;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = UV_Warning;
    }
    break;
  }
}

/* Model step function */
void FOC_step(void)
{
  real_T rtb_Add1;
  real_T rtb_Add2;
  real_T rtb_Switch_f_idx_0;
  real_T rtb_TrigonometricFunction1_tmp;
  real_T rtb_VdFF_unsat;
  real32_T Max2;
  real32_T rtb_Divide;
  real32_T rtb_IProdOut;
  real32_T rtb_IProdOut_g;
  real32_T rtb_IProdOut_l;
  real32_T rtb_Integrator_d;
  real32_T rtb_NProdOut;
  real32_T rtb_Sum_i;
  real32_T rtb_Sum_k;
  real32_T rtb_Sum_n;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_AND3;
  boolean_T rtb_AND3_g;

  /* Product: '<S24>/Divide1' incorporates:
   *  Gain: '<S24>/Gain2'
   *  Inport: '<Root>/Lamda'
   *  Inport: '<Root>/Ld'
   *  Inport: '<Root>/Lq'
   *  Sum: '<S24>/Subtract2'
   */
  rtb_Integrator_d = FOC_U.Lamda / ((FOC_U.Lq - FOC_U.Ld) * 4.0F);

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/Actual Speed'
   *  Inport: '<Root>/Ref Speed'
   *  Sum: '<S6>/Sum1'
   */
  rtb_IProdOut = (real32_T)(FOC_U.RefSpeed - FOC_U.ActualSpeed);

  /* Product: '<S71>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S63>/Filter'
   *  Inport: '<Root>/MTPA_PID'
   *  Product: '<S61>/DProd Out'
   *  Sum: '<S63>/SumD'
   */
  rtb_NProdOut = (rtb_IProdOut * FOC_U.MTPA_PID.Speed_PID_MTPA.Kd_speed_PID_MTPA
                  - FOC_DW.Filter_DSTATE) *
    FOC_U.MTPA_PID.Speed_PID_MTPA.Filter_speed_PID_MTPA;

  /* Sum: '<S78>/Sum' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  DiscreteIntegrator: '<S68>/Integrator'
   *  Inport: '<Root>/MTPA_PID'
   *  Product: '<S73>/PProd Out'
   */
  rtb_Sum_i = (rtb_IProdOut * FOC_U.MTPA_PID.Speed_PID_MTPA.Kp_speed_PID_MTPA +
               FOC_DW.Integrator_DSTATE) + rtb_NProdOut;

  /* Switch: '<S76>/Switch2' incorporates:
   *  Inport: '<Root>/MTPA_PID'
   *  RelationalOperator: '<S76>/LowerRelop1'
   *  RelationalOperator: '<S76>/UpperRelop'
   *  Switch: '<S76>/Switch'
   */
  if (rtb_Sum_i > FOC_U.MTPA_PID.Speed_PID_MTPA.Up_Limit_speed_PID_MTPA) {
    Max2 = FOC_U.MTPA_PID.Speed_PID_MTPA.Up_Limit_speed_PID_MTPA;
  } else if (rtb_Sum_i < FOC_U.MTPA_PID.Speed_PID_MTPA.Low_Limit_speed_PID_MTPA)
  {
    /* Switch: '<S76>/Switch' */
    Max2 = FOC_U.MTPA_PID.Speed_PID_MTPA.Low_Limit_speed_PID_MTPA;
  } else {
    Max2 = rtb_Sum_i;
  }

  /* Product: '<S24>/Divide' incorporates:
   *  Abs: '<S24>/Abs1'
   *  Constant: '<S24>/Constant1'
   *  Inport: '<Root>/Lamda'
   *  Inport: '<Root>/p'
   *  Product: '<S24>/Product'
   *  Switch: '<S76>/Switch2'
   */
  rtb_Divide = (real32_T)(fabsf(Max2));

  /* Switch: '<S30>/Switch2' incorporates:
   *  Inport: '<Root>/Iq_low_limit'
   *  Inport: '<Root>/Iq_up_limit'
   *  RelationalOperator: '<S30>/LowerRelop1'
   *  RelationalOperator: '<S30>/UpperRelop'
   *  Switch: '<S30>/Switch'
   */
  if (rtb_Divide > FOC_U.Iq_up_limit) {
    rtb_Divide = FOC_U.Iq_up_limit;
  } else if (rtb_Divide < FOC_U.Iq_low_limit) {
    /* Switch: '<S30>/Switch' incorporates:
     *  Inport: '<Root>/Iq_low_limit'
     */
    rtb_Divide = FOC_U.Iq_low_limit;
  }

  /* End of Switch: '<S30>/Switch2' */

  /* Math: '<S24>/Math Function2' */
  rtb_Divide *= rtb_Divide;

  /* Sum: '<S24>/Subtract' incorporates:
   *  Abs: '<S24>/Abs2'
   *  Gain: '<S24>/Gain4'
   *  Math: '<S24>/Math Function'
   *  Sqrt: '<S24>/Sqrt'
   *  Sum: '<S24>/Add'
   */
  rtb_Integrator_d -= sqrtf(fabsf(rtb_Integrator_d * rtb_Integrator_d + 0.5F *
    rtb_Divide));

  /* Switch: '<S29>/Switch2' incorporates:
   *  Inport: '<Root>/Id_low_limit'
   *  Inport: '<Root>/Id_up_limit'
   *  RelationalOperator: '<S29>/LowerRelop1'
   *  RelationalOperator: '<S29>/UpperRelop'
   *  Sum: '<S24>/Subtract'
   *  Switch: '<S29>/Switch'
   */
  if (rtb_Integrator_d > FOC_U.Id_up_limit) {
    /* Switch: '<S29>/Switch2' */
    FOC_Y.Id_ref = FOC_U.Id_up_limit;
  } else if (rtb_Integrator_d < FOC_U.Id_low_limit) {
    /* Switch: '<S29>/Switch2' incorporates:
     *  Inport: '<Root>/Id_low_limit'
     *  Switch: '<S29>/Switch'
     */
    FOC_Y.Id_ref = FOC_U.Id_low_limit;
  } else {
    /* Switch: '<S29>/Switch2' */
    FOC_Y.Id_ref = rtb_Integrator_d;
  }

  foc_log.Id_ref = FOC_Y.Id_ref;

  /* End of Switch: '<S29>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S9>/Two phase CRL wrap' */
  /* Gain: '<S10>/one_by_sqrt3' incorporates:
   *  Inport: '<Root>/Phase Current'
   *  Sum: '<S10>/a_plus_2b'
   */
  rtb_Add2 = ((FOC_U.PhaseCurrent[0] + FOC_U.PhaseCurrent[1]) +
              FOC_U.PhaseCurrent[1]) * 0.57735026918962584;

  /* End of Outputs for SubSystem: '<S9>/Two phase CRL wrap' */

  /* Trigonometry: '<S4>/Trigonometric Function' incorporates:
   *  Inport: '<Root>/angle'
   *  Trigonometry: '<S5>/Trigonometric Function1'
   */
  rtb_Add1 = sin(FOC_U.angle);

  /* Trigonometry: '<S4>/Trigonometric Function1' incorporates:
   *  Inport: '<Root>/angle'
   *  Trigonometry: '<S5>/Trigonometric Function'
   */
  rtb_TrigonometricFunction1_tmp = cos(FOC_U.angle);

  /* Outputs for Atomic SubSystem: '<S8>/Two inputs CRL' */
  /* Outputs for Atomic SubSystem: '<S9>/Two phase CRL wrap' */
  /* Switch: '<S12>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S10>/a16'
   *  Inport: '<Root>/Phase Current'
   *  Product: '<S11>/acos'
   *  Product: '<S11>/bsin'
   *  Sum: '<S11>/sum_Ds'
   *  Trigonometry: '<S4>/Trigonometric Function'
   *  Trigonometry: '<S4>/Trigonometric Function1'
   */
  rtb_Switch_f_idx_0 = FOC_U.PhaseCurrent[0] * rtb_TrigonometricFunction1_tmp +
    rtb_Add2 * rtb_Add1;

  /* Switch: '<S18>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S10>/a16'
   *  Inport: '<Root>/Phase Current'
   *  Product: '<S11>/asin'
   *  Product: '<S11>/bcos'
   *  Sum: '<S11>/sum_Qs'
   *  Switch: '<S12>/Switch'
   *  Trigonometry: '<S4>/Trigonometric Function'
   *  Trigonometry: '<S4>/Trigonometric Function1'
   */
  FOC_Y.Iq = rtb_Add2 * rtb_TrigonometricFunction1_tmp - FOC_U.PhaseCurrent[0] *
    rtb_Add1;

  foc_log.Iq = FOC_Y.Iq;

  /* End of Outputs for SubSystem: '<S9>/Two phase CRL wrap' */

  /* Outport: '<Root>/Id' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
   */
  FOC_Y.Id = rtb_Switch_f_idx_0;

  foc_log.Id = FOC_Y.Id;

  /* DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
   *  Sum: '<S6>/Sum3'
   */
  rtb_IProdOut_l = (real32_T)(FOC_Y.Id_ref - rtb_Switch_f_idx_0);

  /* End of Outputs for SubSystem: '<S8>/Two inputs CRL' */

  /* Product: '<S127>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S119>/Filter'
   *  Inport: '<Root>/MTPA_PID'
   *  Product: '<S117>/DProd Out'
   *  Sum: '<S119>/SumD'
   */
  rtb_Integrator_d = (rtb_IProdOut_l *
                      FOC_U.MTPA_PID.Flux_PID_MTPA.Kd_flux_PID_MTPA -
                      FOC_DW.Filter_DSTATE_k) *
    FOC_U.MTPA_PID.Flux_PID_MTPA.Filter_flux_PID_MTPA;

  /* Sum: '<S134>/Sum' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S124>/Integrator'
   *  Inport: '<Root>/MTPA_PID'
   *  Product: '<S129>/PProd Out'
   */
  rtb_Sum_k = (rtb_IProdOut_l * FOC_U.MTPA_PID.Flux_PID_MTPA.Kp_flux_PID_MTPA +
               FOC_DW.Integrator_DSTATE_p) + rtb_Integrator_d;

  /* Sqrt: '<S24>/Sqrt1' incorporates:
   *  Abs: '<S24>/Abs'
   *  Math: '<S24>/Math Function3'
   *  Sum: '<S24>/Subtract1'
   */
  FOC_Y.Iq_ref = sqrt(fabs(rtb_Divide - FOC_Y.Id_ref * FOC_Y.Id_ref));

  foc_log.Iq_ref = FOC_Y.Iq_ref;

  /* Gain: '<S200>/wm_pu2si_mech2elec' incorporates:
   *  Gain: '<S6>/Gain'
   *  Inport: '<Root>/Actual Speed'
   */
  rtb_Add2 = 0.33333333333333331 * FOC_U.ActualSpeed * 3.0;

  /* Gain: '<S200>/NegSign' incorporates:
   *  Product: '<S200>/prod1'
   */
  rtb_VdFF_unsat = -(FOC_ConstB.Switch1 * FOC_Y.Iq_ref * rtb_Add2);

  /* Switch: '<S132>/Switch2' incorporates:
   *  Inport: '<Root>/MTPA_PID'
   *  RelationalOperator: '<S132>/LowerRelop1'
   *  RelationalOperator: '<S132>/UpperRelop'
   *  Switch: '<S132>/Switch'
   */
  if (rtb_Sum_k > FOC_U.MTPA_PID.Flux_PID_MTPA.Up_Limit_flux_PID_MTPA) {
    Max2 = FOC_U.MTPA_PID.Flux_PID_MTPA.Up_Limit_flux_PID_MTPA;
  } else if (rtb_Sum_k < FOC_U.MTPA_PID.Flux_PID_MTPA.Low_Limit_flux_PID_MTPA) {
    /* Switch: '<S132>/Switch' */
    Max2 = FOC_U.MTPA_PID.Flux_PID_MTPA.Low_Limit_flux_PID_MTPA;
  } else {
    Max2 = rtb_Sum_k;
  }

  /* Switch: '<S202>/Switch2' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   *  RelationalOperator: '<S202>/LowerRelop1'
   *  RelationalOperator: '<S202>/UpperRelop'
   *  Switch: '<S202>/Switch'
   *  UnaryMinus: '<S200>/Unary Minus'
   */
  if (rtb_VdFF_unsat > FOC_U.BusVoltage_V) {
    rtb_VdFF_unsat = FOC_U.BusVoltage_V;
  } else if (rtb_VdFF_unsat < -FOC_U.BusVoltage_V) {
    /* Switch: '<S202>/Switch' incorporates:
     *  UnaryMinus: '<S200>/Unary Minus'
     */
    rtb_VdFF_unsat = -FOC_U.BusVoltage_V;
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Switch: '<S132>/Switch2'
   *  Switch: '<S202>/Switch2'
   */
  FOC_Y.Vd = Max2 + rtb_VdFF_unsat;

  foc_log.Vd = FOC_Y.Vd;

  /* Product: '<S200>/prod2' incorporates:
   *  Product: '<S200>/prod3'
   *  Sum: '<S200>/add1'
   */
  rtb_VdFF_unsat = (FOC_ConstB.Switch * FOC_Y.Id_ref + FOC_ConstB.Switch2) *
    rtb_Add2;

  /* Outputs for Atomic SubSystem: '<S8>/Two inputs CRL' */
  /* DataTypeConversion: '<S6>/Data Type Conversion2' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
   *  Sum: '<S6>/Sum2'
   */
  rtb_IProdOut_g = (real32_T)(FOC_Y.Iq_ref - FOC_Y.Iq);

  /* End of Outputs for SubSystem: '<S8>/Two inputs CRL' */

  /* Product: '<S183>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S175>/Filter'
   *  Inport: '<Root>/MTPA_PID'
   *  Product: '<S173>/DProd Out'
   *  Sum: '<S175>/SumD'
   */
  rtb_Divide = (rtb_IProdOut_g *
                FOC_U.MTPA_PID.Torque_PID_MTPA.Kd_torque_PID_MTPA -
                FOC_DW.Filter_DSTATE_d) *
    FOC_U.MTPA_PID.Torque_PID_MTPA.Filter_torque_PID_MTPA;

  /* Sum: '<S190>/Sum' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S180>/Integrator'
   *  Inport: '<Root>/MTPA_PID'
   *  Product: '<S185>/PProd Out'
   */
  rtb_Sum_n = (rtb_IProdOut_g *
               FOC_U.MTPA_PID.Torque_PID_MTPA.Kp_torque_PID_MTPA +
               FOC_DW.Integrator_DSTATE_h) + rtb_Divide;

  /* Switch: '<S203>/Switch2' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   *  RelationalOperator: '<S203>/LowerRelop1'
   *  RelationalOperator: '<S203>/UpperRelop'
   *  Switch: '<S203>/Switch'
   *  UnaryMinus: '<S200>/Unary Minus'
   */
  if (rtb_VdFF_unsat > FOC_U.BusVoltage_V) {
    rtb_VdFF_unsat = FOC_U.BusVoltage_V;
  } else if (rtb_VdFF_unsat < -FOC_U.BusVoltage_V) {
    /* Switch: '<S203>/Switch' incorporates:
     *  UnaryMinus: '<S200>/Unary Minus'
     */
    rtb_VdFF_unsat = -FOC_U.BusVoltage_V;
  }

  /* Switch: '<S188>/Switch2' incorporates:
   *  Inport: '<Root>/MTPA_PID'
   *  RelationalOperator: '<S188>/LowerRelop1'
   *  RelationalOperator: '<S188>/UpperRelop'
   *  Switch: '<S188>/Switch'
   */
  if (rtb_Sum_n > FOC_U.MTPA_PID.Torque_PID_MTPA.Up_Limit_torque_PID_MTPA) {
    Max2 = FOC_U.MTPA_PID.Torque_PID_MTPA.Up_Limit_torque_PID_MTPA;
  } else if (rtb_Sum_n <
             FOC_U.MTPA_PID.Torque_PID_MTPA.Low_Limit_torque_PID_MTPA) {
    /* Switch: '<S188>/Switch' */
    Max2 = FOC_U.MTPA_PID.Torque_PID_MTPA.Low_Limit_torque_PID_MTPA;
  } else {
    Max2 = rtb_Sum_n;
  }

  /* Sum: '<S6>/Sum4' incorporates:
   *  Switch: '<S188>/Switch2'
   *  Switch: '<S203>/Switch2'
   */
  FOC_Y.Vq = rtb_VdFF_unsat + Max2;
  
  foc_log.Vq = FOC_Y.Vq;

  /* Outputs for Atomic SubSystem: '<S14>/Two inputs CRL' */
  /* Switch: '<S18>/Switch' incorporates:
   *  Product: '<S17>/dcos'
   *  Product: '<S17>/qsin'
   *  Sum: '<S17>/sum_alpha'
   */
  rtb_Switch_f_idx_0 = FOC_Y.Vd * rtb_TrigonometricFunction1_tmp - FOC_Y.Vq *
    rtb_Add1;

  /* Gain: '<S16>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S17>/a16'
   */
  rtb_VdFF_unsat = 0.5 * rtb_Switch_f_idx_0;

  /* Gain: '<S16>/sqrt3_by_two' incorporates:
   *  Product: '<S17>/dsin'
   *  Product: '<S17>/qcos'
   *  Sum: '<S17>/sum_beta'
   */
  rtb_Add2 = (FOC_Y.Vq * rtb_TrigonometricFunction1_tmp + FOC_Y.Vd * rtb_Add1) *
    0.8660254037844386;

  /* End of Outputs for SubSystem: '<S14>/Two inputs CRL' */

  /* Sum: '<S16>/add_b' */
  rtb_Add1 = rtb_Add2 - rtb_VdFF_unsat;

  /* Sum: '<S16>/add_c' */
  rtb_VdFF_unsat = (0.0 - rtb_VdFF_unsat) - rtb_Add2;

  /* Outputs for Atomic SubSystem: '<S14>/Two inputs CRL' */
  /* Gain: '<S22>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S17>/a16'
   *  MinMax: '<S22>/Max'
   *  MinMax: '<S22>/Min'
   *  Sum: '<S22>/Add'
   */
  rtb_Add2 = (fmax(fmax(rtb_Switch_f_idx_0, rtb_Add1), rtb_VdFF_unsat) + fmin
              (fmin(rtb_Switch_f_idx_0, rtb_Add1), rtb_VdFF_unsat)) * -0.5;

  /* Gain: '<S21>/Gain' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S17>/a16'
   *  Sum: '<S21>/Add1'
   *  Sum: '<S21>/Add2'
   *  Sum: '<S21>/Add3'
   */
  FOC_Y.Va = (rtb_Switch_f_idx_0 + rtb_Add2) * 1.1547005383792517;

  foc_log.Va = FOC_Y.Va;

  /* End of Outputs for SubSystem: '<S14>/Two inputs CRL' */
  FOC_Y.Vb = (rtb_Add1 + rtb_Add2) * 1.1547005383792517;

  foc_log.Vb = FOC_Y.Vb;

  FOC_Y.Vc = (rtb_Add2 + rtb_VdFF_unsat) * 1.1547005383792517;

  foc_log.Vc = FOC_Y.Vc;

  /* MinMax: '<S3>/Max1' */
  FOC_B.Max1 = fmax(fmax(FOC_Y.Va, FOC_Y.Vb), FOC_Y.Vc);

  /* MinMax: '<S3>/Max2' incorporates:
   *  Inport: '<Root>/MCTemperature_C'
   *  Inport: '<Root>/MotorTemperature_C'
   */
  Max2 = fmaxf(FOC_U.MCTemperature_C, FOC_U.MotorTemperature_C);

  /* MinMax: '<S3>/Max' incorporates:
   *  Inport: '<Root>/Phase Current'
   */
  rtb_VdFF_unsat = fmax(fmax(FOC_U.PhaseCurrent[0], FOC_U.PhaseCurrent[1]),
                        FOC_U.PhaseCurrent[2]);

  /* Chart: '<S3>/Protection_States' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   */
  if (FOC_DW.is_active_c7_FOC == 0) {
    FOC_DW.is_active_c7_FOC = 1U;
    FOC_DW.durationCounter_1 = 0U;
    FOC_DW.is_TemperatureProtection = FOC_IN_TempSafe;

    /* Outport: '<Root>/TempFlag' */
    FOC_Y.TempFlag = SafeTemperature;
    FOC_DW.durationCounter_1_h = 0U;
    FOC_DW.is_VoltageProtection = FOC_IN_VoltageSafe;

    /* Outport: '<Root>/VoltageFlag' */
    FOC_Y.VoltageFlag = SafeVoltage;
    FOC_DW.durationCounter_1_i = 0U;
    FOC_DW.is_CurrentProtection = FOC_IN_CurrentSafe;

    /* Outport: '<Root>/CurrentFlag' */
    FOC_Y.CurrentFlag = SafeCurrent;
  } else {
    switch (FOC_DW.is_TemperatureProtection) {
     case FOC_IN_HighTempError:
      /* Outport: '<Root>/TempFlag' */
      FOC_Y.TempFlag = OT_Error;
      if (!(Max2 < 80.0F)) {
        FOC_DW.durationCounter_1_c = 0U;
      }

      if (FOC_DW.durationCounter_1_c > 1000U) {
        FOC_DW.durationCounter_1 = 0U;
        FOC_DW.is_TemperatureProtection = FOC_IN_TempSafe;

        /* Outport: '<Root>/TempFlag' */
        FOC_Y.TempFlag = SafeTemperature;
      } else {
        if (!(Max2 < 100.0F)) {
          FOC_DW.durationCounter_2 = 0U;
        }

        if (FOC_DW.durationCounter_2 > 1000U) {
          FOC_DW.durationCounter_2_e = 0U;
          FOC_DW.durationCounter_1_e = 0U;
          FOC_DW.is_TemperatureProtection = FOC_IN_HighTempWarning;

          /* Outport: '<Root>/TempFlag' */
          FOC_Y.TempFlag = OT_Warning;
        }
      }
      break;

     case FOC_IN_HighTempWarning:
      /* Outport: '<Root>/TempFlag' */
      FOC_Y.TempFlag = OT_Warning;
      if (!(Max2 > 100.0F)) {
        FOC_DW.durationCounter_2_e = 0U;
      }

      if (FOC_DW.durationCounter_2_e > 1000U) {
        FOC_DW.durationCounter_2 = 0U;
        FOC_DW.durationCounter_1_c = 0U;
        FOC_DW.is_TemperatureProtection = FOC_IN_HighTempError;

        /* Outport: '<Root>/TempFlag' */
        FOC_Y.TempFlag = OT_Error;
      } else {
        if (!(Max2 < 80.0F)) {
          FOC_DW.durationCounter_1_e = 0U;
        }

        if (FOC_DW.durationCounter_1_e > 1000U) {
          FOC_DW.durationCounter_1 = 0U;
          FOC_DW.is_TemperatureProtection = FOC_IN_TempSafe;

          /* Outport: '<Root>/TempFlag' */
          FOC_Y.TempFlag = SafeTemperature;
        }
      }
      break;

     default:
      /* Outport: '<Root>/TempFlag' */
      /* case IN_TempSafe: */
      FOC_Y.TempFlag = SafeTemperature;
      if (!(Max2 > 80.0F)) {
        FOC_DW.durationCounter_1 = 0U;
      }

      if (FOC_DW.durationCounter_1 > 1000U) {
        FOC_DW.durationCounter_2_e = 0U;
        FOC_DW.durationCounter_1_e = 0U;
        FOC_DW.is_TemperatureProtection = FOC_IN_HighTempWarning;

        /* Outport: '<Root>/TempFlag' */
        FOC_Y.TempFlag = OT_Warning;
      }
      break;
    }

    FOC_VoltageProtection();
    switch (FOC_DW.is_CurrentProtection) {
     case FOC_IN_CurrentSafe:
      /* Outport: '<Root>/CurrentFlag' */
      FOC_Y.CurrentFlag = SafeCurrent;
      if (!(rtb_VdFF_unsat > 80.0)) {
        FOC_DW.durationCounter_1_i = 0U;
      }

      if (FOC_DW.durationCounter_1_i > 1000U) {
        FOC_DW.durationCounter_2_c = 0U;
        FOC_DW.durationCounter_1_d = 0U;
        FOC_DW.is_CurrentProtection = FOC_IN_OC_Warning;

        /* Outport: '<Root>/CurrentFlag' */
        FOC_Y.CurrentFlag = OC_Warning;
      }
      break;

     case FOC_IN_OC_Error:
      /* Outport: '<Root>/CurrentFlag' */
      FOC_Y.CurrentFlag = OC_Error;
      if (!(rtb_VdFF_unsat < 80.0)) {
        FOC_DW.durationCounter_1_a = 0U;
      }

      if (FOC_DW.durationCounter_1_a > 1000U) {
        FOC_DW.durationCounter_1_i = 0U;
        FOC_DW.is_CurrentProtection = FOC_IN_CurrentSafe;

        /* Outport: '<Root>/CurrentFlag' */
        FOC_Y.CurrentFlag = SafeCurrent;
      } else {
        if (!(rtb_VdFF_unsat < 100.0)) {
          FOC_DW.durationCounter_2_b = 0U;
        }

        if (FOC_DW.durationCounter_2_b > 1000U) {
          FOC_DW.durationCounter_2_c = 0U;
          FOC_DW.durationCounter_1_d = 0U;
          FOC_DW.is_CurrentProtection = FOC_IN_OC_Warning;

          /* Outport: '<Root>/CurrentFlag' */
          FOC_Y.CurrentFlag = OC_Warning;
        }
      }
      break;

     default:
      /* Outport: '<Root>/CurrentFlag' */
      /* case IN_OC_Warning: */
      FOC_Y.CurrentFlag = OC_Warning;
      if (!(rtb_VdFF_unsat > 100.0)) {
        FOC_DW.durationCounter_2_c = 0U;
      }

      if (FOC_DW.durationCounter_2_c > 1000U) {
        FOC_DW.durationCounter_2_b = 0U;
        FOC_DW.durationCounter_1_a = 0U;
        FOC_DW.is_CurrentProtection = FOC_IN_OC_Error;

        /* Outport: '<Root>/CurrentFlag' */
        FOC_Y.CurrentFlag = OC_Error;
      } else {
        if (!(rtb_VdFF_unsat < 80.0)) {
          FOC_DW.durationCounter_1_d = 0U;
        }

        if (FOC_DW.durationCounter_1_d > 1000U) {
          FOC_DW.durationCounter_1_i = 0U;
          FOC_DW.is_CurrentProtection = FOC_IN_CurrentSafe;

          /* Outport: '<Root>/CurrentFlag' */
          FOC_Y.CurrentFlag = SafeCurrent;
        }
      }
      break;
    }
  }

  if (Max2 > 80.0F) {
    FOC_DW.durationCounter_1++;
  } else {
    FOC_DW.durationCounter_1 = 0U;
  }

  if (Max2 < 80.0F) {
    FOC_DW.durationCounter_1_c++;
    FOC_DW.durationCounter_1_e++;
  } else {
    FOC_DW.durationCounter_1_c = 0U;
    FOC_DW.durationCounter_1_e = 0U;
  }

  if (Max2 < 100.0F) {
    FOC_DW.durationCounter_2++;
  } else {
    FOC_DW.durationCounter_2 = 0U;
  }

  if (Max2 > 100.0F) {
    FOC_DW.durationCounter_2_e++;
  } else {
    FOC_DW.durationCounter_2_e = 0U;
  }

  if (rtb_VdFF_unsat > 80.0) {
    FOC_DW.durationCounter_1_i++;
  } else {
    FOC_DW.durationCounter_1_i = 0U;
  }

  if (rtb_VdFF_unsat < 80.0) {
    FOC_DW.durationCounter_1_a++;
    FOC_DW.durationCounter_1_d++;
  } else {
    FOC_DW.durationCounter_1_a = 0U;
    FOC_DW.durationCounter_1_d = 0U;
  }

  if (rtb_VdFF_unsat < 100.0) {
    FOC_DW.durationCounter_2_b++;
  } else {
    FOC_DW.durationCounter_2_b = 0U;
  }

  if (rtb_VdFF_unsat > 100.0) {
    FOC_DW.durationCounter_2_c++;
  } else {
    FOC_DW.durationCounter_2_c = 0U;
  }

  if (FOC_U.BusVoltage_V > -80.0F) {
    FOC_DW.durationCounter_1_e3++;
  } else {
    FOC_DW.durationCounter_1_e3 = 0U;
  }

  if (FOC_U.BusVoltage_V < -80.0F) {
    FOC_DW.durationCounter_1_o++;
  } else {
    FOC_DW.durationCounter_1_o = 0U;
  }

  if (FOC_U.BusVoltage_V < -60.0F) {
    FOC_DW.durationCounter_1_h++;
  } else {
    FOC_DW.durationCounter_1_h = 0U;
  }

  if (FOC_U.BusVoltage_V > -60.0F) {
    FOC_DW.durationCounter_2_k++;
    FOC_DW.durationCounter_2_n++;
  } else {
    FOC_DW.durationCounter_2_k = 0U;
    FOC_DW.durationCounter_2_n = 0U;
  }

  FOC_DW.durationCounter_2_c0 = 0U;
  FOC_DW.durationCounter_1_m++;
  FOC_DW.durationCounter_1_f++;
  FOC_DW.durationCounter_2_d++;
  FOC_DW.durationCounter_2_bq = 0U;

  /* End of Chart: '<S3>/Protection_States' */

  /* Switch: '<S172>/Switch' incorporates:
   *  Inport: '<Root>/MTPA_PID'
   *  RelationalOperator: '<S172>/u_GTE_up'
   *  RelationalOperator: '<S172>/u_GT_lo'
   *  Switch: '<S172>/Switch1'
   */
  if (rtb_Sum_n >= FOC_U.MTPA_PID.Torque_PID_MTPA.Up_Limit_torque_PID_MTPA) {
    Max2 = FOC_U.MTPA_PID.Torque_PID_MTPA.Up_Limit_torque_PID_MTPA;
  } else if (rtb_Sum_n >
             FOC_U.MTPA_PID.Torque_PID_MTPA.Low_Limit_torque_PID_MTPA) {
    /* Switch: '<S172>/Switch1' */
    Max2 = rtb_Sum_n;
  } else {
    Max2 = FOC_U.MTPA_PID.Torque_PID_MTPA.Low_Limit_torque_PID_MTPA;
  }

  /* Sum: '<S172>/Diff' incorporates:
   *  Switch: '<S172>/Switch'
   */
  Max2 = rtb_Sum_n - Max2;

  /* Product: '<S177>/IProd Out' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   *  Inport: '<Root>/MTPA_PID'
   */
  rtb_IProdOut_g *= FOC_U.MTPA_PID.Torque_PID_MTPA.Ki_torque_PID_MTPA;

  /* Switch: '<S169>/Switch1' incorporates:
   *  Constant: '<S169>/Clamping_zero'
   *  Constant: '<S169>/Constant'
   *  Constant: '<S169>/Constant2'
   *  RelationalOperator: '<S169>/fix for DT propagation issue'
   */
  if (Max2 > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S169>/Switch2' incorporates:
   *  Constant: '<S169>/Clamping_zero'
   *  Constant: '<S169>/Constant3'
   *  Constant: '<S169>/Constant4'
   *  RelationalOperator: '<S169>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_g > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Logic: '<S169>/AND3' incorporates:
   *  Constant: '<S169>/Clamping_zero'
   *  RelationalOperator: '<S169>/Equal1'
   *  RelationalOperator: '<S169>/Relational Operator'
   *  Switch: '<S169>/Switch1'
   *  Switch: '<S169>/Switch2'
   */
  rtb_AND3 = ((Max2 != 0.0F) && (tmp == tmp_0));

  /* Switch: '<S116>/Switch' incorporates:
   *  Inport: '<Root>/MTPA_PID'
   *  RelationalOperator: '<S116>/u_GTE_up'
   *  RelationalOperator: '<S116>/u_GT_lo'
   *  Switch: '<S116>/Switch1'
   */
  if (rtb_Sum_k >= FOC_U.MTPA_PID.Flux_PID_MTPA.Up_Limit_flux_PID_MTPA) {
    Max2 = FOC_U.MTPA_PID.Flux_PID_MTPA.Up_Limit_flux_PID_MTPA;
  } else if (rtb_Sum_k > FOC_U.MTPA_PID.Flux_PID_MTPA.Low_Limit_flux_PID_MTPA) {
    /* Switch: '<S116>/Switch1' */
    Max2 = rtb_Sum_k;
  } else {
    Max2 = FOC_U.MTPA_PID.Flux_PID_MTPA.Low_Limit_flux_PID_MTPA;
  }

  /* Sum: '<S116>/Diff' incorporates:
   *  Switch: '<S116>/Switch'
   */
  Max2 = rtb_Sum_k - Max2;

  /* Product: '<S121>/IProd Out' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion1'
   *  Inport: '<Root>/MTPA_PID'
   */
  rtb_IProdOut_l *= FOC_U.MTPA_PID.Flux_PID_MTPA.Ki_flux_PID_MTPA;

  /* Switch: '<S113>/Switch1' incorporates:
   *  Constant: '<S113>/Clamping_zero'
   *  Constant: '<S113>/Constant'
   *  Constant: '<S113>/Constant2'
   *  RelationalOperator: '<S113>/fix for DT propagation issue'
   */
  if (Max2 > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S113>/Switch2' incorporates:
   *  Constant: '<S113>/Clamping_zero'
   *  Constant: '<S113>/Constant3'
   *  Constant: '<S113>/Constant4'
   *  RelationalOperator: '<S113>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_l > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Logic: '<S113>/AND3' incorporates:
   *  Constant: '<S113>/Clamping_zero'
   *  RelationalOperator: '<S113>/Equal1'
   *  RelationalOperator: '<S113>/Relational Operator'
   *  Switch: '<S113>/Switch1'
   *  Switch: '<S113>/Switch2'
   */
  rtb_AND3_g = ((Max2 != 0.0F) && (tmp == tmp_0));

  /* Switch: '<S60>/Switch' incorporates:
   *  Inport: '<Root>/MTPA_PID'
   *  RelationalOperator: '<S60>/u_GTE_up'
   *  RelationalOperator: '<S60>/u_GT_lo'
   *  Switch: '<S60>/Switch1'
   */
  if (rtb_Sum_i >= FOC_U.MTPA_PID.Speed_PID_MTPA.Up_Limit_speed_PID_MTPA) {
    Max2 = FOC_U.MTPA_PID.Speed_PID_MTPA.Up_Limit_speed_PID_MTPA;
  } else if (rtb_Sum_i > FOC_U.MTPA_PID.Speed_PID_MTPA.Low_Limit_speed_PID_MTPA)
  {
    /* Switch: '<S60>/Switch1' */
    Max2 = rtb_Sum_i;
  } else {
    Max2 = FOC_U.MTPA_PID.Speed_PID_MTPA.Low_Limit_speed_PID_MTPA;
  }

  /* Sum: '<S60>/Diff' incorporates:
   *  Switch: '<S60>/Switch'
   */
  Max2 = rtb_Sum_i - Max2;

  /* Product: '<S65>/IProd Out' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  Inport: '<Root>/MTPA_PID'
   */
  rtb_IProdOut *= FOC_U.MTPA_PID.Speed_PID_MTPA.Ki_speed_PID_MTPA;

  /* Switch: '<S57>/Switch1' incorporates:
   *  Constant: '<S57>/Clamping_zero'
   *  Constant: '<S57>/Constant'
   *  Constant: '<S57>/Constant2'
   *  RelationalOperator: '<S57>/fix for DT propagation issue'
   */
  if (Max2 > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S57>/Switch2' incorporates:
   *  Constant: '<S57>/Clamping_zero'
   *  Constant: '<S57>/Constant3'
   *  Constant: '<S57>/Constant4'
   *  RelationalOperator: '<S57>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S57>/Clamping_zero'
   *  Constant: '<S57>/Constant1'
   *  Logic: '<S57>/AND3'
   *  RelationalOperator: '<S57>/Equal1'
   *  RelationalOperator: '<S57>/Relational Operator'
   *  Switch: '<S57>/Switch1'
   *  Switch: '<S57>/Switch2'
   */
  if ((Max2 != 0.0F) && (tmp == tmp_0)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S68>/Integrator' incorporates:
   *  Switch: '<S57>/Switch'
   */
  FOC_DW.Integrator_DSTATE += 0.0001F * rtb_IProdOut;

  /* Update for DiscreteIntegrator: '<S63>/Filter' */
  FOC_DW.Filter_DSTATE += 0.0001F * rtb_NProdOut;

  /* Switch: '<S113>/Switch' incorporates:
   *  Constant: '<S113>/Constant1'
   */
  if (rtb_AND3_g) {
    rtb_IProdOut_l = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S124>/Integrator' incorporates:
   *  Switch: '<S113>/Switch'
   */
  FOC_DW.Integrator_DSTATE_p += 0.0001F * rtb_IProdOut_l;

  /* Update for DiscreteIntegrator: '<S119>/Filter' */
  FOC_DW.Filter_DSTATE_k += 0.0001F * rtb_Integrator_d;

  /* Switch: '<S169>/Switch' incorporates:
   *  Constant: '<S169>/Constant1'
   */
  if (rtb_AND3) {
    rtb_IProdOut_g = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S180>/Integrator' incorporates:
   *  Switch: '<S169>/Switch'
   */
  FOC_DW.Integrator_DSTATE_h += 0.0001F * rtb_IProdOut_g;

  /* Update for DiscreteIntegrator: '<S175>/Filter' */
  FOC_DW.Filter_DSTATE_d += 0.0001F * rtb_Divide;
}

/* Model initialize function */
void FOC_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(FOC_M, (NULL));

  (void) memset(&FOC_F_T, 0, sizeof(FOC_Flag_T));

  /* block I/O */
  (void) memset(((void *) &FOC_B), 0,
                sizeof(B_FOC_T));

  /* states (dwork) */
  (void) memset((void *)&FOC_DW, 0,
                sizeof(DW_FOC_T));

  /* external inputs */
  (void)memset(&FOC_U, 0, sizeof(ExtU_FOC_T));

  /* external outputs */
  (void)memset(&FOC_Y, 0, sizeof(ExtY_FOC_T));

  /* InitializeConditions for DiscreteIntegrator: '<S68>/Integrator' */
  FOC_DW.Integrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S63>/Filter' */
  FOC_DW.Filter_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Integrator' */
  FOC_DW.Integrator_DSTATE_p = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Filter' */
  FOC_DW.Filter_DSTATE_k = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S180>/Integrator' */
  FOC_DW.Integrator_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S175>/Filter' */
  FOC_DW.Filter_DSTATE_d = 0.0F;

  /* SystemInitialize for Outport: '<Root>/CurrentFlag' incorporates:
   *  Chart: '<S3>/Protection_States'
   */
  FOC_Y.CurrentFlag = SafeCurrent;

  /* SystemInitialize for Outport: '<Root>/VoltageFlag' incorporates:
   *  Chart: '<S3>/Protection_States'
   */
  FOC_Y.VoltageFlag = SafeVoltage;

  /* SystemInitialize for Outport: '<Root>/TempFlag' incorporates:
   *  Chart: '<S3>/Protection_States'
   */
  FOC_Y.TempFlag = SafeTemperature;

  /* SystemInitialize for Chart: '<S3>/Protection_States' */
  FOC_DW.is_active_c7_FOC = 0U;
  FOC_DW.is_TemperatureProtection = FOC_IN_NO_ACTIVE_CHILD;
  FOC_DW.is_VoltageProtection = FOC_IN_NO_ACTIVE_CHILD;
  FOC_DW.is_CurrentProtection = FOC_IN_NO_ACTIVE_CHILD;

  FOC_U.Lq = 0.000387;
  FOC_U.Ld = 0.000147;
  FOC_U.Lamda = 0.0263;
  FOC_U.p = POLEPAIRS;
  FOC_U.torque_ratio = 0.228571f;

  FOC_U.Id_up_limit = 0.0f;
  FOC_U.Id_low_limit = -300.0f;
  FOC_U.Iq_up_limit = 300.0f;
  FOC_U.Iq_low_limit = 0.0f;
  FOC_U.BusVoltage_V = 61.0f;

  FOC_U.MTPA_PID.Speed_PID_MTPA.Kp_speed_PID_MTPA = 5.0;
  FOC_U.MTPA_PID.Speed_PID_MTPA.Ki_speed_PID_MTPA = 72.0;
  FOC_U.MTPA_PID.Speed_PID_MTPA.Kd_speed_PID_MTPA = 0.001;
  FOC_U.MTPA_PID.Speed_PID_MTPA.Filter_speed_PID_MTPA = 10;
  FOC_U.MTPA_PID.Speed_PID_MTPA.Up_Limit_speed_PID_MTPA = 300.0;
  FOC_U.MTPA_PID.Speed_PID_MTPA.Low_Limit_speed_PID_MTPA = 0.0;

  FOC_U.MTPA_PID.Flux_PID_MTPA.Kp_flux_PID_MTPA = 0.01;
  FOC_U.MTPA_PID.Flux_PID_MTPA.Ki_flux_PID_MTPA = 40.0;
  FOC_U.MTPA_PID.Flux_PID_MTPA.Kd_flux_PID_MTPA = 0.001;
  FOC_U.MTPA_PID.Flux_PID_MTPA.Filter_flux_PID_MTPA = 10.0;
  FOC_U.MTPA_PID.Flux_PID_MTPA.Up_Limit_flux_PID_MTPA = (61.0f / sqrtf(3.0));
  FOC_U.MTPA_PID.Flux_PID_MTPA.Low_Limit_flux_PID_MTPA = -(61.0f / sqrtf(3.0));

  FOC_U.MTPA_PID.Torque_PID_MTPA.Kp_torque_PID_MTPA = 0.01;
  FOC_U.MTPA_PID.Torque_PID_MTPA.Ki_torque_PID_MTPA = 42.0;
  FOC_U.MTPA_PID.Torque_PID_MTPA.Kd_torque_PID_MTPA = 0.001;
  FOC_U.MTPA_PID.Torque_PID_MTPA.Filter_torque_PID_MTPA = 10.0;
  FOC_U.MTPA_PID.Torque_PID_MTPA.Up_Limit_torque_PID_MTPA = (61.0f / sqrtf(3.0));
  FOC_U.MTPA_PID.Torque_PID_MTPA.Low_Limit_torque_PID_MTPA = 0.0;

  fnr.current_state = NEUTRAL;
  fnr.previous_state = FORWARD;
  fnr.throttle_disabled = 1;

  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

/* Model terminate function */
void FOC_terminate(void)
{
  /* (no terminate code required) */
}