#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/my_printf.h"
#include "minunit.h"

int tests_run = 0;

static char* test_reverse()
{
    char str[] = "Reverse";
    char goal[] = "esreveR";
    char* result;

    result = _strrev(str, 8);
    int val = strcmp(result, goal);

    mu_assert("[ERROR]: string not reversed", val == 0);
    return 0;
}

static char* test_itoa()
{
    char goal[] = "111";
    int change = 111;

    char* changed = _itoa(change);
    int val = strcmp(changed, goal);

    mu_assert("[ERROR]: int not converted to ascii", val == 0);
    return 0;
}

static char* all_tests()
{
    mu_run_test(test_reverse);
    mu_run_test(test_itoa);
    return 0;
}

int main(int argc, char **argv)
{
    char *result = all_tests();

    if (result != 0)
        printf("%s\n", result);
    else
        printf("ALL TESTS PASSED\n");
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

