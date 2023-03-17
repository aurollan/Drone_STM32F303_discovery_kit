#include "mcu/hat/i2c_send.h"
#include <stdint.h>

uint32_t set_register(const uint8_t reg, const uint8_t *const data,
                      const uint32_t len) {
  return i2c_write(reg, data, len);
}

uint32_t get_register(const uint8_t reg, uint8_t *data, const uint8_t len) {
  return i2c_read(reg, data, len);
}
