#include "main.h"

int exe_semitok(char *line, char *prog, char **argv)
{
    char **line_tok = NULL;
    char ***line3d_tok;
    int exe = 0;

    NOTUSED(prog);
    if (flag_delim(line, ';') == 1)
    {
        line_tok = get_args(line, ";\n");
        line3d_tok = get_filetok(line_tok, " ");
        exe_semiop(line3d_tok, argv);
        free(line_tok);
        free_3darray(line3d_tok);
        exe = 1;
    }

    return (exe);
}


void exe_semiop(char ***arglist, char **argv)
{
    int x, y;
    char *fullcmd, *errmsg;

    NOTUSED(y);
    for (x = 0; arglist[x] != NULL; x++)
    {
        if (is_valid_full_path(arglist[x]) == 1)
        {
            multi_exec_full_path(arglist[x], argv);
        }
        else
        {

            fullcmd = get_full_path(arglist[x][0]);
            if (fullcmd == NULL)
            {
                errmsg = ": not found";
                error_msg(0, arglist[x][0], argv[0], errmsg, arglist[x][0], 0);
                errno = 127;
                continue;

            }
            multi_exec_fullcmd(arglist[x], argv, fullcmd);
        }
    }
}



int exe_ANDtok(char *line, char *prog, char **argv)
{
    char **line_tok = NULL;
    char ***line3d_tok;
    int exe = 0;

    NOTUSED(prog);
    if (strstr(line, "&&") != NULL)
    {
        line_tok = get_args(line, "&&\n");
        line3d_tok = get_filetok(line_tok, " ");
        exe_ANDop(line3d_tok, argv);
        free(line_tok);
        free_3darray(line3d_tok);
        exe = 1;
    }

    return (exe);
}

void exe_ANDop(char ***arglist, char **argv)
{
    int x, y;
    char *fullcmd, *errmsg;

    NOTUSED(y);
    for (x = 0; arglist[x] != NULL; x++)
    {
        if (is_valid_full_path(arglist[x]) == 1)
        {
            if (multi_exec_full_path(arglist[x], argv) == 2)
            {
                return;
            }
        }
        else
        {

            fullcmd = get_full_path(arglist[x][0]);
            if (fullcmd == NULL)
            {
                errmsg = ": not found";
                error_msg(0, arglist[x][0], argv[0], errmsg, arglist[x][0], 0);
                errno = 127;
                return;

            }
            multi_exec_fullcmd(arglist[x], argv, fullcmd);
        }
    }
}

int exe_ORtok(char *line, char *prog, char **argv)
{
    char **line_tok = NULL;
    char ***line3d_tok;
    int exe = 0;

    NOTUSED(prog);
    if (strstr(line, "||") != NULL)
    {
        line_tok = get_args(line, "||\n");
        line3d_tok = get_filetok(line_tok, " ");
        exe_ORop(line3d_tok, argv);
        free(line_tok);
        free_3darray(line3d_tok);
        exe = 1;
    }

    return (exe);
}

void exe_ORop(char ***arglist, char **argv)
{
    int x, y;
    char *fullcmd, *errmsg;

    NOTUSED(y);
    for (x = 0; arglist[x] != NULL; x++)
    {
        if (is_valid_full_path(arglist[x]) == 1)
        {
            if (multi_exec_full_path(arglist[x], argv) == 2)
            {
                continue;
            }
            else
                return;
        }
        else
        {

            fullcmd = get_full_path(arglist[x][0]);
            if (fullcmd == NULL)
            {
                errmsg = ": not found";
                error_msg(0, arglist[x][0], argv[0], errmsg, arglist[x][0], 0);
                errno = 127;
                continue;

            }

            multi_exec_fullcmd(arglist[x], argv, fullcmd);
            return;
        }
    }
}