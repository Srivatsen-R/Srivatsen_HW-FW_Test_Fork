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
#include "main.h"

extern float Duty;
uint8_t duty_state = 0;

extern motorControl_t motorControl;
foc_t foc; 

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

extern float busVoltage;

void FOC_READ_MOTOR_POSITION(void)
{
    foc.rotor_angle =  READ_POSITION(TIM2->CNT);
    foc_log.Angle_mech = foc.rotor_angle;
    rtU.Encoder_count = TIM2->CNT;
    foc.rotor_speed =  READ_SPEED(foc.rotor_angle);

    foc.rotor_speed_filtered = SPEED_FILTER(foc.rotor_speed,foc.rotor_speed_prev,foc.rotor_speed_filtered_prev); 
    foc.speed_sense = (foc.rotor_speed_filtered)*PU*1.0;
    if(foc.speed_sense>MAX_PU_SPEED){foc.speed_sense=MAX_PU_SPEED;} 
    else if (foc.speed_sense<-MAX_PU_SPEED){foc.speed_sense=-MAX_PU_SPEED;}

    if (fnr.current_state == FORWARD)
    {
        FOC_U.ActualSpeed = (foc.speed_sense * SPEED_PU_TO_RPM * 1.0) * RPM_TO_RAD_S;
        fnr.previous_state = fnr.current_state;
    }
    else if (fnr.current_state == REVERSE)
    {
        FOC_U.ActualSpeed = (foc.speed_sense * SPEED_PU_TO_RPM * -1.0) * RPM_TO_RAD_S;
        fnr.previous_state = fnr.current_state;
    }
    else if (fnr.current_state == NEUTRAL)
    {
        if (fnr.previous_state == FORWARD)
        {
            FOC_U.ActualSpeed = (foc.speed_sense * SPEED_PU_TO_RPM * 1.0) * RPM_TO_RAD_S;
        }
        else if (fnr.previous_state == REVERSE)
        {
            FOC_U.ActualSpeed = (foc.speed_sense * SPEED_PU_TO_RPM * -1.0) * RPM_TO_RAD_S;
        }
    }

    foc_log.ActualSpeed = FOC_U.ActualSpeed / RPM_TO_RAD_S;

    static float angle_mech;

    foc.slip_speed = 0.0;
    //Synchronous Speed Calculation
    foc.sync_speed = CALCULATE_SYNC_SPEED(foc.slip_speed,foc.rotor_speed_filtered);//sync speed

    if (fnr.current_state == FORWARD)
    {
        if((foc.speed_sense * 1.0 * SPEED_PU_TO_RPM)<10.0 && duty_state == 0)
        { 
            angle_mech = -(Duty)*DUTY_TO_RADIAN;
            foc.rho_prev = POLEPAIRS*angle_mech; // elec angle
            duty_state = 1;
        }

        fnr.previous_state = fnr.current_state;
    }
    else if (fnr.current_state == REVERSE)
    {
        if((foc.speed_sense * -1.0 * SPEED_PU_TO_RPM)<10.0 && duty_state == 0)
        { 
            angle_mech = (100-Duty)*DUTY_TO_RADIAN;
            foc.rho_prev = POLEPAIRS*angle_mech; // elec angle
            duty_state = 1;
        }

        fnr.previous_state = fnr.current_state;
    }
    else if (fnr.current_state == NEUTRAL)
    {
        if (fnr.previous_state == FORWARD)
        {
            if((foc.speed_sense * 1.0 * SPEED_PU_TO_RPM)<10.0 && duty_state == 0)
            { 
                angle_mech = -(Duty)*DUTY_TO_RADIAN;
                foc.rho_prev = POLEPAIRS*angle_mech; // elec angle
                duty_state = 1;
            }
        }
        else if (fnr.previous_state == REVERSE)
        {
            if((foc.speed_sense * -1.0 * SPEED_PU_TO_RPM)<10.0 && duty_state == 0)
            { 
                angle_mech = (100-Duty)*DUTY_TO_RADIAN;
                foc.rho_prev = POLEPAIRS*angle_mech; // elec angle
                duty_state = 1;
            }
        }
    }

    if (fnr.current_state == FORWARD)
    {
        if((foc.speed_sense * SPEED_PU_TO_RPM * 1.0) <= 10.0)
        {
            duty_state = 0;
        }

        fnr.previous_state = fnr.current_state;
    }
    else if (fnr.current_state == REVERSE)
    {
        if((foc.speed_sense * SPEED_PU_TO_RPM * -1.0) <= 10.0)
        {
            duty_state = 0;
        }

        fnr.previous_state = fnr.current_state;
    }
    else if (fnr.current_state == NEUTRAL)
    {
        if (fnr.previous_state == FORWARD)
        {
            if((foc.speed_sense * SPEED_PU_TO_RPM * 1.0) <= 10.0)
            {
                duty_state = 0;
            }
        }
        else if (fnr.previous_state == REVERSE)
        {
            if((foc.speed_sense * SPEED_PU_TO_RPM * -1.0) <= 10.0)
            {
                duty_state = 0;
            }
        }
    }

    foc.rho = READ_ROTOR_ANGLE(foc.rho_prev,foc.sync_speed,foc.sync_speed_prev);//electrical angle

    foc_log.Angle_intg = foc.rho;

    if (foc.rho >= (4 * PI) && foc.rho <= (6 * PI))
        FOC_U.angle = foc.rho - (4 * PI);
    else if (foc.rho >= (2 * PI) && foc.rho <= (4 * PI))
        FOC_U.angle = foc.rho - (2 * PI);
    else if (foc.rho >= 0 && foc.rho <= (2 * PI))
        FOC_U.angle = foc.rho;

    if (foc.rho <= -(4 * PI) && foc.rho >= -(6 * PI))
        FOC_U.angle = foc.rho + (4 * PI);
    else if (foc.rho <= -(2 * PI) && foc.rho >= -(4 * PI))
        FOC_U.angle = foc.rho + (2 * PI);
    else if (foc.rho <= 0 && foc.rho >= -(2 * PI))
        FOC_U.angle = foc.rho;

    if (fnr.current_state == FORWARD)
    {
        FOC_U.angle = FOC_U.angle - ANGLE_OFFSET_RW - PI;
        fnr.previous_state = fnr.current_state;
    }
    else if (fnr.current_state == REVERSE)
    {
        FOC_U.angle = FOC_U.angle + ANGLE_OFFSET_FW + PI;
        fnr.previous_state = fnr.current_state;
    }
    else if (fnr.current_state == NEUTRAL)
    {
        if (fnr.previous_state == FORWARD)
        {
            FOC_U.angle = FOC_U.angle - ANGLE_OFFSET_RW - PI;
        }
        else if (fnr.previous_state == REVERSE)
        {
            FOC_U.angle = FOC_U.angle + ANGLE_OFFSET_FW + PI;
        }
    }

    foc_log.Angle_intg_noml = FOC_U.angle;

    if (FOC_U.angle >= PI)
        FOC_U.angle -= 2 * PI;
    else if (FOC_U.angle <= -PI)
        FOC_U.angle += 2 * PI;

    foc_log.Angle_elec = FOC_U.angle;

    foc.rotor_speed_prev          = foc.rotor_speed;  
    foc.rotor_speed_filtered_prev = foc.rotor_speed_filtered;
    foc.sync_speed_prev           = foc.sync_speed;
    foc.rho_prev                  = foc.rho;
}

void FOC_SPACE_VECTOR_MODULATION()
{
    // foc.pwm_a = (uint16_t)((PWM_CONST_2*((rtY.V_abc[0] / ( busVoltage/2))))  + PWM_CONST_1);
    // foc.pwm_b = (uint16_t)((PWM_CONST_2*((rtY.V_abc[1] / ( busVoltage/2))))  + PWM_CONST_1);
    // foc.pwm_c = (uint16_t)((PWM_CONST_2*((rtY.V_abc[2] / ( busVoltage/2))))  + PWM_CONST_1);
    
    foc.pwm_a = (uint16_t)((PWM_CONST_2*((rtY.V_abc[0] / (busVoltage))))  + PWM_CONST_1);
    foc.pwm_b = (uint16_t)((PWM_CONST_2*((rtY.V_abc[1] / (busVoltage))))  + PWM_CONST_1);
    foc.pwm_c = (uint16_t)((PWM_CONST_2*((rtY.V_abc[2] / (busVoltage))))  + PWM_CONST_1);

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

    if(motorControl.drive.check == DRIVE_ENABLE) {SVPWM_MODE_DRIVE_FUNCTION(foc.pwm_a,foc.pwm_b,foc.pwm_c);}
    else {DRIVE_STOP();}
}