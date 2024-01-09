#include "shell.h"
/**
 * reads_cmd - this reads the command from the user
 * @cmd: this will be the command
 * @size: this will be the size of the command
 */

void reads_cmd(char *cmd, size_t size)
{
	if (fgets(cmd, size - 1, stdin) == NULL)
	{
	if (feof(stdin))
	{
	cujo_prints("\n");
	exit(EXIT_SUCCESS);
	}
	else
	{
	cujo_prints("ERROR READING THE INPUT.\n");
	exit(EXIT_FAILURE);
	}
	}
	cmd[strcspn(cmd, "\n")] = '\0';
}
