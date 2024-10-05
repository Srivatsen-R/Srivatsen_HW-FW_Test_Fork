/*
 * FOC.c
 *
 * Code generation for model "FOC".
 *
 * Model version              : 18.0
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Oct  4 14:16:40 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Passed (11), Warning (1), Error (0)
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

/* Real-time model */
static RT_MODEL_FOC_T FOC_M_;
RT_MODEL_FOC_T *const FOC_M = &FOC_M_;

/* Model step function */
void FOC_step(void)
{
  real_T rtb_Add2;
  real_T rtb_DeadZone_n;
  real_T rtb_NProdOut_d;
  real_T rtb_NProdOut_n;
  real_T rtb_Switch_f_idx_0;
  real_T rtb_TrigonometricFunction1_tmp;
  real_T rtb_add_c;
  int8_T tmp;
  int8_T tmp_0;

  /* Outputs for Atomic SubSystem: '<S7>/Two phase CRL wrap' */
  /* Gain: '<S8>/one_by_sqrt3' incorporates:
   *  Inport: '<Root>/Phase Current'
   *  Sum: '<S8>/a_plus_2b'
   */
  rtb_Add2 = ((FOC_U.PhaseCurrent[0] + FOC_U.PhaseCurrent[1]) +
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
  /* Sum: '<S9>/sum_Ds' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S8>/a16'
   *  Inport: '<Root>/Phase Current'
   *  Product: '<S9>/acos'
   *  Product: '<S9>/bsin'
   *  Trigonometry: '<S2>/Trigonometric Function'
   *  Trigonometry: '<S2>/Trigonometric Function1'
   */
  FOC_B.IProdOut = FOC_U.PhaseCurrent[0] * rtb_TrigonometricFunction1_tmp +
    rtb_Add2 * FOC_B.Add1;

  /* End of Outputs for SubSystem: '<S7>/Two phase CRL wrap' */

  /* Product: '<S118>/NProd Out' incorporates:
   *  Constant: '<S4>/Id_ref'
   *  DiscreteIntegrator: '<S110>/Filter'
   *  Inport: '<Root>/PID_Vd'
   *  Product: '<S108>/DProd Out'
   *  Sum: '<S110>/SumD'
   *  Sum: '<S4>/Sum3'
   *  Sum: '<S9>/sum_Ds'
   */
  FOC_B.NProdOut = ((0.0 - FOC_B.IProdOut) * FOC_U.PID_Vd[2] -
                    FOC_DW.Filter_DSTATE) * FOC_U.PID_Vd[3];

  /* Sum: '<S124>/Sum' incorporates:
   *  Constant: '<S4>/Id_ref'
   *  DiscreteIntegrator: '<S115>/Integrator'
   *  Inport: '<Root>/PID_Vd'
   *  Product: '<S120>/PProd Out'
   *  Sum: '<S4>/Sum3'
   *  Sum: '<S9>/sum_Ds'
   */
  FOC_B.DeadZone = ((0.0 - FOC_B.IProdOut) * FOC_U.PID_Vd[0] +
                    FOC_DW.Integrator_DSTATE) + FOC_B.NProdOut;

  /* End of Outputs for SubSystem: '<S6>/Two inputs CRL' */

  /* Saturate: '<S122>/Saturation' */
  if (FOC_B.DeadZone > 0.0) {
    FOC_B.Saturation = 0.0;
  } else if (FOC_B.DeadZone < -52.0) {
    FOC_B.Saturation = -52.0;
  } else {
    FOC_B.Saturation = FOC_B.DeadZone;
  }

  /* End of Saturate: '<S122>/Saturation' */

  /* Sum: '<S4>/Sum1' incorporates:
   *  Inport: '<Root>/Actual Speed'
   *  Inport: '<Root>/Ref Speed'
   */
  FOC_B.IProdOut_e = FOC_U.RefSpeed - FOC_U.ActualSpeed;

  /* Product: '<S64>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S56>/Filter'
   *  Inport: '<Root>/PID_Id'
   *  Product: '<S54>/DProd Out'
   *  Sum: '<S56>/SumD'
   */
  rtb_NProdOut_n = (FOC_B.IProdOut_e * FOC_U.PID_Id[2] - FOC_DW.Filter_DSTATE_c)
    * FOC_U.PID_Id[3];

  /* Sum: '<S70>/Sum' incorporates:
   *  DiscreteIntegrator: '<S61>/Integrator'
   *  Inport: '<Root>/PID_Id'
   *  Product: '<S66>/PProd Out'
   */
  FOC_B.DeadZone_b = (FOC_B.IProdOut_e * FOC_U.PID_Id[0] +
                      FOC_DW.Integrator_DSTATE_g) + rtb_NProdOut_n;

  /* Outputs for Atomic SubSystem: '<S6>/Two inputs CRL' */
  /* Outputs for Atomic SubSystem: '<S7>/Two phase CRL wrap' */
  /* Sum: '<S4>/Sum2' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S8>/a16'
   *  Inport: '<Root>/Phase Current'
   *  Product: '<S9>/asin'
   *  Product: '<S9>/bcos'
   *  Sum: '<S9>/sum_Qs'
   *  Trigonometry: '<S2>/Trigonometric Function'
   *  Trigonometry: '<S2>/Trigonometric Function1'
   */
  FOC_B.IProdOut_j = FOC_B.DeadZone_b - (rtb_Add2 *
    rtb_TrigonometricFunction1_tmp - FOC_U.PhaseCurrent[0] * FOC_B.Add1);

  /* End of Outputs for SubSystem: '<S7>/Two phase CRL wrap' */
  /* End of Outputs for SubSystem: '<S6>/Two inputs CRL' */

  /* Product: '<S172>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S164>/Filter'
   *  Inport: '<Root>/PID_Vq'
   *  Product: '<S162>/DProd Out'
   *  Sum: '<S164>/SumD'
   */
  rtb_NProdOut_d = (FOC_B.IProdOut_j * FOC_U.PID_Vq[2] - FOC_DW.Filter_DSTATE_d)
    * FOC_U.PID_Vq[3];

  /* Sum: '<S178>/Sum' incorporates:
   *  DiscreteIntegrator: '<S169>/Integrator'
   *  Inport: '<Root>/PID_Vq'
   *  Product: '<S174>/PProd Out'
   */
  rtb_DeadZone_n = (FOC_B.IProdOut_j * FOC_U.PID_Vq[0] +
                    FOC_DW.Integrator_DSTATE_h) + rtb_NProdOut_d;

  /* Saturate: '<S176>/Saturation' incorporates:
   *  DeadZone: '<S161>/DeadZone'
   */
  if (rtb_DeadZone_n > 58.0) {
    rtb_Add2 = 58.0;
    rtb_DeadZone_n -= 58.0;
  } else {
    if (rtb_DeadZone_n < -58.0) {
      rtb_Add2 = -58.0;
    } else {
      rtb_Add2 = rtb_DeadZone_n;
    }

    if (rtb_DeadZone_n >= -58.0) {
      rtb_DeadZone_n = 0.0;
    } else {
      rtb_DeadZone_n -= -58.0;
    }
  }

  /* End of Saturate: '<S176>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S12>/Two inputs CRL' */
  /* Switch: '<S16>/Switch' incorporates:
   *  Product: '<S15>/dcos'
   *  Product: '<S15>/qsin'
   *  Sum: '<S15>/sum_alpha'
   */
  rtb_Switch_f_idx_0 = FOC_B.Saturation * rtb_TrigonometricFunction1_tmp -
    rtb_Add2 * FOC_B.Add1;

  /* Gain: '<S14>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S15>/a16'
   */
  rtb_add_c = 0.5 * rtb_Switch_f_idx_0;

  /* Gain: '<S14>/sqrt3_by_two' incorporates:
   *  Product: '<S15>/dsin'
   *  Product: '<S15>/qcos'
   *  Sum: '<S15>/sum_beta'
   */
  rtb_Add2 = (rtb_Add2 * rtb_TrigonometricFunction1_tmp + FOC_B.Saturation *
              FOC_B.Add1) * 0.8660254037844386;

  /* End of Outputs for SubSystem: '<S12>/Two inputs CRL' */

  /* Sum: '<S14>/add_b' */
  FOC_B.Add1 = rtb_Add2 - rtb_add_c;

  /* Sum: '<S14>/add_c' */
  rtb_add_c = (0.0 - rtb_add_c) - rtb_Add2;

  /* Outputs for Atomic SubSystem: '<S12>/Two inputs CRL' */
  /* Gain: '<S20>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S15>/a16'
   *  MinMax: '<S20>/Max'
   *  MinMax: '<S20>/Min'
   *  Sum: '<S20>/Add'
   */
  rtb_Add2 = (fmax(fmax(rtb_Switch_f_idx_0, FOC_B.Add1), rtb_add_c) + fmin(fmin
    (rtb_Switch_f_idx_0, FOC_B.Add1), rtb_add_c)) * -0.5;

  /* Outport: '<Root>/Va' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S15>/a16'
   *  Gain: '<S19>/Gain'
   *  Sum: '<S19>/Add3'
   */
  FOC_Y.Va = (rtb_Switch_f_idx_0 + rtb_Add2) * 1.1547005383792517;

  /* End of Outputs for SubSystem: '<S12>/Two inputs CRL' */

  /* Outport: '<Root>/Vb' incorporates:
   *  Gain: '<S19>/Gain'
   *  Sum: '<S19>/Add1'
   */
  FOC_Y.Vb = (FOC_B.Add1 + rtb_Add2) * 1.1547005383792517;

  /* Outport: '<Root>/Vc' incorporates:
   *  Gain: '<S19>/Gain'
   *  Sum: '<S19>/Add2'
   */
  FOC_Y.Vc = (rtb_Add2 + rtb_add_c) * 1.1547005383792517;

  /* Product: '<S166>/IProd Out' incorporates:
   *  Inport: '<Root>/PID_Vq'
   */
  FOC_B.IProdOut_j *= FOC_U.PID_Vq[1];

  /* DeadZone: '<S53>/DeadZone' */
  if (FOC_B.DeadZone_b >= (rtMinusInf)) {
    FOC_B.DeadZone_b = 0.0;
  }

  /* End of DeadZone: '<S53>/DeadZone' */

  /* Product: '<S58>/IProd Out' incorporates:
   *  Inport: '<Root>/PID_Id'
   */
  FOC_B.IProdOut_e *= FOC_U.PID_Id[1];

  /* DeadZone: '<S107>/DeadZone' */
  if (!(FOC_B.DeadZone > 0.0)) {
    if (FOC_B.DeadZone >= -52.0) {
      FOC_B.DeadZone = 0.0;
    } else {
      FOC_B.DeadZone -= -52.0;
    }
  }

  /* End of DeadZone: '<S107>/DeadZone' */

  /* Outputs for Atomic SubSystem: '<S6>/Two inputs CRL' */
  /* Product: '<S112>/IProd Out' incorporates:
   *  Constant: '<S4>/Id_ref'
   *  Inport: '<Root>/PID_Vd'
   *  Sum: '<S4>/Sum3'
   */
  FOC_B.IProdOut = (0.0 - FOC_B.IProdOut) * FOC_U.PID_Vd[1];

  /* End of Outputs for SubSystem: '<S6>/Two inputs CRL' */

  /* Switch: '<S105>/Switch1' incorporates:
   *  Constant: '<S105>/Clamping_zero'
   *  Constant: '<S105>/Constant'
   *  Constant: '<S105>/Constant2'
   *  RelationalOperator: '<S105>/fix for DT propagation issue'
   */
  if (FOC_B.DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S105>/Switch2' incorporates:
   *  Constant: '<S105>/Clamping_zero'
   *  Constant: '<S105>/Constant3'
   *  Constant: '<S105>/Constant4'
   *  RelationalOperator: '<S105>/fix for DT propagation issue1'
   */
  if (FOC_B.IProdOut > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S105>/Switch' incorporates:
   *  Constant: '<S105>/Clamping_zero'
   *  Constant: '<S105>/Constant1'
   *  Logic: '<S105>/AND3'
   *  RelationalOperator: '<S105>/Equal1'
   *  RelationalOperator: '<S105>/Relational Operator'
   *  Switch: '<S105>/Switch1'
   *  Switch: '<S105>/Switch2'
   */
  if ((FOC_B.DeadZone != 0.0) && (tmp == tmp_0)) {
    FOC_B.IProdOut = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S115>/Integrator' incorporates:
   *  Switch: '<S105>/Switch'
   */
  FOC_DW.Integrator_DSTATE += 1.0E-5 * FOC_B.IProdOut;

  /* Update for DiscreteIntegrator: '<S110>/Filter' */
  FOC_DW.Filter_DSTATE += 1.0E-5 * FOC_B.NProdOut;

  /* Switch: '<S51>/Switch2' incorporates:
   *  Constant: '<S51>/Clamping_zero'
   *  Constant: '<S51>/Constant3'
   *  Constant: '<S51>/Constant4'
   *  RelationalOperator: '<S51>/fix for DT propagation issue1'
   */
  if (FOC_B.IProdOut_e > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Clamping_zero'
   *  Constant: '<S51>/Constant1'
   *  Logic: '<S51>/AND3'
   *  RelationalOperator: '<S51>/Equal1'
   *  RelationalOperator: '<S51>/Relational Operator'
   *  Switch: '<S51>/Switch1'
   *  Switch: '<S51>/Switch2'
   */
  if ((FOC_B.DeadZone_b != 0.0) && (tmp == -1)) {
    FOC_B.IProdOut_e = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S61>/Integrator' incorporates:
   *  Switch: '<S51>/Switch'
   */
  FOC_DW.Integrator_DSTATE_g += 1.0E-5 * FOC_B.IProdOut_e;

  /* Update for DiscreteIntegrator: '<S56>/Filter' */
  FOC_DW.Filter_DSTATE_c += 1.0E-5 * rtb_NProdOut_n;

  /* Switch: '<S159>/Switch1' incorporates:
   *  Constant: '<S159>/Clamping_zero'
   *  Constant: '<S159>/Constant'
   *  Constant: '<S159>/Constant2'
   *  RelationalOperator: '<S159>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_n > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S159>/Switch2' incorporates:
   *  Constant: '<S159>/Clamping_zero'
   *  Constant: '<S159>/Constant3'
   *  Constant: '<S159>/Constant4'
   *  RelationalOperator: '<S159>/fix for DT propagation issue1'
   */
  if (FOC_B.IProdOut_j > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S159>/Switch' incorporates:
   *  Constant: '<S159>/Clamping_zero'
   *  Constant: '<S159>/Constant1'
   *  Logic: '<S159>/AND3'
   *  RelationalOperator: '<S159>/Equal1'
   *  RelationalOperator: '<S159>/Relational Operator'
   *  Switch: '<S159>/Switch1'
   *  Switch: '<S159>/Switch2'
   */
  if ((rtb_DeadZone_n != 0.0) && (tmp == tmp_0)) {
    FOC_B.IProdOut_j = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S169>/Integrator' incorporates:
   *  Switch: '<S159>/Switch'
   */
  FOC_DW.Integrator_DSTATE_h += 1.0E-5 * FOC_B.IProdOut_j;

  /* Update for DiscreteIntegrator: '<S164>/Filter' */
  FOC_DW.Filter_DSTATE_d += 1.0E-5 * rtb_NProdOut_d;

  /* Matfile logging */
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

  /* states (dwork) */
  (void) memset((void *)&FOC_DW, 0,
                sizeof(DW_FOC_T));

  /* external inputs */
  (void)memset(&FOC_U, 0, sizeof(ExtU_FOC_T));

  /* external outputs */
  (void)memset(&FOC_Y, 0, sizeof(ExtY_FOC_T));

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Integrator' */
  FOC_DW.Integrator_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S110>/Filter' */
  FOC_DW.Filter_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S61>/Integrator' */
  FOC_DW.Integrator_DSTATE_g = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S56>/Filter' */
  FOC_DW.Filter_DSTATE_c = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S169>/Integrator' */
  FOC_DW.Integrator_DSTATE_h = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S164>/Filter' */
  FOC_DW.Filter_DSTATE_d = 0.0;

  FOC_U.PID_Id[0] = 1;
  FOC_U.PID_Id[1] = 5;
  FOC_U.PID_Id[2] = 0.01;
  FOC_U.PID_Id[3] = 10;

  FOC_U.PID_Vq[0] = 0.15;
  FOC_U.PID_Vd[1] = 8;
  FOC_U.PID_Vq[2] = 0.01;
  FOC_U.PID_Vq[3] = 10;

  FOC_U.PID_Vd[0] = 0.15;
  FOC_U.PID_Vd[1] = 8;
  FOC_U.PID_Vd[2] = 0.01;
  FOC_U.PID_Vd[3] = 10;

  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
}

/* Model terminate function */
void FOC_terminate(void)
{
  /* (no terminate code required) */
}
