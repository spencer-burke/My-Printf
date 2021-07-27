#include <stdarg.h>
#include <unistd.h>
#include <errno.h>

int my_printf(const char *fmt, ...);
int m_printf(const char *fmt, ...);
int m_strlen(const char *str);
int m_print(const char *str, int f_descriptor, int size);
char* convert(unsigned int, int);
void _putchar(char character);

extern int errno;

int main()
{
    const char *str = "Hello World\n";
    char string[13] = "Hello World\n";
    //m_print(str, 1, m_strlen(str));
    //m_printf(string, "Hello ", "World ", "I ", "Variadic\n");
    m_printf("%c\n", 'd');
}

int m_printf(const char *fmt, ...)
//the printf function
{
    va_list arg_list; 
    int return_code = 0;
    char err_msg[30] = "[ERROR]: Reached default case"; 
    char curr;

    va_start(arg_list, fmt);
    while (*fmt)
    {
        switch(*fmt++)
        {
            case 'c':
                m_print(curr, 1, m_strlen(curr));
                break;
        }

    }
    va_end(arg_list);

    return return_code; 
}

char* convert(unsigned int arg, int arg2)
// I have no idea what this does
{

}

int m_strlen(const char *str)
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
        r_code = errno;
        write(2, r_code, 8);
    } 
    
    return r_code;
}
