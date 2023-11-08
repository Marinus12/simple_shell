#include "shell.h"

/*
   * main - Entry point
   *
   * Return: ...
   */
int main(int argc, char **argv)
{
	char *input;
	size_t len = 0;
	FILE *file;
	ssize_t read;
	int interact = isatty(STDIN_FILENO);

	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			perror("Error opening file");
			exit(EXIT_FAILURE);
		}
		while ((read = getline(&input, &len, file)) != -1)
		{
			if (read > 0 && input[read - 1] == '\n')
				input[read - 1] = '\0';
			display_prompt();
			logical_operators(input);
		}
		fclose(file);
		exit(EXIT_SUCCESS);
	}
	while (1)
	{
		if (interact)
		{
			display_prompt();
		}
		read = getline(&input, &len, stdin);

		if (read == -1)
		{
			if (interact)
				write(STDOUT_FILENO, "\n", 1);
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (read == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (input[0] == '\n')
		{
			free(input);
			continue;
		}
		if (handle_exit(input))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		if (handle_env(input))
		{
			command_execute(input);
			free(input);
		}
		else
		{
			logical_operators(input);
		}
	}
	return (0);
}
