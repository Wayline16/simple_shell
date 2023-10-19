#include "main.h"

/**
 *	extract_path - extracts the path from environ.
 *
 *	Return: array of enviroment.
 */
char *extract_path(void)
{
	int index = 0, path_len = 0, length = 0;
	int i, j, k = 0;
	char *buffer;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH", 4) == 0)
		{
            while (environ[i][k] != '=')
            {
                path_len++;
                k++;
            }

			length += strlen(environ[i]) - (path_len + 1);
		}
	}
	buffer = malloc(length + 1);
	if (buffer == NULL)
	{
		return (NULL);
	}
	index = 0;
    k = 0;
    path_len = 0;
	for (j = 0; environ[j] != NULL; j++)
	{
		if (strncmp(environ[j], "PATH", 4) == 0)
		{
            while (environ[j][k] != '=')
            {
                path_len++;
                k++;
            }

			strcpy(buffer + index, environ[j] + (path_len + 1));
			index += strlen(environ[j]) - (path_len + 1);
		}
	}

	return (buffer);
}
