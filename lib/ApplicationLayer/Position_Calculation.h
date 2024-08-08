/*
 * File: Position_Calculation.h
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

#ifndef RTW_HEADER_Position_Calculation_h_
#define RTW_HEADER_Position_Calculation_h_
#ifndef Position_Calculation_COMMON_INCLUDES_
#define Position_Calculation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                               /* Position_Calculation_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_Angle RT_MODEL_Angle;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Switch;                       /* '<S1>/Switch' */
  real_T Position;                     /* '<S1>/Chart1' */
  real_T UnitDelay1_DSTATE;            /* '<S1>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S13>/Unit Delay' */
  real32_T UnitDelay_DSTATE_k;         /* '<S1>/Unit Delay' */
  uint32_T Delay_DSTATE[2];            /* '<S6>/Delay' */
  uint32_T CircBufIdx;                 /* '<S6>/Delay' */
  uint8_T is_active_c3_Position_Calculati;/* '<S1>/Chart1' */
  boolean_T RelationalOperator1;       /* '<S10>/Relational Operator1' */
  boolean_T RelationalOperator1_i;     /* '<S9>/Relational Operator1' */
  boolean_T UnitDelay_DSTATE_g;        /* '<S8>/Unit Delay' */
} DW_Angle;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T MultiportSwitch[2];     /* '<S8>/Multiport Switch' */
} ConstB_Angle;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Encoder_Cnt;                  /* '<Root>/Encoder_Cnt' */
  real_T Z_Cnt;                        /* '<Root>/Z_Cnt' */
  real_T Offset_rad;                   /* '<Root>/Offset_rad' */
} ExtU_Angle;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Mech_Angle_rad;               /* '<Root>/Mech_Angle_rad' */
  real_T Elec_Angle_rad;               /* '<Root>/Elec_Angle_rad' */
  real_T Speed_radsec;                 /* '<Root>/Speed_rad//sec' */
  real32_T Speed_rpm;                  /* '<Root>/Speed_rpm' */
  real_T EncoderReset;                 /* '<Root>/EncoderReset' */
} ExtY_Angle;

/* Real-time Model Data Structure */
struct tag_RTM_Angle {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW_Angle rtDW_Angle;

/* External inputs (root inport signals with default storage) */
extern ExtU_Angle rtU_Angle;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Angle rtY_Angle;
extern const ConstB_Angle rtConstB_Angle;          /* constant block i/o */

/* Model entry point functions */
extern void Position_Calculation_initialize();
extern void Position_Calculation_step(void);

/* Real-time Model object */
extern RT_MODEL_Angle *const rtM_Angle;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S15>/Constant' : Unused code path elimination
 * Block '<S15>/Constant1' : Unused code path elimination
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
 * hilite_system('Working_AngleCalc/Position_Calculation')    - opens subsystem Working_AngleCalc/Position_Calculation
 * hilite_system('Working_AngleCalc/Position_Calculation/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Working_AngleCalc'
 * '<S1>'   : 'Working_AngleCalc/Position_Calculation'
 * '<S2>'   : 'Working_AngleCalc/Position_Calculation/Chart1'
 * '<S3>'   : 'Working_AngleCalc/Position_Calculation/Edge Detector1'
 * '<S4>'   : 'Working_AngleCalc/Position_Calculation/IIR Filter1'
 * '<S5>'   : 'Working_AngleCalc/Position_Calculation/Mechanical to Electrical Position'
 * '<S6>'   : 'Working_AngleCalc/Position_Calculation/Speed Measurement'
 * '<S7>'   : 'Working_AngleCalc/Position_Calculation/powergui'
 * '<S8>'   : 'Working_AngleCalc/Position_Calculation/Edge Detector1/Model'
 * '<S9>'   : 'Working_AngleCalc/Position_Calculation/Edge Detector1/Model/NEGATIVE Edge'
 * '<S10>'  : 'Working_AngleCalc/Position_Calculation/Edge Detector1/Model/POSITIVE Edge'
 * '<S11>'  : 'Working_AngleCalc/Position_Calculation/IIR Filter1/IIR Filter'
 * '<S12>'  : 'Working_AngleCalc/Position_Calculation/IIR Filter1/IIR Filter/Low-pass'
 * '<S13>'  : 'Working_AngleCalc/Position_Calculation/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S14>'  : 'Working_AngleCalc/Position_Calculation/Mechanical to Electrical Position/MechToElec'
 * '<S15>'  : 'Working_AngleCalc/Position_Calculation/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S16>'  : 'Working_AngleCalc/Position_Calculation/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S17>'  : 'Working_AngleCalc/Position_Calculation/Mechanical to Electrical Position/MechToElec/floating-point/Mech To El'
 * '<S18>'  : 'Working_AngleCalc/Position_Calculation/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S19>'  : 'Working_AngleCalc/Position_Calculation/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S20>'  : 'Working_AngleCalc/Position_Calculation/Speed Measurement/DT_Handle'
 * '<S21>'  : 'Working_AngleCalc/Position_Calculation/Speed Measurement/DT_Handle/floating-point'
 */

/*-
 * Requirements for '<Root>': Position_Calculation

 */
#endif                                 /* RTW_HEADER_Position_Calculation_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
