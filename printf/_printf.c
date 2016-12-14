#include "holberton.h"
#include <unistd.h>
#include <stdarg.h>
/**
 *my_str - prints a string
 *@ptr_args: ptr to arguments
 *Return: The number of char
 */
int my_str(va_list ptr_args)
{
	char *j;
	int i, char_count;

	char_count = 0;
	j = va_arg(ptr_args, char *);
	if (j == NULL)
		j = "(null)";
	i = 0;
	while (j[i] != '\0')
	{
		_putchar(j[i]);
		i++;
		char_count++;
	}
	return (char_count);
}
/**
 *my_char - prints out a character
 *@ptr_args: ptr to args
 *Return: 1
 */
int my_char(va_list ptr_args)
{
	char j;

	j = va_arg(ptr_args, int);
	_putchar(j);
	return (1);
}
/**
 *my_percentage - % as an input
 *@per: A %
 *Return: 1
 */
int my_percentage(int per)
{
	per = '%';
	_putchar(per);
	return (1);
}
/**
 *_printf - home made printf function
 *@format: format of the arguments
 *Return: The number of char printed
 */
int _printf(const char *format, ...)
{
	va_list ptr_args;
	int i, j, char_count;
	my_type my_data_type[] = {
		{"s", my_str},
		{"c", my_char},
		{"%", my_percentage},
		{NULL, NULL}
	};
	va_start(ptr_args, format);

	char_count = i = 0;
	if (format == NULL || ptr_args == NULL)
		return (char_count);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			j = 0;
			while (j < 3)
			{
				if (*my_data_type[j].check_char == format[i])
				{
					char_count += (my_data_type[j].f(ptr_args));
				}
				j++;
			}
		}
		else
		{
			_putchar(format[i]);
			char_count++;
		}
		i++;
	}
	va_end(ptr_args);
	return (char_count);
}
