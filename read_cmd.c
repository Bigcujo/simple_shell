#include "shell.h"

void read_cmd(char *buffer) 
{
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        if (feof(stdin)) { 
            printf("\n");
            exit(0);
        } else {
            perror("fgets");
            exit(1);
        }
    }
}

