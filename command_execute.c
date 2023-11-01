#include "shell.h"

/**
  * command_execute - function that can execute the prompt
  * @command: ...
  *
  * Return: ...
  */
void command_execute(const char *command)
{
	pid_t child = fork();

	if (child == -1)
	{
		perror("fork"); /*create child process*/
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		execlp(command, command, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
