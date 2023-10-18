#include "main.h"

/**
 * get_full_path - get full path of command
 * @cmd: command name
 *
 * Return: fulle path of command name
 */
char *get_full_path(char *cmd)
{
    char *paths = extract_path();
    char *directory = NULL, *full_path = NULL;
    char **directories = NULL;
    int num_directories = 0;
    int i;

    if (paths == NULL)
        return (NULL);
    directories = malloc(strlen(paths) + 1);
    if (directories == NULL)
    {
        free(paths);
        return (NULL);
    }
    directory = custom_strtok(paths, ":");
    while (directory != NULL)
    {
        directories[num_directories++] = directory;
        directory = custom_strtok(NULL, ":");
    }

    /*Search each directory in the $PATH environment variable for the command.*/
    for (i = 0; i < num_directories; i++)
    {
        full_path = malloc(strlen(directories[i]) + strlen(cmd) + 2);
        strcpy(full_path, directories[i]);
        strcat(full_path, "/");
        strcat(full_path, cmd);

        /*If the command exists in the directory, return the path to the command.*/
        if (access(full_path, X_OK) == 0)
        {
            free(paths);
            free(directories);
            return full_path;
        }

        free(full_path);
    }
    free(paths);
    free(directories);
    /*If the command is not found in any of the directories in the $PATH environment variable, return NULL.*/
    return NULL;
}