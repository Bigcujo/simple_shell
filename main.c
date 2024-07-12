#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

extern char **environ;

void display_prompt(void)
{
	printf("#cisfun$ ");
}

void read_cmd(char *buffer)
{

	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(0);
		}
		else
		{
			perror("fgets");
			exit(1);
		}
	}
}

void execute_cmd(char *cmd)
{
	char *argv[2];
	argv[0] = cmd;
	argv[1] = NULL;

	if (execve(cmd, argv, environ) == -1)
	{
		perror(cmd);
	}
}

int main(void)
{
	char buffer[BUFFER_SIZE];
	char *cmd;
	while (1)
	{
		display_prompt();
		read_cmd(buffer);

		cmd = strtok(buffer, "\n");

		if (cmd == NULL)
		{
			continue;
		}

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
	return 0;
}
