#ifndef SHELL_H
#define SHELL_H

/* LIBRARIES TO BE USED */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <limits.h>
#include <signal.h>

void display_prompt(void);
void read_cmd(char *buffer);
void execute_cmd(char *command);
