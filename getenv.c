#include "shell.h"

/**
  * get_environ - return the string array copy of the environ
  * @info: structure containing potential arguments, maintaing
  *			constatnt function prototypes
  * Return: Always 0
  */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
  *_unsetenv - removes an environment variable
  * @info: structure containing potential args, used to maintain
  *		constant function prototype.
  * Return: 1 on delet, 0 otherwise
  * @vat: the string env vat property
  */
int _unsetenv(info_t *info, char *vat)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !vat)
		return (0);

	while (node)
	{
		p = starts_with(node->str, vat);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
  * _setenv - initialize new environment variable, or modify existing
  * @info: structure contains potential args, used to maintain
  *			constant function prototypes
  * @var: the string env var property
  * @val: the string env val property
  * Return: Always 0
  */
int _setenv(info_t *info, char *var, char *val)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !val)
		return (0);
	buf = malloc(_strlen(var) + _strlen(val) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, val);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
