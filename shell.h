#ifndef SHELL_H
#define SHELL_H
#define MAX_CMD_SIZE 256
#define MAX_ARGS 32
/**
* The will be the neccesary header files for functions i will be calling
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/stat.h>
/**
* this will be my made functions
*/

void cujo_prints(const char *string);
size_t count_string(const char *str);
void cujo_prompt(void);
void exec_command(const char *command, char *args[]);
void reads_cmd(char *cmd, size_t size);
char *find_executable(const char *path, const char *command);
void tokenize_cmd(const char *cmd, char *args[]);
#endif
