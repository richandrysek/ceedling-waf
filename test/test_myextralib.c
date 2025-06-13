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

void test_funcExt(void)
{
    int32_t value = 0;

    MYLIB_plusEx_ExpectAndReturn(5, 10, (int32_t*)0x56, 0);
    MYLIB_plusEx_IgnoreArg_value();
    int32_t plusValue = 15;
    MYLIB_plusEx_ReturnThruPtr_value(&plusValue);

     MYLIB_minus_ExpectAndReturn(5, 10, -5);


    int32_t res = MYEXTRALIB_funcEx(5, 10, &value);
    TEST_ASSERT_EQUAL(-75, value);
    TEST_ASSERT_EQUAL(0, res);
}

int32_t MYLIB_plusExCallback(const int32_t a, const int32_t b, int32_t * value, int cmock_num_calls)
{
    TEST_ASSERT_NOT_NULL(value);
    TEST_ASSERT_EQUAL(0, *value);
    if(cmock_num_calls < 1) {
        *value = a + b;
    } else {
        *value = 1;
    }
    return 0;
}

void test_funcExt2(void)
{
    int32_t value = 0;

    MYLIB_plusEx_StubWithCallback(MYLIB_plusExCallback);
    
    MYLIB_minus_ExpectAndReturn(5, 10, -5);

    int32_t res = MYEXTRALIB_funcEx(5, 10, &value);
    TEST_ASSERT_EQUAL(-75, value);
    TEST_ASSERT_EQUAL(0, res);


    MYLIB_minus_ExpectAndReturn(5, 10, -5);
    res = MYEXTRALIB_funcEx(5, 10, &value);
    TEST_ASSERT_EQUAL(-5, value);
}