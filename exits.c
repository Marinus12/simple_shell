#include "shell.h"

/**
  * *_strncpy - copies a string
  * @dest: the destination of string to be copied to
  * @src: the source string
  * Return: the concatenated string
  * @n: the amount of characters to be copied
  */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
  * *_strncat - concatenates two strings
  * @dest: the first string
  * @src: the second string
  * @n: the amount of bytes to be maximally used
  * Return: the cocatenated string
  */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0, j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
  * *_strchr - locates a character in a string
  * @str: the string to be parsed
  * @c: the character to look for
  * Return: (str) a pointer to the memory area str
  */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
