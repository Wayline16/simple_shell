#include "main.h"

/**
 * exec_full_path - Executes the command with full path from user
 * @args: An array of user arguments
 * @argv: Array of command line arguments
 * Return: exit status
 */

int exec_full_path(char **args, char **argv)
{
	pid_t pid_num;
	int status;

	pid_num = fork();
	if (pid_num < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	else if (pid_num == 0)
	{
		execve(args[0], args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
		errno = status;
		free(args);
	}

	return (status);
}

/**
 * exec_full_path_cmd - Executes the appended full path command
 * @args: An array of user arguments
 * @argv: Array of command line arguments
 * @fullcmd: full path of the command to execute
 * Return: exit status
 */

int exec_full_path_cmd(char **args, char **argv, char *fullcmd)
{
	pid_t pid_num;
	int status;

	pid_num = fork();
	if (pid_num < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	else if (pid_num == 0)
	{
		execve(fullcmd, args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
		errno = status;
		free(fullcmd);
		free(args);
		return (status);
	}
	return (status);
}


int multi_exec_full_path(char **args, char **argv)
{
	pid_t pid_num;
	int status;

	pid_num = fork();
	if (pid_num < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	else if (pid_num == 0)
	{
		execve(args[0], args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
		errno = status;

	}

	return (status);
}


int multi_exec_fullcmd(char **args, char **argv, char *fullcmd)
{
	pid_t pid_num;
	int status;

	pid_num = fork();
	if (pid_num < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	else if (pid_num == 0)
	{
		execve(fullcmd, args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
		errno = status;
		free(fullcmd);
		
		return (status);
	}
	return (status);
}