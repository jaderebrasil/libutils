#pragma once
#include <stdbool.h>
#include <stdlib.h>

#define LIST_INIT_CAP 20
#define LIST_GROW_RATE 2

/* Types */
struct List;
typedef struct List List;


#define list_new(ty) list_with_cap(sizeof(ty), LIST_INIT_CAP, LIST_GROW_RATE)
List *list_with_cap(const size_t item_size, const size_t cap, const size_t grow_rate);
void list_free(List *lst);

bool list_set(List *__restrict__ lst, size_t ind, const void *__restrict__ value);

const void *list_get(const List* lst, size_t ind);
const void *list_array(const List *lst);
size_t list_len(const List *lst);
size_t list_cap(const List *lst);


bool list_push(List * __restrict__ lst, const void * __restrict__ el);
bool list_pop(List * __restrict__ lst, void * __restrict__ dst);


/* unsafe */
#ifndef LIST_UNSAFE
#define _unsafe static
#else
#define _unsafe

_unsafe void *list_get_mut(List *lst, size_t ind);

#endif
