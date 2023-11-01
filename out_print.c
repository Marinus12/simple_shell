#include "shell.h"

/**
  * out_print - a print function
  * @content: ...
  *
  * Return: ...
  */
void out_print(const char *content)
{
	write(STDOUT_FILENO, content, strlen(content));
}
