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

	token_cnt_cpy = strdup(str);
    if (token_cnt_cpy == NULL)
         return (0);
	token = strtok(token_cnt_cpy, delim);
	while (token)
	{
        count++;
        len += strlen(token);
		token = strtok(NULL, delim);
	}
    free(token_cnt_cpy);
	return (count + len + 1);
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
