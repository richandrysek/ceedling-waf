#include "mymem.h"

#include <stdint.h>

static uint32_t * lastAddr = 0;

void bad_function(uint32_t * memaddr)
{
    //*(volatile uint32_t*)0xFFFFFFFFu = 0x5555u;
    lastAddr = memaddr;
    *memaddr = 0x5555u;
}

uint32_t *get_last_address(void)
{
    return lastAddr;
}