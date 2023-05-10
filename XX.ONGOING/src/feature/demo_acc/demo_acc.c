#include "demo_acc.h"
#include "stm32f3_discovery_lsm303dlhc.h"

#include <stdint.h>

/**
 * @brief Read LSM303DLHC output register, and calculate the acceleration
 * ACC=(1/SENSITIVITY)* (out_h*256+out_l)/16 (12 bit rappresentation)
 * @param pnData: pointer to float buffer where to store data
 * @retval None
 */
void Demo_CompassReadAcc(float *pfData) {
  int16_t pnRawData[3];
  uint8_t ctrlx[2];
  uint8_t buffer[6], cDivider;
  uint8_t i = 0;
  float LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_2g;

  /* Read the register content */
  LSM303DLHC_Read(ACC_I2C_ADDRESS, LSM303DLHC_CTRL_REG4_A, ctrlx, 2);
  LSM303DLHC_Read(ACC_I2C_ADDRESS, LSM303DLHC_OUT_X_L_A, buffer, 6);

  if (ctrlx[1] & 0x40)
    cDivider = 64;
  else
    cDivider = 16;

  /* check in the control register4 the data alignment*/
  if (!(ctrlx[0] & 0x40) ||
      (ctrlx[1] & 0x40)) /* Little Endian Mode or FIFO mode */
  {
    for (i = 0; i < 3; i++) {
      pnRawData[i] =
          ((int16_t)((uint16_t)buffer[2 * i + 1] << 8) + buffer[2 * i]) /
          cDivider;
    }
  } else /* Big Endian Mode */
  {
    for (i = 0; i < 3; i++)
      pnRawData[i] =
          ((int16_t)((uint16_t)buffer[2 * i] << 8) + buffer[2 * i + 1]) /
          cDivider;
  }
  /* Read the register content */
  LSM303DLHC_Read(ACC_I2C_ADDRESS, LSM303DLHC_CTRL_REG4_A, ctrlx, 2);

  if (ctrlx[1] & 0x40) {
    /* FIFO mode */
    LSM_Acc_Sensitivity = 0.25;
  } else {
    /* normal mode */
    /* switch the sensitivity value set in the CRTL4*/
    switch (ctrlx[0] & 0x30) {
    case LSM303DLHC_FULLSCALE_2G:
      LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_2g;
      break;
    case LSM303DLHC_FULLSCALE_4G:
      LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_4g;
      break;
    case LSM303DLHC_FULLSCALE_8G:
      LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_8g;
      break;
    case LSM303DLHC_FULLSCALE_16G:
      LSM_Acc_Sensitivity = LSM_Acc_Sensitivity_16g;
      break;
    }
  }

  /* Obtain the mg value for the three axis */
  for (i = 0; i < 3; i++) {
    pfData[i] = (float)pnRawData[i] / LSM_Acc_Sensitivity;
  }
}
