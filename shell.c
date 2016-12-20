#include "my_shell.h"
/**
 * check_input - inputstring processing
 * @inputString inputstring
 * Return: 0 on error
 */

int check_input(char inputString[INPUT_LENGTH])
{
	char *str2 = "Can't process more than 1000 characters";
	const char token[5] = "exit";
	char *str3 = "exit entered...exiting";
	
	if (fgets(inputString, INPUT_LENGTH, stdin) == NULL)
		return (0);
		if (inputString[0] == token[0] && inputString[1] == token[1] &&
		    inputString[2] == token[2] && inputString[3] == token[3])
		{
			write(1, str3, _strlen(str3));
			exit(0);
		}
		if (_strlen(inputString) > (INPUT_LENGTH - 2))
		{
			write(1, str2, _strlen(str2));
			exit(0);
		}
		return (1);
}

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
	char inputString[INPUT_LENGTH], tempPath[_strlen(path)];
	char *argv[ARGUMENT_LENGTH], *inputChar, *pathChar;
	char *pathArgs[_strlen(path)], *final_PathArgs[_strlen(path)];
	char *str = "#cisfun$ ";
	struct stat sb;


	while (1)
	{
		write(1, str, _strlen(str));
		_memset(inputString, 0, sizeof(inputString));
		_memset(argv, 0, sizeof(argv));
		_memset(pathArgs, 0, sizeof(pathArgs));
		
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
			char pathString[_strlen(path)];

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
			return (0);
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
}
