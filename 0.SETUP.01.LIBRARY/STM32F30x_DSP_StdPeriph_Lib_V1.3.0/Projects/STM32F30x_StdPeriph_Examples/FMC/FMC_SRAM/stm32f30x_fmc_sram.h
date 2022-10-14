/**
  ******************************************************************************
  * @file    stm32f30x_fmc_sram.h
  * @author  MCD Application Team
  * @version V1.1.3
  * @date    14-December-2021
  * @brief   This file contains all the functions prototypes for the 
  *          stm32f30x_fmc_sram firmware driver.
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
#ifndef __STM32F30X_FMC_SRAM_H
#define __STM32F30X_FMC_SRAM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x.h"

/* Exported types ------------------------------------------------------------*/
/* Exported defines ----------------------------------------------------------*/
/**
  * @brief  FMC SRAM bank address
  */   
#define SRAM_BANK_ADDR  ((uint32_t)0x68000000)  
  
/**
  * @brief  FMC SRAM Memory Width
  */  
/* #define SRAM_MEMORY_WIDTH    FMC_NORSRAM_MemoryDataWidth_8b  */
#define SRAM_MEMORY_WIDTH    FMC_NORSRAM_MemoryDataWidth_16b

/**
  * @brief  FMC SRAM Burst Access mode
  */  
#define SRAM_BURSTACCESS    FMC_BurstAccessMode_Disable  
/* #define SRAM_BURSTACCESS    FMC_BurstAccessMode_Enable*/

/**
  * @brief  FMC SRAM Write Burst feature
  */  
#define SRAM_WRITEBURST    FMC_WriteBurst_Disable  
/* #define SRAM_WRITEBURST   FMC_WriteBurst_Enable */

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void SRAM_Init(void);
void SRAM_WriteBuffer(uint16_t* pBuffer, uint32_t WriteAddr, uint32_t NumHalfwordToWrite);
void SRAM_ReadBuffer(uint16_t* pBuffer, uint32_t ReadAddr, uint32_t NumHalfwordToRead);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F30X_FMC_SRAM_H */

