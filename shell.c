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
    char *readbuff = NULL, *fullcmd = NULL;
    int shell_mode = isatty(0);
    int count = 0, i;

    NOTUSED(ac);

    NOTUSED(i);
    while (1)
    {
        count++;
        if (shell_mode == 1)
        {
            write(1, prompt, 4);
            fflush(stdout);
        }
        read_cnt = getline(&readbuff, &n, stdin);
        if (read_cnt == -1)
        {
            free(readbuff);
            free(args);
            exit(errno);
        }
        args = get_args(readbuff);
        if (args[0] == NULL)
        {
            free(args);
            continue;
        }
        if (handle_builtins(args, readbuff) == 1)
             continue;
        if (is_valid_full_path(args) == 1)
             exec_full_path(args, av);
        else
        {

            fullcmd = get_full_path(args[0]);
            if (fullcmd == NULL)
            {
                error_msg(av[0]);
                errno = 127;
                continue;
            }
            exec_full_path_cmd(args, av, fullcmd);
        }
    }
    return (errno);
}