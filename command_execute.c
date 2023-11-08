#include "shell.h"

/**
  * command_execute - function that can execute the prompt
  * @command: ...
  *
  * Return: ...
  */
void command_execute(const char *command)
{
	char *args[300];
	char *token;
	int i = 0, j;
    	pid_t child;
    	extern char **environ;
	char *path = getenv("PATH");
	char cmd_path[256];
	char error_msg[50];

	token = strtok((char *)command, " ");
    	if (token == NULL)
	{
		display_prompt();
		return;
	}

    	if (strcmp(token, "env") == 0)
    	{
        	j = 0;
        	while (environ[j] != NULL)
        	{
            		write(STDOUT_FILENO, environ[j], strlen(environ[j]));
          	  	write(STDOUT_FILENO, "\n", 1);
            		j++;
        	}
		display_prompt();
        	return;
    	}
	if (strcmp(token, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
    	child = fork();
    	if (child == -1)
    	{
		write(STDERR_FILENO, "Fork failed\n", 12);
		exit(EXIT_FAILURE);
    	}
	else if (child == 0)
	{
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;
		token = strtok(path, ":");
		while (token != NULL)
		{
			snprintf(cmd_path, sizeof(cmd_path), "%s/%s", token, args[0]);
			if (access(cmd_path, X_OK) == 0)
			{
				if (execve(cmd_path, args, environ) == -1)
				{
					perror("Error");
					exit(EXIT_FAILURE);
				}
			}
			token = strtok(NULL, ":");
		}
		snprintf(error_msg, sizeof(error_msg),  "Command not found: %s\n", args[0]);
		write(STDERR_FILENO, error_msg, strlen(error_msg));
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		display_prompt();
	}
}
