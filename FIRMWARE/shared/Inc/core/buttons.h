#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "stm32f401xx.h"

#define BUTTON_GPIO_PORT GPIOA

#define BUTTON_GPIO_1 GPIO_PIN_NO_0
#define BUTTON_GPIO_2 GPIO_PIN_NO_1
#define BUTTON_GPIO_3 GPIO_PIN_NO_2
#define BUTTON_GPIO_4 GPIO_PIN_NO_3

void buttons_init(void);
uint8_t buttons_read(void);

#endif