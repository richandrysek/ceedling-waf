#include "myextralib.h"

#include "mylib.h"

int32_t MYEXTRALIB_func(const int32_t a, const int32_t b)
{
    return MYLIB_plus(a, b) * MYLIB_minus(a,b);
}

