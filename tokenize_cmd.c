#include "shell.h"

/**
*tokenize_cmd - Tokenizes the command string into gan array of arguments.
*@cmd: the input command string to be taken
*@args: An array to store the resulting arguments.
*/

void tokenize_cmd(const char *cmd, char **args)
{
	char *cmd_copy = malloc(strlen(cmd) + 1);
	if (cmd_copy == NULL)
	{
		cujo_prints("Memory allocation error!\n");
		return;
	}
	char *token;
	strcpy(cmd_copy, cmd);

	token = strtok(cmd_copy, "\t\n");
	int i = 0;
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	free(cmd_copy);
	}
