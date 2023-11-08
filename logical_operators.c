#include "shell.h"

/**
  * logical_operators - ...
  * @command: ....
  *
  * Return: ....
  */
int logical_operators(const char *command)
{
	char *copy = strdup(command);
	char *command1;
	char *command2;
	int status1;
	int status2;

	if (strstr(copy, "&&") != NULL)
	{
		command1 = strtok(copy, "&&");
		command2 = strtok(NULL, "&&");
		status1 = system(command1);
		if (status1 == 0)
		{
			status2 = system(command2);
			free(copy);
			return (status2);
		}
		else
		{
			free(copy);
			return (status1);
		}
	}
	else if (strstr(copy, "||") != NULL)
	{
		command1 = strtok(copy, "||");
		command2 = strtok(NULL, "||");
		status1 = system(command1);
		if (status1 != 0)
		{
			status2 = system(command2);
			free(copy);
			return (status2);
		}
		else
		{
			free(copy);
			return (status1);
		}
	}
	else
	{
		free(copy);
		return system(command);
	}
}
