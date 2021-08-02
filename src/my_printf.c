#include <stdarg.h>
#include <unistd.h>
#include <errno.h>

int my_printf(const char *fmt, ...);
int m_printf(const char *fmt, ...);
int m_strlen(char *str);
int m_print(char *str, int f_descriptor, int size);
char* m_itoa(int val, char *str, int base);

extern int errno;
/*
 * Supported Formatting Flags:
 * d - signed decimal integer
 * u - unsigned decimal integer
 * e - signed double without rounding
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
    m_printf("Hello World I am number %d\n", num);
    m_printf("Hello World I am the letter %c\n", letter);
}

int m_printf(const char *fmt, ...)
// The printf function
{
    va_list arg_list; 
    int return_code = 0;
    char err_msg[30] = "[ERROR]: Reached default case"; 
    const char *curr;
    int num_arg;
    char arg;
    char *string_arg;

    va_start(arg_list, fmt);
    for(curr = fmt; *curr != '\0'; curr++)
    {
        if(*curr != '%')
            m_print(curr, 1, 1);
        else
        {
            curr++;
            switch(*curr)
            {
                case 'd':
                    num_arg = va_arg(arg_list, int);
                    m_print(arg, 1, sizeof(arg)); 
                    break;
                case 'c':
                    arg = (char) va_arg(arg_list, int);
                    m_print(&arg, 1, 1);
                    break;
                case 's':
                    string_arg = va_arg(arg_list, char *);
                    m_print(string_arg, 1, m_strlen(string_arg)); 
                    break;
            }
        }
    }
    va_end(arg_list);

    return return_code; 
}

int m_strlen(char *str)
// Return the length of the string
{
    int len = 0;
    int i;

    for(int i = 0; str[i] != '\0'; i++)
        len++;

    return len;
}

int m_print(char *str, int f_descriptor, int size) 
// Writes a string to stdout or other nonzero file descriptor
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

char* m_itoa(int val, char *str, int base)
// Convert the int val into a string with the base specified
{
    int temp = val
    int curr;
    int length_val = 0;  
    char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
       
    while (temp != 0)
    {
        temp = temp/10;
        length_val++;
    }
    temp = val;

    for(int i = 0; i < 16;, i++) 
    {
        curr = temp % 10;
        switch(curr) 
        {
        }
    }

    
}
