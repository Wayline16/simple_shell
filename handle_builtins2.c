#include "main.h"

int handle_builtins2(char **args, char *buffer, char *prog)
{
	int overwrite, exe = 0;


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

    return (exe);
}