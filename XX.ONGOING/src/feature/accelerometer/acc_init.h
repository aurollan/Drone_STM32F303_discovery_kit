#pragma once

#include <stdint.h>

struct acc_config_hat {
  uint32_t precision;
};

uint32_t acc_init(const struct acc_config_hat *const acc_config);
