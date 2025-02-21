/*
 * File: Open_loop6.h
 *
 * Code generated for Simulink model 'Open_loop6'.
 *
 * Model version                  : 1.67
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Feb 20 18:50:11 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef Open_loop6_h_
#define Open_loop6_h_
#ifndef Open_loop6_COMMON_INCLUDES_
#define Open_loop6_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#include "main.h"
#endif                                 /* Open_loop6_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef struct_tag_eiAwdgC1qR18Ichlg0q0q
#define struct_tag_eiAwdgC1qR18Ichlg0q0q

struct tag_eiAwdgC1qR18Ichlg0q0q
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_eiAwdgC1qR18Ichlg0q0q */

#ifndef typedef_fixed_system_ModByConstant
#define typedef_fixed_system_ModByConstant

typedef struct tag_eiAwdgC1qR18Ichlg0q0q fixed_system_ModByConstant;

#endif                                 /* typedef_fixed_system_ModByConstant */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  real_T DelayOneStep_DSTATE;          /* '<S6>/Delay One Step' */
  real_T sum_samples;                  /* '<S5>/MATLAB Function4' */
  real_T count_samples;                /* '<S5>/MATLAB Function4' */
  real_T sum_offset;                   /* '<S5>/MATLAB Function4' */
  real_T count_offset_samples;         /* '<S5>/MATLAB Function4' */
  uint8_T is_active_c12_Open_loop6;    /* '<S1>/Chart' */
  uint8_T is_c12_Open_loop6;           /* '<S1>/Chart' */
  boolean_T RelationalOperator1;       /* '<S21>/Relational Operator1' */
  boolean_T RelationalOperator1_h;     /* '<S20>/Relational Operator1' */
  boolean_T UnitDelay_DSTATE;          /* '<S19>/Unit Delay' */
} DW;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S19>/Multiport Switch' */
} ConstB;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T VFratio;                      /* '<Root>/V//F ratio' */
  real_T Ref_Speed_rpm;                /* '<Root>/Ref_Speed_rpm' */
  real_T V_up_limit;                   /* '<Root>/V_up_limit' */
  real_T V_low_limit;                  /* '<Root>/V_low_limit' */
  real_T Encoder_count;                /* '<Root>/Encoder_count' */
  real_T FwdRev;                       /* '<Root>/Fwd//Rev' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T V_abc[3];                     /* '<Root>/V_abc' */
  real_T ref_angle_6pi;                /* '<Root>/ref_angle_6*pi' */
  real_T Vdc;                          /* '<Root>/Vdc' */
  real_T Vdc_sat;                      /* '<Root>/Vdc_sat' */
  real_T ref_angle_2pi;                /* '<Root>/ref_angle_2*pi' */
  real_T ZCD_count;                    /* '<Root>/ZCD_count' */
  real_T Offset_deg;                   /* '<Root>/Offset_deg' */
  real_T Offset_rad;                   /* '<Root>/Offset_rad' */
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
extern const ConstB rtConstB;          /* constant block i/o */

/* Model entry point functions */
extern void Open_loop6_initialize(void);
extern void Open_loop6_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * hilite_system('openloop_working/Open_loop6')    - opens subsystem openloop_working/Open_loop6
 * hilite_system('openloop_working/Open_loop6/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'openloop_working'
 * '<S1>'   : 'openloop_working/Open_loop6'
 * '<S2>'   : 'openloop_working/Open_loop6/Chart'
 * '<S3>'   : 'openloop_working/Open_loop6/Subsystem'
 * '<S4>'   : 'openloop_working/Open_loop6/Subsystem1'
 * '<S5>'   : 'openloop_working/Open_loop6/Subsystem2'
 * '<S6>'   : 'openloop_working/Open_loop6/Zero_Crossing_Detection'
 * '<S7>'   : 'openloop_working/Open_loop6/Subsystem/Saturation Dynamic'
 * '<S8>'   : 'openloop_working/Open_loop6/Subsystem1/If Action Subsystem'
 * '<S9>'   : 'openloop_working/Open_loop6/Subsystem1/If Action Subsystem1'
 * '<S10>'  : 'openloop_working/Open_loop6/Subsystem1/If Action Subsystem2'
 * '<S11>'  : 'openloop_working/Open_loop6/Subsystem2/Degrees to Radians'
 * '<S12>'  : 'openloop_working/Open_loop6/Subsystem2/MATLAB Function4'
 * '<S13>'  : 'openloop_working/Open_loop6/Subsystem2/Radians to Degrees3'
 * '<S14>'  : 'openloop_working/Open_loop6/Subsystem2/Radians to Degrees4'
 * '<S15>'  : 'openloop_working/Open_loop6/Subsystem2/Subsystem4'
 * '<S16>'  : 'openloop_working/Open_loop6/Subsystem2/Subsystem4/If Action Subsystem'
 * '<S17>'  : 'openloop_working/Open_loop6/Subsystem2/Subsystem4/If Action Subsystem1'
 * '<S18>'  : 'openloop_working/Open_loop6/Zero_Crossing_Detection/Edge Detector'
 * '<S19>'  : 'openloop_working/Open_loop6/Zero_Crossing_Detection/Edge Detector/Model'
 * '<S20>'  : 'openloop_working/Open_loop6/Zero_Crossing_Detection/Edge Detector/Model/NEGATIVE Edge'
 * '<S21>'  : 'openloop_working/Open_loop6/Zero_Crossing_Detection/Edge Detector/Model/POSITIVE Edge'
 */
#endif                                 /* Open_loop6_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
