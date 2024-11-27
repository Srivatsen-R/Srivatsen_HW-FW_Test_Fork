/*
 * FOC.c
 *
 * Code generation for model "FOC".
 *
 * Model version              : 18.28
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Tue Oct  8 12:08:08 2024
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

extern uint8_t forward_set;
extern uint8_t reverse_set;

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
  real_T rtb_IProdOut_l;
  real_T rtb_NProdOut;
  real_T rtb_NProdOut_b;
  real_T rtb_Subtract;
  real_T rtb_Sum;
  real_T rtb_Sum_ep;
  real_T rtb_Sum_n;
  real_T rtb_Switch_fv_idx_0;
  real_T rtb_TrigonometricFunction1_tmp;
  real_T rtb_add_c;
  real32_T rtb_Divide1;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_AND3;
  boolean_T rtb_AND3_g;

  /* Product: '<S25>/Divide1' incorporates:
   *  Gain: '<S25>/Gain2'
   *  Inport: '<Root>/Lamda'
   *  Inport: '<Root>/Ld'
   *  Inport: '<Root>/Lq'
   *  Sum: '<S25>/Subtract2'
   */
  rtb_Divide1 = FOC_U.Lamda / ((FOC_U.Lq - FOC_U.Ld) * 4.0F);

  /* Sum: '<S7>/Sum1' incorporates:
   *  Inport: '<Root>/Actual Speed'
   *  Inport: '<Root>/Ref Speed'
   */
  rtb_IProdOut = FOC_U.RefSpeed - FOC_U.ActualSpeed;

  /* Product: '<S71>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S63>/Filter'
   *  Inport: '<Root>/Filter_speed_PID'
   *  Inport: '<Root>/Kd_speed_PID'
   *  Product: '<S61>/DProd Out'
   *  Sum: '<S63>/SumD'
   */
  rtb_NProdOut = (rtb_IProdOut * FOC_U.Kd_speed_PID - FOC_DW.Filter_DSTATE) *
    FOC_U.Filter_speed_PID;

  /* Sum: '<S78>/Sum' incorporates:
   *  DiscreteIntegrator: '<S68>/Integrator'
   *  Inport: '<Root>/Kp_speed_PID'
   *  Product: '<S73>/PProd Out'
   */
  rtb_Sum = (rtb_IProdOut * FOC_U.Kp_speed_PID + FOC_DW.Integrator_DSTATE) +
    rtb_NProdOut;

  /* Switch: '<S76>/Switch2' incorporates:
   *  Inport: '<Root>/Low_Limit_speed_PID'
   *  Inport: '<Root>/Up_Limit_speed_PID'
   *  RelationalOperator: '<S76>/LowerRelop1'
   *  RelationalOperator: '<S76>/UpperRelop'
   *  Switch: '<S76>/Switch'
   */
  if (rtb_Sum > FOC_U.Up_Limit_speed_PID) {
    rtb_Diff = FOC_U.Up_Limit_speed_PID;
  } else if (rtb_Sum < FOC_U.Low_Limit_speed_PID) {
    /* Switch: '<S76>/Switch' incorporates:
     *  Inport: '<Root>/Low_Limit_speed_PID'
     */
    rtb_Diff = FOC_U.Low_Limit_speed_PID;
  } else {
    rtb_Diff = rtb_Sum;
  }

  /* Product: '<S25>/Divide' incorporates:
   *  Constant: '<S25>/Constant1'
   *  Gain: '<S25>/Gain'
   *  Inport: '<Root>/Lamda'
   *  Inport: '<Root>/p'
   *  Product: '<S25>/Product'
   *  Switch: '<S76>/Switch2'
   */
  rtb_Divide = 2.0 * rtb_Diff / (real32_T)(FOC_U.Lamda * FOC_U.p * 3.0);

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
  if (forward_set)
    FOC_U.angle = (FOC_U.angle);
  else if (reverse_set)
    FOC_U.angle = (FOC_U.angle) - -3.14159274F;

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

  /* End of Outputs for SubSystem: '<S9>/Two inputs CRL' */

  /* Switch: '<S29>/Switch2' incorporates:
   *  Inport: '<Root>/Id_low_limit'
   *  Inport: '<Root>/Id_up_limit'
   *  RelationalOperator: '<S29>/LowerRelop1'
   *  RelationalOperator: '<S29>/UpperRelop'
   *  Switch: '<S29>/Switch'
   */
  if (rtb_Subtract > FOC_U.Id_up_limit) {
    rtb_Diff = FOC_U.Id_up_limit;
  } else if (rtb_Subtract < FOC_U.Id_low_limit) {
    /* Switch: '<S29>/Switch' incorporates:
     *  Inport: '<Root>/Id_low_limit'
     */
    rtb_Diff = FOC_U.Id_low_limit;
  } else {
    rtb_Diff = rtb_Subtract;
  }

  FOC_Y.Id_refer = rtb_Diff;

  /* Outputs for Atomic SubSystem: '<S9>/Two inputs CRL' */
  /* Sum: '<S7>/Sum3' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   *  Switch: '<S29>/Switch2'
   */
  rtb_IProdOut_l = rtb_Diff - rtb_Switch_fv_idx_0;

  /* End of Outputs for SubSystem: '<S9>/Two inputs CRL' */

  /* Product: '<S127>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S119>/Filter'
   *  Inport: '<Root>/Filter_flux_PID'
   *  Inport: '<Root>/Kd_flux_PID'
   *  Product: '<S117>/DProd Out'
   *  Sum: '<S119>/SumD'
   */
  rtb_NProdOut_b = (rtb_IProdOut_l * FOC_U.Kd_flux_PID - FOC_DW.Filter_DSTATE_k)
    * FOC_U.Filter_flux_PID;

  /* Sum: '<S134>/Sum' incorporates:
   *  DiscreteIntegrator: '<S124>/Integrator'
   *  Inport: '<Root>/Kp_flux_PID'
   *  Product: '<S129>/PProd Out'
   */
  rtb_Sum_ep = (rtb_IProdOut_l * FOC_U.Kp_flux_PID + FOC_DW.Integrator_DSTATE_p)
    + rtb_NProdOut_b;

  /* Switch: '<S132>/Switch2' incorporates:
   *  Inport: '<Root>/Low_Limit_flux_PID'
   *  Inport: '<Root>/Up_Limit_flux_PID'
   *  RelationalOperator: '<S132>/LowerRelop1'
   *  RelationalOperator: '<S132>/UpperRelop'
   *  Switch: '<S132>/Switch'
   */
  if (rtb_Sum_ep > FOC_U.Up_Limit_flux_PID) {
    /* Switch: '<S132>/Switch2' */
    FOC_Y.Vd = FOC_U.Up_Limit_flux_PID;
  } else if (rtb_Sum_ep < FOC_U.Low_Limit_flux_PID) {
    /* Switch: '<S132>/Switch2' incorporates:
     *  Inport: '<Root>/Low_Limit_flux_PID'
     *  Switch: '<S132>/Switch'
     */
    FOC_Y.Vd = FOC_U.Low_Limit_flux_PID;
  } else {
    /* Switch: '<S132>/Switch2' incorporates:
     *  Switch: '<S132>/Switch'
     */
    FOC_Y.Vd = rtb_Sum_ep;
  }

    FOC_Y.Vd = FOC_Y.Vd - FOC_U.ActualSpeed * FOC_U.Lq * FOC_Y.Iq;

  /* End of Switch: '<S132>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S9>/Two inputs CRL' */
  /* Sum: '<S7>/Sum2' incorporates:
   *  Abs: '<S25>/Abs'
   *  AlgorithmDescriptorDelegate generated from: '<S12>/a16'
   *  Math: '<S25>/Math Function3'
   *  Sqrt: '<S25>/Sqrt1'
   *  Sum: '<S25>/Subtract1'
   *
   * About '<S25>/Math Function3':
   *  Operator: magnitude^2
   */
  FOC_Y.Iq_refer = sqrt(fabs(rtb_Divide - rtb_Subtract * rtb_Subtract)); 

  rtb_Divide = sqrt(fabs(rtb_Divide - rtb_Subtract * rtb_Subtract)) - FOC_Y.Iq;

  /* End of Outputs for SubSystem: '<S9>/Two inputs CRL' */

  /* Product: '<S183>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S175>/Filter'
   *  Inport: '<Root>/Filter_torque_PID'
   *  Inport: '<Root>/Kd_torque_PID'
   *  Product: '<S173>/DProd Out'
   *  Sum: '<S175>/SumD'
   */
  rtb_Subtract = (rtb_Divide * FOC_U.Kd_torque_PID - FOC_DW.Filter_DSTATE_d) *
    FOC_U.Filter_torque_PID;

  /* Sum: '<S190>/Sum' incorporates:
   *  DiscreteIntegrator: '<S180>/Integrator'
   *  Inport: '<Root>/Kp_torque_PID'
   *  Product: '<S185>/PProd Out'
   */
  rtb_Sum_n = (rtb_Divide * FOC_U.Kp_torque_PID + FOC_DW.Integrator_DSTATE_h) +
    rtb_Subtract;

  /* Switch: '<S188>/Switch2' incorporates:
   *  Inport: '<Root>/Low_Limit_torque_PID'
   *  Inport: '<Root>/Up_Limit_torque_PID'
   *  RelationalOperator: '<S188>/LowerRelop1'
   *  RelationalOperator: '<S188>/UpperRelop'
   *  Switch: '<S188>/Switch'
   */
  if (rtb_Sum_n > FOC_U.Up_Limit_torque_PID) {
    /* Switch: '<S188>/Switch2' */
    FOC_Y.Vq = FOC_U.Up_Limit_torque_PID;
  } else if (rtb_Sum_n < FOC_U.Low_Limit_torque_PID) {
    /* Switch: '<S188>/Switch2' incorporates:
     *  Inport: '<Root>/Low_Limit_torque_PID'
     *  Switch: '<S188>/Switch'
     */
    FOC_Y.Vq = FOC_U.Low_Limit_torque_PID;
  } else {
    /* Switch: '<S188>/Switch2' incorporates:
     *  Switch: '<S188>/Switch'
     */
    FOC_Y.Vq = rtb_Sum_n;
  }

  FOC_Y.Vq = FOC_Y.Vq + FOC_U.ActualSpeed * FOC_U.Ld * FOC_Y.Id + FOC_U.ActualSpeed * FOC_U.Lamda;

  real_T Vq_ref_max = sqrtf((65.0f*65.0f) - (FOC_Y.Vd * FOC_Y.Vd));

  if (FOC_Y.Vq > Vq_ref_max)
    FOC_Y.Vq = Vq_ref_max;

  /* End of Switch: '<S188>/Switch2' */

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
  rtb_Diff = (FOC_Y.Vq * rtb_TrigonometricFunction1_tmp + FOC_Y.Vd * rtb_Add1) *
    0.8660254037844386;

  /* End of Outputs for SubSystem: '<S15>/Two inputs CRL' */

  /* Sum: '<S17>/add_b' */
  rtb_Add1 = rtb_Diff - rtb_add_c;

  /* Sum: '<S17>/add_c' */
  rtb_add_c = (0.0 - rtb_add_c) - rtb_Diff;

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
  rtb_Switch_fv_idx_0 = fmax(fmax(FOC_U.PhaseCurrent[0], FOC_U.PhaseCurrent[1]),
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
      if (!(rtb_Switch_fv_idx_0 >
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
      if (!(rtb_Switch_fv_idx_0 <
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
        if (!(rtb_Switch_fv_idx_0 <
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
      if (!(rtb_Switch_fv_idx_0 >
            FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A)) {
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
        if (!(rtb_Switch_fv_idx_0 <
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

  if (rtb_Switch_fv_idx_0 >
      FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A) {
    FOC_DW.durationCounter_1_i++;
  } else {
    FOC_DW.durationCounter_1_i = 0U;
  }

  if (rtb_Switch_fv_idx_0 <
      FOC_B.BusConversion_InsertedFor_Prote.OCWarningLimit_A) {
    FOC_DW.durationCounter_1_a++;
    FOC_DW.durationCounter_1_d++;
  } else {
    FOC_DW.durationCounter_1_a = 0U;
    FOC_DW.durationCounter_1_d = 0U;
  }

  if (rtb_Switch_fv_idx_0 < FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A)
  {
    FOC_DW.durationCounter_2_b++;
  } else {
    FOC_DW.durationCounter_2_b = 0U;
  }

  if (rtb_Switch_fv_idx_0 > FOC_B.BusConversion_InsertedFor_Prote.OCErrorLimit_A)
  {
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

  /* Switch: '<S172>/Switch' incorporates:
   *  Inport: '<Root>/Low_Limit_torque_PID'
   *  Inport: '<Root>/Up_Limit_torque_PID'
   *  RelationalOperator: '<S172>/u_GTE_up'
   *  RelationalOperator: '<S172>/u_GT_lo'
   *  Switch: '<S172>/Switch1'
   */
  if (rtb_Sum_n >= FOC_U.Up_Limit_torque_PID) {
    rtb_Diff = FOC_U.Up_Limit_torque_PID;
  } else if (rtb_Sum_n > FOC_U.Low_Limit_torque_PID) {
    /* Switch: '<S172>/Switch1' */
    rtb_Diff = rtb_Sum_n;
  } else {
    rtb_Diff = FOC_U.Low_Limit_torque_PID;
  }

  /* Sum: '<S172>/Diff' incorporates:
   *  Switch: '<S172>/Switch'
   */
  rtb_Diff = rtb_Sum_n - rtb_Diff;

  /* Product: '<S177>/IProd Out' incorporates:
   *  Inport: '<Root>/Ki_torque_PID'
   */
  rtb_Divide *= FOC_U.Ki_torque_PID;

  /* Switch: '<S169>/Switch1' incorporates:
   *  Constant: '<S169>/Clamping_zero'
   *  Constant: '<S169>/Constant'
   *  Constant: '<S169>/Constant2'
   *  RelationalOperator: '<S169>/fix for DT propagation issue'
   */
  if (rtb_Diff > 0.0) {
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
  if (rtb_Divide > 0.0) {
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
  rtb_AND3 = ((rtb_Diff != 0.0) && (tmp == tmp_0));

  /* Switch: '<S116>/Switch' incorporates:
   *  Inport: '<Root>/Low_Limit_flux_PID'
   *  Inport: '<Root>/Up_Limit_flux_PID'
   *  RelationalOperator: '<S116>/u_GTE_up'
   *  RelationalOperator: '<S116>/u_GT_lo'
   *  Switch: '<S116>/Switch1'
   */
  if (rtb_Sum_ep >= FOC_U.Up_Limit_flux_PID) {
    rtb_Diff = FOC_U.Up_Limit_flux_PID;
  } else if (rtb_Sum_ep > FOC_U.Low_Limit_flux_PID) {
    /* Switch: '<S116>/Switch1' */
    rtb_Diff = rtb_Sum_ep;
  } else {
    rtb_Diff = FOC_U.Low_Limit_flux_PID;
  }

  /* Sum: '<S116>/Diff' incorporates:
   *  Switch: '<S116>/Switch'
   */
  rtb_Diff = rtb_Sum_ep - rtb_Diff;

  /* Product: '<S121>/IProd Out' incorporates:
   *  Inport: '<Root>/Ki_flux_PID'
   */
  rtb_IProdOut_l *= FOC_U.Ki_flux_PID;

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
  if (rtb_IProdOut_l > 0.0) {
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
  rtb_AND3_g = ((rtb_Diff != 0.0) && (tmp == tmp_0));

  /* Switch: '<S60>/Switch' incorporates:
   *  Inport: '<Root>/Low_Limit_speed_PID'
   *  Inport: '<Root>/Up_Limit_speed_PID'
   *  RelationalOperator: '<S60>/u_GTE_up'
   *  RelationalOperator: '<S60>/u_GT_lo'
   *  Switch: '<S60>/Switch1'
   */
  if (rtb_Sum >= FOC_U.Up_Limit_speed_PID) {
    rtb_Diff = FOC_U.Up_Limit_speed_PID;
  } else if (rtb_Sum > FOC_U.Low_Limit_speed_PID) {
    /* Switch: '<S60>/Switch1' */
    rtb_Diff = rtb_Sum;
  } else {
    rtb_Diff = FOC_U.Low_Limit_speed_PID;
  }

  /* Sum: '<S60>/Diff' incorporates:
   *  Switch: '<S60>/Switch'
   */
  rtb_Diff = rtb_Sum - rtb_Diff;

  /* Product: '<S65>/IProd Out' incorporates:
   *  Inport: '<Root>/Ki_speed_PID'
   */
  rtb_IProdOut *= FOC_U.Ki_speed_PID;

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
  if (rtb_AND3_g) {
    rtb_IProdOut_l = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S124>/Integrator' incorporates:
   *  Switch: '<S113>/Switch'
   */
  FOC_DW.Integrator_DSTATE_p += 1.0E-5 * rtb_IProdOut_l;

  /* Update for DiscreteIntegrator: '<S119>/Filter' */
  FOC_DW.Filter_DSTATE_k += 1.0E-5 * rtb_NProdOut_b;

  /* Switch: '<S169>/Switch' incorporates:
   *  Constant: '<S169>/Constant1'
   */
  if (rtb_AND3) {
    rtb_Divide = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S180>/Integrator' incorporates:
   *  Switch: '<S169>/Switch'
   */
  FOC_DW.Integrator_DSTATE_h += 1.0E-5 * rtb_Divide;

  /* Update for DiscreteIntegrator: '<S175>/Filter' */
  FOC_DW.Filter_DSTATE_d += 1.0E-5 * rtb_Subtract;
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
  FOC_DW.Integrator_DSTATE_p = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Filter' */
  FOC_DW.Filter_DSTATE_k = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S180>/Integrator' */
  FOC_DW.Integrator_DSTATE_h = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S175>/Filter' */
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

  FOC_U.Id_up_limit = 0.0;
  FOC_U.Id_low_limit = -15.0f;
  FOC_U.Iq_up_limit = 500.0f;
  FOC_U.Iq_low_limit = 0.0f;

  FOC_U.Kp_speed_PID = 5;
  FOC_U.Ki_speed_PID = 18;
  FOC_U.Kd_speed_PID = 0.01;
  FOC_U.Filter_speed_PID = 10.0;
  FOC_U.Up_Limit_speed_PID = 500.0;
  FOC_U.Low_Limit_speed_PID = 0.0;

  FOC_U.Kp_flux_PID = 0.8;
  FOC_U.Ki_flux_PID = 28.0;
  FOC_U.Kd_flux_PID = 0.05;
  FOC_U.Filter_flux_PID = 10.0;
  FOC_U.Up_Limit_flux_PID = 65.0;
  FOC_U.Low_Limit_flux_PID = -65.0;

  FOC_U.Kp_torque_PID = 0.7;
  FOC_U.Ki_torque_PID = 18.0;
  FOC_U.Kd_torque_PID = 0.01;
  FOC_U.Filter_torque_PID = 10.0;
  FOC_U.Up_Limit_torque_PID = 65.0;
  FOC_U.Low_Limit_torque_PID = -65.0;

  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
}

/* Model terminate function */
void FOC_terminate(void)
{
  /* (no terminate code required) */
}
