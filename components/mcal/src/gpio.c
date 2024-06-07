#include "gpio.h"

static inline bool GPIO_isValid(GPIO * const pGpio)
{
    return (pGpio == GPIOA);
}

void GPIO_Init(void)
{
    GPIOA->mode = 0u;
    GPIOA->state = 0u;
}

int32_t GPIO_Config(GPIO * const pGpio, const uint32_t pin, const GPIO_Mode mode)
{
    int32_t ret = -1;

    if(GPIO_isValid(pGpio))
    {
        uint8_t regVal = pGpio->mode;
        if(mode == GPIO_MODE_DO)
        {
            regVal &= (uint8_t)(~pin);
        }
        else 
        {
            regVal |= (uint8_t)(pin);
        }

        pGpio->mode = regVal;
        ret = 0;
    }

    return ret;
}

int32_t GPIO_SetPin(GPIO * const pGpio, const uint32_t pin, const bool high)
{
    int32_t ret = -1;

    if(GPIO_isValid(pGpio))
    {
        uint8_t regVal = pGpio->state;
        if(high)
        {
            regVal |= (uint8_t)(pin);
        }
        else 
        {
            regVal &= (uint8_t)(~pin);
        }

        pGpio->state = regVal;
        ret = 0;
    }

    return ret;
}
