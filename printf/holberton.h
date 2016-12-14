#ifndef H_98_H
#define H_98_H
#include <unistd.h>
#include <stdarg.h>
/**
 *struct data_type - A struct that has a pointer character and a pointer
 *@check_char: a character pointer
 *@f: a function pointer
 */
typedef struct data_type
{
	char *check_char;
	int (*f)();
} my_type;

int my_format(va_list ptr_args, my_type data_type[], char format);
int _printf(const char *format, ...);
int _putchar(char c);
int my_number(int n);
void my_struct(void);
int my_percentage(int per);
void my_puts_str(char *str);
int my_str(va_list ptr_args);
int itoa(int n, char s[]);
int _abs(int i);
#endif
