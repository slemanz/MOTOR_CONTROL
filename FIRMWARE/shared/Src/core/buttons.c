#include "core/buttons.h"

void buttons_init(void)
{
	GPIO_Handle_t buttonPin;

	buttonPin.pGPIOx = BUTTON_GPIO_PORT;
	buttonPin.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	buttonPin.GPIO_PinConfig.GPIO_PinNumber = BUTTON_GPIO_1;
	buttonPin.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	buttonPin.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	buttonPin.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_Init(&buttonPin);

	buttonPin.GPIO_PinConfig.GPIO_PinNumber = BUTTON_GPIO_2;
	GPIO_Init(&buttonPin);

	buttonPin.GPIO_PinConfig.GPIO_PinNumber = BUTTON_GPIO_3;
	GPIO_Init(&buttonPin);

	buttonPin.GPIO_PinConfig.GPIO_PinNumber = BUTTON_GPIO_4;
	GPIO_Init(&buttonPin);
}

uint8_t buttons_read(void)
{
    uint8_t state = 0x00;

    if(GPIO_ReadFromInputPin(BUTTON_GPIO_PORT, BUTTON_GPIO_1) == GPIO_PIN_RESET) state |= (1 << 0);
    if(GPIO_ReadFromInputPin(BUTTON_GPIO_PORT, BUTTON_GPIO_2) == GPIO_PIN_RESET) state |= (1 << 1);
    if(GPIO_ReadFromInputPin(BUTTON_GPIO_PORT, BUTTON_GPIO_3) == GPIO_PIN_RESET) state |= (1 << 2);
    if(GPIO_ReadFromInputPin(BUTTON_GPIO_PORT, BUTTON_GPIO_4) == GPIO_PIN_RESET) state |= (1 << 3);

    for(uint32_t i = 0; i < 10000; i++) __asm("NOP");
    return state;
}