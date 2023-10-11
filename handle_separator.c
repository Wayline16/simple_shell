#include "main.h"

char **handle_op(char **args)
{
    int flag = flag_delim(args, ';');

       if (flag == 1)
       {
        create_array(args, ";");
       }
       
       return args;
}

char **create_array(char **args, char *delim)
{
    int i = 0, j = 0, len = 0, m = 0, k = 0;
    char **args_cpy;
   for (; args[i] != NULL; i++) {
    j = 0;
    while (args[i][j] != '\0') {
        if (args[i][j] != *delim)
            len++;
        if ((j != 0) && (args[i][j + 1] == '\0'))
            len++;
        j++;
    }

  }

args_cpy = malloc(sizeof(char *) * (len));
i = 0;
j = 0;
for ( ;args[i] != NULL; i++)
{
    j = 0;
    for ( ;args[i][j] != '\0'; j++)
    {
        if (args[i][j] == *delim && args[i][j + 1] =='\0')
            i++;
        if (j == 0 && args[i][j] == *delim)
            {
                if (args[i][j] != '\0')
                {
                    j++;
                }
            }
        if (args[i][j] != *delim)
        {
            args_cpy[m][k++] = args[i][j];
        }
        else if (args[i][j] != *delim && args[i][j + 1] =='\0' && args[i + 1][0] == *delim)
        {
            args_cpy[m][k] = '\0';
            m++;
            k = 0;
        }
        else if ((args[i][j] == *delim && args[i][j + 1] !='\0'))
        {
            args_cpy[m][k] = '\0';
            m++;
            k = 0;
        }
        else if (args[i][j] != *delim && args[i][j + 1] =='\0' &&  args[i + 1] == NULL)
        {
            args_cpy[m][k] = '\0';
        }
    }
}

return args_cpy;

}
