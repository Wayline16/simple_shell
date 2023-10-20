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
 *
 * Return: Void
 */

void free_array(char **argv, int size)
{
    int i = 0;

    if (argv == NULL)
        return;

    while (i < size)
    {
        free(argv[i]);
        i++;
    }
    free(argv);
}

/**
 * is_valid_full_path - check if command is valid path or not
 * @args: command arguments to check
 *
 * Return: 1 if valid path ,-1 error,0 otherwise
 */
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

/**
 * int_to_string - int to char convertor
 * @num: int to convert
 *
 * Return: converted char
 */
char *int_to_string(int num)
{
    /* Calculate the length of the string. */
    int i, is_negative, digit, len = 0;
    int tmp;
    char *str;

    /* Check if the number is 0. */
    if (num == 0)
    {
        /* Return a string containing a single 0 character. */
        str = malloc(2 * sizeof(char));
        if (str == NULL)
        {
            return NULL;
        }
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    is_negative = num < 0;
    if (is_negative)
    {
        /* Multiply the number by -1 to make it positive. */
        num = -num;
        /* Add extend length of the string. */
        len++;
    }
    tmp = num;
    while (tmp > 0)
    {
        len++;
        tmp /= 10;
    }

    /* Allocate memory for the string. */
    str = malloc((len + 1) * sizeof(char));
    if (str == NULL)
    {
        return NULL;
    }

    /* Convert the number to a string, digit by digit, in reverse order. */
    i = len - 1;
    while (num > 0)
    {
        digit = num % 10;
        str[i--] = digit + '0';
        num /= 10;
    }

    if (is_negative)
    {
        /* Add extend length of the string. */
        str[0] = '-';
    }
    /* Add a null terminator to the end of the string. */
    str[len] = '\0';

    return str;
}

/**
 * is_digit_string - check if char is digit or not
 * @s: char to check
 *
 * Return: 1 if digit,0 otherwise
 */
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
