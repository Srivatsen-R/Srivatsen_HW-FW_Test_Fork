
#ifndef VECTOR_CONTROL
#define VECTOR_CONTROL

#include <math.h>
#include "math_func.h"
#include "main.h"
#include "macros.h"
#include "enums.h"
#include <stdbool.h>

typedef struct foc_t {

             float speed_ref;
             float speed_limit;
             float speed_ref_output;
             float torque_current_ref;
             float torque_current_ref_prev;
             float torque_current_max;
             float flux_current_ref;
             float imr_ref;
             float imr_ref_min;
             float vd_ref;
             float vq_ref;
             float vq_ref_max;
             float vd_ref_max;
             float vq_ref_limit;
             float vd_ref_prev;
             float vq_ref_prev;
             int   vq_flag;
             float v_alpha;
             float v_beta;
             int   va_ref;
             int   vb_ref;
             int   vc_ref;
             int   vab_ref;
             int   vbc_ref;
             int   vca_ref;
             int   pwm_a;
             int   pwm_b;
             int   pwm_c;
             float rho; 
             float rotor_angle;
             float rotor_speed;
             float rotor_speed_filtered;
             float phase_U_current;
             float phase_V_current;
             float phase_W_current;  
             float alpha_current;
             float beta_current;
             float torque_current_sense;
             float flux_current_sense;
             float magnetising_current_sense;
             float speed_sense;
             float speed_rpm;
             float decay;
             float sin_rho;
             float cos_rho;
             float sync_speed;
             float slip_speed;
             float sync_speed_prev;
             float flux_current_sense_prev;
             float rotor_speed_prev;
             float rotor_speed_filtered_prev;
             float rho_prev;
             float magnetising_current_sense_prev;
             float speed_incr;
             float imr_incr;
             float flux_ref;
             float new_flux_ref;
             float flux_decrement;
             float flux_increment;

             char fw_flag;
             int  flag_cnt;
        
             int angular_position;
             int angular_position_prev;
             int angular_count;
             int angular_tic;
             int angular_speed;

             float phase_limit;
             float phase_decay;
             float regeneration_current_limit;
             float regen_current;
             float regen_speed;
             float torque_current_commanded;
             float speed_limit_prev;

             int reverse_flag_prev;
             int forward_flag_prev;
             float speed_ref_prev;

             float limMaxVq;
             float limMinVq;

             float limMaxVd;
             float limMinVd;

}foc_t;

#define __IO volatile

//Motor-Controller Specific Parameters
#define RATE_LIMIT 50.0

#define PPR                     4096.0//NIDEC        
//#define PPR                     2048.0//ULTRON    

#define ALPHA                   0.4

#define THROTTLE_CNTRL          1
#define RAMP_CNTRL              0
#define DEBUG_EN                1
#define DEBUG_OFF               0
#define DISABLE_ON_NEUTRAL      0

// #define POLEPAIRS               4.0// Nidec 14kg
#define POLEPAIRS               3.0// Nidec 22kg & ULTRON

#define TIM1_PSCLR              4
#define TIM1_PERIOD             2499// frequency = 200MHz/(2*(TIM1_PSCLR+1)*TIM1_PERIOD)
#define TIM1_DEADTIME           185
#define MAX_RPM                 5000.0

#define ANGLE_OFFSET_FW                               1.216494//R1
#define ANGLE_OFFSET_RW                               1.216494//R1

//General parameters

#define ROTOR_TIME_CONSTANT                 0.11         // ROTOR TIME CONSTANT L/R
#define T_F_ROTOR_SPEED                     0.03         // Constant to filter rotor speed
#define T_F_CURRENT_PHASE                   0.001062
#define SLIP_LIMIT                          20.0


#define F_SW                                10000.0//FCLK/(PSCR*ARR) //100MHz/(10*1000)         // ISR Sampling frequency
#define T_PRD                               2500.0         // PWM Period TIM1
#define T_S                                 1.0/F_SW       // Sampling Time
#define PU                                  32767.0        // PU unit calculation max. value
#define PI                                  3.14159265358979 // PI Value
#define PPR_TO_RAD_CONSTANT                 (2.0*PI)/PPR   // Encoder value to mechanical angle conversion
#define DERIVATIVE_CONSTANT                 (F_SW)/(628.318) // Constant to calculate speed
#define SPEED_FILTER_CONSTANT_1             ((2.0*T_F_ROTOR_SPEED-T_S)/(2.0*T_F_ROTOR_SPEED+T_S)) // Constant to filter speed
#define SPEED_FILTER_CONSTANT_2             (T_S/(2.0*T_F_ROTOR_SPEED+T_S)) // Constant to filter speed
#define CURRENT_FILTER_CONSTANT_1           ((2.0*T_F_CURRENT_PHASE-T_S)/(2.0*T_F_CURRENT_PHASE+T_S)) // Constant to filter current
#define CURRENT_FILTER_CONSTANT_2           (T_S/(2.0*T_F_CURRENT_PHASE+T_S)) // Constant to filter current
#define PWM_CONST_1                         0.5*T_PRD        // CONSTANT FOR PWM Modulation
#define PWM_CONST_2                         (0.5*T_PRD) // CONSTANT FOR PWM Modulation
#define DUTY_TO_RADIAN                      ((2*PI)/100.0)
#define SPEED_PU_TO_RPM         0.18311
#define RPM_TO_RAD_S            0.10472
#define MAX_PU_SPEED            32767.0


void   VECTOR_FOC_Control(void) ;
void   FOC_CLARK_PARK_TRANSFORM(void);
void   FOC_READ_MOTOR_CURRENT(void);
void   FOC_READ_MOTOR_POSITION(void);
void   FOC_TORQUE_PI_CONTROL(void);
void   FOC_ELECTRICAL_ANGLE_CALCULATION(void);
void   FOC_FLUX_PI_CONTROL(void);
void   FOC_INVERSE_CLARK_PARK_TRANSFORM(void);
void   FOC_SPACE_VECTOR_MODULATION(void);
void   FW_AND_MTPA_CONFIG(int);
void   POWER_MAPPING(int);
void   THROTTLE_PROFILE(int);
void   FOC_SPEED_TORQUE_PI_CONTROL();


#endif 
