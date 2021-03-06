#include "my_shell.h"
/**
 * main - linux commond line interpreter
 * Return: 1 if on error
 */


int main(void)
{
	int childPid, status, errno, arg_Counter, sysCallReturn;
	unsigned int i, path_Counter;
	const char whitespace[8] = " \t\v\n\f\n\r";
	const char colon[2] = ":";
	const char *path = _getenv("PATH");
	char inputString[1000], tempPath[1000];
	char *argv[ARGUMENT_LENGTH], *inputChar, *pathChar;
	char *pathArgs[1000], *final_PathArgs[1000];
	char *str = "#cisfun$ ";
	struct stat sb;
	char *inputString1 = inputString;
	char pathString[1000];

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


			for (i = 0; i < _strlen(path); i++)
				pathString[i] = path[i];
			pathChar = my_strtok(pathString, colon);
			pathArgs[path_Counter] = pathChar;
			while (pathChar != NULL)
			{
				path_Counter++;
				pathChar = my_strtok(NULL, colon);
				pathArgs[path_Counter] = pathChar;
			}
			for (i = 0; i < path_Counter; i++)
			{
				_memset(tempPath, 0, sizeof(tempPath));
				_strcpy(tempPath, pathArgs[i]);
				_strcat(tempPath, "/");
				_strcat(tempPath, argv[0]);
				final_PathArgs[i] = tempPath;
				sysCallReturn = stat(final_PathArgs[i], &sb);
				if (sysCallReturn == 0)
				{
					sysCallReturn = execv(final_PathArgs[i], argv);
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
