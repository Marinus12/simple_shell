#include "shell.h"

/*
   * display_prompt - ...
   *
   * Return: ...
   */
void display_prompt(void)
{
	write(STDOUT_FILENO, "out_shell$ ", 12);
	fflush(stdout);
}
