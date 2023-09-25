#ifndef __BOOTLOADERMAIN_H_
#define __BOOTLOADERMAIN_H_

void set_interrupt_flag(uint8_t value);
uint8_t get_interrupt_flag();
uint8_t get_conifg_flag();
void set_config_flag(uint8_t value);

#endif