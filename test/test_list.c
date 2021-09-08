#include <assert.h>
#include <stdio.h>
#include <list.h> /* list_ */
#include "test.h"

bool
list_set_int(List lst, size_t ind, int value)
{
    return list_set(lst, ind, &value);
}

int
list_get_int(List lst, size_t ind)
{
    return *(int*)list_get(lst, ind);
}

void
test_list(void)
{
    /* Basic tests */
    List lst = list_new(int);
    int a = 42;
    for (size_t i = 0; i < 100; i++)
        if (!list_push(lst, &a))
            break;

    assert(list_len(lst) == 100);
    assert(list_get_int(lst, 99) == a);
    
    int b = 30;
    if (list_set_int(lst, 99, b))
        assert(list_get_int(lst, 99) == b);

    int dst;
    list_pop(lst, &dst);
    assert(dst == b);

    for (size_t i = 0; i < list_len(lst); i++)
        assert(list_get_int(lst, i) == a);
}
