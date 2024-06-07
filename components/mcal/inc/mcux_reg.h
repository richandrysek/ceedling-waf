
#ifndef MCUX_REG
#define MCUX_REG

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
    volatile uint8_t mode;
    volatile uint8_t state;
} GPIO;

#define GPIO_PIN0           ((uint8_t)0x01u)
#define GPIO_PIN1           ((uint8_t)0x02u)
#define GPIO_PIN2           ((uint8_t)0x04u)
#define GPIO_PIN3           ((uint8_t)0x08u)
#define GPIO_PIN4           ((uint8_t)0x10u)
#define GPIO_PIN5           ((uint8_t)0x20u)
#define GPIO_PIN6           ((uint8_t)0x40u)
#define GPIO_PIN7           ((uint8_t)0x80u)

#ifdef TEST
extern GPIO MCUX_GPIOA;

#define GPIOA_ADDR          &MCUX_GPIOA
#else
#define GPIOA_ADDR          0xF00F00A0u
#endif

#define GPIOA               ((GPIO *) GPIOA_ADDR)

#ifdef __cplusplus
}
#endif

#endif /* MCUX_REG */