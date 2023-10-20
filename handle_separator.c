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
        free(line_tok);
        exe_files(line3d_tok, argv);
        free_3darray(line3d_tok);
        exe = 1;
    }

    return (exe);
}