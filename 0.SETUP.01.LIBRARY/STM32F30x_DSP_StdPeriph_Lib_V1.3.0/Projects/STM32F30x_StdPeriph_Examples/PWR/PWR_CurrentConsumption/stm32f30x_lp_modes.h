/**
  ******************************************************************************
  * @file    PWR/PWR_CurrentConsumption/stm32f30x_lp_modes.h
  * @author  MCD Application Team
  * @version V1.1.3
  * @date    14-December-2021
  * @brief   Header for stm32f30x_lp_modes.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2015 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F30x_LP_MODES_H
#define __STM32F30x_LP_MODES_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#if !defined (SLEEP_MODE) && !defined (STOP_MODE) && !defined (STANDBY_MODE)\
 && !defined (STANDBY_RTC_MODE) 
/* Uncomment the corresponding line to select the STM32F30x Low Power mode */
#define SLEEP_MODE
/* #define STOP_MODE */
/* #define STANDBY_MODE */
/* #define STANDBY_RTC_MODE */
#endif

#if !defined (SLEEP_MODE) && !defined (STOP_MODE) && !defined (STANDBY_MODE)\
 && !defined (STANDBY_RTC_MODE)
 #error "Please select first the target STM32F30x Low Power mode to be measured (in stm32f30x_lp_modes.h file)"
#endif
   
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void SleepMode_Measure(void);
void StopMode_Measure(void);
void StandbyMode_Measure(void);
void StandbyRTCMode_Measure(void);

#endif /* __STM32F30x_LP_MODES_H */

