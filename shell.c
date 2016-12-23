#include "my_shell.h"
/**
 * main - linux commond line interpreter
 *
 * Return: 0 on success, 1 if on error
 */

int main(void)
{
	int childPid, arg_Counter, sysCallReturn, status, i, path_Counter;
	ssize_t line;
	size_t n;
	const char whitespace[8] = " \t\v\n\f\n\r";
	char *inputString, *inputChar, *argv[ARGUMENT_LENGTH], *pathArgs, *path;
	char **path_tokens, *final_PathArgs, *pathString, *tempPath;
	struct stat sb;

	while (1)
	{
		write(1, "#cisfun$ ", 9);
		n = 32;
		line = getline(&inputString, &n, stdin);
		if (line < 0)
			return (1);
		check_input(inputString); /* checks exit */
		arg_Counter = 0;
		/* handle input */
		inputChar = my_strtok(inputString, whitespace);
		argv[arg_Counter] = inputChar;
		if (argv == NULL)
			return (1);
		while (inputChar != NULL) /* includes trailing null character */
		{
			arg_Counter++;
			inputChar = my_strtok(NULL, whitespace);
			argv[arg_Counter] = inputChar;
		}
		/* handle path */
		path = _getenv("PATH");
		pathString = c_strdup(path); /* duplicate PATH */
		path_tokens = _path(pathString); /* path_tokens is a pointer to an array of tokenized PATH */
		if (path_tokens == NULL)
			return (1);
		path_Counter = _strlen(path);
		pathArgs = *path_tokens; /* maybe no unary operator */
		childPid = fork();
		if (childPid == 0)
		{
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
					sysCallReturn = execve(final_PathArgs, argv);
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
