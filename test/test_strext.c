#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "../include/strext.h"
#include "test.h"

void
test_list()
{
    assert(strcmp(strtriml("  str  "), "str  "));
    assert(strcmp(strtrimr("  str  "), "  str"));
    assert(strcmp(strtrim("  str  "), "str"));
    assert(strcmp(strtrim(""), ""));
    assert(strcmp(strtrim(NULL), ""));
}
