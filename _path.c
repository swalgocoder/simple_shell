#include "my_shell.h"

/**
 * path_helper -
 *
 */

/**
 * _path - handles the PATH
 * @path: pointer to a sting of the duplicated PATH
 *
 * Return: 0 if success
 */
int _path(char *path)
{
	char *token;
	int i;

	token = my_strtok(path, ":"); /* split first token */
	pathArgs = malloc(sizeof(*pathArgs) * _strlen(pathString));
	if (pathArgs == NULL)
		return (1);
	i = 0;
	while (token[i])
	{
		pathArgs[path_Counter] = token[i];
		i++;
		path_Counter++;
	} /* works */
	pathArgs[path_Counter] = '\0';
	while (token != NULL) /* split rest of tokens */
	{
		path_Counter++;
		token = my_strtok(NULL, ":");
		i = 0;
		while (token[i])
		{
			pathArgs[path_Counter] = token[i];
			printf("pathArgs: %s\n", pathArgs);
			printf("path_Counter: %u\n", path_Counter);
			i++;
			path_Counter++;
		}
		pathArgs[path_Counter] = '\0';
	}
}
