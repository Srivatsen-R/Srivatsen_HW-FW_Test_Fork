/*
 * FOC.c
 *
 * Code generation for model "FOC".
 *
 * Model version              : 18.7
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Sat Oct  5 13:15:42 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FOC.h"
#include <math.h>
#include "rtwtypes.h"
#include "vector_control.h"
#include "motor_param.h"
#include <string.h>
#include "FOC_private.h"

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

/* Real-time model */
static RT_MODEL_FOC_T FOC_M_;
RT_MODEL_FOC_T *const FOC_M = &FOC_M_;

/* Model step function */
void FOC_step(void)
{
  real_T rtb_Diff;
  real_T rtb_IProdOut_d;
  real_T rtb_NProdOut_l;
  real_T rtb_Sum_eh;
  real_T rtb_Switch_f_idx_0;
  real_T rtb_TrigonometricFunction1_tmp;
  real_T rtb_add_c;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_AND3;
  boolean_T rtb_AND3_f;

  /* Outputs for Atomic SubSystem: '<S7>/Two phase CRL wrap' */
  /* Gain: '<S8>/one_by_sqrt3' incorporates:
   *  Inport: '<Root>/Phase Current'
   *  Sum: '<S8>/a_plus_2b'
   */
  rtb_Diff = ((FOC_U.PhaseCurrent[0] + FOC_U.PhaseCurrent[1]) +
              FOC_U.PhaseCurrent[1]) * 0.57735026918962584;

  /* End of Outputs for SubSystem: '<S7>/Two phase CRL wrap' */

  /* Trigonometry: '<S2>/Trigonometric Function' incorporates:
   *  Inport: '<Root>/angle'
   *  Trigonometry: '<S3>/Trigonometric Function1'
   */

  if (forward_set)
    FOC_U.angle = (FOC_U.angle);
  else if (reverse_set)
    FOC_U.angle = (FOC_U.angle) - -3.14159274F;

  FOC_B.Add1 = sin(FOC_U.angle);

  /* Trigonometry: '<S2>/Trigonometric Function1' incorporates:
   *  Inport: '<Root>/angle'
   *  Trigonometry: '<S3>/Trigonometric Function'
   */
  rtb_TrigonometricFunction1_tmp = cos(FOC_U.angle);

  /* Outputs for Atomic SubSystem: '<S6>/Two inputs CRL' */
  /* Outputs for Atomic SubSystem: '<S7>/Two phase CRL wrap' */
  /* Switch: '<S10>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S8>/a16'
   *  Inport: '<Root>/Phase Current'
   *  Product: '<S9>/acos'
   *  Product: '<S9>/bsin'
   *  Sum: '<S9>/sum_Ds'
   *  Trigonometry: '<S2>/Trigonometric Function'
   *  Trigonometry: '<S2>/Trigonometric Function1'
   */
  rtb_Switch_f_idx_0 = FOC_U.PhaseCurrent[0] * rtb_TrigonometricFunction1_tmp +
    rtb_Diff * FOC_B.Add1;

  /* Switch: '<S16>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S8>/a16'
   *  Inport: '<Root>/Phase Current'
   *  Product: '<S9>/asin'
   *  Product: '<S9>/bcos'
   *  Sum: '<S9>/sum_Qs'
   *  Switch: '<S10>/Switch'
   *  Trigonometry: '<S2>/Trigonometric Function'
   *  Trigonometry: '<S2>/Trigonometric Function1'
   */
  FOC_Y.Iq = rtb_Diff * rtb_TrigonometricFunction1_tmp - FOC_U.PhaseCurrent[0] *
    FOC_B.Add1;

  /* End of Outputs for SubSystem: '<S7>/Two phase CRL wrap' */

  /* Outport: '<Root>/Id' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   */
  FOC_Y.Id = rtb_Switch_f_idx_0;

  /* Sum: '<S4>/Sum3' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   *  Constant: '<S4>/Id_ref'
   */
  FOC_B.IProdOut = -15.0f - rtb_Switch_f_idx_0;

  /* Product: '<S121>/NProd Out' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   *  Constant: '<S4>/Id_ref'
   *  DiscreteIntegrator: '<S113>/Filter'
   *  Inport: '<Root>/Filter_flux_PID'
   *  Inport: '<Root>/Kd_flux_PID'
   *  Product: '<S111>/DProd Out'
   *  Sum: '<S113>/SumD'
   *  Sum: '<S4>/Sum3'
   */
  FOC_B.NProdOut = ((0.0 - rtb_Switch_f_idx_0) * FOC_U.Kd_flux_PID -
                    FOC_DW.Filter_DSTATE) * FOC_U.Filter_flux_PID;

  /* Sum: '<S128>/Sum' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   *  Constant: '<S4>/Id_ref'
   *  DiscreteIntegrator: '<S118>/Integrator'
   *  Inport: '<Root>/Kp_flux_PID'
   *  Product: '<S123>/PProd Out'
   *  Sum: '<S4>/Sum3'
   */
  FOC_B.Sum = ((0.0 - rtb_Switch_f_idx_0) * FOC_U.Kp_flux_PID +
               FOC_DW.Integrator_DSTATE) + FOC_B.NProdOut;

  /* End of Outputs for SubSystem: '<S6>/Two inputs CRL' */

  /* Switch: '<S126>/Switch2' incorporates:
   *  Inport: '<Root>/Low_Limit_flux_PID'
   *  Inport: '<Root>/Up_Limit_flux_PID'
   *  RelationalOperator: '<S126>/LowerRelop1'
   *  RelationalOperator: '<S126>/UpperRelop'
   *  Switch: '<S126>/Switch'
   */
  if (FOC_B.Sum > FOC_U.Up_Limit_flux_PID) {
    /* Switch: '<S126>/Switch2' */
    FOC_Y.Vd = FOC_U.Up_Limit_flux_PID;
  } else if (FOC_B.Sum < FOC_U.Low_Limit_flux_PID) {
    /* Switch: '<S126>/Switch2' incorporates:
     *  Inport: '<Root>/Low_Limit_flux_PID'
     *  Switch: '<S126>/Switch'
     */
    FOC_Y.Vd = FOC_U.Low_Limit_flux_PID;
  } else {
    /* Switch: '<S126>/Switch2' incorporates:
     *  Switch: '<S126>/Switch'
     */
    FOC_Y.Vd = FOC_B.Sum;
  }

  FOC_Y.Vd = FOC_Y.Vd - FOC_U.ActualSpeed * FOC_U.Lq * FOC_Y.Iq;

  /* End of Switch: '<S126>/Switch2' */

  /* Sum: '<S4>/Sum1' incorporates:
   *  Inport: '<Root>/Actual Speed'
   *  Inport: '<Root>/Ref Speed'
   */
  FOC_B.IProdOut_e = FOC_U.RefSpeed - FOC_U.ActualSpeed;

  /* Product: '<S65>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S57>/Filter'
   *  Inport: '<Root>/Filter_speed_PID'
   *  Inport: '<Root>/Kd_speed_PID'
   *  Product: '<S55>/DProd Out'
   *  Sum: '<S57>/SumD'
   */
  FOC_B.NProdOut_k = (FOC_B.IProdOut_e * FOC_U.Kd_speed_PID -
                      FOC_DW.Filter_DSTATE_c) * FOC_U.Filter_speed_PID;

  /* Sum: '<S72>/Sum' incorporates:
   *  DiscreteIntegrator: '<S62>/Integrator'
   *  Inport: '<Root>/Kp_speed_PID'
   *  Product: '<S67>/PProd Out'
   */
  FOC_B.Sum_f = (FOC_B.IProdOut_e * FOC_U.Kp_speed_PID +
                 FOC_DW.Integrator_DSTATE_g) + FOC_B.NProdOut_k;

  /* Switch: '<S70>/Switch2' incorporates:
   *  Inport: '<Root>/Low_Limit_speed_PID'
   *  Inport: '<Root>/Up_Limit_speed_PID'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  RelationalOperator: '<S70>/UpperRelop'
   *  Switch: '<S70>/Switch'
   */
  if (FOC_B.Sum_f > FOC_U.Up_Limit_speed_PID) {
    rtb_Diff = FOC_U.Up_Limit_speed_PID;
  } else if (FOC_B.Sum_f < FOC_U.Low_Limit_speed_PID) {
    /* Switch: '<S70>/Switch' incorporates:
     *  Inport: '<Root>/Low_Limit_speed_PID'
     */
    rtb_Diff = FOC_U.Low_Limit_speed_PID;
  } else {
    rtb_Diff = FOC_B.Sum_f;
  }

  /* Outputs for Atomic SubSystem: '<S6>/Two inputs CRL' */
  /* Sum: '<S4>/Sum2' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S9>/a16'
   *  Switch: '<S70>/Switch2'
   */
  rtb_IProdOut_d = rtb_Diff - FOC_Y.Iq;

  /* End of Outputs for SubSystem: '<S6>/Two inputs CRL' */

  /* Product: '<S177>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S169>/Filter'
   *  Inport: '<Root>/Filter_torque_PID'
   *  Inport: '<Root>/Kd_torque_PID'
   *  Product: '<S167>/DProd Out'
   *  Sum: '<S169>/SumD'
   */
  rtb_NProdOut_l = (rtb_IProdOut_d * FOC_U.Kd_torque_PID -
                    FOC_DW.Filter_DSTATE_d) * FOC_U.Filter_torque_PID;

  /* Sum: '<S184>/Sum' incorporates:
   *  DiscreteIntegrator: '<S174>/Integrator'
   *  Inport: '<Root>/Kp_torque_PID'
   *  Product: '<S179>/PProd Out'
   */
  rtb_Sum_eh = (rtb_IProdOut_d * FOC_U.Kp_torque_PID +
                FOC_DW.Integrator_DSTATE_h) + rtb_NProdOut_l;

  /* Switch: '<S182>/Switch2' incorporates:
   *  Inport: '<Root>/Low_Limit_torque_PID'
   *  Inport: '<Root>/Up_Limit_torque_PID'
   *  RelationalOperator: '<S182>/LowerRelop1'
   *  RelationalOperator: '<S182>/UpperRelop'
   *  Switch: '<S182>/Switch'
   */
  if (rtb_Sum_eh > FOC_U.Up_Limit_torque_PID) {
    /* Switch: '<S182>/Switch2' */
    FOC_Y.Vq = FOC_U.Up_Limit_torque_PID;
  } else if (rtb_Sum_eh < FOC_U.Low_Limit_torque_PID) {
    /* Switch: '<S182>/Switch2' incorporates:
     *  Inport: '<Root>/Low_Limit_torque_PID'
     *  Switch: '<S182>/Switch'
     */
    FOC_Y.Vq = FOC_U.Low_Limit_torque_PID;
  } else {
    /* Switch: '<S182>/Switch2' incorporates:
     *  Switch: '<S182>/Switch'
     */
    FOC_Y.Vq = rtb_Sum_eh;
  }

  FOC_Y.Vq = FOC_Y.Vq + FOC_U.ActualSpeed * FOC_U.Ld * FOC_Y.Id + FOC_U.ActualSpeed * FOC_U.Lamda;

  real_T Vq_ref_max = sqrtf((65.0f*65.0f) - (FOC_Y.Vd * FOC_Y.Vd));

  if (FOC_Y.Vq > Vq_ref_max)
    FOC_Y.Vq = Vq_ref_max;

  /* End of Switch: '<S182>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S12>/Two inputs CRL' */
  /* Switch: '<S16>/Switch' incorporates:
   *  Product: '<S15>/dcos'
   *  Product: '<S15>/qsin'
   *  Sum: '<S15>/sum_alpha'
   */
  rtb_Switch_f_idx_0 = FOC_Y.Vd * rtb_TrigonometricFunction1_tmp - FOC_Y.Vq *
    FOC_B.Add1;

  /* Gain: '<S14>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S15>/a16'
   */
  rtb_add_c = 0.5 * rtb_Switch_f_idx_0;

  /* Gain: '<S14>/sqrt3_by_two' incorporates:
   *  Product: '<S15>/dsin'
   *  Product: '<S15>/qcos'
   *  Sum: '<S15>/sum_beta'
   */
  rtb_Diff = (FOC_Y.Vq * rtb_TrigonometricFunction1_tmp + FOC_Y.Vd * FOC_B.Add1)
    * 0.8660254037844386;

  /* End of Outputs for SubSystem: '<S12>/Two inputs CRL' */

  /* Sum: '<S14>/add_b' */
  FOC_B.Add1 = rtb_Diff - rtb_add_c;

  /* Sum: '<S14>/add_c' */
  rtb_add_c = (0.0 - rtb_add_c) - rtb_Diff;

  /* Outputs for Atomic SubSystem: '<S12>/Two inputs CRL' */
  /* Gain: '<S20>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S15>/a16'
   *  MinMax: '<S20>/Max'
   *  MinMax: '<S20>/Min'
   *  Sum: '<S20>/Add'
   */
  rtb_Diff = (fmax(fmax(rtb_Switch_f_idx_0, FOC_B.Add1), rtb_add_c) + fmin(fmin
    (rtb_Switch_f_idx_0, FOC_B.Add1), rtb_add_c)) * -0.5;

  /* Outport: '<Root>/Va' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S15>/a16'
   *  Gain: '<S19>/Gain'
   *  Sum: '<S19>/Add3'
   */
  FOC_Y.Va = (rtb_Switch_f_idx_0 + rtb_Diff) * 1.1547005383792517;

  /* End of Outputs for SubSystem: '<S12>/Two inputs CRL' */

  /* Outport: '<Root>/Vb' incorporates:
   *  Gain: '<S19>/Gain'
   *  Sum: '<S19>/Add1'
   */
  FOC_Y.Vb = (FOC_B.Add1 + rtb_Diff) * 1.1547005383792517;

  /* Outport: '<Root>/Vc' incorporates:
   *  Gain: '<S19>/Gain'
   *  Sum: '<S19>/Add2'
   */
  FOC_Y.Vc = (rtb_Diff + rtb_add_c) * 1.1547005383792517;

  /* Switch: '<S166>/Switch' incorporates:
   *  Inport: '<Root>/Low_Limit_torque_PID'
   *  Inport: '<Root>/Up_Limit_torque_PID'
   *  RelationalOperator: '<S166>/u_GTE_up'
   *  RelationalOperator: '<S166>/u_GT_lo'
   *  Switch: '<S166>/Switch1'
   */
  if (rtb_Sum_eh >= FOC_U.Up_Limit_torque_PID) {
    rtb_Diff = FOC_U.Up_Limit_torque_PID;
  } else if (rtb_Sum_eh > FOC_U.Low_Limit_torque_PID) {
    /* Switch: '<S166>/Switch1' */
    rtb_Diff = rtb_Sum_eh;
  } else {
    rtb_Diff = FOC_U.Low_Limit_torque_PID;
  }

  /* Sum: '<S166>/Diff' incorporates:
   *  Switch: '<S166>/Switch'
   */
  rtb_Diff = rtb_Sum_eh - rtb_Diff;

  /* Product: '<S171>/IProd Out' incorporates:
   *  Inport: '<Root>/Ki_torque_PID'
   */
  rtb_IProdOut_d *= FOC_U.Ki_torque_PID;

  /* Switch: '<S163>/Switch1' incorporates:
   *  Constant: '<S163>/Clamping_zero'
   *  Constant: '<S163>/Constant'
   *  Constant: '<S163>/Constant2'
   *  RelationalOperator: '<S163>/fix for DT propagation issue'
   */
  if (rtb_Diff > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S163>/Switch2' incorporates:
   *  Constant: '<S163>/Clamping_zero'
   *  Constant: '<S163>/Constant3'
   *  Constant: '<S163>/Constant4'
   *  RelationalOperator: '<S163>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut_d > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Logic: '<S163>/AND3' incorporates:
   *  Constant: '<S163>/Clamping_zero'
   *  RelationalOperator: '<S163>/Equal1'
   *  RelationalOperator: '<S163>/Relational Operator'
   *  Switch: '<S163>/Switch1'
   *  Switch: '<S163>/Switch2'
   */
  rtb_AND3 = ((rtb_Diff != 0.0) && (tmp == tmp_0));

  /* Switch: '<S54>/Switch' incorporates:
   *  Inport: '<Root>/Low_Limit_speed_PID'
   *  Inport: '<Root>/Up_Limit_speed_PID'
   *  RelationalOperator: '<S54>/u_GTE_up'
   *  RelationalOperator: '<S54>/u_GT_lo'
   *  Switch: '<S54>/Switch1'
   */
  if (FOC_B.Sum_f >= FOC_U.Up_Limit_speed_PID) {
    rtb_Diff = FOC_U.Up_Limit_speed_PID;
  } else if (FOC_B.Sum_f > FOC_U.Low_Limit_speed_PID) {
    /* Switch: '<S54>/Switch1' */
    rtb_Diff = FOC_B.Sum_f;
  } else {
    rtb_Diff = FOC_U.Low_Limit_speed_PID;
  }

  /* Sum: '<S54>/Diff' incorporates:
   *  Switch: '<S54>/Switch'
   */
  rtb_Diff = FOC_B.Sum_f - rtb_Diff;

  /* Product: '<S59>/IProd Out' incorporates:
   *  Inport: '<Root>/Ki_speed_PID'
   */
  FOC_B.IProdOut_e *= FOC_U.Ki_speed_PID;

  /* Switch: '<S51>/Switch1' incorporates:
   *  Constant: '<S51>/Clamping_zero'
   *  Constant: '<S51>/Constant'
   *  Constant: '<S51>/Constant2'
   *  RelationalOperator: '<S51>/fix for DT propagation issue'
   */
  if (rtb_Diff > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S51>/Switch2' incorporates:
   *  Constant: '<S51>/Clamping_zero'
   *  Constant: '<S51>/Constant3'
   *  Constant: '<S51>/Constant4'
   *  RelationalOperator: '<S51>/fix for DT propagation issue1'
   */
  if (FOC_B.IProdOut_e > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Logic: '<S51>/AND3' incorporates:
   *  Constant: '<S51>/Clamping_zero'
   *  RelationalOperator: '<S51>/Equal1'
   *  RelationalOperator: '<S51>/Relational Operator'
   *  Switch: '<S51>/Switch1'
   *  Switch: '<S51>/Switch2'
   */
  rtb_AND3_f = ((rtb_Diff != 0.0) && (tmp == tmp_0));

  /* Switch: '<S110>/Switch' incorporates:
   *  Inport: '<Root>/Low_Limit_flux_PID'
   *  Inport: '<Root>/Up_Limit_flux_PID'
   *  RelationalOperator: '<S110>/u_GTE_up'
   *  RelationalOperator: '<S110>/u_GT_lo'
   *  Switch: '<S110>/Switch1'
   */
  if (FOC_B.Sum >= FOC_U.Up_Limit_flux_PID) {
    rtb_Diff = FOC_U.Up_Limit_flux_PID;
  } else if (FOC_B.Sum > FOC_U.Low_Limit_flux_PID) {
    /* Switch: '<S110>/Switch1' */
    rtb_Diff = FOC_B.Sum;
  } else {
    rtb_Diff = FOC_U.Low_Limit_flux_PID;
  }

  /* Sum: '<S110>/Diff' incorporates:
   *  Switch: '<S110>/Switch'
   */
  rtb_Diff = FOC_B.Sum - rtb_Diff;

  /* Product: '<S115>/IProd Out' incorporates:
   *  Inport: '<Root>/Ki_flux_PID'
   */
  FOC_B.IProdOut *= FOC_U.Ki_flux_PID;

  /* Switch: '<S107>/Switch1' incorporates:
   *  Constant: '<S107>/Clamping_zero'
   *  Constant: '<S107>/Constant'
   *  Constant: '<S107>/Constant2'
   *  RelationalOperator: '<S107>/fix for DT propagation issue'
   */
  if (rtb_Diff > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S107>/Switch2' incorporates:
   *  Constant: '<S107>/Clamping_zero'
   *  Constant: '<S107>/Constant3'
   *  Constant: '<S107>/Constant4'
   *  RelationalOperator: '<S107>/fix for DT propagation issue1'
   */
  if (FOC_B.IProdOut > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S107>/Switch' incorporates:
   *  Constant: '<S107>/Clamping_zero'
   *  Constant: '<S107>/Constant1'
   *  Logic: '<S107>/AND3'
   *  RelationalOperator: '<S107>/Equal1'
   *  RelationalOperator: '<S107>/Relational Operator'
   *  Switch: '<S107>/Switch1'
   *  Switch: '<S107>/Switch2'
   */
  if ((rtb_Diff != 0.0) && (tmp == tmp_0)) {
    FOC_B.IProdOut = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S118>/Integrator' incorporates:
   *  Switch: '<S107>/Switch'
   */
  FOC_DW.Integrator_DSTATE += 1.0E-5 * FOC_B.IProdOut;

  /* Update for DiscreteIntegrator: '<S113>/Filter' */
  FOC_DW.Filter_DSTATE += 1.0E-5 * FOC_B.NProdOut;

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Constant1'
   */
  if (rtb_AND3_f) {
    FOC_B.IProdOut_e = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S62>/Integrator' incorporates:
   *  Switch: '<S51>/Switch'
   */
  FOC_DW.Integrator_DSTATE_g += 1.0E-5 * FOC_B.IProdOut_e;

  /* Update for DiscreteIntegrator: '<S57>/Filter' */
  FOC_DW.Filter_DSTATE_c += 1.0E-5 * FOC_B.NProdOut_k;

  /* Switch: '<S163>/Switch' incorporates:
   *  Constant: '<S163>/Constant1'
   */
  if (rtb_AND3) {
    rtb_IProdOut_d = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S174>/Integrator' incorporates:
   *  Switch: '<S163>/Switch'
   */
  FOC_DW.Integrator_DSTATE_h += 1.0E-5 * rtb_IProdOut_d;

  /* Update for DiscreteIntegrator: '<S169>/Filter' */
  FOC_DW.Filter_DSTATE_d += 1.0E-5 * rtb_NProdOut_l;

  // /* Matfile logging */
  // rt_UpdateTXYLogVars(FOC_M->rtwLogInfo, (&FOC_M->Timing.taskTime0));

  // /* signal main to stop simulation */
  // {                                    /* Sample time: [1.0E-5s, 0.0s] */
  //   if ((rtmGetTFinal(FOC_M)!=-1) &&
  //       !((rtmGetTFinal(FOC_M)-FOC_M->Timing.taskTime0) >
  //         FOC_M->Timing.taskTime0 * (DBL_EPSILON))) {
  //     rtmSetErrorStatus(FOC_M, "Simulation finished");
  //   }
  // }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++FOC_M->Timing.clockTick0)) {
    ++FOC_M->Timing.clockTickH0;
  }

  FOC_M->Timing.taskTime0 = FOC_M->Timing.clockTick0 * FOC_M->Timing.stepSize0 +
    FOC_M->Timing.clockTickH0 * FOC_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void FOC_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)FOC_M, 0,
                sizeof(RT_MODEL_FOC_T));
  rtmSetTFinal(FOC_M, 20.0);
  FOC_M->Timing.stepSize0 = 1.0E-5;

  // /* Setup for data logging */
  // {
  //   static RTWLogInfo rt_DataLoggingInfo;
  //   rt_DataLoggingInfo.loggingInterval = (NULL);
  //   FOC_M->rtwLogInfo = &rt_DataLoggingInfo;
  // }

  // /* Setup for data logging */
  // {
  //   rtliSetLogXSignalInfo(FOC_M->rtwLogInfo, (NULL));
  //   rtliSetLogXSignalPtrs(FOC_M->rtwLogInfo, (NULL));
  //   rtliSetLogT(FOC_M->rtwLogInfo, "tout");
  //   rtliSetLogX(FOC_M->rtwLogInfo, "");
  //   rtliSetLogXFinal(FOC_M->rtwLogInfo, "");
  //   rtliSetLogVarNameModifier(FOC_M->rtwLogInfo, "rt_");
  //   rtliSetLogFormat(FOC_M->rtwLogInfo, 4);
  //   rtliSetLogMaxRows(FOC_M->rtwLogInfo, 0);
  //   rtliSetLogDecimation(FOC_M->rtwLogInfo, 1);
  //   rtliSetLogY(FOC_M->rtwLogInfo, "");
  //   rtliSetLogYSignalInfo(FOC_M->rtwLogInfo, (NULL));
  //   rtliSetLogYSignalPtrs(FOC_M->rtwLogInfo, (NULL));
  // }

  /* states (dwork) */
  (void) memset((void *)&FOC_DW, 0,
                sizeof(DW_FOC_T));

  /* external inputs */
  (void)memset(&FOC_U, 0, sizeof(ExtU_FOC_T));

  /* external outputs */
  (void)memset(&FOC_Y, 0, sizeof(ExtY_FOC_T));

  /* Matfile logging */
  // rt_StartDataLoggingWithStartTime(FOC_M->rtwLogInfo, 0.0, rtmGetTFinal(FOC_M),
  //   FOC_M->Timing.stepSize0, (&rtmGetErrorStatus(FOC_M)));

  /* InitializeConditions for DiscreteIntegrator: '<S118>/Integrator' */
  FOC_DW.Integrator_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Filter' */
  FOC_DW.Filter_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S62>/Integrator' */
  FOC_DW.Integrator_DSTATE_g = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Filter' */
  FOC_DW.Filter_DSTATE_c = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S174>/Integrator' */
  FOC_DW.Integrator_DSTATE_h = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S169>/Filter' */
  FOC_DW.Filter_DSTATE_d = 0.0;

  FOC_U.Lq = 0.000387;
  FOC_U.Ld = 0.000147;
  FOC_U.Lamda = 0.0263;
  FOC_U.Rs = 0.0107;

  FOC_U.Kp_speed_PID = 5;
  FOC_U.Ki_speed_PID = 10;
  FOC_U.Kd_speed_PID = 0.01;
  FOC_U.Filter_speed_PID = 10.0;
  FOC_U.Up_Limit_speed_PID = 500.0;
  FOC_U.Low_Limit_speed_PID = 0.0;

  FOC_U.Kp_flux_PID = 0.8;
  FOC_U.Ki_flux_PID = 20.0;
  FOC_U.Kd_flux_PID = 0.03;
  FOC_U.Filter_flux_PID = 10.0;
  FOC_U.Up_Limit_flux_PID = 65.0;
  FOC_U.Low_Limit_flux_PID = -65.0;

  FOC_U.Kp_torque_PID = 0.7;
  FOC_U.Ki_torque_PID = 15.0;
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
