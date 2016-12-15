#include "my_shell.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
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
unsigned int _strlen(const char *s)
{
	unsigned int l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

/**
 * _strcpy - copy bytes of @strSrc to @strDest
 * @strDest: pointer to destination string
 * @strSrc: pointer to source string
 * Return: pointer to @strdest
 */
char * _strcpy(char *strDest, const char *strSrc)
{
    assert(strDest!=NULL && strSrc!=NULL);
    char *temp = strDest;
    while((*strDest++=*strSrc++) != '\0');
    return temp;

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
