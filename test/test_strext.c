#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <strext.h> /* str____ */
#include "test.h"

#define GREEN "\033[0;32m"
#define RESET "\033[0m"
#define info_ok(n) printf("%s [%s]................................... %sOK%s\n", "test_strext", #n, GREEN, RESET);

void
test_strext(void)
{
    const char *in = "  str  ";

    assert(!strcmp(strtriml("  str  "), "str  "));
    info_ok(1_triml);

    assert(!strcmp(in, "  str  "));
    info_ok(2_const);

    assert(!strcmp(strtrimr("  str  "), "  str"));
    info_ok(3_trimr);

    assert(!strcmp(strtrim("  str  "), "str"));
    info_ok(4__trim);

    assert(strcmp(strtrim(""), ""));
    info_ok(4_empty);
}
