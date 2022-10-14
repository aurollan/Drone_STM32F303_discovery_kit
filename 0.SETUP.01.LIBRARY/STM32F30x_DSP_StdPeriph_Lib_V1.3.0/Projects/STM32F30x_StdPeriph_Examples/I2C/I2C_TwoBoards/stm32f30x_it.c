/**
  ******************************************************************************
  * @file    I2C/I2C_TwoBoards/stm32f30x_it.c 
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

/** @addtogroup I2C_TwoBoards
  * @{
  */
  
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern __IO uint32_t ActionState, RecieverMode;

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

/******************************************************************************/
/*                 STM32F30x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f30x.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles EXTI0 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI9_5_IRQHandler(void)
{
  /* Check if the LEFT push button has been pushed */
  if (EXTI_GetFlagStatus(LEFT_BUTTON_EXTI_LINE) != RESET)  
  {
    if ((ActionState == ACTION_NONE) && (RecieverMode == STATE_OFF))
    {
      ActionState = BUTTON_LEFT;
    }    
    /* Clear the interrupt pending bit */
    EXTI_ClearITPendingBit(LEFT_BUTTON_EXTI_LINE);
  }
  /* Check if the RIGHT push button has been pushed */
  else if (EXTI_GetFlagStatus(RIGHT_BUTTON_EXTI_LINE) != RESET)  
  {
    if ((ActionState == ACTION_NONE) && (RecieverMode == STATE_OFF))
    {
      ActionState = BUTTON_RIGHT;
    }    
    /* Clear the interrupt pending bit */
    EXTI_ClearITPendingBit(RIGHT_BUTTON_EXTI_LINE);
  }
}
 
/**
  * @brief  This function handles TIM6 global interrupt request.
  * @param  None
  * @retval None
  */
void TIM6_DAC_IRQHandler(void)  
{
  if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET)
  {    
    STM_EVAL_LEDToggle(LED1);
    STM_EVAL_LEDToggle(LED4);
    
    TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
  } 
}

/**
  * @brief  This function handles TIM7 global interrupt request.
  * @param  None
  * @retval None
  */
void TIM7_IRQHandler(void)
{
  if (TIM_GetITStatus(TIM7, TIM_IT_Update) != RESET)
  {    
    if ((ActionState == ACTION_NONE) && (RecieverMode == STATE_OFF))
    {
      ActionState =  ACTION_PERIODIC ;
    }
    
    /* Clear Timer interrupt pending bit */
    TIM_ClearITPendingBit(TIM7, TIM_IT_Update);
    
    /* Clear Key Button Interrupt pending bit */
    EXTI_ClearITPendingBit(KEY_BUTTON_EXTI_LINE);
    EXTI_ClearFlag(KEY_BUTTON_EXTI_LINE); 
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
  

