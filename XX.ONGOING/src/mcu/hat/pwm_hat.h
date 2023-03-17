#pragma once

#include <stdint.h>

struct pwm_config_hat {
  uint32_t duty_cycle;
  uint32_t OC_mode;
  uint32_t output_state;
  uint32_t output_Nstate;
  uint32_t pulse;
  uint32_t OC_polarity;
  uint32_t OCN_polarity;
  uint32_t OC_idle_state;
  uint32_t OCN_idle_state;
  uint32_t prescaler;
  uint32_t counter_mode;
  uint32_t period;
  uint32_t clock_division;
  uint32_t repetition_counter;
};

uint32_t pwm_initialize(const struct pwm_config_hat *const pwm_config);
