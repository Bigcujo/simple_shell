#include "shell.h"
/**
*main - this is the main function of the shell scriipt
*Return: this will return 0
*/
int main(void);
{
	char cmd[150];

	while (1)
{
	cujo_prompt();
	reads_cmd(cmd, sizeof(cmd));
	char *args[10];

	tokenize_cmd(cmd, args);
	exec_command(args[0], args);
}
	return (0);
}
