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
