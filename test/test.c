#include <stdio.h>
#include "test.h"

int
main(void)
{
    printf("Tests...\n\n");
    /********************/
    test_list();
    test_strext();
    /*******************/
    printf("Done.\n");
    return 0;
}
