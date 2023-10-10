#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/*char **get_args(char *line)
{

    char *delim = " \n";
    char **args = NULL;
    int i = 0;
     char *token;

    args = (char **)malloc(sizeof(char *));
    if (args == NULL)
    {
        return NULL;
    }

    token = custom_strtok(line, delim);
    while (token != NULL)
    {
        args = (char **)realloc(args, (i + 1) * sizeof(char *));
        if (args == NULL)
        {
            return NULL;
        }

        args[i++] = token;
        token = custom_strtok(NULL, delim);
    }

    args = (char **)realloc(args, (i + 1) * sizeof(char *));
    if (args == NULL)
    {
        return NULL; 
    }
    args[i] = NULL;

    return args;
}*/

char **get_args(char *line)
{
     char *tokens = NULL;
     char *delim = " \n";
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
