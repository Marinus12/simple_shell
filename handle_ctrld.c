#include "shell.h"

/**
  * handle_ctrld - handles the CTRL+D
  * @input: ...
  *
  * Return: ...
  */
void handle_ctrld(char *input)
{
	if (input == NULL || input[0] == '\0')
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(input);
		exit(EXIT_SUCCESS);
	}
}
