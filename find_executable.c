#include "shell.h"

char *find_executable(const char *path, const char *command) {
    struct stat file_stat;
    char *path_copy = strdup(path);
    char *dir;
    char *result = NULL;

    if (path_copy == NULL) {
        return NULL;
    }

    while ((dir = strsep(&path_copy, ":")) != NULL) {
        size_t full_path_len = strlen(dir) + strlen(command) + 2;
        char *full_path = malloc(full_path_len);

        if (full_path == NULL) {
            free(path_copy); 
            return NULL;
        }

        printf("Trying path: %s\n", full_path);

        if (stat(full_path, &file_stat) == 0 && S_ISREG(file_stat.st_mode) && file_stat.st_mode & S_IXUSR) {
            result = full_path;
            break;
        }

        free(full_path);  
    }

    free(path_copy); 
    return result;
}

