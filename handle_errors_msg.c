#include "main.h"

void error_msg(char *prog)
{
    write(2, prog, strlen(prog) + 1);
    write(2, ": No such file or directory", 28);
    write(2, "\n", 1);
}