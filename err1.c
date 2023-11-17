#include "shell.h"

/**
  * _puts_str - prints an input string
  * @str: the string to be printed
  * Return: Nothing
  */
void _puts_str(char *str)
{
	int o = 0;

	if (!str)
		return;
	while (str[o] != '\0')
	{
		_put_char(str[o]);
		o++;
	}
}

/**
  * _put_char - writes the character c to stderr
  * @y: the character to print
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriately
  */
int _put_char(char y)
{
	static int o;
	static char buf[WRITE_BUF_SIZE];

	if (y == BUF_FLUSH || o >= WRITE_BUF_SIZE)
	{
		write(2, buf, o);
		o = 0;
	}
	if (y != BUF_FLUSH)
		buf[o++] = y;
	return (1);
}

/**
  * _put_fd - write the character c to given fd
  * @y: the character to print
  * @fd: the filedescriptor to write to
  *
  * Return: On sccess 1.
  */
int _put_fd(char y, int fd)
{
	static int o;
	static char buf[WRITE_BUF_SIZE];

	if (y == BUF_FLUSH || o >= WRITE_BUF_SIZE)
	{
		write(fd, buf, o);
		o = 0;
	}
	if (y != BUF_FLUSH)
		buf[o++] = y;
	return (1);
}

/**
  * _puts_instr - prints an input string
  * @str: the string to be printed
  * @d: the filedescriptor to write to
  * Return: the number of chars put
  */
int _puts_instr(char *str, int d)
{
	int o = 0;

	if (!str)
		return (0);
	while (*str)
	{
		o += _put_fd(*str++, d);
	}
	return (o);
}
