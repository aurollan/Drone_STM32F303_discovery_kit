#include "timer_hat.h"

#include "stm32f30x_rcc.h"
#include "stm32f30x_tim.h"

uint32_t timer_initialize(const struct timer_config_hat *const timer_config) {
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
  TIM_DeInit(TIM6);
  TIM_TimeBaseStructInit(&TIM_TimeBaseInitStruct);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

  /* 8 Mhz clock and we want to count us */
  TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInitStruct.TIM_Period = UINT32_MAX;
  /* 8 000 000  / (7 + 1) = 1 000 000 */
  TIM_TimeBaseInitStruct.TIM_Prescaler = 7;

  TIM_TimeBaseInit(TIM6, &TIM_TimeBaseInitStruct);

  TIM_Cmd(TIM6, ENABLE);
}
