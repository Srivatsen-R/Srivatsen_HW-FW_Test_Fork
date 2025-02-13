#ifndef _CANDS_H_
#define _CANDS_H_

uint8_t get_conifg_flag();
void set_config_flag(uint8_t value);
void set_interrupt_flag(uint8_t value);
uint8_t get_interrupt_flag();

float rate_limiter(float target_rpm);
void get_UIID(void);
void send_on_300(void);
void send_on_301(void);
void send_on_302(void);
void send_on_303(void);
void send_on_304(void);
void send_on_305(void);
void send_on_306(void);
void send_on_307(void);
void send_on_308(void);
void send_on_705(void);
void send_on_706(void);
void send_on_710(void);
void send_on_715(void);
void send_on_716(void);
void send_on_717(void);
void send_on_724(void);
void send_on_726(void);
void send_on_7A0(void);
void send_on_6F0(uint8_t* UIID_Arr);
void send_on_6F1(uint8_t* UIID_Arr);
void send_on_6F2(uint8_t* UIID_Arr);
void Current_Sensor_offset_cal(void);
void CAN_Transmit_routine(void);
void Throttle_Control_routine(void);
void Get_and_Send_UIID(void);
void Boot_Counter(void);
void Led_Toggle(void);
void hard_fault_handler_c(uint32_t*);
void read_hard_fault_cause(void);

#endif