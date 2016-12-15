#define _GNU_SOURCE
#include "my_shell.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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

	char *ptr;
	char *line;
	size_t len = 200;
	ssize_t i;

	line = (char *) malloc(len + 1);
	
	if (str == NULL)
		return (NULL);

	ptr = str;
	if (n > 1)
	{
		while (n > 0)
		{
		  i = getline(&line, &len, stream);
		  if (i == -1)
		  break;
		  
		  if (i != -1)
		  puts(line);
		}

	}
	
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
	}
	fclose(fp);

	return(0);
}
