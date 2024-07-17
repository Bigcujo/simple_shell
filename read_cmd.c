#include "shell.h"
/**
 * read_cmd - reads command from the commandline.
 * @buffer: where the command will be saved.
 */
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

