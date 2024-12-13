/*
 * FOC.h
 *
 * Code generation for model "FOC".
 *
 * Model version              : 18.35
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Nov 29 17:26:01 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef FOC_h_
#define FOC_h_
#ifndef FOC_COMMON_INCLUDES_
#define FOC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* FOC_COMMON_INCLUDES_ */

#include "FOC_types.h"
#include <stddef.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  char_T Iq_OL_Flag;
  char_T dcV_OV_Flag;
  char_T dcV_UV_Flag;
  char_T Ph_OC_Flag;
  char_T OT_Cont_Flag;
  char_T N_Flag;
} FOC_Flag_T;

typedef struct {
  ThresholdsBus BusConversion_InsertedFor_Prote;
  real_T Max1;                         /* '<S3>/Max1' */
} B_FOC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S69>/Integrator' */
  real_T Filter_DSTATE;                /* '<S64>/Filter' */
  real_T Integrator_DSTATE_p;          /* '<S125>/Integrator' */
  real_T Filter_DSTATE_k;              /* '<S120>/Filter' */
  real_T Integrator_DSTATE_h;          /* '<S181>/Integrator' */
  real_T Filter_DSTATE_d;              /* '<S176>/Filter' */
  uint32_T durationCounter_1;          /* '<S3>/Protection_States' */
  uint32_T durationCounter_1_c;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_1_e;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_2;          /* '<S3>/Protection_States' */
  uint32_T durationCounter_2_e;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_1_i;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_1_a;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_1_d;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_2_b;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_2_c;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_1_e3;       /* '<S3>/Protection_States' */
  uint32_T durationCounter_1_o;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_1_h;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_2_k;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_2_n;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_2_c0;       /* '<S3>/Protection_States' */
  uint32_T durationCounter_1_m;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_1_f;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_2_d;        /* '<S3>/Protection_States' */
  uint32_T durationCounter_2_bq;       /* '<S3>/Protection_States' */
  uint8_T is_active_c7_FOC;            /* '<S3>/Protection_States' */
  uint8_T is_TemperatureProtection;    /* '<S3>/Protection_States' */
  uint8_T is_VoltageProtection;        /* '<S3>/Protection_States' */
  uint8_T is_CurrentProtection;        /* '<S3>/Protection_States' */
} DW_FOC_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Switch;                 /* '<S202>/Switch' */
  const real_T Switch1;                /* '<S202>/Switch1' */
  const real_T Switch2;                /* '<S202>/Switch2' */
  const real32_T UVErrorLimit_V;       /* '<S4>/Data Type Conversion10' */
  const real32_T OVWarningLimit_V;     /* '<S4>/Data Type Conversion11' */
  const real32_T OVErrorLimit_V;       /* '<S4>/Data Type Conversion12' */
  const real32_T OCWarningLimit_A;     /* '<S4>/Data Type Conversion13' */
  const real32_T OCErrorLimit_A;       /* '<S4>/Data Type Conversion14' */
  const real32_T WarningSpeedLimit_rpm;/* '<S4>/Data Type Conversion15' */
  const real32_T VoltageProtectionTimeout_ms;/* '<S4>/Data Type Conversion16' */
  const real32_T TempProtectionTimeout_msec;/* '<S4>/Data Type Conversion17' */
  const real32_T CurrentProtectionTimeout_ms;/* '<S4>/Data Type Conversion18' */
  const real32_T MaxCurrentLimit_A;    /* '<S4>/Data Type Conversion6' */
  const real32_T OTWarningLimit_C;     /* '<S4>/Data Type Conversion7' */
  const real32_T OTErrorLimit_C;       /* '<S4>/Data Type Conversion8' */
  const real32_T UVWarningLimit_V;     /* '<S4>/Data Type Conversion9' */
} ConstB_FOC_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T RefSpeed;                     /* '<Root>/Ref Speed' */
  real_T ActualSpeed;                  /* '<Root>/Actual Speed' */
  real_T angle;                        /* '<Root>/angle' */
  real_T Kp_flux_PID;                  /* '<Root>/Kp_flux_PID' */
  real_T Ki_flux_PID;                  /* '<Root>/Ki_flux_PID' */
  real_T Kd_flux_PID;                  /* '<Root>/Kd_flux_PID' */
  real_T Filter_flux_PID;              /* '<Root>/Filter_flux_PID' */
  real_T Up_Limit_flux_PID;            /* '<Root>/Up_Limit_flux_PID' */
  real_T Low_Limit_flux_PID;           /* '<Root>/Low_Limit_flux_PID' */
  real_T PhaseCurrent[3];              /* '<Root>/Phase Current' */
  real_T Kp_speed_PID;                 /* '<Root>/Kp_speed_PID' */
  real_T Ki_speed_PID;                 /* '<Root>/Ki_speed_PID' */
  real_T Kd_speed_PID;                 /* '<Root>/Kd_speed_PID' */
  real_T Filter_speed_PID;             /* '<Root>/Filter_speed_PID' */
  real_T Up_Limit_speed_PID;           /* '<Root>/Up_Limit_speed_PID' */
  real_T Low_Limit_speed_PID;          /* '<Root>/Low_Limit_speed_PID' */
  real_T Kp_torque_PID;                /* '<Root>/Kp_torque_PID' */
  real_T Ki_torque_PID;                /* '<Root>/Ki_torque_PID' */
  real_T Kd_torque_PID;                /* '<Root>/Kd_torque_PID' */
  real_T Filter_torque_PID;            /* '<Root>/Filter_torque_PID' */
  real_T Up_Limit_torque_PID;          /* '<Root>/Up_Limit_torque_PID' */
  real_T Low_Limit_torque_PID;         /* '<Root>/Low_Limit_torque_PID' */
  real32_T MCTemperature_C;            /* '<Root>/MCTemperature_C' */
  real32_T MotorTemperature_C;         /* '<Root>/MotorTemperature_C' */
  real32_T BusVoltage_V;               /* '<Root>/BusVoltage_V' */
  real32_T Lamda;                      /* '<Root>/Lamda' */
  real32_T Ld;                         /* '<Root>/Ld' */
  real32_T Lq;                         /* '<Root>/Lq' */
  real32_T Rs;                           /* '<Root>/Motor Resistance' */
  real32_T p;                          /* '<Root>/p' */
  real32_T Id_up_limit;                /* '<Root>/Id_up_limit' */
  real32_T Id_low_limit;               /* '<Root>/Id_low_limit' */
  real32_T Iq_up_limit;                /* '<Root>/Iq_up_limit' */
  real32_T Iq_low_limit;               /* '<Root>/Iq_low_limit' */
} ExtU_FOC_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Va;                           /* '<Root>/Va' */
  real_T Vb;                           /* '<Root>/Vb' */
  real_T Vc;                           /* '<Root>/Vc' */
  real_T Id;                           /* '<Root>/Id' */
  real_T Iq;                           /* '<Root>/Iq' */
  real_T Iq_refer;                     /* '<Root>/Iq_refer' */
  real_T Id_refer;                     /* '<Root>/Id_refer' */
  real_T Vd;                           /* '<Root>/Vd' */
  real_T Vq;                           /* '<Root>/Vq' */
  TempState TempFlag;                  /* '<Root>/TempFlag' */
  VoltageState VoltageFlag;            /* '<Root>/VoltageFlag' */
  CurrentState CurrentFlag;            /* '<Root>/CurrentFlag' */
} ExtY_FOC_T;

/* Real-time Model Data Structure */
struct tag_RTM_FOC_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_FOC_T FOC_B;

/* Block states (default storage) */
extern DW_FOC_T FOC_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_FOC_T FOC_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_FOC_T FOC_Y;

extern FOC_Flag_T FOC_F_T;

extern const ConstB_FOC_T FOC_ConstB;  /* constant block i/o */

/* Model entry point functions */
extern void FOC_initialize(void);
extern void FOC_step(void);
extern void FOC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FOC_T *const FOC_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Propagation' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Propagation' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/Data Type Propagation' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate' : Unused code path elimination
 * Block '<S133>/Data Type Propagation' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate' : Unused code path elimination
 * Block '<S189>/Data Type Propagation' : Unused code path elimination
 * Block '<S201>/Data Type Duplicate' : Unused code path elimination
 * Block '<S203>/Data Type Duplicate' : Unused code path elimination
 * Block '<S204>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Kalpha' : Eliminated nontunable gain of 1
 * Block '<S10>/Kbeta' : Eliminated nontunable gain of 1
 * Block '<S17>/Ka' : Eliminated nontunable gain of 1
 * Block '<S17>/Kb' : Eliminated nontunable gain of 1
 * Block '<S17>/Kc' : Eliminated nontunable gain of 1
 * Block '<S201>/Gain' : Eliminated nontunable gain of 1
 * Block '<S202>/Gain' : Eliminated nontunable gain of 1
 * Block '<S202>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S202>/Gain2' : Eliminated nontunable gain of 1
 * Block '<S201>/VdFF_si2pu' : Eliminated nontunable gain of 1
 * Block '<S201>/VqFF_si2pu' : Eliminated nontunable gain of 1
 * Block '<S201>/id_pu2si' : Eliminated nontunable gain of 1
 * Block '<S201>/iq_pu2si' : Eliminated nontunable gain of 1
 * Block '<S13>/Offset' : Unused code path elimination
 * Block '<S13>/Unary_Minus' : Unused code path elimination
 * Block '<S19>/Offset' : Unused code path elimination
 * Block '<S19>/Unary_Minus' : Unused code path elimination
 * Block '<S201>/Constant' : Unused code path elimination
 * Block '<S201>/vsat_mask_input' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC')    - opens subsystem IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC
 * hilite_system('IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test'
 * '<S1>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC'
 * '<S2>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA'
 * '<S3>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/Protections'
 * '<S4>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/Thresholds'
 * '<S5>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Clarke_Park'
 * '<S6>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Inverse_Clarke_Park'
 * '<S7>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID'
 * '<S8>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Clarke_Park/Clarke Transform'
 * '<S9>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Clarke_Park/Park Transform'
 * '<S10>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Clarke_Park/Clarke Transform/Two phase input'
 * '<S11>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Clarke_Park/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S12>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Clarke_Park/Park Transform/Two inputs CRL'
 * '<S13>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Clarke_Park/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S14>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Inverse_Clarke_Park/Inverse Clarke Transform'
 * '<S15>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Inverse_Clarke_Park/Inverse Park Transform'
 * '<S16>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Inverse_Clarke_Park/PWM Reference Generator'
 * '<S17>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Inverse_Clarke_Park/Inverse Clarke Transform/Two phase input'
 * '<S18>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Inverse_Clarke_Park/Inverse Park Transform/Two inputs CRL'
 * '<S19>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Inverse_Clarke_Park/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S20>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Inverse_Clarke_Park/PWM Reference Generator/Modulation method'
 * '<S21>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Inverse_Clarke_Park/PWM Reference Generator/Voltage Input'
 * '<S22>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Inverse_Clarke_Park/PWM Reference Generator/Modulation method/SVPWM'
 * '<S23>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Inverse_Clarke_Park/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S24>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/Inverse_Clarke_Park/PWM Reference Generator/Voltage Input/Vabc'
 * '<S25>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/MTPA'
 * '<S26>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq'
 * '<S27>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd'
 * '<S28>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq'
 * '<S29>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PMSM FeedForward Control'
 * '<S30>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/MTPA/Saturation Dynamic'
 * '<S31>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/MTPA/Saturation Dynamic1'
 * '<S32>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Anti-windup'
 * '<S33>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/D Gain'
 * '<S34>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/External Derivative'
 * '<S35>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Filter'
 * '<S36>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Filter ICs'
 * '<S37>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/I Gain'
 * '<S38>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Ideal P Gain'
 * '<S39>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Ideal P Gain Fdbk'
 * '<S40>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Integrator'
 * '<S41>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Integrator ICs'
 * '<S42>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/N Copy'
 * '<S43>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/N Gain'
 * '<S44>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/P Copy'
 * '<S45>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Parallel P Gain'
 * '<S46>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Reset Signal'
 * '<S47>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Saturation'
 * '<S48>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Saturation Fdbk'
 * '<S49>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Sum'
 * '<S50>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Sum Fdbk'
 * '<S51>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Tracking Mode'
 * '<S52>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Tracking Mode Sum'
 * '<S53>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Tsamp - Integral'
 * '<S54>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Tsamp - Ngain'
 * '<S55>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/postSat Signal'
 * '<S56>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/preInt Signal'
 * '<S57>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/preSat Signal'
 * '<S58>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Anti-windup/Disc. Clamping Parallel'
 * '<S59>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S60>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S61>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S62>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/D Gain/External Parameters'
 * '<S63>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/External Derivative/Error'
 * '<S64>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Filter/Disc. Forward Euler Filter'
 * '<S65>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Filter ICs/Internal IC - Filter'
 * '<S66>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/I Gain/External Parameters'
 * '<S67>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Ideal P Gain/Passthrough'
 * '<S68>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Ideal P Gain Fdbk/Disabled'
 * '<S69>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Integrator/Discrete'
 * '<S70>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Integrator ICs/Internal IC'
 * '<S71>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/N Copy/Disabled'
 * '<S72>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/N Gain/External Parameters'
 * '<S73>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/P Copy/Disabled'
 * '<S74>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Parallel P Gain/External Parameters'
 * '<S75>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Reset Signal/Disabled'
 * '<S76>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Saturation/External'
 * '<S77>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Saturation/External/Saturation Dynamic'
 * '<S78>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Saturation Fdbk/Disabled'
 * '<S79>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Sum/Sum_PID'
 * '<S80>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Sum Fdbk/Disabled'
 * '<S81>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Tracking Mode/Disabled'
 * '<S82>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Tracking Mode Sum/Passthrough'
 * '<S83>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Tsamp - Integral/TsSignalSpecification'
 * '<S84>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/Tsamp - Ngain/Passthrough'
 * '<S85>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/postSat Signal/Forward_Path'
 * '<S86>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/preInt Signal/Internal PreInt'
 * '<S87>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Iq/preSat Signal/Forward_Path'
 * '<S88>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Anti-windup'
 * '<S89>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/D Gain'
 * '<S90>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/External Derivative'
 * '<S91>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Filter'
 * '<S92>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Filter ICs'
 * '<S93>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/I Gain'
 * '<S94>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Ideal P Gain'
 * '<S95>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Ideal P Gain Fdbk'
 * '<S96>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Integrator'
 * '<S97>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Integrator ICs'
 * '<S98>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/N Copy'
 * '<S99>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/N Gain'
 * '<S100>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/P Copy'
 * '<S101>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Parallel P Gain'
 * '<S102>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Reset Signal'
 * '<S103>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Saturation'
 * '<S104>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Saturation Fdbk'
 * '<S105>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Sum'
 * '<S106>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Sum Fdbk'
 * '<S107>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Tracking Mode'
 * '<S108>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Tracking Mode Sum'
 * '<S109>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Tsamp - Integral'
 * '<S110>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Tsamp - Ngain'
 * '<S111>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/postSat Signal'
 * '<S112>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/preInt Signal'
 * '<S113>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/preSat Signal'
 * '<S114>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Anti-windup/Disc. Clamping Parallel'
 * '<S115>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S116>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S117>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S118>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/D Gain/External Parameters'
 * '<S119>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/External Derivative/Error'
 * '<S120>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Filter/Disc. Forward Euler Filter'
 * '<S121>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Filter ICs/Internal IC - Filter'
 * '<S122>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/I Gain/External Parameters'
 * '<S123>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Ideal P Gain/Passthrough'
 * '<S124>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Ideal P Gain Fdbk/Disabled'
 * '<S125>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Integrator/Discrete'
 * '<S126>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Integrator ICs/Internal IC'
 * '<S127>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/N Copy/Disabled'
 * '<S128>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/N Gain/External Parameters'
 * '<S129>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/P Copy/Disabled'
 * '<S130>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Parallel P Gain/External Parameters'
 * '<S131>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Reset Signal/Disabled'
 * '<S132>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Saturation/External'
 * '<S133>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Saturation/External/Saturation Dynamic'
 * '<S134>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Saturation Fdbk/Disabled'
 * '<S135>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Sum/Sum_PID'
 * '<S136>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Sum Fdbk/Disabled'
 * '<S137>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Tracking Mode/Disabled'
 * '<S138>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Tracking Mode Sum/Passthrough'
 * '<S139>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Tsamp - Integral/TsSignalSpecification'
 * '<S140>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/Tsamp - Ngain/Passthrough'
 * '<S141>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/postSat Signal/Forward_Path'
 * '<S142>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/preInt Signal/Internal PreInt'
 * '<S143>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vd/preSat Signal/Forward_Path'
 * '<S144>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Anti-windup'
 * '<S145>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/D Gain'
 * '<S146>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/External Derivative'
 * '<S147>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Filter'
 * '<S148>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Filter ICs'
 * '<S149>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/I Gain'
 * '<S150>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Ideal P Gain'
 * '<S151>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Ideal P Gain Fdbk'
 * '<S152>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Integrator'
 * '<S153>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Integrator ICs'
 * '<S154>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/N Copy'
 * '<S155>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/N Gain'
 * '<S156>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/P Copy'
 * '<S157>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Parallel P Gain'
 * '<S158>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Reset Signal'
 * '<S159>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Saturation'
 * '<S160>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Saturation Fdbk'
 * '<S161>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Sum'
 * '<S162>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Sum Fdbk'
 * '<S163>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Tracking Mode'
 * '<S164>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Tracking Mode Sum'
 * '<S165>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Tsamp - Integral'
 * '<S166>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Tsamp - Ngain'
 * '<S167>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/postSat Signal'
 * '<S168>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/preInt Signal'
 * '<S169>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/preSat Signal'
 * '<S170>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Anti-windup/Disc. Clamping Parallel'
 * '<S171>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S172>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S173>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
 * '<S174>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/D Gain/External Parameters'
 * '<S175>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/External Derivative/Error'
 * '<S176>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Filter/Disc. Forward Euler Filter'
 * '<S177>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Filter ICs/Internal IC - Filter'
 * '<S178>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/I Gain/External Parameters'
 * '<S179>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Ideal P Gain/Passthrough'
 * '<S180>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Ideal P Gain Fdbk/Disabled'
 * '<S181>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Integrator/Discrete'
 * '<S182>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Integrator ICs/Internal IC'
 * '<S183>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/N Copy/Disabled'
 * '<S184>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/N Gain/External Parameters'
 * '<S185>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/P Copy/Disabled'
 * '<S186>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Parallel P Gain/External Parameters'
 * '<S187>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Reset Signal/Disabled'
 * '<S188>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Saturation/External'
 * '<S189>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Saturation/External/Saturation Dynamic'
 * '<S190>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Saturation Fdbk/Disabled'
 * '<S191>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Sum/Sum_PID'
 * '<S192>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Sum Fdbk/Disabled'
 * '<S193>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Tracking Mode/Disabled'
 * '<S194>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Tracking Mode Sum/Passthrough'
 * '<S195>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Tsamp - Integral/TsSignalSpecification'
 * '<S196>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/Tsamp - Ngain/Passthrough'
 * '<S197>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/postSat Signal/Forward_Path'
 * '<S198>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/preInt Signal/Internal PreInt'
 * '<S199>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PI Vq/preSat Signal/Forward_Path'
 * '<S200>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PMSM FeedForward Control/FeedForward Control Selection'
 * '<S201>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PMSM FeedForward Control/FeedForward Control Selection/Linear FeedForward_LumpedParameter_InputPort'
 * '<S202>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PMSM FeedForward Control/FeedForward Control Selection/Linear FeedForward_LumpedParameter_InputPort/LumpedParams_InpurPorts'
 * '<S203>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PMSM FeedForward Control/FeedForward Control Selection/Linear FeedForward_LumpedParameter_InputPort/Vd_sat'
 * '<S204>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/FOC_MTPA/PID/PMSM FeedForward Control/FeedForward Control Selection/Linear FeedForward_LumpedParameter_InputPort/Vq_sat'
 * '<S205>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_MTPA_Test/FOC/Protections/Protection_States'
 */
#endif                                 /* FOC_h_ */
