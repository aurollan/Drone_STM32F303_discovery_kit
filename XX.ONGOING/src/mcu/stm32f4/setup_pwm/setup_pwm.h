#include <stdint.h>

#pragma once

void pwm_initialize();
void set_duty_cycle(uint16_t TIM_Channel, uint8_t percentage);
