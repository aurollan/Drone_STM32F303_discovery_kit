#pragma once

#include "mcu/hat/clock_hat.h"
#include "mcu/hat/gpio_hat.h"
#include "mcu/hat/i2c_hat.h"
#include "mcu/hat/pwm_hat.h"
#include "mcu/hat/timer_hat.h"
#include "mcu/hat/uart_hat.h"

const struct gpio_config_hat gpio_config {
  .gpio_pupd = 0,
};

const struct clock_config_hat clock_config = {
    .clock_speed = 1000000,
};

const struct i2c_config_hat i2c_config = {
    .ack = 0,
    .acknowledged_address = 0,
    .own_address_1 = 0,
    .analog_filter = 0,
    .digital_filter = 0,
    .mode = 0,
    .timing = 0,
};

const struct pwm_config_hat pwm_config = {
    .duty_cycle = 0,
    .OC_mode = 0,
    .output_state = 0,
    .output_Nstate = 0,
    .pulse = 0,
    .OC_polarity = 0,
    .OCN_polarity = 0,
    .OC_idle_state = 0,
    .OCN_idle_state = 0,
    .prescaler = 0,
    .counter_mode = 0,
    .period = 0,
    .clock_division = 0,
    .repetition_counter = 0,
};

const struct uart_config_hat uart_config = {
    .baud_rate = 0,
    .word_length = 0,
    .stop_bits = 0,
    .parity = 0,
    .mode = 0,
    .hardware_flow_control = 0,
};

const struct timer_config_hat timer_config = {
    .duration_max = 0,
    .precision = 0,
};
