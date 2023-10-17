#include "main.h"


/**
 *	_get_args - extracts the arguments.
 *	@line: string containing arguments.
 *	@delim: the delimeter.
 *
 *	Return: array of arguments.
 */
char **get_args(char *line)
{
     char *tokens = NULL;
     char *delim = "; \n";
     char **args = NULL;
     int i = 0;
     int size_tokens;

     size_tokens = _count_tokens(line, delim);
     args = malloc(sizeof(char *) * (size_tokens));
     if (args == NULL)
          return (NULL);
     tokens = custom_strtok(line, delim);
     if (tokens == NULL)
          return (NULL);
     while (tokens != NULL)
     {
          args[i++] = tokens;
          tokens = custom_strtok(NULL, delim);
     }
     args[i] = NULL;
     return (args);
}

#include "main.h"

/**
 * _get_args - extracts the arguments.
 * @line: string containing arguments.
 * @delim: the delimiter.
 *
 * Return: array of arguments.
 *
char **get_args(char *line)
{
    char *tokens = NULL;
    char *delim = "; \n";
    char **args = NULL;
    int i = 0;
    int size_tokens;

    size_tokens = _count_tokens(line, delim);
    args = malloc(sizeof(char *) * (size_tokens));
    if (args == NULL)
        return (NULL);

    tokens = custom_strtok(line, delim);
    if (tokens == NULL)
        return (NULL);

    while (tokens != NULL)
    {
       printf("Token: '%s'\n", tokens);
        if (strcmp(tokens, ";") == 0)
        {
            printf("hello\n");
        }
        args[i++] = tokens;
        tokens = custom_strtok(NULL, delim);
    }

    args[i] = NULL;
    return (args);
}
*/

