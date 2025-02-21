/*
* Medhya.h
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

#ifndef Medhya_h_
#define Medhya_h_
#ifndef Medhya_COMMON_INCLUDES_
#define Medhya_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* Medhya_COMMON_INCLUDES_ */

#include "Medhya_types.h"
#include "rtGetNaN.h"
#include <stddef.h>
#include <string.h>
#include "main.h"     

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Initial;                      /* '<S18>/Initial' */
} B_Medhya_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S18>/Discrete-Time Integrator1' */
  real_T Delay_DSTATE;                 /* '<S32>/Delay' */
  real_T Delay_DSTATE_k;               /* '<S7>/Delay' */
  real_T Delay_DSTATE_b[3];            /* '<S14>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S40>/Discrete-Time Integrator' */
  real_T Delay1_DSTATE[2];             /* '<S14>/Delay1' */
  real_T Delay_DSTATE_h;               /* '<S8>/Delay' */
  real_T Delay_DSTATE_n;               /* '<S33>/Delay' */
  real_T Delay_DSTATE_o;               /* '<S6>/Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S27>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S27>/Unit Delay' */
  real_T UnitDelay2_DSTATE;            /* '<S27>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_m;          /* '<S26>/Unit Delay1' */
  real_T UnitDelay_DSTATE_b;           /* '<S26>/Unit Delay' */
  real_T UnitDelay2_DSTATE_m;          /* '<S26>/Unit Delay2' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S18>/Discrete-Time Integrator1' */
  boolean_T Initial_FirstOutputTime;   /* '<S18>/Initial' */
  boolean_T icLoad;                    /* '<S32>/Delay' */
  boolean_T icLoad_i;                  /* '<S7>/Delay' */
  boolean_T icLoad_iz;                 /* '<S8>/Delay' */
  boolean_T icLoad_f;                  /* '<S33>/Delay' */
  boolean_T icLoad_g;                  /* '<S6>/Delay' */
} DW_Medhya_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0.00E+00	2.96E-04	2.95E-04	2.89E-04	2.82E-04	2.72E-04	2.60E-04	2.46E-04	2.32E-04	2.18E-04	2.04E-04	1.92E-04	1.81E-04	1.71E-04	1.62E-04	1.53E-04	1.46E-04	1.39E-04	1.33E-04	1.27E-04	1.22E-04
     0.00E+00	3.00E-04	2.98E-04	2.93E-04	2.86E-04	2.76E-04	2.63E-04	2.49E-04	2.34E-04	2.19E-04	2.06E-04	1.93E-04	1.82E-04	1.71E-04	1.62E-04	1.54E-04	1.46E-04	1.39E-04	1.33E-04	1.27E-04	1.22E-04
     0.00E+00	3.03E-04	3.02E-04	2.97E-04	2.89E-04	2.79E-04	2.66E-04	2.51E-04	2.36E-04	2.21E-04	2.07E-04	1.94E-04	1.83E-04	1.72E-04	1.63E-04	1.54E-04	1.46E-04	1.39E-04	1.33E-04	1.27E-04	1.22E-04
     0.00E+00	3.06E-04	3.04E-04	3.01E-04	2.93E-04	2.83E-04	2.69E-04	2.53E-04	2.37E-04	2.22E-04	2.08E-04	1.95E-04	1.83E-04	1.73E-04	1.63E-04	1.54E-04	1.47E-04	1.39E-04	1.33E-04	1.27E-04	1.22E-04
     0.00E+00	3.09E-04	3.07E-04	3.04E-04	2.97E-04	2.87E-04	2.72E-04	2.56E-04	2.39E-04	2.23E-04	2.09E-04	1.96E-04	1.84E-04	1.73E-04	1.63E-04	1.55E-04	1.47E-04	1.39E-04	1.33E-04	1.27E-04	1.22E-04
     0.00E+00	3.11E-04	3.10E-04	3.07E-04	3.01E-04	2.90E-04	2.75E-04	2.58E-04	2.41E-04	2.25E-04	2.10E-04	1.96E-04	1.84E-04	1.73E-04	1.64E-04	1.55E-04	1.47E-04	1.40E-04	1.33E-04	1.27E-04	1.22E-04
     0.00E+00	3.13E-04	3.12E-04	3.10E-04	3.05E-04	2.94E-04	2.78E-04	2.60E-04	2.42E-04	2.26E-04	2.11E-04	1.97E-04	1.85E-04	1.74E-04	1.64E-04	1.55E-04	1.47E-04	1.40E-04	1.33E-04	1.27E-04	1.22E-04
     0.00E+00	3.15E-04	3.15E-04	3.13E-04	3.09E-04	2.97E-04	2.80E-04	2.62E-04	2.44E-04	2.27E-04	2.11E-04	1.97E-04	1.85E-04	1.74E-04	1.64E-04	1.55E-04	1.47E-04	1.40E-04	1.33E-04	1.27E-04	1.22E-04
     0.00E+00	3.17E-04	3.17E-04	3.16E-04	3.12E-04	3.00E-04	2.82E-04	2.64E-04	2.45E-04	2.28E-04	2.12E-04	1.98E-04	1.85E-04	1.74E-04	1.64E-04	1.55E-04	1.47E-04	1.39E-04	1.33E-04	1.27E-04	1.22E-04
     0.00E+00	3.19E-04	3.19E-04	3.19E-04	3.15E-04	3.03E-04	2.85E-04	2.65E-04	2.46E-04	2.29E-04	2.12E-04	1.98E-04	1.85E-04	1.74E-04	1.64E-04	1.55E-04	1.47E-04	1.39E-04	1.33E-04	1.27E-04	1.21E-04
     0.00E+00	3.22E-04	3.22E-04	3.22E-04	3.19E-04	3.06E-04	2.86E-04	2.66E-04	2.47E-04	2.29E-04	2.13E-04	1.98E-04	1.85E-04	1.74E-04	1.64E-04	1.55E-04	1.46E-04	1.39E-04	1.33E-04	1.27E-04	1.21E-04
     0.00E+00	3.24E-04	3.25E-04	3.26E-04	3.22E-04	3.08E-04	2.88E-04	2.68E-04	2.48E-04	2.29E-04	2.13E-04	1.98E-04	1.85E-04	1.74E-04	1.63E-04	1.54E-04	1.46E-04	1.39E-04	1.32E-04	1.26E-04	1.21E-04
     0.00E+00	3.27E-04	3.28E-04	3.29E-04	3.26E-04	3.10E-04	2.90E-04	2.68E-04	2.48E-04	2.29E-04	2.12E-04	1.98E-04	1.85E-04	1.73E-04	1.63E-04	1.54E-04	1.46E-04	1.38E-04	1.32E-04	1.26E-04	1.21E-04
     0.00E+00	3.30E-04	3.31E-04	3.33E-04	3.29E-04	3.12E-04	2.91E-04	2.69E-04	2.48E-04	2.29E-04	2.12E-04	1.97E-04	1.84E-04	1.72E-04	1.62E-04	1.53E-04	1.45E-04	1.38E-04	1.31E-04	1.26E-04	1.20E-04
     0.00E+00	3.33E-04	3.36E-04	3.38E-04	3.32E-04	3.14E-04	2.92E-04	2.69E-04	2.48E-04	2.29E-04	2.12E-04	1.96E-04	1.83E-04	1.72E-04	1.62E-04	1.53E-04	1.45E-04	1.37E-04	1.31E-04	1.25E-04	1.20E-04
     0.00E+00	3.38E-04	3.41E-04	3.43E-04	3.36E-04	3.16E-04	2.92E-04	2.69E-04	2.48E-04	2.28E-04	2.11E-04	1.96E-04	1.82E-04	1.71E-04	1.61E-04	1.52E-04	1.44E-04	1.37E-04	1.30E-04	1.25E-04	1.20E-04
     0.00E+00	3.44E-04	3.47E-04	3.49E-04	3.39E-04	3.17E-04	2.92E-04	2.68E-04	2.47E-04	2.27E-04	2.10E-04	1.94E-04	1.81E-04	1.70E-04	1.60E-04	1.51E-04	1.43E-04	1.36E-04	1.30E-04	1.24E-04	1.19E-04
     0.00E+00	3.52E-04	3.55E-04	3.55E-04	3.41E-04	3.18E-04	2.92E-04	2.68E-04	2.46E-04	2.26E-04	2.08E-04	1.93E-04	1.80E-04	1.69E-04	1.59E-04	1.50E-04	1.42E-04	1.35E-04	1.29E-04	1.24E-04	1.18E-04
     0.00E+00	3.64E-04	3.64E-04	3.62E-04	3.44E-04	3.19E-04	2.91E-04	2.66E-04	2.44E-04	2.24E-04	2.07E-04	1.92E-04	1.79E-04	1.67E-04	1.58E-04	1.49E-04	1.41E-04	1.35E-04	1.28E-04	1.23E-04	1.18E-04
     0.00E+00	3.75E-04	3.75E-04	3.68E-04	3.46E-04	3.18E-04	2.90E-04	2.64E-04	2.42E-04	2.22E-04	2.05E-04	1.90E-04	1.77E-04	1.66E-04	1.56E-04	1.48E-04	1.40E-04	1.34E-04	1.28E-04	1.22E-04	1.17E-04
     0.00E+00	3.87E-04	3.87E-04	3.75E-04	3.48E-04	3.17E-04	2.87E-04	2.61E-04	2.39E-04	2.19E-04	2.02E-04	1.88E-04	1.75E-04	1.64E-04	1.55E-04	1.46E-04	1.39E-04	1.32E-04	1.26E-04	1.21E-04	1.16E-04
     ]
   * Referenced by: '<S4>/2-D Lookup Table Lq'
   */
  real_T uDLookupTableLq_tableData[441];

  /* Pooled Parameter (Expression: [-500
     -475
     -450
     -425
     -400
     -375
     -350
     -325
     -300
     -275
     -250
     -225
     -200
     -175
     -150
     -125
     -100
     -75
     -50
     -25
     0
     ])
   * Referenced by:
   *   '<S4>/2-D Lookup Table Ld'
   *   '<S4>/2-D Lookup Table Lq'
   *   '<S4>/2-D Lookup Table Psim'
   */
  real_T pooled9[21];

  /* Pooled Parameter (Expression: [0	25	50	75	100	125	150	175	200	225	250	275	300	325	350	375	400	425	450	475	500
     ])
   * Referenced by:
   *   '<S4>/2-D Lookup Table Ld'
   *   '<S4>/2-D Lookup Table Lq'
   *   '<S4>/2-D Lookup Table Psim'
   */
  real_T pooled10[21];

  /* Expression: [7.04E-05	7.07E-05	7.06E-05	6.93E-05	6.89E-05	6.80E-05	6.71E-05	6.54E-05	6.50E-05	6.46E-05	6.34E-05	6.20E-05	6.10E-05	5.93E-05	5.78E-05	5.68E-05	5.61E-05	5.52E-05	5.48E-05	5.47E-05	5.46E-05
     7.11E-05	7.10E-05	7.11E-05	6.98E-05	6.91E-05	6.86E-05	6.73E-05	6.61E-05	6.57E-05	6.46E-05	6.35E-05	6.27E-05	6.05E-05	5.89E-05	5.72E-05	5.67E-05	5.62E-05	5.56E-05	5.54E-05	5.50E-05	5.46E-05
     7.14E-05	7.13E-05	7.12E-05	7.04E-05	6.97E-05	6.91E-05	6.80E-05	6.65E-05	6.61E-05	6.48E-05	6.36E-05	6.30E-05	6.15E-05	6.01E-05	5.85E-05	5.74E-05	5.65E-05	5.60E-05	5.55E-05	5.50E-05	5.44E-05
     7.18E-05	7.16E-05	7.15E-05	7.09E-05	7.05E-05	6.99E-05	6.85E-05	6.71E-05	6.65E-05	6.49E-05	6.37E-05	6.30E-05	6.17E-05	6.05E-05	6.00E-05	5.93E-05	5.86E-05	5.74E-05	5.56E-05	5.49E-05	5.41E-05
     7.18E-05	7.18E-05	7.18E-05	7.14E-05	7.08E-05	7.06E-05	6.83E-05	6.79E-05	6.71E-05	6.53E-05	6.42E-05	6.35E-05	6.26E-05	6.11E-05	6.02E-05	5.94E-05	5.88E-05	5.80E-05	5.69E-05	5.63E-05	5.46E-05
     7.17E-05	7.21E-05	7.21E-05	7.15E-05	7.12E-05	7.13E-05	6.94E-05	6.88E-05	6.75E-05	6.59E-05	6.51E-05	6.42E-05	6.32E-05	6.17E-05	6.07E-05	5.95E-05	5.86E-05	5.76E-05	5.70E-05	5.63E-05	5.53E-05
     7.20E-05	7.23E-05	7.23E-05	7.17E-05	7.19E-05	7.17E-05	7.02E-05	6.94E-05	6.81E-05	6.69E-05	6.61E-05	6.50E-05	6.35E-05	6.24E-05	6.09E-05	5.97E-05	5.88E-05	5.78E-05	5.70E-05	5.58E-05	5.46E-05
     7.22E-05	7.26E-05	7.24E-05	7.26E-05	7.25E-05	7.18E-05	7.08E-05	7.04E-05	6.89E-05	6.74E-05	6.66E-05	6.56E-05	6.41E-05	6.30E-05	6.13E-05	6.01E-05	5.90E-05	5.77E-05	5.66E-05	5.52E-05	5.41E-05
     7.25E-05	7.26E-05	7.28E-05	7.29E-05	7.29E-05	7.26E-05	7.18E-05	7.08E-05	6.92E-05	6.78E-05	6.68E-05	6.57E-05	6.44E-05	6.34E-05	6.25E-05	6.04E-05	5.86E-05	5.75E-05	5.63E-05	5.52E-05	5.41E-05
     7.26E-05	7.28E-05	7.29E-05	7.36E-05	7.36E-05	7.35E-05	7.27E-05	7.13E-05	6.95E-05	6.78E-05	6.68E-05	6.52E-05	6.43E-05	6.33E-05	6.23E-05	6.08E-05	5.92E-05	5.73E-05	5.62E-05	5.49E-05	5.40E-05
     7.27E-05	7.28E-05	7.32E-05	7.41E-05	7.45E-05	7.44E-05	7.33E-05	7.21E-05	6.94E-05	6.82E-05	6.71E-05	6.52E-05	6.43E-05	6.34E-05	6.18E-05	6.02E-05	5.90E-05	5.74E-05	5.62E-05	5.46E-05	5.35E-05
     7.27E-05	7.30E-05	7.37E-05	7.47E-05	7.56E-05	7.47E-05	7.42E-05	7.21E-05	6.97E-05	6.84E-05	6.71E-05	6.56E-05	6.41E-05	6.25E-05	6.11E-05	5.99E-05	5.84E-05	5.70E-05	5.51E-05	5.39E-05	5.31E-05
     7.29E-05	7.33E-05	7.42E-05	7.56E-05	7.70E-05	7.56E-05	7.42E-05	7.23E-05	6.97E-05	6.84E-05	6.68E-05	6.54E-05	6.39E-05	6.18E-05	6.05E-05	5.92E-05	5.78E-05	5.63E-05	5.50E-05	5.38E-05	5.19E-05
     7.31E-05	7.35E-05	7.48E-05	7.72E-05	7.85E-05	7.63E-05	7.45E-05	7.24E-05	7.08E-05	6.86E-05	6.66E-05	6.45E-05	6.30E-05	6.15E-05	5.97E-05	5.80E-05	5.68E-05	5.58E-05	5.48E-05	5.40E-05	5.30E-05
     7.35E-05	7.42E-05	7.61E-05	7.93E-05	7.94E-05	7.72E-05	7.53E-05	7.32E-05	7.10E-05	6.84E-05	6.57E-05	6.47E-05	6.23E-05	6.08E-05	5.90E-05	5.74E-05	5.67E-05	5.55E-05	5.47E-05	5.37E-05	5.24E-05
     7.39E-05	7.52E-05	7.82E-05	8.12E-05	8.02E-05	7.80E-05	7.65E-05	7.29E-05	7.08E-05	6.88E-05	6.47E-05	6.29E-05	6.14E-05	5.96E-05	5.82E-05	5.72E-05	5.64E-05	5.54E-05	5.45E-05	5.24E-05	5.12E-05
     7.52E-05	7.73E-05	8.01E-05	8.27E-05	8.10E-05	7.97E-05	7.68E-05	7.29E-05	7.01E-05	6.69E-05	6.44E-05	6.08E-05	5.92E-05	5.76E-05	5.67E-05	5.55E-05	5.46E-05	5.30E-05	5.23E-05	5.14E-05	4.97E-05
     7.76E-05	7.93E-05	8.21E-05	8.38E-05	8.23E-05	7.98E-05	7.62E-05	7.25E-05	6.90E-05	6.56E-05	6.27E-05	6.10E-05	5.68E-05	5.60E-05	5.52E-05	5.46E-05	5.30E-05	5.17E-05	5.07E-05	5.03E-05	4.94E-05
     8.22E-05	8.13E-05	8.41E-05	8.54E-05	8.30E-05	7.99E-05	7.60E-05	7.20E-05	6.76E-05	6.46E-05	6.21E-05	6.01E-05	5.89E-05	5.46E-05	5.24E-05	5.27E-05	5.17E-05	5.10E-05	5.05E-05	4.99E-05	4.90E-05
     8.53E-05	8.61E-05	8.66E-05	8.65E-05	8.31E-05	7.80E-05	7.40E-05	7.06E-05	6.71E-05	6.31E-05	6.20E-05	5.88E-05	5.77E-05	5.57E-05	5.21E-05	5.12E-05	4.94E-05	4.92E-05	4.84E-05	4.78E-05	4.76E-05
     0.00E+00	9.03E-05	8.95E-05	8.63E-05	8.17E-05	7.52E-05	7.15E-05	6.86E-05	6.57E-05	6.38E-05	6.16E-05	5.85E-05	5.49E-05	5.31E-05	5.21E-05	5.13E-05	4.83E-05	4.73E-05	4.66E-05	4.57E-05	4.52E-05
     ]
   * Referenced by: '<S4>/2-D Lookup Table Ld'
   */
  real_T uDLookupTableLd_tableData[441];

  /* Expression: [0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316	0.0316
     ]
   * Referenced by: '<S4>/2-D Lookup Table Psim'
   */
  real_T uDLookupTablePsim_tableData[441];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S4>/2-D Lookup Table Ld'
   *   '<S4>/2-D Lookup Table Lq'
   *   '<S4>/2-D Lookup Table Psim'
   */
  uint32_T pooled11[2];
} ConstP_Medhya_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T PwmEnable;                    /* '<Root>/PwmEnable' */
  real_T ManualSpeedRef;               /* '<Root>/ManualSpeedRef' */
  real_T IdRef;                        /* '<Root>/IdRef' */
  real_T IqRef;                        /* '<Root>/IqRef' */
  real_T SpeedRef;                     /* '<Root>/SpeedRef' */
  real_T ManualPositionOffset;         /* '<Root>/ManualPositionOffset' */
  real_T EnableManualPosition;         /* '<Root>/EnableManualPosition' */
  real_T VqRefManual;                  /* '<Root>/VqRefManual' */
  real_T VdRefManual;                  /* '<Root>/VdRefManual' */
  real_T EnableVdVqControl;            /* '<Root>/EnableVdVqControl' */
  real_T VdVqManualControlRampRate;    /* '<Root>/VdVqManualControlRampRate' */
  real_T KpD;                          /* '<Root>/Inport1' */
  real_T KiD;                          /* '<Root>/Inport2' */
  real_T KpQ;                          /* '<Root>/Inport3' */
  real_T KiQ;                          /* '<Root>/Inport4' */
  real_T Speed_Anlge_feedback[2];      /* '<Root>/Inport5' */
  real_T I_abc[3];                     /* '<Root>/Inport6' */
} ExtU_Medhya_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T G[6];                         /* '<Root>/G' */
  real_T ManualPos;                    /* '<Root>/ManualPos' */
  real_T ThetaSensed;                  /* '<Root>/ThetaSensed' */
  real_T IdqFeedback[3];               /* '<Root>/IdqFeedback' */
  real_T VdControl;                    /* '<Root>/VdControl' */
  real_T VqControl;                    /* '<Root>/VqControl' */
  real_T ModWave[3];                   /* '<Root>/ModWave' */
  real_T IdRef_out;                    /* '<Root>/IdRef_out' */
  real_T IqRef_out;                    /* '<Root>/IqRef_out' */
  real_T TorqueCalc;                   /* '<Root>/TorqueCalc' */
  real_T SpeedRef_out;                 /* '<Root>/SpeedRef_out' */
  real_T Va;                           /* '<Root>/Va' */
  real_T Vb;                           /* '<Root>/Vb' */
  real_T Vc;                           /* '<Root>/Vc' */
} ExtY_Medhya_T;

/* Real-time Model Data Structure */
struct tag_RTM_Medhya_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_Medhya_T Medhya_B;

/* Block states (default storage) */
extern DW_Medhya_T Medhya_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Medhya_T Medhya_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Medhya_T Medhya_Y;

/* Constant parameters (default storage) */
extern const ConstP_Medhya_T Medhya_ConstP;

/* Model entry point functions */
extern void Medhya_initialize(void);
extern void Medhya_step(void);
extern void Medhya_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Medhya_T *const Medhya_M;

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
 * hilite_system('Motor_Control_V2_2_2/Medhya')    - opens subsystem Motor_Control_V2_2_2/Medhya
 * hilite_system('Motor_Control_V2_2_2/Medhya/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Motor_Control_V2_2_2'
 * '<S1>'   : 'Motor_Control_V2_2_2/Medhya'
 * '<S2>'   : 'Motor_Control_V2_2_2/Medhya/Inputs'
 * '<S3>'   : 'Motor_Control_V2_2_2/Medhya/Motor Control'
 * '<S4>'   : 'Motor_Control_V2_2_2/Medhya/Motor Parameter'
 * '<S5>'   : 'Motor_Control_V2_2_2/Medhya/Parameter Estimator'
 * '<S6>'   : 'Motor_Control_V2_2_2/Medhya/Inputs/Rate Limiter Dynamic'
 * '<S7>'   : 'Motor_Control_V2_2_2/Medhya/Inputs/Rate Limiter Dynamic1'
 * '<S8>'   : 'Motor_Control_V2_2_2/Medhya/Inputs/Rate Limiter Dynamic2'
 * '<S9>'   : 'Motor_Control_V2_2_2/Medhya/Inputs/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S10>'  : 'Motor_Control_V2_2_2/Medhya/Inputs/Rate Limiter Dynamic1/Saturation Dynamic'
 * '<S11>'  : 'Motor_Control_V2_2_2/Medhya/Inputs/Rate Limiter Dynamic2/Saturation Dynamic'
 * '<S12>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/PWM'
 * '<S13>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem'
 * '<S14>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem2'
 * '<S15>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/PWM/Inverse Park Transform'
 * '<S16>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/PWM/PWM Generator (Three-phase, Two-level)'
 * '<S17>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/PWM/PWM Reference Generator'
 * '<S18>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/PWM/PWM Generator (Three-phase, Two-level)/Gate Signal Generator'
 * '<S19>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/PWM/PWM Generator (Three-phase, Two-level)/Switching Time Calculation'
 * '<S20>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/PWM/PWM Reference Generator/Modulation method'
 * '<S21>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/PWM/PWM Reference Generator/Voltage Input'
 * '<S22>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/PWM/PWM Reference Generator/Modulation method/SVPWM'
 * '<S23>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/PWM/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S24>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/PWM/PWM Reference Generator/Voltage Input/Vabc'
 * '<S25>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/Feedforward pre-control'
 * '<S26>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/PI D-axis reg'
 * '<S27>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/PI D-axis reg1'
 * '<S28>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/Subsystem'
 * '<S29>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/Subsystem1'
 * '<S30>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/PI D-axis reg/Saturation Dynamic'
 * '<S31>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/PI D-axis reg1/Saturation Dynamic'
 * '<S32>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/Subsystem/Rate Limiter Dynamic'
 * '<S33>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/Subsystem/Rate Limiter Dynamic1'
 * '<S34>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/Subsystem/Saturation v1'
 * '<S35>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/Subsystem/Saturation v2'
 * '<S36>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/Subsystem/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S37>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem/Subsystem/Rate Limiter Dynamic1/Saturation Dynamic'
 * '<S38>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem2/Input interface'
 * '<S39>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem2/Park Transform'
 * '<S40>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem2/Subsystem'
 * '<S41>'  : 'Motor_Control_V2_2_2/Medhya/Motor Control/Subsystem2/Input interface/Data Type Conversion Inherited'
 */
#endif                                 /* Medhya_h_ */
