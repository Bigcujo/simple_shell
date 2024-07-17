#include "shell.h"
/**
 * execute_cmd - this will execute the command.
 * @command: command passed
 */
void execute_cmd(char *command)
{
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	if (execve(command, argv, environ) == -1)
	{
	perror(command);
	}
}
