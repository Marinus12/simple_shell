#include "shell.h"

/**
  * parse_command - parse and execute a command
  * @command: the command to be executed
  *
  * Return: ...
  */
void parse_command(const char *command)
{
	char *copy = strdup(command);
	char *args[300];
	char *full_path = NULL, *cmd;
	char *token = strtok(copy, " ");
	int i;
	char *var = strtok(NULL, " ");
	char *val = strtok(NULL, " ");
	char *dir = strtok(NULL, " ");
	char *home = getenv("HOME");
	extern char **environ;

	if (command == NULL)
		return;
	if (copy == NULL)
	{
		perror("Error: strdup failed");
		return;
	}
	if (token == NULL)
	{
		free(copy);
		return;
	}
	if (strcmp(token, "exit") == 0)
	{
		free(copy);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(token, "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	else if (strcmp(token, "setenv") == 0)
	{
		if (var != NULL && val != NULL)
		{
			if (setenv(var, val, 1) == -1)
				perror("Error setting environment variable");
		}
	}
	else if (strcmp(token, "unsetenv") == 0)
	{
		if (var != NULL)
		{
			if (unsetenv(var) == -1)
				perror("Error unsetting environment variable");
		}
	}
	else if (strcmp(token, "cd") == 0)
	{
		if (dir != NULL)
		{
			if (chdir(dir) == -1)
				perror("Error changing directory");
		}
		else
		{
			if (home != NULL)
			{
				if (chdir(home) == -1)
					perror("Error changing to home directory");
			}
		}
	}
	else
	{
		full_path = resolve_path(token);
		if (full_path)
		{
			cmd = full_path;
			token = strtok(NULL, " ");
			i = 0;
			while (token != NULL)
			{
				args[i] = token;
				token = strtok(NULL, " ");
				i++;
			}
			args[i] = NULL;
			execve(cmd, args, environ);
			free(full_path);
		}
		else
		{
			perror("Error: executable not found");
		}
	}
	free(copy);
}

/**
  * resolve_path - resolve the full path of an executable using PATH
  * @executable: name of the executable
  *
  * Return: full path to the executable or NULL
  */
char *resolve_path(const char *executable)
{
	char *path_env = getenv("PATH");
	char *path = strdup(path_env);
	char *token = strtok(path, ":");
	char *full_path;

	while (token)
	{
		full_path = malloc(strlen(token) + strlen(executable) + 2);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}
		snprintf(full_path, strlen(token) + strlen(executable) + 2, "%s/%s", token, executable);

		if (access(full_path, F_OK | X_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
