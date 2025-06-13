#include "unity.h"

#include "mylib.h"

void test_plus(void)
{
    int32_t res = MYLIB_plus(10, 5);
    TEST_ASSERT(res == 15);
}

void test_minus(void)
{
    int32_t res = MYLIB_minus(10, 5);
    TEST_ASSERT(res == 5);
}