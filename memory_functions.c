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

/**
 * _realloc - reallocate a memory block using malloc and free
 * @ptr: pointer to previously called memory (from malloc(old_size))
 * @old_size: size in bytes of memory for ptr
 * @new_size: size in bytes of new memory block
 *
 * Return: pointer to new memory, or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *ptrcopy;
	unsigned int i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (ptr == NULL)
		return (new_ptr);
	ptrcopy = ptr;
	i = 0;
	while (i < old_size && i < new_size)
	{
		new_ptr[i] = ptrcopy[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}
