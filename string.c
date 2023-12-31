#include "shell.h"

/**
  * _strlen - returns the length of a string
  * @s: the string whose length to check
  *
  * Return: integer length of string
  */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

/**
  * _strcmp - performs lexicographic comparision of two stangs.
  * @s1: first stang
  * @s2: second stang
  *
  * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
  */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
  * starts_with - check if needle starts with haystack
  * @haystack: string to search
  * @needle: the substring to find
  *
  * Return: address of next char of haystack or NULL
  */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
  * _strcat - concatenates two strings
  * @des: the destination buffer
  * @src: the source buffer
  *
  * Return: pointer to destination buffer
  */
char *_strcat(char *des, char *src)
{
	char *ret = des;

	while (*des)
		des++;
	while (*src)
		*des++ = *src++;
	*des = *src;
	return (ret);
}
