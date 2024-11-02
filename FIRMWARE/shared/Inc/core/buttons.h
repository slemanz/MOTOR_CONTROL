#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "stm32f401xx.h"

void buttons_init(void);
uint8_t buttons_read(void);

#endif