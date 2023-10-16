#include "main.h"


char **check_alias(char **args)
{
    char *command = NULL;


    command = get_command_by_name(args[0]);
    if (command == NULL)
        return (args);
    else
    {
        args[0] = command;
    }
    return (args);
}