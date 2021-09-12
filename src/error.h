#pragma once
#include <stdio.h>
#include <stdlib.h>

#define error_exit(msg) __raise_err(msg, __func__, __FILE__, __LINE__)

static void
__raise_err(const char *msg, const char *func, const char *file, size_t line)
{
    fprintf(stderr, "[%s:%lld] %s > %s\n", file, line, func, msg);
    exit(1);
}
