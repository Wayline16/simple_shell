#include "main.h"
/**
 * main - function is the entry point for all C programs.
 * @ac: parameter specifies the number of command-line arguments.
 * @av: parameter is an array of pointers to the command-line arguments.
 * Description: function handling simple shell
 * Return: 0 succuss ,1 otherwise
 */

int main(int ac, char **av)
{
    char *prompt = "($) ";
    char **args = NULL;
    size_t n = 0;
    ssize_t read_cnt = 0;
    char *errmsg, *readbuff = NULL, *fullcmd = NULL;
    int shell_mode = isatty(0);
    int i;

    NOTUSED(ac);
    NOTUSED(i);
    errno = 0;
    prog_count = 0;
    while (1)
    {
        prog_count++;
        if (shell_mode == 1)
        {
            write(1, prompt, 4);
            fflush(stdout);
        }
        read_cnt = getline(&readbuff, &n, stdin);
        if (read_cnt == -1)
        {
            free(readbuff);
            free_aliases();
            exit(errno);
        }
        handle_comments(readbuff);
        args = get_args(readbuff);
        if (args == NULL)
        {
            continue;
        }
        check_alias(args);
        if (handle_builtins(args, readbuff, av[0]) || handle_builtins2(args, readbuff, av[0])
        || handle_alias(args, readbuff, av[0]) || handle_file_test(args, av[0]) == 1)
            continue;
        if (is_valid_full_path(args) == 1)
        {
            exec_full_path(args, av);
        }
        else
        {

            fullcmd = get_full_path(args[0]);
            if (fullcmd == NULL)
            {
                errmsg = ": not found";
                error_msg(prog_count, args[0], av[0], errmsg, args[1], 0);
                errno = 127;
                free(args);
                continue;
            }
            exec_full_path_cmd(args, av, fullcmd);
        }
    }
    return (errno);
}