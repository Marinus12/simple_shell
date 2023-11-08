#include "shell.h"

/**
  * execute_command - executes a simple command
  * @command: command to execute
  *
  * Return: void
  */
void execute_command(const char *command)
{
	char *args[300];
	char *token;
	int i = 0;
	pid_t child;

	token = strtok((char *)command, " ");
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	child = fork();
	if (child == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
