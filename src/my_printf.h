#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int m_printf(const char *fmt, ...);
int m_strlen(char *str);
int m_print(char *str, int f_descriptor, int size);
char *m_itoa(int val, char *str, int base);
char* _strrev (char* str, size_t len);
size_t safe_usub (size_t x, size_t y);

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

char *m_itoa(int val, char *str, int base)
// Convert the int val into a string with the base specified
{
    int temp = val;
    int curr;
    int length_val = 0;
    char digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    if (0 == val)
    {
        str[0] = '0';
        str[1] = '\0';
        
       
    while (temp != 0)
    {
        temp = temp/10;
        length_val++;
    }
    temp = val;

    for(int i = 0; i < length_val; i++)
    {
        curr = temp % 10;
        switch(curr) 
        {
            case 0:
                str[i] = digits[0];
                break; 
            case 1:
                str[i] = digits[1];
                break;
            case 2:
                str[i] = digits[2];
                break;
            case 3:
                str[i] = digits[3];
                break;
            case 4:
                str[i] = digits[4];
                break;
            case 5:
                str[i] = digits[5];
                break;
            case 6:
                str[i] = digits[6];
                break;
            case 7:
                str[i] = digits[7];
                break;
            case 8:
                str[i] = digits[8];
                break;
            case 9:
                str[i] = digits[9];
                break;
        }
    }
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

    char*  new = malloc( sizeof(char) * (len-1) );
    size_t index;
    for (index = 0; index < (len-1); index++) 
        new[index] = str[ safe_usub(index + 1, (len-1)) ]; 
    new[index] = 0;

    return new;
}
