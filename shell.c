#include "shell.h"

/**
  * main - Entry point
  *
  * Return: ...
  */
int main(void)
{
	char command[150];

	while (true)
	{
		personal_prompt();
		read_command(command, sizeof(command));
		command_execute(command);
	}
}
