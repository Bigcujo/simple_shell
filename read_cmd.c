#include "shell.h"
/**
 * read_cmd - reads command from the commandline.
 * @buffer: where the command will be saved.
 */
void read_cmd(char *buffer)
{
	size_t len = strlen(buffer);
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

	if (len > 0 && buffer[len - 1] == '\n')
	{
		buffer[len - 1] = '\0';
	}
}

