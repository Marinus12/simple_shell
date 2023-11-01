#include "shell.h"

/**
  * read_command - function recieves user input
  * @command: ...
  * @str_size: ...
  *
  * Return: ...
  */
void read_command(char *command, size_t str_size)
{
	if (fgets(command, str_size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			out_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			out_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
