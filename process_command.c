#include "shell.h"
/**
 * process_command - Processes and executes a command
 * @cmd: The command to process
 */
void process_command(char *cmd)
{
	if (strcmp(cmd, "exit") == 0)
	{
		exit(0);
	}

	handle_fork(cmd);
}
