#include "main.h"

extern foc_t          foc;
extern can_t          can;
extern adc_t          analog;
extern terminal_t     terminal;
extern motorControl_t motorControl;

extern float Duty;
extern float avg_board_temp;
extern float torque_calc;
extern float irms_calc;
extern uint8_t pvd_trig_flag;
extern volatile uint32_t z_trig;

static float prev_rpm = 0;
float speed_ref_temp = 0.0;

uint8_t cantp_config_flag = 0;
uint8_t interrupt_flag = 0;
uint8_t forward_set = 0;
uint8_t reverse_set = 0;
uint32_t boot_counter = 0;
uint32_t bor_counter = 0;
uint8_t bor_counter_trig = 0;
uint32_t pvd_counter = 0;

uint32_t* first_4Bytes = ((uint32_t *)(UID_BASE));
uint32_t* next_4Bytes = ((uint32_t *)(UID_BASE + 4));
uint32_t* last_4Bytes = ((uint32_t *)(UID_BASE + 8));

uint8_t UIID_Array[12];

uint8_t get_conifg_flag(){
  return cantp_config_flag;
}

uint8_t get_interrupt_flag(){
  return interrupt_flag;
}

void set_config_flag(uint8_t value){
  cantp_config_flag = value;
}

void set_interrupt_flag(uint8_t value){
  interrupt_flag = value;
}

void send_on_300()
{
  uint8_t can_data[8] = {0};

  can_data[0] = (uint8_t)(rtY.V_abc[0] + 60.0);
  can_data[1] = (uint8_t)(rtY.V_abc[1] + 60.0);
  can_data[2] = (uint8_t)(rtY.V_abc[2] + 60.0);

  if (forward_set && !reverse_set){can_data[3] = 0x02;}
  else if (reverse_set && !forward_set){can_data[3] = 0x04;}
  else if (forward_set && reverse_set){can_data[3] = 0x01;}

  can_data[4] = (uint8_t)((uint16_t)(rtY.Vdc + 10000.0) & 0x00FF);
  can_data[5] = (uint8_t)(((uint16_t)(rtY.Vdc + 10000.0) & 0xFF00) >> 8);

  can_data[6] = (uint8_t)((uint16_t)(rtY.Vdc_sat + 10000.0) & 0x00FF);
  can_data[7] = (uint8_t)(((uint16_t)(rtY.Vdc_sat + 10000.0) & 0xFF00) >> 8);

  _fdcan_transmit_on_can(FDCAN_DEBUG_ID_300, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_301()
{
  uint8_t can_data[8] = {0};

  can_data[0] = (uint8_t)((uint16_t)(irms_calc) & 0x00FF);
  can_data[1] = (uint8_t)(((uint16_t)(irms_calc) & 0xFF00) >> 8);

  can_data[2] = (uint8_t)((uint16_t)(FOC_U.PhaseCurrent[0] + 800.0) & 0x00FF);
  can_data[3] = (uint8_t)(((uint16_t)(FOC_U.PhaseCurrent[0] + 800.0) & 0xFF00) >> 8);

  can_data[4] = (uint8_t)((uint16_t)(FOC_U.PhaseCurrent[1] + 800.0) & 0x00FF);
  can_data[5] = (uint8_t)(((uint16_t)(FOC_U.PhaseCurrent[1] + 800.0) & 0xFF00) >> 8);

  can_data[6] = (uint8_t)((uint16_t)(FOC_U.PhaseCurrent[2] + 800.0) & 0x00FF);
  can_data[7] = (uint8_t)(((uint16_t)(FOC_U.PhaseCurrent[2] + 800.0) & 0xFF00) >> 8);

  _fdcan_transmit_on_can(FDCAN_DEBUG_ID_301, S, can_data, FDCAN_DLC_BYTES); 
}

void send_on_302()
{
  uint8_t can_data[8] = {0};

  float can_log_rh = 0.0f, speed_rpm = 0.0;
  float speed_ref = FOC_U.RefSpeed / RPM_TO_RAD_S;
  
  can_log_rh = (FOC_U.angle + PI) * 100.0f;
  speed_rpm = (foc.speed_sense < 0) ? (foc.speed_sense * SPEED_PU_TO_RPM * -1.0f) : (foc.speed_sense * SPEED_PU_TO_RPM);

  can_data[0] = (uint8_t)((uint16_t)((can_log_rh)) & 0x00FF);
  can_data[1] = (uint8_t)(((uint16_t)((can_log_rh)) & 0xFF00) >> 8);

  can_data[2] = (uint8_t)((uint16_t)(speed_ref) & 0x00FF);
  can_data[3] = (uint8_t)(((uint16_t)(speed_ref) & 0xFF00) >> 8);

  can_data[4] = (uint8_t)((uint16_t)(speed_rpm) & 0x00FF);
  can_data[5] = (uint8_t)(((uint16_t)(speed_rpm) & 0xFF00) >> 8);

  can_data[6] = (uint8_t)(((uint16_t)(TIM2->CNT)) & 0x00FF);
  can_data[7] = (uint8_t)(((uint16_t)(TIM2->CNT) & 0xFF00) >> 8);
  
  _fdcan_transmit_on_can(FDCAN_DEBUG_ID_302, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_303()
{
  uint8_t can_data[8] = {0};

  can_data[0] = (uint8_t)((uint16_t)(motorControl.temperature.motor));

  can_data[1] = (uint8_t)((uint16_t)(avg_board_temp));

  can_data[2] = (uint8_t)(FOC_F_T.Iq_OL_Flag);
  can_data[3] = (uint8_t)(FOC_F_T.OT_Cont_Flag);
  can_data[4] = (uint8_t)(FOC_F_T.Ph_OC_Flag);

  can_data[5] = (uint8_t)(z_trig);

  _fdcan_transmit_on_can(FDCAN_DEBUG_ID_303, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_304()
{
  uint8_t can_data[8] = {0};

  // can_data[4] = (uint8_t)((uint16_t)(FOC_Y.Id + 10000.0) & 0x00FF);
  // can_data[5] = (uint8_t)(((uint16_t)(FOC_Y.Id + 10000.0) & 0xFF00) >> 8);
  
  // can_data[6] = (uint8_t)((uint16_t)(FOC_Y.Iq + 10000.0) & 0x00FF);
  // can_data[7] = (uint8_t)(((uint16_t)(FOC_Y.Iq + 10000.0) & 0xFF00) >> 8);
  float ref_Angle_2pi_log = (rtY.ref_angle_2pi + PI) * 1000.0f;
  float ref_Angle_6pi_log = (rtY.ref_angle_6pi + PI) * 1000.0f;

  float Offset_deg_log = (rtY.Offset_deg + 360) * 100.0f;
  float Offset_rad_log = (rtY.Offset_rad + PI) * 100.0f;

  can_data[0] = (uint8_t)((uint16_t)(ref_Angle_2pi_log) & 0x00FF);
  can_data[1] = (uint8_t)(((uint16_t)(ref_Angle_2pi_log) & 0xFF00) >> 8);

  can_data[2] = (uint8_t)((uint16_t)(ref_Angle_6pi_log) & 0x00FF);
  can_data[3] = (uint8_t)(((uint16_t)(ref_Angle_6pi_log) & 0xFF00) >> 8);

  can_data[4] = (uint8_t)((uint16_t)(Offset_deg_log) & 0x00FF);
  can_data[5] = (uint8_t)(((uint16_t)(Offset_deg_log) & 0xFF00) >> 8);

  can_data[6] = (uint8_t)((uint16_t)(Offset_rad_log) & 0x00FF);
  can_data[7] = (uint8_t)(((uint16_t)(Offset_rad_log) & 0xFF00) >> 8);

  _fdcan_transmit_on_can(FDCAN_DEBUG_ID_304, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_305()
{
  uint8_t can_data[8] = {0};

  can_data[0] = (uint8_t)((uint16_t)(FOC_Y.Id_ref + 10000.0) & 0x00FF);
  can_data[1] = (uint8_t)(((uint16_t)(FOC_Y.Id_ref + 10000.0) & 0xFF00) >> 8);

  can_data[2] = (uint8_t)((uint16_t)(FOC_Y.Iq_ref + 10000.0) & 0x00FF);
  can_data[3] = (uint8_t)(((uint16_t)(FOC_Y.Iq_ref + 10000.0) & 0xFF00) >> 8);

  #if APP1
  can_data[4] = (uint8_t)(0x01);
  #endif
  #if APP2
  can_data[4] = (uint8_t)(0x02);
  #endif

  can_data[5] = (uint8_t)((uint16_t)(FOC_U.BusVoltage_V) & 0x00FF);
  can_data[6] = (uint8_t)(((uint16_t)(FOC_U.BusVoltage_V) & 0xFF00) >> 8);

  can_data[7] = (uint8_t)((uint16_t)(torque_calc));

  _fdcan_transmit_on_can(FDCAN_DEBUG_ID_305, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_306()
{
  uint8_t can_data[8] = {0};

  can_data[0] = (uint8_t)(boot_counter & 0x000000FF);
  can_data[1] = (uint8_t)((boot_counter & 0x0000FF00) >> 8);
  can_data[2] = (uint8_t)((boot_counter & 0x00FF0000) >> 16);
  can_data[3] = (uint8_t)((boot_counter & 0xFF000000) >> 24);

  _fdcan_transmit_on_can(FDCAN_DEBUG_ID_306, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_307()
{
  uint8_t can_data[8] = {0};

  can_data[0] = (uint8_t)(pvd_counter & 0x000000FF);
  can_data[1] = (uint8_t)((pvd_counter & 0x0000FF00) >> 8);
  can_data[2] = (uint8_t)((pvd_counter & 0x00FF0000) >> 16);
  can_data[3] = (uint8_t)((pvd_counter & 0xFF000000) >> 24);

  can_data[4] = (uint8_t)(hard_fault_c.lr & 0x000000FF);
  can_data[5] = (uint8_t)((hard_fault_c.lr & 0x0000FF00) >> 8);
  can_data[6] = (uint8_t)((hard_fault_c.lr & 0x00FF0000) >> 16);
  can_data[7] = (uint8_t)((hard_fault_c.lr & 0xFF000000) >> 24);

  _fdcan_transmit_on_can(FDCAN_DEBUG_ID_307, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_308()
{
  uint8_t can_data[8] = {0};

  // can_data[0] = (uint8_t)(hard_fault_c.pc & 0x000000FF);
  // can_data[1] = (uint8_t)((hard_fault_c.pc & 0x0000FF00) >> 8);
  // can_data[2] = (uint8_t)((hard_fault_c.pc & 0x00FF0000) >> 16);
  // can_data[3] = (uint8_t)((hard_fault_c.pc & 0xFF000000) >> 24);

  can_data[0] = (uint8_t)(curr_off.W_Phase_Offset & 0x00FF);
  can_data[1] = (uint8_t)((curr_off.W_Phase_Offset & 0xFF00) >> 8);
  can_data[2] = (uint8_t)(curr_off.V_Phase_Offset & 0x00FF);
  can_data[3] = (uint8_t)((curr_off.V_Phase_Offset & 0xFF00) >> 8);

  can_data[6] = (uint8_t)((uint16_t)(Duty) & 0x00FF);
  can_data[7] = (uint8_t)(((uint16_t)(Duty) & 0xFF00) >> 8);

  _fdcan_transmit_on_can(FDCAN_DEBUG_ID_308, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_705()
{
  uint8_t can_data[8] = {0};
  can_data[0] = (uint8_t)(motorControl.temperature.motor + 50.0f);
  can_data[1] = (uint8_t)(avg_board_temp + 50.0f);
  can_data[2] = (uint8_t)(boot_counter & 0x000000FF);
  can_data[3] = (uint8_t)((boot_counter & 0x0000FF00) >> 8);
  can_data[4] = (uint8_t)((boot_counter & 0x00FF0000) >> 16);
  can_data[5] = (uint8_t)((boot_counter & 0xFF000000) >> 24);
  _fdcan_transmit_on_can(tx_Controller_705, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_706()
{
  uint8_t can_data[8] = {0};

  if (forward_set && !reverse_set){can_data[0] = 0x02;}
  else if (reverse_set && !forward_set){can_data[0] = 0x04;}
  else if (reverse_set == 1 && forward_set == 1){can_data[0] = 0x01;}
  if (FOC_F_T.Iq_OL_Flag){can_data[3] = 0x01;}
  else if (FOC_F_T.OT_Cont_Flag){can_data[3] = 0x02;}
  else if (FOC_F_T.Ph_OC_Flag){can_data[3] = 0x03;}
  else if (FOC_F_T.N_Flag){can_data[3] = 0x04;}
  else if (FOC_F_T.EEPROM_Error){can_data[3] = 0x05;}
  can_data[4] = (uint8_t)((uint16_t)(abs(FOC_U.ActualSpeed * RPM_TO_RAD_S) * RPM_TO_KMPH * KMPH_CAN_SCALING) & 0x00FF);
  can_data[5] = (uint8_t)(((uint16_t)(abs(FOC_U.ActualSpeed * RPM_TO_RAD_S) * RPM_TO_KMPH * KMPH_CAN_SCALING) & 0xFF00) >> 8);
  _fdcan_transmit_on_can(tx_Controller_706, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_710()
{
  uint8_t can_data[8] = {0};
  can_data[0] = (uint8_t)((uint16_t)(((float)(analog.bufferData[THROTTLE]) / 65535.0) * 100.0f));
  can_data[3] = (uint8_t)((uint16_t)((float)(analog.bufferData[THROTTLE]) * 3.297f / 65535.0f) * THROTTLE_CAN_ADC_SCALING);
  _fdcan_transmit_on_can(tx_Controller_710, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_715()
{
  uint8_t can_data[8] = {0};
  can_data[4] = (uint8_t)(FOC_U.BusVoltage_V);
  can_data[6] = (uint8_t)((uint16_t)(abs(FOC_U.ActualSpeed * RPM_TO_RAD_S)) & 0x00FF);
  can_data[7] = (uint8_t)(((uint16_t)(abs(FOC_U.ActualSpeed * RPM_TO_RAD_S)) & 0xFF00) >> 8);
  _fdcan_transmit_on_can(tx_Controller_715, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_716()
{
  uint8_t can_data[8] = {0};
  can_data[6] = (uint8_t)((uint16_t)(irms_calc) & 0x00FF);
  can_data[7] = (uint8_t)(((uint16_t)(irms_calc) & 0xFF00) >> 8); 
  _fdcan_transmit_on_can(tx_Controller_716, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_717()
{
  uint8_t can_data[8] = {0};
  float freq = abs(FOC_U.ActualSpeed * RPM_TO_RAD_S) * POLEPAIRS / 120.0f;
  can_data[0] = (uint8_t)((uint16_t)(freq) & 0x00FF);
  can_data[1] = (uint8_t)(((uint16_t)(freq) & 0xFF00) >> 8);
  _fdcan_transmit_on_can(tx_Controller_717, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_724()
{
  uint8_t can_data[8] = {0};
  _fdcan_transmit_on_can(tx_Controller_724, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_726()
{
  uint8_t can_data[8] = {0};
  can_data[0] = 0x04;
  can_data[1] = 0x01;
  can_data[2] = 0x01;
  can_data[3] = 0x00;

  can_data[4] = 0x01;
  can_data[5] = 0x00;
  can_data[6] = 0x07;

  can_data[7] = 0x01;
  _fdcan_transmit_on_can(tx_Controller_726, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_7A0()
{
  uint8_t can_data[8] = {0};
  can_data[0] = 0x04;
  can_data[1] = 0x01;
  can_data[2] = 0x00;

  can_data[3] = 0x01;

  #if APP1
    can_data[7] = 0x01;
  #endif

  #if APP2
    can_data[7] = 0x02;
  #endif

  _fdcan_transmit_on_can(tx_Controller_7A0, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_6F0(uint8_t* UIID_Arr)
{
  uint8_t can_data[8] = {0};
  can_data[0] = 0x04;
  can_data[1] = 0x04;
  can_data[2] = 0x01;
  can_data[3] = 0x01;
  can_data[4] = 0x01;
  can_data[5] = 0x00;
  can_data[6] = 0x01;
  can_data[7] = UIID_Arr[0];
  _fdcan_transmit_on_can(tx_Controller_6F0, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_6F1(uint8_t* UIID_Arr)
{
  uint8_t can_data[8] = {0};
  can_data[0] = 0x04;
  can_data[1] = 0x01;
  can_data[2] = 0x00;
  can_data[3] = 0x00;
  can_data[4] = UIID_Arr[1];
  can_data[5] = UIID_Arr[2];
  can_data[6] = UIID_Arr[3];
  can_data[7] = UIID_Arr[4];
  _fdcan_transmit_on_can(tx_Controller_6F1, S, can_data, FDCAN_DLC_BYTES);
}

void send_on_6F2(uint8_t* UIID_Arr)
{
  uint8_t can_data[8] = {0};
  can_data[0] = 0x04;
  can_data[1] = UIID_Arr[5];
  can_data[2] = UIID_Arr[6];
  can_data[3] = UIID_Arr[7];
  can_data[4] = UIID_Arr[8];
  can_data[5] = UIID_Arr[9];
  can_data[6] = UIID_Arr[10];
  can_data[7] = UIID_Arr[11];
  _fdcan_transmit_on_can(tx_Controller_6F2, S, can_data, FDCAN_DLC_BYTES);
}

void get_UIID()
{
  UIID_Array[0] = (*first_4Bytes) & 0xFF;
  UIID_Array[1] = (*first_4Bytes >> 8) & 0xFF;
  UIID_Array[2] = (*first_4Bytes >> 16) & 0xFF;
  UIID_Array[3] = (*first_4Bytes >> 24) & 0xFF;

  UIID_Array[4] = (*next_4Bytes) & 0xFF;
  UIID_Array[5] = (*next_4Bytes >> 8) & 0xFF;
  UIID_Array[6] = (*next_4Bytes >> 16) & 0xFF;
  UIID_Array[7] = (*next_4Bytes >> 24) & 0xFF;

  UIID_Array[8] = (*last_4Bytes) & 0xFF;
  UIID_Array[9] = (*last_4Bytes >> 8) & 0xFF;
  UIID_Array[10] = (*last_4Bytes >> 16) & 0xFF;
  UIID_Array[11] = (*last_4Bytes >> 24) & 0xFF;
}

// Rate limiter to smooth RPM changes
float rate_limiter(float target_rpm) 
{
  float rpm_change = target_rpm - prev_rpm;

  if (rpm_change > RATE_LIMIT) {
      target_rpm = prev_rpm + RATE_LIMIT;  // Limit the increase
  } else if (rpm_change < -RATE_LIMIT) {
      target_rpm = prev_rpm - RATE_LIMIT;  // Limit the decrease
  }

  prev_rpm = target_rpm;  // Update previous RPM for the next iteration
  return target_rpm;
}

void Current_Sensor_offset_cal(void)
{
  float offset_w = 0;
  float offset_v = 0;

  offset_w = analog.bufferData[PHASE_CURRENT_W];
  offset_v = analog.bufferData[PHASE_CURRENT_V];

  for (uint8_t i = 0; i < 5; i++)
  {
    offset_w += analog.bufferData[PHASE_CURRENT_W];
    offset_v += analog.bufferData[PHASE_CURRENT_V];
  }

  curr_off.W_Phase_Offset = (uint16_t)(offset_w / 6.0f);
  curr_off.V_Phase_Offset = (uint16_t)(offset_v / 6.0f);
}

void Throttle_Control_routine()
{
  uint32_t time_count = HAL_GetTick();
  static uint32_t prev_thr_time = 0;
  
  reverse_set = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_3);
  forward_set = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4);

  if (forward_set && !reverse_set && fabsf((FOC_U.ActualSpeed / RPM_TO_RAD_S)) <= 10.0f && Read_Throttle(analog.bufferData[THROTTLE]) <= 600){fnr.throttle_disabled = 0; fnr.previous_state = fnr.current_state; fnr.current_state = FORWARD;}
  else if (reverse_set && !forward_set && fabsf((FOC_U.ActualSpeed / RPM_TO_RAD_S)) <= 10.0f && Read_Throttle(analog.bufferData[THROTTLE]) <= 600){fnr.throttle_disabled = 0; fnr.previous_state = fnr.current_state; fnr.current_state = REVERSE;}
  else if (forward_set && reverse_set){fnr.throttle_disabled = 1; fnr.current_state = NEUTRAL;}

  if ((fnr.current_state == FORWARD && fnr.previous_state == NEUTRAL) || (fnr.current_state == REVERSE && fnr.previous_state == NEUTRAL)){fnr.throttle_disabled = 0;}

  #if THROTTLE_CNTRL
  if (!fnr.throttle_disabled)
  {
    speed_ref_temp = Throttle_Control(Rpm_Target_Function(moving_Throttle_measured_fun(Read_Throttle(analog.bufferData[THROTTLE]), 1.0)) * SPEED_PU_TO_RPM, speed_ref_temp);
    FOC_U.RefSpeed = speed_ref_temp * RPM_TO_RAD_S;

    if (FOC_U.RefSpeed <= 0.0)
    {
      FOC_U.RefSpeed = 0.0;
    }
  }
  else if (fnr.throttle_disabled)
  {
    speed_ref_temp = Throttle_Control(Rpm_Target_Function(moving_Throttle_measured_fun(Read_Throttle(8500.0f), 1.0)) * SPEED_PU_TO_RPM, speed_ref_temp);
    FOC_U.RefSpeed = speed_ref_temp * RPM_TO_RAD_S;

    if (FOC_U.RefSpeed <= 0.0)
    {
      FOC_U.RefSpeed = 0.0;
    }
  }

  #endif

  #if RAMP_CNTRL
  if (time_count - prev_thr_time >= 100)
  {
    if (FOC_U.RefSpeed < (1000.0 * RPM_TO_RAD_S))
      FOC_U.RefSpeed += 1.0;

    if (FOC_U.RefSpeed > (1000.0 * RPM_TO_RAD_S))
      FOC_U.RefSpeed = (1000.0 * RPM_TO_RAD_S);

    if (FOC_U.RefSpeed < 0.0)
      FOC_U.RefSpeed = 0.0;

    foc_log.RefSpeed = FOC_U.RefSpeed / RPM_TO_RAD_S;

    prev_thr_time = time_count;
  }
  #endif
}

void Get_and_Send_UIID()
{
  get_UIID();

  send_on_6F0(UIID_Array);
  send_on_6F1(UIID_Array);
  send_on_6F2(UIID_Array);
}

void CAN_Transmit_routine()
{
  uint32_t time_count = HAL_GetTick();
  static uint32_t prev_time = 0;
  static uint32_t prev_time_700x = 0;

  #if DEBUG_EN
  if (time_count - prev_time >= 100)
  {
    send_on_300();
    send_on_301();
    send_on_302();
    send_on_303();
    send_on_304();
    send_on_305();
    send_on_306();
    // send_on_307();
    // send_on_308();

    prev_time = time_count;
  }
  #endif

  #if DEBUG_OFF
  if (time_count - prev_time_700x >= 500)
  {
    send_on_705();
    send_on_706();
    send_on_710();
    send_on_715();
    send_on_716();
    send_on_717();
    send_on_724();
    send_on_726();
    send_on_7A0();

    prev_time_700x = time_count;
  }
  #endif
}

void Boot_Counter()
{  
  EEPROM_Read_Data_Boot_Counter(&boot_counter);
  boot_counter += 1;
  EEPROM_Write_Data_Boot_Counter(boot_counter);
}

void read_hard_fault_cause()
{
  // Read all the stored register data
  EEPROM_Read_Data_LR_Register(&hard_fault_c.lr);
  EEPROM_Read_Data_PC_Register(&hard_fault_c.pc);
}

void Led_Toggle()
{
  //turn led red/green depending on drive status
  if(motorControl.drive.check == DRIVE_DISABLE) {
    //rgb gpio
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
  }
  else if(motorControl.drive.check == DRIVE_ENABLE) {
    //rgb gpio
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
  }
}