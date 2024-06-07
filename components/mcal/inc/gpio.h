#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "mcux_reg.h"

typedef enum GPIO_Mode_ {
    GPIO_MODE_DO,
    GPIO_MODE_DI
} GPIO_Mode;

extern void GPIO_Init(void);
extern int32_t GPIO_Config(GPIO * const pGpio, const uint32_t pin, const GPIO_Mode mode);
extern int32_t GPIO_SetPin(GPIO * const pGpio, const uint32_t pin, const bool high);

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
