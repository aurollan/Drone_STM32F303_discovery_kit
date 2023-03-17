#include "config_mcu.h"
#include "hat/i2c_hat.h"
#include "hat/timer_hat.h"

uint32_t init_mcu(void) {

  clock_initialize(&clock_config);
  i2c_initialize(&i2c_config);
  pwm_initialize(&pwm_config);
  uart_initialize(&uart_config);
  timer_initialize(&timer_config);

  return (0);
}
