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

    va_start(arg_list, fmt);
    for(int i = 0; fmt[i] != '\0'; i++)
    {
        if(fmt[i] == "%")
        {
            if(fmt[i+1] != '\0')
            {
                switch(fmt[i+1])  
                {

                }
            }
        }
        else
        {
            m_print(fmt[i], 1, 1);
        }
    }
    va_end(arg_list);
    m_print('\0', 1, 1);

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
    m_printf(string, "Hello ", "World ", "I ", "Variadic\n");
}

