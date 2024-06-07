#include "led.h"
#include "gpio.h"

typedef struct {
	GPIO * pGpio;
	uint8_t pin;
	bool initState;
} LED_PinCfg;

LED_PinCfg LED_pinCfg[] = {
	/* LED_ID_RED */  {GPIOA, GPIO_PIN0, true},
	/* LED_ID_GREEN */  {GPIOA, GPIO_PIN1, true},
	/* LED_ID_ORANGE */  {GPIOA, GPIO_PIN2, true},
};

void LED_Init(void)
{
	for(uint8_t idx = 0; idx < sizeof(LED_pinCfg)/sizeof(LED_pinCfg[0]); idx++)
	{
		LED_Set(idx, LED_pinCfg[idx].initState);
	}
}

int32_t LED_Set(const LED_Id id, bool on)
{
	int32_t ret = -1;
	
	if((id >= LED_ID_RED) && (id <= LED_ID_ORANGE))
	{
		ret = GPIO_SetPin(LED_pinCfg[id].pGpio, LED_pinCfg[id].pin, on);
	}

	return ret;
}