/*
 * File: Pegasus_MBD.h
 *
 * Code generated for Simulink model 'Pegasus_MBD'.
 *
 * Model version                  : 1.137
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon May 20 14:05:05 2024
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

#ifndef DEFINED_TYPEDEF_FOR_ThresholdsBus_
#define DEFINED_TYPEDEF_FOR_ThresholdsBus_

typedef struct {
  real_T MaxBusVoltage_V;
} ThresholdsBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Motor_Inputs_
#define DEFINED_TYPEDEF_FOR_Motor_Inputs_

typedef struct {
  real32_T I_a;
  real32_T I_b;
  real32_T I_c;
  real32_T MtrPos_rad;
} Motor_Inputs;

#endif

#ifndef DEFINED_TYPEDEF_FOR_DataPipeline_
#define DEFINED_TYPEDEF_FOR_DataPipeline_

typedef struct {
  Motor_Inputs Motor_Inputs;
  real32_T Pole_pairs;
  real32_T Lq;
  real32_T Ld;
  real32_T Rs;
  real32_T Lambda_m;
  real32_T Torque;
  real32_T Iq_Torque_ratio;
} DataPipeline;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S93>/Integrator' */
  real_T Filter_DSTATE;                /* '<S88>/Filter' */
  real_T Integrator_DSTATE_e;          /* '<S45>/Integrator' */
  real_T Filter_DSTATE_f;              /* '<S40>/Filter' */
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
  real_T Pq;                           /* '<Root>/Gain_Pq' */
  real_T Iq;                           /* '<Root>/Gain_Iq' */
  real_T Dq;                           /* '<Root>/Gain_Dq' */
  real_T Pd;                           /* '<Root>/Gain_Pd' */
  real_T Id;                           /* '<Root>/Gain_Id' */
  real_T Dd;                           /* '<Root>/Gain_Dd' */
  real_T FilterCoefficient;            /* '<Root>/FilterCoefficient' */
  ThresholdsBus Thresholds;            /* '<Root>/Thresholds' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Va;                           /* '<Root>/Va' */
  real_T Vb;                           /* '<Root>/Vb' */
  real_T Vc;                           /* '<Root>/Vc' */
  real_T Duty_a;                       /* '<Root>/Duty_a+' */
  real_T Duty_a_f;                     /* '<Root>/Duty_a-' */
  real_T Duty_b;                       /* '<Root>/Duty_b+' */
  real_T Duty_b_a;                     /* '<Root>/Duty_b-' */
  real_T Duty_c;                       /* '<Root>/Duty_c+' */
  real_T Duty_c_h;                     /* '<Root>/Duty_c-' */
  real32_T Iq_Calculated;              /* '<Root>/Iq_Calculated' */
  real32_T Iq_Refer;                   /* '<Root>/Iq_Refer' */
  real32_T Id_Refer;                   /* '<Root>/Id_Refer' */
  real_T Vd_Calculated;                /* '<Root>/Vd_Calculated' */
  real_T Vq_Calculated;                /* '<Root>/Vq_Calculated' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Pegasus_MBD_initialize(void);
extern void Pegasus_MBD_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S13>/Offset' : Unused code path elimination
 * Block '<S13>/Unary_Minus' : Unused code path elimination
 * Block '<S110>/Offset' : Unused code path elimination
 * Block '<S110>/Unary_Minus' : Unused code path elimination
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
 * '<S7>'   : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Clarke Transform'
 * '<S8>'   : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Inverse Clarke Transform'
 * '<S9>'   : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Inverse Park Transform'
 * '<S10>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1'
 * '<S11>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2'
 * '<S12>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Park Transform'
 * '<S13>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Inverse Park Transform/Switch_Axis'
 * '<S14>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Anti-windup'
 * '<S15>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/D Gain'
 * '<S16>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Filter'
 * '<S17>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Filter ICs'
 * '<S18>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/I Gain'
 * '<S19>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Ideal P Gain'
 * '<S20>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Ideal P Gain Fdbk'
 * '<S21>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Integrator'
 * '<S22>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Integrator ICs'
 * '<S23>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/N Copy'
 * '<S24>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/N Gain'
 * '<S25>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/P Copy'
 * '<S26>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Parallel P Gain'
 * '<S27>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Reset Signal'
 * '<S28>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Saturation'
 * '<S29>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Saturation Fdbk'
 * '<S30>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Sum'
 * '<S31>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Sum Fdbk'
 * '<S32>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tracking Mode'
 * '<S33>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tracking Mode Sum'
 * '<S34>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tsamp - Integral'
 * '<S35>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tsamp - Ngain'
 * '<S36>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/postSat Signal'
 * '<S37>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/preSat Signal'
 * '<S38>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Anti-windup/Passthrough'
 * '<S39>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/D Gain/External Parameters'
 * '<S40>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S41>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S42>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/I Gain/External Parameters'
 * '<S43>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Ideal P Gain/Passthrough'
 * '<S44>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S45>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Integrator/Discrete'
 * '<S46>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Integrator ICs/Internal IC'
 * '<S47>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/N Copy/Disabled'
 * '<S48>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/N Gain/External Parameters'
 * '<S49>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/P Copy/Disabled'
 * '<S50>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Parallel P Gain/External Parameters'
 * '<S51>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Reset Signal/Disabled'
 * '<S52>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Saturation/Passthrough'
 * '<S53>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Saturation Fdbk/Disabled'
 * '<S54>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Sum/Sum_PID'
 * '<S55>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Sum Fdbk/Disabled'
 * '<S56>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tracking Mode/Disabled'
 * '<S57>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S58>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S59>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S60>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/postSat Signal/Forward_Path'
 * '<S61>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller1/preSat Signal/Forward_Path'
 * '<S62>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Anti-windup'
 * '<S63>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/D Gain'
 * '<S64>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Filter'
 * '<S65>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Filter ICs'
 * '<S66>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/I Gain'
 * '<S67>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Ideal P Gain'
 * '<S68>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Ideal P Gain Fdbk'
 * '<S69>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Integrator'
 * '<S70>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Integrator ICs'
 * '<S71>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/N Copy'
 * '<S72>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/N Gain'
 * '<S73>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/P Copy'
 * '<S74>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Parallel P Gain'
 * '<S75>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Reset Signal'
 * '<S76>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Saturation'
 * '<S77>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Saturation Fdbk'
 * '<S78>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Sum'
 * '<S79>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Sum Fdbk'
 * '<S80>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tracking Mode'
 * '<S81>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tracking Mode Sum'
 * '<S82>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tsamp - Integral'
 * '<S83>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tsamp - Ngain'
 * '<S84>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/postSat Signal'
 * '<S85>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/preSat Signal'
 * '<S86>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Anti-windup/Passthrough'
 * '<S87>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/D Gain/External Parameters'
 * '<S88>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Filter/Disc. Forward Euler Filter'
 * '<S89>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Filter ICs/Internal IC - Filter'
 * '<S90>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/I Gain/External Parameters'
 * '<S91>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Ideal P Gain/Passthrough'
 * '<S92>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S93>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Integrator/Discrete'
 * '<S94>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Integrator ICs/Internal IC'
 * '<S95>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/N Copy/Disabled'
 * '<S96>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/N Gain/External Parameters'
 * '<S97>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/P Copy/Disabled'
 * '<S98>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Parallel P Gain/External Parameters'
 * '<S99>'  : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Reset Signal/Disabled'
 * '<S100>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Saturation/Passthrough'
 * '<S101>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Saturation Fdbk/Disabled'
 * '<S102>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Sum/Sum_PID'
 * '<S103>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Sum Fdbk/Disabled'
 * '<S104>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tracking Mode/Disabled'
 * '<S105>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S106>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tsamp - Integral/Passthrough'
 * '<S107>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S108>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/postSat Signal/Forward_Path'
 * '<S109>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/PID Controller2/preSat Signal/Forward_Path'
 * '<S110>' : 'Pegasus_MBD_Algo/Pegasus_MBD/FOC/Park Transform/Switch_Axis'
 */
#endif                                 /* RTW_HEADER_Pegasus_MBD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
