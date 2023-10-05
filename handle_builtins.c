#include "main.h"

int handle_builtins(char **args, char *buffer)
{
int exe = 0, i = 0;


	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(buffer);
		exit(errno);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (environ[i] != NULL)
		{
			write(1, environ[i], strlen(environ[i]));
			write(1, "\n", 1);

			i++;
		}
		exe = 1;
	}

	return (exe);
}