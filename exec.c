#include "shell.h"
/**
*exec_command - This will execute the comman to the command prompt
*@command: this take the command of the user
*@args: this takes the arguments to be used with the command
*/

void exec_command(const char *command, char **args)
{
	pid_t child = fork();

	if (child == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
	char *path = getenv("PATH");

	char *full_path = find_executable(path, command);

	if (full_path != NULL)
	{
	printf("Found executable at path: %s\n", full_path);
	execve(full_path, args, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
	}
	else
	{
	printf("Warning: Returned path from find_executable is NULL.\n");
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	wait(NULL);
	}


}
