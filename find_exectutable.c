#include "shell.h"
/**
 * *find_executable - this finds the path os the exec_command
 * @path: this will be the path to be taken
 * @command: command to be taken
 * Return: it returns a char
 */
char *find_executable(const char *path, const char *command)
{
	struct stat file_info;

	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
	char *full_path = malloc(strlen(dir) + strlen(command) + 2);
	if (dir == NULL)
	{
	break;
	}


	if (full_path == NULL)
	{
	free(path_copy);
	return (NULL);  /** Handle memory allocation failure */
	}
	sprintf(full_path, "%s/%s", dir, command);

	if (stat(full_path, &file_info) == 0)
	{
	if (S_ISREG(file_info.st_mode) && (file_info.st_mode & S_IXUSR))
	{
	free(path_copy);
	return (full_path);  /** Found and executable */
	}
	}

	free(full_path);
	dir = strtok(NULL, ":");
	}

	free(path_copy);
	fprintf(stderr, "Warning: %s not found or not executable in PATH\n", command);
	return (NULL);  /** Not found or not executable */
}
