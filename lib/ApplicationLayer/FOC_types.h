/*
 * FOC_types.h
 *
 * Code generation for model "FOC".
 *
 * Model version              : 18.115
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Fri Jan 24 14:55:07 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef FOC_types_h_
#define FOC_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_Flux_PID_MTPA_
#define DEFINED_TYPEDEF_FOR_Flux_PID_MTPA_

typedef struct {
  real32_T Kp_flux_PID_MTPA;
  real32_T Ki_flux_PID_MTPA;
  real32_T Kd_flux_PID_MTPA;
  real32_T Filter_flux_PID_MTPA;
  real32_T Up_Limit_flux_PID_MTPA;
  real32_T Low_Limit_flux_PID_MTPA;
} Flux_PID_MTPA;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Speed_PID_MTPA_
#define DEFINED_TYPEDEF_FOR_Speed_PID_MTPA_

typedef struct {
  real32_T Kp_speed_PID_MTPA;
  real32_T Ki_speed_PID_MTPA;
  real32_T Kd_speed_PID_MTPA;
  real32_T Filter_speed_PID_MTPA;
  real32_T Up_Limit_speed_PID_MTPA;
  real32_T Low_Limit_speed_PID_MTPA;
} Speed_PID_MTPA;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Torque_PID_MTPA_
#define DEFINED_TYPEDEF_FOR_Torque_PID_MTPA_

typedef struct {
  real32_T Kp_torque_PID_MTPA;
  real32_T Ki_torque_PID_MTPA;
  real32_T Kd_torque_PID_MTPA;
  real32_T Filter_torque_PID_MTPA;
  real32_T Up_Limit_torque_PID_MTPA;
  real32_T Low_Limit_torque_PID_MTPA;
} Torque_PID_MTPA;

#endif

#ifndef DEFINED_TYPEDEF_FOR_PID_MTPABus_
#define DEFINED_TYPEDEF_FOR_PID_MTPABus_

typedef struct {
  Flux_PID_MTPA Flux_PID_MTPA;
  Speed_PID_MTPA Speed_PID_MTPA;
  Torque_PID_MTPA Torque_PID_MTPA;
} PID_MTPABus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ThresholdsBus_
#define DEFINED_TYPEDEF_FOR_ThresholdsBus_

typedef struct {
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

#ifndef DEFINED_TYPEDEF_FOR_TempState_
#define DEFINED_TYPEDEF_FOR_TempState_

typedef enum {
  SafeTemperature = 0,                 /* Default value */
  OT_Warning,
  OT_Error
} TempState;

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

/* Forward declaration for rtModel */
typedef struct tag_RTM_FOC_T RT_MODEL_FOC_T;

#endif                                 /* FOC_types_h_ */
