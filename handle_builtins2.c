#include "main.h"

/**
 * handle_builtins2 - handle builtin functions
 * @args: input tokenized arguments
 * @buffer: input buffer from getline
 * @prog: shell program name
 * Return: execution status
 */
int handle_builtins2(char **args, char *buffer, char *prog)
{
	int exe = 0;

	NOTUSED(prog);
	NOTUSED(buffer);
	if (strcmp(args[0], "setenv") == 0)
	{
		_setenv(args[1], args[2]);
		exe = 1;
		free(args);
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		_unsetenv(args[1]);
		exe = 1;
		free(args);
	}

	return (exe);
}

/**
 * handle_builtins_echo - handle builtin echo
 * @args: input tokenized arguments
 * @buffer: input buffer from getline
 * @prog: shell program name
 * Return: execution status
 */
int handle_builtins_echo(char **args, char *buffer, char *prog)
{
	int exe = 0;

	NOTUSED(prog);
	NOTUSED(buffer);
	if (strcmp(args[0], "echo") == 0)
	{
		if (args[1] == NULL)
		{
			write(1, "\n", 1);
			free(args);
			exe = 1;
			return (exe);
		}
		if (strcmp(args[1], "$?") == 0 && args[2] == NULL)
		{
			handle_echo_status();
			write(1, "\n", 2);
		}
		else if (strcmp(args[1], "$$") == 0 && args[2] == NULL)
		{
			handle_echo_pid();
			write(1, "\n", 2);
		}
		else
		{
			handle_echo_args(args);
		}
		free(args);
		exe = 1;
	}
	return (exe);
}

/**
 *	handle_echo_status - handle echo status
 *
 *	Return: nothing
 */
void handle_echo_status(void)
{
	char *errnum;

	errnum = int_to_string(errno);
	write(1, errnum, strlen(errnum));
	free(errnum);
}

/**
 *	handle_echo_pid - handle echo pid
 *
 *	Return: nothing
 */
void handle_echo_pid(void)
{
	char *pid_str;
	int pid;

	pid = getpid();
	pid_str = int_to_string(pid);
	write(1, pid_str, strlen(pid_str));
	free(pid_str);
}

/**
 *	handle_echo_args - handle echo arguments
 *  @args: input tokenized arguments
 *
 *	Return: nothing
 */
void handle_echo_args(char **args)
{
	int i = 1;
	char *args_ptr;

	while (args[i] != NULL)
	{
		args_ptr = args[i];
		if (strcmp(args_ptr, "$$") == 0)
		{
			handle_echo_pid();
			if (args[i + 1] == NULL)
				write(1, "\n", 2);
			else
				write(1, "\n", 2);
		}
		else if ((strcmp(args_ptr, "$?") == 0))
		{
			handle_echo_status();
			if (args[i + 1] == NULL)
				write(1, "\n", 2);
		}
		else
		{
			while (*args_ptr != '\0')
			{
				write(1, args_ptr, 1);
				args_ptr++;
			}
			if (args[i + 1] != NULL)
				write(1, " ", 1);
			else
				write(1, "\n", 2);

		}
		i++;
	}
}

void handle_variables(char **args)
{
    int i = 0;

    while (args[i] != NULL)
    {

        if (strcmp(args[i], "$$") != 0 && strcmp(args[i], "$?") != 0 && strcmp(args[i], "$") != 0)
        {

            if (args[i][0] == '$')
            {

                char *var_name = args[i] + 1;

                char *var_value = getenv(var_name);

                if (var_value == NULL)
                {
                    var_value = "";
                }

                strcpy(args[i], var_value);
            }
        }
        i++;
    }
}
