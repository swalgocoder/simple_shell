#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <string.h>
/**
 * _strspn -  calculates the length (in bytes) of the initial segment of p
 * @p: pointer to string to check(target)
 * @s: pointer to string to check against(source)
 * Return: int, number of bytes found
 */
int _strspn(const char *p, const char *s)
{
	int i, j;

	for (i = 0; p[i]; i++)
	{
		for (j = 0; s[j]; j++)
		{
			if (s[j] == p[i])
				break;
		}
		if (!s[j])
			break;
	}
	return (i);
}
#include <string.h>
/**
 * _strcspn - Scans p for the first occurrence of any of the characters found
 * @p: string to scan
 * @s: source string containing characters to search for
 * Return: int the number of characters read before this first occurrence.
 */
int _strcspn(const char *p, const char *s)
{
	int i, j;

	for (i = 0; p[i]; i++)
	{
		for (j = 0; s[j]; j++)
		{
			if (s[j] == p[i])
				break;
		}
		if (s[j])
			break;
	}
	return (i);
}
#include <string.h>
/**
 * my_strtok - tokenize an input string
 * @p: string to tokenize
 * @tok: delminiters
 * Return: pointer
 */
char *my_strtok(char *p, const char *tok)
{
static char    *t;	/* XXX */
	char *r;
	int n;

	if (p)
		t = p;

	r = t + _strspn(t, tok);
	if (!(n = _strcspn(r, tok)))
		return (0);
	t = r + n;
	if (*t)
		*t++ = 0;
	return (r);
}
