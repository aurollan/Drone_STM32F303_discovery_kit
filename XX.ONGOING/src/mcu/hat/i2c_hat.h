#pragma once

#include <stdint.h>

struct i2c_config_hat {
  uint32_t timing;
  uint32_t analog_filter;
  uint32_t digital_filter;
  uint32_t mode;
  uint32_t own_address_1;
  uint32_t ack;
  uint32_t acknowledged_address;
};

uint32_t i2c_initialize(const struct i2c_config_hat *const i2c_config);
