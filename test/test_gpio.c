#define TEST
#ifdef TEST

#include "unity.h"

#include "gpio.h"
#include "mcux_reg.h"

#include "help_mcux_reg.c"


void setUp(void)
{
    GPIO_Init();
}

void tearDown(void)
{
}

void test_gpio_config(void)
{
    int32_t res;

    res = GPIO_Config(GPIOA, GPIO_PIN0, GPIO_MODE_DO);

    TEST_ASSERT(GPIOA->mode == 0x00u);
    TEST_ASSERT(res == 0);

    res = GPIO_Config(GPIOA, GPIO_PIN0, GPIO_MODE_DI);

    TEST_ASSERT(GPIOA->mode == 0x01u);
    TEST_ASSERT(res == 0);

    res = GPIO_Config(NULL, GPIO_PIN0, GPIO_MODE_DI);
    TEST_ASSERT(GPIOA->mode == 0x01u);
    TEST_ASSERT(res == -1);
}

void test_gpio_set_pin(void)
{
    int32_t res;

    res = GPIO_SetPin(GPIOA, GPIO_PIN0, true);

    TEST_ASSERT(GPIOA->state == 0x01u);
    TEST_ASSERT(res == 0);

    res = GPIO_SetPin(GPIOA, GPIO_PIN0, false);

    TEST_ASSERT(GPIOA->state == 0x00u);
    TEST_ASSERT(res == 0);

    res = GPIO_SetPin(NULL, GPIO_PIN0, true);
    TEST_ASSERT(GPIOA->state == 0x00u);
    TEST_ASSERT(res == -1);
}

void test_gpio_get_pin(void)
{
    int32_t res;
    bool state;

    res = GPIO_GetPin(GPIOA, GPIO_PIN0, &state);
    TEST_ASSERT_EQUAL(res, 0);
    TEST_ASSERT_EQUAL(state, 0);

    GPIOA->state = 0x01u;
    res = GPIO_GetPin(GPIOA, GPIO_PIN0, &state);
    TEST_ASSERT_EQUAL(res, 0);
    TEST_ASSERT_EQUAL(state, 1);


}

#endif // TEST
