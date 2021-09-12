#include <assert.h>
#include <stdio.h>
#include <list.h> /* list_ */
#include "test.h"

bool
list_set_int(List *lst, size_t ind, int value)
{
    return list_set(lst, ind, &value);
}

int
list_get_int(List *lst, size_t ind)
{
    return *(int*)list_get(lst, ind);
}

void
test_list(void)
{
    /* Basic tests */
    List *lst = list_with_cap(sizeof(int), 20, 1.1);
    assert(lst != NULL);
    info_ok(constructor);

    int a = 42;
    for (size_t i = 0; i < 100; i++)
        if (!list_push(lst, &a))
            break;

    assert(list_len(lst) == 100);
    assert(list_get_int(lst, 99) == a);
    info_ok(push);
    
    int b = 30;
    if (list_set_int(lst, 99, b))
        assert(list_get_int(lst, 99) == b);
    info_ok(set);

    int dst;
    list_pop(lst, &dst);
    assert(dst == b);
    info_ok(pop);

    int *data;
    size_t LEN = list_len(lst);
    list_free_as_array(lst, (void**)&data);

    for (size_t i = 0; i < LEN; i++)
        assert(data[i] == a);
    
    info_ok(free_as_array);
}
