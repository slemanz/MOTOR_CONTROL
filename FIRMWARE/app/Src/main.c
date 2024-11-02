#include "stm32f401xx.h"
#include "core/system.h"
#include "core/lcd.h"
#include "core/buttons.h"


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
    buttons_init();
    lcd_init();
    lcd_display_clear();
    lcd_display_return_home();
    lcd_print_string((char*)"Iniciando...\0");
    delay_cycles(4000000);

    uint64_t start_time = system_get_ticks();
    uint8_t buttonState = 0x00;

    while (1)
    {
        if((system_get_ticks() - start_time) >= 1000)
        {
            GPIO_ToggleOutputPin(LED_PORT, LED_PIN);
            start_time = system_get_ticks();
        }

        buttonState = buttons_read();
        if(buttonState & (1 << 3))
        {
            
            lcd_display_clear();
            lcd_set_cursor(1, 1);
            lcd_print_string((char*)"Button 4 pressed\0");

            while(buttons_read() & (1 << 3)) __asm("NOP");
        }

        if(buttonState & (1 << 2))
        {
            
            lcd_display_clear();
            lcd_set_cursor(1, 1);
            lcd_print_string((char*)"Button 3 pressed\0");

            while(buttons_read() & (1 << 2)) __asm("NOP");
        }

        if(buttonState & (1 << 1))
        {
            
            lcd_display_clear();
            lcd_set_cursor(1, 1);
            lcd_print_string((char*)"Button 2 pressed\0");

            while(buttons_read() & (1 << 1)) __asm("NOP");
        }

        if(buttonState & (1 << 0))
        {
            
            lcd_display_clear();
            lcd_set_cursor(1, 1);
            lcd_print_string((char*)"Button 1 pressed\0");

            while(buttons_read() & (1 << 0)) __asm("NOP");
        }

        lcd_display_clear();

    }
}