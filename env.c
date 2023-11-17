#include "shell.h"

/**
  * _curenv - prints the current environment
  * @info: structure containing potential arguments, used to maintain
  * constant function prototype
  * Return: Always 0
  */
int _curenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
  * valenv - gets the value of an environ variable
  * @info: structure containing potential arguments, used to maintain
  * @name: env var name
  * Return: the value
  */
char *valenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *o;

	while (node)
	{
		o = starts_with(node->str, name);
		if (o && *o)
			return (o);
		node = node->next;
	}
	return (NULL);
}

/**
  * _setnewenv - initializes a new environ variable, or modifirs existing
  * @info: structure containing potential arguments, used to maintain
  * constant function prototypes
  * Return: Always 0
  */
int _setnewenv(info_t *info)
{
	if (info->argc != 3)
	{
		_puts_str("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
  * _myunsetenv - removes an envronment variable
  * @info: structre containing potential arguments, used to maintain
  * constant fuction prototype.
  * Return: Always 0
  */
int _rmsetenv(info_t *info)
{
	int y = 0;

	if (info->argc == 1)
	{
		_puts_str("Too few arguments.\n");
		return (1);
	}
	for (y = 1; y <= info->argc; y++)
		_unsetenv(info, info->argv[y]);
	return (0);
}

/**
  * pop_env - populates env linked list
  * @info: structure contains potential args, used to maintain constant
  * function prototype
  * Return: Always 0
  */
int pop_env(info_t *info)
{
	list_t *node = NULL;
	size_t y;

	for (y = 0; environ[y]; y++)
		add_node_end(&node, environ[y], 0);
	info->env = node;
	return (0);
}
