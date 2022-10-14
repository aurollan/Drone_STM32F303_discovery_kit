/**
  ******************************************************************************
  * @file    I2C/I2C_TSENSOR/stm32f30x_it.c 
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

/** @addtogroup I2C_TSENSOR
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern __IO uint32_t SMbusAlertOccurred;

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
/*  file (startup_stm32f30x.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles I2C2 Error interrupt request.
  * @param  None
  * @retval None
  */
void I2C2_ER_IRQHandler(void)
{
  /* Check on I2C2 Time out flag and clear it */
  if (I2C_GetITStatus(I2C2, I2C_IT_TIMEOUT))
  {
    I2C_ClearITPendingBit(I2C2, I2C_IT_TIMEOUT);
  }
  
  /* Check on I2C2 Arbitration Lost flag and clear it */
  if (I2C_GetITStatus(I2C2, I2C_IT_ARLO))
  {
    I2C_ClearITPendingBit(I2C2, I2C_IT_ARLO);
  }

  /* Check on I2C2 PEC error flag and clear it */
  if (I2C_GetITStatus(I2C2, I2C_IT_PECERR))
  {
    I2C_ClearITPendingBit(I2C2, I2C_IT_PECERR);
  }
  
  /* Check on I2C2 Overrun/Underrun error flag and clear it */
  if (I2C_GetITStatus(I2C2, I2C_IT_OVR))
  {
    I2C_ClearITPendingBit(I2C2, I2C_IT_OVR);
  }

  /* Check on I2C2 Bus error flag and clear it */
  if (I2C_GetITStatus(I2C2, I2C_IT_BERR))
  {
    I2C_ClearITPendingBit(I2C2, I2C_IT_BERR);
  }
  /* Check on I2C2 SMBALERT flag and clear it */
  if (I2C_GetITStatus(I2C2, I2C_IT_ALERT))
  {
    I2C_ClearITPendingBit(I2C2, I2C_IT_ALERT);
    SMbusAlertOccurred++;
  } 
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

