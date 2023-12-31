#include "shell.h"

/**
  * hsh - main shell loop
  * @info: the parameter & return info struct
  * @av: the argument vector from main()
  * Return: 0 on success, 1 on error, or error code
  */
int hsh(info_t *info, char **av)
{
	ssize_t ren = 0;
	int builtin_ret = 0;

	while (ren != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (output(info))
			_puts("$ ");
		_put_char(BUF_FLUSH);
		ren = get_input(info);
		if (ren != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (output(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!output(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->err_num);
	}
	return (builtin_ret);
}

/**
  * find_builtin - finds a builtin command
  * @info: the parameter & return info struct
  *
  * Return: -1 if builtin not found,
  *			0 if builtin executed successfully,
  *			1 if builtin found but not successful,
  *			-2 if builtin signals exit()
  */
int find_builtin(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtinb[] = {
		{"exit", _exitshell},
		{"env", _curenv},
		{"help", _chdir_p},
		{"history", myhis},
		{"setenv", _setnewenv},
		{"unsetenv", _rmsetenv},
		{"cd", _chdir},
		{"alias", builtin_alias},
		{NULL, NULL}
	};

	for (i = 0; builtinb[i].type; i++)
		if (_strcmp(info->argv[0], builtinb[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtinb[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
  * find_cmd - finds a command in PATH
  * @info: the parameter & return info struct
  * Return: void
  */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!_delimeter(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;
	path = find_path(info, valenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((output(info) || valenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			_printerr(info, "notfound\n");
		}
	}
}

/**
  * fork_cmd - forks an exec thread to run cmd
  * @info: the parameter & return info struc
  * Return: void
  */
void fork_cmd(info_t *info)
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("Error: ");
		return;
	}
	if (child == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/*Error function*/
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				_printerr(info, "Permission denied\n");
		}
	}
}
