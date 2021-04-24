#include <stdarg.h>
#include <unistd.h>
#include <errno.h>

int my_printf(const char *fmt, ...);
int m_strlen(const char *str);
int m_print(const char *str, int f_descriptor, int size);
char* convert(unsigned int, int);

int m_printf(const char *fmt, ...)
//the printf function
{
    va_list arg_list; 
    int return_code = 0;
    int len = m_strlen(fmt);
    char err_msg[30] = "[ERROR]: Reached default case"; 
    char *curr;
    curr = fmt;

    va_start(arg_list, fmt);
    while(curr[0]  != '\0')
    {
        //if(*fmt[i] == "%")
        if(*curr == "%")
        {
            if(*fmt[i+1] != '\0')
            {
                switch(*fmt[i+1])
                {
                    case 'c':
                        //code for printing a char
                        char fmt_arg = va_arg(arg_list, char);
                        m_print(fmt_arg, 1, m_strlen(fmt_arg));
                        break;
                    case 'd':
                        //code for signed decimal integer
                        break;
                    case 'i':
                        //code for signed decimal integer
                        break;
                    case 'e':
                        //code scientific notation (mantissa/exponent) using e character
                        break;
                    case 'E':
                        //code for scientific notation(mantissa/exponent) using E character
                        break;
                    case 'g':
                        //code for shorter %e or %f
                        break;
                    case 'G':
                        //code for shorter %E or %R
                        break;
                    case 'o':
                        //code for signed octal
                        break;
                    case 's':
                        //code for the string of chars
                        break;
                    case 'u':
                        //code for the unsigned decimal integer
                        break;
                    case 'x':
                        //code for the unsigned hexadecimal integer
                        break;
                    case 'X':
                        //code for the unsigend hexadecimal integer (capital letters)
                        break;
                    case 'p':
                        //code for the pointer address
                        break;
                    case 'n':
                        //code for nothing printed(why does this exist???)
                        break;
                    case '%':
                        //code for the % character(why does this also exist???)
                        break;
                    default:
                        //code for default(no clue what to put here yet
                        m_print(err_msg, 1, 30);
                        break;
                }
            }
        }
        else
        {
            m_print(fmt[i], 1, 1);
        }
        curr++;
    }
    va_end(arg_list);
    m_print('\0', 1, 1);

    return return_code; 
}

void test_iter(const char *fmt)
{
    char *curr; 
    char chars;
    chars = *fmt; 

    while(chars != '\0')
    {

    }
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
        r_code = 84;
        write(2, error_msg, 8);
    } 
    return r_code;
}

int main()
{
    const char *str = "Hello World\n";
    char string[13] = "Hello World\n";
    //m_print(str, 1, m_strlen(str));
    //m_printf(string, "Hello ", "World ", "I ", "Variadic\n");
    m_printf("Hello worl%c\n", 'd');
}

