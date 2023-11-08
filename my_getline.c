#include "shell.h"

/**
  * my_getline - custom implementation of a getline
  * @lineptr: ...
  * @n: ...
  *
  * Return: ...
  */
char *my_getline(char **lineptr, size_t *n)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	char *new_line;

	if (lineptr == NULL || n == NULL)
		return (NULL);
	while (1)
	{
		read_bytes = read(STDIN_FILENO, &line[len], 1);
		if (read_bytes == -1 || (read_bytes == 0 && len == 0))
		{
			if (line != NULL)
			{
				free(line);
			}
			return (NULL);
		}
		if (read_bytes == 0 || line[len] == '\n')
		{
			if (line[len] == '\n')
				line[len] = '\0';
			if (len == 0)
			{
				if (line != NULL)
					free(line);
				return (NULL);
			}
			return (line);
		}
		len++;

		if (len >= *n)
		{
			*n += 1024;
			new_line = custom_realloc(line, *n, *n + READ_SIZE);
			if (new_line == NULL)
			{
				free(line);
				return (NULL);
			}
			line = new_line;
		}
	}
}

/**
  * custom_realloc - reallocates memory for a buffer
  * @ptr: ...
  * @old_size: ...
  * @new_size: ...
  * Return: pointer to the new buffer
  */
char *custom_realloc(char *ptr, size_t old_size, size_t new_size)
{
	char *new_ptr;
	size_t i;

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (new_size > old_size)
		new_size = old_size;
	for (i = 0; i < new_size; i++)
		new_ptr[i] = ptr[i];
	free(ptr);
	return (new_ptr);
}
