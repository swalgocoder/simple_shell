#include "my_shell.h"

/**
 * _memset - fill first n bytes of memory area
 * @s: char type pointer
 * @b: constant byte
 * @n: number of bytes to be filled
 *
 * Return: char pointer to memory area s
 */
char *_memset(void *s, int b, unsigned int n)
{
	unsigned int i;
	char *dst = s;
	
	for (i = 0; i < n; i++)
		dst[i] = b;
	return (s);
}
