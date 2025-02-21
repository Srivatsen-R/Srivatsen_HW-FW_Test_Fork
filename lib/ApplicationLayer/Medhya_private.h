/*
 * Medhya_private.h
 *
 * Code generation for model "Medhya".
 *
 * Model version              : 18.86
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Thu Feb 20 19:35:36 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Medhya_private_h_
#define Medhya_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Medhya_types.h"
#include "Medhya.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T look2_binlcpw(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);
extern real_T look2_binlcapw(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);

#endif                                 /* Medhya_private_h_ */
