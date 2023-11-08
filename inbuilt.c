#include "shell.h"

/**
  * handle_exit - ...
  * @command: ...
  *
  * Return: ...
  */
int handle_exit(const char *command)
{
	if (strcmp(command, "exit") == 0)
		exit(EXIT_SUCCESS);
	return (0);
}

/**
  * handle_env - handles the env built-in command
  * @command: the command entered by user
  *
  * Return: 1 if the command is "env", 0 otherwise
  */
int handle_env(const char *command)
{
	int i;
	extern char **environ;

	if (strcmp(command, "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		return (1);
	}
	return (0);
}
