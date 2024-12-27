#include "vector_control.h"

#if SPEED_MODE
/*
 * FOC.c
 *
 * Code generation for model "FOC".
 *
 * Model version              : 18.39
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Sat Dec 21 16:19:18 2024
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
#include "FOC_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "main.h"

/* Named constants for Chart: '<S4>/Protection_States' */
#define FOC_IN_CurrentSafe             ((uint8_T)1U)
#define FOC_IN_HighTempError           ((uint8_T)1U)
#define FOC_IN_HighTempWarning         ((uint8_T)2U)
#define FOC_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define FOC_IN_OC_Error                ((uint8_T)2U)
#define FOC_IN_OC_Warning              ((uint8_T)3U)
#define FOC_IN_OV_Error                ((uint8_T)1U)
#define FOC_IN_OV_Warning              ((uint8_T)2U)
#define FOC_IN_TempSafe                ((uint8_T)3U)
#define FOC_IN_UV_Error                ((uint8_T)3U)
#define FOC_IN_UV_Warning              ((uint8_T)4U)
#define FOC_IN_VoltageSafe             ((uint8_T)5U)

/* Block signals (default storage) */
B_FOC_T FOC_B;

/* Block states (default storage) */
DW_FOC_T FOC_DW;

/* External inputs (root inport signals with default storage) */
ExtU_FOC_T FOC_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FOC_T FOC_Y;

FOC_Flag_T FOC_F_T;

const ConstB_FOC_T FOC_ConstB;

/* Real-time model */
static RT_MODEL_FOC_T FOC_M_;
RT_MODEL_FOC_T *const FOC_M = &FOC_M_;

/* Forward declaration for local functions */
static void FOC_VoltageProtection(void);

/* Function for Chart: '<S4>/Protection_States' */
static void FOC_VoltageProtection(void)
{
  real_T tmp;
  real32_T tmp_0;
  switch (FOC_DW.is_VoltageProtection) {
   case FOC_IN_OV_Error:
    /* Outport: '<Root>/VoltageFlag' */
    FOC_Y.VoltageFlag = OV_Error;

    /* Inport: '<Root>/BusVoltage_V' */
    tmp_0 = (real32_T)((FOC_B.Max1 != 0.0) || (FOC_U.BusVoltage_V != 0.0F));
    if (!(tmp_0 < FOC_B.BusConversion_InsertedFor_Prote.OVWarningLimit_V)) {
      FOC_DW.durationCounter_1_m = 0U;
    }

    tmp = FOC_B.BusConversion_InsertedFor_Prote.VoltageProtectionTimeout_msec *
      100.0F;
    if (FOC_DW.durationCounter_1_m > tmp) {
      FOC_DW.durationCounter_2_c0 = 0U;
      FOC_DW.durationCounter_1_h = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_VoltageSafe;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = SafeVoltage;
    } else {
      if (!(tmp_0 < FOC_B.BusConversion_InsertedFor_Prote.OVErrorLimit_V)) {
        FOC_DW.durationCounter_2_d = 0U;
      }

      if (FOC_DW.durationCounter_2_d > tmp) {
        FOC_DW.durationCounter_2_bq = 0U;
        FOC_DW.durationCounter_1_f = 0U;
        FOC_DW.is_VoltageProtection = FOC_IN_OV_Warning;

        /* Outport: '<Root>/VoltageFlag' */
        FOC_Y.VoltageFlag = OV_Warning;
      }
    }
    break;

   case FOC_IN_OV_Warning:
    /* Outport: '<Root>/VoltageFlag' */
    FOC_Y.VoltageFlag = OV_Warning;

    /* Inport: '<Root>/BusVoltage_V' */
    tmp_0 = (real32_T)((FOC_B.Max1 != 0.0) || (FOC_U.BusVoltage_V != 0.0F));
    if (!(tmp_0 > FOC_B.BusConversion_InsertedFor_Prote.OVErrorLimit_V)) {
      FOC_DW.durationCounter_2_bq = 0U;
    }

    tmp = FOC_B.BusConversion_InsertedFor_Prote.VoltageProtectionTimeout_msec *
      100.0F;
    if (FOC_DW.durationCounter_2_bq > tmp) {
      FOC_DW.durationCounter_2_d = 0U;
      FOC_DW.durationCounter_1_m = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_OV_Error;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = OV_Error;
    } else {
      if (!(tmp_0 < FOC_B.BusConversion_InsertedFor_Prote.OVWarningLimit_V)) {
        FOC_DW.durationCounter_1_f = 0U;
      }

      if (FOC_DW.durationCounter_1_f > tmp) {
        FOC_DW.durationCounter_2_c0 = 0U;
        FOC_DW.durationCounter_1_h = 0U;
        FOC_DW.is_VoltageProtection = FOC_IN_VoltageSafe;

        /* Outport: '<Root>/VoltageFlag' */
        FOC_Y.VoltageFlag = SafeVoltage;
      }
    }
    break;

   case FOC_IN_UV_Error:
    /* Outport: '<Root>/VoltageFlag' */
    FOC_Y.VoltageFlag = UV_Error;

    /* Inport: '<Root>/BusVoltage_V' */
    /* Inport: '<Root>/BusVoltage_V' */
    if (!(FOC_U.BusVoltage_V >
          FOC_B.BusConversion_InsertedFor_Prote.UVErrorLimit_V)) {
      FOC_DW.durationCounter_1_e3 = 0U;
    }

    tmp = FOC_B.BusConversion_InsertedFor_Prote.VoltageProtectionTimeout_msec *
      100.0F;
    if (FOC_DW.durationCounter_1_e3 > tmp) {
      FOC_DW.durationCounter_2_k = 0U;
      FOC_DW.durationCounter_1_o = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_UV_Warning;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = UV_Warning;
    } else {
      if (!(FOC_U.BusVoltage_V >
            FOC_B.BusConversion_InsertedFor_Prote.UVWarningLimit_V)) {
        FOC_DW.durationCounter_2_n = 0U;
      }

      if (FOC_DW.durationCounter_2_n > tmp) {
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
    if (!(FOC_U.BusVoltage_V <
          FOC_B.BusConversion_InsertedFor_Prote.UVErrorLimit_V)) {
      FOC_DW.durationCounter_1_o = 0U;
    }

    tmp = FOC_B.BusConversion_InsertedFor_Prote.VoltageProtectionTimeout_msec *
      100.0F;
    if (FOC_DW.durationCounter_1_o > tmp) {
      FOC_DW.durationCounter_2_n = 0U;
      FOC_DW.durationCounter_1_e3 = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_UV_Error;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = UV_Error;
    } else {
      if (!(FOC_U.BusVoltage_V >
            FOC_B.BusConversion_InsertedFor_Prote.UVWarningLimit_V)) {
        FOC_DW.durationCounter_2_k = 0U;
      }

      if (FOC_DW.durationCounter_2_k > tmp) {
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

    /* Inport: '<Root>/BusVoltage_V' */
    /* Inport: '<Root>/BusVoltage_V' */
    if (!(((FOC_B.Max1 != 0.0) || (FOC_U.BusVoltage_V != 0.0F)) >
          FOC_B.BusConversion_InsertedFor_Prote.OVWarningLimit_V)) {
      FOC_DW.durationCounter_2_c0 = 0U;
    }

    tmp = FOC_B.BusConversion_InsertedFor_Prote.VoltageProtectionTimeout_msec *
      100.0F;
    if (FOC_DW.durationCounter_2_c0 > tmp) {
      FOC_DW.durationCounter_2_bq = 0U;
      FOC_DW.durationCounter_1_f = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_OV_Warning;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = OV_Warning;
    } else {
      if (!(FOC_U.BusVoltage_V <
            FOC_B.BusConversion_InsertedFor_Prote.UVWarningLimit_V)) {
        FOC_DW.durationCounter_1_h = 0U;
      }

      if (FOC_DW.durationCounter_1_h > tmp) {
        FOC_DW.durationCounter_2_k = 0U;
        FOC_DW.durationCounter_1_o = 0U;
        FOC_DW.is_VoltageProtection = FOC_IN_UV_Warning;

        /* Outport: '<Root>/VoltageFlag' */
        FOC_Y.VoltageFlag = UV_Warning;
      }
    }
    break;
  }
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Model step function */
void FOC_step(void)
{
  real_T rtb_Diff_j;
  real_T rtb_Divide;
  real_T rtb_E_expected;
  real_T rtb_IProdOut;
  real_T rtb_IProdOut_l;
  real_T rtb_Integrator_d;
  real_T rtb_NProdOut;
  real_T rtb_NProdOut_b;
  real_T rtb_Subtract;
  real_T rtb_Sum;
  real_T rtb_Sum_ep;
  real_T rtb_Switch_fv_idx_0;
  real_T rtb_TrigonometricFunction1_tmp;
  real_T rtb_VdFF_unsat;
  real_T rtb_add_c;
  real32_T rtb_Divide1;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_AND3;
  boolean_T rtb_AND3_g;

  /* Product: '<S31>/Divide1' incorporates:
   *  Gain: '<S31>/Gain2'
   *  Inport: '<Root>/Lamda'
   *  Inport: '<Root>/Ld'
   *  Inport: '<Root>/Lq'
   *  Sum: '<S31>/Subtract2'
   */
  rtb_Divide1 = FOC_U.Lamda / ((FOC_U.Lq - FOC_U.Ld) * 4.0F);

  /* Sum: '<S8>/Sum1' incorporates:
   *  Inport: '<Root>/Actual Speed'
   *  Inport: '<Root>/Ref Speed'
   */
  rtb_IProdOut = FOC_U.RefSpeed - FOC_U.ActualSpeed;

  /* Product: '<S75>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S67>/Filter'
   *  Inport: '<Root>/Filter_speed_PID'
   *  Inport: '<Root>/Kd_speed_PID'
   *  Product: '<S65>/DProd Out'
   *  Sum: '<S67>/SumD'
   */
  rtb_NProdOut = (rtb_IProdOut * FOC_U.Kd_speed_PID - FOC_DW.Filter_DSTATE) *
    FOC_U.Filter_speed_PID;

  /* Sum: '<S82>/Sum' incorporates:
   *  DiscreteIntegrator: '<S72>/Integrator'
   *  Inport: '<Root>/Kp_speed_PID'
   *  Product: '<S77>/PProd Out'
   */
  rtb_Sum = (rtb_IProdOut * FOC_U.Kp_speed_PID + FOC_DW.Integrator_DSTATE) +
    rtb_NProdOut;

  /* Switch: '<S80>/Switch2' incorporates:
   *  Inport: '<Root>/Low_Limit_speed_PID'
   *  Inport: '<Root>/Up_Limit_speed_PID'
   *  RelationalOperator: '<S80>/LowerRelop1'
   *  RelationalOperator: '<S80>/UpperRelop'
   *  Switch: '<S80>/Switch'
   */
  if (rtb_Sum > FOC_U.Up_Limit_speed_PID) {
    rtb_Diff_j = FOC_U.Up_Limit_speed_PID;
  } else if (rtb_Sum < FOC_U.Low_Limit_speed_PID) {
    /* Switch: '<S80>/Switch' incorporates:
     *  Inport: '<Root>/Low_Limit_speed_PID'
     */
    rtb_Diff_j = FOC_U.Low_Limit_speed_PID;
  } else {
    rtb_Diff_j = rtb_Sum;
  }

  /* Product: '<S31>/Divide' incorporates:
   *  Constant: '<S31>/Constant1'
   *  Gain: '<S31>/Gain'
   *  Inport: '<Root>/Lamda'
   *  Inport: '<Root>/p'
   *  Product: '<S31>/Product'
   *  Switch: '<S80>/Switch2'
   */
  rtb_Divide = 2.0 * rtb_Diff_j / (real32_T)(FOC_U.Lamda * FOC_U.p * 3.0);

  /* Switch: '<S34>/Switch2' incorporates:
   *  Inport: '<Root>/Iq_low_limit'
   *  Inport: '<Root>/Iq_up_limit'
   *  RelationalOperator: '<S34>/LowerRelop1'
   *  RelationalOperator: '<S34>/UpperRelop'
   *  Switch: '<S34>/Switch'
   */
  if (rtb_Divide > FOC_U.Iq_up_limit) {
    rtb_Divide = FOC_U.Iq_up_limit;
  } else if (rtb_Divide < FOC_U.Iq_low_limit) {
    /* Switch: '<S34>/Switch' incorporates:
     *  Inport: '<Root>/Iq_low_limit'
     */
    rtb_Divide = FOC_U.Iq_low_limit;
  }

  FOC_Y.Iq_refer = rtb_Divide;

  /* End of Switch: '<S34>/Switch2' */

  /* Math: '<S31>/Math Function2'
   *
   * About '<S31>/Math Function2':
   *  Operator: magnitude^2
   */
  rtb_Divide *= rtb_Divide;

  /* Sum: '<S31>/Subtract' incorporates:
   *  Gain: '<S31>/Gain4'
   *  Math: '<S31>/Math Function'
   *  Sqrt: '<S31>/Sqrt'
   *  Sum: '<S31>/Add'
   *
   * About '<S31>/Math Function':
   *  Operator: magnitude^2
   */
  rtb_Subtract = rtb_Divide1 - sqrt(rtb_Divide1 * rtb_Divide1 + 0.5 * rtb_Divide);

  /* Switch: '<S33>/Switch2' incorporates:
   *  Inport: '<Root>/Id_low_limit'
   *  Inport: '<Root>/Id_up_limit'
   *  RelationalOperator: '<S33>/LowerRelop1'
   *  RelationalOperator: '<S33>/UpperRelop'
   *  Switch: '<S33>/Switch'
   */
  if (rtb_Subtract > FOC_U.Id_up_limit) {
    rtb_Subtract = FOC_U.Id_up_limit;
  } else if (rtb_Subtract < FOC_U.Id_low_limit) {
    /* Switch: '<S33>/Switch' incorporates:
     *  Inport: '<Root>/Id_low_limit'
     */
    rtb_Subtract = FOC_U.Id_low_limit;
  }

  FOC_Y.Id_refer = rtb_Subtract;

  /* End of Switch: '<S33>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S11>/Two phase CRL wrap' */
  /* Gain: '<S12>/one_by_sqrt3' incorporates:
   *  Inport: '<Root>/Phase Current'
   *  Sum: '<S12>/a_plus_2b'
   */
  rtb_Diff_j = ((FOC_U.PhaseCurrent[0] + FOC_U.PhaseCurrent[1]) +
                FOC_U.PhaseCurrent[1]) * 0.57735026918962584;

  /* End of Outputs for SubSystem: '<S11>/Two phase CRL wrap' */

  /* Trigonometry: '<S6>/Trigonometric Function' incorporates:
   *  Inport: '<Root>/angle'
   *  Trigonometry: '<S7>/Trigonometric Function1'
   */
  if (fnr.current_state == FORWARD)
  {
    FOC_U.angle = (FOC_U.angle);
    fnr.previous_state = fnr.current_state;
  }
  else if (fnr.current_state == REVERSE)
  {
    FOC_U.angle = (FOC_U.angle) - -3.14159274F;
    fnr.previous_state = fnr.current_state;
  }
  else if (fnr.current_state == NEUTRAL)
  {
    if (fnr.previous_state == FORWARD)
    {
      FOC_U.angle = (FOC_U.angle);
    }
    else if (fnr.previous_state == REVERSE)
    {
      FOC_U.angle = (FOC_U.angle) - -3.14159274F;
    }
  }

  rtb_E_expected = sin(FOC_U.angle);

  /* Trigonometry: '<S6>/Trigonometric Function1' incorporates:
   *  Inport: '<Root>/angle'
   *  Trigonometry: '<S7>/Trigonometric Function'
   */
  rtb_TrigonometricFunction1_tmp = cos(FOC_U.angle);

  /* Outputs for Atomic SubSystem: '<S10>/Two inputs CRL' */
  /* Outputs for Atomic SubSystem: '<S11>/Two phase CRL wrap' */
  /* Switch: '<S14>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   *  Inport: '<Root>/Phase Current'
   *  Product: '<S13>/acos'
   *  Product: '<S13>/bsin'
   *  Sum: '<S13>/sum_Ds'
   *  Trigonometry: '<S6>/Trigonometric Function'
   *  Trigonometry: '<S6>/Trigonometric Function1'
   */
  rtb_Switch_fv_idx_0 = FOC_U.PhaseCurrent[0] * rtb_TrigonometricFunction1_tmp +
    rtb_Diff_j * rtb_E_expected;

  /* Switch: '<S20>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   *  Inport: '<Root>/Phase Current'
   *  Product: '<S13>/asin'
   *  Product: '<S13>/bcos'
   *  Sum: '<S13>/sum_Qs'
   *  Switch: '<S14>/Switch'
   *  Trigonometry: '<S6>/Trigonometric Function'
   *  Trigonometry: '<S6>/Trigonometric Function1'
   */
  FOC_Y.Iq = rtb_Diff_j * rtb_TrigonometricFunction1_tmp - FOC_U.PhaseCurrent[0]
    * rtb_E_expected;

  /* End of Outputs for SubSystem: '<S11>/Two phase CRL wrap' */

  /* AlgorithmDescriptorDelegate generated from: '<S13>/a16' */
  FOC_Y.Id = rtb_Switch_fv_idx_0;

  /* Sum: '<S8>/Sum3' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
   */
  rtb_IProdOut_l = rtb_Subtract - rtb_Switch_fv_idx_0;

  /* End of Outputs for SubSystem: '<S10>/Two inputs CRL' */

  /* Product: '<S131>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S123>/Filter'
   *  Inport: '<Root>/Filter_flux_PID'
   *  Inport: '<Root>/Kd_flux_PID'
   *  Product: '<S121>/DProd Out'
   *  Sum: '<S123>/SumD'
   */
  rtb_NProdOut_b = (rtb_IProdOut_l * FOC_U.Kd_flux_PID - FOC_DW.Filter_DSTATE_k)
    * FOC_U.Filter_flux_PID;

  /* Sum: '<S138>/Sum' incorporates:
   *  DiscreteIntegrator: '<S128>/Integrator'
   *  Inport: '<Root>/Kp_flux_PID'
   *  Product: '<S133>/PProd Out'
   */
  rtb_Sum_ep = (rtb_IProdOut_l * FOC_U.Kp_flux_PID + FOC_DW.Integrator_DSTATE_p)
    + rtb_NProdOut_b;

  /* Sqrt: '<S31>/Sqrt1' incorporates:
   *  Abs: '<S31>/Abs'
   *  Math: '<S31>/Math Function3'
   *  Sum: '<S31>/Subtract1'
   *
   * About '<S31>/Math Function3':
   *  Operator: magnitude^2
   */
  rtb_Divide = sqrt(fabs(rtb_Divide - rtb_Subtract * rtb_Subtract));

  /* Gain: '<S204>/wm_pu2si_mech2elec' incorporates:
   *  Gain: '<S8>/Gain'
   *  Inport: '<Root>/Actual Speed'
   */
  rtb_Integrator_d = 0.33333333333333331 * FOC_U.ActualSpeed * 3.0;

  /* Gain: '<S204>/NegSign' incorporates:
   *  Product: '<S204>/prod1'
   */
  rtb_VdFF_unsat = -(FOC_ConstB.Switch1 * rtb_Divide * rtb_Integrator_d);

  /* Switch: '<S136>/Switch2' incorporates:
   *  Inport: '<Root>/Low_Limit_flux_PID'
   *  Inport: '<Root>/Up_Limit_flux_PID'
   *  RelationalOperator: '<S136>/LowerRelop1'
   *  RelationalOperator: '<S136>/UpperRelop'
   *  Switch: '<S136>/Switch'
   */
  if (rtb_Sum_ep > FOC_U.Up_Limit_flux_PID) {
    rtb_Diff_j = FOC_U.Up_Limit_flux_PID;
  } else if (rtb_Sum_ep < FOC_U.Low_Limit_flux_PID) {
    /* Switch: '<S136>/Switch' incorporates:
     *  Inport: '<Root>/Low_Limit_flux_PID'
     */
    rtb_Diff_j = FOC_U.Low_Limit_flux_PID;
  } else {
    rtb_Diff_j = rtb_Sum_ep;
  }

  /* Switch: '<S206>/Switch2' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   *  RelationalOperator: '<S206>/LowerRelop1'
   *  RelationalOperator: '<S206>/UpperRelop'
   *  Switch: '<S206>/Switch'
   *  UnaryMinus: '<S204>/Unary Minus'
   */
  if (rtb_VdFF_unsat > FOC_U.BusVoltage_V) {
    rtb_VdFF_unsat = FOC_U.BusVoltage_V;
  } else if (rtb_VdFF_unsat < -FOC_U.BusVoltage_V) {
    /* Switch: '<S206>/Switch' incorporates:
     *  UnaryMinus: '<S204>/Unary Minus'
     */
    rtb_VdFF_unsat = -FOC_U.BusVoltage_V;
  }

  /* Sum: '<S8>/Sum' incorporates:
   *  Switch: '<S136>/Switch2'
   *  Switch: '<S206>/Switch2'
   */
  FOC_Y.Vd = rtb_Diff_j + rtb_VdFF_unsat;

  /* Product: '<S204>/prod2' incorporates:
   *  Product: '<S204>/prod3'
   *  Sum: '<S204>/add1'
   */
  rtb_Subtract = (FOC_ConstB.Switch * rtb_Subtract + FOC_ConstB.Switch2) *
    rtb_Integrator_d;

  /* Outputs for Atomic SubSystem: '<S10>/Two inputs CRL' */
  /* Sum: '<S8>/Sum2' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
   */
  rtb_Divide -= FOC_Y.Iq;

  /* End of Outputs for SubSystem: '<S10>/Two inputs CRL' */

  /* Product: '<S187>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S179>/Filter'
   *  Inport: '<Root>/Filter_torque_PID'
   *  Inport: '<Root>/Kd_torque_PID'
   *  Product: '<S177>/DProd Out'
   *  Sum: '<S179>/SumD'
   */
  rtb_Integrator_d = (rtb_Divide * FOC_U.Kd_torque_PID - FOC_DW.Filter_DSTATE_d)
    * FOC_U.Filter_torque_PID;

  /* Sum: '<S194>/Sum' incorporates:
   *  DiscreteIntegrator: '<S184>/Integrator'
   *  Inport: '<Root>/Kp_torque_PID'
   *  Product: '<S189>/PProd Out'
   */
  rtb_VdFF_unsat = (rtb_Divide * FOC_U.Kp_torque_PID +
                    FOC_DW.Integrator_DSTATE_h) + rtb_Integrator_d;

  /* Switch: '<S207>/Switch2' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   *  RelationalOperator: '<S207>/LowerRelop1'
   *  RelationalOperator: '<S207>/UpperRelop'
   *  Switch: '<S207>/Switch'
   *  UnaryMinus: '<S204>/Unary Minus'
   */
  if (rtb_Subtract > FOC_U.BusVoltage_V) {
    rtb_Subtract = FOC_U.BusVoltage_V;
  } else if (rtb_Subtract < -FOC_U.BusVoltage_V) {
    /* Switch: '<S207>/Switch' incorporates:
     *  UnaryMinus: '<S204>/Unary Minus'
     */
    rtb_Subtract = -FOC_U.BusVoltage_V;
  }

  /* Switch: '<S192>/Switch2' incorporates:
   *  Inport: '<Root>/Low_Limit_torque_PID'
   *  Inport: '<Root>/Up_Limit_torque_PID'
   *  RelationalOperator: '<S192>/LowerRelop1'
   *  RelationalOperator: '<S192>/UpperRelop'
   *  Switch: '<S192>/Switch'
   */
  if (rtb_VdFF_unsat > FOC_U.Up_Limit_torque_PID) {
    rtb_Diff_j = FOC_U.Up_Limit_torque_PID;
  } else if (rtb_VdFF_unsat < FOC_U.Low_Limit_torque_PID) {
    /* Switch: '<S192>/Switch' incorporates:
     *  Inport: '<Root>/Low_Limit_torque_PID'
     */
    rtb_Diff_j = FOC_U.Low_Limit_torque_PID;
  } else {
    rtb_Diff_j = rtb_VdFF_unsat;
  }

  /* Sum: '<S8>/Sum4' incorporates:
   *  Switch: '<S192>/Switch2'
   *  Switch: '<S207>/Switch2'
   */
  FOC_Y.Vq = rtb_Subtract + rtb_Diff_j;

  real_T Vq_ref_max = sqrtf((61.0f*61.0f) - (FOC_Y.Vd * FOC_Y.Vd));

  if (FOC_Y.Vq > Vq_ref_max)
    FOC_Y.Vq = Vq_ref_max;

  /* Outputs for Atomic SubSystem: '<S16>/Two inputs CRL' */
  /* Switch: '<S20>/Switch' incorporates:
   *  Product: '<S19>/dcos'
   *  Product: '<S19>/qsin'
   *  Sum: '<S19>/sum_alpha'
   */
  rtb_Switch_fv_idx_0 = FOC_Y.Vd * rtb_TrigonometricFunction1_tmp - FOC_Y.Vq *
    rtb_E_expected;

  /* Gain: '<S18>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S19>/a16'
   */
  rtb_add_c = 0.5 * rtb_Switch_fv_idx_0;

  /* Gain: '<S18>/sqrt3_by_two' incorporates:
   *  Product: '<S19>/dsin'
   *  Product: '<S19>/qcos'
   *  Sum: '<S19>/sum_beta'
   */
  rtb_Subtract = (FOC_Y.Vq * rtb_TrigonometricFunction1_tmp + FOC_Y.Vd *
                  rtb_E_expected) * 0.8660254037844386;

  /* End of Outputs for SubSystem: '<S16>/Two inputs CRL' */

  /* Sum: '<S18>/add_b' */
  rtb_E_expected = rtb_Subtract - rtb_add_c;

  /* Sum: '<S18>/add_c' */
  rtb_add_c = (0.0 - rtb_add_c) - rtb_Subtract;

  /* Outputs for Atomic SubSystem: '<S16>/Two inputs CRL' */
  /* Gain: '<S24>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S19>/a16'
   *  MinMax: '<S24>/Max'
   *  MinMax: '<S24>/Min'
   *  Sum: '<S24>/Add'
   */
  rtb_Diff_j = (fmax(fmax(rtb_Switch_fv_idx_0, rtb_E_expected), rtb_add_c) +
                fmin(fmin(rtb_Switch_fv_idx_0, rtb_E_expected), rtb_add_c)) *
    -0.5;

  /* Gain: '<S23>/Gain' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S19>/a16'
   *  Sum: '<S23>/Add1'
   *  Sum: '<S23>/Add2'
   *  Sum: '<S23>/Add3'
   */
  FOC_Y.Va = (rtb_Switch_fv_idx_0 + rtb_Diff_j) * 1.1547005383792517;

  /* End of Outputs for SubSystem: '<S16>/Two inputs CRL' */
  FOC_Y.Vb = (rtb_E_expected + rtb_Diff_j) * 1.1547005383792517;
  FOC_Y.Vc = (rtb_Diff_j + rtb_add_c) * 1.1547005383792517;

  /* MinMax: '<S4>/Max1' */
  FOC_B.Max1 = fmax(fmax(FOC_Y.Va, FOC_Y.Vb), FOC_Y.Vc);

  /* MinMax: '<S4>/Max2' incorporates:
   *  Inport: '<Root>/MCTemperature_C'
   *  Inport: '<Root>/MotorTemperature_C'
   */
  rtb_Divide1 = fmaxf(FOC_U.MCTemperature_C, FOC_U.MotorTemperature_C);

  /* MinMax: '<S4>/Max' incorporates:
   *  Inport: '<Root>/Phase Current'
   */
  rtb_Subtract = fmax(fmax(FOC_U.PhaseCurrent[0], FOC_U.PhaseCurrent[1]),
                      FOC_U.PhaseCurrent[2]);

  /* BusCreator generated from: '<S4>/Protection_States' */
  FOC_B.BusConversion_InsertedFor_Prote.MaxCurrentLimit_A =
    FOC_ConstB.MaxCurrentLimit_A;
  FOC_B.BusConversion_InsertedFor_Prote.OTWarningLimit_C =
    FOC_ConstB.OTWarningLimit_C;
  FOC_B.BusConversion_InsertedFor_Prote.OTErrorLimit_C =
    FOC_ConstB.OTErrorLimit_C;
  FOC_B.BusConversion_InsertedFor_Prote.UVWarningLimit_V =
    FOC_ConstB.UVWarningLimit_V;
  FOC_B.BusConversion_InsertedFor_Prote.UVErrorLimit_V =
    FOC_ConstB.UVErrorLimit_V;
  FOC_B.BusConversion_InsertedFor_Prote.OVWarningLimit_V =
    FOC_ConstB.OVWarningLimit_V;
  FOC_B.BusConversion_InsertedFor_Prote.OVErrorLimit_V =
    FOC_ConstB.OVErrorLimit_V;
  FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A =
    FOC_ConstB.OCWarningLimit_A;
  FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A =
    FOC_ConstB.OCErrorLimit_A;
  FOC_B.BusConversion_InsertedFor_Prote.WarningSpeedLimit_rpm =
    FOC_ConstB.WarningSpeedLimit_rpm;
  FOC_B.BusConversion_InsertedFor_Prote.VoltageProtectionTimeout_msec =
    FOC_ConstB.VoltageProtectionTimeout_ms;
  FOC_B.BusConversion_InsertedFor_Prote.TempProtectionTimeout_msec =
    FOC_ConstB.TempProtectionTimeout_msec;
  FOC_B.BusConversion_InsertedFor_Prote.CurrentProtectionTimeout_msec =
    FOC_ConstB.CurrentProtectionTimeout_ms;

  /* Chart: '<S4>/Protection_States' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   */
  if (FOC_DW.is_active_c7_FOC == 0) {
    FOC_DW.is_active_c7_FOC = 1U;
    FOC_DW.durationCounter_1 = 0U;
    FOC_DW.is_TemperatureProtection = FOC_IN_TempSafe;

    /* Outport: '<Root>/TempFlag' */
    FOC_Y.TempFlag = SafeTemperature;
    FOC_DW.durationCounter_2_c0 = 0U;
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
      if (!(rtb_Divide1 < FOC_B.BusConversion_InsertedFor_Prote.OTWarningLimit_C))
      {
        FOC_DW.durationCounter_1_c = 0U;
      }

      rtb_Diff_j =
        FOC_B.BusConversion_InsertedFor_Prote.TempProtectionTimeout_msec *
        100.0F;
      if (FOC_DW.durationCounter_1_c > rtb_Diff_j) {
        FOC_DW.durationCounter_1 = 0U;
        FOC_DW.is_TemperatureProtection = FOC_IN_TempSafe;

        /* Outport: '<Root>/TempFlag' */
        FOC_Y.TempFlag = SafeTemperature;
      } else {
        if (!(rtb_Divide1 < FOC_B.BusConversion_InsertedFor_Prote.OTErrorLimit_C))
        {
          FOC_DW.durationCounter_2 = 0U;
        }

        if (FOC_DW.durationCounter_2 > rtb_Diff_j) {
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
      if (!(rtb_Divide1 > FOC_B.BusConversion_InsertedFor_Prote.OTErrorLimit_C))
      {
        FOC_DW.durationCounter_2_e = 0U;
      }

      rtb_Diff_j =
        FOC_B.BusConversion_InsertedFor_Prote.TempProtectionTimeout_msec *
        100.0F;
      if (FOC_DW.durationCounter_2_e > rtb_Diff_j) {
        FOC_DW.durationCounter_2 = 0U;
        FOC_DW.durationCounter_1_c = 0U;
        FOC_DW.is_TemperatureProtection = FOC_IN_HighTempError;

        /* Outport: '<Root>/TempFlag' */
        FOC_Y.TempFlag = OT_Error;
      } else {
        if (!(rtb_Divide1 <
              FOC_B.BusConversion_InsertedFor_Prote.OTWarningLimit_C)) {
          FOC_DW.durationCounter_1_e = 0U;
        }

        if (FOC_DW.durationCounter_1_e > rtb_Diff_j) {
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
      if (!(rtb_Divide1 > FOC_B.BusConversion_InsertedFor_Prote.OTWarningLimit_C))
      {
        FOC_DW.durationCounter_1 = 0U;
      }

      if ((real_T)FOC_DW.durationCounter_1 >
          FOC_B.BusConversion_InsertedFor_Prote.TempProtectionTimeout_msec *
          100.0F) {
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
      if (!(rtb_Subtract >
            FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A)) {
        FOC_DW.durationCounter_1_i = 0U;
      }

      if ((real_T)FOC_DW.durationCounter_1_i >
          FOC_B.BusConversion_InsertedFor_Prote.CurrentProtectionTimeout_msec *
          100.0F) {
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
      if (!(rtb_Subtract <
            FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A)) {
        FOC_DW.durationCounter_1_a = 0U;
      }

      rtb_Diff_j =
        FOC_B.BusConversion_InsertedFor_Prote.CurrentProtectionTimeout_msec *
        100.0F;
      if (FOC_DW.durationCounter_1_a > rtb_Diff_j) {
        FOC_DW.durationCounter_1_i = 0U;
        FOC_DW.is_CurrentProtection = FOC_IN_CurrentSafe;

        /* Outport: '<Root>/CurrentFlag' */
        FOC_Y.CurrentFlag = SafeCurrent;
      } else {
        if (!(rtb_Subtract <
              FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A)) {
          FOC_DW.durationCounter_2_b = 0U;
        }

        if (FOC_DW.durationCounter_2_b > rtb_Diff_j) {
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
      if (!(rtb_Subtract > FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A))
      {
        FOC_DW.durationCounter_2_c = 0U;
      }

      rtb_Diff_j =
        FOC_B.BusConversion_InsertedFor_Prote.CurrentProtectionTimeout_msec *
        100.0F;
      if (FOC_DW.durationCounter_2_c > rtb_Diff_j) {
        FOC_DW.durationCounter_2_b = 0U;
        FOC_DW.durationCounter_1_a = 0U;
        FOC_DW.is_CurrentProtection = FOC_IN_OC_Error;

        /* Outport: '<Root>/CurrentFlag' */
        FOC_Y.CurrentFlag = OC_Error;
      } else {
        if (!(rtb_Subtract <
              FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A)) {
          FOC_DW.durationCounter_1_d = 0U;
        }

        if (FOC_DW.durationCounter_1_d > rtb_Diff_j) {
          FOC_DW.durationCounter_1_i = 0U;
          FOC_DW.is_CurrentProtection = FOC_IN_CurrentSafe;

          /* Outport: '<Root>/CurrentFlag' */
          FOC_Y.CurrentFlag = SafeCurrent;
        }
      }
      break;
    }
  }

  if (rtb_Divide1 > FOC_B.BusConversion_InsertedFor_Prote.OTWarningLimit_C) {
    FOC_DW.durationCounter_1++;
  } else {
    FOC_DW.durationCounter_1 = 0U;
  }

  if (rtb_Divide1 < FOC_B.BusConversion_InsertedFor_Prote.OTWarningLimit_C) {
    FOC_DW.durationCounter_1_c++;
    FOC_DW.durationCounter_1_e++;
  } else {
    FOC_DW.durationCounter_1_c = 0U;
    FOC_DW.durationCounter_1_e = 0U;
  }

  if (rtb_Divide1 < FOC_B.BusConversion_InsertedFor_Prote.OTErrorLimit_C) {
    FOC_DW.durationCounter_2++;
  } else {
    FOC_DW.durationCounter_2 = 0U;
  }

  if (rtb_Divide1 > FOC_B.BusConversion_InsertedFor_Prote.OTErrorLimit_C) {
    FOC_DW.durationCounter_2_e++;
  } else {
    FOC_DW.durationCounter_2_e = 0U;
  }

  if (rtb_Subtract > FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A) {
    FOC_DW.durationCounter_1_i++;
  } else {
    FOC_DW.durationCounter_1_i = 0U;
  }

  if (rtb_Subtract < FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A) {
    FOC_DW.durationCounter_1_a++;
    FOC_DW.durationCounter_1_d++;
  } else {
    FOC_DW.durationCounter_1_a = 0U;
    FOC_DW.durationCounter_1_d = 0U;
  }

  if (rtb_Subtract < FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A) {
    FOC_DW.durationCounter_2_b++;
  } else {
    FOC_DW.durationCounter_2_b = 0U;
  }

  if (rtb_Subtract > FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A) {
    FOC_DW.durationCounter_2_c++;
  } else {
    FOC_DW.durationCounter_2_c = 0U;
  }

  if (FOC_U.BusVoltage_V > FOC_B.BusConversion_InsertedFor_Prote.UVErrorLimit_V)
  {
    FOC_DW.durationCounter_1_e3++;
  } else {
    FOC_DW.durationCounter_1_e3 = 0U;
  }

  if (FOC_U.BusVoltage_V < FOC_B.BusConversion_InsertedFor_Prote.UVErrorLimit_V)
  {
    FOC_DW.durationCounter_1_o++;
  } else {
    FOC_DW.durationCounter_1_o = 0U;
  }

  if (FOC_U.BusVoltage_V <
      FOC_B.BusConversion_InsertedFor_Prote.UVWarningLimit_V) {
    FOC_DW.durationCounter_1_h++;
  } else {
    FOC_DW.durationCounter_1_h = 0U;
  }

  if (FOC_U.BusVoltage_V >
      FOC_B.BusConversion_InsertedFor_Prote.UVWarningLimit_V) {
    FOC_DW.durationCounter_2_k++;
    FOC_DW.durationCounter_2_n++;
  } else {
    FOC_DW.durationCounter_2_k = 0U;
    FOC_DW.durationCounter_2_n = 0U;
  }

  rtb_Divide1 = (real32_T)((FOC_B.Max1 != 0.0) || (FOC_U.BusVoltage_V != 0.0F));
  if (rtb_Divide1 > FOC_B.BusConversion_InsertedFor_Prote.OVWarningLimit_V) {
    FOC_DW.durationCounter_2_c0++;
  } else {
    FOC_DW.durationCounter_2_c0 = 0U;
  }

  if (rtb_Divide1 < FOC_B.BusConversion_InsertedFor_Prote.OVWarningLimit_V) {
    FOC_DW.durationCounter_1_m++;
    FOC_DW.durationCounter_1_f++;
  } else {
    FOC_DW.durationCounter_1_m = 0U;
    FOC_DW.durationCounter_1_f = 0U;
  }

  if (rtb_Divide1 < FOC_B.BusConversion_InsertedFor_Prote.OVErrorLimit_V) {
    FOC_DW.durationCounter_2_d++;
  } else {
    FOC_DW.durationCounter_2_d = 0U;
  }

  if (rtb_Divide1 > FOC_B.BusConversion_InsertedFor_Prote.OVErrorLimit_V) {
    FOC_DW.durationCounter_2_bq++;
  } else {
    FOC_DW.durationCounter_2_bq = 0U;
  }

  /* End of Chart: '<S4>/Protection_States' */

  /* Outputs for Atomic SubSystem: '<S10>/Two inputs CRL' */
  /* SampleTimeMath: '<S211>/TSamp' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
   *  Inport: '<Root>/Lq'
   *  Product: '<S209>/Product1'
   *
   * About '<S211>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_Subtract = FOC_U.Lq * FOC_Y.Iq * 7123.0f;

  /* End of Outputs for SubSystem: '<S10>/Two inputs CRL' */

  /* SampleTimeMath: '<S210>/TSamp' incorporates:
   *  Inport: '<Root>/Lamda'
   *  Inport: '<Root>/Ld'
   *  Product: '<S209>/Product'
   *  Sum: '<S209>/Add'
   *
   * About '<S210>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_E_expected = (FOC_U.Ld * FOC_Y.Id + FOC_U.Lamda) * 7123.0f;

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/Actual Speed'
   */
  if (FOC_U.ActualSpeed > 0.0) {
    rtb_Diff_j = FOC_U.ActualSpeed;
  } else {
    rtb_Diff_j = 0.12;
  }

  /* Outputs for Atomic SubSystem: '<S10>/Two inputs CRL' */
  /* Product: '<S3>/Divide' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S13>/a16'
   *  Gain: '<S208>/Gain'
   *  Inport: '<Root>/Lamda'
   *  Inport: '<Root>/Rs'
   *  Inport: '<Root>/p'
   *  Math: '<S209>/Hypot'
   *  Product: '<S208>/Product'
   *  Product: '<S209>/Product2'
   *  Product: '<S209>/Product3'
   *  Sum: '<S209>/Add1'
   *  Sum: '<S209>/Add2'
   *  Sum: '<S210>/Diff'
   *  Sum: '<S211>/Diff'
   *  Switch: '<S3>/Switch'
   *  UnitDelay: '<S210>/UD'
   *  UnitDelay: '<S211>/UD'
   */
  rtb_Diff_j = (1.0 / (0.33333333333333331 * rtb_Diff_j * FOC_U.p * FOC_U.Lamda)) *
    rt_hypotd_snf((FOC_Y.Vd - (rtb_E_expected - FOC_DW.UD_DSTATE_e)) - FOC_U.Rs *
                  FOC_Y.Id, (FOC_Y.Vq - (rtb_Subtract - FOC_DW.UD_DSTATE)) -
                  FOC_U.Rs * FOC_Y.Iq);

  /* End of Outputs for SubSystem: '<S10>/Two inputs CRL' */

  /* Trigonometry: '<S3>/Cos' */
  if (rtb_Diff_j > 1.0) {
    rtb_Diff_j = 1.0;
  } else if (rtb_Diff_j < -1.0) {
    rtb_Diff_j = -1.0;
  }

  /* Outport: '<Root>/Offset_angle' incorporates:
   *  Trigonometry: '<S3>/Cos'
   */
  FOC_Y.Offset_angle = acos(rtb_Diff_j);

  /* Switch: '<S176>/Switch' incorporates:
   *  Inport: '<Root>/Low_Limit_torque_PID'
   *  Inport: '<Root>/Up_Limit_torque_PID'
   *  RelationalOperator: '<S176>/u_GTE_up'
   *  RelationalOperator: '<S176>/u_GT_lo'
   *  Switch: '<S176>/Switch1'
   */
  if (rtb_VdFF_unsat >= FOC_U.Up_Limit_torque_PID) {
    rtb_Diff_j = FOC_U.Up_Limit_torque_PID;
  } else if (rtb_VdFF_unsat > FOC_U.Low_Limit_torque_PID) {
    /* Switch: '<S176>/Switch1' */
    rtb_Diff_j = rtb_VdFF_unsat;
  } else {
    rtb_Diff_j = FOC_U.Low_Limit_torque_PID;
  }

  /* Sum: '<S176>/Diff' incorporates:
   *  Switch: '<S176>/Switch'
   */
  rtb_Diff_j = rtb_VdFF_unsat - rtb_Diff_j;

  /* Product: '<S181>/IProd Out' incorporates:
   *  Inport: '<Root>/Ki_torque_PID'
   */
  rtb_Divide *= FOC_U.Ki_torque_PID;

  /* Switch: '<S173>/Switch1' incorporates:
   *  Constant: '<S173>/Clamping_zero'
   *  Constant: '<S173>/Constant'
   *  Constant: '<S173>/Constant2'
   *  RelationalOperator: '<S173>/fix for DT propagation issue'
   */
  if (rtb_Diff_j > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S173>/Switch2' incorporates:
   *  Constant: '<S173>/Clamping_zero'
   *  Constant: '<S173>/Constant3'
   *  Constant: '<S173>/Constant4'
   *  RelationalOperator: '<S173>/fix for DT propagation issue1'
   */
  if (rtb_Divide > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Logic: '<S173>/AND3' incorporates:
   *  Constant: '<S173>/Clamping_zero'
   *  RelationalOperator: '<S173>/Equal1'
   *  RelationalOperator: '<S173>/Relational Operator'
   *  Switch: '<S173>/Switch1'
   *  Switch: '<S173>/Switch2'
   */
  rtb_AND3 = ((rtb_Diff_j != 0.0) && (tmp == tmp_0));

  /* Switch: '<S120>/Switch' incorporates:
   *  Inport: '<Root>/Low_Limit_flux_PID'
   *  Inport: '<Root>/Up_Limit_flux_PID'
   *  RelationalOperator: '<S120>/u_GTE_up'
   *  RelationalOperator: '<S120>/u_GT_lo'
   *  Switch: '<S120>/Switch1'
   */
  if (rtb_Sum_ep >= FOC_U.Up_Limit_flux_PID) {
    rtb_Diff_j = FOC_U.Up_Limit_flux_PID;
  } else if (rtb_Sum_ep > FOC_U.Low_Limit_flux_PID) {
    /* Switch: '<S120>/Switch1' */
    rtb_Diff_j = rtb_Sum_ep;
  } else {
    rtb_Diff_j = FOC_U.Low_Limit_flux_PID;
  }

  /* Sum: '<S120>/Diff' incorporates:
   *  Switch: '<S120>/Switch'
   */
  rtb_Diff_j = rtb_Sum_ep - rtb_Diff_j;

  /* Product: '<S125>/IProd Out' incorporates:
   *  Inport: '<Root>/Ki_flux_PID'
   */
  rtb_IProdOut_l *= FOC_U.Ki_flux_PID;

  /* Switch: '<S117>/Switch1' incorporates:
   *  Constant: '<S117>/Clamping_zero'
   *  Constant: '<S117>/Constant'
   *  Constant: '<S117>/Constant2'
   *  RelationalOperator: '<S117>/fix for DT propagation issue'
   */
  if (rtb_Diff_j > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S117>/Switch2' incorporates:
   *  Constant: '<S117>/Clamping_zero'
   *  Constant: '<S117>/Constant3'
   *  Constant: '<S117>/Constant4'
   *  RelationalOperator: '<S117>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_l > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Logic: '<S117>/AND3' incorporates:
   *  Constant: '<S117>/Clamping_zero'
   *  RelationalOperator: '<S117>/Equal1'
   *  RelationalOperator: '<S117>/Relational Operator'
   *  Switch: '<S117>/Switch1'
   *  Switch: '<S117>/Switch2'
   */
  rtb_AND3_g = ((rtb_Diff_j != 0.0) && (tmp == tmp_0));

  /* Switch: '<S64>/Switch' incorporates:
   *  Inport: '<Root>/Low_Limit_speed_PID'
   *  Inport: '<Root>/Up_Limit_speed_PID'
   *  RelationalOperator: '<S64>/u_GTE_up'
   *  RelationalOperator: '<S64>/u_GT_lo'
   *  Switch: '<S64>/Switch1'
   */
  if (rtb_Sum >= FOC_U.Up_Limit_speed_PID) {
    rtb_Diff_j = FOC_U.Up_Limit_speed_PID;
  } else if (rtb_Sum > FOC_U.Low_Limit_speed_PID) {
    /* Switch: '<S64>/Switch1' */
    rtb_Diff_j = rtb_Sum;
  } else {
    rtb_Diff_j = FOC_U.Low_Limit_speed_PID;
  }

  /* Sum: '<S64>/Diff' incorporates:
   *  Switch: '<S64>/Switch'
   */
  rtb_Diff_j = rtb_Sum - rtb_Diff_j;

  /* Product: '<S69>/IProd Out' incorporates:
   *  Inport: '<Root>/Ki_speed_PID'
   */
  rtb_IProdOut *= FOC_U.Ki_speed_PID;

  /* Switch: '<S61>/Switch1' incorporates:
   *  Constant: '<S61>/Clamping_zero'
   *  Constant: '<S61>/Constant'
   *  Constant: '<S61>/Constant2'
   *  RelationalOperator: '<S61>/fix for DT propagation issue'
   */
  if (rtb_Diff_j > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S61>/Switch2' incorporates:
   *  Constant: '<S61>/Clamping_zero'
   *  Constant: '<S61>/Constant3'
   *  Constant: '<S61>/Constant4'
   *  RelationalOperator: '<S61>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S61>/Switch' incorporates:
   *  Constant: '<S61>/Clamping_zero'
   *  Constant: '<S61>/Constant1'
   *  Logic: '<S61>/AND3'
   *  RelationalOperator: '<S61>/Equal1'
   *  RelationalOperator: '<S61>/Relational Operator'
   *  Switch: '<S61>/Switch1'
   *  Switch: '<S61>/Switch2'
   */
  if ((rtb_Diff_j != 0.0) && (tmp == tmp_0)) {
    rtb_IProdOut = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S72>/Integrator' incorporates:
   *  Switch: '<S61>/Switch'
   */
  FOC_DW.Integrator_DSTATE += 1.0E-5 * rtb_IProdOut;

  /* Update for DiscreteIntegrator: '<S67>/Filter' */
  FOC_DW.Filter_DSTATE += 1.0E-5 * rtb_NProdOut;

  /* Switch: '<S117>/Switch' incorporates:
   *  Constant: '<S117>/Constant1'
   */
  if (rtb_AND3_g) {
    rtb_IProdOut_l = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S128>/Integrator' incorporates:
   *  Switch: '<S117>/Switch'
   */
  FOC_DW.Integrator_DSTATE_p += 1.0E-5 * rtb_IProdOut_l;

  /* Update for DiscreteIntegrator: '<S123>/Filter' */
  FOC_DW.Filter_DSTATE_k += 1.0E-5 * rtb_NProdOut_b;

  /* Switch: '<S173>/Switch' incorporates:
   *  Constant: '<S173>/Constant1'
   */
  if (rtb_AND3) {
    rtb_Divide = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S184>/Integrator' incorporates:
   *  Switch: '<S173>/Switch'
   */
  FOC_DW.Integrator_DSTATE_h += 1.0E-5 * rtb_Divide;

  /* Update for DiscreteIntegrator: '<S179>/Filter' */
  FOC_DW.Filter_DSTATE_d += 1.0E-5 * rtb_Integrator_d;

  /* Update for UnitDelay: '<S211>/UD' */
  FOC_DW.UD_DSTATE = rtb_Subtract;

  /* Update for UnitDelay: '<S210>/UD' */
  FOC_DW.UD_DSTATE_e = rtb_E_expected;
}

/* Model initialize function */
void FOC_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(FOC_M, (NULL));

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

  /* InitializeConditions for DiscreteIntegrator: '<S72>/Integrator' */
  FOC_DW.Integrator_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S67>/Filter' */
  FOC_DW.Filter_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S128>/Integrator' */
  FOC_DW.Integrator_DSTATE_p = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S123>/Filter' */
  FOC_DW.Filter_DSTATE_k = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S184>/Integrator' */
  FOC_DW.Integrator_DSTATE_h = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S179>/Filter' */
  FOC_DW.Filter_DSTATE_d = 0.0;

  /* InitializeConditions for UnitDelay: '<S211>/UD' */
  FOC_DW.UD_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S210>/UD' */
  FOC_DW.UD_DSTATE_e = 1.0E-6;

  /* SystemInitialize for Outport: '<Root>/CurrentFlag' incorporates:
   *  Chart: '<S4>/Protection_States'
   */
  FOC_Y.CurrentFlag = SafeCurrent;

  /* SystemInitialize for Outport: '<Root>/VoltageFlag' incorporates:
   *  Chart: '<S4>/Protection_States'
   */
  FOC_Y.VoltageFlag = SafeVoltage;

  /* SystemInitialize for Outport: '<Root>/TempFlag' incorporates:
   *  Chart: '<S4>/Protection_States'
   */
  FOC_Y.TempFlag = SafeTemperature;

  /* SystemInitialize for Chart: '<S4>/Protection_States' */
  FOC_DW.is_active_c7_FOC = 0U;
  FOC_DW.is_TemperatureProtection = FOC_IN_NO_ACTIVE_CHILD;
  FOC_DW.is_VoltageProtection = FOC_IN_NO_ACTIVE_CHILD;
  FOC_DW.is_CurrentProtection = FOC_IN_NO_ACTIVE_CHILD;

  FOC_U.Lq = 0.000387;
  FOC_U.Ld = 0.000147;
  FOC_U.Lamda = 0.0263;
  FOC_U.Rs = 0.0107;
  FOC_U.p = POLEPAIRS;

  FOC_U.Id_up_limit = 0.0f;
  FOC_U.Id_low_limit = -15.0f;
  FOC_U.Iq_up_limit = 280.0f;
  FOC_U.Iq_low_limit = 0.0f;

  #if PEG4W
  FOC_U.Kp_speed_PID = 4.0;
  FOC_U.Ki_speed_PID = 15.0;
  FOC_U.Kd_speed_PID = 0.001;
  FOC_U.Filter_speed_PID = 2;
  FOC_U.Up_Limit_speed_PID = 550.0;
  FOC_U.Low_Limit_speed_PID = 0.0;

  FOC_U.Kp_flux_PID = 0.12;
  FOC_U.Ki_flux_PID = 16.0;
  FOC_U.Kd_flux_PID = 0.001;
  FOC_U.Filter_flux_PID = 2.0;
  FOC_U.Up_Limit_flux_PID = 61.0;
  FOC_U.Low_Limit_flux_PID = -61.0;

  FOC_U.Kp_torque_PID = 0.12;
  FOC_U.Ki_torque_PID = 8.0;
  FOC_U.Kd_torque_PID = 0.001;
  FOC_U.Filter_torque_PID = 2.0;
  FOC_U.Up_Limit_torque_PID = 61.0;
  FOC_U.Low_Limit_torque_PID = -61.0;
  #endif

  #if PEG3W
  FOC_U.I_max = 250.0f;

  FOC_U.Kp_speed_PID = 4.0;
  FOC_U.Ki_speed_PID = 20.0;
  FOC_U.Kd_speed_PID = 0.01;
  FOC_U.Filter_speed_PID = 2;
  FOC_U.Up_Limit_speed_PID = 250.0;
  FOC_U.Low_Limit_speed_PID = 0.0;

  FOC_U.Kp_flux_PID = 0.8;
  FOC_U.Ki_flux_PID = 30.0;
  FOC_U.Kd_flux_PID = 0.01;
  FOC_U.Filter_flux_PID = 2.0;
  FOC_U.Up_Limit_flux_PID = 61.0;
  FOC_U.Low_Limit_flux_PID = -61.0;

  FOC_U.Kp_torque_PID = 0.7;
  FOC_U.Ki_torque_PID = 22.0;
  FOC_U.Kd_torque_PID = 0.01;
  FOC_U.Filter_torque_PID = 2.0;
  FOC_U.Up_Limit_torque_PID = 61.0;
  FOC_U.Low_Limit_torque_PID = -61.0;
  #endif

  fnr.current_state = NEUTRAL;
  fnr.previous_state = FORWARD;
  fnr.throttle_disabled = 1;

  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
}

/* Model terminate function */
void FOC_terminate(void)
{
  /* (no terminate code required) */
}
#endif

#if TORQUE_MODE
/*
 * FOC.c
 *
 * Code generation for model "FOC".
 *
 * Model version              : 18.37
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Dec 13 13:25:35 2024
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
#include "vector_control.h"
#include "main.h"
#include "motor_param.h"
#include <math.h>
#include <string.h>

/* Named constants for Chart: '<S3>/Protection_States' */
#define FOC_IN_CurrentSafe             ((uint8_T)1U)
#define FOC_IN_HighTempError           ((uint8_T)1U)
#define FOC_IN_HighTempWarning         ((uint8_T)2U)
#define FOC_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define FOC_IN_OC_Error                ((uint8_T)2U)
#define FOC_IN_OC_Warning              ((uint8_T)3U)
#define FOC_IN_OV_Error                ((uint8_T)1U)
#define FOC_IN_OV_Warning              ((uint8_T)2U)
#define FOC_IN_TempSafe                ((uint8_T)3U)
#define FOC_IN_UV_Error                ((uint8_T)3U)
#define FOC_IN_UV_Warning              ((uint8_T)4U)
#define FOC_IN_VoltageSafe             ((uint8_T)5U)

/* Block signals (default storage) */
B_FOC_T FOC_B;

/* Block states (default storage) */
DW_FOC_T FOC_DW;

/* External inputs (root inport signals with default storage) */
ExtU_FOC_T FOC_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FOC_T FOC_Y;

FOC_Flag_T FOC_F_T;

const ConstB_FOC_T FOC_ConstB;

/* Real-time model */
static RT_MODEL_FOC_T FOC_M_;
RT_MODEL_FOC_T *const FOC_M = &FOC_M_;

/* Forward declaration for local functions */
static void FOC_VoltageProtection(void);

/* Function for Chart: '<S3>/Protection_States' */
static void FOC_VoltageProtection(void)
{
  real_T tmp;
  real32_T tmp_0;
  switch (FOC_DW.is_VoltageProtection) {
   case FOC_IN_OV_Error:
    /* Outport: '<Root>/VoltageFlag' */
    FOC_Y.VoltageFlag = OV_Error;

    /* Inport: '<Root>/BusVoltage_V' */
    tmp_0 = (real32_T)((FOC_B.Max1 != 0.0) || (FOC_U.BusVoltage_V != 0.0F));
    if (!(tmp_0 < FOC_B.BusConversion_InsertedFor_Prote.OVWarningLimit_V)) {
      FOC_DW.durationCounter_1_m = 0U;
    }

    tmp = FOC_B.BusConversion_InsertedFor_Prote.VoltageProtectionTimeout_msec *
      100.0F;
    if (FOC_DW.durationCounter_1_m > tmp) {
      FOC_DW.durationCounter_2_c0 = 0U;
      FOC_DW.durationCounter_1_h = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_VoltageSafe;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = SafeVoltage;
    } else {
      if (!(tmp_0 < FOC_B.BusConversion_InsertedFor_Prote.OVErrorLimit_V)) {
        FOC_DW.durationCounter_2_d = 0U;
      }

      if (FOC_DW.durationCounter_2_d > tmp) {
        FOC_DW.durationCounter_2_bq = 0U;
        FOC_DW.durationCounter_1_f = 0U;
        FOC_DW.is_VoltageProtection = FOC_IN_OV_Warning;

        /* Outport: '<Root>/VoltageFlag' */
        FOC_Y.VoltageFlag = OV_Warning;
      }
    }
    break;

   case FOC_IN_OV_Warning:
    /* Outport: '<Root>/VoltageFlag' */
    FOC_Y.VoltageFlag = OV_Warning;

    /* Inport: '<Root>/BusVoltage_V' */
    tmp_0 = (real32_T)((FOC_B.Max1 != 0.0) || (FOC_U.BusVoltage_V != 0.0F));
    if (!(tmp_0 > FOC_B.BusConversion_InsertedFor_Prote.OVErrorLimit_V)) {
      FOC_DW.durationCounter_2_bq = 0U;
    }

    tmp = FOC_B.BusConversion_InsertedFor_Prote.VoltageProtectionTimeout_msec *
      100.0F;
    if (FOC_DW.durationCounter_2_bq > tmp) {
      FOC_DW.durationCounter_2_d = 0U;
      FOC_DW.durationCounter_1_m = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_OV_Error;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = OV_Error;
    } else {
      if (!(tmp_0 < FOC_B.BusConversion_InsertedFor_Prote.OVWarningLimit_V)) {
        FOC_DW.durationCounter_1_f = 0U;
      }

      if (FOC_DW.durationCounter_1_f > tmp) {
        FOC_DW.durationCounter_2_c0 = 0U;
        FOC_DW.durationCounter_1_h = 0U;
        FOC_DW.is_VoltageProtection = FOC_IN_VoltageSafe;

        /* Outport: '<Root>/VoltageFlag' */
        FOC_Y.VoltageFlag = SafeVoltage;
      }
    }
    break;

   case FOC_IN_UV_Error:
    /* Outport: '<Root>/VoltageFlag' */
    FOC_Y.VoltageFlag = UV_Error;

    /* Inport: '<Root>/BusVoltage_V' */
    /* Inport: '<Root>/BusVoltage_V' */
    if (!(FOC_U.BusVoltage_V >
          FOC_B.BusConversion_InsertedFor_Prote.UVErrorLimit_V)) {
      FOC_DW.durationCounter_1_e3 = 0U;
    }

    tmp = FOC_B.BusConversion_InsertedFor_Prote.VoltageProtectionTimeout_msec *
      100.0F;
    if (FOC_DW.durationCounter_1_e3 > tmp) {
      FOC_DW.durationCounter_2_k = 0U;
      FOC_DW.durationCounter_1_o = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_UV_Warning;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = UV_Warning;
    } else {
      if (!(FOC_U.BusVoltage_V >
            FOC_B.BusConversion_InsertedFor_Prote.UVWarningLimit_V)) {
        FOC_DW.durationCounter_2_n = 0U;
      }

      if (FOC_DW.durationCounter_2_n > tmp) {
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
    if (!(FOC_U.BusVoltage_V <
          FOC_B.BusConversion_InsertedFor_Prote.UVErrorLimit_V)) {
      FOC_DW.durationCounter_1_o = 0U;
    }

    tmp = FOC_B.BusConversion_InsertedFor_Prote.VoltageProtectionTimeout_msec *
      100.0F;
    if (FOC_DW.durationCounter_1_o > tmp) {
      FOC_DW.durationCounter_2_n = 0U;
      FOC_DW.durationCounter_1_e3 = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_UV_Error;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = UV_Error;
    } else {
      if (!(FOC_U.BusVoltage_V >
            FOC_B.BusConversion_InsertedFor_Prote.UVWarningLimit_V)) {
        FOC_DW.durationCounter_2_k = 0U;
      }

      if (FOC_DW.durationCounter_2_k > tmp) {
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

    /* Inport: '<Root>/BusVoltage_V' */
    /* Inport: '<Root>/BusVoltage_V' */
    if (!(((FOC_B.Max1 != 0.0) || (FOC_U.BusVoltage_V != 0.0F)) >
          FOC_B.BusConversion_InsertedFor_Prote.OVWarningLimit_V)) {
      FOC_DW.durationCounter_2_c0 = 0U;
    }

    tmp = FOC_B.BusConversion_InsertedFor_Prote.VoltageProtectionTimeout_msec *
      100.0F;
    if (FOC_DW.durationCounter_2_c0 > tmp) {
      FOC_DW.durationCounter_2_bq = 0U;
      FOC_DW.durationCounter_1_f = 0U;
      FOC_DW.is_VoltageProtection = FOC_IN_OV_Warning;

      /* Outport: '<Root>/VoltageFlag' */
      FOC_Y.VoltageFlag = OV_Warning;
    } else {
      if (!(FOC_U.BusVoltage_V <
            FOC_B.BusConversion_InsertedFor_Prote.UVWarningLimit_V)) {
        FOC_DW.durationCounter_1_h = 0U;
      }

      if (FOC_DW.durationCounter_1_h > tmp) {
        FOC_DW.durationCounter_2_k = 0U;
        FOC_DW.durationCounter_1_o = 0U;
        FOC_DW.is_VoltageProtection = FOC_IN_UV_Warning;

        /* Outport: '<Root>/VoltageFlag' */
        FOC_Y.VoltageFlag = UV_Warning;
      }
    }
    break;
  }
}

/* Model step function */
void FOC_step(void)
{
  real_T rtb_Add1;
  real_T rtb_Diff;
  real_T rtb_Divide;
  real_T rtb_IProdOut;
  real_T rtb_Integrator_d;
  real_T rtb_NProdOut;
  real_T rtb_Subtract;
  real_T rtb_Sum;
  real_T rtb_Switch_fv_idx_0;
  real_T rtb_TrigonometricFunction1_tmp;
  real_T rtb_VdFF_unsat;
  real_T rtb_add_c;
  real32_T rtb_Divide1;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_AND3;

  /* Product: '<S25>/Divide1' incorporates:
   *  Gain: '<S25>/Gain2'
   *  Inport: '<Root>/Lamda'
   *  Inport: '<Root>/Ld'
   *  Inport: '<Root>/Lq'
   *  Sum: '<S25>/Subtract2'
   */
  rtb_Divide1 = FOC_U.Lamda / ((FOC_U.Lq - FOC_U.Ld) * 4.0F);

  /* Product: '<S25>/Divide' incorporates:
   *  Constant: '<S25>/Constant1'
   *  Gain: '<S25>/Gain'
   *  Inport: '<Root>/Current_ref'
   *  Inport: '<Root>/Lamda'
   *  Inport: '<Root>/Torque_ratio'
   *  Inport: '<Root>/p'
   *  Product: '<S25>/Product'
   *  Product: '<S7>/Product'
   */
  rtb_Divide = FOC_U.RefSpeed * FOC_U.Torque_ratio * 2.0 / (real32_T)
    (FOC_U.Lamda * FOC_U.p * 3.0);

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

  /* Math: '<S25>/Math Function2'
   *
   * About '<S25>/Math Function2':
   *  Operator: magnitude^2
   */
  rtb_Divide *= rtb_Divide;

  /* Sum: '<S25>/Subtract' incorporates:
   *  Gain: '<S25>/Gain4'
   *  Math: '<S25>/Math Function'
   *  Sqrt: '<S25>/Sqrt'
   *  Sum: '<S25>/Add'
   *
   * About '<S25>/Math Function':
   *  Operator: magnitude^2
   */
  rtb_Subtract = rtb_Divide1 - sqrt(rtb_Divide1 * rtb_Divide1 + 0.5 * rtb_Divide);

  /* Switch: '<S29>/Switch2' incorporates:
   *  Inport: '<Root>/Id_low_limit'
   *  Inport: '<Root>/Id_up_limit'
   *  RelationalOperator: '<S29>/LowerRelop1'
   *  RelationalOperator: '<S29>/UpperRelop'
   *  Switch: '<S29>/Switch'
   */
  if (rtb_Subtract > FOC_U.Id_up_limit) {
    rtb_Subtract = FOC_U.Id_up_limit;
  } else if (rtb_Subtract < FOC_U.Id_low_limit) {
    /* Switch: '<S29>/Switch' incorporates:
     *  Inport: '<Root>/Id_low_limit'
     */
    rtb_Subtract = FOC_U.Id_low_limit;
  }

  /* End of Switch: '<S29>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S10>/Two phase CRL wrap' */
  /* Gain: '<S11>/one_by_sqrt3' incorporates:
   *  Inport: '<Root>/Phase Current'
   *  Sum: '<S11>/a_plus_2b'
   */
  rtb_Diff = ((FOC_U.PhaseCurrent[0] + FOC_U.PhaseCurrent[1]) +
              FOC_U.PhaseCurrent[1]) * 0.57735026918962584;

  /* End of Outputs for SubSystem: '<S10>/Two phase CRL wrap' */

  /* Trigonometry: '<S5>/Trigonometric Function' incorporates:
   *  Inport: '<Root>/angle'
   *  Trigonometry: '<S6>/Trigonometric Function1'
   */
  if (fnr.current_state == FORWARD)
  {
    FOC_U.angle = (FOC_U.angle);
    fnr.previous_state = fnr.current_state;
  }
  else if (fnr.current_state == REVERSE)
  {
    FOC_U.angle = (FOC_U.angle) - -3.14159274F;
    fnr.previous_state = fnr.current_state;
  }
  else if (fnr.current_state == NEUTRAL)
  {
    if (fnr.previous_state == FORWARD)
    {
      FOC_U.angle = (FOC_U.angle);
    }
    else if (fnr.previous_state == REVERSE)
    {
      FOC_U.angle = (FOC_U.angle) - -3.14159274F;
    }
  }

  rtb_Add1 = sin(FOC_U.angle);

  /* Trigonometry: '<S5>/Trigonometric Function1' incorporates:
   *  Inport: '<Root>/angle'
   *  Trigonometry: '<S6>/Trigonometric Function'
   */
  rtb_TrigonometricFunction1_tmp = cos(FOC_U.angle);

  /* Outputs for Atomic SubSystem: '<S9>/Two inputs CRL' */
  /* Outputs for Atomic SubSystem: '<S10>/Two phase CRL wrap' */
  /* Switch: '<S13>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
   *  Inport: '<Root>/Phase Current'
   *  Product: '<S12>/acos'
   *  Product: '<S12>/bsin'
   *  Sum: '<S12>/sum_Ds'
   *  Trigonometry: '<S5>/Trigonometric Function'
   *  Trigonometry: '<S5>/Trigonometric Function1'
   */
  rtb_Switch_fv_idx_0 = FOC_U.PhaseCurrent[0] * rtb_TrigonometricFunction1_tmp +
    rtb_Diff * rtb_Add1;

  /* Switch: '<S19>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S11>/a16'
   *  Inport: '<Root>/Phase Current'
   *  Product: '<S12>/asin'
   *  Product: '<S12>/bcos'
   *  Sum: '<S12>/sum_Qs'
   *  Switch: '<S13>/Switch'
   *  Trigonometry: '<S5>/Trigonometric Function'
   *  Trigonometry: '<S5>/Trigonometric Function1'
   */
  FOC_Y.Iq = rtb_Diff * rtb_TrigonometricFunction1_tmp - FOC_U.PhaseCurrent[0] *
    rtb_Add1;

  /* End of Outputs for SubSystem: '<S10>/Two phase CRL wrap' */

  /* Outport: '<Root>/Id' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   */
  FOC_Y.Id = rtb_Switch_fv_idx_0;

  /* Sum: '<S7>/Sum3' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   */
  rtb_IProdOut = rtb_Subtract - rtb_Switch_fv_idx_0;

  FOC_Y.Id_refer = rtb_Subtract;

  /* End of Outputs for SubSystem: '<S9>/Two inputs CRL' */

  /* Product: '<S71>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S63>/Filter'
   *  Inport: '<Root>/Filter_flux_PID'
   *  Inport: '<Root>/Kd_flux_PID'
   *  Product: '<S61>/DProd Out'
   *  Sum: '<S63>/SumD'
   */
  rtb_NProdOut = (rtb_IProdOut * FOC_U.Kd_flux_PID - FOC_DW.Filter_DSTATE) *
    FOC_U.Filter_flux_PID;

  /* Sum: '<S78>/Sum' incorporates:
   *  DiscreteIntegrator: '<S68>/Integrator'
   *  Inport: '<Root>/Kp_flux_PID'
   *  Product: '<S73>/PProd Out'
   */
  rtb_Sum = (rtb_IProdOut * FOC_U.Kp_flux_PID + FOC_DW.Integrator_DSTATE) +
    rtb_NProdOut;

  /* Sqrt: '<S25>/Sqrt1' incorporates:
   *  Abs: '<S25>/Abs'
   *  Math: '<S25>/Math Function3'
   *  Sum: '<S25>/Subtract1'
   *
   * About '<S25>/Math Function3':
   *  Operator: magnitude^2
   */
  rtb_Divide = sqrt(fabs(rtb_Divide - rtb_Subtract * rtb_Subtract));

  FOC_Y.Iq_refer = rtb_Divide;

  /* Gain: '<S144>/wm_pu2si_mech2elec' incorporates:
   *  Gain: '<S7>/Gain'
   *  Inport: '<Root>/Actual Speed'
   */
  rtb_Integrator_d = 0.33333333333333331 * FOC_U.ActualSpeed * 3.0;

  /* Gain: '<S144>/NegSign' incorporates:
   *  Product: '<S144>/prod1'
   */
  rtb_VdFF_unsat = -(FOC_ConstB.Switch1 * rtb_Divide * rtb_Integrator_d);

  /* Switch: '<S76>/Switch2' incorporates:
   *  Inport: '<Root>/Low_Limit_flux_PID'
   *  Inport: '<Root>/Up_Limit_flux_PID'
   *  RelationalOperator: '<S76>/LowerRelop1'
   *  RelationalOperator: '<S76>/UpperRelop'
   *  Switch: '<S76>/Switch'
   */
  if (rtb_Sum > FOC_U.Up_Limit_flux_PID) {
    rtb_Diff = FOC_U.Up_Limit_flux_PID;
  } else if (rtb_Sum < FOC_U.Low_Limit_flux_PID) {
    /* Switch: '<S76>/Switch' incorporates:
     *  Inport: '<Root>/Low_Limit_flux_PID'
     */
    rtb_Diff = FOC_U.Low_Limit_flux_PID;
  } else {
    rtb_Diff = rtb_Sum;
  }

  /* Switch: '<S146>/Switch2' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   *  RelationalOperator: '<S146>/LowerRelop1'
   *  RelationalOperator: '<S146>/UpperRelop'
   *  Switch: '<S146>/Switch'
   *  UnaryMinus: '<S144>/Unary Minus'
   */
  if (rtb_VdFF_unsat > FOC_U.BusVoltage_V) {
    rtb_VdFF_unsat = FOC_U.BusVoltage_V;
  } else if (rtb_VdFF_unsat < -FOC_U.BusVoltage_V) {
    /* Switch: '<S146>/Switch' incorporates:
     *  UnaryMinus: '<S144>/Unary Minus'
     */
    rtb_VdFF_unsat = -FOC_U.BusVoltage_V;
  }

  /* Sum: '<S7>/Sum' incorporates:
   *  Switch: '<S146>/Switch2'
   *  Switch: '<S76>/Switch2'
   */
  FOC_Y.Vd = rtb_Diff + rtb_VdFF_unsat;

  /* Product: '<S144>/prod2' incorporates:
   *  Product: '<S144>/prod3'
   *  Sum: '<S144>/add1'
   */
  rtb_Subtract = (FOC_ConstB.Switch * rtb_Subtract + FOC_ConstB.Switch2) *
    rtb_Integrator_d;

  /* Outputs for Atomic SubSystem: '<S9>/Two inputs CRL' */
  /* Sum: '<S7>/Sum2' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   */
  rtb_Divide -= FOC_Y.Iq;

  /* End of Outputs for SubSystem: '<S9>/Two inputs CRL' */

  /* Product: '<S127>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S119>/Filter'
   *  Inport: '<Root>/Filter_torque_PID'
   *  Inport: '<Root>/Kd_torque_PID'
   *  Product: '<S117>/DProd Out'
   *  Sum: '<S119>/SumD'
   */
  rtb_Integrator_d = (rtb_Divide * FOC_U.Kd_torque_PID - FOC_DW.Filter_DSTATE_d)
    * FOC_U.Filter_torque_PID;

  /* Sum: '<S134>/Sum' incorporates:
   *  DiscreteIntegrator: '<S124>/Integrator'
   *  Inport: '<Root>/Kp_torque_PID'
   *  Product: '<S129>/PProd Out'
   */
  rtb_VdFF_unsat = (rtb_Divide * FOC_U.Kp_torque_PID +
                    FOC_DW.Integrator_DSTATE_h) + rtb_Integrator_d;

  /* Switch: '<S147>/Switch2' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   *  RelationalOperator: '<S147>/LowerRelop1'
   *  RelationalOperator: '<S147>/UpperRelop'
   *  Switch: '<S147>/Switch'
   *  UnaryMinus: '<S144>/Unary Minus'
   */
  if (rtb_Subtract > FOC_U.BusVoltage_V) {
    rtb_Subtract = FOC_U.BusVoltage_V;
  } else if (rtb_Subtract < -FOC_U.BusVoltage_V) {
    /* Switch: '<S147>/Switch' incorporates:
     *  UnaryMinus: '<S144>/Unary Minus'
     */
    rtb_Subtract = -FOC_U.BusVoltage_V;
  }

  /* Switch: '<S132>/Switch2' incorporates:
   *  Inport: '<Root>/Low_Limit_torque_PID'
   *  Inport: '<Root>/Up_Limit_torque_PID'
   *  RelationalOperator: '<S132>/LowerRelop1'
   *  RelationalOperator: '<S132>/UpperRelop'
   *  Switch: '<S132>/Switch'
   */
  if (rtb_VdFF_unsat > FOC_U.Up_Limit_torque_PID) {
    rtb_Diff = FOC_U.Up_Limit_torque_PID;
  } else if (rtb_VdFF_unsat < FOC_U.Low_Limit_torque_PID) {
    /* Switch: '<S132>/Switch' incorporates:
     *  Inport: '<Root>/Low_Limit_torque_PID'
     */
    rtb_Diff = FOC_U.Low_Limit_torque_PID;
  } else {
    rtb_Diff = rtb_VdFF_unsat;
  }

  /* Sum: '<S7>/Sum4' incorporates:
   *  Switch: '<S132>/Switch2'
   *  Switch: '<S147>/Switch2'
   */
  FOC_Y.Vq = rtb_Subtract + rtb_Diff;

  real_T Vq_ref_max = sqrtf((61.0f*61.0f) - (FOC_Y.Vd * FOC_Y.Vd));

  if (FOC_Y.Vq > Vq_ref_max)
    FOC_Y.Vq = Vq_ref_max;

  /* Outputs for Atomic SubSystem: '<S15>/Two inputs CRL' */
  /* Switch: '<S19>/Switch' incorporates:
   *  Product: '<S18>/dcos'
   *  Product: '<S18>/qsin'
   *  Sum: '<S18>/sum_alpha'
   */
  rtb_Switch_fv_idx_0 = FOC_Y.Vd * rtb_TrigonometricFunction1_tmp - FOC_Y.Vq *
    rtb_Add1;

  /* Gain: '<S17>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
   */
  rtb_add_c = 0.5 * rtb_Switch_fv_idx_0;

  /* Gain: '<S17>/sqrt3_by_two' incorporates:
   *  Product: '<S18>/dsin'
   *  Product: '<S18>/qcos'
   *  Sum: '<S18>/sum_beta'
   */
  rtb_Subtract = (FOC_Y.Vq * rtb_TrigonometricFunction1_tmp + FOC_Y.Vd *
                  rtb_Add1) * 0.8660254037844386;

  /* End of Outputs for SubSystem: '<S15>/Two inputs CRL' */

  /* Sum: '<S17>/add_b' */
  rtb_Add1 = rtb_Subtract - rtb_add_c;

  /* Sum: '<S17>/add_c' */
  rtb_add_c = (0.0 - rtb_add_c) - rtb_Subtract;

  /* Outputs for Atomic SubSystem: '<S15>/Two inputs CRL' */
  /* Gain: '<S23>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
   *  MinMax: '<S23>/Max'
   *  MinMax: '<S23>/Min'
   *  Sum: '<S23>/Add'
   */
  rtb_Diff = (fmax(fmax(rtb_Switch_fv_idx_0, rtb_Add1), rtb_add_c) + fmin(fmin
    (rtb_Switch_fv_idx_0, rtb_Add1), rtb_add_c)) * -0.5;

  /* Gain: '<S22>/Gain' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
   *  Sum: '<S22>/Add1'
   *  Sum: '<S22>/Add2'
   *  Sum: '<S22>/Add3'
   */
  FOC_Y.Va = (rtb_Switch_fv_idx_0 + rtb_Diff) * 1.1547005383792517;

  /* End of Outputs for SubSystem: '<S15>/Two inputs CRL' */
  FOC_Y.Vb = (rtb_Add1 + rtb_Diff) * 1.1547005383792517;
  FOC_Y.Vc = (rtb_Diff + rtb_add_c) * 1.1547005383792517;

  /* MinMax: '<S3>/Max1' */
  FOC_B.Max1 = fmax(fmax(FOC_Y.Va, FOC_Y.Vb), FOC_Y.Vc);

  /* MinMax: '<S3>/Max2' incorporates:
   *  Inport: '<Root>/MCTemperature_C'
   *  Inport: '<Root>/MotorTemperature_C'
   */
  rtb_Divide1 = fmaxf(FOC_U.MCTemperature_C, FOC_U.MotorTemperature_C);

  /* MinMax: '<S3>/Max' incorporates:
   *  Inport: '<Root>/Phase Current'
   */
  rtb_Subtract = fmax(fmax(FOC_U.PhaseCurrent[0], FOC_U.PhaseCurrent[1]),
                      FOC_U.PhaseCurrent[2]);

  /* BusCreator generated from: '<S3>/Protection_States' */
  FOC_B.BusConversion_InsertedFor_Prote.MaxCurrentLimit_A =
    FOC_ConstB.MaxCurrentLimit_A;
  FOC_B.BusConversion_InsertedFor_Prote.OTWarningLimit_C =
    FOC_ConstB.OTWarningLimit_C;
  FOC_B.BusConversion_InsertedFor_Prote.OTErrorLimit_C =
    FOC_ConstB.OTErrorLimit_C;
  FOC_B.BusConversion_InsertedFor_Prote.UVWarningLimit_V =
    FOC_ConstB.UVWarningLimit_V;
  FOC_B.BusConversion_InsertedFor_Prote.UVErrorLimit_V =
    FOC_ConstB.UVErrorLimit_V;
  FOC_B.BusConversion_InsertedFor_Prote.OVWarningLimit_V =
    FOC_ConstB.OVWarningLimit_V;
  FOC_B.BusConversion_InsertedFor_Prote.OVErrorLimit_V =
    FOC_ConstB.OVErrorLimit_V;
  FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A =
    FOC_ConstB.OCWarningLimit_A;
  FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A =
    FOC_ConstB.OCErrorLimit_A;
  FOC_B.BusConversion_InsertedFor_Prote.WarningSpeedLimit_rpm =
    FOC_ConstB.WarningSpeedLimit_rpm;
  FOC_B.BusConversion_InsertedFor_Prote.VoltageProtectionTimeout_msec =
    FOC_ConstB.VoltageProtectionTimeout_ms;
  FOC_B.BusConversion_InsertedFor_Prote.TempProtectionTimeout_msec =
    FOC_ConstB.TempProtectionTimeout_msec;
  FOC_B.BusConversion_InsertedFor_Prote.CurrentProtectionTimeout_msec =
    FOC_ConstB.CurrentProtectionTimeout_ms;

  /* Chart: '<S3>/Protection_States' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   */
  if (FOC_DW.is_active_c7_FOC == 0) {
    FOC_DW.is_active_c7_FOC = 1U;
    FOC_DW.durationCounter_1 = 0U;
    FOC_DW.is_TemperatureProtection = FOC_IN_TempSafe;

    /* Outport: '<Root>/TempFlag' */
    FOC_Y.TempFlag = SafeTemperature;
    FOC_DW.durationCounter_2_c0 = 0U;
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
      if (!(rtb_Divide1 < FOC_B.BusConversion_InsertedFor_Prote.OTWarningLimit_C))
      {
        FOC_DW.durationCounter_1_c = 0U;
      }

      rtb_Diff =
        FOC_B.BusConversion_InsertedFor_Prote.TempProtectionTimeout_msec *
        100.0F;
      if (FOC_DW.durationCounter_1_c > rtb_Diff) {
        FOC_DW.durationCounter_1 = 0U;
        FOC_DW.is_TemperatureProtection = FOC_IN_TempSafe;

        /* Outport: '<Root>/TempFlag' */
        FOC_Y.TempFlag = SafeTemperature;
      } else {
        if (!(rtb_Divide1 < FOC_B.BusConversion_InsertedFor_Prote.OTErrorLimit_C))
        {
          FOC_DW.durationCounter_2 = 0U;
        }

        if (FOC_DW.durationCounter_2 > rtb_Diff) {
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
      if (!(rtb_Divide1 > FOC_B.BusConversion_InsertedFor_Prote.OTErrorLimit_C))
      {
        FOC_DW.durationCounter_2_e = 0U;
      }

      rtb_Diff =
        FOC_B.BusConversion_InsertedFor_Prote.TempProtectionTimeout_msec *
        100.0F;
      if (FOC_DW.durationCounter_2_e > rtb_Diff) {
        FOC_DW.durationCounter_2 = 0U;
        FOC_DW.durationCounter_1_c = 0U;
        FOC_DW.is_TemperatureProtection = FOC_IN_HighTempError;

        /* Outport: '<Root>/TempFlag' */
        FOC_Y.TempFlag = OT_Error;
      } else {
        if (!(rtb_Divide1 <
              FOC_B.BusConversion_InsertedFor_Prote.OTWarningLimit_C)) {
          FOC_DW.durationCounter_1_e = 0U;
        }

        if (FOC_DW.durationCounter_1_e > rtb_Diff) {
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
      if (!(rtb_Divide1 > FOC_B.BusConversion_InsertedFor_Prote.OTWarningLimit_C))
      {
        FOC_DW.durationCounter_1 = 0U;
      }

      if ((real_T)FOC_DW.durationCounter_1 >
          FOC_B.BusConversion_InsertedFor_Prote.TempProtectionTimeout_msec *
          100.0F) {
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
      if (!(rtb_Subtract >
            FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A)) {
        FOC_DW.durationCounter_1_i = 0U;
      }

      if ((real_T)FOC_DW.durationCounter_1_i >
          FOC_B.BusConversion_InsertedFor_Prote.CurrentProtectionTimeout_msec *
          100.0F) {
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
      if (!(rtb_Subtract <
            FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A)) {
        FOC_DW.durationCounter_1_a = 0U;
      }

      rtb_Diff =
        FOC_B.BusConversion_InsertedFor_Prote.CurrentProtectionTimeout_msec *
        100.0F;
      if (FOC_DW.durationCounter_1_a > rtb_Diff) {
        FOC_DW.durationCounter_1_i = 0U;
        FOC_DW.is_CurrentProtection = FOC_IN_CurrentSafe;

        /* Outport: '<Root>/CurrentFlag' */
        FOC_Y.CurrentFlag = SafeCurrent;
      } else {
        if (!(rtb_Subtract <
              FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A)) {
          FOC_DW.durationCounter_2_b = 0U;
        }

        if (FOC_DW.durationCounter_2_b > rtb_Diff) {
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
      if (!(rtb_Subtract > FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A))
      {
        FOC_DW.durationCounter_2_c = 0U;
      }

      rtb_Diff =
        FOC_B.BusConversion_InsertedFor_Prote.CurrentProtectionTimeout_msec *
        100.0F;
      if (FOC_DW.durationCounter_2_c > rtb_Diff) {
        FOC_DW.durationCounter_2_b = 0U;
        FOC_DW.durationCounter_1_a = 0U;
        FOC_DW.is_CurrentProtection = FOC_IN_OC_Error;

        /* Outport: '<Root>/CurrentFlag' */
        FOC_Y.CurrentFlag = OC_Error;
      } else {
        if (!(rtb_Subtract <
              FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A)) {
          FOC_DW.durationCounter_1_d = 0U;
        }

        if (FOC_DW.durationCounter_1_d > rtb_Diff) {
          FOC_DW.durationCounter_1_i = 0U;
          FOC_DW.is_CurrentProtection = FOC_IN_CurrentSafe;

          /* Outport: '<Root>/CurrentFlag' */
          FOC_Y.CurrentFlag = SafeCurrent;
        }
      }
      break;
    }
  }

  if (rtb_Divide1 > FOC_B.BusConversion_InsertedFor_Prote.OTWarningLimit_C) {
    FOC_DW.durationCounter_1++;
  } else {
    FOC_DW.durationCounter_1 = 0U;
  }

  if (rtb_Divide1 < FOC_B.BusConversion_InsertedFor_Prote.OTWarningLimit_C) {
    FOC_DW.durationCounter_1_c++;
    FOC_DW.durationCounter_1_e++;
  } else {
    FOC_DW.durationCounter_1_c = 0U;
    FOC_DW.durationCounter_1_e = 0U;
  }

  if (rtb_Divide1 < FOC_B.BusConversion_InsertedFor_Prote.OTErrorLimit_C) {
    FOC_DW.durationCounter_2++;
  } else {
    FOC_DW.durationCounter_2 = 0U;
  }

  if (rtb_Divide1 > FOC_B.BusConversion_InsertedFor_Prote.OTErrorLimit_C) {
    FOC_DW.durationCounter_2_e++;
  } else {
    FOC_DW.durationCounter_2_e = 0U;
  }

  if (rtb_Subtract > FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A) {
    FOC_DW.durationCounter_1_i++;
  } else {
    FOC_DW.durationCounter_1_i = 0U;
  }

  if (rtb_Subtract < FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A) {
    FOC_DW.durationCounter_1_a++;
    FOC_DW.durationCounter_1_d++;
  } else {
    FOC_DW.durationCounter_1_a = 0U;
    FOC_DW.durationCounter_1_d = 0U;
  }

  if (rtb_Subtract < FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A) {
    FOC_DW.durationCounter_2_b++;
  } else {
    FOC_DW.durationCounter_2_b = 0U;
  }

  if (rtb_Subtract > FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A) {
    FOC_DW.durationCounter_2_c++;
  } else {
    FOC_DW.durationCounter_2_c = 0U;
  }

  if (FOC_U.BusVoltage_V > FOC_B.BusConversion_InsertedFor_Prote.UVErrorLimit_V)
  {
    FOC_DW.durationCounter_1_e3++;
  } else {
    FOC_DW.durationCounter_1_e3 = 0U;
  }

  if (FOC_U.BusVoltage_V < FOC_B.BusConversion_InsertedFor_Prote.UVErrorLimit_V)
  {
    FOC_DW.durationCounter_1_o++;
  } else {
    FOC_DW.durationCounter_1_o = 0U;
  }

  if (FOC_U.BusVoltage_V <
      FOC_B.BusConversion_InsertedFor_Prote.UVWarningLimit_V) {
    FOC_DW.durationCounter_1_h++;
  } else {
    FOC_DW.durationCounter_1_h = 0U;
  }

  if (FOC_U.BusVoltage_V >
      FOC_B.BusConversion_InsertedFor_Prote.UVWarningLimit_V) {
    FOC_DW.durationCounter_2_k++;
    FOC_DW.durationCounter_2_n++;
  } else {
    FOC_DW.durationCounter_2_k = 0U;
    FOC_DW.durationCounter_2_n = 0U;
  }

  rtb_Divide1 = (real32_T)((FOC_B.Max1 != 0.0) || (FOC_U.BusVoltage_V != 0.0F));
  if (rtb_Divide1 > FOC_B.BusConversion_InsertedFor_Prote.OVWarningLimit_V) {
    FOC_DW.durationCounter_2_c0++;
  } else {
    FOC_DW.durationCounter_2_c0 = 0U;
  }

  if (rtb_Divide1 < FOC_B.BusConversion_InsertedFor_Prote.OVWarningLimit_V) {
    FOC_DW.durationCounter_1_m++;
    FOC_DW.durationCounter_1_f++;
  } else {
    FOC_DW.durationCounter_1_m = 0U;
    FOC_DW.durationCounter_1_f = 0U;
  }

  if (rtb_Divide1 < FOC_B.BusConversion_InsertedFor_Prote.OVErrorLimit_V) {
    FOC_DW.durationCounter_2_d++;
  } else {
    FOC_DW.durationCounter_2_d = 0U;
  }

  if (rtb_Divide1 > FOC_B.BusConversion_InsertedFor_Prote.OVErrorLimit_V) {
    FOC_DW.durationCounter_2_bq++;
  } else {
    FOC_DW.durationCounter_2_bq = 0U;
  }

  /* End of Chart: '<S3>/Protection_States' */

  /* Switch: '<S116>/Switch' incorporates:
   *  Inport: '<Root>/Low_Limit_torque_PID'
   *  Inport: '<Root>/Up_Limit_torque_PID'
   *  RelationalOperator: '<S116>/u_GTE_up'
   *  RelationalOperator: '<S116>/u_GT_lo'
   *  Switch: '<S116>/Switch1'
   */
  if (rtb_VdFF_unsat >= FOC_U.Up_Limit_torque_PID) {
    rtb_Diff = FOC_U.Up_Limit_torque_PID;
  } else if (rtb_VdFF_unsat > FOC_U.Low_Limit_torque_PID) {
    /* Switch: '<S116>/Switch1' */
    rtb_Diff = rtb_VdFF_unsat;
  } else {
    rtb_Diff = FOC_U.Low_Limit_torque_PID;
  }

  /* Sum: '<S116>/Diff' incorporates:
   *  Switch: '<S116>/Switch'
   */
  rtb_Diff = rtb_VdFF_unsat - rtb_Diff;

  /* Product: '<S121>/IProd Out' incorporates:
   *  Inport: '<Root>/Ki_torque_PID'
   */
  rtb_Divide *= FOC_U.Ki_torque_PID;

  /* Switch: '<S113>/Switch1' incorporates:
   *  Constant: '<S113>/Clamping_zero'
   *  Constant: '<S113>/Constant'
   *  Constant: '<S113>/Constant2'
   *  RelationalOperator: '<S113>/fix for DT propagation issue'
   */
  if (rtb_Diff > 0.0) {
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
  if (rtb_Divide > 0.0) {
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
  rtb_AND3 = ((rtb_Diff != 0.0) && (tmp == tmp_0));

  /* Switch: '<S60>/Switch' incorporates:
   *  Inport: '<Root>/Low_Limit_flux_PID'
   *  Inport: '<Root>/Up_Limit_flux_PID'
   *  RelationalOperator: '<S60>/u_GTE_up'
   *  RelationalOperator: '<S60>/u_GT_lo'
   *  Switch: '<S60>/Switch1'
   */
  if (rtb_Sum >= FOC_U.Up_Limit_flux_PID) {
    rtb_Diff = FOC_U.Up_Limit_flux_PID;
  } else if (rtb_Sum > FOC_U.Low_Limit_flux_PID) {
    /* Switch: '<S60>/Switch1' */
    rtb_Diff = rtb_Sum;
  } else {
    rtb_Diff = FOC_U.Low_Limit_flux_PID;
  }

  /* Sum: '<S60>/Diff' incorporates:
   *  Switch: '<S60>/Switch'
   */
  rtb_Diff = rtb_Sum - rtb_Diff;

  /* Product: '<S65>/IProd Out' incorporates:
   *  Inport: '<Root>/Ki_flux_PID'
   */
  rtb_IProdOut *= FOC_U.Ki_flux_PID;

  /* Switch: '<S57>/Switch1' incorporates:
   *  Constant: '<S57>/Clamping_zero'
   *  Constant: '<S57>/Constant'
   *  Constant: '<S57>/Constant2'
   *  RelationalOperator: '<S57>/fix for DT propagation issue'
   */
  if (rtb_Diff > 0.0) {
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
  if (rtb_IProdOut > 0.0) {
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
  if ((rtb_Diff != 0.0) && (tmp == tmp_0)) {
    rtb_IProdOut = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S68>/Integrator' incorporates:
   *  Switch: '<S57>/Switch'
   */
  FOC_DW.Integrator_DSTATE += 1.0E-5 * rtb_IProdOut;

  /* Update for DiscreteIntegrator: '<S63>/Filter' */
  FOC_DW.Filter_DSTATE += 1.0E-5 * rtb_NProdOut;

  /* Switch: '<S113>/Switch' incorporates:
   *  Constant: '<S113>/Constant1'
   */
  if (rtb_AND3) {
    rtb_Divide = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S124>/Integrator' incorporates:
   *  Switch: '<S113>/Switch'
   */
  FOC_DW.Integrator_DSTATE_h += 1.0E-5 * rtb_Divide;

  /* Update for DiscreteIntegrator: '<S119>/Filter' */
  FOC_DW.Filter_DSTATE_d += 1.0E-5 * rtb_Integrator_d;
}

/* Model initialize function */
void FOC_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(FOC_M, (NULL));

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
  FOC_DW.Integrator_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S63>/Filter' */
  FOC_DW.Filter_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Integrator' */
  FOC_DW.Integrator_DSTATE_h = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Filter' */
  FOC_DW.Filter_DSTATE_d = 0.0;

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
  FOC_U.Rs = 0.0107;
  FOC_U.p = POLEPAIRS;
  FOC_U.Torque_ratio = 0.228571;

  FOC_U.Id_up_limit = 0.0f;
  FOC_U.Id_low_limit = 0.0f;
  FOC_U.Iq_up_limit = 0.0f;
  FOC_U.Iq_low_limit = 0.0f;

  #if PEG4W
  FOC_U.Kp_flux_PID = 0.12;
  FOC_U.Ki_flux_PID = 16.0;
  FOC_U.Kd_flux_PID = 0.001;
  FOC_U.Filter_flux_PID = 2.0;
  FOC_U.Up_Limit_flux_PID = 61.0;
  FOC_U.Low_Limit_flux_PID = -61.0;

  FOC_U.Kp_torque_PID = 0.12;
  FOC_U.Ki_torque_PID = 8.0;
  FOC_U.Kd_torque_PID = 0.001;
  FOC_U.Filter_torque_PID = 2.0;
  FOC_U.Up_Limit_torque_PID = 61.0;
  FOC_U.Low_Limit_torque_PID = -61.0;
  #endif

  #if PEG3W
  FOC_U.Kp_flux_PID = 0.8;
  FOC_U.Ki_flux_PID = 30.0;
  FOC_U.Kd_flux_PID = 0.01;
  FOC_U.Filter_flux_PID = 2.0;
  FOC_U.Up_Limit_flux_PID = 61.0;
  FOC_U.Low_Limit_flux_PID = -61.0;

  FOC_U.Kp_torque_PID = 0.7;
  FOC_U.Ki_torque_PID = 22.0;
  FOC_U.Kd_torque_PID = 0.01;
  FOC_U.Filter_torque_PID = 2.0;
  FOC_U.Up_Limit_torque_PID = 61.0;
  FOC_U.Low_Limit_torque_PID = -61.0;
  #endif

  fnr.current_state = NEUTRAL;
  fnr.previous_state = FORWARD;
  fnr.throttle_disabled = 1;

  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
}

/* Model terminate function */
void FOC_terminate(void)
{
  /* (no terminate code required) */
}
#endif