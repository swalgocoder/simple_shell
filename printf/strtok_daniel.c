/**
 * seg_num - helper function for _strtok; finds number of segments
 * @line: pointer to line being split
 * @sep: value evaluated as a separator
 *
 * Return: number of segments in @line
 */
int seg_num(char *line, char sep)
{
	int i;

	if (line == NULL)
		return (-1);
	i = 0;
	while (*line)
	{
		while (*line == sep)
			line++;
		if (*line == '\0')
			break;
		while (*line && *line != '\0')
			line++;
		i++;
	}
	return (i);
}

/**
 * seg_strlen - helper function for _strtok; finds length of each segment
 * @line: segment being evaluated
 * @sep: value evaluated as a separator
 *
 * Return: length of segment
 */
int seg_strlen(char *line, char sep)
{
	int i;

	i = 0;
	while (line[i] && line[i] != sep)
		i++;
	return (i);
}

/**
 * _strtok - split a string into a sequence of tokens
 * @line: line being split
 * @sep: value being used as separator
 *
 * Return: pointer to an array of tokens
 */
char **_strtok(char *line, char sep)
{
	char **token;
	char *ptr;
	int num, len;

	num = seg_num(line, sep);
	if (num <= 0)
		return (NULL);
	/* +2 for initial char value and trailing '\0' */
	token = malloc(sizeof(char *) * (num + 2));
	if (token == NULL)
		return (NULL);
	num = 0;
	while (*line)
	{
		while (*line == sep)
			line++;
		len = seg_strlen(line, sep);
		token[num] = malloc(sizeof(*ptr) * (len + 1));
		ptr = token[num];
		while (*line && *line != sep)
		{
			*ptr = *line;
			ptr++;
			line++;
		}
		while (*line == sep)
			line++;
		*ptr = 0;
		num++;
	}
	token[num] = 0;
	return (token);
}
