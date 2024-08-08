/*
 * File: Position_Calculation.c
 *
 * Code generated for Simulink model 'Position_Calculation'.
 *
 * Model version                  : 1.38
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Aug  3 19:04:42 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Execution efficiency
 *    3. RAM efficiency
 *    4. Debugging
 *    5. Safety precaution
 *    6. ROM efficiency
 * Validation result: Not run
 */

#include "Position_Calculation.h"
#include "vector_control.h"
#include <math.h>
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW_Angle rtDW_Angle;

/* External inputs (root inport signals with default storage) */
ExtU_Angle rtU_Angle;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Angle rtY_Angle;

/* Real-time model */
static RT_MODEL_Angle rtM_;
RT_MODEL_Angle *const rtM_Angle = &rtM_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM_Angle->Timing.TaskCounters.TID[1])++;
  if ((rtM_Angle->Timing.TaskCounters.TID[1]) > 49) {/* Sample time: [0.0025s, 0.0s] */
    rtM_Angle->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void Position_Calculation_step(void)
{
  real_T rtb_Add1;
  real_T rtb_Numberofpolepairs;
  real_T rtb_Numberofpolepairs_tmp;
  real32_T rtb_Speed_rpm;
  uint32_T rtb_PositionToCount;
  boolean_T rtb_LogicalOperator1;

  /* Sum: '<S1>/Add' incorporates:
   *  Inport: '<Root>/Z_Cnt'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  rtb_Numberofpolepairs_tmp = rtU_Angle.Z_Cnt - rtDW_Angle.UnitDelay1_DSTATE;

  /* Outputs for Enabled SubSystem: '<S8>/POSITIVE Edge' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  if (rtConstB_Angle.MultiportSwitch[0] > 0.0) {
    /* RelationalOperator: '<S10>/Relational Operator1' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion2'
     *  Sum: '<S1>/Add'
     *  UnitDelay: '<S8>/Unit Delay'
     */
    rtDW_Angle.RelationalOperator1 = (((rtb_Numberofpolepairs_tmp != 0.0) ? ((int32_T)
      1) : ((int32_T)0)) > (int32_T)(rtDW_Angle.UnitDelay_DSTATE_g ? 1 : 0));
  }

  /* End of Outputs for SubSystem: '<S8>/POSITIVE Edge' */

  /* Outputs for Enabled SubSystem: '<S8>/NEGATIVE Edge' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (rtConstB_Angle.MultiportSwitch[1] > 0.0) {
    /* RelationalOperator: '<S9>/Relational Operator1' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion2'
     *  Sum: '<S1>/Add'
     *  UnitDelay: '<S8>/Unit Delay'
     */
    rtDW_Angle.RelationalOperator1_i = ((int32_T)(rtDW_Angle.UnitDelay_DSTATE_g ? 1 : 0) >
      ((rtb_Numberofpolepairs_tmp != 0.0) ? ((int32_T)1) : ((int32_T)0)));
  }

  /* End of Outputs for SubSystem: '<S8>/NEGATIVE Edge' */

  /* Logic: '<S8>/Logical Operator1' */
  rtb_LogicalOperator1 = rtDW_Angle.RelationalOperator1 | rtDW_Angle.RelationalOperator1_i;
  if (rtM_Angle->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S1>/Switch' incorporates:
     *  UnitDelay: '<S1>/Unit Delay'
     */
    rtDW_Angle.Switch = (real_T)((rtDW_Angle.UnitDelay_DSTATE_k > 0.0F) ? ((int32_T)1) :
      ((int32_T)0));
  }

  /* Chart: '<S1>/Chart1' incorporates:
   *  Inport: '<Root>/Encoder_Cnt'
   */
  if ((uint32_T)rtDW_Angle.is_active_c3_Position_Calculati == 0U) {
    rtDW_Angle.is_active_c3_Position_Calculati = 1U;
  } else if ((boolean_T)((int32_T)(((rtDW_Angle.Switch == 0.0) ? ((int32_T)1) :
                ((int32_T)0)) & (rtb_LogicalOperator1 ? ((int32_T)1) : ((int32_T)
      0))))) {
    rtDW_Angle.Position = 6.2831853071795862;

    /* Outport: '<Root>/EncoderReset' */
    rtY_Angle.EncoderReset = 4096.0;
  } else if ((boolean_T)((int32_T)(((rtDW_Angle.Switch == 1.0) ? ((int32_T)1) :
                ((int32_T)0)) & (rtb_LogicalOperator1 ? ((int32_T)1) : ((int32_T)
      0))))) {
    rtDW_Angle.Position = 0.0;

    /* Outport: '<Root>/EncoderReset' */
    rtY_Angle.EncoderReset = 0.0;
  } else {
    rtDW_Angle.Position = (6.2831853071795862 * rtU_Angle.Encoder_Cnt) / 4096.0;
  }

  /* End of Chart: '<S1>/Chart1' */

  /* Outport: '<Root>/Mech_Angle_rad' incorporates:
   *  Constant: '<S1>/Constant'
   *  Sum: '<S1>/Add1'
   */
  rtY_Angle.Mech_Angle_rad = 6.2831853071795862 - rtDW_Angle.Position;
  if (rtM_Angle->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S6>/PositionToCount' incorporates:
     *  Outport: '<Root>/Mech_Angle_rad'
     *  Sum: '<S1>/Add1'
     */
    rtb_PositionToCount = (uint32_T)((real_T)(6.8356367710720658E+8 *
      rtY_Angle.Mech_Angle_rad));

    /* Sum: '<S13>/Add1' incorporates:
     *  Constant: '<S13>/Filter_Constant'
     *  Constant: '<S13>/One'
     *  DataTypeConversion: '<S21>/DTC'
     *  Delay: '<S6>/Delay'
     *  Gain: '<S6>/SpeedGain'
     *  Product: '<S13>/Product'
     *  Product: '<S13>/Product1'
     *  Sum: '<S6>/SpeedCount'
     *  UnitDelay: '<S13>/Unit Delay'
     */
    rtb_Add1 = (((real_T)((int32_T)((int32_T)rtb_PositionToCount - (int32_T)
      rtDW_Angle.Delay_DSTATE[rtDW_Angle.CircBufIdx])) * 2.9258361585343194E-7) * 0.01) +
      (0.99 * rtDW_Angle.UnitDelay_DSTATE);

    /* Outport: '<Root>/Speed_rad//sec' */
    rtY_Angle.Speed_radsec = rtb_Add1;

    /* Gain: '<S1>/Gain' */
    rtb_Speed_rpm = (real32_T)((real_T)(9.5492965855137211 * rtb_Add1));

    /* Outport: '<Root>/Speed_rpm' */
    rtY_Angle.Speed_rpm = rtb_Speed_rpm;
  }

  /* If: '<S16>/If' incorporates:
   *  Constant: '<S18>/Constant'
   *  Gain: '<S17>/Number of pole pairs'
   *  Inport: '<Root>/Offset_rad'
   *  Outport: '<Root>/Mech_Angle_rad'
   *  Sum: '<S18>/Add'
   *  Sum: '<S19>/Add'
   *  Sum: '<S1>/Add1'
   */
  if (rtY_Angle.Mech_Angle_rad <= rtU_Angle.Offset_rad) {
    /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    rtb_Numberofpolepairs = rtY_Angle.Mech_Angle_rad + 6.2831853071795862 -
      rtU_Angle.Offset_rad;

    /* End of Outputs for SubSystem: '<S16>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    rtb_Numberofpolepairs = rtY_Angle.Mech_Angle_rad - rtU_Angle.Offset_rad;

    /* End of Outputs for SubSystem: '<S16>/If Action Subsystem1' */
  }

  rtb_Numberofpolepairs *= 3.0;

  /* End of If: '<S16>/If' */

  /* Outport: '<Root>/Elec_Angle_rad' incorporates:
   *  Gain: '<S17>/Multiply'
   *  Gain: '<S17>/Multiply1'
   *  Rounding: '<S17>/Floor'
   *  Sum: '<S17>/Add'
   */
  rtY_Angle.Elec_Angle_rad = rtb_Numberofpolepairs - (floor(0.15915494309189535 *
    rtb_Numberofpolepairs) * 6.2831853071795862);

  /* Update for UnitDelay: '<S1>/Unit Delay1' incorporates:
   *  Inport: '<Root>/Z_Cnt'
   */
  rtDW_Angle.UnitDelay1_DSTATE = rtU_Angle.Z_Cnt;

  /* Update for UnitDelay: '<S8>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion2'
   */
  rtDW_Angle.UnitDelay_DSTATE_g = (rtb_Numberofpolepairs_tmp != 0.0);
  if (rtM_Angle->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S1>/Unit Delay' */
    rtDW_Angle.UnitDelay_DSTATE_k = rtb_Speed_rpm;

    /* Update for Delay: '<S6>/Delay' */
    rtDW_Angle.Delay_DSTATE[rtDW_Angle.CircBufIdx] = rtb_PositionToCount;
    if (rtDW_Angle.CircBufIdx < 1U) {
      rtDW_Angle.CircBufIdx = 1U;
    } else {
      rtDW_Angle.CircBufIdx = 0U;
    }

    /* End of Update for Delay: '<S6>/Delay' */

    /* Update for UnitDelay: '<S13>/Unit Delay' */
    rtDW_Angle.UnitDelay_DSTATE = rtb_Add1;
  }

  rate_scheduler();
}

/* Model initialize function */
void Position_Calculation_initialize()
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
