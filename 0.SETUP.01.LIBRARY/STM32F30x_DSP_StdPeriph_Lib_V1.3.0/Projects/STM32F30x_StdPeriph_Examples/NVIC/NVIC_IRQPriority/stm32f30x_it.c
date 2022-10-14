/**
  ******************************************************************************
  * @file    NVIC/NVIC_IRQPriority/stm32f30x_it.c 
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

/** @addtogroup NVIC_IRQPriority
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern __IO uint8_t PreemptionOccured;
extern __IO uint8_t PreemptionPriorityValue; 

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
  /* If the SEL_BUTTON_EXTI IRQ Handler (EXTI15_10_IRQHandler) was preempted
     by SysTick Handler */
  if(NVIC_GetActive(SEL_BUTTON_EXTI_IRQn) != 0)
  {
    PreemptionOccured = 1;
  }
}

/******************************************************************************/
/*                 STM32F30x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f30x.s).                                            */
/******************************************************************************/

/**
    * @brief  This function handles EXTI Lines 9 to 5 interrupts requests.
  * @param  None
  * @retval None
  */
void EXTI9_5_IRQHandler(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  if(EXTI_GetITStatus(KEY_BUTTON_EXTI_LINE) != RESET)
  {
    PreemptionPriorityValue = !PreemptionPriorityValue;
    PreemptionOccured = 0;

    /* Modify the SEL_BUTTON_EXTI_IRQn Interrupt Preemption Priority */
    NVIC_InitStructure.NVIC_IRQChannel = SEL_BUTTON_EXTI_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = PreemptionPriorityValue;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    /* Configure the SysTick Handler Priority: Preemption priority and subpriority */
    NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), !PreemptionPriorityValue, 0));    

    /* Clear KEY_BUTTON_EXTI_LINE pending bit */
    EXTI_ClearITPendingBit(KEY_BUTTON_EXTI_LINE);
  }
}

/**
  * @brief  This function handles EXTI Lines 15 to 10 interrupts requests.
  * @param  None
  * @retval None
  */
void EXTI15_10_IRQHandler(void)
{
  /* Generate SysTick exception */
  SCB->ICSR |= 0x04000000;
  
  /* Clear SEL_BUTTON_EXTI_LINE pending bit */
  EXTI_ClearITPendingBit(SEL_BUTTON_EXTI_LINE);
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


