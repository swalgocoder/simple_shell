#include "my_shell.h"
/**
 * main - linux commond line interpreter
 *
 * Return: 0 on success, 1 if on error
 */

int main(void)
{
	int childPid, status, errno, arg_Counter, sysCallReturn;
	unsigned int i, path_Counter;
	size_t n, line;
	const char whitespace[8] = " \t\v\n\f\n\r", *path = _getenv("PATH");
	char *inputString, *inputChar, *argv[ARGUMENT_LENGTH];
	char *pathArgs, *final_PathArgs, *pathString, *pathChar, *tempPath;
	struct stat sb;

	pathArgs = malloc(sizeof(*pathArgs) * _strlen(path));
	if (pathArgs == NULL)
		return (1);
	while (1)
	{
		write(1, "#cisfun$ ", 9);
		n = 32;
		line = getline(&inputString, &n, stdin); /* working */
		check_input(inputString);
		childPid = fork();
		if (childPid == 0)
		{
			arg_Counter = 0;
			path_Counter = 0;
			inputChar = my_strtok(inputString, whitespace);
			argv[arg_Counter] = inputChar;
			while (inputChar != NULL)
			{
				arg_Counter++;
				inputChar = my_strtok(NULL, whitespace);
				argv[arg_Counter] = inputChar;
			}
			pathString = malloc(sizeof(*pathString) * _strlen(path));
			if (pathString == NULL)
				return (1);
			for (i = 0; i < _strlen(path); i++)
				pathString[i] = path[i];
			pathChar = my_strtok(pathString, ":");
			pathArgs[path_Counter] = pathChar[i];
			while (pathChar != NULL)
			{
				path_Counter++;
				pathChar = my_strtok(NULL, ":");
				pathArgs[path_Counter] = pathChar[i];
			}
			tempPath = malloc(sizeof(*tempPath) * _strlen(path));
			if (tempPath == NULL)
				return (1);
			final_PathArgs = malloc(sizeof(*final_PathArgs) * _strlen(path));
			if (final_PathArgs == NULL)
				return (1);
			for (i = 0; i < path_Counter; i++)
			{
				_memset(tempPath, 0, sizeof(tempPath));
				_strcpy(tempPath, pathArgs);
				_strcat(tempPath, "/");
				_strcat(tempPath, argv[0]);
				final_PathArgs = tempPath;
				sysCallReturn = stat(final_PathArgs, &sb);
				if (sysCallReturn == 0)
				{
					sysCallReturn = execv(final_PathArgs, argv);
					break;
				}
			}
			if (sysCallReturn == -1)
			write(1, strerror(errno), strlen(strerror(errno)));
			return (1);
		}
		else if (childPid == -1)
		{
			write(1, strerror(errno), strlen(strerror(errno)));

			break;
		}
		else
		{
			if (wait(&status) == -1)
			write(1, strerror(errno), strlen(strerror(errno)));
		}
	}
	return (0);
}
