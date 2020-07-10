#include <stdio.h>
#include <stdarg.h>

int
my_printf(const char *fmt, ...)
{
    va_list arg_list; 
    int return_code = 0;
    char result[sizeof(fmt)]; 
    int str_len = strlen(fmt);

    va_start(arg_list, fmt);
    while ( *fmt)
    {
        puts(fmt);
    }
    va_end(arg_list);

    return return_code; 
}

int main()
{
    my_printf("Hello world");
}
