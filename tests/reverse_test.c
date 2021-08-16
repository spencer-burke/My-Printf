#include <stdio.h>
#include "minunit.h"
#include "../src/my_printf.h"
int tests_run = 0;
char correct_string[5] = "olleh";
char input_string[5] = "hello";

static char* test_reverse()
{
    reverse(input_string, 5);
    int correct = strcmp(correct_string, input_string);
    mu_assert("[ERROR]: input_string != correct_string", correct == 0);

    return 0;
}
