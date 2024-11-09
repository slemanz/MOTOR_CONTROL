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

typedef enum state_t {
    State_Input,
    State_UpdateLcd,
    State_Start
} state_t;


int main(void)
 {
    system_setup();
    gpio_setup();
    buttons_init();
    lcd_init();
    lcd_display_clear();
    lcd_display_return_home();
    _printf1("Iniciando...");
    delay_cycles(4000000);

    uint64_t start_time = system_get_ticks();
    uint8_t buttonState = 0x00;
    uint8_t state = State_Input;
    uint8_t dir = 0;
    float step = 90.0;
    char fbuff[8] = {0};

    ftoa(step, fbuff, 1);

    lcd_display_clear();
    _printf1("Angulo: %s", fbuff);
    _printf2("Teste %d", dir);
    lcd_display_return_home();

    while (1)
    {
        switch (state)
        {
        case State_Input:
            buttonState = buttons_read();
            if(buttonState & (1 << 3))
            {
                dir = 4;
                state = State_UpdateLcd;
                while(buttons_read() & (1 << 3)) __asm("NOP");
            }

            if(buttonState & (1 << 2))
            {
                dir = 3;
                state = State_UpdateLcd;
                while(buttons_read() & (1 << 2)) __asm("NOP");
            }

            if(buttonState & (1 << 1))
            {
                if(step <= 0.0f)
                {
                    step = 0.0f;
                }else
                {
                    step = step - 1.8f;
                }
                state = State_UpdateLcd;
                while(buttons_read() & (1 << 1)) __asm("NOP");
            }

            if(buttonState & (1 << 0))
            {
                if(step >= 360.0f)
                {
                    step = 360.0f;
                }else
                {
                    step = step + 1.8f;
                }
                state = State_UpdateLcd;
                while(buttons_read() & (1 << 0)) __asm("NOP");
            }

            break;

        case State_UpdateLcd:
            lcd_display_clear();
            ftoa(step, fbuff, 1);
            _printf1("Angulo: %s", fbuff);
            _printf2("Teste %d", dir);
            lcd_display_return_home();
            state = State_Input;
        
        default:
            break;
        }

        if((system_get_ticks() - start_time) >= 1000)
        {
            GPIO_ToggleOutputPin(LED_PORT, LED_PIN);
            start_time = system_get_ticks();
        }


    }
}