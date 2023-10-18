#include "main.h"

/**
 * flag_arraydelim - check in an array if delimiter found
 * @str: array to check
 * @delim: delimiter to search
 *
 * Return: 1 if found,2 if invalid delim ,0 otherwise
 */
int flag_arraydelim(char **str, char delim)
{
    int flag = 0, j = 0, k = 0;

    for (; str[j] != NULL; j++)
    {
        k = 0;
        while (str[j][k] != '\0')
        {
            if (str[j][k] == delim)
            {
                if (str[j][k + 1] == delim)
                {
                    flag = 2;
                    break;
                }
                else
                    flag = 1;
            }
            k++;
        }
    }
    return (flag);
}

/**
 * flag_delim - check in a string if delimiter found
 * @str: string to check
 * @delim: delimiter to search
 *
 * Return: 1 if found,2 if invalid delim ,0 otherwise
 */
int flag_delim(char *str, char delim)
{
    int flag = 0, j = 0;

    while (str[j] != '\0')
    {
        if (str[j] == delim)
        {
            if (str[j + 1] == delim)
            {
                flag = 2;
                break;
            }
            else
                flag = 1;
        }
        j++;
    }

    return (flag);
}
