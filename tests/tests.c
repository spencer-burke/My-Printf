#include <stdio.h>
#include "minunit.h"
#include "../src/my_printf.h"

int tests_run = 0;

void _strrev(char* arg, int len)
{
    int ii;
    int j;
    char c;

    for (ii = 0, j = len-1; ii < j; ii++, j--)
    {
        c = arg[ii];
        arg[ii] = arg[j];
        arg[j] = c;
    }
}

static char* test_reverse()
{
    char[] reverse = "Reverse";
    char[] reversed = "esreveR";
    int comparison = strcmp(reverse, reversed);
    mu_assert("[ERROR]: string not reversed", comparison == 0);
}

static char* all_tests()
{
    mu_run_test(test_reverse);
} 

int main(int argc, char **argv)
{
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
