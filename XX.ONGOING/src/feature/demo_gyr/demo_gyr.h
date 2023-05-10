#pragma once

#define L3G_Sensitivity_250dps                                                 \
  (float)114.285f /*!< gyroscope sensitivity with 250 dps full scale [LSB/dps] \
                   */
#define L3G_Sensitivity_500dps                                                 \
  (float)57.1429f /*!< gyroscope sensitivity with 500 dps full scale [LSB/dps] \
                   */
#define L3G_Sensitivity_2000dps                                                \
  (float)14.285f /*!< gyroscope sensitivity with 2000 dps full scale [LSB/dps] \
                  */
#define PI (float)3.14159265f

void Demo_GyroConfig(void);
void Demo_GyroReadAngRate(float *pfData);
