/*
 * FOC.h
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

#ifndef FOC_h_
#define FOC_h_
#ifndef FOC_COMMON_INCLUDES_
#define FOC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* FOC_COMMON_INCLUDES_ */

#include "FOC_types.h"
#include "rtGetInf.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Add1;                         /* '<S19>/Add1' */
  real_T IProdOut;                     /* '<S112>/IProd Out' */
  real_T DeadZone;                     /* '<S107>/DeadZone' */
  real_T IProdOut_e;                   /* '<S58>/IProd Out' */
  real_T NProdOut;                     /* '<S118>/NProd Out' */
  real_T Saturation;                   /* '<S122>/Saturation' */
  real_T DeadZone_b;                   /* '<S53>/DeadZone' */
  real_T IProdOut_j;                   /* '<S166>/IProd Out' */
} B_FOC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S115>/Integrator' */
  real_T Filter_DSTATE;                /* '<S110>/Filter' */
  real_T Integrator_DSTATE_g;          /* '<S61>/Integrator' */
  real_T Filter_DSTATE_c;              /* '<S56>/Filter' */
  real_T Integrator_DSTATE_h;          /* '<S169>/Integrator' */
  real_T Filter_DSTATE_d;              /* '<S164>/Filter' */
} DW_FOC_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ActualSpeed;                  /* '<Root>/Actual Speed' */
  real_T RefSpeed;                     /* '<Root>/Ref Speed' */
  real_T angle;                        /* '<Root>/angle' */
  real_T PhaseCurrent[3];              /* '<Root>/Phase Current' */
  real_T PID_Vd[4];                    /* '<Root>/PID_Vd' */
  real_T PID_Id[4];                    /* '<Root>/PID_Id' */
  real_T PID_Vq[4];                    /* '<Root>/PID_Vq' */
} ExtU_FOC_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Va;                           /* '<Root>/Va' */
  real_T Vb;                           /* '<Root>/Vb' */
  real_T Vc;                           /* '<Root>/Vc' */
} ExtY_FOC_T;

/* Real-time Model Data Structure */
struct tag_RTM_FOC_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_FOC_T FOC_B;

/* Block states (default storage) */
extern DW_FOC_T FOC_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_FOC_T FOC_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_FOC_T FOC_Y;

/* Model entry point functions */
extern void FOC_initialize(void);
extern void FOC_step(void);
extern void FOC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FOC_T *const FOC_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Kalpha' : Eliminated nontunable gain of 1
 * Block '<S7>/Kbeta' : Eliminated nontunable gain of 1
 * Block '<S14>/Ka' : Eliminated nontunable gain of 1
 * Block '<S14>/Kb' : Eliminated nontunable gain of 1
 * Block '<S14>/Kc' : Eliminated nontunable gain of 1
 * Block '<S68>/Saturation' : Eliminated Saturate block
 * Block '<S10>/Offset' : Unused code path elimination
 * Block '<S10>/Unary_Minus' : Unused code path elimination
 * Block '<S16>/Offset' : Unused code path elimination
 * Block '<S16>/Unary_Minus' : Unused code path elimination
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
 * hilite_system('IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC')    - opens subsystem IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC
 * hilite_system('IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1'
 * '<S1>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC'
 * '<S2>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Clarke_Park'
 * '<S3>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Inverse_Clarke_Park'
 * '<S4>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID'
 * '<S5>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Clarke_Park/Clarke Transform'
 * '<S6>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Clarke_Park/Park Transform'
 * '<S7>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Clarke_Park/Clarke Transform/Two phase input'
 * '<S8>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Clarke_Park/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S9>'   : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Clarke_Park/Park Transform/Two inputs CRL'
 * '<S10>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Clarke_Park/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S11>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Inverse_Clarke_Park/Inverse Clarke Transform'
 * '<S12>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Inverse_Clarke_Park/Inverse Park Transform'
 * '<S13>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Inverse_Clarke_Park/PWM Reference Generator'
 * '<S14>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Inverse_Clarke_Park/Inverse Clarke Transform/Two phase input'
 * '<S15>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Inverse_Clarke_Park/Inverse Park Transform/Two inputs CRL'
 * '<S16>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Inverse_Clarke_Park/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S17>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Inverse_Clarke_Park/PWM Reference Generator/Modulation method'
 * '<S18>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Inverse_Clarke_Park/PWM Reference Generator/Voltage Input'
 * '<S19>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Inverse_Clarke_Park/PWM Reference Generator/Modulation method/SVPWM'
 * '<S20>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Inverse_Clarke_Park/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S21>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/Inverse_Clarke_Park/PWM Reference Generator/Voltage Input/Vabc'
 * '<S22>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq'
 * '<S23>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd'
 * '<S24>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq'
 * '<S25>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Anti-windup'
 * '<S26>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/D Gain'
 * '<S27>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/External Derivative'
 * '<S28>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Filter'
 * '<S29>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Filter ICs'
 * '<S30>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/I Gain'
 * '<S31>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Ideal P Gain'
 * '<S32>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Ideal P Gain Fdbk'
 * '<S33>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Integrator'
 * '<S34>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Integrator ICs'
 * '<S35>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/N Copy'
 * '<S36>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/N Gain'
 * '<S37>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/P Copy'
 * '<S38>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Parallel P Gain'
 * '<S39>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Reset Signal'
 * '<S40>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Saturation'
 * '<S41>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Saturation Fdbk'
 * '<S42>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Sum'
 * '<S43>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Sum Fdbk'
 * '<S44>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Tracking Mode'
 * '<S45>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Tracking Mode Sum'
 * '<S46>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Tsamp - Integral'
 * '<S47>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Tsamp - Ngain'
 * '<S48>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/postSat Signal'
 * '<S49>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/preInt Signal'
 * '<S50>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/preSat Signal'
 * '<S51>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Anti-windup/Disc. Clamping Parallel'
 * '<S52>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S53>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S54>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/D Gain/External Parameters'
 * '<S55>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/External Derivative/Error'
 * '<S56>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Filter/Disc. Forward Euler Filter'
 * '<S57>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Filter ICs/Internal IC - Filter'
 * '<S58>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/I Gain/External Parameters'
 * '<S59>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Ideal P Gain/Passthrough'
 * '<S60>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Ideal P Gain Fdbk/Disabled'
 * '<S61>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Integrator/Discrete'
 * '<S62>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Integrator ICs/Internal IC'
 * '<S63>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/N Copy/Disabled'
 * '<S64>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/N Gain/External Parameters'
 * '<S65>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/P Copy/Disabled'
 * '<S66>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Parallel P Gain/External Parameters'
 * '<S67>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Reset Signal/Disabled'
 * '<S68>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Saturation/Enabled'
 * '<S69>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Saturation Fdbk/Disabled'
 * '<S70>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Sum/Sum_PID'
 * '<S71>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Sum Fdbk/Disabled'
 * '<S72>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Tracking Mode/Disabled'
 * '<S73>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Tracking Mode Sum/Passthrough'
 * '<S74>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Tsamp - Integral/TsSignalSpecification'
 * '<S75>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/Tsamp - Ngain/Passthrough'
 * '<S76>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/postSat Signal/Forward_Path'
 * '<S77>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/preInt Signal/Internal PreInt'
 * '<S78>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Iq/preSat Signal/Forward_Path'
 * '<S79>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Anti-windup'
 * '<S80>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/D Gain'
 * '<S81>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/External Derivative'
 * '<S82>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Filter'
 * '<S83>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Filter ICs'
 * '<S84>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/I Gain'
 * '<S85>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Ideal P Gain'
 * '<S86>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Ideal P Gain Fdbk'
 * '<S87>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Integrator'
 * '<S88>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Integrator ICs'
 * '<S89>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/N Copy'
 * '<S90>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/N Gain'
 * '<S91>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/P Copy'
 * '<S92>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Parallel P Gain'
 * '<S93>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Reset Signal'
 * '<S94>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Saturation'
 * '<S95>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Saturation Fdbk'
 * '<S96>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Sum'
 * '<S97>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Sum Fdbk'
 * '<S98>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Tracking Mode'
 * '<S99>'  : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Tracking Mode Sum'
 * '<S100>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Tsamp - Integral'
 * '<S101>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Tsamp - Ngain'
 * '<S102>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/postSat Signal'
 * '<S103>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/preInt Signal'
 * '<S104>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/preSat Signal'
 * '<S105>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Anti-windup/Disc. Clamping Parallel'
 * '<S106>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S107>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S108>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/D Gain/External Parameters'
 * '<S109>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/External Derivative/Error'
 * '<S110>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Filter/Disc. Forward Euler Filter'
 * '<S111>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Filter ICs/Internal IC - Filter'
 * '<S112>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/I Gain/External Parameters'
 * '<S113>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Ideal P Gain/Passthrough'
 * '<S114>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Ideal P Gain Fdbk/Disabled'
 * '<S115>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Integrator/Discrete'
 * '<S116>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Integrator ICs/Internal IC'
 * '<S117>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/N Copy/Disabled'
 * '<S118>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/N Gain/External Parameters'
 * '<S119>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/P Copy/Disabled'
 * '<S120>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Parallel P Gain/External Parameters'
 * '<S121>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Reset Signal/Disabled'
 * '<S122>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Saturation/Enabled'
 * '<S123>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Saturation Fdbk/Disabled'
 * '<S124>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Sum/Sum_PID'
 * '<S125>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Sum Fdbk/Disabled'
 * '<S126>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Tracking Mode/Disabled'
 * '<S127>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Tracking Mode Sum/Passthrough'
 * '<S128>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Tsamp - Integral/TsSignalSpecification'
 * '<S129>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/Tsamp - Ngain/Passthrough'
 * '<S130>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/postSat Signal/Forward_Path'
 * '<S131>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/preInt Signal/Internal PreInt'
 * '<S132>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vd/preSat Signal/Forward_Path'
 * '<S133>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Anti-windup'
 * '<S134>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/D Gain'
 * '<S135>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/External Derivative'
 * '<S136>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Filter'
 * '<S137>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Filter ICs'
 * '<S138>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/I Gain'
 * '<S139>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Ideal P Gain'
 * '<S140>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Ideal P Gain Fdbk'
 * '<S141>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Integrator'
 * '<S142>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Integrator ICs'
 * '<S143>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/N Copy'
 * '<S144>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/N Gain'
 * '<S145>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/P Copy'
 * '<S146>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Parallel P Gain'
 * '<S147>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Reset Signal'
 * '<S148>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Saturation'
 * '<S149>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Saturation Fdbk'
 * '<S150>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Sum'
 * '<S151>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Sum Fdbk'
 * '<S152>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Tracking Mode'
 * '<S153>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Tracking Mode Sum'
 * '<S154>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Tsamp - Integral'
 * '<S155>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Tsamp - Ngain'
 * '<S156>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/postSat Signal'
 * '<S157>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/preInt Signal'
 * '<S158>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/preSat Signal'
 * '<S159>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Anti-windup/Disc. Clamping Parallel'
 * '<S160>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S161>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S162>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/D Gain/External Parameters'
 * '<S163>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/External Derivative/Error'
 * '<S164>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Filter/Disc. Forward Euler Filter'
 * '<S165>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Filter ICs/Internal IC - Filter'
 * '<S166>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/I Gain/External Parameters'
 * '<S167>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Ideal P Gain/Passthrough'
 * '<S168>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Ideal P Gain Fdbk/Disabled'
 * '<S169>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Integrator/Discrete'
 * '<S170>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Integrator ICs/Internal IC'
 * '<S171>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/N Copy/Disabled'
 * '<S172>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/N Gain/External Parameters'
 * '<S173>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/P Copy/Disabled'
 * '<S174>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Parallel P Gain/External Parameters'
 * '<S175>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Reset Signal/Disabled'
 * '<S176>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Saturation/Enabled'
 * '<S177>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Saturation Fdbk/Disabled'
 * '<S178>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Sum/Sum_PID'
 * '<S179>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Sum Fdbk/Disabled'
 * '<S180>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Tracking Mode/Disabled'
 * '<S181>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Tracking Mode Sum/Passthrough'
 * '<S182>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Tsamp - Integral/TsSignalSpecification'
 * '<S183>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/Tsamp - Ngain/Passthrough'
 * '<S184>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/postSat Signal/Forward_Path'
 * '<S185>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/preInt Signal/Internal PreInt'
 * '<S186>' : 'IPMSM_motor_discrete_try_SVM_test_PID_code_gen_1/FOC/PID/PI Vq/preSat Signal/Forward_Path'
 */
#endif                                 /* FOC_h_ */
