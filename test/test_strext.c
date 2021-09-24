#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <strext.h> /* str____ */
#include "test.h"

void
test_strtok_rc(void)
{
    char str[] = "1\n\n22\n\n\n333\n\n\n\n4444\n\n\n\n\n55555";
    const char *sep = "\n";
    char *token;
    char *rest = NULL;
    size_t found = 0;
    size_t i = 0;

    token = strtok_rc(str, sep, &rest, &found);

    while (token != NULL) {
        assert(found == i);
        token = strtok_rc(NULL, sep, &rest, &found);
        i++;
    };
}

void
test_strext(void)
{
    char *in = calloc(8, 1);
    strcpy(in, "  str  ");

    assert(!strcmp(strtriml(in), "str  "));
    info_ok(triml);

    assert(!strcmp(in, "  str  "));
    info_ok(const);

    assert(!strcmp(strtrimr(in), "  str"));
    info_ok(trimr);

    assert(!strcmp(strtrim(in), "str"));
    info_ok(trim);

    for (size_t i = 0; i < 7; i++)
        if (i % 2 == 0)
            in[i] = '\t';
        else
            in[i] = ' ';

    assert(!strcmp(strtrim(in), ""));
    info_ok(trim_spaces);

    assert(!strcmp(strtrim(in), ""));
    info_ok(trim_empty);

    //printf("%s\n", strtrim(NULL));
    //assert(!strcmp(strtrim(NULL), ""));
    //info_ok(null);

    test_strtok_rc();
    info_ok(tokrc);

    free(in);
    in = NULL;
}

