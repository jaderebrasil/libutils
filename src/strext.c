#include "../include/strext.h"
#include <ctype.h>
#include <string.h>

char *
strtriml(char *str)
{
    while(isspace(*str)) str++;
    return str; 
}

char *
strtrimr(char *str)
{
    char *aux = str + strlen(str);
    while(isspace(*--aux));
    *(aux + 1) = '\0';

    return str;
}

char *
strtrim(char *str)
{
    return strtrimr(strtriml(str));
}
