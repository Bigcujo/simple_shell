#include "shell.h"

/**
*cujo_prints - funtion will print out a string to the stdout
*@string: this is a pointer that takes the string to be printed
*/
void cujo_prints(const char *string)
{
	write(STDOUT_FILENO, string, count_string(string));
}
