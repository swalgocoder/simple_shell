#include "my_shell.h"

int _path(char *path)
{
	char *token, **args;
	int i;

	token = my_strtok(path, ":"); /* split first token */
	i = 0;
	args = malloc(sizeof(token) * _strlen(path));
	if (args == NULL)
		return (1);
	args[i] = token;
	while (token != NULL) /* split rest of tokens */
	{
		i++;
		token = my_strtok(NULL, ":");
		args[i] = token;
	}
	return (0); /* testing */
}
