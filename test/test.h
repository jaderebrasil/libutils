#include <stdio.h>
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

static size_t g_passed_tests = 0;
inline static void
log_info_ok(const char *desc, const char *func)
{
    g_passed_tests++;
    printf("%s [%zu: %s]................................... %sOK%s\n", func, g_passed_tests, desc, GREEN, RESET);
}

#define info_ok(n) log_info_ok(#n, __func__);

void test_list(void);
void test_strext(void);

