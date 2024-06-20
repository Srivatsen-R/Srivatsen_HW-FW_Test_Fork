/*
 * File: Pegasus_MBD.h
 *
 * Code generated for Simulink model 'Pegasus_MBD'.
 *
 * Model version                  : 1.190
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jun 18 18:20:11 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pegasus_MBD_h_
#define RTW_HEADER_Pegasus_MBD_h_
#ifndef Pegasus_MBD_COMMON_INCLUDES_
#define Pegasus_MBD_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Pegasus_MBD_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_ThresholdsBus_
#define DEFINED_TYPEDEF_FOR_ThresholdsBus_

typedef struct {
  real32_T BusVoltage_V;
  real32_T Iq_max_limit_A;
  real32_T Iq_min_limit_A;
  real32_T Vq_max_limit_V;
  real32_T Vq_min_limit_V;
  real32_T Vd_max_limit_V;
  real32_T Vd_min_limit_V;
  real32_T MaxCurrentLimit_A;
  real32_T OTWarningLimit_C;
  real32_T OTErrorLimit_C;
  real32_T UVWarningLimit_V;
  real32_T UVErrorLimit_V;
  real32_T OVWarningLimit_V;
  real32_T OVErrorLimit_V;
  real32_T OCWarningLimit_A;
  real32_T OCErrorLimit_A;
  real32_T WarningSpeedLimit_rpm;
  real32_T VoltageProtectionTimeout_msec;
  real32_T TempProtectionTimeout_msec;
  real32_T CurrentProtectionTimeout_msec;
} ThresholdsBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_DutyCycleBus_
#define DEFINED_TYPEDEF_FOR_DutyCycleBus_

typedef struct {
  real32_T Duty_a_pos;
  real32_T Duty_a_neg;
  real32_T Duty_b_pos;
  real32_T Duty_b_neg;
  real32_T Duty_c_pos;
  real32_T Duty_c_neg;
} DutyCycleBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FOC_OutBus_
#define DEFINED_TYPEDEF_FOR_FOC_OutBus_

typedef struct {
  real32_T Id_Refer;
  real32_T Iq_Refer;
  real32_T Id_Calculated;
  real32_T Iq_Calculated;
  real32_T Vd_Calculated;
  real32_T Vq_Calculated;
  real32_T Va;
  real32_T Vb;
  real32_T Vc;
  real32_T Normalized_Va;
  real32_T Normalized_Vb;
  real32_T Normalized_Vc;
} FOC_OutBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MCTempState_
#define DEFINED_TYPEDEF_FOR_MCTempState_

typedef enum {
  SafeTemperature = 0,                 /* Default value */
  OT_Warning,
  OT_Error
} MCTempState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_VoltageState_
#define DEFINED_TYPEDEF_FOR_VoltageState_

typedef enum {
  SafeVoltage = 0,                     /* Default value */
  OV_Warning,
  OV_Error,
  UV_Warning,
  UV_Error
} VoltageState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CurrentState_
#define DEFINED_TYPEDEF_FOR_CurrentState_

typedef enum {
  SafeCurrent = 0,                     /* Default value */
  OC_Warning,
  OC_Error
} CurrentState;

#endif

/* Block signals and states (default storage) for system '<S6>/Va_Saturation' */
typedef struct {
  uint8_T is_c1_Pegasus_MBD;           /* '<S6>/Va_Saturation' */
  uint8_T is_active_c1_Pegasus_MBD;    /* '<S6>/Va_Saturation' */
} DW_Va_Saturation;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_Va_Saturation sf_Vc_Saturation;   /* '<S6>/Vc_Saturation' */
  DW_Va_Saturation sf_Vb_Saturation;   /* '<S6>/Vb_Saturation' */
  DW_Va_Saturation sf_Va_Saturation;   /* '<S6>/Va_Saturation' */
  real32_T Out;                        /* '<S6>/Vq_Refer_Saturation' */
  real32_T Out_o;                      /* '<S6>/Vd_Refer_Saturation' */
  real32_T Out_e;                      /* '<S6>/Vc_Saturation' */
  real32_T Out_m;                      /* '<S6>/Vb_Saturation' */
  real32_T Out_d;                      /* '<S6>/Va_Saturation' */
  real32_T Out_m2;                     /* '<S6>/Iq_Refer_Saturation' */
  real32_T Integrator_DSTATE;          /* '<S103>/Integrator' */
  real32_T Filter_DSTATE;              /* '<S98>/Filter' */
  real32_T Integrator_DSTATE_e;        /* '<S55>/Integrator' */
  real32_T Filter_DSTATE_f;            /* '<S50>/Filter' */
  int32_T durationCounter_1;           /* '<S7>/Protection_States' */
  int32_T durationCounter_1_k;         /* '<S7>/Protection_States' */
  int32_T durationCounter_1_h;         /* '<S7>/Protection_States' */
  int32_T durationCounter_2;           /* '<S7>/Protection_States' */
  int32_T durationCounter_2_j;         /* '<S7>/Protection_States' */
  int32_T durationCounter_1_n;         /* '<S7>/Protection_States' */
  int32_T durationCounter_1_h3;        /* '<S7>/Protection_States' */
  int32_T durationCounter_1_j;         /* '<S7>/Protection_States' */
  int32_T durationCounter_2_d;         /* '<S7>/Protection_States' */
  int32_T durationCounter_2_i;         /* '<S7>/Protection_States' */
  int32_T durationCounter_2_j2;        /* '<S7>/Protection_States' */
  int32_T durationCounter_1_hz;        /* '<S7>/Protection_States' */
  int32_T durationCounter_1_jg;        /* '<S7>/Protection_States' */
  int32_T durationCounter_2_f;         /* '<S7>/Protection_States' */
  int32_T durationCounter_2_h;         /* '<S7>/Protection_States' */
  int32_T durationCounter_1_kl;        /* '<S7>/Protection_States' */
  int32_T durationCounter_1_f;         /* '<S7>/Protection_States' */
  int32_T durationCounter_1_g;         /* '<S7>/Protection_States' */
  int32_T durationCounter_2_g;         /* '<S7>/Protection_States' */
  int32_T durationCounter_2_f0;        /* '<S7>/Protection_States' */
  uint8_T is_TemperatureProtection;    /* '<S7>/Protection_States' */
  uint8_T is_VoltageProtection;        /* '<S7>/Protection_States' */
  uint8_T is_CurrentProtection;        /* '<S7>/Protection_States' */
  uint8_T is_active_c7_Pegasus_MBD;    /* '<S7>/Protection_States' */
  uint8_T is_c3_Pegasus_MBD;           /* '<S6>/Vq_Refer_Saturation' */
  uint8_T is_active_c3_Pegasus_MBD;    /* '<S6>/Vq_Refer_Saturation' */
  uint8_T is_c6_Pegasus_MBD;           /* '<S6>/Vd_Refer_Saturation' */
  uint8_T is_active_c6_Pegasus_MBD;    /* '<S6>/Vd_Refer_Saturation' */
  uint8_T is_c5_Pegasus_MBD;           /* '<S6>/Iq_Refer_Saturation' */
  uint8_T is_active_c5_Pegasus_MBD;    /* '<S6>/Iq_Refer_Saturation' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T I_a;                        /* '<Root>/I_a' */
  real32_T I_b;                        /* '<Root>/I_b' */
  real32_T I_c;                        /* '<Root>/I_c' */
  real32_T MtrPos_rad;                 /* '<Root>/MtrPos_rad' */
  real32_T Pole_pairs;                 /* '<Root>/Pole_pairs' */
  real32_T Lq;                         /* '<Root>/Lq' */
  real32_T Ld;                         /* '<Root>/Ld' */
  real32_T Rs;                         /* '<Root>/Rs' */
  real32_T Lambda_m;                   /* '<Root>/Lambda_m' */
  real32_T Torque;                     /* '<Root>/Torque' */
  real32_T Iq_Torque_ratio;            /* '<Root>/Iq_Torque_ratio' */
  real32_T Pq;                         /* '<Root>/Gain_Pq' */
  real32_T Iq;                         /* '<Root>/Gain_Iq' */
  real32_T Dq;                         /* '<Root>/Gain_Dq' */
  real32_T Pd;                         /* '<Root>/Gain_Pd' */
  real32_T Id;                         /* '<Root>/Gain_Id' */
  real32_T Dd;                         /* '<Root>/Gain_Dd' */
  real32_T FilterCoefficient;          /* '<Root>/FilterCoefficient' */
  ThresholdsBus Thresholds;            /* '<Root>/Thresholds' */
  real32_T MotorControllerTemperature; /* '<Root>/MotorControllerTemperature' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  DutyCycleBus DutyCylces;             /* '<Root>/DutyCylces' */
  FOC_OutBus FOC_Out;                  /* '<Root>/FOC_Out' */
  MCTempState MCTempFlag;              /* '<Root>/MCTempFlag' */
  VoltageState VoltageFlag;            /* '<Root>/VoltageFlag' */
  CurrentState CurrentFlag;            /* '<Root>/CurrentFlag' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Pegasus_MBD_initialize(void);
extern void Pegasus_MBD_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S23>/Offset' : Unused code path elimination
 * Block '<S23>/Unary_Minus' : Unused code path elimination
 * Block '<S120>/Offset' : Unused code path elimination
 * Block '<S120>/Unary_Minus' : Unused code path elimination
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
 * hilite_system('Pegasus_MBD_Algo/Pegasus_MBD')    - opens subsystem Pegasus_MBD_Algo/Pegasus_MBD
 * hilite_system('Pegasus_MBD_Algo/Pegasus_MBD/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Pegasus_MBD_Algo'
 * '<S1>'   : 'Pegasus_MBD_Algo/Pegasus_MBD'
 * '<S2>'   : 'Pegasus_MBD_Algo/Pegasus_MBD/DataPipeline'
 * '<S3>'   : 'Pegasus_MBD_Algo/Pegasus_MBD/DutyCycleCalculation_Va'
 * '<S4>'   : 'Pegasus_MBD_Algo/Pegasus_MBD/DutyCycleCalculation_Vb'
 * '<S5>'   : 'Pegasus_MBD_Algo/Pegasus_MBD/DutyCycleCalculation_Vc'
 * '<S6>'   : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC'
 * '<S7>'   : 'Pegasus_MBD_Algo/Pegasus_MBD/Protections'
 * '<S8>'   : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Clarke Transform'
 * '<S9>'   : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Inverse Clarke Transform'
 * '<S10>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Inverse Park Transform'
 * '<S11>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Iq_Refer_Saturation'
 * '<S12>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Normalized_Va'
 * '<S13>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Normalized_Vb'
 * '<S14>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Normalized_Vc'
 * '<S15>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1'
 * '<S16>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2'
 * '<S17>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Park Transform'
 * '<S18>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Va_Saturation'
 * '<S19>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Vb_Saturation'
 * '<S20>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Vc_Saturation'
 * '<S21>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Vd_Refer_Saturation'
 * '<S22>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Vq_Refer_Saturation'
 * '<S23>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Inverse Park Transform/Switch_Axis'
 * '<S24>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Anti-windup'
 * '<S25>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/D Gain'
 * '<S26>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Filter'
 * '<S27>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Filter ICs'
 * '<S28>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/I Gain'
 * '<S29>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Ideal P Gain'
 * '<S30>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Ideal P Gain Fdbk'
 * '<S31>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Integrator'
 * '<S32>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Integrator ICs'
 * '<S33>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/N Copy'
 * '<S34>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/N Gain'
 * '<S35>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/P Copy'
 * '<S36>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Parallel P Gain'
 * '<S37>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Reset Signal'
 * '<S38>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Saturation'
 * '<S39>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Saturation Fdbk'
 * '<S40>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Sum'
 * '<S41>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Sum Fdbk'
 * '<S42>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tracking Mode'
 * '<S43>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tracking Mode Sum'
 * '<S44>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tsamp - Integral'
 * '<S45>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tsamp - Ngain'
 * '<S46>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/postSat Signal'
 * '<S47>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/preSat Signal'
 * '<S48>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Anti-windup/Passthrough'
 * '<S49>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/D Gain/External Parameters'
 * '<S50>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S51>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S52>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/I Gain/External Parameters'
 * '<S53>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Ideal P Gain/Passthrough'
 * '<S54>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S55>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Integrator/Discrete'
 * '<S56>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Integrator ICs/Internal IC'
 * '<S57>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/N Copy/Disabled'
 * '<S58>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/N Gain/External Parameters'
 * '<S59>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/P Copy/Disabled'
 * '<S60>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Parallel P Gain/External Parameters'
 * '<S61>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Reset Signal/Disabled'
 * '<S62>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Saturation/Passthrough'
 * '<S63>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Saturation Fdbk/Disabled'
 * '<S64>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Sum/Sum_PID'
 * '<S65>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Sum Fdbk/Disabled'
 * '<S66>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tracking Mode/Disabled'
 * '<S67>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S68>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S69>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S70>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/postSat Signal/Forward_Path'
 * '<S71>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/preSat Signal/Forward_Path'
 * '<S72>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Anti-windup'
 * '<S73>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/D Gain'
 * '<S74>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Filter'
 * '<S75>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Filter ICs'
 * '<S76>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/I Gain'
 * '<S77>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Ideal P Gain'
 * '<S78>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Ideal P Gain Fdbk'
 * '<S79>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Integrator'
 * '<S80>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Integrator ICs'
 * '<S81>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/N Copy'
 * '<S82>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/N Gain'
 * '<S83>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/P Copy'
 * '<S84>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Parallel P Gain'
 * '<S85>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Reset Signal'
 * '<S86>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Saturation'
 * '<S87>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Saturation Fdbk'
 * '<S88>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Sum'
 * '<S89>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Sum Fdbk'
 * '<S90>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tracking Mode'
 * '<S91>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tracking Mode Sum'
 * '<S92>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tsamp - Integral'
 * '<S93>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tsamp - Ngain'
 * '<S94>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/postSat Signal'
 * '<S95>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/preSat Signal'
 * '<S96>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Anti-windup/Passthrough'
 * '<S97>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/D Gain/External Parameters'
 * '<S98>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Filter/Disc. Forward Euler Filter'
 * '<S99>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S100>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/I Gain/External Parameters'
 * '<S101>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Ideal P Gain/Passthrough'
 * '<S102>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S103>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Integrator/Discrete'
 * '<S104>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Integrator ICs/Internal IC'
 * '<S105>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/N Copy/Disabled'
 * '<S106>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/N Gain/External Parameters'
 * '<S107>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/P Copy/Disabled'
 * '<S108>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Parallel P Gain/External Parameters'
 * '<S109>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Reset Signal/Disabled'
 * '<S110>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Saturation/Passthrough'
 * '<S111>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Saturation Fdbk/Disabled'
 * '<S112>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Sum/Sum_PID'
 * '<S113>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Sum Fdbk/Disabled'
 * '<S114>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tracking Mode/Disabled'
 * '<S115>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S116>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S117>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S118>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/postSat Signal/Forward_Path'
 * '<S119>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/preSat Signal/Forward_Path'
 * '<S120>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Park Transform/Switch_Axis'
 * '<S121>' : 'Pegasus_MBD_Algo/Pegasus_MBD/Protections/Protection_States'
 */
#endif                                 /* RTW_HEADER_Pegasus_MBD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
