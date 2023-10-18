#include "main.h"

/**
 *	check_alias - check if input is alias
 *  @args: arguments to check for
 *
 *	Return: an alias value replacement if exist
 */
char **check_alias(char **args)
{
	char *command = NULL;

	command = get_command_by_name(args[0]);
	if (command == NULL)
	{
		return (args);
	}
	else
	{
		args[0] = command;
	}

	return (args);
}

