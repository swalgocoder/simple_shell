#include "my_shell.h"

/**
 * _strdup - copy a string
 * @str: string
 *
 * Return: pointer to copy
 */
char *_strdup(char *str)
{
	char *s;
	unsigned int i, n;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	s = malloc((i * sizeof(char)) + 1);
	if (s == NULL)
		return (NULL);
	n = 0;
	while (n < i)
	{
		s[n] = str[n];
		n++;
	}
	s[n] = '\0';
	return (s);
}

/**
 * _strcmp - compare two strings
 * @s1: string one
 * @s2: const type string two
 *
 * Return: 1 or 0
 */
int _strcmp(char *s1, const char *s2)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (1);
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] >  s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else
		return (1);
}
