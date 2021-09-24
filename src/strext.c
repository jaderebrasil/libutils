#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "strext.h"

char *
strtriml(char *str)
{
    assert(str != NULL);

    size_t len = strlen(str);
    if (len == 0) return (char*)"";

    while(isspace(*str)) str++; /* */

    return str;
}

char *
strtrimr(char *str)
{
    assert(str != NULL);

    size_t len = strlen(str);
    if (len == 0) return (char*)"";

    char *aux = str + strlen(str);
    while(isspace(*--aux)); /* */
    *(aux + 1) = '\0'; /* */

    return str;
}

char *
strtrim(char *str)
{
    return strtrimr(strtriml(str));
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

