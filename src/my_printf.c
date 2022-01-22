#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include "my_printf.h"

extern int errno;
/*
 * Supported Formatting Flags:
 * u - unsigned decimal integer
 * c - unsigned char
 * s - char* or string 
 */

int main()
{
    const char *str = "Hello World\n";
    char string[13] = "Hello World\n";
    char *arg = "one";
    char letter = 'a';
    int num = 1;
    m_printf("Hello World I am number %s\n", arg);
    m_printf("Hello World I am number %u\n", num);
    m_printf("Hello World I am the letter %c\n", letter);
}
