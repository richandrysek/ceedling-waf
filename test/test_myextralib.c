#include "unity.h"

#include "myextralib.h"

#include "mock_mylib.h"

void setUp(void)
{
    mock_mylib_Init();
}

void tearDown(void)
{
    mock_mylib_Verify();
}

void test_func(void)
{
    MYLIB_plus_ExpectAndReturn(5, 10, 15);
    MYLIB_minus_ExpectAndReturn(5, 10, -5);
    int32_t res = MYEXTRALIB_func(5, 10);
    TEST_ASSERT_EQUAL(-75, res);
}