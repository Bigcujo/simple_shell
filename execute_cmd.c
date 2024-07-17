#include "shell.h"
/**
 * execute_cmd - this will execute the command.
 * @command: command passed
 */
void execute_cmd(char *command)
{
	char *argv[BUFFER_SIZE];
	char *token;
	int i = 0;

	token = strtok(command, " ");
	while (token != NULL && i < BUFFER_SIZE - 1)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	if (execve(argv[0], argv, environ) == -1)
	{
		perror(argv[0]);
	}

}
