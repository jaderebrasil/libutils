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
