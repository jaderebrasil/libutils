#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "strext.h"

char *
strtriml(const char *_Source)
{
    assert(_Source != NULL);

    size_t len = strlen(_Source);
    char *str = malloc(len);
    if (len == 0)
        return str;

    strcpy(str, _Source);

    while(isspace(*str)) str++;
    return str; 
}

char *
strtrimr(const char *_Source)
{
    assert(_Source != NULL);

    size_t len = strlen(_Source);
    char *str = malloc(len);
    if (len == 0)
        return str;

    strcpy(str, _Source);

    char *aux = str + strlen(str);
    while(isspace(*--aux));
    *(aux + 1) = '\0';

    return str;
}

char *
strtrim(const char *_Source)
{
    return strtrimr(strtriml(_Source));
}


/*
 * basically the same as strtok_r, but write 
 * the character value in the last parameter
 * skipped by strspn.
 */
char *
strtok_rc(char *restrict str, const char *restrict skip_set, char **restrict save_ptr, size_t *restrict c)
{
    if (!str && !(str = *save_ptr)) return NULL;
	str += (*c = strspn(str, skip_set));

	if (!*str) return (*save_ptr = 0);
	*save_ptr = str + strcspn(str, skip_set);

	if (**save_ptr) 
        *(*save_ptr)++ = 0;
	else 
        *save_ptr = 0;

	return str;
}
