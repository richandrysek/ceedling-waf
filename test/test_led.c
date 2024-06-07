#ifdef TEST

#include "unity.h"

#include "led.h"
#include "mcux_reg.h" 
#include "mock_gpio.h"

#include "help_mcux_reg.c"

void setUp(void)
{
    GPIO_SetPin_IgnoreAndReturn(0);
    LED_Init();
}

void tearDown(void)
{
}

void test_led_set(void)
{
    GPIO_SetPin_ExpectAndReturn(GPIOA, GPIO_PIN2, true, 0);

    int32_t res = LED_Set(LED_ID_ORANGE, true);

    TEST_ASSERT(res == 0);

    res = LED_Set((LED_Id)-5, true);

    TEST_ASSERT(res == -1);
}

#endif // TEST
