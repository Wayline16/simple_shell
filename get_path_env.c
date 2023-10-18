#include "main.h"

/**
 *	extract_path - extracts the path from environ.
 *
 *	Return: array of enviroment.
 */
char *extract_path(void)
{
    int index = 0, length = 0;
    int i, j;
    char *buffer;

    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], "PATH=", 5) == 0)
        {
            length += strlen(environ[i]) - 5;
        }
    }

    buffer = malloc(length + 1);
    if (buffer == NULL)
    {
        return (NULL);
    }

    index = 0;
    for (j = 0; environ[j] != NULL; j++)
    {
        if (strncmp(environ[j], "PATH=", 5) == 0)
        {
            strcpy(buffer + index, environ[j] + 5);
            index += strlen(environ[j]) - 5;
        }
    }

    return (buffer);
}
