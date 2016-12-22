#include "my_shell.h"
/**
 * main - linux commond line interpreter
 * Return: 0 if on error
 */


int main(void)
{
	int childPid, status, errno, arg_Counter, sysCallReturn;
	unsigned int i, path_Counter;
	const char whitespace[8] = " \t\v\n\f\n\r";
	const char colon[2] = ":";
	const char *path = _getenv("PATH");
	char *pathString;
	char *argv[ARGUMENT_LENGTH], *inputChar, *pathChar, *inputString;
	char *pathArgs, *final_PathArgs, *tempPath;
	char *str = "#cisfun$ ";
	struct stat sb;
<<<<<<< HEAD
	char *inputString1;

	inputString = malloc(sizeof(*inputString) * 1002);
	if (inputString == NULL)
		return (1);
	inputString1 = inputString;
	pathArgs = malloc(sizeof(*pathArgs) * _strlen(path));
	if (pathArgs == NULL)
		return (1);
=======
	char *inputString1 = inputString;
	char pathString[_strlen(path)];
>>>>>>> cafe3ccb3cace91f219f000f09df02ad923f28e6

	while (1)
	{
		write(1, str, _strlen(str));
		_memset(inputString, 0, sizeof(inputString));
		_memset(argv, 0, sizeof(argv));
		_memset(pathArgs, 0, sizeof(pathArgs));

		check_input(inputString1);

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
<<<<<<< HEAD
			pathString = malloc(sizeof(*pathString) * _strlen(path));
			if (pathString == NULL)
				return (1);
=======


>>>>>>> cafe3ccb3cace91f219f000f09df02ad923f28e6
			for (i = 0; i < _strlen(path); i++)
				pathString[i] = path[i];
			pathChar = my_strtok(pathString, colon);
			pathArgs[path_Counter] = pathChar[i];
			while (pathChar != NULL)
			{
				path_Counter++;
				pathChar = my_strtok(NULL, colon);
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
