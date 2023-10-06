#include "main.h"

int handle_builtins(char **args, char *buffer, char *prog)
{
	int exe = 0, i = 0;

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{

			errno = exit_status(args[1], prog);
			free(args);
			free(buffer);
			exit(errno);
		}
		else
		{
			free(args);
			free(buffer);
			exit(errno);
		}
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

int exit_status(char *arg, char *prog)
{
	int num = 0;
	int sign = 1;
	char *errmsg, *cmd;

	errmsg = ": Illegal number";
	cmd = "exit";

	if (is_digit_string(arg) == 1)
	{
		if (*arg == '-')
		{
			sign = -1;
			arg++;
		}

		while (*arg != '\0')
		{
			num = num * 10 + (*arg - '0');
			arg++;
		}

		if (sign == -1)
		{
			num = sign * num;
			int_to_string(arg, num);
			error_msg(prog_count, cmd, prog, errmsg, arg, 1);
			return (2);
		}
	}
	else
	{
		error_msg(prog_count, cmd, prog, errmsg, arg, 1);
		return (2);
	}

	return (num);
}