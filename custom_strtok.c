#include "main.h"

/**
 * custom_strtok - Tokenizes a string.
 * @str: The string.
 * @delimiters: delimiter character to tokenize the string
 *
 * Return: A pointer to an array containing the tokenized words.
 */
char *custom_strtok(char *str, const char *delimiters)
{
    static char *nextToken = NULL;
    char *tokenStart;

    if (str != NULL)
    {
        nextToken = str;
    }

    if (nextToken == NULL || *nextToken == '\0')
    {
        return NULL;
    }

    while (*nextToken != '\0' && strchr(delimiters, *nextToken) != NULL)
    {
        nextToken++;
    }

    if (*nextToken == '\0')
    {
        return NULL;
    }

    tokenStart = nextToken;
    while (*nextToken != '\0' && strchr(delimiters, *nextToken) == NULL)
    {
        nextToken++;
    }

    if (*nextToken != '\0')
    {
        *nextToken = '\0';
        nextToken++;
    }

    return tokenStart;
}