#ifndef MYLIB_H

#include <stdint.h>

typedef int32_t Number;

int32_t MYLIB_plus(const int32_t a, const int32_t b);
int32_t MYLIB_minus(const int32_t a, const int32_t b);
int32_t MYLIB_divide(const int32_t a, const int32_t b);

int32_t MYLIB_plusEx(const int32_t a, const int32_t b, int32_t * value);
int32_t MYLIB_funcExB(const int32_t a, const int32_t b, int32_t * value, int32_t *bValue);

#endif