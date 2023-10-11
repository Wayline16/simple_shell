#include "main.h"

/**
 * _count_tokens - count number of tokens.
 * @str: the string to tokenize.
 * @delim: the point to tokenize at.
 *
 * Return: number of tokens
 */
int _count_tokens(char *str, char *delim)
{
    int len = 0, count = 0;
    char *token = NULL;
    char *token_cnt_cpy = NULL;

    if (str == NULL)
        return (count);
    token_cnt_cpy = strdup(str);
    token = strtok(token_cnt_cpy, delim);
    while (token)
    {
        count++;
        len += strlen(token);
        token = strtok(NULL, delim);
    }
    len++;
    free(token_cnt_cpy);
    return (count + len);
}

/**
 * free_array - Frees an array of dynamically allocated string
 * @argc: Number to be freed
 * @argv: Array of dynamically allocated strings
 * Author: Wassim Haimoudi
 * Return: Void
 */

void free_array(char **argv)
{
    int i = 0;

    if (argv == NULL)
        return;

    while (argv[i] != NULL)
    {
        free(argv[i]);
        i++;
    }
    free(argv);
}

int is_valid_full_path(char **args)
{
    int ret;

    if (args[0] == NULL)
    {
        return -1;
    }
    ret = access(args[0], X_OK);
    if (ret == 0)
    {
        /*The file exists, so it is a valid path.*/
        return 1;
    }
    else if (errno == ENOENT)
    {
        /*The file does not exist, so it is not a valid path.*/
        return 0;
    }
    else
    {
        /*There was an error accessing the file.*/
        return -1;
    }
}

char *int_to_string(char *str, int num)
{
    int len, tmp, digit, i;
    /*Check if the number is negative.*/
    int is_negative = num < 0;
    if (is_negative)
    {
        /*Convert the number to positive.*/
        num = -num;
        /*Add a minus sign to the beginning of the string.*/
        *str++ = '-';
    }

    /*Calculate the length of the string.*/
    len = 0;
    tmp = num;
    while (tmp > 0)
    {
        len++;
        tmp /= 10;
    }

    /*Convert the number to a string, digit by digit, in reverse order.*/
    i = len - 1;
    while (num > 0)
    {
        digit = num % 10;
        str[i--] = digit + '0';
        num /= 10;
    }

    /*Add a null terminator to the end of the string.*/
    str[len] = '\0';

    return str;
}

int is_digit_string(char *s)
{
    /*Check if the string is empty.*/
    if (*s == '\0')
    {
        return 0;
    }

    /*Check if the first character of the string is a minus sign.*/
    if (*s == '-')
    {
        /*Advance to the next character in the string.*/
        s++;
    }

    /*Iterate over the rest of the string, checking each character.*/
    while (*s != '\0')
    {
        /*If the character is not a digit, return 0.*/
        if (!isdigit(*s))
        {
            return 0;
        }

        /*Advance to the next character in the string.*/
        s++;
    }

    /*If we reach here, then all of the characters in the string were digits.*/
    return 1;
}

int flag_delim(char **str, char delim)
{
    int flag = 0, j = 0, k = 0;

    for (;str[j] != NULL; j++)
    {
        k = 0;
        while (str[j][k] != '\0')
        {
            if (str[j][k] == delim)
            {
                if(str[j][k + 1] == delim)
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