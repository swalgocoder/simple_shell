#include "my_shell.h"

/**
 * _putchar - writes character to stdout
 * @c: character to print
 *
 * Return: write
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printstring - print string using _putchar
 * @string: string to print
 *
 * Return: 1
 */
int _printstring(char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		_putchar(string[i]);
		i++;
	}
	return (1);
}

/**
 * _strlen - find length of string
 * @s: pointer to  string
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

/**
 * _strncpy - copy @n bytes of @src to @dest
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @n: bytes to copy
 *
 * Return: pointer to @dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i != n)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
		{
			while (i != n)
				dest[i++] = '\0';
			break;
		}
		i++;
	}
	return (dest);
}

/**
 * _strcat - concatenate two strings
 * @dest: base string
 * @src: string to be added
 *
 * Return: char
 */
char *_strcat(char *dest, char *src)
{
	int i, n;

	i = n = 0;
	while (dest[i])
		i++;
	while (src[n])
		dest[i++] = src[n++];
	dest[i] = '\0';
	return (dest);
}
