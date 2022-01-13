#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"

int tests_run = 0;

size_t safe_usub (size_t x, size_t y) 
// safe_usub -- perform safe unsigned subtraction
{
    return x > y ? x - y : y - x ;
}

char* _strrev (char* str, size_t len) 
// len will be the one more than the visible characters to account for the null terminator
{
    if (!str) { return 0; }

    char*  new = malloc( sizeof(char) * (len-1) );
    size_t index;
    for (index = 0; index < (len-1); index++) 
        new[index] = str[ safe_usub(index + 1, (len-1)) ]; 
    new[index] = 0;

    return new;
}

static char * test_reverse()
{
    char str[] = "Reverse";
    char goal[] = "esreveR";
    char* result;

    result = _strrev(str, 8);
    int val = strcmp(result, goal);

    mu_assert("[ERROR]: string not reversed", val == 0);
    return 0;
}

static char * all_tests()
{
    mu_run_test(test_reverse);
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

