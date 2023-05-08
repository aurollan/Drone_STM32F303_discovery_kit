#include <stdint.h>

#include "feature/led_compass/led.h"

uint32_t blink_led_compass() {
  uint32_t index;

  for (index = 0; index < STATIC_ARRAY_LEN(led_compass); index++) {
    led_toggle(led_compass[index]);
    delay_ms(5);
  }

  return (0);
}

int main(void) {
  while (1) {
    blink_led_compass();
  }

  return (0);
}
