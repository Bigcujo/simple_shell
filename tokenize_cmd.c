#include "shell.h"

/**
*tokenize_cmd - Tokenizes the command string into gan array of arguments.
*@cmd: the input command string to be taken
*@args: An array to store the resulting arguments.
*/

void tokenize_cmd(const char *cmd, char *args[])
{
	char cmd_copy[strlen(cmd) + 1];

	strcpy(cmd_copy, cmd);

	char *token = strtok(cmd_copy, "\t\n");
	int i = 0;

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;

}
