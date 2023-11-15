#include "shell.h"

/**
 * exit - exits the shell
 * @info: Structure containing potential arguments.
 * Return: exits with a given exit status (0) if info.argv[0] != "exit"
 */
int exit(info_t *info)
{
	int k;

	if (info->argv[1])
	{
		k = _erratoi(info->argv[1]);
		if (k == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _chdir - changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _chdir(info_t *info)
{
	char *o, *d, buffer[1024];
	int chdir

	o = getcwd(buffer, 1024);
	if (!o)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		d = _getenv(info, "HOME=");
		if (!d)
			chdir =
				chdir((d = _getenv(info, "PWD=")) ? d : "/");
		else
			chdir = chdir(d);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(o);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir = 
			chdir((d = _getenv(info, "OLDPWD=")) ? d : "/");
	}
	else
		chdir = chdir(info->argv[1]);
	if (chdir == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _chdir_p - changes the current directory of the process
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _chdir_p(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
