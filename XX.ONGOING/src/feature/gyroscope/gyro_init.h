#pragma once

#include <stdint.h>

struct gyro_config_hat {
  uint32_t precision;
};

uint32_t gyro_init(const struct gyro_config_hat *const gyro_config);
