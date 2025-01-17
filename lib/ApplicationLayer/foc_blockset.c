/*
Pegasus - Motor Controller Unit software for HL,HLP,Storm,Vortex and future projects.

Contributors: Pujit Gandhi,Pratik Rout,Olay,Saksham

This file contains functions associated with Vector FOC Control for motor control applications.

*/

#include <math.h>
#include "foc_blockset.h"
#include "vector_control.h"
#include "structures.h"
#include "tim.h"
#include "sanity.h"
#include "motor_param.h"

//Calculate rotor speed from position.
float READ_SPEED(float angle) 
{
    static float sine_rotor ,sine_rotor_prev;
    static float derivative_sine_rotor;
    static float cosine_rotor,cosine_rotor_prev;
    static float derivative_cosine_rotor;

    sine_rotor = sin(angle);
    derivative_sine_rotor = DERIVATIVE_CONSTANT*(sine_rotor-sine_rotor_prev);
    cosine_rotor = cos(angle);
    derivative_cosine_rotor = DERIVATIVE_CONSTANT*(cosine_rotor-cosine_rotor_prev);
    sine_rotor_prev = sine_rotor;
    cosine_rotor_prev = cosine_rotor;
    return ((cosine_rotor*derivative_sine_rotor)-(sine_rotor*derivative_cosine_rotor));
}

//Read rotor position from Encoder pulses.
float READ_POSITION(int position) {
    return (position*PPR_TO_RAD_CONSTANT);
}

//Filter for  speed of rotor.
float  SPEED_FILTER(float speed ,float speed_prev,float speed_filtered_prev) {
    return ((SPEED_FILTER_CONSTANT_1*speed_filtered_prev) + (SPEED_FILTER_CONSTANT_2*(speed+speed_prev)));
}

//Filter for  current of phase.
float  CURRENT_FILTER(float current, float current_prev, float current_filtered_prev) {
    return ((CURRENT_FILTER_CONSTANT_1*current_filtered_prev) + (CURRENT_FILTER_CONSTANT_2*(current+current_prev)));
}

//Slip Speed Routine
float CALCULATE_SLIP_SPEED(float iq_sen,float imr_ref)
{
    float slip;
    slip = iq_sen/(ROTOR_TIME_CONSTANT*imr_ref);//0.22 5Nm 0.59 7Nm 0.89 10Nm 0.99Nm  
    if(slip>SLIP_LIMIT){slip =SLIP_LIMIT;}
    if(slip<0.0){slip=0.0;}
    return slip ;        
}

// PI LOOP 2 END
//Synchronous Speed Routine
float CALCULATE_SYNC_SPEED(float slip , float rotor_speed) {
    return (slip+(POLEPAIRS*(rotor_speed*628.0)));
}

//Electrical angle calculation
float  READ_ROTOR_ANGLE(float rho_prev,float w_s,float w_s_prev) {
    return (rho_prev+((0.5*T_S)*(w_s+w_s_prev)));
}

void SPWM(int p_a ,int p_b , int p_c) 
{
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,p_a);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
        
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,p_b);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
    
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,p_c);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
}

void SVPWM_MODE_DRIVE_FUNCTION(int A_Duty_Svpwm_iq15 , int B_Duty_Svpwm_iq15  , int C_Duty_Svpwm_iq15 ) 
{
   __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,A_Duty_Svpwm_iq15);
   __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,B_Duty_Svpwm_iq15);
   __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,C_Duty_Svpwm_iq15);
}

void MotorControl_Init (void) 
{
    if(HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3) != HAL_OK) Error_Handler();
    if(HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2) != HAL_OK) Error_Handler();
    if(HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1) != HAL_OK) Error_Handler();

    if(HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3) != HAL_OK) Error_Handler();
    if(HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2) != HAL_OK) Error_Handler();
    if(HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1) != HAL_OK) Error_Handler();
}

void DRIVE_STOP(void) 
{ 
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);

    HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1);
    HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_2);
    HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3);

    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
}

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}