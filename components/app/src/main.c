#include <stdio.h>
#include "gpio.h"

int main()
{

#if REAL_MCU
    // currently not a specific one
    GPIO_Init();
    LED_Init();
#endif

    printf("Hello world!\n");
    return 0;
}