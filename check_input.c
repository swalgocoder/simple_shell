#include "my_shell.h"
/**
 * check_input - inputstring processing
 * @inputString1: pointer to inputstring array
 * Return: 0,98, on error
 */

int check_input(char *inputString)
{
	char *str2 = "Can't process more than 1000 characters\n";
	const char token[5] = "exit";
	char *str3 = "exit entered...exiting\n";
	unsigned int inputLength;

	inputLength = 1002;

	if (inputString == NULL)
		return (0);
	if (inputString[0] == token[0] && inputString[1] == token[1] &&
	    inputString[2] == token[2] && inputString[3] == token[3])
	{
		write(1, str3, _strlen(str3));
		exit(98);
	}
	if (_strlen(inputString) > (inputLength - 2))
	{
		write(1, str2, _strlen(str2));
		exit(0);
	}
	return (1);
}
