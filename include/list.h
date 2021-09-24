#pragma once
#include <stdbool.h>
#include <stdlib.h>

#define LIST_INIT_CAP 20 /* default cap */
#define LIST_GROW_RATE 2.0 /* default grow rate */

/* Types */
typedef struct List List;

/* constructors */
#define list_new(ty) list_with_cap(sizeof(ty), LIST_INIT_CAP, LIST_GROW_RATE)
List *list_with_cap(const size_t item_size, const size_t cap, const float grow_rate);

/* add an element to the end of the list */
bool list_push(List * __restrict__ lst, const void * __restrict__ el);

/* removes the last element and copy the value on dst */
bool list_pop(List * __restrict__ lst, void * __restrict__ dst);

/* rewrite an existing element */
bool list_set(List *__restrict__ lst, size_t ind, const void *__restrict__ value);

/* get a const pointer to the value contained in the position `ind` */
const void *list_get(const List *lst, size_t ind);

/* how many elements are in the list. */
size_t list_len(const List *lst);

/* the maximum number of elements before a realloc is needed. */
size_t list_cap(const List *lst);

/* free the list, writes in *arr a pointer to the data array and return current cap. */
size_t list_free_as_array(List *restrict lst, void **arr);

/* free the list and the data it contains. */
void list_free(List *lst);
