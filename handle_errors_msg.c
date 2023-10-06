#include "main.h"

void error_msg(int prog_cnt, char *cmd, char *prog, char *msg, char *arg, int mode)
{
    char prg_cnt = prog_cnt + '0';
/*mode_0:command error handling*/
/*mode_1:exit error handling*/
    write(2, prog, strlen(prog));
    write(2, ": ", 2);
    write(2, &prg_cnt, strlen(&prg_cnt));
    write(2, ": ", 2);
    write(2, cmd, strlen(cmd));
    write(2, msg, strlen(msg));
    if(mode == 1)
    {
        write(2, ": ", 2);
        write(2, arg, strlen(arg));
    }
    write(2, "\n", 1);

}