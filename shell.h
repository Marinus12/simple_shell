#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

 void out_print(const char *content);
void command_execute(const char *command);
void read_command(char *command, size_t str_size);
void personal_prompt(void);

#endif
