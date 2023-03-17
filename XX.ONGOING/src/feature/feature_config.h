#pragma once

#include "accelerometer/acc_init.h"
#include "gyroscope/gyro_init.h"

const struct gyro_config_hat gyro_config = {
    .precision = 0,
};

const struct acc_config_hat acc_config = {
    .precision = 0,
};
