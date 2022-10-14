/**
  ******************************************************************************
  * @file    I2S/I2S_FullDuplexDataExchangeIT/stm32f30x_it.c 
  * @author  MCD Application Team
  * @version V1.1.3
  * @date    14-December-2021
  * @brief   Main Interrupt Service Routines.
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

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_it.h"

/** @addtogroup STM32F30x_StdPeriph_Examples
  * @{
  */
  
/** @addtogroup I2S_FullDuplexDataExchangeIT
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern const uint16_t I2S_Buffer_Tx[32];
extern __IO uint32_t TxIdx, RxIdx, I2SextRxIdx, I2SextTxIdx;
extern uint16_t I2S_Buffer_Rx[32], I2Sext_Buffer_Rx[32];
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F30x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f30x.s).                                            */
/******************************************************************************/
/**
  * @brief  This function handles SPI global interrupt request
  * @param  None
  * @retval : None
  */
void SPI_IRQHandler(void)
{ 
  static uint32_t spitmpreg = 0x00, i2stmpreg = 0x00;
  
  spitmpreg = SPI->SR;
  i2stmpreg = I2Sext->SR;
  
#ifdef I2S_SLAVE_FULL_DUPLEX  
  if ((spitmpreg&0x01)==0x01)
  {
    I2S_Buffer_Rx[RxIdx++] = SPI_I2S_ReceiveData16(SPI3);

    /* Disable the Interrupt when transfer is complete */ 
    if(RxIdx == 32)
    {
      /* Disable the I2S RXNE Interrupt */
      SPI_I2S_ITConfig(SPI, SPI_I2S_IT_RXNE, DISABLE);
    } 
  }
  
  if((i2stmpreg&0x02)==0x02)
  {
    SPI_I2S_SendData16(I2Sext, I2S_Buffer_Tx[I2SextTxIdx++]);
    
    if(I2SextTxIdx == 32)
    {    
      /* Disable the I2S1 TXE Interrupt */
      SPI_I2S_ITConfig(I2Sext, SPI_I2S_IT_TXE, DISABLE);
    }
  }
#endif /* I2S_SLAVE_FULL_DUPLEX */ 
 
#ifdef I2S_MASTER_FULL_DUPLEX

  if ((i2stmpreg&0x01)==0x01)
  {
    I2Sext_Buffer_Rx[I2SextRxIdx++] = SPI_I2S_ReceiveData16(I2S3ext);
    if(I2SextRxIdx == 32)
    {    
      /* Disable the I2S1 TXE Interrupt */
      SPI_I2S_ITConfig(I2Sext, SPI_I2S_IT_RXNE, DISABLE); 
    }
  }
  
  if((spitmpreg&0x02)==0x02)
  {
    SPI_I2S_SendData16(SPI, I2S_Buffer_Tx[TxIdx++]);
    /* Disable the Interrupt when transfer is complete */ 
    if(TxIdx == 32)
    {    
      /* Disable the I2S TXE Interrupt */
      SPI_I2S_ITConfig(SPI, SPI_I2S_IT_TXE, DISABLE); 
    }
  } 
#endif /* I2S_MASTER_FULL_DUPLEX */
  
}
/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

/**
  * @}
  */ 
  
