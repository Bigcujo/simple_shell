#include "shell.h"
int main(void)
{
	char buffer[BUFFER_SIZE];
	char *cmd;
	pid_t pid;
	while (1)
	{
		display_prompt();
		read_cmd(buffer);

		cmd = strtok(buffer, "\n");

		if (cmd == NULL)
		{
			continue;
		}

		pid = fork();
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
