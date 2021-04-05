#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *fmt, ...);
int str_len(const char *str);
int m_print(const char *str, int f_descriptor);
char* convert(unsigned int, int);

int m_printf(const char *fmt, ...)
//the printf function
{
    va_list arg_list; 
    int return_code = 0;
    char result[sizeof(fmt)]; 
    int str_len = strlen(fmt);

    va_start(arg_list, fmt);
    while ( *fmt)
    {
       //pass 
    }
    va_end(arg_list);

    return return_code; 
}

int str_len(const char *str)
//return the length of the string
{
    int len = 0;
    int i;

    for(int i = 0; i != '\0'; i++)
        len++;

    return len;
}

int m_print(const char *str, int f_descriptor)
//writes a string to stdout or other nonzero file descriptor
{
    int r_code = 0;
    int len = size_of(str); 

    if(f_descriptor > 1)
       f_descriptor = 1;
    else
        f_descriptor = f_descriptor;
	
	if((write(f_descriptor, str, len)) != len)
	{
		write(2, "Error occurred", 16);
        r_code = 84;
	}
    
    return r_code;
}

int main()
{
    const char *str = "Hello World";
    //my_printf("Hello world");
    m_print(str, 1);
}

