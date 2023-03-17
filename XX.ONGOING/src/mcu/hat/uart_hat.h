#pragma once

#include <stdint.h>

struct uart_config_hat {
  uint32_t baud_rate;
  uint32_t word_length;
  uint32_t stop_bits;
  uint32_t parity;
  uint32_t mode;
  uint32_t hardware_flow_control;
};

uint32_t uart_initialize(const struct uart_config_hat *const uart_config);
