#include "shell.h"
/**
 * handle_fork - Handles the fork and execution of a command
 * @cmd: The command to execute
 */
void handle_fork(char *cmd)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		execute_cmd(cmd);
		exit(1);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
