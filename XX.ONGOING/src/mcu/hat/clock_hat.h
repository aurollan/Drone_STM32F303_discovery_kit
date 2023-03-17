#pragma once

#include <stdint.h>

struct clock_config_hat {
  uint32_t clock_speed;
};

uint32_t clock_initialize(const struct clock_config_hat *const clock_config);
