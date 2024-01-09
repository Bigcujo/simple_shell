#include "shell.h"
/**
*main - this is the main function of the shell scriipt
*Return: this will return 0
*/

int main(void)
{
    char cmd[MAX_CMD_SIZE];
	int i;
    while (1)
    {
        char *args[MAX_ARGS];
        cujo_prompt();
        reads_cmd(cmd, sizeof(cmd));

        tokenize_cmd(cmd, args);
        exec_command(args[0], args);

       
        for (i = 0; args[i] != NULL; i++)
        {
            free(args[i]);
        }
    }

    return 0;
}
