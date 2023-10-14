#include "main.h"


int handle_alias(char **args, char *buffer, char *prog)
{
    int i = 1, exe = 0;
    char *name, *value;

    NOTUSED(prog);
    NOTUSED(buffer);
    if (strcmp(args[0], "alias") == 0 && args[1] == NULL)
	{
        print_all_aliases();
        exe = 1;
        free(args);
    }
    else if (strcmp(args[0], "alias") == 0)
    {
        while (args[i] != NULL)
        {
            if (flag_delim(args[i], '=') == 1)
            {
            name = get_alias_name(args[i]);
            value = get_alias_value(args[i]);
            define_alias(name, value);
            free(name);
            free(value);
            }
            else
            {
                print_aliases(args[i]);
            }
            i++;
        }
        exe = 1;
        free(args);

    }
    else if (strcmp(args[0], "unalias") == 0)
    {
        i = 1;
        while (args[i] != NULL)
        {
            remove_alias(args[i]);
            i++;
        }
        exe = 1;
        free(args);
    }
    return (exe);
}





char *get_alias_name(char *str)
{
    char *name = NULL;
    char *sign;
    int name_len;

    sign = strchr(str, '=');
    if (sign == NULL)
        return (NULL);
    if (sign != NULL)
    {
        name_len = sign - str;
        name = malloc(sizeof(char) * name_len + 1);
        if (name == NULL)
        {
            free(name);
            return (NULL);
        }
        strncpy(name, str, name_len);
        name[name_len] = '\0';
    }
    return (name);
}

char *get_alias_value(char *str)
{
    char *value = NULL;
    char *sign;

    sign = strchr(str, '=');
    if (sign == NULL)
        return (NULL);
    if (sign != NULL)
    {
        value = malloc(strlen(sign + 1) + 1);
        if (value == NULL)
        {
            free(value);
            return (NULL);
        }
        strcpy(value, sign + 1);
    }
    return (value);
}






















