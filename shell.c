#include "shell.h"
/**
* main - this is the main function of the shell scriipt
*Return: this will return 0
*/

int main(void)
{
	char cmd[MAX_CMD_SIZE];

	while (1)
	{
	char **args = (char **)calloc(MAX_ARGS, sizeof(char *));

	if (args == NULL)
	{
	cujo_prints("Memory allocation error!\n");
	break;
	}

	cujo_prompt();

	reads_cmd(cmd, sizeof(cmd));

	tokenize_cmd(cmd, args);

	exec_command(args[0], args);

	free(args);
	}

	return (0);
}
