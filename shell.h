#ifndef SHELL_H
#define SHELL_H
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#define BUFFER_SIZE 1024
#define READ_SIZE 1024
#define MAX_INPUT_LEN 1024
void execute_command(const char *command);
int logical_operators(const char *command);
void parse_command(const char *command);
void handle_ctrld(char *input);
void display_prompt(void);
void command_execute(const char *command);
int handle_env(const char *command);
int handle_exit(const char *command);
char *custom_realloc(char *ptr, size_t old_size, size_t new_size);
char *my_getline(char **lineptr, size_t *n);
int main(int argc, char **argv);
char *trim(char *str);
void parse_trim_command(const char *command);
char *resolve_path(const char *executable);
#endif
