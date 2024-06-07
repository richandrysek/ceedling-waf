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

#endif // TEST
