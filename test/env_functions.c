#include "my_shell.h"

/**
 * _getenv - get an environmental variable
 * @name: name of environmental variable
 *
 * Return: pointer to the value in the environment, or NULL if no match
 */
char *_getenv(const char *name)
{
	extern char **environ;
	char *str;
	size_t i, comp;

	i  = 0;
	while (environ[i])
	{
		str = _strdup(environ[i]);
		str = strtok(str, "=");
		comp = _strcmp(str, name);
		if (comp == 0)
		{
			str = _strdup(strtok(NULL, "\0"));
			return (str);
		}
		i++;
	}
	return (NULL);
}
