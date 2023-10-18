#include "main.h"


/**
 *	handle_alias - handle alias functions
 *  @args: input tokenized arguments
 *  @buffer: input buffer from getline
 * 	@prog: shell program name
 *	Return: execution status
 */
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

/**
 *	get_alias_name - retreve alias name
 *  @str: array to get alias name from
 *
 *	Return: alias name
 */
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


/**
 *	get_alias_value - retreve alias value
 *  @str: array to get alias value from
 *
 *	Return: alias value
 */
char *get_alias_value(char *str)
{
    char *value = NULL;
    char *sign;
    int len, i;

    sign = strchr(str, '=');
    if (sign == NULL)
        return (NULL);
    if (sign != NULL)
    {
        for (i = 0; sign[i] != '\0'; i++)
        {
            if (sign[i] == '\'' && sign[i + 1] == '\0')
            {
                len = i;
                sign[i] = '\0';
                break;
            }
            else
                len = strlen(sign + 1);
        }
        value = malloc(len + 1);
        if (value == NULL)
        {
            free(value);
            return (NULL);
        }
        if (sign[1] == '\'')
            strcpy(value, sign + 2);
        else
            strcpy(value, sign + 1);
    }
    return (value);
}
