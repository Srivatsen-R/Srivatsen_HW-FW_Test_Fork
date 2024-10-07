/*
Pegasus - Motor Controller Unit software for HL,HLP,Storm,Vortex and future projects.

Contributors: Pujit Gandhi,Pratik Rout,Olay,Saksham

This file contains functions associated with algorithm implementation for Field oriented control for ACIM/PMSM.

VECTOR_FOC_Control(void) : This functions contains all the FOC blockset functions responsible for motor control.

VECTOR CONTROL SUMMARY
To summarize the steps required for indirect vector
control:

1. The 3-phase stator currents are measured. This measurement provides ia, ib and ic. The rotor velocity is also measured.

2. The 3-phase currents are converted to a 2-axis system. This conversion provides the variables iα and iβ from the measured ia, ib and ic 
values.iα and iβ are time varying quadrature current values as viewed from the perspective of the stator.

3. The 2-axis coordinate system is rotated to align with the rotor flux using a transformation angle information calculated at the last 
iteration of the control loop. This conversion provides the Id and Iq variables from iα and iβ. Id and Iq are the quadrature currents 
transformed to the rotating coordinate system. For steady state conditions, Id and Iq will be constant.

4. Error signals are formed using Id, Iq and reference values for each. The Id reference controls rotor magnetizing flux. 
The Iq reference controls the torque output of the motor. The error signals are input to PI controllers. The output of the 
controllers provide Vd and Vq, which is a voltage vector that will be sent to the motor.

5. A new coordinate transformation angle is calculated. The motor speed, rotor electrical time constant, Id and Iq are the inputs 
to this calculation.The new angle tells the algorithm where to place the next voltage vector to produce an amount of slip for the present 
operating conditions.

6. The Vd and Vq output values from the PI controllers are rotated back to the stationary reference frame using the new angle. 
This calculation provides quadrature voltage values vα and vβ.

7. The vα and vβ values are transformed back to 3-phase values va, vb and vc. The 3-phase voltage values are used to calculate new PWM
duty cycle values that generate the desired voltage vector.

*/

#include <math.h>
#include "math_func.h"
#include "vector_control.h"
#include "dr_devices.h"
#include "structures.h"
#include "tim.h"
#include "sanity.h"
#include "foc_blockset.h"
#include "foc_mtpa_lut.h"
#include <stdint.h>
#include "motor_param.h"
#include "Pegasus_MBD.h"
#include "Position_Calculation.h"
#include "FOC.h"
#include "rtwtypes.h"

extern int a_current;
extern int b_current;
extern int dc_current_u;
extern int dc_current_v;
extern int dc_current_w;
extern int speed_filtered;
extern float ref_output;

extern int forward_flag;
extern int reverse_flag;
extern int neutral_flag;
extern float Duty;
extern uint8_t reset_flag;
extern uint8_t forward_set;
extern uint8_t reverse_set;
uint8_t duty_state=1;
uint8_t speed_fix_flag=0;
extern uint8_t acc_flag;
extern uint8_t deacc_flag;

float log_gain=0;
float log_intg=0;
extern motorControl_t motorControl;

extern ExtU rtU;
extern ExtY rtY;

extern ExtU_FOC_T FOC_U;
extern ExtY_FOC_T FOC_Y;

int state=0;

foc_t foc; 
extern mtpa_lut mtpa;

extern const int mtpa_lut_id[16][6];
extern const int mtpa_lut_iq[16][6];


terminal_t terminal = {
       .rotor.rpm            = 10000.0,
       .rotor.angle          = 0.0,
       .rotor.speed          = 0.0,
       .rotor.speed_filtered = 0.0,
       .phase.A_current      = 0,
       .phase.B_current      = 0,
       .phase.C_current      = 0,
       .clarke.alpha_current = 0.0,
       .clarke.beta_current  = 0.0,
       .park.ids             = 0.0,
       .park.iqs             = 0.0,
       .speed.slip           = 0.0,
       .speed.sync           = 0.0,
       .speed.angular        = 0.0,
       .rho_                 = 0.0,
       .rho.sin              = 0.0,
       .rho.cos              = 0.0,
       .vd.ref               = 0.0,
       .vq.ref               = 0.0,
       .imr.ref              = 0.0,
       .imr.sen              = 0.0,
       .imr.err              = 0.0,
       .imr.gain             = 0.0,
       .imr.intg             = 0.0, 
       .w.ref                = 0.0,
       .w.sen                = 0.0,
       .w.err                = 0.0,
       .w.gain               = 0.0,
       .w.intg               = 0.0,
       .iq.err               = 0.0,
       .iq.gain              = 0.0,
       .iq.intg              = 0.0,
       .id.err               = 0.0,
       .id.gain              = 0.0,
       .id.intg              = 0.0,
       .volt.bus_volt        = 0.0, 
};

void FOC_READ_MOTOR_POSITION(void)
{
    foc.rotor_angle =  READ_POSITION(motorControl.encoder.value);
    foc.rotor_speed =  READ_SPEED(foc.rotor_angle);

    // if(foc.rotor_speed<0.0){foc.rotor_speed=0.0;}
    foc.rotor_speed_filtered = SPEED_FILTER(foc.rotor_speed,foc.rotor_speed_prev,foc.rotor_speed_filtered_prev); 
    foc.speed_sense = (foc.rotor_speed_filtered)*PU*1.0;
    if(foc.speed_sense>MAX_PU_SPEED){foc.speed_sense=MAX_PU_SPEED;} 
    else if (foc.speed_sense<-MAX_PU_SPEED){foc.speed_sense=-MAX_PU_SPEED;}

    if (forward_set)
        FOC_U.ActualSpeed = (foc.speed_sense * SPEED_PU_TO_RPM * 1.0) * 0.1047;
    else if (reverse_set)
        FOC_U.ActualSpeed = (foc.speed_sense * SPEED_PU_TO_RPM * -1.0) * 0.1047;

    static float angle_mech;

    foc.slip_speed = 0.0;
    //Synchronous Speed Calculation
    foc.sync_speed = CALCULATE_SYNC_SPEED(foc.slip_speed,foc.rotor_speed_filtered);//sync speed

    if (forward_set)
    {
        if((foc.speed_sense * 1.0 * SPEED_PU_TO_RPM * 0.1047)<10.0 && duty_state)
        { 
            angle_mech = (100-Duty)*DUTY_TO_RADIAN;

            // angle_mech = (Duty)*DUTY_TO_RADIAN; //mech angle
            foc.rho_prev = POLEPAIRS*angle_mech; // elec angle
            if (angle_mech>2.095 && angle_mech<4.1866){foc.rho_prev = foc.rho_prev - 6.28;}
            else  if(angle_mech>=4.1886){foc.rho_prev = foc.rho_prev - 12.56;}
            duty_state = 0;
        }
    }
    else if (reverse_set)
    {
        if((foc.speed_sense * -1.0 * SPEED_PU_TO_RPM * 0.1047)<10.0 && duty_state)
        { 
            angle_mech = (100-Duty)*DUTY_TO_RADIAN;

            // angle_mech = (Duty)*DUTY_TO_RADIAN; //mech angle
            foc.rho_prev = POLEPAIRS*angle_mech; // elec angle
            if (angle_mech>2.095 && angle_mech<4.1866){foc.rho_prev = foc.rho_prev - 6.28;}
            else  if(angle_mech>=4.1886){foc.rho_prev = foc.rho_prev - 12.56;}
            duty_state = 0;
        }
    }

    if(reset_flag == 1)
    {
        reset_flag=0;
    }

    if (forward_set)
    {
        if((foc.speed_sense * SPEED_PU_TO_RPM * 1.0 * 0.1047) <= 0.0)
        {
            duty_state = 1;
        }
    }
    else if (reverse_set)
    {
        if((foc.speed_sense * SPEED_PU_TO_RPM * -1.0 * 0.1047) <= 0.0)
        {
            duty_state = 1;
        }
    }

    foc.rho = READ_ROTOR_ANGLE(foc.rho_prev,foc.sync_speed,foc.sync_speed_prev);//electrical angle
    Position_Calculation_step();

    if (forward_set)
        FOC_U.angle = foc.rho + ANGLE_OFFSET_RW;
    else if (reverse_set)
        FOC_U.angle = foc.rho + ANGLE_OFFSET_FW;

    foc.rotor_speed_prev          = foc.rotor_speed;  
    foc.rotor_speed_filtered_prev = foc.rotor_speed_filtered;
    foc.sync_speed_prev           = foc.sync_speed;
    foc.rho_prev                  = foc.rho;
}

void FOC_SPACE_VECTOR_MODULATION()
{
    // //PWM DUTY VARIABLES
    // if (rtY.FOC_Out.Normalized_Va > UL)
    //     rtY.FOC_Out.Normalized_Va = UL;
    // else if (rtY.FOC_Out.Normalized_Va < LL)
    //     rtY.FOC_Out.Normalized_Va = LL;

    // if (rtY.FOC_Out.Normalized_Vb > UL)
    //     rtY.FOC_Out.Normalized_Vb = UL;
    // else if (rtY.FOC_Out.Normalized_Vb < LL)
    //     rtY.FOC_Out.Normalized_Vb = LL;

    // if (rtY.FOC_Out.Normalized_Vc > UL)
    //     rtY.FOC_Out.Normalized_Vc = UL;
    // else if (rtY.FOC_Out.Normalized_Vc < LL)
    //     rtY.FOC_Out.Normalized_Vc = LL;

    foc.pwm_a = (uint16_t)((PWM_CONST_2*((FOC_Y.Va / 60.0) * 32767.0))  + PWM_CONST_1);
    foc.pwm_b = (uint16_t)((PWM_CONST_2*((FOC_Y.Vb / 60.0) * 32767.0))  + PWM_CONST_1);
    foc.pwm_c = (uint16_t)((PWM_CONST_2*((FOC_Y.Vc / 60.0) * 32767.0))  + PWM_CONST_1);   

    if (foc.pwm_a < 0)
        foc.pwm_a = 0;
    else if (foc.pwm_a > 2500)
        foc.pwm_a = 2500;

    if (foc.pwm_b < 0)
        foc.pwm_b = 0;
    else if (foc.pwm_b > 2500)
        foc.pwm_b = 2500;

    if (foc.pwm_c < 0)
        foc.pwm_c = 0;
    else if (foc.pwm_c > 2500)
        foc.pwm_c = 2500;

    //Modulation  Techniques
    //SPWM(foc.pwm_a,foc.pwm_b,foc.pwm_c);
    if(motorControl.drive.check == DRIVE_ENABLE) {SVPWM_MODE_DRIVE_FUNCTION(foc.pwm_a,foc.pwm_b,foc.pwm_c);}
    else {DRIVE_STOP();}
}