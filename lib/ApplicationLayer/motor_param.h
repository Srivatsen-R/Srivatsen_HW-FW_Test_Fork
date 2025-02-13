
#ifndef MOTOR_PARAM_H
#define MOTOR_PARAM_H


//Drive parameters
#define NTC_PULL_UP_RESISTOR                10000//NIDEC NTC VALUE


#define SPEED_LIMIT                     1500.0
#define HEAT_SINK_MAX_TEMP_LIMIT        75.0
#define MOTOR_TEMP_LIMIT                130.0   

#define MAX_SPEED                       30000    
#define SPEED_MUL_FACTOR                ((SPEED_LIMIT*32767.0)/(6000.0*MAX_SPEED))//0.364//0.273
#define HEAT_SINK_TEMP_HYS              10.0 
#define THROTTLE_ADC_OFFSET_COUNT       1700 //0.8V

#define VBUS_OFFSET                      2.3   
#define OVER_VOLT_HYS                    0.5   
#define UNDER_VOLT_HYS                   0.5   
#define Adc_max_COUNT                    65535
#define ADC_REF                          3.3
#define MAX_TARGET_SPEED                    3000.0
#define TH_AVG_MAX_ADC_COUNT                (Adc_max_COUNT -  THROTTLE_ADC_OFFSET_COUNT)
#define TH_AVG_TO_SPEED_MUL_FACTOR          ((MAX_TARGET_SPEED / TH_AVG_MAX_ADC_COUNT) * SPEED_MUL_FACTOR)
#define PU_TO_RPM                           21.85//65535/3000
#define TH_START_LIMIT                      20.0
#define TH_HYSS_LIMIT                       5.0

#define RPM_TO_KMPH                         0.0083246
#define HOUR_TO_MS_100                      0.000277778
#define KMPH_CAN_SCALING                    10
#define ODO_CAN_SCALING                     10 
#define THROTTLE_CAN_ADC_SCALING            10.0
#define BETA_VALUE                          4000.0   
#define T_AMBIENT                           25.0
#define KELVIN_TO_CELSIUS                   273.15 
#define THROTTLE_AVG                        1.0
#define TEMP_AVG                            15.0
#define VOLTAGE_AVG                         60.0

float moving_Batt_voltage_measured_fun(float  , float ) ;
float moving_Temperature_measured_fun(float ,float);
int moving_Throttle_measured_fun(int,int);
float Throttle_Control(int,float);
int Rpm_Target_Function(int);
int Read_Throttle(int);


#endif 
