#include "shell.h"

/**
  * parse_trim_command = parses the trim command
  * @command: command to be executed
  *
  * Return: ...
  */
void parse_trim_command(const char *command)
{
	char *copy = strdup(command);
	char *token = strtok(copy, " ");
	char *trimmed;

	if (command == NULL)
		return;
	if (copy == NULL)
	{
		perror("Error: strdup failed");
		return;
	}
	while (token != NULL)
	{
		trimmed = trim(token);
		if (strlen(trimmed) > 0)
			execute_command(trimmed);
		token = strtok(NULL, ";");
	}
	free(copy);
}

/**
  * trim - remove leading and trailing whitespace from a string
  * @str: input string
  *
  * Return: new string with leading trailing whitespace
  */
char *trim(char *str)
{
	char *end = str + strlen(str) - 1;

	while (isspace(*str))
	{
		str++;
	}
	if (*str == 0)
		return str;
	while (end > str && isspace(*end))
	{			
		end--;
	}
	end[1] = '\0';
	return (str);
}
