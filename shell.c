#include "my_shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#define INPUT_LENGTH 1002
#define ARGUMENT_LENGTH 1001

int main () {
	int childPid, status, errno, arg_Counter, sysCallReturn;
	unsigned int i, path_Counter;
	const char whitespace[8] = " \t\v\n\f\n\r";
	const char colon[2] = ":";
	const char* path = _getenv("PATH");
	char inputString[INPUT_LENGTH], tempPath[_strlen(path)];
	char *argv[ARGUMENT_LENGTH], *inputChar, *pathChar;
	char *pathArgs[_strlen(path)], *final_PathArgs[_strlen(path)];
	char *str = "#cisfun$ ";
	struct stat sb;
	char *str2 = "Can't process more than 1000 characters";
	
	while (1) {
		/* can not use fprintf */
		write(1, str, _strlen(str));
		_memset(inputString, 0, sizeof(inputString));
		_memset(argv, 0, sizeof(argv));
		_memset(pathArgs, 0, sizeof(pathArgs));
		/* can not use fgets */
		if (fgets(inputString, INPUT_LENGTH, stdin) == NULL)
			return 0;
		if (_strlen(inputString) > (INPUT_LENGTH - 2))
		{
			/* can not use printf */
			write(1, str2, _strlen(str2));
			/* can not use getchar */
			while (getchar() != '\n');
			continue;
		}
		childPid = fork();
		if (childPid == 0)
		{
			arg_Counter = 0;
			path_Counter = 0;
			inputChar = strtok(inputString, whitespace);
			argv[arg_Counter] = inputChar;
			while(inputChar != NULL )
			{
				arg_Counter++;
				inputChar = strtok(NULL, whitespace);
				argv[arg_Counter] = inputChar;
			}
			char pathString[_strlen(path)];
			for (i = 0; i < _strlen(path); i++)
				pathString[i] = path[i];
			pathChar = strtok(pathString, colon);
			pathArgs[path_Counter] = pathChar;
			while(pathChar != NULL )
			{
				path_Counter++;
				pathChar = strtok(NULL, colon);
				pathArgs[path_Counter] = pathChar;
			}
			for (i = 0; i < path_Counter; i++)
			{
				_memset(tempPath, 0, sizeof(tempPath));
				_strcpy (tempPath, pathArgs[i]);
				_strcat (tempPath, "/");
				_strcat (tempPath, argv[0]);
				final_PathArgs[i] = tempPath;
				sysCallReturn = stat(final_PathArgs[i], &sb);
				if (sysCallReturn == 0)
				{
					sysCallReturn = execv(final_PathArgs[i], argv);
					break;
				}
			}
			if (sysCallReturn == -1)
				/* can not use printf */
			write(1, strerror(errno), strlen(strerror(errno)));
			return 0;
		}
		else if (childPid == -1)
		{
			/* can not use printf */
			write(1, strerror(errno), strlen(strerror(errno)));

			break;
		}
		else
		{
			if (wait(&status) == -1)
				/* can not use printf */
			write(1, strerror(errno), strlen(strerror(errno)));
		}
	}
}
