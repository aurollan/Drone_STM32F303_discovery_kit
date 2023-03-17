#include "feature_config.h"

uint32_t feature_initialize(void) {

  acc_init(&acc_config);
  gyro_init(&gyro_config);

  return (0);
}
