/*
 * File: Pegasus_MBD.c
 *
 * Code generated for Simulink model 'Pegasus_MBD'.
 *
 * Model version                  : 1.203
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jun 20 15:58:03 2024
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
#include "motor_param.h"
#include <math.h>

/* Named constants for Chart: '<S6>/Va_Saturation' */
#define IN_Lobby                       ((uint8_T)1U)
#define IN_Lobby1                      ((uint8_T)2U)
#define IN_Lobby2                      ((uint8_T)3U)

/* Named constants for Chart: '<S6>/Iq_Refer_Saturation' */
#define IN_Lobby1_j                    ((uint8_T)2U)
#define IN_Lobby2_f                    ((uint8_T)3U)
#define IN_Lobby_k                     ((uint8_T)1U)

/* Named constants for Chart: '<S7>/Protection_States' */
#define IN_CurrentSafe                 ((uint8_T)1U)
#define IN_HighTempError               ((uint8_T)1U)
#define IN_HighTempWarning             ((uint8_T)2U)
#define IN_OC_Error                    ((uint8_T)2U)
#define IN_OC_Warning                  ((uint8_T)3U)
#define IN_OV_Error                    ((uint8_T)1U)
#define IN_OV_Warning                  ((uint8_T)2U)
#define IN_TempSafe                    ((uint8_T)3U)
#define IN_UV_Error                    ((uint8_T)3U)
#define IN_UV_Warning                  ((uint8_T)4U)
#define IN_VoltageSafe                 ((uint8_T)5U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void Va_Saturation_Init(real32_T *rty_Out);
static void Va_Saturation(real32_T rtu_In, real32_T rtu_BusVoltage_V, real32_T
  *rty_Out, DW_Va_Saturation *localDW);

/* Forward declaration for local functions */
static void VoltageProtection(const real32_T *Max1);

/*
 * System initialize for atomic system:
 *    '<S6>/Va_Saturation'
 *    '<S6>/Vb_Saturation'
 *    '<S6>/Vc_Saturation'
 */
static void Va_Saturation_Init(real32_T *rty_Out)
{
  *rty_Out = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S6>/Va_Saturation'
 *    '<S6>/Vb_Saturation'
 *    '<S6>/Vc_Saturation'
 */
static void Va_Saturation(real32_T rtu_In, real32_T rtu_BusVoltage_V, real32_T
  *rty_Out, DW_Va_Saturation *localDW)
{
  /* Chart: '<S6>/Va_Saturation' */
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

  /* End of Chart: '<S6>/Va_Saturation' */
}

/* Function for Chart: '<S7>/Protection_States' */
static void VoltageProtection(const real32_T *Max1)
{
  switch (rtDW.is_VoltageProtection) {
   case IN_OV_Error:
    {
      real_T tmp;

      /* Outport: '<Root>/VoltageFlag' */
      rtY.VoltageFlag = OV_Error;

      /* Inport: '<Root>/BusVoltage_V' incorporates:
       *  Inport: '<Root>/Thresholds'
       */
      if (!((real32_T)(((*Max1 != 0.0F) || (rtU.BusVoltage_V != 0.0F)) ?
                       ((int32_T)1) : ((int32_T)0)) <
            rtU.Thresholds.OVWarningLimit_V)) {
        rtDW.durationCounter_1_f = 0;
      }

      /* Inport: '<Root>/Thresholds' */
      /* Inport: '<Root>/BusVoltage_V' incorporates:
       *  Inport: '<Root>/Thresholds'
       */
      tmp = (real_T)((real32_T)(rtU.Thresholds.VoltageProtectionTimeout_msec *
        20.0F));
      if ((real_T)rtDW.durationCounter_1_f > tmp) {
        rtDW.durationCounter_2_n = 0;
        rtDW.durationCounter_1_jg = 0;
        rtDW.is_VoltageProtection = IN_VoltageSafe;

        /* Outport: '<Root>/VoltageFlag' */
        rtY.VoltageFlag = SafeVoltage;
      } else {
        if (!((real32_T)(((*Max1 != 0.0F) || (rtU.BusVoltage_V != 0.0F)) ?
                         ((int32_T)1) : ((int32_T)0)) <
              rtU.Thresholds.OVErrorLimit_V)) {
          rtDW.durationCounter_2_g = 0;
        }

        if ((real_T)rtDW.durationCounter_2_g > tmp) {
          rtDW.durationCounter_2_f0 = 0;
          rtDW.durationCounter_1_g = 0;
          rtDW.is_VoltageProtection = IN_OV_Warning;

          /* Outport: '<Root>/VoltageFlag' */
          rtY.VoltageFlag = OV_Warning;
        }
      }
    }
    break;

   case IN_OV_Warning:
    {
      real_T tmp;

      /* Outport: '<Root>/VoltageFlag' */
      rtY.VoltageFlag = OV_Warning;

      /* Inport: '<Root>/BusVoltage_V' incorporates:
       *  Inport: '<Root>/Thresholds'
       */
      if (!((real32_T)(((*Max1 != 0.0F) || (rtU.BusVoltage_V != 0.0F)) ?
                       ((int32_T)1) : ((int32_T)0)) >
            rtU.Thresholds.OVErrorLimit_V)) {
        rtDW.durationCounter_2_f0 = 0;
      }

      /* Inport: '<Root>/Thresholds' */
      /* Inport: '<Root>/BusVoltage_V' incorporates:
       *  Inport: '<Root>/Thresholds'
       */
      tmp = (real_T)((real32_T)(rtU.Thresholds.VoltageProtectionTimeout_msec *
        20.0F));
      if ((real_T)rtDW.durationCounter_2_f0 > tmp) {
        rtDW.durationCounter_2_g = 0;
        rtDW.durationCounter_1_f = 0;
        rtDW.is_VoltageProtection = IN_OV_Error;

        /* Outport: '<Root>/VoltageFlag' */
        rtY.VoltageFlag = OV_Error;
      } else {
        if (!((real32_T)(((*Max1 != 0.0F) || (rtU.BusVoltage_V != 0.0F)) ?
                         ((int32_T)1) : ((int32_T)0)) <
              rtU.Thresholds.OVWarningLimit_V)) {
          rtDW.durationCounter_1_g = 0;
        }

        if ((real_T)rtDW.durationCounter_1_g > tmp) {
          rtDW.durationCounter_2_n = 0;
          rtDW.durationCounter_1_jg = 0;
          rtDW.is_VoltageProtection = IN_VoltageSafe;

          /* Outport: '<Root>/VoltageFlag' */
          rtY.VoltageFlag = SafeVoltage;
        }
      }
    }
    break;

   case IN_UV_Error:
    {
      real_T tmp;

      /* Outport: '<Root>/VoltageFlag' */
      rtY.VoltageFlag = UV_Error;

      /* Inport: '<Root>/BusVoltage_V' incorporates:
       *  Inport: '<Root>/Thresholds'
       */
      if (!(rtU.BusVoltage_V > rtU.Thresholds.UVErrorLimit_V)) {
        rtDW.durationCounter_1_a = 0;
      }

      /* Inport: '<Root>/Thresholds' */
      /* Inport: '<Root>/BusVoltage_V' incorporates:
       *  Inport: '<Root>/Thresholds'
       */
      tmp = (real_T)((real32_T)(rtU.Thresholds.VoltageProtectionTimeout_msec *
        20.0F));
      if ((real_T)rtDW.durationCounter_1_a > tmp) {
        rtDW.durationCounter_2_f = 0;
        rtDW.durationCounter_1_hz = 0;
        rtDW.is_VoltageProtection = IN_UV_Warning;

        /* Outport: '<Root>/VoltageFlag' */
        rtY.VoltageFlag = UV_Warning;
      } else {
        if (!(rtU.BusVoltage_V > rtU.Thresholds.UVWarningLimit_V)) {
          rtDW.durationCounter_2_h = 0;
        }

        if ((real_T)rtDW.durationCounter_2_h > tmp) {
          rtDW.durationCounter_2_n = 0;
          rtDW.durationCounter_1_jg = 0;
          rtDW.is_VoltageProtection = IN_VoltageSafe;

          /* Outport: '<Root>/VoltageFlag' */
          rtY.VoltageFlag = SafeVoltage;
        }
      }
    }
    break;

   case IN_UV_Warning:
    {
      real_T tmp;

      /* Outport: '<Root>/VoltageFlag' */
      rtY.VoltageFlag = UV_Warning;

      /* Inport: '<Root>/BusVoltage_V' incorporates:
       *  Inport: '<Root>/Thresholds'
       */
      if (!(rtU.BusVoltage_V < rtU.Thresholds.UVErrorLimit_V)) {
        rtDW.durationCounter_1_hz = 0;
      }

      /* Inport: '<Root>/Thresholds' */
      /* Inport: '<Root>/BusVoltage_V' incorporates:
       *  Inport: '<Root>/Thresholds'
       */
      tmp = (real_T)((real32_T)(rtU.Thresholds.VoltageProtectionTimeout_msec *
        20.0F));
      if ((real_T)rtDW.durationCounter_1_hz > tmp) {
        rtDW.durationCounter_2_h = 0;
        rtDW.durationCounter_1_a = 0;
        rtDW.is_VoltageProtection = IN_UV_Error;

        /* Outport: '<Root>/VoltageFlag' */
        rtY.VoltageFlag = UV_Error;
      } else {
        if (!(rtU.BusVoltage_V > rtU.Thresholds.UVWarningLimit_V)) {
          rtDW.durationCounter_2_f = 0;
        }

        if ((real_T)rtDW.durationCounter_2_f > tmp) {
          rtDW.durationCounter_2_n = 0;
          rtDW.durationCounter_1_jg = 0;
          rtDW.is_VoltageProtection = IN_VoltageSafe;

          /* Outport: '<Root>/VoltageFlag' */
          rtY.VoltageFlag = SafeVoltage;
        }
      }
    }
    break;

   default:
    {
      real_T tmp;

      /* Outport: '<Root>/VoltageFlag' */
      /* case IN_VoltageSafe: */
      rtY.VoltageFlag = SafeVoltage;

      /* Inport: '<Root>/BusVoltage_V' incorporates:
       *  Inport: '<Root>/Thresholds'
       */
      if (!((real32_T)(((*Max1 != 0.0F) || (rtU.BusVoltage_V != 0.0F)) ?
                       ((int32_T)1) : ((int32_T)0)) >
            rtU.Thresholds.OVWarningLimit_V)) {
        rtDW.durationCounter_2_n = 0;
      }

      /* Inport: '<Root>/Thresholds' */
      /* Inport: '<Root>/BusVoltage_V' incorporates:
       *  Inport: '<Root>/Thresholds'
       */
      tmp = (real_T)((real32_T)(rtU.Thresholds.VoltageProtectionTimeout_msec *
        20.0F));
      if ((real_T)rtDW.durationCounter_2_n > tmp) {
        rtDW.durationCounter_2_f0 = 0;
        rtDW.durationCounter_1_g = 0;
        rtDW.is_VoltageProtection = IN_OV_Warning;

        /* Outport: '<Root>/VoltageFlag' */
        rtY.VoltageFlag = OV_Warning;
      } else {
        if (!(rtU.BusVoltage_V < rtU.Thresholds.UVWarningLimit_V)) {
          rtDW.durationCounter_1_jg = 0;
        }

        if ((real_T)rtDW.durationCounter_1_jg > tmp) {
          rtDW.durationCounter_2_f = 0;
          rtDW.durationCounter_1_hz = 0;
          rtDW.is_VoltageProtection = IN_UV_Warning;

          /* Outport: '<Root>/VoltageFlag' */
          rtY.VoltageFlag = UV_Warning;
        }
      }
    }
    break;
  }
}

/* Model step function */
void Pegasus_MBD_step(void)
{
  real32_T rtb_Abs1_j;
  real32_T rtb_Abs_h;
  real32_T rtb_Abs_l;
  real32_T rtb_NProdOut;
  real32_T rtb_NProdOut_g;
  real32_T rtb_NProdOut_o;
  real32_T rtb_Sum;
  real32_T rtb_Sum_c;
  real32_T rtb_Switch_idx_0;
  real32_T rtb_Switch_idx_1;

  /* Outputs for Atomic SubSystem: '<S6>/Clarke Transform' */
  /* Gain: '<S8>/one_by_sqrt3' incorporates:
   *  Inport: '<Root>/I_a'
   *  Inport: '<Root>/I_b'
   *  Sum: '<S8>/a_plus_2b'
   */
  rtb_Abs_h = (rtU.I_a + rtU.I_b + rtU.I_b) * 0.577350259F;

  /* End of Outputs for SubSystem: '<S6>/Clarke Transform' */

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Constant'
   *  Gain: '<S2>/Gain'
   *  Inport: '<Root>/MtrPos_rad'
   */
  rtb_Abs1_j = (rtU.MtrPos_rad) - -3.14159274F;

  /* Trigonometry: '<S6>/Sin' incorporates:
   *  Trigonometry: '<S6>/Sin1'
   */
  rtb_Abs_l = sinf(rtb_Abs1_j);

  /* Trigonometry: '<S6>/Cos' incorporates:
   *  Trigonometry: '<S6>/Cos1'
   */
  rtb_Abs1_j = cosf(rtb_Abs1_j);

  /* Outputs for Atomic SubSystem: '<S6>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S6>/Clarke Transform' */
  /* Switch: '<S169>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S8>/a16'
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
  rtb_Switch_idx_0 = (rtU.I_a * rtb_Abs1_j) + (rtb_Abs_h * rtb_Abs_l);
  rtb_Switch_idx_1 = (rtb_Abs_h * rtb_Abs1_j) - (rtU.I_a * rtb_Abs_l);

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

  /* Product: '<S107>/NProd Out' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
   *  Constant: '<S6>/Constant3'
   *  DiscreteIntegrator: '<S99>/Filter'
   *  Inport: '<Root>/FilterCoefficient_Id'
   *  Inport: '<Root>/Gain_Dd'
   *  Product: '<S98>/DProd Out'
   *  Sum: '<S6>/Add2'
   *  Sum: '<S99>/SumD'
   */
  rtb_NProdOut = (((0.0F - rtb_Switch_idx_0) * rtU.Dd) - rtDW.Filter_DSTATE) *
    rtU.FilterCoefficient;

  /* Sum: '<S113>/Sum' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
   *  Constant: '<S6>/Constant3'
   *  DiscreteIntegrator: '<S104>/Integrator'
   *  Inport: '<Root>/Gain_Pd'
   *  Product: '<S109>/PProd Out'
   *  Sum: '<S6>/Add2'
   */
  rtb_Sum = ((0.0F - rtb_Switch_idx_0) * rtU.Pd) + rtDW.Integrator_DSTATE +
    rtb_NProdOut;

  /* End of Outputs for SubSystem: '<S6>/Park Transform' */

  /* Chart: '<S6>/Vd_Refer_Saturation' incorporates:
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

  /* End of Chart: '<S6>/Vd_Refer_Saturation' */

  /* Sum: '<S6>/Add' incorporates:
   *  Inport: '<Root>/Speed_rpm'
   *  Inport: '<Root>/Speed_rpm_fb'
   */
  rtb_Sum = rtU.Speed_rpm - rtU.Speed_rpm_fb;

  /* Product: '<S155>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S147>/Filter'
   *  Inport: '<Root>/FilterCoefficient_rpm'
   *  Inport: '<Root>/Gain_Drpm'
   *  Product: '<S146>/DProd Out'
   *  Sum: '<S147>/SumD'
   */
  rtb_NProdOut_o = ((rtb_Sum * rtU.Drpm) - rtDW.Filter_DSTATE_e) *
    rtU.FilterCoefficient_k;

  /* Sum: '<S161>/Sum' incorporates:
   *  DiscreteIntegrator: '<S152>/Integrator'
   *  Inport: '<Root>/Gain_Prpm'
   *  Product: '<S157>/PProd Out'
   */
  rtb_Sum_c = (rtb_Sum * rtU.Prpm) + rtDW.Integrator_DSTATE_h + rtb_NProdOut_o;

  /* Chart: '<S6>/Iq_Refer_Saturation' incorporates:
   *  Inport: '<Root>/Thresholds'
   */
  if ((uint32_T)rtDW.is_active_c5_Pegasus_MBD == 0U) {
    rtDW.is_active_c5_Pegasus_MBD = 1U;
    rtDW.is_c5_Pegasus_MBD = IN_Lobby_k;
  } else {
    switch (rtDW.is_c5_Pegasus_MBD) {
     case IN_Lobby_k:
      if (rtb_Sum_c <= rtU.Thresholds.Iq_min_limit_A) {
        rtDW.is_c5_Pegasus_MBD = IN_Lobby1_j;
      } else if (rtb_Sum_c >= rtU.Thresholds.Iq_max_limit_A) {
        rtDW.is_c5_Pegasus_MBD = IN_Lobby2_f;
      } else {
        rtDW.Out_m2 = rtb_Sum_c;
      }
      break;

     case IN_Lobby1_j:
      if (rtb_Sum_c > rtU.Thresholds.Iq_min_limit_A) {
        rtDW.is_c5_Pegasus_MBD = IN_Lobby_k;
      } else {
        rtDW.Out_m2 = rtU.Thresholds.Iq_min_limit_A;
      }
      break;

     default:
      /* case IN_Lobby2: */
      if (rtb_Sum_c < rtU.Thresholds.Iq_max_limit_A) {
        rtDW.is_c5_Pegasus_MBD = IN_Lobby_k;
      } else {
        rtDW.Out_m2 = rtU.Thresholds.Iq_max_limit_A;
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Iq_Refer_Saturation' */

  /* Outputs for Atomic SubSystem: '<S6>/Park Transform' */
  /* Sum: '<S6>/Add3' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S18>/a16'
   */
  rtb_Sum_c = rtDW.Out_m2 - rtb_Switch_idx_1;

  /* End of Outputs for SubSystem: '<S6>/Park Transform' */

  /* Product: '<S59>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S51>/Filter'
   *  Inport: '<Root>/FilterCoefficient_Iq'
   *  Inport: '<Root>/Gain_Dq'
   *  Product: '<S50>/DProd Out'
   *  Sum: '<S51>/SumD'
   */
  rtb_NProdOut_g = ((rtb_Sum_c * rtU.Dq) - rtDW.Filter_DSTATE_f) *
    rtU.FilterCoefficient_n;

  /* Sum: '<S65>/Sum' incorporates:
   *  DiscreteIntegrator: '<S56>/Integrator'
   *  Inport: '<Root>/Gain_Pq'
   *  Product: '<S61>/PProd Out'
   */
  rtb_Switch_idx_0 = (rtb_Sum_c * rtU.Pq) + rtDW.Integrator_DSTATE_e +
    rtb_NProdOut_g;

  /* Chart: '<S6>/Vq_Refer_Saturation' incorporates:
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
        rtDW.Out = rtb_Switch_idx_0;
      }
      break;

     case IN_Lobby1_j:
      if (rtb_Switch_idx_0 > rtU.Thresholds.Vq_min_limit_V) {
        rtDW.is_c3_Pegasus_MBD = IN_Lobby_k;
      } else {
        rtDW.Out = rtU.Thresholds.Vq_min_limit_V;
      }
      break;

     default:
      /* case IN_Lobby2: */
      if (rtb_Switch_idx_0 < rtU.Thresholds.Vq_max_limit_V) {
        rtDW.is_c3_Pegasus_MBD = IN_Lobby_k;
      } else {
        rtDW.Out = rtU.Thresholds.Vq_max_limit_V;
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Vq_Refer_Saturation' */

  /* Outputs for Atomic SubSystem: '<S6>/Inverse Park Transform' */
  /* Switch: '<S24>/Switch' incorporates:
   *  Product: '<S10>/dcos'
   *  Product: '<S10>/dsin'
   *  Product: '<S10>/qcos'
   *  Product: '<S10>/qsin'
   *  Sum: '<S10>/sum_alpha'
   *  Sum: '<S10>/sum_beta'
   */
  rtb_Switch_idx_0 = (rtDW.Out_o * rtb_Abs1_j) - (rtDW.Out * rtb_Abs_l);
  rtb_Switch_idx_1 = (rtDW.Out * rtb_Abs1_j) + (rtDW.Out_o * rtb_Abs_l);

  /* Chart: '<S6>/Va_Saturation' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S10>/a16'
   *  Inport: '<Root>/BusVoltage_V'
   */
  Va_Saturation(rtb_Switch_idx_0, rtU.BusVoltage_V, &rtDW.Out_d,
                &rtDW.sf_Va_Saturation);

  /* Gain: '<S9>/one_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S10>/a16'
   */
  rtb_Abs1_j = 0.5F * rtb_Switch_idx_0;

  /* Gain: '<S9>/sqrt3_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S10>/a16'
   */
  rtb_Abs_l = 0.866025388F * rtb_Switch_idx_1;

  /* End of Outputs for SubSystem: '<S6>/Inverse Park Transform' */

  /* Chart: '<S6>/Vb_Saturation' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   *  Sum: '<S9>/add_b'
   */
  Va_Saturation(rtb_Abs_l - rtb_Abs1_j, rtU.BusVoltage_V, &rtDW.Out_m,
                &rtDW.sf_Vb_Saturation);

  /* Chart: '<S6>/Vc_Saturation' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   *  Sum: '<S9>/add_c'
   */
  Va_Saturation(0.0F - rtb_Abs1_j - rtb_Abs_l, rtU.BusVoltage_V, &rtDW.Out_e,
                &rtDW.sf_Vc_Saturation);

  /* Product: '<S12>/Divide' incorporates:
   *  Gain: '<S12>/Gain'
   *  Inport: '<Root>/BusVoltage_V'
   */
  rtY.FOC_Out.Normalized_Va = (32767.00F * rtDW.Out_d) / rtU.BusVoltage_V;

  /* Product: '<S13>/Divide' incorporates:
   *  Gain: '<S13>/Gain'
   *  Inport: '<Root>/BusVoltage_V'
   */
  rtY.FOC_Out.Normalized_Vb = (32767.00F * rtDW.Out_m) / rtU.BusVoltage_V;

  /* Product: '<S14>/Divide' incorporates:
   *  Gain: '<S14>/Gain'
   *  Inport: '<Root>/BusVoltage_V'
   */
  rtY.FOC_Out.Normalized_Vc = (32767.00F * rtDW.Out_e) / rtU.BusVoltage_V;

  /* BusCreator: '<S6>/Bus Creator' incorporates:
   *  Constant: '<S6>/Constant3'
   *  Outport: '<Root>/FOC_Out'
   */
  rtY.FOC_Out.Id_Refer = 0.0F;
  rtY.FOC_Out.Iq_Refer = rtDW.Out_m2;
  rtY.FOC_Out.Vd_Calculated = rtDW.Out_o;
  rtY.FOC_Out.Vq_Calculated = rtDW.Out;
  rtY.FOC_Out.Va = rtDW.Out_d;
  rtY.FOC_Out.Vb = rtDW.Out_m;
  rtY.FOC_Out.Vc = rtDW.Out_e;

  /* Product: '<S5>/Divide' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   */
  rtb_Abs_l = (1.0F / rtU.BusVoltage_V) * rtDW.Out_e;

  /* Product: '<S3>/Divide' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   */
  rtb_Abs1_j = (1.0F / rtU.BusVoltage_V) * rtDW.Out_d;

  /* Product: '<S4>/Divide' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   */
  rtb_Switch_idx_0 = (1.0F / rtU.BusVoltage_V) * rtDW.Out_m;

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Zero'
   */
  if (rtDW.Out_d > 0.0F) {
    rtb_Switch_idx_1 = rtb_Abs1_j;
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
    rtb_Abs1_j = 0.0F;
  }

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Abs: '<S3>/Abs1'
   *  Outport: '<Root>/DutyCylces'
   *  Switch: '<S3>/Switch1'
   */
  rtY.DutyCylces.Duty_a_neg = fabsf(rtb_Abs1_j);

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
  if (rtDW.Out_e > 0.0F) {
    rtb_Switch_idx_1 = rtb_Abs_l;
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
  if (!(-rtDW.Out_e > 0.0F)) {
    rtb_Abs_l = 0.0F;
  }

  /* BusCreator: '<S1>/Bus Creator' incorporates:
   *  Abs: '<S5>/Abs1'
   *  Outport: '<Root>/DutyCylces'
   *  Switch: '<S5>/Switch1'
   */
  rtY.DutyCylces.Duty_c_neg = fabsf(rtb_Abs_l);

  /* MinMax: '<S7>/Max1' */
  rtb_Abs_l = fmaxf(fmaxf(rtDW.Out_d, rtDW.Out_m), rtDW.Out_e);

  /* MinMax: '<S7>/Max2' incorporates:
   *  Inport: '<Root>/MCTemperature_C'
   *  Inport: '<Root>/MotorTemperature'
   */
  rtb_Abs1_j = fmaxf(rtU.MotorControllerTemperature_C, rtU.MotorTemperature_C);

  /* MinMax: '<S7>/Max' incorporates:
   *  Inport: '<Root>/I_a'
   *  Inport: '<Root>/I_b'
   *  Inport: '<Root>/I_c'
   */
  rtb_Switch_idx_0 = fmaxf(fmaxf(rtU.I_a, rtU.I_b), rtU.I_c);

  /* Chart: '<S7>/Protection_States' incorporates:
   *  Inport: '<Root>/BusVoltage_V'
   *  Inport: '<Root>/Thresholds'
   */
  if ((uint32_T)rtDW.is_active_c7_Pegasus_MBD == 0U) {
    rtDW.is_active_c7_Pegasus_MBD = 1U;
    rtDW.durationCounter_1 = 0;
    rtDW.is_TemperatureProtection = IN_TempSafe;

    /* Outport: '<Root>/MCTempFlag' */
    rtY.MCTempFlag = SafeTemperature;
    rtDW.durationCounter_2_n = 0;
    rtDW.durationCounter_1_jg = 0;
    rtDW.is_VoltageProtection = IN_VoltageSafe;

    /* Outport: '<Root>/VoltageFlag' */
    rtY.VoltageFlag = SafeVoltage;
    rtDW.durationCounter_1_n = 0;
    rtDW.is_CurrentProtection = IN_CurrentSafe;

    /* Outport: '<Root>/CurrentFlag' */
    rtY.CurrentFlag = SafeCurrent;
  } else {
    real_T tmp;
    switch (rtDW.is_TemperatureProtection) {
     case IN_HighTempError:
      /* Outport: '<Root>/MCTempFlag' */
      rtY.MCTempFlag = OT_Error;
      if (!(rtb_Abs1_j < rtU.Thresholds.OTWarningLimit_C)) {
        rtDW.durationCounter_1_k = 0;
      }

      tmp = (real_T)((real32_T)(rtU.Thresholds.TempProtectionTimeout_msec *
        20.0F));
      if ((real_T)rtDW.durationCounter_1_k > tmp) {
        rtDW.durationCounter_1 = 0;
        rtDW.is_TemperatureProtection = IN_TempSafe;

        /* Outport: '<Root>/MCTempFlag' */
        rtY.MCTempFlag = SafeTemperature;
      } else {
        if (!(rtb_Abs1_j < rtU.Thresholds.OTErrorLimit_C)) {
          rtDW.durationCounter_2 = 0;
        }

        if ((real_T)rtDW.durationCounter_2 > tmp) {
          rtDW.durationCounter_2_j = 0;
          rtDW.durationCounter_1_h = 0;
          rtDW.is_TemperatureProtection = IN_HighTempWarning;

          /* Outport: '<Root>/MCTempFlag' */
          rtY.MCTempFlag = OT_Warning;
        }
      }
      break;

     case IN_HighTempWarning:
      /* Outport: '<Root>/MCTempFlag' */
      rtY.MCTempFlag = OT_Warning;
      if (!(rtb_Abs1_j > rtU.Thresholds.OTErrorLimit_C)) {
        rtDW.durationCounter_2_j = 0;
      }

      tmp = (real_T)((real32_T)(rtU.Thresholds.TempProtectionTimeout_msec *
        20.0F));
      if ((real_T)rtDW.durationCounter_2_j > tmp) {
        rtDW.durationCounter_2 = 0;
        rtDW.durationCounter_1_k = 0;
        rtDW.is_TemperatureProtection = IN_HighTempError;

        /* Outport: '<Root>/MCTempFlag' */
        rtY.MCTempFlag = OT_Error;
      } else {
        if (!(rtb_Abs1_j < rtU.Thresholds.OTWarningLimit_C)) {
          rtDW.durationCounter_1_h = 0;
        }

        if ((real_T)rtDW.durationCounter_1_h > tmp) {
          rtDW.durationCounter_1 = 0;
          rtDW.is_TemperatureProtection = IN_TempSafe;

          /* Outport: '<Root>/MCTempFlag' */
          rtY.MCTempFlag = SafeTemperature;
        }
      }
      break;

     default:
      /* Outport: '<Root>/MCTempFlag' */
      /* case IN_TempSafe: */
      rtY.MCTempFlag = SafeTemperature;
      if (!(rtb_Abs1_j > rtU.Thresholds.OTWarningLimit_C)) {
        rtDW.durationCounter_1 = 0;
      }

      if ((real_T)rtDW.durationCounter_1 > (real_T)((real32_T)
           (rtU.Thresholds.TempProtectionTimeout_msec * 20.0F))) {
        rtDW.durationCounter_2_j = 0;
        rtDW.durationCounter_1_h = 0;
        rtDW.is_TemperatureProtection = IN_HighTempWarning;

        /* Outport: '<Root>/MCTempFlag' */
        rtY.MCTempFlag = OT_Warning;
      }
      break;
    }

    VoltageProtection(&rtb_Abs_l);
    switch (rtDW.is_CurrentProtection) {
     case IN_CurrentSafe:
      /* Outport: '<Root>/CurrentFlag' */
      rtY.CurrentFlag = SafeCurrent;
      if (!(rtb_Switch_idx_0 > rtU.Thresholds.OCWarningLimit_A)) {
        rtDW.durationCounter_1_n = 0;
      }

      if ((real_T)rtDW.durationCounter_1_n > (real_T)((real32_T)
           (rtU.Thresholds.CurrentProtectionTimeout_msec * 20.0F))) {
        rtDW.durationCounter_2_i = 0;
        rtDW.durationCounter_1_j = 0;
        rtDW.is_CurrentProtection = IN_OC_Warning;

        /* Outport: '<Root>/CurrentFlag' */
        rtY.CurrentFlag = OC_Warning;
      }
      break;

     case IN_OC_Error:
      /* Outport: '<Root>/CurrentFlag' */
      rtY.CurrentFlag = OC_Error;
      if (!(rtb_Switch_idx_0 < rtU.Thresholds.OCWarningLimit_A)) {
        rtDW.durationCounter_1_h3 = 0;
      }

      tmp = (real_T)((real32_T)(rtU.Thresholds.CurrentProtectionTimeout_msec *
        20.0F));
      if ((real_T)rtDW.durationCounter_1_h3 > tmp) {
        rtDW.durationCounter_1_n = 0;
        rtDW.is_CurrentProtection = IN_CurrentSafe;

        /* Outport: '<Root>/CurrentFlag' */
        rtY.CurrentFlag = SafeCurrent;
      } else {
        if (!(rtb_Switch_idx_0 < rtU.Thresholds.OCErrorLimit_A)) {
          rtDW.durationCounter_2_d = 0;
        }

        if ((real_T)rtDW.durationCounter_2_d > tmp) {
          rtDW.durationCounter_2_i = 0;
          rtDW.durationCounter_1_j = 0;
          rtDW.is_CurrentProtection = IN_OC_Warning;

          /* Outport: '<Root>/CurrentFlag' */
          rtY.CurrentFlag = OC_Warning;
        }
      }
      break;

     default:
      /* Outport: '<Root>/CurrentFlag' */
      /* case IN_OC_Warning: */
      rtY.CurrentFlag = OC_Warning;
      if (!(rtb_Switch_idx_0 > rtU.Thresholds.OCErrorLimit_A)) {
        rtDW.durationCounter_2_i = 0;
      }

      tmp = (real_T)((real32_T)(rtU.Thresholds.CurrentProtectionTimeout_msec *
        20.0F));
      if ((real_T)rtDW.durationCounter_2_i > tmp) {
        rtDW.durationCounter_2_d = 0;
        rtDW.durationCounter_1_h3 = 0;
        rtDW.is_CurrentProtection = IN_OC_Error;

        /* Outport: '<Root>/CurrentFlag' */
        rtY.CurrentFlag = OC_Error;
      } else {
        if (!(rtb_Switch_idx_0 < rtU.Thresholds.OCWarningLimit_A)) {
          rtDW.durationCounter_1_j = 0;
        }

        if ((real_T)rtDW.durationCounter_1_j > tmp) {
          rtDW.durationCounter_1_n = 0;
          rtDW.is_CurrentProtection = IN_CurrentSafe;

          /* Outport: '<Root>/CurrentFlag' */
          rtY.CurrentFlag = SafeCurrent;
        }
      }
      break;
    }
  }

  if (rtb_Abs1_j > rtU.Thresholds.OTWarningLimit_C) {
    rtDW.durationCounter_1++;
  } else {
    rtDW.durationCounter_1 = 0;
  }

  if (rtb_Abs1_j < rtU.Thresholds.OTWarningLimit_C) {
    rtDW.durationCounter_1_k++;
    rtDW.durationCounter_1_h++;
  } else {
    rtDW.durationCounter_1_k = 0;
    rtDW.durationCounter_1_h = 0;
  }

  if (rtb_Abs1_j < rtU.Thresholds.OTErrorLimit_C) {
    rtDW.durationCounter_2++;
  } else {
    rtDW.durationCounter_2 = 0;
  }

  if (rtb_Abs1_j > rtU.Thresholds.OTErrorLimit_C) {
    rtDW.durationCounter_2_j++;
  } else {
    rtDW.durationCounter_2_j = 0;
  }

  if (rtb_Switch_idx_0 > rtU.Thresholds.OCWarningLimit_A) {
    rtDW.durationCounter_1_n++;
  } else {
    rtDW.durationCounter_1_n = 0;
  }

  if (rtb_Switch_idx_0 < rtU.Thresholds.OCWarningLimit_A) {
    rtDW.durationCounter_1_h3++;
    rtDW.durationCounter_1_j++;
  } else {
    rtDW.durationCounter_1_h3 = 0;
    rtDW.durationCounter_1_j = 0;
  }

  if (rtb_Switch_idx_0 < rtU.Thresholds.OCErrorLimit_A) {
    rtDW.durationCounter_2_d++;
  } else {
    rtDW.durationCounter_2_d = 0;
  }

  if (rtb_Switch_idx_0 > rtU.Thresholds.OCErrorLimit_A) {
    rtDW.durationCounter_2_i++;
  } else {
    rtDW.durationCounter_2_i = 0;
  }

  if (rtU.BusVoltage_V > rtU.Thresholds.UVErrorLimit_V) {
    rtDW.durationCounter_1_a++;
  } else {
    rtDW.durationCounter_1_a = 0;
  }

  if (rtU.BusVoltage_V < rtU.Thresholds.UVErrorLimit_V) {
    rtDW.durationCounter_1_hz++;
  } else {
    rtDW.durationCounter_1_hz = 0;
  }

  if (rtU.BusVoltage_V < rtU.Thresholds.UVWarningLimit_V) {
    rtDW.durationCounter_1_jg++;
  } else {
    rtDW.durationCounter_1_jg = 0;
  }

  if (rtU.BusVoltage_V > rtU.Thresholds.UVWarningLimit_V) {
    rtDW.durationCounter_2_f++;
    rtDW.durationCounter_2_h++;
  } else {
    rtDW.durationCounter_2_f = 0;
    rtDW.durationCounter_2_h = 0;
  }

  if ((real32_T)(((rtb_Abs_l != 0.0F) || (rtU.BusVoltage_V != 0.0F)) ? ((int32_T)
        1) : ((int32_T)0)) > rtU.Thresholds.OVWarningLimit_V) {
    rtDW.durationCounter_2_n++;
  } else {
    rtDW.durationCounter_2_n = 0;
  }

  if ((real32_T)(((rtb_Abs_l != 0.0F) || (rtU.BusVoltage_V != 0.0F)) ? ((int32_T)
        1) : ((int32_T)0)) < rtU.Thresholds.OVWarningLimit_V) {
    rtDW.durationCounter_1_f++;
    rtDW.durationCounter_1_g++;
  } else {
    rtDW.durationCounter_1_f = 0;
    rtDW.durationCounter_1_g = 0;
  }

  if ((real32_T)(((rtb_Abs_l != 0.0F) || (rtU.BusVoltage_V != 0.0F)) ? ((int32_T)
        1) : ((int32_T)0)) < rtU.Thresholds.OVErrorLimit_V) {
    rtDW.durationCounter_2_g++;
  } else {
    rtDW.durationCounter_2_g = 0;
  }

  if ((real32_T)(((rtb_Abs_l != 0.0F) || (rtU.BusVoltage_V != 0.0F)) ? ((int32_T)
        1) : ((int32_T)0)) > rtU.Thresholds.OVErrorLimit_V) {
    rtDW.durationCounter_2_f0++;
  } else {
    rtDW.durationCounter_2_f0 = 0;
  }

  /* End of Chart: '<S7>/Protection_States' */

  /* Update for DiscreteIntegrator: '<S104>/Integrator' incorporates:
   *  Inport: '<Root>/Gain_Id'
   *  Product: '<S101>/IProd Out'
   */
  rtDW.Integrator_DSTATE += (rtb_Abs_h * rtU.Id) * 5.0E-5F;

  /* Update for DiscreteIntegrator: '<S99>/Filter' */
  rtDW.Filter_DSTATE += 5.0E-5F * rtb_NProdOut;

  /* Update for DiscreteIntegrator: '<S152>/Integrator' incorporates:
   *  Inport: '<Root>/Gain_Irpm'
   *  Product: '<S149>/IProd Out'
   */
  rtDW.Integrator_DSTATE_h += (rtb_Sum * rtU.Irpm) * 5.0E-5F;

  /* Update for DiscreteIntegrator: '<S147>/Filter' */
  rtDW.Filter_DSTATE_e += 5.0E-5F * rtb_NProdOut_o;

  /* Update for DiscreteIntegrator: '<S56>/Integrator' incorporates:
   *  Inport: '<Root>/Gain_Iq'
   *  Product: '<S53>/IProd Out'
   */
  rtDW.Integrator_DSTATE_e += (rtb_Sum_c * rtU.Iq) * 5.0E-5F;

  /* Update for DiscreteIntegrator: '<S51>/Filter' */
  rtDW.Filter_DSTATE_f += 5.0E-5F * rtb_NProdOut_g;
}

/* Model initialize function */
void Pegasus_MBD_initialize(void)
{
  /* SystemInitialize for Chart: '<S6>/Va_Saturation' */
  Va_Saturation_Init(&rtDW.Out_d);

  /* SystemInitialize for Chart: '<S6>/Vb_Saturation' */
  Va_Saturation_Init(&rtDW.Out_m);

  /* SystemInitialize for Chart: '<S6>/Vc_Saturation' */
  Va_Saturation_Init(&rtDW.Out_e);

  rtU.Pole_pairs = POLEPAIRS;
  rtU.Rs = 0.0107;
  rtU.Ld = 0.000146;
  rtU.Lq = 0.000387;
  rtU.Lambda_m = 0.0263;
  rtU.Pq = 0.5;
  rtU.Iq = 8;
  rtU.Dq = 0.01;
  rtU.Pd = 0.5;
  rtU.Id = 8;
  rtU.Dd = 0.01;
  rtU.Prpm = 1;
  rtU.Irpm = 5;
  rtU.Drpm = 0.01;
  rtU.FilterCoefficient = 10.0;
  rtU.FilterCoefficient_n = 10.0;
  rtU.FilterCoefficient_k = 10.0;
  rtU.Thresholds.Iq_max_limit_A = 550.0;
  rtU.Thresholds.Iq_min_limit_A = -550.0;
  rtU.Thresholds.Vq_max_limit_V = 49.0;
  rtU.Thresholds.Vq_min_limit_V = -49.0;
  rtU.Thresholds.Vd_max_limit_V = 49.0;
  rtU.Thresholds.Vd_min_limit_V = -49.0;
  rtU.Thresholds.MaxCurrentLimit_A = 550.0;
  rtU.Thresholds.OTWarningLimit_C = 80.0;
  rtU.Thresholds.OTErrorLimit_C = 100.0;
  rtU.Thresholds.UVWarningLimit_V = 45.0;
  rtU.Thresholds.UVErrorLimit_V = 40.0;
  rtU.Thresholds.OVWarningLimit_V = 65.0;
  rtU.Thresholds.OVErrorLimit_V = 70.0;
  rtU.Thresholds.OCWarningLimit_A = 500.0;
  rtU.Thresholds.OCErrorLimit_A = 550.0;
  rtU.Thresholds.WarningSpeedLimit_rpm = 3200.0;
  rtU.Thresholds.VoltageProtectionTimeout_msec = 1.0;
  rtU.Thresholds.TempProtectionTimeout_msec = 10.0;
  rtU.Thresholds.CurrentProtectionTimeout_msec = 1.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
