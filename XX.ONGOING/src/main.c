#include "feature/demo_acc/demo_acc.h"
#include "feature/demo_gyr/demo_gyr.h"
#include "feature/demo_mag/demo_mag.h"
#include "mcu/init_mcu.h"
#include <stdint.h>

#define ABS(x) (x < 0) ? (-x) : x
RCC_ClocksTypeDef RCC_Clocks;
__IO uint32_t TimingDelay = 0;
__IO uint32_t UserButtonPressed = 0;
__IO float HeadingValue = 0.0f;
float MagBuffer[3] = {0.0f}, AccBuffer[3] = {0.0f}, Buffer[3] = {0.0f};
uint8_t Xval, Yval = 0x00;

__IO uint8_t DataReady = 0;
__IO uint8_t PrevXferComplete = 1;
__IO uint32_t USBConnectTimeOut = 100;

float fNormAcc, fSinRoll, fCosRoll, fSinPitch, fCosPitch = 0.0f, RollAng = 0.0f,
                                               PitchAng = 0.0f;
float fTiltedX, fTiltedY = 0.0f;

void assert_failed(uint8_t *file, uint32_t line) {
  (void)file;
  (void)line;
}

void Demo_led() {
  /* Waiting User Button is pressed */
  while (UserButtonPressed == 0x00) {
    /* Toggle LD3 */
    STM_EVAL_LEDToggle(LED3);
    /* Insert 50 ms delay */
    Delay(5);
    /* Toggle LD5 */
    STM_EVAL_LEDToggle(LED5);
    /* Insert 50 ms delay */
    Delay(5);
    /* Toggle LD7 */
    STM_EVAL_LEDToggle(LED7);
    /* Insert 50 ms delay */
    Delay(5);
    /* Toggle LD9 */
    STM_EVAL_LEDToggle(LED9);
    /* Insert 50 ms delay */
    Delay(5);
    /* Toggle LD10 */
    STM_EVAL_LEDToggle(LED10);
    /* Insert 50 ms delay */
    Delay(5);
    /* Toggle LD8 */
    STM_EVAL_LEDToggle(LED8);
    /* Insert 50 ms delay */
    Delay(5);
    /* Toggle LD6 */
    STM_EVAL_LEDToggle(LED6);
    /* Insert 50 ms delay */
    Delay(5);
    /* Toggle LD4 */
    STM_EVAL_LEDToggle(LED4);
    /* Insert 50 ms delay */
    Delay(5);
  }
}

void Demo_gyro() {
  /* Waiting User Button is pressed */
  while (UserButtonPressed == 0x01) {
    /* Wait for data ready */
    while (DataReady != 0x05) {
    }
    DataReady = 0x00;

    /* LEDs Off */
    STM_EVAL_LEDOff(LED3);
    STM_EVAL_LEDOff(LED6);
    STM_EVAL_LEDOff(LED7);
    STM_EVAL_LEDOff(LED4);
    STM_EVAL_LEDOff(LED10);
    STM_EVAL_LEDOff(LED8);
    STM_EVAL_LEDOff(LED9);
    STM_EVAL_LEDOff(LED5);

    /* Read Gyro Angular data */
    Demo_GyroReadAngRate(Buffer);

    /* Update autoreload and capture compare registers value*/
    Xval = ABS((int8_t)(Buffer[0]));
    Yval = ABS((int8_t)(Buffer[1]));

    if (Xval > Yval) {
      if ((int8_t)Buffer[0] > 5.0f) {
        /* LD10 On */
        STM_EVAL_LEDOn(LED10);
      }
      if ((int8_t)Buffer[0] < -5.0f) {
        /* LD3 On */
        STM_EVAL_LEDOn(LED3);
      }
    } else {
      if ((int8_t)Buffer[1] < -5.0f) {
        /* LD6 on */
        STM_EVAL_LEDOn(LED6);
      }
      if ((int8_t)Buffer[1] > 5.0f) {
        /* LD7 On */
        STM_EVAL_LEDOn(LED7);
      }
    }
    DataReady = 0x00;
  }
}

void Demo_compass(void) {
  uint8_t i = 0;
  /* Waiting User Button is pressed */
  while (UserButtonPressed == 0x02) {
    /* Wait for data ready */
    while (DataReady != 0x05) {
    }
    DataReady = 0x00;

    /* Read Compass data */
    Demo_CompassReadMag(MagBuffer);
    Demo_CompassReadAcc(AccBuffer);

    for (i = 0; i < 3; i++)
      AccBuffer[i] /= 100.0f;

    fNormAcc =
        sqrt((AccBuffer[0] * AccBuffer[0]) + (AccBuffer[1] * AccBuffer[1]) +
             (AccBuffer[2] * AccBuffer[2]));

    fSinRoll = -AccBuffer[1] / fNormAcc;
    fCosRoll = sqrt(1.0 - (fSinRoll * fSinRoll));
    fSinPitch = AccBuffer[0] / fNormAcc;
    fCosPitch = sqrt(1.0 - (fSinPitch * fSinPitch));
    if (fSinRoll > 0) {
      if (fCosRoll > 0) {
        RollAng = acos(fCosRoll) * 180 / PI;
      } else {
        RollAng = acos(fCosRoll) * 180 / PI + 180;
      }
    } else {
      if (fCosRoll > 0) {
        RollAng = acos(fCosRoll) * 180 / PI + 360;
      } else {
        RollAng = acos(fCosRoll) * 180 / PI + 180;
      }
    }

    if (fSinPitch > 0) {
      if (fCosPitch > 0) {
        PitchAng = acos(fCosPitch) * 180 / PI;
      } else {
        PitchAng = acos(fCosPitch) * 180 / PI + 180;
      }
    } else {
      if (fCosPitch > 0) {
        PitchAng = acos(fCosPitch) * 180 / PI + 360;
      } else {
        PitchAng = acos(fCosPitch) * 180 / PI + 180;
      }
    }

    if (RollAng >= 360) {
      RollAng = RollAng - 360;
    }

    if (PitchAng >= 360) {
      PitchAng = PitchAng - 360;
    }

    fTiltedX = MagBuffer[0] * fCosPitch + MagBuffer[2] * fSinPitch;
    fTiltedY = MagBuffer[0] * fSinRoll * fSinPitch + MagBuffer[1] * fCosRoll -
               MagBuffer[1] * fSinRoll * fCosPitch;

    HeadingValue =
        (float)((atan2f((float)fTiltedY, (float)fTiltedX)) * 180) / PI;

    if (HeadingValue < 0) {
      HeadingValue = HeadingValue + 360;
    }

    if ((RollAng <= 40.0f) && (PitchAng <= 40.0f)) {
      if (((HeadingValue < 25.0f) && (HeadingValue >= 0.0f)) ||
          ((HeadingValue >= 340.0f) && (HeadingValue <= 360.0f))) {
        STM_EVAL_LEDOn(LED10);
        STM_EVAL_LEDOff(LED3);
        STM_EVAL_LEDOff(LED6);
        STM_EVAL_LEDOff(LED7);
        STM_EVAL_LEDOff(LED4);
        STM_EVAL_LEDOff(LED8);
        STM_EVAL_LEDOff(LED9);
        STM_EVAL_LEDOff(LED5);
      } else if ((HeadingValue < 70.0f) && (HeadingValue >= 25.0f)) {
        STM_EVAL_LEDOn(LED9);
        STM_EVAL_LEDOff(LED6);
        STM_EVAL_LEDOff(LED10);
        STM_EVAL_LEDOff(LED3);
        STM_EVAL_LEDOff(LED8);
        STM_EVAL_LEDOff(LED5);
        STM_EVAL_LEDOff(LED4);
        STM_EVAL_LEDOff(LED7);
      } else if ((HeadingValue < 115.0f) && (HeadingValue >= 70.0f)) {
        STM_EVAL_LEDOn(LED7);
        STM_EVAL_LEDOff(LED3);
        STM_EVAL_LEDOff(LED4);
        STM_EVAL_LEDOff(LED9);
        STM_EVAL_LEDOff(LED10);
        STM_EVAL_LEDOff(LED8);
        STM_EVAL_LEDOff(LED6);
        STM_EVAL_LEDOff(LED5);
      } else if ((HeadingValue < 160.0f) && (HeadingValue >= 115.0f)) {
        STM_EVAL_LEDOn(LED5);
        STM_EVAL_LEDOff(LED6);
        STM_EVAL_LEDOff(LED10);
        STM_EVAL_LEDOff(LED8);
        STM_EVAL_LEDOff(LED9);
        STM_EVAL_LEDOff(LED7);
        STM_EVAL_LEDOff(LED4);
        STM_EVAL_LEDOff(LED3);
      } else if ((HeadingValue < 205.0f) && (HeadingValue >= 160.0f)) {
        STM_EVAL_LEDOn(LED3);
        STM_EVAL_LEDOff(LED6);
        STM_EVAL_LEDOff(LED4);
        STM_EVAL_LEDOff(LED8);
        STM_EVAL_LEDOff(LED9);
        STM_EVAL_LEDOff(LED5);
        STM_EVAL_LEDOff(LED10);
        STM_EVAL_LEDOff(LED7);
      } else if ((HeadingValue < 250.0f) && (HeadingValue >= 205.0f)) {
        STM_EVAL_LEDOn(LED4);
        STM_EVAL_LEDOff(LED6);
        STM_EVAL_LEDOff(LED10);
        STM_EVAL_LEDOff(LED8);
        STM_EVAL_LEDOff(LED9);
        STM_EVAL_LEDOff(LED5);
        STM_EVAL_LEDOff(LED3);
        STM_EVAL_LEDOff(LED7);
      } else if ((HeadingValue < 295.0f) && (HeadingValue >= 250.0f)) {
        STM_EVAL_LEDOn(LED6);
        STM_EVAL_LEDOff(LED9);
        STM_EVAL_LEDOff(LED10);
        STM_EVAL_LEDOff(LED8);
        STM_EVAL_LEDOff(LED3);
        STM_EVAL_LEDOff(LED5);
        STM_EVAL_LEDOff(LED4);
        STM_EVAL_LEDOff(LED7);
      } else if ((HeadingValue < 340.0f) && (HeadingValue >= 295.0f)) {
        STM_EVAL_LEDOn(LED8);
        STM_EVAL_LEDOff(LED6);
        STM_EVAL_LEDOff(LED10);
        STM_EVAL_LEDOff(LED7);
        STM_EVAL_LEDOff(LED9);
        STM_EVAL_LEDOff(LED3);
        STM_EVAL_LEDOff(LED4);
        STM_EVAL_LEDOff(LED5);
      }
    } else {
      /* Toggle All LEDs */
      STM_EVAL_LEDToggle(LED7);
      STM_EVAL_LEDToggle(LED6);
      STM_EVAL_LEDToggle(LED10);
      STM_EVAL_LEDToggle(LED8);
      STM_EVAL_LEDToggle(LED9);
      STM_EVAL_LEDToggle(LED3);
      STM_EVAL_LEDToggle(LED4);
      STM_EVAL_LEDToggle(LED5);
      /* Delay 50ms */
      Delay(5);
    }
  }
}

int main(void) {
  init_mcu();
  Demo_GyroConfig();
  Demo_CompassConfig();
  Set_System();
  /* LEDs Off */
  STM_EVAL_LEDOff(LED3);
  STM_EVAL_LEDOff(LED6);
  STM_EVAL_LEDOff(LED7);
  STM_EVAL_LEDOff(LED4);
  STM_EVAL_LEDOff(LED10);
  STM_EVAL_LEDOff(LED8);
  STM_EVAL_LEDOff(LED9);
  STM_EVAL_LEDOff(LED5);
  while (1)
    ;
  return (0);
}
