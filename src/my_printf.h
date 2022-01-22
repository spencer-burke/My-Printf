#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int m_printf(char *fmt, ...);
int m_strlen(char *str);
int m_print(char *str, int f_descriptor, int size);
char* _itoa(int val);
char* _strrev (char* str, size_t len);
size_t safe_usub (size_t x, size_t y);

int m_printf(char *fmt, ...)
{
    va_list arg_list; 
    int return_code = 0;
    char err_msg[30] = "[ERROR]: Reached default case"; 
    char *curr;
    unsigned int num_arg;
    char arg;
    char *string_arg;
    double double_arg;

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
                case 'u':
                    num_arg = va_arg(arg_list, unsigned int);
                    m_print(_itoa(num_arg), 1, sizeof(arg)); 
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

char* _itoa(int val)
/*
 * Convert the int val into the string representation
 * This function is supposed to work with unsigned base 10 representations only using something else will cause undefined behaviour
 */
{
    int digit;
    char cdigit;

    int temp = val;
    int curr = 0;
    int length_val = 0;
    char* result;
    
    while (temp != 0)
    {
        temp = temp / 10;
        length_val++;
    }
    temp = val;

    char* reversed = malloc( sizeof(char) * (length_val+1) );

    while (temp != 0)
    {
        digit = temp % 10;
        cdigit = digit + '0'; 
        reversed[curr] = cdigit;
        temp = temp / 10;
        curr++;
    }
    result = _strrev(reversed, (length_val + 1));
    return result;
}

size_t safe_usub (size_t x, size_t y) 
// safe_usub -- perform safe unsigned subtraction
{
    return x > y ? x - y : y - x ;
}

char* _strrev (char* str, size_t len) 
// len will be the one more than the visible characters to account for the null terminator
{
    if (!str) { return 0; }

    char* result = malloc( sizeof(char) * (len-1) );
    size_t index;
    for (index = 0; index < (len-1); index++) 
        result[index] = str[ safe_usub(index + 1, (len-1)) ]; 
    result[index] = 0;

    return result;
}
