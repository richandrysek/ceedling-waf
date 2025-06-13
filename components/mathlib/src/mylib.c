#include "mylib.h"
#include <stddef.h>

int32_t MYLIB_plus(const int32_t a, const int32_t b)
{
    return a + b;
}

int32_t MYLIB_minus(const int32_t a, const int32_t b)
{
    return a - b;
}

int32_t MYLIB_plusEx(const int32_t a, const int32_t b, int32_t * value)
{
    int32_t result = -1;

    if(value != NULL) {
        *value = a + b;
        result = 0;
    }

    return result;
}