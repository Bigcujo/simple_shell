#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: 0 on success, otherwise an error code
 */
int main(void)
{
	char buffer[BUFFER_SIZE];
	char *cmd;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			display_prompt();
		}

		read_cmd(buffer);

		cmd = strtok(buffer, "\n");

		while (cmd != NULL)
		{
			process_command(cmd);
			cmd = strtok(NULL, "\n");
		}
	}

	return (0);
}
