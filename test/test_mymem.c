#if 1
#include "unity.h"
#include <signal.h>
#include <setjmp.h>


#include "mymem.h"

/** Signal of SIGSEGV handeld */
int32_t i = 0;
/** Long jump buffer  */
jmp_buf buf;

void onSigServ(int sig_num)
{
    i = 1;
    /* jump to stored label */
    longjmp(buf, 1);
}

void test_bad_access(void)
{
    /* register handler for a segmentatin fault */
    signal(SIGSEGV, onSigServ);

    /* here is stored the the function stack and 
       it is like "label" for the next start after 
       handling of segmentation fault.*/

    /* avoid to run a segmenation fault infinetly */
    if(setjmp(buf) == 0) {
        /* we use a wrong pointer to see a bad memory access */
        bad_function((uint32_t*)UINTPTR_MAX); 
        //calculate_all(1, 56, 0c67u, 65, true);
    }

    //TEST_ASSERT_EQUAL(get_last_address(), (uint32_t*)0xFFFFFFFFu);
    TEST_ASSERT_EQUAL_PTR(get_last_address(), (uintptr_t)UINTPTR_MAX);
    TEST_ASSERT_EQUAL(i, 1);
}
#else
#include "unity.h"

#include "mymem.h"

void test_bad_access(void)
{
    /* we use a wrong pointer to see a bad memory access */
    bad_function((uint32_t*)0xFFFFFFFFu); 

}

#endif