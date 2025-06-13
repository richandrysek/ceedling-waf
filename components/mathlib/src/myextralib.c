#include "myextralib.h"

#include <stddef.h>
#include "mylib.h"

int32_t MYEXTRALIB_func(const int32_t a, const int32_t b)
{
    return MYLIB_plus(a, b) * MYLIB_minus(a,b);
}

int32_t MYEXTRALIB_funcEx(const int32_t a, const int32_t b, int32_t * value)
{
    int32_t result = -1;
    int32_t *plusValue = NULL;
    int32_t localValue = 0;


    if(value != NULL) {
        /* comment a following line to see NULL pointer test asserts.
           It simmulates a case, when in a code the pointer will be
           not set to an expected structure or memory address. */
        plusValue = &localValue;

        result = MYLIB_plusEx(a, b, plusValue);
        if(result == 0) {
            *value = *plusValue * MYLIB_minus(a,b);
        }
    }

    return result;
}