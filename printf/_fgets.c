#include "my_shell.h"

/**
 * _fgets - reads a line from the @stream and stores it into @str
 * @str: pointer to an array of chars where the string read is stored
 * @n: maximum number of characters to be read, including '\0'
 * @stream: pointer to a FILE object stream where characters are read from
 *
 * Return: @str if success, otherwise NULL
 */
char *_fgets(char *str, int n, FILE *stream)
{
	int i;
	char *ptr;

	if (str == NULL)
		return (NULL);

	ptr = str;
	if (n > 1)
	{
		while (n > 0)
		{
			i = getc(stream);
			if (i != EOF)
			{
				*ptr++ = i;
				if (i == '\n')
					break;
			}
			n--;
		}
		*ptr = '\0';
	}
	return (i == EOF && ptr == str) ? NULL : str;
}

int main()
{
	FILE *fp;
	char str[60];

	/* opening file for reading */
	fp = fopen("file.txt" , "r");
	if(fp == NULL)
	{
		printf("Error opening file");
		return (-1);
	}
	if(_fgets(str, 60, fp)!=NULL )
	{
		/* writing content to stdout */
		puts(str);
	}
	fclose(fp);

	return(0);
}
