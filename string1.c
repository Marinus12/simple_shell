#include "shell.h"

/**
  * _strcpy - copies a string
  * @dest: the destination
  * @src: the source
  * Return: pointer to destination
  */
char *_strcpy(char *dest, char *src)
{
	int o = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[o])
	{
		dest[o] = src[o];
		o++;
	}
	dest[o] = 0;
	return (dest);
}

/**
  * _strdup  - duplicates a string
  * @s: the string to duplicate
  * Return: pointer to the duplicated string
  */
char *_strdup(const char *s)
{
	int len = 0;
	char *r;

	if (s == NULL)
		return (NULL);
	while (*s++)
		len++;
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	for (len++; len--;)
		r[len] = *--s;
	return (r);
}

/**
  * _puts - prints an input string
  * @s: the string to be printed
  * Return: Nothing
  */
void _puts(char *s)
{
	int o = 0;

	if (!s)
		return;
	while (s[o] != '\0')
	{
		_putchar(s[o]);
		o++;
	}
}

/**
  * _putchar - writes the character c to stdout
  * @y: the character to print
  * Return: On success 1
  * On error, -1 is returned, and errno is seet appropriately
  */
int _putchar(char y)
{
	static int o;
	static char buf[WRITE_BUF_SIZE];

	if (y == BUF_FLUSH || o >= WRITE_BUF_SIZE)
	{
		write(1, buf, o);
		o = 0;
	}
	if (y != BUF_FLUSH)
		buf[o++] = y;
	return (1);
}
