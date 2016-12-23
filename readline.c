#include "my_shell.h"

/**
 * readline - read given line
 * @fd: file descriptor
 *
 * Return: pointer to stored read string
 */
char *readline(int fd)
{
	char *buffer, *line;
	unsigned int max, max_plus, i;
	char c;

	/* max length of a given line */
	max = 128;
	buffer = malloc(sizeof(*buffer) * max);
	if (buffer == NULL)
		return (NULL);
	read(fd, &c, 1);
	while (c != '\n')
	{
		if (i == max)
		{
			max_plus = max + 128;
			buffer = _realloc(buffer, max, max_plus);
			if (buffer == NULL)
				return (NULL);
			max = max_plus;
		}
		c = buffer[i];
		i++;
		read(fd, &c, 1);
	}
	buffer[i] = '\0';
	line = malloc(sizeof(*line) * (i + 1));
	if (line == NULL)
		return (NULL);
	line = _strdup(buffer);
	free(buffer);
	return (line);
}
