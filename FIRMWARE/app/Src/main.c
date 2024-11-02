#include "stm32f401xx.h"
#include "core/system.h"
#include "core/lcd.h"


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
    lcd_init();
    lcd_set_cursor(1 , 1);
    delay_cycles(4000000);
    lcd_print_char('A');
    delay_cycles(4000000);
    lcd_display_clear();
    lcd_display_return_home();
    delay_cycles(4000000);
    lcd_print_string((char*)"Sabadou!\0");

    while(1) __asm("NOP");

    uint64_t start_time = system_get_ticks();

    while (1)
    {
        if((system_get_ticks() - start_time) >= 1000)
        {
            GPIO_ToggleOutputPin(LED_PORT, LED_PIN);
            lcd_print_char('b');
            start_time = system_get_ticks();
        }

    }
}