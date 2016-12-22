#include "my_shell.h"
/**
 * check_input - inputstring processing
 * @inputString1: pointer to inputstring array
 * Return: 0,98, on error
 */

int check_input(char *inputString1)
{
	char *str2 = "Can't process more than 1000 characters\n";
	const char token[5] = "exit";
	char *str3 = "exit entered...exiting\n";
	unsigned int inputLength;

	inputLength = 1002;

	if (fgets(inputString1, inputLength, stdin) == NULL)
		return (0);
		if (inputString1[0] == token[0] && inputString1[1] == token[1] &&
		    inputString1[2] == token[2] && inputString1[3] == token[3])
		{
			write(1, str3, _strlen(str3));
			exit(98);
		}
		if (_strlen(inputString1) > (inputLength - 2))
		{
			write(1, str2, _strlen(str2));
			exit(0);
		}
		return (1);
}
