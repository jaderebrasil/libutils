#include <stdio.h>
#include "../include/list.h"
#include "test.h"

bool
list_set_int(List lst, size_t ind, int value)
{
    return list_set(lst, ind, &value);
}

void
test_list(void)
{
    List lst = list_new(int);
    int a = 42;
    printf("Pushing: ");
    for (size_t i = 0; i < 100; i++) {
        putchar('*');
        if (!list_push(lst, &a))
            break;
    }
    printf("Print: \n");
    for (size_t i = 0; i < list_len(lst); i++)
        printf("[%d, %lld]", *(int*)list_get(lst, i), i+1);
    
    if (list_set_int(lst, 99, 30))
        printf("\nChange: [%d, %d]\n\n", *(int*)list_get(lst, 99), 100);

    int dst;
    list_pop(lst, &dst);
    printf("\n--> %d <--\n", dst);

    printf("Print: \n");
    for (size_t i = 0; i < list_len(lst); i++)
        printf("[%d, %lld]", *(int*)list_get(lst, i), i+1);
}
