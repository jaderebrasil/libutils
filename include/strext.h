#pragma once
#include <stdlib.h>

/* String Extension */
char *strtriml(char *str);
char *strtrimr(char *str);
char *strtrim(char *str);

char *strtok_rc(char *restrict str, const char *restrict skip_set, char **restrict save_ptr, size_t *restrict c);
