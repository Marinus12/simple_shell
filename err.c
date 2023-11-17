#include "shell.h"

/**
  * _atoi - converts a string to an integer
  * @p(: the string to br converted
  * Return: 0 if no number instring, converted number otherwise
  * -1 on error
  */
int _atoi(char *p)
{
	int o = 0;
	unsigned long int r = 0;

	if (*p == '+')
		p++;
	for (o = 0; p[o] != '\0'; o++)
	{
		if (p[o] >= '0' && p[o] <= '9')
		{
			r *= 10;
			r += (p[o] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (r);
}

/**
  * print_err - prints an error message
  * @info: the parameter & return info struct
  * @t: string containing specified error type
  * Return: 0 if no numbets in string, converted number otherwise
  * -1 on error
  */
void _printerr(info_t *info, char *t)
{
	_puts_str(info->fname);
	_puts_str(": ");
	_printint(info->line_count, STDERR_FILENO);
	_puts_str(": ");
	_puts_str(info->argv[0]);
	_puts_str(": ");
	_puts_str(t);
}

/**
  * _printint - function prits a decimal (integer) number (base10)
  * @in: the input
  * @d: filedescriptor to write to
  * Return: number of characters printed
  */
int _printint(int in, int d)
{
	int (*__putchar)(char) = _putchar;
	int o, y = 0;
	unsigned int _abs_, current;

	if (d == STDERR_FILENO)
		__putchar = _put_char;
	if (in < 0)
	{
		_abs_ = -in;
		__putchar('-');
		y++;
	}
	else
		_abs_ = in;
	current = _abs_;
	for (o = 1000000000; o > 1; o /= 10)
	{
		if (_abs_ / o)
		{
			_putchar('0' + current / o);
			y++;
		}
		current %= o;
	}
	__putchar('0' + current);
	y++;

	return (y);
}

/**
  * _convnum - converter function, a clone of itoa
  * @num: number
  * @base: base
  * @flags: argument flags
  * Return: string
  */
char *_convnum(long int num, int base, int flags)
{
	static char *a;
	static char buffer[50];
	char sign = 0;
	char *r;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	a = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	r = &buffer[49];
	*r = '\0';

	do	{
		*--r = a[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--r = sign;
	return (r);
}

/**
  * rm_comms - function replaces first instance of '#' with '\0'
  * @f: address of the string to modify
  * Return: Always 0
  */
void rm_comms(char *f)
{
	int o = 0;

	for (o = 00; f[o] != '\0'; o++)
		if (f[o] == '#' && (!o || f[o - 1] == ' '))
		{
			f[o] = '\0';
			break;
		}
}
