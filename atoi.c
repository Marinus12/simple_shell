#include "shell.h"

/**
 * output - returns true if shell is interactive mode
 * @input: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int output(info_t *input)
{
	return (isatty(STDIN_FILENO) && input->readfd <= 2);
}

/**
 * _delimeter - checks if character is a delimeter
 * @i: the char to check
 * @: the delimeter string
 * Return: 1 if true, 0 if false
 */
int _delimeter(char i, char *d)
{
	while (*d)
		if (*d++ == c)
			return (1);
	return (0);
}

/**
 *_alphabeth - checks for alphabetic character
 *@m: The character to input
 *Return: 1 if m is alphabetic, 0 otherwise
 */

int _alphabeth(int m)
{
	if ((m >= 'a' && m <= 'z') || (m >= 'A' && m <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_integer - converts a string to an integer
 *@p: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _integer(char *p)
{
	int i, s = 1, f = 0, op;
	unsigned int r = 0;

	for (i = 0;  p[i] != '\0' && f != 2; i++)
	{
		if (p[i] == '-')
			s *= -1;

		if (p[i] >= '0' && p[i] <= '9')
		{
			f = 1;
			r *= 10;
			r += (p[i] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (s == -1)
		op = -r;
	else
		op = r;

	return (op);
}
