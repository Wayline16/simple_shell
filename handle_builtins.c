#include "main.h"

/**
 *	handle_builtins - handle builtin functions
 *  @args: input tokenized arguments
 *  @buffer: input buffer from getline
 * 	@prog: shell program name
 *	Return: execution status
 */
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
			free_aliases();
			exit(errno);
		}
		else
		{
			free(args);
			free(buffer);
			free_aliases();
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
		free(args);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		exe = _cd(args);
		free(args);
	}

	return (exe);
}

/**
 *	exit_status - handle the exit status value
 *  @arg: input tokenized arguments of exit value
 * 	@prog: shell program name
 *	Return: execution status
 */
int exit_status(char *arg, char *prog)
{
	int num = 0;
	int sign = 1;
	char *errmsg, *cmd, *errnum = NULL;

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
			errnum = int_to_string(num);
			error_msg(prog_count, cmd, prog, errmsg, errnum, 1);
			free(errnum);
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

/**
 * _cd - change directory.
 * @args: list of commandline arguments.
 *
 * Return: exe status.
 */
int _cd(char **args)
{
	char cur_dir[1024];
	char *old_pwd;
	int i, j, flag;

	i = j = flag = 0;

	getcwd(cur_dir, sizeof(cur_dir));
	if (args[1] == NULL)
	{
		return (_cd_HOME());
	}
	else if (strcmp(args[1], "-") == 0)
	{
		if (i == 0)
		{
			old_pwd = getenv("OLDPWD");
			if (old_pwd == NULL)
			{
				old_pwd = getcwd(NULL, 0);
			}
			i++;
		}
		chdir(old_pwd);
		setenv("PWD", old_pwd, 1);
		if (i == 1)
		{
			setenv("OLDPWD", cur_dir, 1);
			i--;
		}
		return (1);
	}
	else
	{
		chdir(args[1]);
		setenv("OLDPWD", cur_dir, 1);
	}
	flag = 1;
	return (1);
}

/**
 *  _cd_HOME - change directory to home.
 *
 * Return: 0 if error ,1 otherwise
 */
int _cd_HOME(void)
{
	char bef_hom_dir[1024];
	char *home_dir;

	getcwd(bef_hom_dir, sizeof(bef_hom_dir));
	home_dir = getenv("HOME");
	if (home_dir == NULL)
		return (0);
	chdir(home_dir);
	setenv("PWD", home_dir, 1);
	setenv("OLDPWD", bef_hom_dir, 1);
	return (1);
}
