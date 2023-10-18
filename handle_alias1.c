#include "main.h"

/*A hash table to store the aliases.*/
alias_t **aliases = NULL;
int num_aliases = 0;

/**
 *	define_alias - Define an alias.
 *  @name: name of alias
 *  @value: value of alias
 *	Return: noting
 */
void define_alias(char *name, char *value)
{
	char *cmd = NULL;
	alias_t *alias;

	alias = get_alias(name);
	if (alias != NULL)
	{
		free(alias->value);
		alias->value = strdup(value);
	}
	else
	{
		if (num_aliases == 0)
		{
			aliases = malloc(sizeof(alias_t *) * 16);
		}
		else if (num_aliases % 16 == 0)
		{
			aliases = realloc(aliases, sizeof(alias_t *) * (num_aliases + 16));
		}
		alias = malloc(sizeof(alias_t));
		alias->name = strdup(name);
		cmd = get_command_by_name(value);
		if (cmd != NULL)
		{
			alias->value = strdup(cmd);
		}
		else
		{
			alias->value = strdup(value);
		}
		aliases[num_aliases++] = alias;
	}
}

/**
 *	get_alias - et the alias for the given name.
 *  @name: name of alias
 *
 *	Return: aliases
 */
alias_t *get_alias(char *name)
{
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		if (strcmp(aliases[i]->name, name) == 0)
		{
			return (aliases[i]);
		}
	}
	return (NULL);
}

/**
 *	remove_alias - Remove an alias from the hash table.
 *  @name: name of alias
 *
 *	Return: nothing
 */
void remove_alias(char *name)
{
	int i;

	for (i = 0; i < num_aliases; i++)
	{
		if (strcmp(aliases[i]->name, name) == 0)
		{
			free(aliases[i]);
			aliases[i] = aliases[num_aliases - 1];
			num_aliases--;
			return;
		}
	}
}

/**
 *	print_aliases - Print the specified aliases to stdout.
 *  @names: name of alias
 *
 *	Return: nothing
 */
void print_aliases(char *names)
{
	alias_t *alias;
	size_t name_len, value_len;

	alias = get_alias(names);

	if (alias != NULL)
	{
		/*Get the length of the alias name.*/
		name_len = strlen(alias->name);
		/*Write the alias name to stdout.*/
		write(STDOUT_FILENO, alias->name, name_len);
		/*Write the equals sign to stdout.*/
		write(STDOUT_FILENO, "=", 1);
		write(STDOUT_FILENO, "'", 1);
		/*Get the length of the alias value.*/
		value_len = strlen(alias->value);
		/*Write the alias value to stdout.*/
		write(STDOUT_FILENO, alias->value, value_len);
		write(STDOUT_FILENO, "'", 1);
		/*Write a newline character to stdout.*/
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 *	print_all_aliases - Print all aliases to stdout
 *
 *	Return: nothing
 */
void print_all_aliases(void)
{
	int i;
	size_t value_len;
	alias_t *alias;

	for (i = 0; i < num_aliases; i++)
	{
		alias = get_alias(aliases[i]->name);
		if (alias != NULL)
		{
			/*Get the length of the alias name.*/
			size_t name_len = strlen(aliases[i]->name);
			/*Write the alias name to stdout.*/
			write(STDOUT_FILENO, aliases[i]->name, name_len);
			/*Write the equals sign to stdout.*/
			write(STDOUT_FILENO, "=", 1);
			write(STDOUT_FILENO, "'", 1);
			/*Get the length of the alias value.*/
			value_len = strlen(aliases[i]->value);
			/*Write the alias value to stdout.*/
			write(STDOUT_FILENO, aliases[i]->value, value_len);
			write(STDOUT_FILENO, "'", 1);
			/*Write a newline character to stdout.*/
			write(STDOUT_FILENO, "\n", 1);
		}
	}
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
