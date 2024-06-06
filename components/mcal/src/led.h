#ifndef LED_H
#define LED_H

#include <stdint.h>

extern void LED_Init(void);

extern int32_t LED_Set(const uint32_t address);

#endif /* LED_H */