#pragma once

#include <stdint.h>

struct timer_config_hat {
  uint32_t precision;
  uint32_t duration_max;
};

uint32_t timer_initialize(const struct timer_config_hat *const timer_config);
