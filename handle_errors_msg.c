#include "main.h"

void error_msg(int prog_cnt, char *cmd, char *prog)
{
    char prg_cnt = prog_cnt + '0';

    write(2, prog, strlen(prog));
    write(2, ": ", 2);
    write(2, &prg_cnt, strlen(&prg_cnt));
    write(2, ": ", 2);
    write(2, cmd, strlen(cmd));
    write(2, ": not found", 11);
    write(2, "\n", 1);
}