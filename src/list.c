#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

struct List {
    const size_t item_size;
    const float grow_rate;
    size_t cap;
    size_t len;
    char *ptr;
};

size_t
list_len(const List *lst)
{
    return lst->len;
}

size_t
list_cap(const List *lst)
{
    return lst->len;
}

const void *
list_array(const List *lst)
{
    return lst->ptr;
}

static void
list_err(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

List *
list_with_cap(const size_t item_size, const size_t cap, const size_t grow_rate)
{
    assert(item_size > 0);
    assert(cap > 0);
    assert(grow_rate >= 2);

    List *lst = malloc(sizeof(List));  

    if (lst == NULL)
        list_err("list_new: allocation failed.");

    *(size_t*)&lst->item_size = item_size;
    *(float*)&lst->grow_rate = grow_rate;

    lst->cap = cap;
    lst->len = 0;
    lst->ptr = malloc(cap * item_size);
    
    for (size_t i = 0; i < cap; i++)
        lst->ptr[i] = 0;

    return lst;
}

_unsafe void *
list_get_mut(List *lst, size_t ind)
{
    assert(ind < lst->cap);
    if (ind > lst->cap)
        return NULL;

    return &lst->ptr[ind * lst->item_size];
}

const void *
list_get(const List *lst, size_t ind)
{
    assert(ind < lst->len);
    return list_get_mut((List*)lst, ind);
}

static bool
list_reserve(List *lst, size_t r)
{
    size_t reserve = lst->len + r;
    size_t ncap = lst->cap;

    if (reserve <= ncap) 
        return true;

    while (ncap < reserve)
        ncap *= lst->grow_rate;

    char *nptr = realloc(lst->ptr, ncap * lst->item_size);
    if (nptr == NULL)
        return false;

    lst->cap = ncap;
    lst->ptr = nptr;

    return true;
}

bool
list_push(List *restrict lst, const void *restrict el)
{
    if (!list_reserve(lst, 1))
        return false;

    char *ptr = (char*) list_get_mut(lst, lst->len);
    memcpy(ptr, (char*)el, lst->item_size);

    lst->len++;

    return true; 
}

bool
list_pop(List *restrict lst, void *restrict dst)
{
    if (!lst->len)
        return false;

    char *ptr = (char*) list_get_mut(lst, --lst->len);
    memcpy(dst, ptr, lst->item_size);

    return true;
}

bool
list_set(List *restrict lst, size_t ind, const void *restrict value)
{
    assert(ind < lst->len);
    if (ind >= lst->len)
        return false;

    char *ptr = (char*) list_get_mut(lst, ind);
    memcpy(ptr, (char*)value, lst->item_size);

    return true;
}

void
list_free(List *lst)
{
    free(lst->ptr);
    free(lst);
}
