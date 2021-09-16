#include <stdio.h>
#include "minunit.h"
#include "../src/my_printf.h"
int tests_run = 0;
char correct_string[5] = "olleh";
char input_string[5] = "hello";

static char* test_reverse()
{
    reverse(input_string, 5);
    int correct = strcmp(input_string, correct_string);
    mu_assert("[ERROR]: input_string != correct_string", correct == 0);

    return 0;
}

int main(int argc, char **argv)
{
    char *result = test_reverse();
    if (result != 0)
    {
        puts(result);
    }
    else
    {
        puts("[INFO]: TESTS PASSED");
    }
    return result != 0;
}
