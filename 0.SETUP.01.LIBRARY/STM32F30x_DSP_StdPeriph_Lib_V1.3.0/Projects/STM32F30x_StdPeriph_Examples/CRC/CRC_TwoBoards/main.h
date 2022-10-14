/**
  ******************************************************************************
  * @file    CRC/CRC_TwoBoards/main.h 
  * @author  MCD Application Team
  * @version V1.1.3
  * @date    14-December-2021
  * @brief   Header for main.c module
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
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x.h"
#include "stm32303c_eval.h"

/* Exported typedef ----------------------------------------------------------*/
#define countof(a)   (sizeof(a) / sizeof(*(a)))

/* Exported define -----------------------------------------------------------*/

/* Uncomment the line below if you will use the TRANSMITTER mode */
// #define MODE_TRANSMITTER  
/* Uncomment the line below if you will use the RECIVER mode */
#define MODE_RECEIVER

/* USART Communication boards Interface */
#define USARTx                           USART1
#define USARTx_CLK                       RCC_APB2Periph_USART1
#define USARTx_APBPERIPHCLOCK            RCC_APB2PeriphClockCmd
#define USARTx_IRQn                      USART1_IRQn
#define USARTx_IRQHandler                USART1_IRQHandler

#define USARTx_TX_PIN                    GPIO_Pin_4                
#define USARTx_TX_GPIO_PORT              GPIOC                       
#define USARTx_TX_GPIO_CLK               RCC_AHBPeriph_GPIOC
#define USARTx_TX_SOURCE                 GPIO_PinSource4
#define USARTx_TX_AF                     GPIO_AF_7

#define USARTx_RX_PIN                    GPIO_Pin_1               
#define USARTx_RX_GPIO_PORT              GPIOE                    
#define USARTx_RX_GPIO_CLK               RCC_AHBPeriph_GPIOE
#define USARTx_RX_SOURCE                 GPIO_PinSource1
#define USARTx_RX_AF                     GPIO_AF_7

#define TXBUFFERSIZE                     (countof(TxBuffer) - 1)
#define RXBUFFERSIZE                     TXBUFFERSIZE + 1 

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

