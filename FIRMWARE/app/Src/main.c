#include "stm32f401xx.h"
#include "core/system.h"


// Function delay
void delay_cycles(uint32_t cycles)
{
    while (cycles-- > 0) {
        __asm("NOP"); // No operation for delay
    }
}

int main(void)
 {
    system_setup();
    gpio_setup();

    uint64_t start_time = system_get_ticks();

    while (1)
    {
        if((system_get_ticks() - start_time) >= 1000)
        {
            GPIO_ToggleOutputPin(LED_PORT, LED_PIN);
            start_time = system_get_ticks();
        }

    }
}