#include <stdint.h>

uint32_t gpio_initialize(const struct gpio_config_hat *const gpio_config) {

  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable the GPIO_LED Clock */
  RCC_AHBPeriphClockCmd(GPIO_CLK[Led], ENABLE);

  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_PIN[Led];
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIO_PORT[Led], &GPIO_InitStructure);
  return (0);
}

uint32_t set_gpio_output_state(GPIO_TypeDef *gpio_port, uint32_t gpio_pin,
                               bool state) {
  uint32_t ret = 0;

  if (gpio_pin >= 16) {
    ret = EINVAL;
  } else if (state == true) {
    gpio_port->BSRR = (uint16_t)(0x01 << gpio_pin);
  } else {
    gpio_port->BRR = (uint16_t)(0x01 << gpio_pin);
  }

  return (0);
}

uint32_t toggle_gpio_output(GPIO_TypeDef *gpio_port, uint32_t gpio_pin) {
  gpio_port->ODR ^= (uint16_t)(0x01 << gpio_pin);
}
