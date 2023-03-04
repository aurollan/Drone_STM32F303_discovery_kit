#include "mcu/stm32f4/setup_uart/setup_uart.h"
#include "mcu/stm32f4/setup_dma/setup_dma.h"
#include "mcu/stm32f4/setup_uart/setup_uart.h"
#include "mcu/stm32f4/setup_clock/setup_clock.h"
#include "mcu/stm32f4/setup_pwm/setup_pwm.h"



void    init_mcu(void)
{
    pwm_initialize();
    clock_initialize();
    setup_DMA();
    uart_initialize();
    return ;
}
