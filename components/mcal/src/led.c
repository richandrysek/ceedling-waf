#include "led.h"
#include "gpio.h"

void LED_Init(void)
{
	GPIO_Set(0, 0);
}

int32_t LED_Set(const uint32_t address)
{
	return -1;
}