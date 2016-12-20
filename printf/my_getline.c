/**
 * _strdup - copy a string
 * @str: string
 *
 * Return: pointer to copy
 */
char *_strdup(char *str)
{
	char *s;
	unsigned int i, n;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	s = malloc((i * sizeof(char)) + 1);
	if (s == NULL)
		return (NULL);
	n = 0;
	while (n < i)
	{
		s[n] = str[n];
		n++;
	}
	s[n] = '\0';
	return (s);
}

/**
 * _realloc - reallocate a memory block using malloc and free
 * @ptr: pointer to previously called memory (from malloc(old_size))
 * @old_size: size in bytes of memory for ptr
 * @new_size: size in bytes of new memory block
 *
 * Return: pointer to new memory, or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *ptrcopy;
	unsigned int i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (ptr == NULL)
		return (new_ptr);
	ptrcopy = ptr;
	i = 0;
	while (i < old_size && i < new_size)
	{
		new_ptr[i] = ptrcopy[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}

/**
 * readline - read given line
 * @fd - file descriptor
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
