/**
  ******************************************************************************
  * @file    Lib_DEBUG/Lib_DEBUG_Example/stm32f30x_ip_dbg.h 
  * @author  MCD Application Team
  * @version V1.1.3
  * @date    14-December-2021
  * @brief   This file provides all STM32F30x peripherals pointers initialization.
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
#ifndef __STM32F30X_IP_DBG_H
#define __STM32F30X_IP_DBG_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define PERIPH_DEBUG

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void IP_Debug(void);
 
#endif /* __STM32F30X_IP_DBG_H */

