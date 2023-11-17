#include "shell.h"

/**
 * _exitshell - exits the shell
 * @info: Structure containing potential arguments.
 * Return: exits with a given exit status (0) if info.argv[0] != "exit"
 */
int _exitshell(info_t *info)
{
	int k;

	if (info->argv[1])
	{
		k = _atoi(info->argv[1]);
		if (k == -1)
		{
			info->status = 2;
			_printerr(info, "Illegal number: ");
			_puts_str(info->argv[1]);
			_put_char('\n');
			return (1);
		}
		info->err_num = _atoi(info->argv[1]);
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
	int chdir_result;

	o = getcwd(buffer, 1024);
	if (!o)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		d = valenv(info, "HOME=");
		if (!d)
			chdir_result = chdir((d = valenv(info, "PWD=")) ? d : "/");
		else
			chdir_result = chdir(d);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!valenv(info, "OLDPWD="))
		{
			_puts(o);
			_putchar('\n');
			return (1);
		}
		_puts(valenv(info, "OLDPWD=")), _putchar('\n');
		chdir_result = chdir((d = valenv(info, "OLDPWD=")) ? d : "/");
	}
	else
		chdir_result = chdir(info->argv[1]);
	if (chdir_result == -1)
	{
		_printerr(info, "can't cd to ");
		_puts_str(info->argv[1]), _put_char('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", valenv(info, "PWD="));
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
