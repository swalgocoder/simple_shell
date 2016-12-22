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
	char inputString[INPUT_LENGTH], tempPath[_strlen(path)];
	char *argv[ARGUMENT_LENGTH], *inputChar, *pathChar;
	char *pathArgs[_strlen(path)], *final_PathArgs[_strlen(path)];
	char *str = "#cisfun$ ";
	struct stat sb;
	char *inputString1 = inputString;
	char pathString[_strlen(path)];

	while (1)
	{
		write(1, str, _strlen(str));
		_memset(inputString, 0, sizeof(inputString));
		_memset(argv, 0, sizeof(argv));
		_memset(pathArgs, 0, sizeof(pathArgs));

		check_input(inputString1);

		childPid = fork();
		if (childPid == 0)
		  //resets counters from previous child process
		  //my_strtok to parse the arguments based on whitespace(delimiters)
		  //"NULL" to parse the reminder of the string
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

			//print to verify
			printf("argv[0] is %s\n", argv[0]);
			printf("argv[1] is %s\n", argv[1]);
			printf("argv[2] is %s\n", argv[2]);
			printf("argv[3] is %s\n", argv[3]);
			
			//convert PATH variable to a string to be parsed

			for (i = 0; i < _strlen(path); i++)
				pathString[i] = path[i];
			//parses PATH variale based on colon delimiter
			//NULL to parse the reminder of PATH environment variable
			pathChar = my_strtok(pathString, colon);
			//print to verify
			//printf("env variable PATH is %s\n", PATH);
			printf("pathChar is %s\n", pathChar);
			//verify end
			pathArgs[path_Counter] = pathChar;
			//print to verify
			printf("pathArgs[0] is %s\n", pathArgs[0]);
			printf("pathArgs[1] is %s\n", pathArgs[1]);
			//verify end
			
			while (pathChar != NULL)
			{
				path_Counter++;
				pathChar = my_strtok(NULL, colon);
				pathArgs[path_Counter] = pathChar;
			}

			//append file to end of each path and calls stat() to validate file
			for (i = 0; i < path_Counter; i++)
			{
				_memset(tempPath, 0, sizeof(tempPath));
				_strcpy(tempPath, pathArgs[i]);
				_strcat(tempPath, "/");
				_strcat(tempPath, argv[0]);
				final_PathArgs[i] = tempPath;

				//print to verify
				printf("tempPath is %s\n", tempPath);
				printf("final_PathArgs[0]: %s \n", final_PathArgs[0]);
				printf("final_PathArgs[1]: %s \n", final_PathArgs[1]);
				printf("final_PathArgs[2]: %s \n", final_PathArgs[2]);
				printf("final_PathArgs[3]: %s \n", final_PathArgs[3]);
				printf("final_PathArgs[4]: %s \n", final_PathArgs[4]);
				
				//verify end

				//if stat () successful, call execv with proper path and arguments, break out
				sysCallReturn = stat(final_PathArgs[i], &sb);
				if (sysCallReturn == 0)
				{
					sysCallReturn = execv(final_PathArgs[i], argv);
					break;
				}
			}
			//if last system call unsuccessful, print error msg
			if (sysCallReturn == -1)
			write(1, strerror(errno), strlen(strerror(errno)));
			return (0);
		}
		//if fork() errors, print error msg
		else if (childPid == -1)
		{
			write(1, strerror(errno), strlen(strerror(errno)));

			break;
		}
		//parent process executes the following:
		else
		{
			if (wait(&status) == -1)
			write(1, strerror(errno), strlen(strerror(errno)));
		}
	}
}
