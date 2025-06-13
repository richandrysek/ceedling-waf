#ifndef MYMEM_H

#include <stdint.h>

extern void bad_function(uint32_t * memaddr);
extern uint32_t *get_last_address(void);

#endif