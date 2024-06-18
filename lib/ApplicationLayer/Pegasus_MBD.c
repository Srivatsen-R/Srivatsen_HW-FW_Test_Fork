/*
 * File: Pegasus_MBD.c
 *
 * Code generated for Simulink model 'Pegasus_MBD'.
 *
 * Model version                  : 1.174
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Jun 17 15:20:30 2024
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
#include "rtwtypes.h"
#include "vector_control.h"
#include <math.h>

/* Named constants for Chart: '<S6>/Va_Saturation2' */
#define IN_Lobby                       ((uint8_T)1U)
#define IN_Lobby1                      ((uint8_T)2U)
#define IN_Lobby2                      ((uint8_T)3U)

/* Named constants for Chart: '<S6>/Iq_Refer_Saturation1' */
#define IN_Lobby1_j                    ((uint8_T)2U)
#define IN_Lobby2_f                    ((uint8_T)3U)
#define IN_Lobby_k                     ((uint8_T)1U)

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void Va_Saturation2_Init(real32_T *rty_Out);
static void Va_Saturation2(real32_T rtu_In, real32_T rtu_BusVoltage_V, real32_T *
  rty_Out, DW_Va_Saturation2 *localDW);

/*
 * System initialize for atomic system:
 *    '<S6>/Va_Saturation2'
 *    '<S6>/Va_Saturation3'
 *    '<S6>/Va_Saturation4'
 */
static void Va_Saturation2_Init(real32_T *rty_Out)
{
  *rty_Out = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S6>/Va_Saturation2'
 *    '<S6>/Va_Saturation3'
 *    '<S6>/Va_Saturation4'
 */
static void Va_Saturation2(real32_T rtu_In, real32_T rtu_BusVoltage_V, real32_T *
  rty_Out, DW_Va_Saturation2 *localDW)
{
  /* Chart: '<S6>/Va_Saturation2' */
  if ((uint32_T)localDW->is_active_c1_Pegasus_MBD == 0U) {
    localDW->is_active_c1_Pegasus_MBD = 1U;
    localDW->is_c1_Pegasus_MBD = IN_Lobby;
  } else {
    switch (localDW->is_c1_Pegasus_MBD) {
     case IN_Lobby:
      if (rtu_In <= -rtu_BusVoltage_V) {
        localDW->is_c1_Pegasus_MBD = IN_Lobby1;
      } else if (rtu_In >= rtu_BusVoltage_V) {
        localDW->is_c1_Pegasus_MBD = IN_Lobby2;
      } else {
        *rty_Out = rtu_In;
      }
      break;

     case IN_Lobby1:
      if (rtu_In > -rtu_BusVoltage_V) {
        localDW->is_c1_Pegasus_MBD = IN_Lobby;
      } else {
        *rty_Out = -rtu_BusVoltage_V;
      }
      break;

     default:
      /* case IN_Lobby2: */
      if (rtu_In < rtu_BusVoltage_V) {
        localDW->is_c1_Pegasus_MBD = IN_Lobby;
      } else {
        *rty_Out = rtu_BusVoltage_V;
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Va_Saturation2' */
}

/* Model step function */
void Pegasus_MBD_step(void)
{
  /* local block i/o variables */
  real32_T rtb_NProdOut;
  real32_T rtb_NProdOut_l;
  real32_T rtb_IProdOut;
  real32_T rtb_IProdOut_o;
  real32_T rtb_Abs1;
  real32_T rtb_Abs1_m;
  real32_T rtb_Abs_h;
  real32_T rtb_Sum;
  real32_T rtb_Switch_idx_0;
  real32_T rtb_Switch_idx_1;

  /* Outputs for Atomic SubSystem: '<S6>/Clarke Transform' */
  /* Gain: '<S7>/one_by_sqrt3' incorporates:
   *  Inport: '<Root>/I_a'
   *  Inport: '<Root>/I_b'
   *  Sum: '<S7>/a_plus_2b'
   */
  rtb_Abs_h = (rtU.I_a + rtU.I_b + rtU.I_b) * 0.577350259F;

  /* End of Outputs for SubSystem: '<S6>/Clarke Transform' */

  /* Sum: '<S2>/Add' incorporates:
   *  Gain: '<S2>/Gain'
   *  Inport: '<Root>/MtrPos_rad'
   */
  rtb_Abs1_m = (rtU.MtrPos_rad) - -3.14159274F;

  /* Trigonometry: '<S6>/Sin' incorporates:
   *  Trigonometry: '<S6>/Sin1'
   */
  rtb_Abs1 = sinf(rtb_Abs1_m);

  /* Trigonometry: '<S6>/Cos' incorporates:
   *  Trigonometry: '<S6>/Cos1'
   */
  rtb_Abs1_m = cosf(rtb_Abs1_m);

  /* Outputs for Atomic SubSystem: '<S6>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S6>/Clarke Transform' */
  /* Switch: '<S119>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S7>/a16'
   *  Inport: '<Root>/I_a'
   *  Product: '<S18>/acos'
   *  Product: '<S18>/asin'
   *  Product: '<S18>/bcos'
   *  Product: '<S18>/bsin'
   *  Sum: '<S18>/sum_Ds'
   *  Sum: '<S18>/sum_Qs'
   *  Trigonometry: '<S6>/Cos'
   *  Trigonometry: '<S6>/Sin'
   */
  rtb_Switch_idx_0 = (rtU.I_a * rtb_Abs1_m) + (rtb_Abs_h * rtb_Abs1);
  rtb_Switch_idx_1 = (rtb_Abs_h * rtb_Abs1_m) - (rtU.I_a * rtb_Abs1);

  /* End of Outputs for SubSystem: '<S6>/Clarke Transform' */

  /* BusCreator: '<S6>/Bus Creator' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
   *  Outport: '<Root>/FOC_Out'
   */
  rtY.FOC_Out.Id_Calculated = rtb_Switch_idx_0;
  rtY.FOC_Out.Iq_Calculated = rtb_Switch_idx_1;

  /* Sum: '<S6>/Add2' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
   *  Constant: '<S6>/Constant3'
   */
  rtb_Abs_h = 0.0F - rtb_Switch_idx_0;

  /* Product: '<S105>/NProd Out' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
   *  Constant: '<S6>/Constant3'
   *  DiscreteIntegrator: '<S97>/Filter'
   *  Inport: '<Root>/FilterCoefficient'
   *  Inport: '<Root>/Gain_Dd'
   *  Product: '<S96>/DProd Out'
   *  Sum: '<S6>/Add2'
   *  Sum: '<S97>/SumD'
   */
  rtb_NProdOut = (((0.0F - rtb_Switch_idx_0) * rtU.Dd) - rtDW.Filter_DSTATE) *
    rtU.FilterCoefficient;

  /* Sum: '<S111>/Sum' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
   *  Constant: '<S6>/Constant3'
   *  DiscreteIntegrator: '<S102>/Integrator'
   *  Inport: '<Root>/Gain_Pd'
   *  Product: '<S107>/PProd Out'
   *  Sum: '<S6>/Add2'
   */
  rtb_Sum = ((0.0F - rtb_Switch_idx_0) * rtU.Pd) + rtDW.Integrator_DSTATE +
    rtb_NProdOut;

  /* End of Outputs for SubSystem: '<S6>/Park Transform' */

  /* Chart: '<S6>/Iq_Refer_Saturation3' incorporates:
   *  Inport: '<Root>/Thresholds'
   */
  if ((uint32_T)rtDW.is_active_c6_Pegasus_MBD == 0U) {
    rtDW.is_active_c6_Pegasus_MBD = 1U;
    rtDW.is_c6_Pegasus_MBD = IN_Lobby_k;
  } else {
    switch (rtDW.is_c6_Pegasus_MBD) {
     case IN_Lobby_k:
      if (rtb_Sum <= rtU.Thresholds.Vd_min_limit_V) {
        rtDW.is_c6_Pegasus_MBD = IN_Lobby1_j;
      } else if (rtb_Sum >= rtU.Thresholds.Vd_max_limit_V) {
        rtDW.is_c6_Pegasus_MBD = IN_Lobby2_f;
      } else {
        rtDW.Out_o = rtb_Sum;
      }
      break;

     case IN_Lobby1_j:
      if (rtb_Sum > rtU.Thresholds.Vd_min_limit_V) {
        rtDW.is_c6_Pegasus_MBD = IN_Lobby_k;
      } else {
        rtDW.Out_o = rtU.Thresholds.Vd_min_limit_V;
      }
      break;

     default:
      /* case IN_Lobby2: */
      if (rtb_Sum < rtU.Thresholds.Vd_max_limit_V) {
        rtDW.is_c6_Pegasus_MBD = IN_Lobby_k;
      } else {
        rtDW.Out_o = rtU.Thresholds.Vd_max_limit_V;
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Iq_Refer_Saturation3' */

  /* Product: '<S6>/Product' incorporates:
   *  Inport: '<Root>/Iq_Torque_ratio'
   *  Inport: '<Root>/Torque'
   */
  rtb_Sum = rtU.Torque * rtU.Iq_Torque_ratio;

  /* Chart: '<S6>/Iq_Refer_Saturation1' incorporates:
   *  Inport: '<Root>/Thresholds'
   */
  if ((uint32_T)rtDW.is_active_c5_Pegasus_MBD == 0U) {
    rtDW.is_active_c5_Pegasus_MBD = 1U;
    rtDW.is_c5_Pegasus_MBD = IN_Lobby_k;
  } else {
    switch (rtDW.is_c5_Pegasus_MBD) {
     case IN_Lobby_k:
      if (rtb_Sum <= rtU.Thresholds.Iq_min_limit_A) {
        rtDW.is_c5_Pegasus_MBD = IN_Lobby1_j;
      } else if (rtb_Sum >= rtU.Thresholds.Iq_max_limit_A) {
        rtDW.is_c5_Pegasus_MBD = IN_Lobby2_f;
      } else {
        rtDW.Out_m2 = rtb_Sum;
      }
      break;

     case IN_Lobby1_j:
      if (rtb_Sum > rtU.Thresholds.Iq_min_limit_A) {
        rtDW.is_c5_Pegasus_MBD = IN_Lobby_k;
      } else {
        rtDW.Out_m2 = rtU.Thresholds.Iq_min_limit_A;
      }
      break;

     default:
      /* case IN_Lobby2: */
      if (rtb_Sum < rtU.Thresholds.Iq_max_limit_A) {
        rtDW.is_c5_Pegasus_MBD = IN_Lobby_k;
      } else {
        rtDW.Out_m2 = rtU.Thresholds.Iq_max_limit_A;
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Iq_Refer_Saturation1' */

  /* Outputs for Atomic SubSystem: '<S6>/Park Transform' */
  /* Sum: '<S6>/Add3' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
   */
  rtb_Sum = rtDW.Out_m2 - rtb_Switch_idx_1;

  /* End of Outputs for SubSystem: '<S6>/Park Transform' */

  /* Product: '<S57>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S49>/Filter'
   *  Inport: '<Root>/FilterCoefficient'
   *  Inport: '<Root>/Gain_Dq'
   *  Product: '<S48>/DProd Out'
   *  Sum: '<S49>/SumD'
   */
  rtb_NProdOut_l = ((rtb_Sum * rtU.Dq) - rtDW.Filter_DSTATE_f) *
    rtU.FilterCoefficient;

  /* Sum: '<S63>/Sum' incorporates:
   *  DiscreteIntegrator: '<S54>/Integrator'
   *  Inport: '<Root>/Gain_Pq'
   *  Product: '<S59>/PProd Out'
   */
  rtb_Switch_idx_0 = (rtb_Sum * rtU.Pq) + rtDW.Integrator_DSTATE_e +
    rtb_NProdOut_l;

  /* Chart: '<S6>/Iq_Refer_Saturation2' incorporates:
   *  Inport: '<Root>/Thresholds'
   */
  if ((uint32_T)rtDW.is_active_c3_Pegasus_MBD == 0U) {
    rtDW.is_active_c3_Pegasus_MBD = 1U;
    rtDW.is_c3_Pegasus_MBD = IN_Lobby_k;
  } else {
    switch (rtDW.is_c3_Pegasus_MBD) {
     case IN_Lobby_k:
      if (rtb_Switch_idx_0 <= rtU.Thresholds.Vq_min_limit_V) {
        rtDW.is_c3_Pegasus_MBD = IN_Lobby1_j;
      } else if (rtb_Switch_idx_0 >= rtU.Thresholds.Vq_max_limit_V) {
        rtDW.is_c3_Pegasus_MBD = IN_Lobby2_f;
      } else {
        rtDW.Out_h = rtb_Switch_idx_0;
      }
      break;

     case IN_Lobby1_j:
      if (rtb_Switch_idx_0 > rtU.Thresholds.Vq_min_limit_V) {
        rtDW.is_c3_Pegasus_MBD = IN_Lobby_k;
      } else {
        rtDW.Out_h = rtU.Thresholds.Vq_min_limit_V;
      }
      break;

     default:
      /* case IN_Lobby2: */
      if (rtb_Switch_idx_0 < rtU.Thresholds.Vq_max_limit_V) {
        rtDW.is_c3_Pegasus_MBD = IN_Lobby_k;
      } else {
        rtDW.Out_h = rtU.Thresholds.Vq_max_limit_V;
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Iq_Refer_Saturation2' */

  /* Outputs for Atomic SubSystem: '<S6>/Inverse Park Transform' */
  /* Switch: '<S22>/Switch' incorporates:
   *  Product: '<S9>/dcos'
   *  Product: '<S9>/dsin'
   *  Product: '<S9>/qcos'
   *  Product: '<S9>/qsin'
   *  Sum: '<S9>/sum_alpha'
   *  Sum: '<S9>/sum_beta'
   */
  rtb_Switch_idx_0 = (rtDW.Out_o * rtb_Abs1_m) - (rtDW.Out_h * rtb_Abs1);
  rtb_Switch_idx_1 = (rtDW.Out_h * rtb_Abs1_m) + (rtDW.Out_o * rtb_Abs1);

  /* Chart: '<S6>/Va_Saturation2' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   *  Inport: '<Root>/Thresholds'
   */
  Va_Saturation2(rtb_Switch_idx_0, rtU.Thresholds.BusVoltage_V, &rtDW.Out_d,
                 &rtDW.sf_Va_Saturation2);

  /* Gain: '<S8>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   */
  rtb_Abs1_m = 0.5F * rtb_Switch_idx_0;

  /* Gain: '<S8>/sqrt3_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   */
  rtb_Abs1 = 0.866025388F * rtb_Switch_idx_1;

  /* End of Outputs for SubSystem: '<S6>/Inverse Park Transform' */

  /* Chart: '<S6>/Va_Saturation3' incorporates:
   *  Inport: '<Root>/Thresholds'
   *  Sum: '<S8>/add_b'
   */
  Va_Saturation2(rtb_Abs1 - rtb_Abs1_m, rtU.Thresholds.BusVoltage_V, &rtDW.Out_m,
                 &rtDW.sf_Va_Saturation3);

  /* Chart: '<S6>/Va_Saturation4' incorporates:
   *  Inport: '<Root>/Thresholds'
   *  Sum: '<S8>/add_c'
   */
  Va_Saturation2(0.0F - rtb_Abs1_m - rtb_Abs1, rtU.Thresholds.BusVoltage_V,
                 &rtDW.Out, &rtDW.sf_Va_Saturation4);

  /* BusCreator: '<S6>/Bus Creator' incorporates:
   *  Constant: '<S6>/Constant3'
   *  Gain: '<S13>/Gain'
   *  Gain: '<S14>/Gain'
   *  Gain: '<S15>/Gain'
   *  Inport: '<Root>/Thresholds'
   *  Outport: '<Root>/FOC_Out'
   *  Product: '<S13>/Divide'
   *  Product: '<S14>/Divide'
   *  Product: '<S15>/Divide'
   */
  rtY.FOC_Out.Id_Refer = 0.0F;
  rtY.FOC_Out.Iq_Refer = rtDW.Out_m2;
  rtY.FOC_Out.Vd_Calculated = rtDW.Out_o;
  rtY.FOC_Out.Vq_Calculated = rtDW.Out_h;
  rtY.FOC_Out.Va = rtDW.Out_d;
  rtY.FOC_Out.Vb = rtDW.Out_m;
  rtY.FOC_Out.Vc = rtDW.Out;
  rtY.FOC_Out.Normalized_Va = (32767.00F * rtDW.Out_d) /
    rtU.Thresholds.BusVoltage_V;
  rtY.FOC_Out.Normalized_Vb = (32767.00F * rtDW.Out_m) /
    rtU.Thresholds.BusVoltage_V;
  rtY.FOC_Out.Normalized_Vc = (32767.00F * rtDW.Out) /
    rtU.Thresholds.BusVoltage_V;

  /* Product: '<S5>/Divide' incorporates:
   *  Inport: '<Root>/Thresholds'
   *  Product: '<S3>/Divide'
   *  Product: '<S4>/Divide'
   */
  rtb_Switch_idx_0 = 1.0F / rtU.Thresholds.BusVoltage_V;
  rtb_Abs1 = rtb_Switch_idx_0 * rtDW.Out;

  /* Product: '<S3>/Divide' */
  rtb_Abs1_m = rtb_Switch_idx_0 * rtDW.Out_d;

  /* Product: '<S4>/Divide' */
  rtb_Switch_idx_0 *= rtDW.Out_m;

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Zero'
   */
  if (rtDW.Out_d > 0.0F) {
    rtb_Switch_idx_1 = rtb_Abs1_m;
  } else {
    rtb_Switch_idx_1 = 0.0F;
  }

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Abs: '<S3>/Abs'
   *  Outport: '<Root>/DutyCylces'
   *  Switch: '<S3>/Switch'
   */
  rtY.DutyCylces.Duty_a_pos = fabsf(rtb_Switch_idx_1);

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/Zero'
   *  Gain: '<S3>/Gain'
   */
  if (!(-rtDW.Out_d > 0.0F)) {
    rtb_Abs1_m = 0.0F;
  }

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Abs: '<S3>/Abs1'
   *  Outport: '<Root>/DutyCylces'
   *  Switch: '<S3>/Switch1'
   */
  rtY.DutyCylces.Duty_a_neg = fabsf(rtb_Abs1_m);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Zero'
   */
  if (rtDW.Out_m > 0.0F) {
    rtb_Switch_idx_1 = rtb_Switch_idx_0;
  } else {
    rtb_Switch_idx_1 = 0.0F;
  }

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Abs: '<S4>/Abs'
   *  Outport: '<Root>/DutyCylces'
   *  Switch: '<S4>/Switch'
   */
  rtY.DutyCylces.Duty_b_pos = fabsf(rtb_Switch_idx_1);

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/Zero'
   *  Gain: '<S4>/Gain'
   */
  if (!(-rtDW.Out_m > 0.0F)) {
    rtb_Switch_idx_0 = 0.0F;
  }

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Abs: '<S4>/Abs1'
   *  Outport: '<Root>/DutyCylces'
   *  Switch: '<S4>/Switch1'
   */
  rtY.DutyCylces.Duty_b_neg = fabsf(rtb_Switch_idx_0);

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Zero'
   */
  if (rtDW.Out > 0.0F) {
    rtb_Switch_idx_1 = rtb_Abs1;
  } else {
    rtb_Switch_idx_1 = 0.0F;
  }

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Abs: '<S5>/Abs'
   *  Outport: '<Root>/DutyCylces'
   *  Switch: '<S5>/Switch'
   */
  rtY.DutyCylces.Duty_c_pos = fabsf(rtb_Switch_idx_1);

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Zero'
   *  Gain: '<S5>/Gain'
   */
  if (!(-rtDW.Out > 0.0F)) {
    rtb_Abs1 = 0.0F;
  }

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Abs: '<S5>/Abs1'
   *  Outport: '<Root>/DutyCylces'
   *  Switch: '<S5>/Switch1'
   */
  rtY.DutyCylces.Duty_c_neg = fabsf(rtb_Abs1);

  /* Product: '<S51>/IProd Out' incorporates:
   *  Inport: '<Root>/Gain_Iq'
   */
  rtb_IProdOut = rtb_Sum * rtU.Iq;

  /* Product: '<S99>/IProd Out' incorporates:
   *  Inport: '<Root>/Gain_Id'
   */
  rtb_IProdOut_o = rtb_Abs_h * rtU.Id;

  /* Update for DiscreteIntegrator: '<S102>/Integrator' */
  rtDW.Integrator_DSTATE += 5.0E-5F * rtb_IProdOut_o;

  /* Update for DiscreteIntegrator: '<S97>/Filter' */
  rtDW.Filter_DSTATE += 5.0E-5F * rtb_NProdOut;

  /* Update for DiscreteIntegrator: '<S54>/Integrator' */
  rtDW.Integrator_DSTATE_e += 5.0E-5F * rtb_IProdOut;

  /* Update for DiscreteIntegrator: '<S49>/Filter' */
  rtDW.Filter_DSTATE_f += 5.0E-5F * rtb_NProdOut_l;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rtM->Timing.t[0] =
    ((time_T)(++rtM->Timing.clockTick0)) * rtM->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [5.0E-5s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 5.0E-5, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Pegasus_MBD_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&rtM->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 5.0E-5;

  /* SystemInitialize for Chart: '<S6>/Va_Saturation2' */
  Va_Saturation2_Init(&rtDW.Out_d);

  /* SystemInitialize for Chart: '<S6>/Va_Saturation3' */
  Va_Saturation2_Init(&rtDW.Out_m);

  /* SystemInitialize for Chart: '<S6>/Va_Saturation4' */
  Va_Saturation2_Init(&rtDW.Out);

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
  rtU.Thresholds.Iq_max_limit_A = 20.0;
  rtU.Thresholds.Iq_min_limit_A = -20.0;
  rtU.Thresholds.Vq_max_limit_V = 35.0;
  rtU.Thresholds.Vq_min_limit_V = -35.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
