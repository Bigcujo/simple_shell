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
		execve(full_path, args, NULL);
	}
	else
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
else
{
	wait(NULL);
}
}
