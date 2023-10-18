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

/**
 *	get_command_by_name - Get command by name from added aliases
 *  @name: name of alias
 *
 *	Return: alias value
 */
char *get_command_by_name(char *name)
{
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		if (strcmp(aliases[i]->name, name) == 0)
		{
			return (aliases[i]->value);
		}
	}
	return (NULL);
}

/**
 *	free_aliases - Free all of the aliases in the aliases array
 *
 *	Return: anthing
 */

void free_aliases(void)
{
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		if (aliases[i] != NULL)
		{
			free(aliases[i]->name);
			free(aliases[i]->value);
			free(aliases[i]);
		}
	}
	free(aliases);
	aliases = NULL;
	num_aliases = 0;
}
