#include "main.h"


/**
 *	get_args - extracts the arguments.
 *	get_args - extracts the arguments.
 *	@line: string containing arguments.
 *
 *	Return: array of arguments.
 */
char **get_args(char *line)
{
     char *tokens = NULL;
     char *delim = "\\ \n";
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
