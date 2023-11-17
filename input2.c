#include "shell.h"

/**
  * myhis - displays the history list, one command by line,
  * preceeded with numbers, starting at 0.
  * @info: Structure containing potential atrguments, used to maintain
  * constant function prototype.
  * Return: Always 0
  */
int myhis(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
  * string_alias - sets alias to string
  * @info: parameter struct
  * @str: the string alias
  * Return: Always 0 on success, 1 on error
  */
int string_alias(info_t *info, char *str)
{
	char *l, o;
	int rat;

	l = _strchr(str, '=');
	if (!l)
		return (1);
	o = *l;
	*l = 0;
	rat = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*l = o;
	return (rat);
}

/**
  * alias_string - sets alias to string
  * @info: parameter struct
  * @str: the string alias
  * Return: Always 0 on success, 1 on error
  */
int alias_string(info_t *info, char *str)
{
	char *y;

	y = _strchr(str, '=');
	if (!y)
		return (1);
	if (!*++y)
		return (string_alias(info, str));

	string_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
  * print_string - prints an alias string
  * @node: the alias node
  * Return: Always 0 on successs, 1 on error
  */
int print_string(list_t *node)
{
	char *o = NULL, *l = NULL;

	if (node)
	{
		o = _strchr(node->str, '=');
		for (l = node->str; l <= o; l++)
			_putchar(*l);
		_putchar('\'');
		_puts(o + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
  * builtin_alias - mimics the alias builtin (man alias)
  * @info: structure containing potential arguments, used to maintain
  * constant function prototypes
  * Return: Always 0
  */
int builtin_alias(info_t *info)
{
	int y = 0;
	char *o = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_string(node);
			node = node->next;
		}
		return (0);
	}
	for (y = 1; info->argv[y]; y++)
	{
		o = _strchr(info->argv[y], '=');
		if (o)
			alias_string(info, info->argv[y]);
		else
			print_string(node_starts_with(info->alias, info->argv[y], '='));
	}
	return (0);
}
