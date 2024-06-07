#ifndef LED_H
#define LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

typedef enum LED_Id_ {
    LED_ID_RED,
    LED_ID_GREEN,
    LED_ID_ORANGE
} LED_Id;

extern void LED_Init(void);
extern int32_t LED_Set(const LED_Id id, bool on);

#ifdef __cplusplus
}
#endif

#endif /* LED_H */