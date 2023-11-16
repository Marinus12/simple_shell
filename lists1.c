#include "shell.h"

/**
  * list_len - determines length of linked list
  * @g: pointer to the first node
  *
  * Return: size of list
  */
size_t list_len(const list_t *g)
{
	size_t i = 0;

	while (g)
	{
		g = g->next;
		i++;
	}
	return (i);
}

/**
  * list_to_strings - returns an array of the list->str
  * @head: pointer to the first node
  *
  * Return: array of strings
  */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **s, *str;

	if (!head || !i)
		return (NULL);
	s = malloc(sizeof(char *) * (i + 1));
	if (!s)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(s[j]);
			free(s);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		s[i] = str;
	}
	s[i] = NULL;
	return (s);
}

/**
  * print_list - prints all elements of a list_t linked list
  * @h: pointer to first node
  *
  * Return: size of list
  */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
  * node_starts_with - returns node whose string starts with prefix
  * @node: pointer to list head
  * @pref: string to match
  * @c: the next character pref to match
  *
  * Return: match node or null
  */
list_t *node_starts_with(list_t *node, char *pref, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, pref);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
  * get_node_index - gets the index of a node
  * @head: pointer to list head
  * @node: pointer to the node
  *
  * Return: index of node or -1
  */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
