/**
  ******************************************************************************
  * @file    CAN/CAN_FIFOExtension/stm32f30x_it.c 
  * @author  MCD Application Team
  * @version V1.1.3
  * @date    14-December-2021
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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

/** @addtogroup CAN_FIFOExtension
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern CAN_FilterInitTypeDef  CAN_FilterInitStructure;
__IO uint8_t MsgReceived = 0;
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
/******************************************************************************/
/**
  * @brief  This function handles CAN1 RX0 request.
* @param  None
* @retval None
*/
void USB_LP_CAN1_RX0_IRQHandler(void)
{
 if(CAN_GetFlagStatus(CAN1,CAN_FLAG_FF0) != RESET)
  { 
     /* Clears the CAN1 interrupt pending bit */
    CAN_ClearITPendingBit(CANx, CAN_IT_FF0);
    
    /* CAN filter init "FIFO1 " */
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = 1;
    CAN_FilterInit(&CAN_FilterInitStructure);   
  }
}

/**
* @brief  This function handles CAN1 RX1 request.
* @param  None
* @retval None
*/
void CAN1_RX1_IRQHandler(void)
{ 
if(CAN_GetFlagStatus(CAN1,CAN_FLAG_FF1) != RESET)
  {     
    /* Clears the CAN1 interrupt pending bit */    
    CAN_ClearITPendingBit(CAN1,CAN_IT_FF1);
    
    /* CAN filter init "FIFO0" */
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment = 0;
    CAN_FilterInit(&CAN_FilterInitStructure); 

    MsgReceived = 1;
  }
}

/******************************************************************************/
/*                 STM32F30x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f30x.s).                                               */
/******************************************************************************/

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

