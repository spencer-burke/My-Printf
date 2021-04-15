#include <stdarg.h>
#include <unistd.h>
#include <errno.h>

int my_printf(const char *fmt, ...);
int str_len(const char *str);
int m_print(const char *str, int f_descriptor, int size);
char* convert(unsigned int, int);

int m_printf(char *fmt, ...)
//the printf function
{
    va_list arg_list; 
    int return_code = 0;
    int strlen = str_len(fmt);

    va_start(arg_list, fmt);
    while (*fmt)
    {
       m_print(fmt, 1, strlen); 
    }
    va_end(arg_list);

    return return_code; 
}

char* convert(unsigned int, int)
// I have no idea what this does
{

}

int str_len(const char *str)
//return the length of the string
{
    int len = 0;
    int i;

    for(int i = 0; str[i] != '\0'; i++)
        len++;

    return len;
}

int m_print(const char *str, int f_descriptor, int size) 
//writes a string to stdout or other nonzero file descriptor
{
    int r_code = 0;
    int bytes_written = write(f_descriptor, str, size);
    char error_msg[8] = "[Error]\n";
    if(bytes_written != size)
    {
        r_code = 84;
        write(2, error_msg, 8);
    } 
    return r_code;
}

int main()
{
    const char *str = "Hello World\n";
    char string[13] = "Hello World\n";
    m_print(str, 1, str_len(str));
}

