#pragma once
#include <stdlib.h>

/* String Extension */
char *strtriml(const char *_Source);
char *strtrimr(const char *_Source);
char *strtrim(const char *_Source);

char *strtok_rc(char *restrict str, const char *restrict skip_set, char **restrict save_ptr, size_t *restrict c);
