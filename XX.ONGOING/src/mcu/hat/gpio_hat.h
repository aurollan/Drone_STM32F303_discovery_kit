#pragma once

#include <stdint.h>

struct gpio_config_hat {
  uint32_t gpio_pupd;
};

uint32_t gpio_initialize(const struct gpio_config_hat *const gpio_config);
