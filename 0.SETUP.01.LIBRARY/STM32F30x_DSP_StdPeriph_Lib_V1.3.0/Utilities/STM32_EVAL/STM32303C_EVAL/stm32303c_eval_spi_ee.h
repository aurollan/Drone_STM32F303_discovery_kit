/**
  ******************************************************************************
  * @file    stm32303c_eval_spi_ee.h
  * @author  MCD Application Team
  * @version V1.0.4
  * @date    15-December-2021
  * @brief   This file contains all the functions prototypes for the stm32303c_eval_spi_ee
  *          firmware driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2014 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32303C_EVAL_SPI_EE_H
#define __STM32303C_EVAL_SPI_EE_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32303c_eval.h"

/** @addtogroup Utilities
  * @{
  */
  
/** @addtogroup STM32_EVAL
  * @{
  */ 

/** @addtogroup STM32303C_EVAL
  * @{
  */
  
/** @addtogroup STM32303C_EVAL_SPI_EE
  * @{
  */  

/** @defgroup STM32303C_EVAL_SPI_EEPROM_Exported_Types
  * @{
  */ 
/**
  * @}
  */
  
/** @defgroup STM32303C_EVAL_SPI_EEPROM_Exported_Constants
  * @{
  */
/**
  * @brief  M95 SPI EEPROM supported commands
  */  
#define sEE_CMD_WREN           0x06  /*!< Write enable instruction */
#define sEE_CMD_WRDI           0x04  /*!< Write disable instruction */
#define sEE_CMD_RDSR           0x05  /*!< Read Status Register instruction  */
#define sEE_CMD_WRSR           0x01  /*!< Write Status Register instruction */
#define sEE_CMD_WRITE          0x02  /*!< Write to Memory instruction */
#define sEE_CMD_READ           0x03  /*!< Read from Memory instruction */

/**
 * @brief  M95M01 SPI EEPROM defines
 */  
#define sEE_WIP_FLAG           0x01  /*!< Write In Progress (WIP) flag */

#define sEE_DUMMY_BYTE         0xA5

#define sEE_PAGESIZE           256


  
/**
  * @}
  */ 
  
/** @defgroup STM32303C_EVAL_SPI_EEPROM_Exported_Macros
  * @{
  */
/**
  * @brief  Select EEPROM: Chip Select pin low
  */
#define sEE_CS_LOW()       GPIO_ResetBits(sEE_SPI_CS_GPIO_PORT, sEE_SPI_CS_PIN)
/**
  * @brief  Deselect EEPROM: Chip Select pin high
  */
#define sEE_CS_HIGH()      GPIO_SetBits(sEE_SPI_CS_GPIO_PORT, sEE_SPI_CS_PIN)   
/**
  * @}
  */ 
  


/** @defgroup STM32303C_EVAL_SPI_EEPROM_Exported_Functions
  * @{
  */
/**
  * @brief  High layer functions
  */
void     sEE_DeInit(void);
void     sEE_Init(void);
uint32_t sEE_ReadBuffer(uint8_t* pBuffer, uint16_t ReadAddr, uint16_t* NumByteToRead);
void     sEE_WriteBuffer(uint8_t* pBuffer, uint16_t WriteAddr, uint16_t NumByteToWrite);
uint32_t sEE_WritePage(uint8_t* pBuffer, uint16_t WriteAddr, uint16_t* NumByteToWrite);
uint32_t sEE_WaitEepromStandbyState(void);

/**
  * @brief  Low layer functions
  */
uint8_t sEE_ReadByte(void);
uint8_t sEE_SendByte(uint8_t byte);
void sEE_WriteEnable(void);
void sEE_WriteDisable(void);
void sEE_WriteStatusRegister(uint8_t regval);
uint8_t sEE_ReadStatusRegister(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32303C_EVAL_SPI_EE_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */  

