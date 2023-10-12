#include "main.h"

int handle_builtins2(char **args, char *buffer, char *prog)
{
	int overwrite, exe = 0;
    char *errnum;


    NOTUSED(prog);
    NOTUSED(buffer);
    if (strcmp(args[0], "setenv") == 0)
	{
        if(args[3] != NULL)
            overwrite = atoi(args[3]);
        else
            overwrite = 0;
		_setenv(args[1], args[2], overwrite);
        exe = 1;
        free(args);
	}
    else if (strcmp(args[0], "unsetenv") == 0)
    {
        _unsetenv(args[1]);
        exe = 1;
        free(args);
    }
    else if (strcmp(args[0], "echo") == 0)
    {
        if (args[1] == NULL)
            write(1, "\n", 1);
        if (strcmp(args[1], "$?") == 0)
        {
            errnum = int_to_string(errno);
            write(1, errnum, strlen(errnum));
            write(1, "\n", 2);
        }
        exe = 1;
        free(args);
        free(errnum);
    }

    return (exe);
}